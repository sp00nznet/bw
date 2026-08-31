# Black & White Static Recompilation — Project Memory

## Standing Directive
Push completed work to GitHub. Entity hierarchy is complete — focus on translating
Ghidra decompilations and wiring game systems.

## Project Overview
Static recompilation of Black & White (2001) — rebuilding the original x86 binary as clean C++ from decompiled vendor reference material (bw1-decomp).

## Key Paths
- **Git repo root**: `G:/recomp/pc/bw`
- **Source root**: `G:/recomp/pc/bw/src`
- **Headers**: `G:/recomp/pc/bw/src/include/black/`
- **Implementations**: `G:/recomp/pc/bw/src/core/`
- **Vendor reference**: `G:/recomp/pc/bw/vendor/bw1-decomp/black/` (569 decompiled struct headers)
- **CMakeLists.txt**: `G:/recomp/pc/bw/src/CMakeLists.txt`

## Build System
```bash
cd /g/recomp/pc/bw/src
cmake -G "Visual Studio 17 2022" -A Win32 -S . -B build
cmake --build build --config Release
```
- Visual Studio 2022, 32-bit x86 Release
- Static library target: `bw_core`
- Must build clean with zero errors before committing

## Current Stats (as of commit 7abd58b, 2026-06-05)
- **601 headers** in `src/include/black/`
- **254 .cpp files** in `src/core/`
- **17 viewer modules** (loaders, audio, animation, save, helptext, sad, psys_fx, kjmp2, tests)
- **~50,500 lines** of C++ total (core + viewer)
- **252 commits**, all pushed to GitHub

### Session 2026-06-04/05 (Phases 5–8 + decompiler pipeline)
- **MP2 voice decoder** (5A) — BW voice is WAVE_FORMAT_MPEG tag 0x0050 = Layer II
  (NOT MP3); vendored kjmp2, decode-and-cache in sad_loader. `test_mp2` proves it.
- **Billboard particle FX** (5B scope-B) — `psys_fx` replaces placeholder spell
  rings; per-family emitters. (Faithful 128-class Atom/Rule port = scope-A later.)
- **Tolerant bone remap** (6A) — BW L3D/ANM have NO bone names; index-overlap
  remap over a bind-pose base, requires ≥half-skeleton coverage.
- **Person-only gestures** (6B) — villager PLAY_GESTURE restricted to M_P_* clips.
- **Hand phase state machine** (6C-pragmatic) — fixed GET_HAND_STATE (was 5, HOLDING=4).
- **SET_HEADING_AND_SPEED** (Phase 8) — real movement on living units via
  MobileWallHug goal+speed+MOVE_TO_POS; safe AsLivingMover() downcast gate.
- **Decompiler pipeline** (`tools/decomp/`) — binary has RTTI but NO symbol table
  (17,627 funcs, 5 named) → class methods only reachable via RTTI vftable walk,
  not by name. IDA idalib `bw_decomp.py` validated (primary); Ghidra script ready
  but project needs RTTI analyzer re-run. See [[decompiler-tool-locations]].
- **Phase 7 foundation** — GameOSFile serializer + GameThing Save/Load translated
  from decomp, verified by `test_save`. Save/Load/GetSaveType = vtable slots
  58/59/60 in GameThing AND all descendants. Per-leaf fan-out + driver remain.
- **~100% coverage** of 569 vendor types (entity hierarchy complete)
- **0 TODO comments remaining** — all stubs documented with descriptive comments
- **Ghidra headless pipeline operational**
- **Save/load: 91 of 178 save types exact** — table-driven, generated from the binary
- **bw_viewer links bw_core** — dual entity system with state sync
- **LHVM: 464/465 typed natives (100%)** — only NONE stub remaining
- **LHVM bindings: ~430 natives wired with real bodies** (LHVMObjects.cpp, 8 chunks, ~3,900 lines)
- **LHVM ↔ Object handle table** — script handles ↔ Object* with EntityFactory integration
- **Hand/click input wired to LHVM** — GET_HAND_*, GAME_THING_CLICKED, POSITION_CLICKED real
- **Spawn renderer bridge** — CHL CREATE/FLOCK_CREATE/etc. spawn entities visible in viewer
- **Sim-rate throttling** — game ticks at BW's 10 Hz independent of render fps
- **HUD overlay** — Consolas bitmap font, turn/entity/dialogue/library counters, F1 toggle
- **Animation pipeline operational** — L3D bind-pose refactor + full openblack-compatible
  ANM decoder (single + Pack archive) + procedural fallback + keyframe lerp + PLAY_GESTURE wiring
- **SAD audio bank decoder** — LionHead Pack format, samples extracted with HELP_TEXT keys,
  PCM playback via PlaySoundA(SND_MEMORY), MPEG fallback to MessageBeep
- **HelpText subtitle pipeline** — humanized HELP_TEXT_* keys keyed by sample id
- **Slot-based save/load** — BWSV format, F5/F9 hotkeys, SAVE_GAME_IN_SLOT wired
- **Camera follow** — viewer camera tracks LHVM FOCUS_FOLLOW / POSITION_FOLLOW with shake
- **Physics impact** — thrown objects fire Object::ReactToPhysicsImpact on neighbours
- **Villager state machine: IMPLEMENTED** — ProcessState with 30+ states + movement
- **Creature AI: IMPLEMENTED** — ProcessState + EntityFactory spawning
- **Movement system: IMPLEMENTED** — MobileWallHug goal-seeking + arrival
- **Resource gathering loop: IMPLEMENTED** — food/wood pick → storage pit → deposit
- **CHL scripts load and execute** in the viewer game loop

## Architecture Patterns

### Class Hierarchy (vtable-correct)
```
Base (0x4, vftable only)
├── GameThing (0xFC, 56 virtuals at offsets 0x04-0xF8)
│   ├── GameThingWithPos (0x78+, extends with position/map fields)
│   │   ├── Object (0xCC+, adds Process/Init/Click/Draw virtuals)
│   │   │   ├── MultiMapFixed → Abode, CitadelPart, Feature, etc.
│   │   │   ├── SingleMapFixed → Rock, Bonfire, Tree, etc.
│   │   │   ├── Mobile → MobileWallHug → Living → Villager/Animal/Creature
│   │   │   └── MobileObject → Pot, Scaffold, Arrow, etc.
│   │   ├── GCamera (extends GameThingWithPos, NOT Object)
│   │   └── Spell hierarchy (extends GameThingWithPos, NOT Object)
│   ├── BuildingSite (extends GameThing with 12 NEW virtuals at 0xFC+)
│   ├── Container → Citadel, Flock, Forest
│   └── Utility types (GFootpath, ShowNeeds, FireEffect, etc.)
├── GAlignment, GBelief, TownStats, TownDesire (non-positional)
└── CameraMode (separate vtable hierarchy, 18 virtuals, NOT related to GameThing)
```

### Key Design Rules
1. **Virtual methods must match original vtable order exactly** — this is MSVC ABI compatibility
2. **Vendor headers use C structs** — we translate to C++ classes with proper virtual methods
3. **Suffixed method names**: When vendor has overloads, Ghidra names them `Method_0(args)`, `Method_1()` — preserve these exact names
4. **static_assert on every struct size** — e.g., `static_assert(sizeof(Abode) == 0xFC, "Abode size mismatch")`
5. **Forward-declare enums**: `enum ABODE_TYPE : uint32_t;` to avoid pulling in massive enum headers
6. **LHLinkedList pattern**: Per-type 8-byte structs `{ T* first; T* last; }` to avoid ODR issues
7. **Info structs use `void* vftable`** — flat C data, not C++ virtual inheritance
8. **Enum array sizing**: Use literal numbers computed from struct offsets, not enum constants
9. **Method stubs**: Return 0/nullptr/default for now — bodies come later from Ghidra decompilation

### Git Workflow
- Stage specific files (never `git add -A`)
- Commit with descriptive message + `Co-Authored-By: Claude Opus 4.6 <noreply@anthropic.com>`
- Push after each batch
- Batch size: 4-15 types per commit, grouped by subsystem

## What's Been Implemented (by batch)

### Batches 1-12 (prior sessions)
Core hierarchy through all leaf entity types — Base, GameThing, GameThingWithPos, Object, all Fixed/Mobile/Living derivatives, all animal species, containers, basic utility types.

### Batch 13: Spell subclass hierarchy (12 types)
SpellHeal, SpellForest, SpellResource, SpellCreature, SpellWater, SpellStormAndTornado, SpellShield, SpellTeleport, SpellFlock, SpellFlockFlying, SpellFlockGround, PlannedMultiMapFixed

### Batch 14: Info data struct hierarchy (15 header-only types)
GBaseInfo, GObjectInfo, GMultiMapFixedInfo, GSingleMapFixedInfo, GAbodeInfo, GFeatureInfo, GMagicInfo, GTribeInfo, GContainerInfo, GMobileObjectInfo, GAnimalInfo, GVillagerInfo, GCreatureInfo + vendor-level forward decls

### Batch 15: Building entity method stubs (6 types)
Replaced minimal placeholders with properly addressed stubs for CitadelPart, Creche, Wonder, StoragePit, Workshop, TownCentre

### Batch 16: Town system infrastructure (8 types)
GTownDesireInfo (0x90), GTownInfo (0x18C), Temple (0x54), GTownDesireFunction (0x68), TownStats (0x118), TownDesire (0x564), TownSpellIcon (0x118), TownCentreSpellIcon (0x128)

### Batch 17: BuildingSite hierarchy (4 types)
BuildingSite (0x644, 12 new virtuals), StandardBuildingSite (0x648), CitadelBuildingSite (0x644), WorkshopBuildingSite (0x644)

### Batch 18: WorshipSite family (5 types)
GCitadelPartInfo (0x134), GWorshipSiteInfo (0x160), WorshipSpellIcon (0x140), WorshipTotem (0x104), WorshipSite (0x128)

### Batch 19: Camera system core (3 types)
Zoomer (0x30) + Zoomer3d (0x90) header-only, CameraMode (0x8, 18 virtuals), GCamera (0x1D8)

### Batch 20: CameraMode subclasses (12 header-only types)
CameraModeFree (0x18), CameraModeFollow (0x48), + 10 trivial 0x8-byte camera mode variants

### Batch 21: Town class + prerequisites (3 types)
EffectValues (0x40) header-only, PlayerTownInteract (0x80) inline, Town (0xF28, 30 virtual overrides + 35 non-virtual methods), GBelief methods updated

### Batch 22: Player system (2 types)
GPlayer (0xA60, 7 virtual overrides + 12 non-virtual methods + 3 static), GPlayerInfo (0x90) header-only, LH3DColor moved to types.h

### Batch 23-25: Creature belief/info types (21 types)
7 creature info types (all 0x10 GBaseInfo), CreatureBelief (0x4C) + 10 subclasses, CreatureBeliefList (0x14), AllocatedBeliefList (0x18), CreatureBeliefs (0x270)

### Batch 26-31: Creature AI subsystem (42 types)
Full mental model hierarchy: CreatureDesires (0x708), CreatureAgenda (0x1AF8), CreatureLearning (0x16168), CreatureAttitudeToPlayer (0x1DB4), CreatureExplorationMap (0x2018), DecisionTreeCollection (0x140), Attribute base + 23 subclasses, AttributeTest (0x94), CreaturePlan (0x30) + CreaturePlanState (0x830), CreatureContext (0x70), CreatureMental (0x20D40 — 135KB mega struct)

### Batch 32: CreatureInfo chain + subsystem deps (8 types)
GMobileWallHugInfo (0x120), GLivingInfo (0x1F4), CreatureInfo (0x394), GCreaturePenInfo (0x134), CreatureCommandState (0x2C), CreatureMimicState (0x3C), CreatureSubAction (0x60) + CreatureSubActionAgenda (0xC50)

### Batch 33: Creature peripherals + dependencies (17 types)
CreaturePhysical (0x74) + CreatureDamageMap (0x10), CreatureHelpState (0x98), CreatureCommand (0x8), CreatureReceiveSpell (0x1D8), Prss (0x10, 7 virtuals), CreatureSelect (0x10), MultiplayerDatabase (0x10, 2 virtuals), CreatureDatabase (0x10), CreaturePen (0x8C), SubArgument (0x4, 4 virtuals) + 3 subclasses, SecretCreature (0x4), DifferentCreatureInfo + TownCreatureInfo + GMagicCreatureSpellInfo + LESSON_TYPE enum

### Batch 34: Hand state system + entity info types (33 types)
HandState (0x8, 5 virtuals) + 11 subclasses (Invisible/Normal/Camera/Tug/Holding/Totem/MultiPickUp/Creature/Grain/PlayAnim/Citadel), 21 info types (GAlignmentInfo, GAnimatedStaticInfo, GArrowInfo, GBallInfo, GBigForestInfo, GCitadelHeartInfo, GCitadelInfo, GFieldInfo, GFlowersInfo, GPFootballInfo, GForestInfo, GFurnitureInfo, GPrayerIconInfo, GPrayerSiteInfo, GRewardInfo, GScaffoldInfo, GFishFarmInfo, GWorshipSiteUpgradeInfo, GSpotVisualInfo, etc.)

### Batch 35: Magic info hierarchy + data info types (23 types)
GEffectInfo (0x34), GMagicEffectInfo (0x11C), 13 magic spell info types (GMagicFireBallInfo through GMagicWaterInfo), GBeliefInfo, GClimateInfo, GClimateRainInfo, GSpecialVillagerInfo (0x60), GVillagerInfo (0x3A4), HelpSpiritInfo (0x1F4)

### Batch 36: LHVM scripting engine + utility types (3 types)
LHVM bytecode interpreter (CHL file loader + 31-opcode VM), GUtils (static distance/angle utility class), MaterialProperties (0x5)

### Batch 37: LHVM native function dispatch (464 functions)
Complete native function dispatch table — NativeFunction enum (0-463), NativeFunctionEntry dispatch table, OP_CALL dispatch, stack ops with current_task context, ~50 typed stubs (camera, property, object, math, time, text, fade, etc.), remaining functions as no-op stubs

### Batch 38: Creature spawning + Town simulation + Abode resources
Creature::Create factory (calloc + InitCreature, allocates 135KB CreatureMental), Town::Process 7-phase simulation tick, Abode::JustAddResource/JustRemoveResource with clamping, StoragePit resource delegation

### Batch 39-40: Method body pass — systems, map ops, state machines (13 commits)
GCamera: Update loop, Validate, SetPointFromPointDistanceHeadingAndPitch, GetHeadingAndPitchFromPoints
Living: 20+ state queries (Dying/Dead/InHand/Downed/etc.), SetState/StorePreviousState, IsDead, MoveByTeleport
Object: ReduceLife/IncreaseLife (clamped), Set/Get angle methods, GetDistanceFromObject_1, GetTopPos
GGame: GetNextPlayer iteration, GetPlayerFromReal, GetPlayerInterfaceFromReal
GPlayer: ProcessPlayers loop, Process with town delegation, GetPlayerNumber, IsMagicTypeEnabled
Villager: 13 non-virtual methods (GetTown, GetHome, resource mgmt, food, pregnancy)
BuildingSite: GetBuilding/GetRootBuilding, delegation chain (GetTown/GetRadius/BuildBy)
Town: GetRadius, GetOrigin, GetNumberOfInstanceForGlobalList, GetTribe, GetStoragePit
GBelief: GetBeliefInPlayer/SetBelief with bounds checking and cap clamping
TownStats: IncrementNumOfDisciples/DecrementNumOfDisciples
WorshipSite: IsBuilt, Built, GetArrivePos, GetTotemPos, GetNumVillagersRequestingToGoHome
GameThingWithPos: GetDistanceFromObject (Euclidean XZ), GetHeight
Flock: SetDomainCentrePos
Field: IsFieldWithFoodInIt
StoragePit/TownCentre: GetArrivePos via GetDoorPos

SingleMapFixed: InsertMapObject/RemoveMapObject (cell linked list management)
MobileWallHug: MoveTo3D horizontal step, SetTowardsAngle
Villager: IsMaleVillager/IsFemaleVillager, AmILikelyToMove
Workshop/WorshipSite/Abode: Process delegation (building site when under construction)
Town: SetBeliefInPlayer, SetWorshipPercentage
LHVM: RANDOM/RANDOM_ULONG/SQUARE_ROOT math implementations

### Batch 41: Map operations, LHVM natives, Creature/Villager predicates
SingleMapFixed/MultiMapFixed: InsertMapObject/RemoveMapObject (cell linked list management)
Creature: IsCreature, GetCreatureBeliefType, CanBePickedUp, GetHoldType, GetPhysicsConstantsType
Villager: 15 creature interaction predicates (eat/befriend/stroke/kiss/throw/etc.)
LHVM: 25+ typed native function stubs (fire, poison, resource, leash, state queries)
MultiMapFixed: ReduceLife (damage flag), RemoveDamage, GetResourcePos/NearestEdge
WorshipSite: GetScriptObjectType, GetDistanceFromObject_1

### Batch 42: Method body bulk pass — entity lifecycle, physics, resources (4 commits)
MobileStatic: GetXAngle/GetZAngle/SetXYZAngles (field_0x80 angles), GetPhysicsConstantsType/GetResourceType/GetDefaultResource from info offsets, CanBecomeAPhysicsObject, CreatureMustAvoid (fence check), BlocksTownClearArea, GetPlayer delegation
MobileObject: GetXAngle/SetXYZAngles (field_0x5c/0x60), GetPlayer/GetDefaultResource/GetPhysicsConstantsType/GetHoldType from info, CanBecomeAPhysicsObject
Abode: Delete/ToBeDeleted lifecycle chain, InsertMapObject+surrounding objects, RemoveDamage, MakeFunctional/StopBeingFunctional/DeleteDependancys, DoResourceAdding/DoResourceRemoving delegation, CanBeStomped/CanBeKicked, GetPhysicsConstantsType from info, villager management (Add/Remove/RemoveAll)
Rock: GetResourceType/GetDefaultResource, GetPhysicsConstantsType delegation
Pot: ToBeDeleted, GetDefaultResource, IsPartOfStructure, SetSpeedUp/SetMultiMapFixed flag ops
Town: AddStructureToTown (CastAbode + list prepend), AddVillagerToTown (abode assignment), RemoveVillager cleanup
SpellSeed: GetPower/GetPSysPower, GetHoldRadius/LoweringMultiplier/YRotate from info, GetMesh, InsertMapObject/RemoveMapObject delegation
MultiMapFixed: IsObjectInMap_0/IsObjectFullyInMap (flag checks), GetArrivePos→GetDoorPos delegation
LHVM: Native_GET_DISTANCE (actual 3D Euclidean distance)
Villager: SetTown stub

### Batch 43: TODO cleanup + LHVM camera wiring + Zoomer implementation (15 commits)
Cleared all 330 TODO comments: implemented ~80 method bodies, converted ~250 blocked
stubs to descriptive comments documenting what each needs
LHVM: Wired camera natives (SET/GET/MOVE_CAMERA_POSITION/FOCUS) to g_game->camera
via offset-based access, wired DLL_GETTIME/GET_GAME_TIME to game_turn
Zoomer.cpp: Full cubic Hermite interpolation system (SetPosition, SetDestinationWithSpeedAndTime,
Update) — enables smooth camera transitions from CHL scripts
GCamera::Update: Now calls Zoomer3d::Update on heading/origin/FOV zoomers
GCamera::SetCameraFov: Uses Zoomer interpolation instead of snapping
Base::operator new/delete: Defined (were declared but missing, caused viewer link errors)
Abode: InterfaceValidToTap, InterfaceTap, GetDiscipleStateIfInteractedWith, ReactToPhysicsImpact
Rock: AddResource/RemoveResource for ore
Town: AddStructureToTown with CastAbode, full villager management
MobileStatic/MobileObject: angles, physics types, creature predicates
SpellSeed: GetWorshipSite from opaque field block

### Batch 45: LHVM bindings — host-side natives + viewer integration (12 commits, ~3,400 lines)

New module `src/core/LHVMObjects.cpp` + `src/include/black/LHVMObjects.h`:
script handle ↔ Object* registry, host service hooks (hand/click/spawn),
and 8 chunks of native bodies that override the LHVM.cpp stubs.

**Chunks** (all in LHVMObjects.cpp, registered after LHVM.cpp's defaults):
- Chunk 1 (50): GET/SET_POSITION, MOVE_GAME_THING, OBJECT_DELETE, THING_VALID,
  IS_OF_TYPE, GET/SET_PROPERTY, hand/click queries, GET_LAND_HEIGHT, resource
  ops, fire/poison/skeleton/active flags, mana, alignment, town queries
- Chunk 2 (54): real CREATE → EntityFactory dispatch, FLOCK_CREATE/ATTACH/
  DETACH/DISBAND/MEMBER, GET_FIRST/NEXT_IN_CONTAINER, ID_SIZE,
  CREATE_REWARD, LOAD_CREATURE/MY_CREATURE, GET_TEMPLE_*, etc.
- Chunk 3 (52): per-creature CreatureMind side-table — desires, agenda,
  knowledge, action counts, leash, fight queue, name, home, dev stage
- Chunk 4 (49): SPELL_AT_THING/POS/POINT, weather/climate, spirit advisor
  state, BUILD_BUILDING, OBJECT_INFO_BITS, clipping
- Chunk 5 (47): audio/dialogue/UI text/fade/widescreen/time/help, hand demo
- Chunk 6 (49): camera follow + cinematic + dual-camera + computer-player
  AI driver + ally relationships
- Chunk 7 (60): real GET_INFLUENCE walking sources, timers, calendar,
  POPULATE_CONTAINER → real EntityFactory spawns, walk paths, dance
- Chunk 8 (65): mini-games (arena/football), immersion, fades, save slot,
  per-object extras (confined/hurt/draw flags), CREATE_WITH_ANGLE_AND_SCALE

**Viewer wiring**:
- HandQueryCallback registered → GET_HAND_POSITION/STATE return real values
- WM_LBUTTONDOWN → lhvm::NotifyObjectClicked + NotifyPositionClicked
- EntitySpawnCallback registered → CHL CREATE/FLOCK_CREATE/etc. spawn into
  GameState.entities + core_entities so they render through existing path
- SCRIPT_OBJECT_TYPE → mesh-name lookup table for default rendering
- main loop sim throttled to BW's 10 Hz (was running 6× too fast at 60fps)
- delta_time bumped from 1/30 to 1/10 so physics matches turn rate
- LHVM::InitNativeFunctions duplicate call removed

**Bug fixes**:
- GET/SET_PROPERTY indices corrected to match SCRIPT_OBJECT_PROPERTY_TYPE
  enum (HEALTH=1, ANGLE=2, SCALE=8, XPOS=23, YPOS=24, ZPOS=25, etc.)
- SCRIPT_OBJECT_TYPE → category mapping fixed (ROCK=33 not 47, BONFIRE
  doesn't exist as top-level type)

### Batch 44: Ghidra pipeline + method translations from decompilation (8 commits)
Ghidra headless batch decompilation toolchain:
- GhidraBatchDecompile.java: decompile by address (73/83 methods in 4 seconds)
- GhidraDecompileByName.java: decompile by MSVC mangled name (12 found)
- 8,989 lines of Ghidra pseudocode extracted for priority methods
- Key finding: vendor bw1-decomp uses v1.41 addresses but binary is v1.0
  Name-based search with RTTI symbols is more reliable than raw addresses

Translated from Ghidra output:
- MultiMapFixed::Built: full IsCivic→GetAbodeType→AddToPlayer notification chain
- MultiMapFixed::MoveMapObject: validates map bounds before ActualMoveMapObject
- MultiMapFixed::CreateBuildingSite: allocates StandardBuildingSite (0x648 bytes)
- MultiMapFixed::Save: binary format documented (field_0x58 + percent_built)

Also implemented:
- Abode::Process: empty building life decay from GAbodeInfo emptyAbodeLifeReducer
- Abode: CalculateFoodNeededForDinner, IsEnoughFoodForDinner, IsTooCrowded, GetTribeType
- Abode::AddVillagerToAbode: male/female pair tracking
- GBelief: DistanceChangeToBelief (inverse linear), SetBeliefInPlayerCap with clamping
- Creature::ProcessState: MOVE_TO_POS/OBJECT use MobileWallHug with 400 speed
- Town::GetTribe: delegates to g_game->GetTribe(tribe_type)
- Zoomer.cpp: full cubic Hermite interpolation (new file, 161 lines)
- LHVM: camera natives wired to g_game, time natives wired to game_turn
- GCamera::Update: wired to Zoomer3d, SetCameraFov uses interpolation
- Base::operator new/delete: defined (were declared but missing)

## What's Next (priority order)

### Session 2026-08-30 (Phase 7 + 6C-faithful + PSys scope-A)
All three landed via the decompiler pipeline; see the commits for detail.

- **Phase 7 (save/load)** — the fan-out is done *as data*, not 200 hand-written
  method pairs. Every Save body in the binary is the same shape (delegate to
  parent, then run a field list), so slots 58/59/60 across all 200 savable
  classes were parsed into `src/core/SaveLoadTable.gen.cpp` (152 rows, 908 field
  ops, 178 save-type ids) and one chain walker in `SaveLoad.cpp` replays them in
  both directions. Pointers are an object graph: an object is written inline the
  first time it is referenced, by ordinal after that.
  **91 of 178 save types have a fully exact chain**; `SaveFields`/`LoadFields`
  refuse the other 87 rather than write a stream that disagrees with the
  original. Those need per-class work (Town, Citadel, Creature, the animal
  state-dispatch at 0x417e40, the Spell family's container walks).
  Fixed seven wrong save-type ids inherited from vendor v1.41 — Rock was
  carrying Workshop's (82; the real one is 111).
- **6C-faithful hand** — real polymorphic `HandState` objects owned by `CHand`,
  Exit-then-Enter transitions, viewer reports `GET_HAND_STATE` off the live
  state. Found that these bodies are mostly *drawing* (Holding::Update is 700
  lines of mesh calls), so draws funnel through a hook and what is translated is
  the behaviour underneath: Normal's idle-clip latch, PlayAnim's completion
  flag, Grain's offer lerp, and the three virtuals Holding adds at slots 5..7
  that the old header was missing.
- **PSys scope-A** — the atom/rule engine (`black/PSysEngine.h`). The lever was
  that every rule publishes its parameters to the particle editor from vtable
  slot 3, so `work/parse_psysrules.py` recovered **49 rule classes / 210
  parameters** with real names, offsets, types and ranges
  (`work/decomp/psys_rules.json`). Implemented: Atom (304 bytes, offsets
  asserted), the shared 8-slot rule interface with its condition gate, five
  appearance rules, six event conditions, three emitters.

- **Creature AI: attribute layer** — the 24 Attribute classes that turn the
  world into decision-tree inputs. Schema recovered mechanically from their
  shared 13-slot vtable and cross-checked against chlasm's ATTRIBUTE_TYPE
  (CC0): ids 0-23, no collisions. Thresholds verbatim (town big at 40, forest
  at 20 trees, alive above 20% life, height 0.25/0.75/1.25, belief
  0.2/0.4/0.6). **Corrected the vendor layout: Attribute is 0xC, not 0x8** —
  the binary deletes with size 12 and writes a value field at offset 8 that the
  vendor header omits.

- **Creature AI: perception + learning algorithm** — `xrefs`/`callees`/`floats`
  added to bw_decomp.py cracked the non-virtual half. Recovered: the per-belief
  attribute vectors (what the creature can notice about each kind of thing,
  `CreatureBeliefAttributes.cpp`), and **the full learning algorithm — greedy
  decision-tree induction with gain ratio, C4.5, per creature, live**. Written
  up in `work/decomp/creature_learning.md`. The opinion scale is implemented and
  tested (`CreatureOpinion.cpp`): 11 levels −1..+1, overlapping ±0.25 bands that
  bias every opinion one step down, and **level 10 is unreachable**.

- **Creature AI: induction loop implemented** (`CreatureLearner.cpp`). Impurity,
  gain ratio, the 0.01 stop, leaf values, induction, classification — all the
  binary's arithmetic, confirmed by disassembly where pseudocode lied
  (`sub_4B9BB0` is log2; impurity is `(2·sign + level)/3`). `test_learning`
  shows a creature discovering OnFire unaided from contradictory evidence.
  The 148-byte node's layout is still unrecovered, so the node representation
  is ours — arithmetic exact, storage shape a choice.

Remaining:
0. **Creature AI: the CreatureMind file format** — the blocker for desires, and
   the most valuable single thing left. `game_data/CreatureMind/` ships eight
   pre-trained minds; `sub_4C7CF0` loads them through the same GameOSFile
   primitives as Phase 7. The format is **versioned (17 / 25 / 30) with
   different layouts** — version 25 is legible by inspection, the others are
   not, so the loader has to be decompiled properly rather than pattern-matched.
   See `work/decomp/creature_data.md`.
   Note the fifteen creature tuning tables are `.bss`, filled from this data —
   there is nothing to read out of the exe, and our headers *and* the vendor's
   have all fifteen wrong at 0x10 (RTTI wrapper only, payload 56..916 bytes).
1. **Creature AI: agenda and actions** — once desires have real weights,
   `CreatureAgenda`/`CreaturePlan` turn the winning desire plus a tree opinion
   into an action; then wire `Creature::ProcessState`.
   `sub_4B7E00`/`sub_4B7D80` would still give the real induction node layout,
   and `sub_4BA8F0`'s return-2 case is unmodelled.
1. **Phase 7 completion** — the 87 partial save types. Each needs its container
   walk translated by hand; the table + walker are in place and the parser
   reports exactly which chain row blocks each type.
2. **PSys rule graphs** — byte-exact spell visuals are NOT reachable from this
   data set: there are no `.psy` files in `game_data` and no rule-name table in
   the exe, so the graphs are constructed in code, one function per effect.
   Reproducing a specific spell means decompiling those constructors and
   plugging them into the engine that now exists.
3. **PSys renderer half** — the ParticleCreator family and the 74-slot
   Particle3D* leaves, once there is a renderer in core to bind them to.
4. **HandState blob fields** — Camera/Tug/Creature/Citadel keep their opaque
   blocks; each is waiting on a different subsystem (GCamera save/restore,
   physics records, CreatureMental command state, the citadel interface).
5. **Computer player AI** behaviour.
6. **Multiplayer** — LAN-only, planned for a SEPARATE PRIVATE repo + server
   emulator (BWGameSpy online backend is dead; descoped). Design TBD.

Ghidra cross-check is still not live: `work/ghidra_project` has 0 vftable labels
(RTTI analyzer never run on import). IDA idalib is the sole working extractor
and has been sufficient throughout.

## Common Pitfalls (learned the hard way)
- **Vendor addresses are v1.41, binary is v1.0** — use MSVC mangled name search in Ghidra, not raw addresses
- `IsWorshipSite` has two overloads in base: `IsWorshipSite_1()` (no args) and `IsWorshipSite_0(Creature*)` — use suffixed names
- `DoCreatureMimicAfterAddingResource` takes `GInterfaceStatus*` (pointer), not reference
- `GetDistanceFromObject` has overloads: `GetDistanceFromObject_1(Object*)` — use suffixed name
- **Save-type ids from vendor v1.41 can be wrong for v1.0** — take them from the
  binary's vtable slot 60 (`work/decomp/save_ids.txt`), not from vendor headers
- **Hex-Rays writes a field address six different ways** and scales the offset by
  whatever pointer type it picked (`this + 32` on an `int*` is byte 128). Any
  extractor that reads offsets out of pseudocode has to normalise for that first
  — see `normalize()` in `work/parse_saveslots.py`
- **Check before writing a new header**: `black/CHand.h` and
  `black/CreatureLearning.h` are vendor structs with real recovered layouts
  (0x49C4 and 0x16168). A host-side type that wants the same name must take a
  different one — `HandMachine`, `CreatureLearner`. One of these was overwritten
  and pushed before it was caught.
- **The build dir is path-pinned**: a `build/` configured under `D:/` will not
  work from `G:/`. Delete and re-run cmake if the drive letter changed
- BuildingSite inherits GameThing (NOT Object), so its `Init()`/`Process()` are NEW vtable entries, not overrides
- CameraMode has its OWN vtable hierarchy completely separate from GameThing
