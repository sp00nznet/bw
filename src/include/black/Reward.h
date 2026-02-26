#pragma once
// Reward — quest reward object
// Struct layout from bw1-decomp
//
// Size: 0xA8 bytes (inherits 0x68 from MobileObject)

#include "MobileObject.h"

struct Reward : public MobileObject {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    GPlayer* GetPlayer() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
    void ResolveLoad() override;

    // === Overrides of GameThingWithPos virtuals ===
    void PhysicsEditorCreate(int param1) override;
    uint32_t GetOverwriteTapToolTip() override;
    bool32_t IsReward() const override;
    bool32_t IsActive() const override;
    uint32_t GetScriptObjectType() override;

    // === Overrides of Object virtuals ===
    uint32_t Process() override;
    void Draw() override;
    float GetWeight() override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    bool32_t ValidForPlaceInHand(GInterfaceStatus* status) override;
    uint32_t InterfaceValidToTap(GInterfaceStatus* status) override;
    uint32_t InterfaceTap(GInterfaceStatus* status) override;
    bool CanBecomeAPhysicsObject() override;

    // === Fields ===
    uint8_t field_0x68[0x40];  // 0x68
};
static_assert(sizeof(Reward) == 0xA8, "Reward size mismatch");
