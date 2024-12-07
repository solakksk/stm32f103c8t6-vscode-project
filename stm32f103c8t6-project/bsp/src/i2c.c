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

#include "i2c.h"
#include "usart.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_i2c.h"

#define I2CTIMEOUT 0x1000

void i2c1_config(){
  //使能gpiob和i2c1时钟
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1,ENABLE);
  GPIO_InitTypeDef gpioinit;
  I2C_InitTypeDef i2cinit;
  //config pb6 SCL
  gpioinit.GPIO_Mode=GPIO_Mode_AF_OD;
  gpioinit.GPIO_Pin=GPIO_Pin_6;
  gpioinit.GPIO_Speed=GPIO_Speed_50MHz;
  GPIO_Init(GPIOB,&gpioinit);
  //config pb7 SDA
  gpioinit.GPIO_Mode=GPIO_Mode_AF_OD;
  gpioinit.GPIO_Pin=GPIO_Pin_7;
  GPIO_Init(GPIOB,&gpioinit);
  //config i2c
  i2cinit.I2C_Mode=I2C_Mode_I2C;
  i2cinit.I2C_DutyCycle=I2C_DutyCycle_2;
  i2cinit.I2C_OwnAddress1=0x01;
  i2cinit.I2C_AcknowledgedAddress=I2C_AcknowledgedAddress_7bit;
  i2cinit.I2C_Ack=I2C_Ack_Enable;
  i2cinit.I2C_ClockSpeed=400000;
  I2C_Init(I2C1,&i2cinit);
  I2C_Cmd(I2C1,ENABLE);
}
uint8_t i2c1_byte_rw(uint8_t *pbuffer,uint8_t rwdriveraddr,uint8_t rwaddr){
  //产生i2c起始信号s
  I2C_GenerateSTART(I2C1,ENABLE);
  //等待事件event5，即起始信号s已发送且SR1寄存器SB=1
  uint32_t i2ctimeout=I2CTIMEOUT;
  while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_MODE_SELECT)){if((i2ctimeout--)==0){usart_sendstring(USART1,"signal s timeout!");return 1;}}


  //发送i2c从设备地址,从设备地址高7位地址，低1位读或写
  if((rwdriveraddr & (uint8_t)0x01)==1){
    if(rwaddr!=0){
      //先发送i2c从设备写地址
      I2C_Send7bitAddress(I2C1,rwdriveraddr,I2C_Direction_Transmitter);
      //等待事件event6，即从设备写地址已发送且从设备ack已回应，SR1寄存器ADDR=1 TxE=1
      i2ctimeout=I2CTIMEOUT;
      while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED)){if((i2ctimeout--)==0){usart_sendstring(USART1,"wdriveraddr ack timeout!");return 1;}}
      //然后发送1byte从设备数据地址rwaddr
      I2C_SendData(I2C1,rwaddr);
      //等待事件event8，即从设备ack回应，DR寄存器为空，SR1寄存器TxE=1
      i2ctimeout=I2CTIMEOUT;
      while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED)){if((i2ctimeout--)==0){usart_sendstring(USART1,"Tx data timeout!");return 1;}}
      //重新发送起始信号s
      I2C_GenerateSTART(I2C1,ENABLE);
      //等待事件event5，即起始信号s已发送且SR1寄存器SB=1
      uint32_t i2ctimeout=I2CTIMEOUT;
      while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_MODE_SELECT)){if((i2ctimeout--)==0){usart_sendstring(USART1,"signal s timeout!");return 1;}}
      //发送i2c从设备读地址
      I2C_Send7bitAddress(I2C1,rwdriveraddr,I2C_Direction_Receiver);
      //等待事件event6，即从设备读地址已发送且从设备ack已回应，SR1寄存器ADDR=1 RxEN=1
      i2ctimeout=I2CTIMEOUT;
      while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED)){if((i2ctimeout--)==0){usart_sendstring(USART1,"rdriveraddr ack timeout!");return 1;}}
      //读取1byte数据来自从设备
      uint8_t rd=I2C_ReceiveData(I2C1);
      //等待事件event7，即已读取到从设备发来的数据，DR寄存器非空，SR1寄存器RxEN=1
      i2ctimeout=I2CTIMEOUT;
      while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_BYTE_RECEIVED)){if((i2ctimeout--)==0){usart_sendstring(USART1,"Rx data timeout!");return 1;}}
      //产生i2c停止信号
      I2C_GenerateSTOP(I2C1,ENABLE);
      return rd;
    }
    //发送i2c从设备读地址
    I2C_Send7bitAddress(I2C1,rwdriveraddr,I2C_Direction_Receiver);
    //等待事件event6，即从设备读地址已发送且从设备ack已回应，SR1寄存器ADDR=1 RxEN=1
    i2ctimeout=I2CTIMEOUT;
    while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED)){if((i2ctimeout--)==0){usart_sendstring(USART1,"rdriveraddr ack timeout!");return 1;}}
    //读取1byte数据来自从设备，如果从设备是存储设备类型需要提供rwaddr，不是存储设备类型rwaddr=0
    uint8_t rd=I2C_ReceiveData(I2C1);
    //等待事件event7，即已读取到从设备发来的数据，DR寄存器非空，SR1寄存器RxEN=1
    i2ctimeout=I2CTIMEOUT;
    while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_BYTE_RECEIVED)){if((i2ctimeout--)==0){usart_sendstring(USART1,"Rx data timeout!");return 1;}}
    //产生i2c停止信号
    I2C_GenerateSTOP(I2C1,ENABLE);
    return rd;
  }else{
    //发送i2c从设备写地址
    I2C_Send7bitAddress(I2C1,rwdriveraddr,I2C_Direction_Transmitter);
    //等待事件event6，即从设备写地址已发送且从设备ack已回应，SR1寄存器ADDR=1 TxE=1
    i2ctimeout=I2CTIMEOUT;
    while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED)){if((i2ctimeout--)==0){usart_sendstring(USART1,"wdriveraddr ack timeout!");return 1;}}
    //发送1byte数据到从设备，如果从设备是存储设备类型需要提供rwaddr，不是存储设备类型rwaddr=0
    if(rwaddr==0){
      I2C_SendData(I2C1,*pbuffer);
      //等待事件event8，即从设备ack回应，DR寄存器为空，SR1寄存器TxE=1
      i2ctimeout=I2CTIMEOUT;
      while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED)){if((i2ctimeout--)==0){usart_sendstring(USART1,"Tx data timeout!");return 1;}}
      //产生i2c停止信号
      I2C_GenerateSTOP(I2C1,ENABLE);
    }else{
      I2C_SendData(I2C1,rwaddr);
      //等待事件event8，即从设备ack回应，DR寄存器为空，SR1寄存器TxE=1
      i2ctimeout=I2CTIMEOUT;
      while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED)){if((i2ctimeout--)==0){usart_sendstring(USART1,"Tx data timeout!");return 1;}}
      I2C_SendData(I2C1,*pbuffer);
      i2ctimeout=I2CTIMEOUT;
      while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED)){if((i2ctimeout--)==0){usart_sendstring(USART1,"Tx data timeout!");return 1;}}
      //产生i2c停止信号
      I2C_GenerateSTOP(I2C1,ENABLE);
    }
  }
  return 0;
}