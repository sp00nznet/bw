// Fire — see black/Fire.h. Translated from sub_6C4E30 .. sub_6C6940, the
// cooling step from the disassembly (Hex-Rays lost its x87 operands).
#include <black/Fire.h>

#include <black/FireEffect.h>
#include <black/Living.h>
#include <black/Object.h>

#include <algorithm>
#include <cmath>
#include <cstring>

namespace fire {
namespace {

std::vector<FireEffect*> g_fires;  // v1.0: the game's list at +0x201CD0

float InfoF(const Object* o, int off) {
    float x = 0.0f;
    if (o && o->info) std::memcpy(&x, reinterpret_cast<const char*>(o->info) + off, 4);
    return x;
}
float MaxTemp(const Object* o) { return Ignition(o) * 2.0f; }  // sub_6C64A0
// ponytail: an object without a measured radius counts as 1 m across.
float Radius(Object* o) { const float r = o->GetRadius(); return r > 0.0f ? r : 1.0f; }
// sub_6C64F0: how fast it loses heat to the air -- height x radius x 4, the
// height (vslot 267) being twice its mesh's height x scale.
// ponytail: no mesh heights in core; the radius stands in for the height.
float CoolingFactor(Object* o) { return Radius(o) * Radius(o) * 4.0f; }
float Dist(const Object* a, const Object* b) {
    const float dx = MetresOf(a->coords.x - b->coords.x), dz = MetresOf(a->coords.z - b->coords.z);
    return std::sqrt(dx * dx + dz * dz);
}
bool Burning(const FireEffect* f) { return Ignition(f->source) <= f->temperature; }  // sub_6C6640
float& Smoke(FireEffect* f) { return *reinterpret_cast<float*>(&f->field_0x34); }  // +0x34
// sub_6C6900: heat q into the fire, at most d degrees.
void Raise(FireEffect* f, float q, float d) {
    float v = q / Capacity(f->source);
    if (std::fabs(d) < std::fabs(v)) v = d;
    f->temperature += v;
}
// sub_6C66C0: how fiercely it burns, 0..1 (no more than twice its life).
float Intensity(FireEffect* f) {
    const float i = Ignition(f->source);
    float v = (f->temperature - i * 0.8f) / (MaxTemp(f->source) - i * 0.8f);
    const float l2 = f->source->GetLife() * 2.0f;
    if (l2 <= v) v = l2;
    return v <= 0.0f ? 0.0f : (v >= 1.0f ? 1.0f : v);
}

void Extinguish(FireEffect* f) {  // vslot 3: off the list, off the object
    f->source->fire_effect = nullptr;
    g_fires.erase(std::remove(g_fires.begin(), g_fires.end(), f), g_fires.end());
    delete f;
}

// sub_6C5C70: heat a neighbour within the fire's reach.
// ponytail: the height check (sub_6C6260) and the target redirection
// (vslot 374) are left out.
void HeatNeighbour(FireEffect* f, Object* n, float reach) {
    if (n == f->source || n == reinterpret_cast<Object*>(f->thing)) return;
    if (!Burning(f) && Ignition(n) > f->temperature) return;
    if (Radius(n) + reach <= Dist(f->source, n)) return;
    const float d = f->temperature - Temperature(n);
    if (d <= 0.0f) return;
    FireEffect* t = n->fire_effect ? n->fire_effect : Ignite(n, f->player);
    if (!t) return;
    float q = 10.0f * d;  // sub_6C5C50: 0.1 x 100 x d
    const float cap = (f->temperature - kAir) * Capacity(f->source) * 0.5f;  // sub_6C68D0 x 0.5
    if (q >= cap) q = cap;
    Raise(t, q, d);
    if (!Burning(f)) Raise(f, -q, -d);
}

void Tick(FireEffect* f, const std::vector<Object*>& nearby) {  // sub_6C52A0
    Object* o = f->source;
    if (f->temperature - kAir < 0.1f && Smoke(f) == 0.0f) { Extinguish(f); return; }
    uint8_t flags = 0;
    const float ig = Ignition(o);
    if (ig * 3.0f < f->temperature) flags |= 2;
    if (f->temperature2 < ig && f->temperature >= ig) flags |= 1;  // caught (the sparks are not drawn)
    const float rate = BurnRate(o);
    const bool not_burning = f->temperature < ig || rate == 0.0f;
    float wet = 1.0f;
    bool cool = true;
    // ponytail: water and rain at the spot (sub_5BFBF0 / sub_6FE770) are
    // not consulted -- there is no climate yet -- so a fire is only ever dry.
    if (f->temperature2 > f->temperature) flags |= 4;
    if (!not_burning) {
        f->temperature += 0.1f * f->temperature / Capacity(o);
        if (f->temperature > MaxTemp(o)) f->temperature = MaxTemp(o);
        cool = false;
    }
    if (cool) {
        if (f->temperature < kAir) f->temperature = kAir;
        if (f->temperature <= f->temperature2) {
            f->temperature -= (f->temperature + 10.0f - kAir) * CoolingFactor(o) * 0.1f * wet / Capacity(o);
            if (f->temperature2 >= ig && f->temperature < ig) flags |= 8;  // gone out
        }
    }
    const float life = o->GetLife();
    float& smoke = Smoke(f);
    const float smoke_cap = std::max(0.0f, (0.6f - life) / 0.6f);  // flt_CC1658 = 1 / 0.6
    if (f->temperature < ig) {
        if (smoke != 0.0f && life != 0.0f) smoke = std::min(std::max(0.0f, smoke - 0.02f), smoke_cap);
    } else {
        const float burn = (f->temperature - ig) / (MaxTemp(o) - ig) * rate * 0.1f;
        if (life < 0.6f) smoke = std::min(std::min(1.0f, smoke + 0.04f), smoke_cap);
        // ponytail: dying by fire (vslot 382) and the town's emergency are
        // not translated.
        if (life > 0.0f) o->ReduceLifeDueToBurning(burn, f->player);
    }
    f->field_0x38 = flags;
    // sub_6C6200: it reaches 1.25 x its radius x how fiercely it burns.
    const float reach = Radius(o) * 1.25f * Intensity(f);
    if (reach > 0.0f)
        for (Object* n : nearby)
            if (n && n != o && Dist(o, n) < reach + Radius(n) + 10.0f) HeatNeighbour(f, n, reach);
    f->temperature2 = f->temperature;
}

}  // namespace

float Ignition(const Object* o) { const float i = InfoF(o, 180); return i < 40.0f ? 40.0f : i; }
float Capacity(const Object* o) { const float c = InfoF(o, 176); return c < 1.0f ? 1.0f : c; }
float BurnRate(const Object* o) { return InfoF(o, 144); }
float Temperature(const Object* o) { return o && o->fire_effect ? o->fire_effect->temperature : kAir; }

FireEffect* Ignite(Object* o, GPlayer* by) {
    if (!o) return nullptr;
    if (o->fire_effect) return o->fire_effect;
    if (InfoF(o, 180) == 0.0f) return nullptr;  // sub_5EBCF0: it does not burn
    auto* f = new FireEffect();
    f->source = o;
    f->player = by;
    f->thing = nullptr;
    f->temperature = f->temperature2 = Temperature(o);
    o->fire_effect = f;
    g_fires.push_back(f);
    return f;
}

void AddHeat(Object* o, float heat, GPlayer* by) {
    if (heat == 0.0f || !o) return;
    FireEffect* f = o->fire_effect ? o->fire_effect : (heat > 0.0f ? Ignite(o, by) : nullptr);
    if (!f) return;
    const float d = kAir + heat - f->temperature;
    Raise(f, 10.0f * d, d);
}

void Process(const std::vector<Object*>& nearby) {
    const std::vector<FireEffect*> now = g_fires;  // fires started this turn wait for the next
    for (FireEffect* f : now)
        if (std::find(g_fires.begin(), g_fires.end(), f) != g_fires.end()) Tick(f, nearby);
}

int Count() { return static_cast<int>(g_fires.size()); }

void Clear() {
    while (!g_fires.empty()) Extinguish(g_fires.back());
}

}  // namespace fire
