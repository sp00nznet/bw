# Per-record bytes for the 65 DETAIL_* table loaders on the binary path
# (the `if ( a5 )` branch), counting parent readers handed the file (a6).
# Usage: py -3.11 info_tablesizes.py <bw.exe.i64>  -> work/decomp/info_layout2.txt
import sys, re, idapro
idapro.open_database(sys.argv[1], True)
import ida_hexrays, ida_auto
ida_auto.auto_wait()
memo = {}
def reader(ea):  # nested reader: this=element, a2=file
    if ea not in memo:
        t = str(ida_hexrays.decompile(ea))
        n = sum(int(m) for m in re.findall(r"sub_72D2F0\(\s*a2\s*,[^,]+,\s*(\d+)\s*,", t))
        n += sum(reader(int(s, 16)) for s in re.findall(r"\bsub_([0-9A-F]+)\(\s*a2\s*\)", t))
        memo[ea] = n
    return memo[ea]
rows = []
for line in open("decomp/info_loader.txt"):
    m = re.match(r"\s*sub_([0-9A-F]+)\(v9, (\w+), &?(\w+), (\d+), v200, v202\);", line)
    if not m: continue
    t = str(ida_hexrays.decompile(int(m.group(1), 16)))
    body = t[t.index("if ( a5 )"):t.index("\n  else\n")]
    n = sum(int(x) for x in re.findall(r"sub_72D2F0\([^,()]+,\s*(\d+)\s*,", body))
    n += sum(reader(int(s, 16)) for s in re.findall(r"\bsub_([0-9A-F]+)\(\s*a6\s*\)", body))
    loop = "LOOP" if re.search(r"\b(for|while)\s*\(", body.replace("while ( v", "", 1)) else ""
    rows.append((m.group(2), m.group(3), int(m.group(4)), n, loop))
with open("decomp/info_layout2.txt", "w") as f:
    f.write("# section, table, count, bytes/rec on the binary path (parents included), total\n")
    for s, t, c, n, l in rows:
        f.write(f"{s:36s} {t:16s} {c:5d} {n:5d} {c*n:7d} {l}\n")
print(sum(c*n for _, _, c, n, _ in rows), len(rows))
idapro.close_database(save=False)
