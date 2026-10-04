# Rebuild a .bss table by emulating the inlined initialiser that fills it.
#
# These initialisers are straight-line runs of register loads and absolute
# stores (mov reg, imm / xor reg, reg / or reg, -1 / mov [abs], reg|eax|imm).
# IDA never made them functions, so their tables have no xrefs and the
# decompiler has nothing to show; tracking eight registers through the bytes
# reproduces the table exactly. Any other opcode stops the run with its
# address, so nothing is skipped silently.
#
# Usage: py -3 work/emulate_init.py <start hex> <table lo hex> <table hi hex>
#   -> "offset value" for every dword stored into [lo, hi)
import struct, sys

d = open("game_data/runblack_decrypted.exe", "rb").read()
pe = struct.unpack_from("<I", d, 0x3C)[0]
opt = struct.unpack_from("<H", d, pe + 20)[0]
_, vs, va, rs, ro = struct.unpack_from("<8sIIII", d, pe + 24 + opt)
BASE = 0x400000 + va


def byte_at(ea): return d[ro + ea - BASE]
def u32(ea): return struct.unpack_from("<I", d, ro + ea - BASE)[0]


start, lo, hi = (int(x, 16) for x in sys.argv[1:4])
REG = ["eax", "ecx", "edx", "ebx", "esp", "ebp", "esi", "edi"]
r = {n: None for n in REG}
table = {}
ea = start
while True:
    op = byte_at(ea)
    if 0x50 <= op <= 0x57: ea += 1; continue                      # push r
    if 0x58 <= op <= 0x5F: ea += 1; continue                      # pop r
    if op == 0xC3: break                                          # ret
    if 0xB8 <= op <= 0xBF:                                        # mov r, imm32
        r[REG[op - 0xB8]] = u32(ea + 1); ea += 5; continue
    if op == 0x33 and byte_at(ea + 1) >> 6 == 3:                  # xor r, r
        m = byte_at(ea + 1); a, b = (m >> 3) & 7, m & 7
        if a != b: sys.exit("xor of different registers at %X" % ea)
        r[REG[a]] = 0; ea += 2; continue
    if op == 0x83 and byte_at(ea + 1) >> 3 == 0x19 and byte_at(ea + 2) == 0xFF:  # or r, -1
        r[REG[byte_at(ea + 1) & 7]] = 0xFFFFFFFF; ea += 3; continue
    if op == 0x89 and (byte_at(ea + 1) & 0xC7) == 0x05:           # mov [abs], r
        addr = u32(ea + 2); v = r[REG[(byte_at(ea + 1) >> 3) & 7]]
        if lo <= addr < hi: table[addr] = v
        ea += 6; continue
    if op == 0xA3:                                                # mov [abs], eax
        addr = u32(ea + 1)
        if lo <= addr < hi: table[addr] = r["eax"]
        ea += 5; continue
    if op == 0xC7 and byte_at(ea + 1) == 0x05:                    # mov [abs], imm32
        addr, v = u32(ea + 2), u32(ea + 6)
        if lo <= addr < hi: table[addr] = v
        ea += 10; continue
    sys.exit("unhandled opcode %02X at %X" % (op, ea))
for a in sorted(table):
    v = table[a]
    print("%04X %s" % (a - lo, "????????" if v is None else "%08X" % v))
print("ended at %X, %d dwords" % (ea, len(table)), file=sys.stderr)
