#ifndef __CST816_H
#define __CST816_H

#include "stdint.h"
#include "MyI2C.h"
#include "delay.h"

/* CST816 dev pin defination */
#define TOUCH_RST_PIN GPIO_PIN_15
#define TOUCH_INT_PIN GPIO_PIN_1
#define TOUCH_RST_PORT GPIOA
#define TOUCH_INT_PORT GPIOB

/* functions define */
#define TOUCH_RST_0 HAL_GPIO_WritePin(TOUCH_RST_PORT, TOUCH_RST_PIN, GPIO_PIN_RESET)
#define TOUCH_RST_1 HAL_GPIO_WritePin(TOUCH_RST_PORT, TOUCH_RST_PIN, GPIO_PIN_SET)

/* 设备地址 */
#define Device_Addr 	0x15

/* 触摸屏寄存器 */
#define GestureID 			0x01
#define FingerNum 			0x02
#define XposH 				0x03
#define XposL 				0x04
#define YposH 				0x05
#define YposL 				0x06
#define ChipID 				0xA7
#define SleepMode			0xE5
#define MotionMask 			0xEC
#define IrqPluseWidth 		0xED
#define NorScanPer 			0xEE
#define MotionSlAngle 		0xEF
#define LpAutoWakeTime 		0xF4
#define LpScanTH 			0xF5
#define LpScanWin 			0xF6
#define LpScanFreq 			0xF7
#define LpScanIdac 			0xF8
#define AutoSleepTime 		0xF9
#define IrqCtl 				0xFA
#define AutoReset 			0xFB
#define LongPressTime 		0xFC
#define IOCtl 				0xFD
#define DisAutoSleep 		0xFE

/* 触摸屏坐标结构体 */
typedef struct
{
	unsigned int X_Pos;
	unsigned int Y_Pos;
} CST816_Info;

/* 手势ID识别选项 */
typedef enum
{
	NOGESTURE = 	0x00,	//无手势
	DOWNGLIDE = 	0x01,	//下滑
	UPGLIDE = 		0x02,	//上滑
	LEFTGLIDE = 	0x03,	//左滑
	RIGHTGLIDE = 	0x04,	//右滑
	CLICK = 		0x05,	//单击
	DOUBLECLICK = 	0x0B,	//双击
	LONGPRESS = 	0x0C,	//长按
} GestureID_TypeDef;

/* 连续动作配置选项 */
typedef enum
{
	M_DISABLE = 	0x00,	//关闭连续动作
	EnConLR = 		0x01,	//启用水平方向连续动作
	EnConUD = 		0x02,	//启用垂直方向连续动作
	EnDClick = 		0x03,	//启用双击识别
	M_ALLENABLE = 	0x07,  	//启用全部连续动作
} MotionMask_TypeDef;

/* 中断低脉冲发射方式选项 */
typedef enum
{
	OnceWLP = 		0x00,	//默认中断模式,每个触摸事件触发一次低脉冲中断
	EnMotion = 		0x10,	//运动检测中断,连续报告滑动/拖拽手势
	EnChange = 		0x20,	//状态变化中断,检测触摸状态变化（按下/抬起）
	EnTouch = 		0x40,	//触摸感应中断,提供高灵敏度的初始接触响应
	EnTest = 		0x80,	//测试模式中断,通常生成测试信号而非真实中断
} IrqCtl_TypeDef;


/* 触摸屏初始化相关函数 */
void CST816_GPIO_Init(void);
void CST816_RESET(void);
void CST816_Init(void);

/* 触摸屏操作函数 */
void CST816_Get_XY_AXIS(void);
uint8_t CST816_Get_ChipID(void);
uint8_t CST816_Get_FingerNum(void);

/* 触摸屏读写函数 */
void CST816_IIC_WriteREG(uint8_t addr, uint8_t dat);
uint8_t CST816_IIC_ReadREG(unsigned char addr);

/* 触摸屏有关参数配置函数 */
void CST816_Config_MotionMask(uint8_t mode);
void CST816_Config_AutoSleepTime(uint8_t time);
void CST816_Config_MotionSlAngle(uint8_t x_right_y_up_angle);
void CST816_Config_NorScanPer(uint8_t Period);
void CST816_Config_IrqPluseWidth(uint8_t Width);
void CST816_Config_LpScanTH(uint8_t TH);
void CST816_Wakeup(void);
void CST816_Sleep(void);

#endif
