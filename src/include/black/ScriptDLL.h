#pragma once
// ScriptDLL — script virtual machine DLL interface (extends LHDLL)
// Struct layout from bw1-decomp
// Size: 0xDC bytes

#include "LHDLL.h"

#include <stdint.h>

struct LHTransport;

enum VMType : uint32_t;
enum VMScriptType : uint32_t;

struct ScriptDLL {
    LHDLL    super;                    // 0x00
    uint32_t field_0x24;              // 0x24
    uint32_t field_0x28;              // 0x28
    uint32_t field_0x2c;              // 0x2C
    uint32_t field_0x30;              // 0x30
    uintptr_t ParseFile;             // 0x34
    uintptr_t StartScript;           // 0x38
    uintptr_t FindScript;            // 0x3C
    void (__cdecl* AutoStartFn)(LHTransport* transport);  // 0x40
    uintptr_t StopTask;              // 0x44
    uintptr_t StopAllTasks;          // 0x48
    uintptr_t StopTasksOfType;       // 0x4C
    uintptr_t POP;                   // 0x50
    uintptr_t PUSH;                  // 0x54
    uintptr_t STRING;                // 0x58
    int (__cdecl* LoadBinaryFn)(LHTransport* transport, const char* path);  // 0x5C
    uintptr_t SaveBinary;            // 0x60
    uintptr_t SaveState;             // 0x64
    uintptr_t RestoreState;          // 0x68
    uintptr_t Reboot;               // 0x6C
    uint32_t NumTasks;               // 0x70
    uint32_t LineNumber;             // 0x74
    uint32_t TaskNumber;             // 0x78
    uint32_t TaskName;               // 0x7C
    uint32_t TaskFilename;           // 0x80
    uint32_t GetTaskFilename;        // 0x84
    uint32_t GetTaskName;            // 0x88
    uint32_t OpCode;                 // 0x8C
    uint32_t GetCurrentScriptType;   // 0x90
    uint32_t GetScriptInstructionCount; // 0x94
    uint32_t Mode;                   // 0x98
    uint32_t Type;                   // 0x9C
    uint32_t Value;                  // 0xA0
    uint32_t OpCodeName;             // 0xA4
    uint32_t StopScripts;            // 0xA8
    uint32_t GetScriptID;            // 0xAC
    uint32_t Version;                // 0xB0
    uint32_t CodeSize;               // 0xB4
    uint32_t GetNextTask;            // 0xB8
    uint32_t GetPreviousTask;        // 0xBC
    uint32_t GetHighestRunningTask;  // 0xC0
    uint32_t GetFirstRunningTaskId;  // 0xC4
    uint32_t LoopTaskVariables;      // 0xC8
    uint32_t LoopGlobalVariables;    // 0xCC
    uint32_t GetScriptType;          // 0xD0
    uint32_t GetGlobalVariableValue; // 0xD4
    uint32_t field_0xd8;             // 0xD8
};
static_assert(sizeof(ScriptDLL) == 0xDC, "ScriptDLL size mismatch");
