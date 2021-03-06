#include "types.h"
#include "map/wild_pokemon.h"
#include "constants/wild_pokemon_densities.h"
#include "constants/species.h"

wild_pokemon_entry wild_pokemon_route_9_clouds_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 29, .level_max = 31, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 28, .level_max = 31, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 28, .level_max = 31, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 28, .level_max = 31, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 28, .level_max = 31, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 28, .level_max = 31, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 29, .level_max = 32, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 30, .level_max = 34, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_PELIPPER},
};

wild_pokemon_habitat wild_pokemon_route_9_clouds_grass = {
	.frequency = 2, .data = wild_pokemon_route_9_clouds_grass_entries
};