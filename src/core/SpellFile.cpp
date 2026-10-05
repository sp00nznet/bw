// SpellFile — see black/SpellFile.h.
#include <black/SpellFile.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>

namespace psys {

// --- inflate ------------------------------------------------------------------
namespace {

struct Bits {
    const uint8_t* p;
    size_t n, pos = 0;
    uint32_t buf = 0;
    int cnt = 0;
    bool bad = false;
    int Get(int need) {
        while (cnt < need) {
            if (pos >= n) { bad = true; return 0; }
            buf |= static_cast<uint32_t>(p[pos++]) << cnt;
            cnt += 8;
        }
        const int v = static_cast<int>(buf & ((1u << need) - 1));
        buf >>= need;
        cnt -= need;
        return v;
    }
};

struct Huff {
    uint16_t count[16] = {};
    uint16_t symbol[320] = {};
    void Build(const uint8_t* len, int n) {
        std::memset(count, 0, sizeof count);
        for (int i = 0; i < n; ++i) ++count[len[i]];
        count[0] = 0;
        uint16_t offs[16] = {};
        for (int i = 1; i < 16; ++i) offs[i] = static_cast<uint16_t>(offs[i - 1] + count[i - 1]);
        for (int i = 0; i < n; ++i) if (len[i]) symbol[offs[len[i]]++] = static_cast<uint16_t>(i);
    }
    int Decode(Bits& b) const {  // canonical codes, read a bit at a time
        int code = 0, first = 0, index = 0;
        for (int l = 1; l < 16; ++l) {
            code |= b.Get(1);
            const int c = count[l];
            if (code - c < first) return symbol[index + (code - first)];
            index += c;
            first = (first + c) << 1;
            code <<= 1;
        }
        b.bad = true;
        return -1;
    }
};

const uint16_t kLenBase[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 15, 17, 19, 23, 27, 31, 35, 43, 51, 59, 67, 83, 99, 115, 131, 163, 195, 227, 258};
const uint8_t kLenExtra[] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 0};
const uint16_t kDistBase[] = {1, 2, 3, 4, 5, 7, 9, 13, 17, 25, 33, 49, 65, 97, 129, 193, 257, 385, 513, 769, 1025, 1537, 2049, 3073, 4097, 6145, 8193, 12289, 16385, 24577};
const uint8_t kDistExtra[] = {0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13};

bool Codes(Bits& b, const Huff& lit, const Huff& dist, std::vector<uint8_t>* out) {
    for (;;) {
        const int s = lit.Decode(b);
        if (b.bad || s < 0) return false;
        if (s < 256) { out->push_back(static_cast<uint8_t>(s)); continue; }
        if (s == 256) return true;
        const int li = s - 257;
        if (li >= 29) return false;
        const int len = kLenBase[li] + b.Get(kLenExtra[li]);
        const int di = dist.Decode(b);
        if (b.bad || di < 0 || di >= 30) return false;
        const size_t d = kDistBase[di] + static_cast<size_t>(b.Get(kDistExtra[di]));
        if (d > out->size()) return false;
        for (int i = 0; i < len; ++i) out->push_back((*out)[out->size() - d]);
    }
}

}  // namespace

bool Inflate(const uint8_t* in, size_t n, std::vector<uint8_t>* out) {
    if (n < 2 || (in[0] & 0x0F) != 8 || ((in[0] << 8) | in[1]) % 31) return false;  // zlib header
    Bits b{in + 2, n - 2};
    int last = 0;
    do {
        last = b.Get(1);
        const int type = b.Get(2);
        if (type == 0) {  // stored
            b.buf = 0; b.cnt = 0;
            if (b.pos + 4 > b.n) return false;
            const size_t len = b.p[b.pos] | (b.p[b.pos + 1] << 8);
            b.pos += 4;
            if (b.pos + len > b.n) return false;
            out->insert(out->end(), b.p + b.pos, b.p + b.pos + len);
            b.pos += len;
        } else if (type == 1) {  // fixed Huffman
            uint8_t l[320];
            int i = 0;
            for (; i < 144; ++i) l[i] = 8;
            for (; i < 256; ++i) l[i] = 9;
            for (; i < 280; ++i) l[i] = 7;
            for (; i < 288; ++i) l[i] = 8;
            Huff lit, dist;
            lit.Build(l, 288);
            for (i = 0; i < 30; ++i) l[i] = 5;
            dist.Build(l, 30);
            if (!Codes(b, lit, dist, out)) return false;
        } else if (type == 2) {  // dynamic Huffman
            const int nlen = b.Get(5) + 257, ndist = b.Get(5) + 1, ncode = b.Get(4) + 4;
            static const uint8_t order[19] = {16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15};
            uint8_t l[320] = {};
            for (int i = 0; i < ncode; ++i) l[order[i]] = static_cast<uint8_t>(b.Get(3));
            Huff lc;
            lc.Build(l, 19);
            uint8_t lens[320] = {};
            for (int i = 0; i < nlen + ndist;) {
                const int s = lc.Decode(b);
                if (b.bad || s < 0) return false;
                if (s < 16) { lens[i++] = static_cast<uint8_t>(s); continue; }
                int rep = 0, val = 0;
                if (s == 16) { if (!i) return false; val = lens[i - 1]; rep = 3 + b.Get(2); }
                else if (s == 17) rep = 3 + b.Get(3);
                else rep = 11 + b.Get(7);
                if (i + rep > nlen + ndist) return false;
                while (rep--) lens[i++] = static_cast<uint8_t>(val);
            }
            Huff lit, dist;
            lit.Build(lens, nlen);
            dist.Build(lens + nlen, ndist);
            if (!Codes(b, lit, dist, out)) return false;
        } else {
            return false;
        }
        if (b.bad) return false;
    } while (!last);
    return true;
}

// --- properties -------------------------------------------------------------

bool Property::Bool() const { return !raw.empty() && raw[0] != "0"; }
int32_t Property::Int() const { return raw.empty() ? 0 : std::atoi(raw[0].c_str()); }
float Property::Float() const { return raw.empty() ? 0.0f : static_cast<float>(std::atof(raw[0].c_str())); }
std::string Property::Str() const { return raw.empty() || raw[0] == "NULL_STRING" ? std::string() : raw[0]; }
std::vector<float> Property::Array() const {
    std::vector<float> v;
    for (size_t i = 2; i < raw.size(); ++i) v.push_back(static_cast<float>(std::atof(raw[i].c_str())));  // after "SIZE n"
    return v;
}

const Property* SpellClass::Get(const std::string& n) const {
    auto it = props.find(n);
    return it == props.end() ? nullptr : &it->second;
}

const SpellClass* SpellFile::Find(const std::string& name) const {
    for (const SpellClass& c : classes) if (c.name == name) return &c;
    return nullptr;
}

bool SpellFile::Parse(const std::string& text) {
    header.clear();
    classes.clear();
    std::istringstream in(text);
    std::string line;
    SpellClass* cur = nullptr;
    bool in_props = false;
    while (std::getline(in, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();
        std::istringstream ls(line);
        std::string word;
        if (!(ls >> word)) continue;
        if (word == "BEGINCLASS") {
            classes.emplace_back();
            cur = &classes.back();
            ls >> cur->type >> cur->name;
        } else if (word == "ENDCLASS") {
            cur = nullptr;
        } else if (word == "BEGINPROPERTIES") {
            in_props = true;
        } else if (word == "ENDPROPERTIES") {
            in_props = false;
        } else if (word == "PROPERTY" && in_props) {
            std::string name;
            Property p;
            ls >> name >> p.type;
            for (std::string v; ls >> v;) p.raw.push_back(v);
            (cur ? cur->props : header)[name] = p;
        } else {
            return false;  // nothing else appears in these files
        }
    }
    return true;
}

bool SpellFile::Load(const std::string& path) {
    FILE* f = std::fopen(path.c_str(), "rb");
    if (!f) return false;
    std::vector<uint8_t> data;
    uint8_t buf[4096];
    for (size_t r; (r = std::fread(buf, 1, sizeof buf, f)) > 0;) data.insert(data.end(), buf, buf + r);
    std::fclose(f);
    if (data.size() < 6) return false;
    const uint32_t size = data[0] | (data[1] << 8) | (data[2] << 16) | (static_cast<uint32_t>(data[3]) << 24);
    std::vector<uint8_t> text;
    if (!Inflate(data.data() + 4, data.size() - 4, &text) || text.size() != size) return false;
    return Parse(std::string(text.begin(), text.end()));
}

}  // namespace psys
