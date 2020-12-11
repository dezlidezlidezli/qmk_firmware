#pragma once
#include "dezli.h"
/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/
#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif

// clang-format off
#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)

#define _________________BASE_L1_________________        KC_QUOT, KC_COMM, KC_DOT, KC_P,     KC_Y
#define _________________BASE_L2_________________        KC_OA,    KC_O,    KC_E,   KC_SU,     KC_I
#define _________________BASE_L3_________________        KC_SCLN, KC_Q,    KC_J,   KC_K,     KC_X

#define _________________BASE_R1_________________        KC_F,    KC_G,    KC_C,    KC_R,    KC_L
#define _________________BASE_R2_________________        KC_D,    KC_SH,    KC_T,    KC_N,    KC_OS
#define _________________BASE_R3_________________        KC_B,    KC_M,    KC_W,    KC_V,    KC_Z

#define _________________L_2_THUMB_________________        KC_LGUI, KC_NUM_SPC,
#define _________________R_2_THUMB_________________        KC_NAV_BSPC, KC_LCTL
