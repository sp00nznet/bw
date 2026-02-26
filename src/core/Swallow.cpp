// Swallow class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)

#include <black/Swallow.h>

char* Swallow::GetDebugText() {
    // Original at 0x0041ecd0
    static char text[] = "Swallow";
    return text;
}

uint32_t Swallow::GetSaveType() {
    // Original at 0x0041ecc0
    return 0;
}

uint32_t Swallow::StandAnimation() {
    // Original at 0x0041c070 — complex
    return 0;
}
