#pragma once

#ifdef LEADER_ENABLE

// Leader key function declarations
void leader_start_user(void);
void leader_end_user(void);

// Optional: Define leader sequence macros for readability
#define LEADER_LAYER_1 leader_sequence_one_key(KC_1)
#define LEADER_LAYER_2 leader_sequence_one_key(KC_2)
#define LEADER_LAYER_3 leader_sequence_one_key(KC_3)
#define LEADER_LAYER_4 leader_sequence_one_key(KC_4)
#define LEADER_LAYER_5 leader_sequence_one_key(KC_5)
#define LEADER_LAYER_6 leader_sequence_one_key(KC_6)
#define LEADER_LAYER_7 leader_sequence_one_key(KC_7)
#define LEADER_LAYER_0 leader_sequence_one_key(KC_0)

// Email shortcuts
#define LEADER_EMAIL_1 leader_sequence_two_keys(KC_E, KC_1)
#define LEADER_EMAIL_2 leader_sequence_two_keys(KC_E, KC_2)
#define LEADER_EMAIL_3 leader_sequence_two_keys(KC_E, KC_3)

// Signature shortcuts
#define LEADER_SIG_FORMAL leader_sequence_two_keys(KC_S, KC_1)
#define LEADER_SIG_CASUAL leader_sequence_two_keys(KC_S, KC_2)
#define LEADER_SIG_VERY_FORMAL leader_sequence_two_keys(KC_S, KC_3)

// Git command shortcuts
#define LEADER_GIT_STATUS leader_sequence_two_keys(KC_G, KC_S)
#define LEADER_GIT_ADD leader_sequence_two_keys(KC_G, KC_A)
#define LEADER_GIT_COMMIT leader_sequence_two_keys(KC_G, KC_C)
#define LEADER_GIT_PUSH leader_sequence_two_keys(KC_G, KC_P)
#define LEADER_GIT_PULL leader_sequence_two_keys(KC_G, KC_L)

#endif // LEADER_ENABLE