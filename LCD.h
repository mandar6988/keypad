# define RS (1<<12);
//# define RW (1<<13) ;
# define EN (1<<13)	;
# define data_pins (0xFF<<0) 

void delay(unsigned int count)
{

unsigned int i,j;
	for(i=0;i<100;i++)
		{
			for(j=0;j<count;j++)

				{

				}
		}
 }

void LCD_DATA(unsigned char data)
{
unsigned int temp;
temp=data;

 IOSET0=((temp&0XF0)<<4);
 IOSET0=RS;
// IOCLR0=RW;
 IOSET0=EN;
 delay(5);
 IOCLR0=EN;
 IOCLR0=((temp&0XF0)<<4);
 temp=data;
 IOSET0=((temp&0x0F)<<8);
 IOSET0=RS;
// IOCLR0=RW;
 IOSET0=EN;
 delay(5);
 IOCLR0=EN;
 IOCLR0=((temp&0x0F)<<8);
}

void LCD_CMD(unsigned char data)						    
{
 unsigned int temp;
 temp=data;
 IOSET0=((temp&0XF0)<<4);
 IOCLR0=RS;
 //IOCLR0=RW;
 IOSET0=EN;
 delay(5);
 IOCLR0=EN ;
 IOCLR0=((temp&0XF0)<<4);
 temp=data;
 IOSET0=((temp&0x0F)<<8);
 IOCLR0=RS;
// IOCLR0=RW;
 IOSET0=EN;
 delay(5);
 IOCLR0=EN ;
 IOCLR0=((temp&0x0F)<<8);
}


unsigned char LCD_PRINT (unsigned char *x )
     {
	while(*x!='\0')
	{
		LCD_DATA(*x);
		x++;
	}	 
 }


unsigned char LCD_INIT (void)
{
 LCD_CMD(0X02);
 delay(15);
 LCD_CMD(0X28);
 delay(15);
  LCD_CMD(0X0C);
 delay(15);
    LCD_CMD(0X01);
 delay(15);
   LCD_CMD(0X06);
 delay(15);
     LCD_CMD(0X80) ;
 delay(5);



}


