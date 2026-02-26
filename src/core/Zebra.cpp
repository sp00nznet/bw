// Zebra class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)

#include <black/Zebra.h>

char* Zebra::GetDebugText() {
    // Original at 0x0041d910
    static char text[] = "Zebra";
    return text;
}

uint32_t Zebra::GetSaveType() {
    // Original at 0x0041d900
    return 0;
}

uint32_t Zebra::StandAnimation() {
    // Original at 0x0041cc30 — complex
    return 0;
}
