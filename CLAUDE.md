# Black & White Static Recompilation — Project Memory

## Standing Directive
Push completed work to GitHub and continue implementing the entity class hierarchy.

## Project Overview
Static recompilation of Black & White (2001) — rebuilding the original x86 binary as clean C++ from decompiled vendor reference material (bw1-decomp).

## Key Paths
- **Git repo root**: `D:/recomp/pc/bw`
- **Source root**: `D:/recomp/pc/bw/src`
- **Headers**: `D:/recomp/pc/bw/src/include/black/`
- **Implementations**: `D:/recomp/pc/bw/src/core/`
- **Vendor reference**: `D:/recomp/pc/bw/vendor/bw1-decomp/black/` (569 decompiled struct headers)
- **CMakeLists.txt**: `D:/recomp/pc/bw/src/CMakeLists.txt`

## Build System
```bash
cd /d/recomp/pc/bw/src
cmake -G "Visual Studio 17 2022" -A Win32 -S . -B build
cmake --build build --config Release
```
- Visual Studio 2022, 32-bit x86 Release
- Static library target: `bw_core`
- Must build clean with zero errors before committing

## Current Stats (as of commit 48acf10)
- **600 headers** in `src/include/black/`
- **251 .cpp files** in `src/core/`
- **41,000+ lines** of C++ total (core + viewer)
- **152 commits**, all pushed to GitHub
- **~100% coverage** of 569 vendor types (entity hierarchy complete)
- **~1100 stubs remaining** (~350 are intentional base-class defaults)
- **bw_viewer now links against bw_core** — dual entity system active

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

## What's Next (priority order)
1. **Method bodies** — translate remaining Ghidra decompilation (~1400 stubs)
2. **Villager state machine** — implement VillagerStates ProcessState dispatch
3. **Save/Load system** — binary format for entity serialization
4. **LHVM native function bodies** — fill in ~375 remaining stubs as subsystems come online

## Common Pitfalls (learned the hard way)
- `IsWorshipSite` has two overloads in base: `IsWorshipSite_1()` (no args) and `IsWorshipSite_0(Creature*)` — use suffixed names
- `DoCreatureMimicAfterAddingResource` takes `GInterfaceStatus*` (pointer), not reference
- `GetDistanceFromObject` has overloads: `GetDistanceFromObject_1(Object*)` — use suffixed name
- BuildingSite inherits GameThing (NOT Object), so its `Init()`/`Process()` are NEW vtable entries, not overrides
- CameraMode has its OWN vtable hierarchy completely separate from GameThing
