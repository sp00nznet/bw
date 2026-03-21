#pragma once
// LHVM — Lionhead Virtual Machine bytecode interpreter
// This is the scripting engine that executes CHL (Challenge) files.
// CHL files contain compiled bytecode with:
//   - Global variables
//   - Script definitions (entry points)
//   - Instructions (31 opcodes)
//   - Auto-start scripts
//   - Data section (string constants)
//
// The LHVM is embedded inside GScript and accessed through ScriptDLL callbacks.

#include <cstdint>
#include <cstdio>

// VM Opcodes (31 total, from CHL bytecode spec)
enum VMOpcode : uint32_t {
    OP_END         = 0,   // End script execution
    OP_WAIT        = 1,   // Wait for N ticks
    OP_PUSH        = 2,   // Push value onto stack
    OP_POP         = 3,   // Pop value from stack
    OP_ADD         = 4,   // Add top two stack values
    OP_CALL        = 5,   // Call native function
    OP_MINUS       = 6,   // Subtract
    OP_UMINUS      = 7,   // Unary minus
    OP_TIMES       = 8,   // Multiply
    OP_DIVIDE      = 9,   // Divide
    OP_MODULUS     = 10,  // Modulo
    OP_NOT         = 11,  // Logical NOT
    OP_AND         = 12,  // Logical AND
    OP_OR          = 13,  // Logical OR
    OP_EQ          = 14,  // Equal
    OP_NEQ         = 15,  // Not equal
    OP_GEQ         = 16,  // Greater or equal
    OP_LEQ         = 17,  // Less or equal
    OP_GT          = 18,  // Greater than
    OP_LT          = 19,  // Less than
    OP_JUMP        = 20,  // Unconditional jump
    OP_SLEEP       = 21,  // Sleep for N seconds
    OP_EXCEPT      = 22,  // Exception handler
    OP_CAST        = 23,  // Type cast
    OP_RUN         = 24,  // Run a script
    OP_ENDEXCEPT   = 25,  // End exception handler
    OP_RETEXCEPT   = 26,  // Return from exception
    OP_FAILEXCEPT  = 27,  // Fail exception
    OP_BRKEXCEPT   = 28,  // Break from exception
    OP_SWAP        = 29,  // Swap top two stack values
    OP_LINE        = 30,  // Line number (debug)
    _VM_OPCODE_COUNT = 31
};

// VM data types
enum VMType : uint32_t {
    VM_TYPE_NONE    = 0,
    VM_TYPE_INT     = 1,
    VM_TYPE_FLOAT   = 2,
    VM_TYPE_VECTOR  = 3,
    VM_TYPE_OBJECT  = 4,
    VM_TYPE_BOOLEAN = 5,
    _VM_TYPE_COUNT  = 6
};

// Script type tags
enum VMScriptType : uint32_t {
    VM_SCRIPT_TYPE_HELP       = 0,
    VM_SCRIPT_TYPE_CHALLENGE  = 1,
    VM_SCRIPT_TYPE_HIGHLIGHT  = 2,
    VM_SCRIPT_TYPE_SPELL      = 3,
    VM_SCRIPT_TYPE_DIALOGUE   = 4,
    _VM_SCRIPT_TYPE_COUNT     = 5
};

// A single bytecode instruction
struct VMInstruction {
    VMOpcode  opcode;      // 0x00 — which operation
    uint32_t  mode;        // 0x04 — addressing mode
    VMType    data_type;   // 0x08 — type of operand
    union {
        int32_t  int_val;
        float    float_val;
        uint32_t uint_val;
    };                     // 0x0C — immediate value
    uint32_t  line_number; // 0x10 — source line (debug)
};
static_assert(sizeof(VMInstruction) == 0x14, "VMInstruction size mismatch");

// A script definition (entry point in the CHL)
struct VMScript {
    char      name[256];        // 0x000 — script name
    char      filename[256];    // 0x100 — source filename
    VMScriptType script_type;   // 0x200 — what kind of script
    uint32_t  global_count;     // 0x204 — number of local variables
    uint32_t  instruction_addr; // 0x208 — IP of first instruction
    uint32_t  param_count;      // 0x20C — number of parameters
    uint32_t  script_id;        // 0x210 — unique ID
};

// A VM stack value
struct VMStackValue {
    VMType   type;
    union {
        int32_t  int_val;
        float    float_val;
        uint32_t uint_val;
    };
};

// A running script task
struct VMTask {
    uint32_t     task_id;              // unique task ID
    uint32_t     script_id;            // which script this task runs
    uint32_t     ip;                   // instruction pointer
    uint32_t     wait_ticks;           // ticks to wait (OP_WAIT)
    float        sleep_seconds;        // seconds to sleep (OP_SLEEP)
    bool         waiting;              // is waiting
    bool         sleeping;             // is sleeping
    bool         finished;             // has ended
    VMStackValue stack[256];           // operand stack
    uint32_t     stack_top;            // top of stack
    float*       local_vars;           // local variable storage
    uint32_t     local_var_count;      // number of locals
    uint32_t     exception_handler_ip; // IP of exception handler
    VMTask*      prev;                 // linked list
    VMTask*      next;                 // linked list
};

// CHL file header
struct CHLHeader {
    char     magic[4];       // "LHVM"
    uint32_t version;        // format version
};

// The virtual machine state
struct LHVM {
    // CHL data
    VMInstruction*  instructions;      // instruction array
    uint32_t        instruction_count; // total instructions
    VMScript*       scripts;           // script definitions
    uint32_t        script_count;      // total scripts
    char*           data_section;      // string constants
    uint32_t        data_size;         // data section size
    float*          global_vars;       // global variables
    uint32_t        global_var_count;  // total globals
    uint32_t*       auto_start_scripts; // script IDs to auto-start
    uint32_t        auto_start_count;  // count of auto-starts

    // Runtime state
    VMTask*         first_task;        // linked list of running tasks
    VMTask*         last_task;
    uint32_t        next_task_id;      // ID counter for new tasks
    uint32_t        tick_count;        // game ticks processed

    // Methods
    bool LoadBinary(const char* path);
    void FreeBinary();
    uint32_t StartScript(const char* name);
    uint32_t StartScriptByID(uint32_t script_id);
    void StopTask(uint32_t task_id);
    void StopAllTasks();
    void ProcessTick();

    // Stack operations (for native function implementations)
    void PushInt(int32_t value);
    void PushFloat(float value);
    int32_t PopInt();
    float PopFloat();

private:
    void ExecuteTask(VMTask* task);
    VMTask* CreateTask(uint32_t script_id);
    void DestroyTask(VMTask* task);
};
