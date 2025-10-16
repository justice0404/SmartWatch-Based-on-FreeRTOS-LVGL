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
void deinit_scr_SetOffTime(void);
Page_t Page_SetOffTime  = {"SetOffTime",setup_scr_SetOffTime,deinit_scr_SetOffTime,&guider_ui.SetOffTime};


void setup_scr_SetOffTime(lv_ui *ui)
{
    //Write codes SetOffTime
    ui->SetOffTime = lv_obj_create(NULL);
    lv_obj_set_size(ui->SetOffTime, 240, 280);
    lv_obj_set_scrollbar_mode(ui->SetOffTime, LV_SCROLLBAR_MODE_OFF);

    //Write style for SetOffTime, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->SetOffTime, 216, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SetOffTime, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SetOffTime, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SetOffTime_roller_SetOT
    ui->SetOffTime_roller_SetOT = lv_roller_create(ui->SetOffTime);
    lv_roller_set_options(ui->SetOffTime_roller_SetOT, "15\n20\n25\n35\n50\n65", LV_ROLLER_MODE_INFINITE);
	lv_roller_set_selected(ui->SetOffTime_roller_SetOT,ui_OffTimeSelected,LV_ANIM_OFF);
    lv_obj_set_pos(ui->SetOffTime_roller_SetOT, 60, 90);
    lv_obj_set_width(ui->SetOffTime_roller_SetOT, 120);

    //Write style for SetOffTime_roller_SetOT, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->SetOffTime_roller_SetOT, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->SetOffTime_roller_SetOT, 28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SetOffTime_roller_SetOT, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SetOffTime_roller_SetOT, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->SetOffTime_roller_SetOT, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->SetOffTime_roller_SetOT, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->SetOffTime_roller_SetOT, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->SetOffTime_roller_SetOT, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->SetOffTime_roller_SetOT, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->SetOffTime_roller_SetOT, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->SetOffTime_roller_SetOT, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SetOffTime_roller_SetOT, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for SetOffTime_roller_SetOT, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->SetOffTime_roller_SetOT, 125, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SetOffTime_roller_SetOT, lv_color_hex(0x2F92DA), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SetOffTime_roller_SetOT, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->SetOffTime_roller_SetOT, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->SetOffTime_roller_SetOT, &lv_font_montserratMedium_25, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->SetOffTime_roller_SetOT, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);

    lv_roller_set_visible_row_count(ui->SetOffTime_roller_SetOT, 3);
    //Write codes SetOffTime_img_SetOT
    ui->SetOffTime_img_SetOT = lv_img_create(ui->SetOffTime);
    lv_obj_add_flag(ui->SetOffTime_img_SetOT, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->SetOffTime_img_SetOT, &_TurnOff_alpha_30x30);
    lv_img_set_pivot(ui->SetOffTime_img_SetOT, 50,50);
    lv_img_set_angle(ui->SetOffTime_img_SetOT, 0);
    lv_obj_set_pos(ui->SetOffTime_img_SetOT, 105, 20);
    lv_obj_set_size(ui->SetOffTime_img_SetOT, 30, 30);

    //Write style for SetOffTime_img_SetOT, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->SetOffTime_img_SetOT, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->SetOffTime_img_SetOT, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SetOffTime_img_SetOT, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->SetOffTime_img_SetOT, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SetOffTime_img_SetOTConfirm
    ui->SetOffTime_img_SetOTConfirm = lv_img_create(ui->SetOffTime);
    lv_obj_add_flag(ui->SetOffTime_img_SetOTConfirm, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->SetOffTime_img_SetOTConfirm, &_confirm_alpha_30x30);
    lv_img_set_pivot(ui->SetOffTime_img_SetOTConfirm, 50,50);
    lv_img_set_angle(ui->SetOffTime_img_SetOTConfirm, 0);
    lv_obj_set_pos(ui->SetOffTime_img_SetOTConfirm, 105, 240);
    lv_obj_set_size(ui->SetOffTime_img_SetOTConfirm, 30, 30);

    //Write style for SetOffTime_img_SetOTConfirm, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->SetOffTime_img_SetOTConfirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->SetOffTime_img_SetOTConfirm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SetOffTime_img_SetOTConfirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->SetOffTime_img_SetOTConfirm, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SetOffTime_cont_SetOTConfirm
    ui->SetOffTime_cont_SetOTConfirm = lv_obj_create(ui->SetOffTime);
    lv_obj_set_pos(ui->SetOffTime_cont_SetOTConfirm, 0, 240);
    lv_obj_set_size(ui->SetOffTime_cont_SetOTConfirm, 240, 40);
    lv_obj_set_scrollbar_mode(ui->SetOffTime_cont_SetOTConfirm, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->SetOffTime_cont_SetOTConfirm, LV_OBJ_FLAG_CLICKABLE);

    //Write style for SetOffTime_cont_SetOTConfirm, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->SetOffTime_cont_SetOTConfirm, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->SetOffTime_cont_SetOTConfirm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->SetOffTime_cont_SetOTConfirm, lv_color_hex(0x0e0e0e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->SetOffTime_cont_SetOTConfirm, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SetOffTime_cont_SetOTConfirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->SetOffTime_cont_SetOTConfirm, 153, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->SetOffTime_cont_SetOTConfirm, lv_color_hex(0xa3a1a1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->SetOffTime_cont_SetOTConfirm, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->SetOffTime_cont_SetOTConfirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->SetOffTime_cont_SetOTConfirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->SetOffTime_cont_SetOTConfirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->SetOffTime_cont_SetOTConfirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SetOffTime_cont_SetOTConfirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes SetOffTime_label_SetOTIcon
    ui->SetOffTime_label_SetOTIcon = lv_label_create(ui->SetOffTime);
    lv_label_set_text(ui->SetOffTime_label_SetOTIcon, "sec");
    lv_label_set_long_mode(ui->SetOffTime_label_SetOTIcon, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->SetOffTime_label_SetOTIcon, 185, 127);
    lv_obj_set_size(ui->SetOffTime_label_SetOTIcon, 45, 30);

    //Write style for SetOffTime_label_SetOTIcon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->SetOffTime_label_SetOTIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->SetOffTime_label_SetOTIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->SetOffTime_label_SetOTIcon, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->SetOffTime_label_SetOTIcon, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->SetOffTime_label_SetOTIcon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->SetOffTime_label_SetOTIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->SetOffTime_label_SetOTIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->SetOffTime_label_SetOTIcon, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->SetOffTime_label_SetOTIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->SetOffTime_label_SetOTIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->SetOffTime_label_SetOTIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->SetOffTime_label_SetOTIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->SetOffTime_label_SetOTIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->SetOffTime_label_SetOTIcon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of SetOffTime.


    //Update current screen layout.
    lv_obj_update_layout(ui->SetOffTime);

    //Init events for screen.
    events_init_SetOffTime(ui);
}

void deinit_scr_SetOffTime(void)
{
	
}
