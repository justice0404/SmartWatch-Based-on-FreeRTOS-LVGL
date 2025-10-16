/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *Home;
	bool Home_del;
	lv_obj_t *Home_cont_HomeBattery;
	lv_obj_t *Home_arc_HomeBattery;
	lv_obj_t *Home_label_HomeBatteryNum;
	lv_obj_t *Home_img_HomeBattery;
	lv_obj_t *Home_cont_HomeHeart;
	lv_obj_t *Home_arc_HomeHeart;
	lv_obj_t *Home_img_HomeHeart;
	lv_obj_t *Home_label_HomeHeartNum;
	lv_obj_t *Home_cont_HomeTemp;
	lv_obj_t *Home_arc_HomeTemp;
	lv_obj_t *Home_img_HomeTemp;
	lv_obj_t *Home_label_HomeTempNum;
	lv_obj_t *Home_cont_HomeHumidity;
	lv_obj_t *Home_arc_HomeHumidity;
	lv_obj_t *Home_img_HomeHumidity;
	lv_obj_t *Home_label_HomeHumiNum;
	lv_obj_t *Home_label_HomeMonth;
	lv_obj_t *Home_label_HomeMinute;
	lv_obj_t *Home_label_HomeWeekDay;
	lv_obj_t *Home_label_HomeIcon2;
	lv_obj_t *Home_label_HomeIcon1;
	lv_obj_t *Home_label_HomeDay;
	lv_obj_t *Home_label_HomeHour;
	lv_obj_t *Home_cont_HomeStep;
	lv_obj_t *Home_label_HomeStepnum;
	lv_obj_t *Home_label_HomeSteptext;
	lv_obj_t *Home_img_HomeStep;
	lv_obj_t *Home_bar_HomeStep;
	lv_obj_t *Home_cont_HomeTop;
	lv_obj_t *Home_slider_TopLight;
	lv_obj_t *Home_img_TopSetting;
	lv_obj_t *Home_img_TopPowerOff;
	lv_obj_t *Home_img_TopBT;
	lv_obj_t *Home_img_TopLight;
	lv_obj_t *Home_btn_TopBT;
	lv_obj_t *Home_btn_TopBT_label;
	lv_obj_t *Home_btn_TopSet;
	lv_obj_t *Home_btn_TopSet_label;
	lv_obj_t *Home_btn_TopPowerOff;
	lv_obj_t *Home_btn_TopPowerOff_label;
	lv_obj_t *Menu;
	bool Menu_del;
	lv_obj_t *Menu_cont_MenuSetting;
	lv_obj_t *Menu_img_MenuSetting;
	lv_obj_t *Menu_label_MenuSetting;
	lv_obj_t *Menu_cont_MenuGame;
	lv_obj_t *Menu_img_MenuGame;
	lv_obj_t *Menu_label_MenuGame;
	lv_obj_t *Menu_cont_MenuCompass;
	lv_obj_t *Menu_img_MenuCompass;
	lv_obj_t *Menu_label_MenuCompass;
	lv_obj_t *Menu_cont_MenuEnvironment;
	lv_obj_t *Menu_img_MenuEnvironment;
	lv_obj_t *Menu_label_MenuEnvironment;
	lv_obj_t *Menu_cont_MenuHeart;
	lv_obj_t *Menu_img_MenuHeart;
	lv_obj_t *Menu_label_MenuHeart;
	lv_obj_t *Menu_cont_MenuStopwatch;
	lv_obj_t *Menu_img_MenuStopwatch;
	lv_obj_t *Menu_label_MenuStopwatch;
	lv_obj_t *Menu_cont_MenuCalculator;
	lv_obj_t *Menu_label_MenuCalculator;
	lv_obj_t *Menu_img_MenuCalculater;
	lv_obj_t *Menu_cont_MenuCalendar;
	lv_obj_t *Menu_img_MenuCalender;
	lv_obj_t *Menu_label_MenuCalendar;
	lv_obj_t *Calender;
	bool Calender_del;
	lv_obj_t *Calender_calendar_1;
	lv_obj_t *Calculater;
	bool Calculater_del;
	lv_obj_t *Calculater_btnm_1;
	lv_obj_t *Stopwatch;
	bool Stopwatch_del;
	lv_obj_t *Stopwatch_meter_Stopwatch;
	lv_meter_scale_t *Stopwatch_meter_Stopwatch_scale_0;
	lv_obj_t *Stopwatch_btn_StopwatchStop;
	lv_obj_t *Stopwatch_btn_StopwatchStop_label;
	lv_obj_t *Stopwatch_btn_StopwatchReset;
	lv_obj_t *Stopwatch_btn_StopwatchReset_label;
	lv_obj_t *Stopwatch_label_StopwatchMinute;
	lv_obj_t *Stopwatch_label_StopwatchIcon2;
	lv_obj_t *Stopwatch_label_StopwatchSeconds;
	lv_obj_t *Stopwatch_label_StopwatchMs;
	lv_obj_t *Stopwatch_label_StopwatchIcon1;
	lv_obj_t *Heart;
	bool Heart_del;
	lv_obj_t *Heart_label_HeartCnt;
	lv_obj_t *Heart_label_HeartBPM;
	lv_obj_t *Heart_label_HeartText;
	lv_obj_t *Heart_img_HeartRate;
	lv_obj_t *Environment;
	bool Environment_del;
	lv_obj_t *Environment_cont_EnvTemperature;
	lv_obj_t *Environment_bar_EnvTemp;
	lv_obj_t *Environment_label_EnvTempNum;
	lv_obj_t *Environment_label_EnvIcon2;
	lv_obj_t *Environment_img_EnvSun;
	lv_obj_t *Environment_cont_EnvHumidity;
	lv_obj_t *Environment_bar_EnvHumi;
	lv_obj_t *Environment_label_EnvHmdiNum;
	lv_obj_t *Environment_label_EnvIcon1;
	lv_obj_t *Environment_img_EnvWater;
	lv_obj_t *Compass;
	bool Compass_del;
	lv_obj_t *Compass_meter_compass;
	lv_meter_scale_t *Compass_meter_compass_scale_0;
	lv_meter_indicator_t *Compass_meter_compass_scale_0_ndline_0;
	lv_obj_t *Compass_cont_ComCompass;
	lv_obj_t *Compass_img_ComCompass;
	lv_obj_t *Compass_label_ComIcon1;
	lv_obj_t *Compass_label_ComCompassNum;
	lv_obj_t *Compass_cont_CompAlti;
	lv_obj_t *Compass_img_ComAltitude;
	lv_obj_t *Compass_label_ComIcon2;
	lv_obj_t *Compass_label_ComAltitudeNum;
	lv_obj_t *Game;
	bool Game_del;
	lv_obj_t *Game_btn_Game;
	lv_obj_t *Game_btn_Game_label;
	lv_obj_t *Game_label_GameText;
	lv_obj_t *Setting;
	bool Setting_del;
	lv_obj_t *Setting_cont_SettingLightTime;
	lv_obj_t *Setting_img_SettingLight;
	lv_obj_t *Setting_label_SettingLight;
	lv_obj_t *Setting_cont_SettingOffTime;
	lv_obj_t *Setting_img_SettingOffTime;
	lv_obj_t *Setting_label_SettingOffTime;
	lv_obj_t *Setting_cont_SettingDateSet;
	lv_obj_t *Setting_img_SettingDateSet;
	lv_obj_t *Setting_label_SettingDateSet;
	lv_obj_t *Setting_cont_SettingWrist;
	lv_obj_t *Setting_img_SettingWrist;
	lv_obj_t *Setting_label_SettingWrist;
	lv_obj_t *Setting_sw_SettingWrist;
	lv_obj_t *SetLightTime;
	bool SetLightTime_del;
	lv_obj_t *SetLightTime_roller_SetLT;
	lv_obj_t *SetLightTime_img_SetLT;
	lv_obj_t *SetLightTime_label_SetLTIcon;
	lv_obj_t *SetLightTime_img_SetLTConfirm;
	lv_obj_t *SetLightTime_cont_SetLTConfirm;
	lv_obj_t *SetOffTime;
	bool SetOffTime_del;
	lv_obj_t *SetOffTime_roller_SetOT;
	lv_obj_t *SetOffTime_img_SetOT;
	lv_obj_t *SetOffTime_img_SetOTConfirm;
	lv_obj_t *SetOffTime_cont_SetOTConfirm;
	lv_obj_t *SetOffTime_label_SetOTIcon;
	lv_obj_t *SetDateTime;
	bool SetDateTime_del;
	lv_obj_t *SetDateTime_cont_SetDTBlue;
	lv_obj_t *SetDateTime_label_BlueTeeth;
	lv_obj_t *SetDateTime_sw_BT;
	lv_obj_t *SetDateTime_cont_SetDTSetDate;
	lv_obj_t *SetDateTime_label_SetDT2;
	lv_obj_t *SetDateTime_img_SetDT2;
	lv_obj_t *SetDateTime_cont_SetDTSetTime;
	lv_obj_t *SetDateTime_label_SetDT1;
	lv_obj_t *SetDateTime_img_SetDT1;
	lv_obj_t *SetDate;
	bool SetDate_del;
	lv_obj_t *SetDate_img_SetDateConfirm;
	lv_obj_t *SetDate_roller_SetDateYear;
	lv_obj_t *SetDate_cont_SetDateConfirm;
	lv_obj_t *SetDate_roller_SetDateMonth;
	lv_obj_t *SetDate_roller_SetDateDay;
	lv_obj_t *SetTime;
	bool SetTime_del;
	lv_obj_t *SetTime_roller_SetTimeHour;
	lv_obj_t *SetTime_roller_SetTimeMintue;
	lv_obj_t *SetTime_roller_SetTimeSecond;
	lv_obj_t *SetTime_label_SetTimeIcon1;
	lv_obj_t *SetTime_label_SetTimeIcon2;
	lv_obj_t *SetTime_img_SetTimeConfirm;
	lv_obj_t *SetTime_cont_SetTimeConfirm;
	lv_obj_t *PowerOff;
	bool PowerOff_del;
	lv_obj_t *PowerOff_slider_PowerOff;
	lv_obj_t *PowerOff_img_PowerOff;
	lv_obj_t *PowerOff_label_PowerOffText;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);

void init_keyboard(lv_ui *ui);

extern lv_ui guider_ui;


void setup_scr_Home(lv_ui *ui);
void setup_scr_Menu(lv_ui *ui);
void setup_scr_Calender(lv_ui *ui);
void setup_scr_Calculater(lv_ui *ui);
void setup_scr_Stopwatch(lv_ui *ui);
void setup_scr_Heart(lv_ui *ui);
void setup_scr_Environment(lv_ui *ui);
void setup_scr_Compass(lv_ui *ui);
void setup_scr_Game(lv_ui *ui);
void setup_scr_Setting(lv_ui *ui);
void setup_scr_SetLightTime(lv_ui *ui);
void setup_scr_SetOffTime(lv_ui *ui);
void setup_scr_SetDateTime(lv_ui *ui);
void setup_scr_SetDate(lv_ui *ui);
void setup_scr_SetTime(lv_ui *ui);
void setup_scr_PowerOff(lv_ui *ui);
LV_IMG_DECLARE(_battery_alpha_20x20);
LV_IMG_DECLARE(_1_alpha_25x25);
LV_IMG_DECLARE(_2_alpha_25x25);
LV_IMG_DECLARE(_7_alpha_25x25);
LV_IMG_DECLARE(_12_alpha_25x25);
LV_IMG_DECLARE(_setting_alpha_25x25);
LV_IMG_DECLARE(_power_alpha_25x25);
LV_IMG_DECLARE(_blueteeth_alpha_25x25);
LV_IMG_DECLARE(_10_alpha_30x30);
LV_IMG_DECLARE(_setting_alpha_30x30);
LV_IMG_DECLARE(_9_alpha_30x30);
LV_IMG_DECLARE(_3_alpha_30x30);
LV_IMG_DECLARE(_8_alpha_30x30);
LV_IMG_DECLARE(_1_alpha_30x30);
LV_IMG_DECLARE(_5_alpha_30x30);
LV_IMG_DECLARE(_4_alpha_30x30);
LV_IMG_DECLARE(_6_alpha_30x30);
LV_IMG_DECLARE(_start_alpha_30x30);
LV_IMG_DECLARE(_start1_alpha_30x30);
LV_IMG_DECLARE(_stop_alpha_30x30);
LV_IMG_DECLARE(_stop1_alpha_30x30);

LV_IMG_DECLARE(_reset_30x30);
LV_IMG_DECLARE(_1_alpha_30x30);
LV_IMG_DECLARE(_11_alpha_30x30);
LV_IMG_DECLARE(_7_alpha_30x30);
LV_IMG_DECLARE(_needle_alpha_30x70);
LV_IMG_DECLARE(_3_alpha_30x30);
LV_IMG_DECLARE(_altitude_alpha_30x30);
LV_IMG_DECLARE(_TurnOn_alpha_30x30);
LV_IMG_DECLARE(_TurnOff_alpha_30x30);
LV_IMG_DECLARE(_DateSet_alpha_30x30);
LV_IMG_DECLARE(_Wrist_alpha_30x30);
LV_IMG_DECLARE(_TurnOn_alpha_30x30);
LV_IMG_DECLARE(_confirm_alpha_30x30);
LV_IMG_DECLARE(_TurnOff_alpha_30x30);
LV_IMG_DECLARE(_confirm_alpha_30x30);
LV_IMG_DECLARE(_dotdot_alpha_20x20);
LV_IMG_DECLARE(_dotdot_alpha_20x20);
LV_IMG_DECLARE(_confirm_alpha_30x30);
LV_IMG_DECLARE(_confirm_alpha_30x30);
LV_IMG_DECLARE(_power_alpha_40x40);

LV_FONT_DECLARE(lv_font_montserratMedium_20)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_50)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_montserratMedium_25)
LV_FONT_DECLARE(lv_font_montserratMedium_30)


#ifdef __cplusplus
}
#endif
#endif
