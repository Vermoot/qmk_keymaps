// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _BASE = 0,
};

#define LEFT_UP KC_A
#define LEFT_MID KC_S
#define LEFT_DOWN
#define RIGHT_UP
#define RIGHT_MID
#define RIGHT_DOWN
#define BOT_LEFT
#define BOT_MID
#define BOT_RIGHT
#define KNOB_CLICK
#define DSC_MUT KC_F15

#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_bigknob(
        KC_F13,                   DSC_MUT,
        KC_F14,    KC_A,          KC_F16,
        KC_MUTE,                  KC_F17,
        KC_MRWD,   KC_MPLY,       KC_MFFD
    )
};
