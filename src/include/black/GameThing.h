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

    // New virtual methods (vtable slots 7-62, offsets 0x1C-0xF8):

    // --- Identity / influence (0x1C-0x28) ---
    virtual GPlayer* GetPlayer();
    virtual void SetPlayer(GPlayer* player);
    virtual float CalculateInfluence(const MapCoords& coords);

    // --- Availability / dance (0x2C) ---
    virtual void RemoveDance();
    virtual bool IsAvailable();

    // --- Creature type queries (0x30-0x38) ---
    virtual bool IsCreature(Creature* creature);
    virtual bool IsCreature();  // overload - no params
    virtual bool IsCreatureNotTooNear(Creature* creature);

    // --- Drawing / alignment (0x3C-0x44) ---
    virtual float GetDrawImportance();
    virtual float GetMaxAlignmentChangePerGameTurn();
    virtual bool GetComputerSeen();

    // --- Town / villager activity (0x48-0x54) ---
    virtual Town* GetTown();
    virtual float GetVillagerActivityDesire(Villager* villager);
    virtual void SetVillagerActivity(Villager* villager);
    virtual uint32_t UpdateVillagerActivityEffect(Villager* villager);

    // --- Spell (0x58-0x5C) ---
    virtual void MaintainSpell(uint32_t param1, float param2);
    virtual void UpdateSpellInfo(Spell* spell, PSysProcessInfo* info);

    // --- Geometry (0x60-0x64) ---
    virtual float GetRadius();
    virtual float Get2DRadius();

    // --- Player tracking (0x68-0x6C) ---
    virtual GPlayer* GetPlayerWhoLastPickedMeUp();
    virtual GPlayer* GetPlayerWhoLastDroppedMe();

    // --- Footpath (0x70-0x88) ---
    virtual bool IsFootpathLink();
    virtual GFootpathLink* GetFootpathLink();
    virtual void AddFootpathLink(GFootpath* footpath);
    virtual uint32_t GetNearestPathTo(const MapCoords& coords, float param2, int param3);
    virtual void UseFootpathIfNecessary(Living* living, const MapCoords* coords, uint8_t param3);
    virtual uint32_t AddFootpath(GFootpath* footpath);
    virtual uint32_t RemoveFootpath(GFootpath* footpath);

    // --- Resource management (0x8C-0xA0) ---
    virtual uint32_t JustAddResource(RESOURCE_TYPE type, uint32_t amount, bool param3);
    virtual uint32_t JustRemoveResource(RESOURCE_TYPE type, uint32_t amount, bool* param3);
    virtual uint32_t JustGetResource(RESOURCE_TYPE type, uint32_t amount, bool* param3);
    virtual uint32_t GetResource(RESOURCE_TYPE type);
    virtual uint32_t AddResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* status, bool param4, const MapCoords& coords, int param6);
    virtual uint32_t RemoveResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* status, bool* param4);

    // --- Cast methods (0xA4-0xBC) ---
    virtual Creature* CastCreature();
    virtual GPlayer* CastPlayer();
    virtual SpellSeed* CastOneOffSpellSeed();
    virtual Abode* CastAbode();
    virtual MultiMapFixed* CastMultiMapFixed();
    virtual SpellIcon* CastSpellIcon();
    virtual Tree* CastTree();

    // --- Global list / artifact (0xC0-0xCC) ---
    virtual bool IsDeletedOnNewMap();
    virtual uint16_t GetNumberOfInstanceForGlobalList();
    virtual float GetTownArtifactValue();
    virtual bool CanBecomeArtifact();

    // --- Interface / debug (0xD0-0xE4) ---
    virtual void DrawInHand(GInterfaceStatus* status);
    virtual bool IsFunctional();
    virtual char* GetDebugText();
    virtual uint32_t GetSampleForAttack();
    virtual uint32_t GetGuidanceResourceType();
    virtual uint32_t GetShowNeedsPos(uint32_t param1, MapCoords* param2);

    // --- Serialization (0xE8-0xF8) ---
    virtual uint32_t Load(GameOSFile* file);
    virtual uint32_t Save(GameOSFile* file);
    virtual uint32_t GetSaveType();
    virtual void SaveExtraData(GameOSFile* file);
    virtual void ResolveLoad();

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
