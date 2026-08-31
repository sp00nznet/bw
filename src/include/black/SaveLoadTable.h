#pragma once
// SaveLoadTable — the recovered shape of BW's object save stream.
//
// The original serializes an object by walking its class chain from the root
// down, each level writing its own fields after delegating to its parent:
//
//     uint32_t Rock::Save(GameOSFile* f) {
//         if (!SingleMapFixed::Save(f)) return 0;
//         f->Write(this + 0x88, 4);  f->Write(this + 0x8C, 4);
//         f->SavePtr(*(this + 0x90));
//         return 1;
//     }
//
// Every one of those bodies is that same shape, so instead of 200 hand-copied
// method pairs the field lists are extracted straight from the binary (vtable
// slots 58/59, see tools/decomp/) into the tables below, and one chain walker
// in SaveLoad.cpp plays them back in either direction. That keeps save and
// load provably symmetric and puts every offset one regeneration away from the
// binary rather than one typo away from a corrupt save.
//
// Regenerate with:  python work/parse_saveslots.py && python work/gen_saveload.py

#include <stdint.h>

namespace saveload {

enum FieldOp : uint8_t {
    OP_RAW,       // n raw bytes at `off`
    OP_PTR,       // GameThing* at `off`, written as a stream ordinal
    OP_INFO,      // GBaseInfo* at `off`, written as an info-table index
    OP_PTRARRAY,  // count(4) then `n` GameThing* starting at `off`
    OP_RAWARRAY,  // count(4) then `n` dwords starting at `off`
    OP_CHECKSUM,  // the running checksum, written into the stream as a marker
};

// Rows whose original body branches or walks a container instead of running a
// flat field list. SaveLoad.cpp implements these by hand.
enum Hook : uint8_t {
    HOOK_NONE,
    HOOK_OBJECT,  // Object: fields then a conditional physics-transform block
    HOOK_LIVING,  // Living: fields then a trailing linked-list dump
    HOOK_MOBILE,  // MobileWallHug: a hold-type dependent middle block
};

struct Field {
    uint16_t off;  // byte offset into the object
    uint16_t n;    // byte count, or element count for the array ops
    uint8_t  op;   // FieldOp
};

struct ClassDesc {
    const char* name;
    int16_t     parent;  // index into kClasses, -1 at the root
    uint16_t    first;   // slice of kFields contributed by this level
    uint16_t    count;
    uint8_t     hook;    // Hook; when set, `count` is 0 and the hook does it all
    bool        exact;   // false: the original body has logic we did not model
};

struct SaveTypeRow {
    uint16_t id;   // GetSaveType() value
    uint16_t cls;  // index into kClasses
};

extern const Field       kFields[];
extern const ClassDesc   kClasses[];
extern const uint16_t    kClassCount;
extern const SaveTypeRow kSaveTypes[];
extern const uint16_t    kSaveTypeCount;

// Index into kClasses for a save-type id, or -1 if the id is not one we know.
int RowForSaveType(uint32_t save_type);

// Whether every level from the root down to `save_type` was recovered exactly.
// Serializing a type that is not exact would produce a stream that silently
// disagrees with the original, so the walker refuses it.
bool IsSerializable(uint32_t save_type);

// Name of the class a save-type id belongs to, or nullptr.
const char* NameForSaveType(uint32_t save_type);

}  // namespace saveload
