#ifndef __LCD_H
#define __LCD_H

#define OFFSET_Y 20

#include "lvgl.h"
//extern osSemaphoreId_t DMA_SemaphoreHandle; 
//extern void (*dma_callback)(void);

//------------设置横屏或者竖屏显示 0或1为竖屏 2或3为横屏------------
//------------0或1区分哪边是底部，如果上下颠倒左右相反就调这个
#define USE_HORIZONTAL 0  

#if USE_HORIZONTAL==0||USE_HORIZONTAL==1
#define LCD_W 240
#define LCD_H 280

#else
#define LCD_W 280
#define LCD_H 240
#endif

//-----------------LCD端口定义---------------- 
#define SCLK_PORT			GPIOB
#define SCLK_PIN			GPIO_PIN_3  //时钟线

#define SDA_PORT			GPIOB
#define SDA_PIN				GPIO_PIN_5  //单向传输，单片机发LCD收
 
#define RES_PORT			GPIOB
#define RES_PIN				GPIO_PIN_7  //复位信号

#define DC_PORT				GPIOB
#define DC_PIN				GPIO_PIN_9  //Data\Comman 0则写入命令，1则写入数据

#define CS_PORT				GPIOB
#define CS_PIN				GPIO_PIN_8  //片选

#define BLK_PORT			GPIOB
#define BLK_PIN				GPIO_PIN_0  //背光控制线

#define LCD_SCLK_Clr() HAL_GPIO_WritePin(SCLK_PORT,SCLK_PIN,GPIO_PIN_RESET)//SCL=SCLK
#define LCD_SCLK_Set() HAL_GPIO_WritePin(SCLK_PORT,SCLK_PIN,GPIO_PIN_SET)

#define LCD_MOSI_Clr() HAL_GPIO_WritePin(SDA_PORT,SDA_PIN,GPIO_PIN_RESET)//SDA=MOSI
#define LCD_MOSI_Set() HAL_GPIO_WritePin(SDA_PORT,SDA_PIN,GPIO_PIN_SET)

#define LCD_RES_Clr()  HAL_GPIO_WritePin(RES_PORT,RES_PIN,GPIO_PIN_RESET)//RES
#define LCD_RES_Set()  HAL_GPIO_WritePin(RES_PORT,RES_PIN,GPIO_PIN_SET)

#define LCD_DC_Clr()   HAL_GPIO_WritePin(DC_PORT,DC_PIN,GPIO_PIN_RESET)//DC
#define LCD_DC_Set()   HAL_GPIO_WritePin(DC_PORT,DC_PIN,GPIO_PIN_SET)
 		     
#define LCD_CS_Clr()   HAL_GPIO_WritePin(CS_PORT,CS_PIN,GPIO_PIN_RESET)//CS
#define LCD_CS_Set()   HAL_GPIO_WritePin(CS_PORT,CS_PIN,GPIO_PIN_SET)

#define LCD_BLK_Clr()  HAL_GPIO_WritePin(BLK_PORT,BLK_PIN,GPIO_PIN_RESET)//BLK
#define LCD_BLK_Set()  HAL_GPIO_WritePin(BLK_PORT,BLK_PIN,GPIO_PIN_SET)

//画笔颜色
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE           	 0x001F  
#define BRED             0XF81F
#define GRED 			 0XFFE0
#define GBLUE			 0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			 0XBC40 //棕色
#define BRRED 			 0XFC07 //棕红色
#define GRAY  			 0X8430 //灰色
#define DARKBLUE      	 0X01CF	//深蓝色
#define LIGHTBLUE      	 0X7D7C	//浅蓝色  
#define GRAYBLUE       	 0X5458 //灰蓝色
#define LIGHTGREEN     	 0X841F //浅绿色
#define LGRAY 			 0XC618 //浅灰色(PANNEL),窗体背景色
#define LGRAYBLUE        0XA651 //浅灰蓝色(中间层颜色)
#define LBBLUE           0X2B12 //浅棕蓝色(选择条目的反色)


//-------------------------------分割线-------------------------------
//-------------------------------分割线-------------------------------
//-------------------------------分割线-------------------------------

//LCD显示驱动的基础函数
void LCD_GPIO_Init(void);
void LCD_Write_Bus(uint8_t data);
void LCD_Write_Data8(uint8_t data);
void LCD_Write_Data16(uint16_t data);
void LCD_Write_REG(uint8_t data);
void LCD_Address_Set(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);
void LCD_Set_Light(uint8_t dc);
void LCD_Close_Light(void);
void LCD_Open_Light(void);
void LCD_ST7789_SleepIn(void);
void LCD_ST7789_SleepOut(void);
void LCD_Init(void);

//LCD的绘图函数
void LCD_Fill(uint16_t xstart,uint16_t ystart,uint16_t xend,uint16_t yend,uint16_t color);
//void LCD_Color_Fill(uint16_t xstart,uint16_t ystart,uint16_t xend,uint16_t yend,lv_color_t  *color);
void LCD_Color_Fill(uint16_t xsta,uint16_t ysta,uint16_t xend,uint16_t yend,uint16_t *color_p);
void LCD_DrawPoint(uint16_t x,uint16_t y,uint16_t color);
void LCD_DrawLine(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2,uint16_t color);
void LCD_DrawRectangle(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2,uint16_t color);
void Draw_Circle(uint16_t x0,uint16_t y0,uint8_t r,uint16_t color);
void LCD_ShowChinese(uint16_t x, uint16_t y, uint8_t *s, uint16_t fc, uint16_t bc, uint8_t sizey, uint8_t mode);
void LCD_ShowChinese12x12(uint16_t x, uint16_t y, uint8_t *s, uint16_t fc, uint16_t bc, uint8_t sizey, uint8_t mode);
void LCD_ShowChinese16x16(uint16_t x, uint16_t y, uint8_t *s, uint16_t fc, uint16_t bc, uint8_t sizey, uint8_t mode);
void LCD_ShowChinese24x24(uint16_t x, uint16_t y, uint8_t *s, uint16_t fc, uint16_t bc, uint8_t sizey, uint8_t mode);
void LCD_ShowChinese32x32(uint16_t x, uint16_t y, uint8_t *s, uint16_t fc, uint16_t bc, uint8_t sizey, uint8_t mode);
void LCD_ShowChar(uint16_t x, uint16_t y, uint8_t num, uint16_t fc, uint16_t bc, uint8_t sizey, uint8_t mode);
void LCD_ShowString(uint16_t x, uint16_t y, const uint8_t *p, uint16_t fc, uint16_t bc, uint8_t sizey, uint8_t mode);
uint32_t mypow(uint8_t m, uint8_t n);
void LCD_ShowIntNum(uint16_t x, uint16_t y, uint16_t num, uint8_t len, uint16_t fc, uint16_t bc, uint8_t sizey);
void LCD_ShowFloatNum1(uint16_t x, uint16_t y, float num, uint8_t len, uint16_t fc, uint16_t bc, uint8_t sizey);
void LCD_ShowPicture(uint16_t x, uint16_t y, uint16_t length, uint16_t width, const uint8_t pic[]);

#endif
