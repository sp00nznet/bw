#pragma once
// AttributeTest — decision tree test node with learning episodes
// Struct layout from bw1-decomp (CreatureMentalAttributeTest.h)
//
// Size: 0x94 bytes (plain data, no Base inheritance)

#include "types.h"
#include "CreatureLearningEpisode.h"

// Forward-declare enum
enum ATTRIBUTE_TYPE : uint32_t;

struct AttributeTest {
    LHLinkedList_CreatureLearningEpisode episodes;  // 0x00
    uint32_t       field_0x8;                       // 0x08
    uint32_t       field_0xc;                       // 0x0C
    uint32_t       field_0x10;                      // 0x10
    uint32_t       field_0x14;                      // 0x14
    uint32_t       field_0x18;                      // 0x18
    ATTRIBUTE_TYPE attribute_stack[0x18];            // 0x1C-0x7B
    uint32_t       field_0x7c;                      // 0x7C
    uint32_t       field_0x80;                      // 0x80
    uint32_t       field_0x84;                      // 0x84
    uint32_t       field_0x88;                      // 0x88
    uint32_t       field_0x8c;                      // 0x8C
    uint32_t       field_0x90;                      // 0x90
};
static_assert(sizeof(AttributeTest) == 0x94, "AttributeTest size mismatch");

// Per-type linked list for AttributeTest
struct LHLinkedList_AttributeTest {
    AttributeTest* first;
    AttributeTest* last;
};
static_assert(sizeof(LHLinkedList_AttributeTest) == 0x8, "LHLinkedList_AttributeTest size mismatch");
