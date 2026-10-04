# Fire

v1.0 simulates heat. The code is `src/core/Fire.cpp` (`black/Fire.h`); `test_level`
checks it.

## A fire is a temperature

A `FireEffect` (80 bytes, `sub_6C4E30`) hangs on an object at +0x44:

| Offset | Field |
|---|---|
| +0x14 | temperature |
| +0x18 | last turn's temperature |
| +0x1C | the object |
| +0x20 | the player who started it |
| +0x34 | smoke |
| +0x38 | flags |

Fires sit on the game's fire list (+0x201CD0) and are ticked in rotating groups
(`sub_6C6A30`).

The air is 24.7 everywhere (`sub_5C18C0`). An object's materials come from its info:

| Field | Info offset | Notes |
|---|---|---|
| Ignition point | +180 | at least 40 (`sub_6C6470`); 0 means it never burns |
| Heat capacity | +176 | at least 1 (vslot 377) |
| Burn rate | +144 | |
| Hottest it gets | | twice the ignition point |

On Land 1:

| Object | Capacity | Ignition | Burn rate |
|---|---|---|---|
| Hut | 2000 | 150 | 0.01 |
| Town centre | 4000 | 200 | 0.01 |
| Villager | 82.5 | 120 | 0.5 |
| Field | 100 | 100 | 0.1 |
| Tree | 1000 | 110 | 0.01 |
| Animal | 30 | 140 | 0.2 |
| Fish farm | 50000 | 9999 | 0 |

## Each turn (`sub_6C52A0`)

- **Out.** A fire within 0.1 of the air with no smoke is gone.
- **Burning and dry:** heats by 0.1 x T / capacity, up to the hottest it gets.
- **Otherwise it cools:** first to at least the air, then, unless it rose since the
  last turn, by (T + 10 - air) x cooling x 0.1 x wet / capacity. Wet is 50 in water
  (below 2 m) and more in rain. Cooling is the object's height x radius x 4
  (`sub_6C64F0`). This step was read from the disassembly.
- **Above ignition** it takes (T - ignition) / (hottest - ignition) x burn rate x 0.1
  of the object's life a turn (`ReduceLifeDueToBurning`). Smoke builds as life falls
  below 0.6.
- **It heats its neighbours** (`sub_6C5C70`). It reaches 1.25 x its radius x how
  fiercely it burns (`sub_6C66C0`). A neighbour cooler than it, within reach, gets
  10 x the difference in heat, capped at half the fire's own heat above the air, and
  catches when it passes its ignition point. A fire that is not itself burning loses
  what it gives.

## Heat from spells

A spell effect's value [0] is heat (`sub_6C6940`, called from the wound reader
`sub_5EA150`). It adds 10 x (air + heat - T) / capacity, but never more than that
difference. The Fire miracle's heat comes from the fireballs its particle effect
throws (`AttatchFireBallToAtom`), so it waits on the particle system. Water's effect
is -4000, which puts fires out.

`test_level` heats a hut with 40 hits of 1000. It catches at 207 degrees, burns from
life 1.00 to 0.96 over 100 turns, and goes out under a Water miracle cast on it (the
spell rains for about 60 turns; see `docs/gestures.md`).

## Not yet

- Water and rain at the spot (the climate does not exist).
- Mesh heights (the radius stands in).
- The rotating tick groups (every fire ticks every turn).
- Deaths by fire and towns' emergencies.
- Sparks, smoke and sounds.
- The fireballs themselves.
