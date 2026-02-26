#pragma once
// WorshipTotem — totem statue at a worship site
// Struct layout from bw1-decomp
//
// Size: 0x104 bytes (inherits 0x8C from CitadelPart)
// Vtable: extends MultiMapFixedVftable, overrides ~20 methods
//
// Contains TChargingData inner struct for visual charging effects.

#include "CitadelPart.h"
#include "LightSheet.h"

// Forward declarations
struct EffectValues;
struct WorshipSite;

// Inner struct: charging visual data (mangled as Q212WorshipTotem13TChargingData)
struct WorshipTotem_TChargingData {
    uint8_t     field_0x0;      // 0x00
    // 3 bytes padding
    LightSheet  light_sheet;    // 0x04 (0x60 bytes)
    uint32_t    field_0x64;     // 0x64
    uint32_t    field_0x68;     // 0x68
    uint32_t    field_0x6c;     // 0x6C
};
static_assert(sizeof(WorshipTotem_TChargingData) == 0x70, "WorshipTotem_TChargingData size mismatch");

struct WorshipTotem : public CitadelPart {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;                                    // 0x007808e0

    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;                                           // 0x00780800
    uint32_t Load(GameOSFile* file) override;                                // 0x00780f10
    uint32_t Save(GameOSFile* file) override;                                // 0x00780f90
    uint32_t GetSaveType() override;                                         // 0x007807f0
    void ResolveLoad() override;                                             // 0x00780f00

    // === Overrides of GameThingWithPos virtuals ===
    float GetPSysPower() const override;                                     // 0x00780ad0
    float CalculateDesireForFood() override;                                 // 0x00780a80
    float CalculateDesireForRest() override;                                 // 0x00780a90
    float CalculatePeopleHidingIndicator() override;                         // 0x00780aa0
    uint32_t IsSacrificeAltar() override;                                    // 0x007807e0

    // === Overrides of Object virtuals ===
    void SetSpecularColor(LH3DColor color) override;                         // 0x007807b0
    LH3DColor GetSpecularColor() override;                                   // 0x007807c0
    int GetMesh() const override;                                            // 0x00780a70
    void Draw() override;                                                    // 0x00519360
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;  // 0x00780ab0
    LH3DObject_ObjectType Get3DType() override;                              // 0x007807d0
    bool IsSpellSeedReturnPoint() const override;                            // 0x00780790
    uint32_t IsEffectReceiver(EffectValues* values) override;                // 0x007807a0

    // === Static methods ===
    static WorshipTotem* Create(WorshipSite* site);                          // 0x00780930

    // === Fields ===
    uint32_t                    field_0x8c;        // 0x8C
    WorshipTotem_TChargingData  charging_data;     // 0x90 (0x70 bytes)
    WorshipSite*                site;              // 0x100
};
static_assert(sizeof(WorshipTotem) == 0x104, "WorshipTotem size mismatch");
