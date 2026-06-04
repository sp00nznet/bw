/* test_mp2 — decode a raw MPEG Layer II payload (as stored in BW SAD banks,
 * WAVE_FORMAT_MPEG / tag 0x0050) to a PCM .wav using kjmp2, and report stats.
 *
 * Usage: test_mp2 <input.mp2> [output.wav]
 *
 * This exercises the exact kjmp2 frame loop used by sad_loader.cpp's
 * DecodeMP2ToPcmWav, against real game data, without needing a window/audio. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "third_party/kjmp2.h"

static unsigned char *slurp(const char *path, long *out_size) {
    FILE *f = fopen(path, "rb");
    if (!f) return NULL;
    fseek(f, 0, SEEK_END);
    long sz = ftell(f);
    fseek(f, 0, SEEK_SET);
    unsigned char *buf = (unsigned char *)malloc((size_t)sz + KJMP2_MAX_FRAME_SIZE);
    if (!buf) { fclose(f); return NULL; }
    fread(buf, 1, (size_t)sz, f);
    memset(buf + sz, 0, KJMP2_MAX_FRAME_SIZE); /* pad for tail frame */
    fclose(f);
    *out_size = sz;
    return buf;
}

static void put32(unsigned char *p, unsigned int v) { memcpy(p, &v, 4); }
static void put16(unsigned char *p, unsigned short v) { memcpy(p, &v, 2); }

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s <input.mp2> [output.wav]\n", argv[0]);
        return 2;
    }
    long size = 0;
    unsigned char *mpeg = slurp(argv[1], &size);
    if (!mpeg) { fprintf(stderr, "cannot read %s\n", argv[1]); return 1; }

    const unsigned char *p = mpeg, *end = mpeg + size;
    while (p < end && kjmp2_get_sample_rate(p) == 0) ++p;
    int rate = (p < end) ? kjmp2_get_sample_rate(p) : 0;
    if (!rate) { fprintf(stderr, "no valid MP2 frame found\n"); free(mpeg); return 1; }

    kjmp2_context_t ctx;
    kjmp2_init(&ctx);

    /* Grow a PCM buffer (interleaved stereo int16). */
    size_t cap = (size_t)(size / 100 + 1) * KJMP2_SAMPLES_PER_FRAME * 2;
    short *pcm = (short *)malloc(cap * sizeof(short));
    size_t n_pcm = 0;
    int frames = 0;
    short frame[KJMP2_SAMPLES_PER_FRAME * 2];
    while (p < end) {
        unsigned long n = kjmp2_decode_frame(&ctx, p, frame);
        if (n < 4) break;
        if (n_pcm + KJMP2_SAMPLES_PER_FRAME * 2 > cap) {
            cap *= 2;
            pcm = (short *)realloc(pcm, cap * sizeof(short));
        }
        memcpy(pcm + n_pcm, frame, sizeof(frame));
        n_pcm += KJMP2_SAMPLES_PER_FRAME * 2;
        ++frames;
        p += n;
    }

    printf("rate=%d Hz, frames=%d, samples/ch=%zu, seconds=%.2f\n",
           rate, frames, n_pcm / 2, (double)(n_pcm / 2) / rate);

    if (argc >= 3 && n_pcm) {
        unsigned int data_bytes = (unsigned int)(n_pcm * sizeof(short));
        unsigned char h[44];
        memcpy(h, "RIFF", 4);   put32(h + 4, 36 + data_bytes);
        memcpy(h + 8, "WAVE", 4);
        memcpy(h + 12, "fmt ", 4); put32(h + 16, 16);
        put16(h + 20, 1); put16(h + 22, 2);
        put32(h + 24, (unsigned int)rate); put32(h + 28, (unsigned int)rate * 4);
        put16(h + 32, 4); put16(h + 34, 16);
        memcpy(h + 36, "data", 4); put32(h + 40, data_bytes);
        FILE *o = fopen(argv[2], "wb");
        if (o) { fwrite(h, 1, 44, o); fwrite(pcm, sizeof(short), n_pcm, o); fclose(o);
                 printf("wrote %s (%u PCM bytes)\n", argv[2], data_bytes); }
    }
    free(pcm); free(mpeg);
    return frames > 0 ? 0 : 1;
}
