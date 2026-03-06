#pragma once
// GameOSFile — game file I/O with save/load pointer tracking
// Struct layout from bw1-decomp
// Size: 0x230 bytes

#include <stdint.h>

struct GameThing;
struct GBaseInfo;
struct GSaveLoadPtr;
struct LHOSFile;
struct MapCoords;

// LHReleasedOSFile is 0x8 bytes (opaque engine file handle)
struct LHReleasedOSFile {
    uint8_t data[0x8];  // 0x00
};
static_assert(sizeof(LHReleasedOSFile) == 0x8, "LHReleasedOSFile size mismatch");

// Per-type linked list structs (8 bytes each)
struct LHLinkedList_GSaveLoadPtr {
    GSaveLoadPtr* first;  // 0x00
    GSaveLoadPtr* last;   // 0x04
};
static_assert(sizeof(LHLinkedList_GSaveLoadPtr) == 0x8, "LHLinkedList_GSaveLoadPtr size mismatch");

struct LHLinkedList_GameThing_File {
    GameThing* first;  // 0x00
    GameThing* last;   // 0x04
};
static_assert(sizeof(LHLinkedList_GameThing_File) == 0x8, "LHLinkedList_GameThing_File size mismatch");

struct GameOSFile {
    LHReleasedOSFile          super;               // 0x00
    uint8_t                   field_0x8[0x40];     // 0x08
    uint8_t                   field_0x48[0xC4];    // 0x48
    uint32_t                  field_0x10c;         // 0x10C
    char                      filename[0x100];     // 0x110
    uint32_t                  field_0x210;         // 0x210
    uint32_t                  checksum;            // 0x214
    uint32_t                  field_0x218;         // 0x218
    uint32_t                  field_0x21c;         // 0x21C
    LHLinkedList_GSaveLoadPtr save_load_ptr_list;  // 0x220
    LHLinkedList_GameThing_File game_thing_list;   // 0x228
};
static_assert(sizeof(GameOSFile) == 0x230, "GameOSFile size mismatch");
