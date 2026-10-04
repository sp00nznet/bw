# Constructors

The level loader (docs/level-loader.md) creates towns, abodes and villagers. This page
covers how far each of those constructors is translated from v1.0.

**What a translation has to do.** Most of a v1.0 constructor clears fields and sets
vtable pointers. `new T()` already does both: the classes have no user-declared
constructors, so value-initialisation zeroes every field and sets the vptrs. A
translation writes what is left, the **non-zero state and the side effects**.

**Layouts first.** Our class headers came from the vendor's v1.41 reconstruction.
Where v1.0's code disagrees, the header changes to v1.0, and `offsetof` asserts pin the
offsets the constructor writes.

## Town (`sub_6CD070`)

### The layout was v1.41

v1.0 allocates 3,872 bytes (0xF20); our `Town` was 0xF28. The constructor pins the
difference. v1.0 has no `forests` / `field_0x60c` pair at 0x608: TownStats' vtable is
written there (`this[386]`). Removing those 8 bytes shifts everything after them into
v1.0's place:

| v1.0 write | Field | Offset |
|---|---|---|
| `this[386] = &TownStats::vftable` | `stats` | 0x608 |
| `this[456] = this[457] = 0x7FFFFFFF` (`sub_6CE1E0`) | bounding-box min | 0x720 |
| `this[467]` list head, `this[468]++` (`sub_6CD6B0`) | `abode_list` | 0x74C |
| next town in a player's list | `next` | 0x754 |
| `this[484] = &GBelief::vftable` | `belief` | 0x790 |
| `CREATE_TOWN_CENTRE` writes `+2460` | `town_centre` | 0x99C |
| 17 desire objects, `this[618..634]` | `town_desire_flags` | 0x9A8 |
| 8 × `sub_6D0D20`, 128 bytes each | `player_interactions` | 0x9EC |
| `this[939] = this[940] = 1.0f` | `field_0xeb4/eb8` | 0xEAC |
| `memset(this + 944, 0, 64)` | `field_0xec8[16]` | 0xEC0 |
| `SET_TOWN_CONGREGATION_POS` writes `+3848` | `congregation_pos` | 0xF08 |

There is one further difference: the two dwords v1.41 keeps before
`player_interactions`, v1.0 keeps after it. `Town.h` asserts all 18 offsets and the
0xF20 size. Field names keep their v1.41 numbers; the comments give the v1.0 offsets.

### `Town::Construct`

What it writes:
- **Container:** info, position and owner.
- **Desire:** `desire.town = this`.
- **Interaction records:** each gets `+0x10 = 1.0`, and its `EffectValues` effect 5
  = 1.0.
- **Multipliers:** the pair at 0xEAC = 1.0.
- **Belief:** caps 10.0 per player, 41 reaction multipliers 1.0, and each town desire's
  weight copied from `DETAIL_TOWN_DESIRE_INFO` (+0x3C of each element, `sub_430B70`).
- **Identity:** id, name, tribe and player number.
- **From TownInfo:** influence = TownInfo +120 (`sub_6D2810`), +0x5D8 = TownInfo +184,
  and +0x5DC = 1.0.

`AddStructureToTown` follows v1.0's `sub_6CD6B0`: link the abode (+0x9C) at +0x74C,
count at +0x750, then `SetTown`, then recompute the bounds. The bounds are the min/max
of each abode's position ± its radius (`sub_6CE380`). `GetRadius` (vslot 24,
`sub_6D0540`, read from the disassembly because Hex-Rays dropped the subtraction) is
half the larger whole-metre side of that box.

An abode's radius is its mesh's larger horizontal bound times its scale (`sub_5EA550`).
The mesh is `GAbodeInfo::meshId` at +0x15C, the same ids as the viewer's hand table
(Norse Hut 204, Town Centre 179). bw_core has no meshes, so the host answers through
`g_mesh_radius_func`, like terrain height. A `Field` is a flat 5 m (`sub_502D00`).

Land 1, headless with 6 m meshes: the player's 34-abode village has a 127 m radius.
Town 1 has 562 m, and that is real: the script puts one of its two huts 1.1 km from
the other.

**Not yet translated:**
- the 17 desire-flag objects (`sub_6D05E0` → `sub_6D8950`, a 152-byte object class)
- hooking the town to its player (`sub_6CDFF0`: the player's town list and spell
  icons; this needs real `GPlayer`s)
- the map-region flag at +0x5E0 (`sub_6FE660`)
- the game-mode index that picks influence from TownInfo +188 + 4n
- the second half of `sub_6CE1E0`, a bounding sphere

## Abode (`sub_401F10` → `sub_401220`)

The layout already matched v1.0 (0xC4). The constructor's `drinking_water` (+0x80) and
`index` (+0xB8) writes land on the fields of those names.

- **Object (`sub_5E8A80`):** position at +0x14 and +0x2C, info, life 1.0, scale 1.0,
  then angle and scale from the create's arguments (`sub_5EB580` / `sub_5EB520`). The
  factory already did these. New: each object takes the next value of a game-wide
  serial counter (+0x3C).
- **MultiMapFixed (`sub_5044E0`):** a built (not planned) structure sets
  `percent_built` = 1.0 and +0x58 bit 3. The factory already did that.
- **Abode, the town half (`Abode::JoinTown`):**
  - joins the town (`sub_6CD6B0`, above) and takes `index` = the town's count − 1
  - `sub_405680(200)`: looks for drinking water within 200 m, and records in bit 0 of
    +0x7C whether it found any. It tries stream points first (`sub_6C9D10`). Every
    abode in Land 1 is created before the first `CREATE_STREAM`, so there the cell
    search decides (`sub_6DED30`).
  - **The cell search** is a square spiral out from the abode. Each step moves one cell
    east, north, west or south, the run growing every second turn. The direction table
    is `.bss` at `0xCC6694`, filled by an inlined initialiser IDA never made a function;
    it was decoded from the raw bytes at `0x6DDD90`
    (`mov cx,1; xor ax,ax; mov [CC6694],cx; ...`). The walk stops at the first water
    cell, or at the first cell farther than 200 m; corners come first, so in practice
    it stops nearer 140 m. A water cell has flag `0x20` set and `0x10` clear
    (`sub_5BFBF0`). The host serves the flags from the `.lnd` (`g_cell_flags_func`,
    `LandscapeCellFlags`), using the same block grid the original indexes.

Land 1: 7 of 57 abodes have water within reach.

**Not yet translated:**
- slot 406 (`sub_401F80`): the abode's 3D object and transform, which is the viewer's
  job here
- the post-create `sub_401EB0`: resources through vslot 39, then two more virtual
  checks. The loader adds food and wood directly instead.
- `sub_402B80`, which creates door/footpath objects
- the +0x24 category bit (`sub_5EC8B0`)

## Villager (`sub_6DFF00` → `sub_6DFC80`, Living `sub_5AAAE0`)

### The layout was v1.41

v1.0 allocates 296 bytes (0x128); ours was 0x130. In v1.0, `GetTown` (vslot 18,
`sub_706D30`) returns `this[73]` and the home is `this[72]` (`sub_6E1CE0`). So +0x120
is the **home** and +0x124 is the **town**. Our header had `football` at 0x120, two
extra dwords, and `home` at 0x12C. `Villager` is now 0x128 with `home` and `town`
where v1.0 keeps them. `GetTown` returns the town directly, and `SetTown` is no longer
a stub. `Living` already matched v1.0: `birth_turn` 0xA0, the global-list link 0xA4,
and its end at 0xE0.

### `Villager::Construct`

- **From Living:** speed from info +260, +0x9C = info +300, life = info +296, and a
  starting birth turn from info +308.
- **Age (`SetAge`, `sub_6E23C0`):** below the adult age (info +312) the child bit is
  set (+0xE0 bit 3, the same bit `IsChild` reads at vslot 701). Otherwise the age is at
  least 18. It also sets the **scale** (`sub_6DFEA0` / `sub_6E2590`): adults land in
  [0.95, 1.05); children grow from a per-age table at info +740.
- **Starting values:** food = info +704 + rand(0.6), capped at 1.
  `turns_until_next_state_change` = rand(500) + 1.
- **Starting state:** a villager on a deep-water cell starts DROWNING (16); otherwise
  DECIDE_WHAT_TO_DO (85). The test is cell flag 0x10 (`sub_5BFB00`). That also
  explains the drinking-water test: 0x20 means water, 0x10 means deep.
- **Sex** is info +504 (0 male). That replaces a guessed bit in `IsMaleVillager`.

### Housing, as v1.0 links it

- **`Abode::AddVillagerToAbode` (`sub_402DE0`):** take the villager off its town's
  homeless list or its old home. Link it onto the abode's list (head +0xA0, count
  +0xA4, link villager +0xE4), set home and town, and join the town if it is a new
  one. Then count it: children +0xB7; adults +0xB4, the first of each sex into
  `male_female_villagers`, and males +0xB5.
- **`RemoveAliveVillagerFromAbode` (`sub_4030C0`):** the reverse.
- **`Town::AddVillagerToTown` (`sub_6CD8E0`):** refused while uninhabitable. Counted in
  `TownStats::AddVillager` (`sub_6DABD0`: adults/children, per sex, carried food and
  wood, disciples). A home in another town is left. Then the best abode with space
  takes the villager, or it becomes homeless here.
- **`FindAbodeWithSpaceInTown` (`sub_6CE7D0` / score `sub_403670`):** score = room left
  for its kind × how few of its sex live there × nearness on a 500 m scale.
- **`BecomeHomeless` (`sub_6EFD50`):** onto the town's homeless list (+0x760, a count
  beside it).
- **The loader's `CREATE_VILLAGER_POS` (case 18):** the abode in the home cell, unless
  full (villager list = maxAdults). Otherwise the town's best abode with space,
  otherwise homeless in that town.

Land 1: **31 of 55 villagers housed** (29 before): two whose named home was full now
go to another abode in the same town, as the original does.

**Not yet translated:**
- **The game's random generator** (`sub_67BC90` / `sub_67BCB0`). A fixed-seed one
  stands in, so exact starting values differ.
- **The length of a game year** (`dword_C22D44`). It is `.bss`, set at runtime by code
  we have not found: only reads reference it directly. Ages convert to birth turns at
  1 turn per year until it is recovered. Nothing ages yet, so nothing depends on it.
- the villager's 3D object and textures
- the game-wide homeless list
- the stats' homeless counters (`sub_6DADF0`)
- `FindAbodeWithSpace`'s second test (vslot 548)
- the exact distance falloff (`sub_6DF670`)
