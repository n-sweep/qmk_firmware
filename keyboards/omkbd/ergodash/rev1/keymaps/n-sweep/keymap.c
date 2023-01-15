#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _SYMB0 1
#define _MEDNAV 2
#define _ADJUST 3
#define _SYMB0_L 4
#define _SYMB0_R 5

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMB0,
  MEDNAV,
  ADJUST,
  SYMB0_L,
  SYMB0_R,
};

#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*regex to match first four rows: "((?:\|.{6}){7})\|\s{20}((?:\|.{6}){7})\|"gm*/
/*regex to match last row: ((?:\|.{6}){4})\|{7}((?:\|.{6}){3})\|{7}((?:\|.{6}){3})\|{7}((?:\|.{6}){4})*/

  /* ▽ = KC_TRNS / Use the next lowest non-transparent key */

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  =   |   1  |   2  |   3  |   4  |   5  | Home |                    |  End |   6  |   7  |   8  |   9  |   0  |  -   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  | Lyr- |                    | Lyr+ |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | ESC  |   A  |   S  |   D  |   F  |   G  |PageDn|                    |PageUp|   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |  Alt |                    |  Del |   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |  `   | Caps |      |      |||||||| Bksp |  Tab |  GUI ||||||||  Alt | Enter| Space||||||||      |   [  |   ]  | Lyr1 |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT(
    KC_EQL,              KC_1,         KC_2,         KC_3,    KC_4,    KC_5,               KC_HOME,                        KC_END,         KC_6,               KC_7,    KC_8,    KC_9,            KC_0,                 KC_MINS,
    KC_TAB,              KC_Q,         KC_W,         KC_E,    KC_R,    KC_T,               MEDNAV,                         SYMB0,          KC_Y,               KC_U,    KC_I,    KC_O,            KC_P,                 KC_BSLS,
    LT(_MEDNAV, KC_ESC), KC_A,         KC_S,         KC_D,    KC_F,    LT(_SYMB0_R, KC_G), KC_PGDN,                        KC_PGUP,        LT(_SYMB0_L, KC_H), KC_J,    KC_K,    KC_L,            LT(_MEDNAV, KC_SCLN), RGUI_T(KC_QUOT),
    KC_LSFT,             LCTL_T(KC_Z), LALT_T(KC_X), KC_C,    KC_V,    KC_B,               KC_LALT,                        RCTL_T(KC_DEL), KC_N,               KC_M,    KC_COMM, RALT_T(KC_DOT),  RCTL_T(KC_SLSH),      KC_RSFT,
    LT(_SYMB0, KC_GRV),  KC_CAPS,      KC_NO,        KC_NO,            KC_BSPC,            KC_TAB,  KC_LGUI,      KC_RALT, KC_ENT,         KC_SPC,                      KC_NO,   KC_LBRC,         KC_RBRC,              MO(_SYMB0)
  ),

  /* Symb0 [ ▽ = KC_TRNS / Use the next lowest non-transparent key]
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |PrntSc|  F1  |  F2  |  F3  |  F4  |  F5  |   ▽  |                    |   ▽  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |   ▽  |   !  |   @  |   {  |   }  |   |  | Lyr- |                    | Lyr+ |   *  |   1  |   2  |   3  |   -  |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |   ▽  |   #  |   $  |   (  |   )  |   `  |   ▽  |                    |   ▽  |      |   4  |   5  |   6  |   +  |   ▽  |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |   ▽  |   %  |   ^  |   [  |   ]  |   ~  |   ▽  |                    |   ▽  |      |   7  |   8  |   9  |   /  |   ▽  |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |   ▽  |   &  |   *  |      ||||||||   ▽  |   ▽  |   ▽  ||||||||   ▽  |   ▽  |   ▽  ||||||||   0  |   .  |   =  |   ▽  |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_SYMB0] = LAYOUT(
    KC_PSCR, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,                        _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,
    _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, MEDNAV,                         SYMB0,   KC_PAST, KC_7,    KC_8,    KC_9,    KC_PMNS,  KC_F12,
    _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  _______,                        _______, _______, KC_4,    KC_5,    KC_6,    KC_PPLS, _______,
    _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______,                        _______, _______, KC_1,    KC_2,    KC_3,    KC_PSLS, _______,
    _______, KC_AMPR, KC_ASTR, _______,          _______, _______, _______,      _______, _______, _______,          KC_0,    KC_DOT,  KC_EQL,  _______
  ),

  /* Symb0 Left-hand side only
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |PrntSc|  F1  |  F2  |  F3  |  F4  |  F5  |   ▽  |                    |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |   ▽  |   !  |   @  |   {  |   }  |   |  | Lyr- |                    |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |   ▽  |   #  |   $  |   (  |   )  |   `  |   ▽  |                    |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |   ▽  |   %  |   ^  |   [  |   ]  |   ~  |   ▽  |                    |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |   ▽  |   &  |   *  |      ||||||||   ▽  |   ▽  |   ▽  ||||||||   ▽  |   ▽  |   ▽  ||||||||   ▽  |   ▽  |   ▽  |   ▽  |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_SYMB0_L] = LAYOUT(
    KC_PSCR, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,                        _______, _______, _______, _______, _______, _______, _______,
    _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, MEDNAV,                         _______, _______, _______, _______, _______, _______, _______,
    _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  _______,                        _______, _______, _______, _______, _______, _______, _______,
    _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______,                        _______, _______, _______, _______, _______, _______, _______,
    _______, KC_AMPR, KC_ASTR, _______,          _______, _______, _______,      _______, _______, _______,          _______, _______, _______, _______
  ),

  /* Symb0 Right-hand side only
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |                    |   ▽  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |                    | Lyr+ |   *  |   1  |   2  |   3  |   -  |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |                    |   ▽  |      |   4  |   5  |   6  |   +  |   ▽  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |                    |   ▽  |      |   7  |   8  |   9  |   /  |   ▽  |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |   ▽  |   ▽  |   ▽  |   ▽  ||||||||   ▽  |   ▽  |   ▽  ||||||||   ▽  |   ▽  |   ▽  ||||||||   0  |   .  |   =  |   ▽  |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_SYMB0_R] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,                        _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,
    _______, _______, _______, _______, _______, _______, _______,                        SYMB0,   KC_PAST, KC_7,    KC_8,    KC_9,    KC_PMNS,  KC_F12,
    _______, _______, _______, _______, _______, _______, _______,                        _______, _______, KC_4,    KC_5,    KC_6,    KC_PPLS, _______,
    _______, _______, _______, _______, _______, _______, _______,                        _______, _______, KC_1,    KC_2,    KC_3,    KC_PSLS, _______,
    _______, _______, _______, _______,          _______, _______, _______,      _______, _______, _______,          KC_0,    KC_DOT,  KC_EQL,  _______
  ),

  /* Media/Nav
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |                    |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |   ▽  |   ▽  |   ▽  | MsUp |   ▽  |   ▽  | Lyr- |                    | Lyr+ |      |      |      |      |   ▽  |   ▽  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |   ▽  |   ▽  | MsRt | MsDn | MsLt |   ▽  |   ▽  |                    |   ▽  | Left | Down |  Up  | Right|   ▽  | Play |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |                    |   ▽  |   ▽  |   ▽  |PrvsTr| NxtTr|   ▽  |   ▽  |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |   ▽  |   ▽  |   ▽  |   ▽  ||||||||   ▽  | LClk | RClk ||||||||   ▽  | Back |  Fwd |||||||| VolUp| VolDn| Mute |   ▽  |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */

  [_MEDNAV] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,                        _______, _______,   _______,   _______,   _______,   _______, _______,
    _______, _______, _______, KC_MS_U, _______, _______, MEDNAV,                         SYMB0,   MEH(KC_Y), MEH(KC_U), MEH(KC_I), MEH(KC_O), _______, _______,
    _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,                        _______, KC_LEFT,   KC_DOWN,   KC_UP,     KC_RGHT,   _______, KC_MPLY,
    _______, _______, _______, _______, _______, _______, _______,                        _______, _______,   _______,   KC_MPRV,   KC_MNXT,   _______, _______,
    _______, _______, _______, _______,          KC_BTN1, KC_BTN2, _______,      _______, KC_WBAK, KC_WFWD,              KC_VOLU,   KC_VOLD,   KC_MUTE, _______
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |                    |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  | BOOT |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |                    |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |                    |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |                    |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |   ▽  |   ▽  |   ▽  |   ▽  ||||||||   ▽  |   ▽  |   ▽  ||||||||   ▽  |   ▽  |   ▽  ||||||||   ▽  |   ▽  |   ▽  |   ▽  |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */

  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______, QK_BOOT,
    _______, _______, _______, _______, _______, _______, MEDNAV,                         SYMB0,   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,          _______, _______, _______,      _______, _______, _______,          _______, _______, _______, _______
  )

  /* Temp
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |                    |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |                    |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |                    |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |                    |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |   ▽  |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |   ▽  |   ▽  |   ▽  |   ▽  ||||||||   ▽  |   ▽  |   ▽  ||||||||   ▽  |   ▽  |   ▽  ||||||||   ▽  |   ▽  |   ▽  |   ▽  |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */

  /*[_TEMP] = LAYOUT(*/
    /*_______, _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______, _______,*/
    /*_______, _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______, _______,*/
    /*_______, _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______, _______,*/
    /*_______, _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______, _______,*/
    /*_______, _______, _______, _______,          _______, _______, _______,      _______, _______, _______,          _______, _______, _______, _______*/
  /*)*/

};

/*from original code, can probably be removed as I have audio disabled?*/
#ifdef AUDIO_ENABLE
float tone_qwerty[][2] = SONG(QWERTY_SOUND);
#endif

/*layer colors*/
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _SYMB0:
            rgblight_sethsv (148, 255, 100);
            break;
        case _SYMB0_L:
            rgblight_sethsv (148, 255, 100);
            break;
        case _SYMB0_R:
            rgblight_sethsv (148, 255, 100);
            break;
        case _MEDNAV:
            rgblight_sethsv (0, 255, 100);
            break;
        case _ADJUST:
            rgblight_sethsv (0, 0, 100);
            break;
        default:
            rgblight_sethsv (0, 0, 0);
            break;
    }
    return state;
}

/*????*/
void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

/*layer switching*/
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
         print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case SYMB0:
      if (record->event.pressed) {
        layer_invert(_SYMB0);
        update_tri_layer(_SYMB0, _MEDNAV, _ADJUST);
      }
      return false;
      break;
    case MEDNAV:
      if (record->event.pressed) {
        layer_invert(_MEDNAV);
        update_tri_layer(_SYMB0, _MEDNAV, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
