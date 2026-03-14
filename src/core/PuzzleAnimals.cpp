// Puzzle animal implementations
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
//
// Simple GetSaveType overrides for chess puzzle animal variants.

#include <black/PuzzlePieces.h>

uint32_t PuzzleCow::GetSaveType() { return 0x9e; }
uint32_t PuzzleCow::StandAnimation() { return 0x2a; }

uint32_t PuzzleHorse::GetSaveType() { return 0x9f; }

uint32_t PuzzleLion::GetSaveType() { return 0x2e; }

uint32_t PuzzlePig::GetSaveType() { return 0xa0; }

uint32_t PuzzleSheep::GetSaveType() { return 0x2d; }
