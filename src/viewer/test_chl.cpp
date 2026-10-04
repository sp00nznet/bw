// test_chl — the shipped challenge script loads and runs, headless and timed:
// LoadBinary, the auto-start scripts, then VM ticks. Needs game_data/Quests.
#include <black/LHVM.h>
#include <black/LHVMObjects.h>

#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <string>

static double Now() {
    using namespace std::chrono;
    return duration<double>(steady_clock::now().time_since_epoch()).count();
}

int main() {
    const char* roots[] = {"game_data/", "../game_data/", "../../game_data/", "../../../game_data/"};
    std::string path;
    for (const char* r : roots) {
        std::string p = std::string(r) + "Quests/Challenge.chl";
        if (FILE* f = std::fopen(p.c_str(), "rb")) { std::fclose(f); path = p; break; }
    }
    if (path.empty()) { printf("note: game_data/Quests/Challenge.chl not reachable; skipped\n"); return 0; }

    LHVM* vm = static_cast<LHVM*>(std::calloc(1, sizeof(LHVM)));
    double t = Now();
    if (!vm->LoadBinary(path.c_str())) { printf("FAIL: LoadBinary\n"); return 1; }
    printf("ok  : LoadBinary %.2fs: %u instructions, %u scripts, %u auto-start\n",
           Now() - t, vm->instruction_count, vm->script_count, vm->auto_start_count);
    lhvm::SetActiveLHVM(vm);

    t = Now();
    for (uint32_t i = 0; i < vm->auto_start_count; i++) vm->StartScriptByID(vm->auto_start_scripts[i]);
    printf("ok  : auto-start scripts started %.2fs\n", Now() - t);

    t = Now();
    for (int tick = 0; tick < 100; ++tick) {
        vm->ProcessTick();
        if (Now() - t > 20) { printf("FAIL: tick %d still running after 20s\n", tick); return 1; }
    }
    printf("ok  : 100 ticks %.2fs\n", Now() - t);
    printf("\nall passed\n");
    return 0;
}
