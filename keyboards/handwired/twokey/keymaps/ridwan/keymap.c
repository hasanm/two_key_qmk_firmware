#include QMK_KEYBOARD_H

#define GREEN_LED B6
#define RED_LED B7

enum custom_keycodes {
  MY_KEY = SAFE_RANGE,
  MY_SHIFT_KEY
};


enum {
  TAPDANCE_1 = 0,
  TAPDANCE_2
};

enum {
  MACRO_1 = 0,
  MACRO_2
};


// Macro Definitions
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {

    // for basic strings
  case MACRO_1: {
    if (record->event.pressed) {
      SEND_STRING("YOUR_STRING_HERE"); // REPLACE with what you want your macro to be
      return false;
    }
  }

    // for more complex macros (want to add modifiers, etc.)
  case MACRO_2: {
    if (record->event.pressed) {
      // INSERT CODE HERE for your macro. See full documentation for details and functions
    }
  }


    //
  }
  return MACRO_NONE;
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // LAYOUT_ortho_1x2(KC_GRV, MY_KEY)
  // LAYOUT_ortho_1x2(KC_MS_BTN2, MY_KEY)
  LAYOUT_ortho_1x2(KC_MS_BTN1, KC_MS_BTN2)  
};

bool process_record_user (uint16_t keycode, keyrecord_t *record) {
  // static int status = 0; 
  switch(keycode) {
  case MY_KEY:
    if (record->event.pressed) {
       // if (status ==0) {
       //   status = 1;
       //   unregister_code(KC_LCTL);
       //   writePinHigh(GREEN_LED);
       //   writePinLow(RED_LED);
       // } else {
       //   status = 0;
       //   register_code(KC_LCTL);
       //   writePinLow(GREEN_LED);
       //   writePinHigh(RED_LED);
       // }
      // SEND_STRING(SS_LSFT(""));
      register_code(KC_LSFT);
      register_code(KC_MS_BTN2);
      unregister_code(KC_MS_BTN2);
      unregister_code(KC_LSFT);
    }
    return false;
  }
  return true; 
}


void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.

  // Set our LED pins as output
  // setPinOutput(GREEN_LED);
  // setPinOutput(RED_LED);

  // writePinHigh(GREEN_LED);
  // writePinLow(RED_LED);
}
