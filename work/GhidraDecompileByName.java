// Decompile functions by mangled C++ name pattern
// Usage: -postScript GhidraDecompileByName.java <search_patterns.txt> <output.txt>
//
// search_patterns.txt: one MSVC mangled name fragment per line, e.g.:
//   ?Process@Town@@
//   ?Built@MultiMapFixed@@
//   ?AddVillagerToAbode@Abode@@
//
// @author sp00nz/Claude
// @category Decompilation

import ghidra.app.decompiler.*;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.util.*;

public class GhidraDecompileByName extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 1) {
            println("Usage: GhidraDecompileByName.java <patterns.txt> [output.txt]");
            return;
        }

        String patternFile = args[0];
        String outFile = args.length > 1 ? args[1] : patternFile.replace(".txt", "_decompiled.txt");

        // Read search patterns
        List<String> patterns = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(patternFile))) {
            String line;
            while ((line = reader.readLine()) != null) {
                line = line.trim();
                if (!line.isEmpty() && !line.startsWith("//") && !line.startsWith("#")) {
                    // Strip inline comments
                    int ci = line.indexOf("//");
                    if (ci > 0) line = line.substring(0, ci).trim();
                    patterns.add(line);
                }
            }
        }

        println("=== Ghidra Decompile By Name ===");
        println("Patterns: " + patterns.size());
        println("Output: " + outFile);

        // Set up decompiler
        DecompInterface decomp = new DecompInterface();
        decomp.setOptions(new DecompileOptions());
        decomp.openProgram(currentProgram);

        FunctionManager fm = currentProgram.getFunctionManager();
        int success = 0, failed = 0;

        try (PrintWriter out = new PrintWriter(new FileWriter(outFile))) {
            out.println("// ============================================================");
            out.println("// Black & White Decompilation by Name Pattern");
            out.println("// Binary: " + currentProgram.getName());
            out.println("// Patterns: " + patterns.size());
            out.println("// Date: " + new Date());
            out.println("// ============================================================");
            out.println();

            for (String pattern : patterns) {
                println("Searching for: " + pattern);
                boolean found = false;

                // Search all functions for name match
                FunctionIterator funcIter = fm.getFunctions(true);
                while (funcIter.hasNext()) {
                    Function func = funcIter.next();
                    String name = func.getName();

                    if (name.contains(pattern) || pattern.contains(name)) {
                        found = true;
                        long addr = func.getEntryPoint().getOffset();
                        long size = func.getBody().getNumAddresses();

                        try {
                            DecompileResults results = decomp.decompileFunction(func, 60, monitor);
                            if (results.decompileCompleted()) {
                                out.println("// ========================================");
                                out.println("// Pattern: " + pattern);
                                out.println("// Function: " + name);
                                out.println("// Address: 0x" + String.format("%08x", addr));
                                out.println("// Size: " + size + " bytes");
                                out.println("// ========================================");
                                out.println();
                                out.println(results.getDecompiledFunction().getC());
                                out.println();
                                success++;
                                println("  FOUND: " + name + " @ 0x" + String.format("%08x", addr) + " (" + size + " bytes)");
                            }
                        } catch (Exception e) {
                            println("  ERROR decompiling: " + name);
                            failed++;
                        }
                        break;  // Only first match per pattern
                    }
                }

                if (!found) {
                    out.println("// NOT FOUND: " + pattern);
                    out.println();
                    println("  NOT FOUND: " + pattern);
                    failed++;
                }
            }

            out.println("// Summary: " + success + " found, " + failed + " missing");
        } finally {
            decomp.closeProgram();
        }

        println("\n=== Complete: " + success + " found, " + failed + " missing ===");
    }
}
