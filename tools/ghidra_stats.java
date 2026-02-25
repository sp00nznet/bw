// Ghidra headless script to extract analysis stats
// @category Analysis

import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;

public class ghidra_stats extends GhidraScript {
    @Override
    public void run() throws Exception {
        FunctionManager fm = currentProgram.getFunctionManager();
        SymbolTable st = currentProgram.getSymbolTable();

        int funcCount = fm.getFunctionCount();
        println("=== Black & White Analysis Stats ===");
        println("Total functions found: " + funcCount);

        // Count named vs unnamed functions
        int named = 0;
        int unnamed = 0;
        int thunks = 0;
        int imports = 0;
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
        DataIterator diter = currentProgram.getListing().getDefinedData(true);
        int strings = 0;
        while (diter.hasNext()) {
            Data d = diter.next();
            if (d.getDataType().getName().contains("string") || d.getDataType().getName().contains("String")) {
                strings++;
            }
        }
        println("Defined strings: " + strings);

        // Count classes from symbol table
        int classes = 0;
        SymbolIterator si = st.getSymbolIterator();
        java.util.HashSet<String> classNames = new java.util.HashSet<>();
        while (si.hasNext()) {
            Symbol s = si.next();
            Namespace ns = s.getParentNamespace();
            if (ns != null && !ns.isGlobal() && ns.getSymbol().getSymbolType() == SymbolType.CLASS) {
                classNames.add(ns.getName());
            }
        }
        println("C++ classes identified: " + classNames.size());

        // Print first 30 class names
        int count = 0;
        for (String name : classNames) {
            if (count >= 30) {
                println("  ... and " + (classNames.size() - 30) + " more");
                break;
            }
            println("  " + name);
            count++;
        }

        println("=== End Stats ===");
    }
}
