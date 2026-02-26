// Vulture class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)

#include <black/Vulture.h>

char* Vulture::GetDebugText() {
    // Original at 0x0041f0c0
    static char text[] = "Vulture";
    return text;
}

uint32_t Vulture::GetSaveType() {
    // Original at 0x0041f0b0
    return 0;
}

bool32_t Vulture::CanBeFrighteningToCreature(Creature* /*creature*/) {
    // Original at 0x0041f0d0: returns 1
    return 1;
}
