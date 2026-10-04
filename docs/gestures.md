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

## What the gestures mean

- **Power-up gestures.** A spell seed (`DETAIL_SPELL_SEEDS`, the table at 0xCBE310)
  offers up to three stages: magic types at +296..+304 and their power-up gestures at
  +308..+316 (`sub_58F820`). On Land 1's data these are gestures 1 and 2, the big
  spirals.
- **Magic types.** These index the MAGIC_* info sections laid end to end: 0-9
  general, 10-11 heal, 12 teleport, 13 forest, 14-15 food, 16-18 storm, 19-20 shield,
  21 wood, 22-23 water, 24-25 flocks, 26-41 creature spells. Each record's first field
  is its own type, which confirms the order.
- **The hand's own gestures** are fields of `DETAIL_SPELL_SYSTEM_INFO`:
  +16 = 14, +20 = 1, +24 = 2, +48 = 15.
- **Spell icons.** A seed's +268 is the gesture asked for over a spell icon
  (`sub_58FC40` -> `sub_6C0500`).

Not yet: the hand side. That covers capturing the mouse into the trail, choosing which
gestures to ask for from what the hand holds or is over (`sub_58FC40` and its
helpers), and casting the spell that results.
