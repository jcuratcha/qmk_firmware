/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _COLEMAK,
  _SYMBOL,
  _NUMBER,
  _FUNCTION,
  _NAVIGATE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  SYMBOL,
  NUMBER,
  FUNCTION,
  NAVIGATE,
  BACKLIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Nav  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |RShift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Mute | GUI  | Alt  | Func | Sym  |    Space    | No   | Nav  | Ctrl | Alt  | Enter|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid( \
  KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,     KC_7,   KC_8,     KC_9,    KC_0,    KC_BSPC,  \
  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,     KC_U,   KC_I,     KC_O,    KC_P,    KC_DEL,   \
  NAVIGATE, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,     KC_J,   KC_K,     KC_L,    KC_SCLN, KC_QUOT,  \
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,   KC_N,     KC_M,   KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT,  \
  KC_MUTE,  KC_LCTL, KC_LGUI, KC_LALT, SYMBOL, KC_SPC, NAVIGATE, NUMBER, FUNCTION, KC_RCTL, KC_RALT, KC_ENT    \
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |RShift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Mute | GUI  | Alt  | Func | Sym  |    Space    | No   | Nav  | Alt  | Ctrl | Enter|
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_preonic_grid( \
  KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,     KC_7,   KC_8,     KC_9,    KC_0,    KC_BSPC,   \
  KC_TAB,   KC_Q,    KC_W,    KC_F,    KC_P,   KC_G,   KC_J,     KC_L,   KC_U,     KC_Y,    KC_SCLN, KC_DEL,  \
  NAVIGATE, KC_A,    KC_R,    KC_S,    KC_T,   KC_D,   KC_H,     KC_N,   KC_E,     KC_I,    KC_O,    KC_QUOT,  \
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,   KC_K,     KC_M,   KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT,  \
  KC_MUTE,  KC_LCTL, KC_LGUI, KC_LALT, SYMBOL, KC_SPC, NAVIGATE, NUMBER, FUNCTION, KC_RCTL, KC_RALT, KC_ENT    \
),

/* Symbol
 * ,-----------------------------------------------------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   ~  |   |  |   '  |   "  |      |      |   -  |   _  |  {   |   }  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |   [  |   ]  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOL] = LAYOUT_preonic_grid ( \
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
  _______, KC_TILD, KC_PIPE, KC_DQUO, KC_QUOT, _______, _______, KC_MINS, KC_UNDS, KC_LCBR, KC_RCBR, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Number
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   `  |   \  |   '  |   "  |      |      |   -  |   _  |   =  |   +  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   *  |   ,  |   .  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMBER] = LAYOUT_preonic_grid ( \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,  \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,  \
  _______, KC_GRV,  KC_BSLS, KC_DQUO, KC_QUOT, _______, _______, KC_MINS, KC_UNDS, KC_EQL,  KC_PLUS, _______,  \
  _______, _______, _______, _______, _______, _______, _______, KC_ASTR, KC_COMM, KC_DOT,  KC_SLSH, _______,  \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______   \
),

/* Function (no transparent alphas)
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Caps | Num  | LED  |      |      |      |      |      |  F11 |  F12 |      |
 * |------+------+------+----- +------+-------------+------+------+------+------+------|
 * |      | PrSc | Scrl |Pause |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      | Vol- | Vol+ |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |MedPly|      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTION] = LAYOUT_preonic_grid ( \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
  _______, KC_CAPS, KC_NLCK, BACKLIT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F11,  KC_F12,  _______, \
  _______, KC_PSCR, KC_SLCK, KC_PAUS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, _______, \
  KC_MPLY, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Navigate (no transparent alphas)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | PgUp | Home | Up   | End  |      | PgUp | Home | Up   | End  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | PgDn | Left | Down | Right|      | PgDn | Left | Down | Right| Ins  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      | Vol- | Vol+ |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAVIGATE] = LAYOUT_preonic_grid ( \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
  _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  XXXXXXX, KC_PGUP, KC_HOME, KC_UP,   KC_END,  XXXXXXX, _______, \
  _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS,  _______, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Adjust (Sym + Num) (no transparent alphas)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Reset |Debug |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|MusMod|Mus on|MusOff|MidiOn|MidOff|      | Vol- | Vol+ |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid( \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
  _______, RESET,   DEBUG,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
  _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
  _______, MUV_DE,  MUV_IN,  MU_MOD,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  XXXXXXX, KC_VOLD, KC_VOLU, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case FUNCTION:
      if (record->event.pressed) {
        layer_on(_FUNCTION);
      } else {
        layer_off(_FUNCTION);
      }
      return false;
      break;
    case NAVIGATE:
      if (record->event.pressed) {
        layer_on(_NAVIGATE);
      } else {
        layer_off(_NAVIGATE);
      }
      return false;
      break;
    case SYMBOL:
      if (record->event.pressed) {
        layer_on(_SYMBOL);
        update_tri_layer(_SYMBOL, _NUMBER, _ADJUST);
      } else {
        layer_off(_SYMBOL);
        update_tri_layer(_SYMBOL, _NUMBER, _ADJUST);
      }
      return false;
      break;
    case NUMBER:
      if (record->event.pressed) {
        layer_on(_NUMBER);
        update_tri_layer(_SYMBOL, _NUMBER, _ADJUST);
      } else {
        layer_off(_NUMBER);
        update_tri_layer(_SYMBOL, _NUMBER, _ADJUST);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
  }
  return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
  if (IS_LAYER_ON(_NAVIGATE)) {
    if (clockwise)
      tap_code(KC_WH_U);
    else
      tap_code(KC_WH_D);
  }
  else if (IS_LAYER_ON(_FUNCTION))
  {
    if (clockwise)
      tap_code(KC_MNXT);
    else
      tap_code(KC_MPRV);
  }
  else
  {
    if (clockwise)
      tap_code(KC_VOLU);
    else
      tap_code(KC_VOLD);
  }
}

void dip_update(uint8_t index, bool active) { }

void matrix_scan_user(void) { }

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case NUMBER:
    case SYMBOL:
      return false;
    default:
      return true;
  }
}
