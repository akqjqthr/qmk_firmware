#include QMK_KEYBOARD_H
#include "bema.h"


#define _QWERTY 0


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_split_3x5_3(
     KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9   , KC_0    ,
     KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O   , KC_P    ,
     KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L   , KC_SCLN ,
                     KC_C  , KC_V  , KC_B  ,                         KC_B  , KC_N  , KC_M    
  )
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}
