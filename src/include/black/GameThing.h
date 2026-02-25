#pragma once
// GameThing — base class for all game entities
// Struct layout from bw1-decomp, implementations from v1.0 decompilation
//
// Size: 0x14 bytes (inherits 0x8 from Base)
// Vtable: 63 entries (0xFC bytes)

#include "Base.h"
#include "types.h"

// Forward declarations
struct Abode;
struct Creature;
struct GFootpath;
struct GFootpathLink;
struct GInterfaceStatus;
struct GPlayer;
struct GameOSFile;
struct Living;
struct MultiMapFixed;
struct PSysProcessInfo;
struct Spell;
struct SpellIcon;
struct SpellSeed;
struct Town;
struct Tree;
struct Villager;

// Entity type enum — 273 entries from bw1-decomp
enum GAME_THING_TYPE : uint32_t {
    GAME_THING_TYPE_UNUSED_000         = 0x0,
    GAME_THING_TYPE_GFOOTPATH          = 0x1,
    GAME_THING_TYPE_GFOOTPATH_LINK     = 0x2,
    GAME_THING_TYPE_GFOOTPATH_NODE     = 0x3,
    GAME_THING_TYPE_GFOOTPATH_LINK_SAVE = 0x4,
    GAME_THING_TYPE_GFOOTPATH_FINDER   = 0x5,
    GAME_THING_TYPE_VILLAGER           = 0x6,
    GAME_THING_TYPE_ABODE              = 0x7,
    GAME_THING_TYPE_STORAGE_PIT        = 0x8,
    GAME_THING_TYPE_SPELL              = 0x9,
    GAME_THING_TYPE_CREATURE           = 0x69,
    GAME_THING_TYPE_GGAME              = 0x6A,
    GAME_THING_TYPE_TOWN               = 0x28,
    GAME_THING_TYPE_TREE               = 0x4F,
    // ... remaining entries defined in full enum file
    GAME_THING_TYPE_COUNT              = 0x111
};

struct GameThing : public Base {
    // === Vtable (extends Base with 56 more virtuals) ===

    // Inherited from Base: Serialise, ~dtor, Delete, ToBeDeleted, Get3DSoundPos,
    //   CleanUpForSerialisation, Dump

    // New virtual methods (vtable slots 7-62):
    virtual GPlayer* GetPlayer();
    virtual void SetPlayer(GPlayer* player);
    virtual float CalculateInfluence(const MapCoords& coords);
    virtual void RemoveDance();
    virtual bool IsAvailable();
    virtual bool IsCreature(Creature* creature);
    virtual bool IsCreature();  // overload - no params
    virtual bool IsCreatureNotTooNear(Creature* creature);
    virtual float GetDrawImportance();
    virtual float GetMaxAlignmentChangePerGameTurn();
    virtual bool GetComputerSeen();
    virtual Town* GetTown();
    virtual float GetVillagerActivityDesire(Villager* villager);
    virtual void SetVillagerActivity(Villager* villager);
    virtual uint32_t UpdateVillagerActivityEffect(Villager* villager);
    virtual void MaintainSpell(uint32_t param1, float param2);
    virtual void UpdateSpellInfo(Spell* spell, PSysProcessInfo* info);
    virtual float GetRadius();
    virtual float Get2DRadius();
    virtual GPlayer* GetPlayerWhoLastPickedMeUp();
    virtual GPlayer* GetPlayerWhoLastDroppedMe();
    virtual bool IsFootpathLink();
    virtual GFootpathLink* GetFootpathLink();
    virtual void AddFootpathLink(GFootpath* footpath);
    virtual uint32_t GetNearestPathTo(const MapCoords& coords, float param2, int param3);
    // UseFootpathIfNecessary, AddFootpath, RemoveFootpath
    // JustAddResource, JustRemoveResource, JustGetResource, GetResource
    // AddResource, RemoveResource
    // CastCreature, CastPlayer, CastOneOffSpellSeed, CastAbode, CastMultiMapFixed
    // CastSpellIcon, CastTree
    virtual bool IsDeletedOnNewMap();
    virtual uint16_t GetNumberOfInstanceForGlobalList();
    virtual float GetTownArtifactValue();
    virtual bool CanBecomeArtifact();
    virtual void DrawInHand(GInterfaceStatus* status);
    virtual bool IsFunctional();
    // GetDebugText, GetSampleForAttack, GetGuidanceResourceType, GetShowNeedsPos
    // Load, Save, GetSaveType, SaveExtraData, ResolveLoad

    // === Fields ===
    uint16_t field_0x8;   // 0x8 — possibly type flags
    uint8_t  field_0xa;   // 0xa — availability flag (IsAvailable checks ~bit0)
    uint8_t  pad_0xb;     // 0xb — padding
    uint16_t field_0xc;   // 0xc
    uint16_t pad_0xe;     // 0xe — padding
    GameThing* next;      // 0x10 — linked list pointer

    // === Constants ===
    static constexpr float MAX_ALIGNMENT_CHANGE_PER_TURN = 1.0f / (60.0f * 60.0f * 10.0f);
};
static_assert(sizeof(GameThing) == 0x14, "GameThing size mismatch");
