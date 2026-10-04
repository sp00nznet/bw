// miracles — see miracles.h.
#include "miracles.h"

#include <black/Gesture.h>
#include <black/InfoDat.h>
#include <black/LevelLoader.h>
#include <black/Object.h>
#include <black/SpellCast.h>
#include <black/Town.h>

#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

namespace miracles {
namespace {

gesture::Templates g_templates;
gesture::Trail g_trail;
gesture::SpellSelect g_select;
bool g_loaded = false;
int g_held = -1;  // the chosen seed
std::string g_status = "middle mouse: draw a gesture (spiral, then the miracle's)";

// ponytail: every miracle counts as known. In v1.0 the player has those
// whose icons stand at its worship sites (sub_7080A0); Land 1 has none yet.
bool g_known[30];

const char* SeedName(int s) { return infodat::DebugName(infodat::DETAIL_SPELL_SEEDS, static_cast<uint32_t>(s)); }

}  // namespace

bool Init(const std::string& dir) {
    for (bool& k : g_known) k = true;
    g_trail.Clear();
    g_loaded = g_templates.Load(dir + "Gestures.jty") || g_templates.Load(dir + "Data/Gestures.jty");
    if (!g_loaded) g_status = "gestures: Gestures.jty not found";
    return g_loaded;
}

void StrokeBegin() { g_trail.Clear(); }

void StrokePoint(float sx, float sy) {
    // The trail ignores a point that has not moved (the hand held still).
    g_trail.Add(sx, sy);
}

void StrokeEnd(float ratio) {
    if (!g_loaded) return;
    const gesture::Data in = g_trail.ToData(ratio);
    g_trail.Clear();
    auto matches = [&](uint8_t id) { return g_templates.Match(id, in, ratio, nullptr); };
    // ponytail: v1.0 matches every frame while the stroke is drawn and
    // starts the trail again after each match (sub_58FC40 / sub_58EE10);
    // here a stroke is one gesture, matched when the button comes up.
    if (!g_select.active) {
        for (uint8_t opening : {1, 2}) {
            if (matches(opening) && g_select.Begin(opening, g_known)) {
                g_status = opening == 1 ? "spiral: now draw a miracle's gesture" : "spiral: now draw a creature spell's gesture";
                return;
            }
        }
        g_status = "not recognised (start with a spiral)";
        return;
    }
    bool done = false;
    const int chosen = g_select.Step(0.0f, matches, g_known, &done);
    if (chosen >= 0) {
        g_held = chosen;
        g_status = std::string("holding ") + SeedName(chosen) + " -- left click to cast";
    } else if (done) {
        g_status = "selection ended (no miracle has that gesture)";
    } else {
        g_status = "not recognised -- draw the miracle's gesture";
    }
}

bool Holding() { return g_held >= 0; }

std::string Cast(level::World& w, float x, float z) {
    if (g_held < 0) return g_status;
    const int seed = g_held;
    g_held = -1;
    // The seed's magic (sub_6C19A0, no stage chosen: seed +292).
    int32_t magic = -1;
    if (const char* e = static_cast<const char*>(infodat::Element(infodat::DETAIL_SPELL_SEEDS, static_cast<uint32_t>(seed))))
        std::memcpy(&magic, e + 292, 4);
    const bool resource = magic == 14 || magic == 15 || magic == 21;  // MAGIC_FOOD / MAGIC_WOOD sections
    if (magic == 10 || magic == 11) {  // MAGIC_HEAL: the effect where it lands
        // ponytail: one landing particle at the point (no particle effect yet).
        std::vector<Object*> near;
        for (auto& s : w.objects)
            if (s.obj && std::abs(MetresOf(s.obj->coords.x) - x) < 30.0f && std::abs(MetresOf(s.obj->coords.z) - z) < 30.0f) near.push_back(s.obj);
        const spell::Effect e = spell::EffectFor(magic);
        const int n = spell::ApplyInArea(e, MapCoordsFromMetres(x, z), near);
        char buf[128];
        std::snprintf(buf, sizeof buf, "%s: healed %d within %.1f m", SeedName(seed), n, e.radius);
        g_status = buf;
        return g_status;
    }
    if (magic == 22 || magic == 23) {  // MAGIC_WATER: rains for its duration, a drop a turn
        spell::StartWater(magic, MapCoordsFromMetres(x, z));
        g_status = std::string(SeedName(seed)) + ": raining";
        return g_status;
    }
    if (!resource) {
        g_status = std::string(SeedName(seed)) + ": casting not translated yet";
        return g_status;
    }
    // ponytail: one landing particle (the spell's particle effect is not
    // built), so one first drop at the point.
    const spell::Drop d = spell::ResourceDrop(magic, true);
    std::vector<Object*> stores;
    for (Town* t : w.towns)
        if (t->storage_pit_list) stores.push_back(reinterpret_cast<Object*>(t->storage_pit_list));
    const uint32_t left = spell::DropResource(d.resource, d.amount, MapCoordsFromMetres(x, z), stores);
    char buf[160];
    std::snprintf(buf, sizeof buf, "%s: %u %s, %u into a store%s", SeedName(seed), d.amount, d.resource ? "wood" : "food",
                  d.amount - left, left ? " (no store there; piles not built yet)" : "");
    g_status = buf;
    return g_status;
}

std::string Status() { return g_status; }

}  // namespace miracles
