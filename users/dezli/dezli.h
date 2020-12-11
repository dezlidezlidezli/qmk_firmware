#pragma once
#include "quantum.h"
#include "wrappers.h"

enum layers{
  _BASE,
  _NUM_SYM,
  _NAV,
  _META,
};

enum combos {
  TN_ENT,
  EO_ESC,
  NS_TAB,
  OA_TAB
};

#define KC_SU LSFT_T(KC_U)
#define KC_SH RSFT_T(KC_H)
#define KC_OA LALT_T(KC_A)
#define KC_OS LALT_T(KC_S)

#define KC_NUM_SPC LT(_NUM_SYM, KC_SPC)
#define KC_NAV_BSPC LT(_NAV, KC_BSPC)

void encoder_update_kb(uint8_t index, bool clockwise);
void matrix_scan_keymap(void);

extern bool is_alt_tab_active;
extern uint16_t alt_tab_timer;
