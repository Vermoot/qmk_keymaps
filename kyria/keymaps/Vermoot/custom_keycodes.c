// ---- Simple keycodes ---- {{{

// Modtaps n stuff
#define ESC_HYP MT(MOD_HYPR, KC_ESC)
#define TAB_MEH MEH_T(KC_TAB)
#define OSM_SFT OSM(MOD_LSFT)

// Home row mods
#define SFT_A MT(MOD_LSFT, KC_A)
#define SFT_O MT(MOD_RSFT, KC_O)
#define CTL_R MT(MOD_LCTL, KC_R)
#define CTL_I MT(MOD_RCTL, KC_I)
#define ALT_S MT(MOD_LALT, KC_S)
#define ALT_E MT(MOD_LALT, KC_E)
#define CMMD_T MT(MOD_LGUI, KC_T)
#define CMMD_N MT(MOD_RGUI, KC_N)

// QWERTY Home Row Mods
#define SFT_SC MT(MOD_RSFT, KC_SCLN)
#define CTL_S MT(MOD_LCTL, KC_S)
#define CTL_L MT(MOD_RCTL, KC_L)
#define ALT_D MT(MOD_LALT, KC_D)
#define ALT_K MT(MOD_LALT, KC_K)
#define CMMD_F MT(MOD_LGUI, KC_F)
#define CMMD_J MT(MOD_RGUI, KC_J)

// Layer keys
#define BASE  DF(_BASE)
#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define NAV   MO(_NAV)
#define NUM   MO(_NUM)
#define MEDIA LT(_MEDIA, KC_ENT)
#define FUNCT MO(_FUNCT)
#define SELECT LT(_SELECT, KC_SPC)
#define STENO DF(_STENO)

// Misc
#define KC_EURO S(A(KC_2))

// Tapping terms {{{
/* static uint16_t non_mod_input_timer = 0; */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CMMD_N:
        case CMMD_T:
        case CTL_S:
        case CTL_L:
        case ALT_K:
        case ALT_D:
        case CTL_R:
        case CTL_I:
        case ALT_E:
        case ALT_S:
          /* return timer_elapsed(non_mod_input_timer) > 500 ? TAPPING_TERM + 100 : 5; */
          return TAPPING_TERM + 100;
        case SFT_A: return 175;
        case SFT_O: return 250;
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
