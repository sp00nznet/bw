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
struct Abode;
struct GameThingWithPos;

enum VMType : uint32_t;
enum VMScriptType : uint32_t;
enum SCRIPT_OBJECT_TYPE : uint32_t;
enum SCRIPT_INTERFACE_LEVEL : uint32_t;

// Script feature command enum
enum SCRIPT_FEATURE_COMMANDS : uint32_t {
    SCRIPT_FEATURE_COMMANDS_0 = 0,
};

struct GScript : public Base {
    // Fields are mostly opaque — internal VM state, task lists, etc.
    uint8_t field_0x8[0xB4];  // 0x08-0xBB — VM state

    // Non-virtual methods
    GScript* Create();
    void Reset(int param);
    void LoadBinary(char* binary);
    void Process();
    void ProcessFade(bool param);
    void SetupScreenFadeTo(uint8_t r, uint8_t g, uint8_t b, int8_t a);
    void CleanGameForScriptReboot();
    void PUSH(void* value, VMType type);
    void StopScriptsOfType(VMScriptType type);
    void ScriptErrorMessage(char* msg);
    void ScriptWarningMessage(char* msg);
    Abode* FindInTown(GameThingWithPos* pos,
        int (__cdecl* filter)(GameThingWithPos*, SCRIPT_OBJECT_TYPE, uint32_t),
        SCRIPT_OBJECT_TYPE obj_type, uint32_t param);

    // Static methods
    static int StartScript(char* name);
    static void SetInterfaceInteraction(SCRIPT_INTERFACE_LEVEL level);
    static void DeleteAllScriptCreatedGameThings();
};
static_assert(sizeof(GScript) == 0xBC, "GScript size mismatch");

// GScriptOpposingCreature — info type for opposing creature script data
// Size: 0x10 bytes (GBaseInfo only)
#include "GBaseInfo.h"

struct GScriptOpposingCreature {
    GBaseInfo super;  // 0x00
};
static_assert(sizeof(GScriptOpposingCreature) == 0x10, "GScriptOpposingCreature size mismatch");
