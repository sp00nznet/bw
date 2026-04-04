// Ghidra headless batch decompiler for Black & White static recompilation
// Run via: analyzeHeadless <project_dir> <project_name> -process <binary>
//          -noanalysis -scriptPath <this_dir>
//          -postScript GhidraBatchDecompile.java <addresses.txt> <output.txt>
//
// @author sp00nz/Claude
// @category Decompilation
// @description Batch decompile functions at specified addresses to C pseudocode

import ghidra.app.decompiler.*;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.util.task.ConsoleTaskMonitor;
import java.io.*;
import java.util.*;

public class GhidraBatchDecompile extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();

        if (args.length < 1) {
            println("Usage: GhidraBatchDecompile.java <addresses.txt> [output.txt]");
            return;
        }

        String addrFile = args[0];
        String outFile = args.length > 1 ? args[1] :
            addrFile.replace(".txt", "_decompiled.txt");

        println("=== Ghidra Batch Decompiler ===");
        println("Binary: " + currentProgram.getName());
        println("Address file: " + addrFile);
        println("Output file: " + outFile);

        // Read addresses
        List<Long> addresses = readAddresses(addrFile);
        println("Loaded " + addresses.size() + " addresses");

        // Set up decompiler
        DecompInterface decomp = new DecompInterface();
        DecompileOptions opts = new DecompileOptions();
        decomp.setOptions(opts);
        decomp.openProgram(currentProgram);

        long startTime = System.currentTimeMillis();
        int success = 0, failed = 0, skipped = 0;

        try (PrintWriter out = new PrintWriter(new FileWriter(outFile))) {
            out.println("// ============================================================");
            out.println("// Black & White Batch Decompilation Output");
            out.println("// Binary: " + currentProgram.getName());
            out.println("// Addresses: " + addresses.size());
            out.println("// Date: " + new Date());
            out.println("// ============================================================");
            out.println();

            for (int i = 0; i < addresses.size(); i++) {
                long addrLong = addresses.get(i);
                String addrHex = String.format("0x%08x", addrLong);

                Address addr = currentProgram.getAddressFactory()
                    .getDefaultAddressSpace().getAddress(addrLong);

                // Try exact match first, then containing function
                Function func = currentProgram.getFunctionManager().getFunctionAt(addr);
                if (func == null) {
                    func = getFunctionContaining(addr);
                }
                // If still no function, try creating one at this address
                if (func == null) {
                    try {
                        ghidra.app.cmd.function.CreateFunctionCmd cmd =
                            new ghidra.app.cmd.function.CreateFunctionCmd(addr);
                        cmd.applyTo(currentProgram, monitor);
                        func = currentProgram.getFunctionManager().getFunctionAt(addr);
                    } catch (Exception e2) {
                        // Ignore creation failure
                    }
                }
                if (func == null) {
                    println("[" + (i+1) + "/" + addresses.size() + "] SKIP: " + addrHex + " — no function");
                    out.println("// SKIP: " + addrHex + " — no function at this address");
                    out.println();
                    skipped++;
                    continue;
                }

                String funcName = func.getName();
                long funcSize = func.getBody().getNumAddresses();
                String entryHex = func.getEntryPoint().toString();
                boolean exactMatch = func.getEntryPoint().equals(addr);

                try {
                    DecompileResults results = decomp.decompileFunction(func, 60, monitor);

                    if (results.decompileCompleted()) {
                        String cCode = results.getDecompiledFunction().getC();

                        out.println("// ========================================");
                        out.println("// [" + (i+1) + "] " + funcName);
                        out.println("// Requested: " + addrHex);
                        if (!exactMatch) {
                            out.println("// Entry point: " + entryHex + " (containing function)");
                        }
                        out.println("// Size: " + funcSize + " bytes");
                        out.println("// ========================================");
                        out.println();
                        out.println(cCode);
                        out.println();

                        success++;
                        println("[" + (i+1) + "/" + addresses.size() + "] OK: " + funcName +
                                " @ " + addrHex + " (" + funcSize + " bytes)");
                    } else {
                        String errMsg = results.getErrorMessage();
                        if (errMsg == null) errMsg = "unknown error";
                        out.println("// FAILED: " + funcName + " @ " + addrHex + " — " + errMsg);
                        out.println();
                        failed++;
                        println("[" + (i+1) + "/" + addresses.size() + "] FAILED: " + funcName);
                    }
                } catch (Exception e) {
                    out.println("// ERROR: " + funcName + " @ " + addrHex + " — " + e.getMessage());
                    out.println();
                    failed++;
                    println("[" + (i+1) + "/" + addresses.size() + "] ERROR: " + funcName + " — " + e.getMessage());
                }
            }

            long elapsed = System.currentTimeMillis() - startTime;
            double rate = success * 1000.0 / Math.max(elapsed, 1);

            out.println("// ============================================================");
            out.println("// SUMMARY");
            out.println("// Total: " + addresses.size() +
                        " | Success: " + success +
                        " | Failed: " + failed +
                        " | Skipped: " + skipped);
            out.println("// Time: " + (elapsed / 1000) + " seconds (" +
                        String.format("%.2f", rate) + " func/sec)");
            out.println("// ============================================================");
        } finally {
            decomp.closeProgram();
        }

        long elapsed = System.currentTimeMillis() - startTime;
        println("\n=== Complete ===");
        println("Success: " + success + " / " + addresses.size());
        println("Failed: " + failed + ", Skipped: " + skipped);
        println("Time: " + (elapsed / 1000) + " seconds");
        println("Output: " + outFile);
    }

    private List<Long> readAddresses(String filepath) throws IOException {
        List<Long> addresses = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(filepath))) {
            String line;
            while ((line = reader.readLine()) != null) {
                line = line.trim();
                if (line.isEmpty() || line.startsWith("//") || line.startsWith("#")) continue;

                // Strip inline comments
                int commentIdx = line.indexOf("//");
                if (commentIdx > 0) line = line.substring(0, commentIdx).trim();
                commentIdx = line.indexOf("#");
                if (commentIdx > 0) line = line.substring(0, commentIdx).trim();

                try {
                    String hexStr = line.startsWith("0x") || line.startsWith("0X") ?
                        line.substring(2) : line;
                    addresses.add(Long.parseLong(hexStr, 16));
                } catch (NumberFormatException e) {
                    // Skip invalid lines
                }
            }
        }
        return addresses;
    }
}
