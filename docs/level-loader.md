# The level loader

`src/core/LevelLoader.cpp` reads a land script (`Land1.txt` …) and builds the world in
bw_core: towns, their abodes and villagers, fields, fish farms, trees, animals,
features. In play mode the viewer draws what it built and the turn processes it
(`level::Process`). The viewer's own parser (`script_parser.cpp`) is now used only by the
read-only world view.

## Where it comes from

The game has a table of 105 level commands at `0xB44048`. Each 16-byte record is a name
pointer plus a 12-character argument signature (`N` int, `F` float, `A`/`L` string).
`sub_6AD5E0` switches on the command's index; each case is one handler. IDA shows no
xrefs to the name strings (an inlined initialiser), so the table was found by searching
the image for the string's address as a raw pointer. The dumps are
`work/decomp/level_loader.txt` and `level_cmds.txt` (gitignored; regenerate them with
`tools/decomp`).

The handlers index the info arrays directly, and every base and stride matches
`info.dat`'s recovered layout (docs/info-dat.md):

| Command | Info record | Original create |
|---|---|---|
| `CREATE_ABODE`, `CREATE_TOWN_CENTRE` | `456 * idx + 0xB5DF50` (abode) | `sub_401BA0`, a switch on `abodeType` |
| `CREATE_VILLAGER_POS` | `932 * idx + 0xCC7880` (villager) | `sub_6DFF00` |
| `CREATE_NEW_TREE` | `320 * idx + 0xCC4770` (tree) | `sub_6DB4F0` |
| `CREATE_MOBILE_STATIC` | `300 * idx + 0xC5B5E0` | `sub_5C3710` |
| `CREATE_MOBILEOBJECT` | `276 * idx + 0xC59350` | `sub_5C24E0` |
| `CREATE_NEW_FEATURE` | `292 * idx + 0xBEAD00` | `sub_4FE1A0` |
| `CREATE_NEW_ANIMAL` | `716 * idx + 0xB6E8F0` | `sub_416240` |
| `CREATE_NEW_TOWN_FIELD` | `340 * idx + 0xBF03D0` (field type) | `sub_4FEE50` |
| `CREATE_TOWN_FISH_FARM` | `296 * idx + 0xBF0FD8` | `sub_502C80` |
| `CREATE_TOWN` | `DETAIL_TOWN_INFO[0]` | `sub_6CD070` |
| `CREATE_DEAD_TREE` | `320 * idx + 0xCC4770` (tree) | `sub_4EE200` → `sub_4EE080` (160 bytes) |
| `CREATE_BONFIRE` | `0xC5BF40`, MOBILE_STATIC_INFO[8] "Bonfire" | `sub_432250` → `sub_432150` (152 bytes) |
| `CREATE_STREET_LANTERN` | `300 * idx + 0xC5B5E0` (mobile static) | `sub_6CA4E0` (100 bytes) |
| `CREATE_ANIMATED_STATIC` | `300 * idx + 0xB765F0`, by name (`sub_41D0E0`) | `sub_41CB70` (152 bytes, made whole) |
| `CREATE_POT` | `324 * idx + 0xC6D400` (pot) | `sub_616C40`, only when its amount (arg 3) is positive |

## What each handler does

- **CREATE_TOWN** `(id, "x,z", player, _, tribe)`: a `Town` with the id at +0x5B4, tribe
  at +0x5B8 and player number at +0x5BC. Those are the offsets `sub_6CD070` writes, and
  our header has them.
- **CREATE_ABODE** `(town, "x,z", type, angle×1000, scale×1000, food, wood)`: the town by
  id, else the nearest town (`sub_5256C0`, then `sub_525710`). The class follows the
  record's `abodeType`, as `sub_401BA0` does. Food and wood are added, then the abode
  joins the town. **CREATE_TOWN_CENTRE** also becomes the town's centre if it has none.
- **CREATE_VILLAGER_POS** `("x,z", "home x,z", type, age)`: the home is the abode in the
  same map cell as the home position (`coords >> 16`, so a 10 m cell), searched across
  every town. The original refuses when the villager list (+0xA4) has reached
  `maxAdults` (+0x174), children included. Land 1: 34 villagers name a cell holding an
  abode and 29 get in; the other 5 find it full. 21 name a cell with no abode and stay
  homeless in the original as well.
- **The statics** (cases 38, 43, 73, 80, 87):
  - The loader keeps int arguments at +24576 + 4i and floats at +24624 + 4i.
  - **CREATE_DEAD_TREE** `("x,z", player, tree type, scale, x, y, z angles)`: angles and
    scale through vslot 326.
  - **CREATE_BONFIRE** `("x,z", f, angle, scale)`: its first float is passed and not used.
  - **CREATE_STREET_LANTERN** `("x,z", type)`: none within 0.5 m of another.
  - **CREATE_ANIMATED_STATIC** `("x,z", name, angle×1000, scale×1000)`.
  - **CREATE_POT** `("x,z", type, _, amount)`: makes nothing when the amount is not
    positive. Land 1's four all give 0.

  Land 1 makes 4 animated statics, 3 dead trees, 2 bonfires and 12 lanterns. Not kept:
  - the bonfire's 25 m light (`sub_5EFC40`);
  - the dead tree's player;
  - the game's animated-static list (+2104696).

  Our Bonfire header is 0x94 where v1.0's is 152 bytes. The viewer draws animated
  statics from their record's mesh (+0x120). Mobile-static records hold −1 at the +0x100
  that `MobileStatic::GetMesh` reads, so bonfires and lanterns are not drawn yet.
- **CREATE_FLOCK** (case 49, `sub_5058F0`): `(id, pos, centre, radius, radius 2, town)`
  from script version 2.1 (before that the fifth argument is the town and radius 2 is
  30). The flock is made at `pos`, then its domain centre (`sub_505CF0`, which also
  sends the last member there) and radii (+0x50, 0 meaning 80; +0x52) are set, and the
  town puts it on its list at +0xF00. **CREATE_NEW_ANIMAL**'s third argument is the
  flock's id (+0x8C); the animal joins it (`sub_505B20`: a 12-byte node, ordered by the
  member's +0xD4 byte, and the living's +0xB8 points back), and an age of 0 becomes
  5..24. The animal's town (`sub_414480`) is not set yet.
- **FIRE_FLY_SPELL_REWARD_PROB** (case 88, `sub_501E50`): a magic type by name and its
  odds, into a 42-float table (0xBF0F0C) with a running total (0xBF0E64). A firefly
  (`sub_501F10`) rolls below the total and takes the first type whose running total
  reaches the roll; `PickFireFlyReward` does that, the reward seed it then makes is not
  translated. Land 1 has no fireflies; its odds are Heal 20 and six others 1.
- **CREATE_WEATHER_CLIMATE** (case 60, `sub_6FE4B0`): `(id, type, pos, radius, radius)`.
  Id 0 replaces the default climate (`sub_6FE1D0`: record 0, 5000 m); any other id
  is a `GClimate` of DETAIL_CLIMATE_INFO[type] at pos with its radii in order.
  **…_RAIN / _TEMP / _WIND** (61..63) set +0x34 (float, int, int, byte), +0x44 (two
  floats) and +0x4C (three floats) on the climate of that id. The constructors'
  season-dependent defaults and the weather state are not translated.
- **CREATE_STREAM** / **CREATE_STREAM_POINT** (cases 66/67, `sub_6C9B30` / `sub_6C9C00`):
  a `GStream` on the game's list (newest first) and its points in order, in metres at
  the land's height, added to every stream of that id. Streams are drinking water:
  `sub_6DEDF0` (the abode's search, `sub_405680`) takes the nearest stream point
  within range (`sub_6C9D10`, 2D) and then any water cell nearer than it.
- **CREATE_MIST** (case 0, `sub_5C1980`): `(pos, height, colour, scale, f)`. A `Mist`
  on the game's list with its scale (+0x2C), ARGB colour (+0x30) and fifth argument
  (+0x34); the height is above the land. **CREATE_ARENA** (case 69, `sub_41EF60`):
  `(pos, radius)`, a `GArena` on its list whose `GetRadius` (vslot 24, `sub_41EFF0`)
  is the radius at +0x30. Neither's vslot-320 creation call is made, nor the arena's
  villager reaction (`sub_67EFC0`, type 19).
- v1.0's `MapCoords` y is the height above the land (a stream point is stored as land
  height + y); ours carry the altitude itself, so the loader adds the land's height.
- **CREATE_CITADEL** (case 19, `sub_44EAF0`): `(pos, heart type, player, angle×1000,
  scale×1000)`. A new citadel for the player (`sub_44E400`) and its heart, whole, at
  scale 1 (the fifth argument is not read), which raises the citadel's power by 125 and
  starts its worship sites (`sub_450320`). `NewCitadel` / `NewCitadelHeart` are shared
  with the planned heart. The land check (`sub_5BFD80`) and the players' refresh
  (`sub_59BBC0`) are not translated.
- **CREATE_WORSHIP_SITE** (case 22, `sub_4504D0`): only the player and tribe are used.
  The citadel's site for the tribe (`sub_44EAD0`) takes the player's town of that tribe
  and, if the town is building it, is finished (vslot 576, `BuildBy(1)`) and the
  building site removed; with no such town it is finished anyway.
- **CREATE_FOREST** (case 26, `sub_50E200`): a `Forest` with that id (0: the next
  number) on the game's forest list; **CREATE_NEW_TREE**'s first argument is the id of
  its forest (−1 for none), and the tree's +0x68 points at it. The forest's own tree
  lists are not filled yet.
- **CREATE_TOWN_VILLAGER** (case 16): `(town, pos, type, age)`, a villager like
  CREATE_VILLAGER_POS's, taken in by the town of that id or else the nearest
  (`sub_525710`) through `AddVillagerToTown` (`sub_6CD8E0`).
- **SET_TOWN_BELIEF_CAP** (case 4, `sub_4316D0`): the belief cap (+0x68) for a player,
  stored as given (Land 3 uses 2.0), the current belief untouched.
  **SET_TOWN_CONGREGATION_POS** (case 6): town +0xF08.
  **TOWN_DESIRE_BOOST** (case 86): `desire.boost[i]` (town +0x108), the desire named
  from v1.0's table at 0xCC3F60 (Food, Wood, Playtime, Protection, Mercy, Abodes,
  Civic_Buildings, Supply_Worship, For_Children, To_Build, For_Rain, For_Sun,
  Repair_Town, Suppy_Workshop — the misspelling is the game's).
- **SET_GLOBAL_LAND_BALANCE** (case 93): `g_land_balance[i]` (0xC3B390).
  **SET_NIGHTTIME** (case 102, `sub_528F70`): day length, night and dusk shares, clamped;
  the light ramp is not built. **TOGGLE_COMPUTER_PLAYER** (case 77) acts on the player's
  computer player (+0x15C), which we never make, so it changes nothing.
- **SET_TOWN_BELIEF**, **SET_TOWN_UNINHABITABLE** (+0x5F4 = 1, which makes
  `AddVillagerToTown` refuse everyone), **START_CAMERA_POS**, **LOAD_LANDSCAPE**,
  **SET_LAND_NUMBER**, **VERSION**.

## Not translated yet

Land 1 has 2,342 commands and all of them are handled; `test_level` lists any that
are not. Known departures from the original:

- **The creates are not the original's constructors.** The objects are our classes,
  built with `new`, with the arguments set that the handler passes. The constructor and
  `Init` chains of `sub_6CD070`, `sub_401F10` and `sub_6DFC80` are not translated.
- `CREATE_MOBILE_STATIC`'s five floats are read as scale (arg 2) and angle (arg 4), the
  way the viewer always read them; `sub_5C3710`'s own use of them is not translated.
- All animals are the `Animal` class. The 17 species subclasses wait on their virtuals.
- Our header names the town centre slot at 0x9A4. v1.0 keeps it at 0x99C.
- `Field` kept its town at +0x118 (`GetTown`) but inherited a setter that wrote +0x98,
  so a field never knew its town. It now overrides `SetTown`.

`test_level` loads Land 1, checks the six towns, 57 abodes owned by their towns,
29 housed villagers and info on all 1,946 objects, then runs 100 turns.
