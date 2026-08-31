// Attribute — the creature's vocabulary for describing the world.
//
// Translated from runblack_decrypted.exe (v1.0), vtable slot 10 of each of the
// 24 Attribute classes (work/decomp/creature_ai.txt, schema in
// work/decomp/attributes.json). Every body in the binary has the same shape:
//
//     this->value = <some feature of the object>;
//     if (this->value > GetNumValues() - 1) this->value = GetNumValues() - 1;
//     return this->value;
//
// so Store() below is that tail, written once. Only the feature differs, and
// the feature is what each comment records.
//
// The thresholds are the interesting part and they are all verbatim: a creature
// counts a town as "big" at 40 buildings, a forest as "big" at 20 trees, and
// treats anything above 20% health as alive. Those numbers are why the creature
// behaves the way it does, so none of them are rounded or guessed.

#include "black/Attribute.h"

#include "black/Creature.h"
#include "black/GameThingWithPos.h"
#include "black/Player.h"

namespace {

AttributeWorld g_world;

}  // namespace

void SetAttributeWorld(const AttributeWorld& w) { g_world = w; }
const AttributeWorld& GetAttributeWorld() { return g_world; }

uint32_t Attribute::Store(uint32_t v) {
    const uint32_t last = GetNumValues() ? GetNumValues() - 1 : 0;
    value = v > last ? last : v;
    return value;
}

// --- abstract base (vftable 0x80e550) -------------------------------------

const char* Attribute::GetName() const { return "NULL"; }        // sub_4B1DF0
uint32_t Attribute::GetNumValues() const { return 0; }           // sub_4017D0
const char* Attribute::GetValueName(uint32_t) const {
    // sub_4B1E00 returns "NULL"; the concrete classes index a 64-byte-stride
    // string table that only the in-game debug overlay reads, so the tables are
    // left in the binary rather than transcribed.
    return "NULL";
}
uint32_t Attribute::Evaluate(GameThingWithPos*, Creature*) { return 0; }  // nullsub_54
ATTRIBUTE_TYPE Attribute::GetAttributeType() const { return ATTRIBUTE_TYPE_ERROR; }
bool Attribute::IsConcrete() const { return false; }

// -------------------------------------------------------------------------
// Boilerplate for the constant slots. Everything except Evaluate is a constant
// return in the binary too, so this stays a table rather than becoming code.
// -------------------------------------------------------------------------
#define BW_ATTR_CONST(Cls, NameStr, Values, Type, Concrete)               \
    const char* Cls::GetName() const { return NameStr; }                  \
    uint32_t Cls::GetNumValues() const { return Values; }                 \
    ATTRIBUTE_TYPE Cls::GetAttributeType() const { return Type; }         \
    bool Cls::IsConcrete() const { return Concrete; }

BW_ATTR_CONST(AttributeAllegiance, "Allegiance", 3, ATTRIBUTE_TYPE_ALLEGIANCE, true)
BW_ATTR_CONST(AttributeIsHarderThanMe, "IsHarderThanMe", 2, ATTRIBUTE_TYPE_HARDER_THAN_ME, true)
BW_ATTR_CONST(AttributeCreatureType, "CreatureType", 17, ATTRIBUTE_TYPE_CREATURE_TYPE, true)
BW_ATTR_CONST(AttributeLife, "Life", 2, ATTRIBUTE_TYPE_LIFE, true)
BW_ATTR_CONST(AttributeTownReligiousBeliefInYou, "Belief", 4, ATTRIBUTE_TYPE_RELIGIOUS_BELIEF_IN_YOU, true)
BW_ATTR_CONST(AttributeWhatTownNeedsMost, "NeedsMost", 17, ATTRIBUTE_TYPE_TOWN_NEEDS_MOST, true)
BW_ATTR_CONST(AttributeCreatureDominantDesire, "Desire", 41, ATTRIBUTE_TYPE_CREATURE_DOMINANT_DESIRE, true)
BW_ATTR_CONST(AttributeCreatureHeight, "Height", 4, ATTRIBUTE_TYPE_CREATURE_HEIGHT, true)
BW_ATTR_CONST(AttributeCreatureSpellKnowledge, "Spell", 43, ATTRIBUTE_TYPE_CREATURE_SPELL_KNOWLEDGE, true)
BW_ATTR_CONST(AttributeCreatureWhatHeIsCarrying, "Carrying", 45, ATTRIBUTE_TYPE_CREATURE_CARRYING, true)
BW_ATTR_CONST(AttributeForestSize, "Size", 3, ATTRIBUTE_TYPE_FOREST_SIZE, true)
BW_ATTR_CONST(AttributeAbodeBeingBuilt, "BeingBuilt", 2, ATTRIBUTE_TYPE_ABODE_BEING_BUILT, true)
BW_ATTR_CONST(AttributeOnFire, "OnFire", 2, ATTRIBUTE_TYPE_ABODE_ON_FIRE, true)

BW_ATTR_CONST(AttributeOrigin, "Origin", 3, ATTRIBUTE_TYPE_ORIGIN, false)
BW_ATTR_CONST(AttributeAnimate, "Animate", 2, ATTRIBUTE_TYPE_ANIMATE, false)
BW_ATTR_CONST(AttributePlayerNumber, "PlayerNumber", 8, ATTRIBUTE_TYPE_PLAYER_NUMBER, false)
BW_ATTR_CONST(AttributeType, "Type", 24, ATTRIBUTE_TYPE_TYPE, false)
BW_ATTR_CONST(AttributeTribe, "Tribe", 9, ATTRIBUTE_TYPE_TRIBE, false)
BW_ATTR_CONST(AttributeTownSize, "Size", 3, ATTRIBUTE_TYPE_TOWN_SIZE, false)
BW_ATTR_CONST(AttributeVillagerJob, "None", 17, ATTRIBUTE_TYPE_VILLAGER_JOB, false)
BW_ATTR_CONST(AttributeSex, "None", 2, ATTRIBUTE_TYPE_SEX, false)
BW_ATTR_CONST(AttributeMobileObjectType, "Type", 32, ATTRIBUTE_TYPE_MOBILE_OBJECT_TYPE, false)
BW_ATTR_CONST(AttributeAbodeType, "AbodeType", 24, ATTRIBUTE_TYPE_ABODE_TYPE, false)

#undef BW_ATTR_CONST

// -------------------------------------------------------------------------
// Evaluate
//
// Where the feature is reachable through GameThing's own virtuals it is wired
// straight through; where it needs an info block, a town's internals or the
// creature's mental state it goes via AttributeWorld, because guessing those
// would put invented numbers behind real-looking thresholds.
// -------------------------------------------------------------------------

// sub_4B6E90: is this thing on someone else's side? Zero when it belongs to the
// observing creature's own player.
uint32_t AttributeAllegiance::Evaluate(GameThingWithPos* obj, Creature* observer) {
    if (!obj) return Store(0);
    GPlayer* owner = obj->GetPlayer();
    GPlayer* mine = observer ? observer->GetPlayer() : nullptr;
    return Store(mine != owner ? 1u : 0u);
}

// sub_4B76B0: compare the two creatures' physical size.
uint32_t AttributeIsHarderThanMe::Evaluate(GameThingWithPos* obj, Creature* observer) {
    Creature* them = obj ? obj->CastCreature() : nullptr;
    if (!them || !observer) return Store(0);
    return Store(observer->GetRadius() < them->GetRadius() ? 1u : 0u);
}

// sub_4B7750: species, read off the creature's info block.
uint32_t AttributeCreatureType::Evaluate(GameThingWithPos* obj, Creature*) {
    Creature* c = obj ? obj->CastCreature() : nullptr;
    return Store(c && g_world.creature_type ? g_world.creature_type(c) : 0u);
}

// sub_4B6F70: "alive" is not a flag, it is a threshold -- anything above 20%
// health counts.
uint32_t AttributeLife::Evaluate(GameThingWithPos* obj, Creature*) {
    return Store(obj && obj->GetLife() > 0.2f ? 1u : 0u);
}

// sub_4B7030: how much this town believes in the observing creature's god,
// bucketed at 0.2 / 0.4 / 0.6.
uint32_t AttributeTownReligiousBeliefInYou::Evaluate(GameThingWithPos* obj, Creature* observer) {
    if (!obj || !observer || !g_world.town_belief_in) return Store(0);
    const float belief = g_world.town_belief_in(obj, observer);
    if (belief < 0.2f) return Store(0);
    if (belief < 0.4f) return Store(1);
    if (belief < 0.6f) return Store(2);
    return Store(3);
}

uint32_t AttributeWhatTownNeedsMost::Evaluate(GameThingWithPos* obj, Creature*) {  // sub_4B70E0
    return Store(obj && g_world.town_needs_most ? g_world.town_needs_most(obj) : 0u);
}

uint32_t AttributeCreatureDominantDesire::Evaluate(GameThingWithPos* obj, Creature*) {  // sub_4B71C0
    Creature* c = obj ? obj->CastCreature() : nullptr;
    return Store(c && g_world.creature_dominant_desire
                     ? g_world.creature_dominant_desire(c) : 0u);
}

// sub_4B7240: size, bucketed at 0.25 / 0.75 / 1.25 -- infant, juvenile, adult,
// and whatever is bigger than that.
uint32_t AttributeCreatureHeight::Evaluate(GameThingWithPos* obj, Creature*) {
    Creature* c = obj ? obj->CastCreature() : nullptr;
    if (!c) return Store(0);
    const float h = c->GetRadius();
    if (h < 0.25f) return Store(0);
    if (h < 0.75f) return Store(1);
    if (h < 1.25f) return Store(2);
    return Store(3);
}

uint32_t AttributeCreatureSpellKnowledge::Evaluate(GameThingWithPos* obj, Creature*) {  // sub_4B72E0
    Creature* c = obj ? obj->CastCreature() : nullptr;
    return Store(c && g_world.creature_spell_knowledge
                     ? g_world.creature_spell_knowledge(c) : 0u);
}

// sub_4B7350: what is in its hands, as an object type. Empty hands is bucket
// 29 -- a real entry in the table, not a sentinel.
uint32_t AttributeCreatureWhatHeIsCarrying::Evaluate(GameThingWithPos* obj, Creature*) {
    Creature* c = obj ? obj->CastCreature() : nullptr;
    if (!c || !g_world.creature_carrying) return Store(29);
    return Store(g_world.creature_carrying(c));
}

// sub_4B73C0: trees plus saplings, bucketed at 10 and 20.
uint32_t AttributeForestSize::Evaluate(GameThingWithPos* obj, Creature*) {
    if (!obj || !g_world.forest_size) return Store(0);
    const uint32_t trees = g_world.forest_size(obj);
    if (trees < 10) return Store(0);
    if (trees < 20) return Store(1);
    return Store(2);
}

// sub_4B7590: note the inversion -- a finished building is bucket 1.
uint32_t AttributeAbodeBeingBuilt::Evaluate(GameThingWithPos* obj, Creature*) {
    return Store(obj && obj->IsFunctional() ? 0u : 1u);
}

// sub_4B75F0
uint32_t AttributeOnFire::Evaluate(GameThingWithPos* obj, Creature* observer) {
    return Store(obj && obj->IsOnFire(observer) ? 1u : 0u);
}

// --- the ones the trees do not branch on ----------------------------------

uint32_t AttributeOrigin::Evaluate(GameThingWithPos* obj, Creature*) {          // sub_4B6ED0
    return Store(obj && g_world.origin ? g_world.origin(obj) : 0u);
}

uint32_t AttributeAnimate::Evaluate(GameThingWithPos* obj, Creature*) {         // sub_4B6F00
    return Store(obj && obj->IsAnimate() ? 1u : 0u);
}

// sub_4B7640: unowned things read as player 7, the neutral slot.
uint32_t AttributePlayerNumber::Evaluate(GameThingWithPos* obj, Creature*) {
    GPlayer* p = obj ? obj->GetPlayer() : nullptr;
    return Store(p ? p->GetPlayerNumber() : 7u);
}

uint32_t AttributeType::Evaluate(GameThingWithPos* obj, Creature*) {            // sub_4B6F30
    return Store(obj ? obj->GetScriptObjectType() : 0u);
}

uint32_t AttributeTribe::Evaluate(GameThingWithPos* obj, Creature*) {           // sub_4B6FE0
    return Store(obj && g_world.town_tribe ? g_world.town_tribe(obj) : 0u);
}

// sub_4B7150: abodes plus villagers, bucketed at 20 and 40.
uint32_t AttributeTownSize::Evaluate(GameThingWithPos* obj, Creature*) {
    if (!obj || !g_world.town_population) return Store(0);
    const uint32_t size = g_world.town_population(obj);
    if (size < 20) return Store(0);
    if (size < 40) return Store(1);
    return Store(2);
}

uint32_t AttributeVillagerJob::Evaluate(GameThingWithPos* obj, Creature*) {     // sub_4B7430
    return Store(obj && g_world.villager_job ? g_world.villager_job(obj) : 0u);
}

uint32_t AttributeSex::Evaluate(GameThingWithPos* obj, Creature*) {             // sub_4B74A0
    return Store(obj && g_world.villager_sex ? g_world.villager_sex(obj) : 0u);
}

uint32_t AttributeMobileObjectType::Evaluate(GameThingWithPos* obj, Creature*) { // sub_4B74F0
    return Store(obj && g_world.mobile_object_type ? g_world.mobile_object_type(obj) : 0u);
}

uint32_t AttributeAbodeType::Evaluate(GameThingWithPos* obj, Creature*) {       // sub_4B7540
    return Store(obj && g_world.abode_type ? g_world.abode_type(obj) : 0u);
}

// -------------------------------------------------------------------------
// The registry. One instance each, as the original keeps: attributes are
// stateless apart from the last value they computed, so the decision trees
// share them rather than allocating per test.
// -------------------------------------------------------------------------
namespace {

AttributeAllegiance                 s_allegiance;
AttributeOrigin                     s_origin;
AttributeAnimate                    s_animate;
AttributePlayerNumber               s_player_number;
AttributeIsHarderThanMe             s_harder_than_me;
AttributeCreatureType               s_creature_type;
AttributeType                       s_type;
AttributeLife                       s_life;
AttributeTribe                      s_tribe;
AttributeTownReligiousBeliefInYou   s_belief;
AttributeWhatTownNeedsMost          s_needs_most;
AttributeTownSize                   s_town_size;
AttributeCreatureDominantDesire     s_dominant_desire;
AttributeCreatureHeight             s_height;
AttributeCreatureSpellKnowledge     s_spell_knowledge;
AttributeCreatureWhatHeIsCarrying   s_carrying;
AttributeForestSize                 s_forest_size;
AttributeVillagerJob                s_villager_job;
AttributeSex                        s_sex;
AttributeMobileObjectType           s_mobile_type;
AttributeAbodeType                  s_abode_type;
AttributeAbodeBeingBuilt            s_being_built;
AttributeOnFire                     s_on_fire;

Attribute* const s_by_type[] = {
    &s_allegiance, &s_origin, &s_animate, &s_player_number, &s_harder_than_me,
    &s_creature_type, &s_type, &s_life, &s_tribe, &s_belief, &s_needs_most,
    &s_town_size, &s_dominant_desire, &s_height, &s_spell_knowledge,
    &s_carrying, &s_forest_size, &s_villager_job, &s_sex, &s_mobile_type,
    &s_abode_type, &s_being_built, &s_on_fire,
};
static_assert(sizeof(s_by_type) / sizeof(s_by_type[0]) == _ATTRIBUTE_TYPE_COUNT,
              "attribute registry must cover every ATTRIBUTE_TYPE");

}  // namespace

Attribute* GetAttribute(ATTRIBUTE_TYPE type) {
    if (type >= _ATTRIBUTE_TYPE_COUNT) return nullptr;
    return s_by_type[type];
}
