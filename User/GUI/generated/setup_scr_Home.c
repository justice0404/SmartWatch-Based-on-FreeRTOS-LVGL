/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"
#include "PageManager.h"
#include "HWDataAccess.h"

/**************屏幕注册**************/
void deinit_scr_Home(void);
Page_t Page_Home  = {"Home",setup_scr_Home,deinit_scr_Home,&guider_ui.Home};


/**************变量管理**************/
//定时器
lv_timer_t * HomeTimer;
//时间日期
uint8_t ui_Minute = 30;
uint8_t ui_Hour = 11;
uint8_t ui_Day = 8;
uint8_t ui_Month = 11;
const char * ui_WeekDay[7] = {"MON","TUE","WED","THUR","FRI","SAT","SUN"};
uint8_t ui_WeedDayValue = 2;
//电量
uint8_t ui_BatValue = 70;
//温湿度
int8_t ui_TempValue = 25;
int8_t ui_HumiValue = 67;
//步数
uint16_t ui_StepNum = 500;
//
uint32_t cnt = 0;

/**************定时器回调函数**************/
static void HomeTimerHandler(lv_timer_t * timer)
{
	if(timer == NULL)
	{
		return;
	}
	
	lv_ui * ui = (lv_ui *)timer->user_data;
	char temp_str[10];
	
	if(ui->Home == NULL || !lv_obj_is_valid(ui->Home))
		return;
	
		/***********  RTC  **********/
		//获取
		HW_DateTimeTypeDef DateTime;
		HWInterface.RealTimeClock.GetTimeDate(&DateTime);
		//更新
		if(ui_Minute != DateTime.Minutes)
		{
			ui_Minute = DateTime.Minutes;
			sprintf(temp_str,"%02d",ui_Minute);
			lv_label_set_text(ui->Home_label_HomeMinute,temp_str);
			cnt++;
		}
		if(ui_Hour != DateTime.Hours)
		{
			ui_Hour = DateTime.Hours;
			sprintf(temp_str,"%2d",ui_Hour);
			lv_label_set_text(ui->Home_label_HomeHour,temp_str);
		}
		if(ui_Day != DateTime.Date)
		{
			ui_Day = DateTime.Date;
			ui_WeedDayValue = DateTime.WeekDay;
			sprintf(temp_str,"%02d",ui_Day);
			lv_label_set_text(ui->Home_label_HomeDay,temp_str);
			lv_label_set_text(ui->Home_label_HomeWeekDay,ui_WeekDay[ui_WeedDayValue-1]);
		}
		if(ui_Month != DateTime.Month)
		{
			ui_Month = DateTime.Month;
			sprintf(temp_str,"%2d",ui_Month);
			lv_label_set_text(ui->Home_label_HomeMonth,temp_str);
			
			ui_Day = DateTime.Date;
			ui_WeedDayValue = DateTime.WeekDay;
			sprintf(temp_str,"%02d",ui_Day);
			lv_label_set_text(ui->Home_label_HomeDay,temp_str);
			lv_label_set_text(ui->Home_label_HomeWeekDay,ui_WeekDay[ui_WeedDayValue-1]);
		}
		
		/***********  电量  **********/
		if(ui_BatValue != HWInterface.Power.power_remain)
		{
			ui_BatValue = HWInterface.Power.power_remain;
			//圆弧
			lv_arc_set_value(ui->Home_arc_HomeBattery,ui_BatValue);
			//标签
			sprintf(temp_str,"%02d",ui_BatValue);
			lv_label_set_text(ui->Home_label_HomeBatteryNum,temp_str);
		}
		
		/***********  温湿度  **********/
		if(ui_TempValue != HWInterface.AHT21.temperature)
		{
			ui_TempValue = HWInterface.AHT21.temperature;
			//圆弧
			lv_arc_set_value(ui->Home_arc_HomeTemp,ui_TempValue);
			//标签
			sprintf(temp_str,"%d",ui_TempValue);
			lv_label_set_text(ui->Home_label_HomeTempNum,temp_str);
		}
		
		if(ui_HumiValue != HWInterface.AHT21.humidity)
		{
			ui_HumiValue = HWInterface.AHT21.humidity;
			//圆弧
			lv_arc_set_value(ui->Home_arc_HomeHumidity,ui_HumiValue);
			//标签
			sprintf(temp_str,"%d",ui_HumiValue);
			lv_label_set_text(ui->Home_label_HomeHumiNum,temp_str);
		}
		
		//步数
		if(ui_StepNum != HWInterface.IMU.Steps)
		{
			ui_StepNum = HWInterface.IMU.Steps;
			//Bar
			lv_bar_set_value(ui->Home_bar_HomeStep,ui_StepNum,LV_ANIM_OFF);
			//Label
			sprintf(temp_str,"%d",ui_StepNum);
			lv_label_set_text(ui->Home_label_HomeStepnum,temp_str);
		}
	
}

void setup_scr_Home(lv_ui *ui)
{
    //Write codes Home
    ui->Home = lv_obj_create(NULL);
    lv_obj_set_size(ui->Home, 240, 280);
    lv_obj_set_scrollbar_mode(ui->Home, LV_SCROLLBAR_MODE_OFF);

    //Write style for Home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home, 216, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_cont_HomeBattery
    ui->Home_cont_HomeBattery = lv_obj_create(ui->Home);
    lv_obj_set_pos(ui->Home_cont_HomeBattery, 5, 30);
    lv_obj_set_size(ui->Home_cont_HomeBattery, 60, 75);
    lv_obj_set_scrollbar_mode(ui->Home_cont_HomeBattery, LV_SCROLLBAR_MODE_OFF);

    //Write style for Home_cont_HomeBattery, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cont_HomeBattery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cont_HomeBattery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cont_HomeBattery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cont_HomeBattery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cont_HomeBattery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cont_HomeBattery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cont_HomeBattery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cont_HomeBattery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_arc_HomeBattery
    ui->Home_arc_HomeBattery = lv_arc_create(ui->Home_cont_HomeBattery);
    lv_arc_set_mode(ui->Home_arc_HomeBattery, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->Home_arc_HomeBattery, 0, 100);
    lv_arc_set_bg_angles(ui->Home_arc_HomeBattery, 135, 45);
    lv_arc_set_value(ui->Home_arc_HomeBattery, 70);
    lv_arc_set_rotation(ui->Home_arc_HomeBattery, 0);
    lv_obj_set_style_arc_rounded(ui->Home_arc_HomeBattery, 0,  LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->Home_arc_HomeBattery, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->Home_arc_HomeBattery, -10, 0);
    lv_obj_set_size(ui->Home_arc_HomeBattery, 91, 75);

    //Write style for Home_arc_HomeBattery, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_arc_HomeBattery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Home_arc_HomeBattery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->Home_arc_HomeBattery, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Home_arc_HomeBattery, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Home_arc_HomeBattery, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_arc_HomeBattery, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_arc_HomeBattery, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_arc_HomeBattery, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_arc_HomeBattery, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_arc_HomeBattery, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_arc_HomeBattery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Home_arc_HomeBattery, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->Home_arc_HomeBattery, 4, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Home_arc_HomeBattery, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Home_arc_HomeBattery, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for Home_arc_HomeBattery, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_arc_HomeBattery, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->Home_arc_HomeBattery, 5, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes Home_label_HomeBatteryNum
    ui->Home_label_HomeBatteryNum = lv_label_create(ui->Home_cont_HomeBattery);
    lv_label_set_text(ui->Home_label_HomeBatteryNum, "86");
    lv_label_set_long_mode(ui->Home_label_HomeBatteryNum, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_HomeBatteryNum, 12, 55);
    lv_obj_set_size(ui->Home_label_HomeBatteryNum, 30, 20);

    //Write style for Home_label_HomeBatteryNum, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_HomeBatteryNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_HomeBatteryNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_HomeBatteryNum, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_HomeBatteryNum, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_HomeBatteryNum, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_HomeBatteryNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_HomeBatteryNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_HomeBatteryNum, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_HomeBatteryNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_HomeBatteryNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_HomeBatteryNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_HomeBatteryNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_HomeBatteryNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_HomeBatteryNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_img_HomeBattery
    ui->Home_img_HomeBattery = lv_img_create(ui->Home_cont_HomeBattery);
    lv_obj_add_flag(ui->Home_img_HomeBattery, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Home_img_HomeBattery, &_battery_alpha_20x20);
    lv_img_set_pivot(ui->Home_img_HomeBattery, 50,50);
    lv_img_set_angle(ui->Home_img_HomeBattery, 0);
    lv_obj_set_pos(ui->Home_img_HomeBattery, 17, 30);
    lv_obj_set_size(ui->Home_img_HomeBattery, 20, 20);

    //Write style for Home_img_HomeBattery, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Home_img_HomeBattery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Home_img_HomeBattery, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_img_HomeBattery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Home_img_HomeBattery, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_cont_HomeHeart
    ui->Home_cont_HomeHeart = lv_obj_create(ui->Home);
    lv_obj_set_pos(ui->Home_cont_HomeHeart, 0, 180);
    lv_obj_set_size(ui->Home_cont_HomeHeart, 80, 90);
    lv_obj_set_scrollbar_mode(ui->Home_cont_HomeHeart, LV_SCROLLBAR_MODE_OFF);

    //Write style for Home_cont_HomeHeart, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cont_HomeHeart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cont_HomeHeart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cont_HomeHeart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cont_HomeHeart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cont_HomeHeart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cont_HomeHeart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cont_HomeHeart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cont_HomeHeart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_arc_HomeHeart
    ui->Home_arc_HomeHeart = lv_arc_create(ui->Home_cont_HomeHeart);
    lv_arc_set_mode(ui->Home_arc_HomeHeart, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->Home_arc_HomeHeart, 50, 180);
    lv_arc_set_bg_angles(ui->Home_arc_HomeHeart, 270, 269);
    lv_arc_set_value(ui->Home_arc_HomeHeart, 120);
    lv_arc_set_rotation(ui->Home_arc_HomeHeart, 0);
    lv_obj_set_pos(ui->Home_arc_HomeHeart, -6, -10);
    lv_obj_set_size(ui->Home_arc_HomeHeart, 91, 105);

    //Write style for Home_arc_HomeHeart, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_arc_HomeHeart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Home_arc_HomeHeart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->Home_arc_HomeHeart, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Home_arc_HomeHeart, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Home_arc_HomeHeart, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_arc_HomeHeart, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_arc_HomeHeart, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_arc_HomeHeart, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_arc_HomeHeart, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_arc_HomeHeart, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_arc_HomeHeart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Home_arc_HomeHeart, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->Home_arc_HomeHeart, 4, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Home_arc_HomeHeart, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Home_arc_HomeHeart, lv_color_hex(0xd00420), LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for Home_arc_HomeHeart, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_arc_HomeHeart, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->Home_arc_HomeHeart, 0, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes Home_img_HomeHeart
    ui->Home_img_HomeHeart = lv_img_create(ui->Home_cont_HomeHeart);
    lv_obj_add_flag(ui->Home_img_HomeHeart, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Home_img_HomeHeart, &_1_alpha_25x25);
    lv_img_set_pivot(ui->Home_img_HomeHeart, 50,50);
    lv_img_set_angle(ui->Home_img_HomeHeart, 0);
    lv_obj_set_pos(ui->Home_img_HomeHeart, 27, 23);
    lv_obj_set_size(ui->Home_img_HomeHeart, 25, 25);

    //Write style for Home_img_HomeHeart, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Home_img_HomeHeart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Home_img_HomeHeart, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_img_HomeHeart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Home_img_HomeHeart, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_HomeHeartNum
    ui->Home_label_HomeHeartNum = lv_label_create(ui->Home_cont_HomeHeart);
    lv_label_set_text(ui->Home_label_HomeHeartNum, "120");
    lv_label_set_long_mode(ui->Home_label_HomeHeartNum, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_HomeHeartNum, 15, 65);
    lv_obj_set_size(ui->Home_label_HomeHeartNum, 50, 20);

    //Write style for Home_label_HomeHeartNum, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_HomeHeartNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_HomeHeartNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_HomeHeartNum, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_HomeHeartNum, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_HomeHeartNum, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_HomeHeartNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_HomeHeartNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_HomeHeartNum, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_HomeHeartNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_HomeHeartNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_HomeHeartNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_HomeHeartNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_HomeHeartNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_HomeHeartNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_cont_HomeTemp
    ui->Home_cont_HomeTemp = lv_obj_create(ui->Home);
    lv_obj_set_pos(ui->Home_cont_HomeTemp, 80, 180);
    lv_obj_set_size(ui->Home_cont_HomeTemp, 80, 90);
    lv_obj_set_scrollbar_mode(ui->Home_cont_HomeTemp, LV_SCROLLBAR_MODE_OFF);

    //Write style for Home_cont_HomeTemp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cont_HomeTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cont_HomeTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cont_HomeTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cont_HomeTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cont_HomeTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cont_HomeTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cont_HomeTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cont_HomeTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_arc_HomeTemp
    ui->Home_arc_HomeTemp = lv_arc_create(ui->Home_cont_HomeTemp);
    lv_arc_set_mode(ui->Home_arc_HomeTemp, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->Home_arc_HomeTemp, 0, 50);
    lv_arc_set_bg_angles(ui->Home_arc_HomeTemp, 270, 269);
    lv_arc_set_value(ui->Home_arc_HomeTemp, 26);
    lv_arc_set_rotation(ui->Home_arc_HomeTemp, 0);
    lv_obj_set_pos(ui->Home_arc_HomeTemp, -7, -10);
    lv_obj_set_size(ui->Home_arc_HomeTemp, 93, 108);

    //Write style for Home_arc_HomeTemp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_arc_HomeTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Home_arc_HomeTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->Home_arc_HomeTemp, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Home_arc_HomeTemp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Home_arc_HomeTemp, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_arc_HomeTemp, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_arc_HomeTemp, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_arc_HomeTemp, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_arc_HomeTemp, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_arc_HomeTemp, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_arc_HomeTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Home_arc_HomeTemp, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->Home_arc_HomeTemp, 4, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Home_arc_HomeTemp, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Home_arc_HomeTemp, lv_color_hex(0xf77414), LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for Home_arc_HomeTemp, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_arc_HomeTemp, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->Home_arc_HomeTemp, 0, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes Home_img_HomeTemp
    ui->Home_img_HomeTemp = lv_img_create(ui->Home_cont_HomeTemp);
    lv_obj_add_flag(ui->Home_img_HomeTemp, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Home_img_HomeTemp, &_2_alpha_25x25);
    lv_img_set_pivot(ui->Home_img_HomeTemp, 50,50);
    lv_img_set_angle(ui->Home_img_HomeTemp, 0);
    lv_obj_set_pos(ui->Home_img_HomeTemp, 27, 23);
    lv_obj_set_size(ui->Home_img_HomeTemp, 25, 25);

    //Write style for Home_img_HomeTemp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Home_img_HomeTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Home_img_HomeTemp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_img_HomeTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Home_img_HomeTemp, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_HomeTempNum
    ui->Home_label_HomeTempNum = lv_label_create(ui->Home_cont_HomeTemp);
    lv_label_set_text(ui->Home_label_HomeTempNum, "26");
    lv_label_set_long_mode(ui->Home_label_HomeTempNum, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_HomeTempNum, 15, 65);
    lv_obj_set_size(ui->Home_label_HomeTempNum, 50, 20);

    //Write style for Home_label_HomeTempNum, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_HomeTempNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_HomeTempNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_HomeTempNum, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_HomeTempNum, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_HomeTempNum, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_HomeTempNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_HomeTempNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_HomeTempNum, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_HomeTempNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_HomeTempNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_HomeTempNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_HomeTempNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_HomeTempNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_HomeTempNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_cont_HomeHumidity
    ui->Home_cont_HomeHumidity = lv_obj_create(ui->Home);
    lv_obj_set_pos(ui->Home_cont_HomeHumidity, 160, 180);
    lv_obj_set_size(ui->Home_cont_HomeHumidity, 80, 90);
    lv_obj_set_scrollbar_mode(ui->Home_cont_HomeHumidity, LV_SCROLLBAR_MODE_OFF);

    //Write style for Home_cont_HomeHumidity, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cont_HomeHumidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cont_HomeHumidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cont_HomeHumidity, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_cont_HomeHumidity, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_cont_HomeHumidity, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cont_HomeHumidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cont_HomeHumidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cont_HomeHumidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cont_HomeHumidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cont_HomeHumidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_arc_HomeHumidity
    ui->Home_arc_HomeHumidity = lv_arc_create(ui->Home_cont_HomeHumidity);
    lv_arc_set_mode(ui->Home_arc_HomeHumidity, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->Home_arc_HomeHumidity, 10, 90);
    lv_arc_set_bg_angles(ui->Home_arc_HomeHumidity, 270, 269);
    lv_arc_set_value(ui->Home_arc_HomeHumidity, 66);
    lv_arc_set_rotation(ui->Home_arc_HomeHumidity, 0);
    lv_obj_set_pos(ui->Home_arc_HomeHumidity, -7, -10);
    lv_obj_set_size(ui->Home_arc_HomeHumidity, 93, 108);

    //Write style for Home_arc_HomeHumidity, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_arc_HomeHumidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Home_arc_HomeHumidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->Home_arc_HomeHumidity, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Home_arc_HomeHumidity, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Home_arc_HomeHumidity, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_arc_HomeHumidity, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_arc_HomeHumidity, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_arc_HomeHumidity, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_arc_HomeHumidity, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_arc_HomeHumidity, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_arc_HomeHumidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Home_arc_HomeHumidity, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->Home_arc_HomeHumidity, 4, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Home_arc_HomeHumidity, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Home_arc_HomeHumidity, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for Home_arc_HomeHumidity, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_arc_HomeHumidity, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_arc_HomeHumidity, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_arc_HomeHumidity, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->Home_arc_HomeHumidity, 0, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes Home_img_HomeHumidity
    ui->Home_img_HomeHumidity = lv_img_create(ui->Home_cont_HomeHumidity);
    lv_obj_add_flag(ui->Home_img_HomeHumidity, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Home_img_HomeHumidity, &_7_alpha_25x25);
    lv_img_set_pivot(ui->Home_img_HomeHumidity, 50,50);
    lv_img_set_angle(ui->Home_img_HomeHumidity, 0);
    lv_obj_set_pos(ui->Home_img_HomeHumidity, 27, 23);
    lv_obj_set_size(ui->Home_img_HomeHumidity, 25, 25);

    //Write style for Home_img_HomeHumidity, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Home_img_HomeHumidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Home_img_HomeHumidity, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_img_HomeHumidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Home_img_HomeHumidity, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_HomeHumiNum
    ui->Home_label_HomeHumiNum = lv_label_create(ui->Home_cont_HomeHumidity);
    lv_label_set_text(ui->Home_label_HomeHumiNum, "66");
    lv_label_set_long_mode(ui->Home_label_HomeHumiNum, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_HomeHumiNum, 15, 65);
    lv_obj_set_size(ui->Home_label_HomeHumiNum, 50, 20);

    //Write style for Home_label_HomeHumiNum, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_HomeHumiNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_HomeHumiNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_HomeHumiNum, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_HomeHumiNum, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_HomeHumiNum, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_HomeHumiNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_HomeHumiNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_HomeHumiNum, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_HomeHumiNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_HomeHumiNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_HomeHumiNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_HomeHumiNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_HomeHumiNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_HomeHumiNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_HomeMonth
    ui->Home_label_HomeMonth = lv_label_create(ui->Home);
    lv_label_set_text(ui->Home_label_HomeMonth, "12");
    lv_label_set_long_mode(ui->Home_label_HomeMonth, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_HomeMonth, 65, 20);
    lv_obj_set_size(ui->Home_label_HomeMonth, 35, 25);

    //Write style for Home_label_HomeMonth, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_HomeMonth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_HomeMonth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_HomeMonth, lv_color_hex(0xd0d5d9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_HomeMonth, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_HomeMonth, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_HomeMonth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_HomeMonth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_HomeMonth, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_HomeMonth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_HomeMonth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_HomeMonth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_HomeMonth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_HomeMonth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_HomeMonth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_HomeMinute
    ui->Home_label_HomeMinute = lv_label_create(ui->Home);
    lv_label_set_text(ui->Home_label_HomeMinute, "30");
    lv_label_set_long_mode(ui->Home_label_HomeMinute, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_HomeMinute, 135, 51);
    lv_obj_set_size(ui->Home_label_HomeMinute, 90, 55);

    //Write style for Home_label_HomeMinute, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_HomeMinute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_HomeMinute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_HomeMinute, lv_color_hex(0xcb3c50), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_HomeMinute, &lv_font_montserratMedium_50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_HomeMinute, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_HomeMinute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_HomeMinute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_HomeMinute, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_HomeMinute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_HomeMinute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_HomeMinute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_HomeMinute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_HomeMinute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_HomeMinute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_HomeWeekDay
    ui->Home_label_HomeWeekDay = lv_label_create(ui->Home);
    lv_label_set_text(ui->Home_label_HomeWeekDay, "THUR");
    lv_label_set_long_mode(ui->Home_label_HomeWeekDay, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_HomeWeekDay, 134, 20);
    lv_obj_set_size(ui->Home_label_HomeWeekDay, 60, 25);

    //Write style for Home_label_HomeWeekDay, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_HomeWeekDay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_HomeWeekDay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_HomeWeekDay, lv_color_hex(0xd0d5d9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_HomeWeekDay, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_HomeWeekDay, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_HomeWeekDay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_HomeWeekDay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_HomeWeekDay, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_HomeWeekDay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_HomeWeekDay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_HomeWeekDay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_HomeWeekDay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_HomeWeekDay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_HomeWeekDay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_HomeIcon2
    ui->Home_label_HomeIcon2 = lv_label_create(ui->Home);
    lv_label_set_text(ui->Home_label_HomeIcon2, ":");
    lv_label_set_long_mode(ui->Home_label_HomeIcon2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_HomeIcon2, 125, 50);
    lv_obj_set_size(ui->Home_label_HomeIcon2, 10, 55);

    //Write style for Home_label_HomeIcon2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_HomeIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_HomeIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_HomeIcon2, lv_color_hex(0xcb3c50), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_HomeIcon2, &lv_font_montserratMedium_50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_HomeIcon2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_HomeIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_HomeIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_HomeIcon2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_HomeIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_HomeIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_HomeIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_HomeIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_HomeIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_HomeIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_HomeIcon1
    ui->Home_label_HomeIcon1 = lv_label_create(ui->Home);
    lv_label_set_text(ui->Home_label_HomeIcon1, "-");
    lv_label_set_long_mode(ui->Home_label_HomeIcon1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_HomeIcon1, 88, 20);
    lv_obj_set_size(ui->Home_label_HomeIcon1, 20, 21);

    //Write style for Home_label_HomeIcon1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_HomeIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_HomeIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_HomeIcon1, lv_color_hex(0xd0d5d9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_HomeIcon1, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_HomeIcon1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_HomeIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_HomeIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_HomeIcon1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_HomeIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_HomeIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_HomeIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_HomeIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_HomeIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_HomeIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_HomeDay
    ui->Home_label_HomeDay = lv_label_create(ui->Home);
    lv_label_set_text(ui->Home_label_HomeDay, "30");
    lv_label_set_long_mode(ui->Home_label_HomeDay, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_HomeDay, 100, 20);
    lv_obj_set_size(ui->Home_label_HomeDay, 35, 25);

    //Write style for Home_label_HomeDay, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_HomeDay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_HomeDay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_HomeDay, lv_color_hex(0xd0d5d9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_HomeDay, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_HomeDay, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_HomeDay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_HomeDay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_HomeDay, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_HomeDay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_HomeDay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_HomeDay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_HomeDay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_HomeDay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_HomeDay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_HomeHour
    ui->Home_label_HomeHour = lv_label_create(ui->Home);
    lv_label_set_text(ui->Home_label_HomeHour, "12");
    lv_label_set_long_mode(ui->Home_label_HomeHour, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_HomeHour, 65, 50);
    lv_obj_set_size(ui->Home_label_HomeHour, 50, 55);

    //Write style for Home_label_HomeHour, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_HomeHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_HomeHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_HomeHour, lv_color_hex(0xcb3c50), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_HomeHour, &lv_font_montserratMedium_50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_HomeHour, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_HomeHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_HomeHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_HomeHour, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_HomeHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_HomeHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_HomeHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_HomeHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_HomeHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_HomeHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_cont_HomeStep
    ui->Home_cont_HomeStep = lv_obj_create(ui->Home);
    lv_obj_set_pos(ui->Home_cont_HomeStep, 0, 115);
    lv_obj_set_size(ui->Home_cont_HomeStep, 240, 65);
    lv_obj_set_scrollbar_mode(ui->Home_cont_HomeStep, LV_SCROLLBAR_MODE_OFF);

    //Write style for Home_cont_HomeStep, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cont_HomeStep, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cont_HomeStep, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cont_HomeStep, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cont_HomeStep, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cont_HomeStep, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cont_HomeStep, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cont_HomeStep, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cont_HomeStep, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_HomeStepnum
    ui->Home_label_HomeStepnum = lv_label_create(ui->Home_cont_HomeStep);
    lv_label_set_text(ui->Home_label_HomeStepnum, "3241");
    lv_label_set_long_mode(ui->Home_label_HomeStepnum, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_HomeStepnum, 30, 27);
    lv_obj_set_size(ui->Home_label_HomeStepnum, 60, 20);

    //Write style for Home_label_HomeStepnum, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_HomeStepnum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_HomeStepnum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_HomeStepnum, lv_color_hex(0xd7d3d3), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_HomeStepnum, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_HomeStepnum, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_HomeStepnum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_HomeStepnum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_HomeStepnum, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_HomeStepnum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_HomeStepnum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_HomeStepnum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_HomeStepnum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_HomeStepnum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_HomeStepnum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_HomeSteptext
    ui->Home_label_HomeSteptext = lv_label_create(ui->Home_cont_HomeStep);
    lv_label_set_text(ui->Home_label_HomeSteptext, "Step");
    lv_label_set_long_mode(ui->Home_label_HomeSteptext, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_HomeSteptext, 50, 3);
    lv_obj_set_size(ui->Home_label_HomeSteptext, 80, 25);

    //Write style for Home_label_HomeSteptext, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_HomeSteptext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_HomeSteptext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_HomeSteptext, lv_color_hex(0x74c679), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_HomeSteptext, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_HomeSteptext, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_HomeSteptext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_HomeSteptext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_HomeSteptext, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_HomeSteptext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_HomeSteptext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_HomeSteptext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_HomeSteptext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_HomeSteptext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_HomeSteptext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_img_HomeStep
    ui->Home_img_HomeStep = lv_img_create(ui->Home_cont_HomeStep);
    lv_obj_add_flag(ui->Home_img_HomeStep, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Home_img_HomeStep, &_12_alpha_25x25);
    lv_img_set_pivot(ui->Home_img_HomeStep, 50,50);
    lv_img_set_angle(ui->Home_img_HomeStep, 0);
    lv_obj_set_pos(ui->Home_img_HomeStep, 30, 0);
    lv_obj_set_size(ui->Home_img_HomeStep, 25, 25);

    //Write style for Home_img_HomeStep, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Home_img_HomeStep, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Home_img_HomeStep, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_img_HomeStep, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Home_img_HomeStep, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_bar_HomeStep
    ui->Home_bar_HomeStep = lv_bar_create(ui->Home_cont_HomeStep);
    lv_obj_set_style_anim_time(ui->Home_bar_HomeStep, 1000, 0);
    lv_bar_set_mode(ui->Home_bar_HomeStep, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->Home_bar_HomeStep, 0, 10000);
    lv_bar_set_value(ui->Home_bar_HomeStep, 3241, LV_ANIM_OFF);
    lv_obj_set_pos(ui->Home_bar_HomeStep, 20, 50);
    lv_obj_set_size(ui->Home_bar_HomeStep, 200, 10);

    //Write style for Home_bar_HomeStep, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_bar_HomeStep, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_bar_HomeStep, lv_color_hex(0x74c679), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_bar_HomeStep, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_bar_HomeStep, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_bar_HomeStep, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Home_bar_HomeStep, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_bar_HomeStep, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_bar_HomeStep, lv_color_hex(0x74c679), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_bar_HomeStep, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_bar_HomeStep, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes Home_cont_HomeTop
    ui->Home_cont_HomeTop = lv_obj_create(ui->Home);
    lv_obj_set_pos(ui->Home_cont_HomeTop, 0, -125);
    lv_obj_set_size(ui->Home_cont_HomeTop, 240, 120);
    lv_obj_set_scrollbar_mode(ui->Home_cont_HomeTop, LV_SCROLLBAR_MODE_OFF);

    //Write style for Home_cont_HomeTop, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cont_HomeTop, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Home_cont_HomeTop, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Home_cont_HomeTop, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->Home_cont_HomeTop, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cont_HomeTop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cont_HomeTop, 247, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_cont_HomeTop, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_cont_HomeTop, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cont_HomeTop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cont_HomeTop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cont_HomeTop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cont_HomeTop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cont_HomeTop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_slider_TopLight
    ui->Home_slider_TopLight = lv_slider_create(ui->Home_cont_HomeTop);
    lv_slider_set_range(ui->Home_slider_TopLight, 0, 100);
    lv_slider_set_mode(ui->Home_slider_TopLight, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->Home_slider_TopLight, 55, LV_ANIM_OFF);
    lv_obj_set_pos(ui->Home_slider_TopLight, 48, 75);
    lv_obj_set_size(ui->Home_slider_TopLight, 180, 20);
    lv_obj_add_flag(ui->Home_slider_TopLight, LV_OBJ_FLAG_PRESS_LOCK);

    //Write style for Home_slider_TopLight, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_slider_TopLight, 48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_slider_TopLight, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_slider_TopLight, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_slider_TopLight, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->Home_slider_TopLight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_slider_TopLight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Home_slider_TopLight, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_slider_TopLight, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_slider_TopLight, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_slider_TopLight, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_slider_TopLight, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for Home_slider_TopLight, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_slider_TopLight, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_slider_TopLight, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes Home_img_TopSetting
    ui->Home_img_TopSetting = lv_img_create(ui->Home_cont_HomeTop);
    lv_obj_add_flag(ui->Home_img_TopSetting, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Home_img_TopSetting, &_setting_alpha_25x25);
    lv_img_set_pivot(ui->Home_img_TopSetting, 50,50);
    lv_img_set_angle(ui->Home_img_TopSetting, 0);
    lv_obj_set_pos(ui->Home_img_TopSetting, 45, 25);
    lv_obj_set_size(ui->Home_img_TopSetting, 25, 25);

    //Write style for Home_img_TopSetting, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Home_img_TopSetting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Home_img_TopSetting, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_img_TopSetting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Home_img_TopSetting, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_img_TopPowerOff
    ui->Home_img_TopPowerOff = lv_img_create(ui->Home_cont_HomeTop);
    lv_obj_add_flag(ui->Home_img_TopPowerOff, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Home_img_TopPowerOff, &_power_alpha_25x25);
    lv_img_set_pivot(ui->Home_img_TopPowerOff, 50,50);
    lv_img_set_angle(ui->Home_img_TopPowerOff, 0);
    lv_obj_set_pos(ui->Home_img_TopPowerOff, 176, 25);
    lv_obj_set_size(ui->Home_img_TopPowerOff, 25, 25);

    //Write style for Home_img_TopPowerOff, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Home_img_TopPowerOff, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Home_img_TopPowerOff, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_img_TopPowerOff, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Home_img_TopPowerOff, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_img_TopBT
    ui->Home_img_TopBT = lv_img_create(ui->Home_cont_HomeTop);
    lv_obj_add_flag(ui->Home_img_TopBT, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Home_img_TopBT, &_blueteeth_alpha_25x25);
    lv_img_set_pivot(ui->Home_img_TopBT, 50,50);
    lv_img_set_angle(ui->Home_img_TopBT, 0);
    lv_obj_set_pos(ui->Home_img_TopBT, 109, 25);
    lv_obj_set_size(ui->Home_img_TopBT, 25, 25);

    //Write style for Home_img_TopBT, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Home_img_TopBT, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Home_img_TopBT, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_img_TopBT, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Home_img_TopBT, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_img_TopLight
    ui->Home_img_TopLight = lv_img_create(ui->Home_cont_HomeTop);
    lv_obj_add_flag(ui->Home_img_TopLight, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Home_img_TopLight, &_10_alpha_30x30);
    lv_img_set_pivot(ui->Home_img_TopLight, 50,50);
    lv_img_set_angle(ui->Home_img_TopLight, 0);
    lv_obj_set_pos(ui->Home_img_TopLight, 13, 70);
    lv_obj_set_size(ui->Home_img_TopLight, 30, 30);

    //Write style for Home_img_TopLight, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Home_img_TopLight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Home_img_TopLight, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_img_TopLight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Home_img_TopLight, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_btn_TopBT
    ui->Home_btn_TopBT = lv_btn_create(ui->Home_cont_HomeTop);
    ui->Home_btn_TopBT_label = lv_label_create(ui->Home_btn_TopBT);
    lv_label_set_text(ui->Home_btn_TopBT_label, "");
    lv_label_set_long_mode(ui->Home_btn_TopBT_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Home_btn_TopBT_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Home_btn_TopBT, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Home_btn_TopBT_label, LV_PCT(100));
    lv_obj_set_pos(ui->Home_btn_TopBT, 105, 20);
    lv_obj_set_size(ui->Home_btn_TopBT, 35, 35);

    //Write style for Home_btn_TopBT, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_btn_TopBT, 181, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_btn_TopBT, lv_color_hex(0x6f6d6d), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_btn_TopBT, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Home_btn_TopBT, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_btn_TopBT, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_btn_TopBT, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_btn_TopBT, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_btn_TopBT, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_btn_TopBT, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_btn_TopBT, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_btn_TopSet
    ui->Home_btn_TopSet = lv_btn_create(ui->Home_cont_HomeTop);
    ui->Home_btn_TopSet_label = lv_label_create(ui->Home_btn_TopSet);
    lv_label_set_text(ui->Home_btn_TopSet_label, "");
    lv_label_set_long_mode(ui->Home_btn_TopSet_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Home_btn_TopSet_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Home_btn_TopSet, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Home_btn_TopSet_label, LV_PCT(100));
    lv_obj_set_pos(ui->Home_btn_TopSet, 40, 20);
    lv_obj_set_size(ui->Home_btn_TopSet, 35, 35);

    //Write style for Home_btn_TopSet, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_btn_TopSet, 181, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_btn_TopSet, lv_color_hex(0x6f6d6d), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_btn_TopSet, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Home_btn_TopSet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_btn_TopSet, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_btn_TopSet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_btn_TopSet, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_btn_TopSet, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_btn_TopSet, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_btn_TopSet, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_btn_TopPowerOff
    ui->Home_btn_TopPowerOff = lv_btn_create(ui->Home_cont_HomeTop);
    ui->Home_btn_TopPowerOff_label = lv_label_create(ui->Home_btn_TopPowerOff);
    lv_label_set_text(ui->Home_btn_TopPowerOff_label, "");
    lv_label_set_long_mode(ui->Home_btn_TopPowerOff_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Home_btn_TopPowerOff_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Home_btn_TopPowerOff, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Home_btn_TopPowerOff_label, LV_PCT(100));
    lv_obj_set_pos(ui->Home_btn_TopPowerOff, 170, 20);
    lv_obj_set_size(ui->Home_btn_TopPowerOff, 35, 35);

    //Write style for Home_btn_TopPowerOff, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_btn_TopPowerOff, 181, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_btn_TopPowerOff, lv_color_hex(0x6f6d6d), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_btn_TopPowerOff, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Home_btn_TopPowerOff, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_btn_TopPowerOff, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_btn_TopPowerOff, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_btn_TopPowerOff, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_btn_TopPowerOff, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_btn_TopPowerOff, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_btn_TopPowerOff, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Home.
	HomeTimer = lv_timer_create(HomeTimerHandler,300,ui);
	
    //Update current screen layout.
    lv_obj_update_layout(ui->Home);

    //Init events for screen.
    events_init_Home(ui);
}

void deinit_scr_Home(void)
{
	if(HomeTimer != NULL)
	{
		lv_timer_del(HomeTimer);
		HomeTimer = NULL;
	}
	
	guider_ui.Home = NULL;
    guider_ui.Home_cont_HomeBattery = NULL;
    guider_ui.Home_arc_HomeBattery = NULL;
    guider_ui.Home_label_HomeBatteryNum = NULL;
    guider_ui.Home_img_HomeBattery = NULL;
    guider_ui.Home_cont_HomeHeart = NULL;
    guider_ui.Home_arc_HomeHeart = NULL;
    guider_ui.Home_img_HomeHeart = NULL;
    guider_ui.Home_label_HomeHeartNum = NULL;
    guider_ui.Home_cont_HomeTemp = NULL;
    guider_ui.Home_arc_HomeTemp = NULL;
    guider_ui.Home_img_HomeTemp = NULL;
    guider_ui.Home_label_HomeTempNum = NULL;
    guider_ui.Home_cont_HomeHumidity = NULL;
    guider_ui.Home_arc_HomeHumidity = NULL;
    guider_ui.Home_img_HomeHumidity = NULL;
    guider_ui.Home_label_HomeHumiNum = NULL;
    guider_ui.Home_label_HomeMonth = NULL;
    guider_ui.Home_label_HomeMinute = NULL;
    guider_ui.Home_label_HomeWeekDay = NULL;
    guider_ui.Home_label_HomeIcon1 = NULL;
    guider_ui.Home_label_HomeIcon2 = NULL;
    guider_ui.Home_label_HomeDay = NULL;
    guider_ui.Home_label_HomeHour = NULL;
    guider_ui.Home_cont_HomeStep = NULL;
    guider_ui.Home_label_HomeStepnum = NULL;
    guider_ui.Home_label_HomeSteptext = NULL;
    guider_ui.Home_img_HomeStep = NULL;
    guider_ui.Home_bar_HomeStep = NULL;
    guider_ui.Home_cont_HomeTop = NULL;
    guider_ui.Home_slider_TopLight = NULL;
    guider_ui.Home_img_TopSetting = NULL;
    guider_ui.Home_img_TopPowerOff = NULL;
    guider_ui.Home_img_TopBT = NULL;
    guider_ui.Home_img_TopLight = NULL;
    guider_ui.Home_btn_TopBT = NULL;
    guider_ui.Home_btn_TopBT_label = NULL;
    guider_ui.Home_btn_TopSet = NULL;
    guider_ui.Home_btn_TopSet_label = NULL;
    guider_ui.Home_btn_TopPowerOff = NULL;
    guider_ui.Home_btn_TopPowerOff_label = NULL;
}
