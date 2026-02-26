// Goat class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)

#include <black/Goat.h>

char* Goat::GetDebugText() {
    // Original at 0x0041d6d0
    static char text[] = "Goat";
    return text;
}

uint32_t Goat::GetSaveType() {
    // Original at 0x0041d6c0
    return 0;
}

uint32_t Goat::StandAnimation() {
    // Original at 0x0041c9d0 — complex
    return 0;
}
