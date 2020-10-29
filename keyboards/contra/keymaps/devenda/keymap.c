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
   * |  ESC |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |  <   |  >   |      |      |  /   |  \   |   _  |   +  |TD ({[|TD )}]|  -   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | Pg Up|      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |      | Home | Pg Do| End  |
   * `-----------------------------------------------------------------------------------'
   */
  [_LO] = LAYOUT_planck_mit(
    KC_ESC,  BE_1,    BE_2,    BE_3,    BE_4,    BE_5,    BE_6,    BE_7,    BE_8,    BE_9,        BE_0,        KC_DEL,
    _______, BE_LABK, BE_RABK, _______, _______, BE_SLSH, BE_BSLS, BE_UNDS, BE_PLUS, TD(TD_LPRN), TD(TD_RPRN), BE_MINS,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     KC_PGUP,     _______,
    _______, _______, _______, _______, _______,     _______,      _______, _______, KC_HOME,     KC_PGDN,     KC_END
  ),

  /* Raise 
   * ,-----------------------------------------------------------------------------------.
   * | ESC  |   &  |   é  |   "  |   '  |   (  |   §  |   è  |   !  |   ç  |   à  | Del  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |   |  |   @  |   #  |      |      |      |      |   =  |   [  |   ]  |  *   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | Vol+ |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |      | Prev | Vol+ | Play |
   * `-----------------------------------------------------------------------------------'
   */
  [_RA] = LAYOUT_planck_mit(
    KC_ESC,  BE_AMPR, BE_EACU, BE_DQUO, BE_QUOT, BE_LPRN, BE_SECT, BE_EGRV, BE_EXLM, BE_CCED, BE_AGRV, KC_DEL,
    _______, BE_PIPE, BE_AT,   BE_HASH, _______, _______, _______, _______, BE_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU, KC_MPLY,
    _______, _______, _______, _______, _______,     _______,      _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
  ),
  
  /* Function
   * ,-----------------------------------------------------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |      |Ctrl -|      |CtSh -|
   * `-----------------------------------------------------------------------------------'
   */
 [_FU] = LAYOUT_planck_mit(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,        KC_F11,  KC_F12,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______,
    _______, _______, _______, _______, _______,     _______,      _______, _______, LCTL(BE_MINS), _______, LCTL(LSFT(BE_MINS)) 
   ) 
};

// Tap Dance definitions
void dance_lprn_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(BE_LPRN);
    } else if (state->count == 2) {
        register_code16(BE_LCBR);
    } else {
        register_code16(BE_LBRC);
    }
}

void dance_lprn_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(BE_LPRN);
    } else if (state->count == 2) {
        unregister_code16(BE_LCBR);
    } else {
        unregister_code16(BE_LBRC);
    }
}

void dance_rprn_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(BE_RPRN);
    } else if (state->count == 2) {
        register_code16(BE_RCBR);
    } else {
        register_code16(BE_RBRC);
    }
}

void dance_rprn_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(BE_RPRN);
    } else if (state->count == 2) {
        unregister_code16(BE_RCBR);
    } else {
        unregister_code16(BE_RBRC);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_LPRN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_lprn_finished, dance_lprn_reset),
    [TD_RPRN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_rprn_finished, dance_rprn_reset),
};