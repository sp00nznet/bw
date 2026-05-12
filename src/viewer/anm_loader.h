// anm_loader — Lionhead .anm animation file parser (work in progress).
//
// AllAnims.anm and friends use a "LiOnHeAdJulien0" magic and an
// undocumented binary layout. This module currently reads the header,
// confirms the magic, captures the metadata word at +0x28, and walks the
// table of per-animation offset entries. Frame data inside each entry
// (quaternion + translation tracks per bone) is decoded enough to identify
// it but not yet plugged into the animator — that's a follow-up once the
// per-bone track stride is locked down.

#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace bw {

struct ANMEntry {
    uint32_t file_offset;   // where the entry begins in the file
    uint32_t header_value;  // first u32 inside the entry (counts/flags)
};

struct ANMArchive {
    std::string  filename;
    uint32_t     header_field_0x28 = 0;  // unknown; possibly anim count or
                                          //  total-frame count
    std::vector<ANMEntry> entries;        // one per top-level animation
    bool         loaded = false;
};

// Load and inspect an ANM file. Returns true if the magic matched and at
// least one entry offset was recovered. Currently does not produce a
// playable animation — it builds the table of contents.
bool LoadANM(const std::string& path, ANMArchive& out);

} // namespace bw
