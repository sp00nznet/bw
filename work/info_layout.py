# info.dat layout, recovered from the loader (sub_425250) rather than guessed.
#
# info.dat is a flat stream: a 44-byte header, then every section in the order
# the loader reads it, no tags or lengths between them. A section's size is
# therefore only knowable from code: sum the constant sizes each reader passes
# to the file read (sub_72D2F0), plus any parent reader it calls with the file.
# Parents matter: most "Info" classes start with a shared 240- or 244-byte block,
# and missing those was the whole of the old "304 KB unread" mystery.
#
# Pitfall: IDA retypes a parent as __thiscall once it has decompiled it, so the
# same call reads `sub_X(a2)` or `sub_X(this, a2)` depending on decompile order.
# Match the file argument in any position.
#
# Usage: py -3.11 info_layout.py <bw.exe.i64>   -> work/decomp/info_layout.txt
# Then:  py -3 info_walk.py                     (checks it against game_data/info.dat)
import sys, re, idapro
idapro.open_database(sys.argv[1], True)
import ida_hexrays, ida_auto
ida_auto.auto_wait()

READ = r"sub_72D2F0\([^;]*?(\d+)\s*,\s*-1\s*\)"
def calls_with(arg): return r"\bsub_([0-9A-F]+)\([^()]*\b" + arg + r"\s*\)"

memo = {}
def reader(ea):
    """Bytes a nested reader (this=element, a2=file) consumes."""
    if ea not in memo:
        t = str(ida_hexrays.decompile(ea)).split("{", 1)[1]  # body only: the signature names a2 too
        memo[ea] = sum(map(int, re.findall(READ, t))) + \
                   sum(reader(int(s, 16)) for s in re.findall(calls_with("a2"), t))
    return memo[ea]

def table(ea):
    """Bytes per record of a DETAIL_* table loader; binary path is its `if ( a5 )` branch."""
    t = str(ida_hexrays.decompile(ea))
    body = t[t.index("if ( a5 )"):t.index("\n  else\n")]
    return sum(map(int, re.findall(READ, body))) + \
           sum(reader(int(s, 16)) for s in re.findall(calls_with("a6"), body))

# Per-class readers, binary-path order: (reader, count, element stride). Counts
# are the loader's loop bounds (array span / stride); single heap objects use
# their allocation size (sub_4300A0's first argument) as the stride.
def arr(reader, lo, hi, stride): return (reader, (hi - lo) // stride, stride)
CLASSES = [
 (0x4274A0,10,88),(0x427A00,2,96),(0x427CC0,1,92),(0x427650,1,108),(0x427570,2,112),
 (0x4278D0,3,108),(0x427770,2,116),(0x427570,1,112),(0x4274A0,2,88),(0x429020,1,100),
 (0x429120,1,104),(0x427AF0,16,156),
 arr(0x4273D0,0xBE7990,0xBEA828,284), arr(0x429390,0xCBE310,0xCC11F0,400),
 arr(0x428980,0xB6E8F0,0xB73FA4,716), arr(0x428430,0xB81CE8,0xB859BC,916),
 arr(0x428550,0xB815B8,0xB81CE4,108), arr(0x427D80,0xBA6310,0xBA7030,84),
 arr(0x427E10,0xBA5BD8,0xBA6310,132), arr(0x427EA0,0xBA5710,0xBA5BD8,72),
 (0x428AC0,1,84),(0x428BE0,1,344),
 arr(0x428D60,0xBCE788,0xBCEDDC,324), arr(0x428EE0,0xCEC6C0,0xCED320,352),
 arr(0x429250,0xCBE080,0xCBE2D8,300), arr(0x428290,0xB5DF50,0xB6E528,456),
 arr(0x428010,0xCC7880,0xCDAA50,932), arr(0x429760,0xCBBE00,0xCBD000,96),
 arr(0x428820,0xCC4770,0xCC6430,320), arr(0x427BE0,0xBF1118,0xBF1528,260),
 arr(0x429660,0xCB7128,0xCB7568,272), arr(0x429840,0xCC1268,0xCC1478,264),
 (0x428680,1,320)]
# Single records read between the DETAIL_* tables: after PlayerInfo (sound,
# belief) and after HelpSprites (influence, help system).
AFTER = {"aDetailPlayerIn": [("aDetailSoundInf",0x4294C0,1,76),("aDetailBeliefIn",0x4281B0,1,40)],
         "aDetailHelpSpri": [("aDetailInfluenc",0x429470,1,28),("aDetailHelpSyst",0x429560,1,32)]}

import ida_name, idc
def label_str(label):
    ea = ida_name.get_name_ea(idc.BADADDR, label)
    return idc.get_strlit_contents(ea).decode()

def table_stride(ea):
    """Element stride: the pointer increment in the binary branch, scaled by its type."""
    t = str(ida_hexrays.decompile(ea))
    body = t[t.index("if ( a5 )"):t.index("\n  else\n")]
    var, n = re.search(r"\b(\w+) \+= (\d+);", body).groups()
    decl = re.search(r"\n\s+([\w ]+?)\s*(\*?)\s*" + var + r"; //", t)
    unit = 4 if decl and decl.group(2) and "_DWORD" in decl.group(1) else 1
    return int(n) * unit

# Section names in class-reader order come from the text-path branch, which
# looks each one up by name in the same order.
src = open("decomp/info_loader.txt").read().splitlines()[375:1348]
CLASS_NAMES = re.findall(r"sub_5B1630\((aDetail\w+)", "\n".join(src))
assert len(CLASS_NAMES) == len(CLASSES), (len(CLASS_NAMES), len(CLASSES))

rows = [(label_str(nm), reader(ea), n, st) for nm, (ea, n, st) in zip(CLASS_NAMES, CLASSES)]
for line in open("decomp/info_loader.txt"):
    m = re.match(r"\s*sub_([0-9A-F]+)\(v9, (\w+), &?\w+, (\d+), v200, v202\);", line)
    if not m: continue
    ea = int(m.group(1), 16)
    rows.append((label_str(m.group(2)), table(ea), int(m.group(3)), table_stride(ea)))
    rows += [(label_str(nm), reader(r), n, st) for nm, r, n, st in AFTER.get(m.group(2), [])]

for name, size, n, st in rows:
    assert st >= 16 + size, (name, size, st)  # the record lands at +16 inside each element
with open("decomp/info_layout.txt", "w") as f:
    f.write("# section, bytes/record (parents included), count, element stride -- file order\n")
    for name, size, n, st in rows:
        f.write(f"{name:52s} {size:5d} {n:5d} {st:5d}\n")
print("payload bytes:", sum(s * n for _, s, n, _ in rows), "sections:", len(rows))
idapro.close_database(save=False)
