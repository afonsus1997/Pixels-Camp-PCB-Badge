/**
  ******************************************************************************
  * @file    main.h
  * $Author: wdluo $
  * $Revision: 67 $
  * $Date:: 2012-08-15 19:00:29 +0800 #$
  * @brief   主函数包含的头文件.
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

#if  VERSION==1
#include "IS31FL3741.h"
#elif VERSION==2
#include "IS31FL3742.h"
#endif

#endif/* __MAIN_H */

/*********************************END OF FILE**********************************/
