// Leopard class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)

#include <black/Leopard.h>

char* Leopard::GetDebugText() {
    // Original at 0x0041fc90
    static char text[] = "Leopard";
    return text;
}

uint32_t Leopard::GetSaveType() {
    // Original at 0x0041fc80
    return 0;
}

uint32_t Leopard::StandAnimation() {
    // Original at 0x0041c2e0 — complex
    return 0;
}
