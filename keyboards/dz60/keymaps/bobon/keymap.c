#include QMK_KEYBOARD_H
#include "bobon.h"

#define SFT_TAB LSFT(KC_TAB)

#define CTL_T_CAPS  LCTL_T(KC_CAPS)
#define CTL_T_SLCK  LCTL_T(KC_SLCK)

#define CTL_ENT     LCTL(KC_ENT)
#define CTL_SFT_ENT LCTL(LSFT(KC_ENT))

#define CTL_LEFT    LCTL(KC_LEFT)
#define CTL_UP      LCTL(KC_UP)
#define CTL_DOWN    LCTL(KC_DOWN)
#define CTL_RGHT    LCTL(KC_RGHT)

#define CTL_BSPC    LCTL(KC_BSPC)
#define CTL_DEL     LCTL(KC_DEL)


#define NAV_CTL_SFT LM(_NAV, MOD_LCTL | MOD_LSFT)
#define FN_TT       TT(_FN)
#define CFG         MO(_CFG)
#define SYS         MO(_SYS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* BASE
    * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
    * │ESC│01 │02 │03 │04 │05 │06 │07 │08 │09 │10 │ - │ = │ \ │ ` │
    * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
    * │ TAB │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │BSPC │
    * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
    * │CTL/CL│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  ENTER │
    * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
    * │ LS/(   │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │     RS/) │
    * ├────┬───┴┬──┴─┬─┴───┴──┬┴───┼───┴───┴──┬┴───┼───┴┬────┬────┤
    * │MFn │META│LALT│ BSPC   │ Fn │ SPACE    │RALT│RCTL│4d  │CFG │
    * └────┴────┴────┴────────┴────┴──────────┴────┴────┴────┴────┘
    */
	[_BASE] = LAYOUT_60_ansi_split_space_bs(
        KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSLS, KC_GRV ,
        KC_TAB      , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSPC    ,
        CTL_T_CAPS     , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT           ,
        KC_LSPO           , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSPC                ,
        NAV_CTL_SFT, KC_LGUI  , KC_LALT  , KC_BSPC         , FN_TT    , KC_SPC                    , KC_RALT  , KC_RCTL  , KC_GRV   , CFG     ),

    /* NAV
    * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
    * │ESC│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│D11│F12│PRS│PAU│
    * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
    * │S_TAB│m3 │m1 │m^ │m2 │Wh^│Ins│Hom│ ^ │End│   │   │   │ DEL │
    * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
    * │CTL/SL│m4 │m< │mv │m> │Whv│PgU│ < │ v │ > │   │   │C_ENTER │
    * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
    * │ LS/(   │m5 │ma0│ma1│ma2│   │PgD│<< │^^ │vv │>> │ CS_ENTER │
    * ├────┬───┴┬──┴─┬─┴───┴──┬┴───┼───┴───┴──┬┴───┼───┴┬────┬────┤
    * │MFn │META│LALT│ DEL    │ Fn │ SPACE    │RALT│RCTL│4d  │CFG │
    * └────┴────┴────┴────────┴────┴──────────┴────┴────┴────┴────┘
    */
	[_NAV] = LAYOUT_60_ansi_split_space_bs(
        KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_PSCR, KC_PAUS,
        SFT_TAB     , KC_BTN3, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, KC_INS , KC_HOME, KC_UP  , KC_END , XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL     ,
        CTL_T_SLCK     , KC_BTN4, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, CTL_ENT          ,
        _______           , KC_BTN5, KC_ACL0, KC_ACL1, KC_ACL2, KC_NO, KC_PGDN, CTL_LEFT, CTL_UP  , CTL_DOWN, CTL_RGHT, CTL_SFT_ENT          ,
        _______  , _______   , _______  , KC_DEL           , _______  , _______                  , _______  , _______  , _______  , _______  ),

    /* EDIT
    * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
    * │ESC│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│D11│F12│PRS│PAU│
    * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
    * │S_TAB│m3 │m1 │m^ │m2 │Wh^│Ins│Hom│ ^ │End│Bsp│CBs│   │ DEL │
    * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
    * │CTL/SL│m4 │m< │mv │m> │Whv│PgU│ < │ v │ > │Del│Cdl│C_ENTER │
    * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
    * │ LS/(   │m5 │ma0│ma1│ma2│   │PgD│<< │^^ │vv │>> │ CS_ENTER │
    * ├────┬───┴┬──┴─┬─┴───┴──┬┴───┼───┴───┴──┬┴───┼───┴┬────┬────┤
    * │MFn │META│LALT│ DEL    │ Fn │ SPACE    │RALT│RCTL│4d  │CFG │
    * └────┴────┴────┴────────┴────┴──────────┴────┴────┴────┴────┘
    */
    [_EDIT] = LAYOUT_60_ansi_split_space_bs(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______     , _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSPC, CTL_BSPC, _______, _______   ,
        _______        , _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL , CTL_DEL , _______         ,
        _______           , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______                ,
        _______  , _______   , _______  , _______          , _______  , _______                  , _______  , _______  , _______  , _______  ),

    [_FN] = LAYOUT_60_ansi_split_space_bs(
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_PAUS,
        LCTL(KC_TAB), KC_BTN3, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, KC_INS, KC_HOME, KC_UP, KC_END, KC_BSPC, LCTL(KC_BSPC), KC_NO, KC_DEL,
        LCTL_T(KC_SLCK), KC_BTN4, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL, LCTL(KC_DEL), RCTL(KC_ENT),
        _______, KC_BTN5, KC_ACL0, KC_ACL1, KC_ACL2, KC_NO, KC_PGDN, LCTL(KC_LEFT), LCTL(KC_UP), LCTL(KC_DOWN), LCTL(KC_RGHT), RCTL(RSFT(KC_ENT)),
        _______, _______, _______, KC_DEL, _______, KC_NO, _______, _______, _______, _______),

    [_CFG] = LAYOUT_60_ansi_split_space_bs(
        MAGIC_SWAP_GRAVE_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MAGIC_SWAP_BACKSLASH_BACKSPACE, MAGIC_UNSWAP_GRAVE_ESC,
        XXXXXXX     , XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG , RGB_MOD , RGB_RMOD, RGB_VAI , RGB_VAD , RGB_SPI , RGB_SPD , XXXXXXX, XXXXXXX, MAGIC_UNSWAP_BACKSLASH_BACKSPACE,
        MAGIC_SWAP_CONTROL_CAPSLOCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MAGIC_UNNO_GUI, MAGIC_NO_GUI, XXXXXXX, XXXXXXX, XXXXXXX, BL_TOGG, BL_INC , BL_DEC          ,
        XXXXXXX           , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MAGIC_HOST_NKRO, MAGIC_UNHOST_NKRO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX                ,
        MAGIC_UNSWAP_CONTROL_CAPSLOCK, XXXXXXX   , XXXXXXX  , XXXXXXX          , XXXXXXX  , XXXXXXX                  , XXXXXXX  , XXXXXXX  , SYS  , _______  ),

	[_SYS] = LAYOUT_60_ansi_split_space_bs(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX     , XXXXXXX, XXXXXXX, XXXXXXX, RESET   , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX   ,
        XXXXXXX        , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX          ,
        XXXXXXX           , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX                ,
        XXXXXXX  , MAGIC_SWAP_ALT_GUI, MAGIC_UNSWAP_ALT_GUI, XXXXXXX          , XXXXXXX  , XXXXXXX                  , XXXXXXX  , XXXXXXX  , _______  , _______  ),

/*
    [_NEW] = LAYOUT_60_ansi_split_space_bs(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______     , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______    ,
        _______        , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______          ,
        _______           , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______                ,
        _______  , _______   , _______  , _______          , _______  , _______                  , _______  , _______  , _______  , _______  ),

    [_NEW] = LAYOUT_60_ansi_split_space_bs(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX     , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX    ,
        XXXXXXX        , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX          ,
        XXXXXXX           , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX                ,
        XXXXXXX  , XXXXXXX   , XXXXXXX  , XXXXXXX          , XXXXXXX  , XXXXXXX                  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ),
*/
};

