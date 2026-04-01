/*
* Copyright 2026 NXP
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



void setup_scr_Menu_Protect(lv_ui *ui)
{
    //Write codes Menu_Protect
    ui->Menu_Protect = lv_obj_create(NULL);
    lv_obj_set_size(ui->Menu_Protect, 960, 240);
    lv_obj_set_scrollbar_mode(ui->Menu_Protect, LV_SCROLLBAR_MODE_OFF);

    //Write style for Menu_Protect, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Menu_Protect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_cont
    ui->Menu_Protect_cont = lv_obj_create(ui->Menu_Protect);
    lv_obj_set_pos(ui->Menu_Protect_cont, 105, 0);
    lv_obj_set_size(ui->Menu_Protect_cont, 855, 240);
    lv_obj_set_scrollbar_mode(ui->Menu_Protect_cont, LV_SCROLLBAR_MODE_OFF);

    //Write style for Menu_Protect_cont, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_Protect_cont, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_cont, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_cont_1
    ui->Menu_Protect_cont_1 = lv_obj_create(ui->Menu_Protect_cont);
    lv_obj_set_pos(ui->Menu_Protect_cont_1, 0, 0);
    lv_obj_set_size(ui->Menu_Protect_cont_1, 855, 560);
    lv_obj_set_scrollbar_mode(ui->Menu_Protect_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for Menu_Protect_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_Protect_cont_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_ovp_state_v_unit
    ui->Menu_Protect_label_ovp_state_v_unit = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_ovp_state_v_unit, "");
    lv_label_set_long_mode(ui->Menu_Protect_label_ovp_state_v_unit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_ovp_state_v_unit, 210, 40);
    lv_obj_set_size(ui->Menu_Protect_label_ovp_state_v_unit, 180, 35);

    //Write style for Menu_Protect_label_ovp_state_v_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_ovp_state_v_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_ovp_state_v_unit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_ovp_state_v_unit, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_ovp_state_v_unit, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_ovp_state_v_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_ovp_state_v_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_ovp_state_v_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_ovp_state_v_unit, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_ovp_state_v_unit, 70, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_Protect_label_ovp_state_v_unit, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_label_ovp_state_v_unit, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_ovp_state_v_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_ovp_state_v_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_ovp_state_v_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_ovp_state_v_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_ovp_state_v_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_ovp_state_v_set
    ui->Menu_Protect_label_ovp_state_v_set = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_ovp_state_v_set, "123.456V");
    lv_label_set_long_mode(ui->Menu_Protect_label_ovp_state_v_set, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_ovp_state_v_set, 212, 0);
    lv_obj_set_size(ui->Menu_Protect_label_ovp_state_v_set, 185, 80);

    //Write style for Menu_Protect_label_ovp_state_v_set, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_ovp_state_v_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_ovp_state_v_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_ovp_state_v_set, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_ovp_state_v_set, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_ovp_state_v_set, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_ovp_state_v_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_ovp_state_v_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_ovp_state_v_set, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_ovp_state_v_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_ovp_state_v_set, 40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_ovp_state_v_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_ovp_state_v_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_ovp_state_v_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_ovp_state_v_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_ovp_state_v
    ui->Menu_Protect_label_ovp_state_v = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_ovp_state_v, "Voltage");
    lv_label_set_long_mode(ui->Menu_Protect_label_ovp_state_v, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_ovp_state_v, 226, 0);
    lv_obj_set_size(ui->Menu_Protect_label_ovp_state_v, 160, 42);

    //Write style for Menu_Protect_label_ovp_state_v, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_ovp_state_v, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_ovp_state_v, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_ovp_state_v, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_ovp_state_v, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_ovp_state_v, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_ovp_state_v, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_ovp_state_v, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_ovp_state_v, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_ovp_state_v, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_ovp_state_v, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_ovp_state_v, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_ovp_state_v, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_ovp_state_v, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_ovp_state_v, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_ovp_state_delay_unit
    ui->Menu_Protect_label_ovp_state_delay_unit = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_ovp_state_delay_unit, "");
    lv_label_set_long_mode(ui->Menu_Protect_label_ovp_state_delay_unit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_ovp_state_delay_unit, 445, 40);
    lv_obj_set_size(ui->Menu_Protect_label_ovp_state_delay_unit, 180, 35);

    //Write style for Menu_Protect_label_ovp_state_delay_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_ovp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_ovp_state_delay_unit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_ovp_state_delay_unit, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_ovp_state_delay_unit, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_ovp_state_delay_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_ovp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_ovp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_ovp_state_delay_unit, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_ovp_state_delay_unit, 70, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_Protect_label_ovp_state_delay_unit, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_label_ovp_state_delay_unit, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_ovp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_ovp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_ovp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_ovp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_ovp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_ovp_state_delay_set
    ui->Menu_Protect_label_ovp_state_delay_set = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_ovp_state_delay_set, "12.456S");
    lv_label_set_long_mode(ui->Menu_Protect_label_ovp_state_delay_set, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_ovp_state_delay_set, 441, 0);
    lv_obj_set_size(ui->Menu_Protect_label_ovp_state_delay_set, 180, 80);

    //Write style for Menu_Protect_label_ovp_state_delay_set, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_ovp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_ovp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_ovp_state_delay_set, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_ovp_state_delay_set, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_ovp_state_delay_set, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_ovp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_ovp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_ovp_state_delay_set, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_ovp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_ovp_state_delay_set, 40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_ovp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_ovp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_ovp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_ovp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_ovp_state_delay
    ui->Menu_Protect_label_ovp_state_delay = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_ovp_state_delay, "Delay");
    lv_label_set_long_mode(ui->Menu_Protect_label_ovp_state_delay, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_ovp_state_delay, 455, -1);
    lv_obj_set_size(ui->Menu_Protect_label_ovp_state_delay, 160, 42);

    //Write style for Menu_Protect_label_ovp_state_delay, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_ovp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_ovp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_ovp_state_delay, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_ovp_state_delay, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_ovp_state_delay, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_ovp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_ovp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_ovp_state_delay, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_ovp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_ovp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_ovp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_ovp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_ovp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_ovp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_ocp_state_pos_i_unit
    ui->Menu_Protect_label_ocp_state_pos_i_unit = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_ocp_state_pos_i_unit, "");
    lv_label_set_long_mode(ui->Menu_Protect_label_ocp_state_pos_i_unit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_ocp_state_pos_i_unit, 210, 121);
    lv_obj_set_size(ui->Menu_Protect_label_ocp_state_pos_i_unit, 180, 35);

    //Write style for Menu_Protect_label_ocp_state_pos_i_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_ocp_state_pos_i_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_ocp_state_pos_i_unit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_ocp_state_pos_i_unit, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_ocp_state_pos_i_unit, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_ocp_state_pos_i_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_ocp_state_pos_i_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_ocp_state_pos_i_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_ocp_state_pos_i_unit, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_ocp_state_pos_i_unit, 70, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_Protect_label_ocp_state_pos_i_unit, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_label_ocp_state_pos_i_unit, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_ocp_state_pos_i_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_ocp_state_pos_i_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_ocp_state_pos_i_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_ocp_state_pos_i_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_ocp_state_pos_i_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_ocp_state_pos_i_set
    ui->Menu_Protect_label_ocp_state_pos_i_set = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_ocp_state_pos_i_set, "123.456A");
    lv_label_set_long_mode(ui->Menu_Protect_label_ocp_state_pos_i_set, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_ocp_state_pos_i_set, 212, 81);
    lv_obj_set_size(ui->Menu_Protect_label_ocp_state_pos_i_set, 185, 80);

    //Write style for Menu_Protect_label_ocp_state_pos_i_set, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_ocp_state_pos_i_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_ocp_state_pos_i_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_ocp_state_pos_i_set, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_ocp_state_pos_i_set, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_ocp_state_pos_i_set, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_ocp_state_pos_i_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_ocp_state_pos_i_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_ocp_state_pos_i_set, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_ocp_state_pos_i_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_ocp_state_pos_i_set, 40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_ocp_state_pos_i_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_ocp_state_pos_i_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_ocp_state_pos_i_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_ocp_state_pos_i_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_ocp_state_pos_i
    ui->Menu_Protect_label_ocp_state_pos_i = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_ocp_state_pos_i, "+Current");
    lv_label_set_long_mode(ui->Menu_Protect_label_ocp_state_pos_i, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_ocp_state_pos_i, 226, 80);
    lv_obj_set_size(ui->Menu_Protect_label_ocp_state_pos_i, 160, 42);

    //Write style for Menu_Protect_label_ocp_state_pos_i, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_ocp_state_pos_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_ocp_state_pos_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_ocp_state_pos_i, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_ocp_state_pos_i, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_ocp_state_pos_i, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_ocp_state_pos_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_ocp_state_pos_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_ocp_state_pos_i, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_ocp_state_pos_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_ocp_state_pos_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_ocp_state_pos_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_ocp_state_pos_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_ocp_state_pos_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_ocp_state_pos_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_ocp_state_neg_i_unit
    ui->Menu_Protect_label_ocp_state_neg_i_unit = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_ocp_state_neg_i_unit, "");
    lv_label_set_long_mode(ui->Menu_Protect_label_ocp_state_neg_i_unit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_ocp_state_neg_i_unit, 442, 121);
    lv_obj_set_size(ui->Menu_Protect_label_ocp_state_neg_i_unit, 180, 35);

    //Write style for Menu_Protect_label_ocp_state_neg_i_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_ocp_state_neg_i_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_ocp_state_neg_i_unit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_ocp_state_neg_i_unit, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_ocp_state_neg_i_unit, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_ocp_state_neg_i_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_ocp_state_neg_i_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_ocp_state_neg_i_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_ocp_state_neg_i_unit, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_ocp_state_neg_i_unit, 70, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_Protect_label_ocp_state_neg_i_unit, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_label_ocp_state_neg_i_unit, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_ocp_state_neg_i_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_ocp_state_neg_i_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_ocp_state_neg_i_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_ocp_state_neg_i_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_ocp_state_neg_i_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_ocp_state_neg_i_set
    ui->Menu_Protect_label_ocp_state_neg_i_set = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_ocp_state_neg_i_set, "-123.456A");
    lv_label_set_long_mode(ui->Menu_Protect_label_ocp_state_neg_i_set, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_ocp_state_neg_i_set, 441, 81);
    lv_obj_set_size(ui->Menu_Protect_label_ocp_state_neg_i_set, 185, 80);

    //Write style for Menu_Protect_label_ocp_state_neg_i_set, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_ocp_state_neg_i_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_ocp_state_neg_i_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_ocp_state_neg_i_set, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_ocp_state_neg_i_set, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_ocp_state_neg_i_set, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_ocp_state_neg_i_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_ocp_state_neg_i_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_ocp_state_neg_i_set, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_ocp_state_neg_i_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_ocp_state_neg_i_set, 40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_ocp_state_neg_i_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_ocp_state_neg_i_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_ocp_state_neg_i_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_ocp_state_neg_i_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_ocp_state_neg_i
    ui->Menu_Protect_label_ocp_state_neg_i = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_ocp_state_neg_i, "-Current");
    lv_label_set_long_mode(ui->Menu_Protect_label_ocp_state_neg_i, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_ocp_state_neg_i, 455, 77);
    lv_obj_set_size(ui->Menu_Protect_label_ocp_state_neg_i, 160, 42);

    //Write style for Menu_Protect_label_ocp_state_neg_i, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_ocp_state_neg_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_ocp_state_neg_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_ocp_state_neg_i, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_ocp_state_neg_i, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_ocp_state_neg_i, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_ocp_state_neg_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_ocp_state_neg_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_ocp_state_neg_i, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_ocp_state_neg_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_ocp_state_neg_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_ocp_state_neg_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_ocp_state_neg_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_ocp_state_neg_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_ocp_state_neg_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_ocp_state_delay_unit
    ui->Menu_Protect_label_ocp_state_delay_unit = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_ocp_state_delay_unit, "");
    lv_label_set_long_mode(ui->Menu_Protect_label_ocp_state_delay_unit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_ocp_state_delay_unit, 665, 121);
    lv_obj_set_size(ui->Menu_Protect_label_ocp_state_delay_unit, 180, 35);

    //Write style for Menu_Protect_label_ocp_state_delay_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_ocp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_ocp_state_delay_unit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_ocp_state_delay_unit, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_ocp_state_delay_unit, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_ocp_state_delay_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_ocp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_ocp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_ocp_state_delay_unit, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_ocp_state_delay_unit, 70, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_Protect_label_ocp_state_delay_unit, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_label_ocp_state_delay_unit, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_ocp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_ocp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_ocp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_ocp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_ocp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_ocp_state_delay_set
    ui->Menu_Protect_label_ocp_state_delay_set = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_ocp_state_delay_set, "123.456");
    lv_label_set_long_mode(ui->Menu_Protect_label_ocp_state_delay_set, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_ocp_state_delay_set, 665, 81);
    lv_obj_set_size(ui->Menu_Protect_label_ocp_state_delay_set, 185, 80);

    //Write style for Menu_Protect_label_ocp_state_delay_set, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_ocp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_ocp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_ocp_state_delay_set, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_ocp_state_delay_set, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_ocp_state_delay_set, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_ocp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_ocp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_ocp_state_delay_set, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_ocp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_ocp_state_delay_set, 40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_ocp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_ocp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_ocp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_ocp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_ocp_state_delay
    ui->Menu_Protect_label_ocp_state_delay = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_ocp_state_delay, "Delay");
    lv_label_set_long_mode(ui->Menu_Protect_label_ocp_state_delay, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_ocp_state_delay, 675, 78);
    lv_obj_set_size(ui->Menu_Protect_label_ocp_state_delay, 160, 42);

    //Write style for Menu_Protect_label_ocp_state_delay, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_ocp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_ocp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_ocp_state_delay, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_ocp_state_delay, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_ocp_state_delay, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_ocp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_ocp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_ocp_state_delay, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_ocp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_ocp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_ocp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_ocp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_ocp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_ocp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_opp_state_pos_w_unit
    ui->Menu_Protect_label_opp_state_pos_w_unit = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_opp_state_pos_w_unit, "");
    lv_label_set_long_mode(ui->Menu_Protect_label_opp_state_pos_w_unit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_opp_state_pos_w_unit, 210, 201);
    lv_obj_set_size(ui->Menu_Protect_label_opp_state_pos_w_unit, 180, 35);

    //Write style for Menu_Protect_label_opp_state_pos_w_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_opp_state_pos_w_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_opp_state_pos_w_unit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_opp_state_pos_w_unit, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_opp_state_pos_w_unit, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_opp_state_pos_w_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_opp_state_pos_w_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_opp_state_pos_w_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_opp_state_pos_w_unit, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_opp_state_pos_w_unit, 70, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_Protect_label_opp_state_pos_w_unit, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_label_opp_state_pos_w_unit, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_opp_state_pos_w_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_opp_state_pos_w_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_opp_state_pos_w_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_opp_state_pos_w_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_opp_state_pos_w_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_opp_state_pos_w_set
    ui->Menu_Protect_label_opp_state_pos_w_set = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_opp_state_pos_w_set, "123.456W");
    lv_label_set_long_mode(ui->Menu_Protect_label_opp_state_pos_w_set, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_opp_state_pos_w_set, 212, 161);
    lv_obj_set_size(ui->Menu_Protect_label_opp_state_pos_w_set, 185, 80);

    //Write style for Menu_Protect_label_opp_state_pos_w_set, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_opp_state_pos_w_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_opp_state_pos_w_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_opp_state_pos_w_set, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_opp_state_pos_w_set, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_opp_state_pos_w_set, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_opp_state_pos_w_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_opp_state_pos_w_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_opp_state_pos_w_set, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_opp_state_pos_w_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_opp_state_pos_w_set, 40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_opp_state_pos_w_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_opp_state_pos_w_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_opp_state_pos_w_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_opp_state_pos_w_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_opp_state_pos_w
    ui->Menu_Protect_label_opp_state_pos_w = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_opp_state_pos_w, "+Power");
    lv_label_set_long_mode(ui->Menu_Protect_label_opp_state_pos_w, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_opp_state_pos_w, 226, 160);
    lv_obj_set_size(ui->Menu_Protect_label_opp_state_pos_w, 160, 42);

    //Write style for Menu_Protect_label_opp_state_pos_w, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_opp_state_pos_w, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_opp_state_pos_w, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_opp_state_pos_w, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_opp_state_pos_w, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_opp_state_pos_w, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_opp_state_pos_w, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_opp_state_pos_w, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_opp_state_pos_w, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_opp_state_pos_w, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_opp_state_pos_w, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_opp_state_pos_w, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_opp_state_pos_w, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_opp_state_pos_w, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_opp_state_pos_w, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_opp_state_neg_w_unit
    ui->Menu_Protect_label_opp_state_neg_w_unit = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_opp_state_neg_w_unit, "");
    lv_label_set_long_mode(ui->Menu_Protect_label_opp_state_neg_w_unit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_opp_state_neg_w_unit, 442, 201);
    lv_obj_set_size(ui->Menu_Protect_label_opp_state_neg_w_unit, 180, 35);

    //Write style for Menu_Protect_label_opp_state_neg_w_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_opp_state_neg_w_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_opp_state_neg_w_unit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_opp_state_neg_w_unit, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_opp_state_neg_w_unit, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_opp_state_neg_w_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_opp_state_neg_w_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_opp_state_neg_w_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_opp_state_neg_w_unit, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_opp_state_neg_w_unit, 70, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_Protect_label_opp_state_neg_w_unit, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_label_opp_state_neg_w_unit, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_opp_state_neg_w_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_opp_state_neg_w_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_opp_state_neg_w_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_opp_state_neg_w_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_opp_state_neg_w_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_opp_state_neg_w_set
    ui->Menu_Protect_label_opp_state_neg_w_set = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_opp_state_neg_w_set, "-123.456W");
    lv_label_set_long_mode(ui->Menu_Protect_label_opp_state_neg_w_set, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_opp_state_neg_w_set, 441, 161);
    lv_obj_set_size(ui->Menu_Protect_label_opp_state_neg_w_set, 185, 80);

    //Write style for Menu_Protect_label_opp_state_neg_w_set, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_opp_state_neg_w_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_opp_state_neg_w_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_opp_state_neg_w_set, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_opp_state_neg_w_set, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_opp_state_neg_w_set, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_opp_state_neg_w_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_opp_state_neg_w_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_opp_state_neg_w_set, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_opp_state_neg_w_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_opp_state_neg_w_set, 40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_opp_state_neg_w_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_opp_state_neg_w_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_opp_state_neg_w_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_opp_state_neg_w_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_opp_state_neg_w
    ui->Menu_Protect_label_opp_state_neg_w = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_opp_state_neg_w, "-Power");
    lv_label_set_long_mode(ui->Menu_Protect_label_opp_state_neg_w, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_opp_state_neg_w, 455, 159);
    lv_obj_set_size(ui->Menu_Protect_label_opp_state_neg_w, 160, 42);

    //Write style for Menu_Protect_label_opp_state_neg_w, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_opp_state_neg_w, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_opp_state_neg_w, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_opp_state_neg_w, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_opp_state_neg_w, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_opp_state_neg_w, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_opp_state_neg_w, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_opp_state_neg_w, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_opp_state_neg_w, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_opp_state_neg_w, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_opp_state_neg_w, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_opp_state_neg_w, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_opp_state_neg_w, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_opp_state_neg_w, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_opp_state_neg_w, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_opp_state_delay_unit
    ui->Menu_Protect_label_opp_state_delay_unit = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_opp_state_delay_unit, "");
    lv_label_set_long_mode(ui->Menu_Protect_label_opp_state_delay_unit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_opp_state_delay_unit, 665, 201);
    lv_obj_set_size(ui->Menu_Protect_label_opp_state_delay_unit, 180, 35);

    //Write style for Menu_Protect_label_opp_state_delay_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_opp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_opp_state_delay_unit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_opp_state_delay_unit, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_opp_state_delay_unit, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_opp_state_delay_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_opp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_opp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_opp_state_delay_unit, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_opp_state_delay_unit, 70, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_Protect_label_opp_state_delay_unit, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_label_opp_state_delay_unit, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_opp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_opp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_opp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_opp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_opp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_opp_state_delay_set
    ui->Menu_Protect_label_opp_state_delay_set = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_opp_state_delay_set, "123.456S");
    lv_label_set_long_mode(ui->Menu_Protect_label_opp_state_delay_set, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_opp_state_delay_set, 665, 161);
    lv_obj_set_size(ui->Menu_Protect_label_opp_state_delay_set, 185, 80);

    //Write style for Menu_Protect_label_opp_state_delay_set, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_opp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_opp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_opp_state_delay_set, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_opp_state_delay_set, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_opp_state_delay_set, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_opp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_opp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_opp_state_delay_set, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_opp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_opp_state_delay_set, 40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_opp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_opp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_opp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_opp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_opp_state_delay
    ui->Menu_Protect_label_opp_state_delay = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_opp_state_delay, "Delay");
    lv_label_set_long_mode(ui->Menu_Protect_label_opp_state_delay, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_opp_state_delay, 675, 160);
    lv_obj_set_size(ui->Menu_Protect_label_opp_state_delay, 160, 42);

    //Write style for Menu_Protect_label_opp_state_delay, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_opp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_opp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_opp_state_delay, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_opp_state_delay, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_opp_state_delay, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_opp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_opp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_opp_state_delay, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_opp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_opp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_opp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_opp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_opp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_opp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_uvp_state_v_unit
    ui->Menu_Protect_label_uvp_state_v_unit = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_uvp_state_v_unit, "");
    lv_label_set_long_mode(ui->Menu_Protect_label_uvp_state_v_unit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_uvp_state_v_unit, 210, 281);
    lv_obj_set_size(ui->Menu_Protect_label_uvp_state_v_unit, 180, 35);

    //Write style for Menu_Protect_label_uvp_state_v_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_uvp_state_v_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_uvp_state_v_unit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_uvp_state_v_unit, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_uvp_state_v_unit, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_uvp_state_v_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_uvp_state_v_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_uvp_state_v_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_uvp_state_v_unit, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_uvp_state_v_unit, 70, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_Protect_label_uvp_state_v_unit, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_label_uvp_state_v_unit, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_uvp_state_v_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_uvp_state_v_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_uvp_state_v_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_uvp_state_v_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_uvp_state_v_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_uvp_state_v_set
    ui->Menu_Protect_label_uvp_state_v_set = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_uvp_state_v_set, "123.456V");
    lv_label_set_long_mode(ui->Menu_Protect_label_uvp_state_v_set, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_uvp_state_v_set, 212, 241);
    lv_obj_set_size(ui->Menu_Protect_label_uvp_state_v_set, 185, 80);

    //Write style for Menu_Protect_label_uvp_state_v_set, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_uvp_state_v_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_uvp_state_v_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_uvp_state_v_set, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_uvp_state_v_set, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_uvp_state_v_set, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_uvp_state_v_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_uvp_state_v_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_uvp_state_v_set, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_uvp_state_v_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_uvp_state_v_set, 40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_uvp_state_v_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_uvp_state_v_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_uvp_state_v_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_uvp_state_v_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_uvp_state_v
    ui->Menu_Protect_label_uvp_state_v = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_uvp_state_v, "Voltage");
    lv_label_set_long_mode(ui->Menu_Protect_label_uvp_state_v, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_uvp_state_v, 226, 241);
    lv_obj_set_size(ui->Menu_Protect_label_uvp_state_v, 160, 42);

    //Write style for Menu_Protect_label_uvp_state_v, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_uvp_state_v, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_uvp_state_v, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_uvp_state_v, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_uvp_state_v, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_uvp_state_v, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_uvp_state_v, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_uvp_state_v, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_uvp_state_v, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_uvp_state_v, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_uvp_state_v, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_uvp_state_v, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_uvp_state_v, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_uvp_state_v, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_uvp_state_v, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_uvp_state_warm_unit
    ui->Menu_Protect_label_uvp_state_warm_unit = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_uvp_state_warm_unit, "");
    lv_label_set_long_mode(ui->Menu_Protect_label_uvp_state_warm_unit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_uvp_state_warm_unit, 442, 281);
    lv_obj_set_size(ui->Menu_Protect_label_uvp_state_warm_unit, 180, 35);

    //Write style for Menu_Protect_label_uvp_state_warm_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_uvp_state_warm_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_uvp_state_warm_unit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_uvp_state_warm_unit, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_uvp_state_warm_unit, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_uvp_state_warm_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_uvp_state_warm_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_uvp_state_warm_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_uvp_state_warm_unit, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_uvp_state_warm_unit, 70, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_Protect_label_uvp_state_warm_unit, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_label_uvp_state_warm_unit, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_uvp_state_warm_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_uvp_state_warm_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_uvp_state_warm_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_uvp_state_warm_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_uvp_state_warm_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_uvp_state_warm_set
    ui->Menu_Protect_label_uvp_state_warm_set = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_uvp_state_warm_set, "123.456S");
    lv_label_set_long_mode(ui->Menu_Protect_label_uvp_state_warm_set, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_uvp_state_warm_set, 439, 241);
    lv_obj_set_size(ui->Menu_Protect_label_uvp_state_warm_set, 180, 80);

    //Write style for Menu_Protect_label_uvp_state_warm_set, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_uvp_state_warm_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_uvp_state_warm_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_uvp_state_warm_set, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_uvp_state_warm_set, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_uvp_state_warm_set, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_uvp_state_warm_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_uvp_state_warm_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_uvp_state_warm_set, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_uvp_state_warm_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_uvp_state_warm_set, 40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_uvp_state_warm_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_uvp_state_warm_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_uvp_state_warm_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_uvp_state_warm_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_uvp_state_warm
    ui->Menu_Protect_label_uvp_state_warm = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_uvp_state_warm, "Warm Time");
    lv_label_set_long_mode(ui->Menu_Protect_label_uvp_state_warm, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_uvp_state_warm, 422, 238);
    lv_obj_set_size(ui->Menu_Protect_label_uvp_state_warm, 225, 37);

    //Write style for Menu_Protect_label_uvp_state_warm, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_uvp_state_warm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_uvp_state_warm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_uvp_state_warm, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_uvp_state_warm, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_uvp_state_warm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_uvp_state_warm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_uvp_state_warm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_uvp_state_warm, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_uvp_state_warm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_uvp_state_warm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_uvp_state_warm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_uvp_state_warm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_uvp_state_warm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_uvp_state_warm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_uvp_state_delay_unit
    ui->Menu_Protect_label_uvp_state_delay_unit = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_uvp_state_delay_unit, "");
    lv_label_set_long_mode(ui->Menu_Protect_label_uvp_state_delay_unit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_uvp_state_delay_unit, 665, 281);
    lv_obj_set_size(ui->Menu_Protect_label_uvp_state_delay_unit, 180, 35);

    //Write style for Menu_Protect_label_uvp_state_delay_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_uvp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_uvp_state_delay_unit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_uvp_state_delay_unit, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_uvp_state_delay_unit, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_uvp_state_delay_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_uvp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_uvp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_uvp_state_delay_unit, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_uvp_state_delay_unit, 70, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_Protect_label_uvp_state_delay_unit, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_label_uvp_state_delay_unit, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_uvp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_uvp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_uvp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_uvp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_uvp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_uvp_state_delay_set
    ui->Menu_Protect_label_uvp_state_delay_set = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_uvp_state_delay_set, "123.456S");
    lv_label_set_long_mode(ui->Menu_Protect_label_uvp_state_delay_set, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_uvp_state_delay_set, 663, 241);
    lv_obj_set_size(ui->Menu_Protect_label_uvp_state_delay_set, 185, 80);

    //Write style for Menu_Protect_label_uvp_state_delay_set, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_uvp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_uvp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_uvp_state_delay_set, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_uvp_state_delay_set, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_uvp_state_delay_set, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_uvp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_uvp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_uvp_state_delay_set, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_uvp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_uvp_state_delay_set, 40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_uvp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_uvp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_uvp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_uvp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_uvp_state_delay
    ui->Menu_Protect_label_uvp_state_delay = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_uvp_state_delay, "Delay");
    lv_label_set_long_mode(ui->Menu_Protect_label_uvp_state_delay, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_uvp_state_delay, 675, 240);
    lv_obj_set_size(ui->Menu_Protect_label_uvp_state_delay, 160, 42);

    //Write style for Menu_Protect_label_uvp_state_delay, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_uvp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_uvp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_uvp_state_delay, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_uvp_state_delay, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_uvp_state_delay, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_uvp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_uvp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_uvp_state_delay, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_uvp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_uvp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_uvp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_uvp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_uvp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_uvp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_ucp_state_i_pos_unit
    ui->Menu_Protect_label_ucp_state_i_pos_unit = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_ucp_state_i_pos_unit, "");
    lv_label_set_long_mode(ui->Menu_Protect_label_ucp_state_i_pos_unit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_ucp_state_i_pos_unit, 210, 360);
    lv_obj_set_size(ui->Menu_Protect_label_ucp_state_i_pos_unit, 180, 35);

    //Write style for Menu_Protect_label_ucp_state_i_pos_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_ucp_state_i_pos_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_ucp_state_i_pos_unit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_ucp_state_i_pos_unit, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_ucp_state_i_pos_unit, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_ucp_state_i_pos_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_ucp_state_i_pos_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_ucp_state_i_pos_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_ucp_state_i_pos_unit, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_ucp_state_i_pos_unit, 70, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_Protect_label_ucp_state_i_pos_unit, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_label_ucp_state_i_pos_unit, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_ucp_state_i_pos_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_ucp_state_i_pos_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_ucp_state_i_pos_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_ucp_state_i_pos_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_ucp_state_i_pos_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_ucp_state_i_pos_set
    ui->Menu_Protect_label_ucp_state_i_pos_set = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_ucp_state_i_pos_set, "123.456A");
    lv_label_set_long_mode(ui->Menu_Protect_label_ucp_state_i_pos_set, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_ucp_state_i_pos_set, 212, 319);
    lv_obj_set_size(ui->Menu_Protect_label_ucp_state_i_pos_set, 185, 80);

    //Write style for Menu_Protect_label_ucp_state_i_pos_set, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_ucp_state_i_pos_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_ucp_state_i_pos_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_ucp_state_i_pos_set, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_ucp_state_i_pos_set, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_ucp_state_i_pos_set, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_ucp_state_i_pos_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_ucp_state_i_pos_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_ucp_state_i_pos_set, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_ucp_state_i_pos_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_ucp_state_i_pos_set, 40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_ucp_state_i_pos_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_ucp_state_i_pos_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_ucp_state_i_pos_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_ucp_state_i_pos_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_ucp_state_i_pos
    ui->Menu_Protect_label_ucp_state_i_pos = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_ucp_state_i_pos, "+Current");
    lv_label_set_long_mode(ui->Menu_Protect_label_ucp_state_i_pos, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_ucp_state_i_pos, 226, 323);
    lv_obj_set_size(ui->Menu_Protect_label_ucp_state_i_pos, 160, 42);

    //Write style for Menu_Protect_label_ucp_state_i_pos, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_ucp_state_i_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_ucp_state_i_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_ucp_state_i_pos, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_ucp_state_i_pos, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_ucp_state_i_pos, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_ucp_state_i_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_ucp_state_i_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_ucp_state_i_pos, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_ucp_state_i_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_ucp_state_i_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_ucp_state_i_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_ucp_state_i_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_ucp_state_i_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_ucp_state_i_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_ucp_state_i_neg_unit
    ui->Menu_Protect_label_ucp_state_i_neg_unit = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_ucp_state_i_neg_unit, "");
    lv_label_set_long_mode(ui->Menu_Protect_label_ucp_state_i_neg_unit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_ucp_state_i_neg_unit, 442, 360);
    lv_obj_set_size(ui->Menu_Protect_label_ucp_state_i_neg_unit, 180, 35);

    //Write style for Menu_Protect_label_ucp_state_i_neg_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_ucp_state_i_neg_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_ucp_state_i_neg_unit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_ucp_state_i_neg_unit, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_ucp_state_i_neg_unit, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_ucp_state_i_neg_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_ucp_state_i_neg_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_ucp_state_i_neg_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_ucp_state_i_neg_unit, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_ucp_state_i_neg_unit, 70, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_Protect_label_ucp_state_i_neg_unit, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_label_ucp_state_i_neg_unit, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_ucp_state_i_neg_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_ucp_state_i_neg_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_ucp_state_i_neg_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_ucp_state_i_neg_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_ucp_state_i_neg_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_ucp_state_i_neg_set
    ui->Menu_Protect_label_ucp_state_i_neg_set = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_ucp_state_i_neg_set, "-123.456W");
    lv_label_set_long_mode(ui->Menu_Protect_label_ucp_state_i_neg_set, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_ucp_state_i_neg_set, 440, 319);
    lv_obj_set_size(ui->Menu_Protect_label_ucp_state_i_neg_set, 185, 80);

    //Write style for Menu_Protect_label_ucp_state_i_neg_set, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_ucp_state_i_neg_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_ucp_state_i_neg_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_ucp_state_i_neg_set, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_ucp_state_i_neg_set, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_ucp_state_i_neg_set, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_ucp_state_i_neg_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_ucp_state_i_neg_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_ucp_state_i_neg_set, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_ucp_state_i_neg_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_ucp_state_i_neg_set, 40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_ucp_state_i_neg_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_ucp_state_i_neg_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_ucp_state_i_neg_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_ucp_state_i_neg_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_ucp_state_i_neg
    ui->Menu_Protect_label_ucp_state_i_neg = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_ucp_state_i_neg, "-Current");
    lv_label_set_long_mode(ui->Menu_Protect_label_ucp_state_i_neg, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_ucp_state_i_neg, 455, 319);
    lv_obj_set_size(ui->Menu_Protect_label_ucp_state_i_neg, 160, 42);

    //Write style for Menu_Protect_label_ucp_state_i_neg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_ucp_state_i_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_ucp_state_i_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_ucp_state_i_neg, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_ucp_state_i_neg, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_ucp_state_i_neg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_ucp_state_i_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_ucp_state_i_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_ucp_state_i_neg, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_ucp_state_i_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_ucp_state_i_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_ucp_state_i_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_ucp_state_i_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_ucp_state_i_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_ucp_state_i_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_ucp_state_delay_unit
    ui->Menu_Protect_label_ucp_state_delay_unit = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_ucp_state_delay_unit, "");
    lv_label_set_long_mode(ui->Menu_Protect_label_ucp_state_delay_unit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_ucp_state_delay_unit, 665, 360);
    lv_obj_set_size(ui->Menu_Protect_label_ucp_state_delay_unit, 180, 35);

    //Write style for Menu_Protect_label_ucp_state_delay_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_ucp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_ucp_state_delay_unit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_ucp_state_delay_unit, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_ucp_state_delay_unit, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_ucp_state_delay_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_ucp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_ucp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_ucp_state_delay_unit, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_ucp_state_delay_unit, 70, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_Protect_label_ucp_state_delay_unit, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_label_ucp_state_delay_unit, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_ucp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_ucp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_ucp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_ucp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_ucp_state_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_ucp_state_delay_set
    ui->Menu_Protect_label_ucp_state_delay_set = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_ucp_state_delay_set, "123.456S");
    lv_label_set_long_mode(ui->Menu_Protect_label_ucp_state_delay_set, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_ucp_state_delay_set, 665, 319);
    lv_obj_set_size(ui->Menu_Protect_label_ucp_state_delay_set, 180, 80);

    //Write style for Menu_Protect_label_ucp_state_delay_set, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_ucp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_ucp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_ucp_state_delay_set, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_ucp_state_delay_set, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_ucp_state_delay_set, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_ucp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_ucp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_ucp_state_delay_set, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_ucp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_ucp_state_delay_set, 40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_ucp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_ucp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_ucp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_ucp_state_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_ucp_state_delay
    ui->Menu_Protect_label_ucp_state_delay = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_ucp_state_delay, "Delay");
    lv_label_set_long_mode(ui->Menu_Protect_label_ucp_state_delay, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_ucp_state_delay, 675, 320);
    lv_obj_set_size(ui->Menu_Protect_label_ucp_state_delay, 160, 42);

    //Write style for Menu_Protect_label_ucp_state_delay, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_ucp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_ucp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_ucp_state_delay, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_ucp_state_delay, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_ucp_state_delay, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_ucp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_ucp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_ucp_state_delay, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_ucp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_ucp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_ucp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_ucp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_ucp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_ucp_state_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_ucp_state_warm_unit
    ui->Menu_Protect_label_ucp_state_warm_unit = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_ucp_state_warm_unit, "");
    lv_label_set_long_mode(ui->Menu_Protect_label_ucp_state_warm_unit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_ucp_state_warm_unit, 210, 439);
    lv_obj_set_size(ui->Menu_Protect_label_ucp_state_warm_unit, 180, 35);

    //Write style for Menu_Protect_label_ucp_state_warm_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_ucp_state_warm_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_ucp_state_warm_unit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_ucp_state_warm_unit, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_ucp_state_warm_unit, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_ucp_state_warm_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_ucp_state_warm_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_ucp_state_warm_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_ucp_state_warm_unit, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_ucp_state_warm_unit, 70, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_Protect_label_ucp_state_warm_unit, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_label_ucp_state_warm_unit, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_ucp_state_warm_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_ucp_state_warm_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_ucp_state_warm_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_ucp_state_warm_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_ucp_state_warm_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_ucp_state_warm_set
    ui->Menu_Protect_label_ucp_state_warm_set = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_ucp_state_warm_set, "123.456S");
    lv_label_set_long_mode(ui->Menu_Protect_label_ucp_state_warm_set, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_ucp_state_warm_set, 212, 399);
    lv_obj_set_size(ui->Menu_Protect_label_ucp_state_warm_set, 185, 80);

    //Write style for Menu_Protect_label_ucp_state_warm_set, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_ucp_state_warm_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_ucp_state_warm_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_ucp_state_warm_set, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_ucp_state_warm_set, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_ucp_state_warm_set, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_ucp_state_warm_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_ucp_state_warm_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_ucp_state_warm_set, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_ucp_state_warm_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_ucp_state_warm_set, 40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_ucp_state_warm_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_ucp_state_warm_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_ucp_state_warm_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_ucp_state_warm_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_ucp_state_warm
    ui->Menu_Protect_label_ucp_state_warm = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_ucp_state_warm, "Warm Time");
    lv_label_set_long_mode(ui->Menu_Protect_label_ucp_state_warm, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_ucp_state_warm, 204, 402);
    lv_obj_set_size(ui->Menu_Protect_label_ucp_state_warm, 204, 37);

    //Write style for Menu_Protect_label_ucp_state_warm, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_ucp_state_warm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_ucp_state_warm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_ucp_state_warm, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_ucp_state_warm, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_ucp_state_warm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_ucp_state_warm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_ucp_state_warm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_ucp_state_warm, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_ucp_state_warm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_ucp_state_warm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_ucp_state_warm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_ucp_state_warm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_ucp_state_warm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_ucp_state_warm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_foldback_delay_unit
    ui->Menu_Protect_label_foldback_delay_unit = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_foldback_delay_unit, "");
    lv_label_set_long_mode(ui->Menu_Protect_label_foldback_delay_unit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_foldback_delay_unit, 210, 520);
    lv_obj_set_size(ui->Menu_Protect_label_foldback_delay_unit, 180, 35);

    //Write style for Menu_Protect_label_foldback_delay_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_foldback_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_foldback_delay_unit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_foldback_delay_unit, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_foldback_delay_unit, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_foldback_delay_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_foldback_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_foldback_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_foldback_delay_unit, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_foldback_delay_unit, 70, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_Protect_label_foldback_delay_unit, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_label_foldback_delay_unit, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_foldback_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_foldback_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_foldback_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_foldback_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_foldback_delay_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_foldback_delay_set
    ui->Menu_Protect_label_foldback_delay_set = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_foldback_delay_set, "123.456S");
    lv_label_set_long_mode(ui->Menu_Protect_label_foldback_delay_set, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_foldback_delay_set, 212, 480);
    lv_obj_set_size(ui->Menu_Protect_label_foldback_delay_set, 180, 74);

    //Write style for Menu_Protect_label_foldback_delay_set, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_foldback_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_foldback_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_foldback_delay_set, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_foldback_delay_set, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_foldback_delay_set, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_foldback_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_foldback_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_foldback_delay_set, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_foldback_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_foldback_delay_set, 40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_foldback_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_foldback_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_foldback_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_foldback_delay_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_foldback_delay
    ui->Menu_Protect_label_foldback_delay = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_foldback_delay, "Delay");
    lv_label_set_long_mode(ui->Menu_Protect_label_foldback_delay, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_foldback_delay, 226, 480);
    lv_obj_set_size(ui->Menu_Protect_label_foldback_delay, 160, 42);

    //Write style for Menu_Protect_label_foldback_delay, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_foldback_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_foldback_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_foldback_delay, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_foldback_delay, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_foldback_delay, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_foldback_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_foldback_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_foldback_delay, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_foldback_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_foldback_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_foldback_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_foldback_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_foldback_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_foldback_delay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_line_1
    ui->Menu_Protect_line_1 = lv_line_create(ui->Menu_Protect_cont_1);
    static lv_point_t Menu_Protect_line_1[] = {{0, 0},{855, 0},};
    lv_line_set_points(ui->Menu_Protect_line_1, Menu_Protect_line_1, 2);
    lv_obj_set_pos(ui->Menu_Protect_line_1, 0, 80);
    lv_obj_set_size(ui->Menu_Protect_line_1, 855, 1);

    //Write style for Menu_Protect_line_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->Menu_Protect_line_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->Menu_Protect_line_1, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->Menu_Protect_line_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->Menu_Protect_line_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_line_2
    ui->Menu_Protect_line_2 = lv_line_create(ui->Menu_Protect_cont_1);
    static lv_point_t Menu_Protect_line_2[] = {{0, 0},{855, 0},};
    lv_line_set_points(ui->Menu_Protect_line_2, Menu_Protect_line_2, 2);
    lv_obj_set_pos(ui->Menu_Protect_line_2, 0, 160);
    lv_obj_set_size(ui->Menu_Protect_line_2, 855, 1);

    //Write style for Menu_Protect_line_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->Menu_Protect_line_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->Menu_Protect_line_2, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->Menu_Protect_line_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->Menu_Protect_line_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_line_3
    ui->Menu_Protect_line_3 = lv_line_create(ui->Menu_Protect_cont_1);
    static lv_point_t Menu_Protect_line_3[] = {{0, 0},{855, 0},};
    lv_line_set_points(ui->Menu_Protect_line_3, Menu_Protect_line_3, 2);
    lv_obj_set_pos(ui->Menu_Protect_line_3, 0, 240);
    lv_obj_set_size(ui->Menu_Protect_line_3, 855, 1);

    //Write style for Menu_Protect_line_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->Menu_Protect_line_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->Menu_Protect_line_3, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->Menu_Protect_line_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->Menu_Protect_line_3, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_line_6
    ui->Menu_Protect_line_6 = lv_line_create(ui->Menu_Protect_cont_1);
    static lv_point_t Menu_Protect_line_6[] = {{0, 0},{855, 0},};
    lv_line_set_points(ui->Menu_Protect_line_6, Menu_Protect_line_6, 2);
    lv_obj_set_pos(ui->Menu_Protect_line_6, 0, 480);
    lv_obj_set_size(ui->Menu_Protect_line_6, 855, 1);

    //Write style for Menu_Protect_line_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->Menu_Protect_line_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->Menu_Protect_line_6, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->Menu_Protect_line_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->Menu_Protect_line_6, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_line_4
    ui->Menu_Protect_line_4 = lv_line_create(ui->Menu_Protect_cont_1);
    static lv_point_t Menu_Protect_line_4[] = {{0, 0},{855, 0},};
    lv_line_set_points(ui->Menu_Protect_line_4, Menu_Protect_line_4, 2);
    lv_obj_set_pos(ui->Menu_Protect_line_4, 0, 320);
    lv_obj_set_size(ui->Menu_Protect_line_4, 855, 1);

    //Write style for Menu_Protect_line_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->Menu_Protect_line_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->Menu_Protect_line_4, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->Menu_Protect_line_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->Menu_Protect_line_4, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_sw_ovp_state
    ui->Menu_Protect_sw_ovp_state = lv_switch_create(ui->Menu_Protect_cont_1);
    lv_obj_set_pos(ui->Menu_Protect_sw_ovp_state, 38, 37);
    lv_obj_set_size(ui->Menu_Protect_sw_ovp_state, 100, 37);

    //Write style for Menu_Protect_sw_ovp_state, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Menu_Protect_sw_ovp_state, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_Protect_sw_ovp_state, lv_color_hex(0x8080f0), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_sw_ovp_state, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Menu_Protect_sw_ovp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_sw_ovp_state, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_sw_ovp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Menu_Protect_sw_ovp_state, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->Menu_Protect_sw_ovp_state, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->Menu_Protect_sw_ovp_state, lv_color_hex(0xff0027), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_sw_ovp_state, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->Menu_Protect_sw_ovp_state, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for Menu_Protect_sw_ovp_state, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Menu_Protect_sw_ovp_state, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_Protect_sw_ovp_state, lv_color_hex(0x51f304), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_sw_ovp_state, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Menu_Protect_sw_ovp_state, 5, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Menu_Protect_sw_ovp_state, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Menu_Protect_sw_ovp_state, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->Menu_Protect_sw_ovp_state, LV_BORDER_SIDE_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_sw_ovp_state, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_ovp_state_OFF
    ui->Menu_Protect_ovp_state_OFF = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_ovp_state_OFF, "OFF");
    lv_label_set_long_mode(ui->Menu_Protect_ovp_state_OFF, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_ovp_state_OFF, 74, 46);
    lv_obj_set_size(ui->Menu_Protect_ovp_state_OFF, 50, 25);

    //Write style for Menu_Protect_ovp_state_OFF, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_ovp_state_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_ovp_state_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_ovp_state_OFF, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_ovp_state_OFF, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_ovp_state_OFF, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_ovp_state_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_ovp_state_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_ovp_state_OFF, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_ovp_state_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_ovp_state_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_ovp_state_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_ovp_state_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_ovp_state_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_ovp_state_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_ovp_state_ON
    ui->Menu_Protect_ovp_state_ON = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_ovp_state_ON, "ON");
    lv_label_set_long_mode(ui->Menu_Protect_ovp_state_ON, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_ovp_state_ON, 47, 44);
    lv_obj_set_size(ui->Menu_Protect_ovp_state_ON, 40, 25);
    lv_obj_add_flag(ui->Menu_Protect_ovp_state_ON, LV_OBJ_FLAG_HIDDEN);

    //Write style for Menu_Protect_ovp_state_ON, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_ovp_state_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_ovp_state_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_ovp_state_ON, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_ovp_state_ON, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_ovp_state_ON, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_ovp_state_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_ovp_state_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_ovp_state_ON, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_ovp_state_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_ovp_state_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_ovp_state_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_ovp_state_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_ovp_state_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_ovp_state_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_ovp_state
    ui->Menu_Protect_label_ovp_state = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_ovp_state, "OVP State\n");
    lv_label_set_long_mode(ui->Menu_Protect_label_ovp_state, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_ovp_state, 0, 0);
    lv_obj_set_size(ui->Menu_Protect_label_ovp_state, 180, 80);

    //Write style for Menu_Protect_label_ovp_state, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_ovp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_ovp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_ovp_state, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_ovp_state, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_ovp_state, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_ovp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_ovp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_ovp_state, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_ovp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_ovp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_ovp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_ovp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_ovp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_ovp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_sw_ocp_state
    ui->Menu_Protect_sw_ocp_state = lv_switch_create(ui->Menu_Protect_cont_1);
    lv_obj_set_pos(ui->Menu_Protect_sw_ocp_state, 38, 119);
    lv_obj_set_size(ui->Menu_Protect_sw_ocp_state, 100, 37);

    //Write style for Menu_Protect_sw_ocp_state, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Menu_Protect_sw_ocp_state, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_Protect_sw_ocp_state, lv_color_hex(0x8080f0), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_sw_ocp_state, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Menu_Protect_sw_ocp_state, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Menu_Protect_sw_ocp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Menu_Protect_sw_ocp_state, lv_color_hex(0x5ffd00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->Menu_Protect_sw_ocp_state, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_sw_ocp_state, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_sw_ocp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Menu_Protect_sw_ocp_state, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->Menu_Protect_sw_ocp_state, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->Menu_Protect_sw_ocp_state, lv_color_hex(0xff0027), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_sw_ocp_state, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->Menu_Protect_sw_ocp_state, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for Menu_Protect_sw_ocp_state, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Menu_Protect_sw_ocp_state, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_Protect_sw_ocp_state, lv_color_hex(0x51f304), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_sw_ocp_state, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Menu_Protect_sw_ocp_state, 5, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Menu_Protect_sw_ocp_state, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Menu_Protect_sw_ocp_state, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->Menu_Protect_sw_ocp_state, LV_BORDER_SIDE_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_sw_ocp_state, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_ocp_state_OFF
    ui->Menu_Protect_ocp_state_OFF = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_ocp_state_OFF, "OFF");
    lv_label_set_long_mode(ui->Menu_Protect_ocp_state_OFF, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_ocp_state_OFF, 74, 124);
    lv_obj_set_size(ui->Menu_Protect_ocp_state_OFF, 50, 25);

    //Write style for Menu_Protect_ocp_state_OFF, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_ocp_state_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_ocp_state_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_ocp_state_OFF, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_ocp_state_OFF, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_ocp_state_OFF, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_ocp_state_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_ocp_state_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_ocp_state_OFF, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_ocp_state_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_ocp_state_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_ocp_state_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_ocp_state_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_ocp_state_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_ocp_state_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_ocp_state_ON
    ui->Menu_Protect_ocp_state_ON = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_ocp_state_ON, "ON");
    lv_label_set_long_mode(ui->Menu_Protect_ocp_state_ON, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_ocp_state_ON, 47, 124);
    lv_obj_set_size(ui->Menu_Protect_ocp_state_ON, 40, 25);
    lv_obj_add_flag(ui->Menu_Protect_ocp_state_ON, LV_OBJ_FLAG_HIDDEN);

    //Write style for Menu_Protect_ocp_state_ON, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_ocp_state_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_ocp_state_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_ocp_state_ON, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_ocp_state_ON, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_ocp_state_ON, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_ocp_state_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_ocp_state_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_ocp_state_ON, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_ocp_state_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_ocp_state_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_ocp_state_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_ocp_state_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_ocp_state_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_ocp_state_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_ocp_state
    ui->Menu_Protect_label_ocp_state = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_ocp_state, "OCP State\n");
    lv_label_set_long_mode(ui->Menu_Protect_label_ocp_state, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_ocp_state, 0, 80);
    lv_obj_set_size(ui->Menu_Protect_label_ocp_state, 180, 80);

    //Write style for Menu_Protect_label_ocp_state, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_ocp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_ocp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_ocp_state, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_ocp_state, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_ocp_state, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_ocp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_ocp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_ocp_state, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_ocp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_ocp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_ocp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_ocp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_ocp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_ocp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_sw_opp_state
    ui->Menu_Protect_sw_opp_state = lv_switch_create(ui->Menu_Protect_cont_1);
    lv_obj_set_pos(ui->Menu_Protect_sw_opp_state, 38, 199);
    lv_obj_set_size(ui->Menu_Protect_sw_opp_state, 100, 37);

    //Write style for Menu_Protect_sw_opp_state, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Menu_Protect_sw_opp_state, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_Protect_sw_opp_state, lv_color_hex(0x8080f0), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_sw_opp_state, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Menu_Protect_sw_opp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_sw_opp_state, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_sw_opp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Menu_Protect_sw_opp_state, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->Menu_Protect_sw_opp_state, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->Menu_Protect_sw_opp_state, lv_color_hex(0xff0027), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_sw_opp_state, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->Menu_Protect_sw_opp_state, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for Menu_Protect_sw_opp_state, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Menu_Protect_sw_opp_state, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_Protect_sw_opp_state, lv_color_hex(0x51f304), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_sw_opp_state, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Menu_Protect_sw_opp_state, 5, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Menu_Protect_sw_opp_state, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Menu_Protect_sw_opp_state, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->Menu_Protect_sw_opp_state, LV_BORDER_SIDE_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_sw_opp_state, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_opp_state_ON
    ui->Menu_Protect_opp_state_ON = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_opp_state_ON, "ON");
    lv_label_set_long_mode(ui->Menu_Protect_opp_state_ON, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_opp_state_ON, 47, 204);
    lv_obj_set_size(ui->Menu_Protect_opp_state_ON, 40, 25);
    lv_obj_add_flag(ui->Menu_Protect_opp_state_ON, LV_OBJ_FLAG_HIDDEN);

    //Write style for Menu_Protect_opp_state_ON, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_opp_state_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_opp_state_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_opp_state_ON, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_opp_state_ON, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_opp_state_ON, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_opp_state_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_opp_state_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_opp_state_ON, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_opp_state_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_opp_state_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_opp_state_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_opp_state_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_opp_state_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_opp_state_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_opp_state_OFF
    ui->Menu_Protect_opp_state_OFF = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_opp_state_OFF, "OFF");
    lv_label_set_long_mode(ui->Menu_Protect_opp_state_OFF, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_opp_state_OFF, 74, 204);
    lv_obj_set_size(ui->Menu_Protect_opp_state_OFF, 50, 25);

    //Write style for Menu_Protect_opp_state_OFF, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_opp_state_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_opp_state_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_opp_state_OFF, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_opp_state_OFF, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_opp_state_OFF, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_opp_state_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_opp_state_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_opp_state_OFF, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_opp_state_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_opp_state_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_opp_state_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_opp_state_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_opp_state_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_opp_state_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_opp_state
    ui->Menu_Protect_label_opp_state = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_opp_state, "OPP State");
    lv_label_set_long_mode(ui->Menu_Protect_label_opp_state, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_opp_state, 0, 160);
    lv_obj_set_size(ui->Menu_Protect_label_opp_state, 180, 80);

    //Write style for Menu_Protect_label_opp_state, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_opp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_opp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_opp_state, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_opp_state, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_opp_state, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_opp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_opp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_opp_state, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_opp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_opp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_opp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_opp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_opp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_opp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_sw_uvp_state
    ui->Menu_Protect_sw_uvp_state = lv_switch_create(ui->Menu_Protect_cont_1);
    lv_obj_set_pos(ui->Menu_Protect_sw_uvp_state, 38, 279);
    lv_obj_set_size(ui->Menu_Protect_sw_uvp_state, 100, 37);

    //Write style for Menu_Protect_sw_uvp_state, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Menu_Protect_sw_uvp_state, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_Protect_sw_uvp_state, lv_color_hex(0x8080f0), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_sw_uvp_state, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Menu_Protect_sw_uvp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_sw_uvp_state, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_sw_uvp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Menu_Protect_sw_uvp_state, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->Menu_Protect_sw_uvp_state, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->Menu_Protect_sw_uvp_state, lv_color_hex(0xff0027), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_sw_uvp_state, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->Menu_Protect_sw_uvp_state, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for Menu_Protect_sw_uvp_state, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Menu_Protect_sw_uvp_state, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_Protect_sw_uvp_state, lv_color_hex(0x51f304), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_sw_uvp_state, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Menu_Protect_sw_uvp_state, 5, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Menu_Protect_sw_uvp_state, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Menu_Protect_sw_uvp_state, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->Menu_Protect_sw_uvp_state, LV_BORDER_SIDE_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_sw_uvp_state, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_uvp_ON
    ui->Menu_Protect_label_uvp_ON = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_uvp_ON, "ON");
    lv_label_set_long_mode(ui->Menu_Protect_label_uvp_ON, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_uvp_ON, 47, 285);
    lv_obj_set_size(ui->Menu_Protect_label_uvp_ON, 40, 25);
    lv_obj_add_flag(ui->Menu_Protect_label_uvp_ON, LV_OBJ_FLAG_HIDDEN);

    //Write style for Menu_Protect_label_uvp_ON, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_uvp_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_uvp_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_uvp_ON, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_uvp_ON, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_uvp_ON, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_uvp_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_uvp_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_uvp_ON, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_uvp_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_uvp_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_uvp_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_uvp_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_uvp_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_uvp_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_uvp_OFF
    ui->Menu_Protect_label_uvp_OFF = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_uvp_OFF, "OFF");
    lv_label_set_long_mode(ui->Menu_Protect_label_uvp_OFF, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_uvp_OFF, 74, 285);
    lv_obj_set_size(ui->Menu_Protect_label_uvp_OFF, 50, 25);

    //Write style for Menu_Protect_label_uvp_OFF, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_uvp_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_uvp_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_uvp_OFF, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_uvp_OFF, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_uvp_OFF, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_uvp_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_uvp_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_uvp_OFF, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_uvp_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_uvp_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_uvp_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_uvp_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_uvp_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_uvp_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_uvp_state
    ui->Menu_Protect_label_uvp_state = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_uvp_state, "UVP State");
    lv_label_set_long_mode(ui->Menu_Protect_label_uvp_state, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_uvp_state, 0, 240);
    lv_obj_set_size(ui->Menu_Protect_label_uvp_state, 180, 80);

    //Write style for Menu_Protect_label_uvp_state, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_uvp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_uvp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_uvp_state, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_uvp_state, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_uvp_state, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_uvp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_uvp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_uvp_state, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_uvp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_uvp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_uvp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_uvp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_uvp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_uvp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_sw_ucp_state
    ui->Menu_Protect_sw_ucp_state = lv_switch_create(ui->Menu_Protect_cont_1);
    lv_obj_set_pos(ui->Menu_Protect_sw_ucp_state, 38, 359);
    lv_obj_set_size(ui->Menu_Protect_sw_ucp_state, 100, 37);

    //Write style for Menu_Protect_sw_ucp_state, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Menu_Protect_sw_ucp_state, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_Protect_sw_ucp_state, lv_color_hex(0x8080f0), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_sw_ucp_state, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Menu_Protect_sw_ucp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_sw_ucp_state, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_sw_ucp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Menu_Protect_sw_ucp_state, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->Menu_Protect_sw_ucp_state, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->Menu_Protect_sw_ucp_state, lv_color_hex(0xff0027), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_sw_ucp_state, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->Menu_Protect_sw_ucp_state, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for Menu_Protect_sw_ucp_state, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Menu_Protect_sw_ucp_state, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_Protect_sw_ucp_state, lv_color_hex(0x51f304), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_sw_ucp_state, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Menu_Protect_sw_ucp_state, 5, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Menu_Protect_sw_ucp_state, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Menu_Protect_sw_ucp_state, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->Menu_Protect_sw_ucp_state, LV_BORDER_SIDE_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_sw_ucp_state, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_ucp_OFF
    ui->Menu_Protect_label_ucp_OFF = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_ucp_OFF, "OFF");
    lv_label_set_long_mode(ui->Menu_Protect_label_ucp_OFF, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_ucp_OFF, 74, 366);
    lv_obj_set_size(ui->Menu_Protect_label_ucp_OFF, 50, 25);

    //Write style for Menu_Protect_label_ucp_OFF, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_ucp_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_ucp_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_ucp_OFF, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_ucp_OFF, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_ucp_OFF, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_ucp_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_ucp_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_ucp_OFF, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_ucp_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_ucp_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_ucp_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_ucp_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_ucp_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_ucp_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_ucp_ON
    ui->Menu_Protect_label_ucp_ON = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_ucp_ON, "ON");
    lv_label_set_long_mode(ui->Menu_Protect_label_ucp_ON, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_ucp_ON, 47, 364);
    lv_obj_set_size(ui->Menu_Protect_label_ucp_ON, 40, 25);
    lv_obj_add_flag(ui->Menu_Protect_label_ucp_ON, LV_OBJ_FLAG_HIDDEN);

    //Write style for Menu_Protect_label_ucp_ON, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_ucp_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_ucp_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_ucp_ON, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_ucp_ON, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_ucp_ON, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_ucp_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_ucp_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_ucp_ON, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_ucp_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_ucp_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_ucp_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_ucp_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_ucp_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_ucp_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_ucp_state
    ui->Menu_Protect_label_ucp_state = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_ucp_state, "UCP State");
    lv_label_set_long_mode(ui->Menu_Protect_label_ucp_state, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_ucp_state, 0, 320);
    lv_obj_set_size(ui->Menu_Protect_label_ucp_state, 180, 80);

    //Write style for Menu_Protect_label_ucp_state, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_ucp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_ucp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_ucp_state, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_ucp_state, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_ucp_state, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_ucp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_ucp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_ucp_state, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_ucp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_ucp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_ucp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_ucp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_ucp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_ucp_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_ddlist_foldback
    ui->Menu_Protect_ddlist_foldback = lv_dropdown_create(ui->Menu_Protect_cont_1);
    lv_dropdown_set_options(ui->Menu_Protect_ddlist_foldback, "CV to CCCP\nCC to CVCP");
    lv_obj_set_pos(ui->Menu_Protect_ddlist_foldback, 421, 519);
    lv_obj_set_size(ui->Menu_Protect_ddlist_foldback, 230, 36);

    //Write style for Menu_Protect_ddlist_foldback, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->Menu_Protect_ddlist_foldback, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_ddlist_foldback, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_ddlist_foldback, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Menu_Protect_ddlist_foldback, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Menu_Protect_ddlist_foldback, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Menu_Protect_ddlist_foldback, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->Menu_Protect_ddlist_foldback, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_ddlist_foldback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_ddlist_foldback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_ddlist_foldback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_ddlist_foldback, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_ddlist_foldback, 70, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_Protect_ddlist_foldback, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_ddlist_foldback, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_ddlist_foldback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_CHECKED for &style_Menu_Protect_ddlist_foldback_extra_list_selected_checked
    static lv_style_t style_Menu_Protect_ddlist_foldback_extra_list_selected_checked;
    ui_init_style(&style_Menu_Protect_ddlist_foldback_extra_list_selected_checked);

    lv_style_set_border_width(&style_Menu_Protect_ddlist_foldback_extra_list_selected_checked, 0);
    lv_style_set_radius(&style_Menu_Protect_ddlist_foldback_extra_list_selected_checked, 0);
    lv_style_set_bg_opa(&style_Menu_Protect_ddlist_foldback_extra_list_selected_checked, 255);
    lv_style_set_bg_color(&style_Menu_Protect_ddlist_foldback_extra_list_selected_checked, lv_color_hex(0x51f304));
    lv_style_set_bg_grad_dir(&style_Menu_Protect_ddlist_foldback_extra_list_selected_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->Menu_Protect_ddlist_foldback), &style_Menu_Protect_ddlist_foldback_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_Menu_Protect_ddlist_foldback_extra_list_main_default
    static lv_style_t style_Menu_Protect_ddlist_foldback_extra_list_main_default;
    ui_init_style(&style_Menu_Protect_ddlist_foldback_extra_list_main_default);

    lv_style_set_max_height(&style_Menu_Protect_ddlist_foldback_extra_list_main_default, 115);
    lv_style_set_text_color(&style_Menu_Protect_ddlist_foldback_extra_list_main_default, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_Menu_Protect_ddlist_foldback_extra_list_main_default, &lv_font_SourceHanSerifSC_Regular_35);
    lv_style_set_text_opa(&style_Menu_Protect_ddlist_foldback_extra_list_main_default, 255);
    lv_style_set_border_width(&style_Menu_Protect_ddlist_foldback_extra_list_main_default, 1);
    lv_style_set_border_opa(&style_Menu_Protect_ddlist_foldback_extra_list_main_default, 255);
    lv_style_set_border_color(&style_Menu_Protect_ddlist_foldback_extra_list_main_default, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_Menu_Protect_ddlist_foldback_extra_list_main_default, LV_BORDER_SIDE_NONE);
    lv_style_set_radius(&style_Menu_Protect_ddlist_foldback_extra_list_main_default, 0);
    lv_style_set_bg_opa(&style_Menu_Protect_ddlist_foldback_extra_list_main_default, 255);
    lv_style_set_bg_color(&style_Menu_Protect_ddlist_foldback_extra_list_main_default, lv_color_hex(0x2195f6));
    lv_style_set_bg_grad_dir(&style_Menu_Protect_ddlist_foldback_extra_list_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->Menu_Protect_ddlist_foldback), &style_Menu_Protect_ddlist_foldback_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_Menu_Protect_ddlist_foldback_extra_list_scrollbar_default
    static lv_style_t style_Menu_Protect_ddlist_foldback_extra_list_scrollbar_default;
    ui_init_style(&style_Menu_Protect_ddlist_foldback_extra_list_scrollbar_default);

    lv_style_set_radius(&style_Menu_Protect_ddlist_foldback_extra_list_scrollbar_default, 0);
    lv_style_set_bg_opa(&style_Menu_Protect_ddlist_foldback_extra_list_scrollbar_default, 255);
    lv_style_set_bg_color(&style_Menu_Protect_ddlist_foldback_extra_list_scrollbar_default, lv_color_hex(0x01ff01));
    lv_style_set_bg_grad_dir(&style_Menu_Protect_ddlist_foldback_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->Menu_Protect_ddlist_foldback), &style_Menu_Protect_ddlist_foldback_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_foldback_mode
    ui->Menu_Protect_label_foldback_mode = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_foldback_mode, "Mode");
    lv_label_set_long_mode(ui->Menu_Protect_label_foldback_mode, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_foldback_mode, 455, 480);
    lv_obj_set_size(ui->Menu_Protect_label_foldback_mode, 160, 42);

    //Write style for Menu_Protect_label_foldback_mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_foldback_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_foldback_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_foldback_mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_foldback_mode, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_foldback_mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_foldback_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_foldback_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_foldback_mode, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_foldback_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_foldback_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_foldback_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_foldback_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_foldback_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_foldback_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_sw_foldback
    ui->Menu_Protect_sw_foldback = lv_switch_create(ui->Menu_Protect_cont_1);
    lv_obj_set_pos(ui->Menu_Protect_sw_foldback, 38, 519);
    lv_obj_set_size(ui->Menu_Protect_sw_foldback, 100, 37);

    //Write style for Menu_Protect_sw_foldback, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Menu_Protect_sw_foldback, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_Protect_sw_foldback, lv_color_hex(0x8080f0), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_sw_foldback, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Menu_Protect_sw_foldback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_sw_foldback, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_sw_foldback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Menu_Protect_sw_foldback, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->Menu_Protect_sw_foldback, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->Menu_Protect_sw_foldback, lv_color_hex(0xff0027), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_sw_foldback, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->Menu_Protect_sw_foldback, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for Menu_Protect_sw_foldback, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Menu_Protect_sw_foldback, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_Protect_sw_foldback, lv_color_hex(0x51f304), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Protect_sw_foldback, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Menu_Protect_sw_foldback, 5, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Menu_Protect_sw_foldback, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Menu_Protect_sw_foldback, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->Menu_Protect_sw_foldback, LV_BORDER_SIDE_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_sw_foldback, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_foldback_ON
    ui->Menu_Protect_label_foldback_ON = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_foldback_ON, "ON");
    lv_label_set_long_mode(ui->Menu_Protect_label_foldback_ON, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_foldback_ON, 47, 525);
    lv_obj_set_size(ui->Menu_Protect_label_foldback_ON, 40, 25);
    lv_obj_add_flag(ui->Menu_Protect_label_foldback_ON, LV_OBJ_FLAG_HIDDEN);

    //Write style for Menu_Protect_label_foldback_ON, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_foldback_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_foldback_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_foldback_ON, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_foldback_ON, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_foldback_ON, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_foldback_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_foldback_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_foldback_ON, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_foldback_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_foldback_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_foldback_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_foldback_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_foldback_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_foldback_ON, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_foldback_OFF
    ui->Menu_Protect_label_foldback_OFF = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_foldback_OFF, "OFF");
    lv_label_set_long_mode(ui->Menu_Protect_label_foldback_OFF, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_foldback_OFF, 74, 526);
    lv_obj_set_size(ui->Menu_Protect_label_foldback_OFF, 50, 25);

    //Write style for Menu_Protect_label_foldback_OFF, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_foldback_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_foldback_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_foldback_OFF, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_foldback_OFF, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_foldback_OFF, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_foldback_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_foldback_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_foldback_OFF, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_foldback_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_foldback_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_foldback_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_foldback_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_foldback_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_foldback_OFF, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Protect_label_foldback
    ui->Menu_Protect_label_foldback = lv_label_create(ui->Menu_Protect_cont_1);
    lv_label_set_text(ui->Menu_Protect_label_foldback, "Foldback");
    lv_label_set_long_mode(ui->Menu_Protect_label_foldback, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Menu_Protect_label_foldback, 0, 480);
    lv_obj_set_size(ui->Menu_Protect_label_foldback, 180, 80);

    //Write style for Menu_Protect_label_foldback, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Protect_label_foldback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Protect_label_foldback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Menu_Protect_label_foldback, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Menu_Protect_label_foldback, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Menu_Protect_label_foldback, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Menu_Protect_label_foldback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Menu_Protect_label_foldback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Menu_Protect_label_foldback, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Protect_label_foldback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Protect_label_foldback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Protect_label_foldback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Protect_label_foldback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Protect_label_foldback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Protect_label_foldback, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Menu_Protect.


    //Update current screen layout.
    lv_obj_update_layout(ui->Menu_Protect);

}
