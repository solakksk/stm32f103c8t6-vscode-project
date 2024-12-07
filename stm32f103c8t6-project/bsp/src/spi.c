/**
  ******************************************************************************
  * @file    spi.c
  * @author  
  * @version V1.0.0
  * @date    2024-12-1
  * @brief   
  ******************************************************************************
  * @attention
  ******************************************************************************
  */

#include "spi.h"
#include "stm32f10x_spi.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"

#define SPIT_FLAG_TIMEOUT 1000

void spi_config(SPI_TypeDef *spix,uint16_t SPI_Direction,uint16_t SPI_Mode,uint16_t SPI_DataSize,uint16_t SPI_CPOL,uint16_t SPI_CPHA,uint16_t SPI_NSS,uint16_t SPI_BaudRatePrescaler,uint16_t SPI_FirstBit,uint16_t SPI_CRCPolynomial){
  if(spix==SPI1){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_SPI1,ENABLE);
    GPIO_InitTypeDef gpioinit;
    gpioinit.GPIO_Pin=GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
    gpioinit.GPIO_Mode=GPIO_Mode_AF_PP;
    gpioinit.GPIO_Speed=GPIO_Speed_50MHz;
    GPIO_Init(GPIOA,&gpioinit);
    if(SPI_NSS==SPI_NSS_Soft){
      gpioinit.GPIO_Pin=GPIO_Pin_4;
      gpioinit.GPIO_Mode=GPIO_Mode_Out_PP;
      GPIO_Init(GPIOA,&gpioinit);
    }
  }else if(spix==SPI2){
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
    GPIO_InitTypeDef gpioinit;
    gpioinit.GPIO_Pin=GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
    gpioinit.GPIO_Mode=GPIO_Mode_AF_PP;
    gpioinit.GPIO_Speed=GPIO_Speed_50MHz;
    GPIO_Init(GPIOB,&gpioinit);
    if(SPI_NSS==SPI_NSS_Soft){
      gpioinit.GPIO_Pin=GPIO_Pin_12;
      gpioinit.GPIO_Mode=GPIO_Mode_Out_PP;
      GPIO_Init(GPIOB,&gpioinit);
    }
  }else{
    return;
  }
  SPI_InitTypeDef spiinit;
  spiinit.SPI_Direction=SPI_Direction;
  spiinit.SPI_Mode=SPI_Mode;
  spiinit.SPI_DataSize=SPI_DataSize;
  spiinit.SPI_CPOL=SPI_CPOL;
  spiinit.SPI_CPHA=SPI_CPHA;
  spiinit.SPI_NSS=SPI_NSS;
  spiinit.SPI_BaudRatePrescaler=SPI_BaudRatePrescaler;
  spiinit.SPI_FirstBit=SPI_FirstBit;
  spiinit.SPI_CRCPolynomial=SPI_CRCPolynomial;
  SPI_Init(spix,&spiinit);
  if(SPI_NSS==SPI_NSS_Soft){
    SPI_Cmd(spix,ENABLE);
  }
}
uint8_t spi_sendu8(SPI_TypeDef *spix,uint8_t sbyte){
    uint32_t SPITimeout = SPIT_FLAG_TIMEOUT;
    /* 等待发送缓冲区为空，TXE事件 */
    while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET)
    {
        if ((SPITimeout--) == 0) return 1;
    }
    /* 写入数据寄存器，把要写入的数据写入发送缓冲区 */
    SPI_I2S_SendData(spix,sbyte);
    return 0;
}
uint8_t spi_readu8(SPI_TypeDef *spix,uint8_t *rbyte){
    uint32_t SPITimeout = SPIT_FLAG_TIMEOUT;
    /* 等待接收缓冲区非空，RXNE事件 */
    while (SPI_I2S_GetFlagStatus(spix, SPI_I2S_FLAG_RXNE) == RESET)
    {
        if ((SPITimeout--) == 0) return 1;
    }
    /* 读取数据寄存器，获取接收缓冲区数据 */
    *rbyte=SPI_I2S_ReceiveData(spix);
    return 0;
}
uint8_t spi_sendu16(SPI_TypeDef *spix,uint16_t sbyte){
    uint32_t SPITimeout = SPIT_FLAG_TIMEOUT;
    /* 等待发送缓冲区为空，TXE事件 */
    while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET)
    {
        if ((SPITimeout--) == 0) return 1;
    }
    /* 写入数据寄存器，把要写入的数据写入发送缓冲区 */
    SPI_I2S_SendData(spix,sbyte);
    return 0;
}
uint8_t spi_readu16(SPI_TypeDef *spix,uint16_t *rbyte){
    uint32_t SPITimeout = SPIT_FLAG_TIMEOUT;
    /* 等待接收缓冲区非空，RXNE事件 */
    while (SPI_I2S_GetFlagStatus(spix, SPI_I2S_FLAG_RXNE) == RESET)
    {
        if ((SPITimeout--) == 0) return 1;
    }
    /* 读取数据寄存器，获取接收缓冲区数据 */
    *rbyte=SPI_I2S_ReceiveData(spix);
    return 0;
}
