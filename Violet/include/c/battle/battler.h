/*
 * battler.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_BATTLE_BATTLER_H_
#define INCLUDE_C_BATTLE_BATTLER_H_

#include <stdbool.h>
#include "types.h"
#include "pokemon/virtual.h"
#include "constants/battle/battle_statuses.h"
#include "constants/battle/battle_positions.h"
#include "constants/pokemon_stat_names.h"

typedef struct battler {
    u16 species;
    u16 stats[5];
    u16 moves[4];
    u32 ivs;
    u8 stat_changes[8];
    u8 ability;
    u8 type1;
    u8 type2;
    u8 field_23;
    u8 current_pp[4];
    u16 current_hp;
    u8 level;
    u8 happiness;
    u16 max_hp;
    u16 item;
    u8 name[11];
    u8 trigger;
    u8 ot[8];
    u32 custom_status; //to apply hacks
    pid_t pid;
    u32 status1;
    u32 status2;
    u32 tid;
} battler;

typedef struct battler_status{
    u32 protect : 1;
    u32 endure : 1;
    u32 out_of_moves : 1;
    u32 helping_hand : 1;
    u32 bounce : 1;
    u32 steal : 1;
    u32 bit_6 : 1;
    u32 immobility : 1;
    u32 hurt_in_confusion : 1;
    u32 target_unaffected : 1;
    u32 charging : 1;
    u32 flee : 2;
    u32 used_imprisoned_move : 1;
    u32 love_immobility : 1;
    u32 used_disabled_move : 1;
    u32 used_taunted_move : 1;
    u32 bit_10 : 1;
    u32 flinched : 1;
    u32 not_first_strike : 1;
	int physical_damage;
	int special_damage;
	u8 physical_damage_battler;
	u8 special_damage_battler;
} battler_status;


typedef struct  {
    u32 pid;
    u16 disabled_move;
    u16 encore_move;
    u8 protect;
    u8 stockpile_counter;
    u8 substitue_hp;
    u8 disable_timer : 4;
    u8 disable_timer_start : 4;
    u8 encored_move_idx;
    u8 field_0xd;
    u8 encore_timer : 4;
    u8 encore_timer_start : 4;
    u8 perish_song_timer : 4;
    u8 perish_song_timer_start : 4;
    u8 furry_cutter_timer;
    u8 rollout_timer : 4;
    u8 rollout_timer_start : 4;
    u8 charge_timer : 4;
    u8 charge_timer_start : 4;
    u8 taunt_timer : 4;
    u8 taunt_timer_2 : 4;
    u8 prevents_escape;
    u8 cant_miss;
    u8 is_first_turn;
    u8 field_0x17;
    u8 truant_counter : 1;
    u8 truant_switch_in_hack : 1;
    u8 filler_18_2 : 2;
    u8 mimicked_moves : 4;
    u8 recharge_timer;
    u8 field_0x1a;
    u8 field_0x1b;
} battler_disable_t;

extern battler_disable_t battler_disable[4];

typedef struct battler_damage_taken_stru {
	u8 stat_dropped : 1;
	u8 lighting_rod : 1;
	u8 restored_sprite : 1;
	u8 intimdated_foe : 1;
	u8 traced : 1;
	u8 pp_unaffected_by_pressure : 1;
	u8 bit_6;
	u8 used_focus_band : 1;
	int damage;
	int physical_damage;
	int special_damage;
	u8 physical_damage_battler;
	u8 special_damage_battler;
} battler_damage_taken_stru;

typedef struct {
    u8 reflect_turns;
    u8 reflect_battler_idx;
    u8 lightscreen_turns;
    u8 lightscreen_battler_idx;
    u8 mist_turns;
    u8 mist_battler_idx;
    u8 safeguard_turns;
    u8 safeguard_battler_idx;
    u8 follow_me_turns;
    u8 follow_me_target_battler_idx;
    u8 spikes_layers;
    u8 field_B;
} battle_side_timer_stru;

typedef struct {
	u16 reflect : 1;
	u16 lightscreen : 1;
	u16 status_2 : 1;
	u16 status_3 : 1;
	u16 status_spikes : 1;
	u16 status_safeguard : 1;
	u16 status_future_sight : 1;
	u16 status_mist : 1;
	u16 status_spikes_damaged : 1;
} battle_side_status_stru;

typedef struct {
	u8 future_sight_turns[4];
	u8 future_sight_attacking_battler_idx[4];
	int future_sight_damage[4];
	u16 future_sight_move[4];
	u8 wish_turns[4];
	u8 wish_target[4];
	u8 weather_turns;
	u8 knocked_off[2]; // One entry per side, bit per battler
	u8 field_2B;
} battler_timer_stru;

extern battler battlers[4];
extern battler_status battler_statuses[4];
extern battler_damage_taken_stru battler_damage_taken[4];
extern battle_side_timer_stru battle_side_timers[2];
extern battle_side_status_stru battle_side_statuses[2];
extern battler_timer_stru battler_timers;
extern u8 battlers_absent;
extern u8 battler_in_party_menu;
extern u8 effect_battler;

#define DAMAGE_CAUSED ((battler_damage_taken[defending_battler].physical_damage != 0 || battler_damage_taken[defending_battler].special_damage != 0))


#define BATTLER_CAN_SWITCH_OUT(i) (\
    (battlers[i].status2 & (STATUS2_ESCAPE_PREVENTATION | STATUS2_WRAPPED)) == 0 && \
    (battler_statuses3[i] & STATUS3_ROOTED) == 0 \
)



extern u8 attack_targets;
extern u8 attacking_battler;
extern u8 defending_battler;
extern u8 defending_battler_ability;
extern u8 active_battler;
extern u8 battler_oams[];
extern u8 battler_cnt;
// extern u16 battler_party_idxs[4]; Removed - instead use battler_idx_to_party_idx to account for reorderings...
extern u8 battler_attacking_order[];
extern u32 battler_statuses3[4];
extern u8 item_target_battler;
extern u8 battler_positions[4];
extern u16 battler_last_landed_move[4];

#define STAT_CHANGE_MULTIPLIER_DIVIDEND 0
#define STAT_CHANGE_MULTIPLIER_DIVISOR 1
extern u8 battle_stat_change_multipliers[][2];

#define STAT_CHANGE_APPLY_MULTIPLIER(value, stat)(((value) * battle_stat_change_multipliers[stat][STAT_CHANGE_MULTIPLIER_DIVIDEND]) / battle_stat_change_multipliers[stat][STAT_CHANGE_MULTIPLIER_DIVISOR])

#define OPPONENT(battler_idx) ((battler_idx) ^ 1)
#define PARTNER(battler_idx) ((battler_idx) ^ 2)
#define SIDE(battler_idx) ((battler_idx) & 1)

#define BATTLE_SIDE_PLAYER 0
#define BATTLE_SIDE_OPPONENT 1

#define OWNER_PLAYER 0
#define OWNER_TRAINER_A 1
#define OWNER_ALLY 2
#define OWNER_TRAINER_B 3

/**
 * Returns the owner of a battler.
 * @param battler_idx the battler to check ownership of
 * @return the owner of the battler
 **/
u8 battler_get_owner(u8 battler_idx);

extern u8 battler_action_chosen[4];

/**
 * Checks if a battler is an opponent
 * @param index The battler index
 * @return Whether the battler is an opponent
 */
bool battler_is_opponent(u8 index);


#define ALIVE_EXCEPT_ACTIVE_BATTLER 0
#define ALIVE_ATTACKING_SIDE 1
#define ALIVE_DEFENDING_SIDE 2

/**
 * Counts the battlers alive for a side (i.e. in double battles).
 * @param side the side for which to count battlers alive (see above)
 * @return num_alive the number of battlers alive
 */
u8 battlers_alive(int side);


/**
 * Gets the position of a battler.
 * @param battler_idx the index of the battler
 * @return position position of the battler
 */
u8 battler_get_position(u8 battler_idx);

/**
 * Gets the idx of a battler at a certain position.
 * @param position the position to get
 * @return the battler idx
 **/
u8 battler_get_by_position(u8 position);

/**
 * Gets the effective speed of a battler, considering paralysis, items, abilities, etc.
 * @return the effective speed value of the battler
 */
int battler_get_effective_speed(u8 battler_idx);

/**
 * Loads a pokemon from the player party as a battler.
 * @param battler_idx into which battler slot to load the pokemon
 * @param party_idx which pokemon of the player party to load
 **/
void battler_load_from_player_party(u8 battler_idx, u8 party_idx);

/**
 * Gets the trainer name of a battler.
 * @param battler_idx the battler to get the trainer name of
 * @dst where to put the name
 **/
void battler_get_trainer_name (u8 battler_idx, u8 *dst);

/**
 * Loads the gfx and palette of a battler, but does not apply the updates. Adjusts y-position of the sprite.
 * @param battler_idx the battler to load
 * @param load_battler if false, subsititue sprite will be loaded instead
 * @param oam_idx the oam to load into
 **/
void battler_load_gfx(u8 battler_idx,u8 load_battler_gfx,u8 oam_idx);

/**
 * Updates the species and stats of a battler.
 * @param battler_idx the battler to update.
 * @param species the species to set.
 **/
void battler_form_change(u8 battler_idx, u16 species);

/**
 * Callback that loads the sprite of a battler to an oam (and removes it from BG2).
 * @param self self-reference
 **/
void battle_animation_battler_gfx_to_oam(u8 self);

/**
 * Gets the multiplayer idx associated with a battler.
 * @param battler_idx the battler
 * @return the associated multiplayer idx
 **/
u8 battler_get_multiplayer_idx(u8 battler_idx);

/**
 * Checks if a link trainer is at the flank of the battle field.
 * @param multiplayer_idx the link trainer to check
 * @return if the trainer is at the flank (i.e. right side for player, left side for opp.)
 **/
bool link_trainer_is_at_flank(u8 multiplayer_idx);

/**
 * Loads the idxs of all battlers relative to a certain battler
 * @param battler the battler to get idxs relative to
 * @param partner partner of battler, if present (else battler)
 * @param foe battler that opposes battler
 * @param foe_partner battler that is the partner of opposing foe (if present, else foe)
 **/
void battler_get_partner_and_foes(u8 battler, u8 *partner, u8 *foe, u8 *foe_partner);

/**
 * Gets the relative priority the oam associated with a battler should be initialized with.
 * @param battler_idx the battler to get the priority of
 * @return the relative priority of the oam to create
 **/
u8 battler_oam_get_relative_priority(u8 battler_idx);

/**
 * Clears fury cutter, destiny bond and grudge for a battler.
 * @param battler_idx the battler to clear the statuses of
 **/
void battler_remove_fury_cutter_destiny_bond_grudge(u8 battler_idx);

/**
 * Gets the party idx of a battler, accounting for reorderings.
 * @param battler_idx the battler idx
 * @return party_idx of the battler, accounting for reorderings.
 **/
u8 battler_idx_to_party_idx(u8 battler_idx);

/**
 * Gets the trainer idx of a battler, or 0xFFFF, if not trainer is associated with the battler.
 * @param battler_idx the battler
 * @return the trainer using the battler
 **/
u16 trainer_idx_by_battler_idx(u8 battler_idx);

/**
 * Checks if a battler is alive, or rather if it is present in the battle at all.
 * @param battler_idx the battler to check
 * @return if the battler is present in the battle
 **/
bool battler_is_alive(u8 battler_idx);

/**
 * Clears *all* battle releated data of the active battler, i.e. after fainting
 **/
void battle_clear_active_battler_data();

enum
{
    BATTLER_COORD_X,
    BATTLER_COORD_Y,
    BATTLER_COORD_X_2,
    BATTLER_COORD_Y_PIC_OFFSET,
    BATTLER_COORD_Y_PIC_OFFSET_DEFAULT,
};

/**
 * Gets the position of a battler
 * @param battler_idx the battler to get the position of
 * @param type which coordinate to get
 * @return the coordiante
 **/
u8 battler_get_coordinate(u8 battler_idx, u8 type);


#endif /* INCLUDE_C_BATTLE_BATTLER_H_ */
