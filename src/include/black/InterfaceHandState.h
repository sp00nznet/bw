#pragma once
#include "Base.h"
#include "HandState.h"  // For HAND_STATES enum

struct InterfaceHandState : public Base {
    HAND_STATES hand_state;  // 0x08
};
static_assert(sizeof(InterfaceHandState) == 0xC, "InterfaceHandState size mismatch");
