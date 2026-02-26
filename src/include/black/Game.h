#pragma once
// GGame — the god struct containing all game state
// Struct layout from bw1-decomp
//
// Size: 0x250544 bytes (2,363,716 bytes = ~2.25 MB)
// Contains embedded GMap (2 MB), 8 GPlayers, landscape, script engine, etc.
// Inherits from GameThing (0x14 bytes)
//
// There is exactly one GGame instance per game session (g_game global).

#include "GameThing.h"
#include "Map.h"
#include "Player.h"
#include "types.h"

// Forward declarations
struct Config;
struct GCamera;
struct GClimate;
struct GScript;
struct Temple;

// Game mode enum
enum GAME_MODE : uint32_t {
    GAME_MODE_NONE = 0,
};

struct GGame : public GameThing {
    // === Fields ===
    // Layout uses opaque byte regions between key typed fields.
    // Offsets verified against bw1-decomp's Game.h.

    uint32_t  field_0x14;                       // 0x14
    GPlayer   players[8];                       // 0x18 (8 * 0xA60 = 0x5300 bytes)
    uint8_t   _pad_5318[0x69C];                 // 0x5318 — stats DB, creature DB, misc
    Temple*   temple;                           // 0x59B4
    GMap      map;                              // 0x59B8 — 512x512 cell grid (0x200050 bytes)
    int32_t   land_number;                      // 0x205A08 — current land/level number
    uint8_t   _pad_205a0c[0x4A684];             // 0x205A0C — landscape, terrain, player info, etc.
    GScript*  script;                           // 0x250090 — the script engine
    uint8_t   _pad_250094[0xEC];                // 0x250094
    GAME_MODE game_mode;                        // 0x250180
    uint8_t   _pad_250184[0x13C];               // 0x250184
    GCamera*  camera;                           // 0x2502C0
    uint8_t   _pad_2502c4[0x280];               // 0x2502C4 — to end at 0x250544

    // Non-virtual methods
    void Init();
    void Loop();
    void StartGame();
    void ProcessOneGameTurn();
    GPlayer* GetPlayer(uint32_t index);
};
static_assert(sizeof(GGame) == 0x250544, "GGame size mismatch");

// Global game instance (the one and only)
extern GGame* g_game;
