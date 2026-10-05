// SpellFile — the particle graphs behind every spell effect, as shipped in
// game_data/ZSpellFiles/SF_*_txt.zzz. docs/psys-files.md.
//
// Each file is a 4-byte size, then a zlib stream of text: a header block of
// properties (DeleteOnCloseDown, Hierarchies[25], InitiallyCreated[25],
// MaxSpellAge), then BEGINCLASS <Type> <Name> blocks, each a list of
// "PROPERTY <Name> <TYPE> <value...>" lines. Rules belong to one of the 25
// groups ("Group"), emit into others ("NextGroups") and refer to one another
// by name (PERSIS_PNTR).
#pragma once

#include <cstdint>
#include <map>
#include <string>
#include <vector>

namespace psys {

struct Property {
    std::string type;              // BOOL INTEGER FLOAT STRING PERSIS_PNTR ARRAY SOUND_ACTION ENUM
    std::vector<std::string> raw;  // the value's words as written (ARRAY: "SIZE", n, items...)

    bool        Bool() const;
    int32_t     Int() const;
    float       Float() const;
    std::string Str() const;       // STRING / PERSIS_PNTR / ENUM; "" for NULL_STRING
    std::vector<float> Array() const;
};

struct SpellClass {
    std::string type;  // e.g. UR_HandSprinkle
    std::string name;  // e.g. UR_HandSprinkle0
    std::map<std::string, Property> props;
    const Property* Get(const std::string& n) const;
};

struct SpellFile {
    std::map<std::string, Property> header;
    std::vector<SpellClass> classes;
    const SpellClass* Find(const std::string& name) const;

    bool Load(const std::string& path);      // a .zzz
    bool Parse(const std::string& text);
};

// zlib (RFC 1950/1951) inflate: stored, fixed and dynamic Huffman blocks.
bool Inflate(const uint8_t* in, size_t n, std::vector<uint8_t>* out);

}  // namespace psys
