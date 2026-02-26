#pragma once
// Fragment — broken building piece with physics
// Struct layout from bw1-decomp
//
// Size: 0xA8 bytes (inherits 0x94 from Rock)

#include "Rock.h"

// Forward declarations
struct FragMesh;

struct Fragment : public Rock {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
    void ResolveLoad() override;

    // === Overrides of GameThingWithPos virtuals ===
    bool32_t CanBePickedUpByCreature(Creature* creature) override;
    bool32_t CanBeThrownByPlayer() override;
    uint32_t GetScriptObjectType() override;

    // === Overrides of Object virtuals ===
    void Draw() override;
    bool32_t ValidForPlaceInHand(GInterfaceStatus* status) override;
    uint32_t InterfaceValidToTap(GInterfaceStatus* status) override;
    uint32_t GetPhysicsConstantsType() override;
    void SetUpPhysOb(PhysOb* param1) override;
    void EndPhysics(PhysicsObject* param1, bool param2) override;
    bool InteractsWithPhysicsObjects() override;
    void ReactToPhysicsImpact(PhysicsObject* param1, bool param2) override;
    bool CreatureMustAvoid(Creature* param1) override;
    SOUND_COLLISION_TYPE GetCollideSoundType() override;
    IMMERSION_EFFECT_TYPE GetInHandImmersionTexture() override;
    bool ShouldFootpathsGoRound() override;

    // === Fields ===
    FragMesh* frag_mesh;   // 0x94
    uint32_t  field_0x98;  // 0x98
    uint32_t  field_0x9c;  // 0x9C
    uint32_t  field_0xa0;  // 0xA0
    uint32_t  field_0xa4;  // 0xA4
};
static_assert(sizeof(Fragment) == 0xA8, "Fragment size mismatch");
