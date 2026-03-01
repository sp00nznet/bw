#pragma once
// PSysHandFX — hand visual effects for particle system
// Struct layout from bw1-decomp (PSysHandFX.h)
//
// PSysHandFX (0x4, own vtable with 10 entries)
// PHandFX (0x74, extends PSysHandFX)
// PHandFX_Band (0x14, extends PSysBase)

#include <cstdint>
#include "PSysBase.h"

struct PSysHandFX {
    virtual void RemoveAllPermBands();
    virtual void DoRemoveFromHandVisual();
    virtual void AddSpellToHandVisuals();
    virtual void SetPULevel(uint32_t level);
    virtual void DrawHandFX();
    virtual uint32_t GetPULevel();
    virtual void StartTribalPowerRing();
    virtual void StopTribalPowerRing();
    virtual void ReleaseOrCreateTribalPowerRing();
    virtual void Release();

    // Static methods
    static PSysHandFX* CreateHandFX();
    static void CreateTribalPowerColumn();
};
static_assert(sizeof(PSysHandFX) == 0x4, "PSysHandFX size mismatch");

struct PHandFX : public PSysHandFX {
    void RemoveAllPermBands() override;
    void DoRemoveFromHandVisual() override;
    void AddSpellToHandVisuals() override;
    void SetPULevel(uint32_t level) override;
    void DrawHandFX() override;
    uint32_t GetPULevel() override;
    void StartTribalPowerRing() override;
    void StopTribalPowerRing() override;
    void ReleaseOrCreateTribalPowerRing() override;
    void Release() override;

    // === Fields ===
    uint8_t  field_0x4[0x44];     // 0x04
    uint32_t power_up_level;      // 0x48
    uint8_t  field_0x4c[0x28];    // 0x4C
};
static_assert(sizeof(PHandFX) == 0x74, "PHandFX size mismatch");

struct PHandFX_Band : public PSysBase {
    ~PHandFX_Band() override;
};
static_assert(sizeof(PHandFX_Band) == 0x14, "PHandFX_Band size mismatch");
