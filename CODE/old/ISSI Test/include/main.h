/**
  ******************************************************************************
  * @file    main.h
  * $Author: wdluo $
  * $Revision: 67 $
  * $Date:: 2012-08-15 19:00:29 +0800 #$
  * @brief   ������������ͷ�ļ�.
  ******************************************************************************
  * @attention
  *
  *<h3><center>&copy; Copyright 2009-2012, ViewTool</center>
  *<center><a href="http:\\www.viewtool.com">http://www.viewtool.com</a></center>
  *<center>All Rights Reserved</center></h3>
  * 
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H
/* Includes ------------------------------------------------------------------*/

#define R_LED 0
#define G_LED 1
#define B_LED 2

#define SCAL 0
#define PWM  1

#define Mode_Max 4

/*choose IC promgram*/
#define VERSION 1


extern void IS31FL3741_Init(void);
extern void Play_IS31FL3741_Demo_mode(void);
extern int IS31FL3741_Mode_1(void);
#endif

/*********************************END OF FILE**********************************/
