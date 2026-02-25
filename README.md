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

### Phase 0: Reconnaissance 🔍
- [x] Acquire original game files
- [ ] Unpack and inventory game data (textures, models, scripts, audio)
- [ ] Identify executable format and protections
- [ ] Initial disassembly / decompilation pass (Ghidra / IDA)
- [ ] Map out major subsystems (renderer, physics, AI, scripting, audio)
- [ ] Document the original engine architecture

### Phase 1: Skeleton 🦴
- [ ] Set up build system (CMake)
- [ ] Create stub implementations for all major subsystems
- [ ] Get a window open with the game's splash screen
- [ ] Load and parse game data files

### Phase 2: The Hand of God 🖐️
- [ ] Implement the renderer (terrain, sky, water, creatures)
- [ ] Input system (the iconic hand!)
- [ ] Basic world loading and navigation

### Phase 3: Let There Be Life 🐄
- [ ] Creature AI and learning system
- [ ] Villager simulation
- [ ] Belief / alignment system
- [ ] Scripting engine (original game scripts)

### Phase 4: Polish & Miracles ✨
- [ ] Audio engine
- [ ] Multiplayer (the original had it!)
- [ ] Modding support
- [ ] Quality-of-life improvements the original desperately needed

## Project Structure

```
bw/
├── README.md          ← You are here
├── .gitignore
├── docs/              ← Research notes, engine docs, file format specs (coming soon)
├── src/               ← Recompiled source code (coming soon)
├── tools/             ← Asset extraction & analysis utilities (coming soon)
└── assets/            ← Extracted game data (not checked in — bring your own disc!)
```

## How to Help

This is early days. If you:
- Have experience with reverse engineering x86 binaries
- Know your way around Ghidra, IDA, or Binary Ninja
- Have worked with DirectX 7/8 era rendering
- Just really love Black & White and want to see it live again

...then welcome aboard. Open an issue, submit a PR, or just come lurk.

## Legal

This project contains **no copyrighted game assets**. You need your own copy of Black & White to use this. We're reimplementing the engine, not distributing the game.

This is a clean-room-ish effort — we're studying the binary to understand behavior, then writing new code that produces the same results. Think of it as translating a book from Ancient x86 to Modern C++.

## Acknowledgments

- **Lionhead Studios** — for making something truly special
- **Peter Molyneux** — for dreaming bigger than any engine could handle (as usual)
- The Black & White community — still keeping the faith after 25 years
- Everyone who has ever tried to get this game running on Windows 10 and lived to tell the tale

---

*"We will make this game run again. We have the technology. We have the stubbornness."*
