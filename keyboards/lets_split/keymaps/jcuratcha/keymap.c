#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

enum custom_layers {
  _QWERTY,
  _SYMBOL,
  _NUMBER,
  _FUNCTION,
  _NAVIGATE,
  _MOUSE,
  _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMBOL,
  NUMBER,
  FUNCTION,
  NAVIGATE,
  MOUSE,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Nav  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |RShift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | Func | Sym  |    Space    | No   | Nav  | Enter| Alt  | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_TAB,   KC_Q,    KC_W,    KC_E,     KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,     KC_O,    KC_P,    KC_BSPC, \
  NAVIGATE, KC_A,    KC_S,    KC_D,     KC_F,   KC_G,   KC_H,   KC_J,   KC_K,     KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,  KC_Z,    KC_X,    KC_C,     KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT, \
  KC_LCTL,  KC_LGUI, KC_LALT, FUNCTION, SYMBOL, KC_SPC, KC_SPC, NUMBER, NAVIGATE, KC_RCTL, KC_RALT, KC_ENT \
),

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
[_SYMBOL] = KEYMAP( \
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
  _______, KC_TILD, KC_PIPE, KC_DQUO, KC_QUOT, _______, _______, KC_MINS, KC_UNDS, KC_LCBR, KC_RCBR, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

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
[_NUMBER] = KEYMAP( \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  _______, KC_GRV,  KC_BSLS, KC_DQUO, KC_QUOT, _______, _______, KC_MINS, KC_UNDS, KC_EQL,  KC_PLUS, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_ASTR, KC_COMM, KC_DOT,  KC_SLSH, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Function
 * ,-----------------------------------------------------------------------------------.
 * | Esc  | Caps | Num  |      | PrSc | Scrl |Pause |      |      |      | Del  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      | Vol- | Vol+ |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTION] = KEYMAP( \
  KC_ESC,  KC_CAPS, KC_NLCK, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, _______, _______, KC_DEL,  _______, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, KC_VOLD, KC_VOLU, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

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
[_NAVIGATE] = KEYMAP( \
  KC_ESC,  KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_DEL,  _______, \
  _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS,  _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Adjust (Symbol + Number)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Mouse |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = KEYMAP( \
  XXXXXXX, RESET,   DEBUG,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  MOUSE,   XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
),

/* Mouse keys
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | M Lf | M Dn | M Up | M Ri |      |      | MB 1 | MB 2 | MB 3 |      |Qwerty|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | MW L | MW D | MW U | MW R |      |      | Spd0 | Spd1 | Spd2 |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  Sym |             |   No |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = KEYMAP( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U,  KC_MS_R, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN3, XXXXXXX, QWERTY , \
  XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U,  KC_WH_R, XXXXXXX, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, XXXXXXX, \
  KC_LCTL, KC_LGUI, KC_LALT, FUNCTION, SYMBOL,  KC_SPC,  KC_SPC,  NUMBER,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
)
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
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
  }
  return true;
}