#pragma once
// CreatureLearningEpisode — a single learning episode record
// Struct layout from bw1-decomp (CreatureLearning.h)
//
// Size: 0x14 bytes (inherits 0x8 from Base)

#include "Base.h"

struct CreatureLearningEpisode : public Base {
    uint8_t field_0x8[0xC];  // 0x08-0x13
};
static_assert(sizeof(CreatureLearningEpisode) == 0x14, "CreatureLearningEpisode size mismatch");

// Per-type linked list (8 bytes: first + last pointers)
struct LHLinkedList_CreatureLearningEpisode {
    CreatureLearningEpisode* first;
    CreatureLearningEpisode* last;
};
static_assert(sizeof(LHLinkedList_CreatureLearningEpisode) == 0x8, "LHLinkedList_CreatureLearningEpisode size mismatch");
