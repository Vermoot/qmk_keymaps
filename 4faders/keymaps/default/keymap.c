// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "analog.h"
#include <stdint.h>
#include "print.h"

enum layers {
    _BASE = 0,
    _RST
};

#define M_RST LT(_RST, KC_M)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_midifaders(
        KC_A,  KC_B, KC_C, KC_D,
        KC_E,  KC_F, KC_G, KC_H,
        KC_I,  KC_J, KC_K, KC_L,
        M_RST, KC_N, KC_O, KC_P
    ),

    [_RST] = LAYOUT_midifaders(
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, QK_BOOT
    )
};


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = {
        ENCODER_CCW_CW(KC_A, S(KC_A)),
        ENCODER_CCW_CW(KC_B, S(KC_B)),
        ENCODER_CCW_CW(KC_C, S(KC_C)),
        ENCODER_CCW_CW(KC_D, S(KC_D)),
        ENCODER_CCW_CW(KC_E, S(KC_E)),
        ENCODER_CCW_CW(KC_F, S(KC_F)),
        ENCODER_CCW_CW(KC_G, S(KC_G)),
        ENCODER_CCW_CW(KC_H, S(KC_H))
    },

    [_RST] = {
        ENCODER_CCW_CW(KC_M, S(KC_M)),
        ENCODER_CCW_CW(KC_N, S(KC_N)),
        ENCODER_CCW_CW(KC_O, S(KC_O)),
        ENCODER_CCW_CW(KC_P, S(KC_P)),
        ENCODER_CCW_CW(KC_Q, S(KC_Q)),
        ENCODER_CCW_CW(KC_R, S(KC_R)),
        ENCODER_CCW_CW(KC_S, S(KC_S)),
        ENCODER_CCW_CW(KC_T, S(KC_T))
    }


};
#endif

uint16_t last_readA = 0;
uint16_t current_readA = 0;
uint16_t last_readB = 0;
uint16_t current_readB = 0;
uint16_t last_readC = 0;
uint16_t current_readC = 0;
uint16_t last_readD = 0;
uint16_t current_readD = 0;

void matrix_scan_user(void) {
    uint16_t current_readA = analogReadPin(GP29);
    uint16_t current_readB = analogReadPin(GP28);
    uint16_t current_readC = analogReadPin(GP27);
    uint16_t current_readD = analogReadPin(GP26);
    uprintf("%u %u %u %u\n", current_readA, current_readB, current_readC, current_readD);
}
