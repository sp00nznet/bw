// Poo class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Simple methods at 0x0055d0xx are packed 16 bytes apart.

#include <black/Poo.h>

char* Poo::GetDebugText() {
    static char text[] = "Poo";
    return text;
}

uint32_t Poo::GetSaveType() {
    // Original at 0x0055d0a0
    return 0;
}

uint32_t Poo::GetScriptObjectType() {
    // Original at 0x006083c0
    return 0;
}

void Poo::InsertMapObject() {
    // Original at 0x006079d0 — complex
}

HOLD_TYPE Poo::GetHoldType() {
    // Original at 0x006083d0
    return HOLD_TYPE_DEFAULT;
}

uint32_t Poo::GetPhysicsConstantsType() {
    // Original at 0x006079c0
    return 0;
}
