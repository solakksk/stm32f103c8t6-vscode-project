/**
  ******************************************************************************
  * @file    delay.h
  * @author  
  * @version V1.0.0
  * @date    2024-10-10
  * @brief   
  ******************************************************************************
  * @attention
  ******************************************************************************
  */

#ifndef _DELAY_H
#define _DELAY_H
#include "stm32f10x.h"

void systick_intcmd(FunctionalState state);
void delay_us(__IO uint32_t us);
void delay_ms(__IO uint32_t ms);
#endif