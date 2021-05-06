#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum jiran_layers {
  _QWERTY,
  _LOWER
};

#define KC_RBGI  RGUI_T(KC_RBRC)
#define KC_BSCT  RCTL_T(KC_BSLS)
#define KC_QTSH  RSFT_T(KC_QUOT)
#define KC_SLSF  RSFT_T(KC_LSCR)
#define KC_NLCT  RCTL_T(KC_LNUM)
#define KC_ETAL  RALT_T(KC_ENT)
#define LOWER  MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
    //            ┌─────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
                   KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
  // ┌────────────┼─────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┼───────────┐
     LCTL(KC_BSPC),KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,   KC_LBRC, KC_RBRC,
  // └────────────┼─────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┼───────────┘
                   KC_LSPO,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //              ├─────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
                   LALT_T
                   (KC_CAPS), KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_BSLS,
  //              └─────────┴────────┴────────┴────────┼────────┼────────┤                          ├────────┼────────┼────────┴────────┴────────┴────────┘
                                               KC_LGUI, KC_SPC,  KC_LCTL,                            KC_ENT,  KC_BSPC, MO(1)
                                  //          └────────┴────────┴────────┘                          └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
    //            ┌─────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
                   KC_GRV,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_F9,   KC_F10,  KC_F11,
  // ┌────────────┼─────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┼───────────┐
      SGUI(KC_SPC),_______,  KC_PSCR, KC_DEL,  RESET,   KC_PGUP, KC_PGDN,                            KC_LBRC, KC_LPRN, KC_LCBR, KC_PMNS, KC_PLUS, KC_F12,  RALT(KC_SPC),
  // └────────────┼─────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┼───────────┘
                   KC_RSPC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_END,                             KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_COLN, KC_DQUO,
  //              ├─────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
                   _______,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_HOME,                            KC_RBRC, KC_RPRN, KC_RCBR, KC_UNDS, KC_QUES, KC_PIPE,
  //              └─────────┴────────┴────────┴────────┼────────┼────────┤                          ├────────┼────────┼────────┴────────┴────────┴────────┘
                                               SGUI
                                               (KC_ENT), _______, _______,                           _______,  _______, _______
                                  //          └────────┴────────┴────────┘                          └────────┴────────┴────────┘
                   ),

};
