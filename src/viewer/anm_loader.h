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
    uint32_t     header_field_0x28 = 0;  // archive-only; appears to be the
                                          //  total frame count across all
                                          //  embedded animations (≈ 11748
                                          //  for AllAnims.anm)
    std::vector<ANMEntry> entries;        // archive-only: one per anim
    bool         loaded = false;
};

// --- Single-animation .anm files (Anims/*.anm) ----------------------------
//
// Layout (all little-endian):
//   0x00..0x1F  source max-file name, null-padded (32 bytes)
//   0x20        uint32  unknown
//   0x24        float   unknown (appears to be a very small constant)
//   0x28        float   frame time in seconds (typically 0.025 = 40 fps)
//   0x2C..0x33  reserved zeros
//   0x34        float   frame time, duplicate of 0x28
//   0x38        uint32  frame count
//   0x3C        uint32  ?? always 1 in observed files
//   0x40        uint32  total file size in bytes
//   0x44        uint32  ?? always 1
//   0x48        uint32  offset of sentinel cell that ends the frame offset
//                       table (i.e. one past the last frame offset)
//   0x4C        uint32  offset where the frame offset table begins (0x54)
//   0x50        uint32  ?? (unidentified — looks like a constant)
//   0x54+       uint32 frame_offset[]  — one entry per frame, terminated
//                                        by 0xFFFFFFFF at offset 0x48
//
// Each frame is 0x400 = 1024 bytes laid out as:
//   +0x00  uint32  pointer-to-self + 4    (sub-section A)
//   +0x04  uint32  pointer-to-self + 8    (sub-section B)
//   +0x08  uint32  bone count             (21 in observed villager anim)
//   +0x0C  uint32  pointer-to-self + 16   (start of bone array)
//   +0x10  bone[bone_count]               48 bytes each = 12 floats
//
// The 12 floats per bone represent a per-frame transformation; positions
// 9 and 11 are stable across frames, suggesting they encode bone-length
// or fixed axis terms. The exact decomposition (rotation/translation/
// scale layout) is still under investigation — see DecodeFrame() below
// for the current best-guess interpretation.

struct ANMFrame {
    uint32_t                   bone_count;
    // Raw 12-float bone records, kept verbatim so future decoders can try
    // different interpretations without re-reading the file.
    std::vector<float>         bone_data;   // size = bone_count * 12
};

struct ANMSingle {
    std::string             filename;
    std::string             source_name;     // "M_P_Conduct_Meeting.max" etc.
    float                   frame_time_sec = 0;
    uint32_t                frame_count    = 0;
    std::vector<ANMFrame>   frames;
    bool                    loaded = false;
};

// Load an archive (multiple animations) — used for AllAnims.anm.
bool LoadANM(const std::string& path, ANMArchive& out);

// Load a single animation file — used for Anims/*.anm.
bool LoadANMSingle(const std::string& path, ANMSingle& out);

} // namespace bw
