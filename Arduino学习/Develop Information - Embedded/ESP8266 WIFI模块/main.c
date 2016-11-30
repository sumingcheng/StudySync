/*************	���س�������	**************/
#define MAIN_Fosc		22118400L	//������ʱ��
#define	RX1_Lenth		32			//���ڽ��ջ��峤��
#define	BaudRate1		115200UL	//ѡ������
#define	Timer1_Reload	(65536UL -(MAIN_Fosc / 4 / BaudRate1))		//Timer 1 ��װֵ�� ��Ӧ300KHZ
#define	Timer2_Reload	(65536UL -(MAIN_Fosc / 4 / BaudRate1))		//Timer 2 ��װֵ�� ��Ӧ300KHZ
#include	"STC15Fxxxx.H"
/*************	���ر�������	**************/
u8	idata RX1_Buffer[RX1_Lenth];	//���ջ���
u8	TX1_Cnt;	//���ͼ���
u8	RX1_Cnt;	//���ռ���
bit	B_TX1_Busy;	//����æ��־
/*************	�˿����Ŷ���	**************/
sbit LED1=P1^0;//LED1
sbit LED2=P1^1;//LED2
sbit LED3=P3^7;//LED3
sbit DK1=P3^3;//�̵���
sbit BEEP=P3^4;//������
sbit K1=P1^3;//����1
sbit K2=P1^2;//����2
sbit K3=P1^4;//����3
char led1bl,led2bl,led3bl;
unsigned char LYMS[13]={0x41,0x54,0x2B,0x43,0x57,0x4D,0x4F,0x44,0x45,0x3D,0x32,0x0D,0x0A};//AT+CWMODE=2 ���ó�·��ģʽ
unsigned char SZLY[38]={0x41,0x54,0x2B,0x43,0x57,0x53,0x41,0x50,0x3D,0x22,0x45,0x53,0x50,0x38,0x32,0x36,0x36,0x22,0x2C,0x22,0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x22,0x2C,0x31,0x31,0x2C,0x33,0x0D,0x0A};//AT+CWSAP="ESP8266","0123456789",11,0 ����·��
unsigned char RST[8]={0x41,0x54,0x2B,0x52,0x53,0x54,0x0D,0x0A};//AT+RST ����
unsigned char SZDLJ[13]={0x41,0x54,0x2B,0x43,0x49,0x50,0x4D,0x55,0x58,0x3D,0x31,0x0D,0x0A};//AT+CIPMUX=1 ���óɶ�����
unsigned char KQFU[21]={0x41,0x54,0x2B,0x43,0x49,0x50,0x53,0x45,0x52,0x56,0x45,0x52,0x3D,0x31,0x2C,0x35,0x30,0x30,0x30,0x0D,0x0A};//AT+CIPSERVER=1,5000 ����TCP����˿�
unsigned char FSSJ[11]={0x41,0x54,0x2B,0x43,0x49,0x50,0x53,0x45,0x4E,0x44,0x3D};//AT+CIPSEND= ��������
void Delay1(unsigned long ms)
{
	unsigned char i, j,k;
	for(k=0;k<ms;k++)
	{
		_nop_();
		_nop_();
		i = 22;
		j = 128;
		do
		{
			while (--j);
		} while (--i);
	}
}
void Delay2(unsigned long cnt)
{
	long i;
 	for(i=0;i<cnt*100;i++);
}
void main(void)
{
	char i=0;
	B_TX1_Busy = 0;
	RX1_Cnt = 0;
	TX1_Cnt = 0;
	S1_8bit();				//8λ����
	S1_USE_P30P31();		//UART1 ʹ��P30 P31��	Ĭ��
	AUXR &= ~(1<<4);	//Timer stop		������ʹ��Timer2����
	AUXR |= 0x01;		//S1 BRT Use Timer2;
	AUXR |=  (1<<2);	//Timer2 set as 1T mode
	TH2 = (u8)(Timer2_Reload >> 8);
	TL2 = (u8)Timer2_Reload;
	AUXR |=  (1<<4);	//Timer run enable
	REN = 1;	//�������
	ES  = 1;	//�����ж�
	EA = 1;		//����ȫ���ж�
	P3M1 = 0x00;
  P3M0 = 0xFF;
	RX1_Cnt=0;
	DK1=0;
	BEEP=0;
	Delay2(1000);
	for(i=0;i<13;i++)//AT+CWMODE=2 ���ó�·��ģʽ
	{
		SBUF=LYMS[i];Delay1(1);
	}
	Delay2(1000);
	for(i=0;i<38;i++)//AT+CWSAP="ESP8266","0123456789",11,0 ����·��
	{
		SBUF=SZLY[i];Delay1(1);
	}
	Delay2(1000);
	for(i=0;i<8;i++)//AT+RST ����
	{
		SBUF=RST[i];Delay1(1);
	}
	Delay2(5000);
	for(i=0;i<13;i++)//AT+CIPMUX=1 ���óɶ�����
	{
		SBUF=SZDLJ[i];Delay1(1);
	}
	Delay2(2000);
	for(i=0;i<21;i++)//AT+CIPSERVER=1,5000 ����TCP����˿�
	{
		SBUF=KQFU[i];Delay1(1);
	}
	Delay2(2000);
	while (1)
	{
		if(K1==0)
		{
			Delay1(1);
			if(K1==0)
			{
				LED1=!LED1;
			}
			while(K1==0);
		}
		if(K2==0)
		{
			Delay1(1);
			if(K2==0)
			{
				LED2=!LED2;
			}
			while(K2==0);
		}
		if(K3==0)
		{
			Delay1(1);
			if(K3==0)
			{
				LED3=!LED3;
			}
			while(K3==0);
		}
	}
}

/********************* UART1�жϺ���************************/
void UART1_int (void) interrupt UART1_VECTOR
{
	char i,a,b,c;
	if(RI)
	{
		RI = 0;
		RX1_Buffer[RX1_Cnt] = SBUF;		//����һ���ֽ�
		if(RX1_Buffer[0]==0x45)
		{
			RX1_Cnt++;
		}
		else
		{
			RX1_Cnt=0;
		}
		if(RX1_Cnt>=10)
		{
			if(RX1_Buffer[0]==0x45&&RX1_Buffer[1]==0x53&&RX1_Buffer[2]==0x50)
			{
				if(RX1_Buffer[4]==0x4C&&RX1_Buffer[5]==0x45&&RX1_Buffer[6]==0x44)//�ж�LED
				{
					if(RX1_Buffer[7]==0x31)//�ж�LED1
					{
						if(RX1_Buffer[3]==0x4B)//�жϿ�
						{
							LED1=0;
						}
						if(RX1_Buffer[3]==0x47)//�жϹ�
						{
							LED1=1;
						}
					}
					if(RX1_Buffer[7]==0x32)//�ж�LED2
					{
						if(RX1_Buffer[3]==0x4B)//�жϿ�
						{
							LED2=0;
						}
						if(RX1_Buffer[3]==0x47)//�жϹ�
						{
							LED2=1;
						}
					}
					if(RX1_Buffer[7]==0x33)//�ж�LED3
					{
						if(RX1_Buffer[3]==0x4B)//�жϿ�
						{
							LED3=0;
						}
						if(RX1_Buffer[3]==0x47)//�жϹ�
						{
							LED3=1;
						}
					}
				}
				if(RX1_Buffer[4]==0x4A&&RX1_Buffer[5]==0x44&&RX1_Buffer[6]==0x51)//�жϼ̵���
				{
					if(RX1_Buffer[7]==0x31)//�ж�LED1
					{
						if(RX1_Buffer[3]==0x4B)//�жϿ�
						{
							DK1=1;
						}
						if(RX1_Buffer[3]==0x47)//�жϹ�
						{
							DK1=0;
						}
					}
				}
				if(RX1_Buffer[3]==0x46&&RX1_Buffer[4]==0x4D&&RX1_Buffer[5]==0x51&&RX1_Buffer[6]==0x43&&RX1_Buffer[7]==0x53)//�жϷ�����
				{
					BEEP=1;Delay2(100);BEEP=0;Delay2(100);BEEP=1;Delay2(100);BEEP=0;Delay2(100);
				}
				if(RX1_Buffer[3]==0x43&&RX1_Buffer[4]==0x58&&RX1_Buffer[5]==0x53&&RX1_Buffer[6]==0x4A)//��ѯ����
				{
					if(LED1==0){a=0x4B;}else{a=0x47;}
					if(LED2==0){b=0x4B;}else{b=0x47;}
					if(LED3==0){c=0x4B;}else{c=0x47;}
					for(i=0;i<11;i++)//AT+CIPSEND= ��������
					{
						SBUF=FSSJ[i];Delay1(1);
					}
					SBUF=0x30;Delay1(1);
					SBUF=0x2C;Delay1(1);
					SBUF=0x32;Delay1(1);
					SBUF=0x32;Delay1(1);
					SBUF=0x0D;Delay1(1);
					SBUF=0x0A;Delay1(1);
					
					SBUF=0x45;Delay1(1);
					SBUF=0x53;Delay1(1);
					SBUF=0x50;Delay1(1);
					SBUF=0x4C;Delay1(1);
					SBUF=0x45;Delay1(1);
					SBUF=0x44;Delay1(1);
					SBUF=0x31;Delay1(1);
					SBUF=a;Delay1(1);
					SBUF=0x4C;Delay1(1);
					SBUF=0x45;Delay1(1);
					SBUF=0x44;Delay1(1);
					SBUF=0x32;Delay1(1);
					SBUF=b;Delay1(1);
					SBUF=0x4C;Delay1(1);
					SBUF=0x45;Delay1(1);
					SBUF=0x44;Delay1(1);
					SBUF=0x33;Delay1(1);
					SBUF=c;Delay1(1);
					SBUF=0x50;Delay1(1);
					SBUF=0x53;Delay1(1);
					SBUF=0x45;Delay1(1);
					//45 53 50 4C 45 44 31 4B 4C 45 44 32 4B 4C 45 44 33 4B 50 53 45 
				}
				RX1_Cnt=0;
			}
			else
			{
				RX1_Cnt=0;
			}
			RX1_Cnt=0;
		}
	}
	if(TI)
	{
		TI = 0;
		B_TX1_Busy = 0;		//�������æ��־
	}
}
