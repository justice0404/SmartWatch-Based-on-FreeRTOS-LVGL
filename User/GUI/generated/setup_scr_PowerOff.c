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
void deinit_scr_PowerOff(void);
Page_t Page_PowerOff  = {"PowerOff",setup_scr_PowerOff,deinit_scr_PowerOff,&guider_ui.PowerOff};


void setup_scr_PowerOff(lv_ui *ui)
{
    //Write codes PowerOff
    ui->PowerOff = lv_obj_create(NULL);
    lv_obj_set_size(ui->PowerOff, 240, 280);
    lv_obj_set_scrollbar_mode(ui->PowerOff, LV_SCROLLBAR_MODE_OFF);

    //Write style for PowerOff, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->PowerOff, 215, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->PowerOff, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->PowerOff, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes PowerOff_slider_PowerOff
    ui->PowerOff_slider_PowerOff = lv_slider_create(ui->PowerOff);
    lv_slider_set_range(ui->PowerOff_slider_PowerOff, 0, 100);
    lv_slider_set_mode(ui->PowerOff_slider_PowerOff, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->PowerOff_slider_PowerOff, 10, LV_ANIM_OFF);
    lv_obj_set_pos(ui->PowerOff_slider_PowerOff, 20, 150);
    lv_obj_set_size(ui->PowerOff_slider_PowerOff, 200, 25);

    //Write style for PowerOff_slider_PowerOff, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->PowerOff_slider_PowerOff, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->PowerOff_slider_PowerOff, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->PowerOff_slider_PowerOff, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->PowerOff_slider_PowerOff, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->PowerOff_slider_PowerOff, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->PowerOff_slider_PowerOff, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for PowerOff_slider_PowerOff, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->PowerOff_slider_PowerOff, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->PowerOff_slider_PowerOff, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->PowerOff_slider_PowerOff, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->PowerOff_slider_PowerOff, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for PowerOff_slider_PowerOff, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->PowerOff_slider_PowerOff, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->PowerOff_slider_PowerOff, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->PowerOff_slider_PowerOff, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->PowerOff_slider_PowerOff, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes PowerOff_img_PowerOff
    ui->PowerOff_img_PowerOff = lv_img_create(ui->PowerOff);
    lv_obj_add_flag(ui->PowerOff_img_PowerOff, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->PowerOff_img_PowerOff, &_power_alpha_40x40);
    lv_img_set_pivot(ui->PowerOff_img_PowerOff, 50,50);
    lv_img_set_angle(ui->PowerOff_img_PowerOff, 0);
    lv_obj_set_pos(ui->PowerOff_img_PowerOff, 100, 55);
    lv_obj_set_size(ui->PowerOff_img_PowerOff, 40, 40);

    //Write style for PowerOff_img_PowerOff, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->PowerOff_img_PowerOff, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->PowerOff_img_PowerOff, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->PowerOff_img_PowerOff, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->PowerOff_img_PowerOff, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes PowerOff_label_PowerOffText
    ui->PowerOff_label_PowerOffText = lv_label_create(ui->PowerOff);
    lv_label_set_text(ui->PowerOff_label_PowerOffText, "Slide To Confirm\n");
    lv_label_set_long_mode(ui->PowerOff_label_PowerOffText, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->PowerOff_label_PowerOffText, 10, 220);
    lv_obj_set_size(ui->PowerOff_label_PowerOffText, 220, 32);

    //Write style for PowerOff_label_PowerOffText, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->PowerOff_label_PowerOffText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->PowerOff_label_PowerOffText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->PowerOff_label_PowerOffText, lv_color_hex(0xb3b3b3), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->PowerOff_label_PowerOffText, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->PowerOff_label_PowerOffText, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->PowerOff_label_PowerOffText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->PowerOff_label_PowerOffText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->PowerOff_label_PowerOffText, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->PowerOff_label_PowerOffText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->PowerOff_label_PowerOffText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->PowerOff_label_PowerOffText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->PowerOff_label_PowerOffText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->PowerOff_label_PowerOffText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->PowerOff_label_PowerOffText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of PowerOff.


    //Update current screen layout.
    lv_obj_update_layout(ui->PowerOff);

    //Init events for screen.
    events_init_PowerOff(ui);
}

void deinit_scr_PowerOff(void)
{
	
}
