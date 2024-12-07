/**
  ******************************************************************************
  * @file    dma.h
  * @author  
  * @version V1.0.0
  * @date    2024-11-17
  * @brief   
  ******************************************************************************
  * @attention
  ******************************************************************************
  */

#ifndef _DMA_H
#define _DMA_H
#include "stm32f10x.h"

void dma1_config(DMA_Channel_TypeDef* dma1channel,uint32_t paddr,uint32_t maddr,uint32_t pinc,uint32_t minc,uint32_t dir,uint32_t buffersize,uint32_t datasize,uint32_t m2m,FunctionalState status);
uint8_t buffercmp(const uint32_t* flash_bufferPrt,uint32_t* sram_bufferPrt, uint16_t BufferLength);
#endif