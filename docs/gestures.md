# Gestures

How v1.0 recognises a gesture drawn with the hand. The code is
`src/core/Gesture.cpp` (`black/Gesture.h`), checked by `test_gesture`.

## The templates: `Data/Gestures.jty`

The file is a count (81), then one 1,628-byte record per template (`sub_545AC0` /
`sub_545600`):

- **80 points of 20 bytes**: x, an unused float, y (both 0..1), the turn at that point
  in radians, and the octant 0-7 of the heading of the segment that starts there.
- **Seven dwords**, read to +1608, +1609, +1610, +1616, +1620, +1624 and +1612.
  The first three land on overlapping bytes, so only their low bytes survive: the
  point count (+1608) and the gesture id (+1609). The rest are three flags and the
  aspect:
  - +1616: the first segment's octant must agree.
  - +1620: the template may also match mirrored.
  - +1624: the aspect band must agree.
  - +1612: the aspect (width / height).

The 81 templates cover 23 gestures; most gestures have several drawings.

## The trail

The hand keeps the stroke in a ring of 80 entries of 40 bytes (`sub_546890`). Each
entry is a point as above, plus a world position, a flag and a heading.

- **Adding a point.** The hand held still for 70 points clears the trail. The check
  compares the new point with the point two back, not the one before; that quirk is
  kept.
- **After each point** (`sub_546FC0`), the first point is flagged as the start and the
  newest as the end. Then the tracker looks for a corner between the last key point
  and the newest point (`sub_546BB0`):
  - Candidates must be at least 4 px from both ends.
  - The candidate with the sharpest turn, of at least 0.29 rad, becomes a corner.
- **Close corners merge.** A corner too close to the last one (`sub_5471A0`: closer
  than 12 px, or than 4 px in a gesture under 50 px) is merged with it, at whichever
  spot turns more sharply (`sub_546DD0`).
- **Each corner records** (`sub_5472B0` / `sub_5473C0`): the heading of the segment it
  starts, that heading's octant (`sub_544F80`, rounded half up), and the turn from the
  previous segment.

The start, corners, end and last point become a record shaped like a template
(`sub_545360`). Its aspect (`sub_545570`) is width over height, with the height scaled
by the screen's width / height.

## Matching

Matching asks one question: does the stroke match gesture *id*? It tries every
template of that id (`sub_545D70` -> `sub_545E80`); the original asks this for each
gesture the context allows. For each start point in the stroke (`sub_545FD0`):

1. If the template asks for it, the octant there must equal the template's first
   octant. Mirrored, it must equal 8 minus that octant.
2. The template's turns and the stroke's are walked together, summing their difference
   (wrapped to plus or minus pi).
3. A turn under 0.52 rad may be passed over on either side when that brings the sum
   closer. A sum above 0.59 rad fails this start.
4. If the template asks for it, the matched span's aspect band must agree
   (`sub_545DD0`, read from the disassembly). The bands are thin (under 0.15),
   ordinary, and wide (over 4). A thin stroke needs a thin template, an ordinary one
   an ordinary template, and a wide one any template that is not thin.

Failing as drawn, a template that allows it is tried mirrored (`sub_546210`), with the
stroke's turns negated.

The angles come from initialisers IDA never made functions (0x545C50, 0x5467A0):
corner pi/8 x 3 x 0.25 = 0.2945 rad, skip that x 7 x 0.25 = 0.5154 rad, drift limit
twice the corner, 0.589 rad.

`test_gesture` draws each template as a mouse stroke, 200 px across with a point every
20 px. 76 of the 81 are recognised as their own gesture, and the misses are
coarsely-sampled curves. The trail reproduces a template's corners closely: template 20
comes back with the same six points, turns within 0.01 rad, and the same octants.

## Choosing a miracle

At a worship site the hand chooses a spell by a short sequence of gestures
(`sub_58F990` / `sub_58F9C0`, then `sub_590420` each frame):

- Each spell seed (`DETAIL_SPELL_SEEDS`, the table at 0xCBE310) names up to three
  gestures at +256, +260 and +264. The first is a spiral: 1 for miracles, 2 for
  creature spells.
- Drawing a spiral that one of the player's spell icons begins with starts the
  selection. The candidates are those icons' seeds. The gestures that would advance
  are the candidates' next gestures.
- Each gesture drawn keeps the seeds whose next gesture it is, and only those the
  player still has (`sub_5F9100`). A seed whose sequence ends there is chosen: game
  command 37, `sub_523770(37, seed)`.
- Gesture 5 cancels. The selection also ends after `DETAIL_SPELL_SYSTEM_INFO` +28
  seconds without progress (`flt_CC1214`), or when no candidate is left.

| Spell | Gestures | Spell | Gestures |
|---|---|---|---|
| Storm | 1, 12 | Wood | 1, 6 |
| Nature | 1, 16 | Water | 1, 20 |
| Fire | 1, 7 | Flying flock | 1, 15 |
| Food | 1, 3 | Ground flock | 1, 22 |
| Shield | 1, 9 | Teleport | 1, 21 |
| Physical shield | 1, 11 | Beam explosion | 1, 8 |
| Lightning bolt | 1, 10 | Creature spells | 2, then 7-19 |
| Heal | 1, 13 | | |

Seven creature spells (fat, thin, hungry, frightened, tired, ill, thirsty) have no
second gesture in this data, so they cannot be chosen this way.

`test_gesture` draws each spell's sequence from the templates and gets that spell for
all 23 that have one.

## Other gestures in the data

- **Power-up gestures.** A seed's three stages are magic types at +296..+304, with
  their power-up gestures at +308..+316 (`sub_58F820`). On this data those are 1 and
  2.
- **Magic types** index the MAGIC_* info sections laid end to end: 0-9 general, 10-11
  heal, 12 teleport, 13 forest, 14-15 food, 16-18 storm, 19-20 shield, 21 wood, 22-23
  water, 24-25 flocks, 26-41 creature spells. Each record's first field is its own
  type, which confirms the order. The info class makes its spell at vslot 13: for
  example `GMagicResourceInfo` builds a SpellResource (`sub_5B8540`), and heal and
  water work the same way (`sub_5B94B0`, `sub_5B8590`).
- **The hand's own gestures** are fields of `DETAIL_SPELL_SYSTEM_INFO`:
  +16 = 14, +20 = 1, +24 = 2, +48 = 15.
- **Over a spell icon**, the hand asks for the gesture at seed +268 (`sub_58FC40`).

## Casting (so far)

What v1.0 does once a seed is in the hand:

1. The held seed (`SpellSeed`, made from the spell icon: `sub_6BED50` ->
   `sub_6BEAA0`) casts at a position or at an object (`sub_6C00D0` / `sub_6BFF60`).
2. That goes through the magic info: `sub_5B8DB0` / `sub_5B8D20`, then the info's
   vslot 13 to make the Spell, then the Spell's vslot 333 or 334 to start it.
3. The Spell starts a particle effect (`sub_636B40`). Each particle that lands reports
   to the spell (vslot 331).
4. A resource spell (`SpellResource`, `sub_6BBBF0`) then drops its resource there:
   the first drop is big, the later ones small. The mana it costs is the drop times
   info +104.
5. The drop (`sub_618E10`) first goes to whatever nearby takes it: a storage pit takes
   anything, a pile its own kind, within 1.2 x the object's radius, searching the 3 x 3
   cells around the point. What's left becomes a MagicFood or MagicWood pile
   (`sub_5B8230`).

| Miracle | Resource | First drop | Later drops |
|---|---|---|---|
| Food (magic 15) | food | 200 | 20 |
| Wood (magic 21) | wood | 500 | 20 |

Translated in `SpellCast.cpp`: finding a spell's magic info, the drop amount, and the
drop into nearby stores. `test_level` casts both on the village's storage pit and the
pit gains exactly that.

The magic info offsets are read 4 bytes earlier than v1.0's code reads them. This is
inferred from the values (it makes the food-or-wood field 0 or 1), and the MAGIC_*
loader path is not yet walked to prove it.

## Effects: heal

Spells other than the resource ones act through the base Spell's landing handler
(`sub_6B7E70`), which applies the magic type's effect where each particle lands:

- **The effect record** is the type's entry in `DETAIL_MAGIC_EFFECT_INFO` (284 bytes,
  indexed by magic type). It holds seven values at +16..+40 and a radius at +44
  (`sub_4FC630`), all scaled by the spell's strength (`sub_4FCA90`).
- **Who it reaches** (`sub_4FC660`): everything around the point that takes effects
  (vslot 477; a heal reaches only the living) and lies within its own radius plus the
  effect's.
- **On a living thing** (vslot 371, `sub_5E9DD0`):
  - Values [1] and [2] wound, each times the target's defence multiplier from its info
    (+144..+168, vslot 370; `sub_5EA150`).
  - Value [3] heals, times multiplier [2] (`sub_5EA1D0`, from the disassembly).
- **Heal's record** is [3] = 1 over 2 m. Water's is [0] = -4000 over 1 m (likely
  cooling), and fire's direct values are zero: its damage comes another way.

`test_level` draws spiral + Heal and casts on a villager at 0.3 life, which rises to
1.0.

## In the viewer

In play mode (`bw_viewer game_data/Land1.txt --play`), the hand works miracles:

- **Hold the middle mouse button** and draw a spiral, then release.
- **Draw the miracle's gesture** the same way (Food 3, Wood 6, and so on; see the table
  above). The HUD's "Miracle:" line says what the hand holds.
- **Left-click** to cast it under the hand. Food and wood land in a storage pit there;
  Heal heals the living within its radius; other miracles say they are not translated yet.

`viewer/miracles.cpp` is the glue. `test_level` drives it headlessly: it draws the
spiral and Food's gesture as mouse strokes and casts on the village's pit, which gains
200 food.

Simplified:
- Every miracle counts as known (Land 1 has no worship-site icons yet).
- A stroke is matched when the button comes up. v1.0 matches every frame and starts
  the trail again after each match.
- A cast is one landing, so one first drop.

Not yet: the hand's other gesture modes (power-ups, cancelling, the creature's
gestures), the spell's particle effect, piles where no store takes the drop, and the
other miracles' effects.
