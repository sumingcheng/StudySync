/*
 ESP8266WiFiSTA.cpp - WiFi library for esp8266

 Copyright (c) 2014 Ivan Grokhotkov. All rights reserved.
 This file is part of the esp8266 core for Arduino environment.

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

 Reworked on 28 Dec 2015 by Markus Sattler

 */

#include "ESP8266WiFi.h"
#include "ESP8266WiFiGeneric.h"
#include "ESP8266WiFiSTA.h"

extern "C" {
#include "c_types.h"
#include "ets_sys.h"
#include "os_type.h"
#include "osapi.h"
#include "mem.h"
#include "user_interface.h"
#include "smartconfig.h"
#include "lwip/err.h"
#include "lwip/dns.h"
}

#include "debug.h"

extern "C" void esp_schedule();
extern "C" void esp_yield();

// -----------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------- Private functions ------------------------------------------------
// -----------------------------------------------------------------------------------------------------------------------

static bool sta_config_equal(const station_config& lhs, const station_config& rhs);


/**
 * compare two STA configurations
 * @param lhs station_config
 * @param rhs station_config
 * @return equal
 */
static bool sta_config_equal(const station_config& lhs, const station_config& rhs) {
    if(strcmp(reinterpret_cast<const char*>(lhs.ssid), reinterpret_cast<const char*>(rhs.ssid)) != 0) {
        return false;
    }

    if(strcmp(reinterpret_cast<const char*>(lhs.password), reinterpret_cast<const char*>(rhs.password)) != 0) {
        return false;
    }

    if(lhs.bssid_set != rhs.bssid_set) {
        return false;
    }

    if(lhs.bssid_set) {
        if(memcmp(lhs.bssid, rhs.bssid, 6) != 0) {
            return false;
        }
    }

    return true;
}

// -----------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------- STA function -----------------------------------------------------
// -----------------------------------------------------------------------------------------------------------------------

bool ESP8266WiFiSTAClass::_useStaticIp = false;

/**
 * Start Wifi connection
 * if passphrase is set the most secure supported mode will be automatically selected
 * @param ssid const char*          Pointer to the SSID string.
 * @param passphrase const char *   Optional. Passphrase. Valid characters in a passphrase must be between ASCII 32-126 (decimal).
 * @param bssid uint8_t[6]          Optional. BSSID / MAC of AP
 * @param channel                   Optional. Channel of AP
 * @param connect                   Optional. call connect
 * @return
 */
wl_status_t ESP8266WiFiSTAClass::begin(const char* ssid, const char *passphrase, int32_t channel, const uint8_t* bssid, bool connect) {

    if(!WiFi.enableSTA(true)) {
        // enable STA failed
        return WL_CONNECT_FAILED;
    }

    if(!ssid || *ssid == 0x00 || strlen(ssid) > 31) {
        // fail SSID too long or missing!
        return WL_CONNECT_FAILED;
    }

    if(passphrase && strlen(passphrase) > 64) {
        // fail passphrase too long!
        return WL_CONNECT_FAILED;
    }

    struct station_config conf;
    strcpy(reinterpret_cast<char*>(conf.ssid), ssid);

    if(passphrase) {
        if (strlen(passphrase) == 64) // it's not a passphrase, is the PSK
            memcpy(reinterpret_cast<char*>(conf.password), passphrase, 64);
        else
            strcpy(reinterpret_cast<char*>(conf.password), passphrase);
    } else {
        *conf.password = 0;
    }

    if(bssid) {
        conf.bssid_set = 1;
        memcpy((void *) &conf.bssid[0], (void *) bssid, 6);
    } else {
        conf.bssid_set = 0;
    }

    struct station_config current_conf;
    wifi_station_get_config(&current_conf);
    if(sta_config_equal(current_conf, conf)) {
        DEBUGV("sta config unchanged");
        return status();
    }

    ETS_UART_INTR_DISABLE();

    if(WiFi._persistent) {
        // workaround for #1997: make sure the value of ap_number is updated and written to flash
        // to be removed after SDK update
        wifi_station_ap_number_set(2);
        wifi_station_ap_number_set(1);

        wifi_station_set_config(&conf);
    } else {
        wifi_station_set_config_current(&conf);
    }

    if(connect) {
        wifi_station_connect();
    }

    ETS_UART_INTR_ENABLE();

    if(channel > 0 && channel <= 13) {
        wifi_set_channel(channel);
    }

    if(!_useStaticIp) {
        wifi_station_dhcpc_start();
    }

    return status();
}

wl_status_t ESP8266WiFiSTAClass::begin(char* ssid, char *passphrase, int32_t channel, const uint8_t* bssid, bool connect) {
    return begin((const char*) ssid, (const char*) passphrase, channel, bssid, connect);
}

/**
 * Use to connect to SDK config.
 * @return wl_status_t
 */
wl_status_t ESP8266WiFiSTAClass::begin() {

    if(!WiFi.enableSTA(true)) {
        // enable STA failed
        return WL_CONNECT_FAILED;
    }

    ETS_UART_INTR_DISABLE();
    wifi_station_connect();
    ETS_UART_INTR_ENABLE();

    if(!_useStaticIp) {
        wifi_station_dhcpc_start();
    }
    return status();
}


/**
 * Change IP configuration settings disabling the dhcp client
 * @param local_ip   Static ip configuration
 * @param gateway    Static gateway configuration
 * @param subnet     Static Subnet mask
 * @param dns1       Static DNS server 1
 * @param dns2       Static DNS server 2
 */
bool ESP8266WiFiSTAClass::config(IPAddress local_ip, IPAddress gateway, IPAddress subnet, IPAddress dns1, IPAddress dns2) {

    if(!WiFi.enableSTA(true)) {
        return false;
    }

    struct ip_info info;
    info.ip.addr = static_cast<uint32_t>(local_ip);
    info.gw.addr = static_cast<uint32_t>(gateway);
    info.netmask.addr = static_cast<uint32_t>(subnet);

    wifi_station_dhcpc_stop();
    if(wifi_set_ip_info(STATION_IF, &info)) {
        _useStaticIp = true;
    } else {
        return false;
    }
    ip_addr_t d;

    if(dns1 != (uint32_t)0x00000000) {
        // Set DNS1-Server
        d.addr = static_cast<uint32_t>(dns1);
        dns_setserver(0, &d);
    }

    if(dns2 != (uint32_t)0x00000000) {
        // Set DNS2-Server
        d.addr = static_cast<uint32_t>(dns2);
        dns_setserver(1, &d);
    }

    return true;
}

/**
 * will force a disconnect an then start reconnecting to AP
 * @return ok
 */
bool ESP8266WiFiSTAClass::reconnect() {
    if((WiFi.getMode() & WIFI_STA) != 0) {
        if(wifi_station_disconnect()) {
            return wifi_station_connect();
        }
    }
    return false;
}

/**
 * Disconnect from the network
 * @param wifioff
 * @return  one value of wl_status_t enum
 */
bool ESP8266WiFiSTAClass::disconnect(bool wifioff) {
    bool ret;
    struct station_config conf;
    *conf.ssid = 0;
    *conf.password = 0;

    ETS_UART_INTR_DISABLE();
    if(WiFi._persistent) {
        wifi_station_set_config(&conf);
    } else {
        wifi_station_set_config_current(&conf);
    }
    ret = wifi_station_disconnect();
    ETS_UART_INTR_ENABLE();

    if(wifioff) {
        WiFi.enableSTA(false);
    }

    return ret;
}

/**
 * is STA interface connected?
 * @return true if STA is connected to an AD
 */
bool ESP8266WiFiSTAClass::isConnected() {
    return (status() == WL_CONNECTED);
}


/**
 * Setting the ESP8266 station to connect to the AP (which is recorded)
 * automatically or not when powered on. Enable auto-connect by default.
 * @param autoConnect bool
 * @return if saved
 */
bool ESP8266WiFiSTAClass::setAutoConnect(bool autoConnect) {
    bool ret;
    ETS_UART_INTR_DISABLE();
    ret = wifi_station_set_auto_connect(autoConnect);
    ETS_UART_INTR_ENABLE();
    return ret;
}

/**
 * Checks if ESP8266 station mode will connect to AP
 * automatically or not when it is powered on.
 * @return auto connect
 */
bool ESP8266WiFiSTAClass::getAutoConnect() {
    return (wifi_station_get_auto_connect() != 0);
}

/**
 * Set whether reconnect or not when the ESP8266 station is disconnected from AP.
 * @param autoReconnect
 * @return
 */
bool ESP8266WiFiSTAClass::setAutoReconnect(bool autoReconnect) {
    return wifi_station_set_reconnect_policy(autoReconnect);
}

/**
 * Wait for WiFi connection to reach a result
 * returns the status reached or disconnect if STA is off
 * @return wl_status_t
 */
uint8_t ESP8266WiFiSTAClass::waitForConnectResult() {
    //1 and 3 have STA enabled
    if((wifi_get_opmode() & 1) == 0) {
        return WL_DISCONNECTED;
    }
    while(status() == WL_DISCONNECTED) {
        delay(100);
    }
    return status();
}

/**
 * Get the station interface IP address.
 * @return IPAddress station IP
 */
IPAddress ESP8266WiFiSTAClass::localIP() {
    struct ip_info ip;
    wifi_get_ip_info(STATION_IF, &ip);
    return IPAddress(ip.ip.addr);
}


/**
 * Get the station interface MAC address.
 * @param mac   pointer to uint8_t array with length WL_MAC_ADDR_LENGTH
 * @return      pointer to uint8_t *
 */
uint8_t* ESP8266WiFiSTAClass::macAddress(uint8_t* mac) {
    wifi_get_macaddr(STATION_IF, mac);
    return mac;
}

/**
 * Get the station interface MAC address.
 * @return String mac
 */
String ESP8266WiFiSTAClass::macAddress(void) {
    uint8_t mac[6];
    char macStr[18] = { 0 };
    wifi_get_macaddr(STATION_IF, mac);

    sprintf(macStr, "%02X:%02X:%02X:%02X:%02X:%02X", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
    return String(macStr);
}

/**
 * Get the interface subnet mask address.
 * @return IPAddress subnetMask
 */
IPAddress ESP8266WiFiSTAClass::subnetMask() {
    struct ip_info ip;
    wifi_get_ip_info(STATION_IF, &ip);
    return IPAddress(ip.netmask.addr);
}

/**
 * Get the gateway ip address.
 * @return IPAddress gatewayIP
 */
IPAddress ESP8266WiFiSTAClass::gatewayIP() {
    struct ip_info ip;
    wifi_get_ip_info(STATION_IF, &ip);
    return IPAddress(ip.gw.addr);
}

/**
 * Get the DNS ip address.
 * @param dns_no
 * @return IPAddress DNS Server IP
 */
IPAddress ESP8266WiFiSTAClass::dnsIP(uint8_t dns_no) {
    ip_addr_t dns_ip = dns_getserver(dns_no);
    return IPAddress(dns_ip.addr);
}


/**
 * Get ESP8266 station DHCP hostname
 * @return hostname
 */
String ESP8266WiFiSTAClass::hostname(void) {
    return String(wifi_station_get_hostname());
}


/**
 * Set ESP8266 station DHCP hostname
 * @param aHostname max length:32
 * @return ok
 */
bool ESP8266WiFiSTAClass::hostname(char* aHostname) {
    if(strlen(aHostname) > 32) {
        return false;
    }
    return wifi_station_set_hostname(aHostname);
}

/**
 * Set ESP8266 station DHCP hostname
 * @param aHostname max length:32
 * @return ok
 */
bool ESP8266WiFiSTAClass::hostname(const char* aHostname) {
    return hostname((char*) aHostname);
}

/**
 * Set ESP8266 station DHCP hostname
 * @param aHostname max length:32
 * @return ok
 */
bool ESP8266WiFiSTAClass::hostname(String aHostname) {
    return hostname((char*) aHostname.c_str());
}

/**
 * Return Connection status.
 * @return one of the value defined in wl_status_t
 *
 */
wl_status_t ESP8266WiFiSTAClass::status() {
    station_status_t status = wifi_station_get_connect_status();

    switch(status) {
        case STATION_GOT_IP:
            return WL_CONNECTED;
        case STATION_NO_AP_FOUND:
            return WL_NO_SSID_AVAIL;
        case STATION_CONNECT_FAIL:
        case STATION_WRONG_PASSWORD:
            return WL_CONNECT_FAILED;
        case STATION_IDLE:
            return WL_IDLE_STATUS;
        default:
            return WL_DISCONNECTED;
    }
}

/**
 * Return the current SSID associated with the network
 * @return SSID
 */
String ESP8266WiFiSTAClass::SSID() const {
    struct station_config conf;
    wifi_station_get_config(&conf);
    return String(reinterpret_cast<char*>(conf.ssid));
}

/**
 * Return the current pre shared key associated with the network
 * @return  psk string
 */
String ESP8266WiFiSTAClass::psk() const {
    struct station_config conf;
    wifi_station_get_config(&conf);
    return String(reinterpret_cast<char*>(conf.password));
}

/**
 * Return the current bssid / mac associated with the network if configured
 * @return bssid uint8_t *
 */
uint8_t* ESP8266WiFiSTAClass::BSSID(void) {
    static struct station_config conf;
    wifi_station_get_config(&conf);
    return reinterpret_cast<uint8_t*>(conf.bssid);
}

/**
 * Return the current bssid / mac associated with the network if configured
 * @return String bssid mac
 */
String ESP8266WiFiSTAClass::BSSIDstr(void) {
    struct station_config conf;
    char mac[18] = { 0 };
    wifi_station_get_config(&conf);
    sprintf(mac, "%02X:%02X:%02X:%02X:%02X:%02X", conf.bssid[0], conf.bssid[1], conf.bssid[2], conf.bssid[3], conf.bssid[4], conf.bssid[5]);
    return String(mac);
}

/**
 * Return the current network RSSI.
 * @return  RSSI value
 */
int32_t ESP8266WiFiSTAClass::RSSI(void) {
    return wifi_station_get_rssi();
}



// -----------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------- STA remote configure -----------------------------------------------
// -----------------------------------------------------------------------------------------------------------------------

void wifi_wps_status_cb(wps_cb_status status);

/**
 * WPS config
 * so far only WPS_TYPE_PBC is supported (SDK 1.2.0)
 * @return ok
 */
bool ESP8266WiFiSTAClass::beginWPSConfig(void) {

    if(!WiFi.enableSTA(true)) {
        // enable STA failed
        return false;
    }

    disconnect();

    DEBUGV("wps begin\n");

    if(!wifi_wps_disable()) {
        DEBUGV("wps disable failed\n");
        return false;
    }

    // so far only WPS_TYPE_PBC is supported (SDK 1.2.0)
    if(!wifi_wps_enable(WPS_TYPE_PBC)) {
        DEBUGV("wps enable failed\n");
        return false;
    }

    if(!wifi_set_wps_cb((wps_st_cb_t) &wifi_wps_status_cb)) {
        DEBUGV("wps cb failed\n");
        return false;
    }

    if(!wifi_wps_start()) {
        DEBUGV("wps start failed\n");
        return false;
    }

    esp_yield();
    // will return here when wifi_wps_status_cb fires

    return true;
}

/**
 * WPS callback
 * @param status wps_cb_status
 */
void wifi_wps_status_cb(wps_cb_status status) {
    DEBUGV("wps cb status: %d\r\n", status);
    switch(status) {
        case WPS_CB_ST_SUCCESS:
            if(!wifi_wps_disable()) {
                DEBUGV("wps disable failed\n");
            }
            wifi_station_connect();
            break;
        case WPS_CB_ST_FAILED:
            DEBUGV("wps FAILED\n");
            break;
        case WPS_CB_ST_TIMEOUT:
            DEBUGV("wps TIMEOUT\n");
            break;
        case WPS_CB_ST_WEP:
            DEBUGV("wps WEP\n");
            break;
    }
    // TODO user function to get status

    esp_schedule(); // resume the beginWPSConfig function
}



bool ESP8266WiFiSTAClass::_smartConfigStarted = false;
bool ESP8266WiFiSTAClass::_smartConfigDone = false;

/**
 * Start SmartConfig
 */
bool ESP8266WiFiSTAClass::beginSmartConfig() {
    if(_smartConfigStarted) {
        return false;
    }

    if(!WiFi.enableSTA(true)) {
        // enable STA failed
        return false;
    }

    if(smartconfig_start(reinterpret_cast<sc_callback_t>(&ESP8266WiFiSTAClass::_smartConfigCallback), 1)) {
        _smartConfigStarted = true;
        _smartConfigDone = false;
        return true;
    }
    return false;
}


/**
 *  Stop SmartConfig
 */
bool ESP8266WiFiSTAClass::stopSmartConfig() {
    if(!_smartConfigStarted) {
        return true;
    }

    if(smartconfig_stop()) {
        _smartConfigStarted = false;
        return true;
    }
    return false;
}

/**
 * Query SmartConfig status, to decide when stop config
 * @return smartConfig Done
 */
bool ESP8266WiFiSTAClass::smartConfigDone() {
    if(!_smartConfigStarted) {
        return false;
    }

    return _smartConfigDone;
}


/**
 * _smartConfigCallback
 * @param st
 * @param result
 */
void ESP8266WiFiSTAClass::_smartConfigCallback(uint32_t st, void* result) {
    sc_status status = (sc_status) st;
    if(status == SC_STATUS_LINK) {
        station_config* sta_conf = reinterpret_cast<station_config*>(result);

        wifi_station_set_config(sta_conf);
        wifi_station_disconnect();
        wifi_station_connect();

        _smartConfigDone = true;
    } else if(status == SC_STATUS_LINK_OVER) {
        WiFi.stopSmartConfig();
    }
}

