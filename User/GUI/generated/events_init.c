/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"
#include "PageManager.h"
#include "HWDataAccess.h"
#include "custom.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif


static void Home_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
	lv_ui * ui = (lv_ui *)lv_event_get_user_data(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        lv_obj_clear_flag(guider_ui.Home_arc_HomeTemp, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_clear_flag(guider_ui.Home_arc_HomeHeart, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_clear_flag(guider_ui.Home_arc_HomeBattery, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_clear_flag(guider_ui.Home_arc_HomeHumidity, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_clear_flag(guider_ui.Home_cont_HomeStep, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_clear_flag(guider_ui.Home_cont_HomeHumidity, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_clear_flag(guider_ui.Home_cont_HomeTemp, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_clear_flag(guider_ui.Home_cont_HomeHeart, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_clear_flag(guider_ui.Home_cont_HomeBattery, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_BOTTOM:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_animation(guider_ui.Home_cont_HomeTop, 100, 0, lv_obj_get_x(guider_ui.Home_cont_HomeTop), 0, &lv_anim_path_linear, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
            ui_animation(guider_ui.Home_cont_HomeTop, 100, 0, lv_obj_get_y(guider_ui.Home_cont_HomeTop), 0, &lv_anim_path_linear, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
            break;
        }
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_animation(guider_ui.Home_cont_HomeTop, 100, 0, lv_obj_get_x(guider_ui.Home_cont_HomeTop), 0, &lv_anim_path_linear, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
            ui_animation(guider_ui.Home_cont_HomeTop, 100, 0, lv_obj_get_y(guider_ui.Home_cont_HomeTop), -125, &lv_anim_path_linear, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
            break;
        }
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            //ui_load_scr_animation(&guider_ui, &guider_ui.Menu, guider_ui.Menu_del, &guider_ui.Home_del, setup_scr_Menu, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true, false);
			Page_Load(ui,&Page_Menu);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void Home_btn_TopBT_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_set_style_bg_color(guider_ui.Home_btn_TopBT, lv_color_hex(0x2195f6), LV_PART_MAIN);
        break;
    }
    default:
        break;
    }
}

static void Home_btn_TopSet_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        //ui_load_scr_animation(&guider_ui, &guider_ui.Setting, guider_ui.Setting_del, &guider_ui.Home_del, setup_scr_Setting, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
		Page_Load(&guider_ui,&Page_Setting);
        break;
    }
    default:
        break;
    }
}

static void Home_btn_TopPowerOff_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        //ui_load_scr_animation(&guider_ui, &guider_ui.PowerOff, guider_ui.PowerOff_del, &guider_ui.Home_del, setup_scr_PowerOff, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
		Page_Load(&guider_ui,&Page_PowerOff);
        break;
    }
    default:
        break;
    }
}

static void Home_slider_TopLight_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
		ui_LightSliderValue = lv_slider_get_value(guider_ui.Home_slider_TopLight);
		HWInterface.LCD.SetLight(ui_LightSliderValue);
        break;
    }
    default:
        break;
    }
}

void events_init_Home (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->Home, Home_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Home_btn_TopBT, Home_btn_TopBT_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Home_btn_TopSet, Home_btn_TopSet_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Home_btn_TopPowerOff, Home_btn_TopPowerOff_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Home_slider_TopLight, Home_slider_TopLight_event_handler, LV_EVENT_ALL, ui);
}

static void Menu_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
	lv_ui * ui = (lv_ui *)lv_event_get_user_data(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            //ui_load_scr_animation(&guider_ui, &guider_ui.Home, guider_ui.Home_del, &guider_ui.Menu_del, setup_scr_Home, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, false, true);
			Page_Back(ui);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void Menu_cont_MenuSetting_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
		Page_Load(&guider_ui,&Page_Setting);
        //ui_load_scr_animation(&guider_ui, &guider_ui.Setting, guider_ui.Setting_del, &guider_ui.Menu_del, setup_scr_Setting, LV_SCR_LOAD_ANIM_NONE, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void Menu_cont_MenuGame_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
		Page_Load(&guider_ui,&Page_Game);
        //ui_load_scr_animation(&guider_ui, &guider_ui.Game, guider_ui.Game_del, &guider_ui.Menu_del, setup_scr_Game, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void Menu_cont_MenuCompass_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
		Page_Load(&guider_ui,&Page_Compass);
        //ui_load_scr_animation(&guider_ui, &guider_ui.Compass, guider_ui.Compass_del, &guider_ui.Menu_del, setup_scr_Compass, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void Menu_cont_MenuEnvironment_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
		Page_Load(&guider_ui,&Page_Environment);
        //ui_load_scr_animation(&guider_ui, &guider_ui.Environment, guider_ui.Environment_del, &guider_ui.Menu_del, setup_scr_Environment, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void Menu_cont_MenuHeart_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
		Page_Load(&guider_ui,&Page_Heart);
        //ui_load_scr_animation(&guider_ui, &guider_ui.Heart, guider_ui.Heart_del, &guider_ui.Menu_del, setup_scr_Heart, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void Menu_cont_MenuStopwatch_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
		Page_Load(&guider_ui,&Page_Stopwatch);
        //ui_load_scr_animation(&guider_ui, &guider_ui.Stopwatch, guider_ui.Stopwatch_del, &guider_ui.Menu_del, setup_scr_Stopwatch, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void Menu_cont_MenuCalculator_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
		Page_Load(&guider_ui,&Page_Calculater);
        //ui_load_scr_animation(&guider_ui, &guider_ui.Calculater, guider_ui.Calculater_del, &guider_ui.Menu_del, setup_scr_Calculater, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void Menu_cont_MenuCalendar_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
		Page_Load(&guider_ui,&Page_Calender);
        //ui_load_scr_animation(&guider_ui, &guider_ui.Calender, guider_ui.Calender_del, &guider_ui.Menu_del, setup_scr_Calender, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_Menu (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->Menu, Menu_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Menu_cont_MenuSetting, Menu_cont_MenuSetting_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Menu_cont_MenuGame, Menu_cont_MenuGame_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Menu_cont_MenuCompass, Menu_cont_MenuCompass_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Menu_cont_MenuEnvironment, Menu_cont_MenuEnvironment_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Menu_cont_MenuHeart, Menu_cont_MenuHeart_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Menu_cont_MenuStopwatch, Menu_cont_MenuStopwatch_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Menu_cont_MenuCalculator, Menu_cont_MenuCalculator_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Menu_cont_MenuCalendar, Menu_cont_MenuCalendar_event_handler, LV_EVENT_ALL, ui);
}

static void Stopwatch_btn_StopwatchStop_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t * target = lv_event_get_target(e);
//    switch (code) {
//    case LV_EVENT_PRESSED:
//    {
//        lv_label_set_text(guider_ui.Stopwatch_label_StopwatchMinute, "01");
//        break;
//    }
//    case LV_EVENT_VALUE_CHANGED:
//    {
//        lv_label_set_text(guider_ui.Stopwatch_label_StopwatchSeconds, "01");
//        break;
//    }
//    default:
//        break;
//    }
	if(code == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(target,LV_STATE_CHECKED))
	{
		//按下
		ui_StopWatch_Flag = 1;
		lv_timer_resume(ui_StopWatchTimer);
	}
	
	if(code == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(target,LV_STATE_CHECKED))
	{
		//放开
		ui_StopWatch_Flag = 0;
		lv_timer_pause(ui_StopWatchTimer);
	}
}

static void Stopwatch_btn_StopwatchReset_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
		if(ui_StopWatch_Flag != 1)
		{
			lv_label_set_text(guider_ui.Stopwatch_label_StopwatchMinute, "00");
			lv_label_set_text(guider_ui.Stopwatch_label_StopwatchSeconds, "00");
			lv_label_set_text(guider_ui.Stopwatch_label_StopwatchMs, "00");
			ui_StopWatch_Min = 0;
			ui_StopWatch_Sec = 0;
			ui_StopWatch_10Ms = 0;
			ui_StopWatch_Ms = 0;
		}
        break;
    }
    default:
        break;
    }
}

void events_init_Stopwatch (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->Stopwatch_btn_StopwatchStop, Stopwatch_btn_StopwatchStop_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Stopwatch_btn_StopwatchReset, Stopwatch_btn_StopwatchReset_event_handler, LV_EVENT_ALL, ui);
}

static void Game_btn_Game_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
		Page_Back_Bottom(&guider_ui);
        //ui_load_scr_animation(&guider_ui, &guider_ui.Home, guider_ui.Home_del, &guider_ui.Game_del, setup_scr_Home, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_Game (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->Game_btn_Game, Game_btn_Game_event_handler, LV_EVENT_ALL, ui);
}

static void Setting_cont_SettingLightTime_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
		Page_Load(&guider_ui,&Page_SetLightTime);
        //ui_load_scr_animation(&guider_ui, &guider_ui.SetLightTime, guider_ui.SetLightTime_del, &guider_ui.Setting_del, setup_scr_SetLightTime, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void Setting_cont_SettingOffTime_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
		Page_Load(&guider_ui,&Page_SetOffTime);
        //ui_load_scr_animation(&guider_ui, &guider_ui.SetOffTime, guider_ui.SetOffTime_del, &guider_ui.Setting_del, setup_scr_SetOffTime, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void Setting_cont_SettingDateSet_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
		Page_Load(&guider_ui,&Page_SetDateTime);
        //ui_load_scr_animation(&guider_ui, &guider_ui.SetDateTime, guider_ui.SetDateTime_del, &guider_ui.Setting_del, setup_scr_SetDateTime, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void Setting_sw_SettingWrist_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESS_LOST:
    {
        lv_obj_t * status_obj = lv_event_get_target(e);
        int status = lv_obj_has_state(status_obj, LV_STATE_CHECKED) ? true : false;

        break;
    }
    default:
        break;
    }
}

void events_init_Setting (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->Setting_cont_SettingLightTime, Setting_cont_SettingLightTime_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Setting_cont_SettingOffTime, Setting_cont_SettingOffTime_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Setting_cont_SettingDateSet, Setting_cont_SettingDateSet_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Setting_sw_SettingWrist, Setting_sw_SettingWrist_event_handler, LV_EVENT_ALL, ui);
}

static void SetLightTime_cont_SetLTConfirm_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
	lv_ui * ui = lv_event_get_user_data(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
		ui_LightTimeSelected = lv_roller_get_selected(ui->SetLightTime_roller_SetLT);
		ui_LightTimeVale = ui_LTimeOptions[ui_LightTimeSelected];
		Page_Back(&guider_ui);
        //ui_load_scr_animation(&guider_ui, &guider_ui.Setting, guider_ui.Setting_del, &guider_ui.SetLightTime_del, setup_scr_Setting, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_SetLightTime (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->SetLightTime_cont_SetLTConfirm, SetLightTime_cont_SetLTConfirm_event_handler, LV_EVENT_ALL, ui);
}

static void SetOffTime_img_SetOTConfirm_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        //ui_load_scr_animation(&guider_ui, &guider_ui.Setting, guider_ui.Setting_del, &guider_ui.SetOffTime_del, setup_scr_Setting, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void SetOffTime_cont_SetOTConfirm_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
	lv_ui * ui = lv_event_get_user_data(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
		ui_OffTimeSelected = lv_roller_get_selected(ui->SetOffTime_roller_SetOT);
		ui_OffTimeVale = ui_OTimeOptions[ui_OffTimeSelected];
		Page_Back(&guider_ui);
        //ui_load_scr_animation(&guider_ui, &guider_ui.Setting, guider_ui.Setting_del, &guider_ui.SetOffTime_del, setup_scr_Setting, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_SetOffTime (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->SetOffTime_img_SetOTConfirm, SetOffTime_img_SetOTConfirm_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->SetOffTime_cont_SetOTConfirm, SetOffTime_cont_SetOTConfirm_event_handler, LV_EVENT_ALL, ui);
}

static void SetDateTime_sw_BT_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        lv_obj_t * status_obj = lv_event_get_target(e);
        int status = lv_obj_has_state(status_obj, LV_STATE_CHECKED) ? true : false;
		Page_Back_Bottom(&guider_ui);
        //ui_load_scr_animation(&guider_ui, &guider_ui.Home, guider_ui.Home_del, &guider_ui.SetDateTime_del, setup_scr_Home, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void SetDateTime_cont_SetDTSetDate_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
		Page_Load(&guider_ui,&Page_SetDate);
        //ui_load_scr_animation(&guider_ui, &guider_ui.SetDate, guider_ui.SetDate_del, &guider_ui.SetDateTime_del, setup_scr_SetDate, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void SetDateTime_cont_SetDTSetTime_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
		Page_Load(&guider_ui,&Page_SetTime);
        //ui_load_scr_animation(&guider_ui, &guider_ui.SetTime, guider_ui.SetTime_del, &guider_ui.SetDateTime_del, setup_scr_SetTime, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_SetDateTime (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->SetDateTime_sw_BT, SetDateTime_sw_BT_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->SetDateTime_cont_SetDTSetDate, SetDateTime_cont_SetDTSetDate_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->SetDateTime_cont_SetDTSetTime, SetDateTime_cont_SetDTSetTime_event_handler, LV_EVENT_ALL, ui);
}

static void SetDate_cont_SetDateConfirm_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
		//获取
		uint8_t setyear = lv_roller_get_selected(guider_ui.SetDate_roller_SetDateYear);
		uint8_t setmonth = lv_roller_get_selected(guider_ui.SetDate_roller_SetDateMonth);
		uint8_t setday = lv_roller_get_selected(guider_ui.SetDate_roller_SetDateDay);
		//更新
		HWInterface.RealTimeClock.SetDate(setyear,setmonth,setday);
		ui_Month = setmonth;
		ui_Day = setday;
		ui_WeedDayValue = HWInterface.RealTimeClock.CalculateWeekday(setyear,setmonth,setday,20);
		//退出
		Page_Back(&guider_ui);
        //ui_load_scr_animation(&guider_ui, &guider_ui.SetDateTime, guider_ui.SetDateTime_del, &guider_ui.SetDate_del, setup_scr_SetDateTime, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_SetDate (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->SetDate_cont_SetDateConfirm, SetDate_cont_SetDateConfirm_event_handler, LV_EVENT_ALL, ui);
}

static void SetTime_cont_SetTimeConfirm_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
		//获取
		uint8_t sethour = lv_roller_get_selected(guider_ui.SetTime_roller_SetTimeHour);
		uint8_t setmin = lv_roller_get_selected(guider_ui.SetTime_roller_SetTimeMintue);
		uint8_t setsec = lv_roller_get_selected(guider_ui.SetTime_roller_SetTimeSecond);
		
		//更新
		HWInterface.RealTimeClock.SetTime(sethour,setmin,setsec);
		ui_Hour = sethour;
		ui_Minute = setmin;
		
		//退出
		Page_Back(&guider_ui);
        //ui_load_scr_animation(&guider_ui, &guider_ui.SetDateTime, guider_ui.SetDateTime_del, &guider_ui.SetTime_del, setup_scr_SetDateTime, LV_SCR_LOAD_ANIM_NONE, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_SetTime (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->SetTime_cont_SetTimeConfirm, SetTime_cont_SetTimeConfirm_event_handler, LV_EVENT_ALL, ui);
}

static void PowerOff_slider_PowerOff_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
		if(lv_slider_get_value(guider_ui.PowerOff_slider_PowerOff) >= 90)
		{
			HWInterface.Power.Shutdown();
		}
	
        break;
    }
    default:
        break;
    }
}

void events_init_PowerOff (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->PowerOff_slider_PowerOff, PowerOff_slider_PowerOff_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
