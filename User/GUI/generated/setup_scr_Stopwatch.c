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

/************** 屏幕注册 **************/
void deinit_scr_Stopwatch(void);
Page_t Page_Stopwatch  = {"Stopwatch",setup_scr_Stopwatch,deinit_scr_Stopwatch,&guider_ui.Stopwatch};


/************** 变量管理 **************/
//定时器
lv_timer_t * ui_StopWatchTimer;
//时间
uint8_t ui_StopWatch_Flag = 0;
uint8_t ui_StopWatch_Min = 0;
uint8_t ui_StopWatch_Sec = 0;
uint8_t ui_StopWatch_10Ms = 0;
uint8_t ui_StopWatch_Ms = 0;

static void StopWatchTimerHandler(lv_timer_t * timer)
{
	char temp_buf[2];
	
	sprintf(temp_buf,"%02d",ui_StopWatch_Min);
	lv_label_set_text(guider_ui.Stopwatch_label_StopwatchMinute,temp_buf);
	sprintf(temp_buf,"%02d",ui_StopWatch_Sec);
	lv_label_set_text(guider_ui.Stopwatch_label_StopwatchSeconds,temp_buf);
	sprintf(temp_buf,"%02d",ui_StopWatch_10Ms);
	lv_label_set_text(guider_ui.Stopwatch_label_StopwatchMs,temp_buf);
}

void setup_scr_Stopwatch(lv_ui *ui)
{
    //Write codes Stopwatch
    ui->Stopwatch = lv_obj_create(NULL);
    lv_obj_set_size(ui->Stopwatch, 240, 280);
    lv_obj_set_scrollbar_mode(ui->Stopwatch, LV_SCROLLBAR_MODE_OFF);

    //Write style for Stopwatch, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Stopwatch, 215, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Stopwatch, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Stopwatch, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Stopwatch_meter_Stopwatch
    ui->Stopwatch_meter_Stopwatch = lv_meter_create(ui->Stopwatch);
    // add scale ui->Stopwatch_meter_Stopwatch_scale_0
    ui->Stopwatch_meter_Stopwatch_scale_0 = lv_meter_add_scale(ui->Stopwatch_meter_Stopwatch);
    lv_meter_set_scale_ticks(ui->Stopwatch_meter_Stopwatch, ui->Stopwatch_meter_Stopwatch_scale_0, 60, 2, 5, lv_color_hex(0x2F92DA));
    lv_meter_set_scale_range(ui->Stopwatch_meter_Stopwatch, ui->Stopwatch_meter_Stopwatch_scale_0, 0, 355, 360, 270);
    lv_obj_set_pos(ui->Stopwatch_meter_Stopwatch, 0, 20);
    lv_obj_set_size(ui->Stopwatch_meter_Stopwatch, 240, 240);

    //Write style for Stopwatch_meter_Stopwatch, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Stopwatch_meter_Stopwatch, 171, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Stopwatch_meter_Stopwatch, lv_color_hex(0x474747), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Stopwatch_meter_Stopwatch, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Stopwatch_meter_Stopwatch, 100, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Stopwatch_meter_Stopwatch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Stopwatch_meter_Stopwatch, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Stopwatch_meter_Stopwatch, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Stopwatch_meter_Stopwatch, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Stopwatch_meter_Stopwatch, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Stopwatch_meter_Stopwatch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Stopwatch_meter_Stopwatch, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->Stopwatch_meter_Stopwatch, lv_color_hex(0xffffff), LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Stopwatch_meter_Stopwatch, &lv_font_montserratMedium_12, LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Stopwatch_meter_Stopwatch, 255, LV_PART_TICKS|LV_STATE_DEFAULT);

    //Write style for Stopwatch_meter_Stopwatch, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Stopwatch_meter_Stopwatch, 0, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes Stopwatch_btn_StopwatchStop
    ui->Stopwatch_btn_StopwatchStop = lv_imgbtn_create(ui->Stopwatch);
    lv_obj_add_flag(ui->Stopwatch_btn_StopwatchStop, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->Stopwatch_btn_StopwatchStop, LV_IMGBTN_STATE_RELEASED, NULL, &_start_alpha_30x30, NULL);
    lv_imgbtn_set_src(ui->Stopwatch_btn_StopwatchStop, LV_IMGBTN_STATE_PRESSED, NULL, &_start1_alpha_30x30, NULL);
    lv_imgbtn_set_src(ui->Stopwatch_btn_StopwatchStop, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_stop_alpha_30x30, NULL);
    lv_imgbtn_set_src(ui->Stopwatch_btn_StopwatchStop, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_stop1_alpha_30x30, NULL);
    ui->Stopwatch_btn_StopwatchStop_label = lv_label_create(ui->Stopwatch_btn_StopwatchStop);
    lv_label_set_text(ui->Stopwatch_btn_StopwatchStop_label, "");
    lv_label_set_long_mode(ui->Stopwatch_btn_StopwatchStop_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Stopwatch_btn_StopwatchStop_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Stopwatch_btn_StopwatchStop, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->Stopwatch_btn_StopwatchStop, 145, 160);
    lv_obj_set_size(ui->Stopwatch_btn_StopwatchStop, 30, 30);
    lv_obj_add_flag(ui->Stopwatch_btn_StopwatchStop, LV_OBJ_FLAG_CHECKABLE);

    //Write style for Stopwatch_btn_StopwatchStop, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->Stopwatch_btn_StopwatchStop, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Stopwatch_btn_StopwatchStop, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Stopwatch_btn_StopwatchStop, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Stopwatch_btn_StopwatchStop, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Stopwatch_btn_StopwatchStop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Stopwatch_btn_StopwatchStop, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Stopwatch_btn_StopwatchStop, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Stopwatch_btn_StopwatchStop, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->Stopwatch_btn_StopwatchStop, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->Stopwatch_btn_StopwatchStop, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->Stopwatch_btn_StopwatchStop, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->Stopwatch_btn_StopwatchStop, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->Stopwatch_btn_StopwatchStop, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->Stopwatch_btn_StopwatchStop, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for Stopwatch_btn_StopwatchStop, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->Stopwatch_btn_StopwatchStop, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->Stopwatch_btn_StopwatchStop, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->Stopwatch_btn_StopwatchStop, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->Stopwatch_btn_StopwatchStop, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->Stopwatch_btn_StopwatchStop, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->Stopwatch_btn_StopwatchStop, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for Stopwatch_btn_StopwatchStop, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->Stopwatch_btn_StopwatchStop, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->Stopwatch_btn_StopwatchStop, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes Stopwatch_btn_StopwatchReset
    ui->Stopwatch_btn_StopwatchReset = lv_btn_create(ui->Stopwatch);
    ui->Stopwatch_btn_StopwatchReset_label = lv_label_create(ui->Stopwatch_btn_StopwatchReset);
    lv_label_set_text(ui->Stopwatch_btn_StopwatchReset_label, "");
    lv_label_set_long_mode(ui->Stopwatch_btn_StopwatchReset_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Stopwatch_btn_StopwatchReset_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Stopwatch_btn_StopwatchReset, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Stopwatch_btn_StopwatchReset_label, LV_PCT(100));
    lv_obj_set_pos(ui->Stopwatch_btn_StopwatchReset, 65, 160);
    lv_obj_set_size(ui->Stopwatch_btn_StopwatchReset, 30, 30);

    //Write style for Stopwatch_btn_StopwatchReset, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Stopwatch_btn_StopwatchReset, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Stopwatch_btn_StopwatchReset, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Stopwatch_btn_StopwatchReset, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Stopwatch_btn_StopwatchReset, lv_color_hex(0x5482a9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->Stopwatch_btn_StopwatchReset, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Stopwatch_btn_StopwatchReset, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Stopwatch_btn_StopwatchReset, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->Stopwatch_btn_StopwatchReset, &_reset_30x30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->Stopwatch_btn_StopwatchReset, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->Stopwatch_btn_StopwatchReset, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Stopwatch_btn_StopwatchReset, lv_color_hex(0x12548b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Stopwatch_btn_StopwatchReset, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Stopwatch_btn_StopwatchReset, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Stopwatch_btn_StopwatchReset, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Stopwatch_label_StopwatchMinute
    ui->Stopwatch_label_StopwatchMinute = lv_label_create(ui->Stopwatch);
    lv_label_set_text(ui->Stopwatch_label_StopwatchMinute, "00");
    lv_label_set_long_mode(ui->Stopwatch_label_StopwatchMinute, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Stopwatch_label_StopwatchMinute, 40, 100);
    lv_obj_set_size(ui->Stopwatch_label_StopwatchMinute, 45, 30);

    //Write style for Stopwatch_label_StopwatchMinute, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Stopwatch_label_StopwatchMinute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Stopwatch_label_StopwatchMinute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Stopwatch_label_StopwatchMinute, lv_color_hex(0xf6e4e4), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Stopwatch_label_StopwatchMinute, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Stopwatch_label_StopwatchMinute, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Stopwatch_label_StopwatchMinute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Stopwatch_label_StopwatchMinute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Stopwatch_label_StopwatchMinute, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Stopwatch_label_StopwatchMinute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Stopwatch_label_StopwatchMinute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Stopwatch_label_StopwatchMinute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Stopwatch_label_StopwatchMinute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Stopwatch_label_StopwatchMinute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Stopwatch_label_StopwatchMinute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Stopwatch_label_StopwatchIcon2
    ui->Stopwatch_label_StopwatchIcon2 = lv_label_create(ui->Stopwatch);
    lv_label_set_text(ui->Stopwatch_label_StopwatchIcon2, ":");
    lv_label_set_long_mode(ui->Stopwatch_label_StopwatchIcon2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Stopwatch_label_StopwatchIcon2, 90, 100);
    lv_obj_set_size(ui->Stopwatch_label_StopwatchIcon2, 5, 30);

    //Write style for Stopwatch_label_StopwatchIcon2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Stopwatch_label_StopwatchIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Stopwatch_label_StopwatchIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Stopwatch_label_StopwatchIcon2, lv_color_hex(0xfeeaea), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Stopwatch_label_StopwatchIcon2, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Stopwatch_label_StopwatchIcon2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Stopwatch_label_StopwatchIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Stopwatch_label_StopwatchIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Stopwatch_label_StopwatchIcon2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Stopwatch_label_StopwatchIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Stopwatch_label_StopwatchIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Stopwatch_label_StopwatchIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Stopwatch_label_StopwatchIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Stopwatch_label_StopwatchIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Stopwatch_label_StopwatchIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Stopwatch_label_StopwatchSeconds
    ui->Stopwatch_label_StopwatchSeconds = lv_label_create(ui->Stopwatch);
    lv_label_set_text(ui->Stopwatch_label_StopwatchSeconds, "00");
    lv_label_set_long_mode(ui->Stopwatch_label_StopwatchSeconds, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Stopwatch_label_StopwatchSeconds, 100, 100);
    lv_obj_set_size(ui->Stopwatch_label_StopwatchSeconds, 45, 30);

    //Write style for Stopwatch_label_StopwatchSeconds, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Stopwatch_label_StopwatchSeconds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Stopwatch_label_StopwatchSeconds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Stopwatch_label_StopwatchSeconds, lv_color_hex(0xf6e4e4), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Stopwatch_label_StopwatchSeconds, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Stopwatch_label_StopwatchSeconds, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Stopwatch_label_StopwatchSeconds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Stopwatch_label_StopwatchSeconds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Stopwatch_label_StopwatchSeconds, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Stopwatch_label_StopwatchSeconds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Stopwatch_label_StopwatchSeconds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Stopwatch_label_StopwatchSeconds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Stopwatch_label_StopwatchSeconds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Stopwatch_label_StopwatchSeconds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Stopwatch_label_StopwatchSeconds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Stopwatch_label_StopwatchMs
    ui->Stopwatch_label_StopwatchMs = lv_label_create(ui->Stopwatch);
    lv_label_set_text(ui->Stopwatch_label_StopwatchMs, "00");
    lv_label_set_long_mode(ui->Stopwatch_label_StopwatchMs, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Stopwatch_label_StopwatchMs, 150, 100);
    lv_obj_set_size(ui->Stopwatch_label_StopwatchMs, 45, 30);

    //Write style for Stopwatch_label_StopwatchMs, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Stopwatch_label_StopwatchMs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Stopwatch_label_StopwatchMs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Stopwatch_label_StopwatchMs, lv_color_hex(0xf6e4e4), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Stopwatch_label_StopwatchMs, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Stopwatch_label_StopwatchMs, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Stopwatch_label_StopwatchMs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Stopwatch_label_StopwatchMs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Stopwatch_label_StopwatchMs, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Stopwatch_label_StopwatchMs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Stopwatch_label_StopwatchMs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Stopwatch_label_StopwatchMs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Stopwatch_label_StopwatchMs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Stopwatch_label_StopwatchMs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Stopwatch_label_StopwatchMs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Stopwatch_label_StopwatchIcon1
    ui->Stopwatch_label_StopwatchIcon1 = lv_label_create(ui->Stopwatch);
    lv_label_set_text(ui->Stopwatch_label_StopwatchIcon1, ".");
    lv_label_set_long_mode(ui->Stopwatch_label_StopwatchIcon1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Stopwatch_label_StopwatchIcon1, 145, 100);
    lv_obj_set_size(ui->Stopwatch_label_StopwatchIcon1, 5, 30);

    //Write style for Stopwatch_label_StopwatchIcon1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Stopwatch_label_StopwatchIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Stopwatch_label_StopwatchIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Stopwatch_label_StopwatchIcon1, lv_color_hex(0xd7cbcb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Stopwatch_label_StopwatchIcon1, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Stopwatch_label_StopwatchIcon1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Stopwatch_label_StopwatchIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Stopwatch_label_StopwatchIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Stopwatch_label_StopwatchIcon1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Stopwatch_label_StopwatchIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Stopwatch_label_StopwatchIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Stopwatch_label_StopwatchIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Stopwatch_label_StopwatchIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Stopwatch_label_StopwatchIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Stopwatch_label_StopwatchIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Stopwatch.
	ui_StopWatchTimer =  lv_timer_create(StopWatchTimerHandler,10,NULL);
	lv_timer_pause(ui_StopWatchTimer);

    //Update current screen layout.
    lv_obj_update_layout(ui->Stopwatch);

    //Init events for screen.
    events_init_Stopwatch(ui);
}

void deinit_scr_Stopwatch(void)
{
	
}
