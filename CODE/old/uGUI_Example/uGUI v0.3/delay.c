// ------------------------------------
// µGUI example project
// http://www.embeddedlightning.com/
// ------------------------------------

#include "delay.h"

void delay_init( void ) 
{
   TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

   RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);
  
   TIM_TimeBaseStructInit(&TIM_TimeBaseStructure); 
   TIM_TimeBaseStructure.TIM_Prescaler = (DELAY_TIMER_INPUT_CLK / DELAY_TIMER_FREQUENCY) - 1;
   TIM_TimeBaseStructure.TIM_Period = UINT32_MAX; 
   TIM_TimeBaseStructure.TIM_ClockDivision = 0;
   TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
   TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure);
 
   TIM_Cmd(TIM5, ENABLE);
}

void delay_us( uint32_t x ) 
{
   TIM5->CNT = 0;
   while(TIM5->CNT < x);
}

void delay_ms( uint32_t x ) 
{
   delay_us( x * 1000 );
}
