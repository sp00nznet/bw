#pragma once
// MagicFireBall — fireball spell projectile
// Struct layout from bw1-decomp
//
// Size: 0x60 bytes (inherits 0x54 from Object)
// Many creature interaction queries trivially return 0.

#include "Object.h"

struct MagicFireBall : public Object {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    GPlayer* GetPlayer() override;
    float Get2DRadius() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    bool32_t IsMagicFireBall() override;
    bool32_t CanBePickedUpByCreature(Creature* creature) override;
    bool32_t CanBeSetOnFire(Creature* creature) override;
    bool32_t CanBeStompedOnByCreature(Creature* creature) override;
    bool32_t CanBeThrownByCreature(Creature* creature) override;
    bool32_t CanBePutInAStoragePit(Creature* creature) override;
    bool32_t CanBeDestroyedByStoning(Creature* creature) override;
    bool32_t CanBeStonedAndEatenByCreature(Creature* creature) override;
    bool32_t CanBeExaminedByCreature(Creature* creature) override;
    bool32_t CanBeFoughtByCreature(Creature* creature) override;
    bool32_t CanActAsAContainer(Creature* creature) override;
    float GetHeight() override;

    // === Overrides of Object virtuals ===
    void InsertMapObject() override;
    float GetHeatCapacity() override;
    void GetFireGPHXDrawn(bool* p1, bool* p2, bool* p3, bool* p4) override;
    float GetRainCoolingMultiplier() override;
    void Draw() override;
    bool32_t ValidForPlaceInHand(GInterfaceStatus* status) override;
    bool32_t InterfaceSetInMagicHand(GInterfaceStatus* status) override;
    bool32_t IsTuggable() override;
    uint32_t InterfaceValidToTap(GInterfaceStatus* status) override;
    uint32_t InterfaceTap(GInterfaceStatus* status) override;
    bool InteractsWithPhysicsObjects() override;
    bool CanBecomeAPhysicsObject() override;
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;

    // === Fields ===
    uint32_t field_0x54;   // 0x54
    bool     field_0x58;   // 0x58
    // 3 bytes padding
    uint32_t field_0x5c;   // 0x5C
};
static_assert(sizeof(MagicFireBall) == 0x60, "MagicFireBall size mismatch");
