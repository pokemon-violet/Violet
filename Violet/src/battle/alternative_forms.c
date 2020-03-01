#include "types.h"
#include "battle/battler.h"
#include "save.h"
#include "mega.h"
#include "pokemon/virtual.h"
#include "constants/pokemon_attributes.h"


void battle_alternative_forms_revert() {
    for (int i = 0; i < player_pokemon_cnt; i++) {
        u16 species = (u16) pokemon_get_attribute(player_pokemon + i, ATTRIBUTE_SPECIES, 0);
        mega_evolution_t *mega_evolution = mega_evolution_get_by_mega_species(species);
        if (mega_evolution) {
            pokemon_set_attribute(player_pokemon + i, ATTRIBUTE_SPECIES, &(mega_evolution->species));
            pokemon_calculate_stats(player_pokemon + i);
        }
    }
}