// Sheep class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)

#include <black/Sheep.h>

char* Sheep::GetDebugText() {
    // Original at 0x0041d540
    static char text[] = "Sheep";
    return text;
}

uint32_t Sheep::GetSaveType() {
    // Original at 0x0041d530
    return 0;
}

uint32_t Sheep::StandAnimation() {
    // Original at 0x0041c8e0 — complex
    return 0;
}
