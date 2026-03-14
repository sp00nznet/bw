// PieceVillager class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)

#include <black/PuzzlePieces.h>

uint32_t PieceVillager::GetSaveType() {
    // Original at Ghidra: returns 0x9d
    return 0x9d;
}

uint32_t PieceVillager::StandAnimation() {
    // Original at Ghidra: returns 0x181
    return 0x181;
}
