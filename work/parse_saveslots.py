"""Turn the IDA save/load dumps into a serialization table.

Input   work/decomp/save_slots.txt    slots 58 (Load) 59 (Save) 60 (GetSaveType)
        work/decomp/save_parents.txt  ancestor bodies pulled in by address
Output  work/decomp/save_table.json

Every Save body in the binary has the same shape:

    if ( !<parentSave>(this, file) ) return 0;
    <primitive>(file, this + OFF, ...)      x N
    return 1;

so a class is fully described by (parent save address, ordered field ops).
Rows are keyed by the *address* of the Save body rather than by class name:
a class that does not override Save simply shares its ancestor's address, and
several classes legitimately map to one row.

Primitive vocabulary (recovered from work/decomp/save_helpers.txt):

    save            load            meaning
    sub_72BE90      sub_72BE50      raw <n> bytes
    sub_604120      sub_604170      raw 1 byte
    sub_66EE00      sub_589540      raw 4 bytes
    sub_4EBF70      sub_4EC100      raw 12 bytes (a vector3)
    sub_531BC0      sub_531F30      GameThing* as save-type id + fixup
    sub_533120      sub_533110        (thin wrappers over the above)
    sub_533B90      sub_533BF0      GBaseInfo* as info index
    sub_531FF0      sub_532060      count(4) then that many GameThing*
    sub_5341D0      -               count(4) then that many raw dwords
"""
import re
import json
import collections

SLOTS = "work/decomp/save_slots.txt"
PARENTS = "work/decomp/save_parents.txt"
OUT = "work/decomp/save_table.json"

# --------------------------------------------------------------- dump readers
HDR = re.compile(r"^// ---- (\S+)::vslot\[(\d+)\]  @ (0x[0-9a-f]+) ----$")
AHDR = re.compile(r"^// ---- (0x[0-9A-Fa-f]+) ----$")


def read_slots(path):
    """cls -> {slot: (addr, text)}"""
    out = collections.defaultdict(dict)
    cur = None
    for line in open(path, encoding="utf-8"):
        m = HDR.match(line.rstrip("\n"))
        if m:
            cur = (m.group(1), int(m.group(2)))
            out[cur[0]][cur[1]] = [m.group(3), []]
            continue
        if cur:
            out[cur[0]][cur[1]][1].append(line)
    for c in out:
        for s in out[c]:
            out[c][s][1] = "".join(out[c][s][1])
    return out


def read_addrs(path):
    """addr -> text"""
    out, cur = {}, None
    try:
        fh = open(path, encoding="utf-8")
    except FileNotFoundError:
        return out
    for line in fh:
        m = AHDR.match(line.rstrip("\n"))
        if m:
            cur = m.group(1).lower()
            out[cur] = []
            continue
        if cur:
            out[cur].append(line)
    return {k: "".join(v) for k, v in out.items()}


# --------------------------------------------------------- offset normalisation
# The object is `this` / `aN` / `vN` and its field addresses appear in every
# form C allows, with the offset scaled by whatever pointer type Hex-Rays chose:
#
#     this + 92                 this declared unsigned __int8*  -> byte 92
#     this + 32                 this declared int*              -> byte 128
#     this[30]                  this declared int*              -> byte 120
#     (unsigned __int8 *)a1 + 88                                -> byte 88
#     (int)(this + 32)          cast on the result, not the ptr -> this's scale
#     *((_DWORD *)this + 37)                                    -> byte 148
#
# Getting this wrong silently writes the wrong field, so every address form is
# rewritten to an explicit byte offset (`this@92`) before any pattern runs.
TYPESIZE = {
    "char": 1, "_BYTE": 1, "__int8": 1, "unsigned __int8": 1, "signed __int8": 1,
    "_WORD": 2, "short": 2, "__int16": 2, "unsigned __int16": 2,
    "int": 4, "_DWORD": 4, "unsigned int": 4, "__int32": 4, "float": 4,
    "unsigned __int32": 4, "void": 1,
}
IDENT = r"(?:this|a\d+|v\d+)"
DECL_TYPE = re.compile(r"\b((?:unsigned |signed |const )*[A-Za-z_]\w*) (\*?)(%s)\b" % IDENT)


def type_size(t, stars):
    return TYPESIZE.get(t.strip(), 1) if stars else 1


def normalize(text):
    """Flatten to one line and rewrite every field address as `ident@byteoff`."""
    flat = re.sub(r"\s+", " ", text)

    scale = {}
    for t, stars, name in DECL_TYPE.findall(flat):
        scale.setdefault(name, type_size(t, stars))

    def sized(cast):
        m = re.match(r"\(\s*((?:unsigned |signed |const )*[A-Za-z_]\w*)\s*\*\s*\)", cast)
        return TYPESIZE.get(m.group(1), 1) if m else None

    # *((TYPE *)x + K)  /  (TYPE *)x + K  /  x[K]  /  x + K
    def sub_deref(m):
        n = int(m.group(3)) * (sized("(%s *)" % m.group(1)) or 1)
        return "*(_DWORD *)(%s@%d)" % (m.group(2), n)

    flat = re.sub(r"\*\(\(([\w ]+) \*\)(%s) \+ (\d+)\)" % IDENT, sub_deref, flat)
    flat = re.sub(r"\(([\w ]+) \*\) ?(%s) \+ (\d+)" % IDENT,
                  lambda m: "%s@%d" % (m.group(2),
                                       int(m.group(3)) * (sized("(%s *)" % m.group(1)) or 1)),
                  flat)
    flat = re.sub(r"\b(%s)\[(\d+)\]" % IDENT,
                  lambda m: "*(_DWORD *)(%s@%d)" % (m.group(1),
                                                    int(m.group(2)) * scale.get(m.group(1), 1)),
                  flat)
    flat = re.sub(r"\b(%s) \+ (\d+)" % IDENT,
                  lambda m: "%s@%d" % (m.group(1),
                                       int(m.group(2)) * scale.get(m.group(1), 1)),
                  flat)
    return flat


# ------------------------------------------------------------------- field ops
SELF = r"(?:\([^()]*\) ?)?\(?(?:this|a\d+|v\d+)@(\d+)\)?"
DSELF = SELF
FILE = r"[^,()]+"


def rx(pat):
    return re.compile(pat % {"s": SELF, "d": DSELF, "f": FILE})


# (regex, kind, fixed size or None -> group(2), unused scale)
# Both directions are matched with a tolerant "anywhere inside this one call"
# prefix: Hex-Rays recovers the GameOSFile* (ecx) as an explicit argument only
# sometimes, and the __userpurge load bodies bury the real arguments in a long
# tail of junk registers. Argument lists contain no `;`, so the scan is bounded.
SAVE_PATS = [
    (rx(r"sub_72BE90\([^;]*?%(s)s, ?(\d+), ?0[,)]"), "raw", None, 1),
    (rx(r"sub_604120\)?\([^;]*?%(s)s\)"), "raw", 1, 1),
    (rx(r"sub_66EE00\)?\([^;]*?%(s)s\)"), "raw", 4, 1),
    (rx(r"sub_4EBF70\)?\([^;]*?%(s)s\)"), "raw", 12, 1),
    (rx(r"sub_531BC0\([^;]*?\*\(_DWORD \*\)\(%(s)s\)\)"), "ptr", 4, 1),
    (rx(r"sub_533120\)?\([^;]*?%(s)s\)"), "ptr", 4, 1),
    (rx(r"sub_533B90\([^;]*?\*\(_DWORD \*\)\(%(s)s\)\)"), "info", 4, 1),
    (rx(r"sub_531FF0\)?\([^;]*?%(s)s, ?(\d+)\)"), "ptrarray", None, 1),
    (rx(r"sub_5341D0\)?\([^;]*?%(s)s, ?(\d+)\)"), "rawarray", None, 1),
    (re.compile(r"sub_533C50\)?\("), "chk", 4, 1),
]
LOAD_PATS = [
    (rx(r"sub_72BE50\)?\([^;]*?%(s)s, ?(\d+), ?0[,)]"), "raw", None, 1),
    (rx(r"sub_604170\)?\([^;]*?%(s)s\)"), "raw", 1, 1),
    (rx(r"sub_589540\)?\([^;]*?%(s)s\)"), "raw", 4, 1),
    (rx(r"sub_4EC100\)?\([^;]*?%(s)s\)"), "raw", 12, 1),
    (rx(r"sub_531F30\)?\([^;]*?%(s)s\)"), "ptr", 4, 1),
    (rx(r"sub_533110\)?\([^;]*?%(s)s\)"), "ptr", 4, 1),
    (rx(r"sub_533BF0\)?\([^;]*?%(s)s\)"), "info", 4, 1),
    (rx(r"sub_532060\)?\([^;]*?%(s)s, ?(\d+)\)"), "ptrarray", None, 1),
    (re.compile(r"sub_533C90\)?\("), "chk", 4, 1),
]


ALIAS = re.compile(r"\b(v\d+) = (?:\([^()]*\) ?)?\(?((?:this|a\d+|v\d+)@\d+)\)?;")


def inline_aliases(flat):
    """Substitute `vN = this@OFF` temporaries back into their uses.

    The compiler hoists a field address into a register when a field is touched
    twice ("v3 = this + 92; ... Write(v3, 2, 0)"), which would otherwise hide
    the offset from the field-op patterns."""
    for _ in range(4):
        subst = dict(ALIAS.findall(flat))
        if not subst:
            break
        new = re.sub(r"\bv\d+\b", lambda m: subst.get(m.group(0), m.group(0)), flat)
        if new == flat:
            break
        flat = new
    return flat


def ops(text, pats):
    """Field ops in source order.

    Overlapping hits are the same call seen through two alternative patterns --
    keep the first."""
    flat = inline_aliases(normalize(text))
    hits = []
    for pat, kind, fixed, _scale in pats:
        for m in pat.finditer(flat):
            if kind == "chk":
                hits.append((m.start(), m.end(), ["chk", 0, 4]))
                continue
            off = int(m.group(1))
            n = fixed if fixed is not None else int(m.group(2))
            hits.append((m.start(), m.end(), [kind, off, n]))
    hits.sort(key=lambda h: (h[0], -h[1]))
    out, last = [], -1
    for start, end, op in hits:
        if start < last:
            continue
        out.append(op)
        last = end
    return out


# ------------------------------------------------------------ wrapper discovery
# The binary is full of one-line wrappers around the primitives above, generated
# by inlining a template on a fixed size ("save 4 bytes at &field"). Rather than
# enumerate them by hand, spot the shape: a body that calls exactly one known
# primitive, has no control flow, and passes a literal size.
DECL = re.compile(r"^\s*(?:const )?(?:unsigned |signed )?"
                  r"(?:int|char|_BYTE|_WORD|_DWORD|float|double|bool|BOOL|void|"
                  r"__int\d+|size_t)[\w \*]*;\s*(?://.*)?$")


def body_lines(text):
    out = []
    for l in text.splitlines():
        s = l.strip()
        if not s or s.startswith("//") or DECL.match(l):
            continue
        out.append(s)
    return out


def discover_wrappers(bodies, save_pats, load_pats):
    """Grow SAVE_PATS/LOAD_PATS with every thin wrapper found in `bodies`.

    Returns the number of new patterns added. Call until it returns 0 so that
    wrappers-of-wrappers resolve too."""
    known_save = {"sub_72BE90": ("raw", None), "sub_531BC0": ("ptr", 4),
                  "sub_533B90": ("info", 4)}
    known_load = {"sub_72BE50": ("raw", None), "sub_531F30": ("ptr", 4),
                  "sub_533BF0": ("info", 4)}
    for pat, kind, fixed, _ in save_pats:
        m = re.search(r"sub_[0-9A-F]+", pat.pattern)
        if m:
            known_save.setdefault(m.group(0), (kind, fixed))
    for pat, kind, fixed, _ in load_pats:
        m = re.search(r"sub_[0-9A-F]+", pat.pattern)
        if m:
            known_load.setdefault(m.group(0), (kind, fixed))

    added = 0
    for a, text in bodies.items():
        tok = "sub_" + a[2:].upper()
        if tok in known_save or tok in known_load:
            continue
        lines = body_lines(text)
        calls = {t for t in re.findall(r"\bsub_[0-9A-F]+\b", "\n".join(lines[1:]))}
        calls.discard(tok)
        if len(calls) != 1 or re.search(r"\b(for|while|goto|switch)\b", text):
            continue
        callee = calls.pop()
        # A wrapper forwards one buffer; the size is the literal in the call.
        size = None
        m = re.search(re.escape(callee) + r"\(([^;]*?)\)\s*(?:==|;|\))", text, re.S)
        if m:
            args = [x.strip() for x in m.group(1).split(",")]
            for i, x in enumerate(args):
                if x.isdigit() and i + 1 < len(args) and args[i + 1] == "0":
                    size = int(x)
                    break
        for known, table, pats in ((known_save, known_save, save_pats),
                                   (known_load, known_load, load_pats)):
            if callee not in known:
                continue
            kind, fixed = known[callee]
            n = fixed if fixed is not None else size
            if kind == "raw" and n is None:
                continue
            # wrapper(this@OFF) or wrapper(file, this@OFF) -- the GameOSFile*
            # travels in ecx and Hex-Rays surfaces it only sometimes.
            pats.append((rx(re.escape(tok) + r"\)?\([^;]*?%(s)s\)"), kind, n, 1))
            table[tok] = (kind, n)
            added += 1
            break
    return added


# ------------------------------------------------------------------ parent link
PARENT = re.compile(r"if \( !(?:\(\([^)]*\)\s*)?(sub_[0-9A-F]+)\)?\(")
CALLS = re.compile(r"\bsub_([0-9A-F]+)\b")


def parent_of(text, known=()):
    """Address of the base-class body this one delegates to.

    Normally the first statement is `if ( !<parent>(this, file) ) return 0;`.
    A few classes are pure forwarders (`return <parent>(file) != 0;`) with no
    guard at all, so fall back to the first call that is itself a known
    Save/Load body."""
    m = PARENT.search(text)
    if m:
        return "0x" + m.group(1)[4:].lower()
    own = None
    for i, a in enumerate(CALLS.findall(text)):
        cand = "0x" + a.lower()
        if i == 0:
            own = cand                      # the function's own signature line
            continue
        if cand != own and cand in known and "sub_" + a.upper() not in PRIMS:
            return cand
    return None


# -------------------------------------------------------------- irregularity
PRIMS = {
    "sub_72BE90", "sub_72BE50", "sub_604120", "sub_604170", "sub_66EE00",
    "sub_589540", "sub_4EBF70", "sub_4EC100", "sub_531BC0", "sub_531F30",
    "sub_533120", "sub_533110", "sub_533B90", "sub_533BF0", "sub_531FF0",
    "sub_532060", "sub_5341D0",
    "sub_533C50", "sub_533C90",                               # checksum marker
    "sub_5B3190",                                             # loader progress tick
    "sub_73445E", "sub_7344DA", "sub_733E17", "sub_7290DE",   # stack helpers
}
TOKEN = re.compile(r"\bsub_[0-9A-F]+\b|\bqmemcpy\b|\bmemset\b")


def leftovers(text, own, parent):
    skip = set(PRIMS)
    for a in (own, parent):
        if a:
            skip.add("sub_" + a[2:].upper())
    lines = [l for l in text.splitlines() if not l.lstrip().startswith("//")]
    bad = {t for t in TOKEN.findall("\n".join(lines[1:])) if t not in skip}
    if re.search(r"\b(for|while|goto)\b", text):
        bad.add("<loop>")
    return sorted(bad)


# ------------------------------------------------------------------------ main
def main():
    slots = read_slots(SLOTS)
    extra = read_addrs(PARENTS)

    # Learn the wrapper vocabulary from the ancestor/helper dump first, so the
    # field-op scan below recognises the size-specialised Write/Read aliases.
    rounds = 0
    while discover_wrappers(extra, SAVE_PATS, LOAD_PATS):
        rounds += 1
        if rounds > 5:
            break
    PRIMS.update(re.search(r"sub_[0-9A-F]+", p.pattern).group(0)
                 for p, _, _, _ in SAVE_PATS + LOAD_PATS
                 if re.search(r"sub_[0-9A-F]+", p.pattern))
    print("wrapper primitives  :", len(PRIMS))

    # class -> save type id
    ids = {}
    for c, sl in slots.items():
        if 60 in sl and "thunk" not in sl[60][1]:
            m = re.search(r"return (\d+);", sl[60][1])
            if m:
                ids[c] = int(m.group(1))

    # address -> body, for both the class dump and the ancestor dump.
    save_body, load_body = {}, {}
    save_users = collections.defaultdict(list)
    for c, sl in slots.items():
        if 59 in sl:
            save_body[sl[59][0]] = sl[59][1]
            save_users[sl[59][0]].append(c)
        if 58 in sl:
            load_body[sl[58][0]] = sl[58][1]
    for a, t in extra.items():
        save_body.setdefault(a, t)
        load_body.setdefault(a, t)

    # Which Save address does each savable class use, and which Load address?
    cls_save = {c: sl[59][0] for c, sl in slots.items() if 59 in sl}
    cls_load = {c: sl[58][0] for c, sl in slots.items() if 58 in sl}

    # Save and Load chains are parallel: walking either gives the same classes
    # in the same order, so pair them up as we walk from the leaf.
    def chain(addr, bodies):
        out, seen = [], set()
        while addr and addr in bodies and addr not in seen:
            seen.add(addr)
            out.append(addr)
            addr = parent_of(bodies[addr], bodies)
        return out, addr if (addr and addr not in bodies) else None

    missing = set()
    rows = {}
    for c in sorted(cls_save):
        sc, unk_s = chain(cls_save[c], save_body)
        lc, unk_l = chain(cls_load.get(c), load_body)
        for u in (unk_s, unk_l):
            if u:
                missing.add(u)
        # index parallel chains from the root so leaf/base pair up correctly
        for sa, la in zip(reversed(sc), reversed(lc)):
            if sa in rows:
                continue
            sv, ld = save_body[sa], load_body.get(la, "")
            rows[sa] = dict(
                addr=sa, load_addr=la,
                name=sorted(save_users.get(sa, [sa]), key=len)[0],
                parent=parent_of(sv, save_body),
                save_ops=ops(sv, SAVE_PATS),
                load_ops=ops(ld, LOAD_PATS),
                odd=sorted(set(leftovers(sv, sa, parent_of(sv, save_body))) |
                           set(leftovers(ld, la, parent_of(ld, load_body)))),
            )

    json.dump(dict(rows=list(rows.values()),
                   ids={c: ids[c] for c in sorted(ids)},
                   cls_save=cls_save,
                   missing=sorted(missing)),
              open(OUT, "w"), indent=1)

    clean = [r for r in rows.values() if not r["odd"]]
    print("savable classes     :", len(cls_save))
    print("  with save-type id :", len(ids))
    print("distinct chain rows :", len(rows))
    print("  regular           :", len(clean))
    print("  irregular         :", len(rows) - len(clean))
    if missing:
        print("\nancestor bodies not yet dumped (feed to `bw_decomp.py addr`):")
        print(" ".join(sorted(missing)))
    print("\n--- irregular rows ---")
    for r in sorted(rows.values(), key=lambda r: r["name"]):
        if r["odd"]:
            print("  %-28s %s" % (r["name"], " ".join(r["odd"][:7])))


if __name__ == "__main__":
    main()
