#include QMK_KEYBOARD_H

enum custom_keycodes {
  UP_URL = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_4x4(
        KC_7,       KC_8,       KC_9,    TG(1),
        KC_4,       KC_5,       KC_6,    TG(2),
        KC_1,       KC_2,       KC_3,    KC_LALT,
        KC_MS_BTN1, KC_MS_BTN2, KC_LSFT, KC_LCTRL
    ),

    [1] = LAYOUT_ortho_4x4(
        KC_F17,  KC_F18,  KC_F18,  KC_TRNS,
        KC_F14,  KC_F15,  KC_F16,  KC_TRNS,
        KC_TRNS, KC_TRNS, KC_F13,  KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [2] = LAYOUT_ortho_4x4(
        KC_SLASH, KC_Q,    KC_W,    KC_E,
        KC_DOT,   KC_Q,    KC_W,    KC_E,
        KC_L,     KC_Q,    KC_W,    KC_E,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [3] = LAYOUT_ortho_4x4(
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS
    ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case UP_URL:
            if (record->event.pressed) {
                SEND_STRING("http://1upkeyboards.com");
            }
            return false;
            break;
    }
    return true;
}

#ifdef ENCODER_ENABLE
#include "encoder.h"
void encoder_update_user(int8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  }
}
#endif
