// SpellCast — casting a miracle, the parts translated so far. docs/gestures.md.
//
// In v1.0 the seed in the hand casts at a position (sub_6C00D0 -> the magic
// info's vslot 13 makes the Spell, Spell vslot 333 starts it). The spell's
// particle system then reports each particle that lands (Spell vslot 331),
// and a resource spell drops food or wood there (SpellResource,
// sub_6BBBF0 -> sub_618E10).
#pragma once

#include <cstdint>
#include <vector>

#include "types.h"

struct Object;

namespace spell {

// The magic info for a magic type: the MAGIC_* info sections laid end to end
// (the pointer arrays from dword_C58C18 on). Null past the end.
const char* MagicInfo(int type);

// A field v1.0's code reads from a magic info at offset X is at X - 4 in our
// info.dat element. Inferred, not proven: read 4 bytes later, the resource
// spells' food-or-wood field comes out 0 / 1 and their drops 200 / 500 (food /
// wood) then 20, where read as is the "flag" is 200 / 500. The loader path for
// the MAGIC_* sections (sub_4274A0 into 88-byte GMagicInfo objects) is not
// yet walked to show where the 4 bytes go.
int MagicOffset(int v10_offset);

// What one landing particle of a resource spell drops (sub_6BBBF0, v1.0
// offsets): food or wood is info +92 (0 / 1); the first drop is +96, later
// ones +100 -- food 200 then 20, wood 500 then 20 -- times the spell's
// power. The mana it costs is that times +104 (sub_6B7BD0).
// ponytail: power is 1 -- the original scales by the mana actually spent
// (sub_6B79A0 / sub_6B8870), and there are no players yet.
struct Drop { int resource; uint32_t amount; };
Drop ResourceDrop(int magic_type, bool first, float power = 1.0f);

// sub_618E10: the drop goes to whatever around it takes that resource and
// lies within 1.2 x its radius -- a storage pit takes anything (vslot 416),
// a pile its own kind -- in the 3 x 3 cells around the point; what is left
// would make a new pile (MagicFood / MagicWood, sub_5B8230). Returns what
// was not taken.
// ponytail: the cells' objects are passed in (no map cell lists yet), and
// leftovers make no pile (our MagicFood/MagicWood layouts are v1.41's).
uint32_t DropResource(int resource, uint32_t amount, const MapCoords& at, const std::vector<Object*>& nearby);

// A spell's effect on what a landing particle touches (the base Spell's
// vslot 331, sub_6B7E70). The values are seven floats and a radius from the
// magic type's DETAIL_MAGIC_EFFECT_INFO record (+16..+40, +44; sub_4FC630),
// all scaled by the spell's strength (sub_4FCA90). [1] and [2] wound, [3]
// heals; heal's record is [3] = 1 over 2 m.
struct Effect {
    float value[7] = {};
    float radius = 0.0f;
};
Effect EffectFor(int magic_type, float strength = 1.0f);

// sub_4FC660: everything around `at` that takes effects and lies within its
// own radius plus the effect's gets it (vslot 371): its heat ([0], into the
// fire simulation) and, on the living, wound and heal. Returns how many did.
// ponytail: the objects are passed in (no map cells), and the height check
// and the target redirection (vslot 374) are left out.
int ApplyInArea(const Effect& e, const MapCoords& at, const std::vector<Object*>& nearby);

// vslot 371 for Living (sub_5E9DD0), the life part: the wound (sub_5EA150:
// [1] and [2] against the target's defence multipliers, info +144..+168) and
// the heal (sub_5EA1D0: [3] x multiplier [2]). Returns the life change.
// ponytail: burning, the death report and the belief credited to towns
// are not translated.
float ApplyToLiving(const Effect& e, Object* target);

// One drop of the Water miracle (SpellWater vslot 330, sub_6BBD30): every
// object within 2.5 m of its edge gets vslot 415 (ApplyWaterSpell) -- a
// field is planted or grown. The drops fall within 6 m (magic 22) or 12 m
// (23) of the cast (sub_5B8600) for as long as the spell lasts.
// ponytail: one drop at the point; only fields answer (fire, trees not yet).
int WaterDrop(const MapCoords& at, const std::vector<Object*>& nearby);

}  // namespace spell
