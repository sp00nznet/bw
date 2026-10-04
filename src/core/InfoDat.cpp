// InfoDat — info.dat loader. Layout and reasoning: docs/info-dat.md.
#include <black/InfoDat.h>
#include <black/GBaseInfo.h>

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <vector>

namespace infodat {
namespace {

constexpr char     kMagic[] = "LiOnHeAdInfo";
constexpr uint32_t kHeaderBytes = 0x2C;   // magic block, payload size at 0x28
constexpr uint32_t kSizeOffset  = 0x28;

std::vector<uint8_t> g_sections[SECTION_COUNT];
bool g_loaded = false;

bool Fail(std::string* err, const std::string& msg) {
    if (err) *err = msg;
    Unload();
    return false;
}

} // namespace

bool LoadFromMemory(const uint8_t* data, size_t size, std::string* err) {
    Unload();
    if (size < kHeaderBytes || std::memcmp(data, kMagic, sizeof(kMagic) - 1) != 0)
        return Fail(err, "not an info.dat (bad magic)");
    uint32_t payload;
    std::memcpy(&payload, data + kSizeOffset, 4);
    if (payload != kPayloadBytes || size != kHeaderBytes + payload)
        return Fail(err, "info.dat payload is " + std::to_string(payload) + " bytes in a " +
                         std::to_string(size) + "-byte file; this build's layout expects " +
                         std::to_string(kPayloadBytes) + " (v1.0). Wrong game version?");

    // The original links every info into one list (GBaseInfo::next) and numbers
    // them in load order (GBaseInfo::index) — sub_4304A0.
    GBaseInfo* prev = nullptr;
    int32_t index = 0;
    const uint8_t* p = data + kHeaderBytes;
    for (int s = 0; s < SECTION_COUNT; ++s) {
        const SectionLayout& L = kLayout[s];
        g_sections[s].assign(size_t(L.stride) * L.count, 0);
        for (uint32_t i = 0; i < L.count; ++i) {
            uint8_t* e = g_sections[s].data() + size_t(i) * L.stride;
            std::memcpy(e + sizeof(GBaseInfo), p, L.record_bytes);
            p += L.record_bytes;
            GBaseInfo* h = reinterpret_cast<GBaseInfo*>(e);
            h->next = prev;
            h->index = index++;
            prev = h;
        }
    }
    g_loaded = true;
    return true;
}

bool Load(const char* path, std::string* err) {
    FILE* f = std::fopen(path, "rb");
    if (!f) return Fail(err, std::string("cannot open ") + path);
    std::vector<uint8_t> buf;
    uint8_t chunk[65536];
    size_t n;
    while ((n = std::fread(chunk, 1, sizeof(chunk), f)) > 0) buf.insert(buf.end(), chunk, chunk + n);
    std::fclose(f);
    return LoadFromMemory(buf.data(), buf.size(), err);
}

bool Loaded() { return g_loaded; }

void Unload() {
    for (auto& v : g_sections) std::vector<uint8_t>().swap(v);
    g_loaded = false;
}

uint32_t Count(Section s) { return g_loaded && s < SECTION_COUNT ? kLayout[s].count : 0; }

const void* Element(Section s, uint32_t i) {
    if (!g_loaded || s >= SECTION_COUNT || i >= kLayout[s].count) return nullptr;
    return g_sections[s].data() + size_t(i) * kLayout[s].stride;
}

const char* DebugName(Section s, uint32_t i) {
    const uint8_t* e = static_cast<const uint8_t*>(Element(s, i));
    if (!e || kLayout[s].record_bytes < 240) return "";
    const char* name = reinterpret_cast<const char*>(e + 24);
    return std::memchr(name, 0, 48) ? name : "";
}

int FindByName(Section s, const char* script_name) {
    const size_t n = std::strlen(script_name);
    for (uint32_t i = 0; i < Count(s); ++i) {
        std::string name = DebugName(s, i);
        for (char& c : name) c = c == ' ' ? '_' : char(std::toupper(uint8_t(c)));
        if (name.size() < n || !std::equal(script_name, script_name + n, name.begin(),
                [](char a, char b) { return (a == ' ' ? '_' : std::toupper(uint8_t(a))) == b; }))
            continue;
        const std::string rest = name.substr(n);
        if (rest.empty() || rest == "_MALE" || rest == "_FEMALE") return int(i);
    }
    return -1;
}

int FindAbode(const char* script_name) {
    // TRIBE_TYPE order; the data agrees (Celtic Hut tribe 0, Norse Hut tribe 7).
    static const char* const kTribes[] = {"CELTIC", "AFRICAN", "AZTEC", "JAPANESE", "INDIAN",
                                          "EGYPTIAN", "GREEK", "NORSE", "TIBETAN"};
    constexpr uint32_t kTribeAt = 0x158, kTagAt = 0x128;  // element offsets in GAbodeInfo
    for (int32_t t = 0; t < 9; ++t) {
        const size_t len = std::strlen(kTribes[t]);
        if (std::strncmp(script_name, kTribes[t], len) != 0 || script_name[len] != '_') continue;
        const char* tag = script_name + len + 1;
        for (uint32_t i = 0; i < Count(DETAIL_ABODE_INFO); ++i) {
            const uint8_t* e = static_cast<const uint8_t*>(Element(DETAIL_ABODE_INFO, i));
            int32_t tribe;
            std::memcpy(&tribe, e + kTribeAt, 4);
            if (tribe == t && std::strncmp(reinterpret_cast<const char*>(e + kTagAt), tag, 32) == 0)
                return int(i);
        }
    }
    return -1;
}

} // namespace infodat
