#include "../lib/ISSI/LEDMatrixDriver.hpp"

#include <Arduino.h>
#include "../include/boardpins.h"
#include "bitmaps.h"
#include "amongus.h"
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
int currentFrame;
volatile bool scroll = true;
volatile bool annoyingDog = false;
volatile bool bounceAnimation = false;
volatile int iSecret;

/***
 * VERY TEMPORARY
 */

// 'frame_3_delay-0', 39x33px
const unsigned char epd_bitmap_frame_3_delay_0 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0xfc, 0x80, 0x00, 0x00, 0x0d, 
	0xfd, 0x80, 0x00, 0x00, 0x0f, 0xff, 0x80, 0x00, 0x00, 0x0f, 0xff, 0xe0, 0x00, 0x00, 0x0f, 0xff, 
	0xe0, 0x00, 0x00, 0x39, 0xcf, 0xe0, 0x00, 0x00, 0x39, 0xef, 0xe0, 0x00, 0x00, 0x3f, 0xff, 0xfe, 
	0x00, 0x00, 0x3e, 0x3f, 0xff, 0xc0, 0x00, 0x3e, 0x3f, 0xff, 0xc0, 0x00, 0x36, 0x73, 0xff, 0xff, 
	0xf0, 0x26, 0x73, 0xff, 0xff, 0xf0, 0x38, 0x0f, 0xff, 0xff, 0x80, 0x38, 0x0f, 0xff, 0xff, 0x80, 
	0x3f, 0xff, 0xff, 0xff, 0x80, 0x3f, 0xff, 0xff, 0xff, 0x80, 0x3f, 0xff, 0xff, 0xff, 0x80, 0x3f, 
	0xff, 0xff, 0xff, 0x80, 0x3f, 0xff, 0xff, 0xff, 0x80, 0x3f, 0xff, 0xff, 0xff, 0x80, 0x3f, 0xff, 
	0xff, 0xff, 0x80, 0x3f, 0xff, 0xff, 0xfe, 0x00, 0x1f, 0xff, 0xff, 0xfe, 0x00, 0x0f, 0xff, 0xff, 
	0xfe, 0x00, 0x0e, 0x3c, 0x07, 0x0e, 0x00, 0x0e, 0x3c, 0x07, 0x0e, 0x00, 0x0e, 0x30, 0x06, 0x0e, 
	0x00, 0x0e, 0x10, 0x04, 0x0e, 0x00, 0x08, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00
};
// 'frame_2_delay-0', 39x33px
const unsigned char epd_bitmap_frame_2_delay_0 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0xfc, 0x80, 0x00, 0x00, 0x0d, 
	0xfd, 0x80, 0x00, 0x00, 0x0f, 0xff, 0x80, 0x00, 0x00, 0x0f, 0xff, 0xe0, 0x00, 0x00, 0x0f, 0xff, 
	0xe0, 0x00, 0x00, 0x39, 0xcf, 0xe0, 0x00, 0x00, 0x39, 0xef, 0xe0, 0x00, 0x00, 0x3f, 0xff, 0xfe, 
	0x01, 0x80, 0x3e, 0x3f, 0xff, 0xc1, 0x80, 0x3e, 0x3f, 0xff, 0xc1, 0x80, 0x36, 0x73, 0xff, 0xff, 
	0x80, 0x26, 0x73, 0xff, 0xff, 0x80, 0x38, 0x0f, 0xff, 0xff, 0x80, 0x38, 0x0f, 0xff, 0xff, 0x80, 
	0x3f, 0xff, 0xff, 0xff, 0x80, 0x3f, 0xff, 0xff, 0xff, 0x80, 0x3f, 0xff, 0xff, 0xff, 0x80, 0x3f, 
	0xff, 0xff, 0xff, 0x80, 0x3f, 0xff, 0xff, 0xff, 0x80, 0x3f, 0xff, 0xff, 0xff, 0x80, 0x3f, 0xff, 
	0xff, 0xff, 0x80, 0x3f, 0xff, 0xff, 0xfe, 0x00, 0x1f, 0xff, 0xff, 0xfe, 0x00, 0x0f, 0xff, 0xff, 
	0xfe, 0x00, 0x0e, 0x3c, 0x07, 0x0e, 0x00, 0x0e, 0x3c, 0x07, 0x0e, 0x00, 0x08, 0x3c, 0x07, 0x0c, 
	0x00, 0x08, 0x3c, 0x07, 0x08, 0x00, 0x00, 0x30, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00
};

// Array of all bitmaps for convenience. (Total bytes used to store images in PROGMEM = 384)
const int epd_bitmap_allArray_LEN = 2;
const unsigned char* epd_bitmap_allArray[2] = {
	epd_bitmap_frame_2_delay_0,
	epd_bitmap_frame_3_delay_0
};

void initMatrix(){
    xStringSemaphore = xSemaphoreCreateBinary();
    Serial.print("Initializing Matrix...");
    matrix.begin();
    matrix.setEnabled(1);
    Serial.print("Done!\n");
    return;
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

int animation(int speed, int framerate, bool shake, int y)
{
    int padding = -10; //default 1
    if (shake) iSecret = rand() % 5;
    else iSecret = 0;
    // Serial.println("iSecret: " + String(iSecret));

	matrix.fillScreen(0);	
	//for (y; y < 33-9; y++) {
    if (!bounceAnimation){
        if (y == 33-9-padding) bounceAnimation = true;
		matrix.fillScreen(0);
		// matrix.drawBitmap(iSecret, -y, epd_bitmap_allArray[currentFrame], 39, 9+y, brightness);
		matrix.drawBitmap(iSecret, -y, amongusallArray[currentFrame], 39, 9+y, brightness);
        matrix.updateFrameBuffer();
        y++;
		delay(speed);
	}
    //for(y; y >= 0; y--){
    else {
        if (y == 0) bounceAnimation = false;
		matrix.fillScreen(0);
		matrix.drawBitmap(iSecret, -y, amongusallArray[currentFrame], 39, 9+y, brightness);
        matrix.updateFrameBuffer();
        y--;
		delay(speed);
    }
    currentFrame = (currentFrame+1) % amongusallArray_LEN;
    return y;
}


void vMatrixTask(){
    srand (time(NULL));
    int text_y = 1;
    uint16_t w, h;
    int16_t ignore;
    int max_strings;
    int x_positions[10];
    int x_positions_init[10];
    int i, y = 0, currentFrame = 0;
    int spawn_position;
    portBASE_TYPE xStatusQ;
    // String text = "The quick brown fox jumps over the lazy dog ";   // A message to scroll
    
    // xSemaphoreTake( xStringSemaphore, portMAX_DELAY );
    Serial.println(textRX);
    // Serial.println(annoyingDogFrame1[0]);

    text = "";
    text = textRX;
    for(i=0;i<spacing;i++)
        text += " ";
    matrix.setTextColor(brightness);
    matrix.fillScreen(0);
    matrix.updateFrameBuffer();
    text_y = 1;
    matrix.setTextWrap(false);

    // Get text dimensions to determine X coord where scrolling resets
    
    matrix.getTextBounds(text, 0, 0, &ignore, &ignore, &w, &h);
    // Serial.print("Text size: "); Serial.println(w);
    Serial.println("Matrix width: " + String(matrix.width()));
    Serial.println("w: " + String(w));
    Serial.println("matrix width / w: " + String(matrix.width() / w));
    max_strings = (matrix.width() / w) + 2;
    Serial.println(max_strings);

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
                y = animation(100, 1, false, y);
            else {
                /***
                 * I'll refactor this later.
                 * Maybe.
                 ***/
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
                /***
                 * Maybe I won't tho
                 ***/
            }
        }
    }
}

