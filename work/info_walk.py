# Check work/decomp/info_layout.txt against game_data/info.dat: walk the
# sections in order, show where each one's strings fall inside its records
# (a name at the same offset in every record means the stride is right), and
# confirm the walk ends exactly at EOF.
import re
D = open("../game_data/info.dat", "rb").read()
rows = [l.split() for l in open("decomp/info_layout.txt") if not l.startswith("#")]
strs = [(m.start(), m.group().decode()) for m in re.finditer(rb"[A-Za-z][A-Za-z0-9_ ]{4,}", D)]
off = 0x2C  # header: "LiOnHeAdInfo" + payload size at 0x28
for name, rec, n, *_ in rows:
    rec, n = int(rec), int(n)
    end = off + rec * n
    inside = [(o, s) for o, s in strs if off <= o < end]
    rel = ", ".join(f"{(o-off)%rec}:{s[:18]}" for o, s in inside[:4])
    print(f"{off:7d} {name:24s} {rec:4d}x{n:<4d} strs={len(inside):3d} {rel}")
    off = end
print("end", off, "file", len(D), "OK" if off == len(D) else "MISMATCH")
