#pragma once
// CreatureActionValidity — whether a creature can do an action at all right
// now: the 47 predicates at action-table +16 (docs/creature-chooser.md).
//
// They are methods on the creature and read its state, its mind, its player
// and the world. The facts they read are gathered here, each named for where
// the binary keeps it; the logic, thresholds and comparisons are the binary's.
// A fact the host cannot supply keeps its default, which is chosen to answer
// as an idle creature with no player would.

#include <cstdint>
#include <functional>

namespace creature {

struct ActionPlan;

struct CreatureFacts {
    // The creature.
    float    life = 1.0f;                 // vslot 71 GetLife
    bool     has_player = false;          // vslot 7 GetPlayer
    bool     has_citadel = false;         // vslot 69 GetCitadel
    bool     controlled = false;          // sub_4B29D0: a player's hand is on it
    float    home_distance = 0.0f;        // metres to creature+0x1200 (home)
    uint32_t stage = 0;                   // creature+0x1268 (the mind file's +4712)
    bool     home_built = false;          // creature+0x11FC
    uint32_t home_progress = 0;           // creature+0x1210 (> 6: a home to show)
    uint32_t last_social_turn = 0;        // creature+0x10FC
    uint32_t last_social_kind = 0;        // creature+0x1100 (1, 9, 12: the last social act)
    bool     on_fire = false;             // sub_5EA110
    bool     others_far = true;           // sub_4C58C0: no creature within 8 x its vslot 267
    bool     beach_near = false;          // sub_4C1480(5, ...): a type-5 (beach) cell nearby
    bool     fish_farm_near = false;      // sub_503770: a fish farm within 600 m

    // Its player.
    bool     player_has_temple = false;   // player +608
    bool     hand_pointing = false;       // sub_461720: a hand looking at it within 400 m
    bool     hand_visible = false;        // nearest hand (sub_467290) +256 > 0
    bool     hand_close = false;          // nearest hand within 10 m of it (sub_4B6300)
    bool     hand_far = false;            // nearest hand beyond an eighth of the view (sub_4B65A0)

    // Its mind.
    float    desire[40] = {};             // mental+336
    uint32_t action_count[328] = {};      // mental+118432 (turns of each action)
    float    attitude = 0.0f;             // mental+101464 (below 0: dislikes its player)
    float    sadness = 0.0f;              // source SADNESS (48), sub_4C0930
    bool     friend_flag = false;         // mental+7140
    uint32_t last_impressive_turn = 0;    // mental+98084
    float    spell_charge[42] = {};       // mental+97592 / sub_4D82D0 (charge over its maximum)
    bool     can_cast[42] = {};           // sub_4D7910: the spell's cost is affordable
    bool     knows_spell[42] = {};        // sub_4C3F50(1, type)
    bool     spell_forbidden[42] = {};    // dword_C22148 and the player's sub_5F93C0 says no
    bool     held_spell[4] = {};          // the one-off spell it holds: aggressive, compassionate,
                                          // playful, restorative (spell seed vslots 223..226)

    // The world.
    uint32_t turn = 0;                    // game +2104060
    uint32_t turn_ms = 100;               // dword_C22D78
    bool     night = false;               // sub_528F30 (> 1.2)

    // Plan-dependent: DestroyAggressor's target town is under attack (+3748);
    // FollowFriendAround's friend is over 10 m off doing a followable action;
    // the nearest town's anger and compassion scores (sub_4CA530).
    std::function<bool(uint32_t target)> town_under_attack;
    std::function<bool(uint32_t target)> friend_wanders;
    bool  town_near = false;
    float town_anger = 0.0f, town_compassion = 0.0f;
};

// The action's +16 predicate, or true if it has none. `spell` is the action
// record's magic type (+180).
bool ActionValid(uint32_t action, uint32_t spell, const ActionPlan& plan, const CreatureFacts& f);

// Whether the action's predicate has a translation here (all 112 should).
bool ValidityTranslated(uint32_t action);

}  // namespace creature
