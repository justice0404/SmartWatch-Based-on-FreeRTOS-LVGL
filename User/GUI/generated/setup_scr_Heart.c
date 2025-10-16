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
void deinit_scr_Heart(void);
Page_t Page_Heart  = {"Heart",setup_scr_Heart,deinit_scr_Heart,&guider_ui.Heart};

/************** 变量管理 **************/
lv_timer_t * ui_HeartTimer;

static void HRPage_timer_cb(lv_timer_t * timer)
{
	lv_ui * ui = (lv_ui *)timer->user_data;
	
	char temp_buf[6];
	sprintf(temp_buf,"%d",HWInterface.HR_meter.HrRate);
	lv_label_set_text(ui->Heart_label_HeartCnt,temp_buf);
}

void setup_scr_Heart(lv_ui *ui)
{
    //Write codes Heart
    ui->Heart = lv_obj_create(NULL);
    lv_obj_set_size(ui->Heart, 240, 280);
    lv_obj_set_scrollbar_mode(ui->Heart, LV_SCROLLBAR_MODE_OFF);

    //Write style for Heart, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Heart, 215, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Heart, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Heart, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Heart_label_HeartCnt
    ui->Heart_label_HeartCnt = lv_label_create(ui->Heart);
    lv_label_set_text(ui->Heart_label_HeartCnt, "120");
    lv_label_set_long_mode(ui->Heart_label_HeartCnt, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Heart_label_HeartCnt, 60, 130);
    lv_obj_set_size(ui->Heart_label_HeartCnt, 120, 55);

    //Write style for Heart_label_HeartCnt, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Heart_label_HeartCnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Heart_label_HeartCnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Heart_label_HeartCnt, lv_color_hex(0xdedede), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Heart_label_HeartCnt, &lv_font_montserratMedium_50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Heart_label_HeartCnt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Heart_label_HeartCnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Heart_label_HeartCnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Heart_label_HeartCnt, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Heart_label_HeartCnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Heart_label_HeartCnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Heart_label_HeartCnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Heart_label_HeartCnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Heart_label_HeartCnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Heart_label_HeartCnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Heart_label_HeartBPM
    ui->Heart_label_HeartBPM = lv_label_create(ui->Heart);
    lv_label_set_text(ui->Heart_label_HeartBPM, "bpm");
    lv_label_set_long_mode(ui->Heart_label_HeartBPM, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Heart_label_HeartBPM, 180, 153);
    lv_obj_set_size(ui->Heart_label_HeartBPM, 50, 20);

    //Write style for Heart_label_HeartBPM, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Heart_label_HeartBPM, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Heart_label_HeartBPM, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Heart_label_HeartBPM, lv_color_hex(0x807b7b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Heart_label_HeartBPM, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Heart_label_HeartBPM, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Heart_label_HeartBPM, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Heart_label_HeartBPM, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Heart_label_HeartBPM, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Heart_label_HeartBPM, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Heart_label_HeartBPM, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Heart_label_HeartBPM, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Heart_label_HeartBPM, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Heart_label_HeartBPM, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Heart_label_HeartBPM, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Heart_label_HeartText
    ui->Heart_label_HeartText = lv_label_create(ui->Heart);
    lv_label_set_text(ui->Heart_label_HeartText, "Measuring...");
    lv_label_set_long_mode(ui->Heart_label_HeartText, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Heart_label_HeartText, 60, 220);
    lv_obj_set_size(ui->Heart_label_HeartText, 140, 20);

    //Write style for Heart_label_HeartText, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Heart_label_HeartText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Heart_label_HeartText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Heart_label_HeartText, lv_color_hex(0xc5c3c3), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Heart_label_HeartText, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Heart_label_HeartText, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Heart_label_HeartText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Heart_label_HeartText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Heart_label_HeartText, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Heart_label_HeartText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Heart_label_HeartText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Heart_label_HeartText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Heart_label_HeartText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Heart_label_HeartText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Heart_label_HeartText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Heart_img_HeartRate
    ui->Heart_img_HeartRate = lv_img_create(ui->Heart);
    lv_obj_add_flag(ui->Heart_img_HeartRate, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Heart_img_HeartRate, &_1_alpha_30x30);
    lv_img_set_pivot(ui->Heart_img_HeartRate, 50,50);
    lv_img_set_angle(ui->Heart_img_HeartRate, 0);
    lv_obj_set_pos(ui->Heart_img_HeartRate, 105, 55);
    lv_obj_set_size(ui->Heart_img_HeartRate, 30, 30);

    //Write style for Heart_img_HeartRate, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Heart_img_HeartRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Heart_img_HeartRate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Heart_img_HeartRate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Heart_img_HeartRate, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Heart.
	ui_HeartTimer = lv_timer_create(HRPage_timer_cb,50,ui);

    //Update current screen layout.
    lv_obj_update_layout(ui->Heart);

}

void deinit_scr_Heart(void)
{
	lv_timer_del(ui_HeartTimer);
}
