/*
Le chiffre rev2
*/

#include QMK_KEYBOARD_H

enum layers{
  _BASE,
  _NUM_SYM,
  _NAV,
  //_PAD,
  _META
};

enum custom_keycodes{
  RGBRST = SAFE_RANGE,
};

#define KC_NAV_SPC LT(_NAV, KC_SPC)
#define KC_NUM_BSPC LT(_NUM_SYM, KC_BSPC)
//#define KC_GZ LGUI_T(KC_Z)
//#define KC_AV LALT_T(KC_V)
//define KC_CR LCTL_T(KC_R)
#define KC_SF LSFT_T(KC_F)
#define KC_SJ RSFT_T(KC_J)
//#define KC_CU RCTL_T(KC_U)
//#define KC_AM RALT_T(KC_M)
//#define KC_GSCLN RGUI_T(KC_SCLN)
//#define KC_GSLSH RGUI_T(KC_SLSH)

enum combo_events{
  COMBO_BSPC,
  COMBO_NUMBAK,
  COMBO_TAB,
  COMBO_ESC,
  COMBO_DEL,
  COMBO_ENTER,
  COMBO_SMCLN,
  COMBO_COMGUI,
  COMBO_CAPS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,  KC_MUTE,  KC_Y,   KC_U,    KC_I,   KC_O,     KC_P,
    KC_A,   KC_S,  KC_D,   KC_SF,   KC_G,            KC_H,  KC_SJ,    KC_K,   KC_L,  KC_QUOT,
    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,            KC_N,   KC_M, KC_COMM, KC_DOT,  KC_SLSH,
                         KC_LCTL, KC_NUM_BSPC,            KC_NAV_SPC, KC_RALT
  ),

  [_NUM_SYM] = LAYOUT(
        KC_1,  KC_2,     KC_3,     KC_4,      KC_5,  KC_MPLY,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
    KC_EXLM,  KC_AT,  KC_HASH,   KC_DLR,   KC_PERC,            KC_CIRC,  KC_AMPR,  KC_ASTR, KC_EQUAL,  KC_MINS,
    KC_BSLS, KC_UNDS,   KC_LCBR,  KC_LBRC,  KC_LPRN,            KC_RPRN,  KC_RBRC,  KC_RCBR,   KC_DOT,   KC_GRV,
                                KC_TRNS,   KC_TRNS,            KC_TRNS,  KC_TRNS
  ),

  [_NAV] = LAYOUT(
    KC_WBAK,  KC_PGDN,	 KC_UP,  KC_PGUP,   KC_WFWD, KC_WHOM, KC_WBAK,  KC_PGDN,    KC_UP,  KC_PGUP,  KC_WFWD,
    KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_END,           KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RGHT,   KC_END,
    KC_LSFT,  KC_CUT,  KC_COPY,  KC_PASTE,  KC_UNDO,                KC_MINS,    KC_RO,  KC_COMM,   KC_DOT,  KC_RSFT,
                                  KC_TRNS,KC_TRNS,           KC_TRNS,  KC_TRNS
  ),

  [_META] = LAYOUT(
     RESET,  KC_F19,  KC_F20,  KC_F21,  KC_F22,    RGB_TOG,   KC_F1,  KC_F2,    KC_F3,  KC_F4,  KC_SLEP,
    RGB_MOD,  RGB_HUI,  RGB_SAI,  RGB_VAI,  KC_F23,           KC_F5,  KC_F6,  KC_F7,  KC_F8,   KC_PAUS,
    RGB_RMOD,  RGB_HUD,  RGB_SAD,  RGB_VAD,  KC_F24,           KC_F9,    KC_F10,  KC_F11,   KC_F12,  KC_BSLS,
                                  KC_TRNS,KC_TRNS,           KC_TRNS,  KC_TRNS
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _NUM_SYM, _NAV, _META);
    return state;
}

#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_bspc[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_numbak[] = {KC_0, KC_9, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_del[] = {KC_MINS, KC_EQL, COMBO_END};
const uint16_t PROGMEM combo_enter[] = {KC_L, KC_QUOT, COMBO_END};
const uint16_t PROGMEM combo_smcln[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_comgui[] = {KC_B, KC_N, COMBO_END};
const uint16_t PROGMEM combo_caps[] = {KC_G, KC_H, COMBO_END};
//const uint16_t PROGMEM combo_[] = {KC_, KC_, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_BSPC] = COMBO(combo_bspc,KC_BSPC),
  [COMBO_NUMBAK] = COMBO(combo_numbak,KC_BSPC),
  [COMBO_TAB] = COMBO(combo_tab,KC_TAB),
  [COMBO_ESC] = COMBO(combo_esc,KC_ESC),
  [COMBO_DEL] = COMBO(combo_del,KC_DEL),
  [COMBO_ENTER] = COMBO(combo_enter,KC_ENTER),
  [COMBO_SMCLN] = COMBO(combo_smcln,KC_SCLN),
  [COMBO_COMGUI] = COMBO(combo_comgui,KC_LGUI),
  [COMBO_CAPS] = COMBO(combo_caps,KC_CAPS),
};
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch(biton32(layer_state)){
			case _META:
				if(clockwise) {
				rgblight_step();
				} else {
				rgblight_step_reverse();
				} break;

			 case _NAV:
                if (clockwise) {
                register_code(KC_LCTL);
                tap_code(KC_TAB);
                unregister_code(KC_LCTL);
                } else {
                register_code(KC_LCTL);
				register_code(KC_LSFT);
                tap_code(KC_TAB);
                unregister_code(KC_LCTL);
				unregister_code(KC_LSFT);
                }
                break;

            case _NUM_SYM:
                if (clockwise) {
                tap_code(KC_MNXT);
                } else {
                tap_code(KC_MPRV);

                }
                break;

            default:
                if (clockwise){
                    tap_code(KC_VOLU);
                } else{
                    tap_code(KC_VOLD);
                }
                break;
      }
    }
  }
#endif

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_90;  // rotates for dank proper orientation
}

void render_lechiffre_logo(void) {
    static const char PROGMEM lechiffre_logo[] = {
	// 'lechiffre_logo', 32x20px
   0x00, 0x3e, 0x20, 0x20, 0x00, 0x18, 0x2c, 0xa8, 0x80, 0x00, 0x1c, 0x22, 0x22, 0x00, 0x3e, 0x08, 
0x30, 0x00, 0x34, 0x00, 0x3c, 0x0a, 0x00, 0xbc, 0x8a, 0x00, 0x38, 0x08, 0x00, 0x18, 0x2c, 0x28, 
0x00, 0xb6, 0xb6, 0x00, 0xdb, 0xdb, 0x00, 0x6d, 0x6d, 0x00, 0xdb, 0xdb, 0x00, 0xdb, 0xdb, 0x00, 
0x00, 0xdb, 0xdb, 0x00, 0xdb, 0xdb, 0x00, 0x6d, 0x6d, 0x00, 0xdb, 0xdb, 0x00, 0xb6, 0xb6, 0x00, 
0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x06, 0x06, 0x06, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, 
0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00
};

  oled_write_raw_P(lechiffre_logo, sizeof(lechiffre_logo));
}

static void render_layer_status(void) {
    oled_write_P(PSTR("-----"), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("BASE"), false);
            break;
        case _NUM_SYM:
            oled_write_ln_P(PSTR(" SYM"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR(" NAV"), false);
            break;
		//case _PAD:
        //    oled_write_ln_P(PSTR(" PAD"), false);
        //    break;
        case _META:
            oled_write_ln_P(PSTR("META"), false);
            break;
        default:
            oled_write_ln_P(PSTR("?????"), false);
    }
}

/*
void render_prompt(void) {
    bool blink = (timer_read() % 1000) < 500;

    if (layer_state_is(_BASE)) {
        oled_write_ln_P(blink ? PSTR("> BS_") : PSTR("> BS "), false);
    } else if (layer_state_is(_NUM_SYM)) {
        oled_write_ln_P(blink ? PSTR("> SM_") : PSTR("> SM "), false);
    } else if (layer_state_is(_NAV)) {
        oled_write_ln_P(blink ? PSTR("> NV_") : PSTR("> NV "), false);
    } else if (layer_state_is(_META)) {
        oled_write_ln_P(blink ? PSTR("> MT_") : PSTR("> MT "), false);
    } else {
        oled_write_ln_P(blink ? PSTR("> _  ") : PSTR(">    "), false);
    }
};
*/

#    define KEYLOG_LEN 11
char     keylog_str[KEYLOG_LEN] = {};
uint8_t  keylogs_str_idx        = 0;
uint16_t log_timer              = 0;

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void add_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }

    for (uint8_t i = KEYLOG_LEN - 1; i > 0; i--) {
        keylog_str[i] = keylog_str[i - 1];
    }
    if (keycode < 60) {
        keylog_str[0] = code_to_name[keycode];
    }
    keylog_str[KEYLOG_LEN - 1] = 0;

    log_timer = timer_read();
}

void update_log(void) {
    if (timer_elapsed(log_timer) > 750) {
        add_keylog(0);
    }
}

//Text only renders
void render_keylogger_status(void) {
    oled_write_P(PSTR("-----"), false);
    oled_write(keylog_str, false);
}

void render_keylock_status(uint8_t led_usb_state) {
    oled_write_P(PSTR("-----"), false);
    oled_write_P(PSTR("C"), led_usb_state & (1 << USB_LED_CAPS_LOCK));
	oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("N"), led_usb_state & (1 << USB_LED_NUM_LOCK));
	oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("S"), led_usb_state & (1 << USB_LED_SCROLL_LOCK));
    //oled_write_ln_P(PSTR(" "), false);
}

void render_mod_status(uint8_t modifiers) {
       oled_write_P(PSTR("-----"), false);
    oled_write_ln_P(PSTR("SHFT"), (modifiers & MOD_MASK_SHIFT));
    oled_write_ln_P(PSTR("ALT"), (modifiers & MOD_MASK_ALT));
    oled_write_ln_P(PSTR("CTRL"), (modifiers & MOD_MASK_CTRL));
    oled_write_ln_P(PSTR("GUI"), (modifiers & MOD_MASK_GUI));
}

void oled_task_user(void) {
    render_lechiffre_logo();
    oled_set_cursor(0,3);
    render_layer_status();	// Renders the current keyboard state (layer, lock, caps, scroll, etc)
	render_mod_status(get_mods()|get_oneshot_mods());
	render_keylock_status(host_keyboard_leds());
	render_keylogger_status();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
      add_keylog(keycode);
    }
    return true;
  }
#endif 
