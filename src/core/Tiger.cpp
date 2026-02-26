// Tiger class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)

#include <black/Tiger.h>

char* Tiger::GetDebugText() {
    // Original at 0x00421430
    static char text[] = "Tiger";
    return text;
}

uint32_t Tiger::GetSaveType() {
    // Original at 0x00421420
    return 0;
}

uint32_t Tiger::StandAnimation() {
    // Original at 0x0041c430 — complex
    return 0;
}
