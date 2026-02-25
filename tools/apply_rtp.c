// apply_rtp.c — Apply an RTPatch (.rtp) binary patch file
// Uses patchw32.dll from InstallShield
//
// Usage: apply_rtp.exe <patch.rtp> <base_dir> [flags]
// patchw32.dll must be in the same directory as this exe

#include <windows.h>
#include <stdio.h>

typedef unsigned int (__stdcall *RTPatchApply32_t)(const char* cmdline, void* callback, BOOL wait);
typedef unsigned int (__stdcall *RTPatchApply32NoCall_t)(const char* cmdline);

int main(int argc, char* argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: apply_rtp.exe <patch.rtp> <base_dir> [extra_flags]\n");
        fprintf(stderr, "  Extra flags: -n (no prompt), -noCHK (no checksum)\n");
        return 1;
    }

    HMODULE dll = LoadLibraryA("patchw32.dll");
    if (!dll) {
        fprintf(stderr, "Error: Could not load patchw32.dll (error %lu)\n", GetLastError());
        return 1;
    }

    // Try NoCall variant which writes to stdout
    RTPatchApply32NoCall_t applyNoCall = (RTPatchApply32NoCall_t)GetProcAddress(dll, "RTPatchApply32NoCall");
    RTPatchApply32_t apply = (RTPatchApply32_t)GetProcAddress(dll, "RTPatchApply32@12");

    // Build full command line: patchfile basedir [flags]
    char cmdline[4096];
    int pos = snprintf(cmdline, sizeof(cmdline), "%s %s", argv[1], argv[2]);
    for (int i = 3; i < argc && pos < (int)sizeof(cmdline) - 100; i++) {
        pos += snprintf(cmdline + pos, sizeof(cmdline) - pos, " %s", argv[i]);
    }

    fprintf(stderr, "Cmd: %s\n", cmdline);
    fprintf(stderr, "ApplyNoCall: %p  Apply@12: %p\n", (void*)applyNoCall, (void*)apply);
    fflush(stderr);

    unsigned int result;
    if (applyNoCall) {
        fprintf(stderr, "Using RTPatchApply32NoCall...\n");
        fflush(stderr);
        result = applyNoCall(cmdline);
    } else {
        fprintf(stderr, "Using RTPatchApply32@12...\n");
        fflush(stderr);
        result = apply(cmdline, NULL, TRUE);
    }

    fprintf(stderr, "Result: 0x%X (%u)\n", result, result);
    fflush(stderr);

    FreeLibrary(dll);
    return (result != 0 && result > 31) ? 1 : 0;
}
