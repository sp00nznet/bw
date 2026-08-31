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
    LHReleasedOSFile          super;               // 0x00 — OS handle (we stash FILE* here)
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

    // --- Serialization primitives (translated from the v1.0 binary) ---------
    //
    // The original tracks "has the stream gone bad" in two globals (one per
    // direction) and every primitive is a no-op once they are clear, so a
    // failed write does not cascade into garbage. `failed` is that flag, and
    // `ptr_table` is the ordinal table SavePtr/LoadPtr assign from -- both
    // live in the original's unused field_0x8 block so the struct keeps its
    // 0x230 layout.
    // The byte-level format is what matters for save compatibility, so we
    // reproduce that with plain C I/O rather than the original's opaque OS
    // layer (off_7EB2E8 et al). Per write/read the running checksum at 0x214
    // accumulates (firstByteOfBuffer + byteCount), exactly as GameThing::Save
    // / SaveExtraData do in the binary (sub_53E8E0 / sub_53EA90).
    bool     Open(const char* path, bool writing);   // false on failure
    void     Close();
    bool     IsOpen() const;
    // Write/Read `size` bytes; return true on success (3-on-error in the
    // binary maps to false here). Both fold the buffer into `checksum`.
    bool     Write(const void* buf, uint32_t size);
    bool     Read(void* buf, uint32_t size);
    uint32_t GetChecksum() const { return checksum; }

    // Sticky "the stream went bad" flag; every primitive below is a no-op once
    // it is set, matching the original's dword_B19AC8 / dword_B19ACC.
    bool     Failed() const;
    void     Fail();

    // The running checksum, written into the stream as a marker and folded
    // back in (sub_533C50 / sub_533C90). GameThing emits one per object.
    void     WriteChecksumMarker();
    void     ReadChecksumMarker();

    // GameThing* <-> stream ordinal, with the pointee serialized inline the
    // first time it is seen. See SaveLoad.h.
    void     SavePtr(GameThing* obj);
    void     LoadPtr(GameThing** out);

    // GBaseInfo* <-> info-table index, via the host mapping in SaveLoad.h.
    void     SaveInfoPtr(const void* info);
    void     LoadInfoPtr(void** out);

    // Reset the per-file serialization state (ordinal table + failed flag).
    void     ResetSaveState();
};
static_assert(sizeof(GameOSFile) == 0x230, "GameOSFile size mismatch");
