#define Addr_GND 0x30
#define Addr 0x30

#define R 0xFF
#define G 0xFF
#define B 0xFF
//#define byte int

#include <Wire.h>
#include <pgmspace.h>

extern void IS31FL3741_PWM_Write(int iColor, int iX, int iY, int idata);