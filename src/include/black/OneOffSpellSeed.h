#pragma once
// OneOffSpellSeed — one-off spell projectile
// Struct layout from bw1-decomp
//
// Size: 0x7C bytes (inherits 0x68 from MobileObject)

#include "MobileObject.h"

// Forward declarations
struct EffectValues;
struct SpellSeed;

struct OneOffSpellSeed : public MobileObject {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    bool GetComputerSeen() override;
    SpellSeed* CastOneOffSpellSeed() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
    uint32_t GetScriptObjectType() override;

    // === Overrides of GameThingWithPos virtuals ===
    uint32_t GetOverwritePickUpToolTip() override;
    uint32_t GetOverwriteTapToolTip() override;
    bool32_t CanBeEatenByCreature(Creature* creature) override;
    bool32_t IsOneOffSpellBelongingToOtherPlayer(Creature* creature) override;
    bool32_t IsOneOffSpellAggressive(Creature* creature) override;
    bool32_t IsOneOffSpellCompassionate(Creature* creature) override;
    bool32_t IsOneOffSpellPlayful(Creature* creature) override;
    bool32_t IsOneOffSpellToRestoreHealth(Creature* creature) override;
    bool32_t IsStealableSpell(Creature* creature) override;
    HELP_TEXT GetQueryFirstEnumText() override;
    HELP_TEXT GetQueryLastEnumText() override;

    // === Overrides of Object virtuals ===
    HOLD_TYPE GetHoldType() override;
    int GetMesh() const override;
    void Draw() override;
    void DrawOutOfMap(bool param1) override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    bool32_t InterfaceSetInMagicHand(GInterfaceStatus* status) override;
    uint32_t InterfaceValidToTap(GInterfaceStatus* status) override;
    uint32_t InterfaceTap(GInterfaceStatus* status) override;
    bool32_t IsEffectReceiver(EffectValues* param1) override;
    uint32_t GetPhysicsConstantsType() override;
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;

    // === Fields === (sub_6C0E40 / sub_6C0DE0)
    int32_t  seed = -1;          // 0x68: SPELL_SEED_TYPE
    float    strength = 1.0f;    // 0x6C
    uint32_t field_0x70 = 0;
    uint32_t field_0x74 = 0;
    int32_t  powerup = -1;       // 0x78: -1 the seed's own magic, else 0..2
};
static_assert(sizeof(OneOffSpellSeed) == 0x7C, "OneOffSpellSeed size mismatch");

// sub_6C0D30 -> sub_6C0DE0: a one-off seed (MOBILE_OBJECT_INFO[25], 0xC5AE44)
// at `at`; none for a seed above 29.
OneOffSpellSeed* CreateOneOffSpellSeed(const MapCoords& at, int seed, int powerup, float strength);
