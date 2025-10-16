#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include "cmsis_os.h"
#include "delay.h"
#include "spi.h"
#include "tim.h"
#include "LCDfont.h"
#include "LCD.h"

/******************************************************************************
      函数说明：LCD端口初始化
      入口数据：无
      返回值：  无
******************************************************************************/
void LCD_GPIO_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure = {0};
	
 	__HAL_RCC_GPIOB_CLK_ENABLE();
	
	GPIO_InitStructure.Pin = RES_PIN|CS_PIN|DC_PIN;	 
 	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP; 		 //推挽输出
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;//速度50MHz
 	HAL_GPIO_Init(GPIOB, &GPIO_InitStructure);	  //初始化GPIOB
 	HAL_GPIO_WritePin(GPIOB, RES_PIN|CS_PIN|DC_PIN, GPIO_PIN_SET);
}

/******************************************************************************
      函数说明：LCD串行数据写入函数(software SPI)
      入口数据：data  要写入的串行数据
      返回值：  无
******************************************************************************/
void LCD_Write_Bus(uint8_t data)
{
	//硬件SPI
	HAL_SPI_Transmit(&hspi1,&data,1,1);
	
	//软件SPI
//	uint8_t i;
//	for(i = 0;i<8;i++)
//	{
//		LCD_SCLK_Clr(); //先拉低时钟线，写入数据
//		
//		if(data&0x80)  //位与0x1000 0000判断最高位的情况
//		{
//			LCD_MOSI_Set(); //1则拉高，0则拉低
//		}
//		else{
//			LCD_MOSI_Clr();
//		}
//		
//		LCD_SCLK_Set();  //再拉高时钟线，传输数据
//		data <<= 1;  //右移data传输下一位
//	}
}

/******************************************************************************
      函数说明：LCD写入8位数据
      入口数据：data 写入的数据
      返回值：  无
******************************************************************************/
void LCD_Write_Data8(uint8_t data)
{
	LCD_Write_Bus(data);
}

/******************************************************************************
      函数说明：LCD写入16位数据
      入口数据：data 写入的数据
      返回值：  无
******************************************************************************/
void LCD_Write_Data16(uint16_t data)
{
	//硬件SPI
	uint8_t temp[2];
	temp[0] = (data>>8) & 0xff;
	temp[1] = data & 0xff;
	HAL_SPI_Transmit(&hspi1,temp,2,1);
	//软件
//	LCD_Write_Bus(data >> 8);
//	LCD_Write_Bus(data);
}

/******************************************************************************
      函数说明：LCD写入命令
      入口数据：dat 写入的命令
      返回值：  无
******************************************************************************/
void LCD_Write_REG(uint8_t data)
{
	LCD_DC_Clr(); //写入命令
	LCD_Write_Bus(data);
	LCD_DC_Set(); //写入数据
}

/******************************************************************************
      函数说明：设置起始和结束地址
      入口数据：x1,x2 设置列的起始和结束地址
                y1,y2 设置行的起始和结束地址
      返回值：  无
******************************************************************************/
void LCD_Address_Set(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2)
{
	LCD_Write_REG(0x2a); //列地址设置
	LCD_Write_Data16(x1);
	LCD_Write_Data16(x2);
	LCD_Write_REG(0x2b); //行地址设置
	LCD_Write_Data16(y1);
	LCD_Write_Data16(y2);
	LCD_Write_REG(0x2c);
}

/******************************************************************************
      函数说明：LCD调节背光
      入口数据：dc,占空比,5%~100%
      返回值：  无
******************************************************************************/
void LCD_Set_Light(uint8_t dc)
{
	if(dc >=5 && dc <= 100)
	{
		__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_3,dc*PWM_PERIOD/100);
	}
}

/******************************************************************************
      函数说明：LCD关闭背光
      入口数据：无
      返回值：  无
******************************************************************************/
void LCD_Close_Light(void)
{
	__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_3,0);
}

/******************************************************************************
      函数说明：LCD开启背光
      入口数据：无
      返回值：  无
******************************************************************************/
void LCD_Open_Light(void)
{
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_3);
}

/******************************************************************************
      函数说明：ST7789 SLEEP IN
      入口数据：无
      返回值：  无
******************************************************************************/
void LCD_ST7789_SleepIn(void)
{
	LCD_Write_REG(0x10);
	delay_ms(100);
}

/******************************************************************************
      函数说明：ST7789 SLEEP OUT
      入口数据：无
      返回值：  无
******************************************************************************/
void LCD_ST7789_SleepOut(void)
{
	LCD_Write_REG(0x11);
	delay_ms(100);
}

/******************************************************************************
      函数说明：LCD初始化
      入口数据：无
      返回值：  无
******************************************************************************/
void LCD_Init(void)
{
	LCD_GPIO_Init();
	LCD_CS_Clr();  //拉低片选信号，选中芯片
	
	LCD_RES_Clr(); //复位
	delay_ms(100);
	LCD_RES_Set();
	delay_ms(100);
	
	//下面是厂家的标准启动流程
	LCD_Write_REG(0x11); 
	delay_ms(120); 
	LCD_Write_REG(0x36); 
	if(USE_HORIZONTAL==0) LCD_Write_Data8(0x00);
	else if(USE_HORIZONTAL==1) LCD_Write_Data8(0xC0);
	else if(USE_HORIZONTAL==2) LCD_Write_Data8(0x70);
	else LCD_Write_Data8(0xA0);

	LCD_Write_REG(0x3A);
	LCD_Write_Data8(0x05);

	LCD_Write_REG(0xB2);
	LCD_Write_Data8(0x0C);
	LCD_Write_Data8(0x0C);
	LCD_Write_Data8(0x00);
	LCD_Write_Data8(0x33);
	LCD_Write_Data8(0x33); 

	LCD_Write_REG(0xB7); 
	LCD_Write_Data8(0x35);  

	LCD_Write_REG(0xBB);
	LCD_Write_Data8(0x19);

	LCD_Write_REG(0xC0);
	LCD_Write_Data8(0x2C);

	LCD_Write_REG(0xC2);
	LCD_Write_Data8(0x01);

	LCD_Write_REG(0xC3);
	LCD_Write_Data8(0x12);   

	LCD_Write_REG(0xC4);
	LCD_Write_Data8(0x20);  

	LCD_Write_REG(0xC6); 
	LCD_Write_Data8(0x0F);    

	LCD_Write_REG(0xD0); 
	LCD_Write_Data8(0xA4);
	LCD_Write_Data8(0xA1);

	LCD_Write_REG(0xE0);
	LCD_Write_Data8(0xD0);
	LCD_Write_Data8(0x04);
	LCD_Write_Data8(0x0D);
	LCD_Write_Data8(0x11);
	LCD_Write_Data8(0x13);
	LCD_Write_Data8(0x2B);
	LCD_Write_Data8(0x3F);
	LCD_Write_Data8(0x54);
	LCD_Write_Data8(0x4C);
	LCD_Write_Data8(0x18);
	LCD_Write_Data8(0x0D);
	LCD_Write_Data8(0x0B);
	LCD_Write_Data8(0x1F);
	LCD_Write_Data8(0x23);

	LCD_Write_REG(0xE1);
	LCD_Write_Data8(0xD0);
	LCD_Write_Data8(0x04);
	LCD_Write_Data8(0x0C);
	LCD_Write_Data8(0x11);
	LCD_Write_Data8(0x13);
	LCD_Write_Data8(0x2C);
	LCD_Write_Data8(0x3F);
	LCD_Write_Data8(0x44);
	LCD_Write_Data8(0x51);
	LCD_Write_Data8(0x2F);
	LCD_Write_Data8(0x1F);
	LCD_Write_Data8(0x1F);
	LCD_Write_Data8(0x20);
	LCD_Write_Data8(0x23);

	LCD_Write_REG(0x21); 
	LCD_Write_REG(0x29); 
}


/*******************************************分割线*****************************************/
/*******************************************分割线*****************************************/
/*******************************************分割线*****************************************/
/*******************************************分割线*****************************************/
/*******************************************分割线*****************************************/

/******************************************************************************
      函数说明：在指定区域填充颜色
      入口数据：xsta,ysta   起始坐标
                xend,yend   终止坐标
								color       要填充的颜色
      返回值：  无
******************************************************************************/
void LCD_Fill(uint16_t xstart,uint16_t ystart,uint16_t xend,uint16_t yend,uint16_t color)
{
	uint16_t i,j;
	LCD_Address_Set(xstart,ystart+OFFSET_Y,xend-1,yend-1+OFFSET_Y);//设置显示范围
	for(i = ystart;i < yend;i++)
	{
		for(j = xstart;j < xend;j++)
		{
			LCD_Write_Data16(color);
		}
	}
}

/******************************************************************************
      函数说明：在指定区域填充颜色
      入口数据：xsta,ysta   起始坐标
                xend,yend   终止坐标
								color       要填充的颜色
      返回值：  无
******************************************************************************/

//void LCD_Color_Fill(uint16_t xstart,uint16_t ystart,uint16_t xend,uint16_t yend,lv_color_t  *color)
//{
//	uint16_t width,height;
//	width = xend - xstart + 1;
//	height = yend - ystart + 1;
//	uint32_t size = width * height;
//	uint32_t y = 0;
//	
//	LCD_Address_Set(xstart,ystart+OFFSET_Y,xend,yend+OFFSET_Y);
//	
//	for(y=0;y<size;y++)
//	{
//		LCD_Write_Data16(color->full);
//		color++;
//	}
//}
void LCD_Color_Fill(uint16_t xsta,uint16_t ysta,uint16_t xend,uint16_t yend,uint16_t *color_p)
{
	uint16_t i,j,width,height; 
	width = xend-xsta+1;
	height = yend-ysta+1;
	uint32_t size = width * height;
	
	LCD_Address_Set(xsta,ysta+OFFSET_Y,xend,yend+OFFSET_Y);
	
	hspi1.Init.DataSize = SPI_DATASIZE_16BIT;
	hspi1.Instance->CR1|=SPI_CR1_DFF;
	HAL_SPI_Transmit_DMA(&hspi1,(uint8_t*)color_p,size);
	while(__HAL_DMA_GET_COUNTER(&hdma_spi1_tx)!=0);
	
	hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
	hspi1.Instance->CR1&=~SPI_CR1_DFF;
	
}

/******************************************************************************
      函数说明：在指定位置画点
      入口数据：x,y 画点坐标
                color 点的颜色
      返回值：  无
******************************************************************************/
void LCD_DrawPoint(uint16_t x,uint16_t y,uint16_t color)
{
	LCD_Address_Set(x,y,x,y);  //设置光标位置
	LCD_Write_Data16(color);
}

/******************************************************************************
      函数说明：画线
      入口数据：x1,y1   起始坐标
                x2,y2   终止坐标
                color   线的颜色
      返回值：  无
******************************************************************************/
void LCD_DrawLine(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2,uint16_t color)
{
	uint16_t t;
	int xerr=0,yerr=0,delta_x,delta_y,distance;
	int incx,incy,uRow,uCol;
	delta_x=x2-x1; //计算坐标增量 
	delta_y=y2-y1;
	uRow=x1;//画线起点坐标
	uCol=y1;
	if(delta_x>0)incx=1; //设置单步方向 
	else if (delta_x==0)incx=0;//垂直线 
	else {incx=-1;delta_x=-delta_x;}
	if(delta_y>0)incy=1;
	else if (delta_y==0)incy=0;//水平线 
	else {incy=-1;delta_y=-delta_y;}
	if(delta_x>delta_y)distance=delta_x; //选取基本增量坐标轴 
	else distance=delta_y;
	for(t=0;t<distance+1;t++)
	{
		LCD_DrawPoint(uRow,uCol,color);//画点
		xerr+=delta_x;
		yerr+=delta_y;
		if(xerr>distance)
		{
			xerr-=distance;
			uRow+=incx;
		}
		if(yerr>distance)
		{
			yerr-=distance;
			uCol+=incy;
		}
	}
}

/******************************************************************************
      函数说明：画矩形
      入口数据：x1,y1   起始坐标
                x2,y2   终止坐标
                color   矩形的颜色
      返回值：  无
******************************************************************************/
void LCD_DrawRectangle(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2,uint16_t color)
{
	LCD_DrawLine(x1,y1,x2,y1,color);
	LCD_DrawLine(x1,y1,x1,y2,color);
	LCD_DrawLine(x1,y2,x2,y2,color);
	LCD_DrawLine(x2,y1,x2,y2,color);
}

/******************************************************************************
      函数说明：画圆
      入口数据：x0,y0   圆心坐标
                r       半径
                color   圆的颜色
      返回值：  无
******************************************************************************/
void Draw_Circle(uint16_t x0,uint16_t y0,uint8_t r,uint16_t color)
{
	int a,b;
	a=0;b=r;	  
	while(a<=b)
	{
		LCD_DrawPoint(x0-b,y0-a,color);             //3           
		LCD_DrawPoint(x0+b,y0-a,color);             //0           
		LCD_DrawPoint(x0-a,y0+b,color);             //1                
		LCD_DrawPoint(x0-a,y0-b,color);             //2             
		LCD_DrawPoint(x0+b,y0+a,color);             //4               
		LCD_DrawPoint(x0+a,y0-b,color);             //5
		LCD_DrawPoint(x0+a,y0+b,color);             //6 
		LCD_DrawPoint(x0-b,y0+a,color);             //7
		a++;
		if((a*a+b*b)>(r*r))//判断要画的点是否过远
		{
			b--;
		}
	}
}

/******************************************************************************
      函数说明：显示汉字串
      入口数据：x,y显示坐标
                *s 要显示的汉字串
                fc 字的颜色
                bc 字的背景色
                sizey 字号 可选 16 24 32
                mode:  0非叠加模式  1叠加模式
      返回值：  无
******************************************************************************/
void LCD_ShowChinese(uint16_t x, uint16_t y, uint8_t *s, uint16_t fc, uint16_t bc, uint8_t sizey, uint8_t mode)
{
	while(*s!=0)
	{
		if(sizey==12) LCD_ShowChinese12x12(x,y,s,fc,bc,sizey,mode);
		else if(sizey==16) LCD_ShowChinese16x16(x,y,s,fc,bc,sizey,mode);
		else if(sizey==24) LCD_ShowChinese24x24(x,y,s,fc,bc,sizey,mode);
		else if(sizey==32) LCD_ShowChinese32x32(x,y,s,fc,bc,sizey,mode);
		else return;
		s+=2;
		x+=sizey;
	}
}

/******************************************************************************
      函数说明：显示单个12x12汉字
      入口数据：x,y显示坐标
                *s 要显示的汉字
                fc 字的颜色
                bc 字的背景色
                sizey 字号
                mode:  0非极加模式  1叠加模式
      返回值：  无
******************************************************************************/
void LCD_ShowChinese12x12(uint16_t x, uint16_t y, uint8_t *s, uint16_t fc, uint16_t bc, uint8_t sizey, uint8_t mode)
{
	uint8_t i,j,m=0;
	uint16_t k;
	uint16_t HZnum;//汉字数目
	uint16_t TypefaceNum;//一个字符所占字节大小
	uint16_t x0=x;
	TypefaceNum=(sizey/8+((sizey%8)?1:0))*sizey;
	                         
	HZnum=sizeof(tfont12)/sizeof(typFNT_GB12);	//统计汉字数目
	for(k=0;k<HZnum;k++) 
	{
		if((tfont12[k].Index[0]==*(s))&&(tfont12[k].Index[1]==*(s+1)))
		{ 	
			LCD_Address_Set(x,y,x+sizey-1,y+sizey-1);
			for(i=0;i<TypefaceNum;i++)
			{
				for(j=0;j<8;j++)
				{	
					if(!mode)//非叠加方式
					{
						if(tfont12[k].Msk[i]&(0x01<<j)) LCD_Write_Data16(fc);
						else LCD_Write_Data16(bc);
						m++;
						if(m%sizey==0)
						{
							m=0;
							break;
						}
					}
					else//叠加方式
					{
						if(tfont12[k].Msk[i]&(0x01<<j)) LCD_DrawPoint(x,y,fc);//画一个点
						x++;
						if((x-x0)==sizey)
						{
							x=x0;
							y++;
							break;
						}
					}
				}
			}
		}				  	
		continue;  //查找到对应点阵字库立即退出，防止多个汉字重复取模带来影响
	}
} 

/******************************************************************************
      函数说明：显示单个16x16汉字
      入口数据：x,y显示坐标
                *s 要显示的汉字
                fc 字的颜色
                bc 字的背景色
                sizey 字号
                mode:  0非叠加模式  1叠加模式
      返回值：  无
******************************************************************************/
void LCD_ShowChinese16x16(uint16_t x, uint16_t y, uint8_t *s, uint16_t fc, uint16_t bc, uint8_t sizey, uint8_t mode)
{
	uint8_t i,j,m=0;
	uint16_t k;
	uint16_t HZnum;//汉字数目
	uint16_t TypefaceNum;//一个字符所占字节大小
	uint16_t x0=x;
    TypefaceNum=(sizey/8+((sizey%8)?1:0))*sizey;
	HZnum=sizeof(tfont16)/sizeof(typFNT_GB16);	//统计汉字数目
	for(k=0;k<HZnum;k++) 
	{
		if ((tfont16[k].Index[0]==*(s))&&(tfont16[k].Index[1]==*(s+1)))
		{ 	
			LCD_Address_Set(x,y,x+sizey-1,y+sizey-1);
			for(i=0;i<TypefaceNum;i++)
			{
				for(j=0;j<8;j++)
				{	
					if(!mode)//非叠加方式
					{
						if(tfont16[k].Msk[i]&(0x01<<j)) LCD_Write_Data16(fc);
						else LCD_Write_Data16(bc);
						m++;
						if(m%sizey==0)
						{
							m=0;
							break;
						}
					}
					else//叠加方式
					{
						if(tfont16[k].Msk[i]&(0x01<<j)) LCD_DrawPoint(x,y,fc);//画一个点
						x++;
						if((x-x0)==sizey)
						{
							x=x0;
							y++;
							break;
						}
					}
				}
			}
		}				  	
		continue;  //查找到对应点阵字库立即退出，防止多个汉字重复取模带来影响
	}
} 


/******************************************************************************
      函数说明：显示单个24x24汉字
      入口数据：x,y显示坐标
                *s 要显示的汉字
                fc 字的颜色
                bc 字的背景色
                sizey 字号
                mode:  0非叠加模式  1叠加模式
      返回值：  无
******************************************************************************/
void LCD_ShowChinese24x24(uint16_t x, uint16_t y, uint8_t *s, uint16_t fc, uint16_t bc, uint8_t sizey, uint8_t mode)
{
	uint8_t i,j,m=0;
	uint16_t k;
	uint16_t HZnum;//汉字数目
	uint16_t TypefaceNum;//一个字符所占字节大小
	uint16_t x0=x;
	TypefaceNum=(sizey/8+((sizey%8)?1:0))*sizey;
	HZnum=sizeof(tfont24)/sizeof(typFNT_GB24);	//统计汉字数目
	for(k=0;k<HZnum;k++) 
	{
		if ((tfont24[k].Index[0]==*(s))&&(tfont24[k].Index[1]==*(s+1)))
		{ 	
			LCD_Address_Set(x,y,x+sizey-1,y+sizey-1);
			for(i=0;i<TypefaceNum;i++)
			{
				for(j=0;j<8;j++)
				{	
					if(!mode)//非叠加方式
					{
						if(tfont24[k].Msk[i]&(0x01<<j)) LCD_Write_Data16(fc);
						else LCD_Write_Data16(bc);
						m++;
						if(m%sizey==0)
						{
							m=0;
							break;
						}
					}
					else//叠加方式
					{
						if(tfont24[k].Msk[i]&(0x01<<j)) LCD_DrawPoint(x,y,fc);//画一个点
						x++;
						if((x-x0)==sizey)
						{
							x=x0;
							y++;
							break;
						}
					}
				}
			}
		}				  	
		continue;  //查找到对应点阵字库立即退出，防止多个汉字重复取模带来影响
	}
} 

/******************************************************************************
      函数说明：显示单个32x32汉字
      入口数据：x,y显示坐标
                *s 要显示的汉字
                fc 字的颜色
                bc 字的背景色
                sizey 字号
                mode:  0非叠加模式  1叠加模式
      返回值：  无
******************************************************************************/
void LCD_ShowChinese32x32(uint16_t x, uint16_t y, uint8_t *s, uint16_t fc, uint16_t bc, uint8_t sizey, uint8_t mode)
{
	uint8_t i,j,m=0;
	uint16_t k;
	uint16_t HZnum;//汉字数目
	uint16_t TypefaceNum;//一个字符所占字节大小
	uint16_t x0=x;
	TypefaceNum=(sizey/8+((sizey%8)?1:0))*sizey;
	HZnum=sizeof(tfont32)/sizeof(typFNT_GB32);	//统计汉字数目
	for(k=0;k<HZnum;k++) 
	{
		if ((tfont32[k].Index[0]==*(s))&&(tfont32[k].Index[1]==*(s+1)))
		{ 	
			LCD_Address_Set(x,y,x+sizey-1,y+sizey-1);
			for(i=0;i<TypefaceNum;i++)
			{
				for(j=0;j<8;j++)
				{	
					if(!mode)//非叠加方式
					{
						if(tfont32[k].Msk[i]&(0x01<<j)) LCD_Write_Data16(fc);
						else LCD_Write_Data16(bc);
						m++;
						if(m%sizey==0)
						{
							m=0;
							break;
						}
					}
					else//叠加方式
					{
						if(tfont32[k].Msk[i]&(0x01<<j)) LCD_DrawPoint(x,y,fc);//画一个点
						x++;
						if((x-x0)==sizey)
						{
							x=x0;
							y++;
							break;
						}
					}
				}
			}
		}				  	
		continue;  //查找到对应点阵字库立即退出，防止多个汉字重复取模带来影响
	}
}


/******************************************************************************
      函数说明：显示单个字符
      入口数据：x,y显示坐标
                num 要显示的字符
                fc 字的颜色
                bc 字的背景色
                sizey 字号
                mode:  0非叠加模式  1叠加模式
      返回值：  无
******************************************************************************/
void LCD_ShowChar(uint16_t x, uint16_t y, uint8_t num, uint16_t fc, uint16_t bc, uint8_t sizey, uint8_t mode)
{
	uint8_t temp,sizex,t,m=0;
	uint16_t i,TypefaceNum;//一个字符所占字节大小
	uint16_t x0=x;
	sizex=sizey/2;
	TypefaceNum=(sizex/8+((sizex%8)?1:0))*sizey;
	num=num-' ';    //得到偏移后的值
	LCD_Address_Set(x,y,x+sizex-1,y+sizey-1);  //设置光标位置 
	for(i=0;i<TypefaceNum;i++)
	{ 
		if(sizey==12)temp=ascii_1206[num][i];		       //调用6x12字体
		else if(sizey==16)temp=ascii_1608[num][i];		 //调用8x16字体
		else if(sizey==24)temp=ascii_2412[num][i];		 //调用12x24字体
		else if(sizey==32)temp=ascii_3216[num][i];		 //调用16x32字体
		else return;
		for(t=0;t<8;t++)
		{
			if(!mode)//非叠加模式
			{
				if(temp&(0x01<<t)) LCD_Write_Data16(fc);
				else LCD_Write_Data16(bc);
				m++;
				if(m%sizex==0)
				{
					m=0;
					break;
				}
			}
			else//叠加模式
			{
				if(temp&(0x01<<t)) LCD_DrawPoint(x,y,fc);//画一个点
				x++;
				if((x-x0)==sizex)
				{
					x=x0;
					y++;
					break;
				}
			}
		}
	}   	 	  
}


/******************************************************************************
      函数说明：显示字符串
      入口数据：x,y显示坐标
                *p 要显示的字符串
                fc 字的颜色
                bc 字的背景色
                sizey 字号
                mode:  0非叠加模式  1叠加模式
      返回值：  无
******************************************************************************/
void LCD_ShowString(uint16_t x, uint16_t y, const uint8_t *p, uint16_t fc, uint16_t bc, uint8_t sizey, uint8_t mode)
{         
	while(*p!='\0')
	{       
		LCD_ShowChar(x,y,*p,fc,bc,sizey,mode);
		x+=sizey/2;
		p++;
	}  
}


/******************************************************************************
      函数说明：显示数字
      入口数据：m底数，n指数
      返回值：  无
******************************************************************************/
uint32_t mypow(uint8_t m, uint8_t n)
{
	uint32_t result=1;	 
	while(n--)result*=m;
	return result;
}


/******************************************************************************
      函数说明：显示整数变量
      入口数据：x,y显示坐标
                num 要显示整数变量
                len 要显示的位数
                fc 字的颜色
                bc 字的背景色
                sizey 字号
      返回值：  无
******************************************************************************/
void LCD_ShowIntNum(uint16_t x, uint16_t y, uint16_t num, uint8_t len, uint16_t fc, uint16_t bc, uint8_t sizey)
{         	
	uint8_t t,temp;
	uint8_t enshow=0;
	uint8_t sizex=sizey/2;
	for(t=0;t<len;t++)
	{
		temp=(num/mypow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				LCD_ShowChar(x+t*sizex,y,' ',fc,bc,sizey,0);
				continue;
			}else enshow=1; 
		 	 
		}
	 	LCD_ShowChar(x+t*sizex,y,temp+48,fc,bc,sizey,0);
	}
} 


/******************************************************************************
      函数说明：显示两位小数变量
      入口数据：x,y显示坐标
                num 要显示小数变量
                len 要显示的位数
                fc 字的颜色
                bc 字的背景色
                sizey 字号
      返回值：  无
******************************************************************************/
void LCD_ShowFloatNum1(uint16_t x, uint16_t y, float num, uint8_t len, uint16_t fc, uint16_t bc, uint8_t sizey)
{         	
	uint8_t t,temp,sizex;
	uint16_t num1;
	sizex=sizey/2;
	num1=num*100;
	for(t=0;t<len;t++)
	{
		temp=(num1/mypow(10,len-t-1))%10;
		if(t==(len-2))
		{
			LCD_ShowChar(x+(len-2)*sizex,y,'.',fc,bc,sizey,0);
			t++;
			len+=1;
		}
	 	LCD_ShowChar(x+t*sizex,y,temp+48,fc,bc,sizey,0);
	}
}


/******************************************************************************
      函数说明：显示图片
      入口数据：x,y起点坐标
                length 图片长度
                width  图片宽度
                pic[]  图片数组    
      返回值：  无
******************************************************************************/
void LCD_ShowPicture(uint16_t x, uint16_t y, uint16_t length, uint16_t width, const uint8_t pic[])
{
	uint16_t i,j;
	uint32_t k=0;
	LCD_Address_Set(x,y,x+length-1,y+width-1);
	for(i=0;i<length;i++)
	{
		for(j=0;j<width;j++)
		{
			LCD_Write_Data8(pic[k*2]);
			LCD_Write_Data8(pic[k*2+1]);
			k++;
		}
	}			
}
