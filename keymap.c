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
#define CTL_LEFT LCTL(KC_LEFT)
#define CTL_RGHT LCTL(KC_RIGHT)
#define CTL_UP LCTL(KC_UP)
#define CTL_DOWN LCTL(KC_DOWN)
#define NUKE_ENT LT(L_NUKE_WAR, KC_ENT)

#define ENRU TL_EN_RU
#define RUEN TL_RU_EN
#define UAEN TL_UA_EN

enum custom_keycodes {
  PLACEHOLDER = CUSTOM_SAFE_RANGE,
  ENRU_BSP,
  RUEN_BSP,
  UAEN_BSP,
};

/* Tap Dance */
enum {
 TD_RY_UI = 0,
 TD_RE_UJE,
 TD_RH_UJI,
};

void dance_ry_ui_f (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code(KC_S); 
  } else {
    lang_activate(2); 
    register_code(KC_S); 
  }
}
void dance_ry_ui_r (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code(KC_S);
  } else {
    unregister_code(KC_S); 
    lang_activate(1);
  }
}


void dance_re_uje_f (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code(KC_QUOT); 
  } else {
    lang_activate(2); 
    register_code(KC_QUOT); 
  }
}
void dance_re_uje_r (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code(KC_QUOT);
  } else {
    unregister_code(KC_QUOT); 
    lang_activate(1);
  }
}


void dance_rh_uji_f (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code(KC_LBRC); 
  } else {
    lang_activate(2); 
    register_code(KC_RBRC); 
  }
}
void dance_rh_uji_r (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code(KC_LBRC);
  } else {
    unregister_code(KC_RBRC); 
    lang_activate(1);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_RY_UI] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_ry_ui_f, dance_ry_ui_r),
  [TD_RE_UJE] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_re_uje_f, dance_re_uje_r),
  [TD_RH_UJI] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_rh_uji_f, dance_rh_uji_r),
};

#define RY_UI TD(TD_RY_UI)
#define RE_UJE TD(TD_RE_UJE)
#define RH_UJI TD(TD_RH_UJI)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [L_EN] = LAYOUT(
                          KC_ESC,  EN_QUOT, AG_DQUO, EN_HASH, EN_DLR,    AG_PERC,                                      AG_COLN, EN_AMPR, AG_ASTR, AG_MINS,  AG_PLUS,  AG_QUES,
           LA_CHNG,       KC_TAB,  EN_Q,    EN_W,    EN_E,    EN_R,      EN_T,                                         EN_Y,    EN_U,    EN_I,    EN_O,     EN_P,     EN_GRV,   AG_SLSH,
                          AWSM_T,  EN_A,    EN_S,    EN_D,    EN_F,      EN_G,                                         EN_H,    EN_J,    EN_K,    EN_L,     AG_SCLN,  EN_AT,  
                          KC_LALT, EN_Z,    EN_X,    EN_C,    EN_V,      EN_B,                                         EN_N,    EN_M,    AG_EQL,  AG_UNDS,  AG_DOT,   AG_COMM,
                                                              SFT_N,     KC_SPC, KC_LCTL,                   NUKE_ENT,  ENRU_BSP,MO(L_OTHER)
  ),

  [L_EN_S] = LAYOUT(
                          EN_TILD, EN_1,    EN_2 ,   EN_3,    EN_4,      EN_5,                                         EN_6,    EN_7,    EN_8,    EN_9,     EN_0,     EN_PIPE,
           LA_CHNG,       KC_TAB,  EN_S_Q,  EN_S_W,  EN_S_F,  EN_S_P,    EN_S_B,                                       EN_S_J,  EN_S_L,  EN_S_U,  EN_S_Y,   _______,  _______,  AG_BSLS,
                          KC_LGUI, EN_S_A,  EN_S_R,  EN_S_D,  EN_S_T,    EN_S_G,                                       EN_S_M,  EN_S_N,  EN_S_E,  EN_S_I,   EN_S_O,   _______,
                          KC_LALT, EN_S_Z,  EN_S_X,  EN_S_C,  EN_S_D,    EN_S_V,                                       EN_S_K,  EN_S_H,  _______,  _______, AG_EXCL,  EN_CIRC,
                                                              _______,   KC_SPC, KC_LCTL,                   NUKE_ENT,  ENRU_BSP,MO(L_OTHER)
  ),

  [L_RU] = LAYOUT(
                          KC_ESC,  EN_QUOT, AG_DQUO, RU_NUME, EN_DLR,  AG_PERC,                                        AG_COLN, EN_AMPR, AG_ASTR, AG_MINS,  AG_PLUS,  AG_QUES,
           LA_CHNG,       KC_TAB,  RU_J,    RU_TS,   RU_U,    RU_K,    RU_JE,                                          RU_N,    RU_G,    RU_SH,   RU_SC,    RU_Z,     RH_UJI,   AG_SLSH,
                          AWSM_T,  RU_F,    RY_UI,   RU_V,    RU_A,    RU_P,                                           RU_R,    RU_O,    RU_L,    RU_D,     RU_ZH,    RE_UJE,
                          KC_LALT, RU_JA,   RU_CH,   RU_S,    RU_M,    RU_I,                                           RU_T,    RU_SF,   RU_B,    RU_JU,    AG_DOT,   AG_COMM,
                                                              SFT_N,   KC_SPC,   KC_LCTL,                   NUKE_ENT,  RUEN_BSP,MO(L_OTHER)
  ),
  
  [L_RU_S] = LAYOUT(
                          EN_TILD, RU_1,    RU_2 ,   RU_3,    RU_4,    RU_5,                                           RU_6,    RU_7,    RU_8,    RU_9,     RU_0,     EN_PIPE,
           LA_CHNG,       KC_TAB,  RU_S_J,  RU_S_TS, RU_S_U,  RU_S_K,  RU_S_JE,                                        RU_S_N,  RU_S_G,  RU_S_SH, RU_S_SC,  RU_S_Z,   RH_UJI, AG_BSLS,
                          KC_LGUI, RU_S_F,  RY_UI,   RU_S_V,  RU_S_A,  RU_S_P,                                         RU_S_R,  RU_S_O,  RU_S_L,  RU_S_D,   RU_S_ZH,  RE_UJE,
                          KC_LALT, RU_S_JA, RU_S_CH, RU_S_S,  RU_S_M,  RU_S_I,                                         RU_S_T,  RU_S_SF, RU_S_B,  RU_S_JU,  AG_EXCL,  EN_CIRC,
                                                              _______, KC_SPC,   KC_LCTL,                   NUKE_ENT,  RUEN_BSP,MO(L_OTHER)
  ),

  [L_UA] = LAYOUT(
                          KC_ESC,  EN_QUOT, AG_DQUO, UA_NUME, EN_DLR,  AG_PERC,                                        AG_COLN, EN_AMPR, AG_ASTR, AG_MINS,  AG_PLUS,  AG_QUES,
           LA_CHNG,       KC_TAB,  UA_J,    UA_TS,   UA_U,    UA_K,    UA_E,                                           UA_N,    UA_G,    UA_SH,   UA_SC,    UA_Z,     UA_H,     EN_SLSH,
                          AWSM_T,  UA_F,    UA_I,    UA_V,    UA_A,    UA_P,                                           UA_R,    UA_O,    UA_L,    UA_D,     UA_ZH,    UA_JE,
                          KC_LALT, UA_JA,   UA_CH,   UA_S,    UA_M,    UA_Y,                                           UA_T,    UA_SF,   UA_B,    UA_JU,    AG_DOT,   AG_COMM,
                                                              SFT_N,   KC_SPC,   KC_LCTL,                   NUKE_ENT,  UAEN_BSP,MO(L_OTHER)
  ),

  [L_UA_S] = LAYOUT(
                          EN_TILD, UA_1,    UA_2 ,   UA_3,    UA_4,    UA_5,                                           UA_6,    UA_7,    UA_8,    UA_9,     UA_0,     EN_PIPE,
           LA_CHNG,       KC_TAB,  UA_S_J,  UA_S_TS, UA_S_U,  UA_S_K,  UA_S_E,                                         UA_S_N,  UA_S_G,  UA_S_SH, UA_S_SC,  UA_S_Z,   UA_S_H,   EN_BSLS,
                          KC_LGUI, UA_S_F,  UA_S_I,  UA_S_V,  UA_S_A,  UA_S_P,                                         UA_S_R,  UA_S_O,  UA_S_L,  UA_S_D,   UA_S_ZH,  UA_S_JE,
                          KC_LALT, UA_S_JA, UA_S_CH, UA_S_S,  UA_S_M,  UA_S_Y,                                         UA_S_T,  UA_S_SF, UA_S_B,  UA_S_JU,  AG_EXCL,  EN_CIRC,
                                                              _______, KC_SPC,   KC_LCTL,                   NUKE_ENT,  UAEN_BSP,MO(L_OTHER)
  ),

  [L_OTHER] = LAYOUT(
                          KC_F1,         KC_F2,     KC_F3,    KC_F4,     KC_F5,   KC_F6,                               KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12,
           LA_SYNC,       KC_PSCR,       EN_CJSLB,  EN_LTEQ,  EN_LCBR,   EN_RCBR, EN_ARR2,                             KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,  KC_NO,       KC_DEL,
                          KC_LGUI,       EN_CJST,   EN_LT,    AG_LPRN,   AG_RPRN, EN_GT,                               KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,  KC_NO,
                          KC_LALT,       EN_CJIF,   EN_GTEQ,  EN_LBRC,   EN_RBRC, EN_ARR1,                             CTL_LEFT,CTL_DOWN,CTL_UP,  CTL_RGHT,KC_NO,  KC_NO,
                                                                         KC_LSFT, KC_SPC, KC_LCTL,          RESET,     KC_BSPC, KC_NO
  ),

  [L_NUKE_WAR] = LAYOUT(
                          KC_ESC,         KC_SLCK,   KC_CAPS,  KC_INSERT, KC_PAUSE,KC_PSCR,                            KC_NO,   KC_PSLS, KC_P7,   KC_P8,   KC_P9,  KC_PMNS,
           KC_MENU,       KC_TAB,         _______,   _______,  _______,   _______,   _______,                          _______, KC_PAST, KC_P4,   KC_P5,   KC_P6,  KC_PPLS,     KC_NLCK,
                          KC_RGUI,        _______,   _______,  _______,   _______,   _______,                          _______, _______, KC_P1,   KC_P2,   KC_P3,  KC_PENT,
                          KC_RALT,        KC_LALT,   KC_LSFT,  KC_LGUI,   _______,   _______,                          _______, _______, KC_P0,   KC_PDOT, KC_PCMM,KC_PEQL,
                                                                          KC_RSFT, KC_SPC, KC_RCTL,         KC_NO,     KC_BSPC, MO(L_OTHER)
  ),

  [L_AWSM] = LAYOUT(
                          _______, KC_1,    KC_2,  KC_3,  KC_4,    KC_5,                                               KC_6,  KC_7,  KC_8,    KC_9,   KC_0,    _______,
           LA_CHNG,       _______, KC_Q,    KC_W,  KC_E,  KC_R,    KC_T,                                               KC_Y,  KC_U,  KC_I,    KC_O,   KC_P,    _______,  _______,
                          _______, KC_A,    KC_S,  KC_D,  KC_F,    KC_G,                                               KC_H,  KC_J,  KC_K,    KC_L,   _______, _______,
                          _______, KC_Z,    KC_X,  KC_C,  KC_V,    KC_B,                                               KC_N,  KC_M,  KC_COMM, KC_DOT, _______,  _______,
                                                          KC_LSHIFT, _______, _______,                       _______,  _______, _______
  ),

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
