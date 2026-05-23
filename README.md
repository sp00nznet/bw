# Black & White — Static Recompilation Project

> *"I am merciful... but I am also bored of Windows XP compatibility hacks."*
> — Your Conscience, probably

## What Is This?

**Black & White** (2001) by Lionhead Studios is one of the most ambitious, bizarre, and beloved god games ever made. You raise a giant creature, hurl villagers into the sea, and micromanage belief systems — what's not to love?

The problem: **it barely runs on anything made after 2005.** DirectX 7 quirks, ancient threading models, 32-bit assumptions, and installer DRM from a civilization that has since collapsed. Patches exist but they're duct tape on a leaking dam.

Lionhead is gone. Peter Molyneux is off doing... Peter Molyneux things. A sequel or remaster isn't coming. **So we're doing it ourselves.**

This project is a **static recompilation** of Black & White — taking the original x86 binary apart, understanding it, and rebuilding it as clean, portable C/C++ that runs natively on modern systems.

## The Vision

- Native Windows (32-bit today, 64-bit + Linux/macOS later) support
- Modern graphics backend (OpenGL now, Vulkan/D3D12 later)
- No emulation layers, no compatibility shims, no crying into WinXP VMs at 2 AM
- Same gameplay, same hand-slapping-villagers goodness — just actually functional

## Current Status

**601 headers | 253 implementations | 14 viewer modules | ~49,800 lines of C++ | 244 commits**

The viewer ticks the entire game loop end-to-end: terrain renders, CHL scripts drive entity spawning, the LHVM dispatches ~430 wired native functions, villagers play real ANM skeletal animations from `AllAnims.anm`, sound effects fire from extracted SAD audio banks, and the camera follows whatever the script tells it to.

### What works right now

**Rendering**
- L3D mesh loader (bind pose + bones preserved for runtime CPU skinning)
- G3D archive loader (622/626 meshes, 111K verts, 101K tris with DXT1/DXT3 textures)
- LND terrain renderer (heightmap, altitude colouring, 17×17 cell blocks)
- Per-entity OpenGL render with hover/selected tinting
- HUD overlay (Consolas bitmap font) showing turn, entity counts, hand state, dialogue ids, library counts
- Subtitle text at the bottom of the screen
- Click marker / spirit pointer beam / coloured influence rings / expanding spell rings — all driven by LHVM state

**Animation**
- L3D refactored to keep bind-pose vertices + bones separately for runtime skinning
- Procedural per-bone idle / walk / animal-idle / bird-flap modes with proper parent-frame composition
- Full ANM file decoder for both individual `Anims/*.anm` files and the `AllAnims.anm` Pack archive
- Per-bone 4×3 affine matrices decoded into `BoneMatrix` and applied via CPU skinning
- Adjacent-keyframe linear interpolation for smooth playback
- Script-driven animation selection via `PLAY_GESTURE` / `OVERRIDE_STATE_ANIMATION` natives
- Library indexed by source-name (e.g. `M_P_Conduct_Meeting`) and integer id

**LHVM scripting**
- 464/465 typed native functions (only `NONE` is a no-op stub)
- ~430 of those have real bodies in `LHVMObjects.cpp` (8 chunks, ~3,900 lines):
  - Chunk 1: object handle table + 50 entity-touching natives (GET/SET_POSITION, OBJECT_DELETE, THING_VALID, IS_OF_TYPE, GET/SET_PROPERTY, hand/click, resource ops, status flags, ...)
  - Chunk 2: real `CREATE`→EntityFactory dispatch, flock subsystem, container iteration, position-cinematic helpers
  - Chunk 3: per-creature CreatureMind side-table — desires, agenda, knowledge, leash, fight queue, name/home/sound/temple flags
  - Chunk 4: spell records with expiry, weather + climate state, spirit advisor state, BUILD_BUILDING, GAME_THING_HIT → real ReduceLife
  - Chunk 5: audio/dialogue/UI text/fade/widescreen/time, hand demo
  - Chunk 6: camera follow + cinematic + dual-camera + computer-player AI + ally relationships
  - Chunk 7: GET_INFLUENCE walks real sources, timers, calendar, walk paths, dance, animation modify, AVI sequence
  - Chunk 8: mini-games (arena/football), immersion, fades, save slot, per-object extras
- Sim throttled to BW's 10 Hz via accumulator-based main loop
- CHL bytecode loader + 31-opcode stack VM + task management
- `Land1.txt` / `challenge.chl` load on startup; auto-start scripts tick each frame

**Host integration (viewer ↔ bw_core)**
- Hand position + clicks → LHVM (`GET_HAND_POSITION/STATE`, `GAME_THING_CLICKED`, `POSITION_CLICKED`)
- Script-spawned entities (CREATE, FLOCK_CREATE, LOAD_CREATURE, etc.) appear in the viewer's render list with sensible default meshes from `SCRIPT_OBJECT_TYPE`
- Camera follows LHVM `FOCUS_FOLLOW` / `POSITION_FOLLOW` targets with lerp + shake
- Thrown objects fire `Object::ReactToPhysicsImpact` on neighbours within a speed-scaled blast radius

**Audio**
- Full SAD audio bank decoder — LionHead Pack format with `LHFileSegmentBankInfo` / `LHAudioWaveData` / `LHAudioBankSampleTable` blocks
- 227 samples extracted from `Guidance.sad` plus everything under `SFX/` and `Audio/`
- PCM samples play through `PlaySoundA(SND_MEMORY)`
- MPEG-2 voice samples fall back to MessageBeep tones (real MP2 decoder pending)
- Music: `START_MUSIC` plays `intro.wav` looped via `PlaySoundA`

**Subtitle text**
- `HELP_TEXT_<KEY>_<NN>` keys extracted from SAD sample names → humanized into readable strings (`"Death in village"` etc.) and indexed by sample id
- Subtitle path first checks the HelpText pool, then falls back to LHVM data-section literals

**Persistence**
- Slot-based binary snapshot (`BWSV` magic, v1) with section tags `GTRN`/`ENTS`/`HAND`/`LGLB`/`LINF`
- F5 saves slot 0, F9 loads it
- `SAVE_GAME_IN_SLOT` script native fires real serialization via `g_save_slot_func`

### Phase 0: Reconnaissance — COMPLETE
- [x] Acquire original game files
- [x] Strip SafeDisc 2.10.030 copy protection
- [x] Ghidra disassembly + RTTI scan (14,626 functions, 936 classes)
- [x] Vendor reference integration (bw1-decomp — 569 struct headers)

### Phase 1: Build System & Type Hierarchy — COMPLETE
- [x] CMake build system (Visual Studio 2022, 32-bit x86)
- [x] All 569 vendor types rebuilt as C++ with correct vtable layout
- [x] 500+ method bodies translated from Ghidra
- [x] Building lifecycle, resource management, living state machine
- [x] Map operations, creature AI subsystem structs, GUtils

### Phase 2: Rendering Pipeline — COMPLETE
- [x] L3D / G3D / LND loaders
- [x] DXT1/DXT3 texture rendering
- [x] Mesh browser, world viewer

### Phase 3: Game Loop & Interaction — COMPLETE
- [x] Level script parser
- [x] God hand with picking + throwing physics
- [x] LHVM scripting engine with 464/465 typed natives
- [x] ~430 native bodies wired through LHVMObjects.cpp
- [x] Host integration: hand/click input, spawn render bridge, sim throttle
- [x] HUD overlay with bitmap font
- [x] Animation pipeline (bind pose, procedural, ANM playback, keyframe lerp, script selection)
- [x] Camera follow + shake
- [x] SAD audio bank decoder + PCM playback
- [x] Save/Load (host format)
- [x] HelpText subtitle pipeline (humanized SAD keys)

### Phase 4: Polish & Full Game — IN PROGRESS
- [ ] MP2 decoder so BW voice samples actually play
- [ ] Native BW save format via `GameOSFile` (currently host-snapshot only)
- [ ] PSysManager + real spell particle visuals (currently placeholder rings)
- [ ] Bone-name remap so any ANM plays on any mesh (currently positional)
- [ ] Multiplayer / network stack (stubbed)
- [ ] LHVM physics natives → bw_core forces (currently logical)
- [ ] Computer player AI behaviour
- [ ] Localized text source — currently humanized SAD keys; real strings need MP2-side-channel or community translation

## How to Build & Run

```bash
# Build (requires Visual Studio 2022, CMake 3.20+)
cd src
cmake -G "Visual Studio 17 2022" -A Win32 -S . -B build
cmake --build build --config Release

# View a mesh
build/Release/bw_viewer.exe game_data/A_horse_boned.l3d

# Browse all 626 meshes (Left/Right arrows)
build/Release/bw_viewer.exe game_data/AllMeshes.g3d

# View terrain
build/Release/bw_viewer.exe game_data/Land1.lnd

# World viewer (terrain + entities)
build/Release/bw_viewer.exe game_data/Land1.txt

# Game mode — interactive with god hand + bw_core entities + script execution
build/Release/bw_viewer.exe game_data/Land1.txt --play
```

**Controls (game mode):**
- Mouse — move hand cursor
- LMB on entity — pick up (queries real `CanBePickedUp` from bw_core; also latches a script click)
- Release LMB while moving — fling entity (syncs back to bw_core MapCoords + fires `ReactToPhysicsImpact`)
- RMB while holding — throw forward
- LMB drag (empty space) — orbit camera
- RMB drag — zoom
- Scroll wheel — zoom
- WASD — pan (camera-relative)
- Tab — wireframe toggle
- F1 — HUD overlay toggle
- F5 — quicksave (slot 0)
- F9 — quickload (slot 0)
- R — reset camera
- Esc — quit

## Project Structure

```
bw/
├── README.md                  ← this file
├── CLAUDE.md                  ← Development memory + architecture notes
├── src/
│   ├── CMakeLists.txt         ← Builds bw_core lib + bw_viewer exe
│   ├── include/black/         ← 601 C++ headers (entity classes, vtable layout)
│   │   ├── LHVMObjects.h      ← Script ↔ Object bridge declarations
│   │   └── ...                ← All 569 vendor entity types
│   ├── core/                  ← 253 implementation files
│   │   ├── LHVMObjects.cpp    ← ~430 wired LHVM native bodies (3,900 lines)
│   │   ├── EntityFactory.cpp  ← Creates real entities from level data
│   │   ├── Terrain.cpp        ← Terrain height service
│   │   ├── LHVM.cpp           ← 2700-line VM with 31-opcode dispatch
│   │   ├── Game.cpp           ← GGame::ProcessTurn game loop
│   │   └── ...                ← All 569 entity type implementations
│   └── viewer/                ← OpenGL viewer/game application
│       ├── main.cpp           ← Win32+OpenGL window, render, input, HUD
│       ├── game_loop.cpp      ← Game state, bw_core bridge, hand interaction
│       ├── l3d_loader.*       ← L3D mesh parser with bind-pose preserved
│       ├── g3d_loader.*       ← G3D archive parser (meshes + DXT textures)
│       ├── lnd_loader.*       ← LND terrain heightmap parser
│       ├── script_parser.*    ← Level script entity placement parser
│       ├── animator.*         ← Procedural skeletal animation
│       ├── anm_loader.*       ← ANM file parser (single + Pack archive) + CPU skinning
│       ├── audio.*            ← Audio dispatch (SAD playback + fallback beeps)
│       ├── sad_loader.*       ← LionHead SAD audio bank decoder
│       ├── helptext.*         ← Subtitle string pool
│       ├── save_state.*       ← Slot-based binary save/load
│       └── mesh_names.h       ← 626 mesh name lookup
├── vendor/
│   └── bw1-decomp/            ← 569 decompiled struct headers (reference)
└── game_data/                 ← Your own game data (not included)
    ├── AllMeshes.g3d          ← 626 meshes + 110 textures
    ├── AllAnims.anm           ← ~11k animation frames (Pack archive)
    ├── Land1-5.lnd            ← Campaign terrain files
    ├── Land1-5.txt            ← Level scripts
    ├── Quests/Challenge.chl   ← Compiled script bytecode
    ├── Guidance.sad           ← Voice + SFX audio bank (LionHead Pack)
    └── *.L3D                  ← Individual creature meshes
```

## Legal

This project contains **no copyrighted game assets**. You need your own copy of Black & White to use this. We're reimplementing the engine, not distributing the game.

## Acknowledgments

- **Lionhead Studios** — for making something truly special
- **openblack** — for file format documentation (L3D, G3D, LND, CHL, ANM, Pack/SAD)
- **bw1-decomp** — for 569 decompiled struct headers + chlasm enum tables
- The Black & White community — still keeping the faith after 25 years

---

*"We cracked it open. We stripped its armor. We read its soul. Now we rebuild it."*
