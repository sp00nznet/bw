#pragma once
// SpellSeedGraphic — visual representation of a spell seed
// Struct layout from bw1-decomp
//
// Size: 0x74 bytes (inherits 0x28 from GameThingWithPos)
// Vtable: extends GameThingWithPos

#include "GameThingWithPos.h"

// Forward declarations
struct Game3DObject;

// Power-up type enum (partial — from bw1-decomp chlasm/Enum.h)
enum POWER_UP_TYPE : uint32_t {
    POWER_UP_TYPE_NONE = 0,
    // ... remaining entries
};

struct SpellSeedGraphic : public GameThingWithPos {
    // === Overrides ===
    void ToBeDeleted(int param) override;
    GPlayer* GetPlayer() override;
    void SetPlayer(GPlayer* player) override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
    void ResolveLoad() override;
    float GetScale() override;
    const char* GetText() override;
    int ForDrawFXGetNumVertices() override;
    void ForDrawFXGetVertexPos(int param1, LHPoint* param2) override;

    // === Fields ===
    uint32_t       field_0x28;    // 0x28
    int*           field_0x2c;    // 0x2C
    Game3DObject*  obj;           // 0x30
    float          field_0x34;    // 0x34
    float          field_0x38;    // 0x38
    float          field_0x3c;    // 0x3C
    float          field_0x40;    // 0x40
    float          field_0x44;    // 0x44
    int            field_0x48;    // 0x48
    uint32_t       field_0x4c;    // 0x4C
    int*           field_0x50;    // 0x50
    float          field_0x54;    // 0x54
    float          field_0x58;    // 0x58
    char           field_0x5c;    // 0x5C
    // 3 bytes padding
    POWER_UP_TYPE  power_up_type; // 0x60
    uint32_t       field_0x64;    // 0x64
    uint32_t       field_0x68;    // 0x68
    uint32_t       field_0x6c;    // 0x6C
    uint32_t       field_0x70;    // 0x70
};
static_assert(sizeof(SpellSeedGraphic) == 0x74, "SpellSeedGraphic size mismatch");
