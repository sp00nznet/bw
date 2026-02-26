// Seagull class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)

#include <black/Seagull.h>

char* Seagull::GetDebugText() {
    // Original at 0x0041ee50
    static char text[] = "Seagull";
    return text;
}

uint32_t Seagull::GetSaveType() {
    // Original at 0x0041ee40
    return 0;
}

uint32_t Seagull::StandAnimation() {
    // Original at 0x0041bff0 — complex
    return 0;
}
