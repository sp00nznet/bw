// Label all discovered vtables, RTTI structures, and find key globals
// Run AFTER VtableMatcher.java has been run (uses its output)
//
// @category Analysis

import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.address.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.data.*;
import java.io.*;
import java.util.*;

public class LabelVtablesAndGlobals extends GhidraScript {

    @Override
    public void run() throws Exception {
        Memory mem = currentProgram.getMemory();
        AddressSpace space = currentProgram.getAddressFactory().getDefaultAddressSpace();
        SymbolTable st = currentProgram.getSymbolTable();
        FunctionManager fm = currentProgram.getFunctionManager();

        int labelsCreated = 0;

        // === Part 1: Find RTTI and label type descriptors ===
        println("=== Part 1: Labeling RTTI Type Descriptors ===");
        byte[] avPattern = {0x2E, 0x3F, 0x41, 0x56}; // ".?AV"
        Map<String, Address> classToTD = new LinkedHashMap<>();

        Address searchAddr = space.getMinAddress();
        Address maxAddr = space.getMaxAddress();

        while (searchAddr != null && searchAddr.compareTo(maxAddr) < 0) {
            Address found = mem.findBytes(searchAddr, maxAddr, avPattern, null, true, monitor);
            if (found == null) break;

            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < 256; i++) {
                byte b = mem.getByte(found.add(i));
                if (b == 0) break;
                sb.append((char)(b & 0xFF));
            }
            String fullName = sb.toString();

            if (fullName.startsWith(".?AV") && fullName.endsWith("@@")) {
                String className = fullName.substring(4, fullName.length() - 2);
                Address tdAddr = found.subtract(8);
                classToTD.put(className, tdAddr);

                // Label the type descriptor
                try {
                    st.createLabel(tdAddr, "RTTI_TD_" + sanitize(className), SourceType.IMPORTED);
                    labelsCreated++;
                } catch (Exception e) { /* ignore duplicates */ }
            }
            searchAddr = found.add(1);
        }
        println("Labeled " + classToTD.size() + " type descriptors");

        // === Part 2: Build pointer index and find COLs + vtables ===
        println("\n=== Part 2: Finding and labeling COLs + vtables ===");

        List<MemoryBlock> scanBlocks = new ArrayList<>();
        for (MemoryBlock block : mem.getBlocks()) {
            String name = block.getName();
            if (name.equals(".rdata") || name.equals(".data")) {
                scanBlocks.add(block);
            }
        }

        Map<Long, List<Address>> ptrIndex = new HashMap<>();
        for (MemoryBlock block : scanBlocks) {
            Address start = block.getStart();
            long size = block.getSize();
            for (long offset = 0; offset < size - 3; offset += 4) {
                if (offset % 0x100000 == 0) monitor.checkCancelled();
                Address loc = start.add(offset);
                try {
                    int val = mem.getInt(loc);
                    long key = val & 0xFFFFFFFFL;
                    ptrIndex.computeIfAbsent(key, k -> new ArrayList<>()).add(loc);
                } catch (Exception e) { /* skip */ }
            }
        }

        // Find COLs
        Map<String, List<Address>> classToCOLs = new LinkedHashMap<>();
        for (Map.Entry<String, Address> entry : classToTD.entrySet()) {
            String className = entry.getKey();
            long tdVal = entry.getValue().getOffset();
            List<Address> refs = ptrIndex.get(tdVal);
            if (refs == null) continue;

            for (Address ref : refs) {
                Address colAddr = ref.subtract(0x0C);
                try {
                    int sig = mem.getInt(colAddr);
                    if (sig != 0) continue;
                    int pTD = mem.getInt(colAddr.add(0x0C));
                    if ((pTD & 0xFFFFFFFFL) != tdVal) continue;

                    classToCOLs.computeIfAbsent(className, k -> new ArrayList<>()).add(colAddr);

                    // Label the COL
                    try {
                        st.createLabel(colAddr, "RTTI_COL_" + sanitize(className), SourceType.IMPORTED);
                        labelsCreated++;
                    } catch (Exception e) { /* ignore */ }
                } catch (Exception e) { /* ignore */ }
            }
        }

        // Find vtables from COLs
        Map<String, Address> classToVtable = new LinkedHashMap<>();
        Address textStart = null, textEnd = null;
        for (MemoryBlock block : mem.getBlocks()) {
            if (block.getName().equals(".text")) {
                textStart = block.getStart();
                textEnd = block.getEnd();
                break;
            }
        }

        for (Map.Entry<String, List<Address>> colEntry : classToCOLs.entrySet()) {
            String className = colEntry.getKey();
            for (Address colAddr : colEntry.getValue()) {
                long colVal = colAddr.getOffset();
                List<Address> vtableRefs = ptrIndex.get(colVal);
                if (vtableRefs == null) continue;

                for (Address vtableMinusOne : vtableRefs) {
                    Address vtableStart = vtableMinusOne.add(4);

                    // Validate: first entry should be a .text address
                    try {
                        int firstEntry = mem.getInt(vtableStart);
                        Address firstFunc = space.getAddress(firstEntry & 0xFFFFFFFFL);
                        if (textStart != null && firstFunc.compareTo(textStart) >= 0 && firstFunc.compareTo(textEnd) <= 0) {
                            classToVtable.put(className, vtableStart);

                            // Label the vtable
                            try {
                                st.createLabel(vtableStart, "vftable_" + sanitize(className), SourceType.IMPORTED);
                                labelsCreated++;
                            } catch (Exception e) { /* ignore */ }

                            // Also label vtable[-1] (COL pointer slot)
                            try {
                                st.createLabel(vtableMinusOne, "vftable_meta_" + sanitize(className), SourceType.IMPORTED);
                                labelsCreated++;
                            } catch (Exception e) { /* ignore */ }
                        }
                    } catch (Exception e) { /* skip */ }
                }
            }
        }
        println("Labeled " + classToVtable.size() + " vtables");

        // === Part 3: Find key globals ===
        println("\n=== Part 3: Hunting for key globals ===");

        // Strategy: scan .data section for pointers to known vtables
        // This finds instances of objects (globals) that use these vtables

        Address dataStart = null, dataEnd = null;
        for (MemoryBlock block : mem.getBlocks()) {
            if (block.getName().equals(".data")) {
                dataStart = block.getStart();
                dataEnd = block.getEnd();
                break;
            }
        }

        if (dataStart != null) {
            // Look for key game globals by scanning for vtable pointers in .data
            // GGame, GGlobal, etc. are large structures that start with a vtable pointer
            String[] keyClasses = {
                "GGame", "GGlobal", "GGameInfo", "FrontEnd",
                "GScript", "ScriptManage", "GCamera",
                "GPlayer", "PSysManager", "LH_AudioSystem",
                "GTerrainMap", "BWLan", "BWGameSpy"
            };

            for (String cls : keyClasses) {
                Address vtAddr = classToVtable.get(cls);
                if (vtAddr == null) continue;

                long vtVal = vtAddr.getOffset();
                List<Address> instances = ptrIndex.get(vtVal);
                if (instances == null) continue;

                // Filter: only instances in .data section
                for (Address inst : instances) {
                    if (inst.compareTo(dataStart) >= 0 && inst.compareTo(dataEnd) <= 0) {
                        println("  Found " + cls + " instance at 0x" + inst);
                        try {
                            st.createLabel(inst, "g_" + cls, SourceType.IMPORTED);
                            labelsCreated++;
                        } catch (Exception e) { /* ignore */ }
                    }
                }
            }

            // Also find the GGame** pointer: scan for references to GGame instances
            Address gGameAddr = classToVtable.get("GGame");
            // The game pointer is typically a pointer-to-pointer; we'll find it from cross-refs

            // Find command-line args globals by looking for known arg strings
            println("\n  Searching for arg-related globals...");
            String[] argStrings = {
                "-newgame", "-multiplayer", "-land", "-skirmish",
                "-editor", "-convert", "-version"
            };
            for (String arg : argStrings) {
                byte[] argBytes = arg.getBytes("US-ASCII");
                Address found = mem.findBytes(space.getMinAddress(), maxAddr, argBytes, null, true, monitor);
                if (found != null) {
                    println("  String '" + arg + "' at 0x" + found);
                }
            }
        }

        // === Part 4: Find GInfo array globals by looking for consecutive vtable pointers ===
        println("\n=== Part 4: Finding GInfo arrays ===");

        String[] infoClasses = {
            "GBaseInfo", "GAlignmentInfo", "GAnimalInfo", "GAnimalStateTableInfo",
            "GMobileInfo", "GMobileWallHugInfo", "GLivingInfo",
            "GAbodeInfo", "GObjectInfo"
        };

        for (String cls : infoClasses) {
            Address vtAddr = classToVtable.get(cls);
            if (vtAddr == null) continue;

            long vtVal = vtAddr.getOffset();
            List<Address> instances = ptrIndex.get(vtVal);
            if (instances == null) continue;

            // Find instances in .data section
            List<Address> dataInstances = new ArrayList<>();
            for (Address inst : instances) {
                if (dataStart != null && inst.compareTo(dataStart) >= 0 && inst.compareTo(dataEnd) <= 0) {
                    dataInstances.add(inst);
                }
            }

            if (!dataInstances.isEmpty()) {
                Collections.sort(dataInstances);
                println("  " + cls + ": " + dataInstances.size() + " instances in .data");
                if (dataInstances.size() > 0) {
                    Address first = dataInstances.get(0);
                    println("    First at 0x" + first);
                    try {
                        st.createLabel(first, "g_" + cls + "_array", SourceType.IMPORTED);
                        labelsCreated++;
                    } catch (Exception e) { /* ignore */ }
                }
            }
        }

        // === Part 5: Find WinMain and entry-related functions ===
        println("\n=== Part 5: Key function identification ===");

        // Entry point should already be labeled
        // Look for functions that call many subsystem inits
        Address entryAddr = space.getAddress(0x00737B8E);
        Function entryFunc = fm.getFunctionAt(entryAddr);
        if (entryFunc != null) {
            println("  Entry point: " + entryFunc.getName() + " at 0x" + entryAddr);
        }

        // Find WinMain by looking for the function that calls GetModuleHandleA and GetCommandLineA
        // In MSVC6 CRT startup, WinMain is called near the end of WinMainCRTStartup
        byte[] winMainStr = "WinMain".getBytes("US-ASCII");
        Address wmFound = mem.findBytes(space.getMinAddress(), maxAddr, winMainStr, null, true, monitor);
        if (wmFound != null) {
            println("  'WinMain' string at 0x" + wmFound);
        }

        // Look for "Black & White" window class name string - this is near the WinMain-equivalent
        byte[] bwStr = "Black & White".getBytes("US-ASCII");
        Address bwFound = mem.findBytes(space.getMinAddress(), maxAddr, bwStr, null, true, monitor);
        if (bwFound != null) {
            println("  'Black & White' string at 0x" + bwFound);
        }

        println("\n=== Summary ===");
        println("Total labels created: " + labelsCreated);
        println("  Type descriptors: " + classToTD.size());
        println("  COLs: " + classToCOLs.size());
        println("  Vtables: " + classToVtable.size());
    }

    private String sanitize(String name) {
        // Make name safe for Ghidra labels
        return name.replaceAll("[^A-Za-z0-9_]", "_");
    }
}
