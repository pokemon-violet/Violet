#include "types.h"
#include "map/wild_pokemon.h"
#include "constants/wild_pokemon_densities.h"
#include "constants/species.h"

wild_pokemon_entry wild_pokemon_1_0_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 16, .level_max = 20, .species = POKEMON_SAMURZEL},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 16, .level_max = 20, .species = POKEMON_KNILZ},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 16, .level_max = 20, .species = POKEMON_WAUMPEL},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 16, .level_max = 20, .species = POKEMON_MYRAPLA},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 16, .level_max = 20, .species = POKEMON_SAMURZEL},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 16, .level_max = 20, .species = POKEMON_KNILZ},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 16, .level_max = 20, .species = POKEMON_SCHALOKO},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 16, .level_max = 20, .species = POKEMON_KNILZ},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 16, .level_max = 20, .species = POKEMON_PANEKON},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 16, .level_max = 20, .species = POKEMON_PUDOX},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 16, .level_max = 20, .species = POKEMON_BLANAS},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 20, .level_max = 24, .species = POKEMON_TENGULIST},
};

wild_pokemon_habitat wild_pokemon_1_0_grass = {
	.frequency = 9, .data = wild_pokemon_1_0_grass_entries
};

wild_pokemon_entry wild_pokemon_1_0_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 35, .level_max = 35, .species = POKEMON_ENTON},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 35, .level_max = 35, .species = POKEMON_GEHWEIHER},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_GEHWEIHER},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 35, .level_max = 35, .species = POKEMON_ENTORON},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 35, .level_max = 35, .species = POKEMON_ENTORON},
};

wild_pokemon_habitat wild_pokemon_1_0_water = {
	.frequency = 10, .data = wild_pokemon_1_0_water_entries
};

wild_pokemon_entry wild_pokemon_1_0_other_entries[5] = {
	[WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] = 
		{.level_min = 20, .level_max = 25, .species = POKEMON_PARAGONI},
	[WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] = 
		{.level_min = 20, .level_max = 25, .species = POKEMON_TANNZA},
	[WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] = 
		{.level_min = 20, .level_max = 25, .species = POKEMON_KASTADUR},
	[WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] = 
		{.level_min = 20, .level_max = 25, .species = POKEMON_PARAGONI},
	[WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] = 
		{.level_min = 20, .level_max = 25, .species = POKEMON_KASTADUR},
};

wild_pokemon_habitat wild_pokemon_1_0_other = {
	.frequency = 138, .data = wild_pokemon_1_0_other_entries
};

wild_pokemon_entry wild_pokemon_1_0_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 14, .level_max = 14, .species = POKEMON_SCHMERBE},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 14, .level_max = 14, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 36, .level_max = 36, .species = POKEMON_GARADOS},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 36, .level_max = 36, .species = POKEMON_WELSAR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 36, .level_max = 36, .species = POKEMON_WELSAR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] = 
		{.level_min = 48, .level_max = 48, .species = POKEMON_WELSAR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 48, .level_max = 48, .species = POKEMON_WELSAR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 48, .level_max = 48, .species = POKEMON_GARADOS},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 55, .level_max = 55, .species = POKEMON_WELSAR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 55, .level_max = 55, .species = POKEMON_WELSAR},
};

wild_pokemon_habitat wild_pokemon_1_0_rod = {
	.frequency = 38, .data = wild_pokemon_1_0_rod_entries
};
