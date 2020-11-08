#include QMK_KEYBOARD_H

#include <stdio.h>
#include "keycode.h" // added for code completion
#include "keymap_belgian.h"
#include "sendstring_belgian.h"

enum planck_layers {
  _AZ,
  _FU,
  _QMK
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    /* Azerty
    * ,-----------------------------------------------------------------------------------------.
    * | ESC |  &  |  é  |  "  |  '  |  (  |  §  |  è  |  !  |  ç  |  à  |  )  |  -  |   Bkspc   |
    * |-----------------------------------------------------------------------------------------+
    * | Tab    |  A  |  Z  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  ^  |  $  |  Enter |
    * |-----------------------------------------------------------------------------------------+
    * | Caps    |  Q  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  M  |  ù  |    Enter    |
    * |-----------------------------------------------------------------------------------------+
    * | Shift    |  W  |  X  |  C  |  V  |  B  |  N  |  ,  |  ;  |  :  |  =   | RSh |  Up | Del |
    * |-----------------------------------------------------------------------------------------+
    * | Ctrl |  Alt  |  Cmd |     Space   |  Fn  |     Space     | RAlt | Cmd | Left| Down| Rght|
    * `-----------------------------------------------------------------------------------------'
    */
    [_AZ] = LAYOUT_directional(
        KC_ESC, BE_AMPR, BE_EACU, BE_DQUO, BE_QUOT, BE_LPRN, BE_SECT, BE_EGRV, BE_EXLM, BE_CCED, BE_AGRV, BE_RPRN, BE_MINS, KC_BSPC, KC_BSPC, 
        KC_TAB, BE_A, BE_Z, BE_E, BE_R, BE_T, BE_Y, BE_U, BE_I, BE_O, BE_P, BE_DCIR, BE_DLR, KC_ENT, 
        KC_CAPS, BE_Q, BE_S, BE_D, BE_F, BE_G, BE_H, BE_J, BE_K, BE_L, BE_M, BE_UGRV, KC_ENT, 
        KC_LSFT, BE_W, BE_X, BE_C, BE_V, BE_B, BE_N, BE_COMM, BE_SCLN, BE_COLN, BE_EQL, KC_RSFT, KC_UP,   KC_DEL, 
        KC_LCTL, KC_LGUI, KC_LALT,   KC_SPC  , MO(_FU),   KC_SPC  , KC_RALT, KC_RCTL,   KC_LEFT, KC_DOWN, KC_RGHT),

  /* Function Layer
   * ,-----------------------------------------------------------------------------------------.
   * |     |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |     |     |
   * |-----------------------------------------------------------------------------------------+
   * |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
   * |-----------------------------------------------------------------------------------------+
   * |         | _QMK|     |     |     |     |     |     |     |     |     |      |            |
   * |-----------------------------------------------------------------------------------------+
   * |           |     |     |     |     |     |     |     |     |     |     |     |     |     |
   * |-----------------------------------------------------------------------------------------+
   * |      |       |      |               |      |             |     |      |Ctrl-|     |CtSh-|
   * `-----------------------------------------------------------------------------------------'
   */
    [_FU] = LAYOUT_directional(
        KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_NO, TG(_QMK), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LCTL(BE_MINS), KC_NO, LCTL(LSFT(BE_MINS))),

  /* QMK Layer
   * ,-----------------------------------------------------------------------------------------.
   * | _AZ |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
   * |-----------------------------------------------------------------------------------------+
   * |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
   * |-----------------------------------------------------------------------------------------+
   * |         |     |     |     |     |     |     |     |     |     |     |      |            |
   * |-----------------------------------------------------------------------------------------+
   * |           |     |     |     |     |     |     |     |     |     |     |     |     |     |
   * |-----------------------------------------------------------------------------------------+
   * |      |       |      |               |      |    RGB_TOG   |     |      |     |     |     |
   * `-----------------------------------------------------------------------------------------'
   */
    [_QMK] = LAYOUT_directional(
        TG(_QMK), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_TOG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
};
