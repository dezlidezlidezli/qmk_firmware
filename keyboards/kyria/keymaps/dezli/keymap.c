/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include <stdio.h>
#include <stdlib.h>
#include "dezli.c"
//layers and what their number alias is

enum my_keycodes {
     KC_CHAT = SAFE_RANGE, // Activate chat and go to chat layer
     KC_COMMAND, // activate chat with commands, and go to chat layer
     KC_MCENT, // exit chat with enter, and go back to gaming layer
     KC_MCESC, // above, but with escape
     };

enum layers {
    _DVORAK = 0,
    _LOWER = 1,
    _RAISE = 2,
    _QWERTY = 3,
    _GAMING = 4,
    _GAMINGCHAT = 5,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: DVORAK
 *
 * KEYCODES FOUND AT https://docs.qmk.fm/#/keycodes?id=dynamic-macros
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | LCKSCRN|   "  |   ,  |   .  |   P  |   Y  |                              |   F  |   G  |   C  |   R  |   L  |  MUTE  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  TAB   |   A  |   O  |  E   |   U  |   I  |                              |   D  |   H  |   T  |   N  |   S  |  ? /   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |   ~    | : ;  |   Q  |   J  |   K  |   X  |Space |Raise |  |Enter | BKSP |   B  |   M  |   W  |   V  |   Z  |  - _   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | Alt  | Ctl  | CMD  |Space | Lower|  | Esc  | Shift| CMD  | \ |  | + =  |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
// done, except layer movement and QWERTY command
    [_DVORAK] = LAYOUT( //0
      C(G(KC_Q)), KC_QUOTE,  KC_COMMA,   KC_DOT,   KC_P,    KC_Y,                                          KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC__MUTE,
      KC_TAB,     KC_A,      KC_O,       KC_E,     KC_U,    KC_I,                                          KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
      KC_GRAVE,   KC_SCLN,   KC_Q,       KC_J,     KC_K,    KC_X,     KC_NO,  TT(2),              KC_ENT, KC_ESC, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_MINS,
                                         KC_LALT,  KC_LCTL, LM(3, MOD_LGUI),  KC_SPC, TT(1),      KC_LSFT, KC_BSPC, LM(3, MOD_LGUI), KC_BSLS, KC_EQL
    ),
/*
 * Lower Layer: numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | LCKSCRN|   !  |   @  |   #  |  $   |  %   |                              |   %  |   1  |   2  |   3  |   :  |  MUTE  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  TAB   |   ^  |   &  |   *  |  (   |   )  |                              |   $  |   4  |   5  |   6  |   +  |  ENT   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |    ~   |   [  |   ]  |   -  |  <   |   >  | SPACE| RAISE|  | ENTER| BKSP |   -  |   7  |   8  |   9  |   =  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | Alt  | Ctl  | CMD  | SPACE| LOWER|  |  ESC | SHFT | CMD  |   0  |   0  |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
     [_LOWER] = LAYOUT( //1
       _______,    KC_EXLM,   KC_AT,     KC_HASH,  KC_DLR,   KC_PERC,                                              KC_PERC, KC_P1,   KC_P2,   KC_P3,   KC_COLN,  _______,
       KC_TAB,     KC_CIRC,   KC_AMPR,   KC_ASTR,  KC_LPRN,  KC_RPRN,                                              KC_DLR,  KC_P4,   KC_P5,   KC_P6,   KC_PLUS,  KC_ENT,
       KC_GRAVE,   KC_LBRC,   KC_RBRC,   KC_MINS,  KC_RABK,  KC_LABK,   _______,  _______,      _______, _______,  KC_MINS, KC_P7,   KC_P8,   KC_P9,   KC_EQL,   KC_NO,
                                         _______,  _______,  _______,   _______,  _______,      _______, _______,  _______, KC_P0,   KC_P0
    ),

/*
 * Raise Layer: F keys, media and arow keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |  UP  |      | B-UP |                              |      |  F1  |  F2  |  F3  |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      | LEFT | DOWN |RIGHT |B-DOWN|                              |      |  F4  |  F5  |  F6  |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |  <<  |  ||  |  >>  |      |      |      |  |      |      |      |  F7  |  F8  |  F9  |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_RAISE] = LAYOUT( //2
      _______, KC_NO,  KC_NO,   KC_UP,   KC_NO,   KC_BRMD,                                          TO(4), KC_NO, KC_NO, KC_NO, KC_NO, _______,
      KC_NO,   KC_NO,  KC_LEFT, KC_DOWN, KC_RGHT, KC_BRMU,                                          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO,   KC_NO,  KC_MPRV, KC_MPLY, KC_MNXT, KC_NO,   _______, _______,    _______, _______,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                               _______, _______, _______,  _______, _______,    _______, _______, _______, KC_NO, KC_NO
    ),

    [_QWERTY] = LAYOUT( //5
      _______,    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
      KC_TAB,     KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT,    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,  _______, _______,                  _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                              _______, _______, _______, _______, _______,                  _______,  _______, _______, _______, _______
    ),
/*
 * Gaming Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   |   1  |   2  |  3   |   4  |  5   |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  TAB   | TAB  |   Q  |   W  |  E   |  R   |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  SHFT  | SHFT |   A  |   S  |  D   |  C   |  SPC |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |   6  |   7  |      |  SPC |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_GAMING] = LAYOUT( //3
      KC_ESC,  KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,                                     KC_CHAT,   KC_CHAT,   KC_CHAT,   KC_CHAT,  KC_COMMAND,  KC_NO,
      KC_ESC,  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,                                     KC_CHAT,   KC_CHAT,   KC_CHAT,   KC_CHAT,  KC_COMMAND,  KC_NO,
      KC_LSFT, KC_LSFT, KC_A,    KC_S,    KC_D,    KC_C,    KC_SPC,  KC_NO,    TO(0), TO(0), KC_NO,  KC_COMMAND,  KC_COMMAND,  KC_COMMAND, KC_COMMAND,  KC_COMMAND,
                                 KC_6,    KC_7,    KC_LALT, KC_SPC,  KC_NO,    TO(0), TO(0), KC_NO,  KC_NO,  KC_NO
    ),

    [_GAMINGCHAT] = LAYOUT( //4
      KC_MCESC,     KC_QUOTE,  KC_COMMA,   KC_DOT,   KC_P,    KC_Y,                                          KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_MCENT,
      KC_MCESC,     KC_A,      KC_O,       KC_E,     KC_U,    KC_I,                                          KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MCENT,
      KC_GRAVE,   KC_SCLN,   KC_Q,       KC_J,     KC_K,    KC_X,     KC_NO,  KC_NO,      KC_MCENT,  KC_BSPC,   KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_MCENT,
                                         KC_LALT,  KC_LCTL, KC_LGUI,  KC_SPC, KC_NO,      KC_MCESC, KC_LSFT, KC_RGUI, KC_BSLS, KC_EQL
    ),


// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case KC_CHAT:
    if (record->event.pressed) {
      tap_code(KC_T);
  //    tap_code16(TO(5));
      layer_on(5);
      return false;
    }
//    break;
  case KC_MCESC:
    if (record->event.pressed) {
      tap_code(KC_ESC);
      //      tap_code16(TO(4));
      layer_off(5);
      layer_on(4);
      return false;
    }
//    break;
  case KC_COMMAND:
    if (record->event.pressed) {
      tap_code(KC_SLSH);
      //    tap_code16(TO(5));
      layer_on(5);
      return false;
    }
//    break;
  case KC_MCENT:
    if (record->event.pressed) {
      tap_code(KC_ENT);
//      tap_code16(TO(4));
      layer_off(5);
      layer_on(4);
      return false;
    }
//    break;
//  return false; // Skip all further processing of this key
    default:
      return true; // Process all other keycodes normally
  }
}
