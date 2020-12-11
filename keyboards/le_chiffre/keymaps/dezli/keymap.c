#include QMK_KEYBOARD_H
#include "dezli.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_wrapper(
    _________________BASE_L1_________________,  KC__MUTE,  _________________BASE_R1_________________,
    _________________BASE_L2_________________,             _________________BASE_R2_________________,
    _________________BASE_L3_________________,             _________________BASE_R3_________________,
    _________________L_2_THUMB_________________,         _________________R_2_THUMB_________________
  ),

  [_NUM_SYM] = LAYOUT(
        KC_1,  KC_2,     KC_3,     KC_4,      KC_5, KC_TRNS, KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
    KC_EXLM,  KC_AT,  KC_HASH,   KC_DLR,   KC_PERC,             KC_CIRC,  KC_AMPR,  KC_ASTR, KC_MINS,  KC_SLSH,
    KC_LBRC, KC_RBRC,  KC_BSLS, KC_EQL,   KC_RSHIFT,             KC_RSHIFT,  KC_GRAVE,  KC_UNDS,   KC_LPRN,   KC_RPRN,
                                KC_TRNS,   KC_TRNS,             KC_TRNS,  KC_TRNS
  ),

  [_NAV] = LAYOUT(
      KC_TRNS,  _______,  AG_NORM,  AG_SWAP,  DEBUG, KC_TRNS,   KC_GRV,  KC_PGDN,    KC_UP,  KC_PGUP,  KC_SCLN,
    RGB_TOG,  RGB_HUI,  RGB_SAI,  RGB_VAI,  KC_NO,           KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RGHT,   KC_END,
    RGB_MOD,  RGB_HUD,  RGB_SAD,  RGB_VAD,  KC_NO,           KC_MINS,    KC_RO,  KC_COMM,   KC_DOT,  KC_BSLS,
                                  KC_TRNS,KC_TRNS,           KC_TRNS,  KC_TRNS
  ),


  [_META] = LAYOUT(
      RESET,  _______,  AG_NORM,  AG_SWAP,  DEBUG, KC_TRNS,   KC_GRV,  KC_PGDN,    KC_UP,  KC_PGUP,  KC_SCLN,
      RGB_TOG,  RGB_HUI,  RGB_SAI,  RGB_VAI,  KC_NO,           KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RGHT,   KC_END,
      RGB_MOD,  RGB_HUD,  RGB_SAD,  RGB_VAD,  KC_NO,           KC_MINS,    KC_RO,  KC_COMM,   KC_DOT,  KC_BSLS,
                                    KC_TRNS,KC_TRNS,           KC_TRNS,  KC_TRNS
    ),

};
