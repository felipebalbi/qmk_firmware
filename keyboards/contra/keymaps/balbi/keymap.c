/* Copyright 2018 - Felipe Balbi
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

#define KEYLOCK LCTL(LGUI(KC_L))

extern keymap_config_t keymap_config;

enum balbi_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _NAVIGATION,
  _PAGEUP
};

enum balbi_keycodes {
  BASE = SAFE_RANGE,
  LOWER,
  RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base
 * ,-----------------------------------------------------------------------------------.
 * | `    |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | GUI  |      | Esc  | Alt  |Lower | Ctrl | Spc  |Raise |   \  |      |      | GUI  |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = {
  {KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,            KC_O,    KC_P,    KC_BSPC},
  {KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,            KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,         KC_DOT,  KC_SLSH, RSFT_T(KC_ENT)},
  {KC_LGUI, _______, KC_ESC,  KC_LALT, LOWER,   KC_LCTL, KC_SPC,  RAISE,   LALT_T(KC_BSLS), _______, _______, KC_RGUI}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   +  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  _   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   =  |  1   |   2  |   3  |   4  |   5  |   6  |   7  |  8   |   9  |   0  |  -   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  {   |  [   |   ]  |   }  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_PLUS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS},
  {KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,     KC_8,    KC_9,    KC_0,    KC_MINS},
  {_______, _______, _______, _______, _______, _______, _______, KC_LCBR,  KC_LBRC, KC_RBRC, KC_RCBR, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      | M-!  |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |OS(1) |OS(2) |OS(3) |OS(4) |OS(5) |OS(6) |OS(7) |OS(8) |OS(9) |OS(0) |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  F12 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {_______, LALT(KC_EXLM), _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______},
  {_______, LGUI(KC_1),    LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), LGUI(KC_0), _______},
  {KC_F12,  KC_F1,         KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11 },
  {_______, _______,       _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______}
},

/* Navigation (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | Lock |      |      | End  |      |      |      |      |      |      | Up   | RESET|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Home |      | Del  |Right |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      | PgDn | Left | Down |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAVIGATION] = {
  {KEYLOCK, _______, _______, KC_END,      _______,  _______, _______, _______, _______, _______, KC_UP,   RESET  },
  {_______, KC_HOME, _______, KC_DEL,      KC_RIGHT, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______,     KC_PGDN,  KC_LEFT, KC_DOWN, _______, _______, _______, _______, _______},
  {_______, _______, _______, MO(_PAGEUP), _______,  _______, _______, _______, _______, _______, _______, _______}
},


/* Page Up
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      | M-Up |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |M-Rght|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      | PgUp |M-Left|M-Down|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_PAGEUP] = {
  {_______, _______, _______, _______, _______,        _______,       _______,       _______, _______, _______, LALT(KC_UP), _______},
  {_______, _______, _______, _______, LALT(KC_RIGHT), _______,       _______,       _______, _______, _______, _______,     _______},
  {_______, _______, _______, _______, KC_PGUP,        LALT(KC_LEFT), LALT(KC_DOWN), _______, _______, _______, _______,     _______},
  {_______, _______, _______, _______, _______,        _______,       _______,       _______, _______, _______, _______,     _______}
},
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
	switch (keycode) {
	case LOWER:
		if (record->event.pressed) {
			layer_on(_LOWER);
			update_tri_layer(_LOWER, _RAISE, _NAVIGATION);
		} else {
			layer_off(_LOWER);
			update_tri_layer(_LOWER, _RAISE, _NAVIGATION);
		}
		return false;
		break;
	case RAISE:
		if (record->event.pressed) {
			layer_on(_RAISE);
			update_tri_layer(_LOWER, _RAISE, _NAVIGATION);
		} else {
			layer_off(_RAISE);
			update_tri_layer(_LOWER, _RAISE, _NAVIGATION);
		}
		return false;
		break;
	}
	return true;
}
