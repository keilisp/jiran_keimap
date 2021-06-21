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
 L_UA,
 L_UA_S,
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
#define CTL_TAB LCTL_T(KC_TAB)
#define NUKE_ENT LT(L_NUKE_WAR, KC_ENT)

enum custom_keycodes {
  PLACEHOLDER = CUSTOM_SAFE_RANGE,
  KC_LMBD,
  KC_RQUES,
  KC_PI,
  KC_PSI,
  KC_OMEG,
  KC_TBFL,
  KC_DSPR,
  KC_IDK,
  KC_TROL,
  KC_BRUH,
  KC_CLWN,
  KC_KISS,
};

/* TODO:
 * Fix UA (mb modify lang_shift src)
 * Setup arbitrary keycodes (ALT_T(LA_CHNG))
 * Set Lang_Set change on nuke layer
 * Add layers for: Emacs,  mb for unicode*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [L_EN] = LAYOUT(
                          KC_ESC,  EN_QUOT, AG_DQUO, EN_HASH, EN_DLR,    AG_PERC,                                      AG_COLN, EN_AMPR, AG_ASTR, AG_MINS,  AG_PLUS,  AG_QUES,
           LA_CHNG,       TL_EN_RU,EN_Q,    EN_W,    EN_E,    EN_R,      EN_T,                                         EN_Y,    EN_U,    EN_I,    EN_O,     EN_P,     EN_GRV,   AG_SLSH,
                          AWSM_T,  EN_A,    EN_S,    EN_D,    EN_F,      EN_G,                                         EN_H,    EN_J,    EN_K,    EN_L,     AG_SCLN,  EN_AT,
                          KC_LALT, EN_Z,    EN_X,    EN_C,    EN_V,      EN_B,                                         EN_N,    EN_M,    AG_EQL,  AG_UNDS,  AG_DOT,   AG_COMM,
                                                              SFT_N,     KC_SPC, CTL_TAB,                   NUKE_ENT,  KC_BSPC, MO(L_OTHER)
  ),

  [L_EN_S] = LAYOUT(
                          EN_TILD, EN_1,    EN_2 ,   EN_3,    EN_4,      EN_5,                                         EN_6,    EN_7,    EN_8,    EN_9,     EN_0,     EN_PIPE,
           LA_CHNG,       TL_EN_RU,EN_S_Q,  EN_S_W,  EN_S_E,  EN_S_R,    EN_S_T,                                       EN_S_Y,  EN_S_U,  EN_S_I,  EN_S_O,   EN_S_P,   _______,  AG_BSLS,
                          KC_LGUI, EN_S_A,  EN_S_S,  EN_S_D,  EN_S_F,    EN_S_G,                                       EN_S_H,  EN_S_J,  EN_S_K,  EN_S_L,   _______,  _______,
                          KC_LALT, EN_S_Z,  EN_S_X,  EN_S_C,  EN_S_V,    EN_S_B,                                       EN_S_N,  EN_S_M,  _______,  _______, AG_EXCL,  EN_CIRC,
                                                              _______,   KC_SPC, CTL_TAB,                   NUKE_ENT,  KC_BSPC, MO(L_OTHER)
  ),

  [L_RU] = LAYOUT(
                          KC_ESC,  EN_QUOT, AG_DQUO, RU_NUME, EN_DLR,  AG_PERC,                                        AG_COLN, EN_AMPR, AG_ASTR, AG_MINS,  AG_PLUS,  AG_QUES,
           LA_CHNG,       TL_RU_EN,RU_J,    RU_TS,   RU_U,    RU_K,    RU_JE,                                          RU_N,    RU_G,    RU_SH,   RU_SC,    RU_Z,     RU_H,     AG_SLSH,
                          AWSM_T,  RU_F,    RU_Y,    RU_V,    RU_A,    RU_P,                                           RU_R,    RU_O,    RU_L,    RU_D,     RU_ZH,    RU_E,
                          KC_LALT, RU_JA,   RU_CH,   RU_S,    RU_M,    RU_I,                                           RU_T,    RU_SF,   RU_B,    RU_JU,    AG_DOT,   AG_COMM,
                                                              SFT_N,   KC_SPC,   CTL_TAB,                   NUKE_ENT,  KC_BSPC, MO(L_OTHER)
  ),

  [L_RU_S] = LAYOUT(
                          EN_TILD, RU_1,    RU_2 ,   RU_3,    RU_4,    RU_5,                                           RU_6,    RU_7,    RU_8,    RU_9,     RU_0,     EN_PIPE,
           LA_CHNG,       TL_RU_EN,RU_S_J,  RU_S_TS, RU_S_U,  RU_S_K,  RU_S_JE,                                        RU_S_N,  RU_S_G,  RU_S_SH, RU_S_SC,  RU_S_Z,   RU_S_H,   AG_BSLS,
                          KC_LGUI, RU_S_F,  RU_S_Y,  RU_S_V,  RU_S_A,  RU_S_P,                                         RU_S_R,  RU_S_O,  RU_S_L,  RU_S_D,   RU_S_ZH,  RU_S_E,
                          KC_ENT,  RU_S_JA, RU_S_CH, RU_S_S,  RU_S_M,  RU_S_I,                                         RU_S_T,  RU_S_SF, RU_S_B,  RU_S_JU,  AG_EXCL,  EN_CIRC,
                                                              _______, KC_SPC,   CTL_TAB,                   NUKE_ENT,  KC_BSPC, MO(L_OTHER)
  ),

  [L_UA] = LAYOUT(
                          KC_ESC,  EN_QUOT, AG_DQUO, UA_NUME, EN_DLR,  AG_PERC,                                        AG_COLN, EN_AMPR, AG_ASTR, AG_MINS,  AG_PLUS,  AG_QUES,
           LA_CHNG,       TL_UA_EN,UA_J,    UA_TS,   UA_U,    UA_K,    UA_E,                                           UA_N,    UA_G,    UA_SH,   UA_SC,    UA_Z,     UA_H,     EN_SLSH,
                          AWSM_T,  UA_F,    UA_I,    UA_V,    UA_A,    UA_P,                                           UA_R,    UA_O,    UA_L,    UA_D,     UA_ZH,    UA_JE,
                          KC_LALT, UA_JA,   UA_CH,   UA_S,    UA_M,    UA_Y,                                           UA_T,    UA_SF,   UA_B,    UA_JU,    AG_DOT,   AG_COMM,
                                                              SFT_N,   KC_SPC,   CTL_TAB,                   NUKE_ENT,  KC_BSPC, MO(L_OTHER)
  ),

  [L_UA_S] = LAYOUT(
                          EN_TILD, UA_1,    UA_2 ,   UA_3,    UA_4,    UA_5,                                           UA_6,    UA_7,    UA_8,    UA_9,     UA_0,     EN_PIPE,
           LA_CHNG,       TL_UA_EN,UA_S_J,  UA_S_TS, UA_S_U,  UA_S_K,  UA_S_E,                                         UA_S_N,  UA_S_G,  UA_S_SH, UA_S_SC,  UA_S_Z,   UA_S_H,   EN_BSLS,
                          KC_LGUI, UA_S_F,  UA_S_I,  UA_S_V,  UA_S_A,  UA_S_P,                                         UA_S_R,  UA_S_O,  UA_S_L,  UA_S_D,   UA_S_ZH,  UA_S_JE,
                          KC_ENT,  UA_S_JA, UA_S_CH, UA_S_S,  UA_S_M,  UA_S_Y,                                         UA_S_T,  UA_S_SF, UA_S_B,  UA_S_JU,  AG_EXCL,  EN_CIRC,
                                                              _______, KC_SPC,   CTL_TAB,                   NUKE_ENT,  KC_BSPC, MO(L_OTHER)
  ),

  [L_OTHER] = LAYOUT(
                 KC_F1,         KC_F2,     KC_F3,    KC_F4,     KC_F5,   KC_F6,                                        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12,
      LA_SYNC,   LCTL(KC_ENT),  EN_CJSLB,  EN_LTEQ,  EN_LCBR,   EN_RCBR, EN_ARR2,                                      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  UA_JI,  UA_S_JI,  KC_DEL,
                 KC_LGUI,       EN_CJLB,   EN_LT,    AG_LPRN,   AG_RPRN, EN_GT,                                        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, UA_JE,  UA_S_JE,
                 SGUI(KC_ENT),  EN_CLLB,   EN_GTEQ,  EN_LBRC,   EN_RBRC, EN_ARR1,                                      UA_S_I,  UA_I,    UA_GE,   UA_S_GE,   RU_JO,  RU_S_JO,
                                                                KC_LSFT, KC_SPC, CTL_TAB,                     RESET,  KC_BSPC, KC_NO
  ),

  [L_NUKE_WAR] = LAYOUT(
                KC_ESC,         KC_SLCK,   KC_CAPS,  KC_INSERT, KC_PAUSE,KC_PSCR,                                      KC_NO,   KC_PSLS, KC_P7,   KC_P8,   KC_P9,  KC_PMNS,
      KC_MENU,  KC_LGUI,        KC_LMBD,   KC_RQUES, KC_PI,     KC_PSI,  KC_OMEG,                                      KC_NO,   KC_PAST, KC_P4,   KC_P5,   KC_P6,  KC_PPLS,  KC_NLCK,
                KC_LSFT,        KC_TBFL,   KC_DSPR,  KC_IDK,    KC_TROL, KC_BRUH,                                      KC_NO,   KC_NO,   KC_P1,   KC_P2,   KC_P3,  KC_PENT,
                KC_LCTL,        KC_LALT,   KC_RALT,  KC_RGUI,   KC_CLWN, KC_KISS,                                      KC_NO,   KC_NO,   KC_P0,   KC_PDOT, KC_PCMM,KC_PEQL,
                                                                KC_RSFT, KC_SPC, KC_RCTL,                     KC_NO,   KC_BSPC, MO(L_OTHER)
  ),

  [L_AWSM] = LAYOUT(
                      _______, KC_1,    KC_2,  KC_3,  KC_4,    KC_5,                                       KC_6,  KC_7,  KC_8,    KC_9,   KC_0,    _______,
           LA_CHNG,   _______, KC_Q,    KC_W,  KC_E,  KC_R,    KC_T,                                       KC_Y,  KC_U,  KC_I,    KC_O,   KC_P,    _______,  _______,
                      _______, KC_A,    KC_S,  KC_D,  KC_F,    KC_G,                                       KC_H,  KC_J,  KC_K,    KC_L,   _______, _______,
                      _______, KC_Z,    KC_X,  KC_C,  KC_V,    KC_B,                                       KC_N,  KC_M,  KC_COMM, KC_DOT, _______,  _______,
                                                               KC_LSHIFT, _______, _______,      _______,  _______, _______
  ),

};

// TODO [[https://github.com/klavarog/arbitrary_keycode/][arbitrary_keycode]]

/* #include QMK_KEYBOARD_H */
/* enum custom_keycodes { */
/*   MY_HASH = SAFE_RANGE */
/* }; */
/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { */
/*   [0] = LAYOUT( /\* Base *\/ */
/*     MY_HASH \ */
/*   ), */
/* }; */
/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*   static uint16_t my_hash_timer; */
/*   switch (keycode) { */
/*     case MY_HASH: */
/*       if(record->event.pressed) { */
/*         my_hash_timer = timer_read(); */
/*         register_code(KC_LCTL); // Change the key to be held here */
/*       } else { */
/*         unregister_code(KC_LCTL); // Change the key that was held here, too! */
/*         if (timer_elapsed(my_hash_timer) < TAPPING_TERM) { */
/*           SEND_STRING("#"); // Change the character(s) to be sent on tap here */
/*         } */
/*       } */
/*       return false; // We handled this keypress */
/*   } */
/*   return true; // We didn't handle other keypresses */
/* } */

//-----------------------------------------------------------------------------
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!lang_shift_process_record(keycode, record)) {
    return false;
  }

  if (!process_my_lang_keys(keycode, record)) {
    return false;
  }

  switch (keycode) {
  case KC_LMBD:
    if (record->event.pressed) {
      send_unicode_string("𝜆");
    }
    return true;
  case KC_RQUES:
    if (record->event.pressed) {
      send_unicode_string("¿");
    }
    return true;
  case KC_PI:
    if (record->event.pressed) {
      send_unicode_string("𝜋");
    }
    return true;
  case KC_PSI:
    if (record->event.pressed) {
      send_unicode_string("𝝍");
    }
    return true;
  case KC_OMEG:
    if (record->event.pressed) {
      send_unicode_string("ꭥ");
    }
    return true;
  case KC_TBFL:
    if (record->event.pressed) {
      send_unicode_string("(ノಠ益ಠ)ノ彡┻━┻");
    }
    return true;
  case KC_DSPR:
    if (record->event.pressed) {
      send_unicode_string("ಠ_ಠ");
    }
    return true;
  case KC_IDK:
    if (record->event.pressed) {
      send_unicode_string("¯\\_(ツ)_/¯");
    }
    return true;
  case KC_TROL:
    if (record->event.pressed) {
      send_unicode_string("( ͡° ͜ʖ ͡°)");
    }
    return true;
  case KC_BRUH:
    if (record->event.pressed) {
      send_unicode_string("(T_T)");
    }
    return true;
  case KC_CLWN:
    if (record->event.pressed) {
      send_unicode_string("🤡");
    }
    return true;
  case KC_KISS:
    if (record->event.pressed) {
      send_unicode_string("😘");
    }
    return true;
  }
  return true;
}

void user_timer(void) { lang_shift_user_timer(); }

void matrix_scan_user(void) { user_timer(); }
