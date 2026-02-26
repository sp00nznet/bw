// PlannedWorshipSite class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)

#include <black/PlannedWorshipSite.h>

char* PlannedWorshipSite::GetDebugText() {
    // Original at 0x0077bf00
    static char text[] = "PlannedWorshipSite";
    return text;
}

uint32_t PlannedWorshipSite::Load(GameOSFile* /*file*/) {
    // Original at 0x0077bf90 — complex serialization
    return 0;
}

uint32_t PlannedWorshipSite::Save(GameOSFile* /*file*/) {
    // Original at 0x0077bf30 — complex serialization
    return 0;
}

uint32_t PlannedWorshipSite::GetSaveType() {
    // Original at 0x0077bef0
    return 0;
}
