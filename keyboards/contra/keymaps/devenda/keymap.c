/* Copyright 2015-2017 Jack Humbert
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
#include "keycode.h" // added for code completion
#include "keymap_belgian.h"
#include "sendstring_belgian.h"

enum planck_layers {
  _AZ,
  _LO,
  _RA,
  _FU
};

// Tap Dance declarations
enum {
    TD_LPRN,
    TD_RPRN,
    TD_LABK,
    TD_RABK
};

// Custom keycodes (macros,...)
enum custom_keycodes {
    SQLSEL = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Azerty
   * ,-----------------------------------------------------------------------------------.
   * | Esc  |   A  |   Z  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Tab  |   Q  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   M  |Enter |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   W  |   X  |   C  |   V  |   B  |   N  |   ,  |   ;  |   :  |  Up  |Shift |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Ctrl | GUI  | Func | Alt  |Lower |    Space    |Raise |AltGr | Left | Down |Right |
   * `-----------------------------------------------------------------------------------'
   */
  [_AZ] = LAYOUT_planck_mit(
    KC_ESC,  BE_A,    BE_Z,    BE_E,    BE_R,    BE_T,    BE_Y,    BE_U,    BE_I,    BE_O,    BE_P,    KC_BSPC,
    KC_TAB,  BE_Q,    BE_S,    BE_D,    BE_F,    BE_G,    BE_H,    BE_J,    BE_K,    BE_L,    BE_M,    KC_ENT,
    KC_LSFT, BE_W,    BE_X,    BE_C,    BE_V,    BE_B,    BE_N,    BE_COMM, BE_SCLN, BE_COLN, KC_UP,   KC_RSFT,
    KC_LCTL, KC_LGUI, MO(_FU), KC_LALT, MO(_LO),      KC_SPC,      MO(_RA), KC_ALGR, KC_LEFT, KC_DOWN, KC_RGHT
  ),

   /* Lower 
   * ,-----------------------------------------------------------------------------------.
   * |  ESC |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |   |  |   @  |   #  |   _  |TD ({[|  /   |  \   |TD )}]|   -  |   +  |   =  |  *   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |      |      |      |TD <[ |      |      |TD >] |   %  |   $  | Pg Up|      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |      | Home | Pg Do| End  |
   * `-----------------------------------------------------------------------------------'
   */
  [_LO] = LAYOUT_planck_mit(
    KC_ESC,  BE_1,    BE_2,    BE_3,    BE_4,        BE_5,    BE_6,    BE_7,        BE_8,    BE_9,    BE_0,    KC_BSPC,
    BE_PIPE, BE_AT,   BE_HASH, BE_UNDS, TD(TD_LPRN), BE_SLSH, BE_BSLS, TD(TD_RPRN), BE_MINS, BE_PLUS, BE_ASTR, BE_EQL,
    _______, _______, _______, _______, TD(TD_LABK), _______, _______, TD(TD_RABK), BE_PERC, BE_DLR,  KC_PGUP, _______,
    _______, _______, _______, _______, _______,         _______,      _______,     _______, KC_HOME, KC_PGDN, KC_END
  ),

  /* Raise 
   * ,-----------------------------------------------------------------------------------.
   * | ESC  |   &  |   é  |   "  |   '  |   (  |   §  |   è  |   !  |   ç  |   à  | Del  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |   |  |   @  |   #  |   _  |TD ({ |  /   |  \   |TD )} |   -  |   +  |   =  |  *   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |      |      |      |TD <[ |      |      |TD >] |   %  |   $  | Vol+ | Play |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |      | Prev | Vol- | Next |
   * `-----------------------------------------------------------------------------------'
   */
  [_RA] = LAYOUT_planck_mit(
    KC_ESC,  BE_AMPR, BE_EACU, BE_DQUO, BE_QUOT,     BE_LPRN, BE_SECT, BE_EGRV,     BE_EXLM, BE_CCED, BE_AGRV, KC_DEL,
    BE_PIPE, BE_AT,   BE_HASH, BE_UNDS, TD(TD_LPRN), BE_SLSH, BE_BSLS, TD(TD_RPRN), BE_MINS, BE_PLUS, BE_ASTR, BE_EQL,
    _______, _______, _______, _______, TD(TD_LABK), _______, _______, TD(TD_RABK), BE_PERC, BE_DLR,  KC_VOLU, KC_MPLY,
    _______, _______, _______, _______, _______,         _______,      _______,     _______, KC_MPRV, KC_VOLD, KC_MNXT
  ),
  
  /* Function
   * ,-----------------------------------------------------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |SQLSEL|      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |      |Ctrl -|      |CtSh -|
   * `-----------------------------------------------------------------------------------'
   */
 [_FU] = LAYOUT_planck_mit(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,        KC_F11,  KC_F12,
    _______, _______, SQLSEL,  _______, _______, _______, _______, _______, _______, _______,       _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______,
    _______, _______, _______, _______, _______,     _______,      _______, _______, LCTL(BE_MINS), _______, LCTL(LSFT(BE_MINS)) 
   ) 
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LPRN] = ACTION_TAP_DANCE_DOUBLE(BE_LPRN, BE_LCBR),
    [TD_RPRN] = ACTION_TAP_DANCE_DOUBLE(BE_RPRN, BE_RCBR),
    [TD_LABK] = ACTION_TAP_DANCE_DOUBLE(BE_LABK, BE_LBRC),
    [TD_RABK] = ACTION_TAP_DANCE_DOUBLE(BE_RABK, BE_RBRC),
};

// Custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case SQLSEL:
        if (record->event.pressed) {
            // when keycode SQLSEL is pressed
            SEND_STRING("SELECT *\r\nFROM \r\nORDER BY 1 DESC");
            SEND_STRING(SS_TAP(X_UP));
        } else {
            // when keycode QMKBEST is released
        }
        break;
    }
    return true;
};