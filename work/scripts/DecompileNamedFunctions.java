// Export decompiled C code for all named (non-FUN_) functions
// Groups output by class (extracted from mangled names)
//
// @category Analysis

import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.util.*;

public class DecompileNamedFunctions extends GhidraScript {

    @Override
    public void run() throws Exception {
        FunctionManager fm = currentProgram.getFunctionManager();

        // Set up decompiler
        DecompInterface decomp = new DecompInterface();
        decomp.openProgram(currentProgram);
        DecompileOptions options = new DecompileOptions();
        decomp.setOptions(options);

        String outDir = "D:/recomp/pc/bw/work/decompiled";
        new File(outDir).mkdirs();

        // Collect all named functions grouped by class
        Map<String, List<Function>> classFuncs = new TreeMap<>();
        int totalNamed = 0;

        FunctionIterator iter = fm.getFunctions(true);
        while (iter.hasNext()) {
            Function func = iter.next();
            String name = func.getName();

            // Skip unnamed, thunks, externals
            if (name.startsWith("FUN_") || func.isThunk() || func.isExternal()) continue;

            // Extract class name from MSVC mangled name
            String className = extractClassName(name);
            classFuncs.computeIfAbsent(className, k -> new ArrayList<>()).add(func);
            totalNamed++;
        }

        println("Found " + totalNamed + " named functions in " + classFuncs.size() + " classes");

        // Decompile priority classes first (core game hierarchy)
        String[] priorityClasses = {
            "Base", "GameThing", "GameThingWithPos", "Object",
            "Fixed", "MultiMapFixed", "Abode",
            "Mobile", "MobileWallHug", "Living", "Animal",
            "Creature", "Villager", "SpecialVillager",
            "Town", "TownCentre", "WorshipSite", "Citadel",
            "Spell", "SpellIcon", "TownSpellIcon",
            "Tree", "Forest", "BigForest",
            "GGame", "GScript", "ScriptManage",
            "GBaseInfo", "GAlignmentInfo", "GAnimalInfo",
            "GCamera", "CameraMode", "CameraModeFree",
            "PSysManager", "LH_AudioSystem"
        };

        // Create an index file
        PrintWriter indexWriter = new PrintWriter(new FileWriter(outDir + "/index.txt"));
        indexWriter.println("=== Decompiled Functions Index ===");
        indexWriter.println("Total named functions: " + totalNamed);
        indexWriter.println("Total classes: " + classFuncs.size());
        indexWriter.println();

        int decompiled = 0;
        int failed = 0;
        Set<String> processedClasses = new HashSet<>();

        // Process priority classes first
        for (String cls : priorityClasses) {
            List<Function> funcs = classFuncs.get(cls);
            if (funcs == null) continue;
            processedClasses.add(cls);

            int[] result = decompileClass(decomp, cls, funcs, outDir, indexWriter);
            decompiled += result[0];
            failed += result[1];
        }

        // Then process all remaining classes
        for (Map.Entry<String, List<Function>> entry : classFuncs.entrySet()) {
            String cls = entry.getKey();
            if (processedClasses.contains(cls)) continue;

            int[] result = decompileClass(decomp, cls, entry.getValue(), outDir, indexWriter);
            decompiled += result[0];
            failed += result[1];

            // Stop if we've done enough (don't want to take forever)
            if (decompiled + failed > 3000) {
                println("  Stopping after 3000 functions to save time");
                break;
            }
        }

        indexWriter.close();
        decomp.dispose();

        println("\n=== Decompilation Complete ===");
        println("Successfully decompiled: " + decompiled);
        println("Failed: " + failed);
        println("Output directory: " + outDir);
    }

    private int[] decompileClass(DecompInterface decomp, String className,
                                  List<Function> funcs, String outDir,
                                  PrintWriter indexWriter) throws Exception {
        int ok = 0, fail = 0;
        String sanitizedName = className.replaceAll("[^A-Za-z0-9_]", "_");
        String filePath = outDir + "/" + sanitizedName + ".c";
        PrintWriter writer = new PrintWriter(new FileWriter(filePath));
        writer.println("// Decompiled functions for class: " + className);
        writer.println("// Source: Black & White v1.0 (runblack_decrypted.exe)");
        writer.println("// Auto-decompiled by Ghidra " + ghidraVer());
        writer.println();

        indexWriter.println(className + " (" + funcs.size() + " functions) -> " + sanitizedName + ".c");

        for (Function func : funcs) {
            monitor.checkCancelled();

            DecompileResults results = decomp.decompileFunction(func, 30, monitor);

            if (results != null && results.decompileCompleted()) {
                ClangTokenGroup tokens = results.getCCodeMarkup();
                if (tokens != null) {
                    writer.println("// " + func.getName() + " @ 0x" + func.getEntryPoint());
                    writer.println(results.getDecompiledFunction().getC());
                    writer.println();
                    ok++;
                } else {
                    writer.println("// FAILED: " + func.getName() + " @ 0x" + func.getEntryPoint());
                    writer.println();
                    fail++;
                }
            } else {
                writer.println("// FAILED: " + func.getName() + " @ 0x" + func.getEntryPoint());
                writer.println();
                fail++;
            }
        }

        writer.close();

        if (ok + fail > 0) {
            println("  " + className + ": " + ok + " ok, " + fail + " failed");
        }

        return new int[]{ok, fail};
    }

    private String extractClassName(String mangledName) {
        // MSVC mangled: ?FuncName@ClassName@@...
        if (mangledName.startsWith("?")) {
            int firstAt = mangledName.indexOf('@');
            if (firstAt > 0) {
                int secondAt = mangledName.indexOf('@', firstAt + 1);
                if (secondAt > firstAt + 1) {
                    return mangledName.substring(firstAt + 1, secondAt);
                }
            }
        }
        // Old-style mangled: _FuncName__ClassNameFparams
        if (mangledName.startsWith("_")) {
            int dunder = mangledName.indexOf("__");
            if (dunder > 0) {
                String rest = mangledName.substring(dunder + 2);
                // Class name ends at next non-alphanumeric
                StringBuilder sb = new StringBuilder();
                // Skip leading digits (length prefix)
                int i = 0;
                while (i < rest.length() && Character.isDigit(rest.charAt(i))) i++;
                while (i < rest.length() && (Character.isLetterOrDigit(rest.charAt(i)) || rest.charAt(i) == '_')) {
                    sb.append(rest.charAt(i));
                    i++;
                }
                if (sb.length() > 0) return sb.toString();
            }
        }
        // Special names
        if (mangledName.startsWith("__")) return "_CRT";
        return "_misc";
    }

    private String ghidraVer() {
        try {
            return ghidra.framework.Application.getApplicationVersion();
        } catch (Exception e) {
            return "12.0.3";
        }
    }
}
