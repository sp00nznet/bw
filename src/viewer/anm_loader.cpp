// anm_loader — see anm_loader.h.

#include "anm_loader.h"

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

    // Source filename is the first 32 bytes, null-padded.
    char name[33] = {};
    memcpy(name, buf.data(), 32);
    out.source_name = name;

    // Header fields per the doc in anm_loader.h.
    const float* fp = reinterpret_cast<const float*>(buf.data() + 0x28);
    out.frame_time_sec = *fp;

    uint32_t frame_count   = *At<uint32_t>(buf, 0x38);
    uint32_t file_size     = *At<uint32_t>(buf, 0x40);
    uint32_t frame_table_0 = *At<uint32_t>(buf, 0x4C);
    uint32_t frame_table_end = *At<uint32_t>(buf, 0x48);

    if (file_size != buf.size()) {
        fprintf(stderr, "ANM(single): size mismatch (header says %u, file is %zu)\n",
                file_size, buf.size());
    }
    if (frame_table_0 != 0x54) {
        fprintf(stderr, "ANM(single): unexpected frame table start 0x%X (expected 0x54)\n",
                frame_table_0);
    }

    // Walk the frame offset table.
    out.frame_count = frame_count;
    out.frames.reserve(frame_count);
    constexpr uint32_t FRAME_STRIDE = 0x400;

    for (uint32_t i = 0; i < frame_count; ++i) {
        uint32_t cell = frame_table_0 + i * 4;
        if (cell + 4 > buf.size()) break;
        uint32_t fofs = *At<uint32_t>(buf, cell);
        if (fofs == 0xFFFFFFFFu) break;
        if (fofs + FRAME_STRIDE > buf.size()) break;

        ANMFrame frame;
        // Frame header occupies the first 16 bytes; bone count is at +8.
        frame.bone_count = *At<uint32_t>(buf, fofs + 8);
        if (frame.bone_count == 0 || frame.bone_count > 256) {
            fprintf(stderr, "ANM(single): suspicious bone count %u at frame %u\n",
                    frame.bone_count, i);
            break;
        }

        // Bone data follows the 16-byte header. 12 floats per bone.
        const size_t needed = frame.bone_count * 12 * sizeof(float);
        if (fofs + 16 + needed > buf.size()) break;

        frame.bone_data.resize(frame.bone_count * 12);
        memcpy(frame.bone_data.data(), buf.data() + fofs + 16, needed);
        out.frames.push_back(std::move(frame));
    }

    if (frame_table_end != 0 && frame_table_end < buf.size()) {
        uint32_t sentinel = *At<uint32_t>(buf, frame_table_end);
        if (sentinel != 0xFFFFFFFFu) {
            fprintf(stderr, "ANM(single): missing 0xFFFFFFFF sentinel at 0x%X (got 0x%X)\n",
                    frame_table_end, sentinel);
        }
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

} // namespace bw
