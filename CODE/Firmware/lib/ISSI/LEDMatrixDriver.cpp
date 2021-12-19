/*
 * LEDMatrixDriver.cpp
 *
 *  Created on: 30.03.2017
 *      Author: Bartosz Bielawski
 */

#include "LEDMatrixDriver.hpp"
#include "addrmap.h"
#include <Arduino.h>
#include <Wire.h>


void I2CWriteByte(int Dev_Add, byte Reg_Add, byte Reg_Dat)
{
	Wire.beginTransmission(Dev_Add); // transmit to device IS31FL373x
	Wire.write(Reg_Add); // sends regaddress
	Wire.write(Reg_Dat); // sends regaddress
	Wire.endTransmission(); // stop transmitting
}

void I2CWriteMultipleBytes(int Dev_Add, byte Reg_Add, byte* Reg_Dat, int nBytes)
{
	Wire.beginTransmission(Dev_Add); // transmit to device IS31FL373x
	Wire.write(Reg_Add); // sends regaddress
	for (int i = 0; i < nBytes; i++){
		Wire.write(Reg_Dat[i]);
	}
	Wire.endTransmission(); // stop transmitting
}

LEDMatrixDriver::LEDMatrixDriver(uint8_t sdaPin, uint8_t sclPin, uint8_t addr, uint8_t enablePin):
Adafruit_GFX(39, 9), //needchange
	// frameBuffer(fb),
	selfAllocated(1),
	sdaPin(sdaPin),
	sclPin(sclPin),
	addr(addr),
	enablePin(enablePin)	
{


}


void LEDMatrixDriver::begin()
	{

			// uint8_t *frameBuffer = (uint8_t *) ps_malloc(9 * 39 * sizeof(uint8_t));

	if (selfAllocated){
		// uint8_t *frameBuffer = (uint8_t *) ps_malloc(1 * 1 * sizeof(uint8_t));
		// uint8_t frameBuffer[2][2] = {(1, 2), (1, 2)};

		
		frameBuffer = new uint8_t*[9];
		for(int i = 0; i < 9; ++i)
			frameBuffer[i] = new uint8_t[39];

		// uint8_t ** frameBuffer = (uint8_t**) ps_malloc(sizeof(int *) * 9 + sizeof(int) * 39*9);
		// uint8_t * frameBuffer = (uint8_t*) ps_calloc(39*9, sizeof(uint8_t));

		
		// frameBuffer = (uint8_t**) ps_malloc(sizeof(int *) * 9 + sizeof(int) * 39*9);

	}

	clear();	// initally clear the buffer as the memory will not be initialized on reset (old content will be in memory yet)

	Wire.begin(sdaPin, sclPin);
	Wire.setClock(4000000);//I2C 1MHz

	int i;
	int Rdata = 0xFF;
    int Gdata = 0xFF;
    int Bdata = 0xFF;

	I2CWriteByte(addr,0xfe,0xc5);//unlock
    I2CWriteByte(addr,0xfD,0x02);//write page 2
    for(i=2;i<0xB4;i+=3)
        {
            I2CWriteByte(addr,i,Rdata);//R LED Scaling
        }
    for(i=1;i<0xB4;i+=3)
    {
        I2CWriteByte(addr,i,Gdata);//G LED Scaling
    }
    for(i=0;i<0xB4;i+=3)
    {
        I2CWriteByte(addr,i,Bdata);//B LED Scaling
    }
    I2CWriteByte(addr,0xfe,0xc5);//unlock
    I2CWriteByte(addr,0xfD,0x03);//write page 3
    for(i=2;i<0xAB;i+=3)
    {
        I2CWriteByte(addr,i,Rdata);//R LED Scaling
    }
    for(i=1;i<0xAB;i+=3)
    {
        I2CWriteByte(addr,i,Gdata);//G LED Scaling
    }
    for(i=0;i<0xAB;i+=3)
    {
        I2CWriteByte(addr,i,Bdata);//B LED Scaling
    }
    I2CWriteByte(addr,0xfe,0xc5);//unlock
    I2CWriteByte(addr,0xfD,0x00);//write page 0
    for(i=0;i<0xB4;i++)
    {
        I2CWriteByte(addr,i,0x00);//write all PWM set 0x00
    }
    I2CWriteByte(addr,0xfe,0xc5);//unlock
    I2CWriteByte(addr,0xfD,0x01);//write page 1
    for(i=0;i<0xAB;i++)
    {
        I2CWriteByte(addr,i,0x00);//write all PWM set 0x00
    } //init all the PWM data to 0

    I2CWriteByte(addr,0xfe,0xc5);//unlock
    I2CWriteByte(addr,0xfD,0x04);//write page 4
    I2CWriteByte(addr,0x01,0x7F);//global current
    I2CWriteByte(addr,0x01,0xFF);//global current
    I2CWriteByte(addr,0x00,0x01);//normal operation

	ClearFrameBuffer();
	updateFrameBuffer();


	
#ifdef ESP8266
	SPI.setHwCs(false);
#endif


}

// LEDMatrixDriver::~LEDMatrixDriver()
// {
// 	if (selfAllocated)
// 		delete[] frameBuffer;
// }

void LEDMatrixDriver::ClearFrameBuffer(){
	for(int x = 0; x<39; x++)
		for(int y = 0; y<9; y++)
			frameBuffer[y][x] = 0x0;	
}

void LEDMatrixDriver::setPixel(int8_t x, int8_t y, uint8_t pwm)
{
	
	frameBuffer[y][x] = pwm;
	
}

uint8_t LEDMatrixDriver::getPixel(int8_t x, int8_t y) const
{
	return frameBuffer[y][x];
}

void LEDMatrixDriver::setColumn(int8_t x, uint8_t value) //not needed?
{
	//no need to check x, will be checked by setPixel
	for (uint8_t y = 0; y < 8; ++y)
	{
		setPixel(x, y, value & 1);
		value >>= 1;
	}
}

void LEDMatrixDriver::setEnabled(bool enabled)
{
		digitalWrite(enablePin, enabled);
		return;
}


/**
 * Sets a digit to the specified value.
 * Digits are numbered 0..(8*N-1).
 * Digits 0..7 are in the first controller, digits 8..15 in the next, etc.
 */
void LEDMatrixDriver::setDigit(uint16_t digit, uint8_t value, bool dot)
{
	// if (digit >= (8*N)) not needed?
	// 	return;

	// // The frameBuffer is organized as 8 rows of N bytes.
	// uint8_t row = digit & 7;
	// uint8_t controller = digit >> 3;

	// frameBuffer[row * N + controller] = value | (dot ? 1<<7 : 0);
}

void LEDMatrixDriver::_sendCommand(uint8_t Reg_Add, uint8_t Reg_Dat)
{
	Wire.beginTransmission(addr); // transmit to device IS31FL373x
	Wire.write((byte)Reg_Add); // sends regaddress
 	Wire.write((byte)Reg_Dat); // sends regaddress
 	Wire.endTransmission(); // stop transmitting
}

//a helper function used to reverse bits in a byte
static void reverse(uint8_t& b) {
   b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
   b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
   b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
}

void LEDMatrixDriver::_displayRow(uint8_t row)
{
	//writes one row
	return;

}

void LEDMatrixDriver::display()
{
	for (uint8_t y = 0; y < 9; y++)
	{
		_displayRow(y);
	}
}

void LEDMatrixDriver::scroll(scrollDirection direction, bool wrap)
{
	switch( direction )
	{
		case scrollDirection::scrollUp:
		{
			uint8_t tmp[39];							//space for extra row
			if (wrap)
				for(int i = 0; i<39; i++)
					tmp[i] = frameBuffer[0][i];		//save the first row
			else
				memset(tmp, 0, 39);					//or zero the memory
			
			memmove(frameBuffer, frameBuffer+39, sizeof(uint8_t)*39);	//shift 7 rows
			memcpy(frameBuffer + 8*39, tmp, 39);		//last row is zeros or copy of the first row
			break;
		}

		case scrollDirection::scrollDown:
		{
			uint8_t tmp[39];							//space for extra row
			if (wrap)
				for(int i = 0; i<39; i++)
					tmp[i] = frameBuffer[8][i];		//save the last row
			else
				memset(tmp, 0, 39);
			
			memmove(frameBuffer+39, frameBuffer, 8*39);
			memcpy(frameBuffer, tmp, 39);
			break;
		}

		case scrollDirection::scrollLeft:
		{
			uint8_t tmp[9];
			if(wrap)
				for(int i = 0; i<9; i++)
					tmp[i] = frameBuffer[i][0];		//save the first row	
			
			for(int i = 0; i<38; i++)
				for(int j = 0; j<9; j++)
					frameBuffer[i][j] = frameBuffer[i+1][j];

			for(int j = 0; j<9; j++)
					frameBuffer[j][38] = tmp[j];

			break;
		}

		case scrollDirection::scrollRight:
		{
			uint8_t tmp[9];
			if(wrap){
				for(int i = 0; i<9; i++){
					tmp[i] = frameBuffer[i][38];		//save the last row	
				}
			}
				
			
			for(int i = 38; i>0; i--){
				for(int j = 0; j<9; j++){
					frameBuffer[i][j] = frameBuffer[i-1][j];
				}
			}
				
			for(int j = 0; j<9; j++){
				frameBuffer[j][0] = tmp[j];
			}
			break;
		}
	}
}



void LEDMatrixDriver::writePixelLow(uint8_t x, uint8_t y, uint8_t pwm){
	if(IS31FL3741addrmap[y][x][1]) //page 1
		page1buffer[IS31FL3741addrmap[y][x][0]] = pwm;
	else
		page0buffer[IS31FL3741addrmap[y][x][0]] = pwm;

}

void LEDMatrixDriver::updateFrameBuffer(){
	
	for(int x = 0; x<39; x++){
		for(int y = 0; y<9; y++){
			writePixelLow(x, y, frameBuffer[y][x]);	
		}
	}

	//write all of page0 contents
	I2CWriteByte(addr,0xFE,0xC5); //UNLOCK
	I2CWriteByte(addr,0xFD,0x00); //SELECT PAGE
	I2CWriteMultipleBytes(addr, 0x00, page0buffer, 180); //180 i think 127 is the biggest wire buffer size

	//write all of page0 contents
	I2CWriteByte(addr,0xFE,0xC5); //UNLOCK
	I2CWriteByte(addr,0xFD,0x01); //SELECT PAGE
	I2CWriteMultipleBytes(addr, 0x00, page1buffer, 171); //171




    
}


