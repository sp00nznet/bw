#!/bin/bash
# Extracts all "Original at 0x00XXXXXX" addresses from stub methods in src/core/
# and produces a prioritized address list for Ghidra batch decompilation.
#
# Usage: bash gen_address_list.sh > function_addresses.txt

CORE_DIR="$(dirname "$0")/../src/core"

echo "// Black & White function addresses for Ghidra batch decompilation"
echo "// Generated from src/core/ stub comments"
echo "// Format: ADDRESS  METHOD_NAME  FILE"
echo "//"

# Extract addresses from methods that are stubs (have "Original at" and return trivially)
grep -rn "// Original at 0x" "$CORE_DIR" --include="*.cpp" | \
    sed 's/.*Original at //' | \
    sed 's/ .*//' | \
    sort -u
