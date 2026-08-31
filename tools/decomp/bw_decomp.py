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
