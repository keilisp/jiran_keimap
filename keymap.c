#include QMK_KEYBOARD_H

#define CUSTOM_SAFE_RANGE SAFE_RANGE
#include "lang_shift/include.h"

#include "custom_lang.h"

#define UNICODE_SELECTED_MODES UC_LNX

enum jiran_layers {
 L_EN = 0,
 L_EN_S,
 L_RU,
 L_RU_S,
 L_OTHER,
 L_NUKE_WAR,
 L_AWSM
};


enum LANG_CHANGE {
	CAPS,
	ALT_SHIFT,
	CTRL_SHIFT,
	WIN_SPACE
};

#define AWSM_T LM(L_AWSM, MOD_LGUI)

enum custom_keycodes {
  PLACEHOLDER = CUSTOM_SAFE_RANGE,

  MO_EN,
  MO_RU,

  UA_I,
  UA_S_I,
  UA_JI,
  UA_S_JI,
  UA_JE,
  UA_S_JE,
  UA_GE,
  UA_S_GE,

};

/* TODO:
 * Fix UA (mb modify lang_shift src)
 * Setup arbitrary keycodes (ALT_T(LA_CHNG))
 * Set Lang_Set change on nuke layer
 * Add layers for: Emacs,  mb for unicode*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [L_EN] = LAYOUT(
                          KC_ESC,  EN_QUOT, AG_DQUO, EN_HASH, EN_DLR,    AG_PERC,                                      AG_COLN, EN_AMPR, AG_ASTR, AG_MINS,  AG_PLUS,  AG_QUES,
   LT(5, KC_ENTER),       KC_LALT, EN_Q,    EN_W,    EN_E,    EN_R,      EN_T,                                         EN_Y,    EN_U,    EN_I,    EN_O,     EN_P,     EN_GRV,   AG_SLSH,
                          AWSM_T,  EN_A,    EN_S,    EN_D,    EN_F,      EN_G,                                         EN_H,    EN_J,    EN_K,    EN_L,     AG_SCLN,  EN_AT,
                          LA_CHNG, EN_Z,    EN_X,    EN_C,    EN_V,      EN_B,                                         EN_N,    EN_M,    AG_EQL,  AG_UNDS,  AG_DOT,   AG_COMM,
                                                              SFT_N,     KC_SPC, LCTL_T(KC_TAB),       MO_RU,  KC_BSPC, MO(4)
  ),

  [L_EN_S] = LAYOUT(
                          EN_TILD, EN_1,    EN_2 ,   EN_3,    EN_4,      EN_5,                                         EN_6,    EN_7,    EN_8,    EN_9,     EN_0,     EN_PIPE,
   LT(5, KC_ENTER),       KC_LALT, EN_S_Q,  EN_S_W,  EN_S_E,  EN_S_R,    EN_S_T,                                       EN_S_Y,  EN_S_U,  EN_S_I,  EN_S_O,   EN_S_P,   _______,  AG_BSLS,
                          KC_LGUI, EN_S_A,  EN_S_S,  EN_S_D,  EN_S_F,    EN_S_G,                                       EN_S_H,  EN_S_J,  EN_S_K,  EN_S_L,   _______,  _______,
                          LA_CHNG, EN_S_Z,  EN_S_X,  EN_S_C,  EN_S_V,    EN_S_B,                                       EN_S_N,  EN_S_M,  _______,  _______, AG_EXCL,  EN_CIRC,
                                                              _______,   KC_SPC, LCTL_T(KC_TAB),       MO_RU,  KC_BSPC, MO(4)
  ),

  [L_RU] = LAYOUT(
                          KC_ESC,  EN_QUOT, AG_DQUO, RU_NUME, EN_DLR,  AG_PERC,                                        AG_COLN, EN_AMPR, AG_ASTR, AG_MINS,  AG_PLUS,  AG_QUES,
   LT(5, KC_ENTER),       KC_LALT, RU_J,    RU_TS,   RU_U,    RU_K,    RU_JE,                                          RU_N,    RU_G,    RU_SH,   RU_SC,    RU_Z,     RU_H,     AG_SLSH,
                          AWSM_T,  RU_F,    RU_Y,    RU_V,    RU_A,    RU_P,                                           RU_R,    RU_O,    RU_L,    RU_D,     RU_ZH,    RU_E,
                          LA_CHNG, RU_JA,   RU_CH,   RU_S,    RU_M,    RU_I,                                           RU_T,    RU_SF,   RU_B,    RU_JU,    AG_DOT,   AG_COMM,
                                                              SFT_N,   KC_SPC,   LCTL_T(KC_TAB),       MO_EN,  KC_BSPC, MO(4)
  ),

  [L_RU_S] = LAYOUT(
                          EN_TILD, RU_1,    RU_2 ,   RU_3,    RU_4,    RU_5,                                           RU_6,    RU_7,    RU_8,    RU_9,     RU_0,     EN_PIPE,
   LT(5, KC_ENTER),       KC_LALT, RU_S_J,  RU_S_TS, RU_S_U,  RU_S_K,  RU_S_JE,                                        RU_S_N,  RU_S_G,  RU_S_SH, RU_S_SC,  RU_S_Z,   RU_S_H,   AG_BSLS,
                          KC_LGUI, RU_S_F,  RU_S_Y,  RU_S_V,  RU_S_A,  RU_S_P,                                         RU_S_R,  RU_S_O,  RU_S_L,  RU_S_D,   RU_S_ZH,  RU_S_E,
                          LA_CHNG, RU_S_JA, RU_S_CH, RU_S_S,  RU_S_M,  RU_S_I,                                         RU_S_T,  RU_S_SF, RU_S_B,  RU_S_JU,  AG_EXCL,  EN_CIRC,
                                                              _______, KC_SPC,   LCTL_T(KC_TAB),       MO_EN,  KC_BSPC, MO(4)
  ),

  [L_OTHER] = LAYOUT(
                 KC_F1,         KC_F2,     KC_F3,    KC_F4,     KC_F5,   KC_F6,                               KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12,
      KC_ENTER,  LCTL(KC_ENT),  EN_MACR,   EN_LTEQ,  EN_LCBR,   EN_RCBR, EN_ARR2,                             KC_HOME, KC_PGDN, KC_PGUP, KC_END,  UA_JI,  UA_S_JI,  KC_DEL,
                 SGUI(KC_SPC),  EN_FISH,   EN_LT,    AG_LPRN,   AG_RPRN, EN_GT,                               KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, UA_I,   UA_S_I,
                 LA_SYNC,       EN_LAMB,   EN_GTEQ,  EN_LBRC,   EN_RBRC, EN_ARR1,                 /* FIXME */ UA_S_JE, UA_JE,   UA_GE,   UA_S_GE, RU_JO,  RU_S_JO,
                                                                KC_LSFT, KC_SPC, LCTL_T(KC_TAB),     RESET,  KC_BSPC, KC_NO
  ),

  [L_NUKE_WAR] = LAYOUT(
                KC_ESC,         KC_SLCK,   KC_CAPS,  KC_INSERT, KC_PAUSE,KC_PSCR,                             KC_NO,   KC_PSLS, KC_P7,   KC_P8,   KC_P9,  KC_PMNS,
        KC_NO,  LCTL(KC_ENT),   KC_NO,     KC_NO,    KC_NO,     KC_NO,   KC_NO,                               KC_NO,   KC_PAST, KC_P4,   KC_P5,   KC_P6,  KC_PPLS,  KC_NLCK,
                KC_LSFT,        KC_NO,     KC_NO,    KC_NO,     KC_NO,   KC_NO,                               KC_NO,   KC_NO,   KC_P1,   KC_P2,   KC_P3,  KC_PENT,
                KC_LCTL,        KC_LGUI,   KC_LALT,  KC_RALT,   KC_RGUI, KC_MENU,                             KC_NO,   KC_NO,   KC_P0,   KC_PDOT, KC_PCMM,KC_PEQL,
                                                                KC_RSFT, KC_SPC, KC_RCTL,            KC_ENT,  KC_BSPC, MO(4)
  ),

  [L_AWSM] = LAYOUT(
                      _______, KC_1,    KC_2,  KC_3,  KC_4,    KC_5,                                       KC_6,  KC_7,  KC_8,  KC_9,   KC_0,    _______,
   LT(5, KC_ENTER),   _______, KC_Q,    KC_W,  KC_E,  KC_R,    KC_T,                                       KC_Y,  KC_U,  KC_I,  KC_O,   KC_P,    _______,  _______,
                      _______, KC_A,    KC_S,  KC_D,  KC_F,    KC_G,                                       KC_H,  KC_J,  KC_K,  KC_L,   _______, _______,
                      _______, KC_Z,    KC_X,  KC_C,  KC_V,    KC_B,                                       KC_N,  KC_M,  _______,  _______, _______,  _______,
                                                              KC_LSHIFT,   _______, _______,       _______,  _______, _______
  ),

};

//-----------------------------------------------------------------------------
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!lang_shift_process_record(keycode, record)) {
        return false;
    }

    if (!process_my_lang_keys(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case MO_RU:
            if (record->event.pressed) {
                layer_on(L_RU);
            } else {
                layer_off(L_RU);
            }
            return false;
            break;

            /* #HACK? */
        case MO_EN:
            if (record->event.pressed) {
                layer_clear();
            } else {
                layer_on(L_RU);
            }
            return false;
            break;

            // UKRAINIAN #FIXME
        case UA_I:
            if (record->event.pressed) {
                send_unicode_string("і");
            }
            return false;
            break;
        case UA_S_I:
            if (record->event.pressed) {
                send_unicode_string("І");
            }
            return false;
            break;
        case UA_JI:
            if (record->event.pressed) {
                send_unicode_string("ї");
            }
            return false;
            break;
        case UA_S_JI:
            if (record->event.pressed) {
                send_unicode_string("Ї");
            }
            return false;
            break;
        case UA_JE:
            if (record->event.pressed) {
                send_unicode_string("є");
            }
            return false;
            break;
        case UA_S_JE:
            if (record->event.pressed) {
                send_unicode_string("Є");
            }
            return false;
            break;
        case UA_GE:
            if (record->event.pressed) {
                send_unicode_string("ґ");
            }
            return false;
            break;
        case UA_S_GE:
            if (record->event.pressed) {
                send_unicode_string("Ґ");
            }
            return false;
            break;
    }
    return true;
}

void user_timer(void) { lang_shift_user_timer(); }

void matrix_scan_user(void) { user_timer(); }
