/**
  ******************************************************************************
  * @file    usart.c
  * @author  
  * @version V1.0.0
  * @date    2024-10-20
  * @brief   
  ******************************************************************************
  * @attention
  ******************************************************************************
  */

#include "usart.h"
#include "misc.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_usart.h"

static void nvic_config(){
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
  NVIC_InitTypeDef nvicinit;
  nvicinit.NVIC_IRQChannel=USART1_IRQn;
  nvicinit.NVIC_IRQChannelCmd=ENABLE;
  nvicinit.NVIC_IRQChannelPreemptionPriority=1;
  nvicinit.NVIC_IRQChannelSubPriority=1;
  NVIC_Init(&nvicinit);
}
void usart_pa9_10_config(void){
//使能gpioa和串口1时钟
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_USART1,ENABLE);
  GPIO_InitTypeDef gpioinit;
  USART_InitTypeDef usartinit;
//config pa9 tx
  gpioinit.GPIO_Mode=GPIO_Mode_AF_PP;
  gpioinit.GPIO_Pin=GPIO_Pin_9;
  gpioinit.GPIO_Speed=GPIO_Speed_50MHz;
  GPIO_Init(GPIOA,&gpioinit);
//config pa10 rx
  gpioinit.GPIO_Mode=GPIO_Mode_IN_FLOATING;
  gpioinit.GPIO_Pin=GPIO_Pin_10;
  GPIO_Init(GPIOA,&gpioinit);
//config usart1
  //串口波特率
  usartinit.USART_BaudRate=115200;
  //串口硬件流控制
  usartinit.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
  //串口工作模式
  usartinit.USART_Mode=USART_Mode_Tx|USART_Mode_Rx;
  //串口校验位配置
  usartinit.USART_Parity=USART_Parity_No;
  //串口停止位配置
  usartinit.USART_StopBits=USART_StopBits_1;
  //数据帧字长无校验8bit
  usartinit.USART_WordLength=USART_WordLength_8b;
  //初始化usart1
  USART_Init(USART1,&usartinit);
  //串口中断优先级配置
  nvic_config();
  //使能串口接收中断
  USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
  //使能串口
  USART_Cmd(USART1,ENABLE);
}
void usart_sendbyte(USART_TypeDef* pUSARTx,uint8_t ch){
  USART_SendData(pUSARTx,ch);
  while(USART_GetFlagStatus(pUSARTx,USART_FLAG_TXE)==RESET);
}
void usart_sendstring(USART_TypeDef* pUSARTx,char* str){
  unsigned int i=0;
  while (*(str+i)!='\0')
  {
    usart_sendbyte(pUSARTx,*(str+i));
    i++;
  }
  while(USART_GetFlagStatus(pUSARTx,USART_FLAG_TC)==RESET);
}