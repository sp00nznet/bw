#pragma once
// DecisionTree — decision tree hierarchy for creature AI
// Struct layout from bw1-decomp (CreatureMentalAttributeTest.h)
//
// Contains DecisionTreeNode (0x8), DecisionTree (0x8),
// DecisionTreeAgenda (0x24), DecisionTreeAgendas (0xa0),
// DecisionTreeCollection (0x140).

#include "types.h"

struct AttributeTest;

// Forward-declare enums
enum DECISION_TREE_TYPE : uint32_t;
enum CREATURE_DESIRES : uint32_t;

struct DecisionTreeNode {
    AttributeTest* tests[2];  // 0x00
};
static_assert(sizeof(DecisionTreeNode) == 0x8, "DecisionTreeNode size mismatch");

struct DecisionTree {
    DecisionTreeNode root;  // 0x00
};
static_assert(sizeof(DecisionTree) == 0x8, "DecisionTree size mismatch");

struct DecisionTreeAgenda {
    DECISION_TREE_TYPE tree_type;         // 0x00
    CREATURE_DESIRES   creature_desires;  // 0x04
    uint32_t           field_0x8;         // 0x08
    uint32_t           field_0xc;         // 0x0C
    uint32_t           field_0x10;        // 0x10
    DecisionTree       trees[2];          // 0x14-0x23
};
static_assert(sizeof(DecisionTreeAgenda) == 0x24, "DecisionTreeAgenda size mismatch");

struct DecisionTreeAgendas {
    DecisionTreeAgenda* contents[0x28];  // 0x00
};
static_assert(sizeof(DecisionTreeAgendas) == 0xA0, "DecisionTreeAgendas size mismatch");

// _LESSON_TYPE_COUNT = 2
struct DecisionTreeCollection {
    DecisionTreeAgendas agendas[2];  // 0x00
};
static_assert(sizeof(DecisionTreeCollection) == 0x140, "DecisionTreeCollection size mismatch");
