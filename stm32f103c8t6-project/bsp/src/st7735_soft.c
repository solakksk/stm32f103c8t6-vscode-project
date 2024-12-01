#include "st7735_soft.h"
#include "delay.h"

uint16_t BACK_COLOR;

/**
  * @brief 配置GPIO
	* PA1: CS
	* PA4: RSE
	* PA5: SCL
	* PA6: DC
	* PA7: SDA
  * @retval None
  */
void LCD_GPIO_Config(void)	
{
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); // 开启GPIOB时钟
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;	//定义要使用的pin
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);  //初始化GPIO
}

/**
  * @brief SPI协议写一个字节
  * @param  data 8位数据
  * @retval None
  */
void writeBus(uint8_t data)
{
	uint8_t i;
	LCD_CS_CLR();
	for(i=0; i<8; i++)
	{
		LCD_SCL_CLR();
		if(data&0x80)
			LCD_SDA_SET();
		else
			LCD_SDA_CLR();
		LCD_SCL_SET();
		data<<=1;
	}
	LCD_CS_SET();
}

/**
  * @brief LCD写一个字节
  * @param  data 8位数据
  * @retval None
  */
void LCD_writeData8(uint8_t data)
{
	LCD_DC_SET();
	writeBus(data);
}

/**
  * @brief LCD写个两字节
  * @param  data 16位数据
  * @retval None
  */
void LCD_writeData(uint16_t data)
{
	LCD_DC_SET();
	writeBus(data>>8);
	writeBus(data);
}

/**
  * @brief LCD写个两字节
  * @param  data 8位命令
  * @retval None
  */
void LCD_writeCommand(uint8_t data)
{
	LCD_DC_CLR();
	writeBus(data);
}

/**
  * @brief LCD设置起始和结束地址
  * @param  x1,y1,x2,y2行列地址
  * @retval None
  */
void LCD_setAddress(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
	if(USE_HORIZONTAL==0)
	{
		LCD_writeCommand(0x2a);
		LCD_writeData(x1+1);
		LCD_writeData(x2+1);
		LCD_writeCommand(0x2b);
		LCD_writeData(y1);
		LCD_writeData(y2);
		LCD_writeCommand(0x2c);
	}
	else if(USE_HORIZONTAL==1)
	{
		LCD_writeCommand(0x2a);
		LCD_writeData(x1+1);
		LCD_writeData(x2+1);
		LCD_writeCommand(0x2b);
		LCD_writeData(y1);
		LCD_writeData(y2);
		LCD_writeCommand(0x2c);
	}
	else if(USE_HORIZONTAL==2)
	{
		LCD_writeCommand(0x2a);
		LCD_writeData(x1);
		LCD_writeData(x2);
		LCD_writeCommand(0x2b);
		LCD_writeData(y1+1);
		LCD_writeData(y2+1);
		LCD_writeCommand(0x2c);
	}
	else
	{
		LCD_writeCommand(0x2a);
		LCD_writeData(x1);
		LCD_writeData(x2);
		LCD_writeCommand(0x2b);
		LCD_writeData(y1+1);
		LCD_writeData(y2+1);
		LCD_writeCommand(0x2c);
	}
}

/**
  * @brief LCD初始化函数
  * @param  None
  * @retval None
  */
void LCD_init(void)
{
	LCD_RST_SET();
	delay_ms(100);
	LCD_RST_CLR();
	delay_ms(200);
	LCD_RST_SET();
	delay_ms(100);

	LCD_writeCommand(0x11); 
	delay_ms(100);

	//LCD_writeCommand(0x21); 

	LCD_writeCommand(0xB1); 
	LCD_writeData8(0x02);
	LCD_writeData8(0x2E);
	LCD_writeData8(0x2E);

	LCD_writeCommand(0xB2);
	LCD_writeData8(0x05);
	LCD_writeData8(0x3A);
	LCD_writeData8(0x3A);

	LCD_writeCommand(0xB3); 
	LCD_writeData8(0x05);  
	LCD_writeData8(0x3A);
	LCD_writeData8(0x3A);
	LCD_writeData8(0x05);
	LCD_writeData8(0x3A);
	LCD_writeData8(0x3A);

	LCD_writeCommand(0xB4);
	LCD_writeData8(0x03);

	LCD_writeCommand(0xC0);//电压控制
	LCD_writeData8(0x00);//VRH[4:0] GVDD
	LCD_writeData8(0x00);//IB_SEL[5:4] AVDD

	LCD_writeCommand(0xC1);//VGH|VGL
	LCD_writeData8(0x00);

	LCD_writeCommand(0xC2);//in Normal mode/Full colors
	LCD_writeData8(0xF1);//AP[2:0]运算放大器中的电流量
	LCD_writeData8(0x00);//DC[2:0]设置booster电路升压周期

	LCD_writeCommand(0xC3);//in Idle mode/8-colors
	LCD_writeData8(0x8D);
	LCD_writeData8(0x6A);   

	LCD_writeCommand(0xC4);//in Partial mode/full-colors
	LCD_writeData8(0x8D); 
	LCD_writeData8(0xEE); 

	LCD_writeCommand(0xC5);//VCOM
	LCD_writeData8(0x0E);    

	LCD_writeCommand(0xE0);
	LCD_writeData8(0x10);
	LCD_writeData8(0x0E);
	LCD_writeData8(0x02);
	LCD_writeData8(0x03);
	LCD_writeData8(0x0E);
	LCD_writeData8(0x07);
	LCD_writeData8(0x02);
	LCD_writeData8(0x07);
	LCD_writeData8(0x0A);
	LCD_writeData8(0x12);
	LCD_writeData8(0x27);
	LCD_writeData8(0x37);
	LCD_writeData8(0x00);
	LCD_writeData8(0x0D);
	LCD_writeData8(0x0E);
	LCD_writeData8(0x10);

	LCD_writeCommand(0xE1);
	LCD_writeData8(0x10);
	LCD_writeData8(0x0E);
	LCD_writeData8(0x03);
	LCD_writeData8(0x03);
	LCD_writeData8(0x0F);
	LCD_writeData8(0x06);
	LCD_writeData8(0x02);
	LCD_writeData8(0x08);
	LCD_writeData8(0x0A);
	LCD_writeData8(0x13);
	LCD_writeData8(0x26);
	LCD_writeData8(0x36);
	LCD_writeData8(0x00);
	LCD_writeData8(0x0D);
	LCD_writeData8(0x0E);
	LCD_writeData8(0x10);

	LCD_writeCommand(0x3A); 
	LCD_writeData8(0x05);

	LCD_writeCommand(0x36);
	if(USE_HORIZONTAL==0)LCD_writeData8(0x00);
	else if(USE_HORIZONTAL==1)LCD_writeData8(0xC0);
	else if(USE_HORIZONTAL==2)LCD_writeData8(0x60);
	else LCD_writeData8(0xA0);

	LCD_writeCommand(0x29); 
}

/**
  * @brief LCD清屏函数
  * @param  color 16位RGB颜色
  * @retval None
  */
void LCD_clear(uint16_t color)
{
	uint16_t i, j;
	LCD_setAddress(1, 1, LCD_W, LCD_H);
	for(i=0; i<LCD_H; i++)
	{
		for(j=0; j<LCD_W; j++)
		{
			LCD_writeData(color);
		}
	}
}

/**
  * @brief LCD画点函数
  * @param  x,y 画点的坐标
	*	        color 16位RGB颜色
  * @retval None
  */
void LCD_drawPoint(uint16_t x, uint16_t y, uint16_t color)
{
	LCD_setAddress(x, y, x, y);
	LCD_writeData(color);
}

/**
	* @brief LCD显示一个1608字符函数
  * @param  x,y 字符的坐标
  *         color 16位RGB颜色
  * @retval None
  */
void LCD_showChar(uint16_t x, uint16_t y, uint8_t chr, uint16_t color)
{
	uint8_t i, j;
	uint8_t temp;
	chr = chr - ' ';
	LCD_setAddress(x, y, x+8, y+16);
	for(i=0; i<16; i++)
	{
		temp = asc2_1608[chr][i];
		for(j=0; j<8; j++)
		{
			if(temp&0x01)
			{
				LCD_drawPoint(x+j, y+i, color);
			}
			else
			{
				LCD_drawPoint(x+j, y+i, BACK_COLOR);
			}
			temp >>= 1;
		}
	}
}

/**
	* @brief LCD显示字串函数
  * @param  x,y 字符的坐标
  *         *p 字符串
  *         color 16位RGB颜色
  * @retval None
  */
void LCD_showString(uint16_t x, uint16_t y, char *p, uint16_t color)
{
	while(*p!='\0')
	{
		if(x>LCD_W-16)
		{
			x=0;
			y+=16;
		}
		if(y>LCD_H-16)
		{
			y=x=0;
			LCD_clear(BACK_COLOR);
		}
		LCD_showChar(x, y, *p, color);
		x+=8;
		p++;
	}
}
