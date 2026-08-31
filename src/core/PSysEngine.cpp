// PSysEngine — atom/rule particle engine, translated from the v1.0 binary.
//
// Every body here names the sub_ it came from. Where Hex-Rays lost something
// the comment says so rather than presenting a guess as recovered fact.

#include "black/PSysEngine.h"

#include <cmath>
#include <cstdlib>
#include <cstring>
#include <new>

namespace psys {

namespace {

float (*g_landscape_height)(float, float) = nullptr;

// The original draws from a shared table (sub_61C050 -> dword_C6EE60). A plain
// LCG stands in: what matters to the rules is a uniform float in [0, limit).
uint32_t g_rand_state = 0x1234567u;

inline float Length3(const float v[3]) {
    return std::sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

inline float Clamp(float v, float lo, float hi) {
    return v < lo ? lo : (v > hi ? hi : v);
}

const float kTwoPi = 6.2831855f;   // the literal 1086918619 the emitters pass

}  // namespace

void SetLandscapeHeightFn(float (*fn)(float, float)) { g_landscape_height = fn; }

float LandscapeHeight(float x, float z) {
    return g_landscape_height ? g_landscape_height(x, z) : 0.0f;
}

void SeedPSysRandom(uint32_t seed) { g_rand_state = seed ? seed : 1u; }

float PSysRandom(float limit) {
    g_rand_state = g_rand_state * 1664525u + 1013904223u;
    return (static_cast<float>(g_rand_state >> 8) / 16777216.0f) * limit;
}

// ---------------------------------------------------------------------------
// Atom
// ---------------------------------------------------------------------------

// sub_61D210: the atom does not store its age; it subtracts its birth time
// from the clock its collection carries.
float Atom::Age() const {
    return owner ? owner->time - birth_time : 0.0f;
}

float Atom::Speed() const { return Length3(vel); }

// ---------------------------------------------------------------------------
// Rule::Apply -- the shared appearance-rule body (sub_61ED40)
// ---------------------------------------------------------------------------
// Walk the collection's atoms and run ApplyToAtom on each. With a condition
// attached, only atoms whose Test result differs from the condition's `invert`
// byte are touched -- that is how one rule graph drives "fade only the ones
// that hit water" without a second collection.
bool Rule::Apply(Collection* c) {
    if (!c) return true;
    for (Atom* a = c->atoms; a;) {
        Atom* next = a->next;   // read first: ApplyToAtom may retire the atom
        if (!condition || condition->Test(a) != condition->invert) ApplyToAtom(a);
        a = next;
    }
    return true;
}

// ---------------------------------------------------------------------------
// Appearance rules
// ---------------------------------------------------------------------------

// sub_64B1A0. Two independent ramps off the same parameter: scale runs out at
// twice VanishAge, alpha at VanishAge, so the atom finishes fading before it
// finishes shrinking.
void AppearanceRuleFadeOut::ApplyToAtom(Atom* a) {
    if (VanishAge <= 0.0f) return;
    const float age = a->Age();
    a->scale = Clamp(1.0f - age * 0.5f / VanishAge, 0.0f, 1.0f);
    const float alpha = Clamp(1.0f - age / VanishAge, 0.0f, 1.0f);
    a->SetAlpha(static_cast<uint8_t>(alpha * 255.0f));
}

// sub_64B260. Hex-Rays renders the in-window value as a bare ftol of
// StartAlpha, having folded the interpolation away; the four parameters
// (StartTime/StopTime/StartAlpha/StopAlpha) only describe a ramp, so that is
// what this does. The snap to StopAlpha on the frame that crosses StopTime is
// explicit in the original and kept.
void AR_FadeAlpha::ApplyToAtom(Atom* a) {
    const float age = a->Age();
    if (age < StartTime) return;
    if (age > StopTime) {
        const float dt = a->owner ? a->owner->delta_time : 0.0f;
        if (age - dt <= StopTime) a->SetAlpha(static_cast<uint8_t>(StopAlpha));
        return;
    }
    const float span = StopTime - StartTime;
    const float t = span > 0.0f ? (age - StartTime) / span : 1.0f;
    const float v = StartAlpha + (StopAlpha - StartAlpha) * t;
    a->SetAlpha(static_cast<uint8_t>(Clamp(v, 0.0f, 255.0f)));
}

// sub_64B400: alpha from height above the terrain, flat below zero and above
// RefHeight, linear between.
void AR_FadeAlphaWithHeightAboveLandscape::ApplyToAtom(Atom* a) {
    const float ground = LandscapeHeight(a->pos[0], a->pos[2]);
    const float height = a->pos[1] - ground;
    float v;
    if (height < 0.0f) {
        v = static_cast<float>(AlphaAtZero);
    } else if (RefHeight > 0.0f && height <= RefHeight) {
        v = static_cast<float>(AlphaAtZero) +
            (static_cast<float>(AlphaAtRefHeight) - static_cast<float>(AlphaAtZero)) *
            height / RefHeight;
    } else {
        v = static_cast<float>(AlphaAtRefHeight);
    }
    a->SetAlpha(static_cast<uint8_t>(Clamp(v, 0.0f, 255.0f)));
}

// sub_64C720: spin proportional to speed. The orientation block is four rows
// of three; the original rotates one column pair of every row, choosing the
// pair on a condition Hex-Rays lost inside an fsincos. This takes the (1,2)
// pair -- rotation in the YZ plane, i.e. tumbling end over end, which is the
// motion the class is named for.
void AppearanceRuleTumble::ApplyToAtom(Atom* a) {
    float rate = a->Speed() * TumbleSpeed;
    if (RestrictMaxRotation) rate = Clamp(rate, -MaxTumbleSpeed, MaxTumbleSpeed);
    const float dt = a->owner ? a->owner->delta_time : 0.0f;
    const float angle = rate * dt;
    const float c = std::cos(angle);
    const float s = std::sin(angle);
    for (int row = 0; row < 4; ++row) {
        float& y = a->orient[row * 3 + 1];
        float& z = a->orient[row * 3 + 2];
        const float ny = s * z + c * y;
        z = c * z - s * y;
        y = ny;
    }
}

// sub_64B320: the collection-wide ramp. TimesAreAfterCloseDown measures from
// when the effect started closing rather than from its birth, which is how an
// effect fades out on demand instead of on a schedule.
bool AR_FadeCollectionAlpha::Apply(Collection* c) {
    if (!c) return true;
    float t;
    if (TimesAreAfterCloseDown) {
        if (c->closedown_time < 0.0f) return true;   // not closing yet
        t = c->time - c->closedown_time;
        if (t < 0.0f) t = 0.0f;
    } else {
        t = c->time;
    }

    if (t < StartTime || t > StopTime) {
        if (SetAlphaAfterStopTime && t > StopTime)
            c->alpha = static_cast<uint8_t>(StopAlpha);
        return true;
    }
    const float span = StopTime - StartTime;
    const float f = span > 0.0f ? (t - StartTime) / span : 1.0f;
    float v = StartAlpha + (StopAlpha - StartAlpha) * f;
    // The original snaps to StopAlpha on the frame that would step past it.
    if (t + c->delta_time > StopTime) v = static_cast<float>(StopAlpha);
    c->alpha = static_cast<uint8_t>(Clamp(v, 0.0f, 255.0f));
    return true;
}

// ---------------------------------------------------------------------------
// Event conditions
// ---------------------------------------------------------------------------

bool EventConditionAtomDelay::Test(Atom* a) {           // sub_626650
    return a->Age() > DelayTime;
}

bool EventConditionAtomLimitedTime::Test(Atom* a) {     // sub_626720
    const float age = a->Age();
    return age >= StartTime && age < StopTime;
}

bool EventConditionAtomBelowSpeed::Test(Atom* a) {      // sub_626850
    return a->Speed() < CutOffSpeed;
}

bool EventConditionAtomBelowHeight::Test(Atom* a) {     // sub_626930
    return a->pos[1] - LandscapeHeight(a->pos[0], a->pos[2]) - CutOffHeight < 0.0f;
}

bool EC_AtomAlphaAbove::Test(Atom* a) {                 // sub_626A00
    return static_cast<int32_t>(a->GetAlpha()) > AlphaValue;
}

// ---------------------------------------------------------------------------
// Emitter rules
// ---------------------------------------------------------------------------

// sub_64C8C0: the emitter asks whether it may make another atom this tick. The
// original spends a budget accumulated from an emission frequency; here the
// budget is set by whoever drives the collection.
bool EmitterRule::WantsToEmit(Collection* /*c*/) {
    if (!emit_budget) return false;
    --emit_budget;
    return true;
}

namespace {

// sub_61E290: a new atom inherits the emitter's atom template -- position,
// colour and scale -- before the rule perturbs it.
Atom* SpawnAtom(Collection* c, EmitterRule* rule) {
    Atom* a = c->NewAtom();
    if (!a) return nullptr;
    if (rule->creator && rule->creator->create) a->particle = rule->creator->create(a);
    if (rule->no_collide) a->flags |= Atom::FLAG_NO_COLLIDE;
    else                  a->flags &= static_cast<uint8_t>(~Atom::FLAG_NO_COLLIDE);
    return a;
}

}  // namespace

// sub_64CC20
bool EmitterRuleSimple::Apply(Collection* c) {
    if (!creator || !c) return false;
    while (WantsToEmit(c)) {
        Atom* a = SpawnAtom(c, this);
        if (!a) break;
        if (Speed != 0.0f) {
            // A random direction, normalised, scaled by a random speed up to
            // Speed. The original's random unit vector is sub_61C090.
            float d[3] = {PSysRandom(2.0f) - 1.0f,
                          PSysRandom(2.0f) - 1.0f,
                          PSysRandom(2.0f) - 1.0f};
            const float len = Length3(d);
            if (len > 0.0f) {
                const float s = PSysRandom(Speed) / len;
                a->vel[0] = d[0] * s;
                a->vel[1] = d[1] * s;
                a->vel[2] = d[2] * s;
            }
        }
        // OrientWithParent copies the parent atom's orientation onto the new
        // one (sub_61D650); with no parent chain here there is nothing to copy.
    }
    return true;
}

// sub_64CF80
bool EmitterRuleConical::Apply(Collection* c) {
    if (!creator || !c) return false;
    while (WantsToEmit(c)) {
        Atom* a = SpawnAtom(c, this);
        if (!a) break;

        const float theta = PSysRandom(Spread);          // half-angle off +Y
        const float phi = PSysRandom(kTwoPi);            // around +Y
        // Speed is jittered over the top third of its range, so a cone never
        // emits a perfectly uniform shell.
        const float speed = PSysRandom(Speed * 0.33f) + Speed * 0.66f;

        const float ring = std::sin(theta) * speed;
        a->vel[0] = std::cos(phi) * ring;
        a->vel[1] = std::cos(theta) * speed;
        a->vel[2] = std::sin(phi) * ring;

        if (Radius != 0.0f) {
            const float ang = PSysRandom(kTwoPi);
            const float dist = PSysRandom(Radius);
            a->pos[0] += std::cos(ang) * dist;
            a->pos[2] += std::sin(ang) * dist;
        }
    }
    return true;
}

// sub_64C9F0: rejection-sample a point in the unit disk, normalise it, and
// push the atom out along it by a random distance up to Radius.
bool DiskEmitter::Apply(Collection* c) {
    if (!creator || !c) return false;
    while (WantsToEmit(c)) {
        Atom* a = SpawnAtom(c, this);
        if (!a) break;

        float x, z;
        do {
            x = PSysRandom(2.0f) - 1.0f;
            z = PSysRandom(2.0f) - 1.0f;
        } while (x * x + z * z > 1.0f);

        const float dist = PSysRandom(Radius);
        const float len = std::sqrt(x * x + z * z);
        if (len > 0.0f) { x /= len; z /= len; }
        a->pos[0] += x * dist;
        a->pos[1] += Height;
        a->pos[2] += z * dist;
    }
    return true;
}

// ---------------------------------------------------------------------------
// Collection
// ---------------------------------------------------------------------------

void Collection::AddRule(Rule* r) {
    if (!r || rule_count >= 16) return;
    rules[rule_count++] = r;
    r->Enter(nullptr);
}

Atom* Collection::NewAtom() {
    // sub_61CD50 / sub_61CD90: 304 zeroed bytes, identity orientation, a random
    // per-atom seed, and the birth time stamped from the collection's clock.
    Atom* a = static_cast<Atom*>(std::calloc(1, sizeof(Atom)));
    if (!a) return nullptr;
    a->owner = this;
    a->birth_time = time;
    a->scale = 1.0f;
    a->colour = 0xFFFFFFFFu;
    a->orient[0] = a->orient[4] = a->orient[8] = 1.0f;
    a->rand_seed = static_cast<uint8_t>(PSysRandom(256.0f));
    a->next = atoms;
    atoms = a;
    return a;
}

void Collection::FreeAtom(Atom* a) { std::free(a); }

int Collection::CountAtoms() const {
    int n = 0;
    for (const Atom* a = atoms; a; a = a->next) ++n;
    return n;
}

void Collection::Clear() {
    while (atoms) {
        Atom* next = atoms->next;
        FreeAtom(atoms);
        atoms = next;
    }
}

// A fully transparent atom is done: the fade rules are what end an effect, so
// nothing else needs to track lifetimes.
void Collection::RetireInvisible() {
    Atom** link = &atoms;
    while (*link) {
        Atom* a = *link;
        if (a->GetAlpha() == 0) {
            *link = a->next;
            FreeAtom(a);
        } else {
            link = &a->next;
        }
    }
}

void Collection::Update(float dt) {
    delta_time = dt;
    time += dt;

    for (int i = 0; i < rule_count; ++i)
        if (rules[i]) rules[i]->Apply(this);

    for (Atom* a = atoms; a; a = a->next) {
        a->pos[0] += a->vel[0] * dt;
        a->pos[1] += a->vel[1] * dt;
        a->pos[2] += a->vel[2] * dt;
    }

    RetireInvisible();
}

}  // namespace psys
