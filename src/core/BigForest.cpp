// BigForest class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Simple methods at 0x00438dxx-0x00438exx are packed 16 bytes apart.
// Complex methods at 0x00438fxx-0x004395xx.

#include <black/BigForest.h>
#include <black/Terrain.h>

#include <cstring>

// ============================================================================
// Overrides of Base virtuals
// ============================================================================

void BigForest::ToBeDeleted(int /*param*/) {
    // Original at 0x00438e60 — complex
}

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

uint32_t BigForest::RemoveResource(RESOURCE_TYPE type, uint32_t amount,
                                    GInterfaceStatus* /*status*/, bool* /*param4*/) {
    // v1.0 sub_431C90: wood only. The amount costs amount / life of the store;
    // what is left over goes all at once, and the forest goes with it.
    // ponytail: the mesh is not rescaled as the forest shrinks (vslot 73 +
    // sub_431DE0), and the emptied forest is not deleted -- it holds 0 wood.
    if (static_cast<int>(type) != 1) return 0;
    const float l = GetLife() > 0.0f ? GetLife() : 1.0f;
    const float cost = static_cast<float>(amount) / l;
    if (GetWoodValue() > cost) {
        wood -= cost;
        return amount;
    }
    const uint32_t all = static_cast<uint32_t>(GetWoodValue());
    wood = 0.0f;
    return all;
}

float BigForest::GetRadius() {  // sub_5EA550
    if (!g_mesh_radius_func) return 0.0f;
    return g_mesh_radius_func(GetMesh()) * scale;
}

char* BigForest::GetDebugText() {
    // Original at 0x00438e10
    static char text[] = "BigForest";
    return text;
}

uint32_t BigForest::Load(GameOSFile* /*file*/) {
    // Original at 0x004394e0 — complex serialization
    return 0;
}

uint32_t BigForest::Save(GameOSFile* /*file*/) {
    // Original at 0x00439470 — complex serialization
    return 0;
}

uint32_t BigForest::GetSaveType() {
    // Original at 0x00438e00: mov eax, 0x4d
    return 0x4d;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

int BigForest::GetMesh() const {  // v1.0 vslot 520, sub_4319D0: info +292
    int32_t mesh = -1;
    if (info) std::memcpy(&mesh, reinterpret_cast<const char*>(info) + 292, 4);
    return mesh;
}

void BigForest::Draw() {
    // Original at 0x00438f60 — complex rendering
}

uint32_t BigForest::GetDiscipleStateIfInteractedWith(GInterfaceStatus* /*status*/,
                                                      Villager* /*villager*/) {
    // Original at 0x00439550 — complex
    return 0;
}

void BigForest::CallVirtualFunctionsForCreation(const MapCoords& coords) {
    // Original at 0x00439050 — complex
    MultiMapFixed::CallVirtualFunctionsForCreation(coords);
}

LH3DObject_ObjectType BigForest::Get3DType() {
    // Original at 0x00438da0
    return LH3D_OBJECT_TYPE_DEFAULT;
}

float BigForest::GetWoodValue() {  // v1.0 vslot 409, sub_431C70: life x wood
    return GetLife() * wood;
}

bool32_t BigForest::ValidForPlaceInHand(GInterfaceStatus* /*status*/) {
    // Original at 0x00438db0
    return 0;
}

bool32_t BigForest::InterfaceSetInMagicHand(GInterfaceStatus* /*status*/) {
    // Original at 0x004393c0 — complex
    return 0;
}

bool32_t BigForest::IsTuggable() {
    // Original at 0x00438dc0: returns 0
    return 0;
}

bool BigForest::InteractsWithPhysicsObjects() {
    // Original at 0x004390a0: returns false
    return false;
}

bool BigForest::CreatureMustAvoid(Creature* /*param1*/) {
    // Original at 0x00438f50 — complex
    return false;
}

bool32_t BigForest::VillagerMustAvoid(Villager* /*param1*/) {
    // Original at 0x00438dd0: returns 1
    return 1;
}

uint32_t BigForest::GetCarriedTreeType() {
    // Original at 0x00438de0
    return 0;
}

size_t BigForest::SaveObject(LHOSFile* /*param1*/, const MapCoords* /*param2*/) {
    // Original at 0x00438f70 — complex
    return 0;
}
