#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "unicode.h"

#define _______ KC_TRNS

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define EMOJ 2 // emoji keys
#define MDIA 3 // media keys

enum custom_keycodes {
  // Keycodes included with the default keymap
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,

  UNDER_DASH, // underscore regular, dash when shift is applied

  // Windows specific
  LOCK,
  CTRL_ALT_DELETE
};

enum {
  // Emoji tap dance codes
  // Unicode emojis
  TEARS_OF_JOY_E = 0,
  WINKING_FACE_E,
  SMILING_FACE_SMILING_EYES_E,
  SMILING_SUNGLASSES_E,
  HEART_EYES_E,
  BLOWING_KISS_E,
  STAR_STRUCK_E,
  RAISED_EYEBROW_E,
  EYE_ROLL_E,
  SMIRKING_E,
  TONGUE_STICKING_OUT_E,
  WINKING_TONGUE_E,
  UNAMUSED_E,
  ASTONISHED_E,
  CRYING_E,
  LOUDLY_CRYING_E,
  WEARY_E,
  EXPLODING_E,
  FLUSHED_E,
  SMILING_HALO_E,
  SMILING_DEVIL_E,
  EGGPLANT_E,
  FIRE_E,
  DROPLETS_E,
  RED_HEART_E,
  THUMBS_UP_E,
  OK_HAND_E,
  VULCAN_SALUTE_E,
  TONGUE_E,

  // ASCII art emojis
  SHRUG_A,
  TABLE_FLIP_A,

  // Shortcuts
  Y_COPY,
  U_CUT,
  J_PASTE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Note missing grave key
  // Also note that the home, end, page up, and page down keys are of limited
  // use potentially
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | EMOJ |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |LOCK  |  Y   |  U   |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |  J   |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | CAD  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Symb |  Ctrl |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |   {  | _/-  |       | Alt  | Esc  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Ctrl  |------|       |------|  Del   |Enter |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_EQUAL,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   TG(EMOJ),
        KC_TAB,        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   TG(SYMB),
        KC_BSPC,        KC_A,    KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSHIFT,        KC_Z,  KC_X,   KC_C,   KC_V,   KC_B,   ALL_T(KC_NO),
        MO(SYMB),KC_LCTRL,      LALT(KC_LSFT),  KC_LEFT,KC_RGHT,
                                              KC_LEFT_CURLY_BRACE, KC_MINUS,
                                                              KC_HOME,
                                               KC_SPC,KC_RCTRL,KC_END,
        // right hand
             KC_RGHT,          KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_MINS,
             LOCK,             KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,             KC_BSLS,
                                          KC_H,   KC_J,  KC_K,   KC_L,   KC_SCOLON,GUI_T(KC_QUOT),
             CTRL_ALT_DELETE , KC_N,   KC_M,  KC_COMM,KC_DOT, CTL_T(KC_SLSH),   KC_RSHIFT,
                                  KC_UP, KC_DOWN,KC_LBRC,KC_RBRC,          KC_FN1,
             KC_LALT,        KC_ESC,
             KC_PGUP,
             KC_PGDN,KC_DELETE, KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       VRSN,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
          EPRM,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       RGB_MOD,KC_TRNS,
                                               KC_TRNS,
                               RGB_VAD,RGB_VAI,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       RGB_TOG, RGB_SLD,
       KC_TRNS,
       KC_TRNS, RGB_HUD, RGB_HUI
),
/* Keymap 2: Emoji layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |       |  🙄  |  😒  |  🤨  |  😉  |  😜  |  😢  |           |  ❤️  |   Y  | flip |  😇  |  😳  |  🤯  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   😍   |  😘  |  👌  |  😊  |  😂  |  😎  |------|           |------| shrug |  😩  |  😈  |  🍆  |  🖖  |   💦    |
 * |--------+------+------+------+------+------|  😭  |           |  😘  |------+------+------+------+------+--------|
 * |   🔥   |  🤩  |  👍  |  😛  |  😏  |  😲  |      |           |      |   N  |   M  |   ,  |  👅  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[EMOJ] = LAYOUT_ergodox(
        // left hand
        _______,                _______,              _______,          _______,                          _______,              _______,                  _______,
        _______,                TD(EYE_ROLL_E),       TD(UNAMUSED_E),   TD(RAISED_EYEBROW_E),             TD(WINKING_FACE_E),   TD(WINKING_TONGUE_E),     TD(CRYING_E),
        TD(HEART_EYES_E),       TD(BLOWING_KISS_E),   TD(OK_HAND_E),    TD(SMILING_FACE_SMILING_EYES_E),  TD(TEARS_OF_JOY_E),   TD(SMILING_SUNGLASSES_E),
        TD(FIRE_E),             TD(STAR_STRUCK_E),    TD(THUMBS_UP_E),  TD(TONGUE_STICKING_OUT_E),        TD(SMIRKING_E),       TD(ASTONISHED_E),         TD(LOUDLY_CRYING_E),
        _______,                _______,              _______,          _______,                          _______,
                                                  _______,          _______,
                                                                    _______,
                                                  _______,_______,  _______,
        // right hand
        _______,              _______,        _______,            _______,                _______,          _______,              _______,
        TD(RED_HEART_E),      _______,        TD(TABLE_FLIP_A),   TD(SMILING_HALO_E),     TD(FLUSHED_E),    TD(EXPLODING_E),      _______,
                              TD(SHRUG_A),    TD(WEARY_E),        TD(SMILING_DEVIL_E),    TD(EGGPLANT_E),   TD(VULCAN_SALUTE_E),  TD(DROPLETS_E),
        TD(BLOWING_KISS_E),   _______,        _______,            _______,                TD(TONGUE_E),     _______,              _______,
                                              _______,            _______,                _______,          _______,              _______,
        _______,            _______,
        _______,
        _______,_______,    _______
    ),
/* Keymap 3: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

char *get_emoji_hex(uint16_t keycode) {
  // As seen in process_tap_dance.c, we have to subtract away QK_TAP_DANCE
  // from the keycode to get the value of the enumeration that triggered the
  // tap dance.
  switch (keycode - QK_TAP_DANCE) {
    case TEARS_OF_JOY_E:
      return "d83dde02";
    case WINKING_FACE_E:
      return "d83dde09";
    case SMILING_FACE_SMILING_EYES_E:
      return "d83dde0a";
    case SMILING_SUNGLASSES_E:
      return "d83dde0e";
    case HEART_EYES_E:
      return "d83dde0d";
    case BLOWING_KISS_E:
      return "d83dde18";
    case STAR_STRUCK_E:
      return "d83edd29";
    case RAISED_EYEBROW_E:
      return "d83edd28";
    case EYE_ROLL_E:
      return "d83dde44";
    case SMIRKING_E:
      return "d83dde0f";
    case TONGUE_STICKING_OUT_E:
      return "d83dde1b";
    case WINKING_TONGUE_E:
      return "d83dde1c";
    case UNAMUSED_E:
      return "d83dde12";
    case ASTONISHED_E:
      return "d83dde32";
    case CRYING_E:
      return "d83dde22";
    case LOUDLY_CRYING_E:
      return "d83dde2d";
    case WEARY_E:
      return "d83dde29";
    case EXPLODING_E:
      return "d83edd2f";
    case FLUSHED_E:
      return "d83dde33";
    case SMILING_HALO_E:
      return "d83dde07";
    case SMILING_DEVIL_E:
      return "d83dde08";
    case EGGPLANT_E:
      return "d83cdf46";
    case FIRE_E:
      return "d83ddd25";
    case DROPLETS_E:
      return "d83ddca6";
    case RED_HEART_E:
      return "2764fe0f";
    case THUMBS_UP_E:
      return "d83ddc4d";
    case OK_HAND_E:
      return "d83ddc4c";
    case VULCAN_SALUTE_E:
      return "d83ddd96";
    case TONGUE_E:
      return "d83ddc45";
    case SHRUG_A:
      return "00AF005C005F002830C40029002F00AF";
    case TABLE_FLIP_A:
      return "0028256F00B025A100B0FF09256FFE350020253B2501253B";
    default:
      SEND_STRING("EMOJI NOT FOUND");
      return "";
  }
}

void tap_dance_emoji(qk_tap_dance_state_t *state, void *user_data) {
  int emoji_count = state->count;
  uint16_t emoji_code = state->keycode;
  emit_unicode_hex(get_emoji_hex(emoji_code), emoji_count);
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TEARS_OF_JOY_E] = ACTION_TAP_DANCE_FN (tap_dance_emoji),
  [WINKING_FACE_E] = ACTION_TAP_DANCE_FN (tap_dance_emoji),
  [SMILING_FACE_SMILING_EYES_E] = ACTION_TAP_DANCE_FN (tap_dance_emoji),
  [SMILING_SUNGLASSES_E] = ACTION_TAP_DANCE_FN (tap_dance_emoji),
  [HEART_EYES_E] = ACTION_TAP_DANCE_FN (tap_dance_emoji),
  [BLOWING_KISS_E] = ACTION_TAP_DANCE_FN (tap_dance_emoji),
  [STAR_STRUCK_E] = ACTION_TAP_DANCE_FN (tap_dance_emoji),
  [RAISED_EYEBROW_E] = ACTION_TAP_DANCE_FN (tap_dance_emoji),
  [EYE_ROLL_E] = ACTION_TAP_DANCE_FN (tap_dance_emoji),
  [SMIRKING_E] = ACTION_TAP_DANCE_FN (tap_dance_emoji),
  [TONGUE_STICKING_OUT_E] = ACTION_TAP_DANCE_FN (tap_dance_emoji),
  [WINKING_TONGUE_E] = ACTION_TAP_DANCE_FN (tap_dance_emoji),
  [UNAMUSED_E] = ACTION_TAP_DANCE_FN (tap_dance_emoji),
  [ASTONISHED_E] = ACTION_TAP_DANCE_FN (tap_dance_emoji),
  [CRYING_E] = ACTION_TAP_DANCE_FN (tap_dance_emoji),
  [LOUDLY_CRYING_E] = ACTION_TAP_DANCE_FN (tap_dance_emoji),
  [WEARY_E] = ACTION_TAP_DANCE_FN (tap_dance_emoji),
  [EXPLODING_E] = ACTION_TAP_DANCE_FN (tap_dance_emoji),
  [FLUSHED_E] = ACTION_TAP_DANCE_FN (tap_dance_emoji),
  [SMILING_HALO_E] = ACTION_TAP_DANCE_FN (tap_dance_emoji),
  [SMILING_DEVIL_E] = ACTION_TAP_DANCE_FN (tap_dance_emoji),
  [EGGPLANT_E] = ACTION_TAP_DANCE_FN (tap_dance_emoji),
  [FIRE_E] = ACTION_TAP_DANCE_FN (tap_dance_emoji),
  [DROPLETS_E] = ACTION_TAP_DANCE_FN (tap_dance_emoji),
  [RED_HEART_E] = ACTION_TAP_DANCE_FN (tap_dance_emoji),
  [THUMBS_UP_E] = ACTION_TAP_DANCE_FN (tap_dance_emoji),
  [OK_HAND_E] = ACTION_TAP_DANCE_FN (tap_dance_emoji),
  [VULCAN_SALUTE_E] = ACTION_TAP_DANCE_FN (tap_dance_emoji),
  [TONGUE_E] = ACTION_TAP_DANCE_FN (tap_dance_emoji),
  [SHRUG_A] = ACTION_TAP_DANCE_FN (tap_dance_emoji),
  [TABLE_FLIP_A] = ACTION_TAP_DANCE_FN (tap_dance_emoji),

  [Y_COPY] = ACTION_TAP_DANCE_DOUBLE (KC_Y, LGUI(KC_C)),
  [U_CUT] = ACTION_TAP_DANCE_DOUBLE (KC_U, LGUI(KC_X)),
  [J_PASTE] = ACTION_TAP_DANCE_DOUBLE (KC_J, LGUI(KC_V))
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Cases that were part of the default keymap
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
    case LOCK:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("l"));
      }
      break;
    case CTRL_ALT_DELETE:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_RCTRL)SS_DOWN(X_RALT)SS_DOWN(X_DELETE)SS_UP(X_RCTRL)SS_UP(X_RALT)SS_UP(X_DELETE));
      }
      break;
    // case UNDER_DASH:
    //   // Note: could also make it so some press count flips behavior so is
    //   // an underscore with shift and is regular dash without as normal
    //   if (record->event.pressed) {
    //     int shift_mod_bits = MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT);
    //     int shift_pressed = get_mods() & shift_mod_bits;
    //     if (shift_pressed) {
    //       SEND_STRING("-");
    //     } else {
    //       SEND_STRING("_");
    //     }
    //   }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
static uint8_t last_layer;
void matrix_init_user(void) {
  last_layer = BASE;
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
// TODO ensure that the input mode is automatically switched when transitioning
// to/from the emoji layer.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  if (last_layer == EMOJ) {
    deactivate_unicode_input();
  }
  last_layer = layer;
  switch (layer) {
      case BASE:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case SYMB:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case EMOJ:
        activate_unicode_input();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case MDIA:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      // case 4:
      //   ergodox_right_led_1_on();
      //   ergodox_right_led_2_on();
      //   #ifdef RGBLIGHT_COLOR_LAYER_4
      //     rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
      //   #endif
      //   break;
      // case 5:
      //   ergodox_right_led_1_on();
      //   ergodox_right_led_3_on();
      //   #ifdef RGBLIGHT_COLOR_LAYER_5
      //     rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
      //   #endif
      //   break;
      // case 6:
      //   ergodox_right_led_2_on();
      //   ergodox_right_led_3_on();
      //   #ifdef RGBLIGHT_COLOR_LAYER_6
      //     rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
      //   #endif
      //   break;
      // case 7:
      //   ergodox_right_led_1_on();
      //   ergodox_right_led_2_on();
      //   ergodox_right_led_3_on();
      //   #ifdef RGBLIGHT_COLOR_LAYER_7
      //     rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
      //   #endif
      //   break;
      // default:
      //   break;
    }

  return state;
};
