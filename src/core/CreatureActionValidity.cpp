// CreatureActionValidity — see black/CreatureActionValidity.h. Each case is
// the predicate at that v1.0 address, as decompiled (work: the action table's
// +16 entries, recovered by work/gen_chooser_dispatch.py).
#include <black/CreatureActionValidity.h>
#include <black/CreatureDesire.h>
#include <black/CreatureDispatch.gen.h>

namespace creature {

namespace {

// sub_464BB0: done in the last `seconds`, counting its turns in whole seconds.
bool Recent(const CreatureFacts& f, uint32_t action, float seconds) {
    const uint32_t turns = f.action_count[action];
    const uint32_t per_second = f.turn_ms ? 1000u / f.turn_ms : 10u;
    return turns && static_cast<double>(turns / (per_second ? per_second : 1)) < seconds;
}

// sub_4B5FE0, shared by the 47 spell actions: the spell is charged to at
// least half, the player allows it, and its cost is affordable.
bool SpellReady(const CreatureFacts& f, uint32_t t) {
    if (t == 0 || t >= 42) return false;
    if (f.spell_charge[t] <= 1.0f && f.spell_charge[t] < 0.5f) return false;
    if (f.spell_forbidden[t]) return false;
    return f.can_cast[t];
}

bool Since(const CreatureFacts& f, uint32_t turns) { return f.turn - f.last_social_turn > turns; }

}  // namespace

namespace {

// 1 / 0, or -1 for an address with no translation.
int Eval(uint32_t action, uint32_t t, const ActionPlan& plan, const CreatureFacts& f) {
    if (action >= 328) return -1;
    switch (kActionValidityFn[action]) {
    case 0: return true;  // no predicate
    case 0x4B5FE0: return SpellReady(f, t);
    case 0x4B6190: return f.stage >= 8 && SpellReady(f, t);      // the power-up casts
    case 0x4B61C0: return SpellReady(f, t) && f.home_distance > 150.0f;  // teleport
    case 0x4B68F0: return f.on_fire && SpellReady(f, t);           // CastMagicWater
    case 0x4B60C0:                                                  // CastImpressiveSpell
        for (uint32_t s : {14u, 10u, 16u, 11u, 24u})                // unk_906338
            if (f.knows_spell[s] && f.can_cast[s] && f.spell_charge[s] > 0.5f) return true;
        return false;
    case 0x4C5A80:                                                  // CastAmusingSpellOnCreature
        for (uint32_t s = 26; s <= 41; ++s)
            if (f.knows_spell[s] && f.can_cast[s]) return true;
        return false;
    case 0x4B6830: return f.held_spell[0];  // the held one-off spell's kind (vslots 223..226)
    case 0x4B6860: return f.held_spell[1];
    case 0x4B6890: return f.held_spell[2];
    case 0x4B68C0: return f.held_spell[3];

    case 0x4B6370: return f.has_player && f.hand_visible;           // LookAtHand
    case 0x4B6240: return !f.hand_pointing;                         // FollowPlayer, ShowPlayerAnObject
    case 0x4B6570: return f.has_player && f.hand_pointing;          // GoToMiddleOfScreen
    case 0x4B65A0: return f.has_player && f.hand_far;               // GoToHand
    case 0x4B6300: return f.has_player && f.hand_close && f.attitude < 0.0f;  // RunAwayFromPlayer
    case 0x4B6800: return f.attitude < -0.1f;                       // BeCrossWithPlayer
    case 0x4B63B0:                                                  // SleepAtHome, PrayAtCitadel
        return f.has_player && f.player_has_temple && f.home_distance < 1000.0f;
    case 0x4B6490:                                                  // SleepByObject, SleepOnTheSpot
        if (f.controlled) return true;
        return !(f.has_player && f.player_has_temple && f.home_distance <= 140.0f);
    case 0x4B6250: return f.has_citadel;                            // Steal..ToCitadel, Sacrifice

    case 0x4B62D0: return f.life > 0.1f;                            // Fight
    case 0x4B6A40: return f.fish_farm_near;                         // the fishing actions
    case 0x4C58B0: return f.others_far;                             // RestToGetBetter, RestOnTheSpot
    case 0x4B6220: return f.stage >= 3;                             // LookOutToSea, SitDownOnBeach
    case 0x4B67C0: return f.beach_near;                             // GoToBeachWithFriend
    case 0x4B66B0: return !f.night;                                 // LookAtSun
    case 0x4B66D0: return f.night;                                  // LookAtMoon
    case 0x4B6690: return !Recent(f, 75, 2.0f);                     // Scratch
    case 0x4B6670: return !Recent(f, 81, 2.0f);                     // SitDown
    case 0x4B6A00:                                                  // ShowImpressiveAnimation
        return !f.last_impressive_turn || f.turn - f.last_impressive_turn > 200;

    case 0x4828B0: return f.home_built && !(f.home_progress > 6);   // BuildHome
    case 0x4828D0: return !f.home_built;                            // CreateHome
    case 0x4B6660: return f.home_progress > 6;                      // ShowFriendHome
    case 0x4B6640: return f.home_distance > 20.0f;                  // GoHome (sub_463150)
    case 0x4B6650: return !(f.home_distance > 20.0f);               // PooAtHome

    case 0x4B6400: return f.last_social_kind != 12 && Since(f, 200);  // DanceWithVillagers
    case 0x4B6430: return f.last_social_kind != 1 && Since(f, 300);   // DancePlayfully...
    case 0x4B6460: return f.last_social_kind != 9 && Since(f, 450);   // TellVillagersAStory

    case 0x4B66E0: return f.desire[4] > 0.1f;                       // EatWithFriend (hunger)
    case 0x4B6710: return f.desire[14] > 0.1f;                      // DrinkWithFriend (water)
    case 0x4B6740: return f.desire[7] > 0.1f;                       // PooWithFriend
    case 0x4B6790: return f.desire[8] > 0.1f;                       // SleepWithFriend (tiredness)
    case 0x4B6770: return f.sadness < 0.1f;                         // BeHappyWithFriend
    case 0x4B6270: return f.friend_flag;                            // ThrowStonesInSeaWithFriend
    case 0x4B64F0: return plan.target && f.friend_wanders && f.friend_wanders(plan.target);  // FollowFriendAround
    case 0x4B6920: return f.town_near && f.town_compassion < f.town_anger;    // AttackWithFriend
    case 0x4B6990: return f.town_near && f.town_compassion >= f.town_anger;   // HelpTownWithFriend
    case 0x4B6280:                                                  // DestroyAggressor
        return plan.target && f.town_under_attack && f.town_under_attack(plan.target);
    default: return -1;
    }
}

}  // namespace

bool ActionValid(uint32_t action, uint32_t spell, const ActionPlan& plan, const CreatureFacts& f) {
    return Eval(action, spell, plan, f) == 1;
}

bool ValidityTranslated(uint32_t action) {
    return Eval(action, 0, ActionPlan(), CreatureFacts()) != -1;
}

}  // namespace creature
