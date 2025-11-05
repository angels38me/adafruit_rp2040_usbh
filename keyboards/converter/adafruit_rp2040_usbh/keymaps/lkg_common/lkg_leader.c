#include "lkg_km_common.h"
#include "lkg_leader.h"

#ifdef LEADER_ENABLE

static uint8_t leader_previous_layer = 0;

void leader_start_user(void) {
    #ifdef CONSOLE_ENABLE
    uprintf("Leader key activated!\n");
    #endif
    
    // Store the current layer before switching
    leader_previous_layer = get_highest_layer(layer_state);
    
    // Temporarily switch to layer 0 for leader sequences
    // This ensures all leader keys use layer 0 mappings
    layer_clear();
    layer_on(0);
}

void leader_end_user(void) {
    #ifdef CONSOLE_ENABLE
    uprintf("Leader sequence ended\n");
    #endif
    
    // ========================================
    // LAYER SWITCHING - Single key
    // ========================================
    if (LEADER_LAYER_1) {
        layer_move(1);  // Switch to layer 1
        return;  // Don't restore previous layer
    }
    
    if (LEADER_LAYER_2) {
        layer_move(2);  // Switch to layer 2
        return;  // Don't restore previous layer
    }
    
    if (LEADER_LAYER_3) {
        layer_move(3);  // Switch to layer 3
        return;  // Don't restore previous layer
    }
    
    if (LEADER_LAYER_4) {
        layer_move(4);  // Switch to layer 4
        return;  // Don't restore previous layer
    }
    
    if (LEADER_LAYER_5) {
        layer_move(5);  // Switch to layer 4
        return;  // Don't restore previous layer
    }
    
    if (LEADER_LAYER_6) {
        layer_move(6);  // Switch to layer 4
        return;  // Don't restore previous layer
    }
    
    if (LEADER_LAYER_7) {
        layer_move(7);  // Switch to layer 4
        return;  // Don't restore previous layer
    }
    
    if (LEADER_LAYER_0) {
        layer_move(0);  // Stay on layer 0
        return;  // Don't restore previous layer
    }
    
    // ========================================
    // EMAIL ADDRESSES - E + key
    // ========================================
    if (LEADER_EMAIL_1) {
        SEND_STRING("dispatchamerilink@gmail.com");
        // Fall through to restore layer
    }
    else if (LEADER_EMAIL_2) {
        SEND_STRING("maherrera@stacruzlog.com");
    }

    else if (LEADER_EMAIL_3) {
        SEND_STRING("angels38me@gmail.com");
    }
    
    // ========================================
    // SIGNATURES - S + key
    // ========================================
    else if (LEADER_SIG_FORMAL) {
        SEND_STRING("Best regards,\nMiguel Herrera");
    }
    else if (LEADER_SIG_CASUAL) {
        SEND_STRING("Thanks,\nMiguel");
    }
    else if (LEADER_SIG_VERY_FORMAL) {
        SEND_STRING("Sincerely,\nMiguel Herrera");
    }
    
    // ========================================
    // COMMON PHRASES - P + key
    // ========================================
    else if (leader_sequence_two_keys(KC_P, KC_1)) {
        SEND_STRING("Thank you!");
    }
    else if (leader_sequence_two_keys(KC_P, KC_2)) {
        SEND_STRING("You're welcome!");
    }
    else if (leader_sequence_two_keys(KC_P, KC_3)) {
        SEND_STRING("No problem!");
    }
    else if (leader_sequence_two_keys(KC_P, KC_4)) {
        SEND_STRING("Looking forward to hearing from you.");
    }
    
    // ========================================
    // ADDRESSES - A + key
    // ========================================
    else if (leader_sequence_two_keys(KC_A, KC_1)) {
        SEND_STRING("1477 Lomaland Dr. Ste. D10 El Paso, TX 79935");
    }
    else if (leader_sequence_two_keys(KC_A, KC_2)) {
        SEND_STRING("14703 Cassidy Dr. El Paso, TX 79938");
    }
    
    // ========================================
    // PROGRAMMING - C + key (Code snippets)
    // ========================================
    else if (leader_sequence_two_keys(KC_C, KC_1)) {
        SEND_STRING("if () {\n\n}" SS_TAP(X_UP) SS_TAP(X_TAB));
    }
    else if (leader_sequence_two_keys(KC_C, KC_2)) {
        SEND_STRING("for (int i = 0; i < ; i++) {\n\n}");
        tap_code(KC_UP);
        tap_code(KC_END);
        for(int i = 0; i < 8; i++) {
            tap_code(KC_LEFT);
        }
    }
    else if (leader_sequence_two_keys(KC_C, KC_3)) {
        SEND_STRING("while () {\n\n}" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_END) SS_TAP(X_LEFT));
    }
    else if (leader_sequence_two_keys(KC_C, KC_4)) {
        SEND_STRING("function () {\n\n}" SS_TAP(X_UP) SS_TAP(X_TAB));
    }
    
    // ========================================
    // DATES & TIMES - D + key
    // ========================================
    else if (leader_sequence_two_keys(KC_D, KC_1)) {
        SEND_STRING("11/04/2025");
    }
    else if (leader_sequence_two_keys(KC_D, KC_2)) {
        SEND_STRING("2025-11-04");
    }
    
    // ========================================
    // WINDOW MANAGEMENT - W + key
    // ========================================
    else if (leader_sequence_two_keys(KC_W, KC_1)) {
        tap_code16(LGUI(KC_1));
    }
    else if (leader_sequence_two_keys(KC_W, KC_2)) {
        tap_code16(LGUI(KC_2));
    }
    else if (leader_sequence_two_keys(KC_W, KC_3)) {
        tap_code16(LGUI(KC_3));
    }
    else if (leader_sequence_two_keys(KC_W, KC_M)) {
        tap_code16(LGUI(KC_M));
    }
    else if (leader_sequence_two_keys(KC_W, KC_C)) {
        tap_code16(LALT(KC_F4));
    }
    
    // ========================================
    // SPECIAL CHARACTERS - X + key
    // ========================================
    else if (leader_sequence_two_keys(KC_X, KC_1)) {
        SEND_STRING("()" SS_TAP(X_LEFT));
    }
    else if (leader_sequence_two_keys(KC_X, KC_2)) {
        SEND_STRING("[]" SS_TAP(X_LEFT));
    }
    else if (leader_sequence_two_keys(KC_X, KC_3)) {
        SEND_STRING("{}" SS_TAP(X_LEFT));
    }
    else if (leader_sequence_two_keys(KC_X, KC_4)) {
        SEND_STRING("\"\"" SS_TAP(X_LEFT));
    }
    else if (leader_sequence_two_keys(KC_X, KC_5)) {
        SEND_STRING("''" SS_TAP(X_LEFT));
    }
    
    // ========================================
    // GIT COMMANDS - G + key
    // ========================================
    else if (LEADER_GIT_STATUS) {
        SEND_STRING("git status\n");
    }
    else if (LEADER_GIT_ADD) {
        SEND_STRING("git add .");
    }
    else if (LEADER_GIT_COMMIT) {
        SEND_STRING("git commit -m \"\"" SS_TAP(X_LEFT));
    }
    else if (LEADER_GIT_PUSH) {
        SEND_STRING("git push");
    }
    else if (LEADER_GIT_PULL) {
        SEND_STRING("git pull");
    }
    
    // ========================================
    // QUICK LAUNCHERS - Q + key
    // ========================================
    else if (leader_sequence_two_keys(KC_Q, KC_T)) {
        tap_code16(LCTL(LALT(KC_T)));
    }
    else if (leader_sequence_two_keys(KC_Q, KC_B)) {
        tap_code16(LCTL(LALT(KC_B)));
    }
    else if (leader_sequence_two_keys(KC_Q, KC_E)) {
        tap_code16(LCTL(LALT(KC_E)));
    }
    
    // ========================================
    // UNICODE/SPECIAL - U + key
    // ========================================
    else if (leader_sequence_two_keys(KC_U, KC_N)) {
        SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_4) SS_UP(X_LALT));
    }
    else if (leader_sequence_two_keys(KC_U, KC_A)) {
        SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_0) SS_UP(X_LALT));
    }
    else if (leader_sequence_two_keys(KC_U, KC_E)) {
        SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_KP_1) SS_TAP(X_KP_3) SS_TAP(X_KP_0) SS_UP(X_LALT));
    }
    else if (leader_sequence_two_keys(KC_U, KC_I)) {
        SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_1) SS_UP(X_LALT));
    }
    else if (leader_sequence_two_keys(KC_U, KC_O)) {
        SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_2) SS_UP(X_LALT));
    }
    else if (leader_sequence_two_keys(KC_U, KC_U)) {
        SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_3) SS_UP(X_LALT));
    }
    
    // ========================================
    // RESTORE PREVIOUS LAYER (if no layer switch was requested)
    // ========================================
    // If we get here, no layer switch was requested, so restore the previous layer
    else {
        // Restore the layer we were on before leader key
        layer_move(leader_previous_layer);
    }
}

#endif // LEADER_ENABLE