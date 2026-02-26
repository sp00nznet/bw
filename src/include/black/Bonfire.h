#pragma once
// Bonfire — fire source placed on the map
// Struct layout from bw1-decomp
//
// Size: 0x94 bytes (same as Rock — no new fields)
// Simple methods at 0x004397xx are packed 16 bytes apart.
// Complex methods at 0x00439840-0x00439a90.

#include "Rock.h"

struct Bonfire : public Rock {
    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    void PhysicsEditorCreate(int param1) override;
    uint32_t GetScriptObjectType() override;

    // === Overrides of Object virtuals ===
    void Draw() override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    bool32_t ValidForPlaceInHand(GInterfaceStatus* status) override;
    uint32_t InterfaceValidToTap(GInterfaceStatus* status) override;
    bool InteractsWithPhysicsObjects() override;
    void ReactToPhysicsImpact(PhysicsObject* param1, bool param2) override;
    bool CanBecomeAPhysicsObject() override;
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;
    IMMERSION_EFFECT_TYPE GetInHandImmersionTexture() override;
};
static_assert(sizeof(Bonfire) == 0x94, "Bonfire size mismatch");
