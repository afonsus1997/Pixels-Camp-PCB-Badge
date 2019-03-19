
#define R_LED 0
#define G_LED 1
#define B_LED 2
#define byte int
#define Addr_GND 0x30


#include <pgmspace.h>

extern void I2CWriteByte(int Dev_Add,int Reg_Add,int Reg_Dat);

void IS31FL3741_PWM_Write(int iColor, int iX, int iY, int idata)
{
	switch(iX)
	{
							case 1 :switch(iY)
											{
												case 1:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x02,idata);break;
												case 2:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x05,idata);break;
												case 3:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x08,idata);break;
												case 4:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x0B,idata);break;
												case 5:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x0E,idata);break;
												case 6:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x11,idata);break;
												case 7:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x14,idata);break;
												case 8:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x17,idata);break;
												case 9:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x1A,idata);break;
												case 10:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x1D,idata);break;
												case 11:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x5C,idata);break;
												case 12:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x5F,idata);break;
												case 13:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x62,idata);break;
												default: break;
											}break;
							case 2 :switch(iY)
											{
												case 1:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x20,idata);break;
												case 2:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x23,idata);break;
												case 3:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x26,idata);break;
												case 4:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x29,idata);break;
												case 5:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x2C,idata);break;
												case 6:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x2F,idata);break;
												case 7:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x32,idata);break;
												case 8:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x35,idata);break;
												case 9:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x38,idata);break;
												case 10:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x3B,idata);break;
												case 11:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x65,idata);break;
												case 12:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x68,idata);break;
												case 13:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x6B,idata);break;
												default: break;
											}break;
							case 3 :switch(iY)
											{
												case 1:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x3E,idata);break;
												case 2:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x41,idata);break;
												case 3:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x44,idata);break;
												case 4:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x47,idata);break;
												case 5:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x4A,idata);break;
												case 6:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x4D,idata);break;
												case 7:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x50,idata);break;
												case 8:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x53,idata);break;
												case 9:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x56,idata);break;
												case 10:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x59,idata);break;
												case 11:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x6E,idata);break;
												case 12:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x71,idata);break;
												case 13:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x74,idata);break;
												default: break;
											}break;
							case 4 :switch(iY)
											{
												case 1:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x5C,idata);break;
												case 2:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x5F,idata);break;
												case 3:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x62,idata);break;
												case 4:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x65,idata);break;
												case 5:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x68,idata);break;
												case 6:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x6B,idata);break;
												case 7:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x6E,idata);break;
												case 8:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x71,idata);break;
												case 9:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x74,idata);break;
												case 10:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x77,idata);break;
												case 11:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x77,idata);break;
												case 12:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x7A,idata);break;
												case 13:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x7D,idata);break;
												default: break;
											}break;
							case 5 :switch(iY)
											{
												case 1:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x7A,idata);break;
												case 2:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x7D,idata);break;
												case 3:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x80,idata);break;
												case 4:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x83,idata);break;
												case 5:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x86,idata);break;
												case 6:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x89,idata);break;
												case 7:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x8C,idata);break;
												case 8:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x8F,idata);break;
												case 9:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x92,idata);break;
												case 10:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x95,idata);break;
												case 11:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x80,idata);break;
												case 12:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x83,idata);break;
												case 13:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x86,idata);break;
												default: break;
											}break;
							case 6 :switch(iY)
											{
												case 1:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x98,idata);break;
												case 2:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x9B,idata);break;
												case 3:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x9E,idata);break;
												case 4:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0xA1,idata);break;
												case 5:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0xA4,idata);break;
												case 6:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0xA7,idata);break;
												case 7:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0xAA,idata);break;
												case 8:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0xAD,idata);break;
												case 9:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0xB0,idata);break;
												case 10:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0xB3,idata);break;
												case 11:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x89,idata);break;
												case 12:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x8C,idata);break;
												case 13:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x8F,idata);break;
												default: break;
											}break;
							case 7 :switch(iY)
											{
												case 1:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x02,idata);break;
												case 2:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x05,idata);break;
												case 3:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x08,idata);break;
												case 4:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x0B,idata);break;
												case 5:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x0E,idata);break;
												case 6:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x11,idata);break;
												case 7:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x14,idata);break;
												case 8:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x17,idata);break;
												case 9:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x1A,idata);break;
												case 10:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x1D,idata);break;
												case 11:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x92,idata);break;
												case 12:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x95,idata);break;
												case 13:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x98,idata);break;
												default: break;
											}break;
							case 8 :switch(iY)
											{
												case 1:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x20,idata);break;
												case 2:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x23,idata);break;
												case 3:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x26,idata);break;
												case 4:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x29,idata);break;
												case 5:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x2C,idata);break;
												case 6:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x2F,idata);break;
												case 7:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x32,idata);break;
												case 8:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x35,idata);break;
												case 9:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x38,idata);break;
												case 10:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x3B,idata);break;
												case 11:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x9B,idata);break;
												case 12:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x9E,idata);break;
												case 13:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0xA1,idata);break;
												default: break;
											}break;
							case 9 :switch(iY)
											{
												case 1:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x3E,idata);break;
												case 2:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x41,idata);break;
												case 3:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x44,idata);break;
												case 4:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x47,idata);break;
												case 5:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x4A,idata);break;
												case 6:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x4D,idata);break;
												case 7:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x50,idata);break;
												case 8:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x53,idata);break;
												case 9:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x56,idata);break;
												case 10:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x59,idata);break;
												case 11:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0xA4,idata);break;
												case 12:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0xA7,idata);break;
												case 13:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0xAA,idata);break;
												default: break;
											}break;
							case 10 :switch(iY)
											{
												case 1:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x01,idata);break;
												case 2:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x04,idata);break;
												case 3:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x07,idata);break;
												case 4:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x0A,idata);break;
												case 5:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x0D,idata);break;
												case 6:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x10,idata);break;
												case 7:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x13,idata);break;
												case 8:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x16,idata);break;
												case 9:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x19,idata);break;
												case 10:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x1C,idata);break;
												case 11:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x5B,idata);break;
												case 12:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x5E,idata);break;
												case 13:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x61,idata);break;
												default: break;
											}break;
							case 11:switch(iY)
											{
												case 1:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x1F,idata);break;
												case 2:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x22,idata);break;
												case 3:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x25,idata);break;
												case 4:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x28,idata);break;
												case 5:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x2B,idata);break;
												case 6:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x2E,idata);break;
												case 7:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x31,idata);break;
												case 8:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x34,idata);break;
												case 9:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x37,idata);break;
												case 10:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x3A,idata);break;
												case 11:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x64,idata);break;
												case 12:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x67,idata);break;
												case 13:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x6A,idata);break;
												default: break;
											}break;
							case 12 :switch(iY)
											{
												case 1:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x3D,idata);break;
												case 2:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x40,idata);break;
												case 3:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x43,idata);break;
												case 4:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x46,idata);break;
												case 5:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x49,idata);break;
												case 6:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x4C,idata);break;
												case 7:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x4F,idata);break;
												case 8:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x52,idata);break;
												case 9:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x55,idata);break;
												case 10:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x58,idata);break;
												case 11:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x6D,idata);break;
												case 12:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x70,idata);break;
												case 13:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x73,idata);break;
												default: break;
											}break;
							case 13 :switch(iY)
											{
												case 1:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x5B,idata);break;
												case 2:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x5E,idata);break;
												case 3:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x61,idata);break;
												case 4:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x64,idata);break;
												case 5:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x67,idata);break;
												case 6:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x6A,idata);break;
												case 7:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x6D,idata);break;
												case 8:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x70,idata);break;
												case 9:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x73,idata);break;
												case 10:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x76,idata);break;
												case 11:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x76,idata);break;
												case 12:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x79,idata);break;
												case 13:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x7C,idata);break;
												default: break;
											}break;
							case 14 :switch(iY)
											{
												case 1:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x79,idata);break;
												case 2:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x7C,idata);break;
												case 3:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x7F,idata);break;
												case 4:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x82,idata);break;
												case 5:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x85,idata);break;
												case 6:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x88,idata);break;
												case 7:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x8B,idata);break;
												case 8:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x8E,idata);break;
												case 9:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x91,idata);break;
												case 10:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x94,idata);break;
												case 11:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x7F,idata);break;
												case 12:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x82,idata);break;
												case 13:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x85,idata);break;
												default: break;
											}break;
							case 15 :switch(iY)
											{
												case 1:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x97,idata);break;
												case 2:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x9A,idata);break;
												case 3:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x9D,idata);break;
												case 4:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0xA0,idata);break;
												case 5:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0xA3,idata);break;
												case 6:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0xA6,idata);break;
												case 7:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0xA9,idata);break;
												case 8:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0xAC,idata);break;
												case 9:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0xAF,idata);break;
												case 10:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0xB2,idata);break;
												case 11:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x88,idata);break;
												case 12:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x8B,idata);break;
												case 13:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x8E,idata);break;
												default: break;
											}break;
							case 16 :switch(iY)
											{
												case 1:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x01,idata);break;
												case 2:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x04,idata);break;
												case 3:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x07,idata);break;
												case 4:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x0A,idata);break;
												case 5:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x0D,idata);break;
												case 6:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x10,idata);break;
												case 7:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x13,idata);break;
												case 8:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x16,idata);break;
												case 9:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x19,idata);break;
												case 10:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x1C,idata);break;
												case 11:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x91,idata);break;
												case 12:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x94,idata);break;
												case 13:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x97,idata);break;
												default: break;
											}break;
							case 17 :switch(iY)
											{
												case 1:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x1F,idata);break;
												case 2:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x22,idata);break;
												case 3:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x25,idata);break;
												case 4:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x28,idata);break;
												case 5:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x2B,idata);break;
												case 6:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x2E,idata);break;
												case 7:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x31,idata);break;
												case 8:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x34,idata);break;
												case 9:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x37,idata);break;
												case 10:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x3A,idata);break;
												case 11:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x9A,idata);break;
												case 12:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x9D,idata);break;
												case 13:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0xA0,idata);break;
												default: break;
											}break;
							case 18 :switch(iY)
											{
												case 1:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x3D,idata);break;
												case 2:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x40,idata);break;
												case 3:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x43,idata);break;
												case 4:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x46,idata);break;
												case 5:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x49,idata);break;
												case 6:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x4C,idata);break;
												case 7:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x4F,idata);break;
												case 8:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x52,idata);break;
												case 9:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x55,idata);break;
												case 10:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x58,idata);break;
												case 11:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0xA3,idata);break;
												case 12:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0xA6,idata);break;
												case 13:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0xA9,idata);break;
												default: break;
											}break;
							case 19 :switch(iY)
											{
												case 1:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x00,idata);break;
												case 2:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x03,idata);break;
												case 3:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x06,idata);break;
												case 4:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x09,idata);break;
												case 5:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x0c,idata);break;
												case 6:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x0f,idata);break;
												case 7:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x12,idata);break;
												case 8:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x15,idata);break;
												case 9:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x18,idata);break;
												case 10:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x1B,idata);break;
												case 11:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x5A,idata);break;
												case 12:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x5D,idata);break;
												case 13:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x60,idata);break;
												default: break;
											}break;
							case 20 :switch(iY)
											{
												case 1:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x1E,idata);break;
												case 2:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x21,idata);break;
												case 3:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x24,idata);break;
												case 4:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x27,idata);break;
												case 5:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x2A,idata);break;
												case 6:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x2D,idata);break;
												case 7:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x30,idata);break;
												case 8:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x33,idata);break;
												case 9:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x36,idata);break;
												case 10:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x39,idata);break;
												case 11:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x63,idata);break;
												case 12:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x66,idata);break;
												case 13:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x69,idata);break;
												default: break;
											}break;
							case 21 :switch(iY)
											{
												case 1:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x3C,idata);break;
												case 2:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x3F,idata);break;
												case 3:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x42,idata);break;
												case 4:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x45,idata);break;
												case 5:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x48,idata);break;
												case 6:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x4B,idata);break;
												case 7:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x4E,idata);break;
												case 8:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x51,idata);break;
												case 9:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x54,idata);break;
												case 10:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x57,idata);break;
												case 11:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x6C,idata);break;
												case 12:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x6F,idata);break;
												case 13:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x72,idata);break;
												default: break;
											}break;
							case 22 :switch(iY)
											{
												case 1:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x5A,idata);break;
												case 2:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x5D,idata);break;
												case 3:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x60,idata);break;
												case 4:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x63,idata);break;
												case 5:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x66,idata);break;
												case 6:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x69,idata);break;
												case 7:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x6C,idata);break;
												case 8:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x6F,idata);break;
												case 9:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x72,idata);break;
												case 10:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x75,idata);break;
												case 11:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x75,idata);break;
												case 12:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x78,idata);break;
												case 13:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x7B,idata);break;
												default: break;
											}break;
							case 23 :switch(iY)
											{
												case 1:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x78,idata);break;
												case 2:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x7B,idata);break;
												case 3:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x7E,idata);break;
												case 4:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x81,idata);break;
												case 5:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x84,idata);break;
												case 6:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x87,idata);break;
												case 7:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x8A,idata);break;
												case 8:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x8D,idata);break;
												case 9:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x90,idata);break;
												case 10:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x93,idata);break;
												case 11:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x7E,idata);break;
												case 12:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x81,idata);break;
												case 13:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x84,idata);break;
												default: break;
											}break;
							case 24 :switch(iY)
											{
												case 1:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x96,idata);break;
												case 2:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x99,idata);break;
												case 3:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x9C,idata);break;
												case 4:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x9F,idata);break;
												case 5:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0xA2,idata);break;
												case 6:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0xA5,idata);break;
												case 7:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0xA8,idata);break;
												case 8:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0xAB,idata);break;
												case 9:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0xAE,idata);break;
												case 10:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0xB1,idata);break;
												case 11:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x87,idata);break;
												case 12:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x8A,idata);break;
												case 13:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x8D,idata);break;
												default: break;
											}break;
							case 25 :switch(iY)
											{
												case 1:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x00,idata);break;
												case 2:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x03,idata);break;
												case 3:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x06,idata);break;
												case 4:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x09,idata);break;
												case 5:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x0C,idata);break;
												case 6:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x0F,idata);break;
												case 7:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x12,idata);break;
												case 8:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x15,idata);break;
												case 9:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x18,idata);break;
												case 10:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x1B,idata);break;
												case 11:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x90,idata);break;
												case 12:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x93,idata);break;
												case 13:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x96,idata);break;
												default: break;
											}break;
							case 26 :switch(iY)
											{
												case 1:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x1E,idata);break;
												case 2:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x21,idata);break;
												case 3:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x24,idata);break;
												case 4:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x27,idata);break;
												case 5:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x2A,idata);break;
												case 6:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x2D,idata);break;
												case 7:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x30,idata);break;
												case 8:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x33,idata);break;
												case 9:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x36,idata);break;
												case 10:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x39,idata);break;
												case 11:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x99,idata);break;
												case 12:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x9C,idata);break;
												case 13:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x9F,idata);break;
												default: break;
											}break;
							case 27 :switch(iY)
											{
												case 1:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x3C,idata);break;
												case 2:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x3F,idata);break;
												case 3:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x42,idata);break;
												case 4:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x45,idata);break;
												case 5:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x48,idata);break;
												case 6:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x4B,idata);break;
												case 7:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x4E,idata);break;
												case 8:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x51,idata);break;
												case 9:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x54,idata);break;
												case 10:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x57,idata);break;
												case 11:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0xA2,idata);break;
												case 12:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0xA5,idata);break;
												case 13:I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0xA8,idata);break;
												default: break;
											}break;
		default: break;
		}
}

