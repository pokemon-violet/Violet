#include "types.h"
#include "pokemon/virtual.h"
#include "map/wild_pokemon.h"
#include "save.h"
#include "constants/wild_pokemon_densities.h"
#include "debug.h"

static wild_pokemon_unown_t wild_pokemon_unowns[] = {
	{.bank = 11, .map_idx = 4, .letters = {
		UNOWN_LETTER('C'), UNOWN_LETTER('Y'), UNOWN_LETTER('H'), POKEMON_ICOGNITO_EXCLAMATION - POKEMON_EGG,
	}},
	{.bank = 6, .map_idx = 7, .letters = {
		UNOWN_LETTER('A'), UNOWN_LETTER('V'), UNOWN_LETTER('K'), POKEMON_ICOGNITO_QUESTION - POKEMON_EGG,
	}},
	{.bank = 8, .map_idx = 2, .letters = {
		UNOWN_LETTER('B'), UNOWN_LETTER('U'), UNOWN_LETTER('M'), UNOWN_LETTER('W'),
	}},
	{.bank = 9, .map_idx = 4, .letters = {
		UNOWN_LETTER('E'), UNOWN_LETTER('P'), UNOWN_LETTER('Q'), UNOWN_LETTER('J'),
	}},
	{.bank = 12, .map_idx = 7, .letters = {
		UNOWN_LETTER('D'), UNOWN_LETTER('G'), UNOWN_LETTER('I'), UNOWN_LETTER('X'),
	}},
	{.bank = 27, .map_idx = 1, .letters = {
		UNOWN_LETTER('F'), UNOWN_LETTER('Z'), UNOWN_LETTER('N'), UNOWN_LETTER('T'),
	}},
	{.bank = 0xFF, .map_idx = 0xFF},
};

u8 *wild_pokemon_get_current_unown_letters() {
    for (int i = 0; wild_pokemon_unowns[i].bank != 0xFF || wild_pokemon_unowns[i].map_idx != 0xFF; i++) {
        if (wild_pokemon_unowns[i].bank == save1->bank && wild_pokemon_unowns[i].map_idx == save1->map) {
            // dprintf("Letters located @%x\n", wild_pokemon_unowns[i].letters);
            return wild_pokemon_unowns[i].letters;
        }
    }
    return NULL;
}