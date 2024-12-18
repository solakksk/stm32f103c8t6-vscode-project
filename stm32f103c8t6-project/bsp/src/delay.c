/**
  ******************************************************************************
  * @file    delay.c
  * @author  
  * @version V1.0.0
  * @date    2024-10-10
  * @brief   
  ******************************************************************************
  * @attention
  ******************************************************************************
  */

#include "delay.h"

FunctionalState stateing=DISABLE;
void systick_intcmd(FunctionalState state){
    stateing=state;
}
void delay_us(__IO uint32_t us){
    uint32_t i;
    SysTick_Config(SystemCoreClock/1000000);
    if(stateing==DISABLE){SysTick->CTRL &=~SysTick_CTRL_TICKINT_Msk;}
    for(i=0;i<us;i++){
        while(!((SysTick->CTRL)&(1<<16)));
    }
    SysTick->CTRL &=~SysTick_CTRL_ENABLE_Msk;
}
void delay_ms(__IO uint32_t ms){
    uint32_t i;
    SysTick_Config(SystemCoreClock/1000);
    if(stateing==DISABLE){SysTick->CTRL &=~SysTick_CTRL_TICKINT_Msk;}
    for(i=0;i<ms;i++){
        while(!((SysTick->CTRL)&(1<<16)));
    }
    SysTick->CTRL &=~SysTick_CTRL_ENABLE_Msk;
}