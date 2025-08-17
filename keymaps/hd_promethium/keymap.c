// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// *** Layers ***
enum keymap_layers {
    LAYER_BASE,
    LAYER_NAV,
    LAYER_NUM,
    LAYER_FUN
};


// *** Key Override ***
const key_override_t semicolon_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA,    KC_SEMICOLON);
const key_override_t colon_override     = ko_make_basic(MOD_MASK_SHIFT, KC_DOT,      KC_COLON);
const key_override_t quexclam_override  = ko_make_basic(MOD_MASK_SHIFT, KC_QUESTION, KC_EXCLAIM);

const key_override_t *key_overrides[] = {
	&semicolon_override,
	&colon_override,
	&quexclam_override
};


// *** Combos ***
const uint16_t PROGMEM caps_combo[] = {KC_D, KC_O, COMBO_END};
combo_t key_combos[] = {COMBO(caps_combo, KC_CAPS_LOCK)};


// *** Hold Mods ***
//   ---Left---
//Home Row
#define HR_LGUI LGUI_T(KC_S)
#define HR_LALT LALT_T(KC_N)
#define HR_LCTL LCTL_T(KC_T)
#define HR_LSFT LSFT_T(KC_H)
// Layers
#define L_ESC_FUN LT(LAYER_FUN, KC_ESC)
#define L_R_NAV   LT(LAYER_NAV, KC_R)

//   ---Right---
//Home Row
#define HR_RSFT RSFT_T(KC_A)
#define HR_RCTL RCTL_T(KC_E)
#define HR_RALT RALT_T(KC_I)
#define HR_RGUI RGUI_T(KC_C)
// layers
#define L_SPC_NUM LT(LAYER_NUM, KC_SPACE)
#define L_DEL_FUN LT(LAYER_FUN, KC_DELETE)


// *** Keymaps ***
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Base
  [LAYER_BASE] = LAYOUT(
              KC_F,    KC_P,    KC_D,     KC_L,    KC_X,     KC_Q,          KC_U,       KC_O,       KC_Y,     KC_B,
              HR_LGUI, HR_LALT, HR_LCTL,  HR_LSFT, KC_K,     KC_Z,          HR_RSFT,    HR_RCTL,    HR_RALT,  HR_RGUI,
    KC_TAB,   KC_V,    KC_W,    KC_G,     KC_M,    KC_J,     KC_MINUS,      KC_EQUAL,   KC_COMMA,   KC_DOT,   KC_QUOTE,   KC_QUESTION,

                         L_ESC_FUN,   L_R_NAV,  KC_ENTER,    KC_BACKSPACE,  L_SPC_NUM,   L_DEL_FUN
  ),

// Navigation
  [LAYER_NAV] = LAYOUT(
              _______,      _______,      _______,       _______,        _______,     KC_VOLU,  KC_HOME,  KC_INSERT,  KC_END,    KC_PAGE_UP,
              KC_LEFT_GUI,  KC_LEFT_ALT,  KC_LEFT_CTRL,  KC_LEFT_SHIFT,  _______,     KC_LEFT,  KC_DOWN,  KC_UP,      KC_RIGHT,  KC_PAGE_DOWN,
    _______,  _______,      _______,      _______,       _______,        _______,     KC_VOLD,  _______,  _______,  _______,   _______, _______,

                                          _______,       _______,        _______,     _______,            _______,  _______
  ),

// Numeric
  [LAYER_NUM] = LAYOUT(
              _______,      KC_7,  KC_8,      KC_9,     KC_0,                     QK_DYNAMIC_TAPPING_TERM_UP,     _______,     KC_0,  _______,   _______,
              _______,      KC_4,  KC_5,      KC_6,     KC_LEFT_ANGLE_BRACKET,    QK_DYNAMIC_TAPPING_TERM_PRINT,     KC_0,     KC_0,  _______,   _______,
    _______,  _______,      KC_1,  KC_2,      KC_3,     KC_RIGHT_ANGLE_BRACKET,   QK_DYNAMIC_TAPPING_TERM_DOWN,   _______,  _______,  _______,   _______, _______,

                                   _______,   _______,  _______,                  _______,  _______,  _______
  ),

// Function
  [LAYER_FUN] = LAYOUT(
              KC_F12,   KC_F7,  KC_F8,    KC_F9,    KC_GRAVE,        KC_AT,        KC_LEFT_BRACKET,      KC_RIGHT_BRACKET,      KC_DOLLAR,     KC_BACKSLASH,
              KC_F11,   KC_F4,  KC_F5,    KC_F6,    KC_TILDE,        KC_HASH,      KC_LEFT_PAREN,        KC_RIGHT_PAREN,        KC_PERCENT,    KC_SLASH,
    _______,  KC_F10,   KC_F1,  KC_F2,    KC_F3,    KC_CIRCUMFLEX,   KC_ASTERISK,  KC_LEFT_CURLY_BRACE,  KC_RIGHT_CURLY_BRACE,  KC_AMPERSAND,  KC_PIPE,       _______,

                                _______,  _______,  _______,         _______,      _______,              _______
  )

};