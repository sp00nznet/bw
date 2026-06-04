// psys_fx — lightweight billboard particle FX for spell visuals.
//
// Scope-B "openblack-faithful" particle manager: a CPU particle pool with
// camera-facing additive billboards, driven by the active LHVM spell set.
// Per-spell emitters approximate BW's real Atom/Rule behaviours (the engine
// exposes EmitterRuleConical, UR_HealSpellChakra, UR_LightningStrike,
// UR_SphereSurfaceTracer, etc. — see memory psys-real-architecture). This is
// a visual stand-in, not a 1:1 port of those ~128 rule classes.
//
// Usage (viewer main loop / render):
//   psysfx::Init();                       // once, after GL context exists
//   psysfx::Sync(spells, n, dt, height);  // each sim step
//   psysfx::Render();                     // each frame, in world space

#pragma once

#include <cstdint>

#include <black/LHVMObjects.h>   // lhvm::SpellSnap

namespace bw {
namespace psysfx {

// Height sampler: returns terrain altitude at world (x, z).
using HeightFn = float (*)(float x, float z);

// Build the soft-dot sprite texture. Safe to call more than once.
void Init();

// Advance the simulation by dt seconds and (re)emit from active spells.
// `spells`/`count` is the current lhvm::SnapshotSpells set; `height` samples
// terrain so ground-anchored emitters spawn at the right altitude.
void Sync(const lhvm::SpellSnap* spells, uint32_t count, float dt, HeightFn height);

// Draw every live particle as a camera-facing billboard (world space; assumes
// the modelview/projection for the scene is already set).
void Render();

// Number of live particles (HUD / debugging).
uint32_t LiveCount();

} // namespace psysfx
} // namespace bw
