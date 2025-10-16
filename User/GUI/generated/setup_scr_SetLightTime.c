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
void deinit_scr_SetLightTime(void);
Page_t Page_SetLightTime  = {"SetLightTime",setup_scr_SetLightTime,deinit_scr_SetLightTime,&guider_ui.SetLightTime};


void setup_scr_SetLightTime(lv_ui *ui)
{
    //Write codes SetLightTime
    ui->SetLightTime = lv_obj_create(NULL);
    lv_obj_set_size(ui->SetLightTime, 240, 280);
    lv_obj_set_scrollbar_mode(ui->SetLightTime, LV_SCROLLBAR_MODE_OFF);

    //Write style for SetLightTime, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->SetLightTime, 216, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SetLightTime, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SetLightTime, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SetLightTime_roller_SetLT
    ui->SetLightTime_roller_SetLT = lv_roller_create(ui->SetLightTime);
    lv_roller_set_options(ui->SetLightTime_roller_SetLT, "10\n15\n20\n30\n45\n60", LV_ROLLER_MODE_INFINITE);
	lv_roller_set_selected(ui->SetLightTime_roller_SetLT,ui_LightTimeSelected,LV_ANIM_OFF);
    lv_obj_set_pos(ui->SetLightTime_roller_SetLT, 60, 90);
    lv_obj_set_width(ui->SetLightTime_roller_SetLT, 120);

    //Write style for SetLightTime_roller_SetLT, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->SetLightTime_roller_SetLT, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->SetLightTime_roller_SetLT, 28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SetLightTime_roller_SetLT, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SetLightTime_roller_SetLT, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->SetLightTime_roller_SetLT, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->SetLightTime_roller_SetLT, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->SetLightTime_roller_SetLT, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->SetLightTime_roller_SetLT, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->SetLightTime_roller_SetLT, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->SetLightTime_roller_SetLT, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->SetLightTime_roller_SetLT, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SetLightTime_roller_SetLT, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for SetLightTime_roller_SetLT, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->SetLightTime_roller_SetLT, 125, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SetLightTime_roller_SetLT, lv_color_hex(0x2F92DA), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SetLightTime_roller_SetLT, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->SetLightTime_roller_SetLT, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->SetLightTime_roller_SetLT, &lv_font_montserratMedium_25, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->SetLightTime_roller_SetLT, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);

    lv_roller_set_visible_row_count(ui->SetLightTime_roller_SetLT, 3);
    //Write codes SetLightTime_img_SetLT
    ui->SetLightTime_img_SetLT = lv_img_create(ui->SetLightTime);
    lv_obj_add_flag(ui->SetLightTime_img_SetLT, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->SetLightTime_img_SetLT, &_TurnOn_alpha_30x30);
    lv_img_set_pivot(ui->SetLightTime_img_SetLT, 50,50);
    lv_img_set_angle(ui->SetLightTime_img_SetLT, 0);
    lv_obj_set_pos(ui->SetLightTime_img_SetLT, 105, 20);
    lv_obj_set_size(ui->SetLightTime_img_SetLT, 30, 30);

    //Write style for SetLightTime_img_SetLT, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->SetLightTime_img_SetLT, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->SetLightTime_img_SetLT, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SetLightTime_img_SetLT, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->SetLightTime_img_SetLT, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SetLightTime_label_SetLTIcon
    ui->SetLightTime_label_SetLTIcon = lv_label_create(ui->SetLightTime);
    lv_label_set_text(ui->SetLightTime_label_SetLTIcon, "sec");
    lv_label_set_long_mode(ui->SetLightTime_label_SetLTIcon, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->SetLightTime_label_SetLTIcon, 185, 127);
    lv_obj_set_size(ui->SetLightTime_label_SetLTIcon, 45, 30);

    //Write style for SetLightTime_label_SetLTIcon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->SetLightTime_label_SetLTIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SetLightTime_label_SetLTIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->SetLightTime_label_SetLTIcon, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->SetLightTime_label_SetLTIcon, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->SetLightTime_label_SetLTIcon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->SetLightTime_label_SetLTIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->SetLightTime_label_SetLTIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->SetLightTime_label_SetLTIcon, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->SetLightTime_label_SetLTIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->SetLightTime_label_SetLTIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->SetLightTime_label_SetLTIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->SetLightTime_label_SetLTIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->SetLightTime_label_SetLTIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SetLightTime_label_SetLTIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SetLightTime_img_SetLTConfirm
    ui->SetLightTime_img_SetLTConfirm = lv_img_create(ui->SetLightTime);
    lv_obj_add_flag(ui->SetLightTime_img_SetLTConfirm, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->SetLightTime_img_SetLTConfirm, &_confirm_alpha_30x30);
    lv_img_set_pivot(ui->SetLightTime_img_SetLTConfirm, 50,50);
    lv_img_set_angle(ui->SetLightTime_img_SetLTConfirm, 0);
    lv_obj_set_pos(ui->SetLightTime_img_SetLTConfirm, 105, 240);
    lv_obj_set_size(ui->SetLightTime_img_SetLTConfirm, 30, 30);

    //Write style for SetLightTime_img_SetLTConfirm, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->SetLightTime_img_SetLTConfirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->SetLightTime_img_SetLTConfirm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SetLightTime_img_SetLTConfirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->SetLightTime_img_SetLTConfirm, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SetLightTime_cont_SetLTConfirm
    ui->SetLightTime_cont_SetLTConfirm = lv_obj_create(ui->SetLightTime);
    lv_obj_set_pos(ui->SetLightTime_cont_SetLTConfirm, 0, 240);
    lv_obj_set_size(ui->SetLightTime_cont_SetLTConfirm, 240, 40);
    lv_obj_set_scrollbar_mode(ui->SetLightTime_cont_SetLTConfirm, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->SetLightTime_cont_SetLTConfirm, LV_OBJ_FLAG_CLICKABLE);

    //Write style for SetLightTime_cont_SetLTConfirm, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->SetLightTime_cont_SetLTConfirm, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->SetLightTime_cont_SetLTConfirm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->SetLightTime_cont_SetLTConfirm, lv_color_hex(0x0e0e0e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->SetLightTime_cont_SetLTConfirm, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SetLightTime_cont_SetLTConfirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->SetLightTime_cont_SetLTConfirm, 153, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SetLightTime_cont_SetLTConfirm, lv_color_hex(0xa3a1a1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SetLightTime_cont_SetLTConfirm, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->SetLightTime_cont_SetLTConfirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->SetLightTime_cont_SetLTConfirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->SetLightTime_cont_SetLTConfirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->SetLightTime_cont_SetLTConfirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SetLightTime_cont_SetLTConfirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of SetLightTime.


    //Update current screen layout.
    lv_obj_update_layout(ui->SetLightTime);

    //Init events for screen.
    events_init_SetLightTime(ui);
}

void deinit_scr_SetLightTime(void)
{
	
}
