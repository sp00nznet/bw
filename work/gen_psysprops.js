const fs = require("fs");
const text = fs.readFileSync("vendor/bw1-decomp/black/PSysProperties.h", "utf8");
const re = /struct (\w+)\s*\{[^}]*struct (\w+) super;[^}]*\};\s*static_assert\(sizeof\(struct \w+\) == (0x[0-9a-fA-F]+)/g;
let m;
const atoms = [];
const collections = [];
while ((m = re.exec(text)) != null) {
    if (m[2] === "BaseAtomModifierData") atoms.push(m[1]);
    else collections.push(m[1]);
}

let out = `#pragma once
// PSysProperties — particle system modifier data types
// All extend BaseAtomModifierData or BaseCollectionModifierData at size 0x14
// Struct layouts from bw1-decomp (71 types)

#include "PSysModifiers.h"

#include <stdint.h>

// === Atom modifier data types (extend BaseAtomModifierData, 0x14 bytes each) ===

`;

for (const name of atoms) {
    out += `struct ${name} : public BaseAtomModifierData {};\n`;
    out += `static_assert(sizeof(${name}) == 0x14, "${name} size mismatch");\n\n`;
}

out += `// === Collection modifier data types (extend BaseCollectionModifierData, 0x14 bytes each) ===\n\n`;

for (const name of collections) {
    out += `struct ${name} : public BaseCollectionModifierData {};\n`;
    out += `static_assert(sizeof(${name}) == 0x14, "${name} size mismatch");\n\n`;
}

fs.writeFileSync("src/include/black/PSysProperties.h", out);
console.log(`Generated ${atoms.length} atom + ${collections.length} collection = ${atoms.length + collections.length} types`);
