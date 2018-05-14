/*
 * virtual.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_POKEMON_VIRTUAL_H_
#define INCLUDE_C_POKEMON_VIRTUAL_H_

typedef struct marking {
    u8 circle : 1;
    u8 square : 1;
    u8 triangle : 1;
    u8 heart : 1;
    u8 padding : 4;
} marking;

typedef union {
    u32 value;

    struct {
        u32 ability : 1;
        u32 gender_partial : 7;
        u32 shinyness : 16;
        u32 nature : 5;
        u32 form : 3;
    } fields;
} pid;

typedef struct pokemon {
    pid pid;
    u32 tid;
    u8 nickname [10];
    u16 language;
    u8 ot_name [7];
    marking markings;
    u16 checksum;
    u16 padding;
    u16 encrypted_substructure [24];
    u32 status_condition;
    u8 level;
    u8 pokerus_remaining_byte;
    u16 current_hp;
    u16 total_hp;
    u16 attack;
    u16 defense;
    u16 speed;
    u16 sattack;
    u16 sdefense;

} pokemon;


pokemon *player_pokemon = (pokemon*) 0x02024284;
pokemon *opponent_pokemon = (pokemon*) 0x0202402C;

/**
 * Gets the attribute of a virtual pokemon
 * @param p The offset of the virtual pokemon
 * @param requested_attribute Id of the attribute to get
 * @param result Storage for the result if it is no scalar type (pass 0 otherwise)
 */
int pokemon_get_attribute(pokemon* p, int requested_attribute, void *result);

/**
 * Sets the attribute of a virtual pokemon
 * @param p The offset of the virutal pokemon
 * @param requested_attribute Id of the attribute to set
 * @param value Pointer to the value to apply
 */
void pokemon_set_attribute(pokemon* p, int requested_attribute, void* value);


/**
 * Calculates the stats of a pokemon.
 * @param p Pokemon to calculate the stats of
 */
void pokemon_calculate_stats(pokemon *p);

/**
 * Gets the number of pokemon in the player's party
 * @return The number of pokemon in the player's party
 */
u8 pokemon_get_number_in_party();

void pokemon_load_name_as_string(pokemon *pokemon, u8 *buffer);
void pokemon_new(pokemon *space, u16 species, u8 level, u8 ev_split,
        bool pid_determined, pid pid, bool tid_determined, u32 tid);
u16 pokemon_append_attack(pokemon *p, u16 attack);
void pokemon_rotate_and_push_attack(pokemon *p, u16 attack);
void pokemon_spawn_by_seed_algorithm(pokemon *p, u16 species, u8 level, u8 ev_spread, bool tid_determined, u32 tid, u16(*seed_generator)());
u8 get_pokemons_ability(pokemon *poke);
u8 write_ability_into_dbuf(pokemon *poke);
void special_heal_team_index();
void pokemon_team_remove();
void pokemon_team_knows_hm();
bool pokemon_knows_hm(pokemon *p);

/**
 * Heals all pokemon in the player's party
 */
void pokemon_heal_player_party();

/**
 *
 * @param p
 * @return 0 := male, 0xFE := female i guess? 0xFF := no gender at all
 */
u8 pokemon_get_gender(pokemon *p);

u8 pokemon_get_nature(pokemon *target);

#endif /* INCLUDE_C_POKEMON_VIRTUAL_H_ */