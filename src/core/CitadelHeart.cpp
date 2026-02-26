// CitadelHeart and LeashObj class implementations
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)

#include <black/CitadelHeart.h>

// ============================================================================
// LeashObj
// ============================================================================

uint32_t LeashObj::GetOverwriteInteractableToolTip() {
    // Original at 0x00464580 — complex
    return 0;
}

const char* LeashObj::GetText() {
    // Original at 0x00464860 — complex
    return "LeashObj";
}

HELP_TEXT LeashObj::GetQueryFirstEnumText() {
    // Original at 0x00464870 — complex
    return HELP_TEXT_NONE;
}

HELP_TEXT LeashObj::GetQueryLastEnumText() {
    // Original at 0x00464880 — complex
    return HELP_TEXT_NONE;
}

bool32_t LeashObj::ValidAsInterfaceLeashTarget() {
    // Original at 0x00464850 — complex
    return 0;
}

uint32_t LeashObj::InterfaceValidToTap(GInterfaceStatus* /*status*/) {
    // Original at 0x00464450 — complex
    return 0;
}

uint32_t LeashObj::InterfaceTap(GInterfaceStatus* /*status*/) {
    // Original at 0x00464490 — complex
    return 0;
}

size_t LeashObj::SaveObject(LHOSFile* /*param1*/, const MapCoords* /*param2*/) {
    // Original at 0x00464840 — complex
    return 0;
}

// ============================================================================
// CitadelHeart — Overrides of Base virtuals
// ============================================================================

void CitadelHeart::ToBeDeleted(int param) {
    // Original at 0x00464c50 — complex cleanup
    CitadelPart::ToBeDeleted(param);
}

// ============================================================================
// CitadelHeart — Overrides of GameThing virtuals
// ============================================================================

GPlayer* CitadelHeart::GetPlayer() {
    // Original at 0x00468020 — complex
    return nullptr;
}

char* CitadelHeart::GetDebugText() {
    // Original at 0x00464bb0
    static char text[] = "CitadelHeart";
    return text;
}

uint32_t CitadelHeart::Load(GameOSFile* /*file*/) {
    // Original at 0x004657f0 — complex serialization
    return 0;
}

uint32_t CitadelHeart::Save(GameOSFile* /*file*/) {
    // Original at 0x004655c0 — complex serialization
    return 0;
}

uint32_t CitadelHeart::GetSaveType() {
    // Original at 0x00464ba0
    return 0;
}

void CitadelHeart::ResolveLoad() {
    // Original at 0x00465a10 — complex
}

// ============================================================================
// CitadelHeart — Overrides of GameThingWithPos virtuals
// ============================================================================

bool32_t CitadelHeart::IsCitadelHeart() {
    // Original at 0x00464b80: returns 1
    return 1;
}

bool32_t CitadelHeart::CreateBuildingSite() {
    // Original at 0x00468dc0 — complex
    return 0;
}

uint32_t CitadelHeart::GetScriptObjectType() {
    // Original at 0x004680b0 — complex
    return 0;
}

// ============================================================================
// CitadelHeart — Overrides of Object virtuals
// ============================================================================

void CitadelHeart::SetSpecularColor(LH3DColor /*color*/) {
    // Original at 0x00464b20 — sets color on 3D object
}

LH3DColor CitadelHeart::GetSpecularColor() {
    // Original at 0x00464b30 — complex
    return LH3DColor{0};
}

void* CitadelHeart::GetActualObjectToEffect(GPlayer* /*player*/, bool /*param2*/) {
    // Original at 0x00468c30 — complex
    return nullptr;
}

uint32_t CitadelHeart::DestroyedByEffect(GPlayer* /*player*/, float /*param2*/) {
    // Original at 0x00468da0 — complex
    return 0;
}

uint32_t CitadelHeart::Process() {
    // Original at 0x004665a0 — complex
    return 0;
}

void CitadelHeart::Draw() {
    // Original at 0x00464b90 — complex rendering
}

void CitadelHeart::GetWorldMatrix(LHMatrix* /*out*/) {
    // Original at 0x00467870 — complex
}

void CitadelHeart::CallVirtualFunctionsForCreation(const MapCoords& coords) {
    // Original at 0x004675a0 — complex
    CitadelPart::CallVirtualFunctionsForCreation(coords);
}

LH3DObject_ObjectType CitadelHeart::Get3DType() {
    // Original at 0x00464b40 — complex
    return LH3D_OBJECT_TYPE_DEFAULT;
}

uint32_t CitadelHeart::GetPhysicsConstantsType() {
    // Original at 0x00467b60 — complex
    return 0;
}

void CitadelHeart::SetUpPhysOb(PhysOb* /*param1*/) {
    // Original at 0x00467b70 — complex
}

bool CitadelHeart::InteractsWithPhysicsObjects() {
    // Original at 0x00467b40 — complex
    return false;
}

uint32_t CitadelHeart::ChecksVerticesVObjects() {
    // Original at 0x00467b30 — complex
    return 0;
}

void CitadelHeart::ReactToPhysicsImpact(PhysicsObject* /*param1*/, bool /*param2*/) {
    // Original at 0x00467bb0 — complex
}

void CitadelHeart::AddToRoutePlan(RPHolder* /*p1*/, Creature* /*p2*/, int /*p3*/, void (*/*p4*/)(int, Point2D, float, int)) {
    // Original at 0x004680d0 — complex
}

float CitadelHeart::GetRoutePlanRadius(Creature* /*param1*/) {
    // Original at 0x004680c0 — complex
    return 0.0f;
}

uint32_t CitadelHeart::GetObjectCollide() {
    // Original at 0x00464b50 — complex
    return 0;
}

size_t CitadelHeart::SaveObject(LHOSFile* /*param1*/, const MapCoords* /*param2*/) {
    // Original at 0x004673a0 — complex serialization
    return 0;
}

bool CitadelHeart::ShouldFootpathsGoRound() {
    // Original at 0x00464b70: returns true
    return true;
}

// ============================================================================
// CitadelHeart — Overrides of MultiMapFixed virtuals
// ============================================================================

MapCoords* CitadelHeart::GetDoorPos(MapCoords* pos) {
    // Original at 0x00467d10 — complex
    return pos;
}

bool CitadelHeart::Built() {
    // Original at 0x00465000 — complex
    return false;
}

ABODE_TYPE CitadelHeart::GetAbodeType() {
    // Original at 0x00464b60 — complex
    return ABODE_TYPE_NONE;
}

PlannedMultiMapFixed* CitadelHeart::ConvertToPlanned() {
    // Original at 0x00465430 — complex
    return nullptr;
}

void CitadelHeart::CreateCollideData() {
    // Original at 0x00468fb0 — complex
}
