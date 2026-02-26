// Crow class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)

#include <black/Crow.h>

char* Crow::GetDebugText() {
    // Original at 0x0041ec10
    static char text[] = "Crow";
    return text;
}

uint32_t Crow::GetSaveType() {
    // Original at 0x0041ec00
    return 0;
}

uint32_t Crow::StandAnimation() {
    // Original at 0x0041bf10 — complex
    return 0;
}
