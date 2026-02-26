#pragma once
// Ball — creature toy ball with physics
// Struct layout from bw1-decomp
//
// Size: 0xB8 bytes (inherits 0x68 from MobileObject)

#include "MobileObject.h"

// Forward declarations
struct Town;

struct Ball : public MobileObject {
    // === Overrides of GameThing virtuals ===
    GPlayer* GetPlayer() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    bool32_t CanBePickedUpByCreature(Creature* creature) override;
    bool32_t IsToy(Creature* creature) override;
    bool32_t IsToyBall(Creature* creature) override;
    uint32_t GetScriptObjectType() override;

    // === Overrides of Object virtuals ===
    uint32_t Process() override;
    void Draw() override;
    uint32_t GetPhysicsConstantsType() override;

    // === Fields ===
    uint32_t field_0x68;   // 0x68
    LHPoint  field_0x6c;   // 0x6C (12 bytes)
    LHPoint  field_0x78;   // 0x78 (12 bytes)
    uint32_t field_0x84;   // 0x84
    uint32_t field_0x88;   // 0x88
    uint32_t field_0x8c;   // 0x8C
    bool32_t is_owned;     // 0x90
    uint32_t field_0x94;   // 0x94
    uint32_t field_0x98;   // 0x98
    uint32_t field_0x9c;   // 0x9C
    Town*    town;         // 0xA0
    uint32_t field_0xa4;   // 0xA4
    uint32_t field_0xa8;   // 0xA8
    uint32_t field_0xac;   // 0xAC
    uint32_t field_0xb0;   // 0xB0
    uint32_t field_0xb4;   // 0xB4
};
static_assert(sizeof(Ball) == 0xB8, "Ball size mismatch");
