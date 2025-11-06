#include "lkg_km_common.h"

#include "lkg_tap_dances.h"

extern bool actual_num_lock;

static tap dance_state[4];

uint8_t dance_step(tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) return SINGLE_TAP;
    else return SINGLE_HOLD;
  } else if (state->count == 2) {
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return TAP_THEN_HOLD;
    else return DOUBLE_TAP;
  }
  return MORE_TAPS;
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[0].step = dance_step(state);
  switch (dance_state[0].step) {
  case SINGLE_TAP: break;
  case SINGLE_HOLD: register_code16(KC_LCTL); break;
  case DOUBLE_TAP: break; 
  case TAP_THEN_HOLD: layer_on(1); break;
  case DOUBLE_SINGLE_TAP: break;
  case MORE_TAPS: break;
  }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[0].step) {
  case SINGLE_TAP: break;
  case SINGLE_HOLD: unregister_code16(KC_LCTL); break;
  case DOUBLE_TAP: break;
  case TAP_THEN_HOLD: layer_off(1); break;
  case DOUBLE_SINGLE_TAP: break;
  case MORE_TAPS: break;
  }
  dance_state[0].step = 0;
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[1].step = dance_step(state);
  switch (dance_state[1].step) {
  case SINGLE_TAP: register_code16(KC_F3); break;
  case SINGLE_HOLD: register_code16(KC_WH_U); break;
  case DOUBLE_TAP: break;
  case TAP_THEN_HOLD: break; 
  case DOUBLE_SINGLE_TAP: break;
  case MORE_TAPS: break;
  }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
  switch (dance_state[1].step) {
  case SINGLE_TAP: unregister_code16(KC_F3); break;
  case SINGLE_HOLD: unregister_code16(KC_WH_U); break;
  case DOUBLE_TAP: break;
  case TAP_THEN_HOLD: break;
  case DOUBLE_SINGLE_TAP: break;
  case MORE_TAPS: break;
  }
  dance_state[1].step = 0;
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[2].step = dance_step(state);
  switch (dance_state[2].step) {
  case SINGLE_TAP: set_oneshot_mods(MOD_BIT(KC_RALT)); break;
  case SINGLE_HOLD: register_code16(KC_LALT); break;
  case DOUBLE_TAP:  break;
  case TAP_THEN_HOLD:  break; 
  case DOUBLE_SINGLE_TAP: tap_code16(KC_RALT); register_code16(KC_RALT); break;
  case MORE_TAPS: break;
  }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
  switch (dance_state[2].step) {
  case SINGLE_TAP: break;
  case SINGLE_HOLD: clear_oneshot_mods(); unregister_code16(KC_LALT); break;
  case DOUBLE_TAP: break;
  case TAP_THEN_HOLD: break;
  case DOUBLE_SINGLE_TAP: unregister_code16(KC_RALT); break;
  case MORE_TAPS: break;
  }
  dance_state[2].step = 0;
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[3].step = dance_step(state);
  switch (dance_state[3].step) {
  case SINGLE_TAP: register_code16(KC_RBRC); break;
  case SINGLE_HOLD: register_code16(KC_MS_BTN1); break;
  case DOUBLE_TAP: break;
  case TAP_THEN_HOLD: break;
  case DOUBLE_SINGLE_TAP: break;
  case MORE_TAPS: break;
  }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[3].step) {
  case SINGLE_TAP: unregister_code16(KC_RBRC); break;
  case SINGLE_HOLD: unregister_code16(KC_MS_BTN1); break;
  case DOUBLE_TAP: break;
  case TAP_THEN_HOLD: break;
  case DOUBLE_SINGLE_TAP: break;
  case MORE_TAPS: break;
  }
  dance_state[3].step = 0;
}


// Global variables to track states
static bool td_caps_hold_ctrl = false;
static bool td_caps_hold_f24 = false;
static bool td_caps_hold_layer = false;

void td_capslock_finished(tap_dance_state_t *state, void *user_data) {
    // 4 taps = Caps Lock toggle
    if (state->count == 4 && !state->pressed) {
        tap_code(KC_CAPS);  // ✅ 4 taps = Caps Lock
    }
    
    // 1 tap hold = Left Control
    else if (state->count == 1 && state->pressed) {
        td_caps_hold_ctrl = true;
        register_code(KC_LCTL);  // ✅ 1 tap hold = Left Control
    }
    
    // 2 taps hold = F24 modifier (wraps next key)
    else if (state->count == 2 && state->pressed) {
        td_caps_hold_f24 = true;
        register_code(KC_F24);  // ✅ 2 taps hold = F24 modifier
    }
    
    // 3 taps hold = Momentary Layer 1 activation
    else if (state->count == 3 && state->pressed) {
        td_caps_hold_layer = true;
        layer_on(1);  // ✅ 3 taps hold = Momentary Layer 1
    }
}

void td_capslock_reset(tap_dance_state_t *state, void *user_data) {
    // Clean up any held modifiers/layers
    if (td_caps_hold_ctrl) {
        unregister_code(KC_LCTL);
        td_caps_hold_ctrl = false;
    }
    if (td_caps_hold_f24) {
        unregister_code(KC_F24);
        td_caps_hold_f24 = false;
    }
    if (td_caps_hold_layer) {
        layer_off(1);
        td_caps_hold_layer = false;
    }
}

void td_lctrl_finished(tap_dance_state_t *state, void *user_data) {
    
    // 1 tap hold = Left Control
    if (state->count == 1 && state->pressed) {
        td_caps_hold_ctrl = true;
        register_code(KC_LCTL);  // ✅ 1 tap hold = Left Control
    }
    
    // 2 taps hold = Momentary Layer 1 activation
    else if (state->count == 2 && state->pressed) {
        td_caps_hold_layer = true;
        layer_on(1);  // ✅ 3 taps hold = Momentary Layer 1
    }
    
    // 3 taps hold = F24 modifier (wraps next key)
    else if (state->count == 3 && state->pressed) {
        td_caps_hold_f24 = true;
        register_code(KC_F24);  // ✅ 2 taps hold = F24 modifier
    }
    

}

void td_lctrl_reset(tap_dance_state_t *state, void *user_data) {
    // Clean up any held modifiers/layers
    if (td_caps_hold_ctrl) {
        unregister_code(KC_LCTL);
        td_caps_hold_ctrl = false;
    }

    if (td_caps_hold_layer) {
        layer_off(1);
        td_caps_hold_layer = false;
    }    
    
    if (td_caps_hold_f24) {
        unregister_code(KC_F24);
        td_caps_hold_f24 = false;
    }
}


void td_numlock_finished(tap_dance_state_t *state, void *user_data) {
   // switch (state->count) {
    #ifdef CONSOLE_ENABLE
    uprintf("TD_NUM_MEDIA finished: count=%d, pressed=%d\n", state->count, state->pressed);
    #endif
    
    switch (state->count) {
        case 1:
            #ifdef CONSOLE_ENABLE
            uprintf("Sending MPLY\n");
            #endif
            tap_code(KC_MPLY);     // 1 tap = Play/Pause
            break;
        case 2:
            tap_code(KC_MSTP);     // 2 taps = Stop
            break;
        case 3:
            tap_code(KC_NUM);  // Use KC_NUM to match your process_record_user
            break;
        case 4:
            autoshift_toggle();
            tap_code(KC_NUM);
            break;
    }
}

void td_numlock_reset(tap_dance_state_t *state, void *user_data) {
    #ifdef CONSOLE_ENABLE
    uprintf("TD_NUM_MEDIA reset called\n");
    #endif
}

void dance_power_mods_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_LCTL);
    } else if (state->count == 2) {
        register_code(KC_LCTL);
        register_code(KC_LALT);
    } else if (state->count == 3) {
        register_code(KC_LCTL);
        register_code(KC_LALT);
        register_code(KC_LGUI);
    } else if (state->count == 4) {
        register_code(KC_LCTL);
        register_code(KC_LALT);
        register_code(KC_LGUI);
        register_code(KC_LSFT);
    }
}

void dance_power_mods_reset(tap_dance_state_t *state, void *user_data) {
    unregister_code(KC_LCTL);
    unregister_code(KC_LALT);
    unregister_code(KC_LGUI);
    unregister_code(KC_LSFT);
}

void dance_power_mods_r_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_RCTL);
    } else if (state->count == 2) {
        register_code(KC_RCTL);
        register_code(KC_RALT);
    } else if (state->count == 3) {
        register_code(KC_RCTL);
        register_code(KC_RALT);
        register_code(KC_RGUI);
    } else if (state->count == 4) {
        register_code(KC_RCTL);
        register_code(KC_RALT);
        register_code(KC_RGUI);
        register_code(KC_RSFT);
    }
}

void dance_power_mods_r_reset(tap_dance_state_t *state, void *user_data) {
    unregister_code(KC_RCTL);
    unregister_code(KC_RALT);
    unregister_code(KC_RGUI);
    unregister_code(KC_RSFT);
}


/*tap_dance_action_t tap_dance_actions[] = {
  [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_0_finished, dance_0_reset),
  [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_1_finished, dance_1_reset),
  [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_2_finished, dance_2_reset),
  [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_3_finished, dance_3_reset),
};*/

static uint8_t td_layer_active = 0;
static bool td_layer_is_hold = false;

// Tap dance functions for layers 1-7
void td_layer_12_finished(tap_dance_state_t *state, void *user_data) {
   if (state->pressed) {
        // This is a hold - momentary layer activation
        td_layer_is_hold = true;
        switch (state->count) {
            case 1:
                td_layer_active = 1;
                layer_on(1);
                break;
            case 2:
                td_layer_active = 2;
                layer_on(2);
                break;
            case 3:
                td_layer_active = 3;
                layer_on(3);
                break;
            case 4:
                td_layer_active = 4;
                layer_on(4);
                break;
            case 5:
                td_layer_active = 5;
                layer_on(5);
                break;
            case 6:
                td_layer_active = 6;
                layer_on(6);
                break;
            case 7:
                td_layer_active = 7;
                layer_on(7);
                break;
        }
    } else {
        // This is a tap - permanent layer switch
        td_layer_is_hold = false;
        layer_clear();
        switch (state->count) {
            case 1:
                layer_on(1);
                break;
            case 2:
                layer_on(2);
                break;
            case 3:
                layer_on(3);
                break;
            case 4:
                layer_on(4);
                break;
            case 5:
                layer_on(5);
                break;
            case 6:
                layer_on(6);
                break;
            case 7:
                layer_on(7);
                break;
        }
    }
}

void td_layer_12_reset(tap_dance_state_t *state, void *user_data) {
    // Only turn off the layer if it was a hold (momentary)
    if (td_layer_is_hold && td_layer_active >= 1 && td_layer_active <= 7) {
        layer_off(td_layer_active);
    }
    td_layer_active = 0;
    td_layer_is_hold = false;
}
