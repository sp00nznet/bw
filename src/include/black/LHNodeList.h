#pragma once
// v1.0's small object lists: 8-byte nodes {next, object} pushed at the head,
// with a count beside the head pointer. The town's field (+0x778) and fish
// farm (+0x780) lists and a fish farm's fishermen (+0x80) are this shape
// (inserts in sub_4FEB10 / sub_502970 / sub_503660, removals in sub_4FECD0 /
// sub_502B80 / sub_5036A0).
#include <cstdint>

struct LHNode {
    LHNode* next;
    void*   obj;
};

struct LHNodeList {
    LHNode*  head;   // 0x0
    uint32_t count;  // 0x4

    bool Has(const void* o) const {
        for (LHNode* n = head; n; n = n->next)
            if (n->obj == o) return true;
        return false;
    }
    void Add(void* o) {
        head = new LHNode{head, o};
        ++count;
    }
    void Remove(const void* o) {
        for (LHNode** p = &head; *p;) {
            if ((*p)->obj == o) {
                LHNode* dead = *p;
                *p = dead->next;
                delete dead;
                --count;
            } else {
                p = &(*p)->next;
            }
        }
    }
};
static_assert(sizeof(LHNodeList) == 0x8, "LHNodeList size mismatch");
