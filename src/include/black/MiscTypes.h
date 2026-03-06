#pragma once
// MiscTypes — remaining small game types from various vendor headers
// All are simple wrappers or small structs

#include "GBaseInfo.h"
#include "GameThingWithPos.h"
#include "MobileObject.h"
#include "Object.h"
#include "PlannedMultiMapFixed.h"
#include "SingleMapFixed.h"

#include <stdint.h>

struct HelpText;

// === GBaseOnly (0x54) — extends Object ===
// From MobileStatic.h

struct GBaseOnly : public Object {
};
static_assert(sizeof(GBaseOnly) == 0x54, "GBaseOnly size mismatch");

// === Creed (0x68) — extends MobileObject ===
// From Creature.h

struct Creed : public MobileObject {
};
static_assert(sizeof(Creed) == 0x68, "Creed size mismatch");

// === GRewardProgress (0x10) — extends GBaseInfo ===
// From Reward.h

struct GRewardProgress : public GBaseInfo {
};
static_assert(sizeof(GRewardProgress) == 0x10, "GRewardProgress size mismatch");

// === GScriptOpposingCreature (0x10) — extends GBaseInfo ===
// From Script.h

struct GScriptOpposingCreature : public GBaseInfo {
};
static_assert(sizeof(GScriptOpposingCreature) == 0x10, "GScriptOpposingCreature size mismatch");

// === GSpeedThreshold (0x10) — extends GBaseInfo ===
// From MobileObject.h

struct GSpeedThreshold : public GBaseInfo {
};
static_assert(sizeof(GSpeedThreshold) == 0x10, "GSpeedThreshold size mismatch");

// === PPlannedFootball (0x48) — extends PlannedMultiMapFixed ===
// From PFootball.h

struct PPlannedFootball : public PlannedMultiMapFixed {
};
static_assert(sizeof(PPlannedFootball) == 0x48, "PPlannedFootball size mismatch");

// === PrayerIcon (0x5C) — extends SingleMapFixed ===
// From WorshipSpellIcon.h

struct PrayerIcon : public SingleMapFixed {
};
static_assert(sizeof(PrayerIcon) == 0x5C, "PrayerIcon size mismatch");

// === MissionaryControl (0x28) — extends GameThingWithPos ===
// From Villager.h

struct MissionaryControl : public GameThingWithPos {
};
static_assert(sizeof(MissionaryControl) == 0x28, "MissionaryControl size mismatch");

// === HelpTextDataBase (0x8) — help text array container ===
// From HelpText.h

struct HelpTextDataBase {
    HelpText* array;    // 0x00
    uint32_t  count;    // 0x04
};
static_assert(sizeof(HelpTextDataBase) == 0x8, "HelpTextDataBase size mismatch");

// === PlayerInfo (0x8) — player info data ===
// From PlayerInfo.h

struct PlayerInfo {
    uint8_t field_0x0[0x8];  // 0x00
};
static_assert(sizeof(PlayerInfo) == 0x8, "PlayerInfo size mismatch");

// === GFlockInfo (0x1) — flock info marker ===
// From Flock.h

struct GFlockInfo {
    uint8_t field_0x0;  // 0x00
};
static_assert(sizeof(GFlockInfo) == 0x1, "GFlockInfo size mismatch");
