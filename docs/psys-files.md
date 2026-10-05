# Spell particle files

Every spell's particle effect ships as data: `game_data/ZSpellFiles/SF_*_txt.zzz`,
132 files. Our earlier notes said no effect graphs were reachable from the data set,
because we had looked for `.psy` files. They are these. The loader is
`src/core/SpellFile.cpp` (`black/SpellFile.h`), checked by `test_psysfile`.

## Format

- A file is a 4-byte little-endian size, then a zlib stream that inflates to exactly
  that many bytes of text. The loader carries its own inflate, for stored, fixed and
  dynamic Huffman blocks.
- The text opens with header properties: `DeleteOnCloseDown`, `Hierarchies` and
  `InitiallyCreated` (arrays of 25, one per group), and `MaxSpellAge`.
- Then come blocks:

```
BEGINCLASS <Type> <Name>
BEGINPROPERTIES
PROPERTY <Name> <TYPE> <value ...>
ENDPROPERTIES
ENDCLASS
```

Property types: BOOL, INTEGER, FLOAT, STRING, PERSIS_PNTR (another object's name, or
NULL_STRING), ARRAY (`SIZE n` then n values), SOUND_ACTION, ENUM.

A rule belongs to one of the 25 groups (`Group`). Emitters send what they make into
others (`NextGroups`), and rules refer to creators and conditions by name.

## What is there

The 132 files hold 1,630 objects of 135 classes. The commonest are:

| Class | Count |
|---|---|
| ParticleSpriteCreator | 137 |
| CreateRuleAnAtom | 131 |
| ParticlePointCreator | 120 |
| AR_FadeAlpha | 92 |
| RemoveRuleOldAgeOnly | 80 |
| UR_ChangeScale | 73 |
| UpdateRuleGravity | 58 |

**Food** (`SF_Food`) is 13 objects:
- `UR_HandSprinkle` raises the hand over 4 s and sprinkles grains from group 0 into
  group 1. Its rate follows the keypoints 0 / 1 / 1 / 0 at 0, 0.2, 0.8 and 1 of the
  time.
- In group 1, `UpdateRuleGravity` (15) makes the grains fall.
- `LandscapeCollide` with `SendEvent` reports each landing. That landing is the event a
  resource spell answers with a drop (SpellResource vslot 331).

**Wood** is the same with wood meshes. **Heal** (`SF_HealChakra`) is a
`UR_HealSpellChakra` with a fused spherical explode. **Fire**
(`SF_FireBallThrow`) is 49 objects, including the `AttatchFireBallToAtom` that makes
its fireballs.

## How Food's grains are made (read from the binary)

The three rules Food depends on are translated as far as reading them goes:

- **`UR_HandSprinkle`** (vtable 0x872374, Apply `sub_6469D0`) does not make the grains.
  It keeps a source atom on the hand and sets its velocity from the hand's height
  (plus `InitSpeedYHumanPlayerCasting` for a human caster). It also starts the hand's
  raise animation (`sub_576C80`: `HeightToRaise`, `AngleToRaise`, `TotalTime`).
- **`UR_WillowWisp`** in group 1 makes the grains. It emits one each time its parent
  atom (the hand's) moves `EmitDueToMovingDist` (2.5), at most `MaxAtoms` (36) at a
  time. So the food a miracle gives depends on how the hand moves while casting:
  the in-game "shake to sprinkle".
- **`UpdateRuleGravity`** (ApplyToAtom `sub_647AE0`) damps the velocity by
  `1 - dt x Damping`, pulls it down by `clamp(vy + Gravity... ) x MaxSpeed x mass x dt`,
  and moves the atom by it.
- **`LandscapeCollide`** (ApplyToAtom `sub_626480`) fires a type-3 event at an atom
  below the land, if `SendEvent` is set, then removes the atom. That event is the
  landing a resource spell answers with a drop.

Faithful delivery therefore needs the hand's path during the cast and its raise
animation, not only the graph runtime.

## Next

To run a graph:
- the effect's 25 groups and their rules, and the classes the spells use;
- the hand's casting motion as the source of the Food and Wood grains;
- landing events routed to the spell.
