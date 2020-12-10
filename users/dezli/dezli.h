#include "quantum.h"
#include "quantum.h"

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

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
