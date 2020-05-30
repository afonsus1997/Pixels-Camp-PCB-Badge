// ------------------------------------
// µGUI example project
// http://www.embeddedlightning.com/
// ------------------------------------

#include "system.h"

#ifndef __DELAY_H
#define __DELAY_H

#define DELAY_TIMER_INPUT_CLK          84000000
#define DELAY_TIMER_FREQUENCY          1000000

void delay_init( void );
void delay_us( uint32_t x );
void delay_ms( uint32_t x ); 

#endif
