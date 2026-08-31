"""Recover the particle engine's rule parameter schema from the binary.

Every PSys rule exposes its parameters to the in-game particle editor from
vtable slot 3, one call per parameter:

    AppearanceRuleFadeOut::RegisterProperties(editor):
        AppearanceUpdateRule::RegisterProperties(editor)      <- parent first
        editor->AddFloat("Vanishage", &this->vanishage, 0.0f, 100.0f)

so slot 3 hands us, for free and for every rule, the parameter's real name, its
offset in the rule object, its type and its range. That is the entire tunable
surface of the engine -- exactly the part that would otherwise be guesswork.

    sub_54E800  AddFloat(name, &field, min, max)
    sub_54E940  AddInt(name, &field, min, max)
    sub_54ECB0  AddBool(name, &field)
    sub_54EB70  AddFileName(name, &field, ...)
    sub_54EA60  AddSoundAction(name, &field)
    sub_54EDC0  AddMeshEnum(name, &field)
    sub_54EED0  AddAnimEnum(name, &field)

Inputs   work/decomp/psys_all.txt      IDA vtable dump of the 124 PSys classes
         work/decomp/psys_strings.txt  IDA string symbol -> real text
Output   work/decomp/psys_rules.json
"""
import re
import sys
import json
import struct
import collections

sys.path.insert(0, "work")
from parse_saveslots import normalize, inline_aliases  # noqa: E402

DUMP = "work/decomp/psys_all.txt"
STRINGS = "work/decomp/psys_strings.txt"
OUT = "work/decomp/psys_rules.json"

REGISTRARS = {
    "sub_54E800": ("float", 4),
    "sub_54E940": ("int", 4),
    "sub_54ECB0": ("bool", 1),
    "sub_54EB70": ("filename", 4),
    "sub_54EA60": ("sound", 4),
    "sub_54EDC0": ("mesh_enum", 4),
    "sub_54EED0": ("anim_enum", 4),
}

CLASS = re.compile(r"// CLASS (\S+)  vftable @ (\S+)  \((\d+) virtual slots\)")
SLOT = re.compile(r"^(\S+)::vslot\[(\d+)\]  @ (0x[0-9a-f]+)$")


def read_strings():
    out = {}
    for line in open(STRINGS, encoding="utf-8"):
        sym, _, text = line.rstrip("\n").partition("\t")
        if text and text != "?":
            out[sym] = text
    return out


def as_float(bits):
    """A float literal Hex-Rays printed as its integer bit pattern."""
    try:
        return round(struct.unpack("<f", struct.pack("<I", bits & 0xFFFFFFFF))[0], 6)
    except Exception:                                   # noqa: BLE001
        return None


def parse():
    text = open(DUMP, encoding="utf-8").read()
    strings = read_strings()

    sizes, vftables = {}, {}
    for m in CLASS.finditer(text):
        sizes[m.group(1)] = int(m.group(3))
        vftables[m.group(1)] = m.group(2)

    bodies = {}      # (cls, slot) -> text
    addr_of = {}     # (cls, slot) -> address
    for blk in re.split(r"^// ---- ", text, flags=re.M)[1:]:
        head, _, body = blk.partition(" ----\n")
        m = SLOT.match(head.strip())
        if not m:
            continue
        bodies[(m.group(1), int(m.group(2)))] = body
        addr_of[(m.group(1), int(m.group(2)))] = m.group(3)

    # address -> class, so a slot-3 body's first call identifies the parent rule
    owner = {}
    for (cls, slot), a in addr_of.items():
        if slot == 3:
            owner.setdefault(a, cls)

    call = re.compile(r"\b(sub_[0-9A-F]+)\(([^;]*?)\)")
    rules = {}
    for (cls, slot), body in sorted(bodies.items()):
        if slot != 3:
            continue
        flat = inline_aliases(normalize(body))
        props, parent = [], None
        for m in call.finditer(flat):
            fn = m.group(1)
            args = [a.strip() for a in m.group(2).split(",")]
            if fn not in REGISTRARS:
                a = "0x" + fn[4:].lower()
                if parent is None and a in owner and owner[a] != cls:
                    parent = owner[a]
                continue
            if len(args) < 2:
                continue
            kind, width = REGISTRARS[fn]
            name = strings.get(args[0], args[0])
            off = re.search(r"@(\d+)", args[1])
            if not off:
                continue
            lo = hi = None
            if kind in ("float", "int") and len(args) >= 4:
                try:
                    lo, hi = int(args[2], 0), int(args[3], 0)
                    if kind == "float":
                        lo, hi = as_float(lo), as_float(hi)
                except ValueError:
                    lo = hi = None
            props.append(dict(name=name, off=int(off.group(1)), type=kind,
                              width=width, min=lo, max=hi))
        if props or parent:
            rules[cls] = dict(cls=cls, parent=parent, vftable=vftables.get(cls),
                              slots=sizes.get(cls), props=props)

    json.dump(rules, open(OUT, "w"), indent=1)

    total = sum(len(r["props"]) for r in rules.values())
    print("rules with a parameter schema :", len(rules))
    print("parameters recovered          :", total)
    kinds = collections.Counter(p["type"] for r in rules.values() for p in r["props"])
    print("by type                       :", dict(kinds))
    unnamed = sum(1 for r in rules.values() for p in r["props"]
                  if p["name"].startswith("a") and p["name"][1:2].isupper())
    print("names not resolved to strings :", unnamed)
    print()
    for cls in sorted(rules):
        r = rules[cls]
        head = "%s%s" % (cls, "  : " + r["parent"] if r["parent"] else "")
        print("  %-42s %s" % (head,
                              ", ".join("%s@%d:%s" % (p["name"], p["off"], p["type"])
                                        for p in r["props"]) or "(inherits only)"))


if __name__ == "__main__":
    parse()
