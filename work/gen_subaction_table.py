"""Recover the creature sub-action table (0xB0EAF8, 144-byte records: name,
kind at +64, up to four step handlers from +80) by running each of the small
initialisers in 0x4D8300..0x4DE100 under unicorn. Writes
work/decomp/subaction_table.json and prints the named entries.

    py -3.11 work/gen_subaction_table.py
"""
import json, re, struct
import pefile, capstone
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EIP, UC_X86_REG_ESP, UC_X86_REG_ECX

pe = pefile.PE("game_data/runblack_decrypted.exe")
img = pe.get_memory_mapped_image()
mu = Uc(UC_ARCH_X86, UC_MODE_32)
mu.mem_map(0x400000, max(0xD00000 - 0x400000, (len(img) + 0xFFF) & ~0xFFF))
mu.mem_write(0x400000, img)
mu.mem_map(0x100000, 0x10000)
SENT = 0x100800

def hook(uc, addr, size, _):
    if addr == SENT:
        uc.emu_stop(); return
    b = bytes(uc.mem_read(addr, 2))
    if b[0] == 0xE8:  # call: emulate strcpy-like copies? skip, but keep going
        uc.reg_write(UC_X86_REG_EIP, addr + 5); uc.reg_write(UC_X86_REG_EAX, 0)
mu.hook_add(UC_HOOK_CODE, hook)

# function starts: after padding (nop/int3) runs following a ret
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
lo, hi = 0x4d8300, 0x4de120
starts = []
off = lo
code = img[lo - 0x400000:hi - 0x400000]
prev_ret = False
for ins in md.disasm(code, lo):
    if prev_ret and ins.mnemonic not in ("nop", "int3"):
        starts.append(ins.address)
    if ins.mnemonic in ("ret", "jmp") or ins.mnemonic.startswith("ret"):
        prev_ret = True
    elif ins.mnemonic not in ("nop", "int3"):
        prev_ret = False
ran = 0
for s in starts:
    mu.reg_write(UC_X86_REG_ESP, 0x108000)
    mu.mem_write(0x108000, struct.pack("<I", SENT) * 4)
    try:
        mu.emu_start(s, SENT, count=200000)
        ran += 1
    except Exception as e:
        pass
print("functions run", ran, "of", len(starts))
base = 0xB0EAF8
out = [list(struct.unpack("<36I", bytes(mu.mem_read(base + 144 * i, 144)))) for i in range(160)]
names = []
for r in out:
    m = re.match(rb"([A-Za-z0-9_ ]+)\x00", struct.pack("<16I", *r[:16]))
    names.append(m.group(1).decode() if m else "")
json.dump({"records": out, "names": names}, open("work/decomp/subaction_table.json", "w"))
for k in range(160):
    if out[k][16] or any(out[k][20:36]):
        steps = [hex(out[k][20 + 4 * s]) for s in range(4) if out[k][20 + 4 * s]]
        print(k, repr(names[k]), "kind", out[k][16], steps)
