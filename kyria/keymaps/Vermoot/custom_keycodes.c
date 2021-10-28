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
#define NAV   LT(_NAV, KC_NO)
#define NUM   MO(_NUM)
#define MEDIA LT(_MEDIA, KC_ENT)
#define FUNCT MO(_FUNCT)
#define SELECT LT(_SELECT, KC_SPC)
#define STENO DF(_STENO)

// Misc
#define KC_EURO S(A(KC_2))
#define STENESC LT(0, KC_A) // hijacked and used later
#define STENTAB LT(0, KC_B) // hijacked and used later

// Tapping terms {{{
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    /* static uint16_t non_mod_input_timer = 0; */
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
          /* return timer_elapsed(non_mod_input_timer) > 500 ? 50 : TAPPING_TERM + 100; */
          return TAPPING_TERM;
        case SFT_A:
          return TAPPING_TERM - 25;
        case SFT_O:
          return TAPPING_TERM + 50;
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
    case NAV:
      if (record->tap.count == 0) {
        if (pressed) {
          prev_layers = layer_state;
          layer_move(_NAV);
        } else {
          layer_state_set(prev_layers);
        }
      } else if (record->tap.count > 0) {
        if (pressed) {
          add_oneshot_mods(MOD_BIT(KC_LSHIFT));
        }
      }
      return false;

    case STENESC:
      if (record->tap.count == 0) {
        if (pressed) {
          prev_layers = layer_state;
          layer_move(_UBERBASE);
          set_mods(MOD_BIT(KC_LCTRL) |
                   MOD_BIT(KC_LALT) |
                   MOD_BIT(KC_LSHIFT) |
                   MOD_BIT(KC_LGUI)); // Hyper
        } else {
          unregister_mods(0x0F); // Hyper
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
          set_mods(MOD_BIT(KC_LCTRL) |
                   MOD_BIT(KC_LALT) |
                   MOD_BIT(KC_LSHIFT)); // Meh
        } else {
          unregister_mods(MOD_BIT(KC_LCTRL) |
                          MOD_BIT(KC_LALT) |
                          MOD_BIT(KC_LSHIFT)); // Meh
          layer_state_set(prev_layers);
        }
      }
      return false;

    default:
      return true;

    break;
  }
}

// ---- END Less simple keycodes ---- }}}
