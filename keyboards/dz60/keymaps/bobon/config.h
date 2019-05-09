#pragma once

// no RGB when computer sleeps
#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_SLEEP
#endif

#define MOUSEKEY_INTERVAL       16
#define MOUSEKEY_DELAY          0
#define MOUSEKEY_TIME_TO_MAX    40
#define MOUSEKEY_MAX_SPEED      5

#define MOUSEKEY_WHEEL_MAX_SPEED    4
#define MOUSEKEY_WHEEL_TIME_TO_MAX  255
#define MOUSEKEY_WHEEL_DELAY        0

#define TAPPING_TOGGLE  2
#define TAPPING_TERM    200
