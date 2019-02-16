#include "../include/main.h"
#include "../include/IS31FL3741.h"

#include<stdlib.h>

extern volatile int Mode_NO;

unsigned char RGB_32PWM_IS31FL3741[144]=
{
	0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
	0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
	0X03,0x07,0x0D,0x16,0x1F,0x2E,0x40,0x4f,
	0X64,0x77,0x8D,0xA7,0xBF,0xD6,0xF1,0xFF,
	0XFF,0xF1,0xD6,0xBF,0xA7,0x8D,0x77,0X64,
	0x4f,0x40,0x2E,0x1F,0x16,0x0D,0x07,0X03,
	0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
	0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
	0X03,0x07,0x0D,0x16,0x1F,0x2E,0x40,0x4f,
	0X64,0x77,0x8D,0xA7,0xBF,0xD6,0xF1,0xFF,
	0XFF,0xF1,0xD6,0xBF,0xA7,0x8D,0x77,0X64,
	0x4f,0x40,0x2E,0x1F,0x16,0x0D,0x07,0X03,
	0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
	0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
	0X03,0x07,0x0D,0x16,0x1F,0x2E,0x40,0x4f,
	0X64,0x77,0x8D,0xA7,0xBF,0xD6,0xF1,0xFF,
	0XFF,0xF1,0xD6,0xBF,0xA7,0x8D,0x77,0X64,
	0x4f,0x40,0x2E,0x1F,0x16,0x0D,0x07,0X03,
};

int RGB_PWM_IS31FL3741[512]=
{
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,
	0x08,0x09,0x0b,0x0d,0x0f,0x11,0x13,0x16,
	0x1a,0x1c,0x1d,0x1f,0x22,0x25,0x28,0x2e,
	0x34,0x38,0x3c,0x40,0x44,0x48,0x4b,0x4f,
	0x55,0x5a,0x5f,0x64,0x69,0x6d,0x72,0x77,
	0x7d,0x80,0x88,0x8d,0x94,0x9a,0xa0,0xa7,
	0xac,0xb0,0xb9,0xbf,0xc6,0xcb,0xcf,0xd6,
	0xe1,0xe9,0xed,0xf1,0xf6,0xfa,0xfe,0xff,

	0xff,0xfe,0xfa,0xf6,0xf1,0xed,0xe9,0xe1,
	0xd6,0xcf,0xcb,0xc6,0xbf,0xb9,0xb0,0xac,
	0xa7,0xa0,0x9a,0x94,0x8d,0x88,0x80,0x7d,
	0x77,0x72,0x6d,0x69,0x64,0x5f,0x5a,0x55,
	0x4f,0x4b,0x48,0x44,0x40,0x3c,0x38,0x34,
	0x2e,0x28,0x25,0x22,0x1f,0x1d,0x1c,0x1a,
	0x16,0x13,0x11,0x0f,0x0d,0x0b,0x09,0x08,
	0x07,0x06,0x05,0x04,0x03,0x02,0x01,0x00,
	
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,

	0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,
	0x08,0x09,0x0b,0x0d,0x0f,0x11,0x13,0x16,
	0x1a,0x1c,0x1d,0x1f,0x22,0x25,0x28,0x2e,
	0x34,0x38,0x3c,0x40,0x44,0x48,0x4b,0x4f,
	0x55,0x5a,0x5f,0x64,0x69,0x6d,0x72,0x77,
	0x7d,0x80,0x88,0x8d,0x94,0x9a,0xa0,0xa7,
	0xac,0xb0,0xb9,0xbf,0xc6,0xcb,0xcf,0xd6,
	0xe1,0xe9,0xed,0xf1,0xf6,0xfa,0xfe,0xff,

	0xff,0xfe,0xfa,0xf6,0xf1,0xed,0xe9,0xe1,
	0xd6,0xcf,0xcb,0xc6,0xbf,0xb9,0xb0,0xac,
	0xa7,0xa0,0x9a,0x94,0x8d,0x88,0x80,0x7d,
	0x77,0x72,0x6d,0x69,0x64,0x5f,0x5a,0x55,
	0x4f,0x4b,0x48,0x44,0x40,0x3c,0x38,0x34,
	0x2e,0x28,0x25,0x22,0x1f,0x1d,0x1c,0x1a,
	0x16,0x13,0x11,0x0f,0x0d,0x0b,0x09,0x08,
	0x07,0x06,0x05,0x04,0x03,0x02,0x01,0x00,
	
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,

	0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,
	0x08,0x09,0x0b,0x0d,0x0f,0x11,0x13,0x16,
	0x1a,0x1c,0x1d,0x1f,0x22,0x25,0x28,0x2e,
	0x34,0x38,0x3c,0x40,0x44,0x48,0x4b,0x4f,
	0x55,0x5a,0x5f,0x64,0x69,0x6d,0x72,0x77,
	0x7d,0x80,0x88,0x8d,0x94,0x9a,0xa0,0xa7,
	0xac,0xb0,0xb9,0xbf,0xc6,0xcb,0xcf,0xd6,
	0xe1,0xe9,0xed,0xf1,0xf6,0xfa,0xfe,0xff,

	0xff,0xfe,0xfa,0xf6,0xf1,0xed,0xe9,0xe1,
	0xd6,0xcf,0xcb,0xc6,0xbf,0xb9,0xb0,0xac,
	0xa7,0xa0,0x9a,0x94,0x8d,0x88,0x80,0x7d,
	0x77,0x72,0x6d,0x69,0x64,0x5f,0x5a,0x55,
	0x4f,0x4b,0x48,0x44,0x40,0x3c,0x38,0x34,
	0x2e,0x28,0x25,0x22,0x1f,0x1d,0x1c,0x1a,
	0x16,0x13,0x11,0x0f,0x0d,0x0b,0x09,0x08,
	0x07,0x06,0x05,0x04,0x03,0x02,0x01,0x00
};

void IS31FL3741_PWM_Write(int iColor, int iX, int iY, int idata)
{
	switch(iColor)
	{
		case R_LED: switch(iX)
								{
									case 1 :switch(iY)
													{
														case 1:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x02,idata);break;
														case 2:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x05,idata);break;
														case 3:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x08,idata);break;
														case 4:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x0B,idata);break;
														case 5:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x0E,idata);break;
														case 6:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x11,idata);break;
														case 7:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x14,idata);break;
														case 8:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x17,idata);break;
														case 9:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x1A,idata);break;
														case 10:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x1D,idata);break;
														case 11:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x5C,idata);break;
														case 12:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x5F,idata);break;
														case 13:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x62,idata);break;
														default: break;
													}break;
									case 2 :switch(iY)
													{
														case 1:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x20,idata);break;
														case 2:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x23,idata);break;
														case 3:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x26,idata);break;
														case 4:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x29,idata);break;
														case 5:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x2C,idata);break;
														case 6:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x2F,idata);break;
														case 7:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x32,idata);break;
														case 8:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x35,idata);break;
														case 9:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x38,idata);break;
														case 10:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x3B,idata);break;
														case 11:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x65,idata);break;
														case 12:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x68,idata);break;
														case 13:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x6B,idata);break;
														default: break;
													}break;
									case 3 :switch(iY)
													{
														case 1:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x3E,idata);break;
														case 2:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x41,idata);break;
														case 3:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x44,idata);break;
														case 4:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x47,idata);break;
														case 5:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x4A,idata);break;
														case 6:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x4D,idata);break;
														case 7:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x50,idata);break;
														case 8:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x53,idata);break;
														case 9:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x56,idata);break;
														case 10:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x59,idata);break;
														case 11:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x6E,idata);break;
														case 12:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x71,idata);break;
														case 13:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x74,idata);break;
														default: break;
													}break;
									case 4 :switch(iY)
													{
														case 1:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x5C,idata);break;
														case 2:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x5F,idata);break;
														case 3:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x62,idata);break;
														case 4:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x65,idata);break;
														case 5:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x68,idata);break;
														case 6:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x6B,idata);break;
														case 7:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x6E,idata);break;
														case 8:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x71,idata);break;
														case 9:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x74,idata);break;
														case 10:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x77,idata);break;
														case 11:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x77,idata);break;
														case 12:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x7A,idata);break;
														case 13:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x7D,idata);break;
														default: break;
													}break;
									case 5 :switch(iY)
													{
														case 1:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x7A,idata);break;
														case 2:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x7D,idata);break;
														case 3:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x80,idata);break;
														case 4:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x83,idata);break;
														case 5:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x86,idata);break;
														case 6:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x89,idata);break;
														case 7:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x8C,idata);break;
														case 8:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x8F,idata);break;
														case 9:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x92,idata);break;
														case 10:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x95,idata);break;
														case 11:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x80,idata);break;
														case 12:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x83,idata);break;
														case 13:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x86,idata);break;
														default: break;
													}break;
									case 6 :switch(iY)
													{
														case 1:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x98,idata);break;
														case 2:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x9B,idata);break;
														case 3:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x9E,idata);break;
														case 4:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0xA1,idata);break;
														case 5:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0xA4,idata);break;
														case 6:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0xA7,idata);break;
														case 7:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0xAA,idata);break;
														case 8:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0xAD,idata);break;
														case 9:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0xB0,idata);break;
														case 10:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0xB3,idata);break;
														case 11:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x89,idata);break;
														case 12:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x8C,idata);break;
														case 13:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x8F,idata);break;
														default: break;
													}break;
									case 7 :switch(iY)
													{
														case 1:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x02,idata);break;
														case 2:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x05,idata);break;
														case 3:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x08,idata);break;
														case 4:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x0B,idata);break;
														case 5:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x0E,idata);break;
														case 6:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x11,idata);break;
														case 7:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x14,idata);break;
														case 8:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x17,idata);break;
														case 9:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x1A,idata);break;
														case 10:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x1D,idata);break;
														case 11:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x92,idata);break;
														case 12:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x95,idata);break;
														case 13:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x98,idata);break;
														default: break;
													}break;
									case 8 :switch(iY)
													{
														case 1:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x20,idata);break;
														case 2:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x23,idata);break;
														case 3:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x26,idata);break;
														case 4:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x29,idata);break;
														case 5:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x2C,idata);break;
														case 6:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x2F,idata);break;
														case 7:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x32,idata);break;
														case 8:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x35,idata);break;
														case 9:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x38,idata);break;
														case 10:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x3B,idata);break;
														case 11:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x9B,idata);break;
														case 12:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x9E,idata);break;
														case 13:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0xA1,idata);break;
														default: break;
													}break;
									case 9 :switch(iY)
													{
														case 1:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x3E,idata);break;
														case 2:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x41,idata);break;
														case 3:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x44,idata);break;
														case 4:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x47,idata);break;
														case 5:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x4A,idata);break;
														case 6:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x4D,idata);break;
														case 7:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x50,idata);break;
														case 8:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x53,idata);break;
														case 9:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x56,idata);break;
														case 10:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x59,idata);break;
														case 11:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0xA4,idata);break;
														case 12:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0xA7,idata);break;
														case 13:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0xAA,idata);break;
														default: break;
													}break;
									default: break;
								}break;
		case G_LED: switch(iX)
								{
									case 1 :switch(iY)
													{
														case 1:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x01,idata);break;
														case 2:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x04,idata);break;
														case 3:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x07,idata);break;
														case 4:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x0A,idata);break;
														case 5:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x0D,idata);break;
														case 6:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x10,idata);break;
														case 7:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x13,idata);break;
														case 8:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x16,idata);break;
														case 9:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x19,idata);break;
														case 10:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x1C,idata);break;
														case 11:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x5B,idata);break;
														case 12:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x5E,idata);break;
														case 13:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x61,idata);break;
														default: break;
													}break;
									case 2 :switch(iY)
													{
														case 1:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x1F,idata);break;
														case 2:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x22,idata);break;
														case 3:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x25,idata);break;
														case 4:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x28,idata);break;
														case 5:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x2B,idata);break;
														case 6:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x2E,idata);break;
														case 7:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x31,idata);break;
														case 8:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x34,idata);break;
														case 9:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x37,idata);break;
														case 10:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x3A,idata);break;
														case 11:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x64,idata);break;
														case 12:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x67,idata);break;
														case 13:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x6A,idata);break;
														default: break;
													}break;
									case 3 :switch(iY)
													{
														case 1:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x3D,idata);break;
														case 2:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x40,idata);break;
														case 3:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x43,idata);break;
														case 4:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x46,idata);break;
														case 5:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x49,idata);break;
														case 6:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x4C,idata);break;
														case 7:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x4F,idata);break;
														case 8:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x52,idata);break;
														case 9:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x55,idata);break;
														case 10:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x58,idata);break;
														case 11:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x6D,idata);break;
														case 12:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x70,idata);break;
														case 13:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x73,idata);break;
														default: break;
													}break;
									case 4 :switch(iY)
													{
														case 1:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x5B,idata);break;
														case 2:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x5E,idata);break;
														case 3:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x61,idata);break;
														case 4:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x64,idata);break;
														case 5:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x67,idata);break;
														case 6:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x6A,idata);break;
														case 7:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x6D,idata);break;
														case 8:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x70,idata);break;
														case 9:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x73,idata);break;
														case 10:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x76,idata);break;
														case 11:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x76,idata);break;
														case 12:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x79,idata);break;
														case 13:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x7C,idata);break;
														default: break;
													}break;
									case 5 :switch(iY)
													{
														case 1:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x79,idata);break;
														case 2:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x7C,idata);break;
														case 3:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x7F,idata);break;
														case 4:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x82,idata);break;
														case 5:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x85,idata);break;
														case 6:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x88,idata);break;
														case 7:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x8B,idata);break;
														case 8:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x8E,idata);break;
														case 9:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x91,idata);break;
														case 10:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x94,idata);break;
														case 11:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x7F,idata);break;
														case 12:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x82,idata);break;
														case 13:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x85,idata);break;
														default: break;
													}break;
									case 6 :switch(iY)
													{
														case 1:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x97,idata);break;
														case 2:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x9A,idata);break;
														case 3:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x9D,idata);break;
														case 4:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0xA0,idata);break;
														case 5:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0xA3,idata);break;
														case 6:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0xA6,idata);break;
														case 7:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0xA9,idata);break;
														case 8:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0xAC,idata);break;
														case 9:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0xAF,idata);break;
														case 10:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0xB2,idata);break;
														case 11:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x88,idata);break;
														case 12:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x8B,idata);break;
														case 13:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x8E,idata);break;
														default: break;
													}break;
									case 7 :switch(iY)
													{
														case 1:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x01,idata);break;
														case 2:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x04,idata);break;
														case 3:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x07,idata);break;
														case 4:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x0A,idata);break;
														case 5:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x0D,idata);break;
														case 6:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x10,idata);break;
														case 7:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x13,idata);break;
														case 8:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x16,idata);break;
														case 9:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x19,idata);break;
														case 10:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x1C,idata);break;
														case 11:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x91,idata);break;
														case 12:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x94,idata);break;
														case 13:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x97,idata);break;
														default: break;
													}break;
									case 8 :switch(iY)
													{
														case 1:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x1F,idata);break;
														case 2:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x22,idata);break;
														case 3:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x25,idata);break;
														case 4:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x28,idata);break;
														case 5:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x2B,idata);break;
														case 6:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x2E,idata);break;
														case 7:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x31,idata);break;
														case 8:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x34,idata);break;
														case 9:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x37,idata);break;
														case 10:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x3A,idata);break;
														case 11:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x9A,idata);break;
														case 12:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x9D,idata);break;
														case 13:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0xA0,idata);break;
														default: break;
													}break;
									case 9 :switch(iY)
													{
														case 1:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x3D,idata);break;
														case 2:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x40,idata);break;
														case 3:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x43,idata);break;
														case 4:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x46,idata);break;
														case 5:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x49,idata);break;
														case 6:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x4C,idata);break;
														case 7:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x4F,idata);break;
														case 8:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x52,idata);break;
														case 9:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x55,idata);break;
														case 10:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x58,idata);break;
														case 11:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0xA3,idata);break;
														case 12:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0xA6,idata);break;
														case 13:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0xA9,idata);break;
														default: break;
													}break;
									default: break;
								}break;
		case B_LED: switch(iX)
								{
									case 1 :switch(iY)
													{
														case 1:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x00,idata);break;
														case 2:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x03,idata);break;
														case 3:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x06,idata);break;
														case 4:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x09,idata);break;
														case 5:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x0c,idata);break;
														case 6:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x0f,idata);break;
														case 7:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x12,idata);break;
														case 8:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x15,idata);break;
														case 9:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x18,idata);break;
														case 10:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x1B,idata);break;
														case 11:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x5A,idata);break;
														case 12:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x5D,idata);break;
														case 13:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x60,idata);break;
														default: break;
													}break;
									case 2 :switch(iY)
													{
														case 1:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x1E,idata);break;
														case 2:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x21,idata);break;
														case 3:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x24,idata);break;
														case 4:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x27,idata);break;
														case 5:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x2A,idata);break;
														case 6:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x2D,idata);break;
														case 7:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x30,idata);break;
														case 8:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x33,idata);break;
														case 9:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x36,idata);break;
														case 10:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x39,idata);break;
														case 11:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x63,idata);break;
														case 12:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x66,idata);break;
														case 13:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x69,idata);break;
														default: break;
													}break;
									case 3 :switch(iY)
													{
														case 1:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x3C,idata);break;
														case 2:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x3F,idata);break;
														case 3:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x42,idata);break;
														case 4:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x45,idata);break;
														case 5:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x48,idata);break;
														case 6:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x4B,idata);break;
														case 7:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x4E,idata);break;
														case 8:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x51,idata);break;
														case 9:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x54,idata);break;
														case 10:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x57,idata);break;
														case 11:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x6C,idata);break;
														case 12:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x6F,idata);break;
														case 13:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x72,idata);break;
														default: break;
													}break;
									case 4 :switch(iY)
													{
														case 1:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x5A,idata);break;
														case 2:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x5D,idata);break;
														case 3:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x60,idata);break;
														case 4:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x63,idata);break;
														case 5:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x66,idata);break;
														case 6:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x69,idata);break;
														case 7:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x6C,idata);break;
														case 8:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x6F,idata);break;
														case 9:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x72,idata);break;
														case 10:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x75,idata);break;
														case 11:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x75,idata);break;
														case 12:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x78,idata);break;
														case 13:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x7B,idata);break;
														default: break;
													}break;
									case 5 :switch(iY)
													{
														case 1:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x78,idata);break;
														case 2:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x7B,idata);break;
														case 3:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x7E,idata);break;
														case 4:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x81,idata);break;
														case 5:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x84,idata);break;
														case 6:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x87,idata);break;
														case 7:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x8A,idata);break;
														case 8:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x8D,idata);break;
														case 9:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x90,idata);break;
														case 10:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x93,idata);break;
														case 11:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x7E,idata);break;
														case 12:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x81,idata);break;
														case 13:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x84,idata);break;
														default: break;
													}break;
									case 6 :switch(iY)
													{
														case 1:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x96,idata);break;
														case 2:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x99,idata);break;
														case 3:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x9C,idata);break;
														case 4:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0x9F,idata);break;
														case 5:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0xA2,idata);break;
														case 6:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0xA5,idata);break;
														case 7:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0xA8,idata);break;
														case 8:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0xAB,idata);break;
														case 9:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0xAE,idata);break;
														case 10:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x00);I2C_WriteByte(Addr_GND_GND,0xB1,idata);break;
														case 11:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x87,idata);break;
														case 12:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x8A,idata);break;
														case 13:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x8D,idata);break;
														default: break;
													}break;
									case 7 :switch(iY)
													{
														case 1:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x00,idata);break;
														case 2:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x03,idata);break;
														case 3:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x06,idata);break;
														case 4:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x09,idata);break;
														case 5:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x0C,idata);break;
														case 6:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x0F,idata);break;
														case 7:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x12,idata);break;
														case 8:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x15,idata);break;
														case 9:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x18,idata);break;
														case 10:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x1B,idata);break;
														case 11:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x90,idata);break;
														case 12:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x93,idata);break;
														case 13:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x96,idata);break;
														default: break;
													}break;
									case 8 :switch(iY)
													{
														case 1:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x1E,idata);break;
														case 2:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x21,idata);break;
														case 3:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x24,idata);break;
														case 4:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x27,idata);break;
														case 5:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x2A,idata);break;
														case 6:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x2D,idata);break;
														case 7:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x30,idata);break;
														case 8:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x33,idata);break;
														case 9:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x36,idata);break;
														case 10:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x39,idata);break;
														case 11:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x99,idata);break;
														case 12:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x9C,idata);break;
														case 13:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x9F,idata);break;
														default: break;
													}break;
									case 9 :switch(iY)
													{
														case 1:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x3C,idata);break;
														case 2:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x3F,idata);break;
														case 3:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x42,idata);break;
														case 4:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x45,idata);break;
														case 5:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x48,idata);break;
														case 6:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x4B,idata);break;
														case 7:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x4E,idata);break;
														case 8:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x51,idata);break;
														case 9:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x54,idata);break;
														case 10:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0x57,idata);break;
														case 11:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0xA2,idata);break;
														case 12:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0xA5,idata);break;
														case 13:I2C_WriteByte(Addr_GND_GND,0xFE,0xC5);I2C_WriteByte(Addr_GND_GND,0xFD,0x01);I2C_WriteByte(Addr_GND_GND,0xA8,idata);break;
														default: break;
													}break;
									default: break;
								}break;
		default: break;
	}
}

void IS31FL3741_LED_X(int iColor,int iX1,int iY1,int iY2,int iY3,int iY4,int iY5,int iY6,int iY7,int iY8,int iY9,int iY10,int iY11,int iY12,int iY13)
{
	IS31FL3741_PWM_Write(iColor,iX1,1,iY1);
	IS31FL3741_PWM_Write(iColor,iX1,2,iY2);
	IS31FL3741_PWM_Write(iColor,iX1,3,iY3);
	IS31FL3741_PWM_Write(iColor,iX1,4,iY4);
	IS31FL3741_PWM_Write(iColor,iX1,5,iY5);
	IS31FL3741_PWM_Write(iColor,iX1,6,iY6);
	IS31FL3741_PWM_Write(iColor,iX1,7,iY7);
	IS31FL3741_PWM_Write(iColor,iX1,8,iY8);
	IS31FL3741_PWM_Write(iColor,iX1,9,iY9);
	IS31FL3741_PWM_Write(iColor,iX1,10,iY10);
	IS31FL3741_PWM_Write(iColor,iX1,11,iY11);
	IS31FL3741_PWM_Write(iColor,iX1,12,iY12);
	IS31FL3741_PWM_Write(iColor,iX1,13,iY13);
}

void IS31FL3741_LED_X_Samedata(int iColor,int iX1,int iY1)
{
	IS31FL3741_PWM_Write(iColor,iX1,1,iY1);
	IS31FL3741_PWM_Write(iColor,iX1,2,iY1);
	IS31FL3741_PWM_Write(iColor,iX1,3,iY1);
	IS31FL3741_PWM_Write(iColor,iX1,4,iY1);
	IS31FL3741_PWM_Write(iColor,iX1,5,iY1);
	IS31FL3741_PWM_Write(iColor,iX1,6,iY1);
	IS31FL3741_PWM_Write(iColor,iX1,7,iY1);
	IS31FL3741_PWM_Write(iColor,iX1,8,iY1);
	IS31FL3741_PWM_Write(iColor,iX1,9,iY1);
	IS31FL3741_PWM_Write(iColor,iX1,10,iY1);
	IS31FL3741_PWM_Write(iColor,iX1,11,iY1);
	IS31FL3741_PWM_Write(iColor,iX1,12,iY1);
	IS31FL3741_PWM_Write(iColor,iX1,13,iY1);
}

void IS31FL3741_LED_Y(int iColor,int iY1,int iX1,int iX2,int iX3,int iX4,int iX5,int iX6,int iX7,int iX8,int iX9)
{
	IS31FL3741_PWM_Write(iColor,1,iY1,iX1);
	IS31FL3741_PWM_Write(iColor,2,iY1,iX2);
	IS31FL3741_PWM_Write(iColor,3,iY1,iX3);
	IS31FL3741_PWM_Write(iColor,4,iY1,iX4);
	IS31FL3741_PWM_Write(iColor,5,iY1,iX5);
	IS31FL3741_PWM_Write(iColor,6,iY1,iX6);
	IS31FL3741_PWM_Write(iColor,7,iY1,iX7);
	IS31FL3741_PWM_Write(iColor,8,iY1,iX8);
	IS31FL3741_PWM_Write(iColor,9,iY1,iX9);
}

void IS31FL3741_LED_Y_Samedata(int iColor,int iY1,int iX1)
{
	IS31FL3741_PWM_Write(iColor,1,iY1,iX1);
	IS31FL3741_PWM_Write(iColor,2,iY1,iX1);
	IS31FL3741_PWM_Write(iColor,3,iY1,iX1);
	IS31FL3741_PWM_Write(iColor,4,iY1,iX1);
	IS31FL3741_PWM_Write(iColor,5,iY1,iX1);
	IS31FL3741_PWM_Write(iColor,6,iY1,iX1);
	IS31FL3741_PWM_Write(iColor,7,iY1,iX1);
	IS31FL3741_PWM_Write(iColor,8,iY1,iX1);
	IS31FL3741_PWM_Write(iColor,9,iY1,iX1);
}

void IS31FL3741_B_LED_SCAL_PWM(int ipage, int idata)
{
	int i;
	if (ipage == SCAL)
	{
		I2C_WriteByte(Addr_GND_GND,0xfe,0xc5);
		I2C_WriteByte(Addr_GND_GND,0xfD,0x02);
		for(i=0;i<0xB4;i+=3)
		{
			I2C_WriteByte(Addr_GND_GND,i,idata);//Scaling
		}
		
		I2C_WriteByte(Addr_GND_GND,0xfe,0xc5);
		I2C_WriteByte(Addr_GND_GND,0xfD,0x03);
		for(i=0;i<0xAB;i+=3)
		{
			I2C_WriteByte(Addr_GND_GND,i,idata);//Scaling
		}
	}
	else
	{
		I2C_WriteByte(Addr_GND_GND,0xfe,0xc5);
		I2C_WriteByte(Addr_GND_GND,0xfD,0x00);
		for(i=0;i<0xB4;i+=3)
		{
			I2C_WriteByte(Addr_GND_GND,i,idata);//PWM
		}
		
		I2C_WriteByte(Addr_GND_GND,0xfe,0xc5);
		I2C_WriteByte(Addr_GND_GND,0xfD,0x01);
		for(i=0;i<0xAB;i+=3)
		{
			I2C_WriteByte(Addr_GND_GND,i,idata);//PWM
		}
	}
}

void IS31FL3741_G_LED_SCAL_PWM(int ipage, int idata)
{
	int i;
	if (ipage == SCAL)
	{
		I2C_WriteByte(Addr_GND_GND,0xfe,0xc5);
		I2C_WriteByte(Addr_GND_GND,0xfD,0x02);
		for(i=1;i<0xB4;i+=3)
		{
			I2C_WriteByte(Addr_GND_GND,i,idata);//Scaling
		}
		
		I2C_WriteByte(Addr_GND_GND,0xfe,0xc5);
		I2C_WriteByte(Addr_GND_GND,0xfD,0x03);
		for(i=1;i<0xAB;i+=3)
		{
			I2C_WriteByte(Addr_GND_GND,i,idata);//Scaling
		}
	}
	else
	{
		I2C_WriteByte(Addr_GND_GND,0xfe,0xc5);
		I2C_WriteByte(Addr_GND_GND,0xfD,0x00);
		for(i=1;i<0xB4;i+=3)
		{
			I2C_WriteByte(Addr_GND_GND,i,idata);//PWM
		}
		
		I2C_WriteByte(Addr_GND_GND,0xfe,0xc5);
		I2C_WriteByte(Addr_GND_GND,0xfD,0x01);
		for(i=1;i<0xAB;i+=3)
		{
			I2C_WriteByte(Addr_GND_GND,i,idata);//PWM
		}
	}
}

void IS31FL3741_R_LED_SCAL_PWM(int ipage, int idata)
{
	int i;
	if (ipage == SCAL)
	{
		I2C_WriteByte(Addr_GND_GND,0xfe,0xc5);
		I2C_WriteByte(Addr_GND_GND,0xfD,0x02);
		for(i=2;i<0xB4;i+=3)
		{
			I2C_WriteByte(Addr_GND_GND,i,idata);//Scaling
		}
		
		I2C_WriteByte(Addr_GND_GND,0xfe,0xc5);
		I2C_WriteByte(Addr_GND_GND,0xfD,0x03);
		for(i=2;i<0xAB;i+=3)
		{
			I2C_WriteByte(Addr_GND_GND,i,idata);//Scaling
		}
	}
	else
	{
		I2C_WriteByte(Addr_GND_GND,0xfe,0xc5);
		I2C_WriteByte(Addr_GND_GND,0xfD,0x00);
		for(i=2;i<0xB4;i+=3)
		{
			I2C_WriteByte(Addr_GND_GND,i,idata);//PWM
		}
		
		I2C_WriteByte(Addr_GND_GND,0xfe,0xc5);
		I2C_WriteByte(Addr_GND_GND,0xfD,0x01);
		for(i=2;i<0xAB;i+=3)
		{
			I2C_WriteByte(Addr_GND_GND,i,idata);//PWM
		}
	}
}

void IS31FL3741_Init(void)
{
	IS31FL3741_R_LED_SCAL_PWM(SCAL,0xFF);
	IS31FL3741_G_LED_SCAL_PWM(SCAL,0xFF);
	IS31FL3741_B_LED_SCAL_PWM(SCAL,0xFF);
	IS31FL3741_R_LED_SCAL_PWM(PWM,0x00);
	IS31FL3741_G_LED_SCAL_PWM(PWM,0x00);
	IS31FL3741_B_LED_SCAL_PWM(PWM,0x00);
	
	I2C_WriteByte(Addr_GND_GND,0xfe,0xc5);
	I2C_WriteByte(Addr_GND_GND,0xfD,0x04);
	I2C_WriteByte(Addr_GND_GND,0x01,0xFF);//GCC
	I2C_WriteByte(Addr_GND_GND,0x00,0x01);
}

int IS31FL3741_Mode_1(void)//Rainbow wave
{
	int com1;
	int x=128;
	int y=64;
	int z=8;
	
	IS31FL3741_R_LED_SCAL_PWM(PWM,0x00);
	IS31FL3741_G_LED_SCAL_PWM(PWM,0x00);
	IS31FL3741_B_LED_SCAL_PWM(PWM,0x00);
	
	while(Mode_NO == 1)
	{
		for(com1=0;com1<189;com1++)
		{	
			IS31FL3741_LED_Y_Samedata(G_LED,1,RGB_PWM_IS31FL3741[com1]);
			IS31FL3741_LED_Y_Samedata(R_LED,1,RGB_PWM_IS31FL3741[com1+x]);
			IS31FL3741_LED_Y_Samedata(B_LED,1,RGB_PWM_IS31FL3741[com1+y]);
	
			IS31FL3741_LED_Y_Samedata(G_LED,2,RGB_PWM_IS31FL3741[com1+z*1]);
			IS31FL3741_LED_Y_Samedata(R_LED,2,RGB_PWM_IS31FL3741[com1+x+z*1]);
			IS31FL3741_LED_Y_Samedata(B_LED,2,RGB_PWM_IS31FL3741[com1+y+z*1]);
	
			IS31FL3741_LED_Y_Samedata(G_LED,3,RGB_PWM_IS31FL3741[com1+z*2]);
			IS31FL3741_LED_Y_Samedata(R_LED,3,RGB_PWM_IS31FL3741[com1+x+z*2]);
			IS31FL3741_LED_Y_Samedata(B_LED,3,RGB_PWM_IS31FL3741[com1+y+z*2]);
		
			IS31FL3741_LED_Y_Samedata(G_LED,4,RGB_PWM_IS31FL3741[com1+z*3]);
			IS31FL3741_LED_Y_Samedata(R_LED,4,RGB_PWM_IS31FL3741[com1+x+z*3]);
			IS31FL3741_LED_Y_Samedata(B_LED,4,RGB_PWM_IS31FL3741[com1+y+z*3]);
			
			IS31FL3741_LED_Y_Samedata(G_LED,5,RGB_PWM_IS31FL3741[com1+z*4]);
			IS31FL3741_LED_Y_Samedata(R_LED,5,RGB_PWM_IS31FL3741[com1+x+z*4]);
			IS31FL3741_LED_Y_Samedata(B_LED,5,RGB_PWM_IS31FL3741[com1+y+z*4]);
			
			IS31FL3741_LED_Y_Samedata(G_LED,6,RGB_PWM_IS31FL3741[com1+z*5]);
			IS31FL3741_LED_Y_Samedata(R_LED,6,RGB_PWM_IS31FL3741[com1+x+z*5]);
			IS31FL3741_LED_Y_Samedata(B_LED,6,RGB_PWM_IS31FL3741[com1+y+z*5]);
			
			IS31FL3741_LED_Y_Samedata(G_LED,7,RGB_PWM_IS31FL3741[com1+z*6]);
			IS31FL3741_LED_Y_Samedata(R_LED,7,RGB_PWM_IS31FL3741[com1+x+z*6]);
			IS31FL3741_LED_Y_Samedata(B_LED,7,RGB_PWM_IS31FL3741[com1+y+z*6]);
			
			IS31FL3741_LED_Y_Samedata(G_LED,8,RGB_PWM_IS31FL3741[com1+z*7]);
			IS31FL3741_LED_Y_Samedata(R_LED,8,RGB_PWM_IS31FL3741[com1+x+z*7]);
			IS31FL3741_LED_Y_Samedata(B_LED,8,RGB_PWM_IS31FL3741[com1+y+z*7]);
			
			IS31FL3741_LED_Y_Samedata(G_LED,9,RGB_PWM_IS31FL3741[com1+z*8]);
			IS31FL3741_LED_Y_Samedata(R_LED,9,RGB_PWM_IS31FL3741[com1+x+z*8]);
			IS31FL3741_LED_Y_Samedata(B_LED,9,RGB_PWM_IS31FL3741[com1+y+z*8]);
			
			IS31FL3741_LED_Y_Samedata(G_LED,10,RGB_PWM_IS31FL3741[com1+z*9]);
			IS31FL3741_LED_Y_Samedata(R_LED,10,RGB_PWM_IS31FL3741[com1+x+z*9]);
			IS31FL3741_LED_Y_Samedata(B_LED,10,RGB_PWM_IS31FL3741[com1+y+z*9]);
			
			IS31FL3741_LED_Y_Samedata(G_LED,11,RGB_PWM_IS31FL3741[com1+z*10]);
			IS31FL3741_LED_Y_Samedata(R_LED,11,RGB_PWM_IS31FL3741[com1+x+z*10]);
			IS31FL3741_LED_Y_Samedata(B_LED,11,RGB_PWM_IS31FL3741[com1+y+z*10]);
			
			IS31FL3741_LED_Y_Samedata(G_LED,12,RGB_PWM_IS31FL3741[com1+z*11]);
			IS31FL3741_LED_Y_Samedata(R_LED,12,RGB_PWM_IS31FL3741[com1+x+z*11]);
			IS31FL3741_LED_Y_Samedata(B_LED,12,RGB_PWM_IS31FL3741[com1+y+z*11]);
			
			IS31FL3741_LED_Y_Samedata(G_LED,13,RGB_PWM_IS31FL3741[com1+z*12]);
			IS31FL3741_LED_Y_Samedata(R_LED,13,RGB_PWM_IS31FL3741[com1+x+z*12]);
			IS31FL3741_LED_Y_Samedata(B_LED,13,RGB_PWM_IS31FL3741[com1+y+z*12]);
			if(Mode_NO != 1)return 0;
		}	
	}
	return 1;
}

int IS31FL3741_Mode_2(void)//Rainbow wave
{
	int i;
	int p_temp;
	int pb1,pr1,pg1;
	pb1 = 0;
	pr1 = 16;
	pg1 = 32;
	IS31FL3741_R_LED_SCAL_PWM(PWM,0x00);
	IS31FL3741_G_LED_SCAL_PWM(PWM,0x00);
	IS31FL3741_B_LED_SCAL_PWM(PWM,0x00);
	while(Mode_NO == 2)
	{
		for(i=0;i<48;i++)
		{
			p_temp=i+pr1;
				IS31FL3741_LED_Y(R_LED,1,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pb1;
				IS31FL3741_LED_Y(B_LED,1,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pg1;
				IS31FL3741_LED_Y(G_LED,1,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pr1+2;
				IS31FL3741_LED_Y(R_LED,2,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pb1+2;
				IS31FL3741_LED_Y(B_LED,2,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pg1+2;
				IS31FL3741_LED_Y(G_LED,2,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pr1+4;
				IS31FL3741_LED_Y(R_LED,3,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pb1+4;
				IS31FL3741_LED_Y(B_LED,3,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pg1+4;
				IS31FL3741_LED_Y(G_LED,3,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pr1+6;
				IS31FL3741_LED_Y(R_LED,4,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pb1+6;
				IS31FL3741_LED_Y(B_LED,4,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pg1+6;
				IS31FL3741_LED_Y(G_LED,4,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pr1+8;
				IS31FL3741_LED_Y(R_LED,5,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pb1+8;
				IS31FL3741_LED_Y(B_LED,5,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pg1+8;
				IS31FL3741_LED_Y(G_LED,5,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pr1+10;
				IS31FL3741_LED_Y(R_LED,6,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pb1+10;
				IS31FL3741_LED_Y(B_LED,6,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pg1+10;
				IS31FL3741_LED_Y(G_LED,6,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pr1+12;
				IS31FL3741_LED_Y(R_LED,7,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pb1+12;
				IS31FL3741_LED_Y(B_LED,7,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pg1+12;
				IS31FL3741_LED_Y(G_LED,7,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pr1+14;
				IS31FL3741_LED_Y(R_LED,8,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pb1+14;
				IS31FL3741_LED_Y(B_LED,8,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pg1+14;
				IS31FL3741_LED_Y(G_LED,8,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pr1+16;
				IS31FL3741_LED_Y(R_LED,9,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pb1+16;
				IS31FL3741_LED_Y(B_LED,9,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pg1+16;
				IS31FL3741_LED_Y(G_LED,9,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pr1+18;
				IS31FL3741_LED_Y(R_LED,10,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pb1+18;
				IS31FL3741_LED_Y(B_LED,10,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pg1+18;
				IS31FL3741_LED_Y(G_LED,10,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pr1+20;
				IS31FL3741_LED_Y(R_LED,11,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pb1+20;
				IS31FL3741_LED_Y(B_LED,11,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pg1+20;
				IS31FL3741_LED_Y(G_LED,11,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pr1+22;
				IS31FL3741_LED_Y(R_LED,12,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pb1+22;
				IS31FL3741_LED_Y(B_LED,12,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pg1+22;
				IS31FL3741_LED_Y(G_LED,12,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pr1+24;
				IS31FL3741_LED_Y(R_LED,13,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pb1+24;
				IS31FL3741_LED_Y(B_LED,13,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				p_temp=i+pg1+24;
				IS31FL3741_LED_Y(G_LED,13,RGB_32PWM_IS31FL3741[24+p_temp],RGB_32PWM_IS31FL3741[21+p_temp],RGB_32PWM_IS31FL3741[18+p_temp],RGB_32PWM_IS31FL3741[15+p_temp],RGB_32PWM_IS31FL3741[12+p_temp],RGB_32PWM_IS31FL3741[9+p_temp],RGB_32PWM_IS31FL3741[6+p_temp],RGB_32PWM_IS31FL3741[3+p_temp],RGB_32PWM_IS31FL3741[0+p_temp]);
				if (Mode_NO != 2) return 0;
				delay(100);
				
		}
	}
	return 1;
}

int IS31FL3741_Mode_3(void)//Rain
{
	int iCnt = 0;
	int x,y,k;
	int irand = rand()%9;
	int R_PWM = rand()%256;
	int G_PWM = rand()%256;
	int B_PWM = rand()%256;
	int ColorPWM[9][13][3];
	IS31FL3741_R_LED_SCAL_PWM(PWM,0x00);
	IS31FL3741_G_LED_SCAL_PWM(PWM,0x00);
	IS31FL3741_B_LED_SCAL_PWM(PWM,0x00);
	for (y=0;y<13;y++)//Init table
	{
		for (x=0;x<9;x++)
		{
			for(k=0;k<3;k++)
			{
				ColorPWM[x][y][k] = 0x00;
			}
		}
	}
	
	while(Mode_NO == 3)
	{
			
		if (iCnt == 3)
		{
			iCnt = 0;
			irand = rand()%9;//Get random numbers 
			R_PWM = rand()%256;
			G_PWM = rand()%256;
			B_PWM = rand()%256;
		}
		if(Mode_NO != 3)return 0;
		for (x=0;x<9;x++)//data transformation
		{
			if (irand == x)
			{
				if (iCnt == 0)
				{
					ColorPWM[x][12][0] = R_PWM;
					ColorPWM[x][12][1] = G_PWM;
					ColorPWM[x][12][2] = B_PWM;
				}
				else
				{
					if (iCnt == 1)
					{
						ColorPWM[x][12][0] = R_PWM/2;
						ColorPWM[x][12][1] = G_PWM/2;
						ColorPWM[x][12][2] = B_PWM/2;
					}
					else
					if(iCnt == 2)
					{
						ColorPWM[x][12][0] = R_PWM/8;
						ColorPWM[x][12][1] = G_PWM/8;
						ColorPWM[x][12][2] = B_PWM/8;
					}
					else
					{
						ColorPWM[x][12][0] = 0x00;
						ColorPWM[x][12][1] = 0x00;
						ColorPWM[x][12][2] = 0x00;
					}
				}				
			}
			else
			{
				ColorPWM[x][12][0] = 0x00;
				ColorPWM[x][12][1] = 0x00;
				ColorPWM[x][12][2] = 0x00;
			}		
		}
		iCnt++;
		for (x=0;x<9;x++)//update LED data
		{
			for (y=0;y<13;y++)
			{
				IS31FL3741_PWM_Write(R_LED,x+1,y+1,ColorPWM[x][y][0]);
				IS31FL3741_PWM_Write(G_LED,x+1,y+1,ColorPWM[x][y][1]);
				IS31FL3741_PWM_Write(B_LED,x+1,y+1,ColorPWM[x][y][2]);
				if(Mode_NO != 3)return 0;
			}
		}
		delay(100);
		if(Mode_NO != 3)return 0;
		for (x=0;x<9;x++)//Data downward movement 
		{
			for (y=0;y<12;y++)
			{
				for (k=0;k<3;k++)
				{
					ColorPWM[x][y][k] = ColorPWM[x][y+1][k];
				}
			}
		}
		
	}
	return 1;
}

int IS31FL3741_Mode_4(void)//Visor
{
	int iCnt = 0;
	int x,y,k;

	int R_PWM = rand()%256;
	int G_PWM = rand()%256;
	int B_PWM = rand()%256;
	int ColorPWM[9][13][3];
	IS31FL3741_R_LED_SCAL_PWM(PWM,0x00);
	IS31FL3741_G_LED_SCAL_PWM(PWM,0x00);
	IS31FL3741_B_LED_SCAL_PWM(PWM,0x00);
	for (y=0;y<13;y++)//Init table
	{
		for (x=0;x<9;x++)
		{
			for(k=0;k<3;k++)
			{
				ColorPWM[x][y][k] = 0x00;
			}
		}
	}
	
	while(Mode_NO == 4)
	{
		for(iCnt=0;iCnt<15;iCnt++)
		{
			if (iCnt == 14)
			{
				R_PWM = rand()%256;
				G_PWM = rand()%256;
				B_PWM = rand()%256;
			}
			if(Mode_NO != 4)return 0;	
			for (y=0;y<13;y++)//data transformation
			{
				if (iCnt == 0)
				{
					ColorPWM[0][y][0] = R_PWM;
					ColorPWM[0][y][1] = G_PWM;
					ColorPWM[0][y][2] = B_PWM;
				}
				else
				{
					if (iCnt == 1)
					{
						ColorPWM[0][y][0] = R_PWM/2;
						ColorPWM[0][y][1] = G_PWM/2;
						ColorPWM[0][y][2] = B_PWM/2;
					}
					else
					if(iCnt == 2)
					{
						ColorPWM[0][y][0] = R_PWM/3;
						ColorPWM[0][y][1] = G_PWM/3;
						ColorPWM[0][y][2] = B_PWM/3;
					}
					else
					if(iCnt == 3)
					{
						ColorPWM[0][y][0] = R_PWM/4;
						ColorPWM[0][y][1] = G_PWM/4;
						ColorPWM[0][y][2] = B_PWM/4;
					}
					else
					if(iCnt == 4)
					{
						ColorPWM[0][y][0] = R_PWM/6;
						ColorPWM[0][y][1] = G_PWM/6;
						ColorPWM[0][y][2] = B_PWM/6;
					}
					else
					if(iCnt == 5)
					{
						ColorPWM[0][y][0] = R_PWM/8;
						ColorPWM[0][y][1] = G_PWM/8;
						ColorPWM[0][y][2] = B_PWM/8;
					}
					else
					{
						ColorPWM[0][y][0] = 0x00;
						ColorPWM[0][y][1] = 0x00;
						ColorPWM[0][y][2] = 0x00;
					}
				}				
			}
			for (x=0;x<9;x++)//update data
			{
				for (y=0;y<13;y++)
				{
					IS31FL3741_PWM_Write(R_LED,x+1,y+1,ColorPWM[x][y][0]);
					IS31FL3741_PWM_Write(G_LED,x+1,y+1,ColorPWM[x][y][1]);
					IS31FL3741_PWM_Write(B_LED,x+1,y+1,ColorPWM[x][y][2]);
					
				}if(Mode_NO != 4)return 0;
			}
			if(Mode_NO != 4)return 0;
			
			for(y=0;y<13;y++)//Move data right 
			{
				for (x=8;x>0;x--)
				{
					for (k=0;k<3;k++)
					{
						ColorPWM[x][y][k] = ColorPWM[x-1][y][k];
					}
				}
 			}
		}
		for(iCnt=0;iCnt<15;iCnt++)
		{
			if (iCnt == 14)
			{
				R_PWM = rand()%256;
				G_PWM = rand()%256;
				B_PWM = rand()%256;
			}
				
			for (y=0;y<13;y++)//data transformation
			{
				if (iCnt == 0)
				{
					ColorPWM[8][y][0] = R_PWM;
					ColorPWM[8][y][1] = G_PWM;
					ColorPWM[8][y][2] = B_PWM;
				}
				else
				{
					if (iCnt == 1)
					{
						ColorPWM[8][y][0] = R_PWM/2;
						ColorPWM[8][y][1] = G_PWM/2;
						ColorPWM[8][y][2] = B_PWM/2;
					}
					else
					if(iCnt == 2)
					{
						ColorPWM[8][y][0] = R_PWM/3;
						ColorPWM[8][y][1] = G_PWM/3;
						ColorPWM[8][y][2] = B_PWM/3;
					}
					else
					if(iCnt == 3)
					{
						ColorPWM[8][y][0] = R_PWM/4;
						ColorPWM[8][y][1] = G_PWM/4;
						ColorPWM[8][y][2] = B_PWM/4;
					}
					else
					if(iCnt == 4)
					{
						ColorPWM[8][y][0] = R_PWM/6;
						ColorPWM[8][y][1] = G_PWM/6;
						ColorPWM[8][y][2] = B_PWM/6;
					}
					else
					if(iCnt == 5)
					{
						ColorPWM[8][y][0] = R_PWM/8;
						ColorPWM[8][y][1] = G_PWM/8;
						ColorPWM[8][y][2] = B_PWM/8;
					}
					else
					{
						ColorPWM[8][y][0] = 0x00;
						ColorPWM[8][y][1] = 0x00;
						ColorPWM[8][y][2] = 0x00;
					}
				}				
			}
			for (x=0;x<9;x++)//update data
			{
				for (y=0;y<13;y++)
				{
					IS31FL3741_PWM_Write(R_LED,x+1,y+1,ColorPWM[x][y][0]);
					IS31FL3741_PWM_Write(G_LED,x+1,y+1,ColorPWM[x][y][1]);
					IS31FL3741_PWM_Write(B_LED,x+1,y+1,ColorPWM[x][y][2]);
					if(Mode_NO != 4)return 0;
				}
			}
			if(Mode_NO != 4)return 0;
			for (x=0;x<8;x++)//Move data left 
			{
				for (y=0;y<13;y++)
				{
					for (k=0;k<3;k++)
					{
						ColorPWM[x][y][k] = ColorPWM[x+1][y][k];
					}
				}
 			}
  	}
		delay(1000);
	}
	return 1;
}

void Play_IS31FL3741_Demo_mode(void)
{
	IS31FL3741_Mode_1();
	while(Mode_NO == 1);  
	IS31FL3741_Mode_2();
	while(Mode_NO == 2);  
	IS31FL3741_Mode_3();
	while(Mode_NO == 3); 
	IS31FL3741_Mode_4();
	while(Mode_NO == 4);
}
