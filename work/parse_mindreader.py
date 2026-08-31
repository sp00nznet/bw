"""Turn a CreatureMind deserializer into a format spec.

The mind files are a flat little-endian stream read sequentially through three
primitives on a 1024-byte buffered reader:

    sub_6AB4B0(dst)   1 byte      cursor at +0x50C, buffer at +0x10C,
    sub_6AB4F0(dst)   2 bytes     refilled by sub_6AB2E0 when it would pass 1024
    sub_6AB530(dst)   4 bytes

and the whole format is versioned on one global, `dword_BCC4D4`, with gates like
`if (version >= 0x11)` wrapping the fields that were added in each revision.
That makes the format recoverable the same way the save tables were: read the
ordered sequence of primitive calls, note which version gate each sits under,
and the result is the grammar.

This does the reading part. It reports the sequence with its guards and its
loops so the spec can be written from facts rather than from staring at a hex
dump -- which is exactly how you end up with a reader that is right on the one
version you looked at and silently wrong on the others.

    python work/parse_mindreader.py work/decomp/mind_reader.txt
"""
import re
import sys

READERS = {
    "sub_6AB4B0": 1,
    "sub_6AB4F0": 2,
    "sub_6AB530": 4,
}
VERSION = "dword_BCC4D4"

GATE = re.compile(r"if \(\s*(?:\(unsigned int\))?%s\s*(>=|<|>|<=|==|!=)\s*(0x[0-9A-Fa-f]+|\d+)\s*\)"
                  % VERSION)
CALL = re.compile(r"\b(sub_6AB4B0|sub_6AB4F0|sub_6AB530)\b")
LOOP = re.compile(r"\b(for|while|do)\b")


def parse(path):
    text = open(path, encoding="utf-8").read()
    body = text.split(" ----\n", 1)[1] if " ----\n" in text else text
    body = re.sub(r"^\s+\w[\w \*]*; //.*$", "", body, flags=re.M)

    # Hex-Rays writes `if (...)` on its own line, with either a braced block on
    # the following lines or a single unbraced statement. Both have to be
    # handled, and getting it wrong silently reports every field as
    # unconditional -- which is worse than not parsing at all, because it looks
    # like an answer.
    depth = 0
    guards = []        # (brace depth, condition) for braced blocks
    loops = []         # brace depths that are loops
    out = []
    armed_gate = None  # a condition seen on the previous line, not yet placed
    armed_loop = False

    for raw in body.splitlines():
        line = raw.strip()
        if not line:
            continue

        opens = line.count("{")
        closes = line.count("}")

        # A condition armed by the previous line lands here: on this line's
        # block if it opens one, otherwise on this single statement.
        one_shot_gate = None
        one_shot_loop = False
        if armed_gate is not None or armed_loop:
            if opens:
                if armed_gate is not None:
                    guards.append((depth + 1, armed_gate))
                if armed_loop:
                    loops.append(depth + 1)
            else:
                one_shot_gate = armed_gate
                one_shot_loop = armed_loop
            armed_gate = None
            armed_loop = False

        for m in CALL.finditer(line):
            size = READERS[m.group(1)]
            conds = [g[1] for g in guards]
            if one_shot_gate:
                conds.append(one_shot_gate)
            out.append(dict(size=size,
                            guard=" and ".join(conds) or "-",
                            in_loop=bool(loops) or one_shot_loop,
                            text=line))

        # Arm anything this line introduces, for the next line to place.
        m = GATE.search(line)
        if m:
            armed_gate = "version %s %s" % (m.group(1), m.group(2))
        if LOOP.search(line):
            armed_loop = True
        # `do {` / `for (...) {` open on the same line.
        if opens and (m or LOOP.search(line)):
            if armed_gate is not None:
                guards.append((depth + 1, armed_gate))
                armed_gate = None
            if armed_loop:
                loops.append(depth + 1)
                armed_loop = False

        depth += opens
        for _ in range(closes):
            while guards and guards[-1][0] >= depth:
                guards.pop()
            while loops and loops[-1] >= depth:
                loops.pop()
            depth -= 1

    return out


def main():
    path = sys.argv[1] if len(sys.argv) > 1 else "work/decomp/mind_reader.txt"
    fields = parse(path)

    total_unconditional = sum(f["size"] for f in fields
                              if f["guard"] == "-" and not f["in_loop"])
    print("reads recovered      :", len(fields))
    print("unconditional, flat  : %d bytes" % total_unconditional)
    print("inside a loop        :", sum(1 for f in fields if f["in_loop"]))
    print("version gated        :", sum(1 for f in fields if f["guard"] != "-"))
    print()

    print("%-6s %-5s %-6s %s" % ("#", "bytes", "loop", "guard"))
    for i, f in enumerate(fields):
        print("%-6d %-5d %-6s %s" % (i, f["size"], "yes" if f["in_loop"] else "", f["guard"]))

    gates = sorted({f["guard"] for f in fields if f["guard"] != "-"})
    print("\ndistinct version gates:")
    for g in gates:
        print("  " + g)


if __name__ == "__main__":
    main()
