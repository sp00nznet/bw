// save_state — see save_state.h.

#include "save_state.h"
#include "game_loop.h"

#include <black/LHVM.h>
#include <black/LHVMObjects.h>
#include <black/Object.h>
#include <black/types.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>

namespace bw {
namespace savestate {

namespace {

constexpr uint32_t MAGIC   = 0x56535742;   // "BWSV"
constexpr uint32_t VERSION = 1;

constexpr uint32_t TAG_GTRN = 0x4E525447;  // "GTRN" — game turn
constexpr uint32_t TAG_ENTS = 0x53544E45;  // "ENTS" — entity table
constexpr uint32_t TAG_HAND = 0x444E4148;  // "HAND" — hand state
constexpr uint32_t TAG_LGLB = 0x424C474C;  // "LGLB" — LHVM globals
constexpr uint32_t TAG_LINF = 0x464E494C;  // "LINF" — influence sources

#pragma pack(push, 1)
struct EntityRecord {
    float    x, y, z;
    float    angle;
    float    scale;
    int32_t  mesh_id;
    uint32_t type;
    uint8_t  alive;
    uint8_t  pad[3];
};
static_assert(sizeof(EntityRecord) == 32, "EntityRecord size");

struct HandRecord {
    float    x, y, z;
    float    vel_x, vel_z;
    int32_t  held_entity;
    int32_t  hover_entity;
    uint8_t  over_land;
    uint8_t  pad[3];
};
static_assert(sizeof(HandRecord) == 32, "HandRecord size");
#pragma pack(pop)

GameState* g_hooked_state = nullptr;

bool WriteSection(FILE* f, uint32_t tag, const void* data, uint32_t size) {
    if (fwrite(&tag,  4, 1, f) != 1) return false;
    if (fwrite(&size, 4, 1, f) != 1) return false;
    if (size && fwrite(data, 1, size, f) != size) return false;
    return true;
}

// Skip an unrecognised section by reading and discarding its payload.
void SkipSection(FILE* f, uint32_t size) {
    fseek(f, static_cast<long>(size), SEEK_CUR);
}

} // namespace

std::string PathFor(int slot) {
    char buf[64];
    snprintf(buf, sizeof(buf), "saves/slot_%02d.bws", slot);
    return buf;
}

bool Save(int slot, const GameState& gs) {
    // Avoid dragging windows.h in: on first miss we shell out to mkdir.
    std::string path = PathFor(slot);
    FILE* f = fopen(path.c_str(), "wb");
    if (!f) {
        // Try creating the saves/ directory and retrying.
        system("mkdir saves 2>NUL");
        f = fopen(path.c_str(), "wb");
        if (!f) return false;
    }

    // Header
    fwrite(&MAGIC,   4, 1, f);
    fwrite(&VERSION, 4, 1, f);

    // GTRN — game turn
    WriteSection(f, TAG_GTRN, &gs.game_turn, sizeof(uint32_t));

    // ENTS — entity table
    std::vector<EntityRecord> ents;
    ents.reserve(gs.entities.size());
    for (const auto& e : gs.entities) {
        EntityRecord r = {};
        r.x = e.x; r.y = e.y; r.z = e.z;
        r.angle = e.angle; r.scale = e.scale;
        r.mesh_id = e.mesh_id;
        r.type = e.type;
        r.alive = e.alive ? 1 : 0;
        ents.push_back(r);
    }
    uint32_t ents_payload = static_cast<uint32_t>(ents.size() * sizeof(EntityRecord) + 4);
    uint32_t ents_count = static_cast<uint32_t>(ents.size());
    fwrite(&TAG_ENTS, 4, 1, f);
    fwrite(&ents_payload, 4, 1, f);
    fwrite(&ents_count, 4, 1, f);
    if (!ents.empty()) fwrite(ents.data(), sizeof(EntityRecord), ents.size(), f);

    // HAND — hand state
    HandRecord hr = {};
    hr.x = gs.hand.x; hr.y = gs.hand.y; hr.z = gs.hand.z;
    hr.vel_x = gs.hand.vel_x; hr.vel_z = gs.hand.vel_z;
    hr.held_entity  = gs.hand.held_entity;
    hr.hover_entity = gs.hand.hover_entity;
    hr.over_land = gs.hand.is_over_land ? 1 : 0;
    WriteSection(f, TAG_HAND, &hr, sizeof(hr));

    // LGLB — LHVM global variables (best-effort)
    if (gs.vm && gs.vm->global_vars && gs.vm->global_var_count > 0) {
        uint32_t bytes = gs.vm->global_var_count * sizeof(float);
        uint32_t payload = bytes + 4;
        fwrite(&TAG_LGLB, 4, 1, f);
        fwrite(&payload, 4, 1, f);
        fwrite(&gs.vm->global_var_count, 4, 1, f);
        fwrite(gs.vm->global_vars, sizeof(float), gs.vm->global_var_count, f);
    }

    // LINF — influence sources
    lhvm::InfluenceSourceView infs[64];
    uint32_t n = lhvm::SnapshotInfluences(infs, 64);
    if (n > 0) {
        uint32_t bytes = n * static_cast<uint32_t>(sizeof(lhvm::InfluenceSourceView));
        uint32_t payload = bytes + 4;
        fwrite(&TAG_LINF, 4, 1, f);
        fwrite(&payload, 4, 1, f);
        fwrite(&n, 4, 1, f);
        fwrite(infs, sizeof(lhvm::InfluenceSourceView), n, f);
    }

    fclose(f);
    printf("Save: wrote slot %d (%zu entities, %u globals) → %s\n",
           slot, ents.size(),
           gs.vm ? gs.vm->global_var_count : 0u, path.c_str());
    fflush(stdout);
    return true;
}

bool Load(int slot, GameState& gs) {
    std::string path = PathFor(slot);
    FILE* f = fopen(path.c_str(), "rb");
    if (!f) return false;

    uint32_t magic, version;
    if (fread(&magic, 4, 1, f) != 1 || magic != MAGIC ||
        fread(&version, 4, 1, f) != 1 || version != VERSION) {
        fclose(f);
        return false;
    }

    while (true) {
        uint32_t tag, size;
        if (fread(&tag, 4, 1, f) != 1) break;
        if (fread(&size, 4, 1, f) != 1) break;

        if (tag == TAG_GTRN && size == 4) {
            fread(&gs.game_turn, 4, 1, f);
        } else if (tag == TAG_ENTS && size >= 4) {
            uint32_t count = 0;
            fread(&count, 4, 1, f);
            uint32_t expected = 4 + count * static_cast<uint32_t>(sizeof(EntityRecord));
            if (size != expected) { SkipSection(f, size - 4); continue; }
            // Only restore entities that already exist in the live state —
            // resurrecting deleted ones requires re-running EntityFactory,
            // which is deferred. For the common case (player saved and is
            // reloading the same session) the entity count matches.
            uint32_t restore = count < gs.entities.size()
                                   ? count
                                   : static_cast<uint32_t>(gs.entities.size());
            std::vector<EntityRecord> rec(count);
            fread(rec.data(), sizeof(EntityRecord), count, f);
            for (uint32_t i = 0; i < restore; i++) {
                auto& e = gs.entities[i];
                e.x = rec[i].x; e.y = rec[i].y; e.z = rec[i].z;
                e.angle = rec[i].angle;
                e.scale = rec[i].scale;
                e.mesh_id = rec[i].mesh_id;
                e.type = rec[i].type;
                e.alive = rec[i].alive != 0;
                if (i < gs.core_entities.size() && gs.core_entities[i]) {
                    int32_t mx = static_cast<int32_t>(e.x * 65536.0f);
                    int32_t mz = static_cast<int32_t>(e.z * 65536.0f);
                    gs.core_entities[i]->SetPos(MapCoords(mx, mz, e.y));
                }
            }
        } else if (tag == TAG_HAND && size == sizeof(HandRecord)) {
            HandRecord hr;
            fread(&hr, sizeof(hr), 1, f);
            gs.hand.x = hr.x; gs.hand.y = hr.y; gs.hand.z = hr.z;
            gs.hand.vel_x = hr.vel_x; gs.hand.vel_z = hr.vel_z;
            gs.hand.held_entity  = hr.held_entity;
            gs.hand.hover_entity = hr.hover_entity;
            gs.hand.is_over_land = hr.over_land != 0;
        } else if (tag == TAG_LGLB && size >= 4) {
            uint32_t count = 0;
            fread(&count, 4, 1, f);
            uint32_t expected = 4 + count * 4;
            if (size != expected) { SkipSection(f, size - 4); continue; }
            if (gs.vm && gs.vm->global_vars && count == gs.vm->global_var_count) {
                fread(gs.vm->global_vars, sizeof(float), count, f);
            } else {
                SkipSection(f, count * 4);
            }
        } else {
            SkipSection(f, size);
        }
    }

    fclose(f);
    printf("Save: loaded slot %d from %s\n", slot, path.c_str());
    fflush(stdout);
    return true;
}

namespace {
void OnSaveGameInSlot(int slot) {
    if (!g_hooked_state) return;
    Save(slot, *g_hooked_state);
}
} // namespace

void RegisterLHVMHook(GameState* gs) {
    g_hooked_state = gs;
    lhvm::g_save_slot_func = OnSaveGameInSlot;
}

} // namespace savestate
} // namespace bw
