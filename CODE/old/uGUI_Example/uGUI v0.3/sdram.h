// ------------------------------------
// µGUI example project
// http://www.embeddedlightning.com/
// ------------------------------------

#ifndef __SDRAM_H
#define __SDRAM_H

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_fmc.h"

#define SDRAM_SIZE               0x800000  //1024 * 1024 * 8 byte = 8 MB
#define SDRAM_BANK_ADDR          ((uint32_t)0xD0000000)

#define SDRAM_OK                 0
#define SDRAM_FAIL               -1

//#define SDRAM_MEMORY_WIDTH  FMC_SDMemory_Width_8b
#define SDRAM_MEMORY_WIDTH      FMC_SDMemory_Width_16b

//#define SDRAM_CAS_LATENCY   FMC_CAS_Latency_2
#define SDRAM_CAS_LATENCY       FMC_CAS_Latency_3

#define SDCLOCK_PERIOD          FMC_SDClock_Period_2     // für TFT
//#define SDCLOCK_PERIOD      FMC_SDClock_Period_3

#define SDRAM_READBURST         FMC_Read_Burst_Disable  // für TFT
//#define SDRAM_READBURST     FMC_Read_Burst_Enable

#define SDRAM_MODEREG_BURST_LENGTH_1             ((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_LENGTH_2             ((uint16_t)0x0001)
#define SDRAM_MODEREG_BURST_LENGTH_4             ((uint16_t)0x0002)
#define SDRAM_MODEREG_BURST_LENGTH_8             ((uint16_t)0x0004)
#define SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL      ((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_TYPE_INTERLEAVED     ((uint16_t)0x0008)
#define SDRAM_MODEREG_CAS_LATENCY_2              ((uint16_t)0x0020)
#define SDRAM_MODEREG_CAS_LATENCY_3              ((uint16_t)0x0030)
#define SDRAM_MODEREG_OPERATING_MODE_STANDARD    ((uint16_t)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_PROGRAMMED ((uint16_t)0x0000) 
#define SDRAM_MODEREG_WRITEBURST_MODE_SINGLE     ((uint16_t)0x0200)      

// Prototypen

/* SD-RAM initialisieren */
void sdram_init(void);

/* SD-RAM Pins initialisieren */
void sdram_gpio_init(void);

/* 8 Bit in das SD-RAM schreiben */
void sdram_write_8(uint32_t adr, uint8_t data);

/* 16 Bit in das SD-RAM schreiben */
void sdram_write_16(uint32_t adr, uint16_t data);

/* 32 Bit in das SD-RAM schreiben */
void sdram_write_32(uint32_t adr, uint32_t data);

/* 8 Bit aus dem SD-RAM lesen */
uint8_t sdram_read_8(uint32_t adr);

/* 16 Bit aus dem SD-RAM lesen */
uint16_t sdram_read_16(uint32_t adr);

/* 32 Bit aus dem SD-RAM lesen */
uint32_t sdram_read_32(uint32_t adr);

/* SD-RAM testen */
int sdram_test(void);


#endif
