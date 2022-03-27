#pragma once

#include "quantum.h"

#define LAYOUT_split_3x5_3(\
  L00,   L01,   L02,   L03,   L04,                           R00,   R01,   R02,   R03,   R04, \
  L10,   L11,   L12,   L13,   L14,                           R10,   R11,   R12,   R13,   R14, \
  L20,   L21,   L22,   L23,   L24,                           R20,   R21,   R22,   R23,   R24, \
                L32,   L33,   L34,                           R30,   R31,   R32  \
  ) \
  { \
    { L00,   L01,   L02,   L03,   L04   }, \
    { L10,   L11,   L12,   L13,   L14   }, \
    { L20,   L21,   L22,   L23,   L24   }, \
    { KC_NO, KC_NO, L32,   L33,   L34   }, \
                                           \
    { R00,   R01,   R02,   R03,   R04   }, \
    { R10,   R11,   R12,   R13,   R14   }, \
    { R20,   R21,   R22,   R23,   R24   }, \
    { R30,   R31,   R32, KC_NO, KC_NO   }  \
}


enum charybdis_keycodes {
#        ifdef VIA_ENABLE
    POINTER_DEFAULT_DPI_FORWARD = USER00,
#        else
    POINTER_DEFAULT_DPI_FORWARD = SAFE_RANGE,
#        endif  // VIA_ENABLE
    POINTER_DEFAULT_DPI_REVERSE,
    POINTER_SNIPING_DPI_FORWARD,
    POINTER_SNIPING_DPI_REVERSE,
    SNIPING_MODE,
    SNIPING_MODE_TOGGLE,
    DRAGSCROLL_MODE,
    DRAGSCROLL_MODE_TOGGLE,
    KEYMAP_SAFE_RANGE,
};
#        define CHARYBDIS_SAFE_RANGE KEYMAP_SAFE_RANGE
#        define DPI_MOD POINTER_DEFAULT_DPI_FORWARD
#        define DPI_RMOD POINTER_DEFAULT_DPI_REVERSE
#        define S_D_MOD POINTER_SNIPING_DPI_FORWARD
#        define S_D_RMOD POINTER_SNIPING_DPI_REVERSE
#        define SNIPING SNIPING_MODE
#        define SNP_TOG SNIPING_MODE_TOGGLE
#        define DRGSCRL DRAGSCROLL_MODE
#        define DRG_TOG DRAGSCROLL_MODE_TOGGLE

#    define CHARYBDIS_POINTER_ACCELERATION_ENABLE
#    define CHARYBDIS_DRAGSCROLL_REVERSE_Y


#ifdef POINTING_DEVICE_ENABLE
// /** \brief Return the current DPI value for the pointer's default mode. */
uint16_t charybdis_get_pointer_default_dpi(void);

/**
 * \brief Update the pointer's default DPI to the next or previous step.
 *
 * Increases the DPI value if `forward` is `true`, decreases it otherwise.
 * The increment/decrement steps are equal to CHARYBDIS_DEFAULT_DPI_CONFIG_STEP.
 *
 * The new value is persisted in EEPROM.
 */
void charybdis_cycle_pointer_default_dpi(bool forward);

/**
 * \brief Same as `charybdis_cycle_pointer_default_dpi`, but do not write to
 * EEPROM.
 *
 * This means that reseting the board will revert the value to the last
 * persisted one.
 */
void charybdis_cycle_pointer_default_dpi_noeeprom(bool forward);

/** \brief Return the current DPI value for the pointer's sniper-mode. */
uint16_t charybdis_get_pointer_sniping_dpi(void);

/**
 * \brief Update the pointer's sniper-mode DPI to the next or previous step.
 *
 * Increases the DPI value if `forward` is `true`, decreases it otherwise.
 * The increment/decrement steps are equal to CHARYBDIS_SNIPING_DPI_CONFIG_STEP.
 *
 * The new value is persisted in EEPROM.
 */
void charybdis_cycle_pointer_sniping_dpi(bool forward);

/**
 * \brief Same as `charybdis_cycle_pointer_sniping_dpi`, but do not write to
 * EEPROM.
 *
 * This means that reseting the board will revert the value to the last
 * persisted one.
 */
void charybdis_cycle_pointer_sniping_dpi_noeeprom(bool forward);

/** \brief Whether sniper-mode is enabled. */
bool charybdis_get_pointer_sniping_enabled(void);

/**
 * \brief Enable/disable sniper mode.
 *
 * When sniper mode is enabled the dpi is reduced to slow down the pointer for
 * more accurate movements.
 */
void charybdis_set_pointer_sniping_enabled(bool enable);

/** \brief Whether drag-scroll is enabled. */
bool charybdis_get_pointer_dragscroll_enabled(void);

/**
 * \brief Enable/disable drag-scroll mode.
 *
 * When drag-scroll mode is enabled, horizontal and vertical pointer movements
 * are translated into horizontal and vertical scroll movements.
 */
void charybdis_set_pointer_dragscroll_enabled(bool enable);
#endif  // POINTING_DEVICE_ENABLE

void matrix_init_sub_kb(void);
void matrix_scan_sub_kb(void);

