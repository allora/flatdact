#include QMK_KEYBOARD_H
#include <stdio.h>
#include <string.h>
#include "flatdact.h"
#include "keycodes.h"
#include "../../features/custom_oneshot.h"
#include "../../features/custom_shift_keys.h"
//#include "../../features/caps_word.h"
#include "../../features/case_modes.h"

// Mouse CPI settings
#define DEFAULT_CPI 1000
#define SCROLLING_CPI 500
#define PRECISION_CPI 100
#define SCROLLING_POINTER_SPEED_MULTIPLIER 0.5

const custom_shift_key_t custom_shift_keys[] = {
  {KC_DOT , KC_QUES}, // . Shift: ?
  {KC_COMM, KC_EXLM}, // , Shift: !
  {KC_SLSH, KC_BSLS}, // "/" Shift: "\"
  {KC_PLUS, KC_EQL}, // + Shift: =
  {KC_UNDS, KC_MINUS}, // _ Shift: -
  {KC_COLN, KC_SCLN}, // : Shift: ;
  {KC_GT, KC_EQL}, // > Shift: =
  {KC_LT, KC_UNDS}, // < Shift: _
  {KC_TILD, KC_GRV}, // ~ Shift: `
  //━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  {KC_AMPR, KC_QUES},
  {KC_AT, KC_LBRC},   // @# Shift: []
  {KC_HASH, KC_RBRC},
  {KC_PERC, KC_LCBR}, // %^ Shift: {}
  {KC_CIRC, KC_RCBR},
  {KC_ASTR, KC_LT}, // * Shift: <
  {KC_PIPE, KC_GT} // | Shift: >
};

// layer list{{{
enum klor_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    NAV,
    _FN
};

uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);
/*}}}*/


#define COM LT(NAV, KC_COMM)
#define DOT LT(_FN, KC_DOT)
#define LEFT1 LSFT_T(KC_TAB)
#define LEFT2 MT(MOD_LGUI, KC_ENT)
#define RIGHT1 MT(MOD_RCTL, KC_SPC)
#define RIGHT2 LT(_FN, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_QWERTY] = LAYOUT(
//┏━━━━━━┳━━━━━━━━┳━━━━━━━━┳━━━━━━━━┳━━━━━━━━┓   ┏━━━━━━┳━━━━━━━┳━━━━━━━┳━━━━━━━━┳━━━━━━━━━━┓
    FN_Q ,  KC_W  ,  KC_E  ,  KC_R  ,  KC_T  ,     KC_Y ,  KC_U ,  KC_I ,  KC_O  ,  LL_P    ,
    NV_A ,  KC_S  ,  KC_D  ,  KC_F  ,  KC_G  ,     KC_H ,  KC_J ,  KC_K ,  KC_L  ,  N_QUOT  ,
    LR_Z ,  KC_X  ,  CTLC  ,  ALTV  ,  KC_B  ,     KC_N ,  ALTM ,   COM ,   DOT  ,  REPEAT  ,
//┗━━━━━━┻━━━━━━━━┻━━━━━━━━┻━━━━━━━━┻━━━━━━━━┛   ┗━━━━━━┻━━━━━━━┻━━━━━━━┻━━━━━━━━┻━━━━━━━━━━┛
             _, LEFT1,  LEFT2,  MO(_LOWER),        RIGHT2,MO(_RAISE),  RIGHT1, KC_MUTE
),
 [_LOWER] = LAYOUT(
//┏━━━━┳━━━━━━━━┳━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓   ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━┳━━━━━━━━┳━━━━━┓
   LPAR, KC_RPRN, EXBASH , KC_AT   , KC_HASH ,     KC_UNDS , KC_MINS , KC_TAB , KC_ENT , BSP ,
    TIL, KC_SLSH, DLRAWK , KC_PERC , KC_CIRC ,     QUOTES  ,  MR_sft , MR_gui , ML_ctl , DEL ,
   TTY1,    TTY2, KC_AMPR, KC_ASTR , KC_PIPE ,     KC_EQL  ,  ML_alt ,  XCASE , NXTSEN ,   _ ,
//┗━━━━┻━━━━━━━━┻━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛   ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━┻━━━━━━━━┻━━━━━┛
                  QK_BOOT,  KC_ESC,  _,  _,        _,  _,  _,  KC_MPLY
),
 [_RAISE] = LAYOUT(
//┏━━━━━┳━━━━━━━━━┳━━━━━━━━┳━━━━━━━━┳━━━━━━━━┓   ┏━━━━━━━━┳━━━━━━━━━┳━━━━━━━━┳━━━━━━━━━┳━━━━━┓
    MNS , ZERO000 ,  KC_1  ,  KC_2  ,  KC_3  ,     KC_LT  , BRACES0 , BRACES1,  COLNQU , BSP ,
    PLS , KC_SLSH ,  KC_4  ,  KC_5  ,  KC_6  ,     KC_SCLN,  MR_sft ,  MR_gui,  ML_ctl , GRV ,
    GRV , KC_ASTR ,  KC_7  ,  KC_8  ,  KC_9  ,     KC_GT  ,  ML_alt , KC_SLSH, KC_CAPS , PI  ,
//┗━━━━━┻━━━━━━━━━┻━━━━━━━━┻━━━━━━━━┻━━━━━━━━┛   ┗━━━━━━━━┻━━━━━━━━━┻━━━━━━━━┻━━━━━━━━━┻━━━━━┛
             _,  OSM_CTL,  OSM_ALT,  OSM_GUI,      _,  _,  _,  QK_BOOT
),
  [_FN] = LAYOUT(
//┏━━━━━━━━┳━━━━━━━━┳━━━━━━━┳━━━━━━━━┳━━━━━━━┓   ┏━━━━━━━━━┳━━━━━━━┳━━━━━━━┳━━━━━━━┳━━━━━━━━━┓
    KC_F10 , KC_F1  , KC_F2 ,  KC_F3 ,  MB3  ,     ZERO000 ,  KC_1 ,  KC_2 ,  KC_3 , KC_MINS ,
    KC_F11 , KC_F4  , KC_F5 ,  KC_F6 ,  MB1  ,     KC_SLSH ,  KC_4 ,  KC_5 ,  KC_6 , KC_PLUS ,
    KC_F12 , KC_F7  , KC_F8 ,  KC_F9 ,  MB2  ,     KC_ASTR ,  KC_7 ,  KC_8 ,  KC_9 ,  KC_DOT ,
//┗━━━━━━━━┻━━━━━━━━┻━━━━━━━┻━━━━━━━━┻━━━━━━━┛   ┗━━━━━━━━━┻━━━━━━━┻━━━━━━━┻━━━━━━━┻━━━━━━━━━┛
                _, OSM_GUI,  OSM_CTL,OSM_ALT,      OSM_GUI, OSM_SFT,OSM_CTL, _
 ),
  [NAV] = LAYOUT(
//┏━━━━━━┳━━━━━━━━┳━━━━━━━━┳━━━━━━━━┳━━━━━━━━┓   ┏━━━━━━━━━┳━━━━━━━━┳━━━━━━━━━┳━━━━━━━━┳━━━━━┓
    UPB  ,   MB3  ,   MB1  ,   MB2  ,   MB1  ,     MB1     ,  MB2   ,    MB3  ,    BSP ,  CW ,
    RSE  ,  KB_L  ,  KB_D  ,  KB_U  ,  KB_R  ,     KB_L    ,  KB_D  ,   KB_U  ,   KB_R ,   _ ,
    VIM  ,  WH_L  ,  WH_D  ,  WH_U  ,  WH_R  ,     MRKDWN1 ,MRKDWN2 , KC_HOME , KC_END ,   _ ,
//┗━━━━━━┻━━━━━━━━┻━━━━━━━━┻━━━━━━━━┻━━━━━━━━┛   ┗━━━━━━━━━┻━━━━━━━━┻━━━━━━━━━┻━━━━━━━━┻━━━━━┛
                _, OSM_ALT,  OSM_CTL,OSM_SFT,      OSM_SFT, OSM_CTL,OSM_ALT, _
),

};
// ┌───────────────────────────────────────────────────────────────────────────────┐
// │                             e n c o d e r s                                   │
// │  BASE:  Left: wheel up/down         ┃   Right: volume up/down                 │
// │  LOWER: Left: page up/down          ┃   Right: zoom (ctrl +/-)                │
// │  RAISE: Left: arrow left/right      ┃   Right: page up/down                   │
// │  NAV:   Left: fast forward/rewind   ┃   Right: brightness up/down             │
// │  _FN:   Left: next/previous         ┃   Right: find next/prv (ctrl+g/+sft+g)  │
// └───────────────────────────────────────────────────────────────────────────────┘


// left and right encoders {{{
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case 0: // base
            if (index == 0) { // left
                if (clockwise) {
                    tap_code(KC_WH_U);
                } else {
                    tap_code(KC_WH_D);
                }
            } else if (index == 1) { // right
                if (clockwise) {
                    tap_code(KC_VOLD);
                } else {
                    tap_code(KC_VOLU);
                }
            }
            break;
        case 1: // lower
            if (index == 0) { // left
                if (clockwise) {
                    tap_code(KC_PGUP);
                } else {
                    tap_code(KC_PGDN);
                }
            } else if (index == 1) { // right
                if (clockwise) {
                    tap_code16(C(KC_MINUS));
                } else {
                    tap_code16(C(KC_PLUS));
                }
            }
            break;
        case 2: // raise
            if (index == 0) { // left
                if (clockwise) {
                    tap_code(KC_LEFT);
                } else {
                    tap_code(KC_RIGHT);
                }
            } else if (index == 1) { // right
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
            }
            break;
        case 3: // NAV
            if (index == 0) { // left
                if (clockwise) {
                    tap_code(KC_MFFD);
                } else {
                    tap_code(KC_MRWD);
                }
            } else if (index == 1) { // right
                if (clockwise) {
                    tap_code(KC_BRID);
                } else {
                    tap_code(KC_BRIU);
                }
            }
            break;
        case 4: // _FN
            if (index == 0) { // left
                if (clockwise) {
                    tap_code(KC_MNXT);
                } else {
                    tap_code(KC_MPRV);
                }
            } else if (index == 1) { // right
                if (clockwise) {
                    tap_code16(C(KC_G));
                } else {
                    tap_code16(C(S(KC_G)));
                }
            }
            break;
    }
    return false;
}
/*}}}*/

// Used to extract the basic tapping keycode from a dual-role key.
// Example: GET_TAP_KC(MT(MOD_RSFT, KC_E)) == KC_E
#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF
uint16_t last_keycode = KC_NO;
uint8_t last_modifier = 0;

// Initialize variables holding the bitfield
// representation of active modifiers.
uint8_t mod_state;
uint8_t oneshot_mod_state;

void process_repeat_key(uint16_t keycode, const keyrecord_t *record) {
    if (keycode != REPEAT) {
        // Early return when holding down a pure layer key
        // to retain modifiers
        switch (keycode) {
            case QK_DEF_LAYER ... QK_DEF_LAYER_MAX:
            case QK_MOMENTARY ... QK_MOMENTARY_MAX:
            case QK_LAYER_MOD ... QK_LAYER_MOD_MAX:
            case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
            case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
            case QK_TO ... QK_TO_MAX:
            case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX:
                return;
        }
        last_modifier = oneshot_mod_state > mod_state ? oneshot_mod_state : mod_state;
        switch (keycode) {
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
                if (record->event.pressed) {
                    last_keycode = GET_TAP_KC(keycode);
                }
                break;
            default:
                if (record->event.pressed) {
                    last_keycode = keycode;
                }
                break;
        }
    } else { // keycode == REPEAT
        if (record->event.pressed) {
            register_mods(last_modifier);
            register_code16(last_keycode);
        } else {
            unregister_code16(last_keycode);
            unregister_mods(last_modifier);
        }
    }
}


bool process_record_send_string(uint16_t keycode, keyrecord_t *record) {
    process_repeat_key(keycode, record);
    // It's important to update the mod variables *after* calling process_repeat_key,
    // or else only a single modifier from the previous key is repeated
    // (e.g. Ctrl+Shift+T then Repeat produces Shift+T)
    mod_state = get_mods();
    oneshot_mod_state = get_oneshot_mods();

    switch (keycode) {
    case LT(NAV, KC_COMM):
        clear_mods();
        clear_oneshot_mods();
        if ((mod_state | oneshot_mod_state) & MOD_MASK_SHIFT) {
                if (record->tap.count && record->event.pressed) {
            register_code16(KC_EXLM);
        } else if (record->event.pressed) {
            register_code16(KC_EXLM);
        }
            unregister_code16(KC_EXLM);
            set_mods(mod_state);
            return false;
        }
        break;
    case LT(_FN, KC_DOT):
        clear_mods();
        clear_oneshot_mods();
        if ((mod_state | oneshot_mod_state) & MOD_MASK_SHIFT) {
                if (record->tap.count && record->event.pressed) {
            register_code16(KC_QUES);
        } else if (record->event.pressed) {
            register_code16(KC_QUES);
        }
            unregister_code16(KC_QUES);
            set_mods(mod_state);
            return false;
        }
        break;
    case XCASE:
        if (record->event.pressed) {
            enable_xcase();
        }
        return false;
        break;
    case NXTSEN:  // Next sentence: inserts a period, space, then shift for next letter.
      if (record->event.pressed) {
        SEND_STRING(". ");
        add_oneshot_mods(MOD_BIT(KC_LSFT));  // Set one-shot mod for shift.
      }
        break; // macros / macroes
    case EXBASH: // shift: ="$()" || alt: "$()" || ctrl: ="$(
      if (record->event.pressed) { // useful for bash scripting/variables.
        clear_mods();
        clear_oneshot_mods();
        if ((mod_state | oneshot_mod_state) & MOD_MASK_SHIFT) {
          SEND_STRING("=\"$()\"");
        tap_code(KC_LEFT);
        tap_code(KC_LEFT);
        } else if ((mod_state | oneshot_mod_state) & MOD_MASK_ALT) {
          SEND_STRING("\"$()\"");
        tap_code(KC_LEFT);
        tap_code(KC_LEFT);
        } else if ((mod_state | oneshot_mod_state) & MOD_MASK_CTRL) {
          SEND_STRING("=\"$(");
        } else {
          SEND_STRING("!");
        }
        set_mods(mod_state);
      }
        break; // vim macro for repeating previous commands...
    case VIM: // types ':', line up/back, enter, then quick save+quit binding.
      if (record->event.pressed) {
        SEND_STRING(":");
        tap_code(KC_UP);
        SEND_STRING(SS_TAP(X_ENT));
        SEND_STRING(SS_LSFT("x"));
      }
        break; // increments for instance: buku -w 8848 to 8849 in one keypress.
    case UPB: // go up and back in command history in terminal
      if (record->event.pressed) {
        tap_code(KC_UP);
        SEND_STRING(SS_LCTL("xe")); // readline bindings for edit then run cmd
        SEND_STRING("$"); // go to end of line in vim
        SEND_STRING(SS_LCTL("a")); // increment number up in vim
        SEND_STRING(SS_LSFT("x")); // quick save+quit binding
      }
        break;
    case DLRAWK: // Types `'{}'` || useful for awk.
      if (record->event.pressed) {
        clear_mods();
        clear_oneshot_mods();
        if ((mod_state | oneshot_mod_state) & MOD_MASK_SHIFT) {
          SEND_STRING("'{}'");
        tap_code(KC_LEFT);
        tap_code(KC_LEFT);
        } else {
          SEND_STRING("$");
        }
        set_mods(mod_state);
      }
        break;
    case COLNQU:  // Types : but still "", or '', and puts cursor between.
      if (record->event.pressed) {
        clear_mods();  // Temporarily disable mods.
        clear_oneshot_mods();
        if ((mod_state | oneshot_mod_state) & MOD_MASK_ALT) {
          SEND_STRING("''");
        tap_code(KC_LEFT);  // Move cursor between quote marks.
        } else if ((mod_state | oneshot_mod_state) & MOD_MASK_CTRL) {
          SEND_STRING("\"\"");
        tap_code(KC_LEFT);  // Move cursor between quote marks.
        } else if ((mod_state | oneshot_mod_state) & MOD_MASK_SHIFT) {
          SEND_STRING("\"");
        } else if ((mod_state | oneshot_mod_state) & MOD_MASK_GUI) {
          SEND_STRING("`");
        } else {
          SEND_STRING(":");
        }
        set_mods(mod_state);  // Restore mods.
      }
        break;
    case QUOTES:  // Types "", or '', and puts cursor between quote marks.
      if (record->event.pressed) {
        clear_mods();  // Temporarily disable mods.
        clear_oneshot_mods();
        if ((mod_state | oneshot_mod_state) & MOD_MASK_ALT) {
          SEND_STRING("''");
        tap_code(KC_LEFT);  // Move cursor between quote marks.
        } else if ((mod_state | oneshot_mod_state) & MOD_MASK_CTRL) {
          SEND_STRING("\"\"");
        tap_code(KC_LEFT);  // Move cursor between quote marks.
        } else if ((mod_state | oneshot_mod_state) & MOD_MASK_SHIFT) {
          SEND_STRING("\"");
        } else if ((mod_state | oneshot_mod_state) & MOD_MASK_GUI) {
          SEND_STRING("`");
        } else {
          SEND_STRING("'");
        }
        set_mods(mod_state);  // Restore mods.
      }
        break;
    case BRACES1:
      if (record->event.pressed) {
        clear_mods();  // Temporarily disable mods.
        clear_oneshot_mods();
        if ((mod_state | oneshot_mod_state) & MOD_MASK_SHIFT) {
          SEND_STRING("}");
        } else if ((mod_state | oneshot_mod_state) & MOD_MASK_CTRL) {
          SEND_STRING(")");
        } else if ((mod_state | oneshot_mod_state) & MOD_MASK_GUI) {
          SEND_STRING("<>");
        tap_code(KC_LEFT);  // Move cursor between braces.
        } else if ((mod_state | oneshot_mod_state) & MOD_MASK_ALT) {
          SEND_STRING("()");
        tap_code(KC_LEFT);  // Move cursor between braces.
        } else {
          SEND_STRING("]");
        }
        set_mods(mod_state);  // Restore mods.
      }
        break;
    case BRACES0:
      if (record->event.pressed) {
        clear_mods();  // Temporarily disable mods.
        clear_oneshot_mods();
        if ((mod_state | oneshot_mod_state) & MOD_MASK_SHIFT) {
          SEND_STRING("{");
        } else if ((mod_state | oneshot_mod_state) & MOD_MASK_CTRL) {
          SEND_STRING("(");
        } else if ((mod_state | oneshot_mod_state) & MOD_MASK_GUI) {
          SEND_STRING("()");
        tap_code(KC_LEFT);  // Move cursor between braces.
        } else if ((mod_state | oneshot_mod_state) & MOD_MASK_ALT) {
          SEND_STRING("[]");
        tap_code(KC_LEFT);  // Move cursor between braces.
        } else {
          SEND_STRING("[");
        }
        set_mods(mod_state);  // Restore mods.
      }
        break;
     case MRKDWN2:  // {}, shift: <>, ctrl: ``, alt: **
      if (record->event.pressed) {
        clear_mods();  // Temporarily disable mods.
        clear_oneshot_mods();
        if ((mod_state | oneshot_mod_state) & MOD_MASK_SHIFT) {
          SEND_STRING("<>");
        } else if ((mod_state | oneshot_mod_state) & MOD_MASK_CTRL) {
          SEND_STRING("**");
        } else if ((mod_state | oneshot_mod_state) & MOD_MASK_ALT) {
          SEND_STRING("``");
        } else {
          SEND_STRING("{}");
        }
        tap_code(KC_LEFT);  // Move cursor between braces.
        set_mods(mod_state);  // Restore mods.
      }
        break;
    case MRKDWN1:  // (), shift: [], ctrl: __, alt: ~~
      if (record->event.pressed) {
        clear_mods();  // Temporarily disable mods.
        clear_oneshot_mods();
        if ((mod_state | oneshot_mod_state) & MOD_MASK_SHIFT) {
          SEND_STRING("[]");
        } else if ((mod_state | oneshot_mod_state) & MOD_MASK_CTRL) {
          SEND_STRING("__");
        } else if ((mod_state | oneshot_mod_state) & MOD_MASK_ALT) {
          SEND_STRING("~~");
        } else {
          SEND_STRING("()");
        }
        tap_code(KC_LEFT);  // Move cursor between braces.
        set_mods(mod_state);  // Restore mods.
      }
        break;
    case ZERO000:
        if (record->event.pressed) {
        clear_mods();  // Temporarily disable mods.
        clear_oneshot_mods();
        if ((mod_state | oneshot_mod_state) & MOD_MASK_CTRL) {
            SEND_STRING("00");
        } else if ((mod_state | oneshot_mod_state) & MOD_MASK_SHIFT) {
            SEND_STRING(")");
        } else if ((mod_state | oneshot_mod_state) & MOD_MASK_ALT) {
            SEND_STRING("000");
        } else {
            SEND_STRING("0");
        }
        set_mods(mod_state);  // Restore mods.
        }
        break;
      case KC_BSPC:
      case LT(_FN, KC_BSPC):
      case LT(_RAISE, KC_BSPC):
        {
        // Initialize a boolean variable that keeps track
        // of the delete key status: registered or not?
        static bool delkey_registered;
        if (record->event.pressed) {
            // Detect the activation of either shift keys
            if (mod_state & MOD_MASK_SHIFT) {
                // First temporarily canceling both shifts so that
                // shift isn't applied to the KC_DEL keycode
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_DEL);
                // Update the boolean variable to reflect the status of KC_DEL
                delkey_registered = true;
                // Reapplying modifier state so that the held shift key(s)
                // still work even after having tapped the Backspace/Delete key.
                set_mods(mod_state);
                return false;
            }
        } else { // on release of KC_BSPC
            // In case KC_DEL is still being sent even after the release of KC_BSPC
            if (delkey_registered) {
                unregister_code(KC_DEL);
                delkey_registered = false;
                return false;
            }
        }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        return true;
    }

    }

    return true;
}

// doesn't appear to work with no timer one shot mods but works with zero macro.
// overrideable function to determine whether the case mode should stop
//__attribute__ ((weak))
bool terminate_case_modes(uint16_t keycode, const keyrecord_t *record) {
        switch (keycode) {
            // Keycodes to ignore (don't disable caps word)
            case KC_A ... KC_Z:
            case KC_1 ... KC_0:
            case KC_MINS:
            case KC_UNDS:
            case KC_BSPC:
            case KC_RSFT:
            case KC_LSFT:
            case ZERO000:
            case MR_gui:
            case MR_sft:
            case ML_sft:
            case ML_alt:
            case ML_ctl:
            case OSM(MOD_RSFT):
            case OSM(MOD_LSFT):
            case LSFT_T(KC_TAB):
                // If mod chording disable the mods
                if (record->event.pressed && (get_mods() != 0)) {
                    return true;
                }
                break;
            default:
                if (record->event.pressed) {
                    return true;
                }
                break;
        }
        return false;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    process_custom_one_shot(keycode, record);

    if (!process_case_modes(keycode, record)) return false;
//    if (!process_caps_word(keycode, record)) return false;
    if (!process_custom_shift_keys(keycode, record)) return false;
    if (!process_record_send_string(keycode, record)) return false;

    return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
        release_custom_one_shot(keycode, record);
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case MT(MOD_RCTL, KC_SPC): //            ctrl / SPACE
            return TAPPING_TERM_CTRL_SPC;
        case MT(MOD_LGUI, KC_ENT): //            super / ENTER
            return TAPPING_TERM_GUI_ENTER;
        case LALT_T(KC_V): //                    alt / V
            return TAPPING_TERM_ALT_V;
        case LALT_T(KC_M): //                    alt / M
            return TAPPING_TERM_ALT_M;
        case LSFT_T(KC_TAB): //                  shift / TAB
            return TAPPING_TERM_SFT_TAB;
        case LT(NAV, KC_QUOT): //                NAV / apostrophe
            return TAPPING_TERM_NAV_QUOT;
        case LT(_FN, KC_A): //                   _FN / A
            return TAPPING_TERM_FN_A;
        default:
            return TAPPING_TERM;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
          case MT(MOD_RCTL, KC_SPC):
            // Immediately select the hold action when another key is pressed.
            return true;
          case MT(MOD_LGUI, KC_ENT):
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_RCTL, KC_SPC):
            return true;
        case MT(MOD_LGUI, KC_ENT):
            return true;
        default:
            return false;
    }
}


static bool scrolling_mode = false;
static bool precision_mode = false;
static bool set_auto_mouse_enabled = true;

void pointing_device_init_user(void) {
    pointing_device_set_cpi(DEFAULT_CPI);
    set_auto_mouse_layer(NAV);
    set_auto_mouse_enable(true);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    set_auto_mouse_enabled = true;
    uint8_t layer = get_highest_layer(state);
    switch(layer) {
        case _LOWER: // enter precision mode, disable scroll mode
            if (!precision_mode || precision_mode) {
                precision_mode = true;
                scrolling_mode = false;
                pointing_device_set_cpi(PRECISION_CPI);
            }

            break;
        case _RAISE: // enter scroll mode, disable precision mode
            if (!scrolling_mode || precision_mode) {
                scrolling_mode = true;
                precision_mode = false;
                pointing_device_set_cpi(SCROLLING_CPI);
            }

            // Set the flag to turn off auto mouse layer
            set_auto_mouse_enabled = false;

            break;
        case _FN: // enter precision mode, disable scroll mode
            if (scrolling_mode || !precision_mode) {
                precision_mode = true;
                scrolling_mode = false;
                pointing_device_set_cpi(PRECISION_CPI);
            }
            break;
        default:
            // check if we were scrolling before and set disable if so
            if (scrolling_mode || precision_mode) {
                scrolling_mode = false;
                precision_mode = false;
                pointing_device_set_cpi(DEFAULT_CPI);
            }
            break;
    }

    // Set auto mouse layer state if is_auto_mouse_enabled is not the same as the current
    if (set_auto_mouse_enabled != get_auto_mouse_enable())
    {
        // If auto mouse should be disabled, remove the layer
        if (set_auto_mouse_enabled == false)
        {
            state = remove_auto_mouse_layer(state, false);
        }
        set_auto_mouse_enable(set_auto_mouse_enabled);
    }

    return state;
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {

    if (scrolling_mode) {
        mouse_report.h = mouse_report.x * SCROLLING_POINTER_SPEED_MULTIPLIER;
        mouse_report.v = -mouse_report.y * SCROLLING_POINTER_SPEED_MULTIPLIER;
        mouse_report.x = 0;
        mouse_report.y = 0;
    }

    return mouse_report;
}

//bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
//    switch(keycode) {
//        case MT(MOD_RCTL, KC_SPC):
//            return true;
//        case MT(MOD_LGUI, KC_ENT):
//            return true;
//        default: return false;
//    }
//}
//
