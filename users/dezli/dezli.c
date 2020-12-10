#include "dezli.h"

const uint16_t PROGMEM ent_combo[] = {KC_T, KC_N, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_E, KC_O, COMBO_END};
const uint16_t PROGMEM tab2_combo[] = {KC_O, KC_A, COMBO_END};
const uint16_t PROGMEM tab1_combo[] = {KC_N, KC_S, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [TN_ENT] = COMBO(ent_combo,KC_ENT),
  [EO_ESC] = COMBO(esc_combo,KC_ESC),
  [NS_TAB] = COMBO(tab1_combo,KC_TAB),
  [OA_TAB] = COMBO(tab2_combo,KC_TAB)
};

#ifdef ENCODER_ENABLE

__attribute__((weak))
void encoder_update_kb(int8_t index, bool clockwise) {
}

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder for window movement with command tab and command shift tab - it says alt tab but the function has been replaced*/
    if (clockwise) {
      tap_code(KC__VOLUP);
    } else {
      tap_code(KC__VOLDOWN);
    }
  } else if (index == 1) { /* Second encoder used for volunme*/
    if (clockwise) {
      if (!is_alt_tab_active) {
        is_alt_tab_active = true;
        register_code(KC_LGUI);
      }
      alt_tab_timer = timer_read();
      tap_code16(KC_TAB);
} else {
      if (!is_alt_tab_active) {
        is_alt_tab_active = true;
        register_code(KC_LGUI);
      }
      alt_tab_timer = timer_read();
      tap_code16(S(KC_TAB));
}
    }
}
__attribute__((weak))
void matrix_scan_keymap(void) {
}
void matrix_scan_user(void) {
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 750) {
            unregister_code(KC_LGUI);
            is_alt_tab_active = false;
            }
        }
}

#endif
