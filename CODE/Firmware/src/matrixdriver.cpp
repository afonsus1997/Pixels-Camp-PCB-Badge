#include "../lib/ISSI/LEDMatrixDriver.hpp"

#include <Arduino.h>
#include "../include/boardpins.h"

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

    matrix.setPixel(3, 3, 0x3);

    matrix.updateFrameBuffer();
    


}

