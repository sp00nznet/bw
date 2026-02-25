// Find RTTI Type Descriptors and vtables to enable version cross-referencing
// @category Analysis

import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.address.*;
import java.io.*;
import java.util.*;

public class FindRTTI extends GhidraScript {
    @Override
    public void run() throws Exception {
        Memory mem = currentProgram.getMemory();
        AddressSpace space = currentProgram.getAddressFactory().getDefaultAddressSpace();

        // Search for MSVC RTTI type descriptor strings ".?AV" pattern
        // These appear as: vtable_ptr(4 bytes) + spare(4 bytes) + ".?AVClassName@@\0"
        byte[] pattern = {0x2E, 0x3F, 0x41, 0x56}; // ".?AV"

        println("=== RTTI Type Descriptor Search ===");
        println("Searching for .?AV pattern...");

        String csvPath = "D:/recomp/pc/bw/work/rtti_classes.csv";
        PrintWriter pw = new PrintWriter(new FileWriter(csvPath));
        pw.println("descriptor_addr,class_name");

        int count = 0;
        Address searchAddr = space.getMinAddress();
        Address maxAddr = space.getMaxAddress();

        while (searchAddr != null && searchAddr.compareTo(maxAddr) < 0) {
            Address found = mem.findBytes(searchAddr, maxAddr, pattern, null, true, monitor);
            if (found == null) break;

            // Read the class name string
            StringBuilder sb = new StringBuilder();
            Address strAddr = found;
            int maxLen = 256;
            for (int i = 0; i < maxLen; i++) {
                byte b = mem.getByte(strAddr.add(i));
                if (b == 0) break;
                sb.append((char)(b & 0xFF));
            }
            String className = sb.toString();

            // The type descriptor starts 8 bytes before the string
            Address descAddr = found.subtract(8);

            if (className.startsWith(".?AV") && className.endsWith("@@")) {
                String cleanName = className.substring(4, className.length() - 2);
                pw.println("0x" + descAddr.toString() + "," + cleanName);
                count++;
                if (count <= 50) {
                    println("  0x" + descAddr + " -> " + cleanName);
                }
            }

            searchAddr = found.add(1);
        }

        pw.close();
        println("Total RTTI type descriptors found: " + count);
        println("Exported to: " + csvPath);

        // Also find key strings for version cross-referencing
        println("\n=== Key String Search for Version Cross-Reference ===");
        String[] keyStrings = {
            "Black & White",
            "Black.exe",
            "runblack",
            "LHRegistrySetCurrentKey",
            "pc_main",
            "ARGS_NEWGAME",
            "ARGS_MULTIPLAYER",
            "GameThing",
            "Creature",
            "WinMain"
        };

        for (String key : keyStrings) {
            byte[] keyBytes = key.getBytes("US-ASCII");
            Address found = mem.findBytes(space.getMinAddress(), maxAddr, keyBytes, null, true, monitor);
            if (found != null) {
                println("  String '" + key + "' found at 0x" + found);
            } else {
                println("  String '" + key + "' NOT FOUND");
            }
        }

        println("=== Done ===");
    }
}
