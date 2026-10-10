import struct, sys
d = open(sys.argv[1], "rb").read()
print("RIFF" , d[:4], "WAVE", d[8:12],
      "tag", struct.unpack_from("<H", d, 20)[0],
      "ch", struct.unpack_from("<H", d, 22)[0],
      "rate", struct.unpack_from("<I", d, 24)[0],
      "bits", struct.unpack_from("<H", d, 34)[0],
      "data_bytes", struct.unpack_from("<I", d, 40)[0],
      "file_bytes", len(d))
# peak amplitude sanity (is there real signal, not silence?)
import array
pcm = array.array("h"); pcm.frombytes(d[44:])
peak = max(abs(x) for x in pcm) if pcm else 0
print("peak_amplitude", peak, "of 32767")
