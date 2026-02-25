#pragma once
// Fixed — non-moving Object anchored to the map
// Struct layout from bw1-decomp
//
// Size: 0x58 bytes (inherits 0x54 from Object)
// Vtable: 0x864 bytes (extends Object's 0x85C with 2 methods)

#include "Object.h"

struct Fixed : public Object {
    // === Overrides of inherited virtuals ===
    bool32_t CanBeSetOnFire(Creature*) override;
    bool32_t CanBePickedUpByCreature(Creature*) override;
    bool32_t CanBeFrighteningToCreature(Creature*) override;
    bool32_t CanBeSleptNextToByCreature(Creature*) override;
    bool32_t CanBeDestroyedByStoning(Creature*) override;
    bool32_t CanBeCrushed() override;
    bool32_t VillagerMustAvoid(Villager*) override;
    GameThing* GetTownArtifact() override;
    bool32_t IsTownArtifact() override;
    bool32_t NetworkFriendlyStartLockedSelect(GInterfaceStatus*) override;
    bool32_t ValidForLockedSelectProcess(GInterfaceStatus*) override;
    float GetHowMuchCreatureWantsToLookAtMe() override;

    // === New virtual methods (vtable 0x85C-0x860) ===
    virtual void InsertMapObjectToCellAssumeFixed();
    virtual bool IsObjectFullyInMap();

    // === Fields ===
    GameThing* town_artifact;  // 0x54 — associated town artifact
};
static_assert(sizeof(Fixed) == 0x58, "Fixed size mismatch");
