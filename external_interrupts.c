#include<reg51.h>
sbit led=P1^0;
sbit l=P1^1;
void delay(void);
void delay(void){

unsigned int i;

	for(i=0;i<=50000;i++){
	
}

}

void ex1_int(void) interrupt 4
{while(RI==0);
	P2=SBUF;
	RI=0;
delay();
	}

void main(void){
TMOD=0X20;
	TH1=0XFD;
	SCON=0X50;
	TR1=1;
IE=0x90;
	
	
while(1){
	
	
	l=1;
	delay();
	l=0;
	delay();


}

}
