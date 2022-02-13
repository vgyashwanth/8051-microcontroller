#include<reg51.h>
sbit rs=P3^0;
sbit en=P3^1;
sfr  lcd=0xa0;
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

void main(void){

lcd_int();
	lcd_str(" HELLO WORLD");
	lcd_cmd(0xc0);
	lcd_str("WELCOME");
	delay(10);
	lcd_cmd(0x01);
	lcd_str(" HAPPY *DIWALI*");
	lcd_cmd(0xc0);
	lcd_str(" ***TO ALL*** ");
	while(1);}

