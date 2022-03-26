#include "../lib/ISSI/LEDMatrixDriver.hpp"

#include <Arduino.h>
#include "../include/boardpins.h"
#include "bitmaps.h"
#define byte uint8_t

#define XSIZE 9
#define YSIZE 39

SemaphoreHandle_t xI2CSemaphore;
LEDMatrixDriver matrix(MATRIX_SDA, MATRIX_SCL, MATRIX_ADDR_GND, MATRIX_EN);
SemaphoreHandle_t xStringSemaphore;

String textRX = "Pixels Camp Badger!";
String text;
int spacing = 3;
int speed = 50;
int brightness = 5;
volatile bool scroll = true;
volatile bool annoyingDog = false;

/***
 * VERY TEMPORARY
 */
const unsigned char annoyingDogFrame1 [] = {
	// 'frame_3_delay-0, 39x9px
	0xff, 0xfe, 0xff, 0xff, 0xfe, 0xff, 0xfd, 0xef, 0xff, 0xfe, 0xff, 0xff, 0xf7, 0xff, 0xfe, 0xff, 
	0xff, 0xbf, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 
	0xff, 0xff, 0xfe, 0xff, 0xfd, 0x4b, 0xff, 0xfe, 0xff, 0xfe, 0xfb, 0xff, 0xfe
};

const unsigned char annoyingDogFrame2 [] PROGMEM = {
	// 'frame_2_delay-0, 39x9px
	0xff, 0xfe, 0xff, 0xff, 0xfe, 0xff, 0xfd, 0xef, 0xff, 0xfe, 0xff, 0xff, 0xf5, 0xff, 0xfe, 0xff, 
	0xff, 0xbf, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 
	0xff, 0xff, 0xfe, 0xff, 0xfd, 0x4b, 0xff, 0xfe, 0xff, 0xff, 0x27, 0xff, 0xfe
};

// void I2CUnloadTask( void * parameter ){
//     // xSemaphoreTake( xI2CSemaphore,
//     //              portMAX_DELAY);
//     // matrix.unloadI2CBuffer();
//     for(int i = 0; i<39; i++)
//         for(int j = 0; j<9; j++)
//             matrix.writePixelLow(j, i, 0x3);
// }

void initMatrix(){
    xStringSemaphore = xSemaphoreCreateBinary();
    Serial.print("Initializing Matrix...");
    
    // xI2CSemaphore = xSemaphoreCreateBinary();
    // xSemaphoreTake( xI2CSemaphore,
    //              portMAX_DELAY);


    // vTaskSuspendAll();

    matrix.begin();
    matrix.setEnabled(1);
    Serial.print("Done!\n");
    return;

    // for(int i = 0; i<39; i++)
    //     for(int j = 0; j<9; j++)
    //         matrix.writePixelLow(j, i, 0x3);
    // matrix.writePixelLow(2, 2, 0x3);

    // matrix.setPixel(3, 3, 0x3);

    // matrix.drawCircle(4, 4, 4, 0xA);
    // matrix.drawCircle(14, 4, 4, 0xA);
    // matrix.drawCircle(24, 4, 4, 0xA);
    // matrix.drawCircle(34, 4, 4, 0xA);

    // matrix.drawBitmap(0, 0, glasses, 39, 9, 0xE);


    // matrix.setTextColor(0xE, 0x00);
    // matrix.setCursor(7, 1);
   


}

void matrixPrintString(int x){
    matrix.fillScreen(0);
    matrix.print("abcd");
    matrix.updateFrameBuffer();

}

void setBrightness(int brightness){
    matrix.setTextColor(map(brightness, 0, 100, 0, 255));
    matrix.updateFrameBuffer();
}

void vMatrixTask(){

    int string_len;
    int text_x = 0; // Initial text position = off right edge
    int text_y = 1;
    int text_min;
    uint16_t w, h;
    int16_t ignore;
    int max_strings;
    int matrix_width = matrix.width();
    int x_positions[10];
    int x_positions_init[10];
    int i;
    int spawn_position;
    portBASE_TYPE xStatusQ;

    // String text = "The quick brown fox jumps over the lazy dog ";   // A message to scroll
    
    // xSemaphoreTake( xStringSemaphore, portMAX_DELAY );
    Serial.println(textRX);

    text = "";
    text = textRX;
    for(i=0;i<spacing;i++)
        text += " ";
    matrix.setTextColor(brightness);
    matrix.fillScreen(0);
    matrix.updateFrameBuffer();
    // return;
    string_len = text.length();
    text_x = 0; // Initial text position = off right edge
    text_y = 1;
    matrix.setTextWrap(false);

    // Get text dimensions to determine X coord where scrolling resets
    
    matrix.getTextBounds(text, 0, 0, &ignore, &ignore, &w, &h);
    // Serial.print("Text size: "); Serial.println(w);
    max_strings = (matrix.width() / w) + 2;
    // Serial.println(max_strings);

    for(i = 0; i<max_strings; i++){
        x_positions[i] = (w*i);//+matrix_width;
        x_positions_init[i] = (w*i);//+matrix_width;
    }
    spawn_position = (max_strings - 1) * w;

    while (1)
    {
        if (scroll)
        {
            if (annoyingDog)
            {
                matrix.drawBitmap(0, 39, annoyingDogFrame1, 39, 9, brightness);
                matrix.updateFrameBuffer();
                // delay(speed);
                // matrix.drawBitmap(0, 39, annoyingDogFrame2, w, h, brightness);
                // matrix.updateFrameBuffer();
                // delay(speed);
            }
            else
            {
                xStatusQ = xSemaphoreTake(xStringSemaphore, 1);
                if (xStatusQ == pdTRUE)
                {
                    text = "";
                    text = textRX;
                    for (i = 0; i < spacing; i++)
                        text += " ";
                    Serial.println(text);
                    matrix.setTextColor(brightness);
                    matrix.fillScreen(0);
                    matrix.updateFrameBuffer();
                    // return;
                    string_len = text.length();
                    text_x = 0; // Initial text position = off right edge
                    text_y = 1;
                    matrix.setTextWrap(false);

                    // Get text dimensions to determine X coord where scrolling resets

                    matrix.getTextBounds(text, 0, 0, &ignore, &ignore, &w, &h);
                    // Serial.print("Text size: "); Serial.println(w);
                    max_strings = (matrix.width() / w) + 2;
                    // Serial.println(max_strings);

                    for (i = 0; i < max_strings; i++)
                    {
                        x_positions[i] = (w * i);      //+matrix_width;
                        x_positions_init[i] = (w * i); //+matrix_width;
                    }
                    spawn_position = (max_strings - 1) * w;
                }
                else
                {
                    matrix.fillScreen(0);
                    matrix.updateFrameBuffer();

                    for (i = 0; i < max_strings; i++)
                    {
                        matrix.setCursor(x_positions[i], text_y);
                        matrix.print(text); // write the letter
                        --x_positions[i];
                    }
                    for (i = 0; i < max_strings; i++)
                    {
                        if (x_positions[i] == -w)
                        {
                            x_positions[i] = spawn_position;
                        }
                    }
                    matrix.setTextColor(brightness);
                    matrix.updateFrameBuffer();
                    delay(speed);
                }
            }
        }
    }

    // while(1){
        
    //     // delay(70);
    // }
}

