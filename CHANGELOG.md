# Changelog

Format: [Keep a Changelog](https://keepachangelog.com/). No tagged releases yet;
history before this file lives in the README's batch log and `git log`.

## Unreleased

### Fixed
- BUILD_BUILDING popped an object and set its build fraction. v1.0's takes a position and
  a desire.
- CREATURE_LEARN_EVERYTHING and CREATURE_LEARN_EVERYTHING_EXCLUDING now teach the
  creature's brain, as v1.0's do (sub_4635C0, sub_68F310). The second popped its
  creature and mode in the wrong order.
- LOAD_CREATURE and LOAD_MY_CREATURE took the wrong arguments and pushed a result
  v1.0's do not (sub_696F00: type, mind file, player, position; sub_696E70: position).
  The creature now gets the mind file the script names and its species.
- Fish farms were never put into the map (an empty stub). They now go on their
  cell's fixed list, as v1.0's do.
- An action stopped while the creature pointed left the point clip held for good, so
  every later action waited on it.
- The feature map walked a cell's mobile list by the wrong link.
- Pot amounts were at +0x6C; v1.0's are at +0x70. A pile's add, remove and get were
  stubs returning 0, and PileWood reported food as its resource.
- The level stocked abodes through JustAddResource, where v1.0 calls AddResource,
  so a storage pit's piles were bypassed.
- `GMap::ToMap` indexed the cells [z][x]; v1.0's are x-major (`sub_5BFA00`).
- The desire model labelled `sub_4BEB30` the per-turn update. It is the player-feedback
  path; the per-turn update is `sub_4BE5B0`, now translated. The mind file's
  "unidentified" floats per desire are value, maximum and cycle time.
- Six objects' creature belief types (`GetCreatureBeliefType`), Creature's among them
  (0x16; v1.0 says 8), and Flock's compassion predicate. They are now checked against
  the binary with the rest. A creature now spawns where it is created (its `coords`
  were never set).
- Seventeen of the creature predicates our classes answered differently from v1.0
  (Field could be stomped, examined and pooed on; villagers could be befriended; five
  creature predicates were missing; Rock and Bonfire faulted). `test_chooser` now checks
  all 637 constant answers across twelve classes against the binary.
- A finished abode was re-added to its town's abode list (`Abode::Built` ->
  `MakeFunctional`), turning the list into a cycle; v1.0's `Built` only counts it.

### Added
- Worship sites. The finished CitadelHeart (sub_4503D0) gives each of the player's towns
  its tribe's worship site in the citadel (sub_450320, sub_44EBE0). The town's villagers
  then build it. See docs/players.md.
- The player's citadel. CREATE_PLANNED_CITADEL plans it on the village. BUILD_BUILDING,
  which Land 1's opening calls at that spot, now builds the planned building there, as
  v1.0's does (sub_6D11E0). For the citadel plan, that makes the player's Citadel and an
  unbuilt CitadelHeart, which the village's villagers then build. See docs/players.md.

- Players, with v1.0's 632-byte layout (the vendor's v1.41 GPlayer is 0x828 bytes
  larger). Level loads set up player 0 human and 7 neutral. Towns and loaded
  creatures belong to their players. A creature with a player points at its hand
  (PointAtHand, sub_4977F0). See docs/players.md.
- Player feedback, as v1.0's (sub_4C2090). A stroke or slap teaches the creature about
  its most relevant recent action: the action's opinion, the desire behind it, and its
  opinion of what it acted on. Viewer keys G and B stroke and slap the creature nearest
  the hand.
- Creatures learn by watching, as v1.0's do (sub_4C3AD0, sub_4BA660): abilities from
  what villagers are doing, gated by stage and prerequisites. A grown ape learns to
  fish by watching fishermen.
- HowlAtFriend (315) runs as v1.0's sub-actions. It was the last action creatures
  reached that still finished on arrival.
- Creature development stages (info.dat DETAIL_CREATURE_DEVELOPMENT) switch desires
  on and off, as v1.0's do: sub_4ACB00 for a new or loaded creature (LOAD_CREATURE
  sets 13), and SET_CREATURE_DEV_STAGE (sub_68EBD0) for the story's steps.
- Action 161, the creature's rest, runs as v1.0's sub-actions.
- A creature with no mind file gets a fresh mind for its species, as a new creature
  does: the species' desire tables, nothing learned, no abilities or spells known.
  Viewer creatures without a named mind get one instead of Khazar's.
- In play mode, creatures made by scripts get a brain and act on their own. The debug
  key C makes one at the hand. Brains see the viewer's camera.
- A creature with a brain (`creature::AttachBrain`) runs from `level::Process`: its
  ProcessState ticks the brain over what the map's cells hold within 600 m.
- Villagers, animals and creatures link into the map cell under them, as v1.0's do,
  and are relinked as they walk from cell to cell.
- Storage pits keep their stock in pile objects, as v1.0's do: one food pile and five
  wood piles, with the pot infos' capacities.
- EatFromStoragePit runs as v1.0's sub-actions: a handful of 1000 × size taken from
  the pit's food pile and eaten.
- The game's map (`g_map`) is built at each level load, so fixed objects are in its
  cells.
- The creature's feature map now has its town, forest and citadel blocks.
- Two more creature actions run as v1.0's sub-actions: GoToHillAndWalkAlongRidge and
  TakeFishFromSeaToHome, with the Discard sub-action. `CreatureBrain::StartAction`
  and `RunSubActions` are public, so a host can run an action it chose itself.
- The creature's feature map (`black/LandFeatures.h`, v1.0's `CreatureGlobalExplorationMap`):
  - per 8 × 8-cell block, its highest cell and its coast, water, hill and land bits;
  - the spiral search for the nearest block of a kind.
  It is built from a new host hook for cell altitude (`g_cell_altitude_func`).
- Four more creature actions run as v1.0's sub-actions:
  - SitDownOnBeach, DrinkFromTheSea and WaveAtPlayer;
  - EatAfterExamining, with the HeldObjectAction and Drink sub-actions.
  A creature's height is now 15 × its 3D size.
- EatAlive (action 11) runs as v1.0's sub-actions: Pickup, then Eat.
  - What fits in a creature's hand is translated: `CanCreatureEatMe`,
    `CanBePickedUpByCreature` and `sub_4C4E00`.
  - The creature's radius, weight and reach are read off its 3D object. Without one,
    the reach is 0.
- Villagers, animals and creatures are put in the map when created (`sub_5E8CA0`),
  so `IsObjectInMap_0` holds for them.
- PointAtCamera (action 168) runs as v1.0's sub-actions: face the camera, then point
  at it for 1 s. The host gives the brain the camera's position.
- Four more creature actions run as v1.0's sub-actions: LookAtSun, PointAtHand,
  CommunicateState and HangAroundAtHome. Seven more sub-actions: turning to face a
  point or the camera, pointing, communicating, waiting, and static and individual
  clips.
- FishAndEat now runs as v1.0's sub-actions, step by step (`docs/creature-chooser.md`):
  - The action's handler queues them, and the sub-action runner (`sub_4DE180`) steps
    through them.
  - Each takes turns: walking to the farm, conjuring a fish, picking it up, eating it.
  - Digesting the fish lowers hunger by what it gave in energy.

  Clip lengths are placeholders until core loads the creature's animations.
- What finishing an action does (`docs/creature-chooser.md`):
  - v1.0's eat step: food over growth into energy, the reserve and poo.
  - The action-done routine: costs, the desire's factor, source resets and the
    per-desire countdowns.
  - The sub-action table (158 named sub-actions with their step handlers), recovered
    by emulation.

  A hungry Khazar's fish is now worth exactly what v1.0 says.
- A creature's body and the desires it drives (`docs/creature-chooser.md`):
  - v1.0's body tick: energy, reserve, exhaustion, dehydration, temperature, growth.
  - The per-turn desire system, with sources computed from the body and pushed
    through the sigmoid.
  - The mind file's stage and saved body.

  A starved Khazar's hunger rises by itself on Land 1 until he goes and eats.
- Creature action validity (`docs/creature-chooser.md`): all 47 of v1.0's
  "can I do this now" predicates for the 112 actions that have one, translated and
  wired into `CreatureBrain` (life, home, stage, desires, spell charge, recent actions).
- A creature in the world (`docs/creature-chooser.md`): `CreatureBrain` runs the agenda
  over the objects a creature can see, with the objects' own predicates, the mind's
  opinion trees and known lists, and walks to its plan. On Land 1, Khazar's shipped
  mind, made hungry, walks to the nearest fish farm and fishes.
- The creature's agenda (`docs/creature-chooser.md`): v1.0's per-turn loop. It
  rebuilds each desire's plan, scores it, and switches to a plan that scores twice as
  well. From shipped data, Khazar's innate lesson makes a hungry Khazar choose to eat
  a villager alive.
- The mind file past the desires (`docs/creature-chooser.md`): learning episodes (two
  trees per desire), per-action words, and the known abilities and spells that the
  plan chooser checks. Every shipped mind holds one episode; the story creatures know
  no spells.
- The creature's plan chooser (`docs/creature-chooser.md`): v1.0's desire pickers,
  candidate actions, scores and completeness test, on info.dat's action and desire
  tables. Its object predicates call the target's own virtuals, by the slot the
  binary uses. Both runtime predicate tables were recovered by emulating their initialisers
  (`work/gen_chooser_dispatch.py`). Action record +168 is the action's desire.
- The spell particle files (`docs/psys-files.md`): all 132 `ZSpellFiles/SF_*_txt.zzz`
  graphs load (our own inflate, then the property text). Earlier notes said these
  were not in the data; they are.
- Spells that last (`docs/gestures.md`): a spell ages and stops past its duration, and
  Water rains for it, a drop a turn, enough to put out a burning hut.
- Fire (`docs/fire.md`): v1.0's heat simulation. Objects catch above their ignition
  point, burn their life away and heat their neighbours; spell effects carry heat in
  value [0], so Water's effect puts fires out.
- The Water miracle (`docs/gestures.md`): a field it falls on is planted full or grown
  (v1.0's `Field::ApplyWaterSpell`).
- The Heal miracle (`docs/gestures.md`): a spell's effect record, its area, and the
  heal and wound applied to the living, cast from the viewer's hand.
- Miracles in the viewer (`docs/gestures.md`): hold the middle mouse button to draw a
  spiral and then a miracle's gesture, and left-click to cast. Food and wood land in a
  storage pit under the hand.
- Resource miracles' drops (`docs/gestures.md`): food and wood miracles' drop amounts
  from their magic info, and the drop into a nearby storage pit.
- Choosing miracles by gesture (`docs/gestures.md`): v1.0's selection at a worship
  site. A spiral, then each spell's own gesture, chooses that spell; this works for
  all 23 spells with a sequence in the data.
- The gesture recognizer (`docs/gestures.md`): v1.0's stroke trail with corner
  detection, and turn-by-turn matching against the 81 templates in `Gestures.jty`,
  mirrored and size-banded where the template allows. `test_gesture`: 76 of 81
  templates drawn as mouse strokes are recognised as their own gesture.
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
