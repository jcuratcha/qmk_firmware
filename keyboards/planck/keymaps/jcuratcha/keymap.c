#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _SYMBOL,
  _NUMBER,
  _FUNCTION,
  _NAVIGATE,
  _ADJUST
};

enum planck_keycodes {
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
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Nav  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |RShift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | Func | Sym  |    Space    | No   | Nav  | Ctrl | Alt  | Enter|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,   KC_Q,    KC_W,    KC_E,     KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,     KC_O,   KC_P,    KC_BSPC},
  {NAVIGATE, KC_A,    KC_S,    KC_D,     KC_F,   KC_G,   KC_H,   KC_J,   KC_K,     KC_L,   KC_SCLN, KC_QUOT},
  {KC_LSFT,  KC_Z,    KC_X,    KC_C,     KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT},
  {KC_LCTL,  KC_LGUI, KC_LALT, FUNCTION, SYMBOL, KC_SPC, KC_SPC, NUMBER, NAVIGATE, KC_APP, KC_RCTL, KC_ENT}
},

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |RShift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | Func | Sym  |    Space    | No   | Nav  | Alt  | Ctrl | Enter|
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
  {KC_TAB,   KC_Q,    KC_W,    KC_F,     KC_P,   KC_G,   KC_J,   KC_L,   KC_U,     KC_Y,    KC_SCLN, KC_BSPC},
  {NAVIGATE, KC_A,    KC_R,    KC_S,     KC_T,   KC_D,   KC_H,   KC_N,   KC_E,     KC_I,    KC_O,    KC_QUOT},
  {KC_LSFT,  KC_Z,    KC_X,    KC_C,     KC_V,   KC_B,   KC_K,   KC_M,   KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT},
  {KC_LCTL,  KC_LGUI, KC_LALT, FUNCTION, SYMBOL, KC_SPC, KC_SPC, NUMBER, NAVIGATE, KC_RCTL, KC_RALT, KC_ENT}
},

/* Symbol
 * ,-----------------------------------------------------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   ~  |   |  |   '  |   "  |      |      |   -  |   _  |   {  |   }  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |   [  |   ]  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOL] = {
  {_______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______},
  {_______, KC_TILD, KC_PIPE, KC_DQUO, KC_QUOT, _______, _______, KC_MINS, KC_UNDS, KC_LCBR, KC_RCBR, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Number
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   `  |   \  |   '  |   "  |      |      |   -  |   _  |   =  |   +  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   *  |   ,  |   .  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMBER] = {
  {_______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______},
  {_______, KC_GRV,  KC_BSLS, KC_DQUO, KC_QUOT, _______, _______, KC_MINS, KC_UNDS, KC_EQL,  KC_PLUS, _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_ASTR, KC_COMM, KC_DOT,  KC_SLSH, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Function
 * ,-----------------------------------------------------------------------------------.
 * | Esc  | Caps | Num  | LED  | PrSc | Scrl |Pause |      |      |      | Del  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      | Vol- | Vol+ |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTION] = {
  {KC_ESC,  KC_CAPS, KC_NLCK, BACKLIT, KC_PSCR, KC_SLCK, KC_PAUS, _______, _______, _______, KC_DEL,  _______},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______},
  {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, KC_VOLD, KC_VOLU, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Navigate
 * ,-----------------------------------------------------------------------------------.
 * | Esc  | PgUp | Home | Up   | End  |      | PgUp | Home | Up   | End  | Del  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | PgDn | Left | Down | Right|      | PgDn | Left | Down | Right| Ins  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      | Vol- | Vol+ |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAVIGATE] = {
  {KC_ESC,  KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_DEL,  _______},
  {_______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS,  _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Adjust (Symbol + Number)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {XXXXXXX, RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
}
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