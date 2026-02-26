// Pigeon class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)

#include <black/Pigeon.h>

char* Pigeon::GetDebugText() {
    // Original at 0x0041ed90
    static char text[] = "Pigeon";
    return text;
}

uint32_t Pigeon::GetSaveType() {
    // Original at 0x0041ed80
    return 0;
}

uint32_t Pigeon::StandAnimation() {
    // Original at 0x0041bf80 — complex
    return 0;
}
