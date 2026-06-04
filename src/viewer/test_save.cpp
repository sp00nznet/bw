// test_save — verify GameOSFile serialization primitives (Phase 7 keystone).
//
// Writes a few buffers, records the running checksum, then reads them back from
// the same file and confirms the bytes roundtrip and the read-side checksum
// matches the write-side — i.e. the on-disk format + checksum rule are
// self-consistent (the property real save/load relies on).

#include <black/GameOSFile.h>

#include <cstdio>
#include <cstring>
#include <cstdint>

static int g_fail = 0;
#define CHECK(cond, msg) do { if (!(cond)) { printf("FAIL: %s\n", msg); ++g_fail; } \
                              else printf("ok  : %s\n", msg); } while (0)

int main() {
    const char* path = "test_save.tmp";

    // --- write side -------------------------------------------------------
    uint32_t type = 0x4F;          // e.g. Tree save-type
    uint32_t field4 = 0x12345678;
    uint8_t  field_a = 0xA5;
    uint32_t wsum = 0;
    {
        GameOSFile f{};
        CHECK(f.Open(path, /*writing=*/true), "open for write");
        CHECK(f.Write(&type, 4), "write type");
        CHECK(f.Write(&field4, 4), "write field4");
        CHECK(f.Write(&field_a, 1), "write field_a");
        wsum = f.GetChecksum();
        f.Close();
        CHECK(!f.IsOpen(), "closed after write");
    }

    // Expected checksum: sum over writes of (firstByte + size).
    uint32_t expect = (0x4Fu + 4u) + (0x78u + 4u) + (0xA5u + 1u);
    CHECK(wsum == expect, "write checksum matches the firstByte+size rule");

    // --- read side --------------------------------------------------------
    {
        GameOSFile f{};
        CHECK(f.Open(path, /*writing=*/false), "open for read");
        uint32_t rtype = 0, rfield4 = 0;
        uint8_t  rfield_a = 0;
        CHECK(f.Read(&rtype, 4), "read type");
        CHECK(f.Read(&rfield4, 4), "read field4");
        CHECK(f.Read(&rfield_a, 1), "read field_a");
        CHECK(rtype == type, "type roundtrips");
        CHECK(rfield4 == field4, "field4 roundtrips");
        CHECK(rfield_a == field_a, "field_a roundtrips");
        CHECK(f.GetChecksum() == wsum, "read checksum equals write checksum");
        f.Close();
    }

    std::remove(path);
    printf(g_fail ? "\n%d FAILURE(S)\n" : "\nALL PASS\n", g_fail);
    return g_fail ? 1 : 0;
}
