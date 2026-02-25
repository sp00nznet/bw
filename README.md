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

### Phase 0: Reconnaissance — COMPLETE

- [x] Acquire original game files
- [x] Unpack and inventory game data (textures, models, scripts, audio)
- [x] Identify executable format and protections
- [ ] Initial disassembly / decompilation pass (Ghidra / IDA)
- [x] Map out major subsystems (renderer, physics, AI, scripting, audio)
- [ ] Document the original engine architecture

### Phase 1: Skeleton
- [ ] Set up build system (CMake)
- [ ] Create stub implementations for all major subsystems
- [ ] Get a window open with the game's splash screen
- [ ] Load and parse game data files

### Phase 2: The Hand of God
- [ ] Implement the renderer (terrain, sky, water, creatures)
- [ ] Input system (the iconic hand!)
- [ ] Basic world loading and navigation

### Phase 3: Let There Be Life
- [ ] Creature AI and learning system
- [ ] Villager simulation
- [ ] Belief / alignment system
- [ ] Scripting engine (original game scripts)

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
| Entry point | `0xAE61FD` |
| .text section | 4.0 MB of code |
| .data section | 5.9 MB virtual (2.5 MB on disk) |
| Total image size | 10.9 MB |

**The kicker:** Only **6 imports** from 2 DLLs (`KERNEL32.dll` and `USER32.dll`). The functions are `GetModuleHandleA`, `GetProcAddress`, `GlobalAlloc`, `GlobalFree`, `ExitProcess`, and `MessageBoxA`. That's it. The game loads everything else at runtime via `GetProcAddress`. This is almost entirely statically linked — the whole engine is in this one EXE.

**Copy Protection:** SafeDisc v1. The telltale signs:
- `SELFMOD` section — self-modifying code for anti-debug
- `stxt774` and `stxt371` sections — encrypted code stubs
- `BoG_` signature at offset `0xFD4`
- `secdrv.sys` driver on disc

SafeDisc is well-understood and its encryption has been thoroughly documented. The protection needs to be bypassed/removed before meaningful disassembly can begin, but this is a solved problem.

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
├── README.md           ← You are here
├── .gitignore
├── tools/              ← Asset extraction & analysis utilities
│   ├── bin2iso.js      ← BIN/CUE to ISO converter
│   └── extract_all_v4.js ← InstallShield CAB extractor
├── docs/               ← Research notes, file format specs (coming soon)
├── src/                ← Recompiled source code (coming soon)
└── game_data/          ← Extracted game data (not checked in — bring your own disc!)
    ├── *.h             ← Original Lionhead headers (gold dust)
    ├── *.l3d           ← 3D models
    ├── *.lnd           ← Landscape files
    ├── *.sad           ← Audio banks
    ├── *.txt           ← Level scripts
    ├── Audio/          ← Music (alignment, chant, citadel, script)
    ├── Meshes/         ← 3D mesh data
    ├── CreatureMind/   ← Creature AI definitions
    ├── Dance/          ← Dance choreography data (34 dance types!)
    ├── Playgrounds/    ← Multiplayer maps
    ├── Quests/         ← Quest data
    ├── SFX/            ← Sound effects (atmos, creature, game, script)
    ├── Spells/         ← Spell effect data
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

1. **Strip SafeDisc protection** from `runblack.exe` to get a clean binary for disassembly
2. **Load into Ghidra** and begin function identification (the 6-import stub makes this interesting)
3. **Document file formats** — L3D (3D models), LND (landscapes), SAD (audio), the .zzz archives
4. **Build a script parser** for the level definition files
5. **Prototype a renderer** — get terrain rendering with modern D3D11/Vulkan

## Legal

This project contains **no copyrighted game assets**. You need your own copy of Black & White to use this. We're reimplementing the engine, not distributing the game.

This is a clean-room-ish effort — we're studying the binary to understand behavior, then writing new code that produces the same results. Think of it as translating a book from Ancient x86 to Modern C++.

## Acknowledgments

- **Lionhead Studios** — for making something truly special, and for shipping source headers in your game data like absolute legends
- **Peter Molyneux** — for dreaming bigger than any engine could handle (as usual)
- The Black & White community — still keeping the faith after 25 years
- Everyone who has ever tried to get this game running on Windows 10 and lived to tell the tale

---

*"We cracked it open. We know what's inside. Now we rebuild it."*
