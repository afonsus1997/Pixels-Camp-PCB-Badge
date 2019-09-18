#include "../include/matrixdriver.h"
#include "../lib/ISSI/Adafruit_IS31FL3731.h"

#include <Arduino.h>

#define byte uint8_t

#define XSIZE 9
#define YSIZE 39

#define Addr_GND 0x30

IS31FL3731 matrix = IS31FL3731();


void InitMatrixDriver(int PWM)
{
    int x;
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
/*
void matrixTest(){
    int i;

    I2CWriteByte(Addr_GND,0xfe,0xc5);//unlock
    I2CWriteByte(Addr_GND,0xfD,0x00);//write page 0
    for(i=0;i<0xB4;i++)
    {
        I2CWriteByte(Addr_GND,i,0x00);//write all PWM set 0x00
        //delay(50);
    }
    I2CWriteByte(Addr_GND,0xfe,0xc5);//unlock
    I2CWriteByte(Addr_GND,0xfD,0x01);//write page 1
    for(i=0;i<0xAB;i++)
    {
        I2CWriteByte(Addr_GND,i,0x00);//write all PWM set 0x00
        //delay(50);

    } //init all the PWM data to 0
    

   //IS31FL3741_PWM_Write(0, 1, 1, 0xFF);
    /*
    int i, j, k;
    for(j=1; j<27; j++){
        for(k=1; k<13; k++){
            IS31FL3741_PWM_Write(i, j, k, 0x55);
            delay(100);
        }
    }
    ///////

   //I2CWriteByte(Addr_GND,0xFE,0xC5); UNLOCK
   //I2CWriteByte(Addr_GND,0xFD,0x00); //SELECT PAGE 
                                     //PAGE0 0x00
                                     //PAGE1 0x01
   //I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x02,idata);
    writePixel(0, 0, 0x60);
    writePixel(1, 1, 0x60);
    writePixel(3, 3, 0x60);
    

    delay(500);
    //I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x00,0xFF);

    
}*/

/*void textScroll(){
    while(1){
        //String text = "    //HABIT #IoTWizard    "; // sample text
        String text = "    Next Pixels When, Celso?    "; // sample text
        
        //const int width = 6; // width of the marquee display (in characters)

        for (int offset = 0; offset < text.length(); offset++)
        {
        // Construct the string to display for this iteration
            //matrix.fillRect(0, 1, 35, 9, 0x00);            
        
        String t = "";
        for (int i = 0; i < width; i++){
            t += text.charAt((offset + i) % text.length());
            // Print the string for this iteration
            matrix.setCursor(0, 1); // display will be halfway down screen
            matrix.print(t);
            //Serial.print("Current String: "); Serial.println(t);
            // Short delay so the text doesn't move too fast
            //delay(10);
            

            }
            delay(125);
            matrix.setCursor(0, 1);
            matrix.setTextColor(0x00);
            matrix.print(t);
            matrix.setTextColor(0xC0);
            

        }
    }
}*/

void initI2C(){
    //Wire.begin(23,22);
    //Wire.setClock(400000);//I2C 1MHz
    //delay(500);
    //InitMatrixDriver(0);
    matrix.begin();
    //matrix.drawPixel(0, 0, 0xFF);
    //matrix.setTextColor(0x60, 0x00);
    matrix.setCursor(2, 1);
    matrix.print("*DEEC*");
    //matrix.setTextWrap(false);
    matrix.setTextColor(0xC0);
    //textScroll();

    //matrix.drawRect(0, 0, 39, 9, 0x60);
    

}

