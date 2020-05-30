// ------------------------------------
// µGUI example project
// http://www.embeddedlightning.com/
// ------------------------------------

#ifndef __LTDC_H
#define __LTDC_H

#include "system.h"

#define  THS                     10
#define  THB                     20
#define  THD                     240
#define  THF                     10
#define  TVS                     2
#define  TVB                     2
#define  TVD                     320
#define  TVF                     4

#define  HSPOL                   LTDC_HSPolarity_AL
#define  VSPOL                   LTDC_VSPolarity_AL
#define  DEPOL                   LTDC_DEPolarity_AL
#define  PCLKPOL                 LTDC_PCPolarity_IPC

#define  LCD_PIXEL_WIDTH         (THD)
#define  LCD_PIXEL_HEIGHT        (TVD)

#define  LCD_COLOR_DEPTH         ((u16)2)       /* Farbtiefe: RGB565 --> 2 Bytes / Pixel */

#define  LCD_FRAME_BUFFER        ((u32)SDRAM_BANK_ADDR)
#define  BUFFER_OFFSET           ((u32)LCD_PIXEL_HEIGHT*LCD_PIXEL_WIDTH*LCD_COLOR_DEPTH)
#define  LAYER_1_OFFSET          (0)
#define  LAYER_2_OFFSET          (BUFFER_OFFSET)

#define  LAYER_1                 LAYER_BACKGROUND
#define  LAYER_2                 LAYER_FOREGROUND
#define  LAYER_FOREGROUND        1
#define  LAYER_BACKGROUND        0

void pset(UG_S16 x, UG_S16 y, UG_COLOR col);
void ltdc_draw_layer( u32 layer );
void ltdc_show_layer( u32 layer );
void ltdc_fade_to_layer( u32 layer );
void ltdc_toggle_layer( void );
void ltdc_init( void );
void ltdc_gpio_init( void );
void ltdc_layer_init(void);

#endif
