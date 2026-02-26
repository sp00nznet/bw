#pragma once
// CitadelBuildingSite — building site for citadel construction
// Struct layout from bw1-decomp
//
// Size: 0x644 bytes (same as BuildingSite, no added fields)
// Overrides resource management and building process methods.

#include "BuildingSite.h"

struct CitadelBuildingSite : public BuildingSite {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;                                       // 0x0043d220

    // === Overrides of GameThing virtuals ===
    uint32_t GetResource(RESOURCE_TYPE type) override;                          // 0x0043d320
    uint32_t AddResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* status, bool param4, const MapCoords& coords, int param6) override; // 0x0043d360
    uint32_t RemoveResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* status, bool* param4) override; // 0x0043d3f0
    char* GetDebugText() override;                                              // 0x0043d1a0
    uint32_t Load(GameOSFile* file) override;                                   // 0x0043d620
    uint32_t Save(GameOSFile* file) override;                                   // 0x0043d5e0
    uint32_t GetSaveType() override;                                            // 0x0043d190

    // === Overrides of BuildingSite virtuals ===
    void Process() override;                                                    // 0x0043d660
    Pot* GetPileWood(const MapCoords& coords) override;                         // 0x0043d500
    void SetPileWood(Pot* pile) override;                                       // 0x0043d180
    void CreatePileWood() override;                                             // 0x0043d460
    void GetResourcePosAndYAngle(uint32_t type, uint32_t param2, float* out) override; // 0x0043d470
    void RemovePotFromStructure(PotStructure* structure) override;              // 0x0043d5b0
    bool IsLinkedToThisBuildingSite(Pot* pot) override;                         // 0x0043d580
};
static_assert(sizeof(CitadelBuildingSite) == 0x644, "CitadelBuildingSite size mismatch");
