#pragma once
// TotemStatue — worship totem statue
// Struct layout from bw1-decomp
//
// Size: 0xD8 bytes (inherits 0x7C from MultiMapFixed)

#include "MultiMapFixed.h"

// Forward declarations
struct ControlHandUpdateInfo;
struct Game3DObject;
struct GTotemStatueInfo;
struct TownCentre;
struct WorshipSite;

// Zoomer struct — animation interpolation helper (from lh3dlib)
struct Zoomer {
    float current_value;             // 0x0
    float destination;               // 0x4
    float destination_speed;         // 0x8
    float current_speed;             // 0xC
    float time_m2;                   // 0x10
    float current_time;              // 0x14
    float duration;                  // 0x18
    float start_value;               // 0x1C
    float start_speed;               // 0x20
    LHPoint non_linear_acceleration; // 0x24
};
static_assert(sizeof(Zoomer) == 0x30, "Zoomer size mismatch");

struct TotemStatue : public MultiMapFixed {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    GPlayer* GetPlayer() override;
    Town* GetTown() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
    void ResolveLoad() override;

    // === Overrides of GameThingWithPos virtuals ===
    uint32_t GetCreatureBeliefType() override;
    bool32_t IsTotemStatue() override;
    bool32_t CanBePlayedWithByCreature(Creature* creature) override;
    bool32_t CanBeImpressedByCreature(Creature* creature) override;
    bool32_t DoesTotemBelongToATownWhichIsVeryImpressedIndeed(Creature* creature) override;
    WorshipSite* GetWorshipSite() override;
    bool32_t CanBeStolenByCreature(Creature* creature) override;
    bool32_t IsTotemWithStealableSpell(Creature* creature) override;
    uint32_t GetScriptObjectType() override;

    // === Overrides of Object virtuals ===
    bool32_t HandShouldFeelWithMeshIntersect() override;
    void ReduceLife(float value, GPlayer* player) override;
    void IncreaseLife(float value) override;
    uint32_t Process() override;
    int GetMesh() const override;
    void Draw() override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    bool32_t ValidForLockedSelectProcess(GInterfaceStatus* status) override;
    bool32_t NetworkFriendlyStartLockedSelect(GInterfaceStatus* status) override;
    bool32_t NetworkUnfriendlyStartLockedSelect() override;
    bool32_t NetworkUnfriendlyLockedSelect(ControlHandUpdateInfo* param1) override;
    bool32_t NetworkUnfriendlyEndLockedSelect() override;
    bool32_t NetworkFriendlyEndLockedSelect(GInterfaceStatus* status) override;
    bool32_t IsEffectReceiver(EffectValues* param1) override;
    bool InteractsWithPhysicsObjects() override;
    void ReactToPhysicsImpact(PhysicsObject* param1, bool param2) override;
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;

    // === Overrides of MultiMapFixed virtuals ===
    bool IsRepaired() override;
    bool IsBuilt() override;
    void AddToPlayer() override;

    // === Fields ===
    TownCentre*    town_centre;       // 0x7C
    float          worship_speed;     // 0x80
    uint32_t       field_0x84;        // 0x84
    float          worship_speed_2;   // 0x88
    Game3DObject*  game_3d_object;    // 0x8C
    float          field_0x90;        // 0x90
    float          field_0x94;        // 0x94
    uint32_t       field_0x98;        // 0x98
    Zoomer         zoomer;            // 0x9C
    uint32_t       field_0xcc;        // 0xCC
    uint32_t       field_0xd0;        // 0xD0
    uint32_t       field_0xd4;        // 0xD4
};
static_assert(sizeof(TotemStatue) == 0xD8, "TotemStatue size mismatch");
