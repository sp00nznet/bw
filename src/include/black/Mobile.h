#pragma once
// Mobile — moveable Object (adds minimal state to Object)
// Struct layout from bw1-decomp
//
// Size: 0x58 bytes (inherits 0x54 from Object)
// Vtable: 0x85C bytes (same size as Object — no new virtuals)

#include "Object.h"

struct Mobile : public Object {
    // No new virtual methods — vtable same as Object (0x85C bytes)
    Object* GetMapChild(const MapCell* cell) override;          // sub_4140F0
    void SetMapChild(Object* object, MapCell* cell) override;   // sub_414120
    void InsertMapObject() override;                            // sub_5E8CA0
    void RemoveMapObject() override;                            // sub_5E8D00
    void InsertMapObjectToCell(MapCell* cell) override;         // sub_5E8D90
    void RemoveMapObjectFromCell(MapCell* cell) override;       // sub_5E8E30
    int MoveMapObject(const MapCoords& coords) override;        // sub_5E8FA0
    void ActualMoveMapObject(const MapCoords& coords) override; // sub_5EA470

    // === Fields ===
    uint16_t field_0x54;   // 0x54 — saved/loaded in Mobile::Save/Load
    uint16_t pad_0x56;     // 0x56 — padding to 0x58
};
static_assert(sizeof(Mobile) == 0x58, "Mobile size mismatch");
