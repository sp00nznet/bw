// anm_loader — see anm_loader.h.

#include "anm_loader.h"
#include "l3d_loader.h"   // for BoneMatrix

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

namespace bw {

namespace {
constexpr char kMagic[16] = { 'L','i','O','n','H','e','A','d','J','u','l','i','e','n','0','\0' };

std::vector<uint8_t> Slurp(const std::string& path) {
    std::vector<uint8_t> buf;
    FILE* f = fopen(path.c_str(), "rb");
    if (!f) return buf;
    fseek(f, 0, SEEK_END);
    long sz = ftell(f);
    fseek(f, 0, SEEK_SET);
    if (sz > 0) {
        buf.resize(sz);
        fread(buf.data(), 1, sz, f);
    }
    fclose(f);
    return buf;
}

template <typename T>
const T* At(const std::vector<uint8_t>& buf, size_t off) {
    if (off + sizeof(T) > buf.size()) return nullptr;
    return reinterpret_cast<const T*>(buf.data() + off);
}
} // namespace

// ---------------------------------------------------------------------------
// LionHead Pack archive parser
// ---------------------------------------------------------------------------
//
// AllAnims.anm is a Pack file. Layout:
//   +0x00  "LiOnHeAd" (8 bytes file magic)
//   blocks, each:
//     +0x00  32-byte block name (null-padded)
//     +0x20  uint32 block size
//     +0x24  block body (size bytes)
//
// Animation archives have a "Body" block plus one "Julien<i>" block per
// animation. The Body block's payload is:
//   "MKJC" (4 bytes)
//   uint32 totalAnimations
//   BodyBlockLookup[totalAnimations]  (uint32 offset + uint32 unknown)
// where each `offset` points into the Body block, and there we find the
// 0x54 ANMHeader bytes for that animation. The remainder of the ANM file
// (frame offset table + bone data) lives in the corresponding "Julien<i>"
// block — concatenating header + julien yields a normal .anm file body.

namespace {

struct PackBlock {
    std::string            name;
    std::vector<uint8_t>   data;
};

bool ParsePackBlocks(const std::vector<uint8_t>& buf,
                     std::vector<PackBlock>& out) {
    static constexpr char kFileMagic[8] = { 'L','i','O','n','H','e','A','d' };
    if (buf.size() < 8 || memcmp(buf.data(), kFileMagic, 8) != 0) return false;

    size_t pos = 8;
    while (pos + 0x24 <= buf.size()) {
        // Read 32-byte name + 4-byte size.
        char name[33] = {};
        memcpy(name, buf.data() + pos, 32);
        uint32_t size = *reinterpret_cast<const uint32_t*>(buf.data() + pos + 32);
        size_t body_start = pos + 0x24;
        if (body_start + size > buf.size()) {
            // Truncated — accept what we have so far.
            break;
        }
        PackBlock blk;
        blk.name = name;
        blk.data.assign(buf.data() + body_start, buf.data() + body_start + size);
        out.push_back(std::move(blk));
        pos = body_start + size;
    }
    return !out.empty();
}

const PackBlock* FindBlock(const std::vector<PackBlock>& blocks,
                           const std::string& name) {
    for (const auto& b : blocks) {
        if (b.name == name) return &b;
    }
    return nullptr;
}

} // namespace

bool LoadANM(const std::string& path, ANMArchive& out) {
    out = {};
    out.filename = path;

    auto buf = Slurp(path);
    if (buf.size() < 0x30) {
        fprintf(stderr, "ANM: file too small: %s\n", path.c_str());
        return false;
    }

    std::vector<PackBlock> blocks;
    if (!ParsePackBlocks(buf, blocks)) {
        fprintf(stderr, "ANM: bad LiOnHeAd magic in %s\n", path.c_str());
        return false;
    }

    const PackBlock* body = FindBlock(blocks, "Body");
    if (!body) {
        fprintf(stderr, "ANM: no Body block in %s\n", path.c_str());
        return false;
    }
    if (body->data.size() < 8 || memcmp(body->data.data(), "MKJC", 4) != 0) {
        fprintf(stderr, "ANM: Body block missing MKJC magic in %s\n", path.c_str());
        return false;
    }

    uint32_t total = *reinterpret_cast<const uint32_t*>(body->data.data() + 4);
    constexpr uint32_t ANM_HEADER_SIZE = 0x54;
    constexpr uint32_t LOOKUP_STRIDE   = 8;  // offset(4) + unknown(4)

    if (8 + total * LOOKUP_STRIDE > body->data.size()) {
        fprintf(stderr, "ANM: Body block lookup table truncated (%u entries)\n", total);
        return false;
    }

    out.packed_animations.reserve(total);
    out.entries.reserve(total);
    for (uint32_t i = 0; i < total; ++i) {
        uint32_t lookup_off = 8 + i * LOOKUP_STRIDE;
        uint32_t hdr_off = *reinterpret_cast<const uint32_t*>(body->data.data() + lookup_off);
        if (hdr_off + ANM_HEADER_SIZE > body->data.size()) {
            fprintf(stderr, "ANM: animation %u header offset 0x%X out of range\n", i, hdr_off);
            continue;
        }

        char julien_name[40];
        snprintf(julien_name, sizeof(julien_name), "Julien%u", i);
        const PackBlock* julien = FindBlock(blocks, julien_name);
        if (!julien) {
            fprintf(stderr, "ANM: missing %s block\n", julien_name);
            continue;
        }

        // Reconstruct the full .anm bytes: header from Body + payload
        // from Julien<i>.
        std::vector<uint8_t> anm_bytes;
        anm_bytes.reserve(ANM_HEADER_SIZE + julien->data.size());
        anm_bytes.insert(anm_bytes.end(),
                         body->data.begin() + hdr_off,
                         body->data.begin() + hdr_off + ANM_HEADER_SIZE);
        anm_bytes.insert(anm_bytes.end(), julien->data.begin(), julien->data.end());

        ANMEntry e;
        e.file_offset = hdr_off;
        e.header_value = total;
        out.entries.push_back(e);
        out.packed_animations.push_back(std::move(anm_bytes));
    }

    out.header_field_0x28 = total;
    out.loaded = !out.packed_animations.empty();

    printf("ANM(archive): %s — %zu blocks, %u animations extracted\n",
           path.c_str(), blocks.size(), total);
    fflush(stdout);

    return out.loaded;
}

// ===========================================================================
// Single-animation parser
// ===========================================================================

static bool ParseSingleAnm(const std::vector<uint8_t>& buf,
                           const std::string& debug_name,
                           ANMSingle& out) {
    if (buf.size() < 0x100) {
        fprintf(stderr, "ANM(single): buffer too small: %s\n", debug_name.c_str());
        return false;
    }

    char name[33] = {};
    memcpy(name, buf.data(), 32);
    out.source_name = name;

    const float* fp = reinterpret_cast<const float*>(buf.data() + 0x28);
    out.frame_time_sec = *fp;

    uint32_t frame_count   = *At<uint32_t>(buf, 0x38);
    uint32_t frame_table_0 = *At<uint32_t>(buf, 0x4C);

    // Header at 0x40 carries the animation_duration field (per openblack)
    // rather than file size; for animations extracted from the archive
    // the buffer is the header-prefixed body, not the raw on-disk file.

    out.frame_count = frame_count;
    out.frames.reserve(frame_count);

    // For each frame: follow the 3-level offset indirection then read the
    // bone block at the deepest pointer (boneCount, time, bones[]).
    for (uint32_t i = 0; i < frame_count; ++i) {
        uint32_t cell = frame_table_0 + i * 4;
        if (cell + 4 > buf.size()) break;

        uint32_t a = *At<uint32_t>(buf, cell);
        if (a == 0xFFFFFFFFu || a + 4 > buf.size()) break;
        uint32_t b = *At<uint32_t>(buf, a);
        if (b == 0 || b + 4 > buf.size()) break;
        uint32_t c = *At<uint32_t>(buf, b);
        if (c == 0 || c + 8 > buf.size()) break;

        ANMFrame frame;
        frame.bone_count = *At<uint32_t>(buf, c);
        if (frame.bone_count == 0 || frame.bone_count > 256) {
            fprintf(stderr, "ANM(single): suspicious bone count %u at frame %u\n",
                    frame.bone_count, i);
            break;
        }
        // c+4 is the keyframe time/timestamp slot — read but currently
        // unused; per-frame timing is reconstructed from frame_time_sec.

        const size_t needed = frame.bone_count * 12 * sizeof(float);
        if (c + 8 + needed > buf.size()) break;

        frame.bone_data.resize(frame.bone_count * 12);
        memcpy(frame.bone_data.data(), buf.data() + c + 8, needed);
        out.frames.push_back(std::move(frame));
    }

    printf("ANM(single): %s — \"%s\", %u frames @ %.4fs each, %zu decoded, %u bones/frame\n",
           debug_name.c_str(), out.source_name.c_str(),
           frame_count, out.frame_time_sec,
           out.frames.size(),
           out.frames.empty() ? 0 : out.frames[0].bone_count);
    fflush(stdout);

    out.loaded = !out.frames.empty();
    return out.loaded;
}

bool LoadANMSingle(const std::string& path, ANMSingle& out) {
    out = {};
    out.filename = path;
    auto buf = Slurp(path);
    if (buf.empty()) {
        fprintf(stderr, "ANM(single): cannot open %s\n", path.c_str());
        return false;
    }
    return ParseSingleAnm(buf, path, out);
}

bool LoadANMSingleBytes(const std::vector<uint8_t>& bytes,
                        const std::string& debug_name,
                        ANMSingle& out) {
    out = {};
    out.filename = debug_name;
    return ParseSingleAnm(bytes, debug_name, out);
}

// ---------------------------------------------------------------------------
// Frame → pose application
// ---------------------------------------------------------------------------

namespace {
// Build the LOCAL 4x4 (column-major) for bone `b` from its 12-float record.
inline void BoneLocalFromANM(const float* f, BoneMatrix& out) {
    out.m[ 0] = f[0]; out.m[ 1] = f[1]; out.m[ 2] = f[2]; out.m[ 3] = 0;
    out.m[ 4] = f[3]; out.m[ 5] = f[4]; out.m[ 6] = f[5]; out.m[ 7] = 0;
    out.m[ 8] = f[6]; out.m[ 9] = f[7]; out.m[10] = f[8]; out.m[11] = 0;
    out.m[12] = f[9]; out.m[13] = f[10]; out.m[14] = f[11]; out.m[15] = 1;
}

// world[b] = world[parent] * local[b], 4x4 column-major.
inline void Compose(const BoneMatrix& parent, const BoneMatrix& local, BoneMatrix& out) {
    const float* P = parent.m;
    const float* L = local.m;
    float* R = out.m;
    for (int c = 0; c < 4; ++c) {
        for (int r = 0; r < 4; ++r) {
            R[c*4 + r] = P[0*4 + r]*L[c*4 + 0]
                       + P[1*4 + r]*L[c*4 + 1]
                       + P[2*4 + r]*L[c*4 + 2]
                       + P[3*4 + r]*L[c*4 + 3];
        }
    }
}
} // namespace

void ApplyANMFrame(const ANMSingle& anm,
                   uint32_t frame_index,
                   const std::vector<uint32_t>& parent_indices,
                   std::vector<BoneMatrix>& out_world) {
    out_world.clear();
    if (!anm.loaded || anm.frames.empty()) return;
    if (frame_index >= anm.frames.size()) frame_index = static_cast<uint32_t>(anm.frames.size() - 1);
    const ANMFrame& frame = anm.frames[frame_index];

    const uint32_t bone_count = std::min<uint32_t>(
        frame.bone_count,
        static_cast<uint32_t>(parent_indices.size()));

    out_world.resize(bone_count);
    for (uint32_t b = 0; b < bone_count; ++b) {
        BoneMatrix local;
        BoneLocalFromANM(&frame.bone_data[b * 12], local);

        uint32_t parent = parent_indices[b];
        if (parent != 0xFFFFFFFFu && parent < b) {
            Compose(out_world[parent], local, out_world[b]);
        } else {
            out_world[b] = local;
        }
    }
}

void ApplyANMFrameLerp(const ANMSingle& anm,
                       uint32_t frame_a, uint32_t frame_b, float t,
                       const std::vector<uint32_t>& parent_indices,
                       std::vector<BoneMatrix>& out_world) {
    out_world.clear();
    if (!anm.loaded || anm.frames.empty()) return;

    const uint32_t n = static_cast<uint32_t>(anm.frames.size());
    if (frame_a >= n) frame_a = n - 1;
    if (frame_b >= n) frame_b = n - 1;
    if (t < 0.0f) t = 0.0f; else if (t > 1.0f) t = 1.0f;

    const ANMFrame& fa = anm.frames[frame_a];
    const ANMFrame& fb = anm.frames[frame_b];

    // Pick the smaller bone count so both frames' float arrays are valid.
    uint32_t bone_count = std::min<uint32_t>(fa.bone_count, fb.bone_count);
    bone_count = std::min<uint32_t>(bone_count,
                                    static_cast<uint32_t>(parent_indices.size()));

    out_world.resize(bone_count);
    const float u = 1.0f - t;

    for (uint32_t b = 0; b < bone_count; ++b) {
        // Lerp the 12 floats column-by-column then build the local matrix.
        float lerped[12];
        const float* a = &fa.bone_data[b * 12];
        const float* d = &fb.bone_data[b * 12];
        for (int i = 0; i < 12; ++i) lerped[i] = a[i] * u + d[i] * t;

        BoneMatrix local;
        BoneLocalFromANM(lerped, local);

        uint32_t parent = parent_indices[b];
        if (parent != 0xFFFFFFFFu && parent < b) {
            Compose(out_world[parent], local, out_world[b]);
        } else {
            out_world[b] = local;
        }
    }
}

} // namespace bw
