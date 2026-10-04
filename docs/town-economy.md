# The town economy

How a town runs each turn in v1.0, and how much of that is translated. The source of truth
is the v1.0 binary; offsets are v1.0's.

## The turn

`GPlayer::ProcessPlayers` (`sub_5F7950`) runs each player's `Process` (`sub_5F7440`). That
walks the player's towns (head at player +616, next at town +0x754) and calls
**`Town::Process` (`sub_6D8EB0`)** on each. We walk every town instead; every town belongs
to some player slot, neutral included, so the effect is the same. `level::Process` runs
the towns, then every object that isn't a town's abode, then advances `g_game_turn`.

`Town::Process`, in the original's order:

| Step | v1.0 | Status |
|---|---|---|
| clear +0x5E4 | | done |
| drop finished entries from the list at +0x788 | `sub_4344F0` | not yet |
| influence = TownInfo +120 | `sub_6D2810` | done (mode 0) |
| every TownInfo +76 turns, each abode's `Process`; add its influence | `sub_6D9120` | done |
| × the game influence multiplier, if the town has a player | | not yet (no players) |
| **the 17 desires** | `TownDesire::Process` `sub_6D7950` | done, see below |
| list at +0x98C; every 10 turns `sub_6DA400`; dead villagers off +0x768; the object at +0xE9C; process list +0x770; desire flags; interaction multipliers; `sub_6D9860`, `sub_6D92C0`, `sub_6D59C0` | | not yet |
| the two objects at +0x5F8/+0x5FC, the list at +0x994 | | not yet |
| belief (`sub_4310A0`), the +0xF18 countdown, the influence map | | not yet |
| every TownInfo +360 turns (staggered by id × 20) | `sub_6D3E70` | not yet |

**Abodes are run by their town, not by the global object loop** (`sub_6D9120`).
`Abode::Process` (vslot 383, `sub_4031C0`) wears down an empty functional abode: 0.001 per
call, and `emptyAbodeLifeReducer` of life per whole unit. The old sketch took the full
reduction on every call. `Abode::GetInfluence` (`sub_4058B0`) is
(occupants + 1) × built × scale × life × info influence. In Land 1 the village's
influence is TownInfo's 25.0 plus 375.6 from its abodes.

## The 17 desires

The table at `0xCC3F60` (17 × 104 bytes, our `GTownDesireFunction`) names each desire and
holds its functions. It is `.bss`, filled by an inlined initialiser at `0x6D6A40` that IDA
never made a function. `work/emulate_init.py` rebuilt it by emulating that code's register
loads and stores; the run ends exactly on its `ret`.

```
desire[k] = clamp(raw_k(town) × tribe_weight_k × multiplier_k(town, k), -1, 1)
```

`tribe_weight_k` is `DETAIL_TOWN_DESIRE_INFO[k]` at +88 + 4 × tribe. Everyone else reads a
desire as desire + boost + cheat (`sub_6D1080`). The TownDesire arrays are named from
v1.0's own debug dump (`sub_6D7630`, which labels them `DesireCheat`, `DesireBoost`,
`Desire`, `RawDesire`, `VillagerStateAmount`, `VillagerStateCount`).

| # | Desire | raw (+16) | multiplier (+80) |
|---|---|---|---|
| 0 | Food | 1 − available ÷ needed (`sub_6D9980`) | food coming in vs needed |
| 1 | Wood | wood stock vs two need levels, plus forester disciples and the building desires (`sub_6D9A70`) | wood coming in vs needed |
| 2 | Playtime | 0.1 after turn 4000, when no basic desire passes its threshold | villagers on it |
| 3 / 4 | Protection / Mercy | town +0xEB8 / +0xEB4 | villagers on it |
| 5 | Abodes | crowding⁴, damped by Civic and To_Build | villagers on it |
| 6 | Civic_Buildings | for each abode number the town lacks, past its `populationWhenNeeded` | villagers on it |
| 8 | For_Children | food, room, safety; halved without a working creche | villagers on it |
| 9 | To_Build | building-site progress | builders on sites |
| 12 | Repair_Town | abodes' repair desire | villagers on it |
| 14 | For_Wonder | town belief in its player × (1 − basics) | villagers on it |
| 15 / 16 | Relaxation / Sleep | time of day | villagers on it |
| 7, 10, 11, 13 | Supply_Worship, For_Rain, For_Sun, Supply_Workshop | 0 in v1.0 (`sub_6DA0C0`) | |

**Food and wood available** (`sub_6D9590` / `sub_6D9600`) = what villagers are carrying
(stats +0xF8 / +0xFC +0x100) plus the storage pit. **Food needed** (`sub_6D95F0`) =
TownInfo +220 × the town's summed per-villager food (+0x6EC). `TownStats::AddVillager`
accumulates that from villager info +728. One villager carries 150 food or 250 wood
(`dword_CC9F4C` / `CC9F50`, villager info +612 / +616, the same for every type).

### What the stats need: `TownStats::AddAbode`

The desires read the town's capacity and what civic buildings it has. v1.0 fills those
when an abode is counted (`sub_6DAF60`, from vslot 581 `sub_4034C0` once the abode is
built): adult and child room, homes, civic count, and a byte per abode number at stats
+0x108 (town +0x710). A storage pit's vslot 581 also makes it the town's store
(`Town::SetStoragePit`, `sub_6D16B0`). The loader now activates each built abode after
its resources, as `sub_401BA0` → `sub_401EB0` does.

Land 1's Norse village: the script stocks its pit with 20,000 food and 30,000 wood
against a need of 12,025, so Food and Wood are 0. 15 adults with room for 37 gives
Abodes 0.027. For_Children is 0.5: there is no working creche, which halves it.

**Not yet:**
- To_Build and its multiplier: there are no building sites yet
- For_Wonder and For_Children's player factors: no players yet
- Protection/Mercy: their source, the interaction sums (`sub_6D0BA0`)
- Relaxation/Sleep: the game clock (`flt_B201CC`). Noon stands in.
- the +32/+48 have/want counts for Abodes, Civic and Worship: Civic's are read raw, the
  others are not translated
- the advisor's every-50-turns commentary

## Planned buildings and the planner

`CREATE_PLANNED_ABODE` (land-script case 8) makes a PlannedAbode, a 76-byte ghost
holding the abode record, place, angle and scale. It goes at the tail of the town's
planned list (+0x9A0, `sub_6CFFB0`). Land 1 plans a Norse wonder for the village, and
three huts, a shack and a wonder for town 4.

The Abodes desire's handler (`sub_6E8290`) first tries to join a building site. When it
can't, and once a turn per town (+0x5E4, cleared by `Town::Process`), it asks the
planner for an abode (`sub_6CE790(2)`):

1. The planner (`sub_6CD990`) takes the planned building, of a type with bit 2, that
   the town wants most (`sub_6CD9F0`, read from the disassembly). For an abode (type 2):
   - spare = room for adults (TownStats +0x4C) minus the homeless (+0x764);
     need = a tenth of the town, plus one.
   - Spare room above need: no want. Spare room between 0 and need: the base want
     (info +276).
   - More homeless than room: the base plus the shortfall over need (at most 0.8),
     times 0.6 + a term for how many homeless one hut would take.
   - Then less for each one the town already has (TownStats byte table +0x108), and
     shared among sites already building the same type.
2. The chosen plan becomes an abode at its place with nothing built (`sub_6CEA40` ->
   `sub_403E80` -> `sub_401BA0`). The abode joins the town, and the plan is removed.
3. The abode gets its StandardBuildingSite (vslot 309, `sub_505740` / `sub_433FE0`),
   which goes on the town's site list (+0x788, `sub_6CEAF0`).

Land 1's towns have room to spare, so nothing is started at first, as in v1.0.
`test_level` takes town 4's spare room away and the planner starts a hut.

## Building

Two desires send villagers to building sites: Abodes (`sub_6E8290`, above) and
To_Build (`sub_6E8780`). To_Build's raw value (`sub_6DA070`) is the sum, at most 1, of
each site's remaining work.

- **Choosing a site** (`sub_6CFE90`): the nearest, by distance x (0.9 x remaining +
  0.1). Remaining work (`sub_434560`) is the builders the site still wants, over info
  +272. A site that wants no more builders is only open to builder disciples.
- **Wood or build** (`sub_6E7B70`): a villager within 50 m of the building fetches wood
  only when the site's pile is empty. Further out it weighs the site against the store
  (`sub_434D30`, read from the disassembly). Wood comes from the store when the store
  holds more than the villager can carry (state 39, then 184), else from the nearest
  big forest.
- **Building**: the villager walks to one of 128 positions round the building (40). It
  puts its wood on the site's pile, then works (41). Each stroke takes villager info
  +636 wood from the pile and adds it to the building as a share of the building's
  cost (info +108 x scale). Then it moves on 2-3 m round the building, or goes for
  more wood when the pile is empty.
- Builders join and leave the site's list through the building states' enter and exit
  slots (`sub_434630` / `sub_434680`). A second count at site +0x634 moves with that
  list, and "builders wanted" is info +272 minus that count.
- At 100% the building is Built (`sub_403430`) and counted in its town's stats.

In `test_level`, town 4's forced hut is finished in 3,187 turns by up to 4 builders.

Fixed: `Abode::Built` called `MakeFunctional`, which re-adds the abode to its town's
list. The abode is already there, so the list became a cycle and the next walk of it
never ended. v1.0's `Built` does not do this.

Not yet: clearing obstacles off a site (`sub_6E84F0`, state 185), trees as a wood
source for building, build positions from the mesh outline (a circle at the building's
radius stands in), the site's pile as a Pot object, the other types' planner scoring,
the land check, and TownStats' planned/site counts.
