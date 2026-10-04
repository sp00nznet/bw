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
