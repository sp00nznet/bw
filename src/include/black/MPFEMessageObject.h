#pragma once
// MPFEMessageObject — base class for multiplayer frontend messages
// Struct layout from bw1-decomp (MPFEMessageObject.h)
//
// Size: 0x4 bytes (vtable only)
// Own vtable hierarchy (2 entries) — NOT related to Base/GameThing
// Unlocks 22 MPFE message subclasses

#include <cstdint>

struct MPFEPlayerDetails;

struct MPFEMessageObject {
    virtual ~MPFEMessageObject();
    virtual void Send(MPFEPlayerDetails* details);
};
static_assert(sizeof(MPFEMessageObject) == 0x4, "MPFEMessageObject size mismatch");
