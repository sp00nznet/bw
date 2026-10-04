# Bytes each binary-path info.dat reader consumes, by walking its pseudocode:
# sum the constant sizes passed to the file read (sub_72D2F0) and recurse into
# nested readers that are handed the same file. Flags readers with loops.
# Usage: py -3.11 info_readsizes.py <bw.exe.i64>
import sys, re, idapro
idapro.open_database(sys.argv[1], True)
import ida_hexrays, ida_auto
ida_auto.auto_wait()

READ = "sub_72D2F0"
memo = {}
def size(ea, depth=0):
    if ea in memo: return memo[ea]
    txt = str(ida_hexrays.decompile(ea))
    total, loops = 0, bool(re.search(r"\b(for|while)\s*\(", txt))
    for m in re.finditer(READ + r"\(\s*a2\s*,[^,]+,\s*(\d+)\s*,", txt):
        total += int(m.group(1))
    for m in re.finditer(r"\b(sub_[0-9A-F]+)\(\s*a2\s*\)", txt):
        t, l = size(int(m.group(1)[4:], 16), depth + 1)
        total += t; loops |= l
    memo[ea] = (total, loops)
    return memo[ea]

# (reader, count) in binary-path order, from sub_425250 (work/decomp/info_loader.txt)
SEQ = [
 (0x4274A0,10),(0x427A00,2),(0x427CC0,1),(0x427650,1),(0x427570,2),(0x4278D0,3),
 (0x427770,2),(0x427570,1),(0x4274A0,2),(0x429020,1),(0x429120,1),(0x427AF0,16),
 (0x4273D0,(0xBEA828-0xBE7990)//284),(0x429390,(0xCC11F0-0xCBE310)//400),
 (0x428980,(0xB73FA4-0xB6E8F0)//716),(0x428430,(0xB859BC-0xB81CE8)//916),
 (0x428550,(0xB81CE4-0xB815B8)//108),
 (0x427D80,(0xBA7030-0xBA6310)//84),(0x427E10,(0xBA6310-0xBA5BD8)//132),
 (0x427EA0,(0xBA5BD8-0xBA5710)//72),(0x428AC0,1),(0x428BE0,1),
 (0x428D60,(0xBCEDDC-0xBCE788)//324),(0x428EE0,(0xCED320-0xCEC6C0)//352),
 (0x429250,(0xCBE2D8-0xCBE080)//300),(0x428290,(0xB6E528-0xB5DF50)//456),
 (0x428010,(0xCDAA50-0xCC7880)//932),(0x429760,(0xCBD000-0xCBBE00)//96),
 (0x428820,(0xCC6430-0xCC4770)//320),(0x427BE0,(0xBF1528-0xBF1118)//260),
 (0x429660,(0xCB7568-0xCB7128)//272),(0x429840,(0xCC1478-0xCC1268)//264),
 (0x428680,1),(0x4294C0,1),(0x4281B0,1),(0x429470,1),(0x429560,1),
]
grand = 0
for ea, n in SEQ:
    s, l = size(ea)
    grand += s * n
    print(f"{ea:#x} x{n:4d}  {s:6d} B/rec  {s*n:7d}  {'LOOP' if l else ''}")
print("per-class readers total:", grand)
idapro.close_database(save=False)
