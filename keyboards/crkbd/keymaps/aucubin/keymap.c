#include QMK_KEYBOARD_H

// Aptmak layout, ported from the ZMK swweeep keymap.
enum layers {
    _ALPHA,
    _NUM,
    _NAV,
    _SYM,
    _FUN,
    _BT
};

enum custom_keycodes {
    MC_AE = SAFE_RANGE,
    MC_OE,
    MC_UE,
    MC_SZ
};

// Combo keys must match the base layer keycodes exactly (positions are the 36-key index).
const uint16_t PROGMEM c_q[]        = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM c_z[]        = {KC_C, KC_G, COMBO_END};
const uint16_t PROGMEM c_v[]        = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM c_slash[]    = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM c_minus[]    = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM c_esc[]      = {KC_G, KC_D, COMBO_END};
const uint16_t PROGMEM c_lbrc[]     = {KC_W, LALT_T(KC_S), COMBO_END};
const uint16_t PROGMEM c_lbkt[]     = {KC_F, LGUI_T(KC_T), COMBO_END};
const uint16_t PROGMEM c_lpar[]     = {KC_P, LSFT_T(KC_H), COMBO_END};
const uint16_t PROGMEM c_lt[]       = {KC_B, RALT_T(KC_K), COMBO_END};
const uint16_t PROGMEM c_rbrc[]     = {KC_Y, LALT_T(KC_I), COMBO_END};
const uint16_t PROGMEM c_rbkt[]     = {KC_U, LGUI_T(KC_A), COMBO_END};
const uint16_t PROGMEM c_rpar[]     = {KC_L, RSFT_T(KC_N), COMBO_END};
const uint16_t PROGMEM c_gt[]       = {KC_J, RALT_T(KC_X), COMBO_END};
const uint16_t PROGMEM c_capsword[] = {LSFT_T(KC_H), RSFT_T(KC_N), COMBO_END};
const uint16_t PROGMEM c_capslock[] = {KC_W, KC_Y, COMBO_END};
const uint16_t PROGMEM c_bspc[]     = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM c_del[]      = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM c_delword[]  = {KC_L, KC_Y, COMBO_END};
const uint16_t PROGMEM c_ae[]       = {LGUI_T(KC_A), LT(_SYM, KC_E), COMBO_END};
const uint16_t PROGMEM c_oe[]       = {RCTL_T(KC_O), LT(_SYM, KC_E), COMBO_END};
const uint16_t PROGMEM c_ue[]       = {KC_U, LT(_SYM, KC_E), COMBO_END};
const uint16_t PROGMEM c_sz[]       = {LALT_T(KC_S), LT(_NAV, KC_SPC), COMBO_END};
combo_t key_combos[] = {
    COMBO(c_q, KC_Q),
    COMBO(c_z, KC_Z),
    COMBO(c_v, KC_V),
    COMBO(c_slash, KC_SLSH),
    COMBO(c_minus, KC_MINS),
    COMBO(c_esc, KC_ESC),
    COMBO(c_lbrc, KC_LCBR),
    COMBO(c_lbkt, KC_LBRC),
    COMBO(c_lpar, KC_LPRN),
    COMBO(c_lt, KC_LT),
    COMBO(c_rbrc, KC_RCBR),
    COMBO(c_rbkt, KC_RBRC),
    COMBO(c_rpar, KC_RPRN),
    COMBO(c_gt, KC_GT),
    COMBO(c_capsword, CW_TOGG),
    COMBO(c_capslock, KC_CAPS),
    COMBO(c_bspc, KC_BSPC),
    COMBO(c_del, KC_DEL),
    COMBO(c_delword, LCTL(KC_BSPC)),
    COMBO(c_ae, MC_AE),
    COMBO(c_oe, MC_OE),
    COMBO(c_ue, MC_UE),
    COMBO(c_sz, MC_SZ)
};

// Shift + , -> ;   and   Shift + . -> :
const key_override_t comma_semicolon = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SCLN);
const key_override_t dot_colon       = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLN);
const key_override_t *key_overrides[] = {&comma_semicolon, &dot_colon};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_ALPHA] = LAYOUT_split_3x6_3(
               KC_NO,         KC_V,         KC_W,         KC_F,         KC_P,         KC_B,
                KC_J,         KC_L,         KC_U,         KC_Y,      KC_SCLN,        KC_NO,
               KC_NO, LCTL_T(KC_R), LALT_T(KC_S), LGUI_T(KC_T), LSFT_T(KC_H), RALT_T(KC_K),
        RALT_T(KC_X), RSFT_T(KC_N), LGUI_T(KC_A), LALT_T(KC_I), RCTL_T(KC_O),        KC_NO,
               KC_NO,         KC_Z,         KC_C,         KC_G,         KC_D,         KC_Q,
             KC_QUOT,         KC_M,      KC_COMM,       KC_DOT,      KC_SLSH,        KC_NO,
        LT(_BT, KC_ESC), LT(_NUM, KC_QUOT), LT(_NAV, KC_SPC), LT(_SYM, KC_E), LT(_FUN, KC_ENT),       KC_TAB
  ),
  [_NUM] = LAYOUT_split_3x6_3(
               KC_NO,        KC_NO,         KC_9,         KC_8,         KC_7,      KC_PAST,
             KC_PLUS,         KC_7,         KC_8,         KC_9,        KC_NO,        KC_NO,
               KC_NO, LCTL_T(KC_0), LALT_T(KC_6), LGUI_T(KC_5), LSFT_T(KC_4),      KC_SLSH,
             KC_MINS,         KC_4,         KC_5,         KC_6,      KC_PDOT,        KC_NO,
               KC_NO,        KC_NO,         KC_3,         KC_2,         KC_1,        KC_NO,
               KC_NO,         KC_1,         KC_2,         KC_3,        KC_NO,        KC_NO,
             _______,      _______,      _______,         KC_E,         KC_0,      _______
  ),
  [_NAV] = LAYOUT_split_3x6_3(
               KC_NO,        KC_NO,       KC_INS,        KC_UP,      KC_BSPC,      KC_VOLD,
             KC_VOLU,      KC_BSPC,       KC_DEL,       KC_INS,        KC_NO,        KC_NO,
               KC_NO,      KC_LCTL, LALT_T(KC_LEFT), LGUI_T(KC_DOWN), LSFT_T(KC_RIGHT),      KC_MUTE,
             KC_LEFT,      KC_DOWN,        KC_UP,      KC_RGHT,       KC_TAB,        KC_NO,
               KC_NO,        KC_NO,      KC_HOME,      KC_PGDN,       KC_END,        KC_NO,
               KC_NO,      KC_HOME,      KC_PGUP,       KC_END,        KC_NO,        KC_NO,
             _______,      _______,      _______,      _______,      _______,      _______
  ),
  [_SYM] = LAYOUT_split_3x6_3(
               KC_NO,        KC_NO,       KC_GRV,      KC_DQUO, RALT(LSFT(KC_SCLN)),      KC_LCBR,
             KC_RCBR,      KC_BSLS,      KC_PIPE,        KC_LT,        KC_NO,        KC_NO,
               KC_NO,      KC_EXLM,        KC_AT,      KC_HASH,       KC_DLR,      KC_LPRN,
             KC_RPRN,      KC_AMPR,      KC_ASTR,      KC_PERC,      KC_CIRC,        KC_NO,
               KC_NO,        KC_NO,      KC_TILD,      KC_QUOT,      KC_UNDS,        KC_NO,
               KC_NO,      KC_MINS,      KC_PLUS,       KC_EQL,        KC_NO,        KC_NO,
             _______,      KC_LBRC,      KC_RBRC,      _______,      _______,      _______
  ),
  [_FUN] = LAYOUT_split_3x6_3(
               KC_NO,      _______,      _______,      _______,      _______,      _______,
              KC_F12,        KC_F7,        KC_F8,        KC_F9,       QK_RBT,        KC_NO,
               KC_NO,      _______,      _______,      _______,      _______,      _______,
              KC_F11,        KC_F4,        KC_F5,        KC_F6,       KC_F10,        KC_NO,
               KC_NO,      _______,      _______,      _______,      _______,      _______,
             _______,        KC_F1,        KC_F2,        KC_F3,      QK_BOOT,        KC_NO,
             _______,      _______,      _______,      _______,      _______,      _______
  ),
  [_BT] = LAYOUT_split_3x6_3(
               KC_NO,        KC_NO,      QK_BOOT,        KC_NO,        KC_NO,        KC_NO,
               KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,
               KC_NO,        KC_NO,       QK_RBT,        KC_NO,        KC_NO,        KC_NO,
               KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,
               KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,
               KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,
             _______,      _______,      _______,      _______,      _______,      _______
  )
};

#define ANIM_INVERT false
#define ANIM_RENDER_WPM true
#define FAST_TYPE_WPM 45 //Switch to fast animation when over words per minute

#ifdef OLED_ENABLE
#include "demon.c"
#endif

#ifdef OLED_ENABLE
#include <stdio.h>

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_anim();
    }
    return false;
}

#endif // OLED_ENABLE

static void send_umlaut(uint16_t letter) {
    tap_code16(KC_DQUO);
    tap_code(letter);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case MC_AE:
                send_umlaut(KC_A);
                return false;
            case MC_OE:
                send_umlaut(KC_O);
                return false;
            case MC_UE:
                send_umlaut(KC_U);
                return false;
            case MC_SZ:
                tap_code16(RALT(KC_S));
                return false;
        }
        set_keylog(keycode, record);
    }
    return true;
}
