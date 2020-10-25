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

#include "keycode.h" // added for code completion
#include "keymap_belgian.h"

enum planck_layers {
  _AZ,
  _LO,
  _RA,
  _FU
};

// Tap Dance declarations
enum {
    TD_LPRN,
    TD_RPRN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Azerty
   * ,-----------------------------------------------------------------------------------.
   * | Esc  |   A  |   Z  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Tab  |   Q  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   M  |Enter |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   W  |   X  |   C  |   V  |   B  |   N  |   ,  |   .  |   /  |  Up  |Shift |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Ctrl | Func | GUI  | Alt  |Lower |    Space    |Raise |AltGr | Left | Down |Right |
   * `-----------------------------------------------------------------------------------'
   */
  [_AZ] = LAYOUT_planck_mit(
    KC_ESC,  BE_A,    BE_Z,    BE_E,    BE_R,    BE_T,    BE_Y,    BE_U,    BE_I,    BE_O,    BE_P,    KC_BSPC,
    KC_TAB,  BE_Q,    BE_S,    BE_D,    BE_F,    BE_G,    BE_H,    BE_J,    BE_K,    BE_L,    BE_M,    KC_ENT,
    KC_LSFT, BE_W,    BE_X,    BE_C,    BE_V,    BE_B,    BE_N,    BE_COMM, BE_DOT,  BE_SLSH, KC_UP,   KC_RSFT,
    KC_LCTL, MO(_FU), KC_LGUI, KC_LALT, MO(_LO),      KC_SPC,      MO(_RA), KC_ALGR, KC_LEFT, KC_DOWN, KC_RGHT
  ),

   /* Lower
   * ,-----------------------------------------------------------------------------------.
   * |   &  |   é  |   "  |   '  |   (  |   §  |   è  |   !  |   ç  |   à  |   )  | Del  |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   _  |   +  |TD ({[|TD )}]|  |   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | Pg Up|      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |      | Home | Pg Do| End  |
   * `-----------------------------------------------------------------------------------'
   */
  [_LO] = LAYOUT_planck_mit(
    BE_SUP3, BE_AMPR, BE_EACU, BE_DQUO, BE_QUOT, BE_LPRN, BE_SECT, BE_EGRV, BE_EXLM, BE_CCED,     BE_AGRV,     KC_DEL,
    _______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, TD(TD_LPRN), TD(TD_RPRN), KC_PIPE,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     KC_PGUP,     _______,
    _______, _______, _______, _______, _______,     _______,      _______, _______, KC_HOME,     KC_PGDN,     KC_END
  ),

  /* Raise
   * ,-----------------------------------------------------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
   * `-----------------------------------------------------------------------------------'
   */
  [_RA] = LAYOUT_planck_mit(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______,     _______,      _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
  ),
  
  /* Function
   * ,-----------------------------------------------------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
 [_FU] = LAYOUT_planck_mit(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______) 
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_LPRN] = ACTION_TAP_DANCE_DOUBLE(BE_LPRN, BE_LCBR),
    [TD_RPRN] = ACTION_TAP_DANCE_DOUBLE(BE_RPRN, BE_RCBR)
};


// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     case AZERT:
//       if (record->event.pressed) {
//         print("mode just switched to AZERT and this is a huge string\n");
//         set_single_persistent_default_layer(_AZERT);
//       }

//       return false;
//       break;  
//     case LOWER:
//       if (record->event.pressed) {
//         layer_on(_LOWER);
//         update_tri_layer(_LOWER, _RAISE, _ADJUST);
//       } else {
//         layer_off(_LOWER);
//         update_tri_layer(_LOWER, _RAISE, _ADJUST);
//       }

//       return false;
//       break;
//     case RAISE:
//       if (record->event.pressed) {
//         layer_on(_RAISE);
//         update_tri_layer(_LOWER, _RAISE, _ADJUST);
//       } else {
//         layer_off(_RAISE);
//         update_tri_layer(_LOWER, _RAISE, _ADJUST);
//       }

//       return false;
//       break;
//   }

//   return true;
// }
