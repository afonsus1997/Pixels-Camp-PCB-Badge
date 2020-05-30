#include "ili9341.h"
#include "system.h"

// ------------------------------------
// µGUI example project
// http://www.embeddedlightning.com/
// ------------------------------------

void ili9341_data( uint8_t x )
{
   int n;
   GPIO_WriteBit(GPIOC,GPIO_Pin_2,Bit_RESET);  //CS low
   GPIO_WriteBit(GPIOD,GPIO_Pin_13,Bit_SET);  //CD high

   for(n=0x80;n;n>>=1)
   {
      if ( x & n )
      {
         GPIO_WriteBit(GPIOF,GPIO_Pin_9, Bit_SET);
      }
      else
      {
         GPIO_WriteBit(GPIOF,GPIO_Pin_9, Bit_RESET);
      }
      GPIO_WriteBit(GPIOF,GPIO_Pin_7, Bit_SET);
      GPIO_WriteBit(GPIOF,GPIO_Pin_7, Bit_RESET);
   }
   GPIO_WriteBit(GPIOC,GPIO_Pin_2,Bit_SET);  //CS high
}


void ili9341_cmd( uint8_t x )
{
   int n;
   GPIO_WriteBit(GPIOC,GPIO_Pin_2,Bit_RESET);  //CS low
   GPIO_WriteBit(GPIOD,GPIO_Pin_13,Bit_RESET);  //CD high

   for(n=0x80;n;n>>=1)
   {
      if ( x & n )
      {
         GPIO_WriteBit(GPIOF,GPIO_Pin_9, Bit_SET);
      }
      else
      {
         GPIO_WriteBit(GPIOF,GPIO_Pin_9, Bit_RESET);
      }
      GPIO_WriteBit(GPIOF,GPIO_Pin_7, Bit_SET);
      GPIO_WriteBit(GPIOF,GPIO_Pin_7, Bit_RESET);
   }
   GPIO_WriteBit(GPIOC,GPIO_Pin_2,Bit_SET);  //CS high
}


void ili9341_init(void)
{

   GPIO_InitTypeDef GPIO_InitStructure;

   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
   GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_Init(GPIOC, &GPIO_InitStructure);

   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_9;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
   GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_Init(GPIOF, &GPIO_InitStructure);

   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
   GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_Init(GPIOD, &GPIO_InitStructure);

   GPIO_WriteBit(GPIOC,GPIO_Pin_2,Bit_SET);


   ili9341_cmd(0xCA);
   ili9341_data(0xC3);
   ili9341_data(0x08);
   ili9341_data(0x50);
   ili9341_cmd(LCD_POWERB);
   ili9341_data(0x00);
   ili9341_data(0xC1);
   ili9341_data(0x30);
   ili9341_cmd(LCD_POWER_SEQ);
   ili9341_data(0x64);
   ili9341_data(0x03);
   ili9341_data(0x12);
   ili9341_data(0x81);
   ili9341_cmd(LCD_DTCA);
   ili9341_data(0x85);
   ili9341_data(0x00);
   ili9341_data(0x78);
   ili9341_cmd(LCD_POWERA);
   ili9341_data(0x39);
   ili9341_data(0x2C);
   ili9341_data(0x00);
   ili9341_data(0x34);
   ili9341_data(0x02);
   ili9341_cmd(LCD_PRC);
   ili9341_data(0x20);
   ili9341_cmd(LCD_DTCB);
   ili9341_data(0x00);
   ili9341_data(0x00);
   ili9341_cmd(LCD_FRC);
   ili9341_data(0x00);
   ili9341_data(0x1B);
   ili9341_cmd(LCD_DFC);
   ili9341_data(0x0A);
   ili9341_data(0xA2);
   ili9341_cmd(LCD_POWER1);
   ili9341_data(0x10);
   ili9341_cmd(LCD_POWER2);
   ili9341_data(0x10);
   ili9341_cmd(LCD_VCOM1);
   ili9341_data(0x45);
   ili9341_data(0x15);
   ili9341_cmd(LCD_VCOM2);
   ili9341_data(0x90);
   ili9341_cmd(LCD_MAC);
   ili9341_data(0xC8);
   ili9341_cmd(LCD_3GAMMA_EN);
   ili9341_data(0x00);
   ili9341_cmd(LCD_RGB_INTERFACE);
   ili9341_data(0xC2);
   ili9341_cmd(LCD_DFC);
   ili9341_data(0x0A);
   ili9341_data(0xA7);
   ili9341_data(0x27);
   ili9341_data(0x04);

   /* Column Address Set */
   ili9341_cmd(LCD_COLUMN_ADDR);
   ili9341_data(0x00);
   ili9341_data(0x00);
   ili9341_data(0x00);
   ili9341_data(0xEF);
   /* Page Address Set */
   ili9341_cmd(LCD_PAGE_ADDR);
   ili9341_data(0x00);
   ili9341_data(0x00);
   ili9341_data(0x01);
   ili9341_data(0x3F);
   ili9341_cmd(LCD_INTERFACE);
   ili9341_data(0x01);
   ili9341_data(0x00);
   ili9341_data(0x06);

   ili9341_cmd(LCD_GRAM);
   delay_ms(200);

   ili9341_cmd(LCD_GAMMA);
   ili9341_data(0x01);

   ili9341_cmd(LCD_PGAMMA);
   ili9341_data(0x0F);
   ili9341_data(0x29);
   ili9341_data(0x24);
   ili9341_data(0x0C);
   ili9341_data(0x0E);
   ili9341_data(0x09);
   ili9341_data(0x4E);
   ili9341_data(0x78);
   ili9341_data(0x3C);
   ili9341_data(0x09);
   ili9341_data(0x13);
   ili9341_data(0x05);
   ili9341_data(0x17);
   ili9341_data(0x11);
   ili9341_data(0x00);
   ili9341_cmd(LCD_NGAMMA);
   ili9341_data(0x00);
   ili9341_data(0x16);
   ili9341_data(0x1B);
   ili9341_data(0x04);
   ili9341_data(0x11);
   ili9341_data(0x07);
   ili9341_data(0x31);
   ili9341_data(0x33);
   ili9341_data(0x42);
   ili9341_data(0x05);
   ili9341_data(0x0C);
   ili9341_data(0x0A);
   ili9341_data(0x28);
   ili9341_data(0x2F);
   ili9341_data(0x0F);

   ili9341_cmd(LCD_SLEEP_OUT);
   delay_ms(200);
   ili9341_cmd(LCD_DISPLAY_ON);
   /* GRAM start writing */
   ili9341_cmd(LCD_GRAM);
}
