#include QMK_KEYBOARD_H

#include <stdio.h>
#include "keycode.h"  // added for code completion
#include "keymap_belgian.h"
#include "sendstring_belgian.h"

enum planck_layers { _AZ, _QW, _QWS, _FU, _QMK, _NUM, _WIN };

// Custom keycodes (macros,...)
enum custom_keycodes {
    SQLSEL = SAFE_RANGE,
    SQLIF,
    SCRNSHT,
    SW_QW,
    SW_AZ,
    CU_ACE,
    CU_TILD,
    CU_BCK,
    CU_FWD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Azerty
     * ,-----------------------------------------------------------------------------------------.
     * | ESC |  &  |  é  |  "  |  '  |  (  |  §  |  è  |  !  |  ç  |  à  |  )  |  -  |   Bkspc   |
     * |-----------------------------------------------------------------------------------------+
     * | Tab    |  A  |  Z  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  ^  |  $  |    \   |
     * |-----------------------------------------------------------------------------------------+
     * | Caps    |  Q  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  M  |  ù  |    Enter    |
     * |-----------------------------------------------------------------------------------------+
     * | Shift/<  |  W  |  X  |  C  |  V  |  B  |  N  |  ,  |  ;  |  :  |  =   | RSh |  Up | Del |
     * |-----------------------------------------------------------------------------------------+
     * | Ctrl |  Win  |  LAlt |     Space   |  Fn  |     Space    | RAlt | Cmd | Left| Down| Rght|
     * `-----------------------------------------------------------------------------------------'
     */
    [_AZ] = LAYOUT_directional(
        KC_ESC, BE_AMPR, BE_EACU, BE_DQUO, BE_QUOT, BE_LPRN, BE_SECT, BE_EGRV, BE_EXLM, BE_CCED, BE_AGRV, BE_RPRN, BE_MINS, KC_BSPC, 
        KC_BSPC, KC_TAB, BE_A, BE_Z, BE_E, BE_R, BE_T, BE_Y, BE_U, BE_I, BE_O, BE_P, BE_DCIR, BE_DLR, BE_MICR, 
        LT(_NUM, KC_TAB), BE_Q, BE_S, BE_D, BE_F, BE_G, BE_H, BE_J, BE_K, BE_L, BE_M, BE_UGRV, KC_ENT, 
        LSFT_T(BE_LABK), BE_W, BE_X, BE_C, BE_V, BE_B, BE_N, BE_COMM, BE_SCLN, BE_COLN, BE_EQL, KC_RSFT, KC_UP, KC_DEL, 
        KC_LCTL, LT(_WIN, KC_LGUI), KC_LALT, KC_SPC, MO(_FU), KC_SPC, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RIGHT),

    /*  Qwerty
     * ,-----------------------------------------------------------------------------------------.
     * | ESC |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bkspc   |
     * |-----------------------------------------------------------------------------------------+
     * | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |    \   |
     * |-----------------------------------------------------------------------------------------+
     * | Caps    |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
     * |-----------------------------------------------------------------------------------------+
     * | Shift     |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  | RSh |  Up | Del |
     * |-----------------------------------------------------------------------------------------+
     * | Ctrl |  Win  | LAlt |     Space   |  Fn  |  Space/Shift  | RAlt | Ctrl| Left| Down| Rght|
     * `-----------------------------------------------------------------------------------------'
     */
    [_QW] = LAYOUT_directional(
        KC_ESC, BE_1, BE_2, BE_3, BE_4, BE_5, BE_6, BE_7, BE_8, BE_9, BE_0, BE_MINS, BE_EQL, KC_BSPC, KC_BSPC, 
        KC_TAB, BE_Q, BE_W, BE_E, BE_R, BE_T, BE_Y, BE_U, BE_I, BE_O, BE_P, BE_LBRC, BE_RBRC, BE_BSLS, 
        LT(_NUM, KC_TAB), BE_A, BE_S, BE_D, BE_F, BE_G, BE_H, BE_J, BE_K, BE_L, BE_SCLN, BE_QUOT, KC_ENT, 
        MO(_QWS), BE_Z, BE_X, BE_C, BE_V, BE_B, BE_N, BE_M, BE_COMM, BE_DOT, BE_SLSH, MO(_QWS), KC_UP, KC_DEL, 
        KC_LCTL, LT(_WIN, KC_LGUI), KC_LALT, KC_SPC, MO(_FU), LSFT_T(KC_SPC), KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RIGHT),

    /* Qwerty Shifted
     * ,-----------------------------------------------------------------------------------------.
     * |     |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  )  |  _  |  +  |           |
     * |-----------------------------------------------------------------------------------------+
     * |        |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  {  |  }  |    |   |
     * |-----------------------------------------------------------------------------------------+
     * |         |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  :  |  "  |             |
     * |-----------------------------------------------------------------------------------------+
     * |           |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  <  |  >  |  ?  |     |     |     |
     * |-----------------------------------------------------------------------------------------+
     * |      |       |      |             |      |                |     |     |     |     |     |
     * `-----------------------------------------------------------------------------------------'
     */
    [_QWS] = LAYOUT_directional(
        _______, BE_EXLM, BE_AT, BE_HASH, BE_DLR, BE_PERC, BE_CIRC, BE_AMPR, BE_ASTR, BE_LPRN, BE_RPRN, BE_UNDS, BE_PLUS, _______, _______, 
        _______, S(BE_Q), S(BE_W), S(BE_E), S(BE_R), S(BE_T), S(BE_Y), S(BE_U), S(BE_I), S(BE_O), S(BE_P), BE_LCBR, BE_RCBR, BE_PIPE, 
        _______, S(BE_A), S(BE_S), S(BE_D), S(BE_F), S(BE_G), S(BE_H), S(BE_J), S(BE_K), S(BE_L), BE_COLN, BE_DQUO, _______, 
        _______, S(BE_Z), S(BE_X), S(BE_C), S(BE_V), S(BE_B), S(BE_N), S(BE_M), BE_LABK, BE_RABK, BE_QUES, _______, S(KC_UP), _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, S(KC_LEFT), S(KC_DOWN), S(KC_RIGHT)),

    /* Function Layer
     * ,-----------------------------------------------------------------------------------------.
     * |  ~  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |     |     |
     * |-----------------------------------------------------------------------------------------+
     * |        |     |     |  é  |     |     |     |     |SQLIF|     |     |     |     |        |
     * |-----------------------------------------------------------------------------------------+
     * |         |     |SQLSL|     |     |     |     |     |     |     |     |      |            |
     * |-----------------------------------------------------------------------------------------+
     * |   Shift   |     |     |     |     |     |     |     |     |     |Shift| BCK |Pg Up| FWD |
     * |-----------------------------------------------------------------------------------------+
     * | TRNS | _QMK  | TRNS |               |      |             | TRNS |TRNS |Home |Pg Do| End |
     * `-----------------------------------------------------------------------------------------'
     */
    [_FU] = LAYOUT_directional(
        CU_TILD, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, CU_ACE, KC_NO, KC_NO, KC_NO, KC_NO, SQLIF, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_NO, KC_NO, SQLSEL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, _______, 
        KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_RSFT, CU_BCK, KC_PGUP, CU_FWD, 
        _______, TG(_QMK), _______, KC_NO, KC_NO, KC_NO, _______, _______, KC_HOME, KC_PGDN, KC_END),

    /* QMK Layer
     * ,-----------------------------------------------------------------------------------------.
     * | TG  | _AZ | _QW |     |     |     |     |     |     |     |     |     |     |     |     |
     * |-----------------------------------------------------------------------------------------+
     * |        |     |     |     |RESET|     |     |     |     |     |     |     |     |        |
     * |-----------------------------------------------------------------------------------------+
     * |         |     |     |     |     |     |     |     |     |     |     |      |  RGB_TOG   |
     * |-----------------------------------------------------------------------------------------+
     * |           |     |     |     |     |     |     |     |     |     |     |     |     |     |
     * |-----------------------------------------------------------------------------------------+
     * |      |       |      |               |      |              |     |     | RGB-|     | RGB+|
     * `-----------------------------------------------------------------------------------------'
     */
    [_QMK] = LAYOUT_directional(
        TG(_QMK), SW_AZ, SW_QW, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_TOG, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_RMOD, KC_NO, RGB_MOD),

    /* num Layer
     * ,-----------------------------------------------------------------------------------------.
     * |     |     |     |     |     |     |     |     |   / |  *  |  -  |     |     |     |     |
     * |-----------------------------------------------------------------------------------------+
     * |        |     |     |     |     |     |     |  7  |  8  |  9  |  +  |     |     |        |
     * |-----------------------------------------------------------------------------------------+
     * |         |     |     |     |     |     |     |  4  |  5  |  6  |   + |      |            |
     * |-----------------------------------------------------------------------------------------+
     * |           |     |     |     |     |     |     |  1  |  2  |  3  | Ent |     |     |     |
     * |-----------------------------------------------------------------------------------------+
     * |      |       |      |               |      |       0      |  .  | Ent |     |     |     |
     * `-----------------------------------------------------------------------------------------'
     */
    [_NUM] = LAYOUT_directional(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, BE_SLSH, BE_ASTR, BE_MINS, KC_NO, KC_NO, KC_NO, _______, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_KP_7, KC_KP_8, KC_KP_9, BE_PLUS, KC_NO, KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_KP_4, KC_KP_5, KC_KP_6, BE_PLUS, KC_NO, _______, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_KP_1, KC_KP_2, KC_KP_3, KC_ENT, KC_NO, KC_NO, KC_NO, 
        KC_NO, KC_NO, _______, _______, KC_NO, KC_KP_0, KC_KP_DOT, KC_ENT, KC_NO, KC_NO, KC_NO),

    /* Win Layer
     * ,-----------------------------------------------------------------------------------------.
     * |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
     * |-----------------------------------------------------------------------------------------+
     * |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
     * |-----------------------------------------------------------------------------------------+
     * |         |     |SCRNSHT|     |     |     |     |     |     |     |     |      |  Play    |
     * |-----------------------------------------------------------------------------------------+
     * |           |     |     |     |     |     |     |     |     |     |     |     | Vol+|     |
     * |-----------------------------------------------------------------------------------------+
     * |      |       |      |               |      |              |     |     | Prev| Vol-| Next|
     * `-----------------------------------------------------------------------------------------'
     */
    [_WIN] = LAYOUT_directional(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_NO, KC_NO, SCRNSHT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPLY, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_VOLU, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_MPLY, KC_NO, KC_MPLY, KC_NO, KC_NO, KC_MPRV, KC_VOLD, KC_MNXT)};

// Custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SQLSEL:
            if (record->event.pressed) {
                if (eeconfig_read_default_layer() & (1UL << _QW)) {
                    SEND_STRING("SELECT TOP");
                    SEND_STRING(SS_TAP(X_ESC));
                    SEND_STRING(" 250 *\r\nFROM \r\nWHERE 1=1\r\nORDER BY 1 DESC");
                    SEND_STRING(SS_TAP(X_UP));
                    SEND_STRING(SS_TAP(X_UP));
                } else if (eeconfig_read_default_layer() & (1UL << _AZ)) {
                    SEND_STRING("SELECT TOP ");
                    tap_code(KC_2);
                    tap_code(KC_5);
                    tap_code(KC_0);
                    tap_code(KC_SPC);
                    tap_code16(LSFT(KC_8));
                    SEND_STRING(SS_TAP(X_ESC));
                    SEND_STRING("\r\nFRO");
                    tap_code16(LSFT(KC_M));
                    SEND_STRING(" \r\nZHERE &-&\r\nORDER BY & DESC ");
                    SEND_STRING(SS_TAP(X_UP));
                    SEND_STRING(SS_TAP(X_UP));
                }
            }
            break;
        case SQLIF:
            if (record->event.pressed) {
                // sql if block
                SEND_STRING("IF \r\nBEGIN\r\n\r\nEND\r\nELSE\r\nBEGIN\r\n\r\nEND");
                for (size_t i = 0; i < 7; i++) {
                    SEND_STRING(SS_TAP(X_UP));
                }
                for (size_t i = 0; i < 3; i++) {
                    SEND_STRING(SS_TAP(X_RIGHT));
                }
            }
            break;
        case SCRNSHT:
            if (record->event.pressed) {
                // emulate win + shift + s
                SEND_STRING(SS_LGUI(SS_LSFT("s")));
            }
            break;
        case SW_QW:
            if (record->event.pressed) {
                // Permanently switch to qwerty
                set_single_persistent_default_layer(_QW);
            }
            break;
        case SW_AZ:
            if (record->event.pressed) {
                // Permanently switch to azerty
                set_single_persistent_default_layer(_AZ);
            }
            break;
        case CU_ACE:
            if (record->event.pressed) {
                // Write é
                SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_3) SS_TAP(X_KP_3)));
            }
            break;
        case CU_TILD:
            if (record->event.pressed) {
                // Write ~
                SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_2) SS_TAP(X_KP_6)));
            }
            break;
        case CU_BCK:
            if (record->event.pressed) {
                if (eeconfig_read_default_layer() & (1UL << _QW)) {
                    tap_code16(LCTL(BE_MINS));
                } else if (eeconfig_read_default_layer() & (1UL << _AZ)) {
                    tap_code16(LCTL(KC_MINS));
                }
            }
            break;
        case CU_FWD:
            if (record->event.pressed) {
                if (eeconfig_read_default_layer() & (1UL << _QW)) {
                    tap_code16(LCTL(LSFT(BE_MINS)));
                } else if (eeconfig_read_default_layer() & (1UL << _AZ)) {
                    tap_code16(LCTL(LSFT(KC_MINS)));
                }
            }
            break;
    }
    return true;
};
