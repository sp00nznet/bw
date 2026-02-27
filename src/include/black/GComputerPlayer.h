#pragma once
// GComputerPlayer — computer-controlled player entities
// Struct layout from bw1-decomp (PlayerComputer.h)
//
// Also defines: GComputerAttitudeToPlayer (0x14), GComputerPlayerQueue (0x14),
//   GComputerSeen (0x14), GComputerSpellCast (0x14), PlayerActionState (0x28),
//   PlayerSubAction (0x14), PlayerSubActionArgument (0x14)

#include "GameThing.h"
#include "GameThingWithPos.h"

// GameThing-derived types (0x14, no additional fields)

struct GComputerAttitudeToPlayer : public GameThing {
};
static_assert(sizeof(GComputerAttitudeToPlayer) == 0x14, "GComputerAttitudeToPlayer size mismatch");

struct GComputerPlayerQueue : public GameThing {
};
static_assert(sizeof(GComputerPlayerQueue) == 0x14, "GComputerPlayerQueue size mismatch");

struct GComputerSeen : public GameThing {
};
static_assert(sizeof(GComputerSeen) == 0x14, "GComputerSeen size mismatch");

struct GComputerSpellCast : public GameThing {
};
static_assert(sizeof(GComputerSpellCast) == 0x14, "GComputerSpellCast size mismatch");

struct PlayerSubAction : public GameThing {
};
static_assert(sizeof(PlayerSubAction) == 0x14, "PlayerSubAction size mismatch");

struct PlayerSubActionArgument : public GameThing {
};
static_assert(sizeof(PlayerSubActionArgument) == 0x14, "PlayerSubActionArgument size mismatch");

// GameThingWithPos-derived types (0x28, no additional fields)

struct GComputerPlayer : public GameThingWithPos {
};
static_assert(sizeof(GComputerPlayer) == 0x28, "GComputerPlayer size mismatch");

struct PlayerActionState : public GameThingWithPos {
};
static_assert(sizeof(PlayerActionState) == 0x28, "PlayerActionState size mismatch");
