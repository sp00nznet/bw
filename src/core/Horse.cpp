// Horse class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)

#include <black/Horse.h>

char* Horse::GetDebugText() {
    // Original at 0x0041d780
    static char text[] = "Horse";
    return text;
}

uint32_t Horse::GetSaveType() {
    // Original at 0x0041d770
    return 0;
}

uint32_t Horse::StandAnimation() {
    // Original at 0x0041cb40 — complex
    return 0;
}
