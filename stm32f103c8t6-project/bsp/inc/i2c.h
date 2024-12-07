/**
  ******************************************************************************
  * @file    i2c.h
  * @author  
  * @version V1.0.0
  * @date    2024-11-21
  * @brief   
  ******************************************************************************
  * @attention
  ******************************************************************************
  */

#ifndef _I2C_H
#define _I2C_H
#include "stm32f10x.h"

void i2c1_config();
uint8_t i2c1_byte_rw(uint8_t *pbuffer,uint8_t rwdriveraddr,uint8_t rwaddr);
#endif