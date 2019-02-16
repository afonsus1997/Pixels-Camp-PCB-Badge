/* Includes ------------------------------------------------------------------*/
#include "../include/main.h"
#include <Arduino.h>
#include <Wire.h>
volatile uint8_t Mode_NO = 1;


void setup(){
 Wire.begin(23,22);
 Wire.setClock(100000);//I2C 1MHz
 IS31FL3741_Init();
 
}


void loop()
{
	
	while(1)	
	{
		//#if  VERSION==1
 		//Play_IS31FL3741_Demo_mode();
		//#elif VERSION==2
		//Play_IS31FL3741_Demo_mode();
		IS31FL3741_Mode_1();
	}
}

/*********************************END OF FILE**********************************/
