#include "lkg_km_common.h"
#include "lkg_leader.h"  // Add this include

#ifdef LEADER_ENABLE
#include "process_leader.h"

#endif


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    
    if (!process_caps_word(keycode, record)) {
        return false;
    }


   // #ifdef CONSOLE_ENABLE
   // uprintf("keycode: %u, pressed: %d\n", keycode, record->event.pressed);
   // #endif

        // ADD THIS BLOCK: Neutralize Caps Lock effect on layers 1 and 2
    if (!IS_LAYER_ON(0) && host_keyboard_led_state().caps_lock) {
        // We're not on layer 0 and Caps Lock is on
        // Check if this is an alphabetic key
        if (keycode >= KC_A && keycode <= KC_Z) {
            if (record->event.pressed) {
                // Caps Lock inverts the shift state, so we need to counter it
                // by adding shift (which will cancel out the Caps Lock effect)
                add_mods(MOD_BIT(KC_LSFT));
                register_code(keycode);
                del_mods(MOD_BIT(KC_LSFT));
            } else {
                unregister_code(keycode);
            }
            return false;  // We handled this key
        }
    }

    // ADD THIS BLOCK: Neutralize Num Lock effect on layers 1 and 2  
    if (!IS_LAYER_ON(0) && !host_keyboard_led_state().num_lock) {
        // We're not on layer 0 and Num Lock is off
        // Numpad keys would normally send navigation, but we want numbers
        switch(keycode) {
            case KC_P0:
            case KC_P1:
            case KC_P2:
            case KC_P3:
            case KC_P4:
            case KC_P5:
            case KC_P6:
            case KC_P7:
            case KC_P8:
            case KC_P9:
            case KC_PDOT:
                if (record->event.pressed) {
                    // Temporarily turn on Num Lock for this key
                    tap_code(KC_NUM);  // Turn on Num Lock
                    register_code(keycode);
                    tap_code(KC_NUM);  // Turn it back off
                } else {
                    unregister_code(keycode);
                }
                return false;
        }
    }

    if (record->event.pressed) {
        switch (keycode) {
        
        case SEL_LINE:
            if (record->event.pressed) {

                tap_code(KC_HOME);
                wait_ms(20);
 
                register_code(KC_LSFT);
                tap_code(KC_END);
                unregister_code(KC_LSFT);
            }
            return false; // Skip further processing

        case DUP_LINE:
            if (record->event.pressed) {
                // Select the entire line
                tap_code(KC_HOME);
                tap_code16(S(KC_END));  // Shift+End
                // Copy
                tap_code16(LCTL(KC_C));
                // Move to end of line, new line, paste
                tap_code(KC_END);
                tap_code(KC_ENT);
                tap_code16(LCTL(KC_V));
            }
            return false;
        
        case DEL_LINE:
            if (record->event.pressed) {
                tap_code(KC_HOME);
                tap_code16(S(KC_END));  // Select to end
                tap_code(KC_DEL);       // Delete selection
            }
            return false;

        case DESK_LEFT:
            if (record->event.pressed) {
                tap_code16(LGUI(LCTL(KC_LEFT)));
            }
            return false;

        case DESK_RIGHT:
            if (record->event.pressed) {
                tap_code16(LGUI(LCTL(KC_RGHT)));
            }
            return false;

        case NEW_DESK:
            if (record->event.pressed) {
                tap_code16(LGUI(LCTL(KC_D)));   // Win+Ctrl+D
            }
            return false;

        case CLOSE_DESK:
            if (record->event.pressed) {
                tap_code16(LGUI(LCTL(KC_F4)));
            }
            return false;

        case MY_MACRO_0:
            if (record->event.pressed) {
                // Enhanced shift detection
                uint8_t mods = get_mods();
                #ifndef NO_ACTION_ONESHOT
                uint8_t shift_mods = (mods | get_oneshot_mods()) & MOD_MASK_SHIFT;
                #else
                uint8_t shift_mods = mods & MOD_MASK_SHIFT;
                #endif
                
                if (shift_mods) {
                    // Send Ñ (uppercase) - Alt+165
                    clear_mods();
                    #ifndef NO_ACTION_ONESHOT
                    clear_oneshot_mods();
                    #endif
                    SEND_STRING(
                        SS_DOWN(X_LALT)
                        SS_TAP(X_KP_1)
                        SS_TAP(X_KP_6)
                        SS_TAP(X_KP_5)
                        SS_UP(X_LALT)
                    );
                    set_mods(mods);
                } else {
                    // Send ñ (lowercase) - Alt+164
                    SEND_STRING(
                        SS_DOWN(X_LALT)
                        SS_TAP(X_KP_1)
                        SS_TAP(X_KP_6)
                        SS_TAP(X_KP_4)
                        SS_UP(X_LALT)
                    );
                }
            }
            return false;
        case MY_MACRO_1:
            SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_DEL) SS_UP(X_LCTL));     // Del next word
            return false;
        case MY_MACRO_2:
            SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_BSPC) SS_UP(X_LCTL));    // Del prev word
            return false;
        case MY_MACRO_3:
            SEND_STRING(SS_LCTL("c"));   // Copy
            return false;
        case MY_MACRO_4:
            SEND_STRING(SS_LCTL("v"));   // Paste
            return false;
        case MY_MACRO_5:
            SEND_STRING(SS_LCTL("a"));   // Select all
            return false;
        case MY_MACRO_6:
            SEND_STRING(SS_LCTL("z"));   // Undo
            return false;
        case MY_MACRO_7:
            SEND_STRING(SS_LCTL("y"));   // Redo
            return false;

        // Emacs-style macros (your existing ones)
        case MY_MACRO_8:
            SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_DOWN(X_LCTL)SS_TAP(X_W)SS_UP(X_LCTL));
            return false;
        case MY_MACRO_9:
            SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_DOWN(X_LSFT)SS_TAP(X_LBRC)SS_UP(X_LSFT));
            return false;
        case MY_MACRO_10:
            SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_DOWN(X_LSFT)SS_TAP(X_RBRC)SS_UP(X_LSFT));
            return false;
        case CD_FIRMWARE:
                SEND_STRING("cd ~/qmk_official" SS_TAP(X_ENTER));
                return false;
        case MAKE_KEYMAP:
                SEND_STRING("make converter/adafruit_rp2040_usbh:my_keymap" SS_TAP(X_ENTER));
                return false;
        case MAKE_CODER:
                SEND_STRING("code ." SS_TAP(X_ENTER));
                return false;
        case WORD1:
                SEND_STRING("MiAng*38");
                return false;
        case WORD2:
                SEND_STRING("ang422Juarez");
                return false;
        case HIGH_CONTRAST:
                if (record->event.pressed) {
                    register_code(KC_LALT);
                    register_code(KC_LSFT);
                    tap_code(KC_PSCR);
                    unregister_code(KC_LSFT);
                    unregister_code(KC_LALT);
                }
                return false;
        
    }


  }

    if (get_mods() & MOD_MASK_SHIFT) {
        switch (keycode) {
            case KC_PMNS:  // NumPad Minus
                if (record->event.pressed) {
                    tap_code(KC_VOLD);  // Volume Down
                }
                return false;  // Don't process the original key
                
            case KC_PPLS:  // NumPad Plus
                if (record->event.pressed) {
                    tap_code(KC_VOLU);  // Volume Up
                }
                return false;
                
            case KC_PAST:  // NumPad Multiply
                if (record->event.pressed) {
                    tap_code(KC_MUTE);  // Mute Toggle
                }
                return false;
                
            default:
                break;
        }
    }

    
    
  return true;
}

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SC_LSPO:
        case SC_RSPC:
        case PWRF_L1:
        case PWRJ_L1:
            return 75;  // Shorter timeout for Space Cadet
        case TD(TD_LAYER_1_2):
        case TD(TD_CAPS_CTRL):
            return 300;  // Standard timeout for tap dances
        default:
            return TAPPING_TERM;
    }
}
#endif

void keyboard_post_init_user(void) {
    autoshift_disable();
}

void housekeeping_task_user(void) {
    static bool num_lock_initialized = false;
    
    if (!num_lock_initialized) {
        led_t led_state = host_keyboard_led_state();
        if (!led_state.num_lock) {
            register_code(KC_NUM);
            unregister_code(KC_NUM);
        } else {
            num_lock_initialized = true;
        }
    }
}

// Helper function to set LED states forcefully
void force_led_state(bool num, bool caps, bool scroll) {
    led_t current = host_keyboard_led_state();
    
    // Toggle Num Lock if needed
    if (current.num_lock != num) {
        register_code(KC_NUM);
        unregister_code(KC_NUM);
    }
    
    // Toggle Caps Lock if needed
    if (current.caps_lock != caps) {
        register_code(KC_CAPS);
        unregister_code(KC_CAPS);
    }
    
    // Toggle Scroll Lock if needed
    if (current.scroll_lock != scroll) {
        register_code(KC_SCRL);
        unregister_code(KC_SCRL);
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = get_highest_layer(state);
    
    switch (layer) {
        case 0:
            // Layer 0: Restore actual states (or all off if you prefer)
            //force_led_state(actual_caps_lock, actual_scroll_lock, false);
            // Or to force all LEDs off on layer 0:
            force_led_state(true, false, false);
            break;
        
        case 1:
            // Layer 1: Caps + Num
            force_led_state(true, true, false);
            break;

        case 2:
            // Layer 2: Num + Scroll
            force_led_state(true, false, true);
            break;

        case 3: 
            // Layer 3: Caps + Num + Scroll
            force_led_state(true, true, true);
            break;

        case 4:
            // Layer 4: Only Caps LED on
            force_led_state(false, true, false);
            break;
        
        case 5:
            // Layer 5: Only Scroll Lock LED and Caps Lock
            force_led_state(false, true, true);
            break;
        
        case 6:
            // Layer 6: Only Scroll Lock LED on
            force_led_state(false, false, true);
            break;

        case 7:
            // Layer 7: Only Scroll Lock LED and Caps Lock
            force_led_state(false, false, false);
            break;

    }
    return state;
}
