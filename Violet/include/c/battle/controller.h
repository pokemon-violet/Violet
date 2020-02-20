#ifndef H_BATTLE_CONTROLLER
#define H_BATTLE_CONTROLLER

#include "types.h"
#include "constants/battle/battle_actions.h"

/**
 * Battle controller callback that waits for the player to choose an action (move, item, switch, run)
 **/
void battle_controller_player_choose_action();

/**
 * Battle controller callback that waits for the player to choose a move.
 **/
void battle_controller_player_choose_move();

/**
 * Battle controller callback that waits for dma3 to finish and then continues to letting the player choose a move.
 **/
void battle_controller_player_choose_move_after_dma3();

/**
 * Battle controller callback that initializes choosing a move for the player.
 **/
void battle_controller_player_initialize_choose_move();

/**
 * Battle controller callback that waits for the player to switch moves.
 **/
void battle_controller_player_switch_moves();


/** 
 * Battler controller callback that waits for the player to choose a target.
 **/
void battle_controller_player_choose_target();

/**
 * Taken from pokeemerald.
 **/ 
void battle_controller_emit_get_pokemon_data(u8 buffer_idx, u8 request_idx, u8 battler_idx);

/**
 * Emits two return values for the battle controler.
 * @param buffer_idx
 * @param arg1 the first value to emit
 * @param arg2 the second value to emit
 **/
void battle_controller_emit_two_values(u8 buffer_idx, u8 arg1, u16 arg2);

/**
 * Marks a battler such that is executed by the battle controller.
 * @param battler_idx the battler to mark.
 **/
void battler_mark_for_controller_execution(u8 battler_idx);

#define BOUNCE_EFFECT_BATTLER 0
#define BOUNCE_EFFECT_HEALTHBAR 1

/**
 * Applies the bounce effect to an oam.
 * @param battler_idx the slot to apply the effect to
 * @param target which bounce effec to apply
 * @param ?
 * @param ?
 **/
void battle_bounce_effect(u8 battler_idx, u8 target, u8, u8);

u8 battle_selected_action[4];

extern void (*battle_controllers[4])();

#endif