#include QMK_KEYBOARD_H

enum layers {
    _BASE = 0,
    _NAV,
    _LOWER,
    _RAISE,
    _NUM,
    _MEDIA,
    _FUNCT,
    _SELECT,
    _STENO

};

#include "custom_functions.c"
#include "custom_keycodes.c"
#include "g/keymap_combo.h"
#include "keymap_steno.h"

// ---- Combo terms ---- {{{
uint16_t get_combo_term(uint16_t index, combo_t *combo) {
  switch (index) {

    // Shorter
    case OU_OU:
    case AR_A_GRV:
    case NI_ALT_BSPC:
      return COMBO_TERM - 10;

    // Longer
    case BOU_BEAUCOUP:
    case PER_PEUT_ETRE:
    case C_CEST:
    case I_CAPS:
    case AO_OS_SHIFT:
    case CM_COMME:
    case PLOVER_RET:
      return COMBO_TERM + 20;

    // Long
    case EIO_I_CIRC:
    case LUY_U_CIRC:
    case ARS_A_CIRC:
    case MNE_MEME:
    case MT_MENT:
    case ETR_ETRE:
    case PQ_POURQUOI:
    case CQ_CHAQUE:
    case QD_QUAND:
    case DJ_DEJA:
    case C_A_CETAIT:
    case A_SL_QUESTION:
    case QE_QUE:
    case QI_QUI:
    case QO_QUOI:
    case QON_QUON:
    case QIL_QUIL:
    case QEL_QUELLE:
    case QN_QUELQUUN:
    case QUN_QUUN:
      return COMBO_TERM + 70;

    // Long as fuck
    case AJD_AJD:
    case LTA_LAETITIA:
      return COMBO_TERM + 120;
  }
  return COMBO_TERM;
}
// ---- END Combo terms ---- }}}

// --------------- LAYERS -------------------- {{{
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* ---- BLANK LAYOUT ---- {{{

// ----  ---- {{{
[] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
// ---- END ---- }}}

------------------------- }}} */

// ---- BASE LAYER ---- {{{
[_BASE] = LAYOUT(
  TAB_MEH, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                              KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, MEDIA,
  ESC_HYP, SFT_A,   CTL_R,   ALT_S,   CMMD_T,  KC_G,                                              KC_M,    CMMD_N,  ALT_E,   CTL_I,   SFT_O,   UD_APO,
  _______, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    _______, E_ACUTE,       _______, _______, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_MINS, SELECT,
                             _______, _______, LOWER,   NAV,     NUM,           RAISE,   KC_SPC,  KC_BSPC, FUNCT,   SELECT
),
// ---- END TEST BASE LAYER ---- }}}

// ---- NAV ---- {{{
[_NAV] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                                           _______, KC_PGDN, KC_PGUP, _______, _______, _______,
  _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,                                           KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______,       _______, _______, KC_DEL,  _______, _______
),
// ---- END NAV ---- }}}

// ---- LOWER ---- {{{
[_LOWER] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
  _______, _______, KC_LCBR, KC_LBRC, KC_LPRN, KC_UNDS,                                           KC_MINS, KC_RPRN, KC_RBRC, KC_RCBR, _______, KC_BSLS,
  _______, KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,    _______, _______,       _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
                             _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
// ---- END LOWER ---- }}}

// ---- RAISE ---- {{{
[_RAISE] = LAYOUT(
  _______, _______, _______, KC_EURO, _______, _______,                                           _______, _______, _______, KC_UNDS, KC_PLUS, _______,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                           UD_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
// ---- END RAISE ---- }}}

// ---- NUM ---- {{{
[_NUM] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                                           KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_BSPC,
  _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,                                           KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______,
  _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______, KC_PEQL, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______,
                             _______, _______, _______, _______, _______,       KC_SPC,  KC_P0,   KC_BSPC, _______, KC_PDOT
),
// ---- END NUM ---- }}}

// ---- MEDIA ---- {{{
[_MEDIA] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, KC_BRIU, KC_VOLU, _______,
  _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, KC_BRID, KC_VOLD, KC_F13,
  _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, KC_MUTE, KC_F14,
                             _______, _______, _______, _______, _______,       _______, _______, KC_MRWD, KC_MPLY, KC_MFFD
),
// ---- END MEDIA ---- }}}

// ---- FUNCT ---- {{{
[_FUNCT] = LAYOUT(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,                                           _______, _______, _______, _______, _______, _______,
  _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,                                           _______, KC_RGUI, KC_RALT, KC_RCTL, KC_RSFT, _______,
  _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
// ---- END FUNCT ---- }}}

// ---- SELECT ---- {{{
[_SELECT] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, STENO,
  _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
// ---- END SELECT ---- }}}

// ---- STENO ---- {{{
[_STENO] = LAYOUT(
  BASE,    STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,                                            STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  MEDIA,
  BASE,    STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,                                           STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
  _______, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, NUM,     _______,       _______, _______, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
                             _______, NAV,     STN_A,   STN_O,   LOWER,         RAISE,   STN_E,   STN_U,   _______, _______
),
// ---- END STENO ---- }}}

};
// --------------- END LAYERS --------------- }}}
