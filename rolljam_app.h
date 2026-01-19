#pragma once
#include <furi.h>
#include <gui/gui.h>
#include "rolljam_states.h"

typedef struct {
    RollJamState state;
    uint32_t frequency;
    const char* modulation;
    bool cc1101_ok;
} RollJamApp;
