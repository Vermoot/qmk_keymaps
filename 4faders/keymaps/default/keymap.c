#include QMK_KEYBOARD_H
#include "analog.h"
#include <stdint.h>
#include <stdbool.h>
#include "print.h"


enum layers {
    _BASE = 0,
    _MIDI,
    _RST
};

#include "custom_keycodes.c"
#include "encoders.c"
#include "faders.c"
#include "g/keymap_combo.h"

#define M_RST LT(_RST, KC_M)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_midifaders(
        KNOB1, KNOB2, KNOB3, KNOB4,
        KNOB5, KNOB6, KNOB7, KNOB8,
        KEY1,  KEY2,  KEY3,  KEY4,
        KEY5,  KEY6,  KEY7,  KEY8
    ),

    [_MIDI] = LAYOUT_midifaders(
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______
    ),

    [_RST] = LAYOUT_midifaders(
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, QK_BOOT
    )

};
