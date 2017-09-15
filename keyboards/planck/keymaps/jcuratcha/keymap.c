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
  _MOUSE,
  _PLOVER,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  PLOVER,
  MOUSE,
  SYMBOL,
  NUMBER,
  FUNCTION,
  NAVIGATE,
  BACKLIT,
  EXT_PLV
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Nav  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |RShift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | Func | Sym  |    Space    | No   | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 * NOTE: LShift and RShift are Shift when held, '(' and ')' respectively when held (Space Cadet)
 */
[_QWERTY] = {
  {KC_TAB,   KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {NAVIGATE, KC_A,    KC_S,    KC_D,     KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT },
  {KC_LSPO,  KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC},
  {KC_LCTL,  KC_LGUI, KC_LALT, FUNCTION, SYMBOL,  KC_SPC,  KC_SPC,  NUMBER,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Nav  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |RShift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | Func | Sym  |    Space    | No   | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
  {KC_TAB,   KC_Q,    KC_W,    KC_F,     KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC},
  {NAVIGATE, KC_A,    KC_R,    KC_S,     KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT },
  {KC_LSPO,  KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC},
  {KC_LCTL,  KC_LGUI, KC_LALT, FUNCTION, SYMBOL,  KC_SPC,  KC_SPC,  NUMBER,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Symbol
 * ,-----------------------------------------------------------------------------------.
 * |      |   ~  |   |  |   '  |   "  |      |      |      |      |   {  |   }  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |   [  |   ]  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOL] = {
  {_______, KC_TILD, KC_PIPE, KC_QUOT, KC_DQUO, _______, _______, _______, _______, KC_LCBR, KC_RCBR, _______},
  {_______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Number
 * ,-----------------------------------------------------------------------------------.
 * |      |   `  |   \  |      |      |      |      |   -  |   _  |   =  |   +  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   *  |   ,  |   .  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMBER] = {
  {_______, KC_GRV,  KC_BSLS, _______, _______, _______, _______, KC_MINS, KC_UNDS, KC_EQL,  KC_PLUS, _______},
  {_______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______},
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
 * NOTE: Pressing Ctrl, Alt or GUI will result in the Right-side variant being invoked
 *  (on any other layer, the left side modifiers are invoked)
 */
[_FUNCTION] = {
  {KC_ESC,  KC_CAPS, KC_NLCK, BACKLIT, KC_PSCR, KC_SLCK, KC_PAUS, _______, _______, _______, KC_DEL,  _______},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______},
  {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, KC_VOLD, KC_VOLU, _______},
  {KC_RCTL, KC_RGUI, KC_RALT, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Navigate
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |      |      |      |      |      | PgUp | Home | Up   | End  | Del  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      | PgDn | Left | Down | Right| Ins  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      | Vol- | Vol+ |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAVIGATE] = {
  {KC_ESC,  _______, _______, _______, _______, _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_DEL,  _______},
  {_______, _______, _______, _______, _______, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS,  _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_PLOVER] = {
  {KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   },
  {XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC},
  {XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX}
},

/* Adjust (Symbol + Number)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Plover|      | Mouse|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, _______},
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, PLOVER,  _______, MOUSE  },
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Mouse keys
 * ,-----------------------------------------------------------------------------------.
 * |      |      | M Up |      |      |      |      | Spd0 | Spd1 | Spd2 |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | M Lf | M Dn | M Ri |      |      |      | MB 1 | MB 2 | MB 3 |      |Qwerty|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | MW L | MW D | MW U | MW R |Colemk|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  Sym |             |   No |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = {
  {_______, _______, KC_MS_U, _______, _______, _______, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______},
  {_______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, KC_BTN1, KC_BTN2, KC_BTN3, _______, QWERTY },
  {_______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, COLEMAK},
  {_______, _______, _______, _______, SYMBOL,  KC_SPC,  KC_SPC,  NUMBER,  _______, _______, _______, _______}
}
};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

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
    case MOUSE:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_MOUSE);
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
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_NUMBER);
        layer_off(_SYMBOL);
        layer_off(_FUNCTION);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
  }
  return true;
}