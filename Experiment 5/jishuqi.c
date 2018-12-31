#include<reg51.h>
#include<stdio.h>
typedef unsigned char u8;


unsigned int i=1;
u8 code smgduan[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
					0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};//ÏÔÊ¾0~FµÄÖµ

 
void DelayMs(unsigned int x)
{
	unsigned char i;
	while(x--)
		for(i=0;i<120;i++);
}

void init(){
	TMOD=0x60;
	TH1=0xff;
	TL1=0xff;
	TR1=1;
	ET1=1;
	EA=1;
}

void main()
{
	init();
	while(1);
}


void add() interrupt 3
{
	if(!T1){
		DelayMs(50);
		if(!T1)
		while(!T1);
	P1=~smgduan[i];
	i++;
	
	}	
}





