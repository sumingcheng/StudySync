//********************************************************** OneNet  WiFi  send  Data *******************************************************************************************************
void sendDataWiFi(String APIkey,int thisData,unsigned long deviceid,String sensorid )
{
  int l=getLength(thisData);
  int D=getLength(deviceid);
  int S=sensorid.length(); 
  int lenss=53+S+l;
  int lll=getLength(lenss);
  int lens=214+D+S+l+lll; 
  WiFi_Port.println("AT+CIPSTART=\"TCP\",\"183.230.40.33\",80");
  delay(100);
  returnmsg_ok_conWiFi();
  Debug_Port.println("connecting...");  
  WiFi_Port.print("AT+CIPSEND=");
  delay(100);
  returnmsgWiFi();
  WiFi_Port.println(lens); 
  delay(100); 
  returnmsgWiFi();
  WiFi_Port.print("POST http://api.heclouds.com/devices/");
  delay(100);
  returnmsgWiFi();    
  WiFi_Port.print(deviceid);
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print("/datapoints HTTP/1.1");
  delay(100);
  returnmsgWiFi();    
  WiFi_Port.print(LINEBREAK);
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print("Host: ");
  delay(100);
  returnmsgWiFi();    
  WiFi_Port.print(server);
  delay(100);
  returnmsgWiFi();    
  WiFi_Port.print(LINEBREAK);
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print("api-key: ");
  delay(100);
  returnmsgWiFi();    
  WiFi_Port.print(APIkey);
  delay(100);
  returnmsgWiFi();    
  WiFi_Port.print(LINEBREAK);
  delay(100);
  returnmsgWiFi();
  WiFi_Port.println("Connection: close");
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print("Content-Length: ");
  returnmsgWiFi();
  delay(100);    
  WiFi_Port.print(lenss);
  delay(100);
  returnmsgWiFi();  
  WiFi_Port.print(LINEBREAK);
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print(LINEBREAK);
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print("{\"datastreams\":[{\"id\":\"");
  delay(100);    
  WiFi_Port.print(sensorid);
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print("\",\"datapoints\":[{\"value\":");
  delay(100);
  returnmsgWiFi();  
  WiFi_Port.print(thisData);
  delay(100);
  WiFi_Port.print("}]}]}");
  returnmsgWiFi();
  WiFi_Port.print(LINEBREAK);    
  WiFi_Port.print(LINEBREAK);    
  WiFi_Port.print(LINEBREAK);      
  WiFi_Port.print(LINEBREAK);
  returnmsg_ok_finishWiFi();
}
//********************************************************** OneNet  WiFi  send  GPS Data *******************************************************************************************************
void sendGPSDataWiFi(char* HEIGH,unsigned long deviceid,String sensorid,char* LON,char* LAT,String APIkey )
{
  int l=strlen(HEIGH);
  int D=getLength(deviceid);
  int S=sensorid.length(); 
  int Lonlen=strlen(LON); 
  int Latlen=strlen(LAT); 
  int lenss=53+28+S+l+Lonlen+Latlen;
  int l2=getLength(lenss); 
  int lens=214+28+D+S+l+Lonlen+Latlen+l2;   
  WiFi_Port.println(lens);
  WiFi_Port.println("AT+CIPSTART=\"TCP\",\"183.230.40.33\",80");
  delay(100);  
  returnmsg_ok_conWiFi();    
  Debug_Port.println("connecting...");  
  WiFi_Port.print("AT+CIPSEND=");
  delay(100);  
  returnmsgWiFi();     
  WiFi_Port.println(lens);
  delay(100);  
  returnmsgWiFi();    
  WiFi_Port.print("POST http://api.heclouds.com/devices/");
  delay(100);  
  returnmsgWiFi();  
  WiFi_Port.print(deviceid);
  delay(100);  
  returnmsgWiFi();    
  WiFi_Port.print("/datapoints HTTP/1.1");
  delay(100);  
  returnmsgWiFi();    
  WiFi_Port.print(LINEBREAK);
  delay(100);  
  returnmsgWiFi();    
  WiFi_Port.print("Host: ");
  delay(100);  
  returnmsgWiFi();      
  WiFi_Port.print(server);
  delay(100);  
  returnmsgWiFi();     
  WiFi_Port.print(LINEBREAK);
  delay(100);  
  returnmsgWiFi();    
  WiFi_Port.print("api-key: ");  
  returnmsgWiFi();    
  WiFi_Port.print(APIkey);
  delay(100);  
  returnmsgWiFi();   
  WiFi_Port.print(LINEBREAK);  
  returnmsgWiFi();   
  WiFi_Port.println("Connection: close");
  delay(100);  
  returnmsgWiFi();   
  WiFi_Port.print("Content-Length: ");  
  returnmsgWiFi();  
  WiFi_Port.print(lenss);
  delay(100);  
  returnmsgWiFi();  
  WiFi_Port.print(LINEBREAK);  
  returnmsgWiFi();    
  WiFi_Port.print(LINEBREAK);
  delay(100);  
  returnmsgWiFi();   
  WiFi_Port.print("{\"datastreams\":[{\"id\":\"");
  delay(100);  
  returnmsgWiFi();   
  WiFi_Port.print(sensorid);
  delay(100);  
  returnmsgWiFi();   
  WiFi_Port.print("\",\"datapoints\":[{\"value\":{\"lon\":\"");
  delay(100);  
  returnmsgWiFi();  
  WiFi_Port.print(LON);  
  returnmsgWiFi();      
  WiFi_Port.print("\",\"lat\":\"");
  delay(100);  
  returnmsgWiFi();  
  WiFi_Port.print(LAT);  
  returnmsgWiFi();   
  WiFi_Port.print("\",\"ele\":\"");
  delay(100);  
  returnmsgWiFi();  
  WiFi_Port.print(HEIGH);   
  returnmsgWiFi();     
  WiFi_Port.print("\"}}]}]}");  
  returnmsgWiFi();     
  WiFi_Port.print(LINEBREAK);  
  returnmsgWiFi();  
  WiFi_Port.print(LINEBREAK);  
  WiFi_Port.print(LINEBREAK);  
  WiFi_Port.print(LINEBREAK);
  returnmsg_ok_finishWiFi();    
}
//********************************************************** OneNet  WiFi  send 2 Data *******************************************************************************************************
void send2DataWiFi(String APIkey,int Data1,int Data2,unsigned long deviceid,String sensorid1 ,String sensorid2)
{
  int l1=getLength(Data1);
  int l2=getLength(Data2);
  int D=getLength(deviceid);
  int S1=sensorid1.length(); 
  int S2=sensorid2.length(); 
  int lenss=53+36+S1+l1+S2+l2;                  //Add one sensor lenss Add 36 ,add 1 sensor add 36 1 times;
  int l3=getLength(lenss);
  int lens=214+36+D+S1+l1+S2+l2+l3;             //Add one sensor lens Add 36 ,add 1 sensor add 36 1 times;
  WiFi_Port.println("AT+CIPSTART=\"TCP\",\"183.230.40.33\",80");
  delay(100);
  returnmsg_ok_conWiFi();
  Debug_Port.println("connecting...");
  WiFi_Port.print("AT+CIPSEND=");
  delay(00);
  returnmsgWiFi();
  WiFi_Port.println(lens);
  delay(100); 
  returnmsgWiFi();
  WiFi_Port.print("POST http://api.heclouds.com/devices/");
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print(deviceid);
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print("/datapoints HTTP/1.1");
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print(LINEBREAK);
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print("Host: ");
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print(server);
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print(LINEBREAK);
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print("api-key: ");
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print(APIkey);
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print(LINEBREAK);
  delay(100);
  returnmsgWiFi();
  WiFi_Port.println("Connection: close");
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print("Content-Length: ");
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print(lenss);
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print(LINEBREAK);
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print(LINEBREAK);
  delay(100);
  returnmsgWiFi();
  ////////////////////////////////////////////////////////////////////sensor data
  WiFi_Port.print("{\"datastreams\":[");
  ///////////////////////////////////////////////////////////////////sensor1	
  WiFi_Port.print("{\"id\":\"");
  delay(100);
  WiFi_Port.print(sensorid1);
  delay(100);
  WiFi_Port.print("\",\"datapoints\":[{\"value\":");
  delay(100);
  WiFi_Port.print(Data1);
  delay(100);
  WiFi_Port.print("}]},");
  returnmsgWiFi();
  ///////////////////////////////////////////////////////////////////sensor2	
  WiFi_Port.print("{\"id\":\"");
  delay(100);
  WiFi_Port.print(sensorid2);
  delay(100);
  WiFi_Port.print("\",\"datapoints\":[{\"value\":");
  delay(100);
  WiFi_Port.print(Data2);
  delay(100);
  WiFi_Port.print("}]}");
  returnmsgWiFi();
  ///////////////////////////////////////////////////////////////////sensor end   
  WiFi_Port.print("]}");
  ////////////////////////////////////////////////////sensor data end
  returnmsgWiFi();
  WiFi_Port.print(LINEBREAK);
  WiFi_Port.print(LINEBREAK);
  WiFi_Port.print(LINEBREAK);
  WiFi_Port.print(LINEBREAK);
  returnmsg_ok_finishWiFi();
}
//********************************************************** OneNet  WiFi  send 3 Data *******************************************************************************************************
void send3DataWiFi(String APIkey,int Data1,int Data2,int Data3,unsigned long deviceid,String sensorid1,String sensorid2,String sensorid3)
{
  int l1=getLength(Data1);  
  int l2=getLength(Data2);  
  int l3=getLength(Data3); 
  int D=getLength(deviceid);
  int S1=sensorid1.length();   
  int S2=sensorid2.length();   
  int S3=sensorid3.length(); 
  int lenss=53+36+36+S1+l1+S2+l2+S3+l3;                    //Add one sensor lenss Add 36 ,add 2 sensor add 36 2 times;
  int lll=getLength(lenss);
  int lens=214+36+36+D+lll+S1+l1+S2+l2+S3+l3;              //Add one sensor lens Add 36 ,add 2 sensor add 36 2 times;
  WiFi_Port.println("AT+CIPSTART=\"TCP\",\"183.230.40.33\",80");
  delay(100);
  returnmsg_ok_conWiFi();
  Debug_Port.println("connecting...");
  WiFi_Port.print("AT+CIPSEND=");
  delay(00);
  returnmsgWiFi();
  WiFi_Port.println(lens);
  delay(100); 
  returnmsgWiFi();
  WiFi_Port.print("POST http://api.heclouds.com/devices/");
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print(deviceid);
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print("/datapoints HTTP/1.1");
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print(LINEBREAK);
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print("Host: ");
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print(server);
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print(LINEBREAK);
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print("api-key: ");
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print(APIkey);
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print(LINEBREAK);
  delay(100);
  returnmsgWiFi();
  WiFi_Port.println("Connection: close");
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print("Content-Length: ");
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print(lenss);
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print(LINEBREAK);
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print(LINEBREAK);
  delay(100);
  returnmsgWiFi();
  ////////////////////////////////////////////////////////////////////sensor data
  WiFi_Port.print("{\"datastreams\":[");
  ///////////////////////////////////////////////////////////////////sensor1	
  WiFi_Port.print("{\"id\":\"");
  delay(100);
  WiFi_Port.print(sensorid1);
  delay(100);
  WiFi_Port.print("\",\"datapoints\":[{\"value\":");
  delay(100);
  WiFi_Port.print(Data1);
  delay(100);
  WiFi_Port.print("}]},");
  returnmsgWiFi();
  ///////////////////////////////////////////////////////////////////sensor2	
  WiFi_Port.print("{\"id\":\"");
  delay(100);
  WiFi_Port.print(sensorid2);
  delay(100);
  WiFi_Port.print("\",\"datapoints\":[{\"value\":");
  delay(100);
  WiFi_Port.print(Data2);
  delay(100);
  WiFi_Port.print("}]},");
  returnmsgWiFi();
  ///////////////////////////////////////////////////////////////////sensor2	
  WiFi_Port.print("{\"id\":\"");
  delay(100);
  WiFi_Port.print(sensorid3);
  delay(100);
  WiFi_Port.print("\",\"datapoints\":[{\"value\":");
  delay(100);
  WiFi_Port.print(Data3);
  delay(100);
  WiFi_Port.print("}]}");
  returnmsgWiFi();
  ///////////////////////////////////////////////////////////////////sensor end   
  WiFi_Port.print("]}");
  ////////////////////////////////////////////////////sensor data end
  returnmsgWiFi();
  WiFi_Port.print(LINEBREAK);
  WiFi_Port.print(LINEBREAK);
  WiFi_Port.print(LINEBREAK);
  WiFi_Port.print(LINEBREAK);
  returnmsg_ok_finishWiFi();
}
//********************************************************** OneNet  WiFi  send 4 Data *******************************************************************************************************
void send4DataWiFi(String APIkey,int Data1,int Data2,int Data3,int Data4,unsigned long deviceid,String sensorid1,String sensorid2,String sensorid3,String sensorid4)
{
  int l1=getLength(Data1);
  int l2=getLength(Data2);
  int l3=getLength(Data3);
  int l4=getLength(Data4);
  int D=getLength(deviceid);
  int S1=sensorid1.length(); 
  int S2=sensorid2.length();
  int S3=sensorid3.length();
  int S4=sensorid4.length(); 
  int lenss=53+36+36+36+S1+l1+S2+l2+S3+l3+S4+l4;          //Add one sensor lenss Add 36 ,add 3 sensor add 36 3 times;
  int lll=getLength(lenss);
  int lens=214+36+36+36+D+lll+S1+l1+S2+l2+S3+l3+S4+l4;    //Add one sensor lens Add 36 ,add 3 sensor add 36 3 times;

  WiFi_Port.println("AT+CIPSTART=\"TCP\",\"183.230.40.33\",80");
  delay(100);
  returnmsg_ok_conWiFi();
  Debug_Port.println("connecting...");
  WiFi_Port.print("AT+CIPSEND=");
  delay(00);
  returnmsgWiFi();
  WiFi_Port.println(lens);
  delay(100); 
  returnmsgWiFi();
  WiFi_Port.print("POST http://api.heclouds.com/devices/");
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print(deviceid);
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print("/datapoints HTTP/1.1");
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print(LINEBREAK);
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print("Host: ");
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print(server);
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print(LINEBREAK);
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print("api-key: ");
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print(APIkey);
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print(LINEBREAK);
  delay(100);
  returnmsgWiFi();
  WiFi_Port.println("Connection: close");
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print("Content-Length: ");
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print(lenss);
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print(LINEBREAK);
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print(LINEBREAK);
  delay(100);
  returnmsgWiFi();
  ////////////////////////////////////////////////////////////////////sensor data
  WiFi_Port.print("{\"datastreams\":[");
  ///////////////////////////////////////////////////////////////////sensor1	
  WiFi_Port.print("{\"id\":\"");
  delay(100);
  WiFi_Port.print(sensorid1);
  delay(100);
  WiFi_Port.print("\",\"datapoints\":[{\"value\":");
  delay(100);
  WiFi_Port.print(Data1);
  delay(100);
  WiFi_Port.print("}]},");
  returnmsgWiFi();
  ///////////////////////////////////////////////////////////////////sensor2	
  WiFi_Port.print("{\"id\":\"");
  delay(100);
  WiFi_Port.print(sensorid2);
  delay(100);
  WiFi_Port.print("\",\"datapoints\":[{\"value\":");
  delay(100);
  WiFi_Port.print(Data2);
  delay(100);
  WiFi_Port.print("}]},");
  returnmsgWiFi();
  ///////////////////////////////////////////////////////////////////sensor3	
  WiFi_Port.print("{\"id\":\"");
  delay(100);
  WiFi_Port.print(sensorid3);
  delay(100);
  WiFi_Port.print("\",\"datapoints\":[{\"value\":");
  delay(100);
  WiFi_Port.print(Data3);
  delay(100);
  WiFi_Port.print("}]},");
  returnmsgWiFi();
  ///////////////////////////////////////////////////////////////////sensor4	
  WiFi_Port.print("{\"id\":\"");
  delay(100);
  WiFi_Port.print(sensorid4);
  delay(100);
  WiFi_Port.print("\",\"datapoints\":[{\"value\":");
  delay(100);
  WiFi_Port.print(Data4);
  delay(100);
  WiFi_Port.print("}]}");
  returnmsgWiFi();
  //////////////////////////////////////////////////////////////sensor end   
  WiFi_Port.print("]}");
  ////////////////////////////////////////////////////sensor data end
  returnmsgWiFi();
  WiFi_Port.print(LINEBREAK);
  WiFi_Port.print(LINEBREAK);
  WiFi_Port.print(LINEBREAK);
  WiFi_Port.print(LINEBREAK);
  returnmsg_ok_finishWiFi();
}
//********************************************************** Yeelink  WiFi  send  Data *******************************************************************************************************
void postdateWiFi(int SensorData , String APIKEY , unsigned long DEVICEID ,unsigned long SENSORID)
{
  int l=getLength(SensorData);
  int D=getLength(DEVICEID);
  int S=getLength(SENSORID);
  int lenss=10+l;
  int l2=getLength(lenss);
  int lens=229+D+S+l+l2;

  WiFi_Port.print("AT+CIPSTART=\"TCP\",\"api.yeelink.net\",80");
  WiFi_Port.println("");
  delay(100);
  returnmsg_ok_conWiFi();
  WiFi_Port.print("AT+CIPSEND=");
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print(lens);
  WiFi_Port.println("");
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print("POST /v1.0/device/");
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print(DEVICEID);
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print("/sensor/");
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print(SENSORID);
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print("/datapoints HTTP/1.1");
  WiFi_Port.println("");
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print("Host: api.yeelink.net");
  WiFi_Port.println("");
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print("Accept: */*");
  WiFi_Port.println("");
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print("U-ApiKey:");
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print(APIKEY);
  returnmsgWiFi();
  WiFi_Port.println("");
  delay(100);
  //DebugDebug_Port.print("/datapoints HTTP/1.1\r\nHost: api.yeelink.net\r\nAccept: */*\r\nU-ApiKey:");
  WiFi_Port.print("Content-Length: ");
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print(10+l);
  delay(100);
  returnmsgWiFi();
  WiFi_Port.println("");
  delay(100);
  WiFi_Port.print("Content-Type: application/x-www-form-urlencoded");
  WiFi_Port.println("");
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print("Connection: close");
  delay(100);
  WiFi_Port.println("");
  delay(100);
  WiFi_Port.println("");
  returnmsgWiFi();
  WiFi_Port.print("{\"value\":");
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print(SensorData);
  delay(100);
  returnmsgWiFi();
  WiFi_Port.print("}");
  delay(100);
  WiFi_Port.println("");
  WiFi_Port.println("");
  returnmsg_ok_finishWiFi();
  return;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void returnmsg_okWiFi()
{
  TEMPdata="";
  while(1)
  {
    while(WiFi_Port.available())
    {
      TEMPdata+=char(WiFi_Port.read());
      // DebugDebug_Port.println(TEMPdata);
      delay(2);
    }
    if (TEMPdata.indexOf("OK") > 0)
    {
      Debug_Port.println(TEMPdata); 
      Debug_Port.println("");  
      break;
    }
    else
    {
      delay(1);
    }
  }
  return;
}
//////////////////////////////////////////////////////////////////
void returnmsgWiFi()
{
  TEMPdata="";
  while(!WiFi_Port.available())
  {
  }
  while(WiFi_Port.available())
  {
    TEMPdata+=char(WiFi_Port.read());
    delay(1);
  }
  Debug_Port.print(TEMPdata);   
  return;
}
////////////////////////////////////////////////////////////////
void returnmsg_ok_readyWiFi()
{
  TEMPdata="";
  while(1)
  {
    while(WiFi_Port.available())
    {
      TEMPdata+=char(WiFi_Port.read());
      //DebugDebug_Port.println(TEMPdata); 
      delayMicroseconds(800);                                                          
    }
    if ((TEMPdata.indexOf("OK") > 0)&&(TEMPdata.indexOf("ready") > 0))
    {
      Debug_Port.println(TEMPdata); 
      Debug_Port.println("");  
      break;
    }
  }
  return;
}
////////////////////////////////////////////////////////////////
void returnmsg_ok_conWiFi()
{
  TEMPdata="";
  while(1)
  {
    while(WiFi_Port.available())
    {
      TEMPdata+=char(WiFi_Port.read());
      delay(1);
    }
    if ((TEMPdata.indexOf("OK") > 3)&&(TEMPdata.indexOf("CONNECT") > 0))
    {
      Debug_Port.println(TEMPdata); 
      Debug_Port.println("");  
      break;
    }
  }
  return;
}
/////////////////////////////////////////////////////////////////////
void returnmsg_ok_finishWiFi()
{
  TEMPdata="";
  while(1)
  {
    while(WiFi_Port.available())
    {
      TEMPdata+=char(WiFi_Port.read());
      // DebugDebug_Port.println(TEMPdata); 
      delayMicroseconds(700); 
    }
    if ((TEMPdata.indexOf("CLOSED") > 3)&&(TEMPdata.indexOf("OK") > 0))
    {
      Debug_Port.println(TEMPdata); 
      Debug_Port.println("");  
      break;
    }
    else
    {
      ;
    }
  }
  return;
}
//////////////////////////////////////////////////////////////////////////////////////
void returnmsg_ok_errWiFi()
{
  TEMPdata="";
  while(1)
  {
    while( WiFi_Port.available())
    {
      TEMPdata+=char( WiFi_Port.read());
      //Debug_Port.println(TEMPdata);
      delay(2);
    }
    if ((TEMPdata.indexOf("OK") > 1)||(TEMPdata.indexOf("ERROR") > 1))
    {
      Debug_Port.println(TEMPdata); 
      Debug_Port.println("");  
      break ;
    }
  }
  return ; 

}
/////////////////////////////////////////////////////////////////////////////////////////////////////
void returnmsg_ok_closeWiFi()
{
  TEMPdata="";
  while(1)
  {
    while(WiFi_Port.available())
    {
      TEMPdata+=char(WiFi_Port.read());
      // DebugDebug_Port.println(TEMPdata); 
      delayMicroseconds(700); 
    }
    if ((TEMPdata.indexOf("close") > 3)&&(TEMPdata.indexOf("OK") > 0))
    {
      Debug_Port.println(TEMPdata); 
      Debug_Port.println("");  
      break;
    }
    else
    {
      ;
    }
  }
  return;
}
//////////////////////////////////////////////////////////////////////////////////////

