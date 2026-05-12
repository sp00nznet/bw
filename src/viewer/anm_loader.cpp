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

bool LoadANM(const std::string& path, ANMArchive& out) {
    out = {};
    out.filename = path;

    auto buf = Slurp(path);
    if (buf.size() < 0x30) {
        fprintf(stderr, "ANM: file too small: %s\n", path.c_str());
        return false;
    }

    // Magic check
    if (memcmp(buf.data(), kMagic, 16) != 0) {
        fprintf(stderr, "ANM: bad magic in %s\n", path.c_str());
        return false;
    }

    out.header_field_0x28 = *At<uint32_t>(buf, 0x28);

    // Walk the offset table starting at 0x2C. Each cell is a 4-byte file
    // offset to an entry. The table ends when a value stops looking like
    // a forward-growing offset (the entries are roughly contiguous, so a
    // value that goes backwards or jumps wildly signals end-of-table).
    uint32_t prev_offset = 0;
    constexpr size_t TABLE_START = 0x2C;
    for (size_t cell = TABLE_START; cell + 4 <= buf.size(); cell += 4) {
        uint32_t v = *At<uint32_t>(buf, cell);
        // Heuristic: real entry offsets are > 0xC0 (after header) and
        // monotonically increase by a few hundred bytes at a time. Stop
        // once we see something that breaks the pattern.
        if (v < 0xC0) break;
        if (v >= buf.size()) break;
        if (prev_offset != 0 && (v < prev_offset || v - prev_offset > 0x4000)) break;

        ANMEntry e;
        e.file_offset = v;
        e.header_value = *At<uint32_t>(buf, v);
        out.entries.push_back(e);
        prev_offset = v;
    }

    printf("ANM: %s — magic OK, field@0x28=%u (0x%X), %zu entries\n",
           path.c_str(), out.header_field_0x28, out.header_field_0x28,
           out.entries.size());
    if (!out.entries.empty()) {
        printf("ANM:   first entry @ 0x%X (header_value=%u), "
               "last entry @ 0x%X\n",
               out.entries.front().file_offset,
               out.entries.front().header_value,
               out.entries.back().file_offset);
    }
    fflush(stdout);

    out.loaded = true;
    return true;
}

// ===========================================================================
// Single-animation parser
// ===========================================================================

bool LoadANMSingle(const std::string& path, ANMSingle& out) {
    out = {};
    out.filename = path;

    auto buf = Slurp(path);
    if (buf.size() < 0x100) {
        fprintf(stderr, "ANM(single): file too small: %s\n", path.c_str());
        return false;
    }

    char name[33] = {};
    memcpy(name, buf.data(), 32);
    out.source_name = name;

    const float* fp = reinterpret_cast<const float*>(buf.data() + 0x28);
    out.frame_time_sec = *fp;

    uint32_t frame_count   = *At<uint32_t>(buf, 0x38);
    uint32_t file_size     = *At<uint32_t>(buf, 0x40);
    uint32_t frame_table_0 = *At<uint32_t>(buf, 0x4C);

    if (file_size != buf.size()) {
        fprintf(stderr, "ANM(single): size mismatch (header says %u, file is %zu)\n",
                file_size, buf.size());
    }

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
           path.c_str(), out.source_name.c_str(),
           frame_count, out.frame_time_sec,
           out.frames.size(),
           out.frames.empty() ? 0 : out.frames[0].bone_count);
    fflush(stdout);

    out.loaded = !out.frames.empty();
    return out.loaded;
}

// ---------------------------------------------------------------------------
// Frame → pose application
// ---------------------------------------------------------------------------

void ApplyANMFrame(const ANMSingle& anm,
                   uint32_t frame_index,
                   const std::vector<uint32_t>& parent_indices,
                   std::vector<BoneMatrix>& out_world) {
    out_world.clear();
    if (!anm.loaded || anm.frames.empty()) return;
    if (frame_index >= anm.frames.size()) frame_index = anm.frames.size() - 1;
    const ANMFrame& frame = anm.frames[frame_index];

    const uint32_t bone_count = std::min<uint32_t>(
        frame.bone_count,
        static_cast<uint32_t>(parent_indices.size()));

    out_world.resize(bone_count);

    // For each bone: build the 4x4 LOCAL matrix from its 12-float record,
    // then compose with the parent's world to produce the world matrix.
    for (uint32_t b = 0; b < bone_count; ++b) {
        const float* f = &frame.bone_data[b * 12];
        BoneMatrix local;
        // Column-major 4x4 with X axis / Y axis / Z axis / translation.
        local.m[ 0] = f[0]; local.m[ 1] = f[1]; local.m[ 2] = f[2]; local.m[ 3] = 0;
        local.m[ 4] = f[3]; local.m[ 5] = f[4]; local.m[ 6] = f[5]; local.m[ 7] = 0;
        local.m[ 8] = f[6]; local.m[ 9] = f[7]; local.m[10] = f[8]; local.m[11] = 0;
        local.m[12] = f[9]; local.m[13] = f[10]; local.m[14] = f[11]; local.m[15] = 1;

        uint32_t parent = parent_indices[b];
        if (parent != 0xFFFFFFFFu && parent < b) {
            // world[b] = world[parent] * local[b]   (column-major mult).
            const float* P = out_world[parent].m;
            const float* L = local.m;
            float* R = out_world[b].m;
            for (int c = 0; c < 4; ++c) {
                for (int r = 0; r < 4; ++r) {
                    R[c*4 + r] = P[0*4 + r]*L[c*4 + 0]
                               + P[1*4 + r]*L[c*4 + 1]
                               + P[2*4 + r]*L[c*4 + 2]
                               + P[3*4 + r]*L[c*4 + 3];
                }
            }
        } else {
            out_world[b] = local;
        }
    }
}

} // namespace bw
