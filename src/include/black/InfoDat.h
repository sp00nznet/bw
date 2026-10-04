#pragma once
// InfoDat — loads scripts/info.dat, the game's balance data (every speed, cost,
// capacity and threshold), into the same in-memory shape the original builds.
//
// The file is a 44-byte header and then 102 sections back to back, with no tags
// or lengths: the layout lives only in the loader's code (InfoDatLayout.gen.h,
// docs/info-dat.md). Each record is copied to +16 of an element whose first 16
// bytes are the GBaseInfo header, so a pointer from Element() reads exactly
// like the original's info pointer: code that reads `info + 0x120` gets the
// field the original got.

#include "InfoDatLayout.gen.h"
#include <cstdint>
#include <string>

namespace infodat {

// Parses and validates the file. Refuses (returns false, *err set) on a bad
// magic, a payload size that disagrees with the layout, or a short file; a
// partial load would hand out wrong numbers rather than missing ones.
bool Load(const char* path, std::string* err = nullptr);
bool LoadFromMemory(const uint8_t* data, size_t size, std::string* err = nullptr);
bool Loaded();
void Unload();

uint32_t Count(Section s);
// Element i of section s (GBaseInfo header + record), or nullptr if not loaded
// or out of range.
const void* Element(Section s, uint32_t i);

template <class T> const T* Get(Section s, uint32_t i) {
    return static_cast<const T*>(Element(s, i));
}

// Level scripts name types rather than index them. Both return an element
// index or -1.
//   FindByName: the record's display name, upper-cased with '_' for ' ', equal
//     to the script name or to it plus "_MALE"/"_FEMALE" ("CELTIC_FORESTER" ->
//     "Celtic Forester Male"; "Crater" -> "Crater").
//   FindAbode: "<TRIBE>_<TAG>" against the record's own tribe and tag fields
//     ("NORSE_ABODE_C" -> tribe 7, "ABODE_C"); abode display names repeat
//     ("Town Centre") so they cannot be used.
int FindByName(Section s, const char* script_name);
int FindAbode(const char* script_name);

// Record names live at +24 (+8 into the record) for every section built on the
// shared 240-byte object block; empty for sections without one.
const char* DebugName(Section s, uint32_t i);

} // namespace infodat
