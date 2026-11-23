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

#ifdef OLED_ENABLE
// Displays are mounted vertically: 5 characters wide, 16 lines tall.
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return is_keyboard_left() ? OLED_ROTATION_270 : OLED_ROTATION_90;
}

// Every row is exactly 5 characters, so the cursor wraps by itself: no newline needed.
static void blank_line(void) {
    oled_write_P(PSTR("     "), false);
}

static void render_layers(void) {
    static const char PROGMEM names[][6] = {"ALPHA", "NUM  ", "NAV  ", "SYM  ", "FUN  ", "BT   "};
    oled_write_P(PSTR("LAYER"), false);
    blank_line();
    layer_state_t top = get_highest_layer(layer_state | default_layer_state);
    for (uint8_t i = 0; i < ARRAY_SIZE(names); i++) {
        oled_write_P(names[i], i == top);
    }
}

static void render_mods(void) {
    uint8_t mods = get_mods() | get_oneshot_mods();
    oled_write_P(PSTR("MODS "), false);
    blank_line();
    oled_write_P(PSTR("SHIFT"), mods & MOD_MASK_SHIFT);
    oled_write_P(PSTR("CTRL "), mods & MOD_MASK_CTRL);
    oled_write_P(PSTR("ALT  "), mods & MOD_BIT(KC_LALT));
    oled_write_P(PSTR("ALTGR"), mods & MOD_BIT(KC_RALT));
    oled_write_P(PSTR("GUI  "), mods & MOD_MASK_GUI);
    blank_line();
    oled_write_P(PSTR("CAPS "), host_keyboard_led_state().caps_lock);
}

bool oled_task_user(void) {
    if (is_keyboard_left()) {
        render_layers();
    } else {
        render_mods();
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
    }
    return true;
}
