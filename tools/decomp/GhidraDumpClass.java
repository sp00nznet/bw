// GhidraDumpClass — decompile each class's virtual methods by walking its RTTI
// vftable (cross-check for the IDA idalib extractor, tools/decomp/bw_decomp.py).
//
// The BW release binary has RTTI but NO symbol table: every function is
// FUN_xxxxxxxx, so you CANNOT find a class's methods by name. You CAN find them
// via RTTI — Ghidra's "Windows x86 PE RTTI Analyzer" labels each class vftable
// (e.g. PSysManager::vftable or ??_7PSysManager@@6B@). We resolve that label,
// read consecutive function pointers (stopping at the next vftable), and
// decompile each slot. Slot order == vtable order, so it pairs 1:1 with the
// vendor header's virtual-method list.
//
// Usage (headless, against the already-analysed project):
//   analyzeHeadless <projDir> <projName> -process <prog> -noanalysis \
//       -postScript GhidraDumpClass.java <classlist.txt> <out.txt>
//
// classlist.txt: one class name per line (e.g. "PSysManager", "AtomCore").
//
// @author sp00nz/Claude
// @category Decompilation

import ghidra.app.decompiler.*;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.util.*;

public class GhidraDumpClass extends GhidraScript {

    // Resolve a class's vftable address from its RTTI label, trying the common
    // demangled / mangled forms Ghidra emits.
    private Address findVftable(String cls) {
        String[] names = {
            cls + "::vftable", cls + "::`vftable'",
            "??_7" + cls + "@@6B@", cls + "_vftable",
        };
        SymbolTable st = currentProgram.getSymbolTable();
        for (String n : names) {
            SymbolIterator it = st.getSymbols(n);
            if (it.hasNext()) return it.next().getAddress();
        }
        // Fallback: any symbol containing "??_7<cls>@@6B".
        String needle = "??_7" + cls + "@@6B";
        for (Symbol s : st.getAllSymbols(false)) {
            if (s.getName().contains(needle)) return s.getAddress();
        }
        return null;
    }

    // Collect the set of all vftable addresses so a walk can stop at the next.
    private Set<Address> allVftables() {
        Set<Address> out = new HashSet<>();
        for (Symbol s : currentProgram.getSymbolTable().getAllSymbols(false)) {
            String n = s.getName();
            if (n.startsWith("??_7") || n.endsWith("::vftable")) out.add(s.getAddress());
        }
        return out;
    }

    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 1) { println("Usage: GhidraDumpClass <classlist.txt> [out.txt]"); return; }
        String listFile = args[0];
        String outFile  = args.length > 1 ? args[1] : listFile.replace(".txt", "_ghidra.txt");

        List<String> classes = new ArrayList<>();
        try (BufferedReader r = new BufferedReader(new FileReader(listFile))) {
            String line;
            while ((line = r.readLine()) != null) {
                line = line.trim();
                if (!line.isEmpty() && !line.startsWith("//") && !line.startsWith("#"))
                    classes.add(line);
            }
        }

        Set<Address> vtAddrs = allVftables();
        Memory mem = currentProgram.getMemory();
        Listing listing = currentProgram.getListing();
        DecompInterface decomp = new DecompInterface();
        decomp.setOptions(new DecompileOptions());
        decomp.openProgram(currentProgram);

        int total = 0, found = 0;
        try (PrintWriter out = new PrintWriter(new FileWriter(outFile))) {
            out.println("// BW class-method dump (Ghidra, RTTI vftable walk)");
            out.println("// Binary: " + currentProgram.getName() + "  Date: " + new Date() + "\n");
            for (String cls : classes) {
                Address vt = findVftable(cls);
                if (vt == null) { out.println("// ===== CLASS " + cls + " : no vftable =====\n");
                                  println("  " + cls + ": (no vftable)"); continue; }
                found++;
                out.println("// =========================================================");
                out.println("// CLASS " + cls + "  vftable @ " + vt);
                out.println("// =========================================================\n");
                int n = 0;
                for (int i = 0; i < 512; i++) {
                    Address slot = vt.add(i * 4L);
                    if (i > 0 && vtAddrs.contains(slot)) break;
                    long ptr;
                    try { ptr = Integer.toUnsignedLong(mem.getInt(slot)); } catch (Exception e) { break; }
                    Address fa = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(ptr);
                    Function f = listing.getFunctionAt(fa);
                    if (f == null) break;
                    out.println("// ---- " + cls + "::vslot[" + i + "]  @ " + fa + " ----");
                    try {
                        DecompileResults res = decomp.decompileFunction(f, 60, monitor);
                        out.println(res.decompileCompleted()
                            ? res.getDecompiledFunction().getC()
                            : "// (decompile failed)");
                    } catch (Exception e) { out.println("// (exception: " + e.getMessage() + ")"); }
                    out.println();
                    n++; total++;
                }
                println("  " + cls + ": " + n);
            }
            out.println("// Summary: " + total + " slots across " + found + "/" + classes.size() + " classes");
        } finally { decomp.closeProgram(); }
        println("Done: " + total + " slots, " + found + "/" + classes.size() + " classes");
    }
}
