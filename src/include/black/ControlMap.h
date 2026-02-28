#pragma once
// ControlMap — input binding map for all bindable actions
// Struct layout from bw1-decomp (ControlMap.h)
//
// Size: 0x6534 bytes (plain data, no vtable)

#include "BindableAction.h"
#include "types.h"

struct ControlMap {
    BindableAction bindable_actions[33];        // 0x0000 — _BINDABLE_ACTION_SIZE = 0x21
    bool32_t       bindable_action_states[33];  // 0x648C
    bool32_t       field2_0x6510;               // 0x6510
    bool32_t       field3_0x6514;               // 0x6514
    bool32_t       field4_0x6518;               // 0x6518
    bool32_t       field5_0x651c;               // 0x651C
    bool32_t       field6_0x6520;               // 0x6520
    bool32_t       field7_0x6524;               // 0x6524
    bool32_t       field7_0x6528;               // 0x6528
    bool32_t       field9_0x652c;               // 0x652C
    bool32_t       field10_0x6530;              // 0x6530
};
static_assert(sizeof(ControlMap) == 0x6534, "ControlMap size mismatch");
