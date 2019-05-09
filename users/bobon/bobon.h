#pragma once

#include "quantum.h"

enum userspace_layers {
  _BASE = 0,  // Base Layer
  _NAV,       // Navigation Layer
  _EDIT,      // Edit Layer
  _FN,        // Function  Layer
  _CFG,       // Configuration Layer
  _SYS,       // System Layer
};

enum keycodes {
    KC_NAV = SAFE_RANGE,
    KC_EDIT,
    KC_FN,
    KC_CFG,
    KC_SYS,
};

void illThinkAboutThis(void);

