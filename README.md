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
- Modern graphics backend (OpenGL now, Vulkan/D3D12 later)
- No emulation layers, no compatibility shims, no crying into WinXP VMs at 2 AM
- Same gameplay, same hand-slapping-villagers goodness — just actually functional

## Current Status

**595 headers | 247 implementations | ~35,000 lines of C++ | 115 commits**

**Working right now:** A playable prototype that loads the original game data, renders the terrain with textured buildings and trees, and lets you pick up and throw entities with the god hand. The core B&W interaction loop — hover, grab, fling — works.

### Phase 0: Reconnaissance — COMPLETE

- [x] Acquire original game files
- [x] Strip SafeDisc 2.10.030 copy protection
- [x] Ghidra disassembly + RTTI scan (14,626 functions, 936 classes)
- [x] Vendor reference integration (bw1-decomp — 569 struct headers)

### Phase 1: Build System & Type Hierarchy — COMPLETE

- [x] CMake build system (Visual Studio 2022, 32-bit x86)
- [x] All 569 vendor types rebuilt as C++ classes with correct vtable layout
- [x] ~220 method bodies translated from Ghidra decompilation
- [x] Building lifecycle: IsFunctional, IsBuilt, BuildBy, Built, Repaired
- [x] Resource delegation, influence calculation, repair/damage systems

### Phase 2: Rendering Pipeline — COMPLETE

- [x] **L3D mesh loader** — parses Lionhead's proprietary mesh format with bone transforms
- [x] **G3D archive loader** — loads AllMeshes.g3d (622/626 meshes, 111K verts, 101K tris)
- [x] **DXT1/DXT3 texture rendering** — compressed textures via S3TC OpenGL extensions
- [x] **LND terrain renderer** — heightmap loading, altitude-based coloring, 17×17 cell blocks
- [x] **Mesh browser** — browse all 626 game meshes by name with Left/Right arrows

### Phase 3: Game Loop & Interaction — IN PROGRESS

- [x] **Level script parser** — extracts entity positions from Land*.txt files
- [x] **World viewer** — terrain + buildings + trees + villagers + animals placed from scripts
- [x] **God hand** — spell hand mesh follows cursor, hovers over terrain
- [x] **Entity interaction** — pick up trees/villagers/animals, fling with mouse velocity
- [x] **Throw physics** — gravity, ground collision, bounce damping
- [x] **Camera-relative controls** — WASD moves relative to view direction
- [ ] Creature spawning and AI
- [ ] Town simulation (resource gathering, building)
- [ ] LHVM scripting engine (level logic)

### Phase 4: Full Game
- [ ] Complete GGame loop (ProcessTurn, entity ticking)
- [ ] Audio engine
- [ ] Multiplayer
- [ ] Modding support

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

# Game mode — interactive with god hand!
build/Release/bw_viewer.exe game_data/Land1.txt --play
```

**Controls (game mode):**
- Mouse — move hand cursor
- LMB on entity — pick up (trees, villagers, animals)
- Release LMB while moving — fling entity
- RMB while holding — throw forward
- LMB drag (empty space) — orbit camera
- RMB drag — zoom
- Scroll wheel — zoom
- WASD — pan (camera-relative)
- Tab — wireframe toggle
- R — reset camera
- Esc — quit

## Project Structure

```
bw/
├── README.md
├── src/
│   ├── CMakeLists.txt         ← Builds bw_core lib + bw_viewer exe
│   ├── include/black/         ← 595 C++ headers (entity classes, vtable layout)
│   ├── core/                  ← 247 implementation files (method stubs + bodies)
│   └── viewer/                ← OpenGL viewer/game application
│       ├── main.cpp           ← Win32+OpenGL window, rendering, input
│       ├── l3d_loader.*       ← L3D mesh parser with bone transforms
│       ├── g3d_loader.*       ← G3D archive parser (meshes + DXT textures)
│       ├── lnd_loader.*       ← LND terrain heightmap parser
│       ├── script_parser.*    ← Level script entity placement parser
│       ├── game_loop.*        ← Game state, hand interaction, physics
│       └── mesh_names.h       ← 626 mesh name lookup (from AllMeshes.h)
├── vendor/
│   └── bw1-decomp/            ← 569 decompiled struct headers (reference)
├── work/
│   ├── decompiled/            ← 268 Ghidra auto-decompiled .c files (77K lines)
│   ├── functions.csv          ← 14,277 function addresses
│   └── vtable_matches.csv    ← 65K vtable entries
└── game_data/                 ← Your own game data (not included)
    ├── AllMeshes.g3d          ← 626 meshes + 110 textures
    ├── Land1-5.lnd            ← Campaign terrain files
    ├── Land1-5.txt            ← Level scripts
    └── *.L3D                  ← Individual creature meshes
```

## Legal

This project contains **no copyrighted game assets**. You need your own copy of Black & White to use this. We're reimplementing the engine, not distributing the game.

## Acknowledgments

- **Lionhead Studios** — for making something truly special
- **openblack** — for file format documentation (L3D, G3D, LND)
- **bw1-decomp** — for 569 decompiled struct headers
- The Black & White community — still keeping the faith after 25 years

---

*"We cracked it open. We stripped its armor. We read its soul. Now we rebuild it."*
