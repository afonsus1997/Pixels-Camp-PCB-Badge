#include <Arduino.h>
#include "../AdafruitGFX/Adafruit_GFX.h"
#include <Wire.h>
#include "Adafruit_IS31FL3731.h"



#define byte uint8_t

#define XSIZE 9
#define YSIZE 39


#ifndef _swap_int16_t
#define _swap_int16_t(a, b) { int16_t t = a; a = b; b = t; }
#endif

void I2CWriteByte(int Dev_Add,int Reg_Add,int Reg_Dat)
{
 Wire.beginTransmission(Dev_Add); // transmit to device IS31FL373x
 Wire.write((byte)Reg_Add); // sends regaddress
 Wire.write((byte)Reg_Dat); // sends regaddress
 Wire.endTransmission(); // stop transmitting
}




/* Constructor */
IS31FL3731::IS31FL3731(uint8_t x, uint8_t y) : Adafruit_GFX(x, y) {
}

boolean IS31FL3731::begin() {
  
  int i;
    int Rdata = 0xFF;
    int Gdata = 0xFF;
    int Bdata = 0xFF;

    Wire.begin(23,22);
    Wire.setClock(900000);//I2C 1MHz

    I2CWriteByte(Addr_GND,0xfe,0xc5);//unlock
    I2CWriteByte(Addr_GND,0xfD,0x02);//write page 2
    for(i=2;i<0xB4;i+=3)
        {
            I2CWriteByte(Addr_GND,i,Rdata);//R LED Scaling
        }
    for(i=1;i<0xB4;i+=3)
    {
        I2CWriteByte(Addr_GND,i,Gdata);//G LED Scaling
    }
    for(i=0;i<0xB4;i+=3)
    {
        I2CWriteByte(Addr_GND,i,Bdata);//B LED Scaling
    }
    I2CWriteByte(Addr_GND,0xfe,0xc5);//unlock
    I2CWriteByte(Addr_GND,0xfD,0x03);//write page 3
    for(i=2;i<0xAB;i+=3)
    {
        I2CWriteByte(Addr_GND,i,Rdata);//R LED Scaling
    }
    for(i=1;i<0xAB;i+=3)
    {
        I2CWriteByte(Addr_GND,i,Gdata);//G LED Scaling
    }
    for(i=0;i<0xAB;i+=3)
    {
        I2CWriteByte(Addr_GND,i,Bdata);//B LED Scaling
    }
    I2CWriteByte(Addr_GND,0xfe,0xc5);//unlock
    I2CWriteByte(Addr_GND,0xfD,0x00);//write page 0
    for(i=0;i<0xB4;i++)
    {
        I2CWriteByte(Addr_GND,i,0x00);//write all PWM set 0x00
    }
    I2CWriteByte(Addr_GND,0xfe,0xc5);//unlock
    I2CWriteByte(Addr_GND,0xfD,0x01);//write page 1
    for(i=0;i<0xAB;i++)
    {
        I2CWriteByte(Addr_GND,i,0x00);//write all PWM set 0x00
    } //init all the PWM data to 0

    I2CWriteByte(Addr_GND,0xfe,0xc5);//unlock
    I2CWriteByte(Addr_GND,0xfD,0x04);//write page 4
    I2CWriteByte(Addr_GND,0x01,0x7F);//global current
    //I2CWriteByte(Addr_GND,0x01,0xFF);//global current
    I2CWriteByte(Addr_GND,0x00,0x01);//normal operation
    return 1;
}

void IS31FL3731::clear(void) {
  // all LEDs on & 0 PWM

  int x;
}

void IS31FL3731::setLEDPWM(uint8_t lednum, uint8_t pwm, uint8_t bank) {
  //if (lednum >= 144) return;
  //writeRegister8(bank, 0x24+lednum, pwm);
  int x;
}


void IS31FL3731::drawPixel(int16_t x, int16_t y, uint16_t pwm) {
 // check rotation, move pixel around if necessary
  byte page;
	byte address;
  
  if(x > 38 || y > 8) return;

	if(x <= 29 && y <= 5){ //page0
		
		page = 0x00;
		address = y*0x1E; //base address of Y
		address += x;
   	I2CWriteByte(Addr_GND,0xFE,0xC5); //UNLOCK
		I2CWriteByte(Addr_GND,0xFD,page); //SELECT PAGE
		I2CWriteByte(Addr_GND,address,pwm); //WRITE PIXEL

	}
	else{
		page = 0x01;
    if(x<=29 && y>=6){
      address = (y-6)*0x1E;
      address += x;
      I2CWriteByte(Addr_GND,0xFE,0xC5); //UNLOCK
	  	I2CWriteByte(Addr_GND,0xFD,page); //SELECT PAGE
  		I2CWriteByte(Addr_GND,address,pwm); //WRITE PIXEL
    }
    else{
      address = y*9;
      address += 0x5A;
      address += (x-30);
      I2CWriteByte(Addr_GND,0xFE,0xC5); //UNLOCK
	  	I2CWriteByte(Addr_GND,0xFD,page); //SELECT PAGE
  		I2CWriteByte(Addr_GND,address,pwm); //WRITE PIXEL
    }
	}
  return;
}


/*************/
void IS31FL3731::writeRegister8(uint8_t b, uint8_t reg, uint8_t data) {

  Wire.beginTransmission(Addr_GND);
  Wire.write((byte)reg);
  Wire.write((byte)data);
  Wire.endTransmission();
  //Serial.print("$"); Serial.print(reg, HEX);
  //Serial.print(" = 0x"); Serial.println(data, HEX);
}

uint8_t  IS31FL3731::readRegister8(uint8_t bank, uint8_t reg) {
 uint8_t x;

// Serial.print("$"); Serial.print(reg, HEX);
//  Serial.print(": 0x"); Serial.println(x, HEX);

  return x;
}
