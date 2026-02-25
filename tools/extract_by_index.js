#!/usr/bin/env node
// Extract all files from InstallShield CAB by parsing the file listing
// and extracting each file individually by its index number

const { execSync } = require('child_process');
const fs = require('fs');
const path = require('path');

const I6COMP = '/c/Windows/SysWOW64/UniExtract/bin/i6comp';
const cabPath = process.argv[2];
const outDir = process.argv[3] || './extracted';

if (!cabPath) {
    console.log('Usage: node extract_by_index.js <cab_path> <output_dir>');
    process.exit(1);
}

// First, get the file listing
console.log('Getting file listing...');
const listing = execSync(`"${I6COMP}" l "${cabPath}"`, { encoding: 'utf8', maxBuffer: 10 * 1024 * 1024 });

// Parse the listing to get index -> filename mapping
const files = [];
for (const line of listing.split('\n')) {
    // Format: "date time size attr compsize index,vol filename"
    const match = line.match(/^\d{2}-\d{2}-\d{4}\s+\d{2}:\d{2}\s+\d+\s+\S+\s+\d+\s+(\d+),\s*(\d+)\s+(.+)$/);
    if (match) {
        files.push({
            index: parseInt(match[1]),
            volume: parseInt(match[2]),
            name: match[3].trim()
        });
    }
}

console.log(`Found ${files.length} files in listing`);

// Create output directory structure
fs.mkdirSync(outDir, { recursive: true });

let success = 0;
let failed = 0;
const errors = [];

for (const file of files) {
    const targetDir = path.join(outDir, path.dirname(file.name));
    fs.mkdirSync(targetDir, { recursive: true });

    // Make target writable if it exists
    const targetPath = path.join(outDir, file.name);
    try {
        if (fs.existsSync(targetPath)) {
            fs.chmodSync(targetPath, 0o666);
        }
    } catch (e) {}

    try {
        // Extract to a temp dir then move
        const tmpDir = path.join(outDir, '__tmp_extract');
        fs.mkdirSync(tmpDir, { recursive: true });

        execSync(`cd "${tmpDir}" && "${I6COMP}" e "${path.resolve(cabPath)}" ${file.index}`, {
            encoding: 'utf8',
            timeout: 30000,
            stdio: 'pipe'
        });

        // Find what was extracted in tmpDir
        const extracted = fs.readdirSync(tmpDir);
        if (extracted.length > 0) {
            const srcFile = path.join(tmpDir, extracted[0]);
            if (fs.existsSync(targetPath)) {
                fs.chmodSync(targetPath, 0o666);
                fs.unlinkSync(targetPath);
            }
            fs.renameSync(srcFile, targetPath);
            success++;
        }

        // Clean up tmp
        fs.rmSync(tmpDir, { recursive: true, force: true });
    } catch (e) {
        failed++;
        errors.push(`${file.index}: ${file.name} - ${e.message.split('\n')[0]}`);
    }

    if ((success + failed) % 50 === 0) {
        console.log(`Progress: ${success + failed}/${files.length} (${success} ok, ${failed} failed)`);
    }
}

console.log(`\nDone! ${success} extracted, ${failed} failed out of ${files.length}`);
if (errors.length > 0 && errors.length <= 20) {
    console.log('\nErrors:');
    errors.forEach(e => console.log(`  ${e}`));
}
