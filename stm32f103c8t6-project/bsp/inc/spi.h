/**
  ******************************************************************************
  * @file    spi.h
  * @author  
  * @version V1.0.0
  * @date    2024-12-1
  * @brief   
  ******************************************************************************
  * @attention
  ******************************************************************************
  */

#ifndef _SPI_H
#define _SPI_H

#include "stm32f10x.h"
#include "stm32f10x_gpio.h"

#define SPI1_CS_LOW() GPIO_ResetBits(GPIOA,GPIO_Pin_4)
#define SPI1_CS_HIGH() GPIO_SetBits(GPIOA,GPIO_Pin_4)
#define SPI2_CS_LOW() GPIO_ResetBits(GPIOB,GPIO_Pin_12)
#define SPI2_CS_HIGH() GPIO_SetBits(GPIOB,GPIO_Pin_12)

void spi_config(SPI_TypeDef *spix,uint16_t SPI_Direction,uint16_t SPI_Mode,uint16_t SPI_DataSize,uint16_t SPI_CPOL,uint16_t SPI_CPHA,uint16_t SPI_NSS,uint16_t SPI_BaudRatePrescaler,uint16_t SPI_FirstBit,uint16_t SPI_GetCRCPolynomial);
uint8_t spi_sendu8(SPI_TypeDef *spix,uint8_t sbyte);
uint8_t spi_readu8(SPI_TypeDef *spix,uint8_t *rbyte);
uint8_t spi_sendu16(SPI_TypeDef *spix,uint16_t sbyte);
uint8_t spi_readu16(SPI_TypeDef *spix,uint16_t *rbyte);
#endif