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
void deinit_scr_SetDateTime(void);
Page_t Page_SetDateTime  = {"SetDateTime",setup_scr_SetDateTime,deinit_scr_SetDateTime,&guider_ui.SetDateTime};


void setup_scr_SetDateTime(lv_ui *ui)
{
    //Write codes SetDateTime
    ui->SetDateTime = lv_obj_create(NULL);
    lv_obj_set_size(ui->SetDateTime, 240, 280);
    lv_obj_set_scrollbar_mode(ui->SetDateTime, LV_SCROLLBAR_MODE_OFF);

    //Write style for SetDateTime, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->SetDateTime, 215, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SetDateTime, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SetDateTime, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SetDateTime_cont_SetDTBlue
    ui->SetDateTime_cont_SetDTBlue = lv_obj_create(ui->SetDateTime);
    lv_obj_set_pos(ui->SetDateTime_cont_SetDTBlue, 0, 0);
    lv_obj_set_size(ui->SetDateTime_cont_SetDTBlue, 240, 70);
    lv_obj_set_scrollbar_mode(ui->SetDateTime_cont_SetDTBlue, LV_SCROLLBAR_MODE_OFF);

    //Write style for SetDateTime_cont_SetDTBlue, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->SetDateTime_cont_SetDTBlue, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->SetDateTime_cont_SetDTBlue, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->SetDateTime_cont_SetDTBlue, lv_color_hex(0x5e5e5e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->SetDateTime_cont_SetDTBlue, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SetDateTime_cont_SetDTBlue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->SetDateTime_cont_SetDTBlue, 222, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SetDateTime_cont_SetDTBlue, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SetDateTime_cont_SetDTBlue, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->SetDateTime_cont_SetDTBlue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->SetDateTime_cont_SetDTBlue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->SetDateTime_cont_SetDTBlue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->SetDateTime_cont_SetDTBlue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SetDateTime_cont_SetDTBlue, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SetDateTime_label_BlueTeeth
    ui->SetDateTime_label_BlueTeeth = lv_label_create(ui->SetDateTime_cont_SetDTBlue);
    lv_label_set_text(ui->SetDateTime_label_BlueTeeth, "BT Sync");
    lv_label_set_long_mode(ui->SetDateTime_label_BlueTeeth, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->SetDateTime_label_BlueTeeth, 40, 20);
    lv_obj_set_size(ui->SetDateTime_label_BlueTeeth, 130, 30);

    //Write style for SetDateTime_label_BlueTeeth, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->SetDateTime_label_BlueTeeth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SetDateTime_label_BlueTeeth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->SetDateTime_label_BlueTeeth, lv_color_hex(0xf6f6f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->SetDateTime_label_BlueTeeth, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->SetDateTime_label_BlueTeeth, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->SetDateTime_label_BlueTeeth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->SetDateTime_label_BlueTeeth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->SetDateTime_label_BlueTeeth, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->SetDateTime_label_BlueTeeth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->SetDateTime_label_BlueTeeth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->SetDateTime_label_BlueTeeth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->SetDateTime_label_BlueTeeth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->SetDateTime_label_BlueTeeth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SetDateTime_label_BlueTeeth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SetDateTime_sw_BT
    ui->SetDateTime_sw_BT = lv_switch_create(ui->SetDateTime_cont_SetDTBlue);
    lv_obj_set_pos(ui->SetDateTime_sw_BT, 180, 25);
    lv_obj_set_size(ui->SetDateTime_sw_BT, 40, 20);

    //Write style for SetDateTime_sw_BT, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->SetDateTime_sw_BT, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SetDateTime_sw_BT, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SetDateTime_sw_BT, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->SetDateTime_sw_BT, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SetDateTime_sw_BT, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SetDateTime_sw_BT, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for SetDateTime_sw_BT, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->SetDateTime_sw_BT, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->SetDateTime_sw_BT, lv_color_hex(0x6f6d6d), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->SetDateTime_sw_BT, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->SetDateTime_sw_BT, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for SetDateTime_sw_BT, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->SetDateTime_sw_BT, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SetDateTime_sw_BT, lv_color_hex(0x474646), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SetDateTime_sw_BT, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->SetDateTime_sw_BT, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SetDateTime_sw_BT, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes SetDateTime_cont_SetDTSetDate
    ui->SetDateTime_cont_SetDTSetDate = lv_obj_create(ui->SetDateTime);
    lv_obj_set_pos(ui->SetDateTime_cont_SetDTSetDate, 0, 70);
    lv_obj_set_size(ui->SetDateTime_cont_SetDTSetDate, 240, 70);
    lv_obj_set_scrollbar_mode(ui->SetDateTime_cont_SetDTSetDate, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->SetDateTime_cont_SetDTSetDate, LV_OBJ_FLAG_CLICKABLE);

    //Write style for SetDateTime_cont_SetDTSetDate, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->SetDateTime_cont_SetDTSetDate, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->SetDateTime_cont_SetDTSetDate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->SetDateTime_cont_SetDTSetDate, lv_color_hex(0x5e5e5e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->SetDateTime_cont_SetDTSetDate, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SetDateTime_cont_SetDTSetDate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->SetDateTime_cont_SetDTSetDate, 222, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SetDateTime_cont_SetDTSetDate, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SetDateTime_cont_SetDTSetDate, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->SetDateTime_cont_SetDTSetDate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->SetDateTime_cont_SetDTSetDate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->SetDateTime_cont_SetDTSetDate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->SetDateTime_cont_SetDTSetDate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SetDateTime_cont_SetDTSetDate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SetDateTime_label_SetDT2
    ui->SetDateTime_label_SetDT2 = lv_label_create(ui->SetDateTime_cont_SetDTSetDate);
    lv_label_set_text(ui->SetDateTime_label_SetDT2, "SetDate");
    lv_label_set_long_mode(ui->SetDateTime_label_SetDT2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->SetDateTime_label_SetDT2, 40, 20);
    lv_obj_set_size(ui->SetDateTime_label_SetDT2, 110, 30);

    //Write style for SetDateTime_label_SetDT2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->SetDateTime_label_SetDT2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SetDateTime_label_SetDT2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->SetDateTime_label_SetDT2, lv_color_hex(0xf6f6f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->SetDateTime_label_SetDT2, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->SetDateTime_label_SetDT2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->SetDateTime_label_SetDT2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->SetDateTime_label_SetDT2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->SetDateTime_label_SetDT2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->SetDateTime_label_SetDT2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->SetDateTime_label_SetDT2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->SetDateTime_label_SetDT2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->SetDateTime_label_SetDT2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->SetDateTime_label_SetDT2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SetDateTime_label_SetDT2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SetDateTime_img_SetDT2
    ui->SetDateTime_img_SetDT2 = lv_img_create(ui->SetDateTime_cont_SetDTSetDate);
    lv_obj_add_flag(ui->SetDateTime_img_SetDT2, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->SetDateTime_img_SetDT2, &_dotdot_alpha_20x20);
    lv_img_set_pivot(ui->SetDateTime_img_SetDT2, 50,50);
    lv_img_set_angle(ui->SetDateTime_img_SetDT2, 0);
    lv_obj_set_pos(ui->SetDateTime_img_SetDT2, 200, 25);
    lv_obj_set_size(ui->SetDateTime_img_SetDT2, 20, 20);

    //Write style for SetDateTime_img_SetDT2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->SetDateTime_img_SetDT2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->SetDateTime_img_SetDT2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SetDateTime_img_SetDT2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->SetDateTime_img_SetDT2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SetDateTime_cont_SetDTSetTime
    ui->SetDateTime_cont_SetDTSetTime = lv_obj_create(ui->SetDateTime);
    lv_obj_set_pos(ui->SetDateTime_cont_SetDTSetTime, 0, 140);
    lv_obj_set_size(ui->SetDateTime_cont_SetDTSetTime, 240, 70);
    lv_obj_set_scrollbar_mode(ui->SetDateTime_cont_SetDTSetTime, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->SetDateTime_cont_SetDTSetTime, LV_OBJ_FLAG_CLICKABLE);

    //Write style for SetDateTime_cont_SetDTSetTime, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->SetDateTime_cont_SetDTSetTime, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->SetDateTime_cont_SetDTSetTime, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->SetDateTime_cont_SetDTSetTime, lv_color_hex(0x5e5e5e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->SetDateTime_cont_SetDTSetTime, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SetDateTime_cont_SetDTSetTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->SetDateTime_cont_SetDTSetTime, 222, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SetDateTime_cont_SetDTSetTime, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SetDateTime_cont_SetDTSetTime, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->SetDateTime_cont_SetDTSetTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->SetDateTime_cont_SetDTSetTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->SetDateTime_cont_SetDTSetTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->SetDateTime_cont_SetDTSetTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SetDateTime_cont_SetDTSetTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SetDateTime_label_SetDT1
    ui->SetDateTime_label_SetDT1 = lv_label_create(ui->SetDateTime_cont_SetDTSetTime);
    lv_label_set_text(ui->SetDateTime_label_SetDT1, "SetTime");
    lv_label_set_long_mode(ui->SetDateTime_label_SetDT1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->SetDateTime_label_SetDT1, 40, 20);
    lv_obj_set_size(ui->SetDateTime_label_SetDT1, 110, 30);

    //Write style for SetDateTime_label_SetDT1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->SetDateTime_label_SetDT1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SetDateTime_label_SetDT1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->SetDateTime_label_SetDT1, lv_color_hex(0xf6f6f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->SetDateTime_label_SetDT1, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->SetDateTime_label_SetDT1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->SetDateTime_label_SetDT1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->SetDateTime_label_SetDT1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->SetDateTime_label_SetDT1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->SetDateTime_label_SetDT1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->SetDateTime_label_SetDT1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->SetDateTime_label_SetDT1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->SetDateTime_label_SetDT1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->SetDateTime_label_SetDT1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SetDateTime_label_SetDT1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SetDateTime_img_SetDT1
    ui->SetDateTime_img_SetDT1 = lv_img_create(ui->SetDateTime_cont_SetDTSetTime);
    lv_obj_add_flag(ui->SetDateTime_img_SetDT1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->SetDateTime_img_SetDT1, &_dotdot_alpha_20x20);
    lv_img_set_pivot(ui->SetDateTime_img_SetDT1, 50,50);
    lv_img_set_angle(ui->SetDateTime_img_SetDT1, 0);
    lv_obj_set_pos(ui->SetDateTime_img_SetDT1, 200, 25);
    lv_obj_set_size(ui->SetDateTime_img_SetDT1, 20, 20);

    //Write style for SetDateTime_img_SetDT1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->SetDateTime_img_SetDT1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->SetDateTime_img_SetDT1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SetDateTime_img_SetDT1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->SetDateTime_img_SetDT1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of SetDateTime.


    //Update current screen layout.
    lv_obj_update_layout(ui->SetDateTime);

    //Init events for screen.
    events_init_SetDateTime(ui);
}

void deinit_scr_SetDateTime(void)
{
	
}
