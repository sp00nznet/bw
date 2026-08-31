// test_saveload — exercise the recovered object save format end to end.
//
// The field tables are generated from the binary, so what needs checking is
// the machinery around them: that the chain walker replays a class's ancestry
// in the right order, that save and load are exact mirrors, and that the
// pointer ordinal table turns an object graph into a stream and back --
// including a shared object that must come back as the *same* pointer, not a
// second copy.
//
// The test drives whatever types the generated table says are fully recovered,
// so it keeps testing the real data as the extraction improves.

#include <black/GameOSFile.h>
#include <black/GameThing.h>
#include <black/SaveLoad.h>
#include <black/SaveLoadTable.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

static int g_fail = 0;
#define CHECK(cond, msg) do { if (!(cond)) { printf("FAIL: %s\n", msg); ++g_fail; } \
                              else printf("ok  : %s\n", msg); } while (0)

// A stand-in object big enough for any class's field offsets. GetSaveType
// reads a global rather than a member so no member can collide with a field
// offset the walker writes into.
static uint32_t g_test_type = 0;

struct TestThing : GameThing {
    uint8_t blob[0x1000];
    uint32_t GetSaveType() override { return g_test_type; }
};

static std::vector<TestThing*> g_built;

static GameThing* TestFactory(uint32_t /*save_type*/) {
    TestThing* t = new TestThing();
    std::memset(static_cast<void*>(t->blob), 0, sizeof(t->blob));
    g_built.push_back(t);
    return t;
}

// Every field the chain for `save_type` touches, root-first -- the same order
// the walker uses, so we can check each one after a round trip.
static void ChainFields(uint32_t save_type, std::vector<saveload::Field>& out,
                        bool& has_hook) {
    using namespace saveload;
    std::vector<int> chain;
    for (int row = RowForSaveType(save_type); row >= 0; row = kClasses[row].parent)
        chain.push_back(row);
    has_hook = false;
    for (size_t i = chain.size(); i-- > 0;) {
        const ClassDesc& c = kClasses[chain[i]];
        if (c.hook != HOOK_NONE) has_hook = true;
        for (uint16_t k = 0; k < c.count; ++k) out.push_back(kFields[c.first + k]);
    }
}

// A type whose whole chain was recovered exactly, with enough plain fields to
// be worth comparing and at least one object pointer to exercise the graph.
static bool PickType(uint32_t& type, bool want_ptr) {
    using namespace saveload;
    for (uint16_t i = 0; i < kSaveTypeCount; ++i) {
        uint32_t t = kSaveTypes[i].id;
        if (!t || !IsSerializable(t)) continue;
        std::vector<Field> f;
        bool hook = false;
        ChainFields(t, f, hook);
        if (hook) continue;                 // keep the pick to pure field lists
        size_t raws = 0, ptrs = 0, maxoff = 0;
        for (const Field& x : f) {
            if (x.op == OP_RAW) ++raws;
            if (x.op == OP_PTR) ++ptrs;
            size_t end = x.off + (x.op == OP_RAW ? x.n : 4u);
            if (end > maxoff) maxoff = end;
        }
        if (raws < 4 || maxoff > 0x1000) continue;
        if (want_ptr && ptrs == 0) continue;
        type = t;
        return true;
    }
    return false;
}

static void FillRawFields(uint8_t* obj, const std::vector<saveload::Field>& fields,
                          unsigned seed) {
    for (const saveload::Field& f : fields) {
        if (f.op != saveload::OP_RAW) continue;
        for (uint16_t i = 0; i < f.n; ++i) {
            seed = seed * 1664525u + 1013904223u;
            obj[f.off + i] = static_cast<uint8_t>(seed >> 24);
        }
    }
}

static bool RawFieldsMatch(const uint8_t* a, const uint8_t* b,
                           const std::vector<saveload::Field>& fields,
                           uint16_t* bad_off) {
    for (const saveload::Field& f : fields) {
        if (f.op != saveload::OP_RAW) continue;
        if (std::memcmp(a + f.off, b + f.off, f.n) != 0) {
            *bad_off = f.off;
            return false;
        }
    }
    return true;
}

int main() {
    using namespace saveload;
    const char* path = "test_saveload.tmp";

    // --- table sanity -----------------------------------------------------
    CHECK(kClassCount > 100, "class table populated");
    CHECK(kSaveTypeCount > 100, "save-type table populated");

    bool sorted = true, resolves = true;
    for (uint16_t i = 0; i < kSaveTypeCount; ++i) {
        if (i && kSaveTypes[i - 1].id >= kSaveTypes[i].id) sorted = false;
        if (RowForSaveType(kSaveTypes[i].id) != kSaveTypes[i].cls) resolves = false;
    }
    CHECK(sorted, "save-type ids are ascending (binary search precondition)");
    CHECK(resolves, "every save-type id resolves back to its own row");
    CHECK(RowForSaveType(99999) < 0, "unknown save-type id is rejected");

    // Known ids read straight off the binary's vtable slot 60.
    CHECK(NameForSaveType(79) && !std::strcmp(NameForSaveType(79), "Tree"), "id 79 is Tree");
    CHECK(NameForSaveType(111) && !std::strcmp(NameForSaveType(111), "Rock"), "id 111 is Rock");
    CHECK(NameForSaveType(7) && !std::strcmp(NameForSaveType(7), "Abode"), "id 7 is Abode");

    // Every chain must terminate; a cycle would hang the walker.
    bool terminates = true;
    for (uint16_t i = 0; i < kClassCount; ++i) {
        int steps = 0;
        for (int row = i; row >= 0; row = kClasses[row].parent)
            if (++steps > 32) { terminates = false; break; }
    }
    CHECK(terminates, "no class chain loops");

    // Field offsets must be inside a plausible object and never zero-length.
    bool sane = true;
    for (uint16_t i = 0; i < kClassCount; ++i) {
        const ClassDesc& c = kClasses[i];
        for (uint16_t k = 0; k < c.count; ++k) {
            const Field& f = kFields[c.first + k];
            if (f.op == OP_CHECKSUM) continue;
            if (f.n == 0 || f.off > 0x20000) sane = false;
        }
    }
    CHECK(sane, "every field has a non-zero size and a plausible offset");

    saveload::SetObjectFactory(TestFactory);

    // --- field round trip -------------------------------------------------
    uint32_t type = 0;
    if (!PickType(type, /*want_ptr=*/false)) {
        printf("FAIL: no fully-recovered type to round trip\n");
        return 1;
    }
    std::vector<Field> fields;
    bool hook = false;
    ChainFields(type, fields, hook);
    printf("      round-tripping save-type %u (%s), %zu field ops\n",
           type, NameForSaveType(type), fields.size());
    g_test_type = type;

    TestThing src;
    std::memset(static_cast<void*>(src.blob), 0, sizeof(src.blob));
    FillRawFields(reinterpret_cast<uint8_t*>(&src), fields, 0x1234u);

    uint32_t write_sum = 0;
    {
        GameOSFile f{};
        CHECK(f.Open(path, true), "open for write");
        CHECK(src.Save(&f) == 1, "Save walks the chain and reports success");
        CHECK(!f.Failed(), "stream did not fail during save");
        write_sum = f.GetChecksum();
        f.Close();
    }

    {
        GameOSFile f{};
        CHECK(f.Open(path, false), "open for read");
        uint32_t rtype = 0, extra = 0;
        CHECK(f.Read(&rtype, 4), "read save-type id");
        CHECK(rtype == type, "save-type id round trips");
        CHECK(f.Read(&extra, 4), "read the SaveExtraData word");
        TestThing dst;
        std::memset(static_cast<void*>(dst.blob), 0, sizeof(dst.blob));
        CHECK(dst.Load(&f) == 1, "Load walks the same chain");
        CHECK(!f.Failed(), "stream did not fail during load");
        uint16_t bad = 0;
        CHECK(RawFieldsMatch(reinterpret_cast<const uint8_t*>(&src),
                             reinterpret_cast<const uint8_t*>(&dst), fields, &bad),
              "every raw field round trips byte for byte");
        CHECK(f.GetChecksum() == write_sum, "read checksum equals write checksum");
        f.Close();
    }

    // --- object graph -----------------------------------------------------
    // Two objects both pointing at a third: the shared one must be written
    // once and come back as one pointer, not two copies.
    if (PickType(type, /*want_ptr=*/true)) {
        fields.clear();
        ChainFields(type, fields, hook);
        g_test_type = type;
        uint16_t ptr_off = 0;
        for (const Field& f : fields)
            if (f.op == OP_PTR) { ptr_off = f.off; break; }
        printf("      graph test with save-type %u (%s), pointer at 0x%X\n",
               type, NameForSaveType(type), ptr_off);

        TestThing a, b, shared;
        for (TestThing* t : {&a, &b, &shared})
            std::memset(static_cast<void*>(t->blob), 0, sizeof(t->blob));
        *reinterpret_cast<GameThing**>(reinterpret_cast<uint8_t*>(&a) + ptr_off) = &shared;
        *reinterpret_cast<GameThing**>(reinterpret_cast<uint8_t*>(&b) + ptr_off) = &shared;

        {
            GameOSFile f{};
            CHECK(f.Open(path, true), "graph: open for write");
            f.SavePtr(&a);
            f.SavePtr(&b);
            f.SavePtr(&shared);   // third mention: must be a back-reference
            CHECK(!f.Failed(), "graph: save completed");
            f.Close();
        }

        g_built.clear();
        {
            GameOSFile f{};
            CHECK(f.Open(path, false), "graph: open for read");
            GameThing* ra = nullptr;
            GameThing* rb = nullptr;
            GameThing* rs = nullptr;
            f.LoadPtr(&ra);
            f.LoadPtr(&rb);
            f.LoadPtr(&rs);
            CHECK(!f.Failed(), "graph: load completed");
            CHECK(ra && rb && rs, "graph: all three pointers resolved");
            CHECK(g_built.size() == 3, "graph: shared object built exactly once");
            if (ra && rb) {
                GameThing* pa = *reinterpret_cast<GameThing**>(
                    reinterpret_cast<uint8_t*>(ra) + ptr_off);
                GameThing* pb = *reinterpret_cast<GameThing**>(
                    reinterpret_cast<uint8_t*>(rb) + ptr_off);
                CHECK(pa == pb && pa == rs,
                      "graph: both objects point at the same restored object");
            }
            f.Close();
        }
        for (TestThing* t : g_built) delete t;
        g_built.clear();
    } else {
        printf("FAIL: no fully-recovered type with an object pointer\n");
        ++g_fail;
    }

    // --- refusal ----------------------------------------------------------
    // A type whose chain was not fully recovered must be refused, not written
    // out half-right: a stream that silently disagrees with the original is
    // worse than no stream.
    uint32_t partial = 0;
    for (uint16_t i = 0; i < kSaveTypeCount && !partial; ++i)
        if (kSaveTypes[i].id && !IsSerializable(kSaveTypes[i].id))
            partial = kSaveTypes[i].id;
    if (partial) {
        GameOSFile f{};
        f.Open(path, true);
        TestThing t;
        std::memset(static_cast<void*>(t.blob), 0, sizeof(t.blob));
        CHECK(!saveload::SaveFields(f, &t, partial),
              "a partially-recovered type is refused rather than half-written");
        f.Close();
    }

    std::remove(path);
    printf(g_fail ? "\n%d FAILURE(S)\n" : "\nALL PASS\n", g_fail);
    return g_fail ? 1 : 0;
}
