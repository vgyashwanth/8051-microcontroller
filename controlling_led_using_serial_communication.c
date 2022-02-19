#include<reg51.h>
sbit rs=P2^0;
sbit en=P2^1;
sfr  lcd=0x90;
sbit sw=P2^2;
sbit led=P2^3;
void delay(unsigned int k);
void delay(unsigned int k){
unsigned int i,j;
	for(i=0;i<=k;i++){
	for(j=0;j<=1245;j++){}}
}
void lcd_cmd(unsigned char a);
void lcd_cmd(unsigned char a){
	rs=0;
	lcd= a;
	en=1;
	delay(1);
	en=0;
	delay(1);
}
void lcd_data(unsigned char b);
void lcd_data(unsigned char b){
	rs=1;
	lcd=b;
	en=1;
	delay(1);
	en=0;
	delay(1);
}
void lcd_str(unsigned char *str);
void lcd_str(unsigned char *str){
while(*str){
lcd_data(*str++);
}
}
void lcd_int(void);
void lcd_int(void){
	lcd_cmd(0x38);
	lcd_cmd(0x0c);
	lcd_cmd(0x01);
	lcd_cmd(0x80);


}
void serial_data(unsigned char b);
void serial_data(unsigned char b){
	SBUF=b;
	while(TI==0);
	TI=0;


}


void serial_str(unsigned char *str);
void serial_str(unsigned char *str){

while(*str){

 serial_data(*str++);


}
	

}


void main(void){
	sw=0;
TMOD=0x20;
	TH1=0xFD;
	SCON=0x50;
	TR1=1;
	lcd_int();
	lcd_str("  LED STATUS   ");
	
	while(1){

	if(sw==0){
	led=0;
		lcd_cmd(0xc0);
		lcd_str("  LED OFF ");
	serial_str("LED OFF ");
		serial_data(0x0d);
		while(sw==0);
	
	}else{
	led=1;
		lcd_cmd(0xc0);
		lcd_str("  LED ON  ");
		serial_str("LED ON ");
		serial_data(0x0d);//used to shift new line in serial monitor
	while(sw==1);
	}
}
	
	
	
	
	
	
	}

