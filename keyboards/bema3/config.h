#pragma once

#include "config_common.h"

#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6666
#define DEVICE_VER      0x0001
#define PRODUCT         BeMa3
#define MANUFACTURER    SaNoRaMyun

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 5
#define MATRIX_COLS 5

#define MATRIX_ROW_PINS { F7, B1, B3, B2, B6}
#define MATRIX_COL_PINS { C6, D7, E6, B4, B5}
// #define MATRIX_COL_PINS { B5, B4, E6, D7, C6}

#define UNUSED_PINS

// #define USE_I2C
// #define USE_SERIAL


// #define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define USE_SERIAL

#define SOFT_SERIAL_PIN D2
#define SELECT_SOFT_SERIAL_SPEED 1

// #define SOFT_SERIAL_PIN D2
/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
// #define BACKLIGHT_LEVELS 3

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

