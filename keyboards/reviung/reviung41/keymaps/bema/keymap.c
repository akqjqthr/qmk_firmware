/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define U_NP KC_NO // key is not present
#define U_NA KC_NO // present but not available for use
#define U_NU KC_NO // available but not used

enum layers { BASE, BUTTON, MEDIA, NAV, MOUSE, SYM, NUM, FUN };


enum {
    TD_NUM1,
    TD_NUM2,
    TD_NUM3,
    TD_NUM4,
    TD_NUM5,
    TD_NUM6,
    TD_NUM7,
    TD_NUM8,
    TD_NUM9,
    TD_NUM0,
    TD_BRL,
    TD_BRR,
    TD_MINS,
    TD_EQL,
    TD_BSLS,
    TD_QUOTE,
    TD_GRV,
    TD_DOT,
    TD_C,
    TD_V,
    CT_CBL,
    CT_CBR,
    CT_DEL
};

void dance_cbl_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        register_code16(KC_LCBR);
    } else {
        register_code(KC_LBRC);
    }
}

void dance_cbl_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        unregister_code16(KC_LCBR);
    } else {
        unregister_code(KC_LBRC);
    }    
}

void dance_cbr_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        register_code16(KC_RCBR);
    } else {
        register_code(KC_RBRC);
    }
}

void dance_cbr_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        unregister_code16(KC_RCBR);
    } else {
        unregister_code(KC_RBRC);
    }    
}

// All tap dance functions would go here. Only showing this one.
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_NUM1] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_EXLM),
    [TD_NUM2] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_AT),
    [TD_NUM3] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_HASH),
    [TD_NUM4] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_DLR),
    [TD_NUM5] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_PERC),
    [TD_NUM6] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_CIRC),
    [TD_NUM7] = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_AMPR),
    [TD_NUM8] = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_ASTR),
    [TD_NUM9] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_LPRN),
    [TD_NUM0] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_RPRN),
    [TD_BRL] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
    [TD_BRR] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),
    [TD_MINS] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_UNDS),
    [TD_EQL] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_PLUS),
    [TD_BSLS] = ACTION_TAP_DANCE_DOUBLE(KC_BSLS, KC_PIPE),
    [TD_QUOTE] = ACTION_TAP_DANCE_DOUBLE(KC_QUOTE, KC_DQUO),
    [TD_GRV] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_TILD),
    [TD_DOT] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_LPRN),
    [TD_C] = ACTION_TAP_DANCE_DOUBLE(KC_C, KC_LEFT),
    [TD_V] = ACTION_TAP_DANCE_DOUBLE(KC_V, KC_RGHT),
    [CT_CBL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cbl_finished, dance_cbl_reset),
    [CT_CBR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cbr_finished, dance_cbr_reset),
    [CT_DEL] = ACTION_TAP_DANCE_DOUBLE(KC_DEL, KC_ALGR)
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_F):
            return 200;
        case LSFT_T(KC_J):
            return 150;
        case LCTL_T(KC_D):
            return 250;
        case LCTL_T(KC_K):
            return 250;
        case LALT_T(KC_S):
            return 250;
        case LALT_T(KC_L):
            return 250;
        case LGUI_T(KC_A):
            return 300;
        case LGUI_T(KC_COLN):
            return 300;
        case ALGR_T(KC_M):
            return 200;
        case TD(TD_C):
            return 200;
        case TD(TD_V):
            return 200;
        case TD(TD_GRV):
        case TD(TD_BRL):
        case TD(TD_DOT):
            return 250;
        default:
            return TAPPING_TERM;
    }
}

#define U_RDO C(KC_Y)
#define U_PST C(KC_V)
#define U_CPY C(KC_C)
#define U_CUT C(KC_X)
#define U_UND C(KC_Z)
#define U_ALL C(KC_A)

const uint16_t PROGMEM test_combo1[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM test_combo2[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM test_combo3[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM test_combo4[] = {TD(TD_V), KC_B, COMBO_END};
const uint16_t PROGMEM test_combo5[] = {U_PST, KC_DEL, COMBO_END};
const uint16_t PROGMEM test_combo6[] = {KC_H, LSFT_T(KC_J), COMBO_END};
const uint16_t PROGMEM test_combo7[] = {KC_WH_D, KC_MS_L, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(test_combo1, KC_RALT),
    COMBO(test_combo2, KC_TAB),
    COMBO(test_combo3, KC_DEL),
    COMBO(test_combo4, TO(NAV)),
    COMBO(test_combo5, TO(BASE)),
    COMBO(test_combo6, TO(NAV)),
    COMBO(test_combo7, TO(BASE))
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_reviung41(
  //,----------------------------------------------------------------------------------------------------------------------.                                         ,---------------------------------------------------------------------------------------------------------------------.
         LGUI_T(CT_CBL),               KC_Q,               KC_W,               KC_E,               KC_R,               KC_T,                                                       KC_Y,               KC_U,               KC_I,               KC_O,               KC_P,     LGUI_T(KC_DEL),
  //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                                         |-----------------+-------------------+-------------------+-------------------+-------------------+-------------------|
        LCTL_T(KC_LEFT),       LGUI_T(KC_A),       LALT_T(KC_S),       LCTL_T(KC_D),       LSFT_T(KC_F),               KC_G,                                                       KC_H,       LSFT_T(KC_J),       LCTL_T(KC_K),       LALT_T(KC_L),    LGUI_T(KC_COLN),    LCTL_T(KC_LEFT), 
  //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                                         |-----------------+-------------------+-------------------+-------------------+-------------------+-------------------|
        LSFT_T(KC_RGHT),               KC_Z,       ALGR_T(KC_X),           TD(TD_C),           TD(TD_V),               KC_B,                                                       KC_N,               KC_M,            KC_COMM,     ALGR_T(KC_DOT),LT(BUTTON, KC_SLSH),    LSFT_T(KC_RGHT),
  //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                                         |-----------------+-------------------+-------------------+-------------------+-------------------+-------------------|
                                                                                      LT(MEDIA, KC_ESC),  LT(MOUSE, KC_BSPC),    LT(NUM2, KC_ENT),    LT(SYM, KC_SPC),  LT(FUN, KC_TAB)
  //                                                                               |-------------------+-------------------+--------------------+--------------------+-----------------+-------------------|
  ),


  [BUTTON] = LAYOUT_split_3x6_3(
  //,----------------------------------------------------------------------------------------------------------------------.                                         ,---------------------------------------------------------------------------------------------------------------------.
                KC_TRNS,              U_UND,              U_CUT,              U_CPY,              U_PST,              U_RDO,                                                      U_RDO,              U_PST,              U_CPY,              U_CUT,              U_UND,            KC_TRNS,
  //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                                         |-----------------+-------------------+-------------------+-------------------+-------------------+-------------------|
                KC_TRNS,            KC_LGUI,            KC_LALT,            KC_LCTL,            KC_LSFT,            KC_TRNS,                                                    KC_TRNS,            KC_LSFT,            KC_LCTL,            KC_LALT,            KC_LGUI,            KC_TRNS,
  //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                                         |-----------------+-------------------+-------------------+-------------------+-------------------+-------------------|
                KC_TRNS,              U_UND,              U_CUT,              U_CPY,              U_PST,              U_RDO,                                                      U_RDO,              U_PST,              U_CPY,              U_CUT,              U_UND,            KC_TRNS,
  //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                                         |-----------------+-------------------+-------------------+-------------------+-------------------+-------------------|
                                                                                                 KC_ESC,            KC_BSPC,              KC_ENT,              KC_SPC,           KC_TAB
  //                                                                               |-------------------+-------------------+--------------------+--------------------+-----------------+-------------------|
  ),

  [MEDIA] = LAYOUT_split_3x6_3(
  //,----------------------------------------------------------------------------------------------------------------------.                                         ,---------------------------------------------------------------------------------------------------------------------.
                KC_TRNS,            RGB_TOG,            RGB_MOD,            RGB_HUI,            RGB_SAI,            RGB_VAI,                                                       U_NA,            KC_HOME,              KC_UP,             KC_END,            KC_PGUP,            KC_TRNS,
  //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                                         |-----------------+-------------------+-------------------+-------------------+-------------------|-------------------|
                KC_TRNS,               U_NA,            KC_MPRV,            KC_VOLD,            KC_VOLU,            KC_MNXT,                                                    KC_CAPS,            KC_LEFT,            KC_DOWN,            KC_RGHT,            KC_PGDN,            KC_TRNS,
  //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                                         |-----------------+-------------------+-------------------+-------------------+-------------------|-------------------|
                KC_TRNS,               U_NA,               U_NA,               U_NA,               U_NA,              RESET,                                                      U_UND,              U_CUT,              U_CPY,              U_PST,              U_RDO,            KC_TRNS,
  //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                                         |-----------------+-------------------+-------------------+-------------------+-------------------+-------------------|
                                                                                                KC_MSTP,            KC_MPLY,             KC_MUTE,                U_NA,               U_NA
  //                                                                               |-------------------+-------------------+--------------------+--------------------+-----------------+-------------------|
  ),

  [NAV] = LAYOUT_split_3x6_3(
  //,----------------------------------------------------------------------------------------------------------------------.                                         ,---------------------------------------------------------------------------------------------------------------------.
                KC_TRNS,              U_UND,              U_CUT,            KC_HOME,             KC_END,            KC_PGUP,                                                    KC_PGUP,            KC_HOME,              KC_UP,             KC_END,               U_NA,            KC_TRNS,
  //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                                         |-----------------+-------------------+-------------------+-------------------+-------------------+-------------------|
                KC_TRNS,              U_ALL,            KC_LALT,            KC_LCTL,            KC_LSFT,            KC_PGDN,                                                    KC_PGDN,            KC_LEFT,            KC_DOWN,            KC_RGHT,               U_NA,            KC_TRNS,
  //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                                         |-----------------+-------------------+-------------------+-------------------+-------------------+-------------------|
                KC_TRNS,              U_UND,              U_CUT,              U_CPY,              U_PST,              U_RDO,                                                      U_RDO,              U_PST,              U_CPY,              U_CUT,              U_UND,            KC_TRNS,
  //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                                         |-----------------+-------------------+-------------------+-------------------+-------------------+-------------------|
                                                                                                   U_NA,               U_NA,              KC_ENT,           KC_SPC,             KC_DEL
  //                                                                               |-------------------+-------------------+--------------------+--------------------+-----------------+-------------------|
  ),

  [MOUSE] = LAYOUT_split_3x6_3(
  //,----------------------------------------------------------------------------------------------------------------------.                                         ,---------------------------------------------------------------------------------------------------------------------.
                KC_TRNS,            KC_LEFT,            KC_RGHT,            KC_BTN2,            KC_BTN1,            KC_WH_U,                                                    KC_WH_U,            KC_WH_L,            KC_MS_U,            KC_WH_R,            KC_BTN5,            KC_TRNS,
  //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                                         |-----------------+-------------------+-------------------+-------------------+-------------------+-------------------|
                KC_TRNS,              U_ALL,            KC_LALT,            KC_LCTL,            KC_LSFT,            KC_WH_D,                                                    KC_WH_D,            KC_MS_L,            KC_MS_D,            KC_MS_R,            KC_BTN4,            KC_TRNS,
  //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                                         |-----------------+-------------------+-------------------+-------------------+-------------------+-------------------|
                KC_TRNS,              U_UND,              U_CUT,              U_CPY,              U_PST,            KC_HOME,                                                     KC_END,            KC_LEFT,            KC_DOWN,              KC_UP,            KC_RGHT,            KC_TRNS,
  //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                                         |-----------------+-------------------+-------------------+-------------------+-------------------+-------------------|
                                                                                                   U_NA,               U_NA,             KC_BTN1,          KC_BTN2,            KC_BTN3
  //                                                                               |-------------------+-------------------+--------------------+--------------------+-----------------+-------------------|
  ),

  [SYM] = LAYOUT_split_3x6_3(
  //,----------------------------------------------------------------------------------------------------------------------.                                         ,---------------------------------------------------------------------------------------------------------------------.
                KC_TRNS,            KC_LCBR,            KC_AMPR,            KC_ASTR,            KC_LPRN,            KC_RCBR,                                                       U_NA,               U_NA,               U_NA,               U_NA,               U_NA,            KC_TRNS,
  //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                                         |-----------------+-------------------+-------------------+-------------------+-------------------+-------------------|
                KC_TRNS,            KC_DQUO,             KC_DLR,            KC_PERC,            KC_CIRC,            KC_PLUS,                                                       U_NA,            KC_LSFT,            KC_LCTL,            KC_LALT,            KC_LGUI,            KC_TRNS,
  //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                                         |-----------------+-------------------+-------------------+-------------------+-------------------+-------------------|
                KC_TRNS,            KC_TILD,            KC_EXLM,              KC_AT,            KC_HASH,            KC_PIPE,                                                       U_NA,               U_NA,               U_NA,            KC_ALGR,               U_NA,            KC_TRNS,
  //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                                         |-----------------+-------------------+-------------------+-------------------+-------------------+-------------------|
                                                                                                KC_LPRN,            KC_RPRN,             KC_UNDS,                U_NA,               U_NA
  //                                                                               |-------------------+-------------------+--------------------+--------------------+-----------------+-------------------|
  ),


  [NUM] = LAYOUT_split_3x6_3(
  //,----------------------------------------------------------------------------------------------------------------------.                                         ,---------------------------------------------------------------------------------------------------------------------.
             TD(TD_GRV),        TD(TD_NUM1),        TD(TD_NUM2),        TD(TD_NUM3),        TD(TD_NUM4),         TD(TD_GRV),                                                 TD(TD_EQL),        TD(TD_NUM7),        TD(TD_NUM8),        TD(TD_NUM9),        TD(TD_NUM0),            KC_TRNS,
  //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                                         |-----------------+-------------------+-------------------+-------------------+-------------------|-------------------|
                KC_TRNS,              U_ALL,            KC_LALT,            KC_LCTL,            KC_LSFT,         TD(TD_BRL),                                                 TD(TD_BRR),        TD(TD_NUM4),        TD(TD_NUM5),        TD(TD_NUM6),       TD(TD_QUOTE),            KC_TRNS,
  //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                                         |-----------------+-------------------+-------------------+-------------------+-------------------|-------------------|
                KC_TRNS,              U_UND,              U_CUT,              U_CPY,              U_PST,         TD(TD_DOT),                                                TD(TD_NUM0),        TD(TD_NUM1),        TD(TD_NUM2),        TD(TD_NUM3),        TD(TD_BSLS),            KC_TRNS,
  //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                                         |-----------------+-------------------+-------------------+-------------------+-------------------+-------------------|
                                                                                                   U_NA,               U_NA,          TD(TD_DOT),         TD(TD_NUM0),      TD(TD_MINS)
  //                                                                               |-------------------+-------------------+--------------------+--------------------+-----------------+-------------------|
  ),

  [FUN] = LAYOUT_split_3x6_3(
  //,----------------------------------------------------------------------------------------------------------------------.                                         ,---------------------------------------------------------------------------------------------------------------------.
                KC_TRNS,               U_NA,               U_NA,               U_NA,               U_NA,               U_NA,                                                    KC_PSCR,              KC_F7,              KC_F8,              KC_F9,             KC_F12,            KC_TRNS,
  //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                                         |-----------------+-------------------+-------------------+-------------------+-------------------|-------------------|
                KC_TRNS,            KC_LGUI,            KC_LALT,            KC_LCTL,            KC_LSFT,               U_NA,                                                    KC_SLCK,              KC_F4,              KC_F5,              KC_F6,             KC_F11,            KC_TRNS,
  //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                                         |-----------------+-------------------+-------------------+-------------------+-------------------|-------------------|
                KC_TRNS,               U_NA,               U_NA,               U_NA,            KC_ALGR,               U_NA,                                                    KC_PAUS,              KC_F1,              KC_F2,              KC_F3,             KC_F10,            KC_TRNS,
  //|------------------+-------------------+-------------------+-------------------+-------------------+-------------------|                                         |-----------------+-------------------+-------------------+-------------------+-------------------+-------------------|
                                                                                                 KC_APP,            KC_BSPC,              KC_ENT,                U_NA,             U_NA,               U_NA
  //                                                                               |-------------------+-------------------+--------------------+--------------------+-----------------+-------------------|
  )
};




// #ifdef RGBLIGHT_EFFECT_STATIC_GRADIENT
// uint32_t layer_state_set_keymap(uint32_t state) {
//     rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
//     switch (biton32(state)) {
//         case BASE:
//             rgblight_sethsv_noeeprom_red();
//             break;
//         case NAV:
//             rgblight_sethsv_noeeprom_green();
//             break;
//         default:  // for any other layers, or the default layer
//             rgblight_mode(RGBLIGHT_MODE_STATIC_GRADIENT + 3);
//             rgblight_sethsv_red();
//             break;
//     }
//     return state;
// }
// #endif
