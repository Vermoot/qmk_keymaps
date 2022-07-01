#include QMK_KEYBOARD_H

enum layers {
    _BASE = 0,
    _STENO,
    _NAV,
    _LOWER,
    _NUM,
    _MEDIA,
    _FUNCT,
    _SELECT,
    _UBERBASE,
    _GAMING
};

#include "custom_functions.c"
#include "custom_keycodes.c"
#include "g/keymap_combo.h"
#include "keymap_steno.h"

void eeconfig_init_user() {
    steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HRM_A:
        case HRM_O:
            return false;
        default:
            return false;
    }
}

bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
    case KC_A ... KC_Z:
    case KC_MINS:
    case E_ACUTE ... C_CED:
      add_weak_mods(MOD_BIT(KC_LSFT));
      return true;

    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_DEL:
    case KC_UNDS:
    case KC_SPC:
    case UD_APO ... UD_CIRC:
    case KC_QUOT:
      return true;

    default:
      return false;
  }
}

// ---- Combo terms ---- {{{
uint16_t get_combo_term(uint16_t index, combo_t *combo) {
  switch (index) {

    // Shorter
    /* case OU_OU: */
    /* case AR_A_GRV: */
    /* case NI_HRM_BSPC: */
    case DEAD_UMLAUT:
      return COMBO_TERM - 10;

    // Longer
    case BOU_BEAUCOUP:
    case PER_PEUT_ETRE:
    case C_CEST:
    /* case I_CAPS: */
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
    /* case A_SL_QUESTION: */
    case QE_QUE:
    case QI_QUI:
    /* case QO_QUOI: */
    case QON_QUON:
    case QIL_QUIL:
    case QEL_QUELLE:
    case QN_QUELQUUN:
    case QUN_QUUN:
      return COMBO_TERM + 70;

    // Long as fuck
    case AJD_AJD:
    case LTA_LAETITIA:
    case ES_ESTCEQUE:
    case QES_QUESTCEQUE:
    /* case LEFT_HYPER: */
    /* case RIGHT_HYPER: */
      return COMBO_TERM + 120;
  }
  return COMBO_TERM;
}
// ---- END Combo terms ---- }}}

// --------------- LAYERS -------------------- {{{

// ---- BASE LAYER MACRO ---- {{{
#define BASELAYER LAYOUT(\
  TAB_MEH, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                              KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, MEDIA,\
  ESC_GUI, HRM_A,   HRM_R,   HRM_S,   HRM_T,   KC_G,                                              KC_M,    HRM_N,   HRM_E,   HRM_I,   HRM_O,   UD_APO,\
  _______, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    _______, _______,       _______, _______, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_MINS, SELECT,\
                             _______, LOWER,   NUM,     NAV,     OSS_L,         OSS_R,   KC_SPC,  KC_BSPC, FUNCT,   SELECT)
// ---- END BASE LAYER MACRO ---- }}}

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

[_BASE] = BASELAYER,

// ---- STENO ---- {{{
[_STENO] = LAYOUT(
  STENTAB, STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,                                            STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  MEDIA,
  STENESC, STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,                                           STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
  _______, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, NUM,     _______,       _______, _______, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
                             _______, NUM,     STN_A,   STN_O,   MO(_UBERBASE), STN_N1,  STN_E,   STN_U,   _______, _______
),
// ---- END STENO ---- }}}

// ---- GAMING ---- {{{
[_GAMING] = LAYOUT(
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ENT,
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                              KC_H,    KC_J,    KC_K,    KC_L,    KC_M,    KC_SCLN,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______,       _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                             _______, NUM,     NAV,     KC_SPC,  MO(_UBERBASE), LOWER,   KC_SPC,  KC_BSPC, _______, DF(_BASE)
),
// ---- END GAMING ---- }}}

// ---- NAV ---- {{{
[_NAV] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                                           _______, KC_PGDN, KC_PGUP, _______, _______, _______,
  _______, KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL, _______,                                           KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______,       _______, _______, KC_DEL,  _______, _______
),
// ---- END NAV ---- }}}

// ---- LOWER ---- {{{
[_LOWER] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
  _______, KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,                                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______, _______, KC_LCBR, KC_LBRC, KC_LPRN, KC_UNDS, _______, _______,       _______, _______, KC_MINS, KC_RPRN, KC_RBRC, KC_RCBR, _______, _______,
                             _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
// ---- END LOWER ---- }}}

// ---- NUM ---- {{{
[_NUM] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                                           KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_NUM,
  _______, KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL, _______,                                           KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_QUOT,
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
  _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,                                           _______, KC_RCTL, KC_RALT, KC_RGUI, KC_RSFT, _______,
  _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
// ---- END FUNCT ---- }}}

// ---- SELECT ---- {{{
[_SELECT] = LAYOUT(
  _______, DF(_GAMING),_______, _______, _______, _______,                                           _______, _______, _______, _______, _______, STENO,
  _______, _______,    _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
  _______, _______,    _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
// ---- END SELECT ---- }}}

[_UBERBASE] = BASELAYER

};
// --------------- END LAYERS --------------- }}}
