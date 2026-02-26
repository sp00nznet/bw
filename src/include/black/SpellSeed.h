#pragma once
// SpellSeed — spell pickup object
// Struct layout from bw1-decomp
//
// Size: 0xA0 bytes (inherits 0x54 from Object)
// Vtable: 0x85C bytes (same as Object, overrides ~44 methods)
//
// SpellSeed is a one-shot spell pickup that the player can grab
// and apply to objects or map positions. It manages spell type,
// power level, and worship site association.

#include "Object.h"

// Forward declarations
struct SpellSeedInfo;

struct SpellSeed : public Object {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    uint32_t GetCreatureBeliefType() override;
    uint32_t GetOrigin() override;
    float GetPower() const override;
    float GetPSysPower() const override;
    WorshipSite* GetWorshipSite() override;
    bool32_t IsSpellSeed() override;
    uint32_t GetScriptObjectType() override;

    // === Overrides of Object virtuals ===
    void InsertMapObject() override;
    void RemoveMapObject() override;
    HOLD_TYPE GetHoldType() override;
    float GetHoldRadius() override;
    float GetHoldLoweringMultiplier() override;
    float GetHoldYRotate() override;
    bool32_t HandShouldFeelWithMeshIntersect() override;
    int GetMesh() const override;
    void Draw() override;
    void DrawOutOfMap(bool param1) override;
    bool IsG3DObjectDrawnInHand() override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    bool32_t ValidForPlaceInHand(GInterfaceStatus* status) override;
    bool32_t InterfaceSetInMagicHand(GInterfaceStatus* status) override;
    bool32_t InterfaceSetOutMagicHand(GInterfaceStatus* status) override;
    bool32_t ValidToRemoveFromHand(GInterfaceStatus* status, const MapCoords* param2) override;
    uint32_t RemoveFromHand(GInterfaceStatus* status, const MapCoords* param2) override;
    uint32_t ValidToApplyThisToObject(GInterfaceStatus* status, Object* param2) override;
    uint32_t ApplyThisToObject(GInterfaceStatus* status, Object* param2, GestureSystemPacketData* param3) override;
    uint32_t ValidToApplyThisToMapCoord(GInterfaceStatus* status, const MapCoords* param2) override;
    uint32_t ApplyThisToMapCoord(GInterfaceStatus* status, const MapCoords* param2, GestureSystemPacketData* param3) override;
    uint32_t ValidForLockedApplyProcess(GInterfaceStatus* status) override;
    uint32_t ApplyUnlockProcess(GInterfaceStatus* status) override;
    uint32_t IsInterfacePowerUpWhenInHand() const override;
    uint32_t ApplyOnlyAfterRecSystem() override;
    uint32_t ThrowObjectFromHand(GInterfaceStatus* status, int param2) override;
    bool32_t IsEffectReceiver(EffectValues* param1) override;
    bool InteractsWithPhysicsObjects() override;
    bool ProcessInHand() override;
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;
    IMMERSION_EFFECT_TYPE GetInHandImmersionTexture() override;

    // === Fields ===
    uint8_t field_0x54[0x4c];  // 0x54 — unknown data (spell type, power, etc.)
};
static_assert(sizeof(SpellSeed) == 0xA0, "SpellSeed size mismatch");
