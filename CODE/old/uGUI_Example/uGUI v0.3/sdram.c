// ------------------------------------
// µGUI example project
// http://www.embeddedlightning.com/
// ------------------------------------

#include "sdram.h"
#include "system.h"


void sdram_init(void)
{
   FMC_SDRAMInitTypeDef FMC_SDRAMInitStructure;
   FMC_SDRAMTimingInitTypeDef FMC_SDRAMTimingInitStructure;
   FMC_SDRAMCommandTypeDef FMC_SDRAMCommandStructure;
   uint32_t tmpr = 0;

   /* GPIO configuration for FMC SDRAM bank */
   sdram_gpio_init();

   /* Enable FMC clock */
   RCC_AHB3PeriphClockCmd(RCC_AHB3Periph_FMC, ENABLE);

   /* FMC SDRAM Bank configuration */
   /* Timing configuration for 90 Mhz of SD clock frequency (180Mhz/2) */
   FMC_SDRAMTimingInitStructure.FMC_LoadToActiveDelay    = 2;  /* TMRD: 2 Clock cycles                       */
   FMC_SDRAMTimingInitStructure.FMC_ExitSelfRefreshDelay = 7;  /* TXSR: min=70ns (7x11.11ns)                 */
   FMC_SDRAMTimingInitStructure.FMC_SelfRefreshTime      = 4;  /* TRAS: min=42ns (4x11.11ns) max=120k (ns)   */
   FMC_SDRAMTimingInitStructure.FMC_RowCycleDelay        = 7;  /* TRC:  min=70 (7x11.11ns)                   */
   FMC_SDRAMTimingInitStructure.FMC_WriteRecoveryTime    = 2;  /* TWR:  min=1+ 7ns (1+1x11.11ns)             */
   FMC_SDRAMTimingInitStructure.FMC_RPDelay              = 2;  /* TRP:  20ns => 2x11.11ns                    */
   FMC_SDRAMTimingInitStructure.FMC_RCDDelay             = 2;  /* TRCD: 20ns => 2x11.11ns                    */

   /* FMC SDRAM control configuration */
   FMC_SDRAMInitStructure.FMC_Bank = FMC_Bank2_SDRAM;
   /* Row addressing: [7:0] */
   FMC_SDRAMInitStructure.FMC_ColumnBitsNumber = FMC_ColumnBits_Number_8b;
   /* Column addressing: [11:0] */
   FMC_SDRAMInitStructure.FMC_RowBitsNumber = FMC_RowBits_Number_12b;
   FMC_SDRAMInitStructure.FMC_SDMemoryDataWidth = SDRAM_MEMORY_WIDTH;
   FMC_SDRAMInitStructure.FMC_InternalBankNumber = FMC_InternalBank_Number_4;
   FMC_SDRAMInitStructure.FMC_CASLatency = SDRAM_CAS_LATENCY;
   FMC_SDRAMInitStructure.FMC_WriteProtection = FMC_Write_Protection_Disable;
   FMC_SDRAMInitStructure.FMC_SDClockPeriod = SDCLOCK_PERIOD;
   FMC_SDRAMInitStructure.FMC_ReadBurst = SDRAM_READBURST;
   FMC_SDRAMInitStructure.FMC_ReadPipeDelay = FMC_ReadPipe_Delay_1;
   FMC_SDRAMInitStructure.FMC_SDRAMTimingStruct = &FMC_SDRAMTimingInitStructure;

   /* FMC SDRAM bank initialization */
   FMC_SDRAMInit(&FMC_SDRAMInitStructure);


   /*------------------------------------------*/
   /* FMC SDRAM device initialization sequence */
   /*------------------------------------------*/
   /* Configure a clock configuration enable command */
   FMC_SDRAMCommandStructure.FMC_CommandMode = FMC_Command_Mode_CLK_Enabled;
   FMC_SDRAMCommandStructure.FMC_CommandTarget = FMC_Command_Target_bank2;
   FMC_SDRAMCommandStructure.FMC_AutoRefreshNumber = 1;
   FMC_SDRAMCommandStructure.FMC_ModeRegisterDefinition = 0;
   /* Wait until the SDRAM controller is ready */
   while(FMC_GetFlagStatus(FMC_Bank2_SDRAM, FMC_FLAG_Busy) != RESET){}
   /* Send the command */
   FMC_SDRAMCmdConfig(&FMC_SDRAMCommandStructure);

   /* Insert 100 ms delay */
   delay_ms(10);

   /* Configure a PALL (precharge all) command */
   FMC_SDRAMCommandStructure.FMC_CommandMode = FMC_Command_Mode_PALL;
   FMC_SDRAMCommandStructure.FMC_CommandTarget = FMC_Command_Target_bank2;
   FMC_SDRAMCommandStructure.FMC_AutoRefreshNumber = 1;
   FMC_SDRAMCommandStructure.FMC_ModeRegisterDefinition = 0;
   /* Wait until the SDRAM controller is ready */
   while(FMC_GetFlagStatus(FMC_Bank2_SDRAM, FMC_FLAG_Busy) != RESET){}
   /* Send the command */
   FMC_SDRAMCmdConfig(&FMC_SDRAMCommandStructure);

   /* Configure a Auto-Refresh command */
   FMC_SDRAMCommandStructure.FMC_CommandMode = FMC_Command_Mode_AutoRefresh;
   FMC_SDRAMCommandStructure.FMC_CommandTarget = FMC_Command_Target_bank2;
   FMC_SDRAMCommandStructure.FMC_AutoRefreshNumber = 4;
   FMC_SDRAMCommandStructure.FMC_ModeRegisterDefinition = 0;
   /* Wait until the SDRAM controller is ready */
   while(FMC_GetFlagStatus(FMC_Bank2_SDRAM, FMC_FLAG_Busy) != RESET){}
   /* Send the  first command */
   FMC_SDRAMCmdConfig(&FMC_SDRAMCommandStructure);

   /* Wait until the SDRAM controller is ready */
   while(FMC_GetFlagStatus(FMC_Bank2_SDRAM, FMC_FLAG_Busy) != RESET){}
   /* Send the second command */
   FMC_SDRAMCmdConfig(&FMC_SDRAMCommandStructure);

   /* Program the external memory mode register */
   tmpr = (uint32_t)SDRAM_MODEREG_BURST_LENGTH_2          |
                    SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL   |
                    SDRAM_MODEREG_CAS_LATENCY_3           |
                    SDRAM_MODEREG_OPERATING_MODE_STANDARD |
                    SDRAM_MODEREG_WRITEBURST_MODE_SINGLE;

   /* Configure a load Mode register command*/
   FMC_SDRAMCommandStructure.FMC_CommandMode = FMC_Command_Mode_LoadMode;
   FMC_SDRAMCommandStructure.FMC_CommandTarget = FMC_Command_Target_bank2;
   FMC_SDRAMCommandStructure.FMC_AutoRefreshNumber = 1;
   FMC_SDRAMCommandStructure.FMC_ModeRegisterDefinition = tmpr;
   /* Wait until the SDRAM controller is ready */
   while(FMC_GetFlagStatus(FMC_Bank2_SDRAM, FMC_FLAG_Busy) != RESET){}
   /* Send the command */
   FMC_SDRAMCmdConfig(&FMC_SDRAMCommandStructure);

   /* Set the refresh rate counter */
   /* (15.62 us x Freq) - 20 */
   /* Set the device refresh counter */
   FMC_SetRefreshCount(1386);
   /* Wait until the SDRAM controller is ready */
   while(FMC_GetFlagStatus(FMC_Bank2_SDRAM, FMC_FLAG_Busy) != RESET){}

}

void sdram_gpio_init(void)
{
   GPIO_InitTypeDef GPIO_InitStructure;

   /* Enable GPIOs clock */
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOC | RCC_AHB1Periph_GPIOD |
                          RCC_AHB1Periph_GPIOE | RCC_AHB1Periph_GPIOF | RCC_AHB1Periph_GPIOG, ENABLE);

   /* Common GPIO configuration */
   GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
   GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;

   /* GPIOB configuration */
   GPIO_PinAFConfig(GPIOB, GPIO_PinSource5 , GPIO_AF_FMC);
   GPIO_PinAFConfig(GPIOB, GPIO_PinSource6 , GPIO_AF_FMC);

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5  | GPIO_Pin_6;

   GPIO_Init(GPIOB, &GPIO_InitStructure);

   /* GPIOC configuration */
   GPIO_PinAFConfig(GPIOC, GPIO_PinSource0 , GPIO_AF_FMC);

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;

   GPIO_Init(GPIOC, &GPIO_InitStructure);

   /* GPIOD configuration */
   GPIO_PinAFConfig(GPIOD, GPIO_PinSource0, GPIO_AF_FMC);
   GPIO_PinAFConfig(GPIOD, GPIO_PinSource1, GPIO_AF_FMC);
   GPIO_PinAFConfig(GPIOD, GPIO_PinSource8, GPIO_AF_FMC);
   GPIO_PinAFConfig(GPIOD, GPIO_PinSource9, GPIO_AF_FMC);
   GPIO_PinAFConfig(GPIOD, GPIO_PinSource10, GPIO_AF_FMC);
   GPIO_PinAFConfig(GPIOD, GPIO_PinSource14, GPIO_AF_FMC);
   GPIO_PinAFConfig(GPIOD, GPIO_PinSource15, GPIO_AF_FMC);

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1  | GPIO_Pin_8 |
                                 GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_14 |
                                 GPIO_Pin_15;

   GPIO_Init(GPIOD, &GPIO_InitStructure);

   /* GPIOE configuration */
   GPIO_PinAFConfig(GPIOE, GPIO_PinSource0 , GPIO_AF_FMC);
   GPIO_PinAFConfig(GPIOE, GPIO_PinSource1 , GPIO_AF_FMC);
   GPIO_PinAFConfig(GPIOE, GPIO_PinSource7 , GPIO_AF_FMC);
   GPIO_PinAFConfig(GPIOE, GPIO_PinSource8 , GPIO_AF_FMC);
   GPIO_PinAFConfig(GPIOE, GPIO_PinSource9 , GPIO_AF_FMC);
   GPIO_PinAFConfig(GPIOE, GPIO_PinSource10 , GPIO_AF_FMC);
   GPIO_PinAFConfig(GPIOE, GPIO_PinSource11 , GPIO_AF_FMC);
   GPIO_PinAFConfig(GPIOE, GPIO_PinSource12 , GPIO_AF_FMC);
   GPIO_PinAFConfig(GPIOE, GPIO_PinSource13 , GPIO_AF_FMC);
   GPIO_PinAFConfig(GPIOE, GPIO_PinSource14 , GPIO_AF_FMC);
   GPIO_PinAFConfig(GPIOE, GPIO_PinSource15 , GPIO_AF_FMC);

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0  | GPIO_Pin_1  | GPIO_Pin_7 |
                                 GPIO_Pin_8  | GPIO_Pin_9  | GPIO_Pin_10 |
                                 GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 |
                                 GPIO_Pin_14 | GPIO_Pin_15;

   GPIO_Init(GPIOE, &GPIO_InitStructure);

   /* GPIOF configuration */
   GPIO_PinAFConfig(GPIOF, GPIO_PinSource0 , GPIO_AF_FMC);
   GPIO_PinAFConfig(GPIOF, GPIO_PinSource1 , GPIO_AF_FMC);
   GPIO_PinAFConfig(GPIOF, GPIO_PinSource2 , GPIO_AF_FMC);
   GPIO_PinAFConfig(GPIOF, GPIO_PinSource3 , GPIO_AF_FMC);
   GPIO_PinAFConfig(GPIOF, GPIO_PinSource4 , GPIO_AF_FMC);
   GPIO_PinAFConfig(GPIOF, GPIO_PinSource5 , GPIO_AF_FMC);
   GPIO_PinAFConfig(GPIOF, GPIO_PinSource11 , GPIO_AF_FMC);
   GPIO_PinAFConfig(GPIOF, GPIO_PinSource12 , GPIO_AF_FMC);
   GPIO_PinAFConfig(GPIOF, GPIO_PinSource13 , GPIO_AF_FMC);
   GPIO_PinAFConfig(GPIOF, GPIO_PinSource14 , GPIO_AF_FMC);
   GPIO_PinAFConfig(GPIOF, GPIO_PinSource15 , GPIO_AF_FMC);

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0  | GPIO_Pin_1 | GPIO_Pin_2 |
                                 GPIO_Pin_3  | GPIO_Pin_4 | GPIO_Pin_5 |
                                 GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 |
                                 GPIO_Pin_14 | GPIO_Pin_15;

   GPIO_Init(GPIOF, &GPIO_InitStructure);

   /* GPIOG configuration */
   GPIO_PinAFConfig(GPIOG, GPIO_PinSource0 , GPIO_AF_FMC);
   GPIO_PinAFConfig(GPIOG, GPIO_PinSource1 , GPIO_AF_FMC);
   GPIO_PinAFConfig(GPIOG, GPIO_PinSource4 , GPIO_AF_FMC);
   GPIO_PinAFConfig(GPIOG, GPIO_PinSource5 , GPIO_AF_FMC);
   GPIO_PinAFConfig(GPIOG, GPIO_PinSource8 , GPIO_AF_FMC);
   GPIO_PinAFConfig(GPIOG, GPIO_PinSource15 , GPIO_AF_FMC);


   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_4 |
                                 GPIO_Pin_5 | GPIO_Pin_8 | GPIO_Pin_15;

   GPIO_Init(GPIOG, &GPIO_InitStructure);
}

void sdram_write_8(uint32_t adr, uint8_t data)
{
   *(uint8_t*) (SDRAM_BANK_ADDR + adr) = data;
}

void sdram_write_16(uint32_t adr, uint16_t data)
{
   *(uint16_t*) (SDRAM_BANK_ADDR + adr) = data;
}

void sdram_write_32(uint32_t adr, uint32_t data)
{
   *(uint32_t*) (SDRAM_BANK_ADDR + adr) = data;
}

uint8_t sdram_read_8(uint32_t adr)
{
   return *(volatile uint8_t*)(SDRAM_BANK_ADDR + adr);
}

uint16_t sdram_read_16(uint32_t adr)
{
   return *(volatile uint16_t*)(SDRAM_BANK_ADDR + adr);
}

uint32_t sdram_read_32(uint32_t adr)
{
   return *(volatile uint32_t*)(SDRAM_BANK_ADDR + adr);
}

int sdram_test(void)
{
   uint32_t addr;

   for(addr=0;addr<SDRAM_SIZE;addr++)
   {
      sdram_write_8(addr,addr & 0xFF);
   }
   for(addr=0;addr<SDRAM_SIZE;addr++)
   {
      if ( sdram_read_8(addr) != (addr&0xFF) ) return SDRAM_FAIL;
   }

   for(addr=0;addr<SDRAM_SIZE;addr+=2)
   {
      sdram_write_16(addr,addr & 0xFFFF);
   }
   for(addr=0;addr<SDRAM_SIZE;addr+=2)
   {
      if ( sdram_read_16(addr) != (addr&0xFFFF) ) return SDRAM_FAIL;
   }

   for(addr=0;addr<SDRAM_SIZE;addr+=4)
   {
      sdram_write_32(addr,addr);
   }
   for(addr=0;addr<SDRAM_SIZE;addr+=4)
   {
      if ( sdram_read_32(addr) != addr ) return SDRAM_FAIL;
   }
   return SDRAM_OK;
}

