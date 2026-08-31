// test_psys — the atom/rule particle engine.
//
// Checks the recovered layout, the rule dispatch (including the event-condition
// gate that lets one rule act on a subset of a collection), and the arithmetic
// of each translated rule against what the binary's body computes.

#include <black/PSysEngine.h>

#include <cmath>
#include <cstdio>

using namespace psys;

static int g_fail = 0;
#define CHECK(cond, msg) do { if (!(cond)) { printf("FAIL: %s\n", msg); ++g_fail; } \
                              else printf("ok  : %s\n", msg); } while (0)

static bool Near(float a, float b, float eps = 1e-4f) { return std::fabs(a - b) < eps; }

static float FlatGround(float, float) { return 10.0f; }

// A creator that just counts how many atoms an emitter asked it to build.
static int g_created = 0;
static void* CountingCreate(Atom*) { ++g_created; return nullptr; }

int main() {
    SetLandscapeHeightFn(FlatGround);
    SeedPSysRandom(12345);

    // --- recovered layout -------------------------------------------------
    CHECK(sizeof(Atom) == 0x130, "Atom is the 304 bytes the original allocates");

    Collection c;
    Atom* a = c.NewAtom();
    CHECK(a != nullptr, "collection allocates an atom");
    CHECK(a->owner == &c, "atom points back at its collection");
    CHECK(c.CountAtoms() == 1, "atom is linked into the collection");

    a->SetAlpha(0x80);
    CHECK(a->GetAlpha() == 0x80, "alpha is the high byte of the colour word");
    CHECK((a->colour & 0x00FFFFFFu) == 0x00FFFFFFu, "setting alpha leaves RGB alone");

    // --- age is derived, not stored ---------------------------------------
    c.time = 5.0f;
    a->birth_time = 2.0f;
    CHECK(Near(a->Age(), 3.0f), "age is the collection clock minus birth time");

    // --- AppearanceRuleFadeOut --------------------------------------------
    // scale runs out at 2x VanishAge, alpha at 1x.
    AppearanceRuleFadeOut fade;
    fade.VanishAge = 4.0f;
    c.time = 2.0f; a->birth_time = 0.0f;      // age 2 == half of VanishAge
    fade.ApplyToAtom(a);
    CHECK(Near(a->scale, 0.75f), "FadeOut shrinks on the half-rate ramp");
    CHECK(a->GetAlpha() == 127, "FadeOut halves alpha at half VanishAge");

    c.time = 4.0f;
    fade.ApplyToAtom(a);
    CHECK(a->GetAlpha() == 0, "FadeOut is fully transparent at VanishAge");
    CHECK(Near(a->scale, 0.5f), "and still half size, as the two ramps differ");

    c.time = 100.0f;
    fade.ApplyToAtom(a);
    CHECK(Near(a->scale, 0.0f) && a->GetAlpha() == 0, "FadeOut clamps past the end");

    // --- AR_FadeAlpha ------------------------------------------------------
    AR_FadeAlpha ramp;
    ramp.StartTime = 1.0f; ramp.StopTime = 3.0f;
    ramp.StartAlpha = 200; ramp.StopAlpha = 100;
    a->birth_time = 0.0f;
    a->SetAlpha(255);
    c.time = 0.5f; ramp.ApplyToAtom(a);
    CHECK(a->GetAlpha() == 255, "before StartTime the ramp leaves alpha alone");
    c.time = 2.0f; ramp.ApplyToAtom(a);
    CHECK(a->GetAlpha() == 150, "halfway through the window alpha is halfway");
    c.time = 3.5f; c.delta_time = 1.0f; ramp.ApplyToAtom(a);
    CHECK(a->GetAlpha() == 100, "crossing StopTime snaps to StopAlpha");

    // --- AR_FadeAlphaWithHeightAboveLandscape ------------------------------
    AR_FadeAlphaWithHeightAboveLandscape hfade;
    hfade.AlphaAtZero = 0; hfade.AlphaAtRefHeight = 200; hfade.RefHeight = 10.0f;
    a->pos[0] = a->pos[2] = 0.0f;
    a->pos[1] = 10.0f;                        // exactly on the ground
    hfade.ApplyToAtom(a);
    CHECK(a->GetAlpha() == 0, "on the ground the height fade is AlphaAtZero");
    a->pos[1] = 15.0f;                        // half of RefHeight above it
    hfade.ApplyToAtom(a);
    CHECK(a->GetAlpha() == 100, "halfway to RefHeight is halfway between the alphas");
    a->pos[1] = 500.0f;
    hfade.ApplyToAtom(a);
    CHECK(a->GetAlpha() == 200, "above RefHeight it flattens out");
    a->pos[1] = 0.0f;                         // below the terrain
    hfade.ApplyToAtom(a);
    CHECK(a->GetAlpha() == 0, "below the ground it flattens the other way");

    // --- event conditions --------------------------------------------------
    a->birth_time = 0.0f; c.time = 5.0f;
    EventConditionAtomDelay delay; delay.DelayTime = 4.0f;
    CHECK(delay.Test(a), "delay fires once the atom is older than DelayTime");
    delay.DelayTime = 6.0f;
    CHECK(!delay.Test(a), "and not before");

    EventConditionAtomLimitedTime window;
    window.StartTime = 4.0f; window.StopTime = 6.0f;
    CHECK(window.Test(a), "limited-time window is inclusive at the start");
    window.StopTime = 5.0f;
    CHECK(!window.Test(a), "and exclusive at the stop");

    a->vel[0] = 3.0f; a->vel[1] = 4.0f; a->vel[2] = 0.0f;   // speed 5
    EventConditionAtomBelowSpeed slow; slow.CutOffSpeed = 6.0f;
    CHECK(slow.Test(a), "below-speed compares the velocity magnitude");
    slow.CutOffSpeed = 4.0f;
    CHECK(!slow.Test(a), "and rejects a faster atom");

    a->pos[1] = 12.0f;   // 2 above the flat ground at 10
    EventConditionAtomBelowHeight low; low.CutOffHeight = 3.0f;
    CHECK(low.Test(a), "below-height measures above the terrain, not absolute");
    low.CutOffHeight = 1.0f;
    CHECK(!low.Test(a), "and rejects an atom higher than the cut-off");

    a->SetAlpha(100);
    EC_AtomAlphaAbove bright; bright.AlphaValue = 50;
    CHECK(bright.Test(a), "alpha-above compares the atom's alpha");
    bright.AlphaValue = 150;
    CHECK(!bright.Test(a), "and rejects a dimmer atom");

    // --- the condition gate on a shared Apply ------------------------------
    // This is the bit that makes the rule graph expressive: one rule over a
    // collection, acting only on the atoms a condition selects.
    c.Clear();
    Atom* young = c.NewAtom();
    Atom* old = c.NewAtom();
    c.time = 10.0f;
    young->birth_time = 9.0f;   // age 1
    old->birth_time = 0.0f;     // age 10
    young->SetAlpha(255);
    old->SetAlpha(255);

    AppearanceRuleFadeOut gated;
    gated.VanishAge = 4.0f;
    EventConditionAtomDelay older_than; older_than.DelayTime = 5.0f;
    gated.condition = &older_than;
    gated.Apply(&c);
    CHECK(young->GetAlpha() == 255, "the gate spared the atom the condition rejected");
    CHECK(old->GetAlpha() == 0, "and the rule ran on the one it selected");

    older_than.invert = true;
    young->SetAlpha(255);
    old->SetAlpha(255);
    gated.Apply(&c);
    // young is only a quarter of the way through VanishAge, so it dims rather
    // than vanishing -- what matters is that the two swapped roles.
    CHECK(young->GetAlpha() == 191 && old->GetAlpha() == 255,
          "inverting the condition swaps which atoms the rule touches");

    // --- emitters ----------------------------------------------------------
    ParticleCreatorHook creator;
    creator.create = CountingCreate;

    c.Clear();
    g_created = 0;
    EmitterRuleSimple simple;
    simple.Speed = 5.0f;
    CHECK(!simple.Apply(&c), "an emitter with no creator declines to emit");

    simple.creator = &creator;
    simple.emit_budget = 3;
    CHECK(simple.Apply(&c), "with a creator it emits");
    CHECK(c.CountAtoms() == 3, "it emitted exactly its budget");
    CHECK(g_created == 3, "and asked the creator for each one");
    CHECK(simple.emit_budget == 0, "the budget is spent");

    bool moving = true;
    for (Atom* p = c.atoms; p; p = p->next)
        if (p->Speed() <= 0.0f || p->Speed() > simple.Speed) moving = false;
    CHECK(moving, "every emitted atom got a speed within the rule's Speed");

    // Conical: velocities inside the cone half-angle about +Y.
    c.Clear();
    EmitterRuleConical cone;
    cone.creator = &creator;
    cone.Speed = 10.0f;
    cone.Spread = 0.3f;         // radians
    cone.emit_budget = 40;
    cone.Apply(&c);
    CHECK(c.CountAtoms() == 40, "conical emitter filled its budget");
    bool in_cone = true, in_speed = true;
    for (Atom* p = c.atoms; p; p = p->next) {
        const float speed = p->Speed();
        if (speed <= 0.0f) { in_speed = false; continue; }
        const float angle = std::acos(p->vel[1] / speed);
        if (angle > cone.Spread + 1e-3f) in_cone = false;
        // speed is jittered over the top third of the range
        if (speed < cone.Speed * 0.65f || speed > cone.Speed + 1e-3f) in_speed = false;
    }
    CHECK(in_cone, "every conical velocity lies inside the cone half-angle");
    CHECK(in_speed, "and its speed inside the jittered top third of Speed");

    // Disk: offsets land on a ring no wider than Radius, raised by Height.
    c.Clear();
    DiskEmitter disk;
    disk.creator = &creator;
    disk.Radius = 4.0f;
    disk.Height = 2.0f;
    disk.emit_budget = 30;
    disk.Apply(&c);
    bool on_disk = true;
    for (Atom* p = c.atoms; p; p = p->next) {
        const float r = std::sqrt(p->pos[0] * p->pos[0] + p->pos[2] * p->pos[2]);
        if (r > disk.Radius + 1e-3f) on_disk = false;
        if (!Near(p->pos[1], disk.Height)) on_disk = false;
    }
    CHECK(on_disk, "disk emitter places atoms within Radius and at Height");

    // --- tumble -------------------------------------------------------------
    c.Clear();
    Atom* t = c.NewAtom();
    t->vel[0] = 1.0f; t->vel[1] = 0.0f; t->vel[2] = 0.0f;
    c.delta_time = 0.5f;
    AppearanceRuleTumble tumble;
    tumble.TumbleSpeed = 2.0f;     // rate = speed(1) * 2 = 2 rad/s
    tumble.ApplyToAtom(t);
    // Row 0 was (1,0,0); rotating the (y,z) pair leaves it alone.
    CHECK(Near(t->orient[0], 1.0f), "tumble leaves the rotated row's first column");
    // Row 1 was (0,1,0) -> rotated by 1 rad in the y/z pair.
    CHECK(Near(t->orient[4], std::cos(1.0f)) && Near(t->orient[5], -std::sin(1.0f)),
          "tumble rotates the orientation rows by rate * delta");

    tumble.RestrictMaxRotation = true;
    tumble.MaxTumbleSpeed = 0.1f;
    Atom* t2 = c.NewAtom();
    t2->vel[0] = 100.0f;
    tumble.ApplyToAtom(t2);
    CHECK(Near(t2->orient[4], std::cos(0.05f)),
          "RestrictMaxRotation clamps the rate to MaxTumbleSpeed");

    // --- the update loop ----------------------------------------------------
    c.Clear();
    c.time = 0.0f;
    Atom* mover = c.NewAtom();
    mover->pos[0] = 0.0f; mover->vel[0] = 10.0f;
    mover->SetAlpha(255);
    c.Update(0.1f);
    CHECK(Near(mover->pos[0], 1.0f), "Update integrates position from velocity");
    CHECK(Near(c.time, 0.1f), "Update advances the collection clock");

    // A fully faded atom is retired by the update, which is how the fade rules
    // end an effect without anything tracking lifetimes.
    AppearanceRuleFadeOut ender;
    ender.VanishAge = 0.05f;
    c.AddRule(&ender);
    CHECK(ender.ref_count == 1, "AddRule takes a reference, as Enter does");
    c.Update(1.0f);
    CHECK(c.CountAtoms() == 0, "a fully transparent atom is retired");

    c.Clear();
    printf(g_fail ? "\n%d FAILURE(S)\n" : "\nALL PASS\n", g_fail);
    return g_fail ? 1 : 0;
}
