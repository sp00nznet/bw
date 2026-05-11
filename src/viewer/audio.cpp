// Tiny audio shim — see audio.h.

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

#include "audio.h"

#include <black/LHVMObjects.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

namespace bw {
namespace audio {

namespace {

std::string g_intro_path;
bool        g_have_intro = false;
bool        g_music_on   = false;
DWORD       g_last_sfx_ms = 0;

void OnPlaySound(int32_t sound_id, float /*x*/, float /*y*/, float /*z*/) {
    // PlaySound is synchronous-ish but we use SND_ASYNC. Rate-limit so a
    // script spamming sounds doesn't stall the audio thread or beep wildly.
    DWORD now = GetTickCount();
    if (now - g_last_sfx_ms < 30) return;
    g_last_sfx_ms = now;

    // Map sound id to a system MessageBeep tone for variety. The original
    // LH_SAMPLE table is hundreds of entries; this is purely a placeholder
    // until the SAD parser lands.
    UINT tone;
    switch (sound_id % 5) {
    case 0: tone = MB_OK; break;
    case 1: tone = MB_ICONASTERISK; break;
    case 2: tone = MB_ICONEXCLAMATION; break;
    case 3: tone = MB_ICONHAND; break;
    default: tone = MB_ICONQUESTION; break;
    }
    MessageBeep(tone);
}

void OnStopSound(int32_t /*sound_id*/) {
    // Single-channel MessageBeep cannot be stopped mid-flight, so this is
    // a no-op. PlaySound(NULL, ...) below covers the music path.
}

void OnMusic(int32_t /*music_id*/, bool start) {
    if (start && g_have_intro) {
        PlaySoundA(g_intro_path.c_str(), nullptr,
                   SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
        g_music_on = true;
    } else if (!start && g_music_on) {
        PlaySoundA(nullptr, nullptr, 0);
        g_music_on = false;
    }
}

} // namespace

void Init(const std::string& game_data_dir) {
    if (g_have_intro) return;
    g_intro_path = game_data_dir;
    if (!g_intro_path.empty() &&
        g_intro_path.back() != '/' && g_intro_path.back() != '\\') {
        g_intro_path += '/';
    }
    g_intro_path += "intro.wav";

    FILE* f = fopen(g_intro_path.c_str(), "rb");
    if (f) {
        fclose(f);
        g_have_intro = true;
        printf("Audio: intro.wav located at %s — will play on first music event\n",
               g_intro_path.c_str());
    } else {
        printf("Audio: intro.wav not found at %s — music events will be silent\n",
               g_intro_path.c_str());
    }
    fflush(stdout);
}

void RegisterLHVMHooks() {
    lhvm::g_audio_play_sound_func = OnPlaySound;
    lhvm::g_audio_stop_sound_func = OnStopSound;
    lhvm::g_audio_music_func      = OnMusic;
}

void Shutdown() {
    if (g_music_on) {
        PlaySoundA(nullptr, nullptr, 0);
        g_music_on = false;
    }
}

} // namespace audio
} // namespace bw
