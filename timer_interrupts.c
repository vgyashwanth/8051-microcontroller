#include<reg51.h>
sbit wave=P2^0;
void delay(void);
sbit led=P2^1;
void timer0_int(void) interrupt 1
{
wave=~wave;
}
void main(void){

TMOD=0x02;
	TH0=0XF0;
	
	TL0=0XF0;
	
	IE=0X82;
	TR0=1;
	while(1){
	led=1;
		delay();
		led=0;
		delay();
	
	}



}


void delay(void){

TMOD=0x01;
	TH0=0XFF;
	TL0=0XFE;
	TR0=1;
	while(TF0==0);
	TR0=0;
	TF0=0;

}
