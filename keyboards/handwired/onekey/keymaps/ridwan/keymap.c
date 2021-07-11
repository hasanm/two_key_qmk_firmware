#include QMK_KEYBOARD_H

#define GREEN_LED B6
#define RED_LED B7

enum custom_keycodes {
  MY_KEY = SAFE_RANGE
}; 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  LAYOUT_ortho_1x1(KC_MS_BTN1)
};

bool process_record_user (uint16_t keycode, keyrecord_t *record) {
  static int status = 0; 
  switch(keycode) {
  case MY_KEY:
    if (record->event.pressed) {
      /* SEND_STRING("Mahmudul Hasan"); */
      if (status ==0) {
        status = 1;
        unregister_code(KC_LALT);
        writePinHigh(GREEN_LED);
        writePinLow(RED_LED);
      } else {
        status = 0;
        register_code(KC_LALT);
        writePinLow(GREEN_LED);
        writePinHigh(RED_LED);
      } 
    }
    return false;
    break;
  }
  return true; 
}


void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.

  // Set our LED pins as output
  setPinOutput(GREEN_LED);
  setPinOutput(RED_LED);

  writePinHigh(GREEN_LED);
  writePinLow(RED_LED);
}
