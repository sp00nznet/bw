// GameThing class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// GameThing is the base entity class. Most virtual methods return default/null
// values here and are overridden by derived classes (Object, Creature, Town, etc.)

#include <black/GameThing.h>

// ============================================================================
// Virtual method implementations (from vtable at 0x0083dda4 in v1.0)
// ============================================================================

GPlayer* GameThing::GetPlayer() {
    // Default: no player
    return nullptr;
}

void GameThing::SetPlayer(GPlayer* /*player*/) {
    // Default: no-op (0x004033c0 - empty function)
}

float GameThing::CalculateInfluence(const MapCoords& /*coords*/) {
    // Default influence is 1.0
    return 1.0f;
}

void GameThing::RemoveDance() {
    // Default: no-op
}

bool GameThing::IsAvailable() {
    // Checks bit 0 of field_0xa, inverted
    // Decompiled: return ~*(byte*)(this + 0xa) & 1
    return (~field_0xa) & 1;
}

bool GameThing::IsCreature(Creature* /*creature*/) {
    return false;
}

bool GameThing::IsCreature() {
    return false;
}

bool GameThing::IsCreatureNotTooNear(Creature* /*creature*/) {
    return false;
}

float GameThing::GetDrawImportance() {
    return 0.0f;
}

float GameThing::GetMaxAlignmentChangePerGameTurn() {
    // 1/(60*60*10) = approx 2.7778e-05
    // Player alignment changes by at most this much per game turn
    return MAX_ALIGNMENT_CHANGE_PER_TURN;
}

bool GameThing::GetComputerSeen() {
    return false;
}

Town* GameThing::GetTown() {
    // Default: no town association
    // Decompiled at 0x00404e60 (overridden by Object)
    return nullptr;
}

float GameThing::GetVillagerActivityDesire(Villager* /*villager*/) {
    return 0.0f;
}

void GameThing::SetVillagerActivity(Villager* /*villager*/) {
    // Default: no-op
}

uint32_t GameThing::UpdateVillagerActivityEffect(Villager* /*villager*/) {
    return 0;
}

void GameThing::MaintainSpell(uint32_t /*param1*/, float /*param2*/) {
    // Default: no-op
}

void GameThing::UpdateSpellInfo(Spell* /*spell*/, PSysProcessInfo* /*info*/) {
    // Default: no-op
}

float GameThing::GetRadius() {
    return 0.0f;
}

float GameThing::Get2DRadius() {
    return 0.0f;
}

GPlayer* GameThing::GetPlayerWhoLastPickedMeUp() {
    return nullptr;
}

GPlayer* GameThing::GetPlayerWhoLastDroppedMe() {
    return nullptr;
}

bool GameThing::IsFootpathLink() {
    return false;
}

GFootpathLink* GameThing::GetFootpathLink() {
    return nullptr;
}

void GameThing::AddFootpathLink(GFootpath* /*footpath*/) {
    // Default: no-op
}

uint32_t GameThing::GetNearestPathTo(const MapCoords& /*coords*/, float /*param2*/, int /*param3*/) {
    return 0;
}

bool GameThing::IsDeletedOnNewMap() {
    return true;
}

uint16_t GameThing::GetNumberOfInstanceForGlobalList() {
    return 1;
}

float GameThing::GetTownArtifactValue() {
    return 0.0f;
}

bool GameThing::CanBecomeArtifact() {
    return false;
}

void GameThing::DrawInHand(GInterfaceStatus* /*status*/) {
    // Default: no-op
}

bool GameThing::IsFunctional() {
    // Calls IsAvailable through vtable
    // Decompiled: mov eax, [ecx]; jmp [eax+0x2c]
    // 0x2c / 4 = vtable slot 11 = IsAvailable
    return IsAvailable();
}
