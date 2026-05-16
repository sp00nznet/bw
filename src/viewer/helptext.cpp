// helptext — see helptext.h.
//
// Status: infrastructure is wired end-to-end (LoadFromDLL → Lookup →
// subtitle path), but the BW text source is harder to reach than first
// expected. Key findings:
//
//   * LanguageR.dll / LanguageD.dll have NO standard Win32 string
//     resources — RT_STRING is empty, EnumResourceTypes returns 0.
//   * The DLLs export an Initialise/LookIn C-API, but it (a) depends
//     on LHMultiplayerD.dll → LHLogR.dll → ... a chain that's brittle
//     to set up at runtime and (b) requires undocumented external
//     state (probably a path or buffer) before LookIn becomes safe to
//     call — direct invocation crashes with EXCEPTION_ACCESS_VIOLATION.
//   * The actual user-facing dialogue text is most likely stored in
//     the per-sample `description` field of the SAD audio banks (256
//     chars per AudioBankSampleHeader, paired 1:1 with voice clips).
//     That's the next data source to wire — when the SAD decoder lands
//     it can populate the same g_strings map via LoadFromSAD().
//
// For now the loader scans the DLL's .rdata/.data sections for any
// printable C-strings as a placeholder. Most hits will be import-table
// names rather than BW dialogue, but the path is exercised end-to-end
// so the Lookup→Subtitle wiring stays under test.

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

#include "helptext.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <unordered_map>
#include <vector>

namespace bw {
namespace helptext {

namespace {

std::unordered_map<int32_t, std::string> g_strings;

// Decide whether a NUL-terminated run found in the binary looks like a
// BW string. Most are pure ASCII English with letters; the filter
// rejects pointer-tables, compiler stubs, and random binary runs.
bool IsBWString(const char* s, size_t len) {
    if (len < 2 || len > 4096) return false;
    int printable = 0;
    int letters   = 0;
    for (size_t i = 0; i < len; ++i) {
        unsigned char c = static_cast<unsigned char>(s[i]);
        if (c == '\r' || c == '\n' || c == '\t') { printable++; continue; }
        if (c < 0x20 || c >= 0x7F) return false;
        printable++;
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) letters++;
    }
    if (printable != static_cast<int>(len)) return false;
    // Need a real letter-density to avoid picking up numeric tokens.
    return letters * 3 >= static_cast<int>(len);
}

size_t ExtractFromPE(const std::string& dll_path) {
    FILE* f = fopen(dll_path.c_str(), "rb");
    if (!f) {
        printf("HelpText: cannot open %s\n", dll_path.c_str());
        return 0;
    }
    fseek(f, 0, SEEK_END);
    long sz = ftell(f);
    fseek(f, 0, SEEK_SET);
    if (sz < 0x200) { fclose(f); return 0; }
    std::vector<uint8_t> buf(static_cast<size_t>(sz));
    fread(buf.data(), 1, buf.size(), f);
    fclose(f);

    auto* dos = reinterpret_cast<const IMAGE_DOS_HEADER*>(buf.data());
    if (dos->e_magic != IMAGE_DOS_SIGNATURE) return 0;
    size_t nt_off = static_cast<size_t>(dos->e_lfanew);
    if (nt_off + sizeof(IMAGE_NT_HEADERS32) > buf.size()) return 0;
    auto* nt = reinterpret_cast<const IMAGE_NT_HEADERS32*>(buf.data() + nt_off);
    if (nt->Signature != IMAGE_NT_SIGNATURE) return 0;

    const auto& fh = nt->FileHeader;
    size_t sec_off = nt_off + offsetof(IMAGE_NT_HEADERS32, OptionalHeader)
                            + fh.SizeOfOptionalHeader;
    if (sec_off + fh.NumberOfSections * sizeof(IMAGE_SECTION_HEADER) > buf.size()) return 0;
    auto* secs = reinterpret_cast<const IMAGE_SECTION_HEADER*>(buf.data() + sec_off);

    std::vector<std::string> ordered;
    auto scan_section = [&](const IMAGE_SECTION_HEADER& s) {
        size_t off = s.PointerToRawData;
        size_t len = s.SizeOfRawData;
        if (off >= buf.size()) return;
        if (off + len > buf.size()) len = buf.size() - off;

        size_t i = 0;
        while (i < len) {
            size_t start = i;
            while (i < len && buf[off + i] != 0) i++;
            size_t run = i - start;
            if (run >= 2) {
                const char* p = reinterpret_cast<const char*>(buf.data() + off + start);
                if (IsBWString(p, run)) {
                    std::string text(p, run);
                    while (!text.empty() && (text.back() == ' ' || text.back() == '\r' ||
                                             text.back() == '\n' || text.back() == '\t')) {
                        text.pop_back();
                    }
                    if (!text.empty()) ordered.push_back(std::move(text));
                }
            }
            while (i < len && buf[off + i] == 0) i++;
        }
    };

    // .rdata first (BW's read-only string literals usually live there).
    for (uint16_t i = 0; i < fh.NumberOfSections; ++i) {
        if (memcmp(secs[i].Name, ".rdata", 6) == 0) scan_section(secs[i]);
    }
    // .data picks up anything held in writable globals.
    for (uint16_t i = 0; i < fh.NumberOfSections; ++i) {
        if (memcmp(secs[i].Name, ".data", 5) == 0) scan_section(secs[i]);
    }

    size_t before = g_strings.size();
    for (size_t i = 0; i < ordered.size(); ++i) {
        int32_t id = static_cast<int32_t>(i) + 1;   // 1-based
        if (g_strings.find(id) == g_strings.end()) {
            g_strings[id] = std::move(ordered[i]);
        }
    }
    return g_strings.size() - before;
}

} // namespace

size_t LoadFromDLL(const std::string& dll_path) {
    size_t added = ExtractFromPE(dll_path);
    printf("HelpText: %s — %zu strings extracted (total %zu)\n",
           dll_path.c_str(), added, g_strings.size());
    fflush(stdout);
    return added;
}

const char* Lookup(int32_t id) {
    auto it = g_strings.find(id);
    if (it == g_strings.end()) return "";
    return it->second.c_str();
}

size_t Count() { return g_strings.size(); }

void Add(int32_t id, const std::string& text) {
    if (text.empty()) return;
    if (g_strings.find(id) == g_strings.end()) g_strings[id] = text;
}

} // namespace helptext
} // namespace bw
