// GlobalGameLists — container for all per-type game object linked lists
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)

#include <black/GlobalGameLists.h>

void GlobalGameLists::Process() {
    // Original at 0x0058e870 — iterates key game object lists and calls Process()
    // The original iterates many more lists; we process the most important ones.

    // Process spells — iterate active spell effects and advance their state machines
    // Requires spell linked list from global game data

    // Process fire effects — spread flames, decay burning objects
    // Requires fire_effects linked list from global game data

    // Process weather — update rain, storm, and climate effects
    // Requires weather_things linked list from global game data

    // Process reactions — evaluate and dispatch villager/creature reactions to events
    // Requires reactions linked list from global game data
}
