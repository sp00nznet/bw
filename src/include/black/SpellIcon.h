#pragma once
// SpellIcon — spell icon on the worship site totem
// Struct layout from bw1-decomp
//
// Size: 0x110 bytes (inherits 0x7C from MultiMapFixed)
// Vtable: extends MultiMapFixed
//
// Contains inner TChargingData struct (0x78 bytes) with LightSheet for
// the visual charging effect when a spell is being powered up.

#include "LightSheet.h"
#include "MultiMapFixed.h"

// Forward declarations
struct GSpellSeedInfo;
struct SpellSeedGraphic;

// Inner struct: charging visual data (mangled as Q29SpellIcon13TChargingData)
struct SpellIcon_TChargingData {
    uint8_t    field_0x0;      // 0x00
    // 3 bytes padding (LightSheet alignment)
    LightSheet light_sheet;    // 0x04 (0x60 bytes)
    uint32_t   field_0x64;     // 0x64
    uint32_t   field_0x68;     // 0x68
    uint32_t   field_0x6c;     // 0x6C
    int        field_0x70;     // 0x70
    uint32_t   field_0x74;     // 0x74
};
static_assert(sizeof(SpellIcon_TChargingData) == 0x78, "SpellIcon_TChargingData size mismatch");

struct SpellIcon : public MultiMapFixed {
    // === Overrides of Base/GameThing virtuals ===
    void ToBeDeleted(int param) override;
    GPlayer* GetPlayer() override;
    void SetPlayer(GPlayer* player) override;
    SpellIcon* CastSpellIcon() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    uint32_t GetCreatureBeliefType() override;
    uint32_t GetOverwriteTapToolTip() override;
    bool32_t CanBeFrighteningToCreature(Creature* creature) override;
    WorshipSite* GetWorshipSite() override;
    bool32_t IsSpellIcon() override;

    // === Overrides of Object virtuals ===
    void Create3DObject() override;
    int MoveMapObject(const MapCoords& coords) override;
    void SetSpecularColor(LH3DColor color) override;
    LH3DColor GetSpecularColor() override;
    uint32_t Process() override;
    int GetMesh() const override;
    void Draw() override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    bool IsSpellSeedReturnPoint() const override;
    bool32_t ValidAsInterfaceLeashTarget() override;
    uint32_t InterfaceValidToTap(GInterfaceStatus* status) override;
    uint32_t InterfaceTap(GInterfaceStatus* status) override;
    bool InteractsWithPhysicsObjects() override;

    // === Overrides of MultiMapFixed virtuals ===
    bool IsRepaired() override;
    bool IsBuilt() override;

    // === Fields ===
    SpellSeedGraphic*        graphic;        // 0x7C
    GSpellSeedInfo*          seed_info;      // 0x80
    uint32_t                 field_0x84;     // 0x84
    SpellIcon_TChargingData  charging_data;  // 0x88 (0x78 bytes)
    MapCoords                spell_coords;   // 0x100
    uint32_t                 field_0x10c;    // 0x10C
};
static_assert(sizeof(SpellIcon) == 0x110, "SpellIcon size mismatch");
