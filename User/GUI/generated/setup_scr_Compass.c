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
void deinit_scr_Compass(void);
Page_t Page_Compass  = {"Compass",setup_scr_Compass,deinit_scr_Compass,&guider_ui.Compass};

/************** 变量管理 **************/
lv_timer_t * ui_CompassTimer;

static void CompassTimerHandler(lv_timer_t * timer)
{
	char temp_buf[6];
	//label
	sprintf(temp_buf,"%d",HWInterface.Ecompass.direction);
	lv_label_set_text(guider_ui.Compass_label_ComCompassNum,temp_buf);
	sprintf(temp_buf,"%dm",HWInterface.Barometer.altitude);
	lv_label_set_text(guider_ui.Compass_label_ComAltitudeNum,temp_buf);
	//needle
	lv_meter_set_indicator_value(guider_ui.Compass_meter_compass,guider_ui.Compass_meter_compass_scale_0_ndline_0,HWInterface.Ecompass.direction);
}

void setup_scr_Compass(lv_ui *ui)
{
    //Write codes Compass
    ui->Compass = lv_obj_create(NULL);
    lv_obj_set_size(ui->Compass, 240, 280);
    lv_obj_set_scrollbar_mode(ui->Compass, LV_SCROLLBAR_MODE_OFF);

    //Write style for Compass, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Compass, 216, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Compass, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Compass, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Compass_meter_compass
    ui->Compass_meter_compass = lv_meter_create(ui->Compass);
    // add scale ui->Compass_meter_compass_scale_0
    ui->Compass_meter_compass_scale_0 = lv_meter_add_scale(ui->Compass_meter_compass);
    lv_meter_set_scale_ticks(ui->Compass_meter_compass, ui->Compass_meter_compass_scale_0, 60, 2, 5, lv_color_hex(0x7d7c7c));
    lv_meter_set_scale_major_ticks(ui->Compass_meter_compass, ui->Compass_meter_compass_scale_0, 5, 6, 10, lv_color_hex(0xffffff), 7);
    lv_meter_set_scale_range(ui->Compass_meter_compass, ui->Compass_meter_compass_scale_0, 0, 355, 360, 270);

    // add needle images for ui->Compass_meter_compass_scale_0.
    ui->Compass_meter_compass_scale_0_ndline_0 = lv_meter_add_needle_img(ui->Compass_meter_compass, ui->Compass_meter_compass_scale_0, &_needle_alpha_30x70, 13, 32);
    lv_meter_set_indicator_value(ui->Compass_meter_compass, ui->Compass_meter_compass_scale_0_ndline_0, 0);
    lv_obj_set_pos(ui->Compass_meter_compass, 20, 10);
    lv_obj_set_size(ui->Compass_meter_compass, 200, 200);

    //Write style for Compass_meter_compass, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Compass_meter_compass, 65, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Compass_meter_compass, lv_color_hex(0x545454), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Compass_meter_compass, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Compass_meter_compass, 100, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Compass_meter_compass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Compass_meter_compass, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Compass_meter_compass, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Compass_meter_compass, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Compass_meter_compass, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Compass_meter_compass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Compass_meter_compass, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->Compass_meter_compass, lv_color_hex(0xffffff), LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Compass_meter_compass, &lv_font_montserratMedium_12, LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Compass_meter_compass, 255, LV_PART_TICKS|LV_STATE_DEFAULT);

    //Write style for Compass_meter_compass, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Compass_meter_compass, 0, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes Compass_cont_ComCompass
    ui->Compass_cont_ComCompass = lv_obj_create(ui->Compass);
    lv_obj_set_pos(ui->Compass_cont_ComCompass, 20, 223);
    lv_obj_set_size(ui->Compass_cont_ComCompass, 90, 40);
    lv_obj_set_scrollbar_mode(ui->Compass_cont_ComCompass, LV_SCROLLBAR_MODE_OFF);

    //Write style for Compass_cont_ComCompass, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Compass_cont_ComCompass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Compass_cont_ComCompass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Compass_cont_ComCompass, 102, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Compass_cont_ComCompass, lv_color_hex(0xa3a1a1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Compass_cont_ComCompass, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Compass_cont_ComCompass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Compass_cont_ComCompass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Compass_cont_ComCompass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Compass_cont_ComCompass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Compass_cont_ComCompass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Compass_img_ComCompass
    ui->Compass_img_ComCompass = lv_img_create(ui->Compass_cont_ComCompass);
    lv_obj_add_flag(ui->Compass_img_ComCompass, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Compass_img_ComCompass, &_3_alpha_30x30);
    lv_img_set_pivot(ui->Compass_img_ComCompass, 50,50);
    lv_img_set_angle(ui->Compass_img_ComCompass, 0);
    lv_obj_set_pos(ui->Compass_img_ComCompass, 0, 5);
    lv_obj_set_size(ui->Compass_img_ComCompass, 30, 30);

    //Write style for Compass_img_ComCompass, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Compass_img_ComCompass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Compass_img_ComCompass, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Compass_img_ComCompass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Compass_img_ComCompass, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Compass_label_ComIcon1
    ui->Compass_label_ComIcon1 = lv_label_create(ui->Compass_cont_ComCompass);
    lv_label_set_text(ui->Compass_label_ComIcon1, ":");
    lv_label_set_long_mode(ui->Compass_label_ComIcon1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Compass_label_ComIcon1, 30, 5);
    lv_obj_set_size(ui->Compass_label_ComIcon1, 5, 30);

    //Write style for Compass_label_ComIcon1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Compass_label_ComIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Compass_label_ComIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Compass_label_ComIcon1, lv_color_hex(0xd8d8d8), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Compass_label_ComIcon1, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Compass_label_ComIcon1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Compass_label_ComIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Compass_label_ComIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Compass_label_ComIcon1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Compass_label_ComIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Compass_label_ComIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Compass_label_ComIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Compass_label_ComIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Compass_label_ComIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Compass_label_ComIcon1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Compass_label_ComCompassNum
    ui->Compass_label_ComCompassNum = lv_label_create(ui->Compass_cont_ComCompass);
    lv_label_set_text(ui->Compass_label_ComCompassNum, "349");
    lv_label_set_long_mode(ui->Compass_label_ComCompassNum, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Compass_label_ComCompassNum, 40, 10);
    lv_obj_set_size(ui->Compass_label_ComCompassNum, 40, 20);

    //Write style for Compass_label_ComCompassNum, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Compass_label_ComCompassNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Compass_label_ComCompassNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Compass_label_ComCompassNum, lv_color_hex(0xcfcbcb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Compass_label_ComCompassNum, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Compass_label_ComCompassNum, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Compass_label_ComCompassNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Compass_label_ComCompassNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Compass_label_ComCompassNum, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Compass_label_ComCompassNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Compass_label_ComCompassNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Compass_label_ComCompassNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Compass_label_ComCompassNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Compass_label_ComCompassNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Compass_label_ComCompassNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Compass_cont_CompAlti
    ui->Compass_cont_CompAlti = lv_obj_create(ui->Compass);
    lv_obj_set_pos(ui->Compass_cont_CompAlti, 130, 223);
    lv_obj_set_size(ui->Compass_cont_CompAlti, 90, 40);
    lv_obj_set_scrollbar_mode(ui->Compass_cont_CompAlti, LV_SCROLLBAR_MODE_OFF);

    //Write style for Compass_cont_CompAlti, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Compass_cont_CompAlti, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Compass_cont_CompAlti, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Compass_cont_CompAlti, 102, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Compass_cont_CompAlti, lv_color_hex(0xa3a1a1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Compass_cont_CompAlti, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Compass_cont_CompAlti, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Compass_cont_CompAlti, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Compass_cont_CompAlti, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Compass_cont_CompAlti, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Compass_cont_CompAlti, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Compass_img_ComAltitude
    ui->Compass_img_ComAltitude = lv_img_create(ui->Compass_cont_CompAlti);
    lv_obj_add_flag(ui->Compass_img_ComAltitude, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Compass_img_ComAltitude, &_altitude_alpha_30x30);
    lv_img_set_pivot(ui->Compass_img_ComAltitude, 50,50);
    lv_img_set_angle(ui->Compass_img_ComAltitude, 0);
    lv_obj_set_pos(ui->Compass_img_ComAltitude, 5, 5);
    lv_obj_set_size(ui->Compass_img_ComAltitude, 30, 30);

    //Write style for Compass_img_ComAltitude, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Compass_img_ComAltitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Compass_img_ComAltitude, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Compass_img_ComAltitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Compass_img_ComAltitude, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Compass_label_ComIcon2
    ui->Compass_label_ComIcon2 = lv_label_create(ui->Compass_cont_CompAlti);
    lv_label_set_text(ui->Compass_label_ComIcon2, ":");
    lv_label_set_long_mode(ui->Compass_label_ComIcon2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Compass_label_ComIcon2, 35, 5);
    lv_obj_set_size(ui->Compass_label_ComIcon2, 5, 30);

    //Write style for Compass_label_ComIcon2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Compass_label_ComIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Compass_label_ComIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Compass_label_ComIcon2, lv_color_hex(0xd8d8d8), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Compass_label_ComIcon2, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Compass_label_ComIcon2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Compass_label_ComIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Compass_label_ComIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Compass_label_ComIcon2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Compass_label_ComIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Compass_label_ComIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Compass_label_ComIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Compass_label_ComIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Compass_label_ComIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Compass_label_ComIcon2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Compass_label_ComAltitudeNum
    ui->Compass_label_ComAltitudeNum = lv_label_create(ui->Compass_cont_CompAlti);
    lv_label_set_text(ui->Compass_label_ComAltitudeNum, "59");
    lv_label_set_long_mode(ui->Compass_label_ComAltitudeNum, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Compass_label_ComAltitudeNum, 40, 10);
    lv_obj_set_size(ui->Compass_label_ComAltitudeNum, 40, 20);

    //Write style for Compass_label_ComAltitudeNum, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Compass_label_ComAltitudeNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Compass_label_ComAltitudeNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Compass_label_ComAltitudeNum, lv_color_hex(0xcfcbcb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Compass_label_ComAltitudeNum, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Compass_label_ComAltitudeNum, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Compass_label_ComAltitudeNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Compass_label_ComAltitudeNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Compass_label_ComAltitudeNum, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Compass_label_ComAltitudeNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Compass_label_ComAltitudeNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Compass_label_ComAltitudeNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Compass_label_ComAltitudeNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Compass_label_ComAltitudeNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Compass_label_ComAltitudeNum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Compass.
	ui_CompassTimer = lv_timer_create(CompassTimerHandler,500,NULL);

    //Update current screen layout.
    lv_obj_update_layout(ui->Compass);

}

void deinit_scr_Compass(void)
{
	lv_timer_del(ui_CompassTimer);
}
