#ifndef __ST7735_H
#define __ST7735_H

#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "font.h"

#define USE_HORIZONTAL 1//竖屏屏0，1；横屏2，3
#define OLED

#if USE_HORIZONTAL==0||USE_HORIZONTAL==1
#define LCD_W 128
#define LCD_H 160

#else
#define LCD_W 160
#define LCD_H 128
#endif

//DC
#define LCD_DC_CLR()   GPIO_ResetBits(GPIOA, GPIO_Pin_1)
#define LCD_DC_SET()   GPIO_SetBits(GPIOA, GPIO_Pin_1)
//RES
#define LCD_RST_CLR()  GPIO_ResetBits(GPIOA, GPIO_Pin_6)
#define LCD_RST_SET()  GPIO_SetBits(GPIOA, GPIO_Pin_6)
//BLK
#define LCD_BLK_Clr()  GPIO_ResetBits(GPIOB,GPIO_Pin_10)
#define LCD_BLK_Set()  GPIO_SetBits(GPIOB,GPIO_Pin_10)

#define LCD_CMD  0	//命令
#define LCD_DATA 1	//数据


//颜色
#ifdef OLED
#define WHITE            0xFFFF
#define BLACK            0x0000
#define BLUE             0x001F  
#define BRED             0XF81F
#define GRED             0XFFE0
#define GBLUE            0X07FF
#define RED              0xF800
#define MAGENTA          0xF81F
#define GREEN            0x07E0
#define CYAN             0x7FFF
#define YELLOW           0xFFE0
#define BROWN            0XBC40 //棕色
#define BRRED            0XFC07 //棕红色
#define GRAY             0X8430 //灰色
#define DARKBLUE         0X01CF //深蓝色
#define LIGHTBLUE        0X7D7C //浅蓝色  
#define GRAYBLUE         0X5458 //灰蓝色 
#define LIGHTGREEN       0X841F //浅绿色
#define LGRAY            0XC618 //浅灰色(PANNEL),窗体背景色
#define LGRAYBLUE        0XA651 //浅灰蓝色(中间层颜色)
#define LBBLUE           0X2B12 //浅棕蓝色(选择条目的反色)
#endif

#ifdef LCD
#define BLACK 0xFFFF //BLACK 黑色
#define WHITE 0x0000 //WHITE 白色
#define RED 0x07FF //RED 红色
#define YELLOW 0x001F //YELLOW 黄色
#define GREEN 0xF81F //GREEN 绿色
#define CYAN 0xF800 //CYAN 青色
#define BLUE 0xFFE0 //BLUE 蓝色
#define MAGENTA 0x07E0 //MAGENTA 品红色
#define GRAY 0x8410 //GRAY 灰色
#endif

void LCD_GPIO_Config(void);
void writeBus(uint8_t data);
void LCD_writeData8(uint8_t data);
void LCD_writeData(uint16_t data);
void LCD_writeCommand(uint8_t data);
void LCD_setAddress(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void LCD_init(void);
void LCD_clear(uint16_t color);
void LCD_drawPoint(uint16_t x, uint16_t y, uint16_t color);
void LCD_showChar(uint16_t x, uint16_t y, uint8_t chr, uint16_t color);
void LCD_showString(uint16_t x, uint16_t y, char *p, uint16_t color);
void LCD_showImg(uint16_t x, uint16_t y, uint16_t index1, uint16_t color);

extern uint16_t BACK_COLOR;

#endif