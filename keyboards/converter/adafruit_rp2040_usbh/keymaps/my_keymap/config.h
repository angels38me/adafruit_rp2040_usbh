
#pragma once

// Combo settings
#define COMBO_TERM 25
#define COMBO_MUST_HOLD_MODS
#define COMBO_MUST_TAP

// Leader key settings - use conditional define to avoid conflicts
#define LEADER_TIMEOUT 500
#define LEADER_PER_KEY_TIMING


// Space Cadet settings (fix fast typing issues)
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define RETRO_TAPPING

// Tap dance settings
#define TAPPING_FORCE_HOLD
#define QUICK_TAP_TERM 100

// One-shot settings
#define ONESHOT_TIMEOUT 500

// Mouse settings
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_MOVE_DELTA 8
#define MOUSEKEY_MAX_SPEED 10

// Unicode settings (if using unicode features)
//#define UNICODE_SELECTED_MODES UC_WIN

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#ifdef AUTO_SHIFT_ENABLE
    // ---- Timing ----
    #define AUTO_SHIFT_TIMEOUT 150
    // Per-key timing (uncomment to use with get_autoshift_timeout)
    // #define AUTO_SHIFT_TIMEOUT_PER_KEY

    // ---- Allowed with modifiers ----
    // Hold Ctrl+A past timeout => Ctrl+Shift+A
    // Comment out to keep default (dis3411abled with mods)
    #define AUTO_SHIFT_MODIFIERS

    // ---- What NOT to Auto-Shift ----
    // Uncomment any that you want to exclude:
     #define NO_AUTO_SHIFT_ALPHA      // A–Z
    // #define NO_AUTO_SHIFT_NUMERIC    // 0–9
    // #define NO_AUTO_SHIFT_SYMBOLS    // -_=+[]{};:'",<.>/?
    // #define NO_AUTO_SHIFT_TAB        // Tab only
    // #define NO_AUTO_SHIFT_SPECIAL    // Symbols + Tab (superset of the two above)
    // Or explicitly include Enter:
    // #define AUTO_SHIFT_ENTER

    // ---- Repeat behavior ----
    // #define AUTO_SHIFT_REPEAT             // enable shifted key repeat
    // #define AUTO_SHIFT_NO_AUTO_REPEAT     // disable auto-repeat after timeout

    // Per-key gates for repeat behavior (enable and implement functions):
    // #define AUTO_SHIFT_REPEAT_PER_KEY
    // #define AUTO_SHIFT_NO_AUTO_REPEAT_PER_KEY

    // ---- Setup helpers (for tuning) ----
    // Map AS_UP / AS_DOWN / AS_RPT in your keymap to tune timeout.
    // After tuning, lock out setup behavior:
    // #define AUTO_SHIFT_NO_SETUP
#endif