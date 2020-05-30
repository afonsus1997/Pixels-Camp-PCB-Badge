/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "main.h"

volatile u8 Mode_NO = 1;

int main(void)
{
	Set_System();
	I2C_GPIO_Init();
	USB_Interrupts_Config();//	
	Set_USBClock();//
	USB_Init();//
	EXTI_PB0_Config();
	#if  VERSION==1
	IS31FL3741_Init();
	#elif VERSION==2
	IS31FL3742_Init();
	#endif
	while(1)	
	{
		#if  VERSION==1
 		Play_IS31FL3741_Demo_mode();
		#elif VERSION==2
		Play_IS31FL3742_Demo_mode();
		#endif
	}
}

/*********************************END OF FILE**********************************/
