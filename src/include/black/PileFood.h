#pragma once
#include "PileResource.h"

enum HELP_TEXT : uint32_t;

struct PileFood : public PileResource {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    float Get2DRadius() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    bool32_t IsPileFood() override;
    HELP_TEXT GetQueryFirstEnumText() override;
    HELP_TEXT GetQueryLastEnumText() override;

    // === Overrides of Object virtuals ===
    void Draw() override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    LH3DObject_ObjectType Get3DType() override;
    RESOURCE_TYPE GetResourceType() override;
    bool CreatureMustAvoid(Creature* creature) override;

    // === Fields ===
    PileFood* next;       // 0xB4
    uint32_t  field_0xb8; // 0xB8
};
static_assert(sizeof(PileFood) == 0xBC, "PileFood size mismatch");
