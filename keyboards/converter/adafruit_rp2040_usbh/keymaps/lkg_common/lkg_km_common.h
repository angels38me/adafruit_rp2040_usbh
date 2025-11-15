#pragma once

#ifndef COMBO_TERM
  #define COMBO_TERM 25
#endif

#include QMK_KEYBOARD_H

void force_led_state(bool caps, bool scroll, bool num);

// Home row mods state
extern bool home_row_mods_enabled;

// Single enum layers definition - remove any duplicates
enum layers {
  LAYER_0,
  LAYER_1,
  LAYER_2,
  LAYER_3,
  LAYER_4,
  LAYER_5,
  LAYER_6,
  LAYER_7,
};

// Tap dance enum
enum {
    TD_NUM_MEDIA,
    TD_CAPS_CTRL,
    TD_CTRL_LAY,
    TD_POWER_MODS,
    TD_POWER_MODS_R,
    TD_SHIFT_BRACKETS,
    TD_LAYER_1_2,
};


// Custom keycodes - use MY_MACRO_X to avoid QMK conflicts
enum custom_keycodes {
    MY_MACRO_0 = SAFE_RANGE,  // ñ/Ñ macro
    MY_MACRO_1,               // Delete next word (Ctrl+Del)
    MY_MACRO_2,               // Delete prev word (Ctrl+Backspace)
    MY_MACRO_3,               // Copy (Ctrl+C)
    MY_MACRO_4,               // Paste (Ctrl+V)
    MY_MACRO_5,               // Select all (Ctrl+A)
    MY_MACRO_6,               // Undo (Ctrl+Z)
    MY_MACRO_7,               // Redo (Ctrl+Y)
    MY_MACRO_8,               // Emacs: Ctrl+X Ctrl+W
    MY_MACRO_9,               // Emacs: Ctrl+X {
    MY_MACRO_10,              // Emacs: Ctrl+X }
    MY_MACRO_11,              // Emacs: Ctrl+X 4 B
    MY_MACRO_12,              // Emacs: Ctrl+X 4 D
    MY_MACRO_13,              // Emacs: Ctrl+X ^
    MY_MACRO_14,              // Emacs: Ctrl+X Ctrl+P
    MY_MACRO_15,              // Emacs: Ctrl+X 5 0
    MY_MACRO_16,              // Emacs: Ctrl+X 5 1
    MY_MACRO_17,              // Emacs: Ctrl+X 5 2
    MY_MACRO_18,              // Emacs: Ctrl+X Ctrl+Q
    MY_MACRO_19,              // Emacs: Ctrl+X Ctrl+U
    MY_MACRO_20,              // Emacs: Ctrl+X Ctrl+L
    MY_MACRO_21,              // Emacs: Ctrl+X Ctrl+T
    MY_MACRO_22,              // Emacs: Ctrl+C Ctrl+C
    MY_MACRO_23,              // Emacs: Ctrl+X R S
    MY_MACRO_24,              // Emacs: Ctrl+X R I
    MY_MACRO_25,              // Parentheses with cursor positioning
    MY_MACRO_26,              // Emacs: Ctrl+X R R
    MY_MACRO_27,              // Emacs: Ctrl+X R K
    MY_MACRO_28,              // Emacs: Ctrl+X R O
    MY_MACRO_29,              // Emacs: Ctrl+X R T
    MY_MACRO_30,              // Emacs: Ctrl+X R C
    MY_MACRO_31,              // Emacs: Ctrl+X R Y
    MY_MACRO_32,
    SEL_LINE,
    CD_FIRMWARE,
    MAKE_KEYMAP,
    WORD1,
    WORD2,
    MAKE_CODER,
    HIGH_CONTRAST,
    DUP_LINE,
    DEL_LINE,
    NEW_DESK,
    DESK_LEFT,
    DESK_RIGHT,
    CLOSE_DESK,
    HRM_TOG,              // Home row mods toggle
};

  #define TD_NUM TD(TD_NUM_MEDIA)
  #define TD_CAPS TD(TD_CAPS_CTRL)
  #define TD_LAY TD(TD_LAYER_1_2) 
  #define TD_CLAY TD(TD_CTRL_LAY)
  #define PWR_SPC LT(1, KC_SPC)
  #define PWRF_L1 LT(1, KC_F)
  #define PWRJ_L1 LT(1, KC_J)
  #define ALT_ESC LALT(KC_ESC)

  // Home row mod-tap definitions (only used when HRM is enabled)
  #define HRM_A LCTL_T(KC_A)     // Left Ctrl
  #define HRM_S LGUI_T(KC_S)     // Left GUI/Win
  #define HRM_D LALT_T(KC_D)     // Left Alt
  #define HRM_F LSFT_T(KC_F)     // Left Shift
  #define HRM_J RSFT_T(KC_J)     // Right Shift (opposite order)
  #define HRM_K RALT_T(KC_K)     // Right Alt  
  #define HRM_L RGUI_T(KC_L)     // Right GUI/Win
  #define HRM_SCLN RCTL_T(KC_SCLN) // Right Ctrl

  #define DK_NEW NEW_DESK
  #define DK_LFT DESK_LEFT
  #define DK_RHT DESK_RIGHT
  #define DK_CLS CLOSE_DESK

  #define H1 HYPR(KC_1)
  #define H2 HYPR(KC_2)
  #define H3 HYPR(KC_3)
  #define H4 HYPR(KC_4)
  #define H5 HYPR(KC_5)
  #define H6 HYPR(KC_6)
  #define H7 HYPR(KC_7)
  #define H8 HYPR(KC_8)
  #define H9 HYPR(KC_9)
  #define H0 HYPR(KC_0)

  #define HYPER  HYPR(KC_NO)
