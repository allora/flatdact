#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#define EE_HANDS
// #define MASTER_LEFT
// #define MASTER_RIGHT

#define MOUSEKEY_INTERVAL           16
#define MOUSEKEY_TIME_TO_MAX        64
#define MOUSEKEY_DELAY              0
#define MOUSEKEY_WHEEL_DELAY        100
#define MOUSEKEY_WHEEL_INTERVAL     50
#define MOUSEKEY_WHEEL_TIME_TO_MAX  100
#define MOUSEKEY_MAX_SPEED          6

#define TAPPING_TERM                180
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD_PER_KEY
#define PERMISSIVE_HOLD

#define IGNORE_MOD_TAP_INTERRUPT
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define TAPPING_FORCE_HOLD_PER_KEY

//#define TAPPING_TERM_Q          160
#define TAPPING_TERM_CTRL_SPC     90
#define TAPPING_TERM_GUI_ENTER    90
#define TAPPING_TERM_SFT_TAB      100
#define TAPPING_TERM_NAV_QUOT     120
#define TAPPING_TERM_ALT_V        140
#define TAPPING_TERM_ALT_M        140
#define TAPPING_TERM_ALT_C        160
#define TAPPING_TERM_FN_A         140

#define POINTING_DEVICE_INVERT_Y
#define MOUSE_EXTENDED_REPORT
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_DELAY          480

#define TAPPING_TOGGLE 4
//#define CAPS_WORD_IDLE_TIMEOUT 2000
#define ONESHOT_TAP_TOGGLE 4  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 2000  /* Time (in ms) before the one shot key is released */
