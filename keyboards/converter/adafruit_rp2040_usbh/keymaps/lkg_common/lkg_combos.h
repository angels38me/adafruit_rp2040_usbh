#pragma once

enum combos {
  SCLN_J_DELPREVWORD = 0,    // ; + J = Delete PREV word (Ctrl+Backspace)
  SCLN_L_DELNEXTWORD,        // ; + L = Delete NEXT word (Ctrl+Del)  
  SCLN_A_COPY,               // ; + A = Copy (Ctrl+C)
  D_K_PASTE,                 // D + K = Paste (Ctrl+V)
  Q_D_LGUI,                  // Q + D = Right Gui
  P_K_RGUI,                  // P + K = Right Gui
  L_S_SELECT_ALL,            // L + S = Select all (Ctrl+A)
  Q_V_LCTL,                  // Q + V = Left Control
  P_N_RCTL,                  // P + N = Right Control
  Q_T_LALT,                  // Q + T = Left Alt
  P_Y_RALT,                  // P + Y = Right Alt
  Q_H_J_TO1_BLANK,           // Q + H + J = Toggle Layer 1
  //N_M_V_OSL_BLANK,         // N + M + V = One-shot Layer 1
  SCLN_K_MENU,               // ; + K = Context menu
  E_I_UNDO,                  // E + I = Undo (Ctrl+Z)
  W_O_REDO,                  // W + O = Redo (Ctrl+Y)
  NMNS_PSLS,
  NMNS_PAST,
  BOOT_Combo,              // This gives us the count
  LBRC_RBRC_OSM_CAPS,        // [ + ] = One-shot Caps Lock
  COMBO_LENGTH,              // This gives us the count
};

// Combo key sequences
const uint16_t PROGMEM combo_0[]  = {KC_SCLN,  KC_J,         COMBO_END};
const uint16_t PROGMEM combo_1[]  = {KC_SCLN,  KC_L,         COMBO_END};
const uint16_t PROGMEM combo_2[]  = {KC_SCLN,  KC_A,         COMBO_END};
const uint16_t PROGMEM combo_3[]  = {KC_D,     KC_K,         COMBO_END};
const uint16_t PROGMEM combo_4[]  = {KC_Q,     KC_D,         COMBO_END};
const uint16_t PROGMEM combo_5[]  = {KC_L,     KC_S,         COMBO_END};
const uint16_t PROGMEM combo_6[]  = {KC_Q,     KC_V,         COMBO_END};
const uint16_t PROGMEM combo_7[]  = {KC_P,     KC_N,         COMBO_END};
const uint16_t PROGMEM combo_8[]  = {KC_Q,     KC_H, KC_J,   COMBO_END};
//const uint16_t PROGMEM combo_9[]  = {KC_N,     KC_M, KC_V,   COMBO_END};
const uint16_t PROGMEM combo_10[] = {KC_SCLN,  KC_K,         COMBO_END};
const uint16_t PROGMEM combo_11[] = {KC_E,     KC_I,         COMBO_END};
const uint16_t PROGMEM combo_12[] = {KC_W,     KC_O,         COMBO_END};
const uint16_t PROGMEM combo_13[]  = {KC_Q,     KC_T,         COMBO_END};
const uint16_t PROGMEM combo_14[]  = {KC_P,     KC_Y,         COMBO_END};
const uint16_t PROGMEM combo_15[]  = {KC_P,     KC_K,         COMBO_END};
const uint16_t PROGMEM combo_16[] = {KC_PMNS, KC_PSLS, COMBO_END};  
const uint16_t PROGMEM combo_17[] = {KC_PMNS, KC_PAST, COMBO_END}; 
const uint16_t PROGMEM combo_18[] = {KC_PMNS, KC_PPLS, COMBO_END};  
const uint16_t PROGMEM combo_19[] = {KC_LBRC, KC_RBRC, COMBO_END};



combo_t key_combos[] = {
  [SCLN_J_DELPREVWORD]   = COMBO(combo_0,  MY_MACRO_2),    // FIXED: QK_MACRO_2 -> MY_MACRO_2
  [SCLN_L_DELNEXTWORD]   = COMBO(combo_1,  MY_MACRO_1),    // FIXED: QK_MACRO_1 -> MY_MACRO_1
  [SCLN_A_COPY]          = COMBO(combo_2,  MY_MACRO_3),    // FIXED: QK_MACRO_3 -> MY_MACRO_3
  [D_K_PASTE]            = COMBO(combo_3,  MY_MACRO_4),    // FIXED: QK_MACRO_4 -> MY_MACRO_4
  [L_S_SELECT_ALL]       = COMBO(combo_5,  MY_MACRO_5),    // FIXED: QK_MACRO_5 -> MY_MACRO_5
  [Q_V_LCTL]             = COMBO(combo_6,  KC_LCTL),
  [P_N_RCTL]             = COMBO(combo_7,  KC_RCTL),
  [Q_H_J_TO1_BLANK]      = COMBO(combo_8,  TO(1)),
  //[N_M_V_OSL_BLANK]      = COMBO(combo_9,  TO(2)),         // FIXED: OSL(_BLANK) -> OSL(1)
  [SCLN_K_MENU]          = COMBO(combo_10, KC_APP),
  [E_I_UNDO]             = COMBO(combo_11, MY_MACRO_6),    // FIXED: QK_MACRO_6 -> MY_MACRO_6
  [W_O_REDO]             = COMBO(combo_12, MY_MACRO_7),    // FIXED: QK_MACRO_7 -> MY_MACRO_7
  [Q_T_LALT]             = COMBO(combo_13, KC_LALT),
  [P_Y_RALT]             = COMBO(combo_14, KC_RALT),
  [Q_D_LGUI]             = COMBO(combo_4,  KC_LGUI),
  [P_K_RGUI]             = COMBO(combo_15, KC_RGUI),
  [NMNS_PSLS]   = COMBO(combo_16, KC_MPRV),  // Previous track
  [NMNS_PAST]   = COMBO(combo_17, KC_MNXT),  // Next track
  [BOOT_Combo]   = COMBO(combo_18, TO(7)),  // Next track
  [LBRC_RBRC_OSM_CAPS]   = COMBO(combo_19, KC_CAPS),  // One-shot Caps Lock

};


