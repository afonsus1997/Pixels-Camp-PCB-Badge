// ------------------------------------
// µGUI example project
// http://www.embeddedlightning.com/
// ------------------------------------

#include "ltdc.h"

u32 ltdc_active_layer;
u32 ltdc_work_layer;

void pset(UG_S16 x, UG_S16 y, UG_COLOR col)
{
   uint32_t addr;
   uint8_t r,g,b;

   if ( x<0 ) return;
   if ( y<0 ) return;

   addr = x + y * LCD_PIXEL_WIDTH;
   addr<<=1;

   r = col>>16 & 0xFF;
   g = col>>8 & 0xFF;
   b = col & 0xFF;

   r >>= 3;
   g >>= 2;
   b >>= 3;

   col = b | (g<<5) | (r<<11);

   if ( ltdc_work_layer == LAYER_1 )
   {
      sdram_write_16(LAYER_1_OFFSET+addr,col);
   }
   else
   {
      sdram_write_16(LAYER_2_OFFSET+addr,col);
   }
}

void ltdc_draw_layer( u32 layer )
{
   if ( layer == LAYER_FOREGROUND )
   {
      ltdc_work_layer = LAYER_2;
   }
   else
   {
      ltdc_work_layer = LAYER_1;
   }
}


void ltdc_show_layer( u32 layer )
{
   if ( layer == LAYER_FOREGROUND )
   {
      LTDC_LayerAlpha(LTDC_Layer2, 255);
   }
   else
   {
      LTDC_LayerAlpha(LTDC_Layer2, 0);
   }
   LTDC_ReloadConfig(LTDC_VBReload);
   ltdc_active_layer = layer;
}

void ltdc_fade_to_layer( u32 layer )
{
   u8 v;
   if ( layer == LAYER_FOREGROUND )
   {
      v = 0;
      do
      {
         LTDC_LayerAlpha(LTDC_Layer2, v);
         LTDC_ReloadConfig(LTDC_IMReload);
         delay_ms(10);
      }while(v++ < 0xFF);
   }
   else
   {
      v = 255;
      do
      {
         LTDC_LayerAlpha(LTDC_Layer2, v);
         LTDC_ReloadConfig(LTDC_IMReload);
         delay_ms(10);
      }while(v--);
   }
   ltdc_active_layer = layer;
}

void ltdc_toggle_layer( void )
{
   if ( ltdc_active_layer == LAYER_FOREGROUND )
   {
      ltdc_show_layer( LAYER_BACKGROUND );
   }
   else
   {
      ltdc_show_layer( LAYER_FOREGROUND );
   }
}

void ltdc_init( void )
{
   LTDC_InitTypeDef       LTDC_InitStruct;

   RCC_APB2PeriphClockCmd(RCC_APB2Periph_LTDC, ENABLE);     /* Enable the LTDC Clock   */
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2D, ENABLE);    /* Enable the DMA2D Clock  */

   ltdc_gpio_init();

   /* Polarity configuration */
   LTDC_InitStruct.LTDC_HSPolarity = HSPOL;
   LTDC_InitStruct.LTDC_VSPolarity = VSPOL;
   LTDC_InitStruct.LTDC_DEPolarity = DEPOL;
   LTDC_InitStruct.LTDC_PCPolarity = PCLKPOL;

   /* Configure R,G,B component values for LCD background color */
   LTDC_InitStruct.LTDC_BackgroundRedValue = 0;
   LTDC_InitStruct.LTDC_BackgroundGreenValue = 0;
   LTDC_InitStruct.LTDC_BackgroundBlueValue = 0;

   /* Configure PLLSAI prescalers for LCD */
   /* Enable Pixel Clock */
   /* PLLSAI_VCO Input = HSE_VALUE/PLL_M = 1 Mhz */
   /* PLLSAI_VCO Output = PLLSAI_VCO Input * PLLSAI_N = 192 Mhz */
   /* PLLLCDCLK = PLLSAI_VCO Output/PLLSAI_R = 192/4 = 48 Mhz */
   /* LTDC clock frequency = PLLLCDCLK / RCC_PLLSAIDivR = 48/8 = 6 Mhz */


   /* Discovery 2.8" */
   RCC_PLLSAIConfig(192, 7, 4);
   RCC_LTDCCLKDivConfig(RCC_PLLSAIDivR_Div8);


   /* Enable PLLSAI Clock */
   RCC_PLLSAICmd(ENABLE);
   /* Wait for PLLSAI activation */
   while(RCC_GetFlagStatus(RCC_FLAG_PLLSAIRDY) == RESET){}

   LTDC_InitStruct.LTDC_HorizontalSync = THS-1;
   LTDC_InitStruct.LTDC_VerticalSync = TVS-1;
   LTDC_InitStruct.LTDC_AccumulatedHBP = THS+THB-1;
   LTDC_InitStruct.LTDC_AccumulatedVBP = TVS+TVB-1;
   LTDC_InitStruct.LTDC_AccumulatedActiveW = THS+THB+THD-1;
   LTDC_InitStruct.LTDC_AccumulatedActiveH = TVS+TVB+TVD-1;
   LTDC_InitStruct.LTDC_TotalWidth = THS+THB+THD+THF-1;
   LTDC_InitStruct.LTDC_TotalHeigh = TVS+TVB+TVD+TVF-1;
   LTDC_Init(&LTDC_InitStruct);

   ltdc_layer_init();
}

void ltdc_gpio_init( void )
{
   GPIO_InitTypeDef GPIO_InitStruct;

   /* Enable GPIOA, GPIOB, GPIOC, GPIOD, GPIOF, GPIOG AHB Clocks */
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB | \
                          RCC_AHB1Periph_GPIOC | RCC_AHB1Periph_GPIOD | \
                          RCC_AHB1Periph_GPIOF | RCC_AHB1Periph_GPIOG, ENABLE);


   /* GPIOA configuration */
   GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_LTDC);
   GPIO_PinAFConfig(GPIOA, GPIO_PinSource4, GPIO_AF_LTDC);
   GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_LTDC);
   GPIO_PinAFConfig(GPIOA, GPIO_PinSource11, GPIO_AF_LTDC);
   GPIO_PinAFConfig(GPIOA, GPIO_PinSource12, GPIO_AF_LTDC);

   GPIO_InitStruct.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_6 | \
                              GPIO_Pin_11 | GPIO_Pin_12;

   GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
   GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
   GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
   GPIO_Init(GPIOA, &GPIO_InitStruct);

   /* GPIOB configuration */
   GPIO_PinAFConfig(GPIOB, GPIO_PinSource0, 0x09);
   GPIO_PinAFConfig(GPIOB, GPIO_PinSource1, 0x09);
   GPIO_PinAFConfig(GPIOB, GPIO_PinSource8, GPIO_AF_LTDC);
   GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF_LTDC);
   GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_LTDC);
   GPIO_PinAFConfig(GPIOB, GPIO_PinSource11, GPIO_AF_LTDC);

   GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_8 | \
                             GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11;

   GPIO_Init(GPIOB, &GPIO_InitStruct);

   /* GPIOC configuration */
   GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_LTDC);
   GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_LTDC);
   GPIO_PinAFConfig(GPIOC, GPIO_PinSource10, GPIO_AF_LTDC);

   GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_10;

   GPIO_Init(GPIOC, &GPIO_InitStruct);

   /* GPIOD configuration */
   GPIO_PinAFConfig(GPIOD, GPIO_PinSource3, GPIO_AF_LTDC);
   GPIO_PinAFConfig(GPIOD, GPIO_PinSource6, GPIO_AF_LTDC);

   GPIO_InitStruct.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_6;

   GPIO_Init(GPIOD, &GPIO_InitStruct);

   /* GPIOF configuration */
   GPIO_PinAFConfig(GPIOF, GPIO_PinSource10, GPIO_AF_LTDC);

   GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;

   GPIO_Init(GPIOF, &GPIO_InitStruct);

   /* GPIOG configuration */
   GPIO_PinAFConfig(GPIOG, GPIO_PinSource6, GPIO_AF_LTDC);
   GPIO_PinAFConfig(GPIOG, GPIO_PinSource7, GPIO_AF_LTDC);
   GPIO_PinAFConfig(GPIOG, GPIO_PinSource10, 0x09);
   GPIO_PinAFConfig(GPIOG, GPIO_PinSource11, GPIO_AF_LTDC);
   GPIO_PinAFConfig(GPIOG, GPIO_PinSource12, 0x09);

   GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_10 | \
                              GPIO_Pin_11 | GPIO_Pin_12;

   GPIO_Init(GPIOG, &GPIO_InitStruct);
}

void ltdc_layer_init(void)
{
   LTDC_Layer_InitTypeDef LTDC_Layer_InitStruct;

   LTDC_Layer_InitStruct.LTDC_HorizontalStart = THS+THB;
   LTDC_Layer_InitStruct.LTDC_HorizontalStop = (THS+THB+THD - 1);
   LTDC_Layer_InitStruct.LTDC_VerticalStart = TVS+TVB;;
   LTDC_Layer_InitStruct.LTDC_VerticalStop = (TVS+TVB+TVD - 1);



   /* Pixel Format configuration */
   LTDC_Layer_InitStruct.LTDC_PixelFormat = LTDC_Pixelformat_RGB565;
   /* Alpha constant (255 totally opaque) */
   LTDC_Layer_InitStruct.LTDC_ConstantAlpha = 255;
   /* Default Color configuration (configure A,R,G,B component values) */
   LTDC_Layer_InitStruct.LTDC_DefaultColorBlue = 0;
   LTDC_Layer_InitStruct.LTDC_DefaultColorGreen = 0;
   LTDC_Layer_InitStruct.LTDC_DefaultColorRed = 0;
   LTDC_Layer_InitStruct.LTDC_DefaultColorAlpha = 0;
   /* Configure blending factors */
   LTDC_Layer_InitStruct.LTDC_BlendingFactor_1 = LTDC_BlendingFactor1_CA;
   LTDC_Layer_InitStruct.LTDC_BlendingFactor_2 = LTDC_BlendingFactor2_CA;

   /* the length of one line of pixels in bytes + 3 then :
   Line Lenth = Active high width x number of bytes per pixel + 3
   Active high width         = LCD_PIXEL_WIDTH
   number of bytes per pixel = 2    (pixel_format : RGB565)
   */
   LTDC_Layer_InitStruct.LTDC_CFBLineLength = ((LCD_PIXEL_WIDTH * 2) + 3);
   /* the pitch is the increment from the start of one line of pixels to the
   start of the next line in bytes, then :
   Pitch = Active high width x number of bytes per pixel */
   LTDC_Layer_InitStruct.LTDC_CFBPitch = (LCD_PIXEL_WIDTH * 2);

   /* Configure the number of lines */
   LTDC_Layer_InitStruct.LTDC_CFBLineNumber = LCD_PIXEL_HEIGHT;

   /* Start Address configuration : the LCD Frame buffer is defined on SDRAM */
   LTDC_Layer_InitStruct.LTDC_CFBStartAdress = (LCD_FRAME_BUFFER + LAYER_1_OFFSET);

   /* Initialize LTDC layer 1 */
   LTDC_LayerInit(LTDC_Layer1, &LTDC_Layer_InitStruct);

   /* Configure Layer2 */
   /* Start Address configuration : the LCD Frame buffer is defined on SDRAM w/ Offset */
   LTDC_Layer_InitStruct.LTDC_CFBStartAdress = (LCD_FRAME_BUFFER + LAYER_2_OFFSET);

   /* Configure blending factors */
   LTDC_Layer_InitStruct.LTDC_BlendingFactor_1 = LTDC_BlendingFactor1_PAxCA;
   LTDC_Layer_InitStruct.LTDC_BlendingFactor_2 = LTDC_BlendingFactor2_PAxCA;

   /* Initialize LTDC layer 2 */
   LTDC_LayerInit(LTDC_Layer2, &LTDC_Layer_InitStruct);

   /* LTDC configuration reload */
   LTDC_ReloadConfig(LTDC_IMReload);

   /* Enable foreground & background Layers */
   LTDC_LayerCmd(LTDC_Layer1, ENABLE);
   LTDC_LayerCmd(LTDC_Layer2, ENABLE);

   /* LTDC configuration reload */
   LTDC_ReloadConfig(LTDC_IMReload);

   /* dithering activation */
   LTDC_DitherCmd(ENABLE);
   LTDC_Cmd(ENABLE);
}
