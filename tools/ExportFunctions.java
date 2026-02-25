// Ghidra headless script to export all functions to CSV
// @category Analysis

import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.address.*;
import java.io.*;
import java.util.*;

public class ExportFunctions extends GhidraScript {
    @Override
    public void run() throws Exception {
        FunctionManager fm = currentProgram.getFunctionManager();
        SymbolTable st = currentProgram.getSymbolTable();
        Listing listing = currentProgram.getListing();

        int funcCount = fm.getFunctionCount();
        println("=== Black & White Analysis Stats ===");
        println("Program: " + currentProgram.getName());
        println("Image base: " + currentProgram.getImageBase());
        println("Total functions found: " + funcCount);

        int named = 0, unnamed = 0, thunks = 0, ext = 0;
        FunctionIterator iter = fm.getFunctions(true);
        while (iter.hasNext()) {
            Function f = iter.next();
            if (f.isThunk()) thunks++;
            else if (f.isExternal()) ext++;
            else if (f.getName().startsWith("FUN_")) unnamed++;
            else named++;
        }
        println("Named functions: " + named);
        println("Unnamed functions (FUN_): " + unnamed);
        println("Thunk functions: " + thunks);
        println("External/import functions: " + ext);

        // Count defined strings
        DataIterator diter = listing.getDefinedData(true);
        int strings = 0;
        while (diter.hasNext()) {
            Data d = diter.next();
            String dtName = d.getDataType().getName();
            if (dtName.contains("string") || dtName.contains("String")) {
                strings++;
            }
        }
        println("Defined strings: " + strings);

        // Count classes from RTTI
        SymbolIterator si = st.getSymbolIterator();
        HashSet<String> classNames = new HashSet<String>();
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

        // Export functions to CSV
        String csvPath = "D:/recomp/pc/bw/work/functions.csv";
        PrintWriter pw = new PrintWriter(new FileWriter(csvPath));
        pw.println("address,name,size,is_thunk,calling_convention,param_count,namespace");
        iter = fm.getFunctions(true);
        while (iter.hasNext()) {
            Function f = iter.next();
            String entry = f.getEntryPoint().toString();
            String name = esc(f.getName());
            long size = f.getBody().getNumAddresses();
            boolean isThunk = f.isThunk();
            String cc = f.getCallingConventionName();
            int pc = f.getParameterCount();
            String ns = f.getParentNamespace().getName();
            if (ns.equals("Global")) ns = "";
            pw.println("0x" + entry + "," + name + "," + size + "," + isThunk + "," + (cc != null ? cc : "") + "," + pc + "," + esc(ns));
        }
        pw.close();
        println("Exported functions to: " + csvPath);

        // Key address analysis
        println("\n=== Key Address Analysis ===");
        Address oepAddr = currentProgram.getImageBase().add(0x337B8E);
        Function oepFunc = fm.getFunctionAt(oepAddr);
        if (oepFunc != null) {
            println("Function at OEP (0x337B8E): " + oepFunc.getName());
        } else {
            println("No function at OEP. Checking containing...");
            Function c = fm.getFunctionContaining(oepAddr);
            if (c != null) {
                println("Containing function: " + c.getName() + " at " + c.getEntryPoint());
            }
        }
        println("=== Done ===");
    }

    private String esc(String s) {
        if (s == null) return "";
        if (s.contains(",") || s.contains("\"") || s.contains("\n")) {
            return "\"" + s.replace("\"", "\"\"") + "\"";
        }
        return s;
    }
}
