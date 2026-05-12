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
    uint32_t     header_field_0x28 = 0;
    std::vector<ANMEntry> entries;
    // Animations extracted from a LionHead "Pack" archive. Each entry's
    // bytes are a self-contained .anm file body that LoadANMSingleBytes
    // can parse directly. Populated only when the file is a Pack
    // (typical for AllAnims.anm).
    std::vector<std::vector<uint8_t>> packed_animations;
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
// Each frame uses a 3-level offset indirection chain (cross-checked
// against openblack's reference reader for the same format):
//
//   framesBase[i]       — read uint32 to get  A (keyframe pointer cell)
//   *A                  — read uint32 to get  B (bone offset cell)
//   *B                  — read uint32 to get  C (bone block start)
//   *(C + 0)            — bone count for this frame
//   *(C + 4)            — frame time (often equals C + 8 — overloaded)
//   C + 8 ..            — bone_count × 48 bytes = 12 floats per bone
//
// In practice for anim.anm the data is densely packed so the bone block
// starts at framesBase[i] + 8 and the chain is effectively linear, but
// the indirection is real and must be honored.
//
// The 12 floats per bone describe a 4x3 affine in column-major layout:
//   floats[0..2]   X-axis basis vector  (column 0 of 4x4)
//   floats[3..5]   Y-axis basis vector  (column 1 of 4x4)
//   floats[6..8]   Z-axis basis vector  (column 2 of 4x4)
//   floats[9..11]  Translation          (column 3 of 4x4)
// The matrix is the bone's LOCAL transform relative to its parent.

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

// Parse an in-memory .anm buffer (no I/O). Used to load animations
// extracted from a Pack archive.
bool LoadANMSingleBytes(const std::vector<uint8_t>& bytes,
                        const std::string& debug_name,
                        ANMSingle& out);

// Build a per-bone world-space pose at the given frame index. Each LOCAL
// matrix from the keyframe is combined with its parent's world matrix
// using `parent_indices[i] == 0xFFFFFFFF` to mark the root. Bone count
// must match between the animation and the receiving skeleton; mismatched
// indices fall through to the bind pose (identity).
struct BoneMatrix;  // forward — defined in l3d_loader.h
void ApplyANMFrame(const ANMSingle& anm,
                   uint32_t frame_index,
                   const std::vector<uint32_t>& parent_indices,
                   std::vector<BoneMatrix>& out_world);

// Same as ApplyANMFrame but interpolates between two adjacent keyframes.
// `frame_a` and `frame_b` should be consecutive frame indices; `t` in
// [0,1] is the blend factor. Linear-blends the bone's LOCAL matrices
// column-by-column before composing the hierarchy.
void ApplyANMFrameLerp(const ANMSingle& anm,
                       uint32_t frame_a, uint32_t frame_b, float t,
                       const std::vector<uint32_t>& parent_indices,
                       std::vector<BoneMatrix>& out_world);

} // namespace bw
