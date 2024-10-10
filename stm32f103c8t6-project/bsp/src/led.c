/**
  ******************************************************************************
  * @file    led.c
  * @author  
  * @version V1.0.0
  * @date    2024-10-2
  * @brief   
  ******************************************************************************
  * @attention
  ******************************************************************************
  */

#include "led.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_ASSERT.h"

uint32_t port;uint16_t pin;
void led_init(ledport_typedef ledport,ledpin_typedef ledpin){
  port=ledport;pin=ledpin;
  if     (ledport==GPIOA_BASE){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
  }
  else if(ledport==GPIOB_BASE){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
  }
  else if(ledport==GPIOC_BASE){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
  }
  else if(ledport==GPIOD_BASE){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);
  }
  GPIO_InitTypeDef gpioinitstructure;
  gpioinitstructure.GPIO_Mode=GPIO_Mode_Out_PP;
  gpioinitstructure.GPIO_Pin=ledpin;
  gpioinitstructure.GPIO_Speed=GPIO_Speed_2MHz;
  GPIO_Init(((GPIO_TypeDef *)ledport),&gpioinitstructure);
}
void ledon(){
  if(IS_GPIO_ALL_PERIPH(((GPIO_TypeDef *)port))&&IS_GPIO_PIN(pin)){
  GPIO_ResetBits(((GPIO_TypeDef *)port),pin);
  }else{
  assert_failed((uint8_t *)__FILE__, __LINE__);
  }
}
void ledoff(){
  if(IS_GPIO_ALL_PERIPH(((GPIO_TypeDef *)port))&&IS_GPIO_PIN(pin)){
  GPIO_SetBits(((GPIO_TypeDef *)port),pin);
  }else{
  assert_failed((uint8_t *)__FILE__, __LINE__);
  }
}