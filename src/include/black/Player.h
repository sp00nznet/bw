#pragma once
#include <vector>
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

#include <cstddef>

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
    PLAYER_TYPE_NONE     = 0,  // unused: sub_523160 inits these "Player[%d]"
    PLAYER_TYPE_HUMAN    = 1,  // sub_5F7130
    PLAYER_TYPE_COMPUTER = 2,  // inferred: the mimic hub (sub_4CB260) excludes it
    PLAYER_TYPE_NEUTRAL  = 3,  // player 7; sub_523530 stops there
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

    // === Fields (v1.0: the constructor sub_5F6EF0, Init sub_5F71B0) ===
    // The vendor (v1.41) layout has 0x828 more bytes at 0xB8; v1.0's player is
    // 632 bytes, the stride of GGame's array (sub_523640).
    GInterface*      interfaces[8];             // 0x14 -- by interface index (Init's last argument)
    uint8_t          field_0x34[0x2C];          // 0x34-0x5F (+0x5C zeroed by the constructor)
    GAlignment*      alignment;                 // 0x60
    uint32_t         field_0x64;                // 0x64
    float            multipliers[9];            // 0x68 -- 1.0 (sub_5F7360); +0x70 scales worship (sub_706C40)
    uint8_t          field_0x8c[0x28];          // 0x8C-0xB3 (+0x8C/+0x90, +0x94..+0xB3 zeroed by Init)
    uint8_t          field_0xb4;                // 0xB4
    uint8_t          player_number;             // 0xB5
    uint8_t          field_0xb6;                // 0xB6
    uint8_t          field_0xb7;                // 0xB7
    float            multipliers_b8[9];         // 0xB8 -- 1.0 (sub_5F7360)
    uint8_t          field_0xdc[0x1C];          // 0xDC-0xF7
    PLAYER_TYPE      type;                      // 0xF8 -- sub_523530 stops at the neutral (3)
    char16_t         name[0x1E];                // 0xFC
    uint8_t          field_0x138[0x50];         // 0x138-0x187 (+0x15C a 508-byte object LOAD_CREATURE needs; +0x164)
    int              magic_remainder[0x2A];     // 0x188 -- spell charge remainders (42 spells)
    bool             magic_enabled[0x2A];       // 0x230 -- spell availability flags (42 spells)
    uint8_t          pad_0x25a[2];              // 0x25A
    GameStats*       game_stats;                // 0x25C (4392 bytes, sub_534440)
    Citadel*         citadel;                   // 0x260
    Creature*        creature;                  // 0x264 -- the player's creature (sub_696F00 reads +612)
    LHListHead_Town  towns;                     // 0x268
    uint32_t         field_0x270;               // 0x270
    uint32_t         field_0x274;               // 0x274
};
static_assert(sizeof(GPlayer) == 0x278, "GPlayer size mismatch");
static_assert(offsetof(GPlayer, multipliers) == 0x68 && offsetof(GPlayer, multipliers_b8) == 0xB8, "sub_5F7360");
static_assert(offsetof(GPlayer, player_number) == 0xB5 && offsetof(GPlayer, type) == 0xF8 &&
              offsetof(GPlayer, creature) == 0x264, "GPlayer v1.0 offsets");

// v1.0 keeps the eight players in GGame (+24, sub_523640); core has no GGame,
// so they live here. nullptr past 7.
GPlayer* PlayerAt(uint32_t index);
// A single-player start (sub_523160's shape): player 0 human, 1..6 unused,
// 7 the neutral player.
void ResetPlayers();
// The game's influence multipliers (game +2408752 towns, +2408756 players),
// set by the level's SET_TOWN_ / SET_PLAYER_INFLUENCE_MULTIPLIER (cases 96 / 97).
extern float g_town_influence_multiplier;
extern float g_player_influence_multiplier;
// SET_GLOBAL_LAND_BALANCE's table (0xC3B390, sub_5A2440, 8 floats saved with
// the game); e.g. [1] scales a player's +232 (sub_5EB6B0), [5] a tree's wood
// (sub_6DCC80). A new game sets all eight to 1 (sub_5A23E0).
extern float g_land_balance[8];
void ResetLandBalance();
// v1.0 sub_58DE80: the player's influence at the point, -1..1. Its citadel's
// power and each of its towns' influence count in full where the point is
// nearer than that many metres; the sum is clamped. No player: 1.
float PlayerInfluence(GPlayer* player, const MapCoords& at);
// v1.0's InfluenceRing (68 bytes, a GameThingWithPos; sub_58E270 at a point,
// sub_58E310 at an object): a scripted influence on the game's list +2104584.
struct Object;
struct InfluenceRing {
    MapCoords at;             // +0x14 (an object's position when made)
    Object*   follow = nullptr;  // +0x28: the object it was made at
    GPlayer*  player = nullptr;  // +0x34
    float     radius = 0.0f;     // +0x38
    bool      anti = false;      // +0x3C: none of the player's influence within it
};
InfluenceRing* AddInfluenceRing(const MapCoords& at, Object* follow, GPlayer* player, float radius, bool anti);
void RemoveInfluenceRing(InfluenceRing* ring);
const std::vector<InfluenceRing*>& InfluenceRings();
// v1.0 sub_58E140: a ring's share at distance d of radius r.
float RingFalloff(float d, float r);
// v1.0 sub_58E1E0: the player with the most influence at the point, else the
// local player (0).
GPlayer* InfluenceOwner(const MapCoords& at, float* amount = nullptr);
// A script's player number (sub_6862D0): 1-based; 0 is the local player (0).
GPlayer* ScriptPlayer(int32_t n);
// The player's creature, and it the creature's owner (player +612, creature
// +0x1070), as the creature loader leaves them (sub_606A50).
void SetPlayerCreature(GPlayer* p, Creature* c);
