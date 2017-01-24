int LED_G = 6; //设置绿色LED的数字IO脚
int LED_R = 5; //设置红色LED的数字IO脚
int Timer = 5000;
int OP = 1;

void SendMessage()
{
  Serial.print("AT+CSCS=");
  Serial.print('"');
  Serial.print("GSM");
  Serial.print('"');
  Serial.print("\r\n");

  delay(1000);
  Serial.print("AT+CMGF=1\r\n");
  delay(1000);

  Serial.print("AT+CMGS=");
  Serial.print('"');
  Serial.print("13354208848");      //发送目标手机号在这里设置18602423721
  Serial.print('"');
  Serial.print("\r\n");
  delay(1000);
  Serial.print("Hello World!");     //短信内容
  delay(1000);
  Serial.write(0x1A);               //发送操作
  delay(1000);
  wait_SendMessage();                 //发短信后延时
}

void wait_SendMessage() {
  int Time = 30;
  while (Time--) {
    delay(60000);             //1分钟
  }
}

void wait_Sampling() {
  int Time = 5;
  while (Time--) {
    delay(60000);             //1分钟
  }
}

void showVoltageValue(int i) {
  Serial.print("Voltage Value:" );
  Serial.print(i);
  Serial.println();
}

void setup()
{
  Serial.begin(9600);
  pinMode(LED_G, OUTPUT); //设置数字IO引脚为输出模式
  pinMode(LED_R, OUTPUT); //设置数字IO引脚为输出模式
  digitalWrite(LED_R, HIGH); //设置引脚为低电平，点亮led灯
  digitalWrite(LED_G, HIGH); //设置引脚为高电平，点亮led灯
  delay(5000);
  Serial.println("Redly!");
  digitalWrite(LED_R, LOW); //设置引脚为低电平，点亮led灯
  digitalWrite(LED_G, LOW); //设置引脚为高电平，点亮led灯

}
void loop()
{
  int i;//定义变量·
  int k = 0;
  while (OP)
  {
    i = analogRead(5); //读取模拟5口电压值
    for (int st = 0; st < 3; st++) {  // st : SamplingTime

      showVoltageValue(i);//显示电压

      if (i < 600) //如果电压值大于600
      {
        k++;
        delay(1000);
      } else {
        wait_Sampling();
        k = 0;
        break;
      }
    }

    if (k < 3) {
      digitalWrite(LED_R, LOW); //设置引脚为低电平，点亮led灯
      digitalWrite(LED_G, HIGH); //设置引脚为高电平，点亮led灯
    } else {
      digitalWrite(LED_G, LOW); //设置引脚为低电平，熄灭led灯
      digitalWrite(LED_R, HIGH); //设置引脚为高电平，点亮led灯
      SendMessage();
      OP = 0;
    }
  }
  OP = 1;
}
