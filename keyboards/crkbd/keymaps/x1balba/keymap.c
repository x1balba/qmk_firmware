/* Copyright 2021 x1balba
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _GAMEPAD
};

// Custom keycodes for layer keys
// Dual function escape with left control
#define CTL_ESC LCTL_T(KC_ESC)
#define SFT_BSP LSFT_T(KC_BSPC)
#define SFT_SPC LSFT_T(KC_SPC)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  RGBRST
};

#define GAMEPAD TG(_GAMEPAD)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------.                  ,-----------------------------------------------.
     KC_TAB,   KC_Q,   KC_W,   KC_E,  KC_R,   KC_T,                       KC_Y,   KC_U,   KC_I,   KC_O,  KC_P,  KC_DEL,
  //|-------+-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------+-------|
     KC_LCTL,  KC_A,   KC_S,   KC_D,   KC_F,  KC_G,                       KC_H,   KC_J,   KC_K,   KC_L, KC_SCLN,KC_QUOT,
  //|-------+-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------+-------|
     GAMEPAD,  KC_Z,    KC_X,  KC_C,    KC_V,  KC_B,                      KC_N,  KC_M,  KC_COMM, KC_DOT,KC_SLSH, KC_ENT,
  //|-------+-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------+-------|
                                     CTL_ESC,KC_LALT,SFT_BSP,   SFT_SPC, LOWER,  RAISE
  //                                `-----------------------'  `-----------------------'
  ),

  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------.                  ,-----------------------------------------------.
     KC_ESC,  KC_1, KC_2,   KC_3,   KC_4,   KC_5,                        KC_6,   KC_7,   KC_8,   KC_9,   KC_0,  KC_BSPC,
  //|-------+-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------+-------|
     _______,KC_MINS, KC_EQL,KC_LBRC,KC_RBRC,KC_BSLS,                    KC_GRV,KC_LEFT,KC_DOWN, KC_UP, KC_RGHT,KC_DQUO,
  //|-------+-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------+-------|
      KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,                     KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,
  //|-------+-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------+-------|
                                     _______,_______,_______,   _______,_______,_______
  //                                `-----------------------'  `-----------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------.                  ,-----------------------------------------------.
     KC_ESC, KC_EXLM, KC_AT, KC_HASH, KC_DLR,KC_PERC,                   KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_BSPC,
  //|-------+-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------+-------|
     KC_LCTL,KC_UNDS,KC_PLUS,KC_LCBR,KC_RCBR,KC_PIPE,                   KC_TILD,KC_LEFT,KC_DOWN, KC_UP, KC_RGHT, KC_GRV,
  //|-------+-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------+-------|
     _______, KC_ESC,KC_LGUI,KC_LALT,KC_CAPS,KC_DQUO,                   KC_HOME, KC_END,KC_PGUP,KC_PGDN,KC_PSCR,RSFT_T(KC_SPC),
  //|-------+-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------+-------|
                                     _______,_______,_______,   _______,_______,_______
  //                                `-----------------------'  `-----------------------'
  ),

  [_GAMEPAD] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------.                  ,-----------------------------------------------.
     XXXXXXX, KC_5,   KC_6,   KC_7,    KC_8, KC_S,                      XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
  //|-------+-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------+-------|
     XXXXXXX, KC_1,   KC_2,    KC_3,   KC_4, KC_A,                      XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
  //|-------+-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------+-------|
     XXXXXXX, KC_9,   KC_0,  KC_MINS, KC_EQL,XXXXXXX,                   XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,GAMEPAD,
  //|-------+-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------+-------|
                                     _______,_______,SFT_SPC,   _______,  KC_M,   KC_B
  //                                `-----------------------'  `-----------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------.                  ,-----------------------------------------------.
     RESET,  RGBRST,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                     KC_NO,KC__MUTE, KC_NO,  KC_NO,  KC_NO,  KC_NO,
  //|-------+-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------+-------|
    RGB_TOG,RGB_HUI,RGB_SAI,RGB_VAI,RGB_SPI,KC_NO,                      KC_PAUSE,KC__VOLUP, KC_NO, KC_NO, KC_NO, KC_NO,
  //|-------+-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------+-------|
    RGB_MOD,RGB_HUD,RGB_SAD,RGB_VAD,RGB_SPD,KC_NO,                      KC_SCROLLLOCK,KC__VOLDOWN,KC_NO,KC_NO,KC_NO,RGB_RMOD,
  //|-------+-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------+-------|
                                     _______,_______,_______,   _______,_______,_______
  //                                `-----------------------'  `-----------------------'
  )
};

int RGB_current_mode;

// Setting ADJUST layer when both lower and raise are held
void update_tri_layer_ADJ(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_ADJ(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_ADJ(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_ADJ(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_ADJ(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      #ifdef RGB_MATRIX_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgb_matrix_default();
          rgb_matrix_enable();
        }
      #endif
      break;
  }
  return true;
}

#ifdef RGB_MATRIX_ENABLE


void rgb_matrix_indicators_user(void) {
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case _RAISE:
            rgb_matrix_set_color_all(RGB_RED);
            break;
        case _LOWER:
            rgb_matrix_set_color_all(RGB_BLUE);
            break;
        case _GAMEPAD:
            rgb_matrix_set_color_all(RGB_GREEN);
            break;
        default:
            break;
    }
}


/*
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i <= led_max; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case _RAISE:
                rgb_matrix_set_color(i, RGB_BLUE);
                break;
            case _LOWER:
                rgb_matrix_set_color(i, RGB_YELLOW);
                break;
            case _GAMEPAD:
                rgb_matrix_set_color(i, RGB_GREEN);
                break;
            default:
                break;
        }
    }
}
*/

// Turn RGB Matrix off on suspend
void suspend_power_down_user(void) {
    rgb_matrix_set_suspend_state(true);
}

// Turn RGB Matrix on on wake
void suspend_wakeup_init_user(void) {
    rgb_matrix_set_suspend_state(false);
}

#endif
