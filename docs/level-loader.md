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

## What each handler does

- **CREATE_TOWN** `(id, "x,z", player, _, tribe)`: a `Town` with the id at +0x5B4, tribe
  at +0x5B8 and player number at +0x5BC. Those are the offsets `sub_6CD070` writes, and
  our header has them.
- **CREATE_ABODE** `(town, "x,z", type, angle×1000, scale×1000, food, wood)`: the town by
  id, else the nearest town (`sub_5256C0`, then `sub_525710`). The class follows the
  record's `abodeType`, as `sub_401BA0` does. Food and wood are added, then the abode
  joins the town. **CREATE_TOWN_CENTRE** also becomes the town's centre if it has none.
- **CREATE_VILLAGER_POS** `("x,z", "home x,z", type, age)`: the home is the abode whose
  cell holds the home position (integer parts of x and z), searched across every town.
  The original refuses when the villager list (+0xA4) has reached `maxAdults`
  (+0x174), children included. Land 1: 27 villagers name a real abode and 24 get in;
  the other three are the third occupant of a two-adult hut. 28 name a spot with no
  abode and stay homeless in the original as well.
- **SET_TOWN_BELIEF**, **SET_TOWN_UNINHABITABLE** (+0x5F4 = 1, which makes
  `AddVillagerToTown` refuse everyone), **START_CAMERA_POS**, **LOAD_LANDSCAPE**,
  **SET_LAND_NUMBER**, **VERSION**.

## Not translated yet

Land 1 has 2,342 commands. 1,966 are handled; `test_level` lists the rest. The largest
groups are stream points (187), drink waypoints (47), firefly reward odds (42), flocks
(16), mist (17), and planned abodes and the citadel (7). Known departures from the
original:

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
24 housed villagers and info on all 1,946 objects, then runs 100 turns.
