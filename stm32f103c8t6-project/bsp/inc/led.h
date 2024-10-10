/**
  ******************************************************************************
  * @file    led.h
  * @author  
  * @version V1.0.0
  * @date    2024-10-2
  * @brief   
  ******************************************************************************
  * @attention
  ******************************************************************************
  */

#ifndef _LED_H
#define _LED_H

#include "stm32f10x.h"

typedef enum{
  LED_GPIOA=GPIOA_BASE,
  LED_GPIOB=GPIOB_BASE,
}ledport_typedef;

typedef enum{
  LED_GPIO_PIN_7=((uint16_t)0x0080),
  LED_GPIO_PIN_8=((uint16_t)0x0100),
  LED_GPIO_PIN_0x00=(uint16_t)0x00
}ledpin_typedef;

void led_init(ledport_typedef ledport,ledpin_typedef ledpin);
void ledon(void);
void ledoff(void);
#endif