// Ghidra headless script to export all functions to CSV
// @category Analysis

import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import java.io.*;
import java.util.*;

public class export_functions extends GhidraScript {
    @Override
    public void run() throws Exception {
        FunctionManager fm = currentProgram.getFunctionManager();
        SymbolTable st = currentProgram.getSymbolTable();
        Listing listing = currentProgram.getListing();

        // === STATS ===
        int funcCount = fm.getFunctionCount();
        println("=== Black & White Analysis Stats ===");
        println("Program: " + currentProgram.getName());
        println("Image base: " + currentProgram.getImageBase());
        println("Total functions found: " + funcCount);

        int named = 0, unnamed = 0, thunks = 0, imports = 0;
        FunctionIterator iter = fm.getFunctions(true);
        while (iter.hasNext()) {
            Function f = iter.next();
            if (f.isThunk()) thunks++;
            else if (f.isExternal()) imports++;
            else if (f.getName().startsWith("FUN_")) unnamed++;
            else named++;
        }
        println("Named functions: " + named);
        println("Unnamed functions (FUN_): " + unnamed);
        println("Thunk functions: " + thunks);
        println("External/import functions: " + imports);

        // Count strings
        DataIterator diter = listing.getDefinedData(true);
        int strings = 0;
        while (diter.hasNext()) {
            Data d = diter.next();
            String dtName = d.getDataType().getName();
            if (dtName.contains("string") || dtName.contains("String") || dtName.equals("char[]")) {
                strings++;
            }
        }
        println("Defined strings: " + strings);

        // Count classes
        SymbolIterator si = st.getSymbolIterator();
        HashSet<String> classNames = new HashSet<>();
        while (si.hasNext()) {
            Symbol s = si.next();
            Namespace ns = s.getParentNamespace();
            if (ns != null && !ns.isGlobal() && ns.getSymbol().getSymbolType() == SymbolType.CLASS) {
                classNames.add(ns.getName());
            }
        }
        println("C++ classes identified: " + classNames.size());
        for (String name : classNames) {
            println("  CLASS: " + name);
        }

        // === EXPORT FUNCTIONS TO CSV ===
        String outputDir = System.getProperty("user.dir");
        // Use a fixed output path
        String csvPath = getScriptArgs().length > 0 ? getScriptArgs()[0] : "D:/recomp/pc/bw/work/functions.csv";
        PrintWriter pw = new PrintWriter(new FileWriter(csvPath));
        pw.println("address,name,size,is_thunk,calling_convention,param_count,namespace");

        iter = fm.getFunctions(true);
        while (iter.hasNext()) {
            Function f = iter.next();
            Address entry = f.getEntryPoint();
            String name = f.getName();
            long size = f.getBody().getNumAddresses();
            boolean isThunk = f.isThunk();
            String cc = f.getCallingConventionName();
            int paramCount = f.getParameterCount();
            String ns = f.getParentNamespace().getName();
            if (ns.equals("Global")) ns = "";

            pw.println(String.format("0x%s,%s,%d,%b,%s,%d,%s",
                entry.toString(), csvEscape(name), size, isThunk,
                cc != null ? cc : "unknown", paramCount, csvEscape(ns)));
        }
        pw.close();
        println("Functions exported to: " + csvPath);

        // === EXPORT STRINGS TO CSV ===
        String strPath = "D:/recomp/pc/bw/work/strings.csv";
        PrintWriter spw = new PrintWriter(new FileWriter(strPath));
        spw.println("address,type,value");

        diter = listing.getDefinedData(true);
        int strCount = 0;
        while (diter.hasNext()) {
            Data d = diter.next();
            String dtName = d.getDataType().getName();
            if (dtName.contains("string") || dtName.contains("String") || dtName.equals("char[]")) {
                Object val = d.getValue();
                String strVal = val != null ? val.toString() : "";
                spw.println(String.format("0x%s,%s,%s",
                    d.getAddress().toString(), dtName, csvEscape(strVal)));
                strCount++;
            }
        }
        spw.close();
        println("Strings exported to: " + strPath + " (" + strCount + " strings)");

        // === KEY ADDRESSES ===
        println("\n=== Key Address Analysis ===");
        // Check for WinMain at OEP
        Function oepFunc = fm.getFunctionAt(currentProgram.getImageBase().add(0x337B8E));
        if (oepFunc != null) {
            println("Function at OEP (0x337B8E): " + oepFunc.getName());
            println("  Signature: " + oepFunc.getPrototypeString(false, false));
        } else {
            println("WARNING: No function found at OEP 0x337B8E");
            // Try to find it by looking nearby
            Address oepAddr = currentProgram.getImageBase().add(0x337B8E);
            Function containing = fm.getFunctionContaining(oepAddr);
            if (containing != null) {
                println("  Containing function: " + containing.getName() + " at " + containing.getEntryPoint());
            }
        }

        // Look for known function names
        String[] knownNames = {"WinMain", "main", "_main", "WinMainCRTStartup",
            "_WinMainCRTStartup", "CreateWindow", "RegisterClass",
            "Direct3DCreate", "DirectDrawCreate"};
        for (String kn : knownNames) {
            SymbolIterator found = st.getSymbols(kn);
            while (found.hasNext()) {
                Symbol sym = found.next();
                println("Found symbol '" + kn + "' at " + sym.getAddress() + " (type: " + sym.getSymbolType() + ")");
            }
        }

        println("=== Analysis Complete ===");
    }

    private String csvEscape(String s) {
        if (s == null) return "";
        if (s.contains(",") || s.contains("\"") || s.contains("\n")) {
            return "\"" + s.replace("\"", "\"\"") + "\"";
        }
        return s;
    }
}
