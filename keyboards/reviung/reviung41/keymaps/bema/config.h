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

#pragma once

/* Select hand configuration */

// #define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS


#define RGBLIGHT_LAYERS
#ifdef RGB_DI_PIN
    // /*== all animations enable ==*/
    //#define RGBLIGHT_ANIMATIONS
    // /*== or choose animations ==*/
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#endif


// #ifdef RGB_DI_PIN
//   //  #define RGBLED_NUM 6
//    #define RGBLIGHT_HUE_STEP 8
//    #define RGBLIGHT_SAT_STEP 8
//    #define RGBLIGHT_VAL_STEP 8
//    #define RGBLIGHT_LIMIT_VAL 255 /* The maximum brightness level */
//    #define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
// // /*== all animations enable ==*/
// //   #define RGBLIGHT_ANIMATIONS
// // /*== or choose animations ==*/
// //   #define RGBLIGHT_EFFECT_BREATHING
// //   #define RGBLIGHT_EFFECT_RAINBOW_MOOD
// //   #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
// //   #define RGBLIGHT_EFFECT_SNAKE
// //   #define RGBLIGHT_EFFECT_KNIGHT
// //   #define RGBLIGHT_EFFECT_CHRISTMAS
// //   #define RGBLIGHT_EFFECT_STATIC_GRADIENT
// //   #define RGBLIGHT_EFFECT_RGB_TEST
// //   #define RGBLIGHT_EFFECT_ALTERNATING
//     #define RGBLIGHT_EFFECT_BREATHING
//     #define RGBLIGHT_EFFECT_RAINBOW_MOOD
//     #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
// #endif

// default but used in macros
#undef TAPPING_TERM
#define TAPPING_TERM 200

#define TAPPING_TERM_PER_KEY

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

#define COMBO_COUNT 7
#define COMBO_TERM 30

// Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define AUTO_SHIFT_NO_SETUP

// Recommended for heavy chording.
#define QMK_KEYS_PER_SCAN 4

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       20
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      4
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    40


// #define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
