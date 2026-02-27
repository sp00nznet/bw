#pragma once
// CreatureActionKnownAbout — actions the creature knows about
// Struct layout from bw1-decomp (CreatureAction.h)
//
// Size: 0x8 bytes (Base only)
// Also defines CreatureActionKnownAboutEntry (0x10, GBaseInfo)
// and CreatureMagicActionKnownAboutEntry (0x10, extends entry).

#include "Base.h"
#include "GBaseInfo.h"

struct CreatureActionKnownAbout : public Base {
};
static_assert(sizeof(CreatureActionKnownAbout) == 0x8, "CreatureActionKnownAbout size mismatch");

struct CreatureActionKnownAboutEntry {
    GBaseInfo super;  // 0x0
};
static_assert(sizeof(CreatureActionKnownAboutEntry) == 0x10, "CreatureActionKnownAboutEntry size mismatch");

struct CreatureMagicActionKnownAboutEntry {
    CreatureActionKnownAboutEntry super;  // 0x0
};
static_assert(sizeof(CreatureMagicActionKnownAboutEntry) == 0x10, "CreatureMagicActionKnownAboutEntry size mismatch");
