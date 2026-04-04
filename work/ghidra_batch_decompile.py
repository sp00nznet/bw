# Ghidra headless batch decompiler for Black & White static recompilation
# Run via: analyzeHeadless <project_dir> <project_name> -import <binary> \
#          -scriptPath <this_dir> -postScript ghidra_batch_decompile.py <addresses.txt> <output.txt>
#
# Or for an already-imported project:
#   analyzeHeadless <project_dir> <project_name> -noanalysis \
#   -scriptPath <this_dir> -postScript ghidra_batch_decompile.py <addresses.txt> <output.txt>
#
# @author sp00nz/Claude
# @category Decompilation
# @description Batch decompile functions at specified addresses

from ghidra.app.decompiler import DecompInterface, DecompileOptions
from ghidra.util.task import ConsoleTaskMonitor
import os
import sys
import time

def read_addresses(filepath):
    """Read hex addresses from file, one per line. Skips comments and blanks."""
    addresses = []
    with open(filepath, 'r') as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith('//') or line.startswith('#'):
                continue
            # Strip inline comments
            if '//' in line:
                line = line[:line.index('//')].strip()
            if '#' in line:
                line = line[:line.index('#')].strip()
            try:
                addr = int(line, 16) if line.startswith('0x') or line.startswith('0X') else int(line, 16)
                addresses.append(addr)
            except ValueError:
                print("WARNING: Skipping invalid address: " + line)
    return addresses

def get_function_at(program, addr_long):
    """Get or create a function at the given address."""
    addr_factory = program.getAddressFactory()
    addr = addr_factory.getDefaultAddressSpace().getAddress(addr_long)

    # Try to get existing function
    func = getFunctionContaining(addr)
    if func and func.getEntryPoint().equals(addr):
        return func

    # Try exact match
    func = program.getFunctionManager().getFunctionAt(addr)
    if func:
        return func

    # Function might not be defined — try to create it
    from ghidra.app.cmd.function import CreateFunctionCmd
    cmd = CreateFunctionCmd(addr)
    cmd.applyTo(program, ConsoleTaskMonitor())
    return program.getFunctionManager().getFunctionAt(addr)

def run():
    args = getScriptArgs()

    if len(args) < 1:
        print("Usage: ghidra_batch_decompile.py <addresses.txt> [output.txt]")
        print("  addresses.txt: file with one hex address per line")
        print("  output.txt: output file for decompiled C (default: decompiled_output.txt)")
        return

    addr_file = args[0]
    out_file = args[1] if len(args) > 1 else os.path.join(os.path.dirname(addr_file), "decompiled_output.txt")

    print("=== Ghidra Batch Decompiler ===")
    print("Binary: " + currentProgram.getName())
    print("Address file: " + addr_file)
    print("Output file: " + out_file)

    # Read target addresses
    addresses = read_addresses(addr_file)
    print("Loaded %d addresses to decompile" % len(addresses))

    # Set up decompiler
    decomp = DecompInterface()
    opts = DecompileOptions()
    decomp.setOptions(opts)
    decomp.openProgram(currentProgram)

    start_time = time.time()
    success = 0
    failed = 0
    skipped = 0

    with open(out_file, 'w') as out:
        out.write("// ============================================================\n")
        out.write("// Black & White Batch Decompilation Output\n")
        out.write("// Binary: %s\n" % currentProgram.getName())
        out.write("// Addresses: %d\n" % len(addresses))
        out.write("// ============================================================\n\n")

        for i, addr_long in enumerate(addresses):
            addr_hex = "0x%08x" % addr_long
            func = get_function_at(currentProgram, addr_long)

            if not func:
                print("[%d/%d] SKIP: %s — no function found" % (i+1, len(addresses), addr_hex))
                out.write("// SKIP: %s — no function at this address\n\n" % addr_hex)
                skipped += 1
                continue

            func_name = func.getName()
            func_size = func.getBody().getNumAddresses()

            try:
                results = decomp.decompileFunction(func, 60, ConsoleTaskMonitor())

                if results.decompileCompleted():
                    c_code = results.getDecompiledFunction().getC()

                    out.write("// ========================================\n")
                    out.write("// [%d] %s\n" % (i+1, func_name))
                    out.write("// Address: %s\n" % addr_hex)
                    out.write("// Size: %d bytes\n" % func_size)
                    out.write("// ========================================\n\n")
                    out.write(c_code)
                    out.write("\n\n")

                    success += 1
                    print("[%d/%d] OK: %s @ %s (%d bytes)" % (i+1, len(addresses), func_name, addr_hex, func_size))
                else:
                    error_msg = results.getErrorMessage() if results.getErrorMessage() else "unknown error"
                    out.write("// FAILED: %s @ %s — %s\n\n" % (func_name, addr_hex, error_msg))
                    failed += 1
                    print("[%d/%d] FAILED: %s @ %s — %s" % (i+1, len(addresses), func_name, addr_hex, error_msg))

            except Exception as e:
                out.write("// ERROR: %s @ %s — %s\n\n" % (func_name, addr_hex, str(e)))
                failed += 1
                print("[%d/%d] ERROR: %s — %s" % (i+1, len(addresses), func_name, str(e)))

        elapsed = time.time() - start_time

        out.write("// ============================================================\n")
        out.write("// SUMMARY\n")
        out.write("// Total: %d | Success: %d | Failed: %d | Skipped: %d\n" % (len(addresses), success, failed, skipped))
        out.write("// Time: %.1f seconds (%.2f func/sec)\n" % (elapsed, success / max(elapsed, 0.001)))
        out.write("// ============================================================\n")

    decomp.closeProgram()

    print("\n=== Complete ===")
    print("Success: %d / %d" % (success, len(addresses)))
    print("Failed: %d, Skipped: %d" % (failed, skipped))
    print("Time: %.1f seconds" % elapsed)
    print("Output: %s" % out_file)

run()
