#pragma once
#include <cstdint>

enum LIVING_ACTION_INDEX : uint32_t {
    LIVING_ACTION_INDEX_TOP      = 0x0,
    LIVING_ACTION_INDEX_FINAL    = 0x1,
    LIVING_ACTION_INDEX_PREVIOUS = 0x2,
    _LIVING_ACTION_INDEX_COUNT   = 0x3
};

struct LivingAction {
    uint8_t  states[3];                // 0x00  (indexed by LIVING_ACTION_INDEX)
    uint8_t  field_0x3;               // 0x03
    uint16_t turns_since_state_change; // 0x04
};
static_assert(sizeof(LivingAction) == 0x6, "LivingAction size mismatch");
