#include "black/GClimate.h"
#include "black/InfoDat.h"
#include <algorithm>

namespace {
std::vector<GClimate*> g_climates;
GClimate* g_default = nullptr;
}

std::vector<GClimate*>& Climates() { return g_climates; }
GClimate*& DefaultClimate() { return g_default; }

// ponytail: the constructors' season-dependent rain and temperature from the
// record (sub_700D30 / sub_700EA0 with sub_529350's season), the climate-id
// counter (dword_B475C0) and the weather state are not translated; the level's
// RAIN / TEMP / WIND commands set what they set.
GClimate* CreateClimate(const MapCoords& pos, int type, float r1, float r2, int id) {
    auto* c = new GClimate();
    c->pos = pos;
    c->field_0x30 = 0;
    c->rain = {};
    c->temp[0] = c->temp[1] = 0.0f;
    c->wind[0] = c->wind[1] = c->wind[2] = 0.0f;
    std::fill(std::begin(c->field_0x58), std::end(c->field_0x58), uint8_t{0});
    c->id = id;
    if (!id) {
        if (g_default) {  // the old default goes (its vslot 3)
            g_climates.erase(std::find(g_climates.begin(), g_climates.end(), g_default));
            delete g_default;
        }
        c->info = infodat::Element(infodat::DETAIL_CLIMATE_INFO, 0);
        c->radius_min = c->radius_max = 5000.0f;
        g_default = c;
    } else {
        c->info = infodat::Element(infodat::DETAIL_CLIMATE_INFO, static_cast<uint32_t>(type));
        c->radius_min = std::min(r1, r2);
        c->radius_max = std::max(r1, r2);
    }
    g_climates.insert(g_climates.begin(), c);
    return c;
}

GClimate* FindClimate(int id) {
    if (!id) return g_default ? g_default : CreateClimate({}, 0, 0, 0, 0);
    for (GClimate* c : g_climates) if (c->id == id) return c;
    return nullptr;
}

void ResetClimates() {
    for (GClimate* c : g_climates) delete c;
    g_climates.clear();
    g_default = nullptr;
}

char*    GClimate::GetDebugText() { return "GClimate"; }
uint32_t GClimate::Load(GameOSFile* file) { return 0; }
uint32_t GClimate::Save(GameOSFile* file) { return 0; }
uint32_t GClimate::GetSaveType() { return 252; }

NightTime& Nighttime() { static NightTime t; return t; }

void SetNighttime(float day, float night, float dusk) {
    if (night >= 1.0f) night = 1.0f;
    if (dusk >= 1.0f - night) dusk = 1.0f - night;
    Nighttime() = {day, night, dusk};
}
