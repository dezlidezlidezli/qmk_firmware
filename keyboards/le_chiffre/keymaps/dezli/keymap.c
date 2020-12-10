#include QMK_KEYBOARD_H

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


#define KC_NUM_SPC LT(_NUM_SYM, KC_SPC)
#define KC_NAV_BSPC LT(_NAV, KC_BSPC)

// #define KC_GA LGUI_T(KC_A)
// #define KC_AS LALT_T(KC_S)
// #define KC_CD LCTL_T(KC_D)
#define KC_SU LSFT_T(KC_U)
#define KC_DLRS LSFT_T(KC_DLR)
#define KC_APRS RSFT_T(KC_AMPR)
#define KC_SH RSFT_T(KC_H)
// #define KC_CK RCTL_T(KC_K)
//#define KC_AL RALT_T(KC_L)
// #define KC_GSCLN RGUI_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_QUOT, KC_COMM, KC_DOT, KC_P,   KC_Y,  KC__MUTE,  KC_F,   KC_G,   KC_C,  KC_R,  KC_L,
    KC_A,    KC_O,    KC_E,   KC_SU,  KC_I,            KC_D,   KC_SH,  KC_T,  KC_N,  KC_S,
    KC_SCLN, KC_Q,    KC_J,   KC_K,   KC_X,            KC_B,   KC_M,   KC_W,  KC_V,  KC_Z,
                           KC_LGUI, KC_NUM_SPC,     KC_NAV_BSPC, KC_LCTL
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


layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _NUM_SYM, _NAV, _META);
    return state;
}

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

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC__VOLUP);
        } else {
            tap_code(KC__VOLDOWN);
        }
    }
}
