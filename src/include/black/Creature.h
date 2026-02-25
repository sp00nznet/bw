#pragma once
// Creature — the player's creature (god's avatar)
// Struct layout from bw1-decomp
//
// Size: 0x12C8 bytes (inherits 0xE0 from Living)
// Vtable: 0xB40 bytes (same as Living — no new virtual methods)
//
// The Creature is the largest struct in the game at nearly 5KB, containing
// the AI mind, physical body, alignment system, help system, and vast
// amounts of behavioral state.

#include "Living.h"

// Forward declarations
struct BookmarkGraphic;
struct Bubble;
struct CreatureMental;
struct CreaturePhysical;
struct CreatureReceiveSpell;
struct Dance;
struct GAlignment;
struct GArena;
struct GCreatureInfo;
struct GParticleContainer;
struct LH3DSmoke;

// Creature emotions for music system
struct CreatureEmotionsForMusic {
    uint32_t field_0x0;
    uint32_t field_0x4;
};
static_assert(sizeof(CreatureEmotionsForMusic) == 0x8, "CreatureEmotionsForMusic size mismatch");

// Help system state (0x98 bytes — from bw1-decomp CreatureHelp.h)
struct CreatureHelpState {
    uint8_t data[0x98];  // 0x188-0x21F (from help_state to help_stack_entries)
};
static_assert(sizeof(CreatureHelpState) == 0x98, "CreatureHelpState size mismatch");

// Help stack entry (0x1c bytes each — from bw1-decomp CreatureHelp.h)
struct CreatureHelpStackEntry {
    uint8_t data[0x1c];
};
static_assert(sizeof(CreatureHelpStackEntry) == 0x1c, "CreatureHelpStackEntry size mismatch");

// Sub-action agenda (very large — contains creature action queue)
struct CreatureSubActionAgenda {
    uint8_t data[0xC50];  // 0x408 to 0x1058 (field_0x408 to field_0x1058)
};

struct Creature : public Living {
    // No new virtual methods — uses Living's vtable (0xB40)

    // === Fields ===
    char16_t name[0x40];                   // 0xE0 — creature name (64 UTF-16 chars, 128 bytes)
    CreaturePhysical* physical;            // 0x160 — physical body state
    CreatureMental* mind;                  // 0x164 — AI mind
    GAlignment* alignment;                 // 0x168 — good/evil alignment
    uint32_t field_0x16c;                  // 0x16C
    uint32_t field_0x170;                  // 0x170
    uint32_t field_0x174;                  // 0x174
    uint32_t field_0x178;                  // 0x178
    uint32_t field_0x17c;                  // 0x17C
    uint32_t field_0x180;                  // 0x180
    uint32_t field_0x184;                  // 0x184
    CreatureHelpState help_state;          // 0x188
    uint8_t  help_stack_data[0x150];       // 0x220 — help stack entries (12 * 0x1c = 0x150 bytes)
    CreatureReceiveSpell* receive_spell;   // 0x370
    float    field_0x374;                  // 0x374
    float    field_0x378;                  // 0x378
    uint8_t  field_0x37c;                  // 0x37C
    uint8_t  field_0x37d;                  // 0x37D
    uint8_t  field_0x37e;                  // 0x37E
    uint8_t  field_0x37f;                  // 0x37F
    uint32_t field_0x380;                  // 0x380
    uint32_t field_0x384;                  // 0x384
    CreatureEmotionsForMusic emotions_for_music; // 0x388
    uint32_t field_0x390[0xE];             // 0x390 — 14 dwords
    uint32_t field_0x3c8;                  // 0x3C8
    uint32_t field_0x3cc;                  // 0x3CC
    Creature* next_creature;               // 0x3D0 — linked list
    uint32_t field_0x3d4;                  // 0x3D4
    MapCoords field_0x3d8;                 // 0x3D8
    uint32_t field_0x3e4;                  // 0x3E4
    uint32_t field_0x3e8;                  // 0x3E8
    MapCoords field_0x3ec;                 // 0x3EC
    uint8_t  field_0x3f8;                  // 0x3F8
    uint8_t  field_0x3f9;                  // 0x3F9
    uint8_t  field_0x3fa;                  // 0x3FA
    uint8_t  field_0x3fb;                  // 0x3FB
    float    field_0x3fc;                  // 0x3FC
    float    field_0x400;                  // 0x400
    uint8_t  field_0x404;                  // 0x404
    uint8_t  field_0x405;                  // 0x405
    uint8_t  field_0x406;                  // 0x406
    uint8_t  field_0x407;                  // 0x407
    CreatureSubActionAgenda sub_action_agenda; // 0x408
    int      field_0x1058;                 // 0x1058
    uint32_t field_0x105c;                 // 0x105C
    uint32_t field_0x1060;                 // 0x1060
    uint32_t field_0x1064;                 // 0x1064
    uint32_t field_0x1068;                 // 0x1068
    uint32_t field_0x106c;                 // 0x106C
    GPlayer* owner;                        // 0x1070 — owning player
    Dance*   dance;                        // 0x1074
    uint32_t field_0x1078;                 // 0x1078
    GParticleContainer* particle_container_0; // 0x107C
    GParticleContainer* particle_container_1; // 0x1080
    uint32_t field_0x1084;                 // 0x1084
    uint32_t field_0x1088;                 // 0x1088
    uint32_t field_0x108c;                 // 0x108C
    uint32_t field_0x1090;                 // 0x1090
    uint32_t field_0x1094;                 // 0x1094
    uint32_t field_0x1098;                 // 0x1098
    LH3DSmoke* smoke;                      // 0x109C
    GArena*  arena;                        // 0x10A0
    uint32_t field_0x10a4;                 // 0x10A4
    uint32_t field_0x10a8;                 // 0x10A8
    uint32_t field_0x10ac;                 // 0x10AC
    uint32_t field_0x10b0;                 // 0x10B0
    uint32_t field_0x10b4;                 // 0x10B4
    uint32_t field_0x10b8;                 // 0x10B8
    uint32_t field_0x10bc;                 // 0x10BC
    uint32_t field_0x10c0;                 // 0x10C0
    uint8_t  field_0x10c4[0x8];            // 0x10C4
    uint32_t field_0x10cc;                 // 0x10CC
    uint32_t field_0x10d0;                 // 0x10D0
    uint32_t field_0x10d4;                 // 0x10D4
    uint8_t  field_0x10d8[0x10];           // 0x10D8
    uint32_t field_0x10e8;                 // 0x10E8
    uint32_t field_0x10ec;                 // 0x10EC
    uint32_t field_0x10f0;                 // 0x10F0
    uint32_t field_0x10f4;                 // 0x10F4
    uint32_t field_0x10f8;                 // 0x10F8
    uint32_t field_0x10fc;                 // 0x10FC
    uint32_t field_0x1100;                 // 0x1100
    uint32_t field_0x1104;                 // 0x1104
    uint32_t field_0x1108;                 // 0x1108
    uint32_t field_0x110c;                 // 0x110C
    int      field_0x1110;                 // 0x1110
    uint32_t field_0x1114;                 // 0x1114
    uint32_t field_0x1118;                 // 0x1118
    uint32_t field_0x111c;                 // 0x111C
    uint32_t field_0x1120;                 // 0x1120
    int      game_turn;                    // 0x1124
    uint8_t  field_0x1128[0x28];           // 0x1128
    uint32_t field_0x1150;                 // 0x1150
    uint32_t field_0x1154;                 // 0x1154
    uint32_t field_0x1158;                 // 0x1158
    uint32_t field_0x115c;                 // 0x115C
    uint32_t field_0x1160;                 // 0x1160
    MapCoords field_0x1164;                // 0x1164
    uint32_t field_0x1170[0x8];            // 0x1170
    uint32_t field_0x1190;                 // 0x1190
    uint8_t  field_0x1194[0x14];           // 0x1194
    MapCoords field_0x11a8;                // 0x11A8
    uint32_t field_0x11b4;                 // 0x11B4
    uint32_t field_0x11b8;                 // 0x11B8
    uint32_t field_0x11bc;                 // 0x11BC
    uint32_t field_0x11c0;                 // 0x11C0
    uint32_t field_0x11c4;                 // 0x11C4
    uint32_t field_0x11c8;                 // 0x11C8
    MapCoords field_0x11cc;                // 0x11CC
    uint8_t  field_0x11d8[0xC];            // 0x11D8
    GParticleContainer* particle_container_2; // 0x11E4
    uint32_t field_0x11e8;                 // 0x11E8
    BookmarkGraphic* bookmark_graphic;     // 0x11EC
    uint8_t  field_0x11f0;                 // 0x11F0
    uint8_t  field_0x11f1;                 // 0x11F1
    uint8_t  field_0x11f2;                 // 0x11F2
    uint8_t  field_0x11f3;                 // 0x11F3
    uint32_t field_0x11f4;                 // 0x11F4
    uint32_t field_0x11f8;                 // 0x11F8
    uint32_t field_0x11fc;                 // 0x11FC
    MapCoords field_0x1200;                // 0x1200
    uint32_t field_0x120c;                 // 0x120C
    uint32_t field_0x1210;                 // 0x1210
    MapCoords field_0x1214;                // 0x1214
    uint32_t field_0x1220;                 // 0x1220
    uint32_t field_0x1224;                 // 0x1224
    uint8_t  field_0x1228[0x40];           // 0x1228
    int      field_0x1268;                 // 0x1268
    uint32_t field_0x126c;                 // 0x126C
    uint32_t field_0x1270;                 // 0x1270
    uint32_t field_0x1274;                 // 0x1274
    uint32_t field_0x1278;                 // 0x1278
    Bubble*  bubble;                       // 0x127C
    uint32_t field_0x1280;                 // 0x1280
    uint32_t field_0x1284;                 // 0x1284
    uint32_t field_0x1288;                 // 0x1288
    uint8_t  field_0x128c[0x8];            // 0x128C
    uint32_t field_0x1294;                 // 0x1294
    uint32_t field_0x1298;                 // 0x1298
    int      field_0x129c;                 // 0x129C
    uint32_t field_0x12a0;                 // 0x12A0
    uint32_t field_0x12a4;                 // 0x12A4
    uint32_t field_0x12a8;                 // 0x12A8
    uint8_t  field_0x12ac;                 // 0x12AC
    uint8_t  field_0x12ad;                 // 0x12AD
    uint8_t  field_0x12ae;                 // 0x12AE
    uint8_t  field_0x12af;                 // 0x12AF
    uint32_t field_0x12b0;                 // 0x12B0
    uint32_t field_0x12b4;                 // 0x12B4
    uint32_t field_0x12b8;                 // 0x12B8
    uint32_t field_0x12bc;                 // 0x12BC
    uint32_t field_0x12c0;                 // 0x12C0
    uint32_t field_0x12c4;                 // 0x12C4
};
static_assert(sizeof(Creature) == 0x12C8, "Creature size mismatch");
