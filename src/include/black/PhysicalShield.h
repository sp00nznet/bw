#pragma once
#include "MapShield.h"

struct PhysOb;

struct PhysicalShield : public MapShield {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    float GetImpressiveValue(Living* living, Reaction* reaction) override;

    // === Overrides of Object virtuals ===
    void ApplyEffect(EffectValues* effect, int param2) override;
    uint32_t DestroyedByEffect(GPlayer* player, float param2) override;
    void Draw() override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    LH3DObject_ObjectType Get3DType() override;
    bool SetDying() override;
    bool32_t IsEffectReceiver(EffectValues* param1) override;
    uint32_t GetPhysicsConstantsType() override;
    void SetUpPhysOb(PhysOb* physOb) override;
    bool InteractsWithPhysicsObjects() override;
    void ReactToPhysicsImpact(PhysicsObject* param1, bool param2) override;
    bool GetAlwaysRemainsInPhysicsInternalSystem() override;

    // === Overrides of MapShield virtuals ===
    void ProcessShield() override;
    void DrawShield() override;
    bool IsPointDefinietlyWithinShieldVolume(const MapCoords* point) override;
};
static_assert(sizeof(PhysicalShield) == 0x68, "PhysicalShield size mismatch");
