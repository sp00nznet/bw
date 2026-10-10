const fs = require("fs");
const text = fs.readFileSync("vendor/bw1-decomp/black/PSysProperties.h", "utf8");
const re = /struct (\w+)\s*\{[^}]*struct (\w+) super;[^}]*\};\s*static_assert\(sizeof\(struct \w+\) == (0x[0-9a-fA-F]+)/g;
let m;
const results = [];
while ((m = re.exec(text)) != null) {
    results.push({name: m[1], base: m[2], size: m[3]});
}
console.log(JSON.stringify(results, null, 2));
console.error("Total: " + results.length);
