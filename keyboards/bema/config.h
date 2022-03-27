#pragma once

#include "config_common.h"

#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6666
#define DEVICE_VER      0x0001
#define PRODUCT         BeMa
#define MANUFACTURER    SaNoRaMyun

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 8
#define MATRIX_COLS 5

#define MATRIX_ROW_PINS { F4, F5, F6, F7}
#define MATRIX_COL_PINS { C6, D7, E6, B4, B5}
// #define MATRIX_COL_PINS { B5, B4, E6, D7, C6}

#define MATRIX_ROW_PINS_RIGHT { F4, F5, F6, F7 }
#define MATRIX_COL_PINS_RIGHT { C6, D7, E6, B4, B5 }
// #define MATRIX_COL_PINS_RIGHT { B5, B4, E6, D7, C6}

#define UNUSED_PINS

// #define USE_I2C
// #define USE_SERIAL


// #define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define USE_SERIAL

// #define SPLIT_TRANSPORT_MIRROR
#define SPLIT_HAND_PIN D1

#define SOFT_SERIAL_PIN D2
#define SELECT_SOFT_SERIAL_SPEED 1
// #define EE_HANDS
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2500

// #define SOFT_SERIAL_PIN D2
/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
// #define BACKLIGHT_LEVELS 3

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW


// /* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
// #define LOCKING_SUPPORT_ENABLE
// /* Locking resynchronize hack */
// #define LOCKING_RESYNC_ENABLE

// /* disable these deprecated features by default */
// #define NO_ACTION_MACRO
// #define NO_ACTION_FUNCTION




#undef SPI_SCK_PIN
#undef SPI_MOSI_PIN
#undef SPI_MISO_PIN

/* spi config for eeprom and pmw3360 sensor */
#define SPI_DRIVER                           SPID1
#define SPI_SCK_PIN                          B1
#define SPI_SCK_PAL_MODE                     5
#define SPI_MOSI_PIN                         B2
#define SPI_MOSI_PAL_MODE                    5
#define SPI_MISO_PIN                         B3
#define SPI_MISO_PAL_MODE                    5

/* eeprom config */
#define EXTERNAL_EEPROM_SPI_SLAVE_SELECT_PIN A4
#define EXTERNAL_EEPROM_SPI_CLOCK_DIVISOR    64
// #define EXTERNAL_EEPROM_BYTE_COUNT           8196
// #define EXTERNAL_EEPROM_PAGE_SIZE            32
// #define EXTERNAL_EEPROM_ADDRESS_SIZE         2

/* pmw3360 config  */
#undef PMW3360_CS_PIN
#define PMW3360_CS_PIN                       B6
#define PMW3360_SPI_MODE                     3
#define PMW3360_SPI_DIVISOR                  64
#define ROTATIONAL_TRANSFORM_ANGLE           20



#        define CHARYBDIS_MINIMUM_DEFAULT_DPI 1200
#        define CHARYBDIS_DEFAULT_DPI_CONFIG_STEP 400
#        define CHARYBDIS_MINIMUM_SNIPING_DPI 200
#        define CHARYBDIS_SNIPING_DPI_CONFIG_STEP 100






// #define SPI_DRIVER                           SPID2
// #define SPI_SCK_PIN                          D7
// #define SPI_SCK_PAL_MODE                     5
// #define SPI_MOSI_PIN                         E6
// #define SPI_MOSI_PAL_MODE                    5
// #define SPI_MISO_PIN                         B4
// #define SPI_MISO_PAL_MODE                    5

// #define PMW3360_CS_PIN                       B6
// #define PMW3360_CPI 800  // From the docs: "The CPI range is 100-12000, in increments of 100. Defaults to 1600 CPI."


// #define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT
// #define POINTING_DEVICE_LEFT

#define POINTING_DEVICE_TASK_THROTTLE_MS 1
// #define POINTING_DEVICE_INVERT_X_RIGHT

#define POINTING_DEVICE_INVERT_X
// #define POINTING_DEVICE_INVERT_Y
#define POINTING_DEVICE_ROTATION_90
// #define POINTING_DEVICE_ROTATION_180_RIGHT

#define SPLIT_TRANSACTION_IDS_KB RPC_ID_KB_CONFIG_SYNC

// #define SPLIT_TRANSACTION_IDS_KB RPC_ID_KB_CONFIG_SYNC, RPC_ID_POINTER_STATE_SYNC

// PMW3360_CS_PIN	(Required) Sets the Cable Select pin connected to the sensor.	not defined
// PMW3360_CLOCK_SPEED	(Optional) Sets the clock speed that the sensor runs at.	2000000
// PMW3360_SPI_LSBFIRST	(Optional) Sets the Least/Most Significant Byte First setting for SPI.	false
// PMW3360_SPI_MODE	(Optional) Sets the SPI Mode for the sensor.	3
// PMW3360_SPI_DIVISOR	(Optional) Sets the SPI Divisor used for SPI communication.	varies
// PMW3360_LIFTOFF_DISTANCE	(Optional) Sets the lift off distance at run time	0x02
// ROTATIONAL_TRANSFORM_ANGLE	(Optional) Allows for the sensor data to be rotated +/- 127 degrees directly in the sensor.	0
// PMW3360_FIRMWARE_UPLOAD_FAST	(Optional) Skips the 15us wait between firmware blocks.	not defined

// POINTING_DEVICE_ROTATION_90	(Optional) Rotates the X and Y data by 90 degrees.	not defined
// POINTING_DEVICE_ROTATION_180	(Optional) Rotates the X and Y data by 180 degrees.	not defined
// POINTING_DEVICE_ROTATION_270	(Optional) Rotates the X and Y data by 270 degrees.	not defined
// POINTING_DEVICE_INVERT_X	(Optional) Inverts the X axis report.	not defined
// POINTING_DEVICE_INVERT_Y	(Optional) Inverts the Y axis report.	not defined
// POINTING_DEVICE_MOTION_PIN	(Optional) If supported, will only read from sensor if pin is active.	not defined
// POINTING_DEVICE_TASK_THROTTLE_MS	(Optional) Limits the frequency that the sensor is polled for motion.	not defined

// POINTING_DEVICE_LEFT	Pointing device on the left side (Required - pick one only)	not defined
// POINTING_DEVICE_RIGHT	Pointing device on the right side (Required - pick one only)	not defined
// POINTING_DEVICE_COMBINED	Pointing device on both sides (Required - pick one only)	not defined
// POINTING_DEVICE_ROTATION_90_RIGHT	(Optional) Rotates the X and Y data by 90 degrees.	not defined
// POINTING_DEVICE_ROTATION_180_RIGHT	(Optional) Rotates the X and Y data by 180 degrees.	not defined
// POINTING_DEVICE_ROTATION_270_RIGHT	(Optional) Rotates the X and Y data by 270 degrees.	not defined
// POINTING_DEVICE_INVERT_X_RIGHT	(Optional) Inverts the X axis report.	not defined
// POINTING_DEVICE_INVERT_Y_RIGHT	(Optional) Inverts the Y axis report.	not defined
