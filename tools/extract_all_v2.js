#!/usr/bin/env node
// Extract all files from InstallShield CAB by parsing listing and extracting each by index
// Uses a temp directory per file to avoid overwrite issues

const { execSync } = require('child_process');
const fs = require('fs');
const path = require('path');

const I6COMP = 'C:\\Windows\\SysWOW64\\UniExtract\\bin\\i6comp.exe';
const cabPath = path.resolve(process.argv[2]);
const outDir = path.resolve(process.argv[3] || './extracted');

if (!process.argv[2]) {
    console.log('Usage: node extract_all_v2.js <cab_path> <output_dir>');
    process.exit(1);
}

// Get the file listing
console.log('Parsing file listing...');
const listing = execSync(`"${I6COMP}" l "${cabPath}"`, { encoding: 'utf8', maxBuffer: 10 * 1024 * 1024 });

const files = [];
for (const line of listing.split('\n')) {
    const match = line.match(/^\d{2}-\d{2}-\d{4}\s+\d{2}:\d{2}\s+(\d+)\s+\S+\s+\d+\s+(\d+),\s*(\d+)\s+(.+)$/);
    if (match) {
        files.push({
            origSize: parseInt(match[1]),
            index: parseInt(match[2]),
            volume: parseInt(match[3]),
            name: match[4].trim()
        });
    }
}

console.log(`Found ${files.length} files. Extracting to ${outDir}...`);
fs.mkdirSync(outDir, { recursive: true });

let success = 0;
let skipped = 0;
let failed = 0;
const errors = [];

for (const file of files) {
    // Create subdirectories for files with paths (like SFX\Creature\bape.sad)
    const targetPath = path.join(outDir, file.name.replace(/\//g, path.sep));
    const targetDir = path.dirname(targetPath);
    fs.mkdirSync(targetDir, { recursive: true });

    // Skip if already exists and is correct size
    if (fs.existsSync(targetPath)) {
        try {
            const stat = fs.statSync(targetPath);
            if (stat.size === file.origSize) {
                skipped++;
                continue;
            }
        } catch (e) {}
    }

    // Use a temp dir for extraction
    const tmpDir = path.join(outDir, '__tmp_' + file.index);
    try {
        fs.mkdirSync(tmpDir, { recursive: true });

        execSync(`cd /d "${tmpDir}" && "${I6COMP}" e "${cabPath}" ${file.index}`, {
            encoding: 'utf8',
            timeout: 60000,
            stdio: 'pipe',
            shell: 'cmd.exe'
        });

        // Find extracted file
        const extracted = fs.readdirSync(tmpDir);
        if (extracted.length > 0) {
            const srcFile = path.join(tmpDir, extracted[0]);
            // Remove target if exists
            if (fs.existsSync(targetPath)) {
                try { fs.chmodSync(targetPath, 0o666); } catch(e) {}
                fs.unlinkSync(targetPath);
            }
            fs.renameSync(srcFile, targetPath);
            success++;
        } else {
            failed++;
            errors.push(`${file.index}: ${file.name} - no output file`);
        }
    } catch (e) {
        failed++;
        if (errors.length < 30) {
            errors.push(`${file.index}: ${file.name} - ${e.message.split('\n')[0].substring(0, 100)}`);
        }
    }

    // Cleanup tmp
    try { fs.rmSync(tmpDir, { recursive: true, force: true }); } catch(e) {}

    if ((success + skipped + failed) % 100 === 0) {
        console.log(`Progress: ${success + skipped + failed}/${files.length} (${success} new, ${skipped} existing, ${failed} failed)`);
    }
}

console.log(`\nDone! ${success} extracted, ${skipped} already existed, ${failed} failed`);
console.log(`Total files in output: ${success + skipped}`);
if (errors.length > 0) {
    console.log(`\nFirst ${Math.min(errors.length, 20)} errors:`);
    errors.slice(0, 20).forEach(e => console.log(`  ${e}`));
}
