#pragma once
// Football — football pitch building (villager activity)
// Struct layout from bw1-decomp
//
// Size: 0x318 bytes (inherits 0xC4 from Abode)
// Vtable: extends Abode

#include "Abode.h"

// Football substate enums
enum FOOTBALL_SUBSTATES_ATTACKER : uint32_t {
    FOOTBALL_SUBSTATES_ATTACKER_SHOOT            = 0x0,
    FOOTBALL_SUBSTATES_ATTACKER_PASS             = 0x1,
    FOOTBALL_SUBSTATES_ATTACKER_LOB_NEAR_GOAL    = 0x2,
    FOOTBALL_SUBSTATES_ATTACKER_DRIBBLE          = 0x3,
    FOOTBALL_SUBSTATES_ATTACKER_MOVE_TO_BE_PASSED = 0x4,
    FOOTBALL_SUBSTATES_ATTACKER_GO_TO_BALL       = 0x5,
    FOOTBALL_SUBSTATES_ATTACKER_GO_HOME          = 0x6,
    FOOTBALL_SUBSTATES_ATTACKER_IDLE             = 0x7,
};

enum FOOTBALL_SUBSTATES_DEFENDER : uint32_t {
    FOOTBALL_SUBSTATES_DEFENDER_SAVE        = 0x0,
    FOOTBALL_SUBSTATES_DEFENDER_CLEAR       = 0x1,
    FOOTBALL_SUBSTATES_DEFENDER_DRIBBLE     = 0x2,
    FOOTBALL_SUBSTATES_DEFENDER_PASS        = 0x3,
    FOOTBALL_SUBSTATES_DEFENDER_MARK        = 0x4,
    FOOTBALL_SUBSTATES_DEFENDER_GO_TO_BALL  = 0x5,
    FOOTBALL_SUBSTATES_DEFENDER_GO_HOME     = 0x6,
    FOOTBALL_SUBSTATES_DEFENDER_IDLE        = 0x7,
};

enum FOOTBALL_SUBSTATES_GOALIE : uint32_t {
    FOOTBALL_SUBSTATES_GOALIE_SAVE        = 0x0,
    FOOTBALL_SUBSTATES_GOALIE_CLEAR       = 0x1,
    FOOTBALL_SUBSTATES_GOALIE_LOOK        = 0x2,
    FOOTBALL_SUBSTATES_GOALIE_PASS        = 0x3,
    FOOTBALL_SUBSTATES_GOALIE_GO_TO_BALL  = 0x4,
    FOOTBALL_SUBSTATES_GOALIE_GO_HOME     = 0x5,
    FOOTBALL_SUBSTATES_GOALIE_IDLE        = 0x6,
};

struct Football : public Abode {
    // === Overrides of Base/GameThing virtuals ===
    void ToBeDeleted(int param) override;
    float GetVillagerActivityDesire(Villager* villager) override;
    void SetVillagerActivity(Villager* villager) override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    uint32_t GetCreatureBeliefType() override;
    bool32_t IsFootball() override;

    // === Overrides of Object virtuals ===
    void ReduceLife(float value, GPlayer* player) override;
    uint32_t Process() override;
    void Draw() override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    LH3DObject_ObjectType Get3DType() override;
    bool InteractsWithPhysicsObjects() override;
    bool CreatureMustAvoid(Creature* param1) override;

    // === Overrides of MultiMapFixed virtuals ===
    MapCoords* GetDoorPos(MapCoords* pos) override;
    bool IsRepaired() override;
    bool IsBuilt() override;

    // === Fields ===
    uint8_t field_0xc4[0x254]; // 0xC4 — football game state data
};
static_assert(sizeof(Football) == 0x318, "Football size mismatch");
