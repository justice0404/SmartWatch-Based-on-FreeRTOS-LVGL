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
void deinit_scr_Menu(void);
Page_t Page_Menu  = {"Menu",setup_scr_Menu,deinit_scr_Menu,&guider_ui.Menu};

void setup_scr_Menu(lv_ui *ui)
{
    //Write codes Menu
    ui->Menu = lv_obj_create(NULL);
    lv_obj_set_size(ui->Menu, 240, 280);
    lv_obj_set_scrollbar_mode(ui->Menu, LV_SCROLLBAR_MODE_AUTO);
    lv_obj_add_flag(ui->Menu, LV_OBJ_FLAG_SCROLLABLE);

    //Write style for Menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Menu, 216, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_cont_MenuSetting
    ui->Menu_cont_MenuSetting = lv_obj_create(ui->Menu);
    lv_obj_set_pos(ui->Menu_cont_MenuSetting, 0, 420);
    lv_obj_set_size(ui->Menu_cont_MenuSetting, 240, 60);
    lv_obj_set_scrollbar_mode(ui->Menu_cont_MenuSetting, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->Menu_cont_MenuSetting, LV_OBJ_FLAG_CLICKABLE);

    //Write style for Menu_cont_MenuSetting, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_cont_MenuSetting, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Menu_cont_MenuSetting, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Menu_cont_MenuSetting, lv_color_hex(0x5e5e5e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->Menu_cont_MenuSetting, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_cont_MenuSetting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_cont_MenuSetting, 222, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_cont_MenuSetting, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_cont_MenuSetting, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_cont_MenuSetting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_cont_MenuSetting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_cont_MenuSetting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_cont_MenuSetting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_cont_MenuSetting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_img_MenuSetting
    ui->Menu_img_MenuSetting = lv_img_create(ui->Menu_cont_MenuSetting);
    lv_obj_add_flag(ui->Menu_img_MenuSetting, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Menu_img_MenuSetting, &_setting_alpha_30x30);
    lv_img_set_pivot(ui->Menu_img_MenuSetting, 50,50);
    lv_img_set_angle(ui->Menu_img_MenuSetting, 0);
    lv_obj_set_pos(ui->Menu_img_MenuSetting, 15, 15);
    lv_obj_set_size(ui->Menu_img_MenuSetting, 30, 30);

    //Write style for Menu_img_MenuSetting, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Menu_img_MenuSetting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Menu_img_MenuSetting, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_img_MenuSetting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Menu_img_MenuSetting, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_label_MenuSetting
    ui->Menu_label_MenuSetting = lv_label_create(ui->Menu_cont_MenuSetting);
    lv_label_set_text(ui->Menu_label_MenuSetting, "Setting");
    lv_label_set_long_mode(ui->Menu_label_MenuSetting, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_label_MenuSetting, 70, 15);
    lv_obj_set_size(ui->Menu_label_MenuSetting, 100, 30);

    //Write style for Menu_label_MenuSetting, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_label_MenuSetting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_label_MenuSetting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_label_MenuSetting, lv_color_hex(0xf6f6f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_label_MenuSetting, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_label_MenuSetting, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_label_MenuSetting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_label_MenuSetting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_label_MenuSetting, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_label_MenuSetting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_label_MenuSetting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_label_MenuSetting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_label_MenuSetting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_label_MenuSetting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_label_MenuSetting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_cont_MenuGame
    ui->Menu_cont_MenuGame = lv_obj_create(ui->Menu);
    lv_obj_set_pos(ui->Menu_cont_MenuGame, 0, 360);
    lv_obj_set_size(ui->Menu_cont_MenuGame, 240, 60);
    lv_obj_set_scrollbar_mode(ui->Menu_cont_MenuGame, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->Menu_cont_MenuGame, LV_OBJ_FLAG_CLICKABLE);

    //Write style for Menu_cont_MenuGame, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_cont_MenuGame, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Menu_cont_MenuGame, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Menu_cont_MenuGame, lv_color_hex(0x5e5e5e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->Menu_cont_MenuGame, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_cont_MenuGame, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_cont_MenuGame, 208, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_cont_MenuGame, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_cont_MenuGame, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_cont_MenuGame, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_cont_MenuGame, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_cont_MenuGame, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_cont_MenuGame, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_cont_MenuGame, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_img_MenuGame
    ui->Menu_img_MenuGame = lv_img_create(ui->Menu_cont_MenuGame);
    lv_obj_add_flag(ui->Menu_img_MenuGame, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Menu_img_MenuGame, &_9_alpha_30x30);
    lv_img_set_pivot(ui->Menu_img_MenuGame, 50,50);
    lv_img_set_angle(ui->Menu_img_MenuGame, 0);
    lv_obj_set_pos(ui->Menu_img_MenuGame, 15, 15);
    lv_obj_set_size(ui->Menu_img_MenuGame, 30, 30);

    //Write style for Menu_img_MenuGame, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Menu_img_MenuGame, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Menu_img_MenuGame, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_img_MenuGame, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Menu_img_MenuGame, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_label_MenuGame
    ui->Menu_label_MenuGame = lv_label_create(ui->Menu_cont_MenuGame);
    lv_label_set_text(ui->Menu_label_MenuGame, "Game");
    lv_label_set_long_mode(ui->Menu_label_MenuGame, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_label_MenuGame, 70, 15);
    lv_obj_set_size(ui->Menu_label_MenuGame, 100, 30);

    //Write style for Menu_label_MenuGame, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_label_MenuGame, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_label_MenuGame, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_label_MenuGame, lv_color_hex(0xf6f6f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_label_MenuGame, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_label_MenuGame, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_label_MenuGame, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_label_MenuGame, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_label_MenuGame, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_label_MenuGame, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_label_MenuGame, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_label_MenuGame, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_label_MenuGame, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_label_MenuGame, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_label_MenuGame, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_cont_MenuCompass
    ui->Menu_cont_MenuCompass = lv_obj_create(ui->Menu);
    lv_obj_set_pos(ui->Menu_cont_MenuCompass, 0, 300);
    lv_obj_set_size(ui->Menu_cont_MenuCompass, 240, 60);
    lv_obj_set_scrollbar_mode(ui->Menu_cont_MenuCompass, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->Menu_cont_MenuCompass, LV_OBJ_FLAG_CLICKABLE);

    //Write style for Menu_cont_MenuCompass, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_cont_MenuCompass, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Menu_cont_MenuCompass, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Menu_cont_MenuCompass, lv_color_hex(0x5e5e5e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->Menu_cont_MenuCompass, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_cont_MenuCompass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_cont_MenuCompass, 222, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_cont_MenuCompass, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_cont_MenuCompass, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_cont_MenuCompass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_cont_MenuCompass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_cont_MenuCompass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_cont_MenuCompass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_cont_MenuCompass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_img_MenuCompass
    ui->Menu_img_MenuCompass = lv_img_create(ui->Menu_cont_MenuCompass);
    lv_obj_add_flag(ui->Menu_img_MenuCompass, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Menu_img_MenuCompass, &_3_alpha_30x30);
    lv_img_set_pivot(ui->Menu_img_MenuCompass, 50,50);
    lv_img_set_angle(ui->Menu_img_MenuCompass, 0);
    lv_obj_set_pos(ui->Menu_img_MenuCompass, 15, 15);
    lv_obj_set_size(ui->Menu_img_MenuCompass, 30, 30);

    //Write style for Menu_img_MenuCompass, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Menu_img_MenuCompass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Menu_img_MenuCompass, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_img_MenuCompass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Menu_img_MenuCompass, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_label_MenuCompass
    ui->Menu_label_MenuCompass = lv_label_create(ui->Menu_cont_MenuCompass);
    lv_label_set_text(ui->Menu_label_MenuCompass, "Compass");
    lv_label_set_long_mode(ui->Menu_label_MenuCompass, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_label_MenuCompass, 70, 15);
    lv_obj_set_size(ui->Menu_label_MenuCompass, 120, 30);

    //Write style for Menu_label_MenuCompass, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_label_MenuCompass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_label_MenuCompass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_label_MenuCompass, lv_color_hex(0xf6f6f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_label_MenuCompass, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_label_MenuCompass, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_label_MenuCompass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_label_MenuCompass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_label_MenuCompass, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_label_MenuCompass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_label_MenuCompass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_label_MenuCompass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_label_MenuCompass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_label_MenuCompass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_label_MenuCompass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_cont_MenuEnvironment
    ui->Menu_cont_MenuEnvironment = lv_obj_create(ui->Menu);
    lv_obj_set_pos(ui->Menu_cont_MenuEnvironment, 0, 240);
    lv_obj_set_size(ui->Menu_cont_MenuEnvironment, 240, 60);
    lv_obj_set_scrollbar_mode(ui->Menu_cont_MenuEnvironment, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->Menu_cont_MenuEnvironment, LV_OBJ_FLAG_CLICKABLE);

    //Write style for Menu_cont_MenuEnvironment, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_cont_MenuEnvironment, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Menu_cont_MenuEnvironment, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Menu_cont_MenuEnvironment, lv_color_hex(0x5e5e5e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->Menu_cont_MenuEnvironment, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_cont_MenuEnvironment, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_cont_MenuEnvironment, 222, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_cont_MenuEnvironment, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_cont_MenuEnvironment, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_cont_MenuEnvironment, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_cont_MenuEnvironment, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_cont_MenuEnvironment, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_cont_MenuEnvironment, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_cont_MenuEnvironment, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_img_MenuEnvironment
    ui->Menu_img_MenuEnvironment = lv_img_create(ui->Menu_cont_MenuEnvironment);
    lv_obj_add_flag(ui->Menu_img_MenuEnvironment, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Menu_img_MenuEnvironment, &_8_alpha_30x30);
    lv_img_set_pivot(ui->Menu_img_MenuEnvironment, 50,50);
    lv_img_set_angle(ui->Menu_img_MenuEnvironment, 0);
    lv_obj_set_pos(ui->Menu_img_MenuEnvironment, 15, 15);
    lv_obj_set_size(ui->Menu_img_MenuEnvironment, 30, 30);

    //Write style for Menu_img_MenuEnvironment, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Menu_img_MenuEnvironment, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Menu_img_MenuEnvironment, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_img_MenuEnvironment, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Menu_img_MenuEnvironment, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_label_MenuEnvironment
    ui->Menu_label_MenuEnvironment = lv_label_create(ui->Menu_cont_MenuEnvironment);
    lv_label_set_text(ui->Menu_label_MenuEnvironment, "Temp&Humi");
    lv_label_set_long_mode(ui->Menu_label_MenuEnvironment, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_label_MenuEnvironment, 70, 15);
    lv_obj_set_size(ui->Menu_label_MenuEnvironment, 160, 30);

    //Write style for Menu_label_MenuEnvironment, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_label_MenuEnvironment, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_label_MenuEnvironment, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_label_MenuEnvironment, lv_color_hex(0xf6f6f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_label_MenuEnvironment, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_label_MenuEnvironment, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_label_MenuEnvironment, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_label_MenuEnvironment, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_label_MenuEnvironment, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_label_MenuEnvironment, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_label_MenuEnvironment, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_label_MenuEnvironment, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_label_MenuEnvironment, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_label_MenuEnvironment, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_label_MenuEnvironment, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_cont_MenuHeart
    ui->Menu_cont_MenuHeart = lv_obj_create(ui->Menu);
    lv_obj_set_pos(ui->Menu_cont_MenuHeart, 0, 180);
    lv_obj_set_size(ui->Menu_cont_MenuHeart, 240, 60);
    lv_obj_set_scrollbar_mode(ui->Menu_cont_MenuHeart, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->Menu_cont_MenuHeart, LV_OBJ_FLAG_CLICKABLE);

    //Write style for Menu_cont_MenuHeart, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_cont_MenuHeart, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Menu_cont_MenuHeart, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Menu_cont_MenuHeart, lv_color_hex(0x5e5e5e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->Menu_cont_MenuHeart, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_cont_MenuHeart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_cont_MenuHeart, 222, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_cont_MenuHeart, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_cont_MenuHeart, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_cont_MenuHeart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_cont_MenuHeart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_cont_MenuHeart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_cont_MenuHeart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_cont_MenuHeart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_img_MenuHeart
    ui->Menu_img_MenuHeart = lv_img_create(ui->Menu_cont_MenuHeart);
    lv_obj_add_flag(ui->Menu_img_MenuHeart, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Menu_img_MenuHeart, &_1_alpha_30x30);
    lv_img_set_pivot(ui->Menu_img_MenuHeart, 50,50);
    lv_img_set_angle(ui->Menu_img_MenuHeart, 0);
    lv_obj_set_pos(ui->Menu_img_MenuHeart, 15, 15);
    lv_obj_set_size(ui->Menu_img_MenuHeart, 30, 30);

    //Write style for Menu_img_MenuHeart, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Menu_img_MenuHeart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Menu_img_MenuHeart, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_img_MenuHeart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Menu_img_MenuHeart, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_label_MenuHeart
    ui->Menu_label_MenuHeart = lv_label_create(ui->Menu_cont_MenuHeart);
    lv_label_set_text(ui->Menu_label_MenuHeart, "HeartRate");
    lv_label_set_long_mode(ui->Menu_label_MenuHeart, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_label_MenuHeart, 70, 15);
    lv_obj_set_size(ui->Menu_label_MenuHeart, 140, 30);

    //Write style for Menu_label_MenuHeart, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_label_MenuHeart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_label_MenuHeart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_label_MenuHeart, lv_color_hex(0xf6f6f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_label_MenuHeart, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_label_MenuHeart, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_label_MenuHeart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_label_MenuHeart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_label_MenuHeart, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_label_MenuHeart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_label_MenuHeart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_label_MenuHeart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_label_MenuHeart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_label_MenuHeart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_label_MenuHeart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_cont_MenuStopwatch
    ui->Menu_cont_MenuStopwatch = lv_obj_create(ui->Menu);
    lv_obj_set_pos(ui->Menu_cont_MenuStopwatch, 0, 120);
    lv_obj_set_size(ui->Menu_cont_MenuStopwatch, 240, 60);
    lv_obj_set_scrollbar_mode(ui->Menu_cont_MenuStopwatch, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->Menu_cont_MenuStopwatch, LV_OBJ_FLAG_CLICKABLE);

    //Write style for Menu_cont_MenuStopwatch, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_cont_MenuStopwatch, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Menu_cont_MenuStopwatch, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Menu_cont_MenuStopwatch, lv_color_hex(0x5e5e5e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->Menu_cont_MenuStopwatch, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_cont_MenuStopwatch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_cont_MenuStopwatch, 222, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_cont_MenuStopwatch, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_cont_MenuStopwatch, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_cont_MenuStopwatch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_cont_MenuStopwatch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_cont_MenuStopwatch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_cont_MenuStopwatch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_cont_MenuStopwatch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_img_MenuStopwatch
    ui->Menu_img_MenuStopwatch = lv_img_create(ui->Menu_cont_MenuStopwatch);
    lv_obj_add_flag(ui->Menu_img_MenuStopwatch, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Menu_img_MenuStopwatch, &_5_alpha_30x30);
    lv_img_set_pivot(ui->Menu_img_MenuStopwatch, 50,50);
    lv_img_set_angle(ui->Menu_img_MenuStopwatch, 0);
    lv_obj_set_pos(ui->Menu_img_MenuStopwatch, 15, 15);
    lv_obj_set_size(ui->Menu_img_MenuStopwatch, 30, 30);

    //Write style for Menu_img_MenuStopwatch, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Menu_img_MenuStopwatch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Menu_img_MenuStopwatch, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_img_MenuStopwatch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Menu_img_MenuStopwatch, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_label_MenuStopwatch
    ui->Menu_label_MenuStopwatch = lv_label_create(ui->Menu_cont_MenuStopwatch);
    lv_label_set_text(ui->Menu_label_MenuStopwatch, "StopWatch");
    lv_label_set_long_mode(ui->Menu_label_MenuStopwatch, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_label_MenuStopwatch, 70, 15);
    lv_obj_set_size(ui->Menu_label_MenuStopwatch, 150, 30);

    //Write style for Menu_label_MenuStopwatch, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_label_MenuStopwatch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_label_MenuStopwatch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_label_MenuStopwatch, lv_color_hex(0xf6f6f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_label_MenuStopwatch, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_label_MenuStopwatch, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_label_MenuStopwatch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_label_MenuStopwatch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_label_MenuStopwatch, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_label_MenuStopwatch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_label_MenuStopwatch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_label_MenuStopwatch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_label_MenuStopwatch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_label_MenuStopwatch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_label_MenuStopwatch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_cont_MenuCalculator
    ui->Menu_cont_MenuCalculator = lv_obj_create(ui->Menu);
    lv_obj_set_pos(ui->Menu_cont_MenuCalculator, 0, 61);
    lv_obj_set_size(ui->Menu_cont_MenuCalculator, 240, 60);
    lv_obj_set_scrollbar_mode(ui->Menu_cont_MenuCalculator, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->Menu_cont_MenuCalculator, LV_OBJ_FLAG_CLICKABLE);

    //Write style for Menu_cont_MenuCalculator, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_cont_MenuCalculator, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Menu_cont_MenuCalculator, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Menu_cont_MenuCalculator, lv_color_hex(0x5e5e5e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->Menu_cont_MenuCalculator, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_cont_MenuCalculator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_cont_MenuCalculator, 222, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_cont_MenuCalculator, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_cont_MenuCalculator, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_cont_MenuCalculator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_cont_MenuCalculator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_cont_MenuCalculator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_cont_MenuCalculator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_cont_MenuCalculator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_label_MenuCalculator
    ui->Menu_label_MenuCalculator = lv_label_create(ui->Menu_cont_MenuCalculator);
    lv_label_set_text(ui->Menu_label_MenuCalculator, "Calculator");
    lv_label_set_long_mode(ui->Menu_label_MenuCalculator, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_label_MenuCalculator, 70, 15);
    lv_obj_set_size(ui->Menu_label_MenuCalculator, 135, 30);

    //Write style for Menu_label_MenuCalculator, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_label_MenuCalculator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_label_MenuCalculator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_label_MenuCalculator, lv_color_hex(0xf6f6f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_label_MenuCalculator, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_label_MenuCalculator, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_label_MenuCalculator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_label_MenuCalculator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_label_MenuCalculator, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_label_MenuCalculator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_label_MenuCalculator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_label_MenuCalculator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_label_MenuCalculator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_label_MenuCalculator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_label_MenuCalculator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_img_MenuCalculater
    ui->Menu_img_MenuCalculater = lv_img_create(ui->Menu_cont_MenuCalculator);
    lv_obj_add_flag(ui->Menu_img_MenuCalculater, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Menu_img_MenuCalculater, &_4_alpha_30x30);
    lv_img_set_pivot(ui->Menu_img_MenuCalculater, 50,50);
    lv_img_set_angle(ui->Menu_img_MenuCalculater, 0);
    lv_obj_set_pos(ui->Menu_img_MenuCalculater, 15, 15);
    lv_obj_set_size(ui->Menu_img_MenuCalculater, 30, 30);

    //Write style for Menu_img_MenuCalculater, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Menu_img_MenuCalculater, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Menu_img_MenuCalculater, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_img_MenuCalculater, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Menu_img_MenuCalculater, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_cont_MenuCalendar
    ui->Menu_cont_MenuCalendar = lv_obj_create(ui->Menu);
    lv_obj_set_pos(ui->Menu_cont_MenuCalendar, 0, 0);
    lv_obj_set_size(ui->Menu_cont_MenuCalendar, 240, 60);
    lv_obj_set_scrollbar_mode(ui->Menu_cont_MenuCalendar, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->Menu_cont_MenuCalendar, LV_OBJ_FLAG_CLICKABLE);

    //Write style for Menu_cont_MenuCalendar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_cont_MenuCalendar, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Menu_cont_MenuCalendar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Menu_cont_MenuCalendar, lv_color_hex(0x5e5e5e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->Menu_cont_MenuCalendar, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_cont_MenuCalendar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_cont_MenuCalendar, 222, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_cont_MenuCalendar, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_cont_MenuCalendar, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_cont_MenuCalendar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_cont_MenuCalendar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_cont_MenuCalendar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_cont_MenuCalendar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_cont_MenuCalendar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_img_MenuCalender
    ui->Menu_img_MenuCalender = lv_img_create(ui->Menu_cont_MenuCalendar);
    lv_obj_add_flag(ui->Menu_img_MenuCalender, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Menu_img_MenuCalender, &_6_alpha_30x30);
    lv_img_set_pivot(ui->Menu_img_MenuCalender, 50,50);
    lv_img_set_angle(ui->Menu_img_MenuCalender, 0);
    lv_obj_set_pos(ui->Menu_img_MenuCalender, 15, 15);
    lv_obj_set_size(ui->Menu_img_MenuCalender, 30, 30);

    //Write style for Menu_img_MenuCalender, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Menu_img_MenuCalender, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Menu_img_MenuCalender, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_img_MenuCalender, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Menu_img_MenuCalender, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_label_MenuCalendar
    ui->Menu_label_MenuCalendar = lv_label_create(ui->Menu_cont_MenuCalendar);
    lv_label_set_text(ui->Menu_label_MenuCalendar, "Calendar");
    lv_label_set_long_mode(ui->Menu_label_MenuCalendar, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_label_MenuCalendar, 70, 15);
    lv_obj_set_size(ui->Menu_label_MenuCalendar, 120, 30);

    //Write style for Menu_label_MenuCalendar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_label_MenuCalendar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_label_MenuCalendar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_label_MenuCalendar, lv_color_hex(0xf6f6f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_label_MenuCalendar, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_label_MenuCalendar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_label_MenuCalendar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_label_MenuCalendar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_label_MenuCalendar, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_label_MenuCalendar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_label_MenuCalendar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_label_MenuCalendar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_label_MenuCalendar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_label_MenuCalendar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_label_MenuCalendar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Menu.


    //Update current screen layout.
    lv_obj_update_layout(ui->Menu);

    //Init events for screen.
    events_init_Menu(ui);
}

void deinit_scr_Menu(void)
{
	
}
