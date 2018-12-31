#include "reg52.h"			 

typedef unsigned int u16;	  //���������ͽ�����������
typedef unsigned char u8;


/*******************************************************************************
* ������         :UsartInit()
* ��������		   :���ô���
* ����           : ��
* ���         	 : ��
*******************************************************************************/
void UsartInit()
{
	SCON=0X50;			//����Ϊ������ʽ1
	TMOD=0X20;			//���ü�����������ʽ2
	PCON=0X80;			//�����ʼӱ�
	TH1=0XF3;				//��������ʼֵ���ã�ע�Ⲩ������4800��
	TL1=0XF3;
	ES=1;						//�򿪽����ж�
	EA=1;						//�����ж�
	TR1=1;					//�򿪼�����
}

/*******************************************************************************
* ������         : Usart() interrupt 4
* ��������		  : ����ͨ���жϺ���
* ����           : ��
* ���         	 : ��
*******************************************************************************/
u8 i,val;
u8 arr[6];

/*******************************************************************************
* �� �� ��       : main
* ��������		 : ������
* ��    ��       : ��
* ��    ��    	 : ��
*******************************************************************************/
void main()
{	
	UsartInit();  //	���ڳ�ʼ��
	while(1)
	{
	}		
}



void Usart() interrupt 4
{
	 EA=0;
	 RI=0;
	 arr[i]=SBUF;
	 if(arr[i]==0x88)
	 {
	 	arr[0]=	arr[i];
		i=0;
	 }
	 i++;
	 if(i==6)
  	 {
		i=0;
		if(arr[0]==0x88&&arr[1]==0xfb&&arr[2]==0xAF&&arr[4]==0xfc&&arr[5]==0xfc)
		{
			val=arr[3];
	 		switch (val)
			{
				case 0x00:P0=~0XFE;break;  
				case 0x01:P0=~0XFD;break;
				case 0x02:P0=~0XFB;break;
				case 0x03:P0=~0XF7;break;
				case 0x04:P0=~0XEF;break;
				case 0x05:P0=~0XDF;break;
				case 0x06:P0=~0XBF;break;
				case 0x07:P0=~0X7F;break;
			} 
		}
	 }
 	 EA=1;

}