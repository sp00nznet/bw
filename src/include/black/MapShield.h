#pragma once
// MapShield — magical shield placed on the map
// Struct layout from bw1-decomp
//
// Size: 0x68 bytes (inherits 0x5C from SingleMapFixed)
// Vtable: 0x874 bytes (extends SingleMapFixed's 0x868 with 3 methods)

#include "SingleMapFixed.h"

// Forward declarations
struct GMagicInfo;
struct SpellShield;

struct MapShield : public SingleMapFixed {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    GPlayer* GetPlayer() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of Object virtuals ===
    bool32_t HandShouldFeelWithMeshIntersect() override;
    int GetMesh() const override;
    float GetTopPos() override;
    bool32_t ValidForPlaceInHand(GInterfaceStatus* status) override;
    void ShouldPhysicsRaiseObjectUntilNotIntersectingThis(Object* param1) override;
    bool CanBecomeAPhysicsObject() override;
    bool CreatureMustAvoid(Creature* param1) override;
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;

    // === New virtual methods (vtable 0x868-0x870) ===
    virtual void ProcessShield();
    virtual void DrawShield();
    virtual bool IsPointDefinietlyWithinShieldVolume(const MapCoords* point);

    // === Fields ===
    MapShield*   next;        // 0x5C — linked list next
    SpellShield* spell;       // 0x60 — associated spell
    GMagicInfo*  spell_info;  // 0x64 — spell configuration
};
static_assert(sizeof(MapShield) == 0x68, "MapShield size mismatch");
