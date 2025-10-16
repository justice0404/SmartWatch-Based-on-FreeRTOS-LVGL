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
/**************ÆÁÄ»×¢²á**************/
void deinit_scr_Setting(void);
Page_t Page_Setting  = {"Setting",setup_scr_Setting,deinit_scr_Setting,&guider_ui.Setting};

void setup_scr_Setting(lv_ui *ui)
{
    //Write codes Setting
    ui->Setting = lv_obj_create(NULL);
    lv_obj_set_size(ui->Setting, 240, 280);
    lv_obj_set_scrollbar_mode(ui->Setting, LV_SCROLLBAR_MODE_OFF);

    //Write style for Setting, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Setting, 215, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Setting, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Setting, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Setting_cont_SettingLightTime
    ui->Setting_cont_SettingLightTime = lv_obj_create(ui->Setting);
    lv_obj_set_pos(ui->Setting_cont_SettingLightTime, 0, 0);
    lv_obj_set_size(ui->Setting_cont_SettingLightTime, 240, 70);
    lv_obj_set_scrollbar_mode(ui->Setting_cont_SettingLightTime, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->Setting_cont_SettingLightTime, LV_OBJ_FLAG_CLICKABLE);

    //Write style for Setting_cont_SettingLightTime, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Setting_cont_SettingLightTime, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Setting_cont_SettingLightTime, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Setting_cont_SettingLightTime, lv_color_hex(0x5e5e5e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->Setting_cont_SettingLightTime, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Setting_cont_SettingLightTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Setting_cont_SettingLightTime, 222, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Setting_cont_SettingLightTime, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Setting_cont_SettingLightTime, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Setting_cont_SettingLightTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Setting_cont_SettingLightTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Setting_cont_SettingLightTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Setting_cont_SettingLightTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Setting_cont_SettingLightTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Setting_img_SettingLight
    ui->Setting_img_SettingLight = lv_img_create(ui->Setting_cont_SettingLightTime);
    lv_obj_add_flag(ui->Setting_img_SettingLight, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Setting_img_SettingLight, &_TurnOn_alpha_30x30);
    lv_img_set_pivot(ui->Setting_img_SettingLight, 50,50);
    lv_img_set_angle(ui->Setting_img_SettingLight, 0);
    lv_obj_set_pos(ui->Setting_img_SettingLight, 15, 20);
    lv_obj_set_size(ui->Setting_img_SettingLight, 30, 30);

    //Write style for Setting_img_SettingLight, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Setting_img_SettingLight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Setting_img_SettingLight, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Setting_img_SettingLight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Setting_img_SettingLight, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Setting_label_SettingLight
    ui->Setting_label_SettingLight = lv_label_create(ui->Setting_cont_SettingLightTime);
    lv_label_set_text(ui->Setting_label_SettingLight, "LightTime");
    lv_label_set_long_mode(ui->Setting_label_SettingLight, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Setting_label_SettingLight, 70, 20);
    lv_obj_set_size(ui->Setting_label_SettingLight, 140, 30);

    //Write style for Setting_label_SettingLight, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Setting_label_SettingLight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Setting_label_SettingLight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Setting_label_SettingLight, lv_color_hex(0xf6f6f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Setting_label_SettingLight, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Setting_label_SettingLight, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Setting_label_SettingLight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Setting_label_SettingLight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Setting_label_SettingLight, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Setting_label_SettingLight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Setting_label_SettingLight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Setting_label_SettingLight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Setting_label_SettingLight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Setting_label_SettingLight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Setting_label_SettingLight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Setting_cont_SettingOffTime
    ui->Setting_cont_SettingOffTime = lv_obj_create(ui->Setting);
    lv_obj_set_pos(ui->Setting_cont_SettingOffTime, 0, 70);
    lv_obj_set_size(ui->Setting_cont_SettingOffTime, 240, 70);
    lv_obj_set_scrollbar_mode(ui->Setting_cont_SettingOffTime, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->Setting_cont_SettingOffTime, LV_OBJ_FLAG_CLICKABLE);

    //Write style for Setting_cont_SettingOffTime, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Setting_cont_SettingOffTime, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Setting_cont_SettingOffTime, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Setting_cont_SettingOffTime, lv_color_hex(0x5e5e5e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->Setting_cont_SettingOffTime, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Setting_cont_SettingOffTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Setting_cont_SettingOffTime, 222, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Setting_cont_SettingOffTime, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Setting_cont_SettingOffTime, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Setting_cont_SettingOffTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Setting_cont_SettingOffTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Setting_cont_SettingOffTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Setting_cont_SettingOffTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Setting_cont_SettingOffTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Setting_img_SettingOffTime
    ui->Setting_img_SettingOffTime = lv_img_create(ui->Setting_cont_SettingOffTime);
    lv_obj_add_flag(ui->Setting_img_SettingOffTime, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Setting_img_SettingOffTime, &_TurnOff_alpha_30x30);
    lv_img_set_pivot(ui->Setting_img_SettingOffTime, 50,50);
    lv_img_set_angle(ui->Setting_img_SettingOffTime, 0);
    lv_obj_set_pos(ui->Setting_img_SettingOffTime, 15, 20);
    lv_obj_set_size(ui->Setting_img_SettingOffTime, 30, 30);

    //Write style for Setting_img_SettingOffTime, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Setting_img_SettingOffTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Setting_img_SettingOffTime, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Setting_img_SettingOffTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Setting_img_SettingOffTime, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Setting_label_SettingOffTime
    ui->Setting_label_SettingOffTime = lv_label_create(ui->Setting_cont_SettingOffTime);
    lv_label_set_text(ui->Setting_label_SettingOffTime, "OffTime");
    lv_label_set_long_mode(ui->Setting_label_SettingOffTime, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Setting_label_SettingOffTime, 70, 20);
    lv_obj_set_size(ui->Setting_label_SettingOffTime, 120, 30);

    //Write style for Setting_label_SettingOffTime, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Setting_label_SettingOffTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Setting_label_SettingOffTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Setting_label_SettingOffTime, lv_color_hex(0xf6f6f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Setting_label_SettingOffTime, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Setting_label_SettingOffTime, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Setting_label_SettingOffTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Setting_label_SettingOffTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Setting_label_SettingOffTime, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Setting_label_SettingOffTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Setting_label_SettingOffTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Setting_label_SettingOffTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Setting_label_SettingOffTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Setting_label_SettingOffTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Setting_label_SettingOffTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Setting_cont_SettingDateSet
    ui->Setting_cont_SettingDateSet = lv_obj_create(ui->Setting);
    lv_obj_set_pos(ui->Setting_cont_SettingDateSet, 0, 140);
    lv_obj_set_size(ui->Setting_cont_SettingDateSet, 240, 70);
    lv_obj_set_scrollbar_mode(ui->Setting_cont_SettingDateSet, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->Setting_cont_SettingDateSet, LV_OBJ_FLAG_CLICKABLE);

    //Write style for Setting_cont_SettingDateSet, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Setting_cont_SettingDateSet, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Setting_cont_SettingDateSet, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Setting_cont_SettingDateSet, lv_color_hex(0x5e5e5e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->Setting_cont_SettingDateSet, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Setting_cont_SettingDateSet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Setting_cont_SettingDateSet, 222, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Setting_cont_SettingDateSet, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Setting_cont_SettingDateSet, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Setting_cont_SettingDateSet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Setting_cont_SettingDateSet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Setting_cont_SettingDateSet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Setting_cont_SettingDateSet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Setting_cont_SettingDateSet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Setting_img_SettingDateSet
    ui->Setting_img_SettingDateSet = lv_img_create(ui->Setting_cont_SettingDateSet);
    lv_obj_add_flag(ui->Setting_img_SettingDateSet, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Setting_img_SettingDateSet, &_DateSet_alpha_30x30);
    lv_img_set_pivot(ui->Setting_img_SettingDateSet, 50,50);
    lv_img_set_angle(ui->Setting_img_SettingDateSet, 0);
    lv_obj_set_pos(ui->Setting_img_SettingDateSet, 15, 20);
    lv_obj_set_size(ui->Setting_img_SettingDateSet, 30, 30);

    //Write style for Setting_img_SettingDateSet, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Setting_img_SettingDateSet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Setting_img_SettingDateSet, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Setting_img_SettingDateSet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Setting_img_SettingDateSet, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Setting_label_SettingDateSet
    ui->Setting_label_SettingDateSet = lv_label_create(ui->Setting_cont_SettingDateSet);
    lv_label_set_text(ui->Setting_label_SettingDateSet, "Date&Time");
    lv_label_set_long_mode(ui->Setting_label_SettingDateSet, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Setting_label_SettingDateSet, 70, 20);
    lv_obj_set_size(ui->Setting_label_SettingDateSet, 150, 30);

    //Write style for Setting_label_SettingDateSet, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Setting_label_SettingDateSet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Setting_label_SettingDateSet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Setting_label_SettingDateSet, lv_color_hex(0xf6f6f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Setting_label_SettingDateSet, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Setting_label_SettingDateSet, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Setting_label_SettingDateSet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Setting_label_SettingDateSet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Setting_label_SettingDateSet, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Setting_label_SettingDateSet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Setting_label_SettingDateSet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Setting_label_SettingDateSet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Setting_label_SettingDateSet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Setting_label_SettingDateSet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Setting_label_SettingDateSet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Setting_cont_SettingWrist
    ui->Setting_cont_SettingWrist = lv_obj_create(ui->Setting);
    lv_obj_set_pos(ui->Setting_cont_SettingWrist, 0, 210);
    lv_obj_set_size(ui->Setting_cont_SettingWrist, 240, 70);
    lv_obj_set_scrollbar_mode(ui->Setting_cont_SettingWrist, LV_SCROLLBAR_MODE_OFF);

    //Write style for Setting_cont_SettingWrist, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Setting_cont_SettingWrist, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Setting_cont_SettingWrist, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Setting_cont_SettingWrist, lv_color_hex(0x5e5e5e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->Setting_cont_SettingWrist, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Setting_cont_SettingWrist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Setting_cont_SettingWrist, 222, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Setting_cont_SettingWrist, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Setting_cont_SettingWrist, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Setting_cont_SettingWrist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Setting_cont_SettingWrist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Setting_cont_SettingWrist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Setting_cont_SettingWrist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Setting_cont_SettingWrist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Setting_img_SettingWrist
    ui->Setting_img_SettingWrist = lv_img_create(ui->Setting_cont_SettingWrist);
    lv_obj_add_flag(ui->Setting_img_SettingWrist, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Setting_img_SettingWrist, &_Wrist_alpha_30x30);
    lv_img_set_pivot(ui->Setting_img_SettingWrist, 50,50);
    lv_img_set_angle(ui->Setting_img_SettingWrist, 0);
    lv_obj_set_pos(ui->Setting_img_SettingWrist, 15, 20);
    lv_obj_set_size(ui->Setting_img_SettingWrist, 30, 30);

    //Write style for Setting_img_SettingWrist, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Setting_img_SettingWrist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Setting_img_SettingWrist, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Setting_img_SettingWrist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Setting_img_SettingWrist, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Setting_label_SettingWrist
    ui->Setting_label_SettingWrist = lv_label_create(ui->Setting_cont_SettingWrist);
    lv_label_set_text(ui->Setting_label_SettingWrist, "LiftWake");
    lv_label_set_long_mode(ui->Setting_label_SettingWrist, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Setting_label_SettingWrist, 70, 20);
    lv_obj_set_size(ui->Setting_label_SettingWrist, 115, 30);

    //Write style for Setting_label_SettingWrist, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Setting_label_SettingWrist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Setting_label_SettingWrist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Setting_label_SettingWrist, lv_color_hex(0xf6f6f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Setting_label_SettingWrist, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Setting_label_SettingWrist, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Setting_label_SettingWrist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Setting_label_SettingWrist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Setting_label_SettingWrist, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Setting_label_SettingWrist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Setting_label_SettingWrist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Setting_label_SettingWrist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Setting_label_SettingWrist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Setting_label_SettingWrist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Setting_label_SettingWrist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Setting_sw_SettingWrist
    ui->Setting_sw_SettingWrist = lv_switch_create(ui->Setting_cont_SettingWrist);
    lv_obj_set_pos(ui->Setting_sw_SettingWrist, 190, 25);
    lv_obj_set_size(ui->Setting_sw_SettingWrist, 40, 20);

    //Write style for Setting_sw_SettingWrist, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Setting_sw_SettingWrist, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Setting_sw_SettingWrist, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Setting_sw_SettingWrist, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Setting_sw_SettingWrist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Setting_sw_SettingWrist, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Setting_sw_SettingWrist, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Setting_sw_SettingWrist, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->Setting_sw_SettingWrist, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->Setting_sw_SettingWrist, lv_color_hex(0x6f6d6d), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->Setting_sw_SettingWrist, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->Setting_sw_SettingWrist, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for Setting_sw_SettingWrist, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Setting_sw_SettingWrist, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Setting_sw_SettingWrist, lv_color_hex(0x474646), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Setting_sw_SettingWrist, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Setting_sw_SettingWrist, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Setting_sw_SettingWrist, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

    //The custom code of Setting.


    //Update current screen layout.
    lv_obj_update_layout(ui->Setting);

    //Init events for screen.
    events_init_Setting(ui);
}

void deinit_scr_Setting(void)
{
	
}
