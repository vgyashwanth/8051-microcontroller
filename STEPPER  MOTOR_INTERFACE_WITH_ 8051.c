#include<reg51.h>
void delay(unsigned int k);
sbit wave_form=P3^0;
sbit full_form=P3^1;
sbit half_form=P3^2;
void main(void){
wave_form=0;
	full_form=0;
	half_form=0;
	P2=0x00;
while(1){

 if(wave_form==1){
 
 P2=0x01;
	 delay(1);
	 P2=0x02;
	 delay(1);
	 P2=0x04;
	 delay(1);
	 P2=0x08;
	 delay(1);
 }
	else if(full_form==1){
	
	P2=0x0A;
		delay(2);
		P2=0x05;
		delay(2);
	
	}
	else if(half_form==1){
	
		P2=0x01;
		delay(1);
		P2=0x03;
		delay(1);
		P2=0x02;
		delay(1);
		P2=0x06;
		delay(1);
		P2=0x04;
		delay(1);
		P2=0x0C;
		delay(1);
		P2=0x08;
		delay(1);
		P2=0x09;
		delay(1);
		
	
	
	
	
	}else{
	
	P2=0x00;
	
	}
	
}
}
void delay(unsigned int k){
	double i,j;
	for(i=0;i<k;i++){
for(j=0;j<=19;j++){	
	TMOD=0x01;
	TH0=0x4B;
	TL0=0xFE;
	TR0=1;
	while(TF0==0){}
		TR0=0;
		TF0=0;}
	
	}

}
