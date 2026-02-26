# Black & White — Static Recompilation Project

> *"I am merciful... but I am also bored of Windows XP compatibility hacks."*
> — Your Conscience, probably

## What Is This?

**Black & White** (2001) by Lionhead Studios is one of the most ambitious, bizarre, and beloved god games ever made. You raise a giant creature, hurl villagers into the sea, and micromanage belief systems — what's not to love?

The problem: **it barely runs on anything made after 2005.** DirectX 7 quirks, ancient threading models, 32-bit assumptions, and installer DRM from a civilization that has since collapsed. Patches exist but they're duct tape on a leaking dam.

Lionhead is gone. Peter Molyneux is off doing... Peter Molyneux things. A sequel or remaster isn't coming. **So we're doing it ourselves.**

This project is a **static recompilation** of Black & White — taking the original x86 binary apart, understanding it, and rebuilding it as clean, portable C/C++ that runs natively on modern systems.

## The Vision

- Native 64-bit Windows (and eventually Linux/macOS) support
- Modern graphics backend (Vulkan/DirectX 12, or at minimum D3D11)
- No emulation layers, no compatibility shims, no crying into WinXP VMs at 2 AM
- Same gameplay, same hand-slapping-villagers goodness — just actually functional

## Current Status

**190 headers | 152 implementations | 21,320 lines of C++ | 43 commits**

### Phase 0: Reconnaissance — COMPLETE

- [x] Acquire original game files
- [x] Unpack and inventory game data (textures, models, scripts, audio)
- [x] Identify executable format and protections
- [x] **Strip SafeDisc 2.10.030 copy protection** (TEA decryption, import table restoration, OEP recovery)
- [x] Initial disassembly / decompilation pass (Ghidra + bw1-decomp vendor reference)
- [x] Map out major subsystems (renderer, physics, AI, scripting, audio)
- [ ] Document the original engine architecture

### Phase 1: Build System — COMPLETE

- [x] CMake build system (Visual Studio 2022, 32-bit x86 Release)
- [x] Static library target (`bw_core`) compiling all entity types
- [x] Include path structure (`src/include/black/`)
- [x] Builds clean with zero warnings

### Phase 2: The Hand of God
- [ ] Implement the renderer (terrain, sky, water, creatures)
- [ ] Input system (the iconic hand!)
- [ ] Basic world loading and navigation

### Phase 3: Entity Hierarchy — IN PROGRESS (~33% of vendor types covered)

The complete class hierarchy from the decompiled binary is being rebuilt as idiomatic C++ with correct MSVC vtable layout. Working from 569 vendor reference headers in `bw1-decomp`.

**Implemented (190 types):**

- [x] **Core hierarchy**: Base → GameThing → GameThingWithPos → Object → Mobile → MobileWallHug → Living (7 layers deep)
- [x] **Fixed objects**: MultiMapFixed, SingleMapFixed, Abode, Windmill, Wonder, Totem, Workshop, StoragePit, Creche, Graveyard, SpellDispenser, TownCentre, Field, Feature, Flowers, AnimatedStatic, PrayerSite, Rock, Bonfire, Fragment, DeadTree, Tree, MagicTree, MagicTeleport, PFootball, BigForest
- [x] **CitadelPart family**: CitadelPart, CitadelHeart, TotemStatue, LandscapeVortex, WorshipSiteUpgrade, WorshipSite, WorshipTotem, WorshipSpellIcon
- [x] **Mobile entities**: MobileObject, MobileStatic, Pot, Scaffold, Arrow, Poo, PBall, HanoiBlock, Ball, OneOffSpellSeed, Whale, FieldCrop
- [x] **Object-derived**: Furniture, CitadelEntrance, GWaterfall, GStreetLantern, ShowNeedsVisuals, HelpSpirit, MagicFireBall, SpellSeed, FireFly, Reward, TownDesireFlags, SpellIcon, FishFarm, Football, MapShield
- [x] **Living entities**: Villager, Animal, Creature, Lion, Leopard, Tiger, Wolf, Cow, Horse, Sheep, Pig, Goat, Tortoise, Zebra, Dove, Crow, Pigeon, Seagull, Swallow, Vulture, Bat
- [x] **Containers**: Container, Citadel, Flock, Forest
- [x] **Spell system**: Spell, SpellWithObjects, SpellHeal, SpellForest, SpellResource, SpellCreature, SpellWater, SpellStormAndTornado, SpellShield, SpellTeleport, SpellFlock, SpellFlockFlying, SpellFlockGround
- [x] **Planned buildings**: PlannedMultiMapFixed, PlannedAbode, PlannedFeature, PlannedCitadelPart, PlannedCitadelHeart, PlannedCreaturePen, PlannedWorshipSite, PlannedWorshipSiteUpgrade, PlannedTownCitadelHeart, PlannedTownCentre
- [x] **BuildingSite family**: BuildingSite (12 new vtable entries), StandardBuildingSite, CitadelBuildingSite, WorkshopBuildingSite
- [x] **Camera system**: GCamera, CameraMode (18 virtuals), CameraModeFree, CameraModeFollow, + 10 subclass variants
- [x] **Town system**: TownStats, TownDesire, TownSpellIcon, TownCentreSpellIcon, GTownDesireInfo, GTownInfo, Temple, GTownDesireFunction
- [x] **Info data structs**: GBaseInfo, GObjectInfo, GMultiMapFixedInfo, GSingleMapFixedInfo, GAbodeInfo, GFeatureInfo, GCitadelPartInfo, GWorshipSiteInfo, GMagicInfo, GTribeInfo, GContainerInfo, GMobileObjectInfo, GAnimalInfo, GVillagerInfo, GCreatureInfo
- [x] **Utility/data**: GAlignment, GBelief, Map, MapCoords, Game, Zoomer, Zoomer3d
- [x] **Footpath system**: GFootpath, GFootpathLink, GFootpathNode, GFootpathLinkSave
- [x] **Miscellaneous**: ShowNeeds, FireEffect, DancePathInfo, Playtime, TownArtifact, GParticleContainer, SpellSeedGraphic, Arena, Meeting, WayPoint, ScriptTimer, ScriptMarker, WeatherThing, Mist, InfluenceRing, GStreetLight

**Remaining (~379 types):**

- [ ] Town (0xF28 — the largest class in the game)
- [ ] Player, PlayerList, GSetupInfo
- [ ] Creature AI subsystem (~50 types: CreatureMind, CreatureDesires, CreatureLearning, etc.)
- [ ] Landscape/terrain system
- [ ] Script/LHVM virtual machine
- [ ] Mesh/rendering (L3D, G3D, LH3DIsland)
- [ ] Particle effects, weather details
- [ ] Remaining info structs and helper types

### Phase 4: Polish & Miracles
- [ ] Audio engine
- [ ] Multiplayer (the original had it!)
- [ ] Modding support
- [ ] Quality-of-life improvements the original desperately needed

---

## Recon Report: What We Found Inside

We cracked open the disc image and extracted 1,011 files from the InstallShield 6 CABs. Here's what's inside this 25-year-old beast.

### The Main Executable: `runblack.exe`

| Property | Value |
|----------|-------|
| Internal name | `Black.exe` |
| Format | PE32, Intel i386, 7 sections |
| Size | 8.2 MB |
| Built | March 9, 2001 at 2:56 PM (crunch time energy) |
| Image base | `0x400000` |
| Entry point | `0xAE61FD` (SafeDisc stub) → Real OEP: `0x337B8E` (WinMainCRTStartup) |
| .text section | 4.0 MB of code |
| .data section | 5.9 MB virtual (2.5 MB on disk) |
| Total image size | 10.9 MB |

**The kicker:** The protected binary only shows **6 imports** from 2 DLLs. But after stripping SafeDisc, the real import table was revealed — **19 DLLs** including DirectDraw, DirectInput, Bink Video, and all the Lionhead satellite libraries. The game loads additional functionality via `GetProcAddress` at runtime, but the core is almost entirely statically linked in this one massive EXE.

**Copy Protection:** SafeDisc **2.10.030**. The telltale signs:
- `SELFMOD` section — self-modifying code for anti-debug
- `stxt774` and `stxt371` sections — encrypted code stubs
- `BoG_` signature at offset `0xFD4`, version bytes at `0xFF4`
- `secdrv.sys` driver on disc
- Entire 4.0 MB `.text` section encrypted with TEA (Tiny Encryption Algorithm) in ECB mode
- 732 KB overlay data containing encrypted `dplayerx.dll`

**STATUS: STRIPPED.** We built a custom dump tool on top of [SafeDiscLoader2](https://github.com/TheRogueArchivist/SafeDiscLoader2), injected it at runtime, waited for the TEA decryption to complete, and dumped the fully decrypted binary. The real import table (19 DLLs) has been restored and the entry point fixed to the original `WinMainCRTStartup` at RVA `0x337B8E`. The clean binary is ready for Ghidra.

### Runtime DLL Dependencies

The game loads these DLLs dynamically at runtime:

| DLL | Purpose | Exports |
|-----|---------|---------|
| `DDRAW.dll` | DirectDraw 7 — the renderer | System |
| `DINPUT.dll` | DirectInput — keyboard/mouse/gamepad | System |
| `binkw32.dll` | Bink Video — FMV playback | 81 |
| `QMixer.dll` | QSound audio mixing | 91 |
| `LHaudiodllR.dll` | Lionhead audio system | 124 |
| `LHMultiplayerR.dll` | Lionhead multiplayer/networking | 883 (!!) |
| `LHDialogLib.dll` | Lionhead dialog/UI | 15 |
| `IFC22.dll` | Immersion force feedback | 573 |
| `wearasr.dll` | Dial-up networking (lol) | 13 |
| `LHLogR.dll` | Lionhead logging | System |
| `drvmgt.dll` | SafeDisc driver management | 3 |
| Various Win32 | `USER32`, `GDI32`, `WINMM`, `WSOCK32`, `ADVAPI32`, `SHELL32`, `COMCTL32`, `IMM32`, `ole32`, `comdlg32` | System |

883 exports from the multiplayer DLL alone. Lionhead did not believe in modesty.

### Game Data Inventory

**1,079 files extracted, 726 MB total**

| Type | Count | Description |
|------|-------|-------------|
| `.l3d` / `.L3D` | 228 | 3D models (Lionhead 3D format) |
| `.raw` / `.RAW` | 173 | Texture data |
| `.zzz` | 186 | Compressed data archives |
| `.sad` | 112 | Sound/audio data banks |
| `.DAN` | 35 | Animation data (dance/creature?) |
| `.cam` | 34 | Camera path definitions |
| `.CBN` | 17 | Citadel binary data |
| `.gif` | 28 | Web-era creature cave HTML graphics |
| `.hnd` | 16 | Hand gesture/demo recordings |
| `.lnd` | 10 | Landscape files (one per land/level) |
| `.bik` | 5 | Bink video files (intro, tips, logo) |
| `.555` / `.16b` | 18 | 16-bit textures (sky, etc.) |
| `.exc` | 9 | Script exclusion zones |
| `.anm` | 13 | Animation files |
| `.h` | 5 | **Original C/C++ header files!** |
| `.txt` | 22 | Level scripts, configs, specs |

### Original Header Files (!!!)

Lionhead shipped actual source headers in the game data. These are *extremely* valuable for recompilation:

- **`AllMeshes.h`** — Complete enum of all 626 meshes and 441 animations with IDs
- **`LHAction.h`** — Creature action/sound event enum (breathe, footstep, growl, spell effects...)
- **`SoundAction.h`** — Full sound action enum (167 entries covering combat, spells, creature sounds, villager actions)
- **`SoundObject.h`** — Sound object type enum (54 types: human, lion, ape, wolf, cow, seagull, spell_bubble...)
- **`ScriptSfxEnum.h`** — Script sound effect enum (153 entries)

These headers give us the exact enum values the game code uses internally. No guessing required.

### Level Script System

The game levels are defined in human-readable script files (`Land1.txt` through `Land5.txt`, `LandT.txt`). Example from Land 1:

```
VERSION(2.300000)
SET_LAND_NUMBER(1)
LOAD_LANDSCAPE(".\DATA\LANDSCAPE\Land1.lnd")
START_CAMERA_POS("1441.56,2081.76")
CREATE_TOWN(0, "1865.61,2641.24", "PLAYER_ONE", 7, "NORSE")
SET_TOWN_BELIEF(0, "PLAYER_ONE", 9.238012)
CREATE_ABODE(0, "1755.09,2692.52", "NORSE_ABODE_C", 4710, 990, 0, 0)
CREATE_VILLAGER_POS("1762.85,2692.48", "1755.09,2692.52", "NORSE_FORESTER", 21)
```

These scripts define towns, buildings, villagers, beliefs, camera positions — the entire level setup. The scripting engine that interprets these will be one of the first subsystems to reimplement.

### Game Script Commands Found in the Binary

From string analysis of `runblack.exe`, we identified these game API commands:

**Creature System:** `Creature`, `CreatureDance`, `CreatureFaceDirection`, `CreatureFaceIn/Out`, `CreatureFacial`, `CreatureGesture`, `CreatureIndividual`, `CreatureLookAt`, `CreaturePoint`, `CreatureStatic`, `WorshipCreature`

**World Objects:** `Villager`, `Citadel`, `CitadelPart`, `Forest`, `ForestTree`, `Totem`, `FakeWall`, `Rock`, `Tree`, `Football` (yes, football)

**Actions:** `SetAction`, `SetPos`, `SetSize`, `SetAngle`, `SetState`, `SetPath`, `AddPath`, `RemovePath`, `MoveToPos`, `PlayAnim`, `SetCamera`, `SetCameraTravelTime`, `ShowGroup`, `HideGroup`, `ChangeGroup`, `ChangeSize`

**Rendering:** `SetLightOnOrOff`, `AttachLightToGroup`, `SetLightBitmap`, `SetLightSynchronisationOnOrOff`, `Lightning`

**Species:** Ape, Bear, Chicken, Cow, Crocodile, Elephant, Horse, Lion, Sheep, Wolf

### Engine Architecture (Mapped)

Based on DLL analysis, string extraction, and data file inventory:

```
                        ┌─────────────────────┐
                        │   runblack.exe       │
                        │   (8.2 MB monolith)  │
                        │                      │
                        │  ┌─────────────────┐ │
                        │  │ Game Logic       │ │
                        │  │ - Creature AI    │ │
                        │  │ - Villager sim   │ │
                        │  │ - Belief system  │ │
                        │  │ - Script engine  │ │
                        │  │ - Physics        │ │
                        │  │ - Spells         │ │
                        │  └────────┬────────┘ │
                        │           │          │
                        │  ┌────────┴────────┐ │
                        │  │ Core Engine      │ │
                        │  │ - Renderer (DDraw)│ │
                        │  │ - Input (DInput) │ │
                        │  │ - Camera system  │ │
                        │  │ - L3D loader     │ │
                        │  │ - Landscape      │ │
                        │  │ - Particle sys   │ │
                        │  └────────┬────────┘ │
                        └───────────┼──────────┘
                                    │
              ┌─────────┬───────────┼───────────┬──────────┐
              │         │           │           │          │
        ┌─────┴───┐ ┌───┴────┐ ┌───┴────┐ ┌───┴────┐ ┌──┴───┐
        │LHaudio  │ │QMixer  │ │binkw32 │ │LHMulti │ │IFC22 │
        │(audio)  │ │(mixing)│ │(video) │ │(net)   │ │(ffb) │
        └─────────┘ └────────┘ └────────┘ └────────┘ └──────┘
```

## Project Structure

```
bw/
├── README.md              ← You are here
├── .gitignore
├── tools/                 ← Asset extraction & analysis utilities
│   ├── bin2iso.js         ← BIN/CUE to ISO converter
│   ├── extract_all_v4.js  ← InstallShield CAB extractor
│   └── inject_and_run.c   ← SafeDisc DLL injector for process dumping
├── vendor/                ← Third-party references
│   ├── SafeDiscLoader2/   ← Modified SafeDisc bypass + process dumper
│   └── bw1-decomp/black/  ← 569 decompiled struct headers (reference material)
├── src/                   ← Recompiled source code (active development)
│   ├── CMakeLists.txt     ← Build system (VS2022, 32-bit x86)
│   ├── include/black/     ← 190 C++ headers (classes with vtable layout)
│   └── core/              ← 152 implementation files (method stubs)
├── work/clean/            ← Decrypted, clean binary for analysis
└── game_data/             ← Extracted game data (not checked in — bring your own disc!)
    ├── *.h                ← Original Lionhead headers (gold dust)
    ├── *.l3d              ← 3D models
    ├── *.lnd              ← Landscape files
    ├── *.sad              ← Audio banks
    ├── *.txt              ← Level scripts
    ├── Audio/             ← Music (alignment, chant, citadel, script)
    ├── Meshes/            ← 3D mesh data
    ├── CreatureMind/      ← Creature AI definitions
    ├── Dance/             ← Dance choreography data (34 dance types!)
    ├── Playgrounds/       ← Multiplayer maps
    ├── Quests/            ← Quest data
    ├── SFX/               ← Sound effects (atmos, creature, game, script)
    ├── Spells/            ← Spell effect data
    └── ...
```

## How to Help

This is early days. If you:
- Have experience with reverse engineering x86 binaries
- Know your way around Ghidra, IDA, or Binary Ninja
- Have worked with DirectX 7/8 era rendering
- Understand SafeDisc and can help with unpacking
- Just really love Black & White and want to see it live again

...then welcome aboard. Open an issue, submit a PR, or just come lurk.

## Next Steps

1. ~~**Strip SafeDisc protection** from `runblack.exe`~~ **DONE!**
2. ~~**Set up build system and entity hierarchy**~~ **IN PROGRESS** — 190/569 types implemented (33%)
3. **Implement Town class** (0xF28 bytes — the single largest class) and Player system
4. **Creature AI subsystem** — ~50 types covering mind, desires, learning, actions
5. **Landscape/terrain system** — map loading, heightfield, navigation mesh
6. **LHVM scripting engine** — the virtual machine that runs level scripts
7. **Mesh and rendering** — L3D/G3D loaders, terrain renderer (D3D11/Vulkan)
8. **Fill in real method bodies** from Ghidra decompilation output

## Legal

This project contains **no copyrighted game assets**. You need your own copy of Black & White to use this. We're reimplementing the engine, not distributing the game.

This is a clean-room-ish effort — we're studying the binary to understand behavior, then writing new code that produces the same results. Think of it as translating a book from Ancient x86 to Modern C++.

## Acknowledgments

- **Lionhead Studios** — for making something truly special, and for shipping source headers in your game data like absolute legends
- **Peter Molyneux** — for dreaming bigger than any engine could handle (as usual)
- The Black & White community — still keeping the faith after 25 years
- Everyone who has ever tried to get this game running on Windows 10 and lived to tell the tale

---

*"We cracked it open. We stripped its armor. We read its soul. Now we rebuild it."*
