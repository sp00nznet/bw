// SpellCast — see black/SpellCast.h.
#include <black/SpellCast.h>

#include <black/Abode.h>
#include <black/Field.h>
#include <black/Fire.h>
#include <black/LHRandom.h>
#include <black/Living.h>
#include <black/InfoDat.h>
#include <black/Object.h>
#include <black/CreatureBrain.h>

#include <algorithm>
#include <cmath>
#include <cstring>

namespace spell {

const char* MagicInfo(int type) {
    static const infodat::Section kOrder[] = {
        infodat::DETAIL_MAGIC_GENERAL_INFO, infodat::DETAIL_MAGIC_HEAL_INFO, infodat::DETAIL_MAGIC_TELEPORT_INFO,
        infodat::DETAIL_MAGIC_FOREST_INFO, infodat::DETAIL_MAGIC_FOOD_INFO, infodat::DETAIL_MAGIC_STORM_AND_TORNADO_INFO,
        infodat::DETAIL_MAGIC_SHIELD_ONE_INFO, infodat::DETAIL_MAGIC_WOOD_INFO, infodat::DETAIL_MAGIC_WATER_INFO,
        infodat::DETAIL_MAGIC_FLOCK_FLYING_INFO, infodat::DETAIL_MAGIC_FLOCK_GROUND_INFO,
        infodat::DETAIL_MAGIC_CREATURE_SPELL_INFO};
    if (type < 0) return nullptr;
    for (infodat::Section s : kOrder) {
        const int n = static_cast<int>(infodat::Count(s));
        if (type < n) return static_cast<const char*>(infodat::Element(s, static_cast<uint32_t>(type)));
        type -= n;
    }
    return nullptr;
}

int MagicOffset(int v10_offset) { return v10_offset - 4; }

Drop ResourceDrop(int magic_type, bool first, float power) {
    Drop d{0, 0};
    const char* e = MagicInfo(magic_type);
    if (!e) return d;
    int32_t res, a, b;
    std::memcpy(&res, e + MagicOffset(92), 4);
    std::memcpy(&a, e + MagicOffset(96), 4);
    std::memcpy(&b, e + MagicOffset(100), 4);
    d.resource = res;
    d.amount = static_cast<uint32_t>(power * static_cast<float>(first ? a : b));
    return d;
}

uint32_t DropResource(int resource, uint32_t amount, const MapCoords& at, const std::vector<Object*>& nearby) {
    for (Object* o : nearby) {
        if (!amount) break;
        Abode* a = o ? o->CastAbode() : nullptr;
        if (!a || !a->IsResourceStore(static_cast<RESOURCE_TYPE>(resource))) continue;
        const float dx = MetresOf(at.x - o->coords.x), dz = MetresOf(at.z - o->coords.z);
        if (std::sqrt(dx * dx + dz * dz) > a->GetRadius() * 1.2f) continue;
        amount -= std::min(amount, o->AddResource(static_cast<RESOURCE_TYPE>(resource), amount, nullptr, false, at, 0));
    }
    return amount;
}

Effect EffectFor(int magic_type, float strength) {
    Effect e;
    const char* r = static_cast<const char*>(infodat::Element(infodat::DETAIL_MAGIC_EFFECT_INFO, static_cast<uint32_t>(magic_type)));
    if (!r) return e;
    std::memcpy(e.value, r + 16, sizeof e.value);
    std::memcpy(&e.radius, r + 44, 4);
    if (strength != 1.0f)
        for (float& v : e.value) v *= strength;
    return e;
}

float ApplyToLiving(const Effect& e, Object* t) {
    auto* l = dynamic_cast<Living*>(t);
    if (!l) return 0.0f;
    float def[7] = {};
    if (l->info) std::memcpy(def, reinterpret_cast<const char*>(l->info) + 144, sizeof def);  // vslot 370 (sub_5E9D50)
    float wound = 0.0f;
    for (int k = 1; k <= 2; ++k) {
        const float w = e.value[k] * def[k];
        if (w > 0.0f) wound += w;
    }
    float heal = e.value[3] * def[2];
    if (heal < 0.0f) heal = 0.0f;
    const float before = l->GetLife();
    if (heal > 0.0f) l->IncreaseLife(heal);
    if (wound > 0.0f) l->ReduceLife(wound, nullptr);
    return l->GetLife() - before;
}

int ApplyInArea(const Effect& e, const MapCoords& at, const std::vector<Object*>& nearby) {
    int n = 0;
    for (Object* o : nearby) {
        if (!o || !o->IsAvailable() || !o->info) continue;
        auto* l = dynamic_cast<Living*>(o);
        // vslot 477 (sub_6E1960): a heal reaches only the living not yet dead.
        if (e.value[3] > 0.0f && (!l || l->GetLife() <= 0.0f)) continue;
        const float dx = MetresOf(at.x - o->coords.x), dz = MetresOf(at.z - o->coords.z);
        if (std::sqrt(dx * dx + dz * dz) > o->GetRadius() + e.radius) continue;
        // Value [0] is heat (sub_6C6940, from the wound reader sub_5EA150).
        fire::AddHeat(o, e.value[0], nullptr);
        if (l) ApplyToLiving(e, o);
        ++n;
    }
    return n;
}

int WaterDrop(const MapCoords& at, const std::vector<Object*>& nearby, GPlayer* caster) {
    int n = 0;
    for (Object* o : nearby) {
        auto* f = dynamic_cast<Field*>(o);
        if (!f) continue;
        const float dx = MetresOf(at.x - o->coords.x), dz = MetresOf(at.z - o->coords.z);
        if (std::sqrt(dx * dx + dz * dz) - f->GetRadius() >= 2.5f) continue;
        f->ApplyWaterSpell(nullptr);
        if (caster) creature::PlayerDid(caster, 33, f, 22);
        ++n;
    }
    return n;
}

namespace {
struct Active {
    int magic;
    MapCoords at;
    GPlayer* caster;
    float age;
    float duration;
};
std::vector<Active> g_active;  // v1.0: the game's spell list at +0x201C80

float Duration(int magic_type, float power) {  // sub_5B8FF0 x the cast's power
    float d = 0.0f;
    if (const char* e = static_cast<const char*>(infodat::Element(infodat::DETAIL_MAGIC_EFFECT_INFO, static_cast<uint32_t>(magic_type))))
        std::memcpy(&d, e + 104, 4);
    return d * power;
}
float WaterRadius(int magic_type) { return magic_type == 22 ? 6.0f : (magic_type == 23 ? 12.0f : 1.0f); }  // sub_5B8600

void WaterTick(const Active& a, const std::vector<Object*>& world) {  // sub_6BBD30
    const float r = lh::RandomFloat(WaterRadius(a.magic)) * 0.7f + 0.3f;
    const float ang = lh::RandomFloat(6.2831855f);
    const MapCoords p(a.at.x + static_cast<int32_t>(std::cos(ang) * r * kMapUnitsPerMetre),
                      a.at.z + static_cast<int32_t>(std::sin(ang) * r * kMapUnitsPerMetre), a.at.altitude);
    std::vector<Object*> near;
    for (Object* o : world)
        if (o && std::fabs(MetresOf(o->coords.x - p.x)) < 20.0f && std::fabs(MetresOf(o->coords.z - p.z)) < 20.0f) near.push_back(o);
    WaterDrop(p, near, a.caster);
    ApplyInArea(EffectFor(a.magic), p, near);  // the drop lands (vslot 331): heat -4000
}
}  // namespace

void StartWater(int magic_type, const MapCoords& at, GPlayer* caster) {
    g_active.push_back({magic_type, at, caster, 0.0f, Duration(magic_type, 1.0f)});
}

void ProcessActive(const std::vector<Object*>& world) {
    for (size_t i = 0; i < g_active.size();) {
        Active& a = g_active[i];
        a.age = static_cast<float>(100.0 * 0.001 + static_cast<double>(a.age));  // dword_C22D78 (assumed 100 ms: it is set at runtime) x 0.001, in double as v1.0 does
        if (a.duration >= 0.0f && a.age > a.duration) { g_active.erase(g_active.begin() + static_cast<long>(i)); continue; }
        if (a.magic == 22 || a.magic == 23) WaterTick(a, world);
        ++i;
    }
}

int ActiveCount() { return static_cast<int>(g_active.size()); }
void ClearActive() { g_active.clear(); }

}  // namespace spell
