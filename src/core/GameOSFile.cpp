// GameOSFile — native BW save-file serializer (Phase 7 foundation).
//
// Translated from runblack_decrypted.exe (v1.0) via the tools/decomp pipeline.
// The original wraps an OS file handle (LHReleasedOSFile) and routes every
// field through a Write/Read primitive (sub_72BE90 and its read twin) that
// also folds the buffer into a running checksum at offset 0x214. The exact
// byte order + checksum rule are what matter for compatibility with retail
// .sav files, so we reproduce those with portable C I/O instead of the
// original's opaque OS layer.
//
// Checksum rule (from GameThing::Save sub_53E8E0 / SaveExtraData sub_53EA90):
//   after each Write/Read of `size` bytes from `buf`,
//       checksum += buf[0] + size;

#include "black/GameOSFile.h"

#include <cstdio>
#include <cstring>

namespace {
// Stash a FILE* in the 8-byte LHReleasedOSFile handle that sits at offset 0.
inline FILE*&  HandleOf(GameOSFile* f) { return *reinterpret_cast<FILE**>(&f->super); }
inline FILE*   HandleOf(const GameOSFile* f) {
    return *reinterpret_cast<FILE* const*>(&f->super);
}
}  // namespace

bool GameOSFile::Open(const char* path, bool writing) {
    Close();
    FILE* fp = std::fopen(path, writing ? "wb" : "rb");
    HandleOf(this) = fp;
    if (!fp) return false;
    checksum = 0;
    std::memset(filename, 0, sizeof(filename));
    if (path) {
        std::strncpy(filename, path, sizeof(filename) - 1);
    }
    return true;
}

void GameOSFile::Close() {
    FILE*& fp = HandleOf(this);
    if (fp) { std::fclose(fp); fp = nullptr; }
}

bool GameOSFile::IsOpen() const { return HandleOf(this) != nullptr; }

bool GameOSFile::Write(const void* buf, uint32_t size) {
    FILE* fp = HandleOf(this);
    if (!fp || (size && !buf)) return false;
    if (size && std::fwrite(buf, 1, size, fp) != size) return false;
    checksum += static_cast<uint32_t>(size ? *static_cast<const uint8_t*>(buf) : 0) + size;
    return true;
}

bool GameOSFile::Read(void* buf, uint32_t size) {
    FILE* fp = HandleOf(this);
    if (!fp || (size && !buf)) return false;
    if (size && std::fread(buf, 1, size, fp) != size) return false;
    checksum += static_cast<uint32_t>(size ? *static_cast<const uint8_t*>(buf) : 0) + size;
    return true;
}
