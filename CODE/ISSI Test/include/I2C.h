
/*******************************************************************************
*File Name          : 2124_i2c_.h 
*Author             : MCD Application Team 
* Version            : V2.0.1 
* Date               : 06/10/2015
* Description        : Header for i2c_ee.c module 
********************************************************************************/ 
/* Define to prevent recursive inclusion ------------------------------------ */ 
 #ifndef __I2C_H 
 #define __I2C_H 

/* Includes ------------------------------------------------------------------*/ 
/* Exported types ------------------------------------------------------------*/ 
/* Exported constants --------------------------------------------------------*/ 


/* Exported macro ------------------------------------------------------------*/ 
/* Exported functions ------------------------------------------------------- */ 

#define Addr_GND_GND  0x60

#define TRUE1	1
#define FALSE1 0
#define FALSE2 2
/*
#define SCL_H         GPIOB->BSRR = GPIO_Pin_6 
#define SCL_L         GPIOB->BRR  = GPIO_Pin_6  
    
#define SDA_H         GPIOB->BSRR = GPIO_Pin_7
#define SDA_L         GPIOB->BRR  = GPIO_Pin_7 

#define SCL_read      GPIOB->IDR  & GPIO_Pin_6 
#define SDA_read      GPIOB->IDR  & GPIO_Pin_7 

#define LEDR_H        GPIOB->BSRR = GPIO_Pin_14 
#define LEDR_L        GPIOB->BRR  = GPIO_Pin_14 

#define SDB_H         GPIOB->BSRR = GPIO_Pin_15 
#define SDB_L         GPIOB->BRR = GPIO_Pin_15

#define MISO_H         GPIOA->BSRR = GPIO_Pin_6 
#define MISO_L         GPIOA->BRR = GPIO_Pin_6 
*/
#include <Wire.h>

void delay_ms(uint32_t t);
void I2C_GPIO_Init(void);
int I2C_WriteByte(int DeviceAddress, int WriteAddress, int SendByte);
int I2C_Write2Byte(int WriteAddress, int SendByte);
int I2C_ReadByte(int DeviceAddress,int ReadAddress);
int I2C_WriteBuffer(uint8_t* pBuffer,int length,int DeviceAddress ,int WriteAddress);
#endif /* __2124_I2C_H */ 

