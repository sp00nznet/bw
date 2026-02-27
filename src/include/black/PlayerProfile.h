#pragma once
#include <cstdint>

struct PlayerProfile {
    char16_t creature_name[0x100];     // 0x000
    char16_t current_profile[0x100];   // 0x200
    char16_t login_name[0x100];        // 0x400
    char16_t login_password[0x100];    // 0x600
    uint32_t stuff;                    // 0x800
    uint32_t player_symbol;            // 0x804
    uint32_t timestarted;              // 0x808
    uint32_t numberofsaves;            // 0x80C
    uint32_t numberofloads;            // 0x810
    uint32_t pitchaboutcentre;         // 0x814
    uint32_t pushscroll;               // 0x818
    uint32_t HAND_ORIENTATION;         // 0x81C
    uint32_t IMMERSION_KEY;            // 0x820
};
static_assert(sizeof(PlayerProfile) == 0x824, "PlayerProfile size mismatch");
