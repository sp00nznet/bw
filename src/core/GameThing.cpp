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

void GameThing::UseFootpathIfNecessary(Living* /*living*/, const MapCoords* /*coords*/, uint8_t /*param3*/) {
    // Default: no-op
}

uint32_t GameThing::AddFootpath(GFootpath* /*footpath*/) {
    return 0;
}

uint32_t GameThing::RemoveFootpath(GFootpath* /*footpath*/) {
    return 0;
}

uint32_t GameThing::JustAddResource(RESOURCE_TYPE /*type*/, uint32_t /*amount*/, bool /*param3*/) {
    return 0;
}

uint32_t GameThing::JustRemoveResource(RESOURCE_TYPE /*type*/, uint32_t /*amount*/, bool* /*param3*/) {
    return 0;
}

uint32_t GameThing::JustGetResource(RESOURCE_TYPE /*type*/, uint32_t /*amount*/, bool* /*param3*/) {
    return 0;
}

uint32_t GameThing::GetResource(RESOURCE_TYPE /*type*/) {
    return 0;
}

uint32_t GameThing::AddResource(RESOURCE_TYPE /*type*/, uint32_t /*amount*/, GInterfaceStatus* /*status*/, bool /*param4*/, const MapCoords& /*coords*/, int /*param6*/) {
    return 0;
}

uint32_t GameThing::RemoveResource(RESOURCE_TYPE /*type*/, uint32_t /*amount*/, GInterfaceStatus* /*status*/, bool* /*param4*/) {
    return 0;
}

Creature* GameThing::CastCreature() {
    return nullptr;
}

GPlayer* GameThing::CastPlayer() {
    return nullptr;
}

SpellSeed* GameThing::CastOneOffSpellSeed() {
    return nullptr;
}

Abode* GameThing::CastAbode() {
    return nullptr;
}

MultiMapFixed* GameThing::CastMultiMapFixed() {
    return nullptr;
}

SpellIcon* GameThing::CastSpellIcon() {
    return nullptr;
}

Tree* GameThing::CastTree() {
    return nullptr;
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

char* GameThing::GetDebugText() {
    return nullptr;
}

uint32_t GameThing::GetSampleForAttack() {
    return 0;
}

uint32_t GameThing::GetGuidanceResourceType() {
    return 0;
}

uint32_t GameThing::GetShowNeedsPos(uint32_t /*param1*/, MapCoords* /*param2*/) {
    return 0;
}

uint32_t GameThing::Load(GameOSFile* /*file*/) {
    return 0;
}

uint32_t GameThing::Save(GameOSFile* /*file*/) {
    return 0;
}

uint32_t GameThing::GetSaveType() {
    return 0;
}

void GameThing::SaveExtraData(GameOSFile* /*file*/) {
    // Default: no-op
}

void GameThing::ResolveLoad() {
    // Default: no-op
}
