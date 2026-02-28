#pragma once
// SubOptionEntry — option entry UI hierarchy
// Struct layout from bw1-decomp (SubOptionEntry.h)
//
// Size: 0x4 bytes each (own vtable hierarchy, NOT Base-derived)
// Vtable: 3 entries (GetSubMeshData, UpdateMouse, UpdateKeyboard)
//
// SubOptionEntry (base) + 9 leaf subclasses:
//   SubOptionEntryButton, SubOptionEntryCheckBoxChecked,
//   SubOptionEntryCheckBoxUnChecked, SubOptionEntryFrame,
//   SubOptionEntryListBox, SubOptionEntryPicture,
//   SubOptionEntryScroll, SubOptionEntrySlider, SubOptionEntryText

#include <cstdint>
#include "LHCoord.h"
#include "InterfaceMessage.h"

// Forward declarations
struct SubMeshDrawData;
enum LH_KEY : uint32_t;

struct SubOptionEntry {
    virtual void     GetSubMeshData(SubMeshDrawData* param_1, int param_2, int param_3);  // vtable[0]
    virtual uint32_t UpdateMouse(LHCoord coord, INTERFACE_MESSAGE_TYPES types, int param_2);  // vtable[1]
    virtual uint32_t UpdateKeyboard(LH_KEY key, uint16_t param_2);  // vtable[2]
};
static_assert(sizeof(SubOptionEntry) == 0x4, "SubOptionEntry size mismatch");

struct SubOptionEntryButton : SubOptionEntry {
    void     GetSubMeshData(SubMeshDrawData* param_1, int param_2, int param_3) override;
    uint32_t UpdateMouse(LHCoord coord, INTERFACE_MESSAGE_TYPES types, int param_2) override;
    uint32_t UpdateKeyboard(LH_KEY key, uint16_t param_2) override;
};
static_assert(sizeof(SubOptionEntryButton) == 0x4, "SubOptionEntryButton size mismatch");

struct SubOptionEntryCheckBoxChecked : SubOptionEntry {
    void     GetSubMeshData(SubMeshDrawData* param_1, int param_2, int param_3) override;
    uint32_t UpdateMouse(LHCoord coord, INTERFACE_MESSAGE_TYPES types, int param_2) override;
    uint32_t UpdateKeyboard(LH_KEY key, uint16_t param_2) override;
};
static_assert(sizeof(SubOptionEntryCheckBoxChecked) == 0x4, "SubOptionEntryCheckBoxChecked size mismatch");

struct SubOptionEntryCheckBoxUnChecked : SubOptionEntry {
    void     GetSubMeshData(SubMeshDrawData* param_1, int param_2, int param_3) override;
    uint32_t UpdateMouse(LHCoord coord, INTERFACE_MESSAGE_TYPES types, int param_2) override;
    uint32_t UpdateKeyboard(LH_KEY key, uint16_t param_2) override;
};
static_assert(sizeof(SubOptionEntryCheckBoxUnChecked) == 0x4, "SubOptionEntryCheckBoxUnChecked size mismatch");

struct SubOptionEntryFrame : SubOptionEntry {
    void     GetSubMeshData(SubMeshDrawData* param_1, int param_2, int param_3) override;
    uint32_t UpdateMouse(LHCoord coord, INTERFACE_MESSAGE_TYPES types, int param_2) override;
    uint32_t UpdateKeyboard(LH_KEY key, uint16_t param_2) override;
};
static_assert(sizeof(SubOptionEntryFrame) == 0x4, "SubOptionEntryFrame size mismatch");

struct SubOptionEntryListBox : SubOptionEntry {
    void     GetSubMeshData(SubMeshDrawData* param_1, int param_2, int param_3) override;
    uint32_t UpdateMouse(LHCoord coord, INTERFACE_MESSAGE_TYPES types, int param_2) override;
    uint32_t UpdateKeyboard(LH_KEY key, uint16_t param_2) override;
};
static_assert(sizeof(SubOptionEntryListBox) == 0x4, "SubOptionEntryListBox size mismatch");

struct SubOptionEntryPicture : SubOptionEntry {
    void     GetSubMeshData(SubMeshDrawData* param_1, int param_2, int param_3) override;
    uint32_t UpdateMouse(LHCoord coord, INTERFACE_MESSAGE_TYPES types, int param_2) override;
    uint32_t UpdateKeyboard(LH_KEY key, uint16_t param_2) override;
};
static_assert(sizeof(SubOptionEntryPicture) == 0x4, "SubOptionEntryPicture size mismatch");

struct SubOptionEntryScroll : SubOptionEntry {
    void     GetSubMeshData(SubMeshDrawData* param_1, int param_2, int param_3) override;
    uint32_t UpdateMouse(LHCoord coord, INTERFACE_MESSAGE_TYPES types, int param_2) override;
    uint32_t UpdateKeyboard(LH_KEY key, uint16_t param_2) override;
};
static_assert(sizeof(SubOptionEntryScroll) == 0x4, "SubOptionEntryScroll size mismatch");

struct SubOptionEntrySlider : SubOptionEntry {
    void     GetSubMeshData(SubMeshDrawData* param_1, int param_2, int param_3) override;
    uint32_t UpdateMouse(LHCoord coord, INTERFACE_MESSAGE_TYPES types, int param_2) override;
    uint32_t UpdateKeyboard(LH_KEY key, uint16_t param_2) override;
};
static_assert(sizeof(SubOptionEntrySlider) == 0x4, "SubOptionEntrySlider size mismatch");

struct SubOptionEntryText : SubOptionEntry {
    void     GetSubMeshData(SubMeshDrawData* param_1, int param_2, int param_3) override;
    uint32_t UpdateMouse(LHCoord coord, INTERFACE_MESSAGE_TYPES types, int param_2) override;
    uint32_t UpdateKeyboard(LH_KEY key, uint16_t param_2) override;
};
static_assert(sizeof(SubOptionEntryText) == 0x4, "SubOptionEntryText size mismatch");
