#!/usr/bin/env python3
"""Probe BW binary: how are functions named, and are RTTI vftables present?

    py -3.11 bw_probe.py <exe>

Saves the database (.i64) on exit so later runs reopen fast.
"""
import sys
import idapro
import ida_auto, idautils, ida_funcs, ida_name, ida_bytes, idc

exe = sys.argv[1]
print(f"[*] opening {exe} ...", file=sys.stderr)
if idapro.open_database(exe, True):
    raise SystemExit("open failed")
ida_auto.auto_wait()

funcs = list(idautils.Functions())
def is_sub(n): return n.startswith(("sub_", "nullsub_", "j_", "unknown_libname"))
named = [ea for ea in funcs if not is_sub(ida_funcs.get_func_name(ea))]
print(f"functions      : {len(funcs)}")
print(f"named non-sub  : {len(named)}")
print("--- first 10 named (non-sub) functions ---")
for ea in named[:10]:
    print(f"  {hex(ea)}  {ida_funcs.get_func_name(ea)}")

print("--- ALL names containing 'PSys' (data + code) ---")
cnt = 0
for ea, name in idautils.Names():
    if "PSys" in name:
        dem = idc.demangle_name(name, idc.get_inf_attr(idc.INF_SHORT_DN)) or ""
        print(f"  {hex(ea)}  {name}   {('=> '+dem) if dem else ''}")
        cnt += 1
        if cnt > 60:
            break
print(f"(PSys-name hits shown: {cnt})")

# If a PSysManager vftable symbol exists, dump its slot pointers.
for sym in ("??_7PSysManager@@6B@", "_ZTV11PSysManager", "PSysManager::`vftable'"):
    ea = ida_name.get_name_ea(idc.BADADDR, sym)
    if ea != idc.BADADDR:
        print(f"--- vftable {sym} @ {hex(ea)} ---")
        for i in range(20):
            p = ida_bytes.get_dword(ea + i * 4)
            f = ida_funcs.get_func(p)
            if not f or f.start_ea != p:
                break
            print(f"  slot[{i:2}] -> {hex(p)}  {ida_funcs.get_func_name(p)}")
        break

idapro.close_database(save=True)
print("[*] database saved (.i64) for fast reopen", file=sys.stderr)
