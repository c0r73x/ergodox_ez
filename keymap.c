#include QMK_KEYBOARD_H
#include "version.h"
#include "debug.h"
#include "action_layer.h"
#include "os_detection.h"

#define OSX
#ifdef OSX
    #include "keymap_swedish_mac_ansi.h"
    #define OSX_AT A(SE_2)
    #undef SE_AT
    #define SE_AT OSX_AT
#else
    #include "keymap_swedish.h"
#endif
#include "keymap_nordic.h"

#define KC_TRNS KC_TRANSPARENT
#define KEYMAP LAYOUT_ergodox

enum layers {
    BASE, // default layer
    SYMB, // symbols
    MUSE, // mouse control
    NUMP, // numpad
    GAME, // qwertyish for games
    // POE, // Path of Exile
};

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE, // can always be here
    EPRM,
    VRSN,
    RGB_SLD,
    APQU, // '"
    TILD_SE, // ~
    CIRC, // ^
    ACUT, // ´
    GRAV, // `
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = KEYMAP(
        // left hand
        GRAV,      KC_7,     KC_5,        KC_3,        KC_1,        KC_9, KC_MEDIA_PLAY_PAUSE,
        KC_TAB,    SE_ARNG,  SE_ADIA,     SE_ODIA,     KC_P,        KC_Y, KC_DELETE,
        KC_ESCAPE, KC_A,     GUI_T(KC_O), ALT_T(KC_E), CTL_T(KC_U), KC_I,
        LSFT_T(KC_HOME),   KC_DOT,   KC_Q,        KC_J,        KC_K,        KC_X, LSFT(KC_INSERT),
        KC_LCTL,   KC_LALT,  KC_UP,       KC_RIGHT,    KC_LGUI,
        KC_AUDIO_VOL_DOWN,   KC_AUDIO_VOL_UP,
        KC_HOME,
        LSFT_T(KC_SPACE), KC_TAB, LT(NUMP, KC_END),
        // right hand
        KC_PSCR,    KC_0,     KC_2,         KC_4,        KC_6,         KC_8, ACUT,
        TG(GAME),   KC_F,     KC_G,         KC_C,        KC_R,         KC_L, APQU,
                    KC_D,     RCTL_T(KC_H), ALT_T(KC_T), RGUI_T(KC_N), KC_S, SE_MINS,
        KC_NO,      KC_B,     KC_M,         KC_W,        KC_V,         KC_Z, RSFT_T(KC_END),
        MO(SYMB),   MO(MUSE), TG(NUMP),     KC_RALT,     KC_RCTL,
        KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK,
        KC_PGUP,
        KC_PGDN, KC_BSPC, RSFT_T(KC_ENTER)
    ),

    [GAME] = KEYMAP(
        // left hand
        KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_TRNS,
        KC_TRNS, KC_T,    KC_Q,    KC_W,    KC_E,    KC_R, KC_TRNS,
        KC_TRNS, KC_G,    KC_A,    KC_S,    KC_D,    KC_F,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_SPACE, KC_TRNS, KC_TRNS,
        // right hand
        KC_TRNS, KC_6,    KC_7,    KC_8,     KC_9,    KC_0,    SE_PLUS,
        KC_TRNS, KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,    SE_ARNG,
                 KC_H,    KC_J,    KC_K,     KC_L,    SE_ODIA, SE_ADIA,
        KC_TRNS, KC_N,    KC_M,    KC_COMMA, KC_DOT,  SE_MINS, KC_RSFT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_ENTER
    ),

    // [POE] = KEYMAP(
    //     // left hand
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //     KC_TRNS, KC_T,    KC_Q,    KC_W,    KC_E,    KC_R, KC_TRNS,
    //     KC_TRNS, KC_TRNS, KC_A,    KC_S,    KC_D,    KC_5,
    //     KC_TRNS, KC_Z,    KC_TRNS, KC_TRNS, KC_1,    KC_2, KC_TRNS,
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_C,    KC_B,
    //     KC_TRNS, KC_TRNS,
    //     KC_TRNS,
    //     KC_3,    KC_4,    KC_TAB,
    //     // right hand
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //     KC_TRNS, KC_TRNS,
    //     KC_TRNS,
    //     KC_TRNS, KC_TRNS, KC_TRNS
    // ),

    [SYMB] = KEYMAP(
        // left hand
        KC_TRNS, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
        KC_TRNS, SE_LBRC,  SE_RBRC, SE_LPRN, SE_RPRN, SE_QUES, KC_TRNS,
        KC_TRNS, SE_LCBR,  SE_RCBR, SE_BSLS, SE_SLSH, KC_EXLM,
        KC_TRNS, KC_COMMA, SE_SCLN, SE_AT,   SE_ASTR, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
        RGB_MOD,  KC_TRNS,
        KC_TRNS,
        RGB_VAD, RGB_VAI, KC_F11,
        // right hand
        KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
        KC_TRNS, SE_PND,  SE_EURO, SE_DLR,  SE_AMPR, SE_PIPE, CIRC,
                 KC_DLR,  KC_NUBS, S(KC_NUBS), SE_EQL,  TILD_SE,    SE_PLUS,
        KC_TRNS, KC_PERC, KC_HASH, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        RGB_TOG, RGB_SLD,
        KC_TRNS,
        KC_F12,   RGB_HUD, RGB_HUI
    ),

    [MUSE] = KEYMAP(
        // left hand
        KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,    KC_MS_UP,   KC_TRNS,     KC_TRNS, KC_TRNS,
        KC_TRNS, KC_WH_L, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_WH_R,
        KC_TRNS, KC_TRNS, KC_TRNS,    KC_WH_D,    KC_WH_U,     KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN3,
        // right hand
        KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,      KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_MS_BTN3, KC_MS_BTN2, KC_MS_BTN1
    ),

    [NUMP] = KEYMAP(
        // left hand
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS,  KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        // right hand
        KC_NUM_LOCK, KC_TRNS,  KC_TRNS, KC_KP_SLASH, KC_KP_ASTERISK, KC_TRNS,     KC_TRNS,
        KC_TRNS,     KC_TRNS,  KC_KP_7, KC_KP_8,     KC_KP_9,        KC_KP_MINUS, KC_TRNS,
                     KC_TRNS,  KC_KP_4, KC_KP_5,     KC_KP_6,        KC_KP_PLUS,  KC_TRNS,
        KC_TRNS,     KC_TRNS,  KC_KP_1, KC_KP_2,     KC_KP_3,        KC_EQUAL,    KC_TRNS,
        KC_KP_0,     KC_COMMA, KC_TRNS, KC_TRNS,     KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    ),

};

#define COMBO_NO_TIMER

const uint16_t PROGMEM rshift_combo[] = {RCTL_T(KC_H), ALT_T(KC_T), COMBO_END};
const uint16_t PROGMEM lshift_combo[] = {ALT_T(KC_E), CTL_T(KC_U), COMBO_END};
const uint16_t PROGMEM back_word_combo[] = {GUI_T(KC_O), ALT_T(KC_E), CTL_T(KC_U), COMBO_END};

combo_t key_combos[] = {
    COMBO(lshift_combo, KC_LSFT),
    COMBO(rshift_combo, KC_RSFT),
    COMBO(back_word_combo, LALT(KC_BSPC))
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

void matrix_init_user(void)
{
    #ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
    #endif
};

void press_key_with_level_mods(uint16_t key) {
    const uint8_t interesting_mods = MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT) | MOD_BIT(KC_RALT);

    // Save the state
    const uint8_t real_mods = get_mods();
    const uint8_t weak_mods = get_weak_mods();
    /* const uint8_t macro_mods = get_macro_mods(); */

    uint8_t target_mods = (key >> 8) & (QK_MODS_MAX >> 8);
    // The 5th bit indicates that it's a right hand mod,
    // which needs some fixup
    if (target_mods & 0x10) {
        target_mods &= 0xF;
        target_mods <<= 4;
    }

    // Clear the mods that we are potentially going to modify,
    del_mods(interesting_mods);
    del_weak_mods(interesting_mods);
    /* del_macro_mods(interesting_mods); */

    // Enable the mods that we need
    add_mods(target_mods & interesting_mods);

    // Press and release the key
    register_code(key & 0xFF);
    unregister_code(key & 0xFF);

    // Restore the previous state
    set_mods(real_mods);
    set_weak_mods(weak_mods);
    /* set_macro_mods(macro_mods); */
    send_keyboard_report();
}

bool override_key(keyrecord_t *record, uint16_t normal, uint16_t shifted)
{
    const uint8_t shift = MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT);
    // Todo, should maybe also check at least the weak mods
    uint8_t current_mods = get_mods();

    if (record->event.pressed) {
        // Todo share this code with send keyboard report
        #ifndef SE_ACTION_ONESHOT
        if (get_oneshot_mods()) {
            #if (defined(ONESHOT_TIMEOUT) && (ONESHOT_TIMEOUT > 0))

            if (has_oneshot_mods_timed_out()) {
                dprintf("Oneshot: timeout\n");
                clear_oneshot_mods();
            }

            #endif
            current_mods |= get_oneshot_mods();
            clear_oneshot_mods();
        }

        #endif
        bool shift_pressed = current_mods & shift;
        const uint16_t target = shift_pressed ? shifted : normal;
        uint8_t keycode = target & 0xFF;

        if (keycode == KC_NO) {
            return false;
        }

        press_key_with_level_mods(target);
    }

    return false;
}

static bool wake_dead_key(uint16_t keycode, keyrecord_t *record)
{
    if (record->event.pressed) {
        register_code16(keycode);
        unregister_code16(keycode);
        register_code16(KC_SPACE);
        unregister_code16(KC_SPACE);
    }

    // Let QMK handle onshots
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode) {
        // dynamically generate these.
        case EPRM:
            if (record->event.pressed) {
                eeconfig_init();
            }

            return false;
            break;

        case VRSN:
            if (record->event.pressed) {
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
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

        case APQU:
            return override_key(record, NO_APOS, NO_QUO2);

        case TILD_SE:
            return wake_dead_key(SE_TILD, record);

        case CIRC:
            return wake_dead_key(SE_CIRC, record);

        case ACUT:
            return wake_dead_key(SE_ACUT, record);

        case GRAV:
            return wake_dead_key(SE_GRV, record);
    }

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state)
{

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    switch (layer) {
        case 0:
            #ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
            #endif
            break;

        case 1:
            ergodox_right_led_1_on();
            #ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
            #endif
            break;

        case 2:
            ergodox_right_led_2_on();
            #ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
            #endif
            break;

        case 3:
            ergodox_right_led_3_on();
            #ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
            #endif
            break;

        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            #ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
            #endif
            break;

        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            #ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
            #endif
            break;

        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            #ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
            #endif
            break;

        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            #ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
            #endif
            break;

        default:
            break;
    }

    return state;

};
