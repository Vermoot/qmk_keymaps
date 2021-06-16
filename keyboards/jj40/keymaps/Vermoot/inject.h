  switch(combo_index) {
    case OU_GRV: if (pressed) { tap_code(KC_O); } accented_letter(KC_GRV, KC_U, pressed); break;
    case MNEI_MEME: if (pressed) { tap_code(KC_M); accented_letter(S(KC_6), KC_E, pressed); SEND_STRING("me"); } break;
    case LTA_LAETITIA: if (pressed) {
                         unmod(S(KC_L));
                         SEND_STRING("a");
                         accented_letter(S(KC_QUOT), KC_E, pressed);
                         SEND_STRING("titia");
                       } break;
    case LA_LA: if (pressed) { tap_code(KC_L); } accented_letter(KC_GRV, KC_A, pressed); break;
    case CA_CA: if (pressed) { accented_letter(KC_QUOT, KC_C, pressed); tap_code(KC_A); } break;
    case PE_PEUT_ETRE: if (pressed) {
                          SEND_STRING("peut");
                          unmod(KC_MINUS);
                          accented_letter(S(KC_6), KC_E, pressed);
                          SEND_STRING("tre");
                        } break;
    case C_CEST:
      if (pressed) {
        tap_code(KC_C);
        unmod(KC_QUOT);
        SEND_STRING(" est");
      }
      break;
    case ETR_ETRE: if (pressed) { accented_letter(S(KC_6), KC_E, pressed); SEND_STRING("tre"); } break;
    case DJ_DEJA: if (pressed) {
          tap_code(KC_D);
          accented_letter(KC_QUOT, KC_E, pressed);
          tap_code(KC_J);
    }
      accented_letter(KC_GRV, KC_A, pressed);
    break;
    case C_A_CETAIT:
      if (pressed) {
        tap_code(KC_C);
        unmod(KC_QUOT);
        accented_letter(KC_QUOT, KC_E, pressed);
        SEND_STRING("tait");
      }
      break;
    case TR_TRES:
      if (pressed) { SEND_STRING("tr"); accented_letter(KC_GRV, KC_E, pressed); tap_code(KC_S); } break;
    // English
    case IM_IM: if (pressed) { unmod(S(KC_I)); unmod(KC_QUOT); tap_code(KC_M); } break;
    case DN_DONT: if (pressed) { SEND_STRING("don"); unmod(KC_QUOT); tap_code(KC_T); } break;
  }
