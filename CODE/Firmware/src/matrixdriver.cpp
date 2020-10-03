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

    matrix.drawBitmap(0, 0, glasses, 39, 9, 0xE);


    // matrix.setTextColor(0xE, 0x00);
    // matrix.setCursor(7, 1);
    // matrix.print("BRUH");

    // matrix.updateFrameBuffer();
    // matrix.scroll(LEDMatrixDriver::scrollDirection::scrollUp, 0);
    matrix.updateFrameBuffer();


    


}

