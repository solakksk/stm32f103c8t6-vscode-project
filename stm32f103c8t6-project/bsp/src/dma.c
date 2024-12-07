/**
  ******************************************************************************
  * @file    dma.c
  * @author  
  * @version V1.0.0
  * @date    2024-11-17
  * @brief   
  ******************************************************************************
  * @attention
  ******************************************************************************
  */

#include "dma.h"
#include "stm32f10x_dma.h"
#include "stm32f10x_rcc.h"

void dma1_config(
  DMA_Channel_TypeDef* dma1channel,
  uint32_t paddr,uint32_t maddr,
  uint32_t pinc,uint32_t minc,
  uint32_t dir,
  uint32_t buffersize,uint32_t datasize,
  uint32_t m2m,FunctionalState status)
{
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
  DMA_InitTypeDef dmainit;
  dmainit.DMA_PeripheralBaseAddr=paddr;
  dmainit.DMA_MemoryBaseAddr=maddr;
  dmainit.DMA_DIR=dir;
  dmainit.DMA_BufferSize=buffersize;
  dmainit.DMA_PeripheralInc=pinc;
  dmainit.DMA_MemoryInc=minc;
  if(datasize==32){
    dmainit.DMA_PeripheralDataSize=DMA_PeripheralDataSize_Word;
    dmainit.DMA_MemoryDataSize=DMA_MemoryDataSize_Word;
  }else if(datasize==16){
    dmainit.DMA_PeripheralDataSize=DMA_PeripheralDataSize_HalfWord;
    dmainit.DMA_MemoryDataSize=DMA_MemoryDataSize_HalfWord;
  }else{
    dmainit.DMA_PeripheralDataSize=DMA_PeripheralDataSize_Byte;
    dmainit.DMA_MemoryDataSize=DMA_MemoryDataSize_Byte;
  }
  dmainit.DMA_Mode=DMA_Mode_Normal;
  dmainit.DMA_Priority=DMA_Priority_Low;
  dmainit.DMA_M2M=m2m;
  DMA_Init(dma1channel,&dmainit);
  DMA_Cmd(dma1channel,status);
}
uint8_t buffercmp(const uint32_t* flash_bufferPrt,uint32_t* sram_bufferPrt, uint16_t BufferLength){
  while (BufferLength--) {
    if(*flash_bufferPrt != *sram_bufferPrt){
      return 0;
    }
    flash_bufferPrt++;sram_bufferPrt++;
  }
  return 1;
}