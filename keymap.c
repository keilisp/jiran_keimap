#include QMK_KEYBOARD_H

#define CUSTOM_SAFE_RANGE SAFE_RANGE


#include "lang_shift/include.h"
#include "arbitrary_keycode/include.h"

#include "custom_lang.h"

enum jiran_layers {
 L_EN = 0,
 L_EN_S,
 L_RU,
 L_RU_S,
 L_UA,
 L_UA_S,
 L_PUNCT,
 L_DIGS,
 L_NUKE_WAR
 /* L_AWSM */
};


enum LANG_CHANGE {
	CAPS,
	ALT_SHIFT,
	CTRL_SHIFT,
	WIN_SPACE
};

#define AWSM_T LM(L_AWSM, MOD_LGUI)
#define CTL_TAB LCTL_T(KC_TAB)
#define ALT_TAB LALT_T(KC_TAB)
#define NUKE_ENT LT(L_NUKE_WAR, KC_ENT)
#define DIGS_SPC LT(L_DIGS, KC_SPC)

#define ENRU TL_EN_RU
#define RUEN TL_RU_EN
#define UAEN TL_UA_EN

enum custom_keycodes {
  PLACEHOLDER = CUSTOM_SAFE_RANGE,
  ENRU_BSP,
  RUEN_BSP,
  UAEN_BSP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [L_EN] = LAYOUT(
                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,                                        KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,
           LA_CHNG,       KC_ESC,  EN_Q,    EN_W,    EN_E,    EN_R,      EN_T,                                         EN_Y,    EN_U,    EN_I,    EN_O,     EN_P,     EN_GRV,   AG_SLSH,
                          KC_LGUI, EN_A,    EN_S,    EN_D,    EN_F,      EN_G,                                         EN_H,    EN_J,    EN_K,    EN_L,     EN_QUOT,  EN_HASH,
                          ALT_TAB, EN_Z,    EN_X,    EN_C,    EN_V,      EN_B,                                         EN_N,    EN_M,    AG_SCLN, AG_MINS,  AG_DOT,   AG_COMM,
                                                              SFT_N,     DIGS_SPC, KC_LCTL,                 NUKE_ENT,  ENRU_BSP,MO(L_PUNCT)
  ),

  [L_EN_S] = LAYOUT(
                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,                                        KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,
           LA_CHNG,       KC_TILD, EN_S_Q,  EN_S_W,  EN_S_E,  EN_S_R,    EN_S_T,                                       EN_S_Y,  EN_S_U,  EN_S_I,  EN_S_O,   EN_S_P,   _______,  AG_QUES,
                          KC_LGUI, EN_S_A,  EN_S_S,  EN_S_D,  EN_S_F,    EN_S_G,                                       EN_S_H,  EN_S_J,  EN_S_K,  EN_S_L,   _______,  _______,
                          ALT_TAB, EN_S_Z,  EN_S_X,  EN_S_C,  EN_S_V,    EN_S_B,                                       EN_S_N,  EN_S_M,  _______,  _______, AG_EXCL,  EN_CIRC,
                                                              _______,   DIGS_SPC, KC_LCTL,                 NUKE_ENT,  ENRU_BSP,MO(L_PUNCT)
  ),

  [L_RU] = LAYOUT(
                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,                                        KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,
           LA_CHNG,       KC_ESC,  RU_J,    RU_TS,   RU_U,    RU_K,    RU_JE,                                          RU_N,    RU_G,    RU_SH,   RU_SC,    RU_Z,     RU_H,     AG_SLSH,
                          KC_LGUI, RU_F,    RU_Y,    RU_V,    RU_A,    RU_P,                                           RU_R,    RU_O,    RU_L,    RU_D,     RU_ZH,    RU_E,
                          ALT_TAB, RU_JA,   RU_CH,   RU_S,    RU_M,    RU_I,                                           RU_T,    RU_SF,   RU_B,    RU_JU,    AG_DOT,   AG_COMM,
                                                              SFT_N,   DIGS_SPC,   KC_LCTL,                 NUKE_ENT,  RUEN_BSP,MO(L_PUNCT)
  ),
  
  [L_RU_S] = LAYOUT(
                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,                                        KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,
           LA_CHNG,       KC_TILD, RU_S_J,  RU_S_TS, RU_S_U,  RU_S_K,  RU_S_JE,                                        RU_S_N,  RU_S_G,  RU_S_SH, RU_S_SC,  RU_S_Z,   RU_S_H,   AG_QUES,  
                          KC_LGUI, RU_S_F,  RU_S_Y,  RU_S_V,  RU_S_A,  RU_S_P,                                         RU_S_R,  RU_S_O,  RU_S_L,  RU_S_D,   RU_S_ZH,  RU_S_E,
                          ALT_TAB, RU_S_JA, RU_S_CH, RU_S_S,  RU_S_M,  RU_S_I,                                         RU_S_T,  RU_S_SF, RU_S_B,  RU_S_JU,  AG_EXCL,  EN_CIRC,
                                                              _______, DIGS_SPC,   KC_LCTL,                 NUKE_ENT,  RUEN_BSP,MO(L_PUNCT)
  ),

  [L_UA] = LAYOUT(
                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,                                        KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,
           LA_CHNG,       KC_ESC,  UA_J,    UA_TS,   UA_U,    UA_K,    UA_E,                                           UA_N,    UA_G,    UA_SH,   UA_SC,    UA_Z,     UA_H,     EN_SLSH,   
                          KC_LGUI, UA_F,    UA_I,    UA_V,    UA_A,    UA_P,                                           UA_R,    UA_O,    UA_L,    UA_D,     UA_ZH,    UA_JE,
                          ALT_TAB, UA_JA,   UA_CH,   UA_S,    UA_M,    UA_Y,                                           UA_T,    UA_SF,   UA_B,    UA_JU,    AG_DOT,   AG_COMM,
                                                              SFT_N,   DIGS_SPC,   KC_LCTL,                 NUKE_ENT,  UAEN_BSP,MO(L_PUNCT)
  ),

  [L_UA_S] = LAYOUT(
                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,                                        KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,
           LA_CHNG,       KC_TILD, UA_S_J,  UA_S_TS, UA_S_U,  UA_S_K,  UA_S_E,                                         UA_S_N,  UA_S_G,  UA_S_SH, UA_S_SC,  UA_S_Z,   UA_S_H,   EN_QUES,
                          KC_LGUI, UA_S_F,  UA_S_I,  UA_S_V,  UA_S_A,  UA_S_P,                                         UA_S_R,  UA_S_O,  UA_S_L,  UA_S_D,   UA_S_ZH,  UA_S_JE,
                          ALT_TAB, UA_S_JA, UA_S_CH, UA_S_S,  UA_S_M,  UA_S_Y,                                         UA_S_T,  UA_S_SF, UA_S_B,  UA_S_JU,  AG_EXCL,  EN_CIRC,
                                                              _______, DIGS_SPC,   KC_LCTL,                 NUKE_ENT,  UAEN_BSP,MO(L_PUNCT)
  ),

  [L_PUNCT] = LAYOUT(
                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
           LA_SYNC,       AG_EQL,  EN_DQUO, EN_LTEQ, EN_LCBR, EN_RCBR, EN_ARR2,                                        KC_HOME, KC_PGDN, KC_PGUP, KC_END,  AG_PLUS,AG_BSLS,     KC_DEL,
                          KC_LGUI, EN_CJLB, EN_LT,   AG_LPRN, AG_RPRN, EN_GT,                                          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, EN_DLR, EN_AT,
                          KC_LALT, EN_PIPE, EN_GTEQ, EN_LBRC, EN_RBRC, EN_ARR1,                                        AG_COLN, EN_AMPR, AG_ASTR, AG_UNDS, RU_NUME,AG_PERC,
                                                              KC_LSFT, DIGS_SPC,   KC_LCTL,                 RESET,     KC_BSPC, KC_NO
  ),

  [L_DIGS] = LAYOUT(
                          KC_NO,         KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,    KC_NO,
           LA_SYNC,       KC_ESC,        LSFT(KC_1),LSFT(KC_2),LSFT(KC_3),LSFT(KC_4),LSFT(KC_5),                       LSFT(KC_6),LSFT(KC_7),LSFT(KC_8),LSFT(KC_9),LSFT(KC_0),_______,     _______,
                          _______,       KC_1,      KC_2 ,     KC_3,      KC_4,      KC_5,                             KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      _______,
                          KC_F1,         KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,                            KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,
                                                                          KC_LSFT,   KC_NO, KC_LCTL,        RESET,     KC_BSPC,   MO(L_PUNCT)
  ),

  [L_NUKE_WAR] = LAYOUT(
                          KC_NO,   KC_NO,  KC_NO,    KC_NO,     KC_NO,   KC_NO,                              KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
           KC_MENU,       KC_ESC,  KC_SLCK,KC_CAPS,  KC_INSERT, KC_PAUSE,KC_PSCR,                            KC_PDOT,   KC_PSLS, KC_P7,   KC_P8,   KC_P9,  KC_PPLS,    KC_NLCK,
                          KC_RGUI, UA_GE,  RU_JE,    UA_JE,     UA_I,    UA_JI,                              KC_PCMM,   KC_PAST, KC_P4,   KC_P5,   KC_P6,  KC_PENT,
                          KC_RALT, UA_S_GE,RU_S_JE,  UA_S_JE,   UA_S_I,  UA_S_JI,                            KC_PMNS,   KC_P0,   KC_P1,   KC_P2,   KC_P3,  KC_PEQL,
                                                                          KC_RSFT, DIGS_SPC, KC_RCTL,       KC_NO,     KC_BSPC,   MO(L_PUNCT)
  ),

  /* [L_AWSM] = LAYOUT( */
  /*                         _______, KC_1,    KC_2,  KC_3,  KC_4,    KC_5,                                               KC_6,  KC_7,  KC_8,    KC_9,   KC_0,    _______, */
  /*          LA_CHNG,       _______, KC_Q,    KC_W,  KC_E,  KC_R,    KC_T,                                               KC_Y,  KC_U,  KC_I,    KC_O,   KC_P,    _______,  _______, */
  /*                         _______, KC_A,    KC_S,  KC_D,  KC_F,    KC_G,                                               KC_H,  KC_J,  KC_K,    KC_L,   _______, _______, */
  /*                         _______, KC_Z,    KC_X,  KC_C,  KC_V,    KC_B,                                               KC_N,  KC_M,  KC_COMM, KC_DOT, _______,  _______, */
  /*                                                         KC_LSHIFT, _______, _______,                       _______,  _______, _______ */
  /* ), */

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!lang_shift_process_record(keycode, record)) {
      return false;
    }

    if (!process_my_lang_keys(keycode, record)) {
        return false;
    }


  static uint16_t my_hash_timer;
  switch (keycode) {
    case ENRU_BSP:
      if(record->event.pressed) {
        my_hash_timer = timer_read();
        press_arbitrary_keycode(ENRU, true);
      } else {
        press_arbitrary_keycode(ENRU, false);
        if (timer_elapsed(my_hash_timer) < TAPPING_TERM) {
          register_code(KC_BSPC);
          unregister_code(KC_BSPC);
        }
      }
      return false;

    case RUEN_BSP:
      if(record->event.pressed) {
        my_hash_timer = timer_read();
        press_arbitrary_keycode(RUEN, true);
      } else {
        press_arbitrary_keycode(RUEN, false);
        if (timer_elapsed(my_hash_timer) < TAPPING_TERM) {
          register_code(KC_BSPC);
          unregister_code(KC_BSPC);
        }
      }
      return false; 

    case UAEN_BSP:
      if(record->event.pressed) {
        my_hash_timer = timer_read();
        press_arbitrary_keycode(UAEN, true);
      } else {
        press_arbitrary_keycode(UAEN, false);
        if (timer_elapsed(my_hash_timer) < TAPPING_TERM) {
          register_code(KC_BSPC);
          unregister_code(KC_BSPC);
        }
      }
      return false; 
  }

    return true;
}

void user_timer(void) { lang_shift_user_timer(); }

void matrix_scan_user(void) { user_timer(); }
