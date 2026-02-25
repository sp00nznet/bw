#!/usr/bin/env node
const { execSync } = require('child_process');
const fs = require('fs');
const path = require('path');

// Use forward slashes - node handles them fine on Windows
const I6COMP = 'C:/Windows/SysWOW64/UniExtract/bin/i6comp.exe';
const cabPath = process.argv[2];
const outDir = process.argv[3] || './extracted';

if (!cabPath) {
    console.log('Usage: node extract_all_v4.js <cab_path> <output_dir>');
    process.exit(1);
}

const absCab = path.resolve(cabPath);
const absOut = path.resolve(outDir);

// Get listing using bash (since we're running from git bash)
console.log('Getting file listing...');
const listing = execSync(`"${I6COMP}" l "${absCab}"`, {
    encoding: 'utf8',
    maxBuffer: 10 * 1024 * 1024
});

// Debug: show a sample line
const sampleLines = listing.split('\n').filter(l => l.match(/^\d{2}-\d{2}/));
if (sampleLines.length > 0) {
    console.log('Sample line:', JSON.stringify(sampleLines[0]));
}

const files = [];
for (let line of listing.split('\n')) {
    line = line.replace(/\r/g, '');
    // Match: "MM-DD-YYYY HH:MM   size  attr   compsize  idx, vol  filename"
    const m = line.match(/^(\d{2}-\d{2}-\d{4})\s+(\d{2}:\d{2})\s+(\d+)\s+(\S+)\s+(\d+)\s+(\d+),\s*(\d+)\s+(.+)$/);
    if (m) {
        files.push({
            origSize: parseInt(m[3]),
            index: parseInt(m[6]),
            volume: parseInt(m[7]),
            name: m[8].trim()
        });
    }
}

console.log(`Found ${files.length} files`);
fs.mkdirSync(absOut, { recursive: true });

let success = 0, skipped = 0, failed = 0;
const errors = [];

for (const file of files) {
    const targetPath = path.join(absOut, file.name);
    const targetDir = path.dirname(targetPath);
    fs.mkdirSync(targetDir, { recursive: true });

    // Skip existing correct-size files
    if (fs.existsSync(targetPath)) {
        try {
            if (fs.statSync(targetPath).size === file.origSize) {
                skipped++;
                if ((success + skipped + failed) % 100 === 0)
                    console.log(`  ${success + skipped + failed}/${files.length} (${success} new, ${skipped} skip, ${failed} fail)`);
                continue;
            }
        } catch (e) {}
    }

    const tmpDir = path.join(absOut, `__tmp_${file.index}`);
    try {
        fs.mkdirSync(tmpDir, { recursive: true });
        // Extract single file by index
        execSync(`cd "${tmpDir}" && "${I6COMP}" e "${absCab}" ${file.index}`, {
            encoding: 'utf8',
            timeout: 120000,
            stdio: 'pipe'
        });

        const extracted = fs.readdirSync(tmpDir);
        if (extracted.length > 0) {
            const srcFile = path.join(tmpDir, extracted[0]);
            if (fs.existsSync(targetPath)) {
                try { fs.chmodSync(targetPath, 0o666); } catch(e) {}
                fs.unlinkSync(targetPath);
            }
            fs.renameSync(srcFile, targetPath);
            success++;
        } else {
            failed++;
            if (errors.length < 30) errors.push(`${file.index}: ${file.name} - empty`);
        }
    } catch (e) {
        failed++;
        if (errors.length < 30) errors.push(`${file.index}: ${file.name} - ${e.message.split('\n')[0].substring(0, 80)}`);
    }
    try { fs.rmSync(tmpDir, { recursive: true, force: true }); } catch(e) {}

    if ((success + skipped + failed) % 100 === 0)
        console.log(`  ${success + skipped + failed}/${files.length} (${success} new, ${skipped} skip, ${failed} fail)`);
}

console.log(`\nDone! ${success} new, ${skipped} existed, ${failed} failed (${files.length} total)`);
if (errors.length > 0) {
    console.log('Errors:');
    errors.forEach(e => console.log(`  ${e}`));
}
