// Match vtables in our v1.0 binary using RTTI, then name virtual functions
// from bw1-decomp's vtable layouts.
//
// Prerequisites: Run tools/parse_vtables.js first to generate work/vtable_data.txt
//
// MSVC 32-bit RTTI layout:
//   TypeDescriptor:     [pVFTable(4)] [spare(4)] [".?AVClassName@@\0"]
//   CompleteObjectLocator: [sig(4)] [offset(4)] [cdOffset(4)] [pTypeDescriptor(4)] [pClassHierarchy(4)]
//   Vtable in memory:   [pCOL] [vfunc_0] [vfunc_1] ... (pCOL is at vtable[-1])
//
// @category Analysis

import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.address.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.util.*;

public class VtableMatcher extends GhidraScript {

    // Parsed vtable data: className -> list of mangled function names
    private Map<String, List<String>> vtableData = new LinkedHashMap<>();

    @Override
    public void run() throws Exception {
        Memory mem = currentProgram.getMemory();
        AddressSpace space = currentProgram.getAddressFactory().getDefaultAddressSpace();
        FunctionManager fm = currentProgram.getFunctionManager();

        // Load vtable data from text file
        String dataPath = "D:/recomp/pc/bw/work/vtable_data.txt";
        loadVtableData(dataPath);
        println("Loaded vtable data for " + vtableData.size() + " classes");

        // Step 1: Find all RTTI type descriptors by scanning for ".?AV" pattern
        println("\n=== Step 1: Finding RTTI Type Descriptors ===");
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
            }

            searchAddr = found.add(1);
        }
        println("Found " + classToTD.size() + " type descriptors");

        // Count how many match bw1-decomp
        int preMatchCount = 0;
        for (String cls : classToTD.keySet()) {
            if (vtableData.containsKey(cls)) preMatchCount++;
        }
        println("Of these, " + preMatchCount + " have bw1-decomp vtable data");

        // Step 2: Build pointer index over .rdata and .data sections
        println("\n=== Step 2: Building pointer index ===");

        // Collect all sections to scan
        List<MemoryBlock> scanBlocks = new ArrayList<>();
        for (MemoryBlock block : mem.getBlocks()) {
            String name = block.getName();
            if (name.equals(".rdata") || name.equals(".data")) {
                scanBlocks.add(block);
                println("  Will scan: " + name + " [" + block.getStart() + " - " + block.getEnd() + "]");
            }
        }

        // Build index: pointer_value -> list of locations
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
                } catch (Exception e) {
                    // Skip unreadable memory
                }
            }
        }
        println("Indexed " + ptrIndex.size() + " unique pointer values");

        // Step 3: Find COLs
        println("\n=== Step 3: Finding Complete Object Locators ===");
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
                } catch (Exception e) {
                    // ignore
                }
            }
        }

        int totalCOLs = 0;
        for (List<Address> cols : classToCOLs.values()) totalCOLs += cols.size();
        println("Found " + totalCOLs + " COLs for " + classToCOLs.size() + " classes");

        // Step 4: Find vtables and name functions
        println("\n=== Step 4: Finding vtables and naming functions ===");

        Address textStart = null;
        Address textEnd = null;
        for (MemoryBlock block : mem.getBlocks()) {
            if (block.getName().equals(".text")) {
                textStart = block.getStart();
                textEnd = block.getEnd();
                break;
            }
        }
        println("  .text section: " + textStart + " - " + textEnd);

        int matchedVtables = 0;
        int totalFuncsNamed = 0;
        int totalFuncsCreated = 0;
        int skippedAlreadyNamed = 0;
        int nameConflicts = 0;
        Set<Address> namedFunctions = new HashSet<>();
        Map<String, Address> classToVtable = new LinkedHashMap<>(); // Track vtable addresses

        String csvPath = "D:/recomp/pc/bw/work/vtable_matches.csv";
        PrintWriter csv = new PrintWriter(new FileWriter(csvPath));
        csv.println("class_name,vtable_addr,slot_index,func_addr,mangled_name,status");

        for (Map.Entry<String, List<Address>> colEntry : classToCOLs.entrySet()) {
            String className = colEntry.getKey();
            List<Address> cols = colEntry.getValue();
            List<String> expectedFuncs = vtableData.get(className);

            for (Address colAddr : cols) {
                long colVal = colAddr.getOffset();
                List<Address> vtableRefs = ptrIndex.get(colVal);
                if (vtableRefs == null) continue;

                for (Address vtableMinusOne : vtableRefs) {
                    Address vtableStart = vtableMinusOne.add(4);
                    classToVtable.put(className, vtableStart);

                    if (expectedFuncs == null) {
                        csv.println(className + ",0x" + vtableStart + ",,,no_decomp_data");
                        continue;
                    }

                    matchedVtables++;
                    if (matchedVtables <= 10) {
                        println("  Matched: " + className + " vtable at 0x" + vtableStart +
                                " (" + expectedFuncs.size() + " entries)");
                    }

                    for (int i = 0; i < expectedFuncs.size(); i++) {
                        Address slotAddr = vtableStart.add(i * 4);
                        try {
                            int funcPtr = mem.getInt(slotAddr);
                            Address funcAddr = space.getAddress(funcPtr & 0xFFFFFFFFL);

                            if (textStart != null &&
                                (funcAddr.compareTo(textStart) < 0 || funcAddr.compareTo(textEnd) > 0)) {
                                csv.println(className + ",0x" + vtableStart + "," + i +
                                           ",0x" + funcAddr + "," + expectedFuncs.get(i) + ",out_of_text");
                                break;
                            }

                            String mangledName = expectedFuncs.get(i);
                            Function func = fm.getFunctionAt(funcAddr);
                            if (func == null) {
                                func = createFunction(funcAddr, null);
                                if (func != null) totalFuncsCreated++;
                            }

                            if (func != null) {
                                String currentName = func.getName();
                                if (currentName.startsWith("FUN_") || currentName.startsWith("thunk_")) {
                                    try {
                                        func.setName(mangledName, SourceType.IMPORTED);
                                        totalFuncsNamed++;
                                        namedFunctions.add(funcAddr);
                                        csv.println(className + ",0x" + vtableStart + "," + i +
                                                   ",0x" + funcAddr + "," + mangledName + ",named");
                                    } catch (ghidra.util.exception.DuplicateNameException e) {
                                        // Another vtable already named this function
                                        skippedAlreadyNamed++;
                                        csv.println(className + ",0x" + vtableStart + "," + i +
                                                   ",0x" + funcAddr + "," + mangledName + ",duplicate");
                                    } catch (ghidra.util.exception.InvalidInputException e) {
                                        // Try a simplified name
                                        try {
                                            // Extract just the function name from mangled form
                                            String simpleName = className + "_vf" + i;
                                            func.setName(simpleName, SourceType.IMPORTED);
                                            totalFuncsNamed++;
                                            namedFunctions.add(funcAddr);
                                            csv.println(className + ",0x" + vtableStart + "," + i +
                                                       ",0x" + funcAddr + "," + mangledName + ",named_simple");
                                        } catch (Exception e2) {
                                            nameConflicts++;
                                            csv.println(className + ",0x" + vtableStart + "," + i +
                                                       ",0x" + funcAddr + "," + mangledName + ",name_conflict");
                                        }
                                    }
                                } else {
                                    skippedAlreadyNamed++;
                                    csv.println(className + ",0x" + vtableStart + "," + i +
                                               ",0x" + funcAddr + "," + mangledName + ",already_named=" + currentName);
                                }
                            } else {
                                csv.println(className + ",0x" + vtableStart + "," + i +
                                           ",0x" + funcAddr + "," + mangledName + ",no_function");
                            }
                        } catch (Exception e) {
                            break;
                        }
                    }
                }
            }
        }

        csv.close();

        println("\n=== Results ===");
        println("Classes with RTTI in binary:           " + classToTD.size());
        println("Classes with bw1-decomp vtable data:   " + vtableData.size());
        println("Vtables matched and processed:         " + matchedVtables);
        println("Functions named (total attempts):      " + totalFuncsNamed);
        println("Functions created (new):               " + totalFuncsCreated);
        println("Unique functions named:                " + namedFunctions.size());
        println("Skipped (already named/duplicate):     " + skippedAlreadyNamed);
        println("Name conflicts:                        " + nameConflicts);
        println("Vtable addresses found for classes:    " + classToVtable.size());
        println("\nDetailed CSV: " + csvPath);

        // Write match summary
        String summaryPath = "D:/recomp/pc/bw/work/vtable_match_summary.txt";
        PrintWriter summary = new PrintWriter(new FileWriter(summaryPath));

        summary.println("=== Vtable Addresses Found ===");
        for (Map.Entry<String, Address> e : classToVtable.entrySet()) {
            summary.println("  " + e.getKey() + " -> 0x" + e.getValue());
        }

        summary.println("\n=== Classes in binary WITH bw1-decomp vtable data ===");
        int matched = 0;
        for (String cls : classToTD.keySet()) {
            if (vtableData.containsKey(cls)) {
                matched++;
                summary.println("  " + cls + " (" + vtableData.get(cls).size() + " entries)");
            }
        }
        summary.println("\nMatched: " + matched + " / " + classToTD.size());

        summary.println("\n=== Classes in binary WITHOUT bw1-decomp data ===");
        for (String cls : classToTD.keySet()) {
            if (!vtableData.containsKey(cls)) {
                summary.println("  " + cls);
            }
        }

        summary.println("\n=== Classes in bw1-decomp NOT found in binary ===");
        for (String cls : vtableData.keySet()) {
            if (!classToTD.containsKey(cls)) {
                summary.println("  " + cls);
            }
        }
        summary.close();
        println("Match summary: " + summaryPath);
    }

    private void loadVtableData(String filePath) throws Exception {
        // Simple line-based format:
        //   VTABLE ClassName entryCount
        //   mangledName1
        //   mangledName2
        //   ...
        BufferedReader br = new BufferedReader(new FileReader(filePath));
        String line;
        String currentClass = null;
        int expectedCount = 0;
        List<String> currentEntries = null;

        while ((line = br.readLine()) != null) {
            line = line.trim();
            if (line.isEmpty()) continue;

            if (line.startsWith("VTABLE ")) {
                // Save previous class if any
                if (currentClass != null && currentEntries != null) {
                    vtableData.put(currentClass, currentEntries);
                }
                // Parse: VTABLE ClassName count
                String[] parts = line.split("\\s+");
                currentClass = parts[1];
                expectedCount = Integer.parseInt(parts[2]);
                currentEntries = new ArrayList<>(expectedCount);
            } else if (currentClass != null && currentEntries != null) {
                currentEntries.add(line);
            }
        }
        // Don't forget the last class
        if (currentClass != null && currentEntries != null) {
            vtableData.put(currentClass, currentEntries);
        }
        br.close();
    }
}
