#include "../lib/ISSI/LEDMatrixDriver.hpp"

#include <Arduino.h>
#include "../include/boardpins.h"

#define byte uint8_t

#define XSIZE 9
#define YSIZE 39

#define Addr_GND 0x30


LEDMatrixDriver lmd(22, 23, Addr_GND, (uint8_t)MATRIX_EN, NULL);


// void matrixTest(){
//     int i;

//     I2CWriteByte(Addr_GND,0xfe,0xc5);//unlock
//     I2CWriteByte(Addr_GND,0xfD,0x00);//write page 0
//     for(i=0;i<0xB4;i++)
//     {
//         I2CWriteByte(Addr_GND,i,0x00);//write all PWM set 0x00
//         //delay(50);
//     }
//     I2CWriteByte(Addr_GND,0xfe,0xc5);//unlock
//     I2CWriteByte(Addr_GND,0xfD,0x01);//write page 1
//     for(i=0;i<0xAB;i++)
//     {
//         I2CWriteByte(Addr_GND,i,0x00);//write all PWM set 0x00
//         //delay(50);

//     } //init all the PWM data to 0
    

//    //IS31FL3741_PWM_Write(0, 1, 1, 0xFF);
    
//     int i, j, k;
//     for(j=1; j<27; j++){
//         for(k=1; k<13; k++){
//             IS31FL3741_PWM_Write(i, j, k, 0x55);
//             delay(100);
//         }
//     }
//     ///////

//    I2CWriteByte(Addr_GND,0xFE,0xC5); UNLOCK
//    I2CWriteByte(Addr_GND,0xFD,0x00); //SELECT PAGE 
//                                      PAGE0 0x00
//                                      PAGE1 0x01
//    I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x00);I2CWriteByte(Addr_GND,0x02,idata);
//     writePixel(0, 0, 0x60);
//     writePixel(1, 1, 0x60);
//     writePixel(3, 3, 0x60);
    

//     delay(500);
//     I2CWriteByte(Addr_GND,0xFE,0xC5);I2CWriteByte(Addr_GND,0xFD,0x01);I2CWriteByte(Addr_GND,0x00,0xFF);

    
// }

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

extern void InitMatrixDriver(int PWM);

void initI2C(){
    // matrix.setTextColor(0x60, 0x00);
    // matrix.setCursor(1, 1);
    // matrix.print("WOLOLO");
    // matrix.setTextWrap(false);
    // matrix.setTextColor(0xC0);
    //textScroll();

    // matrix.drawRect(0, 0, 39, 9, 0x60);
    

}

