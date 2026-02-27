#pragma once
// ThingMusicInfo — music info associated with game things
// Struct layout from bw1-decomp (ThingMusicInfo.h)
//
// Size: 0x14 bytes (extends GameThing, no additional fields)

#include "GameThing.h"

struct ThingMusicInfo : public GameThing {
};
static_assert(sizeof(ThingMusicInfo) == 0x14, "ThingMusicInfo size mismatch");
