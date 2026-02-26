#pragma once
// Spell — base class for all magic spells
// Struct layout from bw1-decomp
//
// Size: 0xEC bytes (inherits 0x28 from GameThingWithPos)
// Vtable: 0x554 bytes (extends GameThingWithPos's 0x500 with 21 methods)

#include "GameThingWithPos.h"

// Forward declarations
struct GInterfaceStatus;
struct Object;
struct PSysProcessInfo;
struct SpellCastData;
struct SpellEventInfo;

// Magic type enum (partial — from bw1-decomp's chlasm/Enum.h)
enum MAGIC_TYPE : uint32_t {
    MAGIC_TYPE_NONE = 0,
    // ... remaining entries
};

struct Spell : public GameThingWithPos {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    GPlayer* GetPlayer() override;
    bool IsFunctional() override;
    char* GetDebugText() override;
    uint32_t GetSampleForAttack() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    uint32_t GetCreatureBeliefType() override;
    uint32_t GetCreatureBeliefListType() override;
    uint32_t GetOrigin() override;
    float GetLife() override;
    void GetMovementDirection(LHPoint* pos) override;
    IMPRESSIVE_TYPE GetImpressiveType() override;
    float GetImpressiveIntensity(IMPRESSIVE_TYPE type) override;
    float GetImpressiveValue(Living* param1, Reaction* param2) override;
    float GetUpdateOfBoredomValue(Reaction* param1, GameThingWithPos* param2) override;
    bool32_t IsSuitableForCreatureAction() override;
    bool32_t CanBeFrighteningToCreature(Creature* creature) override;
    WorshipSite* GetWorshipSite() override;
    bool32_t IsSpell() const override;
    const char* GetText() override;
    HELP_TEXT GetQueryFirstEnumText() override;
    HELP_TEXT GetQueryLastEnumText() override;
    uint32_t GetFOVHelpMessageSet() override;
    uint32_t GetFOVHelpCondition() override;
    float GetReactionPower() override;
    void GetSpellCastPos(MapCoords* outPos) override;

    // === New virtual methods (vtable 0x500-0x550) ===
    virtual void ProcessSpellSeed();
    virtual void GetParticleType();
    virtual void DrawSpellSeed();
    virtual void Draw();
    virtual void DebugDraw();
    virtual bool NeedsContinualPackets(GInterfaceStatus* param1);
    virtual void HasEnoughChantsAndLifeForRecast();
    virtual void UpdateStruckReaction();
    virtual void SetUpDestroyedReaction();
    virtual uintptr_t GetCreatureCastOn();
    virtual uint32_t Process();
    virtual void SpellEvent(const SpellEventInfo& info);
    virtual void CloseDown();
    virtual int InitWithPos(GameThing* caster, const MapCoords& pos, SpellCastData* data, const PSysProcessInfo& psys);
    virtual int InitWithObject(GameThing* caster, Object* target, SpellCastData* data, const PSysProcessInfo& psys);
    virtual float CalculateCostToMaintain();
    virtual void AdjustSpellSeedPos(MapCoords* pos);
    virtual bool IsSpellCreature();
    virtual bool IsSpellStormAndTornado();
    virtual void SetMaxObjectsToCreate(int value);
    virtual int GetMaxObjectsToCreate();

    // === Fields ===
    uint32_t   field_0x28;       // 0x28
    float      field_0x2c;       // 0x2C
    uint32_t   field_0x30;       // 0x30
    uint32_t   field_0x34;       // 0x34
    uint32_t   field_0x38;       // 0x38
    uint32_t   field_0x3c;       // 0x3C
    uint32_t   field_0x40;       // 0x40
    uint32_t   field_0x44;       // 0x44
    uint32_t   field_0x48;       // 0x48
    uint32_t   field_0x4c;       // 0x4C
    float      field_0x50;       // 0x50
    float      field_0x54;       // 0x54
    float      field_0x58;       // 0x58
    uint8_t    field_0x5c;       // 0x5C
    uint8_t    field_0x5d;       // 0x5D
    // 2 bytes padding
    uint32_t   field_0x60;       // 0x60
    LHPoint    field_0x64;       // 0x64
    LHPoint    field_0x70;       // 0x70
    LHPoint    field_0x7c;       // 0x7C
    LHPoint    field_0x88;       // 0x88
    float      field_0x94;       // 0x94
    uint32_t   field_0x98;       // 0x98
    uint8_t    field_0x9c;       // 0x9C
    // 3 bytes padding
    GameThing* creator;          // 0xA0 — caster of this spell
    GameThing* field_0xa4;       // 0xA4
    GameThing* interface_status; // 0xA8
    GameThing* field_0xac;       // 0xAC
    uint32_t   field_0xb0;       // 0xB0
    MAGIC_TYPE magic_type;       // 0xB4
    float      field_0xb8;       // 0xB8
    float      field_0xbc;       // 0xBC
    MapCoords  field_0xc0;       // 0xC0
    MapCoords  field_0xcc;       // 0xCC
    uint32_t   field_0xd8;       // 0xD8
    uint32_t   field_0xdc;       // 0xDC
    uint32_t   field_0xe0;       // 0xE0
    float      field_0xe4;       // 0xE4
    Spell*     next;             // 0xE8 — linked list next
};
static_assert(sizeof(Spell) == 0xEC, "Spell size mismatch");
