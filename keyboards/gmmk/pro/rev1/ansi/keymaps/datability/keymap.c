/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum custom_keycodes {
    REPO1 = SAFE_RANGE,
    REPO2,
    REPO3,
    REPO4,
    REPO5,
    REPO6,
    REPO7,
    REPO8,
    CH_ADDR,
    TEST_ALL,
    APP_LIST,
    QUICK_COMMIT,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case REPO1:
            if (record->event.pressed) {
                // when keycode REPO1 is pressed
                SEND_STRING("code ~/src/powerhouse-proto/\n");
            } else {
                // when keycode REPO1 is released
            }
            break;
        case REPO2:
            if (record->event.pressed) {
                SEND_STRING("code ~/src/powerhouse-dsl/\n");
            } else {
            }
            break;
        case REPO3:
            if (record->event.pressed) {
                SEND_STRING("code ~/src/powerhouse-pyspark/\n");
            } else {
            }
            break;
        case REPO4:
            if (record->event.pressed) {
                SEND_STRING("code ~/src/powerhouse-pipelines/\n");
            } else {
            }
            break;
        case REPO5:
            if (record->event.pressed) {
                SEND_STRING("code ~/src/powerhouse-backend/\n");
            } else {
            }
            break;
        case REPO6:
            if (record->event.pressed) {
                SEND_STRING("code ~/src/powerhouse-airflow-plugin/\n");
            } else {
            }
            break;
        case REPO7:
            if (record->event.pressed) {
                SEND_STRING("code ~/src/di-airflow2-test/\n");
            } else {
            }
            break;
        case REPO8:
            if (record->event.pressed) {
                SEND_STRING("code ~/psrc/qmk_firmware/\n");
            } else {
            }
            break;
        case CH_ADDR:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("l"));
            } else {
            }
            break;
        case TEST_ALL:
            if (record->event.pressed) {
                SEND_STRING("coverage run -m pytest && coverage report -m\n");
            } else {
            }
            break;
        case APP_LIST:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_DOWN)));
            } else {
            }
            break;
        case QUICK_COMMIT:
            if (record->event.pressed) {
                SEND_STRING("git commit -m \"quick commit\"\n");
            } else {
            }
            break;
    }
    return true;
};


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the QK_BOOT key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    [0] = LAYOUT(
        KC_ESC,  CH_ADDR, KC_F2,           KC_MISSION_CONTROL,   APP_LIST,      KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  TEST_ALL,  KC_PSCR,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,            KC_3,                 KC_4,          KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,    KC_BSPC,          REPO1,
        KC_TAB,  KC_Q,    KC_W,            KC_E,                 KC_R,          KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,   KC_BSLS,          REPO2,
        KC_CAPS, KC_A,    KC_S,            KC_D,                 KC_F,          KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,            KC_ENT,           REPO3,
        KC_LSFT,          KC_Z,            KC_X,                 KC_C,          KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,            KC_RSFT, KC_UP,   REPO4,
        KC_LCTL, KC_LGUI, KC_LALT,                               KC_SPC,                              KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN,   KC_RGHT
    ),

    [1] = LAYOUT(
        _______, KC_MYCM, KC_WHOM,         KC_CALC,              KC_MSEL,       KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, _______,   _______,          RGB_TOG,
        _______, _______, _______,         _______,              _______,       _______, _______, _______, _______, _______, _______, _______, _______,   KC_DEL,           REPO5,
        _______, RGB_TOG, RGB_VAI,         _______,              _______,       _______, _______, _______, _______, _______, _______, _______, _______,   QK_BOOT,          REPO6,
        _______, RGB_HUI, RGB_VAD,         _______,              _______,       _______, _______, _______, _______, _______, _______, _______,            _______,          REPO7,
        _______,          _______,         _______,              QUICK_COMMIT,  _______, _______, NK_TOGG, _______, _______, _______, _______,            _______, RGB_MOD, REPO8,
        _______, _______, _______,                               _______,                             _______, _______, _______, RGB_SPD, RGB_RMOD,  RGB_SPI
    ),


};
// clang-format on

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif
