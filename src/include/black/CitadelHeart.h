#pragma once
// CitadelHeart — central citadel building, plus LeashObj and TempleLeash
// Struct layout from bw1-decomp
//
// LeashObj: 0x78 bytes (Object subclass)
// TempleLeash: 0x10 bytes (plain struct)
// CitadelHeart: 0xE8 bytes (CitadelPart subclass)

#include "CitadelPart.h"

// Forward declarations
struct GCitadelHeartInfo;
struct GTribeInfo;
struct GWorshipSiteInfo;
struct LH3DObject;
struct LH3DSprite;
struct LHMatrix;
struct PhysOb;
struct TempleLeash;
struct WorshipSite;

// LEASH_TYPE_LAST = 3 (sizeof TempleLeash = 0x10: 4 + 3*4 = 16)
static constexpr int LEASH_TYPE_LAST = 3;

// ============================================================================
// LeashObj — leash endpoint object attached to citadel
// ============================================================================

struct LeashObj : public Object {
    // === Overrides of GameThingWithPos virtuals ===
    uint32_t GetOverwriteInteractableToolTip() override;
    const char* GetText() override;
    HELP_TEXT GetQueryFirstEnumText() override;
    HELP_TEXT GetQueryLastEnumText() override;

    // === Overrides of Object virtuals ===
    bool32_t ValidAsInterfaceLeashTarget() override;
    uint32_t InterfaceValidToTap(GInterfaceStatus* status) override;
    uint32_t InterfaceTap(GInterfaceStatus* status) override;
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;

    // === Fields ===
    int            field_0x54;       // 0x54
    TempleLeash*   temple_leash;     // 0x58
    LH3DObject*    object;           // 0x5C
    float          field_0x60;       // 0x60
    float          field_0x64;       // 0x64
    float          field_0x68;       // 0x68
    uint32_t       field_0x6c;       // 0x6C
    LH3DSprite*    sprite;           // 0x70
    float          field_0x74;       // 0x74
};
static_assert(sizeof(LeashObj) == 0x78, "LeashObj size mismatch");

// ============================================================================
// TempleLeash — leash connection data
// ============================================================================

struct TempleLeash {
    int       field_0x0;                      // 0x0
    LeashObj* leashes[LEASH_TYPE_LAST];       // 0x4
};
static_assert(sizeof(TempleLeash) == 0x10, "TempleLeash size mismatch");

// ============================================================================
// CitadelHeart — central citadel heart building
// ============================================================================

struct CitadelHeart : public CitadelPart {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    GPlayer* GetPlayer() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
    void ResolveLoad() override;

    // === Overrides of GameThingWithPos virtuals ===
    bool32_t IsCitadelHeart() override;
    bool32_t CreateBuildingSite() override;
    uint32_t GetScriptObjectType() override;

    // === Overrides of Object virtuals ===
    void SetSpecularColor(LH3DColor color) override;
    LH3DColor GetSpecularColor() override;
    void* GetActualObjectToEffect(GPlayer* player, bool param2) override;
    uint32_t DestroyedByEffect(GPlayer* player, float param2) override;
    uint32_t Process() override;
    void Draw() override;
    void GetWorldMatrix(LHMatrix* out) override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    LH3DObject_ObjectType Get3DType() override;
    uint32_t GetPhysicsConstantsType() override;
    void SetUpPhysOb(PhysOb* param1) override;
    bool InteractsWithPhysicsObjects() override;
    uint32_t ChecksVerticesVObjects() override;
    void ReactToPhysicsImpact(PhysicsObject* param1, bool param2) override;
    void AddToRoutePlan(RPHolder* p1, Creature* p2, int p3, void (*p4)(int, Point2D, float, int)) override;
    float GetRoutePlanRadius(Creature* param1) override;
    uint32_t GetObjectCollide() override;
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;
    bool ShouldFootpathsGoRound() override;

    // === Overrides of MultiMapFixed virtuals ===
    MapCoords* GetDoorPos(MapCoords* pos) override;
    bool Built() override;
    ABODE_TYPE GetAbodeType() override;
    PlannedMultiMapFixed* ConvertToPlanned() override;
    void CreateCollideData() override;

    // === Fields ===
    uint32_t    field_0x8c;     // 0x8C
    uint32_t    field_0x90;     // 0x90
    GameThing*  field_0x94;     // 0x94
    GameThing*  field_0x98;     // 0x98
    uint32_t    field_0x9c;     // 0x9C
    uint32_t    field_0xa0;     // 0xA0
    int         field_0xa4;     // 0xA4
    uint32_t    field_0xa8;     // 0xA8
    GameThing*  field_0xac;     // 0xAC
    GameThing*  field_0xb0;     // 0xB0
    uint32_t    field_0xb4;     // 0xB4
    uint8_t     field_0xb8;     // 0xB8
    // 3 bytes padding
    float       field_0xbc;     // 0xBC
    GameThing*  field_0xc0;     // 0xC0
    uint32_t    field_0xc4;     // 0xC4
    uint32_t    field_0xc8;     // 0xC8
    GameThing*  field_0xcc;     // 0xCC
    float       field_0xd0;     // 0xD0
    uint32_t    field_0xd4;     // 0xD4
    uint32_t    field_0xd8;     // 0xD8
    GameThing*  field_0xdc;     // 0xDC
    uint32_t    field_0xe0;     // 0xE0
    TempleLeash* leashes;       // 0xE4
};
static_assert(sizeof(CitadelHeart) == 0xE8, "CitadelHeart size mismatch");
