# info.dat: the balance data

`scripts\info.dat` holds every number the simulation runs on: building capacity,
crowding thresholds, decay rates, villager speeds, spell costs, creature tuning.
`src/core/InfoDat.cpp` loads it; `src/include/black/InfoDatLayout.gen.h` is its layout.

## The format has no structure of its own

44-byte header (`LiOnHeAdInfo`, payload size at 0x28), then 102 sections back to back.
No tags, no lengths, no counts. The only description of the layout is the loader,
`sub_425250` in v1.0, so the layout is recovered from that code:

1. Each info class has a reader that copies fixed-size chunks to `element + 16`.
   Many begin by calling a **parent reader** (240 or 244 bytes: the shared object
   block holding the record's name at +8).
2. `work/info_layout.py` (IDA idalib) sums each reader's constant read sizes plus its
   parents, in the loader's order, with each array's count and element stride.
3. `work/info_walk.py` walks the real file with that layout.
4. `work/gen_infodat.py` emits the C++ header.

```
py -3.11 work/info_layout.py E:\ida\work\bw.exe.i64   # payload bytes: 580710 sections: 102
py -3 work/info_walk.py                               # end 580754 file 580754 OK
py -3 work/gen_infodat.py                             # 102 sections, 580710 payload bytes -> ...
```

The extractor's sum equals the size field in the file's own header (580,710), and the
walk ends on the file's last byte. The names line up too: in every one of the 600+
records built on the shared block, the name sits at +8 (`DETAIL_ABODE_INFO[0]` "Celtic
Hut" to `[146]` "Bell Tower").

## Why it looked like the wrong file

An earlier count got 276 KB of 580 KB and blamed a later game build. The v1.2 patch
(`BWPatch-V100-V102.rtp`) refutes that: its header gives the v1.0 sizes it patches from,
and they are ours (`info.dat` 580,754 → 582,066; `runblack.exe` 8,500,623 → 9,993,917).
The missing 304 KB had two causes:

- **The count only included the 65 `DETAIL_*` tables.** Before those tables the loader
  reads 33 per-class arrays: Abode, Villager, Animal, Creature, magic and so on. These
  hold 231 KB.
- **Parent readers were missed**, and only for some callers. IDA retypes a function as
  `__thiscall` once it has decompiled it, so the same call prints as `sub_X(a2)` or
  `sub_X(this, a2)` depending on decompile order. A pattern for only the first form
  undercounted at random. Match the file argument in any position, and only in the
  function body: the signature line names `a2` too.

## In memory

Each record goes to `+16` of an element at the original stride. The first 16 bytes are
the `GBaseInfo` header:
`{vftable, 0, next, index}`. `next` links every info into one list and `index` numbers
them in load order (`sub_4304A0`). So `info + 0x120` reads what the original read:
Celtic Wonder's `abodeType` comes out as 0x100, the `ABODE_TYPE_WONDER` value
`Abode.cpp` already compares against.

The loader refuses a file whose payload size disagrees with the layout. A partial
load would hand out wrong numbers, which is worse than none.

## Objects get their record

`EntityFactory` sets `Object::info`. Level scripts name the type, and CHL's `CREATE`
passes the `*_INFO` enum, which is the record index:

| Source | Example | Resolved by |
|---|---|---|
| `CREATE_ABODE` | `"NORSE_ABODE_C"` | `FindAbode`: tribe 7 + tag `ABODE_C` from the record's own fields (display names repeat, e.g. "Town Centre") |
| `CREATE_VILLAGER_POS` | `"CELTIC_FORESTER"` | `FindByName`: "Celtic Forester Male" |
| `CREATE_NEW_FEATURE` | `"Aztec Statue Feature"` | `FindByName` |
| `CREATE_NEW_TREE`, `_ANIMAL`, `_MOBILE_STATIC` | `3` | the index |
| CHL `CREATE(type, subtype)` | `ABODE_INFO_*` | the index |

`test_infodat` checks that all 1,218 type names in Land1-5 resolve, and `test_spawn` that
Land 1's 1,853 entities spawn (1,849 with a record; the other four are the viewer
parser's `TOWN_CENTRE`/`BONFIRE` placeholders, which name no record).
