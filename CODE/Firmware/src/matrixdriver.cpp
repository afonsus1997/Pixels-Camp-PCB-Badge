#include "../include/matrixdriver.h"



void I2CWriteByte(int Dev_Add,int Reg_Add,int Reg_Dat)
{
 Wire.beginTransmission(Dev_Add/2); // transmit to device IS31FL373x
 Wire.write(Reg_Add); // sends regaddress
 Wire.write(Reg_Dat); // sends regaddress
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
    I2CWriteByte(Addr_GND,0x00,0x01);//normal operation

    
}

void matrixTest(){
    int i;

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


}

void initI2C(){
    Wire.begin(23,22);
    Wire.setClock(400000);//I2C 1MHz
    delay(500);
    InitMatrixDriver(0);
    matrixTest();
}