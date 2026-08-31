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

### Where they are filled from

`sub_425250` is the info loader. It opens `scripts\info.dat`, compares its
timestamp against `balance.cpp` and `scripts\info.txt`, and either streams the
binary or re-parses the text. `game_data/info.dat` ships — 580,754 bytes, magic
`LiOnHeAdInfo`, dated 5 Mar 2001 — so the tuning is on disk, just not in the
executable.

It registers **65 named tables** in one pass, each as
`load(file, "DETAIL_...", &table, count, from_binary)`; the names are resolved in
`work/decomp/info_sections.txt` and the full list with counts and record sizes
in `work/decomp/info_layout.txt`. The creature ones:

    DETAIL_CREATURE_ACTION                        328 x 268
    DETAIL_CREATURE_DESIRE_DEPENDENCIES            40 x 176
    DETAIL_CREATURE_DESIRE_TABLE                   40 x 448
    DETAIL_CREATURE_DESIRE_SOURCE_TABLE            61 x 164
    DETAIL_CREATURE_DESIRE_SOURCE_THRESHOLD_BOUNDS 61 x  28

**This settles the `GBaseInfo` question.** Each loader copies its payload to
`record + 16`: the source-bounds loader moves 12 bytes into a 28-byte record,
the desire-table loader 432 into 448. So `GBaseInfo` is a 16-byte header and the
payload follows it — which is exactly why both our headers and the vendor's had
every one of these at 0x10. Twelve of them are corrected in `src/include/black/`
to their real sizes with an opaque payload; the sizes are now right even though
the field layouts are not yet recovered.

### The binary path, and why the sizes do not reconcile

`sub_72D2F0(buf, n, -1)` reads and `sub_72D2B0(buf, n)` writes, so the fifth
argument to each loader selects direction: with a current `info.dat` the game
streams fixed-size records straight out of it, and when the `.dat` is stale it
looks each record up by name in the parsed `info.txt` tree and writes the `.dat`
back. Records are fixed size with no embedded lengths — `sub_429AD0` reads 4
then 376 bytes and checks the total came to 380.

Chased the accounting to the end and it does not close:

* The 65 registrations read **276,264 bytes**; `info.dat` is **580,754**.
* 26 of the 61 loaders do two reads per record, not one — that correction is in
  the figure above (it was 270,442 before).
* The other 38 `DETAIL_` call sites are three-argument `sub_5B1630` lookups —
  the text path for the magic info, with no binary read.
* Cross-referencing all 61 loaders, and everything that calls `sub_5B1630`,
  finds exactly one caller: `sub_425250`. There is no second registrar.
* ASCII runs are spread evenly across all 580 KB, so it is not fixed tables
  followed by a string region.

The most likely explanation is that the shipped `info.dat` does not belong to
this executable. `runblack_decrypted.exe` is v1.0; `info.dat` is dated 5 Mar
2001, and the `CreatureMind` files in the same install run to version 30 while
the mind loader's gates stop at 0x20. A later build's data with more or larger
tables would read as exactly this: a consistent format, a correct loader, and
twice as many bytes as v1.0 knows how to consume.

That is a hypothesis, not a finding. Testing it needs a v1.0-era `info.dat`, or
the record layouts pinned down well enough to walk the file and see where it
stops making sense. Either way, a reader written against the v1.0 registrar
would be reading the wrong file, so none is written.

**The tables are `.bss`.** Dumping `unk_BA6310` gives 0xFFFFFFFF across every
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
