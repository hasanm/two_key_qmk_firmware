#include QMK_KEYBOARD_H

enum custom_keycodes {
  UP_URL = SAFE_RANGE,
  C_LAYER_SWITCH
};

enum {
  BASE_LAYER = 0,
  CONTROL_LAYER,
  FUNCTION_LAYER,
  CONTROL_ALT_LAYER,
  CONTROL_SHIFT_LAYER,
  BUILD_LAYER
} ;

enum {
  MACRO_1 = 0
}; 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE_LAYER] = LAYOUT_ortho_4x4(
        C_LAYER_SWITCH, KC_F17,     KC_F18,     KC_F19,
        KC_LSFT,        KC_F24,     KC_F15,     KC_F16,
        KC_LALT,        KC_F21,     KC_F22,     KC_F23,
        KC_LCTRL,       KC_MS_BTN1, KC_MS_BTN2, KC_F20
    ),
    [CONTROL_LAYER] = LAYOUT_ortho_4x4(
        KC_TRNS, LCTL(KC_7), LCTL(KC_8), LCTL(KC_9),
        KC_TRNS, LCTL(KC_4), LCTL(KC_5), LCTL(KC_6),   
        KC_TRNS, LCTL(KC_1), LCTL(KC_2), LCTL(KC_3),
        KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS
    ),

    [FUNCTION_LAYER] = LAYOUT_ortho_4x4(
        KC_TRNS, KC_F17,  KC_F18,  KC_F19,  
        KC_TRNS, KC_F24,  KC_F15,  KC_F16,  
        KC_TRNS, KC_F21,  KC_F22,  KC_F23,  
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [CONTROL_ALT_LAYER] = LAYOUT_ortho_4x4(
        KC_TRNS, LCA(KC_7), LCA(KC_8), LCA(KC_9),                    
        KC_TRNS, LCA(KC_4), LCA(KC_5), LCA(KC_6),            
        KC_TRNS, LCA(KC_1), LCA(KC_2), LCA(KC_3),    
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS
    ),

    [CONTROL_SHIFT_LAYER] = LAYOUT_ortho_4x4(
        KC_TRNS, RCS(KC_7), RCS(KC_8), RCS(KC_9),                    
        KC_TRNS, RCS(KC_4), RCS(KC_5), RCS(KC_6),            
        KC_TRNS, RCS(KC_1), RCS(KC_2), RCS(KC_3),    
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS
    ),    

    [BUILD_LAYER] = LAYOUT_ortho_4x4(
        KC_TRNS, KC_Q,             KC_W,    KC_TRNS,
        KC_TRNS, KC_D,             KC_F,    KC_TRNS,
        KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,
        KC_TRNS, LSFT(KC_MS_BTN1), KC_TRNS, KC_TRNS
    ),

    [6] = LAYOUT_ortho_4x4(
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS
    ),

    [7] = LAYOUT_ortho_4x4(
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS
    ),

    [8] = LAYOUT_ortho_4x4(
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS
    ),

    [9] = LAYOUT_ortho_4x4(
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS
    )

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint8_t status = 0; 
  switch (keycode) {
        case UP_URL:
          if (record->event.pressed) {
            SEND_STRING("http://1upkeyboards.com");
          }
          return false;
          break;
        case C_LAYER_SWITCH:
          if (record->event.pressed) {
            SEND_STRING("New String");
            status = (status + 1) % 3;
            layer_move(status); 
            
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
