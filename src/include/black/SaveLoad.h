#pragma once
// SaveLoad — the object-graph half of BW's native save format.
//
// GameOSFile does the bytes and the checksum; this does the graph. Pointers
// are not written as addresses: the first time an object reaches the stream it
// is given the next ordinal, that ordinal is written, and the object is then
// serialized inline right there. Every later reference to it writes just the
// ordinal. Load mirrors it -- an ordinal it has already seen resolves from the
// table, a fresh one means the object's bytes follow and it is registered
// before its fields are read so that cycles resolve.
//
// See SaveLoadTable.h for where the per-class field lists come from.

#include <stdint.h>

struct GameOSFile;
struct GameThing;

namespace saveload {

// Serialize `obj`'s own fields by walking its class chain root-first, the way
// the original's Save/Load delegation chain does. `save_type` is the object's
// GetSaveType(). Returns false if the type is unknown, was not recovered
// exactly (see IsSerializable), or the file has already failed.
bool SaveFields(GameOSFile& f, void* obj, uint32_t save_type);
bool LoadFields(GameOSFile& f, void* obj, uint32_t save_type);

// --- host hooks ----------------------------------------------------------
// Loading an object the stream has not seen before means constructing one of
// the right class. That is the game's business, not the serializer's, so the
// host supplies it; without a factory, loading a forward pointer fails cleanly
// instead of guessing.
using ObjectFactory = GameThing* (*)(uint32_t save_type);
void SetObjectFactory(ObjectFactory fn);
ObjectFactory GetObjectFactory();

// Info structs (GBaseInfo and friends) are shared, read-only game data; the
// original writes them as an index into their global table. The host owns
// those tables, so it supplies the mapping. Unmapped info pointers round-trip
// as index 0 / nullptr rather than dangling.
using InfoToIndex = uint32_t (*)(const void* info);
using IndexToInfo = void*    (*)(uint32_t index);
void SetInfoMapping(InfoToIndex to_index, IndexToInfo to_info);

}  // namespace saveload
