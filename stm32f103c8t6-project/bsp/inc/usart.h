/**
  ******************************************************************************
  * @file    usart.h
  * @author  
  * @version V1.0.0
  * @date    2024-10-20
  * @brief   
  ******************************************************************************
  * @attention
  ******************************************************************************
  */

#ifndef _USART_H
#define _USART_H

#include "stm32f10x.h"

void usart_pa9_10_config(void);
void usart_sendbyte(USART_TypeDef* pUSARTx,uint8_t ch);
void usart_sendstring(USART_TypeDef* pUSARTx,char* str);
#endif
