// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

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

combo_t key_combos[] = {
    COMBO(caps_combo, KC_CAPS_LOCK)
};


// *** Layers ***
enum keymap_layers {
    LAYER_BASE,
    LAYER_NAV,
    LAYER_NUM,
    LAYER_FUN
};

#include "sm_td.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   if (!process_smtd(keycode, record)) return false;

   return true;
}

smtd_resolution on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        // Left side home row
        SMTD_MT(KC_S, KC_LEFT_GUI)
        SMTD_MT(KC_N, KC_LEFT_ALT)
        SMTD_MT(KC_T, KC_LEFT_CTRL)
        SMTD_MT(KC_H, KC_LEFT_SHIFT)

        // Switch layers
        SMTD_LT(KC_ESC, LAYER_FUN)
        SMTD_LT(KC_R,   LAYER_NAV, 2)

        // Right side home row
        SMTD_MT(KC_A, KC_RIGHT_SHIFT)
        SMTD_MT(KC_E, KC_RIGHT_CTRL)
        SMTD_MT(KC_I, KC_RIGHT_ALT)
        SMTD_MT(KC_C, KC_RIGHT_GUI)

        // Switch layers
        SMTD_LT(KC_SPACE,  LAYER_NUM, 2)
        SMTD_LT(KC_DELETE, LAYER_FUN, 2)
    }

    return SMTD_RESOLUTION_UNHANDLED;
}

// *** Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
              KC_F,   KC_P,   KC_D,     KC_L,   KC_X,        KC_Q,         KC_U,       KC_O,       KC_Y,     KC_B,
              KC_S,   KC_N,   KC_T,     KC_H,   KC_K,        KC_Z,         KC_A,       KC_E,       KC_I,     KC_C,
    KC_TAB,   KC_V,   KC_W,   KC_G,     KC_M,   KC_J,        KC_MINUS,     KC_EQUAL,   KC_COMMA,   KC_DOT,   KC_QUOTE,   KC_QUESTION,

                             KC_ESC,   KC_R,  KC_ENTER,    KC_BACKSPACE,  KC_SPACE,   KC_DELETE
  ),

  [LAYER_NAV] = LAYOUT(
              _______,      _______,      _______,       _______,        _______,     KC_VOLU,  KC_HOME,  KC_INSERT,  KC_END,    KC_PAGE_UP,
              KC_LEFT_GUI,  KC_LEFT_ALT,  KC_LEFT_CTRL,  KC_LEFT_SHIFT,  _______,     KC_LEFT,  KC_DOWN,  KC_UP,      KC_RIGHT,  KC_PAGE_DOWN,
    _______,  _______,      _______,      _______,       _______,        _______,     KC_VOLD,  _______,  _______,  _______,   _______, _______,

                                          _______,       _______,        _______,     _______,            _______,  _______
  ),

  [LAYER_NUM] = LAYOUT(
              _______,      KC_7,  KC_8,      KC_9,     KC_0,                     QK_DYNAMIC_TAPPING_TERM_UP,     _______,  _______,  _______,   _______,
              _______,      KC_4,  KC_5,      KC_6,     KC_LEFT_ANGLE_BRACKET,    QK_DYNAMIC_TAPPING_TERM_PRINT,  _______,  _______,  _______,   _______,
    _______,  _______,      KC_1,  KC_2,      KC_3,     KC_RIGHT_ANGLE_BRACKET,   QK_DYNAMIC_TAPPING_TERM_DOWN,   _______,  _______,  _______,   _______, _______,

                                   _______,   _______,  _______,                  _______,  _______,  _______
  ),

  [LAYER_FUN] = LAYOUT(
              KC_F12,   KC_F7,  KC_F8,    KC_F9,    KC_GRAVE,        KC_AT,        KC_LEFT_BRACKET,      KC_RIGHT_BRACKET,      KC_DOLLAR,     KC_BACKSLASH,
              KC_F11,   KC_F4,  KC_F5,    KC_F6,    KC_TILDE,        KC_HASH,      KC_LEFT_PAREN,        KC_RIGHT_PAREN,        KC_PERCENT,    KC_SLASH,
    _______,  KC_F10,   KC_F1,  KC_F2,    KC_F3,    KC_CIRCUMFLEX,   KC_ASTERISK,  KC_LEFT_CURLY_BRACE,  KC_RIGHT_CURLY_BRACE,  KC_AMPERSAND,  KC_PIPE,       _______,

                                _______,  _______,  _______,         _______,      _______,              _______
  )

};