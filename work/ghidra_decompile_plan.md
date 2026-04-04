# Ghidra Decompilation Plan — Black & White Static Recompilation

## Methodology

### Setup
1. Open `runblack_decrypted.exe` (v1.0 / v1.41) in Ghidra
2. Auto-analyze with default settings + "Decompiler Parameter ID"
3. Cross-reference with vendor bw1-decomp headers for struct layouts
4. Focus on one chunk at a time — paste Ghidra pseudocode, Claude translates to C++

### Per-Method Workflow
1. Navigate to address in Ghidra (e.g., `0x00404440`)
2. Open Decompiler view — copy the full pseudocode
3. Note any global variables referenced (addresses → we map to our structs)
4. Paste into Claude with: "Translate this Ghidra output for `Abode::Process`"
5. Claude maps Ghidra field offsets to our named struct fields and produces clean C++

### Key Address Ranges (by subsystem)
- `0x00401xxx-0x00407xxx` — Abode, MultiMapFixed, Fixed, Object base methods
- `0x0043xxxx` — Camera modes, Zoomer, small utility methods
- `0x00450xxx-0x0046xxxx` — Creature, CreatureMental
- `0x004e3xxx-0x004e4xxx` — Shared creature interaction predicates
- `0x00504xxx-0x00505xxx` — MultiMapFixed complex methods
- `0x0052xxxx` — Map operations, SingleMapFixed, FishFarm
- `0x0054xxxx-0x0055xxxx` — GGame, GData, game loop
- `0x005exxxx` — Living state machine
- `0x0060xxxx` — MobileObject, MobileStatic
- `0x0064xxxx` — GPlayer
- `0x0066xxxx` — Pot
- `0x006exxxx` — Rock
- `0x0072xxxx` — SpellSeed, OneOffSpellSeed
- `0x0073xxxx` — Town, TownStats, Totem
- `0x0074xxxx` — Town::Process, Tree

---

## Chunk 1: Town Simulation Core (15 methods, HIGH PRIORITY)

These drive the entire town economy and population system.

| Address | Method | Why |
|---------|--------|-----|
| 0x00747380 | Town::Process | Main town tick — desire eval, construction, emergency |
| 0x007477a0 | Town::ProcessTownEmergency | Starvation, shelter crisis response |
| 0x0073b5d0 | Town::Birthday | Pregnancy, child aging, population growth |
| 0x0073b370 | Town::FindAbodeWithSpaceInTown | Housing assignment algorithm |
| 0x0073d6e0 | Town::GetRadius | Town influence radius calculation |
| 0x0073bc40 | Town::GetCitadel | Citadel lookup from town structures |
| 0x0073c940 | Town::GetWorshipSite | Worship site through citadel parts |
| 0x00739a20 | Town::AddAbodeToTownStats | Population tracking on new building |
| 0x0073a650 | Town::RequestBestPlanned | AI building request system |
| 0x0073a1a0 | Town::GetDesireToBeBuilt | Construction priority scoring |
| 0x0073b860 | Town::AddBuildingSite | Construction site creation |
| 0x0073ba20 | Town::RemoveBuildingSite | Construction completion/cancel |
| 0x0073d080 | Town::AddPlanned | Planned structure management |
| 0x0073d150 | Town::AllVillagersCheckNeedNewAbode | Housing redistribution |
| 0x0073e900 | Town::GetTemporaryResourceStorePotOrPos | Resource delivery target |

## Chunk 2: Abode Lifecycle (12 methods, HIGH PRIORITY)

Building construction, food/resource management, villager housing.

| Address | Method | Why |
|---------|--------|-----|
| 0x00404440 | Abode::Process (full) | Food consumption, pregnancy, life decay |
| 0x00404060 | Abode::AddVillagerToAbode (full) | Linked list insertion, male/female tracking |
| 0x00404340 | Abode::RemoveAliveVillagerFromAbode (full) | Linked list removal |
| 0x00404d90 | Abode::AddResource (full) | Resource with creature mimic/interface |
| 0x00404f10 | Abode::RemoveResource (full) | Resource removal with interface |
| 0x00404df0 | Abode::DoResourceAdding | Resource adding logic |
| 0x00404f60 | Abode::DoResourceRemoving | Resource removal logic |
| 0x00403200 | Abode::CallVirtualFunctionsForCreation | Full creation chain |
| 0x004047e0 | Abode::MakeFunctional (full) | Town notification, player addition |
| 0x004073c0 | Abode::StopBeingFunctional (full) | Shutdown, villager evacuation |
| 0x00404720 | Abode::Built (full) | Construction complete handler |
| 0x00405050 | Abode::ConvertToPlanned | Planned structure conversion |

## Chunk 3: Building Site System (10 methods, HIGH PRIORITY)

Construction management — how buildings get built.

| Address | Method | Why |
|---------|--------|-----|
| 0x0052f590 | MultiMapFixed::CreateBuildingSite | Creates BuildingSite for new construction |
| 0x0052e890 | MultiMapFixed::CallVirtualFunctionsForCreation (full) | Full creation chain |
| 0x0052f0d0 | MultiMapFixed::GetDiscipleStateIfInteractedWith | Villager drop-on-building |
| 0x0052f210 | MultiMapFixed::DoCreatureMimicAfterAddingResource | Creature learning |
| 0x0052f460 | MultiMapFixed::DeleteObjectAndTakeResource | Resource extraction |
| 0x00504e10 | MultiMapFixed::Built (full) | Construction complete notification |
| 0x0052ec60 | MultiMapFixed::StartOnFire | Fire spread to buildings |
| 0x0052e400 | MultiMapFixed::GetMapChild (full) | Multi-cell child lookup |
| 0x0052e420 | MultiMapFixed::SetMapChild (full) | Multi-cell child assignment |
| 0x0052e4f0 | MultiMapFixed::MoveMapObject (full) | Multi-cell repositioning |

## Chunk 4: Villager State Machine (10 methods, MEDIUM PRIORITY)

The villager AI decision loop.

| Address | Method | Why |
|---------|--------|-----|
| 0x00755f30 | Villager::ProcessState (full) | 30+ state dispatch |
| 0x00756530 | Villager::SetTown (full) | Town reference management |
| 0x00757600 | Villager::DecideWhatToDo | AI decision tree |
| 0x00755e00 | Villager::GetVillagerName | Name lookup |
| 0x00753610 | Villager::AmILikelyToMove | Movement prediction |
| 0x004e43f0 | CanBeStompedOnByCreature (shared) | Creature interaction check |
| 0x004e3fa0 | CanBeKickedByCreature (shared) | Creature interaction check |
| 0x004e4cc0 | CanBePickedUpByCreature (shared) | Creature interaction check |
| 0x004e48d0 | CanBeEatenByCreature (shared) | Creature interaction check |
| 0x004d1b60 | GetHowMuchCreatureWantsToLookAtMe (shared) | Creature attention |

## Chunk 5: Serialization Format (8 methods, MEDIUM PRIORITY)

Binary save/load format. Decompiling a few reveals the format for all.

| Address | Method | Why |
|---------|--------|-----|
| 0x00406d20 | Abode::Load | Reveals abode binary format |
| 0x00406a10 | Abode::Save | Confirms field ordering |
| 0x0052f310 | MultiMapFixed::Load | Base building format |
| 0x0052f250 | MultiMapFixed::Save | Base building format |
| 0x006e7870 | Rock::Load | MobileStatic format |
| 0x006e77b0 | Rock::Save | MobileStatic format |
| 0x00608590 | MobileStatic::Load | Base mobile format |
| 0x00554830 | GGame::Load | Game state format (huge) |

## Chunk 6: GGame Loop (8 methods, MEDIUM PRIORITY)

Main game loop subsystem calls.

| Address | Method | Why |
|---------|--------|-----|
| 0x0054e5c0 | GGame::ProcessTurn (full) | All subsystem call addresses |
| 0x0054e960 | GGame::EndTurn (full) | Cleanup, FPS, save detection |
| 0x0054e4f0 | GGame::StartTurn (full) | Timer init, UI update |
| 0x0054cf20 | GGame::Loop | Main loop structure |
| 0x0054f3b0 | GGame::Init | Initialization sequence |
| 0x005507d0 | GGame::LoopThroughPlayers (full) | Per-frame player updates |
| 0x00552620 | GGame::GetTribe | Tribe info lookup |
| 0x0054c190 | GGame::StartGame | Startup sequence |

## Chunk 7: Interface/Hand Interaction (12 methods, LOWER PRIORITY)

How objects respond to the player's magic hand. Pattern-based — decompile a few to understand the template.

| Address | Method | Why |
|---------|--------|-----|
| 0x00608bb0 | MobileStatic::ValidToApplyThisToObject | Template for Apply pattern |
| 0x00608c30 | MobileStatic::ApplyThisToObject | Template for Apply pattern |
| 0x0066dd50 | Pot::ValidToApplyThisToObject | Pot→storage pit interaction |
| 0x0066ddd0 | Pot::ApplyThisToObject | Pot resource transfer |
| 0x0066de70 | Pot::ApplyThisToMapCoord | Pot placement |
| 0x007286d0 | SpellSeed::ValidToApplyThisToObject | Spell compatibility check |
| 0x00728d10 | SpellSeed::ApplyThisToObject | Spell casting |
| 0x00728810 | SpellSeed::InterfaceSetInMagicHand | Pickup charge start |
| 0x00728940 | SpellSeed::InterfaceSetOutMagicHand | Charge finalize |
| 0x00737520 | Totem::ValidForLockedSelectProcess | Totem drag validation |
| 0x00737570 | Totem::NetworkFriendlyStartLockedSelect | Totem drag start |
| 0x00737610 | Totem::NetworkUnfriendlyLockedSelect | Totem drag update |

## Chunk 8: Physics Callbacks (8 methods, LOWER PRIORITY)

How objects respond to physics collisions.

| Address | Method | Why |
|---------|--------|-----|
| 0x00608fc0 | MobileStatic::ReactToPhysicsImpact | Impact damage |
| 0x00608de0 | MobileStatic::GetWorldMatrix | 3x3 rotation from angles |
| 0x00608f40 | MobileStatic::GetBoundingSphere | Bounding sphere from mesh |
| 0x00607a20 | MobileObject::ReactToPhysicsImpact | Impact damage |
| 0x00607560 | MobileObject::GetWorldMatrix | 3x3 rotation from angles |
| 0x006e7930 | Rock::ReactToPhysicsImpact | Rock damage on impact |
| 0x0066dc90 | Pot::ReactToPhysicsImpact | Pot breaking |
| 0x0066df00 | Pot::InitialisePhysicsFromHand | Thrown pot trajectory |

---

## Estimated Effort

| Chunk | Methods | Est. Lines | Priority |
|-------|---------|-----------|----------|
| 1. Town Core | 15 | ~600 | HIGH |
| 2. Abode Lifecycle | 12 | ~400 | HIGH |
| 3. Building Site | 10 | ~350 | HIGH |
| 4. Villager SM | 10 | ~500 | MEDIUM |
| 5. Serialization | 8 | ~400 | MEDIUM |
| 6. Game Loop | 8 | ~300 | MEDIUM |
| 7. Interface/Hand | 12 | ~400 | LOWER |
| 8. Physics | 8 | ~250 | LOWER |
| **Total** | **83** | **~3,200** | |

After these 83 methods, the remaining ~430 stubs are either:
- Rendering (Draw methods) — need 3D pipeline
- Creature Mental Model — massive 135KB struct, separate project
- Networking — multiplayer, not needed for single-player
- Audio — sound system integration
- Minor utility classes — low impact

## How to Feed Ghidra Output to Claude

Paste like this:
```
Translate this Ghidra decompilation for Town::Process at 0x00747380.
Our struct layout: Town is 0xF28 bytes, fields documented in src/include/black/Town.h.
Vendor reference: vendor/bw1-decomp/black/Town.h

[paste Ghidra pseudocode here]
```

Claude will:
1. Map `*(int*)(param1 + 0x610)` → `stats.num_adults`
2. Replace raw vtable calls with named virtual methods
3. Convert __thiscall convention to C++ member functions
4. Handle MSVC-specific patterns (hidden return params, etc.)
