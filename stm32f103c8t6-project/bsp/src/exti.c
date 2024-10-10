/**
  ******************************************************************************
  * @file    exti.c
  * @author  
  * @version V1.0.0
  * @date    2024-10-5
  * @brief   
  ******************************************************************************
  * @attention
  ******************************************************************************
  */

#include "exti.h"
#include "misc.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_exti.h"

#define KEY_GPIO_PORT GPIOA
#define KEY_GPIO_PIN GPIO_Pin_0
#define KEY_GPIO_CLK (RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO)
#define KEY_AFIO_PORT GPIO_PortSourceGPIOA
#define KEY_AFIO_PIN GPIO_PinSource0
#define KEY_EXTI_EXITLINE EXTI_Line0
#define KEY_NVIC_IRQN EXTI0_IRQn

static void gpio_config(){
  RCC_APB2PeriphClockCmd(KEY_GPIO_CLK,ENABLE);
  GPIO_InitTypeDef gpioinit;
  gpioinit.GPIO_Mode=GPIO_Mode_IN_FLOATING;
  gpioinit.GPIO_Pin=KEY_GPIO_PIN;
  GPIO_Init(KEY_GPIO_PORT,&gpioinit);
}
static void afio_config(){
  GPIO_EXTILineConfig(KEY_AFIO_PORT,KEY_AFIO_PIN);
}
static void exti_config(){
  EXTI_InitTypeDef extiinit;
  extiinit.EXTI_Line=KEY_EXTI_EXITLINE;
  extiinit.EXTI_LineCmd=ENABLE;
  extiinit.EXTI_Mode=EXTI_Mode_Interrupt;
  extiinit.EXTI_Trigger=EXTI_Trigger_Falling;
  EXTI_Init(&extiinit);
}
static void nvic_config(){
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
  NVIC_InitTypeDef nvicinit;
  nvicinit.NVIC_IRQChannel=KEY_NVIC_IRQN;
  nvicinit.NVIC_IRQChannelCmd=ENABLE;
  nvicinit.NVIC_IRQChannelPreemptionPriority=1;
  nvicinit.NVIC_IRQChannelSubPriority=1;
  NVIC_Init(&nvicinit);
}
void keywkup_config(void){
  nvic_config();
  gpio_config();
  afio_config();
  exti_config();
}