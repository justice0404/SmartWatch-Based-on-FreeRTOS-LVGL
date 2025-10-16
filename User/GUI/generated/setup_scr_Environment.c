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
/************** 屏幕注册 **************/
void deinit_scr_Environment(void);
Page_t Page_Environment  = {"Environment",setup_scr_Environment,deinit_scr_Environment,&guider_ui.Environment};

/*********** 变量管理 **********/
lv_timer_t * ui_EnvTimer;

static void EnvTimer_Handler(lv_timer_t * timer)
{
	char temp_buf[6];
	//Bar
	lv_bar_set_value(guider_ui.Environment_bar_EnvTemp,HWInterface.AHT21.temperature,LV_ANIM_OFF);
	lv_bar_set_value(guider_ui.Environment_bar_EnvHumi,HWInterface.AHT21.humidity,LV_ANIM_OFF);
	//label
	sprintf(temp_buf,"%d",HWInterface.AHT21.temperature);
	lv_label_set_text(guider_ui.Environment_label_EnvTempNum,temp_buf);
	sprintf(temp_buf,"%d",HWInterface.AHT21.humidity);
	lv_label_set_text(guider_ui.Environment_label_EnvHmdiNum,temp_buf);
}


void setup_scr_Environment(lv_ui *ui)
{
    //Write codes Environment
    ui->Environment = lv_obj_create(NULL);
    lv_obj_set_size(ui->Environment, 240, 280);
    lv_obj_set_scrollbar_mode(ui->Environment, LV_SCROLLBAR_MODE_OFF);

    //Write style for Environment, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Environment, 216, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Environment, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Environment, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Environment_cont_EnvTemperature
    ui->Environment_cont_EnvTemperature = lv_obj_create(ui->Environment);
    lv_obj_set_pos(ui->Environment_cont_EnvTemperature, 0, 30);
    lv_obj_set_size(ui->Environment_cont_EnvTemperature, 240, 100);
    lv_obj_set_scrollbar_mode(ui->Environment_cont_EnvTemperature, LV_SCROLLBAR_MODE_OFF);

    //Write style for Environment_cont_EnvTemperature, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Environment_cont_EnvTemperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Environment_cont_EnvTemperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Environment_cont_EnvTemperature, 65, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Environment_cont_EnvTemperature, lv_color_hex(0x414141), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Environment_cont_EnvTemperature, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Environment_cont_EnvTemperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Environment_cont_EnvTemperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Environment_cont_EnvTemperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Environment_cont_EnvTemperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Environment_cont_EnvTemperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Environment_bar_EnvTemp
    ui->Environment_bar_EnvTemp = lv_bar_create(ui->Environment_cont_EnvTemperature);
    lv_obj_set_style_anim_time(ui->Environment_bar_EnvTemp, 1000, 0);
    lv_bar_set_mode(ui->Environment_bar_EnvTemp, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->Environment_bar_EnvTemp, 0, 100);
    lv_bar_set_value(ui->Environment_bar_EnvTemp, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->Environment_bar_EnvTemp, 10, 70);
    lv_obj_set_size(ui->Environment_bar_EnvTemp, 220, 20);

    //Write style for Environment_bar_EnvTemp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Environment_bar_EnvTemp, 53, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Environment_bar_EnvTemp, lv_color_hex(0x993946), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Environment_bar_EnvTemp, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Environment_bar_EnvTemp, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Environment_bar_EnvTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Environment_bar_EnvTemp, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Environment_bar_EnvTemp, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Environment_bar_EnvTemp, lv_color_hex(0x993946), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Environment_bar_EnvTemp, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Environment_bar_EnvTemp, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes Environment_label_EnvTempNum
    ui->Environment_label_EnvTempNum = lv_label_create(ui->Environment_cont_EnvTemperature);
    lv_label_set_text(ui->Environment_label_EnvTempNum, "27");
    lv_label_set_long_mode(ui->Environment_label_EnvTempNum, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Environment_label_EnvTempNum, 80, 20);
    lv_obj_set_size(ui->Environment_label_EnvTempNum, 50, 30);

    //Write style for Environment_label_EnvTempNum, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Environment_label_EnvTempNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Environment_label_EnvTempNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Environment_label_EnvTempNum, lv_color_hex(0xd2c9c9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Environment_label_EnvTempNum, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Environment_label_EnvTempNum, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Environment_label_EnvTempNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Environment_label_EnvTempNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Environment_label_EnvTempNum, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Environment_label_EnvTempNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Environment_label_EnvTempNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Environment_label_EnvTempNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Environment_label_EnvTempNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Environment_label_EnvTempNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Environment_label_EnvTempNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Environment_label_EnvIcon2
    ui->Environment_label_EnvIcon2 = lv_label_create(ui->Environment_cont_EnvTemperature);
    lv_label_set_text(ui->Environment_label_EnvIcon2, "C");
    lv_label_set_long_mode(ui->Environment_label_EnvIcon2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Environment_label_EnvIcon2, 130, 20);
    lv_obj_set_size(ui->Environment_label_EnvIcon2, 30, 30);

    //Write style for Environment_label_EnvIcon2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Environment_label_EnvIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Environment_label_EnvIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Environment_label_EnvIcon2, lv_color_hex(0x727272), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Environment_label_EnvIcon2, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Environment_label_EnvIcon2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Environment_label_EnvIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Environment_label_EnvIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Environment_label_EnvIcon2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Environment_label_EnvIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Environment_label_EnvIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Environment_label_EnvIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Environment_label_EnvIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Environment_label_EnvIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Environment_label_EnvIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Environment_img_EnvSun
    ui->Environment_img_EnvSun = lv_img_create(ui->Environment_cont_EnvTemperature);
    lv_obj_add_flag(ui->Environment_img_EnvSun, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Environment_img_EnvSun, &_11_alpha_30x30);
    lv_img_set_pivot(ui->Environment_img_EnvSun, 50,50);
    lv_img_set_angle(ui->Environment_img_EnvSun, 0);
    lv_obj_set_pos(ui->Environment_img_EnvSun, 25, 20);
    lv_obj_set_size(ui->Environment_img_EnvSun, 30, 30);

    //Write style for Environment_img_EnvSun, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Environment_img_EnvSun, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Environment_img_EnvSun, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Environment_img_EnvSun, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Environment_img_EnvSun, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Environment_cont_EnvHumidity
    ui->Environment_cont_EnvHumidity = lv_obj_create(ui->Environment);
    lv_obj_set_pos(ui->Environment_cont_EnvHumidity, 0, 150);
    lv_obj_set_size(ui->Environment_cont_EnvHumidity, 240, 100);
    lv_obj_set_scrollbar_mode(ui->Environment_cont_EnvHumidity, LV_SCROLLBAR_MODE_OFF);

    //Write style for Environment_cont_EnvHumidity, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Environment_cont_EnvHumidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Environment_cont_EnvHumidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Environment_cont_EnvHumidity, 65, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Environment_cont_EnvHumidity, lv_color_hex(0x414141), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Environment_cont_EnvHumidity, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Environment_cont_EnvHumidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Environment_cont_EnvHumidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Environment_cont_EnvHumidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Environment_cont_EnvHumidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Environment_cont_EnvHumidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Environment_bar_EnvHumi
    ui->Environment_bar_EnvHumi = lv_bar_create(ui->Environment_cont_EnvHumidity);
    lv_obj_set_style_anim_time(ui->Environment_bar_EnvHumi, 1000, 0);
    lv_bar_set_mode(ui->Environment_bar_EnvHumi, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->Environment_bar_EnvHumi, 0, 100);
    lv_bar_set_value(ui->Environment_bar_EnvHumi, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->Environment_bar_EnvHumi, 10, 70);
    lv_obj_set_size(ui->Environment_bar_EnvHumi, 220, 20);

    //Write style for Environment_bar_EnvHumi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Environment_bar_EnvHumi, 53, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Environment_bar_EnvHumi, lv_color_hex(0x2F92DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Environment_bar_EnvHumi, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Environment_bar_EnvHumi, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Environment_bar_EnvHumi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Environment_bar_EnvHumi, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Environment_bar_EnvHumi, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Environment_bar_EnvHumi, lv_color_hex(0x2F92DA), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Environment_bar_EnvHumi, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Environment_bar_EnvHumi, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes Environment_label_EnvHmdiNum
    ui->Environment_label_EnvHmdiNum = lv_label_create(ui->Environment_cont_EnvHumidity);
    lv_label_set_text(ui->Environment_label_EnvHmdiNum, "53");
    lv_label_set_long_mode(ui->Environment_label_EnvHmdiNum, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Environment_label_EnvHmdiNum, 80, 20);
    lv_obj_set_size(ui->Environment_label_EnvHmdiNum, 50, 30);

    //Write style for Environment_label_EnvHmdiNum, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Environment_label_EnvHmdiNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Environment_label_EnvHmdiNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Environment_label_EnvHmdiNum, lv_color_hex(0xd2c9c9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Environment_label_EnvHmdiNum, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Environment_label_EnvHmdiNum, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Environment_label_EnvHmdiNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Environment_label_EnvHmdiNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Environment_label_EnvHmdiNum, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Environment_label_EnvHmdiNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Environment_label_EnvHmdiNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Environment_label_EnvHmdiNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Environment_label_EnvHmdiNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Environment_label_EnvHmdiNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Environment_label_EnvHmdiNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Environment_label_EnvIcon1
    ui->Environment_label_EnvIcon1 = lv_label_create(ui->Environment_cont_EnvHumidity);
    lv_label_set_text(ui->Environment_label_EnvIcon1, "%");
    lv_label_set_long_mode(ui->Environment_label_EnvIcon1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Environment_label_EnvIcon1, 130, 20);
    lv_obj_set_size(ui->Environment_label_EnvIcon1, 30, 30);

    //Write style for Environment_label_EnvIcon1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Environment_label_EnvIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Environment_label_EnvIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Environment_label_EnvIcon1, lv_color_hex(0x727272), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Environment_label_EnvIcon1, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Environment_label_EnvIcon1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Environment_label_EnvIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Environment_label_EnvIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Environment_label_EnvIcon1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Environment_label_EnvIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Environment_label_EnvIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Environment_label_EnvIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Environment_label_EnvIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Environment_label_EnvIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Environment_label_EnvIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Environment_img_EnvWater
    ui->Environment_img_EnvWater = lv_img_create(ui->Environment_cont_EnvHumidity);
    lv_obj_add_flag(ui->Environment_img_EnvWater, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Environment_img_EnvWater, &_7_alpha_30x30);
    lv_img_set_pivot(ui->Environment_img_EnvWater, 50,50);
    lv_img_set_angle(ui->Environment_img_EnvWater, 0);
    lv_obj_set_pos(ui->Environment_img_EnvWater, 25, 20);
    lv_obj_set_size(ui->Environment_img_EnvWater, 30, 30);

    //Write style for Environment_img_EnvWater, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Environment_img_EnvWater, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Environment_img_EnvWater, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Environment_img_EnvWater, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Environment_img_EnvWater, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Environment.
	ui_EnvTimer = lv_timer_create(EnvTimer_Handler,500,NULL);

    //Update current screen layout.
    lv_obj_update_layout(ui->Environment);

}

void deinit_scr_Environment(void)
{
	lv_timer_del(ui_EnvTimer);
}
