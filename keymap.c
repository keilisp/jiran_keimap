#include QMK_KEYBOARD_H

#define CUSTOM_SAFE_RANGE SAFE_RANGE
#include "lang_shift/include.h"

enum jiran_layers {
 L_EN = 0,
 L_EN_S,
 L_RU,
 L_RU_S,
 L_OTHER,
 L_TEST,
};


enum LANG_CHANGE {
	CAPS,
	ALT_SHIFT,
	CTRL_SHIFT,
	WIN_SPACE
};


enum custom_keycodes {
  PLACEHOLDER = CUSTOM_SAFE_RANGE,

  MO_EN,
  MO_RU,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [L_EN] = LAYOUT(
                 KC_ESC,  EN_QUOT, AG_DQUO, EN_HASH, EN_DLR,    AG_PERC,                                 AG_COLN, EN_AMPR, AG_ASTR, AG_MINS,  AG_PLUS,  AG_BSLS,
      TO_RU,     KC_LALT, EN_Q,    EN_W,    EN_E,    EN_R,      EN_T,                                    EN_Y,    EN_U,    EN_I,    EN_O,     EN_P,     AG_EXCL,  AG_SLSH,
                 KC_LGUI, EN_A,    EN_S,    EN_D,    EN_F,      EN_G,                                    EN_H,    EN_J,    EN_K,    EN_L,     AG_SCLN,  RU_NUME,
                 LA_CHNG, EN_Z,    EN_X,    EN_C,    EN_V,      EN_B,                                    EN_N,    EN_M,    AG_EQL,  AG_UNDS,  AG_DOT,   AG_COMM,
                                                     SFT_N, KC_SPC,  LCTL_T(KC_TAB),        KC_ENT,  KC_BSPC, MO(4)
  ),
  [L_EN_S] = LAYOUT(
                 EN_TILD, EN_1,      EN_2 ,     EN_3,      EN_4,      EN_5,                             EN_6,     EN_7,    EN_8,    EN_9,     EN_0,     EN_PIPE,
      TO_RU,     KC_LALT, EN_S_Q,    EN_S_W,    EN_S_E,    EN_S_R,    EN_S_T,                           EN_S_Y,   EN_S_U,  EN_S_I,  EN_S_O,   EN_S_P,   EN_GRV,   AG_QUES,
                 KC_LGUI, EN_S_A,    EN_S_S,    EN_S_D,    EN_S_F,    EN_S_G,                           EN_S_H,   EN_S_J,  EN_S_K,  EN_S_L,   EN_GRV,   EN_AT,
                 LA_CHNG, EN_S_Z,    EN_S_X,    EN_S_C,    EN_S_V,    EN_S_B,                           EN_S_N,   EN_S_M,  EN_LT,   EN_GT,    KC_SLSH,  EN_CIRC,
                                                     SFT_N, KC_SPC,  LCTL_T(KC_TAB),        KC_ENT, KC_BSPC, MO(4)
  ),
  [L_RU] = LAYOUT(
                KC_ESC,   EN_QUOT, AG_DQUO, RU_NUME, EN_DLR,  AG_PERC,                                   AG_COLN, EN_AMPR, AG_ASTR, AG_MINS,  AG_PLUS,  AG_BSLS,
      TO_EN,    KC_LALT,  RU_J,    RU_TS,   RU_U,    RU_K,    RU_JE,                                     RU_N,    RU_G,    RU_SH,   RU_SC,    RU_Z,     RU_H,     AG_SLSH,
                KC_LGUI,  RU_F,    RU_Y,    RU_V,    RU_A,    RU_P,                                      RU_R,    RU_O,    RU_L,    RU_D,     RU_ZH,    RU_E,
                LA_CHNG,  RU_JA,   RU_CH,   RU_S,    RU_M,    RU_I,                                      RU_T,    RU_SF,   RU_B,    RU_JU,    AG_DOT,   AG_COMM,
                                                     SFT_N, KC_SPC,  LCTL_T(KC_TAB),        KC_ENT,   KC_BSPC, MO(4)
  ),
  [L_RU_S] = LAYOUT(
                EN_TILD,  RU_1,      RU_2 ,     RU_3,      RU_4,      RU_5,                              RU_6,    RU_7,    RU_8,    RU_9,     RU_0,     EN_PIPE,
      TO_EN,    KC_LALT,  RU_S_J,    RU_S_TS,   RU_S_U,    RU_S_K,    RU_S_JE,                           RU_S_N,  RU_S_G,  RU_S_SH, RU_S_SC,  RU_S_Z,   RU_S_H,   AG_QUES,
                KC_LGUI,  RU_S_F,    RU_S_Y,    RU_S_V,    RU_S_A,    RU_S_P,                            RU_S_R,  RU_S_O,  RU_S_L,  RU_S_D,   RU_S_ZH,  RU_S_E,
                LA_CHNG,  RU_S_JA,   RU_S_CH,   RU_S_S,    RU_S_M,    RU_S_I,                            RU_S_T,  RU_S_SF, RU_S_B,  RU_S_JU,  EN_AT,    EN_CIRC,
                                                     SFT_N, KC_SPC,  LCTL_T(KC_TAB),        KC_ENT,  KC_BSPC, MO(4)
  ),

  [L_OTHER] = LAYOUT(
                   KC_GRV,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_F9,   KC_F10,  KC_F11,
      SGUI(KC_SPC),_______,  KC_PSCR, KC_DEL,  RESET,   KC_PGUP, KC_PGDN,                            KC_LBRC, KC_LPRN, KC_LCBR, KC_PMNS, KC_PLUS, KC_F12,  RALT(KC_SPC),
                   KC_RSPC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_END,                             KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_COLN, KC_DQUO,
                   _______,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_HOME,                            KC_RBRC, KC_RPRN, KC_RCBR, KC_UNDS, KC_SLASH, KC_PIPE,
                                               SGUI
                                               (KC_ENT), _______, _______,                           _______,  _______, _______
  ),
  [L_TEST] = LAYOUT(
                   KC_GRV,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_F9,   KC_F10,  KC_F11,
      SGUI(KC_SPC),_______,  EN_Q,    RU_TS,  RESET,   KC_PGUP, KC_PGDN,                            KC_LBRC, KC_LPRN, KC_LCBR, KC_PMNS, KC_PLUS, KC_F12,  RALT(KC_SPC),
                   KC_RSPC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_END,                             KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_COLN, KC_DQUO,
                   _______,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_HOME,                            KC_RBRC, KC_RPRN, KC_RCBR, KC_UNDS, KC_SLASH, KC_KP_SLASH,
                                          SGUI (KC_ENT), _______, _______,                           _______,  _______, _______
  ),

};


//-----------------------------------------------------------------------------
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!lang_shift_process_record(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case TO_RU:
            if (record->event.pressed) {
                layer_on(L_EN);
            } else {
                layer_off(L_EN);
            }
            return false;
            break;

            /* #HACK? */
        case TO_EN:
            if (record->event.pressed) {
                layer_clear();
            } else {
                layer_on(L_RU);
            }
            return false;
            break;
    }
    return true;
}

void user_timer(void) { lang_shift_user_timer(); }

void matrix_scan_user(void) { user_timer(); }
