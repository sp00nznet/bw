// Flock class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Flock manages groups of animals. Simple methods at 0x0052f8xx
// are packed 16 bytes apart (trivial returns).

#include <black/Flock.h>
#include <black/Living.h>

// ============================================================================
// Overrides of Base virtuals
// ============================================================================

void Flock::ToBeDeleted(int /*param*/) {
    // Original at 0x0052ffb0 — complex
}

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

Town* Flock::GetTown() {
    // Original at 0x0052fb00: return *(this + 0x34)
    return town;
}

char* Flock::GetDebugText() {
    static char text[] = "Flock";
    return text;
}

uint32_t Flock::Load(GameOSFile* /*file*/) {
    // Original at 0x00530930 — complex serialization
    return 0;
}

uint32_t Flock::Save(GameOSFile* /*file*/) {
    // Original at 0x005305a0 — complex serialization
    return 0;
}

uint32_t Flock::GetSaveType() {
    // Original at 0x005059e0
    return 0x7e;
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

uint32_t Flock::GetCreatureBeliefType() {
    // Original at 0x0066f560
    return 0x16;
}

uint32_t Flock::GetCreatureBeliefListType() {
    // Original at 0x0052f8b0
    return 0;
}

bool Flock::IsActivityObjectWhichAngerAppliesTo(Creature* /*creature*/) {
    // Original at 0x0052f8d0: returns true
    return true;
}

bool Flock::IsActivityObjectWhichCompassionAppliesTo(Creature* /*creature*/) {
    // v1.0 vslot 113: return 0 (checked by test_chooser)
    return false;
}

bool Flock::IsActivityObjectWhichPlayfulnessAppliesTo(Creature* /*creature*/) {
    // Original at 0x0052f8f0: returns true
    return true;
}

bool32_t Flock::IsSuitableForCreatureActivity() {
    // Original at 0x0052f8c0: returns 1
    return 1;
}

bool32_t Flock::IsFlock() const {
    // Original at 0x0052f860: returns 1
    return 1;
}

bool32_t Flock::IsScriptContainer() const {
    // Original at 0x0052f880: returns 1
    return 1;
}

const char* Flock::GetText() {
    // Original at 0x0052f890
    return "Flock";
}

uint32_t Flock::GetScriptObjectType() {
    // Original at 0x006fc980
    return 0xb;
}

// ============================================================================
// Non-virtual methods
// ============================================================================

// The flock's position is its domain centre; the last member is sent there.
void Flock::SetDomainCentrePos(const MapCoords& pos) {
    if (tail && tail->living) static_cast<MobileWallHug*>(tail->living)->goal = pos;
    coords = pos;
}

// ponytail: the game's flock list (+2104576) is the level loader's.
void Flock::Init(const MapCoords& pos, uint32_t id_) {
    leader = nullptr; town = nullptr; citadel_heart = nullptr;
    head = tail = cursor = nullptr; count = 0;
    field_0x4c = field_0x54 = field_0x58 = field_0x5c = field_0x7c = field_0x80 = field_0x84 = 0;
    max_count = 0;
    field_0x78 = 43;  // sub_506330
    id = id_;
    SetDomainCentrePos(pos);
    start_pos = field_0x6c = pos;
    domain_radius = 80;
    radius_b = 30;
}

// A member leaves its old flock first (and is no longer that flock's
// leader); the node goes in before the first member whose +0xD4 byte is at
// least the newcomer's, else at the end.
bool Flock::AddMember(Living* l) {
    for (Node* n = head; n; n = n->next) if (n->living == l) return false;
    if (Flock* old = l->flock) {
        if (old != this && old->leader == l) old->leader = nullptr;
        old->RemoveMember(l, true);  // sub_5ABA40
    }
    const auto key = [](Living* m) { return static_cast<uint8_t>(m->field_0xd4); };
    Node* node = new Node{nullptr, nullptr, l};
    bool placed = false;
    for (Node* i = head; i && !placed; i = i->next) {
        if (key(i->living) < key(l)) continue;
        placed = true;
        node->prev = i->prev;
        node->next = i;
        if (head == i) head = node; else i->prev->next = node;
        i->prev = node;
        cursor = node;
    }
    if (!placed) {
        if (tail) { tail->next = node; node->prev = tail; } else head = node;
        tail = cursor = node;
    }
    ++count;
    l->flock = this;  // sub_5ACEC0
    return true;
}

bool Flock::RemoveMember(Living* l, bool delete_if_empty) {
    Node* n = head;
    while (n && n->living != l) n = n->next;
    l->flock = nullptr;
    if (!n) return false;
    if (n->prev) n->prev->next = n->next; else head = n->next;
    if (n->next) n->next->prev = n->prev; else tail = n->prev;
    cursor = n->prev ? n->prev : head;
    delete n;
    --count;
    if (!count && delete_if_empty) ToBeDeleted(0);  // vslot 3
    return true;
}

MapCoords* Flock::GetFlockPos() {
    // Original at 0x00530570 — complex
    return &coords;  // ponytail: the domain centre, not the members' average
}
