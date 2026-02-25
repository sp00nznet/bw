# Black & White v1.0 — Phase 1 Analysis Report

**Date:** 2026-02-25
**Binary:** runblack_decrypted.exe (v1.0, built 2001-03-09, MSVC 6)
**Image Base:** 0x00400000 | **Entry Point:** 0x00737B8E (WinMainCRTStartup)

---

## 1. Binary Statistics

| Metric | Value |
|--------|-------|
| Total functions | 13,073 |
| Unnamed (FUN_) | 12,389 (94.8%) |
| Named (RTTI/CRT) | 234 (1.8%) |
| Thunk functions | 100 |
| Imports (external) | 350 (pending recount) |
| C++ classes (RTTI) | 936 |
| Defined strings | 6,769 |
| Total code size | ~2.5 MB |
| Average function size | 203 bytes |
| .text section | 4.0 MB |
| .data section | 5.9 MB virtual |
| Image size | 10.9 MB |

## 2. Class Hierarchy (from RTTI — 936 classes)

### Core Entity Hierarchy
```
Base
└── GameThing
    └── GameThingWithPos
        ├── Object
        │   ├── Fixed
        │   │   └── MultiMapFixed
        │   │       └── Abode (+ PlannedAbode, Windmill)
        │   ├── MobileObject
        │   │   ├── MobileStatic
        │   │   └── MobileWallHug
        │   │       └── Living
        │   │           ├── Animal (Cow, Sheep, Horse, Pig, Tortoise, etc.)
        │   │           ├── Creature (Tiger, Horse, Leopard, etc.)
        │   │           └── Villager (+ SpecialVillager)
        │   ├── Arrow, Ball, Fragment, PileResource, Pot
        │   └── Tree (+ DeadTree, FelledTree)
        ├── Spell (SpellForest, SpellHeal, SpellSeed, etc.)
        ├── SpellIcon, TownSpellIcon, WorshipSpellIcon
        ├── Town, TownCentre, WorshipSite, Citadel
        ├── Forest, BigForest, Field, FishFarm
        └── Flock, Football, Bonfire, Arena
```

### Key Subsystem Classes
- **Creature AI:** CreatureMental, CreaturePhysical, CreaturePlan, CreatureAgenda, CreatureDatabase, CreatureLearning, CreatureBeliefs (23+ Creature* classes)
- **Particle System:** PSysManager, PSysHandFX, Particle3D*, ParticleCreator variants (50+ classes)
- **Camera:** CameraMode, CameraModeFree, CameraModeFollow, CameraModeScript, etc.
- **UI/Frontend:** SetupControl, SetupButton, SetupSlider, DialogBox*, MainMenu, FrontEnd
- **Spells:** Spell, MagicFireBall, MagicFood, MagicTree, MagicTeleport, SpellCreature
- **Audio:** LH_AudioSystem, LH_AudioBank, SoundTag, LHChannel
- **Multiplayer:** BWLan, BWGameSpy, MPFE*, LHSession, LHTransport
- **Scripting:** GScript, ScriptManage, ScriptHighlight, ScriptMarker

## 3. Original Header File Enums (1,468 entries)

| File | Enum | Count | Maps To |
|------|------|-------|---------|
| AllMeshes.h | MESH_LIST | 628 | 3D model indices |
| AllMeshes.h | ANIM_LIST | 446 | Animation indices |
| SoundAction.h | LHSoundAction | 158 | Action/spell sounds |
| ScriptSfxEnum.h | LH_SCRIPT_SAMPLE | 153 | Script SFX triggers |
| SoundObject.h | LHSoundObject | 44 | Entity sound profiles |
| LHAction.h | LHSample | 39 | Creature body sounds |

## 4. File Format Specifications

### L3D (3D Model) — Magic: "L3D0"
- Header: 4-byte magic + 4-byte flags + 4-byte size + 4-byte submesh count
- Flags bitfield controls: normals, materials, bones/skinning, transparency
- Vertex formats: Basic (24B), Textured (32B), Skinned (48B+)
- Index data: uint16 triangle lists
- Fully documented by openblack project

### G3D (Mesh Pack) — Magic: "LiOnHeAd"
- Container for DXT1/DXT3 textures + INFO section + MESHES section
- MESHES section has "MKJC" marker, contains all 626 embedded L3D meshes

### LND (Landscape) — Binary
- 17x17 cell grid blocks, heightmap-based terrain
- Height unit: 0.67f (altitude 255 ≈ 170.85 world units)
- Includes bumpmap and noisemap (65536 bytes each)

### .zzz (Compressed) — Trivial
- 4-byte little-endian decompressed size + zlib data

### CHL (Challenge/Script) — LHVM Bytecode
- Stack-based VM, 31 opcodes, 465 native functions
- Data types: int, float, vector (3 floats), bool
- Version 7 for BW1

## 5. Level Script System

- **46 unique commands** in text-based world layout scripts
- Declarative only (no control flow) — defines initial world state
- Game logic handled by compiled LHVM bytecode in challenge.chl
- 8 tribes: NORSE, CELTIC, AZTEC, JAPANESE, INDIAN, TIBETAN, AFRICAN, EGYPTIAN
- 8 players: PLAYER_ONE through PLAYER_SEVEN + NEUTRAL

## 6. External Resources Assessment

### bw1-decomp (github.com/openblack/bw1-decomp)
- **569 header files** with struct/class definitions — DIRECTLY APPLICABLE
- ~5% decompiled to C, 95% still assembly
- Targets v1.20 (our binary is v1.0)
- `globals.h`: 190+ address-mapped globals
- `libs/chlasm/`: CHL script assembler/disassembler
- `libs/lhall/released/headers/`: Lionhead library headers

### openblack (github.com/openblack/openblack)
- Modern C++ reimplementation, 1500+ stars
- Production-quality format parsers (L3D, LND, G3D, ANM)
- 15-page wiki with format documentation
- Full LHVM specification

## 7. Version Cross-Reference (v1.0 vs v1.20)

**Data section offsets are NOT constant** — the section was rearranged between versions:
- GAlignmentInfo: offset 0xD08F8
- GAnimalInfo through Animal: offset 0xD11B0 (consistent for this range)
- Creature: offset 0xCAC68 (different!)

**Strategy: Match by class name, not address offset.**
- 936 RTTI classes in v1.0 can be matched to bw1-decomp's hierarchy by name
- Vtable layouts (virtual function order) should be identical
- Struct definitions from bw1-decomp apply directly

## 8. Recommended Phase 2 Approach

### Immediate Actions
1. **Import bw1-decomp headers into Ghidra** as data types (569 struct definitions)
2. **Write a vtable matcher** that finds vtables in our binary using RTTI, then names virtual functions using bw1-decomp's vtable layouts
3. **Apply globals mapping** — adapt bw1-decomp's globals.h addresses to v1.0 using RTTI anchor points

### Subsystem Priority (by dependency)
1. **GameThing hierarchy** — base entity system, everything inherits from this
2. **Script/LHVM engine** — drives game logic
3. **Landscape/Terrain** — rendering foundation
4. **3D mesh loading** — L3D/G3D asset pipeline
5. **Creature AI** — the game's signature feature
6. **Audio** — LH_AudioSystem integration
7. **Multiplayer** — MPFE/network stack (lowest priority)

### Build Strategy
- Use openblack's format parsers as reference implementations
- Port subsystem by subsystem, testing against original game data
- Target modern API (D3D11 or Vulkan) instead of original DirectDraw/D3D7

## 9. Files Produced This Session

| File | Contents |
|------|----------|
| work/functions.csv | 12,723 functions (addr, name, size, namespace) |
| work/rtti_classes.csv | 936 RTTI type descriptors (addr, class name) |
| work/scripts/ExportFunctions.java | Ghidra function export script |
| work/scripts/FindRTTI.java | Ghidra RTTI finder script |
| vendor/bw1-decomp/ | Cloned decompilation project |
