// Tortoise class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)

#include <black/Tortoise.h>

char* Tortoise::GetDebugText() {
    // Original at 0x0041db50
    static char text[] = "Tortoise";
    return text;
}

uint32_t Tortoise::GetSaveType() {
    // Original at 0x0041db40
    return 0;
}

uint32_t Tortoise::StandAnimation() {
    // Original at 0x0041ce80 — complex
    return 0;
}
