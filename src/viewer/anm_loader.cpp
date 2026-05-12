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

} // namespace bw
