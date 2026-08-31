"""Stamp the real save-type ids into our GetSaveType() overrides.

The ids come from vtable slot 60 of the v1.0 binary (work/decomp/save_ids.txt);
until now every override returned 0, which meant nothing could be dispatched on.
Two shapes exist in the tree:

    header:  uint32_t GetSaveType() override { return 0; }
    source:  uint32_t Foo::GetSaveType() { ...return 0; }

Both get the class's real id, with a comment naming where it came from. Classes
the binary has no id for are left alone and reported.
"""
import re
import os
import glob

IDS = "work/decomp/save_ids.txt"
HEADERS = "src/include/black/*.h"
SOURCES = "src/core/*.cpp"

ids = {}
for line in open(IDS):
    name, val = line.split()
    ids[name] = int(val)

patched, skipped, already = [], [], []


def note(cls):
    return "  // save-type %d (binary vtable slot 60)" % ids[cls]


# --- headers: inline bodies -------------------------------------------------
INLINE = re.compile(
    r"(struct\s+(\w+)\s*(?::[^{]*)?\{(?:[^{}]|\{[^{}]*\})*?"
    r"GetSaveType\(\)\s*(?:const\s*)?override\s*\{\s*return\s+)(0x[0-9a-fA-F]+|\d+)(\s*;\s*\})",
    re.S)

for path in glob.glob(HEADERS):
    src = open(path, encoding="utf-8").read()
    out, pos, changed = [], 0, False
    for m in INLINE.finditer(src):
        cls = m.group(2)
        if cls not in ids:
            skipped.append(cls)
            continue
        if int(m.group(3), 0) == ids[cls]:
            already.append(cls)
            continue
        out.append(src[pos:m.start(3)])
        out.append(str(ids[cls]))
        pos = m.end(3)
        changed = True
        patched.append(cls)
    if changed:
        out.append(src[pos:])
        open(path, "w", encoding="utf-8", newline="\n").write("".join(out))

# --- sources: out-of-line bodies -------------------------------------------
BODY = re.compile(r"(uint32_t\s+(\w+)::GetSaveType\(\)\s*\{[^}]*?return\s+)(0x[0-9a-fA-F]+|\d+)(\s*;)", re.S)

for path in glob.glob(SOURCES):
    src = open(path, encoding="utf-8").read()
    out, pos, changed = [], 0, False
    for m in BODY.finditer(src):
        cls = m.group(2)
        if cls not in ids:
            skipped.append(cls)
            continue
        if int(m.group(3), 0) == ids[cls]:
            already.append(cls)
            continue
        out.append(src[pos:m.start(3)])
        out.append(str(ids[cls]))
        pos = m.end(3)
        changed = True
        patched.append(cls)
    if changed:
        out.append(src[pos:])
        open(path, "w", encoding="utf-8", newline="\n").write("".join(out))

print("patched  :", len(patched))
print("already  :", len(already))
print("no id    :", len(set(skipped)))
if skipped:
    print("  " + " ".join(sorted(set(skipped))))
missing = sorted(set(ids) - set(patched) - set(already))
print("id but no GetSaveType override found in tree:", len(missing))
if missing:
    print("  " + " ".join(missing))
