/*
 * LEDMatrixDriver.h
 *
 *  Created on: 30.03.2017
 *      Author: Bartosz Bielawski
 */

/*
 * This is a driver for MAX7219 based LED matrix displays.
 * It was written to replace the one already available as a library in Arduino repository.
 *
 * The differences are:
 * 	* This driver uses hardware SPI which makes it much faster (with exception of soft SS)
 * 	* Display or displayRow() has to be used to refresh the display
 * 	* up to 255 segments are supported.
 * 	* can use an external memory or self-allocated buffer
 */

#ifndef LEDMATRIXDRIVER_H_
#define LEDMATRIXDRIVER_H_
#include <Arduino.h>

#ifdef ESP32
#include <cstring>
#endif




#include "../AdafruitGFX/Adafruit_GFX.h"

class LEDMatrixDriver: public Adafruit_GFX

{
	//commands as defined in the datasheet

	
	
	public:
		const static uint8_t INVERT_SEGMENT_X = 1;
		const static uint8_t INVERT_DISPLAY_X = 2;
		const static uint8_t INVERT_Y = 4;

		//with N segments and ssPin as SS,
		//flags describe segment orientation (optional)
		//an already allocated buffer can be provided as well (optional)
		LEDMatrixDriver(uint8_t sdaPin, uint8_t sclPin, uint8_t addr, uint8_t enablePin);
		// virtual
		// ~LEDMatrixDriver();

		//we don't want to copy the object
		// LEDMatrixDriver(const LEDMatrixDriver& other) = delete;
		// LEDMatrixDriver(LEDMatrixDriver& other) = delete;
		// LEDMatrixDriver& operator=(const LEDMatrixDriver& other) = delete;

		// #ifdef USE_ADAFRUIT_GFX
		// void writePixel(uint8_t x, uint8_t y, uint8_t color) {setPixel(x,y,color);}
		virtual void drawPixel(int16_t x, int16_t y, uint16_t color) {setPixel(x,y,color);}
		// virtual void endWrite(void) {return;}//{if (not manualDisplayRefresh) display();}
		virtual void setManualDisplayRefresh(bool enabled) {return;}//{manualDisplayRefresh = enabled;}
		// #endif

		void writePixelLow(uint8_t x, uint8_t y, uint8_t pwm);
		void unloadI2CBuffer();

		//all these commands work on ALL segments
		void setEnabled(bool enabled);
		//display brightness: 0 - 15
		void setIntensity(uint8_t level);
		void setPixel(int8_t x, int8_t y, uint8_t pwm);
		uint8_t getPixel(int8_t x, int8_t y) const;
		//sets pixels in the column acording to value (LSB => y=0)
		void setColumn(int8_t x, uint8_t value);
		// uint8_t getSegments() const {return N;}
		
		uint8_t** getFrameBuffer() const {return frameBuffer;}

		//functions for 7-segment displays
		//number of digits displayed (0 -> 1 digit, 7 -> 8 digits)
		void setScanLimit(uint8_t level);
		void setDecode(uint8_t mask);
		void setDigit(uint16_t digit, uint8_t value, bool dot = false);

		//flush the data to the display
		void display();
		//flush a single row to the display
		void displayRow(uint8_t row) {_displayRow(row);}
		//clear the framebuffer
		// void clear() {memset(frameBuffer, 0, 39*9);}
		void clear() {return;}
		/*void clea() {
			int*** array2d = new (int**)[rows];
			for (int i = 0; i < rows; ++i) {
  				array2d[i] = new (int*)[cols];
}
		}*/
		
		enum class scrollDirection 
		{
			scrollUp = 0,
			scrollDown,
			scrollLeft,
			scrollRight
		};
		
		//scroll the framebuffer 1 pixel in the given direction
		void scroll(scrollDirection direction, bool wrap=false);

		// BCD Code B values
		const static uint8_t BCD_DASH =     0x0A;
		const static uint8_t BCD_E =        0x0B;
		const static uint8_t BCD_H =        0x0C;
		const static uint8_t BCD_L =        0x0D;
		const static uint8_t BCD_P =        0x0E;
		const static uint8_t BCD_BLANK =    0x0F;

	private:
		uint8_t* _getBufferPtr(int16_t x, int16_t y) const;
		void _sendCommand(uint8_t Reg_Add, uint8_t Reg_Dat);
		void _displayRow(uint8_t row);

		uint8_t** frameBuffer;
		bool selfAllocated;
		uint8_t sdaPin;
		uint8_t sclPin;
		uint8_t addr;
		uint8_t enablePin;
		byte page0buffer[180];
    	byte page1buffer[171];

		#ifdef USE_ADAFRUIT_GFX
		bool manualDisplayRefresh = true;
		#endif
};

#endif /* LEDMATRIXDRIVER_H_ */
