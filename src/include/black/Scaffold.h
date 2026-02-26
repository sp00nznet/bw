#pragma once
// Scaffold — construction scaffolding for building sites
// Struct layout from bw1-decomp
//
// Size: 0x9C bytes (inherits 0x68 from MobileObject)
// Vtable: uses MobileObject's vtable layout
//
// Scaffold is the physical scaffolding structure placed at building
// sites. It receives resources (wood) and manages the construction
// process. Can be picked up and thrown by the player/creature.

#include "MobileObject.h"

// Forward declarations
struct GestureSystemPacketData;
struct LHPoint;
struct PhysicsObject;

struct Scaffold : public MobileObject {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    Town* GetTown() override;
    uint32_t AddResource(RESOURCE_TYPE type, uint32_t amount,
                         GInterfaceStatus* status, bool param4,
                         const MapCoords& coords, int param6) override;
    void DrawInHand(GInterfaceStatus* status) override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
    void ResolveLoad() override;

    // === Overrides of GameThingWithPos virtuals ===
    uint32_t GetOverwritePickUpToolTip() override;
    uint32_t GetOverwriteDropToolTip() override;
    float GetImpressiveValue(Living* param1, Reaction* param2) override;
    float GetUpdateOfBoredomValue(Reaction* param1, GameThingWithPos* param2) override;
    bool32_t CanBePickedUpByCreature(Creature* creature) override;
    bool32_t CanBeStolenByCreature(Creature* creature) override;
    bool32_t IsStealableScaffold(Creature* creature) override;
    bool32_t IsScaffold() override;
    uint32_t GetScriptObjectType() override;

    // === Overrides of Object virtuals ===
    void ActualMoveMapObject(const MapCoords& coords) override;
    void Draw() override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    bool IsResourceStore(RESOURCE_TYPE type) override;
    bool DeleteObjectAndTakeResource(Object* obj, GInterfaceStatus* status) override;
    RESOURCE_TYPE GetResourceType() override;
    int GetDefaultResource() override;
    uint32_t ValidForPlaceInHand(GInterfaceStatus* status) override;
    uint32_t InterfaceSetInMagicHand(GInterfaceStatus* status) override;
    uint32_t InterfaceSetOutMagicHand(GInterfaceStatus* status) override;
    uint32_t ValidToApplyThisToObject(GInterfaceStatus* status, Object* target) override;
    uint32_t ApplyThisToObject(GInterfaceStatus* status, Object* target,
                               GestureSystemPacketData* data) override;
    uint32_t InterfaceValidToTap(GInterfaceStatus* status) override;
    uint32_t InterfaceTap(GInterfaceStatus* status) override;
    uint32_t ThrowObjectFromHand(GInterfaceStatus* status, int param) override;
    uint32_t InitialisePhysicsFromHand(LHPoint* param1, LHPoint* param2,
                                        GInterfaceStatus* status,
                                        Object* param4, int param5) override;
    uint32_t InitialisePhysics(const LHPoint* param1, const LHPoint* param2,
                               Object* param3, bool param4,
                               GInterfaceStatus* status) override;
    uint32_t GetPhysicsConstantsType() override;
    void EndPhysics(PhysicsObject* param1, bool param2) override;
    bool InteractsWithPhysicsObjects() override;
    void ReactToPhysicsImpact(PhysicsObject* param1, bool param2) override;
    bool CanBecomeAPhysicsObject() override;
    bool ProcessInHand() override;
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;

    // === Fields ===
    uint8_t field_0x68[0x34];   // 0x68 — internal scaffold state
};
static_assert(sizeof(Scaffold) == 0x9C, "Scaffold size mismatch");
