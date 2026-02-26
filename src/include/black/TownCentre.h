#pragma once
// TownCentre — town's central building with spell icons and totem
// Struct layout from bw1-decomp
//
// Size: 0xE8 bytes (inherits 0xC4 from Abode)
// Vtable: 0x92C bytes (same as Abode, overrides ~29 methods)
//
// TownCentre manages spell icons, particle systems, totem statues,
// and serves as the administrative hub for a town. It's one of the
// most important Abode subclasses.

#include "Abode.h"

// Forward declarations
struct LH3DObject;
struct PSysInterface;
struct TotemStatue;
struct TownCentreSpellIcon;

struct TownCentre : public Abode {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
    void ResolveLoad() override;

    // === Overrides of GameThingWithPos virtuals ===
    MapCoords* GetArrivePos(MapCoords* out) override;
    bool32_t IsCastShadowAtNight() override;
    bool32_t IsTownCentre() override;
    bool32_t CanActAsAContainer(Creature* creature) override;
    bool32_t IsStoragePit(Creature* creature) override;

    // === Overrides of Object virtuals ===
    void ReduceLife(float value, GPlayer* player) override;
    void IncreaseLife(float value) override;
    uint32_t Process() override;
    void Draw() override;
    uint32_t GetDiscipleStateIfInteractedWith(GInterfaceStatus* status, Villager* villager) override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    LH3DObject_ObjectType Get3DType() override;
    uint32_t InterfaceValidToTap(GInterfaceStatus* status) override;
    bool InteractsWithPhysicsObjects() override;
    void ReactToPhysicsImpact(PhysicsObject* param1, bool param2) override;
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;

    // === Overrides of MultiMapFixed virtuals ===
    MapCoords* GetDoorPos(MapCoords* pos) override;
    void AddToPlayer() override;
    PlannedMultiMapFixed* ConvertToPlanned() override;

    // === Overrides of Abode virtuals ===
    void DeleteDependancys() override;
    void MakeFunctional() override;
    void StopBeingFunctional(GPlayer* param1) override;
    bool CausesTownEmergencyIfDamaged() override;
    bool CanBeHiddenIn() override;

    // === Fields ===
    LH3DObject*           game_object;  // 0xC4
    PSysInterface*        psys;         // 0xC8
    TotemStatue*          totem_statue; // 0xCC
    TownCentreSpellIcon*  icons[6];     // 0xD0 — spell icon slots
};
static_assert(sizeof(TownCentre) == 0xE8, "TownCentre size mismatch");
