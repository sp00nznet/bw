#!/usr/bin/env python3
"""BW class-method decompiler (IDA idalib).

The BW release binary has RTTI but NO symbol table, so functions are unnamed
(sub_xxxx). Class<->method association is recovered from RTTI vftables, whose
symbols ARE derived from the class name (e.g. ??_7PSysManager@@6B@). We walk a
class's vftable, pair each slot with the vendor header's virtual-method order,
and decompile every slot via Hex-Rays.

    py -3.11 bw_decomp.py <exe-or-i64> classes <classlist.txt> <out.txt> [slot ...]
    py -3.11 bw_decomp.py <exe-or-i64> vtable  <ClassName>
    py -3.11 bw_decomp.py <exe-or-i64> addr    <0xADDR> [more 0xADDR ...]
    py -3.11 bw_decomp.py <exe-or-i64> xrefs   <0xADDR> [...]   who references it
    py -3.11 bw_decomp.py <exe-or-i64> callees <0xADDR> [...]   what it calls
    py -3.11 bw_decomp.py <exe-or-i64> floats  <0xADDR> <count>  read a data table
    py -3.11 bw_decomp.py <exe-or-i64> disasm  <0xADDR> [...]   raw instructions
    py -3.11 bw_decomp.py <exe-or-i64> doubles <0xADDR> <count>  read a double table
    py -3.11 bw_decomp.py <exe-or-i64> table   <0xBASE> <recsz> <count> [rows]
    py -3.11 bw_decomp.py <exe-or-i64> mkfunc  <0xSTART> <0xEND>   force-analyse a range

The first run on the .exe analyses + saves a .i64; pass that .i64 afterwards
for fast reopen.
"""
import sys
import idapro
import ida_auto, ida_funcs, ida_name, ida_bytes, ida_hexrays, ida_xref, idc, idautils

VTABLE_PATTERNS = ("??_7{c}@@6B@", "{c}::`vftable'", "??_7{c}@@6B@@")

# Addresses of every ??_7… vftable in the image — used as hard stop boundaries
# so a vtable walk never bleeds into the next class's table (they are packed
# back-to-back in .rdata and intermediate entries carry no get_name()).
VFTABLE_SET = set()


def find_vftable(cls):
    for pat in VTABLE_PATTERNS:
        ea = ida_name.get_name_ea(idc.BADADDR, pat.format(c=cls))
        if ea != idc.BADADDR:
            return ea
    # Fallback: scan all names for a vftable symbol of this class. Match
    # "??_7<cls>@@6B" so multiple-inheritance vftables (…@@6B<Base>@@) hit too.
    needle = "%s@@6B" % cls
    for ea, name in idautils.Names():
        if name.startswith("??_7") and needle in name:
            return ea
    return idc.BADADDR


def vtable_slots(ea, limit=512):
    """Function pointers of one vftable. Stops at the next labelled symbol so
    we don't bleed into the adjacent vftable (they are packed in .rdata, each
    starting with its own ??_7… label)."""
    out = []
    for i in range(limit):
        slot = ea + i * 4
        if i > 0 and slot in VFTABLE_SET:          # next class's vftable begins
            break
        p = ida_bytes.get_dword(slot)
        f = ida_funcs.get_func(p)
        if not f or f.start_ea != p:
            break
        out.append(p)
    return out


def decompile(ea):
    f = ida_funcs.get_func(ea)
    if not f:
        return "// (no function at %s)" % hex(ea)
    try:
        return str(ida_hexrays.decompile(f))
    except Exception as e:                       # noqa: BLE001
        return "// (decompile failed: %s)" % e


def emit_class(cls, out, want=None):
    """want: set of slot indices to emit (None = every slot)."""
    vt = find_vftable(cls)
    if vt == idc.BADADDR:
        out.write("// ===== CLASS %s : no vftable symbol found =====\n\n" % cls)
        return 0
    slots = vtable_slots(vt)
    out.write("// ============================================================\n")
    out.write("// CLASS %s  vftable @ %s  (%d virtual slots)\n" % (cls, hex(vt), len(slots)))
    out.write("// ============================================================\n\n")
    n = 0
    for i, ea in enumerate(slots):
        if want is not None and i not in want:
            continue
        out.write("// ---- %s::vslot[%d]  @ %s ----\n" % (cls, i, hex(ea)))
        out.write(decompile(ea))
        out.write("\n\n")
        n += 1
    return n


def main():
    exe = sys.argv[1]
    cmd = sys.argv[2] if len(sys.argv) > 2 else "info"
    print("[*] opening %s ..." % exe, file=sys.stderr)
    if idapro.open_database(exe, True):
        raise SystemExit("open failed")
    ida_auto.auto_wait()
    if not ida_hexrays.init_hexrays_plugin():
        raise SystemExit("Hex-Rays not available")

    for nea, nm in idautils.Names():
        if nm.startswith("??_7"):
            VFTABLE_SET.add(nea)
    print("[*] %d vftables indexed" % len(VFTABLE_SET), file=sys.stderr)

    save = True
    if cmd == "classes":
        listfile, outfile = sys.argv[3], sys.argv[4]
        want = set(int(x) for x in sys.argv[5:]) or None
        classes = [l.strip() for l in open(listfile, encoding="utf-8")
                   if l.strip() and not l.startswith(("#", "//"))]
        total = found = 0
        with open(outfile, "w", encoding="utf-8") as out:
            out.write("// BW class-method dump (IDA Hex-Rays)\n\n")
            for c in classes:
                n = emit_class(c, out, want)
                total += n
                found += 1 if n else 0
                print("  %-32s %d" % (c, n))
            out.write("// Summary: %d slots across %d/%d classes\n" % (total, found, len(classes)))
        print("[*] wrote %s (%d slots, %d/%d classes)" % (outfile, total, found, len(classes)))
    elif cmd == "vtable":
        emit_class(sys.argv[3], sys.stdout)
    elif cmd == "addr":
        for a in sys.argv[3:]:
            print("// ---- %s ----" % a)
            print(decompile(int(a, 16)))
    elif cmd == "strings":
        # Resolve IDA's auto-named string symbols (aVanishage, aSpeed, ...) back
        # to their actual text. The auto-name loses case and punctuation, which
        # matters when the string is a property name being recovered verbatim.
        names = sys.argv[3:]
        if names == ["-"]:
            names = [l.strip() for l in sys.stdin if l.strip()]
        for nm in names:
            ea = ida_name.get_name_ea(idc.BADADDR, nm)
            if ea == idc.BADADDR:
                print("%s\t?" % nm)
                continue
            s = ida_bytes.get_strlit_contents(ea, -1, 0)
            print("%s\t%s" % (nm, s.decode("latin-1") if s else "?"))
    elif cmd == "xrefs":
        # Who references this address, and from which function. The vtable walk
        # only reaches virtual methods; a class like AttributeTest is plain data
        # with non-virtual methods, so the only way in is to follow references
        # from something we have already identified.
        for a in sys.argv[3:]:
            ea = int(a, 16)
            print("// ---- xrefs to %s ----" % hex(ea))
            seen = set()
            for xref in idautils.XrefsTo(ea, 0):
                f = ida_funcs.get_func(xref.frm)
                owner = hex(f.start_ea) if f else "(not in a function)"
                key = (owner, xref.frm)
                if key in seen:
                    continue
                seen.add(key)
                print("%-12s from %-12s in %s" % (
                    "data" if xref.iscode == 0 else "code", hex(xref.frm), owner))
    elif cmd == "mkfunc":
        # Force IDA to treat a range as code and make functions out of it.
        #
        # Several of this binary's dispatch tables are filled by long inlined
        # initialisers that IDA never recognised as functions. Everything else
        # in the toolkit -- xrefs, callees, decompile -- is function-scoped, so
        # those regions are invisible until this runs. It is the difference
        # between "no xref to that table" and reading the code that fills it.
        #
        #   mkfunc <0xSTART> <0xEND>
        start, end = int(sys.argv[3], 16), int(sys.argv[4], 16)
        made = existing = failed = 0
        ea = start
        while ea < end:
            f = ida_funcs.get_func(ea)
            if f:
                existing += 1
                ea = max(f.end_ea, ea + 1)
                continue
            if not ida_bytes.is_code(ida_bytes.get_flags(ea)):
                idc.create_insn(ea)
            if ida_funcs.add_func(ea):
                made += 1
                f = ida_funcs.get_func(ea)
                ea = max(f.end_ea, ea + 1) if f else ea + 1
            else:
                failed += 1
                ea += 1
        ida_auto.auto_wait()
        print("[*] %s..%s: %d functions created, %d already present, %d spots refused"
              % (hex(start), hex(end), made, existing, failed))
    elif cmd == "disasm":
        # Raw instructions. Hex-Rays folds x87 idioms away -- an fyl2x becomes a
        # multiply with a discarded call, say -- so anything numerically load
        # bearing has to be read at this level before it is trusted.
        for a in sys.argv[3:]:
            ea = int(a, 16)
            f = ida_funcs.get_func(ea)
            print("// ---- disasm %s ----" % hex(ea))
            if not f:
                print("(no function)")
                continue
            for item in idautils.FuncItems(f.start_ea):
                print("%s  %s" % (hex(item), idc.GetDisasm(item)))
    elif cmd == "table":
        # Dump a static array of records, one row per field, showing each dword
        # as int / float / string so the layout can be read off rather than
        # guessed. The creature's tuning tables are shipped this way and neither
        # our headers nor the vendor's map their payload.
        #   table <0xBASE> <recsize> <count> [max_rows]
        import struct as _struct
        base = int(sys.argv[3], 16)
        recsz = int(sys.argv[4])
        count = int(sys.argv[5])
        rows = int(sys.argv[6]) if len(sys.argv) > 6 else count
        for r in range(min(rows, count)):
            ra = base + r * recsz
            print("// ---- record %d @ %s ----" % (r, hex(ra)))
            for off in range(0, recsz, 4):
                raw = ida_bytes.get_bytes(ra + off, 4)
                if not raw:
                    continue
                u = _struct.unpack("<I", raw)[0]
                f = _struct.unpack("<f", raw)[0]
                note = ""
                # A plausible pointer into the image: try it as a string.
                if 0x400000 < u < 0xE00000:
                    s = ida_bytes.get_strlit_contents(u, -1, 0)
                    if s and 1 <= len(s) < 64 and all(32 <= c < 127 for c in s):
                        note = '  "%s"' % s.decode("latin-1")
                    else:
                        nm = ida_name.get_name(u)
                        if nm:
                            note = "  %s" % nm
                fs = ("%g" % f) if (abs(f) > 1e-6 and abs(f) < 1e9) else ""
                print("  +%-4d %10d  0x%08x  %-12s%s" % (off, u, u, fs, note))
    elif cmd == "doubles":
        base = int(sys.argv[3], 16)
        count = int(sys.argv[4]) if len(sys.argv) > 4 else 1
        import struct as _struct
        for i in range(count):
            raw = ida_bytes.get_bytes(base + i * 8, 8)
            val = _struct.unpack("<d", raw)[0] if raw else float("nan")
            print("[%2d] %s  %.17g" % (i, hex(base + i * 8), val))
    elif cmd == "floats":
        # Read a run of floats from a data address. Tuning tables live in .rdata
        # as bare arrays with no symbol beyond the first element, and reading
        # them beats inferring them from the code that indexes them.
        base = int(sys.argv[3], 16)
        count = int(sys.argv[4]) if len(sys.argv) > 4 else 1
        import struct as _struct
        for i in range(count):
            raw = ida_bytes.get_bytes(base + i * 4, 4)
            val = _struct.unpack("<f", raw)[0] if raw else float("nan")
            print("[%2d] %s  %g" % (i, hex(base + i * 4), val))
    elif cmd == "callees":
        # Every function this one calls, in address order -- the cheap way to
        # map a subsystem once one entry point into it is known.
        for a in sys.argv[3:]:
            ea = int(a, 16)
            f = ida_funcs.get_func(ea)
            print("// ---- callees of %s ----" % hex(ea))
            if not f:
                continue
            out = []
            for item in idautils.FuncItems(f.start_ea):
                for xref in idautils.XrefsFrom(item, 0):
                    if xref.type in (ida_xref.fl_CN, ida_xref.fl_CF):
                        callee = ida_funcs.get_func(xref.to)
                        if callee and callee.start_ea not in out:
                            out.append(callee.start_ea)
            for c in out:
                print(hex(c))
    else:
        print("unknown command", cmd, file=sys.stderr)
        save = False

    idapro.close_database(save=save)


if __name__ == "__main__":
    main()
