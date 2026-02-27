#pragma once
// GPlayer — player state (human or AI)
// Struct layout from bw1-decomp
//
// Size: 0xA60 bytes (inherits 0x14 from GameThing)
// Vtable: GameThingVftable (0xFC bytes, no new virtual slots)
//
// GGame contains 8 GPlayer instances (players[0..6] + neutral player[7])
// Manages creature ownership, towns, spell charges, alignment, and interface.

#include "GameThing.h"
#include "types.h"

// Forward declarations
struct Citadel;
struct Creature;
struct GAlignment;
struct GInterface;
struct GInterfaceStatus;
struct GameStats;
struct PSysProcessInfo;
struct Spell;
struct Town;

// Forward-declare enum
enum MAGIC_TYPE : uint32_t;

// Player type enum
enum PLAYER_TYPE : uint32_t {
    PLAYER_TYPE_NONE = 0,
};

// Player name/index enum (8 players total)
enum PLAYER_NAME : uint32_t {
    PLAYER_NAME_PLAYER_ONE   = 0,
    PLAYER_NAME_PLAYER_TWO   = 1,
    PLAYER_NAME_PLAYER_THREE = 2,
    PLAYER_NAME_PLAYER_FOUR  = 3,
    PLAYER_NAME_PLAYER_FIVE  = 4,
    PLAYER_NAME_PLAYER_SIX   = 5,
    PLAYER_NAME_PLAYER_SEVEN = 6,
    PLAYER_NAME_NEUTRAL      = 7,
};

// Town list head (simplified — matches LHListHead<Town> at 8 bytes)
struct LHListHead_Town {
    Town* first;
    uint32_t count;
};
static_assert(sizeof(LHListHead_Town) == 0x8, "LHListHead_Town size mismatch");

// GPlayerInfo forward declaration
struct GPlayerInfo;

struct GPlayer : public GameThing {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;
    void Dump() override;

    // === Overrides of GameThing virtuals ===
    GPlayer* GetPlayer() override;
    float GetMaxAlignmentChangePerGameTurn() override;
    void MaintainSpell(uint32_t param1, float param2) override;
    void UpdateSpellInfo(Spell* spell, PSysProcessInfo* info) override;
    GPlayer* CastPlayer() override;

    // === Static methods ===
    static void ProcessPlayers();                          // 0x00649a20
    static void PostLoadCleanup();                         // 0x0064ab90
    static GPlayer* GetPlayerFromText(const char* str);    // 0x0064b5e0

    // === Non-virtual methods ===
    void Init(PLAYER_TYPE type, uint8_t number,
              char16_t* name, uint8_t param4);             // 0x00649190
    void Process();                                        // 0x006494e0
    void Birthday();                                       // 0x0064a6b0
    uint8_t GetPlayerNumber() const;                       // 0x0064a790
    GInterfaceStatus* GetNextInterfaceStatus(
        GInterfaceStatus* status);                         // 0x0064aac0
    bool IsNeutral();                                       // 0x0064ac00
    float CalculateInfluencePower();                       // 0x0064ad00
    LH3DColor* GetPlayer3DColor(LH3DColor* color);        // 0x0064b590
    bool32_t IsMagicTypeEnabled(MAGIC_TYPE type);          // 0x0064c220
    GInterface* GetRealInterface(unsigned long index);     // 0x0064d120
    bool IsMemberOfThisPlayer(GInterfaceStatus* status);   // 0x0064d750
    LH3DColor GetPlayerColour() const;                     // 0x0064d800

    // === Fields ===
    GInterface*      interfaces[1];             // 0x14
    int              field_0x18;                // 0x18
    uint8_t          field_0x1c[0x44];          // 0x1C-0x5F
    GAlignment*      alignment;                 // 0x60
    uint8_t          field_0x64[0x50];          // 0x64-0xB3
    uint8_t          field_0xb4;                // 0xB4
    uint8_t          player_number;             // 0xB5
    uint8_t          field_0xb6;                // 0xB6
    uint8_t          field_0xb7;                // 0xB7
    uint8_t          field_0xb8[0x828];         // 0xB8-0x8DF
    PLAYER_TYPE      type;                      // 0x8E0
    char16_t         name[0x1E];               // 0x8E4 — wide-char player name
    uint8_t          field_0x920[0x50];         // 0x920-0x96F
    int              magic_remainder[0x2A];     // 0x970 — spell charge remainders (42 spells)
    bool             magic_enabled[0x2A];       // 0xA18 — spell availability flags (42 spells)
    uint8_t          pad_0xa42[2];              // 0xA42-0xA43 — alignment padding
    GameStats*       game_stats;                // 0xA44
    Citadel*         citadel;                   // 0xA48
    Creature*        creature;                  // 0xA4C — the player's creature
    LHListHead_Town  towns;                     // 0xA50 — linked list of controlled towns
    uint32_t         field_0xa58;               // 0xA58
    uint32_t         field_0xa5c;               // 0xA5C
};
static_assert(sizeof(GPlayer) == 0xA60, "GPlayer size mismatch");
