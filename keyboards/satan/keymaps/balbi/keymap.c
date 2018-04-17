#include QMK_KEYBOARD_H

enum balbi_layers {
	BASE_LAYER = 0,
	FUNC_LAYER = 1,
	NAVG_LAYER = 2,
};

#define _______ KC_TRNS
#define GRV_ESC 0
#define KEYLOCK LCTL(LGUI(KC_L))

qk_tap_dance_action_t tap_dance_actions[] = {
	/* Tap once for `, twice for Esc */
	[GRV_ESC]  = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_ESC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE_LAYER] = LAYOUT_60_ansi(
			TD(GRV_ESC),    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC, \
			KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS,	\
			LCTL_T(KC_TAB), KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,         KC_ENT, \
			KC_LSFT,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,         KC_RSFT,	\
			KC_CAPS, KC_LGUI,KC_LALT,                KC_SPC,                                 KC_RALT,KC_RGUI, MO(FUNC_LAYER), MO(NAVG_LAYER)),

	[FUNC_LAYER] = LAYOUT_60_ansi(
			KC_ESC, KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,KC_F12,KC_DEL,				\
			KC_ESC,KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC,KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_UNDS,KC_PLUS,KC_DEL, \
			KC_LCTL,KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0,KC_MINUS,KC_EQL,						\
			KC_F12,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,						\
			_______,KC_LGUI,KC_LALT,                 KC_SPC,                       KC_RALT,KC_RGUI,_______, _______),

	[NAVG_LAYER] = LAYOUT_60_ansi(
			KEYLOCK,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,RESET,		\
			_______,KC_PGUP,KC_PGDN,KC_HOME,KC_END,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
			KC_LCTL,LGUI(KC_1),LGUI(KC_2),LGUI(KC_3),LGUI(KC_4),LGUI(KC_5),LGUI(KC_6),LGUI(KC_7),LGUI(KC_8),LGUI(KC_9),LGUI(KC_0),_______,_______, \
			_______,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,_______,_______,_______,_______,_______,_______,_______, \
			_______,KC_LGUI,KC_LALT,                 KC_SPC,                       KC_RALT,KC_RGUI,_______, _______),
};

