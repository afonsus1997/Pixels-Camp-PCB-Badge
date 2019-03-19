#include "../include/matrixdriver.h"

#include <Arduino.h>

#define byte uint8_t


void I2CWriteByte(int Dev_Add,int Reg_Add,int Reg_Dat)
{
 Wire.beginTransmission(Dev_Add); // transmit to device IS31FL373x
 Wire.write((byte)Reg_Add); // sends regaddress
 Wire.write((byte)Reg_Dat); // sends regaddress
 Wire.endTransmission(); // stop transmitting
}


void InitMatrixDriver(int PWM)
{
    
    int i;
    int Rdata = 0xFF;
    int Gdata = 0xFF;
    int Bdata = 0xFF;
    
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
    /*
    int x;

    Serial.println("Start i2c-test");

    I2CWriteByte(Addr_GND, 0x01, 0xFF); //gcc
    delay(10);

    I2CWriteByte(Addr_GND, 0x00, 0x8D); //config register
    delay(10);

    Wire.beginTransmission(Addr_GND);
    Wire.write((byte)0xFC);
    Wire.endTransmission();
    Wire.beginTransmission(Addr_GND);
    Wire.requestFrom(Addr_GND, 1);
    x = Wire.read();
    Wire.endTransmission();
    Serial.print("Check: ");Serial.println(x, HEX);
    delay(10);

    Wire.beginTransmission(Addr_GND);
    Wire.write((byte)0x00);
    Wire.endTransmission();
    Wire.beginTransmission(Addr_GND);
    Wire.requestFrom(Addr_GND, 1);
    x = Wire.read();
    Wire.endTransmission();
    Serial.print("Register: ");Serial.println(x, HEX);
    delay(10);

    Wire.beginTransmission(Addr_GND);
    Wire.write((byte)0xF1);
    Wire.endTransmission();
    Wire.beginTransmission(Addr_GND);
    Wire.requestFrom(Addr_GND, 1);
    x = Wire.read();
    Wire.endTransmission();
    Serial.print("OPEN/SHORT: ");Serial.println(x, HEX);
    delay(10);

    Wire.beginTransmission(Addr_GND);
    Wire.write((byte)0x01);
    Wire.endTransmission();
    Wire.beginTransmission(Addr_GND);
    Wire.requestFrom(Addr_GND, 1);
    x = Wire.read();
    Wire.endTransmission();
    Serial.print("Current: ");Serial.println(x, HEX);
    delay(10);*/
    

    
}

void matrixTest(){
    /*int i;

    I2CWriteByte(Addr_GND,0xfe,0xc5);//unlock
    I2CWriteByte(Addr_GND,0xfD,0x00);//write page 0
    for(i=0;i<0xB4;i++)
    {
        I2CWriteByte(Addr_GND,i,0xFF);//write all PWM set 0x00
        delay(50);
    }
    I2CWriteByte(Addr_GND,0xfe,0xc5);//unlock
    I2CWriteByte(Addr_GND,0xfD,0x01);//write page 1
    for(i=0;i<0xAB;i++)
    {
        I2CWriteByte(Addr_GND,i,0xFF);//write all PWM set 0x00
        delay(50);

    } //init all the PWM data to 0
    */

   //IS31FL3741_PWM_Write(0, 1, 1, 0xFF);

    int i, j, k;
    for(j=1; j<27; j++){
        for(k=1; k<13; k++){
            IS31FL3741_PWM_Write(i, j, k, 0x55);
            delay(100);
        }
    }


    
}

void initI2C(){
    Wire.begin(23,22);
    Wire.setClock(400000);//I2C 1MHz
    delay(500);
    //InitMatrixDriver(0);
    //matrixTest();
}