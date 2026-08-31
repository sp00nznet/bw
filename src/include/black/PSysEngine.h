#pragma once
// PSysEngine — Black & White's atom/rule particle engine (PSys scope-A).
//
// BW does not have "a particle system"; it has a little interpreted one. A
// spell effect is a tree of *collections*, each holding *atoms* (the particles)
// and a list of *rules*. Every frame the manager runs each collection's rules:
// emitter rules create atoms, appearance rules rewrite their colour, scale and
// orientation, and event conditions gate whether a rule runs at all. The .psy
// files shipped with the game are just serialized rule graphs -- which is why
// the effects are so varied from so little code.
//
// The whole thing is recovered from runblack_decrypted.exe (v1.0): 124 classes
// dumped by tools/decomp (work/decomp/psys_all.txt), and -- the part that makes
// this tractable -- every rule publishes its own parameters to the in-game
// particle editor from vtable slot 3, so the real parameter names, offsets,
// types and ranges came straight out of the binary. That schema is
// work/decomp/psys_rules.json (49 rule classes, 210 parameters), extracted by
// work/parse_psysrules.py; the parameter names below are verbatim from it.
//
// Scope: this is the engine and the rules whose behaviour is arithmetic on
// atoms. The rules that exist only to drive the renderer (the ParticleCreator
// family, the 74-slot Particle3D* leaves) stay out -- they would be stubs, and
// the viewer already draws atoms as billboards.

#include <cstddef>
#include <cstdint>

namespace psys {

struct Atom;
struct Collection;

// ---------------------------------------------------------------------------
// Atom -- one particle. 304 bytes in the original (sub_61CD50 allocates that
// much); the offsets below are the ones the rule bodies actually address, so
// they are asserted rather than guessed.
// ---------------------------------------------------------------------------
struct Atom {
    uint8_t     pad_0x00[24];     // 0x00
    Atom*       next;             // 0x18 — sibling in the collection's list
    uint8_t     pad_0x1c[24];     // 0x1C
    float       vel[3];           // 0x34
    float       birth_time;       // 0x40
    // 0x44: a 4x3 matrix -- three orientation rows plus a translation row.
    // AppearanceRuleTumble rotates a column pair of every row.
    float       orient[12];       // 0x44
    uint8_t     pad_0x74[4];      // 0x74
    float       scale;            // 0x78
    uint8_t     pad_0x7c[4];      // 0x7C
    float       pos[3];           // 0x80
    uint32_t    colour;           // 0x8C — 0xAABBGGRR; alpha is the high byte
    uint8_t     pad_0x90[4];      // 0x90
    uint8_t     flags;            // 0x94
    uint8_t     pad_0x95[139];    // 0x95
    Collection* owner;            // 0x120
    uint8_t     pad_0x124[4];     // 0x124
    void*       particle;         // 0x128 — the renderable the creator made
    uint8_t     rand_seed;        // 0x12C
    uint8_t     pad_0x12d[3];     // 0x12D

    // Age is not stored: the original subtracts the atom's birth time from the
    // clock its collection points at (sub_61D210).
    float Age() const;

    uint8_t GetAlpha() const { return static_cast<uint8_t>(colour >> 24); }
    void    SetAlpha(uint8_t a) { colour = (colour & 0x00FFFFFFu) | (uint32_t(a) << 24); }
    float   Speed() const;

    // 0x10 in `flags`: the atom ignores world collision.
    enum : uint8_t { FLAG_NO_COLLIDE = 0x10 };
};
static_assert(sizeof(Atom) == 0x130, "Atom size mismatch");
static_assert(offsetof(Atom, next) == 0x18, "Atom::next offset");
static_assert(offsetof(Atom, vel) == 0x34, "Atom::vel offset");
static_assert(offsetof(Atom, birth_time) == 0x40, "Atom::birth_time offset");
static_assert(offsetof(Atom, orient) == 0x44, "Atom::orient offset");
static_assert(offsetof(Atom, scale) == 0x78, "Atom::scale offset");
static_assert(offsetof(Atom, pos) == 0x80, "Atom::pos offset");
static_assert(offsetof(Atom, colour) == 0x8C, "Atom::colour offset");
static_assert(offsetof(Atom, flags) == 0x94, "Atom::flags offset");
static_assert(offsetof(Atom, owner) == 0x120, "Atom::owner offset");
static_assert(offsetof(Atom, particle) == 0x128, "Atom::particle offset");

// ---------------------------------------------------------------------------
// Rules. Every rule in the binary has the same eight-slot vtable:
//
//   0 Init            1 Reset           2 ~dtor          3 RegisterProperties
//   4 Enter(atom)     5 Exit(atom)      6 Apply(coll)    7 ApplyToAtom(atom)
//
// Enter/Exit are a reference count on the rule (++/-- a word at offset 12), so
// a rule shared by several collections is only torn down once. Apply is the
// per-collection entry point; the appearance rules' shared Apply walks the
// collection's atom list and calls ApplyToAtom on each, optionally filtered by
// an event condition.
// ---------------------------------------------------------------------------
struct EventCondition;

struct Rule {
    virtual ~Rule() {}
    virtual void Init() {}
    virtual void Reset() {}
    virtual void Enter(Atom*) { ++ref_count; }   // sub_61ECF0
    virtual void Exit(Atom*)  { --ref_count; }   // sub_662180
    virtual bool Apply(Collection* c);           // sub_61ED40 (shared)
    virtual void ApplyToAtom(Atom*) {}

    uint16_t        ref_count = 0;   // original offset 12
    EventCondition* condition = nullptr;  // original offset 28
};

// An event condition is a rule whose slot 7 answers a question instead of
// doing work; its Apply always returns false so it is never run as an action.
struct EventCondition : public Rule {
    bool Apply(Collection*) override { return false; }   // sub_401360
    virtual bool Test(Atom* a) = 0;
    // When a condition gates an appearance rule, the rule runs on atoms whose
    // Test result differs from `invert` (the byte at offset 12 in the original).
    bool invert = false;
};

// ---------------------------------------------------------------------------
// Appearance rules -- rewrite an atom's look from its age.
// Parameter names and offsets are verbatim from the editor schema.
// ---------------------------------------------------------------------------

// AppearanceRuleFadeOut (0x8730e4): shrink to nothing and fade out over
// VanishAge. Scale reaches zero at 2x VanishAge, alpha at 1x.
struct AppearanceRuleFadeOut : public Rule {
    void ApplyToAtom(Atom* a) override;          // sub_64B1A0
    float VanishAge = 100.0f;                    // @32, range [0, 100]
};

// AR_FadeAlpha (0x8731bc): ramp alpha between two values over a time window.
struct AR_FadeAlpha : public Rule {
    void ApplyToAtom(Atom* a) override;          // sub_64B260
    float   StartTime = 0.0f;                    // @32
    float   StopTime = 0.0f;                     // @36
    int32_t StartAlpha = 255;                    // @40
    int32_t StopAlpha = 0;                       // @44
};

// AR_FadeAlphaWithHeightAboveLandscape (0x873228): alpha from how high the
// atom is above the terrain, clamped at RefHeight.
struct AR_FadeAlphaWithHeightAboveLandscape : public Rule {
    void ApplyToAtom(Atom* a) override;          // sub_64B400
    int32_t AlphaAtZero = 0;                     // @32
    int32_t AlphaAtRefHeight = 255;              // @36
    float   RefHeight = 1.0f;                    // @40
};

// AppearanceRuleTumble (0x873270): spin the atom's orientation at a rate
// proportional to its speed.
struct AppearanceRuleTumble : public Rule {
    void ApplyToAtom(Atom* a) override;          // sub_64C720
    bool  RestrictMaxRotation = false;           // @32
    float TumbleSpeed = 0.0f;                    // @36
    float MaxTumbleSpeed = 0.0f;                 // @40
};

// AR_FadeCollectionAlpha (0x8731e0): the same ramp applied to the whole
// collection rather than per atom, so it is an Apply with no ApplyToAtom.
struct AR_FadeCollectionAlpha : public Rule {
    bool Apply(Collection* c) override;          // sub_64B320
    float   StartTime = 0.0f;                    // @32
    float   StopTime = 0.0f;                     // @36
    int32_t StartAlpha = 255;                    // @40
    int32_t StopAlpha = 0;                       // @44
    bool    TimesAreAfterCloseDown = false;      // @48
    bool    SetAlphaAfterStopTime = false;       // @49
};

// ---------------------------------------------------------------------------
// Event conditions
// ---------------------------------------------------------------------------

struct EventConditionAtomDelay : public EventCondition {
    bool Test(Atom* a) override;                 // sub_626650
    float DelayTime = 0.0f;                      // @16
};

struct EventConditionAtomLimitedTime : public EventCondition {
    bool Test(Atom* a) override;                 // sub_626720
    float StartTime = 0.0f;                      // @16
    float StopTime = 0.0f;                       // @20
};

struct EventConditionAtomBelowSpeed : public EventCondition {
    bool Test(Atom* a) override;                 // sub_626850
    float CutOffSpeed = 0.0f;                    // @16
};

struct EventConditionAtomBelowHeight : public EventCondition {
    bool Test(Atom* a) override;                 // sub_626930
    float CutOffHeight = 0.0f;                   // @16
};

// EventConditionAtomCloseWater shares BelowHeight's body and parameter; in the
// original it is a distinct class only so the editor can label it differently.
struct EventConditionAtomCloseWater : public EventConditionAtomBelowHeight {};

struct EC_AtomAlphaAbove : public EventCondition {
    bool Test(Atom* a) override;                 // sub_626A00
    int32_t AlphaValue = 0;                      // @16
};

// ---------------------------------------------------------------------------
// Emitter rules -- create atoms. `creator` is the ParticleCreator that builds
// the renderable for each new atom (original offset 40); without one the rule
// declines to emit, exactly as the binary does.
// ---------------------------------------------------------------------------
struct ParticleCreatorHook {
    // Build the renderable for a new atom; may return null.
    void* (*create)(Atom* a) = nullptr;
};

struct EmitterRule : public Rule {
    ParticleCreatorHook* creator = nullptr;      // original offset 40
    bool no_collide = false;                     // original offset 56, sets FLAG_NO_COLLIDE
    // How many atoms this rule still wants to emit this tick (sub_64C8C0).
    virtual bool WantsToEmit(Collection* c);
    uint32_t emit_budget = 0;
};

// EmitterRuleSimple (0x873684): one atom per tick, launched in a random
// direction at Speed.
struct EmitterRuleSimple : public EmitterRule {
    bool Apply(Collection* c) override;          // sub_64CC20
    float Speed = 0.0f;                          // @84, range [0, 10]
    bool  OrientWithParent = false;              // @88
};

// EmitterRuleConical (0x873714): a cone of half-angle Spread about +Y, with
// speed jittered between 0.66x and 0.99x of Speed, optionally offset within a
// disk of the given Radius.
struct EmitterRuleConical : public EmitterRule {
    bool Apply(Collection* c) override;          // sub_64CF80
    float Speed = 0.0f;                          // @84
    float Spread = 0.0f;                         // @88
    float Radius = 0.0f;                         // @92
};

// DiskEmitter (0x8736cc): position offset uniformly over a disk of Radius,
// raised by Height. Emits with no velocity of its own.
struct DiskEmitter : public EmitterRule {
    bool Apply(Collection* c) override;          // sub_64C9F0
    float Radius = 0.0f;                         // @84
    float Height = 0.0f;                         // @88
};

// ---------------------------------------------------------------------------
// Collection -- a list of atoms plus the rules that act on them.
// ---------------------------------------------------------------------------
struct Collection {
    Atom*    atoms = nullptr;       // original offset 64, singly linked by Atom::next
    uint8_t  alpha = 255;           // original offset 80
    float    time = 0.0f;           // the clock atoms measure their age against
    float    closedown_time = -1.0f;  // original offset 164, < 0 until closing
    float    delta_time = 1.0f / 30.0f;

    Rule*    rules[16] = {};
    int      rule_count = 0;

    void AddRule(Rule* r);
    // Emit, then run every rule, then integrate and retire.
    void Update(float dt);

    Atom* NewAtom();                // sub_61CD50 + sub_61CD90
    void  FreeAtom(Atom* a);
    int   CountAtoms() const;
    void  Clear();

    // Atoms are retired once fully transparent, which is how the fade rules
    // end an effect without anything tracking lifetimes.
    void RetireInvisible();
};

// ---------------------------------------------------------------------------
// Host hooks
// ---------------------------------------------------------------------------
// Terrain height under a world position, for the height-based rules.
void SetLandscapeHeightFn(float (*fn)(float x, float z));
float LandscapeHeight(float x, float z);

// The original's random source (sub_61C050 returns a float in [0, limit)).
void  SeedPSysRandom(uint32_t seed);
float PSysRandom(float limit);

}  // namespace psys
