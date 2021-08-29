#include QMK_KEYBOARD_H

bool undead(uint16_t  character, bool pressed) {
  if (pressed) {
    tap_code16(character);
    tap_code(KC_SPC);
  }
  return false;
}

void unmod(uint16_t keycode) {
  uint8_t mod_state = get_mods();
  uint8_t osm_state = get_oneshot_mods();
  /* clear_mods(); clear_oneshot_mods(); clear_macro_mods(); clear_weak_mods(); */
  unregister_mods(MOD_MASK_SHIFT);
  del_oneshot_mods(MOD_MASK_SHIFT);
  tap_code16(keycode);
  register_mods(mod_state);
  add_oneshot_mods(osm_state);
}

bool accented_letter(uint16_t accent, uint16_t letter, bool pressed) {
  if (pressed) {                        // On press:
    unmod(accent);                      // Press accent, unmoded
    register_code(letter);              // Press letter.
  } else {                              // On release: (this is for repeats on hold down)
    unregister_code(letter);            // Release letter
  }                                     // If shift is pressed it'll be released by the user
  return false;                         // Don't continue with the key handling.
}
