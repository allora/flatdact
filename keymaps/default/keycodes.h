#pragma once

#include QMK_KEYBOARD_H

#include "quantum.h"

//uint8_t mod_state;
uint16_t startup_timer;
uint16_t one_shot_timer;

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   m a c r o n a m e s                         │
// └───────────────────────────────────────────────────────────┘

#define OSM_CTL OSM(MOD_RCTL)
#define OSM_ALT OSM(MOD_RALT)
#define OSM_GUI OSM(MOD_RGUI)
#define OSM_SFT OSM(MOD_RSFT)

#define _ KC_TRNS
#define DEL KC_DELETE
#define BSP KC_BSPC
#define GRV KC_GRV
#define PLS KC_PLUS
#define MNS KC_MINS
#define TIL KC_TILD
#define PI  KC_PIPE
#define LPAR KC_LPRN
#define TTY1 LCA(KC_F1)
#define TTY2 LCA(KC_F2)
#define CW  LCTL(KC_W)
#define RSE OSL(_RAISE)
#define CTLC LCTL_T(KC_C)
#define ALTM RALT_T(KC_M)
#define ALTV LALT_T(KC_V)
#define LR_Z LT(_RAISE, KC_Z)
#define LL_P LT(_LOWER, KC_P)
#define N_QUOT LT(NAV, KC_QUOT)
#define NV_A LT(NAV, KC_A)
#define FN_Q LT(_FN, KC_Q)

#define WH_L KC_WH_L
#define WH_R KC_WH_R
#define WH_U KC_WH_U
#define WH_D KC_WH_D

#define KB_L KC_LEFT
#define KB_R KC_RIGHT
#define KB_D KC_DOWN
#define KB_U KC_UP

#define MB1 KC_BTN1
#define MB2 KC_BTN2
#define MB3 KC_BTN3


// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   k e y c o d e s                             │
// └───────────────────────────────────────────────────────────┘

enum custom_keycodes {
    REPEAT = SAFE_RANGE,
    CAPSWORD,
    NXTSEN,
    XCASE,
    VIM,
    UPB,
    EXBASH,
    DLRAWK,
    QUOTES,
    COLNQU,
    BRACES0,
    BRACES1,
    MRKDWN1,
    MRKDWN2,
    ZERO000,
    MR_gui,
    ML_alt,
    ML_ctl,
    ML_sft,
    MR_sft
};
