// sad_loader — see sad_loader.h.

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

#include "sad_loader.h"

#include <cstdio>
#include <cstring>
#include <string>
#include <unordered_map>
#include <vector>

namespace bw {
namespace sad {

namespace {

std::vector<SADSample>                       g_samples;
std::unordered_map<int32_t, uint32_t>        g_by_id;        // id → index
std::unordered_map<std::string, uint32_t>    g_by_help_key;  // KEY → index

// --- Shared PackFile parser (mirrors anm_loader.cpp's local helper) -------

struct PackBlock {
    std::string          name;
    const uint8_t*       data;
    size_t               size;
};

bool ParsePackBlocks(const std::vector<uint8_t>& buf, std::vector<PackBlock>& out) {
    static constexpr char kFileMagic[8] = { 'L','i','O','n','H','e','A','d' };
    if (buf.size() < 8 || memcmp(buf.data(), kFileMagic, 8) != 0) return false;

    size_t pos = 8;
    while (pos + 0x24 <= buf.size()) {
        char name[33] = {};
        memcpy(name, buf.data() + pos, 32);
        uint32_t size = *reinterpret_cast<const uint32_t*>(buf.data() + pos + 32);
        size_t body_start = pos + 0x24;
        if (body_start + size > buf.size()) break;
        PackBlock blk;
        blk.name = name;
        blk.data = buf.data() + body_start;
        blk.size = size;
        out.push_back(std::move(blk));
        pos = body_start + size;
    }
    return !out.empty();
}

const PackBlock* FindBlock(const std::vector<PackBlock>& blocks, const char* name) {
    for (const auto& b : blocks) if (b.name == name) return &b;
    return nullptr;
}

std::vector<uint8_t> SlurpFile(const std::string& path) {
    std::vector<uint8_t> buf;
    FILE* f = fopen(path.c_str(), "rb");
    if (!f) return buf;
    fseek(f, 0, SEEK_END);
    long sz = ftell(f);
    fseek(f, 0, SEEK_SET);
    if (sz > 0) {
        buf.resize(sz);
        fread(buf.data(), 1, buf.size(), f);
    }
    fclose(f);
    return buf;
}

// Extract the HELP_TEXT_<NAME>_<NN> key from a sample's name. The full
// name looks like "C:\Dialogue\Guidance\1622mp2\HELP_TEXT_<KEY>.wav".
// We return only the <KEY> portion (without the trailing _NN trailer)
// so per-line variants collapse to one subtitle.
std::string ExtractHelpKey(const std::string& full_name) {
    // Strip directory and extension.
    size_t slash = full_name.find_last_of("/\\");
    std::string base = slash == std::string::npos ? full_name : full_name.substr(slash + 1);
    size_t dot = base.find_last_of('.');
    if (dot != std::string::npos) base.resize(dot);

    if (base.compare(0, 10, "HELP_TEXT_") != 0) return {};
    std::string key = base.substr(10);   // drop HELP_TEXT_ prefix

    // Drop trailing _NN[N] variant suffix.
    size_t under = key.find_last_of('_');
    if (under != std::string::npos && under > 0 && under + 1 < key.size()) {
        bool all_digits = true;
        for (size_t i = under + 1; i < key.size(); ++i) {
            if (key[i] < '0' || key[i] > '9') { all_digits = false; break; }
        }
        if (all_digits) key.resize(under);
    }
    return key;
}

bool LooksLikePCM(const uint8_t* riff, size_t size) {
    if (size < 24) return false;
    if (memcmp(riff, "RIFF", 4) != 0) return false;
    if (memcmp(riff + 8, "WAVE", 4) != 0) return false;
    if (memcmp(riff + 12, "fmt ", 4) != 0) return false;
    uint16_t fmt = *reinterpret_cast<const uint16_t*>(riff + 20);
    return fmt == 1 /* WAVE_FORMAT_PCM */;
}

} // namespace

size_t LoadSAD(const std::string& path) {
    auto buf = SlurpFile(path);
    if (buf.empty()) return 0;

    std::vector<PackBlock> blocks;
    if (!ParsePackBlocks(buf, blocks)) return 0;

    const PackBlock* wave   = FindBlock(blocks, "LHAudioWaveData");
    const PackBlock* sample = FindBlock(blocks, "LHAudioBankSampleTable");
    if (!wave || !sample || sample->size < 4) return 0;

    uint32_t count = *reinterpret_cast<const uint32_t*>(sample->data);
    if (count == 0) return 0;
    constexpr size_t HDR_SIZE = 640;
    if (4 + count * HDR_SIZE > sample->size) return 0;

    // Layout offsets confirmed against openblack's AudioBankSampleHeader.
    constexpr size_t kNameOff   = 0x000;
    constexpr size_t kIdOff     = 0x104;
    constexpr size_t kSizeOff   = 0x10C;
    constexpr size_t kOffsetOff = 0x110;
    constexpr size_t kSampleRateOff = 0x128;

    size_t added = 0;
    const uint8_t* hdr0 = sample->data + 4;

    for (uint32_t i = 0; i < count; ++i) {
        const uint8_t* h = hdr0 + i * HDR_SIZE;

        char name_buf[257] = {};
        memcpy(name_buf, h + kNameOff, 256);
        std::string name = name_buf;
        if (name.empty()) continue;

        int32_t  id          = *reinterpret_cast<const int32_t*>(h + kIdOff);
        uint32_t wav_size    = *reinterpret_cast<const uint32_t*>(h + kSizeOff);
        uint32_t wav_offset  = *reinterpret_cast<const uint32_t*>(h + kOffsetOff);
        uint32_t sample_rate = *reinterpret_cast<const uint32_t*>(h + kSampleRateOff);

        if (wav_offset >= wave->size || wav_size == 0 ||
            wav_offset + wav_size > wave->size) continue;

        SADSample s;
        s.id       = id;
        s.name     = std::move(name);
        s.help_key = ExtractHelpKey(s.name);
        s.wav_bytes.assign(wave->data + wav_offset,
                           wave->data + wav_offset + wav_size);
        s.sample_rate = sample_rate;
        s.is_pcm      = LooksLikePCM(s.wav_bytes.data(), s.wav_bytes.size());

        uint32_t idx = static_cast<uint32_t>(g_samples.size());
        // First-load-wins for both indices so subsequent SAD files
        // don't clobber existing samples.
        if (g_by_id.find(id) == g_by_id.end()) {
            g_by_id[id] = idx;
        }
        if (!s.help_key.empty() &&
            g_by_help_key.find(s.help_key) == g_by_help_key.end()) {
            g_by_help_key[s.help_key] = idx;
        }
        g_samples.push_back(std::move(s));
        added++;
    }

    printf("SAD: %s — %u samples extracted (total %zu)\n",
           path.c_str(), count, g_samples.size());
    fflush(stdout);
    return added;
}

const SADSample* SampleById(int32_t id) {
    auto it = g_by_id.find(id);
    if (it == g_by_id.end()) return nullptr;
    return &g_samples[it->second];
}

const SADSample* SampleByIndex(uint32_t idx) {
    if (idx >= g_samples.size()) return nullptr;
    return &g_samples[idx];
}

const SADSample* SampleByHelpKey(const std::string& key) {
    auto it = g_by_help_key.find(key);
    if (it == g_by_help_key.end()) return nullptr;
    return &g_samples[it->second];
}

size_t Count() { return g_samples.size(); }

bool Play(int32_t id) {
    const SADSample* s = SampleById(id);
    if (!s || !s->is_pcm || s->wav_bytes.empty()) return false;
    return PlaySoundA(reinterpret_cast<LPCSTR>(s->wav_bytes.data()),
                      nullptr,
                      SND_MEMORY | SND_ASYNC | SND_NODEFAULT) ? true : false;
}

// Walk every .sad below `root_dir` (recursive) and load it.
size_t LoadAllUnder(const std::string& root_dir) {
    size_t before = g_samples.size();
    std::vector<std::string> stack = { root_dir };

    while (!stack.empty()) {
        std::string dir = std::move(stack.back());
        stack.pop_back();

        std::string pattern = dir;
        if (!pattern.empty() && pattern.back() != '/' && pattern.back() != '\\')
            pattern += '\\';
        pattern += '*';

        WIN32_FIND_DATAA fd;
        HANDLE h = FindFirstFileA(pattern.c_str(), &fd);
        if (h == INVALID_HANDLE_VALUE) continue;
        do {
            std::string name = fd.cFileName;
            if (name == "." || name == "..") continue;
            std::string full = dir;
            if (!full.empty() && full.back() != '/' && full.back() != '\\')
                full += '\\';
            full += name;
            if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                stack.push_back(full);
            } else {
                size_t n = name.size();
                if (n > 4 &&
                    (name.compare(n - 4, 4, ".sad") == 0 ||
                     name.compare(n - 4, 4, ".SAD") == 0)) {
                    LoadSAD(full);
                }
            }
        } while (FindNextFileA(h, &fd));
        FindClose(h);
    }

    size_t added = g_samples.size() - before;
    printf("SAD: %s scan complete — %zu new samples (total %zu)\n",
           root_dir.c_str(), added, g_samples.size());
    fflush(stdout);
    return added;
}

} // namespace sad
} // namespace bw
