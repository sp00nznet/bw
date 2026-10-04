// SpellCast — see black/SpellCast.h.
#include <black/SpellCast.h>

#include <black/Abode.h>
#include <black/Living.h>
#include <black/InfoDat.h>
#include <black/Object.h>

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
        if (!o || !o->IsAvailable()) continue;
        auto* l = dynamic_cast<Living*>(o);
        // vslot 477 (sub_6E1960): a heal reaches only the living not yet dead.
        if (!l || (e.value[3] > 0.0f && l->GetLife() <= 0.0f)) continue;
        const float dx = MetresOf(at.x - o->coords.x), dz = MetresOf(at.z - o->coords.z);
        if (std::sqrt(dx * dx + dz * dz) > o->GetRadius() + e.radius) continue;
        ApplyToLiving(e, o);
        ++n;
    }
    return n;
}

}  // namespace spell
