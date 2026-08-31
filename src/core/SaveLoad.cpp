// SaveLoad — chain walker + object graph for BW's native save format.
//
// Translated from runblack_decrypted.exe (v1.0). The per-class field lists
// live in SaveLoadTable.gen.cpp (extracted from vtable slots 58/59); this file
// is the machinery they drive:
//
//   * the sticky failure flag every primitive short-circuits on
//     (dword_B19AC8 on the save side, dword_B19ACC on the load side),
//   * the checksum marker GameThing writes per object (sub_533C50/sub_533C90),
//   * the pointer ordinal table (sub_531BC0/sub_531F30), which is what makes
//     the format an object graph rather than a flat dump,
//   * the three class rows whose bodies branch instead of running a flat list.

#include "black/SaveLoad.h"

#include "black/GameOSFile.h"
#include "black/GameThing.h"
#include "black/SaveLoadTable.h"

#include <cstring>
#include <vector>

namespace {

// Per-file serialization state. The original keeps the ordinal list in the
// GSaveLoadPtr list at offset 0x220 and the failure flag in a global; we keep
// both here and stash the pointer in GameOSFile's unused field_0x8 block so
// the struct keeps its 0x230 layout.
struct SaveState {
    std::vector<GameThing*> ordinals;  // index 0 == ordinal 1
    bool failed = false;
};

SaveState*& StateSlot(GameOSFile* f) {
    return *reinterpret_cast<SaveState**>(f->field_0x8);
}

SaveState& StateOf(GameOSFile* f) {
    SaveState*& s = StateSlot(f);
    if (!s) s = new SaveState();
    return *s;
}

saveload::ObjectFactory g_factory = nullptr;
saveload::InfoToIndex   g_info_to_index = nullptr;
saveload::IndexToInfo   g_index_to_info = nullptr;

}  // namespace

// ---------------------------------------------------------------------------
// GameOSFile serialization primitives
// ---------------------------------------------------------------------------

bool GameOSFile::Failed() const {
    SaveState* s = *reinterpret_cast<SaveState* const*>(field_0x8);
    return s ? s->failed : false;
}

void GameOSFile::Fail() { StateOf(this).failed = true; }

void GameOSFile::ResetSaveState() {
    delete StateSlot(this);
    StateSlot(this) = nullptr;
}

// sub_533C50 / sub_533C90: the running checksum goes into the stream as a
// marker and is then folded back in like any other buffer.
void GameOSFile::WriteChecksumMarker() {
    if (Failed()) return;
    uint32_t marker = checksum;
    if (!Write(&marker, 4)) Fail();
}

void GameOSFile::ReadChecksumMarker() {
    if (Failed()) return;
    uint32_t marker = 0;
    if (!Read(&marker, 4)) Fail();
}

// sub_531BC0. Null and unsavable objects write ordinal 0. An object already in
// the table writes its ordinal. A new one takes the next ordinal, is written,
// and is then serialized inline -- so the reader meets its bytes immediately.
void GameOSFile::SavePtr(GameThing* obj) {
    if (Failed()) return;
    SaveState& st = StateOf(this);

    uint32_t ordinal = 0;
    if (!obj || obj->GetSaveType() == 0) {
        if (!Write(&ordinal, 4)) Fail();
        return;
    }
    for (size_t i = 0; i < st.ordinals.size(); ++i) {
        if (st.ordinals[i] == obj) {
            ordinal = static_cast<uint32_t>(i + 1);
            if (!Write(&ordinal, 4)) Fail();
            return;
        }
    }
    st.ordinals.push_back(obj);
    ordinal = static_cast<uint32_t>(st.ordinals.size());
    if (!Write(&ordinal, 4)) { Fail(); return; }
    obj->Save(this);
}

// sub_531F30, mirrored. A fresh ordinal means the object's bytes follow; it is
// registered before its fields are read so a cycle back to it resolves.
void GameOSFile::LoadPtr(GameThing** out) {
    if (out) *out = nullptr;
    if (Failed()) return;
    SaveState& st = StateOf(this);

    uint32_t ordinal = 0;
    if (!Read(&ordinal, 4)) { Fail(); return; }
    if (ordinal == 0) return;
    if (ordinal <= st.ordinals.size()) {
        if (out) *out = st.ordinals[ordinal - 1];
        return;
    }
    if (ordinal != st.ordinals.size() + 1 || !g_factory) {
        // Either the stream is out of step with us or the host gave us no way
        // to build the object; refusing beats fabricating a wrong graph.
        Fail();
        return;
    }
    uint32_t save_type = 0;
    if (!Read(&save_type, 4)) { Fail(); return; }
    GameThing* obj = g_factory(save_type);
    if (!obj) { Fail(); return; }
    st.ordinals.push_back(obj);
    if (out) *out = obj;
    // Save() wrote the type then SaveExtraData then the fields; we have taken
    // the type, so pick up from the extra-data word.
    uint32_t extra = 0;
    if (!Read(&extra, 4)) { Fail(); return; }
    obj->Load(this);
}

// sub_533B90 / sub_533BF0: info structs are shared read-only game data, stored
// as an index into their global table rather than by address.
void GameOSFile::SaveInfoPtr(const void* info) {
    if (Failed()) return;
    uint32_t index = (info && g_info_to_index) ? g_info_to_index(info) : 0;
    if (!Write(&index, 4)) Fail();
}

void GameOSFile::LoadInfoPtr(void** out) {
    if (out) *out = nullptr;
    if (Failed()) return;
    uint32_t index = 0;
    if (!Read(&index, 4)) { Fail(); return; }
    if (out && index && g_index_to_info) *out = g_index_to_info(index);
}

// ---------------------------------------------------------------------------
// Table lookup
// ---------------------------------------------------------------------------

namespace saveload {

int RowForSaveType(uint32_t save_type) {
    uint16_t lo = 0, hi = kSaveTypeCount;
    while (lo < hi) {
        uint16_t mid = static_cast<uint16_t>((lo + hi) / 2);
        if (kSaveTypes[mid].id < save_type) lo = static_cast<uint16_t>(mid + 1);
        else hi = mid;
    }
    if (lo < kSaveTypeCount && kSaveTypes[lo].id == save_type)
        return kSaveTypes[lo].cls;
    return -1;
}

const char* NameForSaveType(uint32_t save_type) {
    int row = RowForSaveType(save_type);
    return row < 0 ? nullptr : kClasses[row].name;
}

bool IsSerializable(uint32_t save_type) {
    for (int row = RowForSaveType(save_type); row >= 0; row = kClasses[row].parent)
        if (!kClasses[row].exact) return false;
    return RowForSaveType(save_type) >= 0;
}

void SetObjectFactory(ObjectFactory fn) { g_factory = fn; }
ObjectFactory GetObjectFactory() { return g_factory; }

void SetInfoMapping(InfoToIndex to_index, IndexToInfo to_info) {
    g_info_to_index = to_index;
    g_index_to_info = to_info;
}

// -------------------------------------------------------------------------
// Hooks: the three rows whose original body is not a flat field list.
// -------------------------------------------------------------------------
namespace {

inline uint8_t* At(void* obj, uint32_t off) {
    return static_cast<uint8_t*>(obj) + off;
}

// Object::Save (sub_5EBE00) tail. When the object is flagged as a live physics
// body it appends its physics transform: a 48-byte matrix and two vector3s,
// looked up from the global physics record array. Objects without a record --
// which is every object in this build, since we keep no such array -- take the
// original's else branch: an identity matrix and zeroed vectors.
const uint32_t kObjectFlagPhysics = 0x40;   // *(this + 0x24) & 0x40
const uint32_t kThingFlagNoPhysics = 0x10;  // *(this + 0x0A) & 0x10

bool ObjectWantsPhysicsBlock(void* obj) {
    return (*reinterpret_cast<uint16_t*>(At(obj, 36)) & kObjectFlagPhysics) != 0 &&
           (*At(obj, 10) & kThingFlagNoPhysics) == 0;
}

struct PhysicsBlock {
    float matrix[12];  // 48 bytes
    float linear[3];
    float angular[3];
};

void SaveObjectHook(GameOSFile& f, void* obj) {
    f.SaveInfoPtr(*reinterpret_cast<void**>(At(obj, 40)));
    f.Write(At(obj, 44), 12);
    f.Write(At(obj, 60), 4);
    f.Write(At(obj, 72), 4);
    f.Write(At(obj, 80), 4);
    f.Write(At(obj, 76), 4);
    f.SavePtr(*reinterpret_cast<GameThing**>(At(obj, 68)));
    if (!ObjectWantsPhysicsBlock(obj)) return;
    PhysicsBlock pb{};
    pb.matrix[0] = pb.matrix[4] = pb.matrix[8] = 1.0f;  // identity, no record
    f.Write(pb.matrix, 48);
    f.Write(pb.linear, 12);
    f.Write(pb.angular, 12);
}

void LoadObjectHook(GameOSFile& f, void* obj) {
    f.LoadInfoPtr(reinterpret_cast<void**>(At(obj, 40)));
    f.Read(At(obj, 44), 12);
    f.Read(At(obj, 60), 4);
    *reinterpret_cast<uint32_t*>(At(obj, 64)) = 0;  // cleared on load, not read
    f.Read(At(obj, 72), 4);
    f.Read(At(obj, 80), 4);
    f.Read(At(obj, 76), 4);
    f.LoadPtr(reinterpret_cast<GameThing**>(At(obj, 68)));
    if (!ObjectWantsPhysicsBlock(obj)) return;
    PhysicsBlock pb{};
    f.Read(pb.matrix, 48);
    f.Read(pb.linear, 12);
    f.Read(pb.angular, 12);  // discarded: no physics record to restore into
}

// MobileWallHug::Save (sub_5C7040). The middle block depends on what the unit
// is holding: hold type 11 writes one byte, types 12..18 write a carried-object
// descriptor instead.
void MobileHook(GameOSFile& f, void* obj, bool saving) {
    auto rw = [&](uint32_t off, uint32_t n) {
        saving ? (void)f.Write(At(obj, off), n) : (void)f.Read(At(obj, off), n);
    };
    rw(88, 2);
    rw(90, 2);
    rw(92, 2);
    rw(94, 1);

    const uint8_t hold = *At(obj, 94);
    if (hold == 11) {
        rw(120, 1);
    } else if (hold > 11 && hold <= 18) {
        rw(116, 1);
        uint32_t carried = *reinterpret_cast<uint16_t*>(At(obj, 118));
        if (saving) {
            f.Write(&carried, 4);
        } else {
            f.Read(&carried, 4);
            *reinterpret_cast<uint16_t*>(At(obj, 118)) =
                static_cast<uint16_t>(carried);
        }
        // The original resolves a held-object handle here and writes it plus a
        // dword and a vector3. We have no handle table, so the slot round-trips
        // as null with the same byte count.
        GameThing* held = nullptr;
        uint32_t   extra = 0;
        float      pos[3] = {0, 0, 0};
        if (saving) {
            f.SavePtr(held);
            f.Write(&extra, 4);
            f.Write(pos, 12);
        } else {
            f.LoadPtr(&held);
            f.Read(&extra, 4);
            f.Read(pos, 12);
        }
    }

    if (saving) f.SavePtr(*reinterpret_cast<GameThing**>(At(obj, 124)));
    else        f.LoadPtr(reinterpret_cast<GameThing**>(At(obj, 124)));
    rw(128, 12);
    if (saving) f.SavePtr(*reinterpret_cast<GameThing**>(At(obj, 96)));
    else        f.LoadPtr(reinterpret_cast<GameThing**>(At(obj, 96)));
    rw(100, 12);
}

// Living::Save (sub_5ACF00). Flat fields, then the singly linked list at +152
// is dumped as a count followed by two dwords per node.
void LivingHook(GameOSFile& f, void* obj, bool saving) {
    auto ptr = [&](uint32_t off) {
        if (saving) f.SavePtr(*reinterpret_cast<GameThing**>(At(obj, off)));
        else        f.LoadPtr(reinterpret_cast<GameThing**>(At(obj, off)));
    };
    auto rw = [&](uint32_t off, uint32_t n) {
        saving ? (void)f.Write(At(obj, off), n) : (void)f.Read(At(obj, off), n);
    };
    ptr(200);
    ptr(204);
    rw(140, 6);
    ptr(148);
    rw(156, 4);
    rw(160, 4);
    rw(168, 1);
    ptr(172);
    ptr(176);
    rw(180, 2);
    ptr(184);
    ptr(188);
    ptr(200);
    rw(196, 4);
    rw(208, 4);
    rw(212, 1);
    ptr(216);
    rw(220, 1);

    // The list at +152 holds pairs of dwords per node. We do not own that
    // allocator, so it round-trips as empty -- count 0 on the way out, and on
    // the way in the pairs are read and dropped.
    struct Node { Node* next; uint32_t* pair; };
    if (saving) {
        uint32_t count = 0;
        for (Node* n = *reinterpret_cast<Node**>(At(obj, 152)); n; n = n->next)
            ++count;
        f.Write(&count, 4);
        for (Node* n = *reinterpret_cast<Node**>(At(obj, 152)); n; n = n->next) {
            f.Write(n->pair, 4);
            f.Write(n->pair + 1, 4);
        }
    } else {
        uint32_t count = 0;
        f.Read(&count, 4);
        for (uint32_t i = 0; i < count && !f.Failed(); ++i) {
            uint32_t pair[2] = {0, 0};
            f.Read(pair, 4);
            f.Read(pair + 1, 4);
        }
    }
}

bool RunHook(GameOSFile& f, void* obj, uint8_t hook, bool saving) {
    switch (hook) {
        case HOOK_OBJECT: saving ? SaveObjectHook(f, obj) : LoadObjectHook(f, obj); return true;
        case HOOK_LIVING: LivingHook(f, obj, saving); return true;
        case HOOK_MOBILE: MobileHook(f, obj, saving); return true;
        default: return false;
    }
}

// One class level, in either direction.
void ApplyRow(GameOSFile& f, void* obj, const ClassDesc& row, bool saving) {
    if (RunHook(f, obj, row.hook, saving)) return;
    for (uint16_t i = 0; i < row.count && !f.Failed(); ++i) {
        const Field& fl = kFields[row.first + i];
        uint8_t* p = At(obj, fl.off);
        switch (fl.op) {
            case OP_RAW:
                if (!(saving ? f.Write(p, fl.n) : f.Read(p, fl.n))) f.Fail();
                break;
            case OP_PTR:
                if (saving) f.SavePtr(*reinterpret_cast<GameThing**>(p));
                else        f.LoadPtr(reinterpret_cast<GameThing**>(p));
                break;
            case OP_INFO:
                if (saving) f.SaveInfoPtr(*reinterpret_cast<void**>(p));
                else        f.LoadInfoPtr(reinterpret_cast<void**>(p));
                break;
            case OP_PTRARRAY: {
                uint32_t count = fl.n;
                if (saving) {
                    if (!f.Write(&count, 4)) { f.Fail(); break; }
                } else if (!f.Read(&count, 4)) { f.Fail(); break; }
                GameThing** arr = reinterpret_cast<GameThing**>(p);
                for (uint32_t k = 0; k < count && !f.Failed(); ++k) {
                    if (k < fl.n) {
                        if (saving) f.SavePtr(arr[k]);
                        else        f.LoadPtr(&arr[k]);
                    } else {
                        GameThing* discard = nullptr;   // stream is longer than the field
                        f.LoadPtr(&discard);
                    }
                }
                break;
            }
            case OP_RAWARRAY: {
                uint32_t count = fl.n;
                if (saving) {
                    if (!f.Write(&count, 4)) { f.Fail(); break; }
                } else if (!f.Read(&count, 4)) { f.Fail(); break; }
                uint32_t take = count < fl.n ? count : fl.n;
                if (!(saving ? f.Write(p, take * 4) : f.Read(p, take * 4))) f.Fail();
                break;
            }
            case OP_CHECKSUM:
                saving ? f.WriteChecksumMarker() : f.ReadChecksumMarker();
                break;
            default:
                f.Fail();
                break;
        }
    }
}

// Walk the class chain root-first, matching the original's parent-then-self
// delegation order.
bool Walk(GameOSFile& f, void* obj, uint32_t save_type, bool saving) {
    if (!obj || f.Failed()) return false;
    int leaf = RowForSaveType(save_type);
    if (leaf < 0 || !IsSerializable(save_type)) return false;

    int chain[32];
    int depth = 0;
    for (int row = leaf; row >= 0 && depth < 32; row = kClasses[row].parent)
        chain[depth++] = row;
    for (int i = depth - 1; i >= 0; --i)
        ApplyRow(f, obj, kClasses[chain[i]], saving);
    return !f.Failed();
}

}  // namespace

bool SaveFields(GameOSFile& f, void* obj, uint32_t save_type) {
    return Walk(f, obj, save_type, /*saving=*/true);
}

bool LoadFields(GameOSFile& f, void* obj, uint32_t save_type) {
    return Walk(f, obj, save_type, /*saving=*/false);
}

}  // namespace saveload
