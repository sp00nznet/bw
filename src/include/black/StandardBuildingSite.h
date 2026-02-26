#pragma once
// StandardBuildingSite — standard building construction site with wood pile
// Struct layout from bw1-decomp
//
// Size: 0x648 bytes (inherits 0x644 from BuildingSite)
// Overrides all 12 BuildingSite virtual methods plus 5 GameThing overrides.

#include "BuildingSite.h"

struct StandardBuildingSite : public BuildingSite {
    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;                                              // 0x0043d710
    uint32_t Load(GameOSFile* file) override;                                   // 0x0043d890
    uint32_t Save(GameOSFile* file) override;                                   // 0x0043d850
    uint32_t GetSaveType() override;                                            // 0x0043d700

    // === Overrides of BuildingSite virtuals ===
    void Process() override;                                                    // 0x0043d8d0
    uint32_t GetWoodForStats() override;                                        // 0x0043c5e0
    Pot* GetPileWood(const MapCoords& coords) override;                         // 0x0043d6e0
    void SetPileWood(Pot* pile) override;                                       // 0x0043d6f0
    void CreatePileWood() override;                                             // 0x0043d760
    void GetResourcePosAndYAngle(uint32_t type, uint32_t param2, float* out) override; // 0x0043c220
    void RemovePotFromStructure(PotStructure* structure) override;              // 0x0043d800
    bool IsLinkedToThisBuildingSite(Pot* pot) override;                         // 0x0043d830
    float GetNearestEdge(float x, float y, int* out) override;                 // 0x0043ce40
    void GetNextPosFromIndex(int* index) override;                              // 0x0043cf40
    void GetRandomBuildPos(Object* object, int* out) override;                  // 0x0043cde0

    // === Fields ===
    Pot*  wood_pile;  // 0x644
};
static_assert(sizeof(StandardBuildingSite) == 0x648, "StandardBuildingSite size mismatch");
