#include<reg51.h>
sbit led=P1^5;
void delay(void);
void main(void){
unsigned int i;
	while(1){
	led=1;
		for(i=0;i<=20;i++)
{delay();}
		led=0;
		for(i=0;i<=20;i++)
{delay();}
	
	
	
	}


}





void delay(void){

TMOD=0x01;
	TH0=0x4B;
	TL0=0xFE;
	TR0=1;
	

	while(TF0==0){}
		
		TF0=0;
		TR0=0;}
