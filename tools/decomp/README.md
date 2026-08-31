# BW decompilation pipeline (class → pseudocode)

Recovers C pseudocode for the original game's class methods, to translate into
`src/`. Two independent decompilers (IDA primary, Ghidra cross-check) so any
non-trivial body can be diffed for confidence.

## The key constraint

`game_data/runblack_decrypted.exe` (v1.0; identical to `..._v100.exe`) is a
**release build with full RTTI but NO symbol table**: 17,627 functions, only 5
named. You therefore **cannot** find a class's methods by name — the old
`GhidraDecompileByName.java` matched `Save` against `?Save@PSysManager@@…` and
returned NOT FOUND for everything.

What *is* present is MSVC RTTI (900 class descriptors). The RTTI analyzers in
both IDA and Ghidra label each class vftable from its type descriptor
(`??_7PSysManager@@6B@`). So the reliable path is:

```
class name --RTTI--> vftable label --read ptrs--> method addresses --decompile-->
```

Slot order == vtable order, so slot *i* pairs 1:1 with the *i*-th virtual method
in the vendor header at `vendor/bw1-decomp/black/<Class>.h`. That gives every
slot a name, signature, and the binary's own v1.0 address (sidestepping the
vendor headers' v1.41 address mismatch).

> Non-virtual members aren't in any vtable; reach them via xrefs from the
> virtual bodies once you're translating a class.

## IDA (primary) — `bw_decomp.py`

IDA Professional 9.1 idalib (see `E:\ida\IDA-HEADLESS.md`). First run on the
`.exe` analyses + writes a `.i64`; pass that `.i64` afterwards for a fast
(~20 s) reopen.

```powershell
# one-time: analyse + cache (copy keeps game_data clean)
copy G:\recomp\pc\bw\game_data\runblack_decrypted.exe E:\ida\work\bw.exe
py -3.11 bw_probe.py E:\ida\work\bw.exe              # sanity: names + a vftable walk

# extract: decompile every class in the list (uses the cached .i64)
py -3.11 bw_decomp.py E:\ida\work\bw.exe.i64 classes <classlist.txt> <out.txt>
py -3.11 bw_decomp.py E:\ida\work\bw.exe.i64 vtable  PSysManager      # one class to stdout
py -3.11 bw_decomp.py E:\ida\work\bw.exe.i64 addr    0x53e870 ...      # ad-hoc addresses
```

Walk boundary: the table stops at the next `??_7…` vftable address (all are
indexed up front), so it never bleeds into the adjacent class. Large counts are
real — `PSysManager`/`AtomCore`/etc. share a deep base, so 63-entry vtables
(many inherited no-op stubs at `0x4017d0`/`0x403c20`) are expected.

## Ghidra (cross-check) — `GhidraDumpClass.java`

Same RTTI-vftable walk against the pre-analysed project at
`work/ghidra_project` (binary `runblack_decrypted.exe`). Ghidra at
`C:\tools\ghidra\ghidra_12.0.3_PUBLIC`.

```bash
/c/tools/ghidra/ghidra_12.0.3_PUBLIC/support/analyzeHeadless.bat \
  G:/recomp/pc/bw/work/ghidra_project BlackAndWhite \
  -process runblack_decrypted.exe -noanalysis \
  -scriptPath G:/recomp/pc/bw/work \
  -postScript GhidraDumpClass.java <classlist.txt> <out.txt>
```

> **Status (2026-06-04): the existing project has 0 vftable labels** — its
> import never ran the "Windows x86 PE RTTI Analyzer", so the script reports
> `(no vftable)` for every class. To enable the cross-check, re-analyse the
> binary with RTTI on (`analyzeHeadless … -import … -preScript`/analysis
> options, or in the GUI: Analysis ▸ "Windows x86 PE RTTI Analyzer" +
> "Decompiler Switch/Function ID"), then re-run. Until then **IDA is the sole
> working extractor** — which is sufficient; Ghidra is only the second opinion.

## Validation (2026-06-04)

IDA run over 16 core particle classes → `work/decomp/psys_atoms.txt`, 580 slots,
14/16 classes. Sample (`AppearanceRuleFadeOut`): the vtable-setting ctor,
`++this[6]`/`--this[6]` Enter/Exit ref-counting, and a slot passing `"Vanishage"`
+ float `100.0` — directly translatable. This is the input for the Phase 7
(Save/Load) and 5B-scope-A (Atom engine) / 6C-faithful translation workflows.

## Slot-filtered extraction

`classes` takes an optional list of slot indices, so a single concern can be
pulled across every class without decompiling whole vtables:

```powershell
# Load/Save/GetSaveType/SaveExtraData for all 200 savable classes (~2 min)
py -3.11 bw_decomp.py E:\ida\work\bw.exe.i64 classes save_classes_all.txt save_slots.txt 58 59 60 61
```

## Phase 7: save format pipeline

The save/load bodies are all the same shape (delegate to the parent, then run a
list of field writes), so they are extracted as *data* rather than translated
one by one:

```bash
py -3.11 bw_decomp.py <i64> classes work/decomp/save_classes_all.txt work/decomp/save_slots.txt 58 59 60 61
py -3.11 bw_decomp.py <i64> addr <ancestor addrs...>  > work/decomp/save_parents.txt
python work/parse_saveslots.py     # -> work/decomp/save_table.json  (+ coverage report)
python work/gen_saveload.py        # -> src/core/SaveLoadTable.gen.cpp, work/decomp/save_ids.txt
python work/apply_save_ids.py      # stamps GetSaveType() ids across src/
```

`parse_saveslots.py` prints which class rows it could not model exactly; those
are marked in the table and the runtime refuses them (see SaveLoadTable.h).


## When a region is invisible: `mkfunc`

Several of this binary's dispatch tables are `.bss`, filled by long inlined
initialisers that IDA never recognised as functions. That is worse than it
sounds, because everything else here -- `xrefs`, `callees`, `addr` -- is
function-scoped. A table filled that way looks like it has *no writer at all*:
`xrefs` on it returns nothing, and the natural conclusion is that the data must
come from somewhere else entirely.

```bash
py -3.11 bw_decomp.py <i64> mkfunc 0x47F000 0x484000
```

forces the range to code and creates functions over it, then saves the `.i64`
so it sticks. Regions that came back empty before start decompiling.

Two that needed it:

| range | what it turned out to be |
|---|---|
| `0x47F000..0x484000` | the creature action table's initialiser (`sub_48004C`, 1513 lines) |
| `0x570700..0x571000` | the animal per-state dispatch initialiser (`sub_5707FF`, 1914 lines) |

The action one doubles as a check on work already shipped: the 95 action names
in `CreatureActionNames.cpp` were decoded by scanning raw instructions, and the
decompiled initialiser independently contains exactly 95 string assignments, all
95 landing on an action-name slot. Two methods, same answer.

Expect a large "spots refused" count -- data interleaved with the code -- which
is normal and harmless.
