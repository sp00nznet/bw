#pragma once
// MobileStatic — moveable multi-cell object (rocks, toys, fences)
// Struct layout from bw1-decomp
//
// Size: 0x88 bytes (inherits 0x7C from MultiMapFixed)
// Vtable: 0x90C bytes (same as MultiMapFixed, overrides ~50 methods)
//
// MobileStatic is a MultiMapFixed object that can be picked up,
// thrown, and interacted with physically. It serves as the base
// class for Rock, various toys, and fence segments.

#include "MultiMapFixed.h"

// Forward declarations
struct GMobileStaticInfo;

struct MobileStatic : public MultiMapFixed {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    GPlayer* GetPlayer() override;
    bool IsFunctional() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    void PhysicsEditorCreate(int param1) override;
    uint32_t GetCreatureBeliefType() override;
    bool32_t IsCastShadowAtNight() override;
    bool32_t CanBeEatenByCreature(Creature* creature) override;
    bool32_t CanBePlayedWithByCreature(Creature* creature) override;
    bool32_t CanBePickedUpByCreature(Creature* creature) override;
    bool32_t CanBeStompedOnByCreature(Creature* creature) override;
    bool32_t IsToyAwayFromHome(Creature* creature) override;
    bool32_t IsToy(Creature* creature) override;
    bool32_t IsToyBall(Creature* creature) override;
    bool32_t IsToyDie(Creature* creature) override;
    bool32_t IsToyCuddly(Creature* creature) override;
    bool32_t IsFence() override;
    bool32_t CanBeUsedForThrowingDamageByCreature(Creature* creature) override;
    bool32_t CanBeThrownInTheSeaPlayfully(Creature* creature) override;
    uint32_t GetCreatureMimicType() override;
    float GetHowMuchCreatureWantsToLookAtMe() override;
    bool32_t IsMobileStatic() override;
    uint32_t GetScriptObjectType() override;

    // === Overrides of Object virtuals ===
    float GetXAngle() override;
    float GetZAngle() override;
    void SetXYZAngles(float x, float y, float z) override;
    void SetXYZAnglesAndScale(float x, float y, float z, float scale) override;
    bool BlocksTownClearArea() const override;
    HOLD_TYPE GetHoldType() override;
    float GetHoldLoweringMultiplier() override;
    int GetMesh() const override;
    void Draw() override;
    bool CanBePickedUp() override;
    void GetWorldMatrix(LHMatrix* out) override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    RESOURCE_TYPE GetResourceType() override;
    int GetDefaultResource() override;
    bool32_t ValidForPlaceInHand(GInterfaceStatus* status) override;
    uint32_t ValidToApplyThisToObject(GInterfaceStatus* status, Object* param2) override;
    uint32_t ApplyThisToObject(GInterfaceStatus* status, Object* param2, GestureSystemPacketData* param3) override;
    uint32_t ValidToApplyThisToMapCoord(GInterfaceStatus* status, const MapCoords* param2) override;
    uint32_t ApplyThisToMapCoord(GInterfaceStatus* status, const MapCoords* param2, GestureSystemPacketData* param3) override;
    uint32_t ApplyOnlyAfterReleased() override;
    uint32_t GetPhysicsConstantsType() override;
    void GetBoundingSphere(LHPoint* center, float* radius) override;
    bool InteractsWithPhysicsObjects() override;
    uint32_t ChecksVerticesVObjects() override;
    uint32_t PhysicallyDestroysAbodes() override;
    void ReactToPhysicsImpact(PhysicsObject* param1, bool param2) override;
    bool CanBecomeAPhysicsObject() override;
    bool CreatureMustAvoid(Creature* param1) override;
    void AddToRoutePlan(RPHolder* p1, Creature* p2, int p3, void (*p4)(int, Point2D, float, int)) override;
    bool32_t IsSolidToNewAbode() override;
    uint32_t GetTastiness() override;
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;

    // === Fields ===
    Object*  field_0x7c;       // 0x7C — associated object (parent?)
    uint8_t  field_0x80[0x8];  // 0x80 — unknown data (angles/orientation?)
};
static_assert(sizeof(MobileStatic) == 0x88, "MobileStatic size mismatch");
