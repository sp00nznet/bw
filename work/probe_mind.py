"""Walk a CreatureMind file against the recovered grammar.

The point of this is not to extract data -- it is to prove the grammar is right
before any of it becomes C++. A binary reader that is subtly wrong produces
plausible floats in the wrong fields and nothing downstream notices, so the
check has to be structural: follow the read sequence and see whether the cursor
lands where the next known landmark actually is.

Grammar from work/decomp/mind_format.txt (sub_4C95D0), verified so far:

    <loader prologue>                     version-dependent, ends at the name
    u32 name_len ; u16 name[name_len]     length-prefixed UTF-16
    u32 x6
    u32                                   if version >= 0x11
    u32 desire_count                      == 40, NUM_CREATURE_DESIRES
    per desire:
        u32 x4
        u32                               if version < 7
        u32                               if 6 <= version < 0xA
        if version >= 9:
            u32 source_count
            per source: u32 x3
            u32                           if version < 0xF

    python work/probe_mind.py
"""
import glob
import os
import struct
import sys


class Cursor:
    def __init__(self, data):
        self.d = data
        self.p = 0

    def u32(self):
        v = struct.unpack_from("<I", self.d, self.p)[0]
        self.p += 4
        return v

    def f32(self):
        v = struct.unpack_from("<f", self.d, self.p)[0]
        self.p += 4
        return v

    def u16(self):
        v = struct.unpack_from("<H", self.d, self.p)[0]
        self.p += 2
        return v

    def left(self):
        return len(self.d) - self.p


def find_name(data):
    """The loader prologue is version-dependent; locate the name by its own
    shape (a plausible length followed by that many ASCII-range wide chars)
    rather than assuming an offset."""
    for off in range(0, min(len(data) - 4, 512)):
        n = struct.unpack_from("<I", data, off)[0]
        if not (1 <= n <= 32) or off + 4 + n * 2 > len(data):
            continue
        raw = data[off + 4:off + 4 + n * 2]
        if all(raw[i + 1] == 0 and 32 <= raw[i] < 127 for i in range(0, len(raw), 2)):
            return off, raw.decode("utf-16-le")
    return None, None


def walk(path):
    data = open(path, "rb").read()
    version = struct.unpack_from("<I", data, 0)[0]
    name_off, name = find_name(data)
    if name_off is None:
        return dict(file=os.path.basename(path), version=version, name=None,
                    note="no name field found in the first 512 bytes")

    c = Cursor(data)
    c.p = name_off
    n = c.u32()
    c.p += n * 2                       # the name itself

    for _ in range(6):
        c.u32()
    if version >= 0x11:
        c.u32()

    desire_count = c.u32()
    if desire_count != 40:
        return dict(file=os.path.basename(path), version=version, name=name,
                    note="desire count is %d, expected 40" % desire_count)

    desires = []
    for _ in range(desire_count):
        vals = [c.u32() for _ in range(4)]
        if version < 7:
            c.u32()
        if 6 <= version < 0xA:
            c.u32()
        sources = []
        if version >= 9:
            nsrc = c.u32()
            if nsrc > 64:
                return dict(file=os.path.basename(path), version=version, name=name,
                            note="source count %d is implausible at 0x%X" % (nsrc, c.p - 4))
            for _ in range(nsrc):
                sources.append(tuple(c.u32() for _ in range(3)))
            if version < 0xF:
                c.u32()
        desires.append((vals, sources))

    return dict(file=os.path.basename(path), version=version, name=name,
                name_off=name_off, after_desires=c.p, size=len(data),
                left=c.left(), desires=desires)


def main():
    for path in sorted(glob.glob("game_data/CreatureMind/*")):
        r = walk(path)
        if r.get("note"):
            print("%-32s v=%-3d %-10s  %s" % (r["file"], r["version"],
                                              r["name"] or "-", r["note"]))
            continue
        srcs = sum(len(s) for _, s in r["desires"])
        print("%-32s v=%-3d name=%-9s name@0x%-4X desires=40 sources=%-4d "
              "cursor=0x%-6X size=%-7d left=%d"
              % (r["file"], r["version"], r["name"], r["name_off"], srcs,
                 r["after_desires"], r["size"], r["left"]))


if __name__ == "__main__":
    sys.exit(main())
