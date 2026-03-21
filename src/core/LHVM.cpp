// LHVM — Lionhead Virtual Machine bytecode interpreter
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
//
// The CHL (Challenge) file format:
//   [Header]   "LHVM" + version
//   [Globals]  count + variable names
//   [Code]     count + VMInstruction array
//   [AutoStart] count + script ID array
//   [Scripts]  count + VMScript array
//   [Data]     size + string constants

#include <black/LHVM.h>
#include <cstring>
#include <cstdlib>

bool LHVM::LoadBinary(const char* path) {
    FILE* f = fopen(path, "rb");
    if (!f) return false;

    // Read header
    CHLHeader header;
    if (fread(&header, sizeof(header), 1, f) != 1) {
        fclose(f);
        return false;
    }
    if (memcmp(header.magic, "LHVM", 4) != 0) {
        fclose(f);
        return false;
    }

    // Read global variables section
    fread(&global_var_count, sizeof(uint32_t), 1, f);
    global_vars = static_cast<float*>(calloc(global_var_count, sizeof(float)));
    // Skip variable name strings (null-terminated, read until all consumed)
    for (uint32_t i = 0; i < global_var_count; i++) {
        char c;
        do { fread(&c, 1, 1, f); } while (c != '\0');
    }

    // Read code section
    fread(&instruction_count, sizeof(uint32_t), 1, f);
    instructions = static_cast<VMInstruction*>(
        calloc(instruction_count, sizeof(VMInstruction)));
    fread(instructions, sizeof(VMInstruction), instruction_count, f);

    // Read auto-start section
    fread(&auto_start_count, sizeof(uint32_t), 1, f);
    auto_start_scripts = static_cast<uint32_t*>(
        calloc(auto_start_count, sizeof(uint32_t)));
    fread(auto_start_scripts, sizeof(uint32_t), auto_start_count, f);

    // Read scripts section
    fread(&script_count, sizeof(uint32_t), 1, f);
    scripts = static_cast<VMScript*>(calloc(script_count, sizeof(VMScript)));
    for (uint32_t i = 0; i < script_count; i++) {
        // Read null-terminated script name
        uint32_t j = 0;
        char c;
        do {
            fread(&c, 1, 1, f);
            if (j < 255) scripts[i].name[j++] = c;
        } while (c != '\0');
        scripts[i].name[255] = '\0';

        // Read null-terminated source filename
        j = 0;
        do {
            fread(&c, 1, 1, f);
            if (j < 255) scripts[i].filename[j++] = c;
        } while (c != '\0');
        scripts[i].filename[255] = '\0';

        // Read script metadata
        fread(&scripts[i].script_type, sizeof(uint32_t), 1, f);
        fread(&scripts[i].global_count, sizeof(uint32_t), 1, f);
        // Variable names for this script (skip)
        for (uint32_t v = 0; v < scripts[i].global_count; v++) {
            do { fread(&c, 1, 1, f); } while (c != '\0');
        }
        fread(&scripts[i].instruction_addr, sizeof(uint32_t), 1, f);
        fread(&scripts[i].param_count, sizeof(uint32_t), 1, f);
        fread(&scripts[i].script_id, sizeof(uint32_t), 1, f);
    }

    // Read data section (string constants)
    fread(&data_size, sizeof(uint32_t), 1, f);
    data_section = static_cast<char*>(calloc(data_size + 1, 1));
    if (data_size > 0) {
        fread(data_section, 1, data_size, f);
    }

    fclose(f);

    // Initialize runtime
    first_task = nullptr;
    last_task = nullptr;
    next_task_id = 1;
    tick_count = 0;

    return true;
}

void LHVM::FreeBinary() {
    StopAllTasks();
    free(instructions); instructions = nullptr; instruction_count = 0;
    free(scripts);      scripts = nullptr;      script_count = 0;
    free(data_section); data_section = nullptr;  data_size = 0;
    free(global_vars);  global_vars = nullptr;   global_var_count = 0;
    free(auto_start_scripts); auto_start_scripts = nullptr; auto_start_count = 0;
}

VMTask* LHVM::CreateTask(uint32_t script_id) {
    if (script_id >= script_count) return nullptr;

    VMTask* task = static_cast<VMTask*>(calloc(1, sizeof(VMTask)));
    task->task_id = next_task_id++;
    task->script_id = script_id;
    task->ip = scripts[script_id].instruction_addr;
    task->wait_ticks = 0;
    task->sleep_seconds = 0.0f;
    task->waiting = false;
    task->sleeping = false;
    task->finished = false;
    task->stack_top = 0;
    task->local_var_count = scripts[script_id].global_count;
    task->local_vars = static_cast<float*>(
        calloc(task->local_var_count, sizeof(float)));
    task->exception_handler_ip = 0;

    // Add to linked list
    task->prev = last_task;
    task->next = nullptr;
    if (last_task) last_task->next = task;
    else first_task = task;
    last_task = task;

    return task;
}

void LHVM::DestroyTask(VMTask* task) {
    // Unlink from list
    if (task->prev) task->prev->next = task->next;
    else first_task = task->next;
    if (task->next) task->next->prev = task->prev;
    else last_task = task->prev;

    free(task->local_vars);
    free(task);
}

uint32_t LHVM::StartScript(const char* name) {
    for (uint32_t i = 0; i < script_count; i++) {
        if (strcmp(scripts[i].name, name) == 0) {
            VMTask* task = CreateTask(i);
            return task ? task->task_id : 0;
        }
    }
    return 0;
}

uint32_t LHVM::StartScriptByID(uint32_t script_id) {
    VMTask* task = CreateTask(script_id);
    return task ? task->task_id : 0;
}

void LHVM::StopTask(uint32_t task_id) {
    VMTask* task = first_task;
    while (task) {
        if (task->task_id == task_id) {
            task->finished = true;
            return;
        }
        task = task->next;
    }
}

void LHVM::StopAllTasks() {
    VMTask* task = first_task;
    while (task) {
        VMTask* next = task->next;
        free(task->local_vars);
        free(task);
        task = next;
    }
    first_task = nullptr;
    last_task = nullptr;
}

void LHVM::PushInt(int32_t value) {
    // Used by native function callbacks — pushes to current task's stack
    // TODO: needs current task context
}

void LHVM::PushFloat(float value) {
    // TODO: needs current task context
}

int32_t LHVM::PopInt() {
    // TODO: needs current task context
    return 0;
}

float LHVM::PopFloat() {
    // TODO: needs current task context
    return 0.0f;
}

void LHVM::ExecuteTask(VMTask* task) {
    if (task->finished) return;

    // Handle wait state
    if (task->waiting) {
        if (task->wait_ticks > 0) {
            task->wait_ticks--;
            return;
        }
        task->waiting = false;
    }

    // Execute instructions (up to 1000 per tick to prevent infinite loops)
    for (int steps = 0; steps < 1000; steps++) {
        if (task->ip >= instruction_count) {
            task->finished = true;
            return;
        }

        VMInstruction& inst = instructions[task->ip];
        task->ip++;

        switch (inst.opcode) {
        case OP_END:
            task->finished = true;
            return;

        case OP_WAIT:
            task->wait_ticks = static_cast<uint32_t>(
                task->stack_top > 0 ? task->stack[--task->stack_top].int_val : 1);
            task->waiting = true;
            return;

        case OP_PUSH:
            if (task->stack_top < 256) {
                if (inst.mode == 1) {
                    // Push local variable
                    if (inst.uint_val < task->local_var_count) {
                        task->stack[task->stack_top].type = inst.data_type;
                        task->stack[task->stack_top].float_val = task->local_vars[inst.uint_val];
                    }
                } else if (inst.mode == 2) {
                    // Push global variable
                    if (inst.uint_val < global_var_count) {
                        task->stack[task->stack_top].type = inst.data_type;
                        task->stack[task->stack_top].float_val = global_vars[inst.uint_val];
                    }
                } else {
                    // Push immediate
                    task->stack[task->stack_top].type = inst.data_type;
                    task->stack[task->stack_top].int_val = inst.int_val;
                }
                task->stack_top++;
            }
            break;

        case OP_POP:
            if (task->stack_top > 0) {
                task->stack_top--;
                if (inst.mode == 1 && inst.uint_val < task->local_var_count) {
                    task->local_vars[inst.uint_val] = task->stack[task->stack_top].float_val;
                } else if (inst.mode == 2 && inst.uint_val < global_var_count) {
                    global_vars[inst.uint_val] = task->stack[task->stack_top].float_val;
                }
            }
            break;

        case OP_ADD:
            if (task->stack_top >= 2) {
                task->stack_top--;
                task->stack[task->stack_top - 1].float_val += task->stack[task->stack_top].float_val;
            }
            break;

        case OP_MINUS:
            if (task->stack_top >= 2) {
                task->stack_top--;
                task->stack[task->stack_top - 1].float_val -= task->stack[task->stack_top].float_val;
            }
            break;

        case OP_TIMES:
            if (task->stack_top >= 2) {
                task->stack_top--;
                task->stack[task->stack_top - 1].float_val *= task->stack[task->stack_top].float_val;
            }
            break;

        case OP_DIVIDE:
            if (task->stack_top >= 2) {
                task->stack_top--;
                float divisor = task->stack[task->stack_top].float_val;
                if (divisor != 0.0f)
                    task->stack[task->stack_top - 1].float_val /= divisor;
            }
            break;

        case OP_NOT:
            if (task->stack_top > 0) {
                task->stack[task->stack_top - 1].int_val =
                    task->stack[task->stack_top - 1].int_val == 0 ? 1 : 0;
            }
            break;

        case OP_AND:
            if (task->stack_top >= 2) {
                task->stack_top--;
                task->stack[task->stack_top - 1].int_val =
                    (task->stack[task->stack_top - 1].int_val && task->stack[task->stack_top].int_val) ? 1 : 0;
            }
            break;

        case OP_OR:
            if (task->stack_top >= 2) {
                task->stack_top--;
                task->stack[task->stack_top - 1].int_val =
                    (task->stack[task->stack_top - 1].int_val || task->stack[task->stack_top].int_val) ? 1 : 0;
            }
            break;

        case OP_EQ:
            if (task->stack_top >= 2) {
                task->stack_top--;
                task->stack[task->stack_top - 1].int_val =
                    (task->stack[task->stack_top - 1].float_val == task->stack[task->stack_top].float_val) ? 1 : 0;
            }
            break;

        case OP_NEQ:
            if (task->stack_top >= 2) {
                task->stack_top--;
                task->stack[task->stack_top - 1].int_val =
                    (task->stack[task->stack_top - 1].float_val != task->stack[task->stack_top].float_val) ? 1 : 0;
            }
            break;

        case OP_GT:
            if (task->stack_top >= 2) {
                task->stack_top--;
                task->stack[task->stack_top - 1].int_val =
                    (task->stack[task->stack_top - 1].float_val > task->stack[task->stack_top].float_val) ? 1 : 0;
            }
            break;

        case OP_LT:
            if (task->stack_top >= 2) {
                task->stack_top--;
                task->stack[task->stack_top - 1].int_val =
                    (task->stack[task->stack_top - 1].float_val < task->stack[task->stack_top].float_val) ? 1 : 0;
            }
            break;

        case OP_GEQ:
            if (task->stack_top >= 2) {
                task->stack_top--;
                task->stack[task->stack_top - 1].int_val =
                    (task->stack[task->stack_top - 1].float_val >= task->stack[task->stack_top].float_val) ? 1 : 0;
            }
            break;

        case OP_LEQ:
            if (task->stack_top >= 2) {
                task->stack_top--;
                task->stack[task->stack_top - 1].int_val =
                    (task->stack[task->stack_top - 1].float_val <= task->stack[task->stack_top].float_val) ? 1 : 0;
            }
            break;

        case OP_JUMP:
            // Conditional jump if top of stack is nonzero (or unconditional if mode == 0)
            if (inst.mode == 0) {
                task->ip = inst.uint_val;
            } else if (task->stack_top > 0) {
                task->stack_top--;
                if (task->stack[task->stack_top].int_val != 0) {
                    task->ip = inst.uint_val;
                }
            }
            break;

        case OP_CALL:
            // Native function call — inst.uint_val is the function index
            // TODO: dispatch to native function table (465 functions)
            break;

        case OP_SLEEP:
            if (task->stack_top > 0) {
                task->stack_top--;
                task->sleep_seconds = task->stack[task->stack_top].float_val;
            }
            task->sleeping = true;
            return;

        case OP_UMINUS:
            if (task->stack_top > 0) {
                task->stack[task->stack_top - 1].float_val =
                    -task->stack[task->stack_top - 1].float_val;
            }
            break;

        case OP_MODULUS:
            if (task->stack_top >= 2) {
                task->stack_top--;
                int32_t divisor = task->stack[task->stack_top].int_val;
                if (divisor != 0)
                    task->stack[task->stack_top - 1].int_val %= divisor;
            }
            break;

        case OP_SWAP:
            if (task->stack_top >= 2) {
                VMStackValue tmp = task->stack[task->stack_top - 1];
                task->stack[task->stack_top - 1] = task->stack[task->stack_top - 2];
                task->stack[task->stack_top - 2] = tmp;
            }
            break;

        case OP_LINE:
            // Debug info — no runtime effect
            break;

        case OP_RUN:
            // Start another script
            if (task->stack_top > 0) {
                task->stack_top--;
                StartScriptByID(static_cast<uint32_t>(task->stack[task->stack_top].int_val));
            }
            break;

        case OP_EXCEPT:
            task->exception_handler_ip = inst.uint_val;
            break;

        case OP_ENDEXCEPT:
        case OP_RETEXCEPT:
        case OP_FAILEXCEPT:
        case OP_BRKEXCEPT:
            // Exception handling — simplified for now
            break;

        case OP_CAST:
            // Type conversion — simplified (float<->int)
            if (task->stack_top > 0) {
                VMStackValue& top = task->stack[task->stack_top - 1];
                if (inst.data_type == VM_TYPE_FLOAT && top.type == VM_TYPE_INT) {
                    float f = static_cast<float>(top.int_val);
                    top.float_val = f;
                    top.type = VM_TYPE_FLOAT;
                } else if (inst.data_type == VM_TYPE_INT && top.type == VM_TYPE_FLOAT) {
                    int32_t i = static_cast<int32_t>(top.float_val);
                    top.int_val = i;
                    top.type = VM_TYPE_INT;
                }
                top.type = inst.data_type;
            }
            break;

        default:
            // Unknown opcode
            break;
        }
    }
}

void LHVM::ProcessTick() {
    tick_count++;

    // Execute each task
    VMTask* task = first_task;
    while (task) {
        VMTask* next = task->next;  // save in case task is destroyed

        if (!task->finished) {
            ExecuteTask(task);
        }

        // Clean up finished tasks
        if (task->finished) {
            DestroyTask(task);
        }

        task = next;
    }
}
