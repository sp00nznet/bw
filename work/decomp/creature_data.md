# Where the creature's configuration actually lives

Reconnaissance, not translation. Recorded so the next pass starts from facts.

## The tuning tables are not in the executable

Fifteen creature config tables are reachable through a uniform accessor: every
`GBaseInfo`-derived record class puts `{ *count = N; return &table; }` in vtable
slot 9, and the record size falls out of its `operator delete(this, size)` in
slot 1. Extracted from `work/decomp/creature_ai.txt`:

| class | count | record | table |
|---|---|---|---|
| CreatureActionInfo | 328 | 268 | `unk_B8DD10` |
| CreatureInfo | 17 | 916 | `unk_B81CE8` |
| CreatureInitialDesireInfo | 40 | 448 | `unk_B89710` |
| CreatureDesireDependency | 40 | 176 | `unk_BA7030` |
| CreatureDesireSourceTable | 61 | 164 | `unk_BAC0C0` |
| CreatureDesireActionEntry | 40 | 136 | `unk_B881D0` |
| CreatureDevelopmentPhaseEntry | 14 | 132 | `unk_BA5BD8` |
| CreatureMagicActionKnownAboutEntry | 6 | 112 | `unk_BCC240` |
| CreatureActionKnownAboutEntry | 6 | 104 | `unk_BCC240` |
| CreatureDesireForType | 40 | 84 | `unk_BA6310` |
| CreatureInitialSourceInfo | 61 | 84 | `unk_BAACB8` |
| CreatureMimicInfo | 46 | 192 | `unk_BCC4F0` |
| CreatureDevelopmentDurationEntry | 17 | 72 | `unk_BA5710` |
| CreatureDesireAttributeEntry | 40 | 56 | `unk_B87910` |
| CreatureSourceBoundsInfo | 61 | 28 | `unk_BAA608` |

The counts corroborate the enums: 40 = `NUM_CREATURE_DESIRES`, 328 =
`NUM_CREATURE_ACTIONS`, 17 = creature species, 61 = the desire-source table.

**But the tables are `.bss`.** Dumping `unk_BA6310` gives 0xFFFFFFFF across every
record — slot 8 is a `-1` initialiser, not shipped data. The configuration is
loaded at runtime, so there is nothing to read out of the executable and the
record layouts have to come from whatever fills them.

Worth noting: our headers *and* the vendor's have all of these at 0x10
(`GBaseInfo` only). That is the RTTI wrapper; the 56-to-916-byte payload was
never mapped by either. The sizes above are the first hard evidence of it.

## The creature's mind ships as data

`game_data/CreatureMind/` holds eight pre-trained minds:

| file | bytes | version word |
|---|---|---|
| ComputerControlledCreature | 5,748 | 30 |
| CreatureDestroyOtherCreatures | 54,244 | 17 |
| CreatureDestroyTowns | 54,244 | 17 |
| CreatureImpressTowns | 61,444 | 17 |
| CreatureProtectTowns | 130,164 | 17 |
| KhazarCreature | 5,268 | 25 |
| LethysCreature | 5,268 | 25 |
| NemesisCreature | 5,268 | 25 |

All dated 21 Feb 2001.

The loader is `sub_4C7CF0`. It formats `.\Scripts\CreatureMind\%s` (and
`Physique%s` for a second file) and reads through `sub_72BE50` — the same
`GameOSFile` read primitive Phase 7 is built on, so the object graph and
ordinal machinery in `src/core/SaveLoad.cpp` is the right substrate for this.

In the version-25 files the layout is legible by inspection: a 4-byte version,
a 32-byte block, a length-prefixed UTF-16 name (all three read `"Matey"`), then
`40` — `NUM_CREATURE_DESIRES` — followed by per-desire records of an index and
three floats.

### The format, recovered

The stream is flat little-endian, read sequentially through three primitives on
a 1024-byte buffered reader (confirmed by disassembly — cursor at `+0x50C`,
buffer at `+0x10C`, refilled by `sub_6AB2E0` when a read would pass 1024):

| primitive | bytes |
|---|---|
| `sub_6AB4B0` | 1 |
| `sub_6AB4F0` | 2 |
| `sub_6AB530` | 4 |

Versioning is one global, `dword_BCC4D4`, with gates wrapping the fields each
revision added — `version >= 0x11`, `>= 0x18`, `< 7`, and so on. That makes the
format recoverable the same way the save tables were: read the ordered sequence
of primitive calls and note the gate each sits under.

`work/parse_mindreader.py` does exactly that; `work/decomp/mind_format.txt` is
its output. The top-level deserializer is `sub_4C95D0` — **54 reads, 20 of them
version-gated, 27 inside loops**, across 14 distinct gates from `< 7` up to
`>= 0x20`. Five nested deserializers add 23 more.

Its first two reads are a 4-byte count then that many 2-byte characters: the
creature's name, length-prefixed UTF-16. That checks out against the files —
offset 36 in the version-25 minds (`"Matey"`, all three) and offset 40 in the
version-30 one (`"Richard"`), the four-byte shift being a field the loader
prologue gained between those revisions.

Also in the loader: `sub_4C9460` reads two length-prefixed byte blocks and puts
each through `LHVersion::DecryptBlock`, then compares one against
`LHNetGetCurrentUsedProfile` — the 28 bytes of high-entropy data at offset 8 in
every file. The minds are profile-stamped.

**Still not written as a reader, deliberately.** The grammar above is real, but
a reader has to consume it in exactly the right order across all three versions,
and the failure mode is silent: plausible floats in the wrong fields. The next
step is to drive `work/decomp/mind_format.txt` against the eight shipped files
and require that every one parses to exactly its own length — that is the check
that makes it safe, and it has not been run yet.

## Why this matters for the learning code

`src/core/CreatureLearner.cpp` implements the induction exactly, but a creature
in the real game does not start from nothing: it loads one of these minds, and
the desire tables above supply the weights that turn a desire into an action.
Those two are what stand between the algorithm working (which it does, see
`test_learning`) and a creature behaving like a Black & White creature.
