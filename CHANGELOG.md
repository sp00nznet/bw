# Changelog

Format: [Keep a Changelog](https://keepachangelog.com/). No tagged releases yet;
history before this file lives in the README's batch log and `git log`.

## Unreleased

### Fixed
- A finished abode was re-added to its town's abode list (`Abode::Built` ->
  `MakeFunctional`), turning the list into a cycle; v1.0's `Built` only counts it.

### Added
- Building (`docs/town-economy.md`): villagers join a town's building sites, bring
  wood from the store or a big forest, and build, until the building is finished and
  counted in its town. To_Build desire comes from the sites' remaining work.
- Planned buildings and the town planner (`docs/town-economy.md`): `CREATE_PLANNED_ABODE`
  plans go on their towns' lists; the Abodes desire has the town start the abode it
  wants most, which becomes an unbuilt abode with a building site.
- The wood job (`docs/villager-states.md`): big forests from the land script, each
  town's forest list, and villagers taking wood from the nearest forest to the store.
- Farming (`docs/villager-states.md`): fields belong to their town's field list, plant
  up, grow on one turn in ten, and are dug up when full-grown; the food job weighs them
  against fish farms.
- The food job and fishing (`docs/villager-states.md`): the Food desire sends villagers
  to the town's fish farms; they fish and take the catch to the storage pit. Fish
  farms and fields go on their towns' lists as v1.0's constructors put them.
- Villager upkeep, eating and death (`docs/villager-states.md`): food drains each
  turn, hunger costs life and sends villagers to their home or the town's storage
  pit to eat, tired villagers go home, children grow up, and old age or starvation
  kills. A game year is 1,500 turns, read from `GGameInfo`'s constructor; ages now
  count in years.
- Villagers run (`docs/villager-states.md`). This is v1.0's living pass and villager
  tick, with the decision core: town emergencies, homeless villagers moving in, work
  offered from the town's desires, sleep, and idling. The home and sleep states and
  the chill states are in, plus the game's own random generator. Before this, nothing
  ticked villagers at all.
- The town tick in v1.0's shape (`docs/town-economy.md`): the 17 desires, and abodes
  run, worn and counted by their town.
- The v1.0 constructors for towns, abodes and villagers, and v1.0 housing: towns get
  identity, belief caps and desire weights; abodes join their town with an index and
  look for drinking water (the original's spiral cell search); villagers get age,
  scale, food, life and a starting state, and are housed through the original's
  abode/town/homeless links. Land 1 houses 31 of 55. See `docs/constructors.md`.
- The game's own level loader (`LevelLoader`): land scripts build a bw_core world of towns
  with their abodes, housed villagers, fields and fish farms, plus trees, animals,
  features and mobile objects, each with its `info.dat` record. Play mode draws that
  world, and the turn runs towns and then objects (`level::Process`). Land 1: 1,966 of
  2,342 commands handled. See `docs/level-loader.md`. `test_level`.
- `test_chl`: the shipped challenge script loads and runs 100 ticks, timed.
- `info.dat` loader (`InfoDat`): all 102 sections of v1.0's balance data, rebuilt in the
  original in-memory shape, plus a generated layout (`InfoDatLayout.gen.h`). See
  `docs/info-dat.md`.
- Objects created by `EntityFactory` carry their info record: abodes, villagers, trees,
  mobile statics and features, from level-script names or CHL info enums.
- `test_infodat` (layout, shipped-file anchors, all 1,218 Land1-5 type names resolve) and
  `test_spawn` (Land 1's 1,853 entities spawn headless).
- `tools/run_tests.cmd`: runs every test exe and fails on any failure (netlab's QA for bw).

### Fixed
- `VILLAGER_STATES` used v1.41-era numbers for 47 states (85 as DECIDE_WHAT_TO_DO). It is
  now v1.0's 256 states (chlasm's `GStates.h`, matching the binary's state table).
- `Town` and `Villager` used the vendor's v1.41 layouts. v1.0's constructors put Town
  at 0xF20 (no `forests` pair at 0x608) and Villager at 0x128 (home +0x120, town
  +0x124). Both headers now match, with `offsetof` asserts on the constructor's offsets.
- `Town::GetRadius` returned `influence`; it is now v1.0's bounding-box half-size.
- Map scale: everything outside the translated game code converted metres to map units at
  65536 per metre. The original uses 6553.6 (10/65536, `0x3727C5AC`, as `GUtils` already
  had), so a cell is 10 m. At our scale, cell indices ran to about 2,600 on a 512-cell map,
  and every distance, radius and speed the translated code computes was 10x off. One
  definition now (`kMapUnitsPerMetre`, `MapCoordsFromMetres`, `MetresOf` in `types.h`).
  Land 1 now houses 29 villagers at the original's cell granularity, up from 24.
- The CHL loader hung forever on the shipped `Challenge.chl`, misreading each script's
  `var_offset` as its variable count, so the viewer never opened a window and no story
  script ever ran. It now parses version 7 to the last byte, refuses anything else, and
  addresses variables the way the code does (one id space; `docs/chl-format.md`).
- `Field` read its town from +0x118 but set it at +0x98, so fields never knew their town.
- Entities were `calloc`'d, so they had no vtable, and the first virtual call
  (`SetPos`) crashed. That took the viewer down on the first spawned abode, before
  this change too. Entities and flocks are now constructed with `new`.
- Save field offsets were `uint16_t`; GFootpathFinder's last five (up to 409,796, the
  object is 0x640C8) were truncated. MSVC only warned; clang-cl refused. The type was
  already refused as inexact, so no wrong bytes were written. The test's 0x20000
  ceiling that the truncation hid is now the largest real object.
- `tools/run_tests.cmd` counted a test that never started (exit 0xC0000135, a missing
  DLL) as passing; any non-zero exit now fails.
- LHVM spawns that passed a tribe, reward or highlight type in `type_enum` no longer
  have it read as an info index.

### Changed
- Static CRT: the exes no longer need the VC++ redistributable on the machine.
- Builds and QA run on recomp-netlab (`netlab check bw --on testbox`); see README.
- Raw decompiler output, address lists and RTTI/vtable maps are no longer tracked
  (`work/decomp/`, `work/decompiled/`); the scripts that produce them are.
- The `info.dat` "later build" theory is refuted: the v1.2 patch expects our exact
  v1.0 `info.dat` and exe.
