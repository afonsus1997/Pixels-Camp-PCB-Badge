/* Define to prevent recursive inclusion ------------------------------------ */ 
#ifndef __IS31FL3741_H 
#define __IS31FL3741_H 
#define Addr_GND_GND  0x60
#include <Arduino.h>
void Play_IS31FL3741_Demo_mode(void);
void IS31FL3741_Init(void);
extern int I2C_WriteByte(int DeviceAddress, int WriteAddress, int SendByte);
 
#endif 
