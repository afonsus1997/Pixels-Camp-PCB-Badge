// ------------------------------------
// �GUI example project
// http://www.embeddedlightning.com/
// ------------------------------------

#include "system.h"
#include "image.h"

/* GUI structure */
UG_GUI gui;

/* Touch structure */
static TP_STATE* TP_State;

/* Some defines */
#define MAX_OBJECTS        10
#define TOGGLE_GREEN_LED   GPIO_ToggleBits(GPIOG,GPIO_Pin_13);
#define TOGGLE_RED_LED     GPIO_ToggleBits(GPIOG,GPIO_Pin_14);

/* Window 1 */
UG_WINDOW window_1;
UG_OBJECT obj_buff_wnd_1[MAX_OBJECTS];
UG_BUTTON button1_1;
UG_BUTTON button1_2;
UG_BUTTON button1_3;
UG_BUTTON button1_4;
UG_BUTTON button1_5;
UG_BUTTON button1_6;

/* Window 2 */
UG_WINDOW window_2;
UG_OBJECT obj_buff_wnd_2[MAX_OBJECTS];
UG_BUTTON button2_1;
UG_TEXTBOX textbox2_1;
UG_TEXTBOX textbox2_2;
UG_IMAGE image2_1;

/* Window 3 */
UG_WINDOW window_3;
UG_OBJECT obj_buff_wnd_3[MAX_OBJECTS];
UG_BUTTON button3_1;
UG_TEXTBOX textbox3_1;

/* FSM */
#define STATE_MAIN_MENU                0
#define STATE_BENCHMARK_RUN            1
#define STATE_BENCHMARK_RESULT         2
volatile UG_U32 state;
volatile UG_U32 next_state;

/* Benchmark */
volatile UG_U32 timer;
volatile UG_U32 hw_acc = 1;
char result_str[30];
UG_S16 xs,ys;
UG_S16 xe,ye;
UG_COLOR c;

/* Hardware accelerator for UG_DrawLine (Platform: STM32F4x9) */
UG_RESULT _HW_DrawLine( UG_S16 x1, UG_S16 y1, UG_S16 x2, UG_S16 y2, UG_COLOR c )
{
   DMA2D_InitTypeDef DMA2D_InitStruct;

   RCC_AHB1PeriphResetCmd(RCC_AHB1Periph_DMA2D, ENABLE);
   RCC_AHB1PeriphResetCmd(RCC_AHB1Periph_DMA2D, DISABLE);
   DMA2D_InitStruct.DMA2D_Mode = DMA2D_R2M;
   DMA2D_InitStruct.DMA2D_CMode = DMA2D_RGB565;
   /* Convert UG_COLOR to RGB565 */
   DMA2D_InitStruct.DMA2D_OutputBlue = (c>>3) & 0x1F;
   DMA2D_InitStruct.DMA2D_OutputGreen = (c>>10) & 0x3F;
   DMA2D_InitStruct.DMA2D_OutputRed = (c>>19) & 0x1F;
   DMA2D_InitStruct.DMA2D_OutputAlpha = 0x0F;

   /* horizontal line */
   if ( y1 == y2 )
   {
      DMA2D_InitStruct.DMA2D_OutputOffset = 0;
      DMA2D_InitStruct.DMA2D_NumberOfLine = 1;
      DMA2D_InitStruct.DMA2D_PixelPerLine = x2-x1+1;
   }
   /* vertical line */
   else if ( x1 == x2 )
   {
      DMA2D_InitStruct.DMA2D_OutputOffset = LCD_PIXEL_WIDTH - 1;
      DMA2D_InitStruct.DMA2D_NumberOfLine = y2-y1+1;
      DMA2D_InitStruct.DMA2D_PixelPerLine = 1;
   }
   else
   {
      return UG_RESULT_FAIL;
   }

   if ( ltdc_work_layer == LAYER_1 )
   {
      DMA2D_InitStruct.DMA2D_OutputMemoryAdd = SDRAM_BANK_ADDR + LAYER_1_OFFSET + 2*(LCD_PIXEL_WIDTH * y1 + x1);
   }
   else
   {
      DMA2D_InitStruct.DMA2D_OutputMemoryAdd = SDRAM_BANK_ADDR + LAYER_2_OFFSET + 2*(LCD_PIXEL_WIDTH * y1 + x1);
   }
   DMA2D_Init(&DMA2D_InitStruct);
   DMA2D_StartTransfer();
   while(DMA2D_GetFlagStatus(DMA2D_FLAG_TC) == RESET){};
   return UG_RESULT_OK;
}

/* Hardware accelerator for UG_FillFrame (Platform: STM32F4x9) */
UG_RESULT _HW_FillFrame( UG_S16 x1, UG_S16 y1, UG_S16 x2, UG_S16 y2, UG_COLOR c )
{
   DMA2D_InitTypeDef      DMA2D_InitStruct;

   DMA2D_DeInit();
   DMA2D_InitStruct.DMA2D_Mode = DMA2D_R2M;
   DMA2D_InitStruct.DMA2D_CMode = DMA2D_RGB565;
   /* Convert UG_COLOR to RGB565 */
   DMA2D_InitStruct.DMA2D_OutputBlue = (c>>3) & 0x1F;
   DMA2D_InitStruct.DMA2D_OutputGreen = (c>>10) & 0x3F;
   DMA2D_InitStruct.DMA2D_OutputRed = (c>>19) & 0x1F;
   DMA2D_InitStruct.DMA2D_OutputAlpha = 0x0F;
   DMA2D_InitStruct.DMA2D_OutputOffset = (LCD_PIXEL_WIDTH - (x2-x1+1));
   DMA2D_InitStruct.DMA2D_NumberOfLine = y2-y1+1;
   DMA2D_InitStruct.DMA2D_PixelPerLine = x2-x1+1;
   if ( ltdc_work_layer == LAYER_1 )
   {
      DMA2D_InitStruct.DMA2D_OutputMemoryAdd = SDRAM_BANK_ADDR + LAYER_1_OFFSET + 2*(LCD_PIXEL_WIDTH * y1 + x1);
   }
   else
   {
      DMA2D_InitStruct.DMA2D_OutputMemoryAdd = SDRAM_BANK_ADDR + LAYER_2_OFFSET + 2*(LCD_PIXEL_WIDTH * y1 + x1);
   }
   DMA2D_Init(&DMA2D_InitStruct);

   DMA2D_StartTransfer();
   while(DMA2D_GetFlagStatus(DMA2D_FLAG_TC) == RESET){}
   return UG_RESULT_OK;
}

/* Systick interrupt */
void SysTick_Handler(void)
{
   if ( timer ) timer--;

   if ( state == STATE_MAIN_MENU )
   {
      TP_State = IOE_TP_GetState();
      if( TP_State->TouchDetected )
      {
         if ( (TP_State->X > 0) && (TP_State->X < 239 ) )
         {
            if ( (TP_State->Y > 0) && (TP_State->Y < 319 ) )
            {
               UG_TouchUpdate(TP_State->X,TP_State->Y,TOUCH_STATE_PRESSED);
            }
         }
      }
      else
      {
         UG_TouchUpdate(-1,-1,TOUCH_STATE_RELEASED);
      }
   }

   UG_Update();
}

void led_init(void)
{
   GPIO_InitTypeDef GPIO_InitStructure;

   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
   GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_Init(GPIOG, &GPIO_InitStructure);

   GPIO_ToggleBits(GPIOG,GPIO_Pin_14);
}

void systick_init( void )
{
   /* Init SysTick (100Hz) */
   SystemCoreClockUpdate();
   if (SysTick_Config(SystemCoreClock / 100))
   {
      /* Capture error */
      while (1);
   }
}

/* Callback function for the main menu */
void window_1_callback( UG_MESSAGE* msg )
{
   if ( msg->type == MSG_TYPE_OBJECT )
   {
      if ( msg->id == OBJ_TYPE_BUTTON )
      {
         switch( msg->sub_id )
         {
            case BTN_ID_0: /* Toggle green LED */
            {
               TOGGLE_GREEN_LED;
               break;
            }
            case BTN_ID_1: /* Toggle red LED */
            {
               TOGGLE_RED_LED;
               break;
            }
            case BTN_ID_2: /* Show �GUI info */
            {
               UG_WindowShow( &window_2 );
               break;
            }
            case BTN_ID_3: /* Toggle hardware acceleration */
            {
               if ( !hw_acc )
               {
                  UG_ButtonSetForeColor( &window_1, BTN_ID_3, C_RED );
                  UG_ButtonSetText( &window_1, BTN_ID_3, "HW_ACC\nOFF" );
                  UG_DriverEnable( DRIVER_DRAW_LINE );
                  UG_DriverEnable( DRIVER_FILL_FRAME );
               }
               else
               {
                  UG_ButtonSetForeColor( &window_1, BTN_ID_3, C_BLUE );
                  UG_ButtonSetText( &window_1, BTN_ID_3, "HW_ACC\nON" );
                  UG_DriverDisable( DRIVER_DRAW_LINE );
                  UG_DriverDisable( DRIVER_FILL_FRAME );
               }
               hw_acc = !hw_acc;
               break;
            }
            case BTN_ID_4: /* Start benchmark */
            {
               next_state = STATE_BENCHMARK_RUN;
               break;
            }
            case BTN_ID_5: /* Resize window */
            {
               static UG_U32 tog;

               if ( !tog )
               {
                  UG_WindowResize( &window_1, 0, 40, 239, 319-40 );
               }
               else
               {
                  UG_WindowResize( &window_1, 0, 0, 239, 319 );
               }
               tog = ! tog;
               break;
            }
         }
      }
   }
}

/* Callback function for the info window */
void window_2_callback( UG_MESSAGE* msg )
{
   if ( msg->type == MSG_TYPE_OBJECT )
   {
      if ( msg->id == OBJ_TYPE_BUTTON )
      {
         switch( msg->sub_id )
         {
            case BTN_ID_0:
            {
               UG_WindowHide( &window_2 );
               break;
            }
         }
      }
   }
}

/* Callback function for the result window */
void window_3_callback( UG_MESSAGE* msg )
{
   if ( msg->type == MSG_TYPE_OBJECT )
   {
      if ( msg->id == OBJ_TYPE_BUTTON )
      {
         switch( msg->sub_id )
         {
            /* OK button */
            case BTN_ID_0:
            {
               UG_WindowShow( &window_1 );
               break;
            }
         }
      }
   }
}

/* better rand() function */
UG_U32 randx( void )
{
   static UG_U32 z1 = 12345, z2 = 12345, z3 = 12345, z4 = 12345;
   UG_U32 b;
   b  = ((z1 << 6) ^ z1) >> 13;
   z1 = ((z1 & 4294967294U) << 18) ^ b;
   b  = ((z2 << 2) ^ z2) >> 27;
   z2 = ((z2 & 4294967288U) << 2) ^ b;
   b  = ((z3 << 13) ^ z3) >> 21;
   z3 = ((z3 & 4294967280U) << 7) ^ b;
   b  = ((z4 << 3) ^ z4) >> 12;
   z4 = ((z4 & 4294967168U) << 13) ^ b;
   return (z1 ^ z2 ^ z3 ^ z4);
}

int main(void)
{
   SystemInit();
   delay_init();
   sdram_init();
   ltdc_init();
   ili9341_init();
   led_init();

   /* Init �GUI */
   UG_Init(&gui,(void(*)(UG_S16,UG_S16,UG_COLOR))pset,240,320);

   /* Init Touch */
   IOE_Config();

   /* Register hardware acceleration */
   UG_DriverRegister( DRIVER_DRAW_LINE, (void*)_HW_DrawLine );
   UG_DriverRegister( DRIVER_FILL_FRAME, (void*)_HW_FillFrame );
   UG_DriverEnable( DRIVER_DRAW_LINE );
   UG_DriverEnable( DRIVER_FILL_FRAME );

   /* Init SysTick (100Hz) */
   systick_init();

   /* Clear Screen */
   ltdc_draw_layer(LAYER_1);
   ltdc_show_layer(LAYER_1);
   UG_FillScreen( C_BLACK );

   /* Create Window 1 */
   UG_WindowCreate( &window_1, obj_buff_wnd_1, MAX_OBJECTS, window_1_callback );
   UG_WindowSetTitleText( &window_1, "�GUI @ STM32F429" );
   UG_WindowSetTitleTextFont( &window_1, &FONT_12X20 );

   /* Create some Buttons */
   UG_ButtonCreate( &window_1, &button1_1, BTN_ID_0, 10, 10, 110, 60 );
   UG_ButtonCreate( &window_1, &button1_2, BTN_ID_1, 10, 80, 110, 130 );
   UG_ButtonCreate( &window_1, &button1_3, BTN_ID_2, 10, 150, 110,200 );
   UG_ButtonCreate( &window_1, &button1_4, BTN_ID_3, 120, 10, UG_WindowGetInnerWidth( &window_1 ) - 10 , 60 );
   UG_ButtonCreate( &window_1, &button1_5, BTN_ID_4, 120, 80, UG_WindowGetInnerWidth( &window_1 ) - 10, 130 );
   UG_ButtonCreate( &window_1, &button1_6, BTN_ID_5, 120, 150, UG_WindowGetInnerWidth( &window_1 ) - 10, 200 );

   /* Configure Button 1 */
   UG_ButtonSetFont( &window_1, BTN_ID_0, &FONT_12X20 );
   UG_ButtonSetBackColor( &window_1, BTN_ID_0, C_LIME );
   UG_ButtonSetText( &window_1, BTN_ID_0, "Green\nLED" );
   /* Configure Button 2 */
   UG_ButtonSetFont( &window_1, BTN_ID_1, &FONT_12X20 );
   UG_ButtonSetBackColor( &window_1, BTN_ID_1, C_RED );
   UG_ButtonSetText( &window_1, BTN_ID_1, "Red\nLED" );
   /* Configure Button 3 */
   UG_ButtonSetFont( &window_1, BTN_ID_2, &FONT_12X20 );
   UG_ButtonSetText( &window_1, BTN_ID_2, "About\n�GUI" );
   UG_WindowShow( &window_1 );
   /* Configure Button 4 */
   UG_ButtonSetFont( &window_1, BTN_ID_3, &FONT_12X20 );
   UG_ButtonSetForeColor( &window_1, BTN_ID_3, C_RED );
   UG_ButtonSetText( &window_1, BTN_ID_3, "HW_ACC\nOFF" );
   /* Configure Button 5 */
   UG_ButtonSetFont( &window_1, BTN_ID_4, &FONT_8X14 );
   UG_ButtonSetText( &window_1, BTN_ID_4, "Start\nBenchmark" );
   /* Configure Button 6 */
   UG_ButtonSetFont( &window_1, BTN_ID_5, &FONT_10X16 );
   UG_ButtonSetText( &window_1, BTN_ID_5, "Resize\nWindow" );

   /* -------------------------------------------------------------------------------- */
   /* Create Window 2 (�GUI Info)                                                      */
   /* -------------------------------------------------------------------------------- */
   UG_WindowCreate( &window_2, obj_buff_wnd_2, MAX_OBJECTS, window_2_callback );
   UG_WindowSetTitleText( &window_2, "Info" );
   UG_WindowSetTitleTextFont( &window_2, &FONT_12X20 );
   UG_WindowResize( &window_2, 20, 40, 219, 279 );

   /* Create Button 1 */
   UG_ButtonCreate( &window_2, &button2_1, BTN_ID_0, 40, 150, UG_WindowGetInnerWidth( &window_2 )-40, 200 );
   UG_ButtonSetFont( &window_2, BTN_ID_0, &FONT_22X36 );
   UG_ButtonSetText( &window_2, BTN_ID_0, "OK!" );

   /* Create Textbox 1 */
   UG_TextboxCreate( &window_2, &textbox2_1, TXB_ID_0, 10, 10, UG_WindowGetInnerWidth( &window_2 )-10, 40 );
   UG_TextboxSetFont( &window_2, TXB_ID_0, &FONT_16X26 );
   UG_TextboxSetText( &window_2, TXB_ID_0, "�GUI v0.3" );
   UG_TextboxSetAlignment( &window_2, TXB_ID_0, ALIGN_TOP_CENTER );

   /* Create Textbox 2 */
   UG_TextboxCreate( &window_2, &textbox2_2, TXB_ID_1, 10, 125, UG_WindowGetInnerWidth( &window_2 )-10, 135 );
   UG_TextboxSetFont( &window_2, TXB_ID_1, &FONT_6X8 );
   UG_TextboxSetText( &window_2, TXB_ID_1, "www.embeddedlightning.com" );
   UG_TextboxSetAlignment( &window_2, TXB_ID_1, ALIGN_BOTTOM_CENTER );
   UG_TextboxSetForeColor( &window_2, TXB_ID_1, C_BLUE );
   UG_TextboxSetHSpace( &window_2, TXB_ID_1, 1 );

   /* Create Image 1 */
   UG_ImageCreate( &window_2, &image2_1, IMG_ID_0, (UG_WindowGetInnerWidth( &window_2 )>>1) - (logo.width>>1), 40, 0, 0 );
   UG_ImageSetBMP( &window_2, IMG_ID_0, &logo );

   /* -------------------------------------------------------------------------------- */
   /* Create Window 3 (Benchmark Result)                                               */
   /* -------------------------------------------------------------------------------- */
   UG_WindowCreate( &window_3, obj_buff_wnd_3, MAX_OBJECTS, window_3_callback );
   UG_WindowSetTitleText( &window_3, "Benchmark Result" );
   UG_WindowSetTitleTextFont( &window_3, &FONT_10X16 );
   UG_WindowResize( &window_3, 20, 90, 219, 230 );

   /* Create Textbox 1 */
   UG_TextboxCreate( &window_3, &textbox3_1, TXB_ID_0, 5, 10, UG_WindowGetInnerWidth( &window_3 )-5, 60 );
   UG_TextboxSetFont( &window_3, TXB_ID_0, &FONT_12X20 );
   UG_TextboxSetText( &window_3, TXB_ID_0, "Result:\n99999 frm/sec" );
   UG_TextboxSetAlignment( &window_3, TXB_ID_0, ALIGN_TOP_CENTER );

   /* Create Button 1 */
   UG_ButtonCreate( &window_3, &button3_1, BTN_ID_0, 40, 65, UG_WindowGetInnerWidth( &window_3 )-40, 100 );
   UG_ButtonSetFont( &window_3, BTN_ID_0, &FONT_12X16 );
   UG_ButtonSetText( &window_3, BTN_ID_0, "OK!" );

   /* -------------------------------------------------------------------------------- */
   /* Start demo application                                                           */
   /* -------------------------------------------------------------------------------- */
   /* Show Window 1 */
   UG_WindowShow( &window_1 );
   UG_WaitForUpdate();

   /* Initialize FSM */
   next_state = STATE_MAIN_MENU;
   state = !STATE_MAIN_MENU;

   while(1)
   {
      static int frm_cnt;

      /* Do we change the state? */
      if ( next_state != state )
      {
         /* Initialize the next state */
         switch ( next_state )
         {
            case STATE_MAIN_MENU:
            {
               /* Nothing to do */
               break;
            }
            case STATE_BENCHMARK_RUN:
            {
               /* Clear layer 2 */
               ltdc_draw_layer( LAYER_2 );
               UG_FillScreen( C_BLACK );

               /* Fade to layer 2 */
               ltdc_fade_to_layer( LAYER_2 );

               /* Reset the frame counter */
               frm_cnt = 0;

               /* Run benchmark for 5 seconds */
               timer = 500;
               break;
            }
            case STATE_BENCHMARK_RESULT:
            {
               /* Nothing to do */
               break;
            }
         }
         state = next_state;
      }

      /* FSM */
      switch ( state )
      {
         /* Run the benchmark */
         case STATE_BENCHMARK_RUN:
         {
            xs = randx() % 240;
            xe = randx() % 240;
            ys = randx() % 320;
            ye = randx() % 320;
            c = randx() % 0xFFFFFF;
            UG_FillFrame( xs, ys, xe, ye, c );
            frm_cnt++;

            if ( !timer ) next_state = STATE_BENCHMARK_RESULT;
            break;
         }
         /* Show benchmark result */
         case STATE_BENCHMARK_RESULT:
         {
            sprintf( result_str, "Result:\n%u frm/sec", frm_cnt/5 );
            UG_TextboxSetText( &window_3, TXB_ID_0, result_str );

            /* Fade to layer 1 */
            ltdc_draw_layer( LAYER_1 );
            ltdc_fade_to_layer( LAYER_1 );

            /* Show benchmark result */
            UG_WindowShow( &window_3 );

            next_state = STATE_MAIN_MENU;
            break;
         }
         case STATE_MAIN_MENU:
         {
            /* Let �GUI do the job! */
            break;
         }
      }
   }
}
