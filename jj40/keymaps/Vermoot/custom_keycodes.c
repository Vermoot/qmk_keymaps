// ---- Simple keycodes ---- {{{

// Modtaps n stuff
#define ESC_GUI MT(MOD_LGUI, KC_ESC)
#define TAB_MEH MEH_T(KC_TAB)
#define OSM_SFT OSM(MOD_LSFT)

// Home row mods
#define HRM_A MT(MOD_LSFT, KC_A)
#define HRM_O MT(MOD_RSFT, KC_O)
#define HRM_R MT(MOD_LGUI, KC_R)
#define HRM_I MT(MOD_RGUI, KC_I)
#define HRM_S MT(MOD_LALT, KC_S)
#define HRM_E MT(MOD_LALT, KC_E)
#define HRM_T MT(MOD_LCTL, KC_T)
#define HRM_N MT(MOD_RCTL, KC_N)

// Layer keys
#define BASE  DF(_BASE)
#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define NAV   MO(_NAV)
#define NUM   MO(_NUM)
#define MEDIA LT(_MEDIA, KC_ENT)
#define FUNCT MO(_FUNCT)
#define SELECT LT(_SELECT, KC_SPC)

// Misc
#define KC_EURO S(A(KC_2))

// Tapping terms {{{
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HRM_N: return TAPPING_TERM + 100;
        case HRM_T: return TAPPING_TERM + 100;
        case HRM_R: return TAPPING_TERM + 100;
        case HRM_I: return TAPPING_TERM + 100;
        case HRM_E: return TAPPING_TERM + 100;
        case HRM_S: return TAPPING_TERM + 100;
        case HRM_A: return 175;
        case HRM_O: return 250;
        default: return TAPPING_TERM;
    }
}
// END Tapping terms }}}

// ---- END Simple Keycodes ---- }}}

// ---- Less simple keycodes ---- {{{
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
  U_GRV,
  A_CIRC,
  I_CIRC,
  O_CIRC,
  U_CIRC,
  C_CED,

  // Combo keys
  CRN_L,
  RST_1,
  RST_2,
};

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
    case U_GRV: return accented_letter(KC_GRV, KC_U, record->event.pressed);
    case A_CIRC: return accented_letter(S(KC_6), KC_A, record->event.pressed);
    case I_CIRC: return accented_letter(S(KC_6), KC_I, record->event.pressed);
    case O_CIRC: return accented_letter(S(KC_6), KC_O, record->event.pressed);
    case U_CIRC: return accented_letter(S(KC_6), KC_U, record->event.pressed);
    case C_CED: return accented_letter(KC_QUOT, KC_C, record->event.pressed);

    default:
      return true;

    break;
  }
}

// ---- END Less simple keycodes ---- }}}
