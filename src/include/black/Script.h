#pragma once
// GScript — the game's script engine (LHVM bytecode interpreter)
// Struct layout from bw1-decomp
//
// Size: 0xBC bytes (inherits 0x8 from Base)
// Executes CHL (Challenge) bytecode files with a stack-based VM,
// 31 opcodes, and 465 native function bindings.

#include "Base.h"
#include "types.h"

// Forward declarations
struct ScriptDLL;
struct Town;

// Script feature command enum
enum SCRIPT_FEATURE_COMMANDS : uint32_t {
    SCRIPT_FEATURE_COMMANDS_0 = 0,
};

struct GScript : public Base {
    // Fields are mostly opaque — internal VM state, task lists, etc.
    // Key sub-structures include the ScriptDLL (0xDC bytes) which holds
    // the actual bytecode interpreter and native function table.
    uint8_t field_0x8[0xB4];  // 0x08-0xBB — VM state

    // Non-virtual methods
    void Create();
    void StartScript(const char* name, int param2);
    void LoadBinary(const char* filename);
    void Process();
    void ProcessFade();
    void Reset();
    void DeleteAllScriptCreatedGameThings();
    void StopScriptsOfType(int type);
    void SetupScreenFadeTo(float target, float speed);
    void CleanGameForScriptReboot();
    void PUSH(int value);
    Town* FindInTown(const MapCoords& coords);
};
static_assert(sizeof(GScript) == 0xBC, "GScript size mismatch");
