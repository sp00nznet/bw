#pragma once
// MagicTeleport — teleport spell object
// Struct layout from bw1-decomp
//
// Size: 0x88 bytes (same as MobileStatic — no new fields)
// Many creature Can* queries return 0.

#include "MobileStatic.h"

// Forward declarations
struct EffectValues;

struct MagicTeleport : public MobileStatic {
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

    // === Overrides of Object virtuals ===
    void ActualMoveMapObject(const MapCoords& coords) override;
    void Draw() override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    bool32_t ValidForPlaceInHand(GInterfaceStatus* status) override;
    bool32_t InterfaceSetInMagicHand(GInterfaceStatus* status) override;
    bool32_t IsEffectReceiver(EffectValues* param1) override;
    bool InteractsWithPhysicsObjects() override;
    bool CanBecomeAPhysicsObject() override;
    bool32_t IsSolidToNewAbode() override;
};
static_assert(sizeof(MagicTeleport) == 0x88, "MagicTeleport size mismatch");
