// PuzzleGame class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)

#include <black/PuzzleGame.h>

uint32_t PuzzleGame::GetSaveType() {
    // Original at Ghidra: returns 0x2c
    return 0x2c;
}

const char* PuzzleGame::GetText() {
    // Original at Ghidra: returns "PuzzleGame"
    return "PuzzleGame";
}
