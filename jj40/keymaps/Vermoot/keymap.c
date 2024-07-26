// Vermoot's ortho grid keymap

// --------------- DEFINITIONS --------------- {{{

// #includes
#include QMK_KEYBOARD_H

enum layers {
  _BASE,
  _SPLIT,
  _RAISE,
  _LOWER,
  _NAV,
  _NUM,
  _MEDIA,
  _FUNCT,
  _SELECT,
  _STENO,
  _GAMING,
  _ELITE
};

#include "custom_functions.c"
#include "custom_keycodes.c"
#include "g/keymap_combo.h"


/* // Steno stuff for one day {{{
 * #include "keymap_steno.h"
 * void matrix_init_user() {
 *     steno_set_mode(STENO_MODE_GEMINI);
 * }
 }}} */

// One-handed keyboard
const keypos_t hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
  {{11, 0}, {10, 0}, {9, 0}, {8, 0}, {7, 0}, {6, 0}, {5, 0}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}},
  {{11, 1}, {10, 1}, {9, 1}, {8, 1}, {7, 1}, {6, 1}, {5, 1}, {4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}},
  {{11, 2}, {10, 2}, {9, 2}, {8, 2}, {7, 2}, {6, 2}, {5, 2}, {4, 2}, {3, 2}, {2, 2}, {1, 2}, {0, 2}},
  {{11, 3}, {10, 3}, {9, 3}, {8, 3}, {7, 3}, {6, 3}, {5, 3}, {4, 3}, {3, 3}, {2, 3}, {1, 3}, {0, 3}},
};


uint16_t get_combo_term(uint16_t index, combo_t *combo) {
  /* if (KEYCODE_IS_MOD(combo->keycode)) { return COMBO_MOD_TERM; } */
  switch (index) {
    /* case EI_E_ACUTE: return 20; */
    /* case NEI_E_CIRC: return 50; */
    case EIO_I_CIRC:        return 100;
    case IO_O_CIRC:         return 100;
    case LUY_U_CIRC:        return 100;
    case ARS_A_CIRC:        return 100;
    // case AR_A_GRV: return 50;
    /* case XC_C_CED: return 100; */
    case BOU_BEAUCOUP:      return 50;
    case OU_OU:             return COMBO_TERM - 10;
    case MNE_MEME:          return 100;
    case LTA_LAETITIA:      return 100;
    /* case CA_CA: return 50; */
    case PER_PEUT_ETRE:     return 50;
    case C_CEST:            return 50;
    // case MT_MENT:           return 100;
    case I_CAPS:            return 50;
    case AO_OS_SHIFT:       return 50;
    /* case NI_HRM_BCSP: return 50; */
    // case CM_COMME:          return 150;
    case ETR_ETRE:          return 100;
    case C_A_CETAIT:        return 100;
    case A_SL_QUESTION:     return 100;
    case DEAD_UMLAUT: return COMBO_TERM - 10;
    // case VOL_UP:
    // case VOL_DOWN: 
    //   return 20;
  }
  return COMBO_TERM;
}

// --------------- END DEFINITIONS ----------- }}}

// --------------- LAYERS -------------------- {{{

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* ---- BLANK LAYOUT ---- {{{

// ----  ---- {{{
[] = LAYOUT_ortho_4x12(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)
// ---------- }}}

// ------------------------- }}} */

// ---- BASE LAYER ---- {{{
[_BASE] = LAYOUT_ortho_4x12( \
  TAB_MEH, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, MEDIA,
  ESC_GUI, HRM_A,   HRM_R,   HRM_S,   HRM_T,   KC_G,    KC_M,    HRM_N,   HRM_E,   HRM_I,   HRM_O,   UD_APO,
  OSS_L,   KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_MINS, KC_RSFT,
  KC_LCTL, KC_LALT, KC_LGUI, KC_SYRQ, NUM,     NAV,     KC_SPC,  KC_BSPC, FUNCT,   _______, CRN_L,   SELECT
),
// -------------------- }}}

[_SPLIT] = LAYOUT_ortho_4x12( \
  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    TAB_MEH, MEDIA,   KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, 
  HRM_A,   HRM_R,   HRM_S,   HRM_T,   KC_G,    ESC_GUI, UD_APO,  KC_M,    HRM_N,   HRM_E,   HRM_I,   HRM_O,   
  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    OSS_L,   KC_RSFT, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_MINS, 
  KC_LALT, KC_LGUI, _______, NUM,     NAV,     KC_LCTL, SELECT,   KC_SPC,  KC_BSPC, FUNCT,   _______, CRN_L
),

// ---- RAISE ---- {{{
[_RAISE] = LAYOUT_ortho_4x12( \
  _______, _______, _______, KC_EURO, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, _______,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, UD_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  _______, UD_GRV,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
// --------------- }}}

// ---- LOWER ---- {{{
[_LOWER] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  _______,
  _______, _______, KC_LCBR, KC_LBRC, KC_LPRN, _______, _______, KC_RPRN, KC_RBRC, KC_RCBR, _______, KC_BSLS,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
// --------------- }}}

// ---- NAV ---- {{{
[_NAV] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, KC_PGDN, KC_PGUP, _______, _______, _______,
  _______, KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______
),
// --------------- }}}

// ---- NUM ---- {{{
[_NUM] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_NUM, \
  _______, KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL, _______, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______, \
  _______, _______, _______, _______, _______, _______, KC_PEQL, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, \
  _______, _______, _______, _______, _______, _______, KC_P0,   KC_BSPC, KC_COMM, KC_PDOT, _______, _______ \
),
// --------------- }}}

// ---- MEDIA ---- {{{
[_MEDIA] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BRIU, KC_VOLU, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BRID, KC_VOLD, KC_F13, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_F14, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MRWD, KC_MPLY, KC_MFFD \
),
// --------------- }}}

// ---- FUNCT ---- {{{
[_FUNCT] = LAYOUT_ortho_4x12(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, _______, _______, RST_1,   RST_2,
  _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, KC_RCTL, KC_RALT, KC_RGUI, KC_RSFT, _______,
  _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
// --------------- }}}

// ---- SELECT ---- {{{
[_SELECT] = LAYOUT_ortho_4x12(
  _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, DF(_STENO),
  _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, DF(_GAMING),
  _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  DF(_ELITE), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
// ---------------- }}}

/*
// ---- STENO ---- {{{
[_STENO] = LAYOUT_ortho_4x12(
  XXXXXXX, XXXXXXX, STN_N3,  STN_N4,  STN_N5,  XXXXXXX, XXXXXXX, STN_N8,  STN_N9,  STN_NA,  XXXXXXX, XXXXXXX,
  XXXXXXX, STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
  XXXXXXX, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, STN_A,   STN_O,   STN_E,   STN_U,   XXXXXXX, XXXXXXX, XXXXXXX, BASE
)
// ---------------- }}}
*/

// ---- GAMING ---- {{{
[_GAMING] = LAYOUT_ortho_4x12(
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    MEDIA,
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  KC_LCTL, KC_LALT, KC_LGUI, NUM,     NAV,     LOWER,   RAISE,   KC_SPC,  KC_BSPC, FUNCT,   CRN_L,   DF(_BASE)
),
// ---------- }}}

// ---- ELITE ---- {{{
[_ELITE] = LAYOUT_ortho_4x12(
  DF(_BASE), KC_INS,  _______, KC_HOME, _______, _______, _______, _______, _______, KC_F22, KC_F23, KC_F24,
  _______,   KC_DEL,  KC_Q,    KC_END,  _______, _______, _______, _______, _______, KC_F13, KC_F14, KC_F15,
  KC_BSPC,   KC_A,    KC_SPC,  KC_D,    _______, _______, _______, _______, _______, KC_F16, KC_F17, KC_F18,
  _______,   _______, KC_S,    _______, _______, _______, _______, _______, _______, KC_F19, KC_F20, KC_F21
),
// ---------- }}}
};

// ------------------------------------------- }}}
