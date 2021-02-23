// Vermoot's ortho grid keymap

// --------------- DEFINITIONS --------------- {{{

// ---- Options ---- {{{

// Mandatory
#include QMK_KEYBOARD_H
#include "virtser.h"

/*
// Steno stuff
#include "keymap_steno.h"
void matrix_init_user() {
    steno_set_mode(STENO_MODE_GEMINI);
}
*/

// One-handed keyboard
const keypos_t hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
  {{11, 0}, {10, 0}, {9, 0}, {8, 0}, {7, 0}, {6, 0}, {5, 0}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}},
  {{11, 1}, {10, 1}, {9, 1}, {8, 1}, {7, 1}, {6, 1}, {5, 1}, {4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}},
  {{11, 2}, {10, 2}, {9, 2}, {8, 2}, {7, 2}, {6, 2}, {5, 2}, {4, 2}, {3, 2}, {2, 2}, {1, 2}, {0, 2}},
  {{11, 3}, {10, 3}, {9, 3}, {8, 3}, {7, 3}, {6, 3}, {5, 3}, {4, 3}, {3, 3}, {2, 3}, {1, 3}, {0, 3}},
};

// ----------------- }}}

// ---- Enums ---- {{{

enum layers {
  _BASE,
  _RAISE,
  _LOWER,
  _NAV,
  _NUM,
  _MEDIA,
  _FUNCT,
  _SELECT,
  _STENO,
  _GAMING
};

enum custom_keycodes {
  // Undead characters
  UD_APO = SAFE_RANGE,
  UD_GRV,
  UD_TLD,
  UD_CIRC,

  // Accented letters
  E_ACUTE,
  E_GRV,
  E_CIRC,
  A_GRV,
  A_CIRC,
  I_CIRC,
  O_CIRC,
  U_CIRC,
  C_CED,

  // Bigrams
  BI_ON,
  BI_UN,

  // Combo keys
  CRN_L,
  RST_1,
  RST_2,
};

// --------------- }}}

// ---- Custom functions ---- {{{

bool undead(uint16_t  character, bool pressed) {
  if (pressed) {
    tap_code16(character);
    tap_code(KC_SPC);
  }
  return false;
}

void unmod(uint16_t letter) {
  uint8_t mod_state = get_mods();
  uint8_t osm_state = get_oneshot_mods();
  unregister_mods(MOD_MASK_SHIFT);
  del_oneshot_mods(MOD_MASK_SHIFT);
  tap_code16(letter);
  register_mods(mod_state);
  add_oneshot_mods(osm_state);
}

bool accented_letter(uint16_t accent, uint16_t letter, bool pressed) {
  if (pressed) {          // On press:
    unmod(accent);
    register_code(letter);              // Press letter.
  } else {                              // On release: (this is for repeats on hold down)
    unregister_code(letter);            // Release letter
  }                                     // If shift is pressed it'll be released by the user
  return false;                         // Don't continue with the key handling.
}

// -------------------------- }}}

// ---- Custom keys ---- {{{

// Simple ones {{{
// Modtaps
#define ESC_FN MT(MOD_HYPR, KC_ESC)
#define TAB_MEH MEH_T(KC_TAB)
#define OSM_SFT OSM(MOD_LSFT)

// Home row mods
#define SFT_A MT(MOD_LSFT, KC_A)
#define SFT_SC MT(MOD_RSFT, KC_SCLN)
#define CTL_S MT(MOD_LCTL, KC_S)
#define CTL_L MT(MOD_RCTL, KC_L)
#define ALT_D MT(MOD_LALT, KC_D)
#define ALT_K MT(MOD_LALT, KC_K)
#define CMD_F MT(MOD_LGUI, KC_F)
#define CMD_J MT(MOD_RGUI, KC_J)

// Layer keys
#define BASE  DF(_BASE)
#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define NAV   MO(_NAV)
#define NUM   MO(_NUM)
#define MEDIA LT(_MEDIA, KC_ENT)
#define FUNCT MO(_FUNCT)
#define SELECT MO(_SELECT)

// Misc
#define KC_EURO S(A(KC_2))

// Tapping terms {{{
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTL_S: return TAPPING_TERM + 100;
        case CTL_L: return TAPPING_TERM + 100;
        case ALT_K: return TAPPING_TERM + 100;
        case ALT_D: return TAPPING_TERM + 100;
        case SFT_A: return 175; default:
            return TAPPING_TERM;
    }
}
// }}}
// }}}

// Accented letters {{{
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    // Undead characters
    case UD_APO: return undead(KC_QUOT, record->event.pressed);
    case UD_GRV: return undead(KC_GRV, record->event.pressed);
    case UD_TLD: return undead(S(KC_GRV), record->event.pressed);
    case UD_CIRC: return undead(S(KC_6), record->event.pressed);

    // Accented letters
    case E_ACUTE: return accented_letter(KC_QUOT, KC_E, record->event.pressed);
    case E_GRV: return accented_letter(KC_GRV, KC_E, record->event.pressed);
    case E_CIRC: return accented_letter(S(KC_6), KC_E, record->event.pressed);
    case A_GRV: return accented_letter(KC_GRV, KC_A, record->event.pressed);
    case A_CIRC: return accented_letter(S(KC_6), KC_A, record->event.pressed);
    case I_CIRC: return accented_letter(S(KC_6), KC_I, record->event.pressed);
    case O_CIRC: return accented_letter(S(KC_6), KC_O, record->event.pressed);
    case U_CIRC: return accented_letter(S(KC_6), KC_U, record->event.pressed);

    // Bigrams
    case BI_ON: if (record->event.pressed) { SEND_STRING("on"); } return true;
    case BI_UN: if (record->event.pressed) { SEND_STRING("un"); } return true;
    default:
      return true;

    break;
  }
}
// }}}

// Combos {{{

enum combo_events {/*{{{*/
  // Accents
  ER_E_ACUTE,
  EW_E_GRAVE,
  WER_E_CIRC,
  UIO_I_CIRC,
  IOP_O_CIRC,
  YUI_U_CIRC,
  ASD_A_CIRC,
  AS_A_GRV,
  XC_C_CED,
  // Common words
    // French
    OU_GRV,
    BCP_BEAUCOUP,
    MWER_MEME,
    LTA_LAETITIA,
    CA_CA,
    LA_LA,
    PTE_PEUT_ETRE,
    UI_UN,
    OI_ON,
    C_CEST,
    CM_COMME,
    ETR_ETRE,
    DJ_DEJA,
    PA_PAS,
    C_A_CETAIT,
    ME_MENT,
    // English
    I_CAPS,
    IM_IM,
    DN_DONT,
  // Combo keys
  LEFT_ARROW,
  RIGHT_ARROW,
  UP_ARROW,
  DOWN_ARROW,
  CORNER_SPACE,
  JL_ALT_BCSP,
  A_SC_OSM_SFT,
  A_SL_QUESTION,
  RS_SPC_HANDS_SWAP,
  LW_NAV_HANDS_SWAP,
  CMB_RESET,
};/*}}}*/

// consts {{{
// Accents
const uint16_t PROGMEM acute_e_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM grave_e_combo[] = {KC_E, KC_W, COMBO_END};
const uint16_t PROGMEM circ_e_combo[]  = {KC_E, KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM i_circ_combo[] = {KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM o_circ_combo[] = {KC_I, KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM u_circ_combo[] = {KC_Y, KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM a_circ_combo[] = {SFT_A, CTL_S, ALT_D, COMBO_END};
const uint16_t PROGMEM a_grave_combo[] = {SFT_A, CTL_S, COMBO_END};
const uint16_t PROGMEM c_ced_combo[] = {KC_X, KC_C, COMBO_END};
// Common words
  // French
const uint16_t PROGMEM ou_grave_combo[] = {KC_O, KC_U, COMBO_END};
const uint16_t PROGMEM beaucoup_combo[] = {KC_B, KC_C, KC_P, COMBO_END};
const uint16_t PROGMEM meme_combo[] = {KC_M, KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM laetitia_combo[] = {CTL_L, KC_T, SFT_A, COMBO_END};
const uint16_t PROGMEM ca_combo[] = {KC_C, SFT_A, COMBO_END};
const uint16_t PROGMEM la_combo[] = {CTL_L, SFT_A, COMBO_END};
const uint16_t PROGMEM peut_etre_combo[] = {KC_P, KC_T, KC_E, COMBO_END};
const uint16_t PROGMEM un_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM on_combo[] = {KC_O, KC_I, COMBO_END};
const uint16_t PROGMEM cest_combo[] = {KC_C, UD_APO, COMBO_END};
const uint16_t PROGMEM comme_combo[] = {KC_C, KC_M, COMBO_END};
const uint16_t PROGMEM etre_combo[] = {KC_E, KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM deja_combo[] = {ALT_D, CMD_J, COMBO_END};
const uint16_t PROGMEM pas_combo[] = {KC_P, SFT_A, COMBO_END};
const uint16_t PROGMEM cetait_combo[] = {KC_C, UD_APO, SFT_A, COMBO_END};
const uint16_t PROGMEM ment_combo[] = {KC_M, KC_E, COMBO_END};
  // English
const uint16_t PROGMEM cap_i_combo[] = {SFT_A, KC_I, COMBO_END};
const uint16_t PROGMEM i_m_combo[] = {KC_I, KC_M, COMBO_END};
const uint16_t PROGMEM dont_combo[] = {ALT_D, KC_N, COMBO_END};
// Combo keys
const uint16_t PROGMEM right_arrow[] = {CRN_L, SELECT, COMBO_END};
const uint16_t PROGMEM left_arrow[] = {KC_BSPC, FUNCT, COMBO_END};
const uint16_t PROGMEM up_arrow[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM down_arrow[] = {FUNCT, CRN_L, COMBO_END};
const uint16_t PROGMEM space_combo[] = {FUNCT, CRN_L, SELECT, COMBO_END};
const uint16_t PROGMEM alt_bcsp_combo[] = {CMD_J, CTL_L, COMBO_END};
const uint16_t PROGMEM a_sc_oneshotshift_combo[] = {SFT_A, SFT_SC, COMBO_END};
const uint16_t PROGMEM question_mark_combo[] = {SFT_A, KC_SLSH, COMBO_END};
const uint16_t PROGMEM hands_swap_right[] = {RAISE, KC_SPC, COMBO_END};
const uint16_t PROGMEM hands_swap_left[] = {LOWER, NAV, COMBO_END};
const uint16_t PROGMEM reset_combo[] = {RST_1, RST_2, COMBO_END};
/*}}}*/

combo_t key_combos[] = {/*{{{*/
  // Accents
  [ER_E_ACUTE] = COMBO(acute_e_combo, E_ACUTE),
  [EW_E_GRAVE] = COMBO(grave_e_combo, E_GRV),
  [WER_E_CIRC] = COMBO(circ_e_combo, E_CIRC),
  [UIO_I_CIRC] = COMBO(i_circ_combo, I_CIRC),
  [IOP_O_CIRC] = COMBO(o_circ_combo, O_CIRC),
  [YUI_U_CIRC] = COMBO(u_circ_combo, U_CIRC),
  [ASD_A_CIRC] = COMBO(a_circ_combo, A_CIRC),
  [AS_A_GRV] = COMBO(a_grave_combo, A_GRV),
  [XC_C_CED] = COMBO(c_ced_combo, C_CED),

  // Common words
    // French
    [OU_GRV] = COMBO_ACTION(ou_grave_combo),
    [BCP_BEAUCOUP] = COMBO_ACTION(beaucoup_combo),
    [MWER_MEME] = COMBO_ACTION(meme_combo),
    [LTA_LAETITIA] = COMBO_ACTION(laetitia_combo),
    [CA_CA] = COMBO_ACTION(ca_combo),
    [LA_LA] = COMBO_ACTION(la_combo),
    [PTE_PEUT_ETRE] = COMBO_ACTION(peut_etre_combo),
    [UI_UN] = COMBO(un_combo, BI_UN),
    [OI_ON] = COMBO(on_combo, BI_ON),
    [C_CEST] = COMBO_ACTION(cest_combo),
    [CM_COMME] = COMBO_ACTION(comme_combo),
    [ETR_ETRE] = COMBO_ACTION(etre_combo),
    [DJ_DEJA] = COMBO_ACTION(deja_combo),
    [PA_PAS] = COMBO_ACTION(pas_combo),
    [C_A_CETAIT] = COMBO_ACTION(cetait_combo),
    [ME_MENT] = COMBO_ACTION(ment_combo),
    // English
    [I_CAPS] = COMBO(cap_i_combo, S(KC_I)),
    [IM_IM] = COMBO_ACTION(i_m_combo),
    [DN_DONT] = COMBO_ACTION(dont_combo),

  // Combo keys
  [LEFT_ARROW] = COMBO(left_arrow, KC_LEFT),
  [RIGHT_ARROW] = COMBO(right_arrow, KC_RGHT),
  [UP_ARROW] = COMBO(up_arrow, KC_UP),
  [DOWN_ARROW] = COMBO(down_arrow, KC_DOWN),
  [CORNER_SPACE] = COMBO(space_combo, KC_SPC),
  [JL_ALT_BCSP] = COMBO(alt_bcsp_combo, A(KC_BSPC)),
  [A_SC_OSM_SFT] = COMBO(a_sc_oneshotshift_combo, OSM(MOD_LSFT)),
  [A_SL_QUESTION] = COMBO(question_mark_combo, S(KC_SLSH)),
  [RS_SPC_HANDS_SWAP] = COMBO(hands_swap_right, SH_MON),
  [LW_NAV_HANDS_SWAP] = COMBO(hands_swap_left, SH_MON),
  [CMB_RESET] = COMBO(reset_combo, RESET),
};/*}}}*/

void process_combo_event(uint16_t combo_index, bool pressed) {/*{{{*/
  switch(combo_index) {

    // Accents{{{
    case ER_E_ACUTE: accented_letter(KC_QUOT, KC_E, pressed); break;
    case EW_E_GRAVE: accented_letter(KC_GRV, KC_E, pressed); break;
    case WER_E_CIRC: accented_letter(S(KC_6), KC_E, pressed); break;
    case UIO_I_CIRC: accented_letter(S(KC_6), KC_I, pressed); break;
    case IOP_O_CIRC: accented_letter(S(KC_6), KC_O, pressed); break;
    case YUI_U_CIRC: accented_letter(S(KC_6), KC_U, pressed); break;
    case ASD_A_CIRC: accented_letter(S(KC_6), KC_A, pressed); break;
    case AS_A_GRV: accented_letter(KC_GRV, KC_A, pressed); break;
    case XC_C_CED: accented_letter(KC_QUOT, KC_C, pressed); break;
    /*}}}*/

    // Common words{{{
    // French
    case OU_GRV: if (pressed) { tap_code(KC_O); } accented_letter(KC_GRV, KC_U, pressed); break;
    case BCP_BEAUCOUP: if (pressed) { SEND_STRING("beaucoup"); } break;
    case MWER_MEME: if (pressed) { tap_code(KC_M); accented_letter(S(KC_6), KC_E, pressed); SEND_STRING("me"); } break;
    case LTA_LAETITIA: if (pressed) {
                         unmod(S(KC_L));
                         SEND_STRING("a");
                         accented_letter(S(KC_QUOT), KC_E, pressed);
                         SEND_STRING("titia");
                       } break;
    case LA_LA: if (pressed) { tap_code(KC_L); } accented_letter(KC_GRV, KC_A, pressed); break;
    case CA_CA: if (pressed) { accented_letter(KC_QUOT, KC_C, pressed); tap_code(KC_A); } break;
    case PTE_PEUT_ETRE: if (pressed) {
                          SEND_STRING("peut");
                          unmod(KC_MINUS);
                          tap_code(E_CIRC);
                          SEND_STRING("tre");
                        } break;
    case UI_UN: if (pressed) { tap_code(BI_UN); } break;
    case OI_ON: if (pressed) { tap_code(BI_ON); } break;
    case C_CEST:
      if (pressed) {
        tap_code(KC_C);
        unmod(KC_QUOT);
        SEND_STRING(" est");
      }
      break;
    case CM_COMME: if (pressed) { SEND_STRING("comme"); } break;
    case ETR_ETRE: if (pressed) { accented_letter(S(KC_6), KC_E, pressed); SEND_STRING("tre"); } break;
    case DJ_DEJA: if (pressed) {
          tap_code(KC_D);
          accented_letter(KC_QUOT, KC_E, pressed);
          tap_code(KC_J);
    }
      accented_letter(KC_GRV, KC_A, pressed);
    break;
    case PA_PAS: if (pressed) { SEND_STRING("pas"); } break;
    case C_A_CETAIT:
      if (pressed) {
        tap_code(KC_C);
        unmod(KC_QUOT);
        accented_letter(KC_QUOT, KC_E, pressed);
        SEND_STRING("tait");
      }
      break;
    case ME_MENT: if (pressed) { SEND_STRING("ment"); } break;
    // English
    case IM_IM: if (pressed) { unmod(S(KC_I)); unmod(KC_QUOT); tap_code(KC_M); } break;
    case DN_DONT: if (pressed) { SEND_STRING("don"); unmod(KC_QUOT); tap_code(KC_T); } break;
    /*}}}*/

    // Combo keys{{{

    /*}}}*/
  }
}/*}}}*/

// Combo terms {{{
uint16_t get_combo_term(uint16_t index, combo_t *combo) {
  if (KEYCODE_IS_MOD(combo->keycode)) { return COMBO_MOD_TERM; }
  switch (index) {
    case ER_E_ACUTE: return 20;
    case WER_E_CIRC: return 100;
    case UIO_I_CIRC: return 100;
    case IOP_O_CIRC: return 100;
    case YUI_U_CIRC: return 100;
    case ASD_A_CIRC: return 100;
    // case AS_A_GRV: return 50;
    case XC_C_CED: return 100;
    case BCP_BEAUCOUP: return 100;
    case MWER_MEME: return 100;
    case LTA_LAETITIA: return 100;
    case CA_CA: return 50;
    case PTE_PEUT_ETRE: return 50;
    case C_CEST: return 50;
    case UI_UN: return 20;
    case OI_ON: return 20;
    case I_CAPS: return 50;
    case A_SC_OSM_SFT: return 50;
    case JL_ALT_BCSP: return 100;
    case CM_COMME: return 150;
    case ETR_ETRE: return 15;
    case C_A_CETAIT: return 100;
    case A_SL_QUESTION: return 100;
    case RS_SPC_HANDS_SWAP: return 150;
    case LW_NAV_HANDS_SWAP: return 150;
  }
  return COMBO_TERM;
}
// }}}

// }}}

// --------------------- }}}

// ------------------------------------------- }}}

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

------------------------- }}} */

// ---- BASE LAYER ---- {{{
[_BASE] = LAYOUT_ortho_4x12( \
  TAB_MEH, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    MEDIA,
  ESC_FN,  SFT_A,   CTL_S,   ALT_D,   CMD_F,   KC_G,    KC_H,    CMD_J,   ALT_K,   CTL_L,   SFT_SC,  UD_APO,
  OSM_SFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  KC_LCTL, KC_LALT, KC_LGUI, NUM,     NAV,     LOWER,   RAISE,   KC_SPC,  KC_BSPC, FUNCT,   CRN_L,   SELECT
),
// -------------------- }}}

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
  _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,  _______, _______, _______
),
// --------------- }}}

// ---- NUM ---- {{{
[_NUM] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_BSPC, \
  _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______, \
  _______, _______, _______, _______, _______, _______, KC_PEQL, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, \
  _______, _______, _______, _______, _______, _______, KC_SPC,  KC_P0,   KC_BSPC, KC_PDOT, _______, _______ \
),
// --------------- }}}

// ---- MEDIA ---- {{{
[_MEDIA] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BRIU, KC_VOLU, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BRID, KC_VOLD, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MRWD, KC_MPLY, KC_MFFD \
),
// --------------- }}}

// ---- FUNCT ---- {{{
[_FUNCT] = LAYOUT_ortho_4x12(
  KC_F1,   KC_F2,   KC_F3,  _______, _______, _______, _______, _______, _______, _______, RST_1,   RST_2,
  KC_F4,   KC_F5,   KC_F6,  _______, _______, _______, _______, KC_RGUI, KC_RALT, KC_RCTL, KC_RSFT, _______,
  KC_F7,   KC_F8,   KC_F9,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
  KC_F10,  KC_F11,  KC_F12, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
// --------------- }}}

// ---- SELECT ---- {{{
[_SELECT] = LAYOUT_ortho_4x12(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, DF(_STENO),
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, DF(_GAMING),
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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
};

// ------------------------------------------- }}}
