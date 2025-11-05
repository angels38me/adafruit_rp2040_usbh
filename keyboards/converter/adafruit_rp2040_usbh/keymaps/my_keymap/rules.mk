
EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = yes
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
NKRO_ENABLE = yes
UNICODE_ENABLE = yes
AUTO_SHIFT_ENABLE = yes
CONSOLE_ENABLE = yes
CAPS_WORD_ENABLE = yes
LEADER_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
MOUSEKEY_ENABLE = yes
ONE_SHOT_ENABLE = yes

VPATH += keyboards/converter/adafruit_rp2040_usbh/keymaps/lkg_common

SRC += ../lkg_common/lkg_tap_dances.c
SRC += ../lkg_common/lkg_key_process.c
SRC += ../lkg_common/lkg_leader.c        # Add this line

