// ---- Simple keycodes ---- {{{

// Modtaps n stuff
#define ESC_HYP MT(MOD_HYPR, KC_ESC)
#define ESC_GUI MT(MOD_LGUI, KC_ESC)
#define TAB_MEH MEH_T(KC_TAB)
#define OSS_L OSM(MOD_LSFT)
#define OSS_R OSM(MOD_RSFT)

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
#define BASE   DF(_BASE)
#define LOWER  MO(_LOWER)
/* #define NAV    MO(_NAV) */
#define NAV    LT(_NAV, KC_SPC)
#define NUM    MO(_NUM)
#define D_NUM  LT(_NUM, KC_D)
#define MEDIA  LT(_MEDIA,  KC_ENT)
#define FUNCT  MO(_FUNCT)
#define SELECT LT(_SELECT, KC_SPC)
#define STENO  DF(_STENO)

// Misc
#define KC_EURO ALGR(KC_5)
#define STENESC LT(0, KC_A) // hijacked and used later
#define STENTAB LT(0, KC_B) // hijacked and used later
#define R_THUM1 KC_NO

// Tapping terms {{{
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    static uint16_t non_mod_input_timer;
    non_mod_input_timer = timer_read();
    switch (keycode) {
        case HRM_N:
        case HRM_T:
        case HRM_R:
        case HRM_I:
        case HRM_E:
        case HRM_S:
          return timer_elapsed(non_mod_input_timer) > 500 ? 50 : TAPPING_TERM + 100;
          /* return TAPPING_TERM; */
        case HRM_A:
          return TAPPING_TERM*2;
        case HRM_O:
          return TAPPING_TERM*2;
        default:
          return TAPPING_TERM;
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

  // Utilities
  /* STENESC, */
  MOBASE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  const bool pressed = record->event.pressed;
  static layer_state_t prev_layers = 0;

  switch (keycode) {

    // Undead characters
    case UD_APO: return undead(KC_QUOT, pressed);
    case UD_GRV: return undead(KC_GRV, pressed);
    case UD_TLD: return undead(S(KC_GRV), pressed);
    case UD_CIRC: return undead(S(KC_6), pressed);

    // Accented letters
    case E_ACUTE: return accented_letter(KC_QUOT, KC_E, pressed);
    case E_GRV: return accented_letter(KC_GRV, KC_E, pressed);
    case E_CIRC: return accented_letter(S(KC_6), KC_E, pressed);
    case A_GRV: return accented_letter(KC_GRV, KC_A, pressed);
    case U_GRV: return accented_letter(KC_GRV, KC_U, pressed);
    case A_CIRC: return accented_letter(S(KC_6), KC_A, pressed);
    case I_CIRC: return accented_letter(S(KC_6), KC_I, pressed);
    case O_CIRC: return accented_letter(S(KC_6), KC_O, pressed);
    case U_CIRC: return accented_letter(S(KC_6), KC_U, pressed);
    case C_CED: return accented_letter(KC_QUOT, KC_C, pressed);

    // Utilities
    /* case NAV: */
      /* if (record->tap.count == 0) { */
        /* if (pressed) { */
          /* prev_layers = layer_state; */
          /* layer_move(_NAV); */
        /* } else { */
          /* layer_state_set(prev_layers); */
        /* } */
      /* } else if (record->tap.count > 0) { */
        /* if (pressed) { */
          /* add_oneshot_mods(MOD_BIT(KC_LSHIFT)); */
        /* } */
      /* } */
      /* return false; */

    case STENESC:
      if (record->tap.count == 0) {
        if (pressed) {
          prev_layers = layer_state;
          layer_move(_UBERBASE);
          set_mods(MOD_BIT(KC_LGUI));
        } else {
          unregister_mods(MOD_BIT(KC_LGUI));
          layer_state_set(prev_layers);
        }
      } else if (record->tap.count > 0) {
        if (pressed) {
          default_layer_set(0x000000001); // DF(_BASE)
        }
      }
      return false;

    case STENTAB:
      if (record->tap.count == 0) {
        if (pressed) {
          prev_layers = layer_state;
          layer_move(_UBERBASE);
          set_mods(MOD_BIT(KC_LCTL) |
                   MOD_BIT(KC_LALT) |
                   MOD_BIT(KC_LSFT)); // Meh
        } else {
          unregister_mods(MOD_BIT(KC_LCTL) |
                          MOD_BIT(KC_LALT) |
                          MOD_BIT(KC_LSFT)); // Meh
          layer_state_set(prev_layers);
        }
      } else if (record->tap.count > 0) {
        if (pressed) {
          tap_code(KC_TAB);
        }
      }
      return false;

    default:
      return true;

    break;
  }
}

// ---- END Less simple keycodes ---- }}}
