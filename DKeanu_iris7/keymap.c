/* Copyright 2026 Keanu Downard
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

/*
Here is sample code of how to create custom keycodes. Specifically this block of code is an example of how to make one keypress execute two keycodes.


*** This portion here just gives your custom keycodes names ***
enum custom_keycodes {
    DUAL_AB = SAFE_RANGE,
    DUAL_CD,
    DUAL_ENTER_ESC,
};

*** This portion here is a helper funcion that takes in one keycode (your custom one) and executes two keycodes. ***
*** This is technically unnesessary but it makes your code further on look cleaner and more readable ***
void send_dual(uint16_t kc1, uint16_t kc2) {
    tap_code(kc1);
    tap_code(kc2);
}

*** This is where you put custom keycode logic and where our helper function will be used. ***
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case DUAL_AB: send_dual(KC_A, KC_B); return false;
            case DUAL_CD: send_dual(KC_C, KC_D); return false;
            case DUAL_ENTER_ESC: send_dual(KC_ENT, KC_ESC); return false;
        }
    }
    return true;
}

*/

// Now lets try to add the above to out keymap and pray it works.

enum custom_keycodes {
    GAMING = SAFE_RANGE,
    NO_GAMING
};

void send_dual(uint16_t kc1, uint16_t kc2) {
    tap_code(kc1);
    tap_code(kc2);
}

void send_layer_rgb(uint16_t layer, bool rgb) {
    layer_move(layer);
    if (rgb) {
        rgblight_enable();
    } else {
        rgblight_disable();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case GAMING: send_layer_rgb(3, true); return false;
            case NO_GAMING: send_layer_rgb(0, false); return false;
        }
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        // ┌─────────────────────────────────────────── Left Hand ────────────────────────────────────────────┐       ┌─────────────────────────────────────────── Right Hand ───────────────────────────────────────────┐
        KC_NO,           KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                       KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_PSCR,
        KC_TAB,          KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                       KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_DEL,
        KC_ESC,          LGUI_T(KC_A),   LALT_T(KC_S),   LCTL_T(KC_D),   LSFT_T(KC_F),   KC_G,                                       KC_H,           RSFT_T(KC_J),   RCTL_T(KC_K),   RALT_T(KC_L),   RGUI_T(KC_SCLN), KC_BSPC,
        KC_NO,           KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_NO,      KC_NO,          KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,        KC_NO,
                                                                         KC_NO,          MO(1),          KC_SPC,     KC_ENT,         MO(2),          GAMING
    ),

    [1] = LAYOUT(
        KC_F12,          KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                      KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
        KC_NO,           KC_AT,          KC_GRV,         KC_HASH,        KC_TILD,        KC_DLR,                                     KC_EXLM,        KC_LCBR,        KC_RCBR,        KC_UNDS,        KC_PERC,        KC_DEL,
        KC_LCTL,         KC_PLUS,        KC_MINS,        KC_ASTR,        KC_SLSH,        KC_EQL,                                     KC_AMPR,        KC_LPRN,        KC_RPRN,        KC_DQUO,        KC_COLN,        KC_BSPC,
        KC_LSFT,         KC_LT,          KC_GT,          KC_CIRC,        KC_BSLS,        KC_NO,          KC_NO,      KC_NO,          KC_PIPE,        KC_LBRC,        KC_RBRC,        KC_QUOT,        KC_NO,          KC_RSFT,
                                                                         KC_NO,          KC_NO,          KC_SPC,     KC_ENT,         KC_NO,          KC_NO
    ),

    [2] = LAYOUT(
        KC_NO,           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                      KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_NO,           KC_NO,          KC_7,           KC_8,           KC_9,           KC_NO,                                      KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_DEL,
        KC_LCTL,         KC_0,           KC_4,           KC_5,           KC_6,           KC_NO,                                      KC_LEFT,        KC_DOWN,        KC_UP,          KC_RGHT,        KC_PGUP,        KC_BSPC,
        KC_LSFT,         KC_NO,          KC_1,           KC_2,           KC_3,           KC_NO,          KC_NO,      KC_NO,          RM_TOGG,        KC_CAPS,        KC_COMM,        KC_DOT,         KC_PGDN,        KC_RSFT,
                                                                         KC_NO,          KC_NO,          KC_SPC,     KC_ENT,         KC_TRNS,        KC_NO
    ),

    [3] = LAYOUT(
        KC_ESC,          KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                       KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_NO,
        KC_TAB,          KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                       KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_DEL,
        KC_LCTL,         KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                       KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_BSPC,
        KC_LSFT,         KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_NO,      KC_NO,          KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,        KC_RSFT,
                                                                         KC_LALT,        MO(2),          KC_SPC,     KC_ENT,         MO(2),          NO_GAMING
    )
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    // Define encoder mappings here if needed
};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
