"""Recover the creature decision tree's attribute schema from the binary.

An Attribute is how the creature turns the world into something a decision tree
can branch on: given a game object, produce a small integer bucket. All 24 share
a 13-slot vtable, and four of those slots are constant returns, so the schema
comes out mechanically:

    slot  7   GetName()          -> "Life", "OnFire", ...
    slot  8   GetNumValues()     -> how many buckets the attribute has
    slot  9   GetValueName(i)    -> a 64-byte-stride string table
    slot 10   Evaluate(obj, ctx) -> computes the bucket
    slot 11   GetAttributeType() -> the ATTRIBUTE_TYPE id
    slot 12   IsValid()          -> 0 on the abstract base, 1 on real ones

The ids are cross-checked against chlasm's ATTRIBUTE_TYPE enum (CC0, from
bw1-decomp) so a mis-numbered slot would be caught rather than baked in.

Inputs   work/decomp/creature_ai.txt     IDA vtable dump
         work/decomp/attr_strings.txt    string symbol -> text
Output   work/decomp/attributes.json
"""
import re
import json

DUMP = "work/decomp/creature_ai.txt"
STRINGS = "work/decomp/attr_strings.txt"
ENUM = "vendor/bw1-decomp/libs/chlasm/CreatureEnum.h"
OUT = "work/decomp/attributes.json"

SLOT = re.compile(r"^(\S+)::vslot\[(\d+)\]  @ (0x[0-9a-f]+)$")


def read_strings():
    out = {}
    for line in open(STRINGS, encoding="utf-8"):
        sym, _, text = line.rstrip("\n").partition("\t")
        if text and text != "?":
            out[sym] = text
    return out


def read_enum():
    """ATTRIBUTE_TYPE name -> id, from the CC0 chlasm header."""
    out, inside = {}, False
    for line in open(ENUM, encoding="utf-8"):
        if re.match(r"\s*enum\s+ATTRIBUTE_TYPE", line):
            inside = True
            continue
        if inside:
            if line.strip().startswith("}"):
                break
            m = re.match(r"\s*(ATTRIBUTE_TYPE_\w+)\s*=\s*(\d+)", line)
            if m:
                out.setdefault(int(m.group(2)), m.group(1))
    return out


def main():
    text = open(DUMP, encoding="utf-8").read()
    strings = read_strings()
    enum_by_id = read_enum()

    bodies = {}
    for blk in re.split(r"^// ---- ", text, flags=re.M)[1:]:
        head, _, body = blk.partition(" ----\n")
        m = SLOT.match(head.strip())
        if m and m.group(1).startswith("Attribute"):
            bodies[(m.group(1), int(m.group(2)))] = body

    classes = sorted({c for c, _ in bodies})

    def const(cls, slot):
        b = bodies.get((cls, slot), "")
        m = re.search(r"return (-?\d+);", b)
        return int(m.group(1)) if m else None

    def strval(cls, slot):
        b = bodies.get((cls, slot), "")
        m = re.search(r"return (?:\(char \*\))?(a[A-Z]\w*|unk_[0-9A-F]+)", b)
        return strings.get(m.group(1), m.group(1)) if m else None

    def value_table(cls):
        """slot 9 indexes a 64-byte-stride table; recover its base symbol."""
        b = bodies.get((cls, 9), "")
        m = re.search(r"(a[A-Z]\w*|unk_[0-9A-F]+)\b", b)
        if not m:
            return None, None
        stride = re.search(r"(\d+) \* a1|\[(\d+) \* a1\]", b)
        return m.group(1), int(stride.group(1) or stride.group(2)) if stride else 64

    rows = []
    for cls in classes:
        if 11 not in [s for c, s in bodies if c == cls]:
            continue
        type_id = const(cls, 11)
        base, stride = value_table(cls)
        rows.append(dict(
            cls=cls,
            name=strval(cls, 7),
            num_values=const(cls, 8),
            type_id=type_id,
            valid=bool(const(cls, 12)),
            value_table=base,
            value_stride=stride,
            enum_name=enum_by_id.get(type_id),
            evaluate=bodies.get((cls, 10), "").strip(),
        ))

    json.dump(rows, open(OUT, "w"), indent=1)

    real = [r for r in rows if r["valid"]]
    print("attribute classes  :", len(rows), "(%d concrete)" % len(real))
    print("chlasm enum ids    :", len(enum_by_id))
    mismatch = [r for r in real if r["enum_name"] is None]
    print("ids not in the enum:", len(mismatch))
    dupes = {}
    for r in real:
        dupes.setdefault(r["type_id"], []).append(r["cls"])
    clash = {k: v for k, v in dupes.items() if len(v) > 1}
    print("id collisions      :", clash if clash else "none")
    print()
    print("  %-36s %-4s %-5s %-6s %s" % ("class", "id", "vals", "valid", "name / enum"))
    for r in sorted(rows, key=lambda r: (r["type_id"] if r["type_id"] is not None else 99)):
        print("  %-36s %-4s %-5s %-6s %s" % (
            r["cls"], r["type_id"], r["num_values"],
            "yes" if r["valid"] else "-",
            "%s  (%s)" % (r["name"], r["enum_name"] or "?")))


if __name__ == "__main__":
    main()
