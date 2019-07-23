#include <lpc21xx.h>   
#include"LCD.h"
#define key1 16
#define key2 17
#define key3 18
#define key4 19
#define Led1 4
#define Led2 5
#define Led3 6
#define Led4 7
/* start the main program */
int main() 
{
unsigned  int  switch;
 IODIR0 = 0xFFF0FFFF; 
    
	LCD_INIT();
    	delay(1000);
	LCD_PRINT("LCD Initialised");
	LCD_CMD(0x01);
	delay(10000);
   

  while(1)
    {

	delay(50000);
	IOCLR0=0x00000000;
	switch=0x00;
       switch = (IO0PIN);      
       if(switch ==1<<key1 )                 /
       	{  
        	 IOPIN0 = 0x00000010;
       	 
		LCD_CMD(0xC0);
		LCD_PRINT("key 1");
	  	//delay(50000);
	
	}
       else if(switch ==1<<key2)
	    
       {
         IOPIN0 = 0x00000020;
     	 LCD_PRINT("key 2");
	   }
	else if(switchs == 1<<key3)
	    
       {
         IOPIN0 = 0x00000040;
	 LCD_PRINT("key 3");
       } 
	else if(switch== 1<<key4)
	    
       {
         IOPIN0 = 0x00000080;
	 LCD_PRINT("key 4");
       }       
	   else
	   {
	   	 IOPIN0 = (0x00000000);
	   }

    }
}