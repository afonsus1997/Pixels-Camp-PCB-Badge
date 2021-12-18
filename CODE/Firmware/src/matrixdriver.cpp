#include "../lib/ISSI/LEDMatrixDriver.hpp"

#include <Arduino.h>
#include "../include/boardpins.h"
#include "bitmaps.h"

#define byte uint8_t

#define XSIZE 9
#define YSIZE 39

SemaphoreHandle_t xI2CSemaphore;


// void I2CUnloadTask( void * parameter ){
//     // xSemaphoreTake( xI2CSemaphore,
//     //              portMAX_DELAY);
//     // matrix.unloadI2CBuffer();
//     for(int i = 0; i<39; i++)
//         for(int j = 0; j<9; j++)
//             matrix.writePixelLow(j, i, 0x3);
// }



void initMatrix(){
    Serial.print("Initializing Matrix...");
    
    // xI2CSemaphore = xSemaphoreCreateBinary();
    // xSemaphoreTake( xI2CSemaphore,
    //              portMAX_DELAY);


    // vTaskSuspendAll();
 
    LEDMatrixDriver matrix(MATRIX_SDA, MATRIX_SCL, MATRIX_ADDR_GND, MATRIX_EN);

    matrix.setEnabled(1);
    Serial.print("Done!\n");

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
    matrix.setTextColor(5);
    // matrix.print("BRUH");

    // matrix.updateFrameBuffer();
    // matrix.scroll(LEDMatrixDriver::scrollDirection::scrollUp, 0);
    matrix.updateFrameBuffer();

    String text = "Wololo  ";   // A message to scroll
    int string_len = text.length();
    int text_x = 0; // Initial text position = off right edge
    int text_y = 1;
    int text_min;
    matrix.setTextWrap(false);

    // Get text dimensions to determine X coord where scrolling resets
    uint16_t w, h;
    int16_t ignore;
    matrix.getTextBounds(text, 0, 0, &ignore, &ignore, &w, &h);
    Serial.print("Text size: "); Serial.println(w);
    int max_strings = (matrix.width() / w) + 2;
    Serial.println(max_strings);
    int matrix_width = matrix.width();

    int x_positions[10];
    int x_positions_init[10];
    int i;
    for(i = 0; i<max_strings; i++){
        x_positions[i] = (w*i);//+matrix_width;
        x_positions_init[i] = (w*i);//+matrix_width;
    }

    Serial.println("Positions: ");
    for(i = 0; i<max_strings; i++){
        Serial.print(x_positions[i]);  Serial.print(",");
    }
    Serial.println();

    

    int current_string = 0;
    int next_string;

    //next_string = next_string + 1 % max_strings;


  text_min = -w; // Off left edge this many pixels
//   text_min = matrix_width - w;

    while(1){
        matrix.fillScreen(0);
        matrix.updateFrameBuffer();
        
        for(i = 0; i<max_strings; i++){
            matrix.setCursor(x_positions[i], text_y);
            matrix.print(text); // write the letter
            --x_positions[i];
        }
        for(i = 0; i<max_strings; i++){
            if(x_positions[i] == -w){
                x_positions[i] = x_positions_init[max_strings-1];
            }
        }
        

        
        // if (--x_positions[0] < text_min) {
        //     x_positions[0] = matrix.width();
        // }
        matrix.updateFrameBuffer();
        delay(25);
    }



    


}

