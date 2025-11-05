#pragma once

#ifndef COMBO_TERM
  #define COMBO_TERM 25
#endif

#include QMK_KEYBOARD_H

void force_led_state(bool caps, bool scroll, bool num);

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
    TD_POWER_MODS,
    TD_POWER_MODS_R,
    TD_SHIFT_BRACKETS,
    TD_LAYER_1_2,
};

#define TD_NUM TD(TD_NUM_MEDIA)
#define TD_CAPS TD(TD_CAPS_CTRL)
#define TD_LAY TD(TD_LAYER_1_2)
#define PWR_SPC LT(1, KC_SPC)
#define PWRF_L1 LT(1, KC_F)
#define PWRJ_L1 LT(1, KC_J)

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

};