# Compiled CHL (version 7)

`Quests/Challenge.chl` holds the story's compiled scripts. `LHVM::LoadBinary`
(`src/core/LHVM.cpp`) reads it. All integers are little-endian u32, and strings are
NUL-terminated.

```
"LHVM"  version (7)
globals:    count, then count names              -- variable ids 1..count
code:       count, then count x {opcode, mode, type, value, line}   (20 bytes each)
autostart:  count, then count script ids
scripts:    count, then per script:
              name, source file, type, var_offset, var_count,
              var_count names, first instruction, parameter count, id
data:       size, then size bytes of string constants
```

The shipped file: 394 globals, 156,778 instructions, 1 auto-start, 514 scripts and 10,826
data bytes. Parsing ends on its last byte (3,226,458), and the loader refuses a file
that doesn't.

## Variables are one id space

Every variable access is `mode == 1` (21,657 pushes and 7,681 pops). The value is an id:

- **id > the script's `var_offset`**: a local, `local[id - var_offset - 1]`.
  `VortexEntryPerson` (offset 24, four parameters) pops them into 25-28.
- **id ≤ `var_offset`**: a global, `global[id - 1]`. A script can only see globals
  declared before it, which is why its offset bounds them. Ids run from 1 to 462, id 0
  never appears, and id 394 (the last of 394 globals) is used 206 times. That is how
  "1-based" was settled.

## What was wrong before

The old reader took `var_offset` for the number of local names and skipped that many
strings. It desynced on the first script and then looped forever: each string read was
`do fread(c) while (c != 0)`, and at end of file `fread` fails and leaves `c` as it was.
The viewer hung there, before creating its window, and the story script never ran.

## Still unverified

The opcode meanings in `VMOpcode` are not from the game's interpreter. The file shows
opcode 1 used as a conditional jump (`{1, 1, _, 65}` to instruction 65), but our VM
runs it as "wait N ticks". A faithful VM means translating the exe's own LHVM
interpreter; that belongs with the story-script work.
