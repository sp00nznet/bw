# Rebuild a .bss table from the inlined initialiser that fills it: every
# `mov dword ptr [abs], imm32` (C7 05 addr imm) in .text whose address falls
# in [lo, hi). IDA never made these initialisers functions, so they have no
# xrefs; reading the instruction bytes directly is the reliable route.
# Usage: py -3 work/decode_movimm.py <lo hex> <hi hex>  -> "addr value" lines
import struct, sys
d = open("game_data/runblack_decrypted.exe", "rb").read()
pe = struct.unpack_from("<I", d, 0x3C)[0]; opt = struct.unpack_from("<H", d, pe + 20)[0]
name, vs, va, rs, ro = struct.unpack_from("<8sIIII", d, pe + 24 + opt)  # .text
text = d[ro:ro + rs]; base = 0x400000 + va
lo, hi = int(sys.argv[1], 16), int(sys.argv[2], 16)
out = {}
i = 0
while True:
    i = text.find(b"\xC7\x05", i)
    if i < 0: break
    addr, val = struct.unpack_from("<II", text, i + 2)
    if lo <= addr < hi: out[addr] = (val, base + i)
    i += 1
for a in sorted(out):
    print("%08X %08X  (at %08X)" % (a, out[a][0], out[a][1]))
