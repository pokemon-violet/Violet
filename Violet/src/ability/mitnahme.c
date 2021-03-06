#include "types.h"
#include "stdbool.h"
#include "constants/abilities.h"
#include "pokemon/virtual.h"
#include "constants/items.h"
#include "constants/pokemon_attributes.h"
#include "battle/battlescript.h"
#include "prng.h"

u16 mitnahme_items[10][11] = {
  //1, 1, 3, 3, 3, 3, 3, 3, 5, 10, 30 in %
    {ITEM_NUGGET, ITEM_HYPERTRANK, ITEM_HYPERBALL, ITEM_HYPERTRANK, ITEM_PARA_HEILER, ITEM_FLUCHTSEIL, ITEM_SCHUTZ, ITEM_SUPERBALL, ITEM_SUPERTRANK, ITEM_GEGENGIFT, ITEM_TRANK},
    {ITEM_KING_STEIN, ITEM_NUGGET, ITEM_BELEBER, ITEM_HYPERBALL, ITEM_HYPERTRANK, ITEM_PARA_HEILER, ITEM_FLUCHTSEIL, ITEM_SCHUTZ, ITEM_SUPERBALL, ITEM_SUPERTRANK, ITEM_GEGENGIFT},
    {ITEM_TOP_GENESUNG, ITEM_KING_STEIN, ITEM_NUGGET, ITEM_BELEBER, ITEM_HYPERBALL, ITEM_HYPERTRANK, ITEM_PARA_HEILER, ITEM_FLUCHTSEIL, ITEM_SCHUTZ, ITEM_SUPERBALL, ITEM_SUPERTRANK},
    {ITEM_TOP_GENESUNG, ITEM_KING_STEIN, ITEM_AETHER, ITEM_SONDERBONBON, ITEM_BELEBER, ITEM_HYPERBALL, ITEM_HYPERTRANK, ITEM_PARA_HEILER, ITEM_FLUCHTSEIL, ITEM_SCHUTZ, ITEM_SUPERBALL},
    {ITEM_TOP_GENESUNG, ITEM_KING_STEIN, ITEM_AETHER, ITEM_SONDERBONBON, ITEM_RIESENPILZ, ITEM_BELEBER, ITEM_HYPERBALL, ITEM_HYPERTRANK, ITEM_PARA_HEILER, ITEM_FLUCHTSEIL, ITEM_SCHUTZ},
    {ITEM_SONNENSTEIN, ITEM_MONDSTEIN, ITEM_SONDERBONBON, ITEM_TOP_GENESUNG, ITEM_AETHER, ITEM_RIESENPILZ, ITEM_BELEBER, ITEM_HYPERBALL, ITEM_HYPERTRANK, ITEM_PARA_HEILER, ITEM_FLUCHTSEIL},
    {ITEM_HERZSCHUPPE, ITEM_SONNENSTEIN, ITEM_MONDSTEIN, ITEM_SONDERBONBON, ITEM_TOP_GENESUNG, ITEM_AETHER, ITEM_RIESENPILZ, ITEM_BELEBER, ITEM_HYPERBALL, ITEM_HYPERTRANK, ITEM_PARA_HEILER},
    {ITEM_TOP_BELEBER, ITEM_HERZSCHUPPE, ITEM_SONNENSTEIN, ITEM_MONDSTEIN, ITEM_SONDERBONBON, ITEM_TOP_GENESUNG, ITEM_AETHER, ITEM_RIESENPILZ, ITEM_BELEBER, ITEM_HYPERBALL, ITEM_HYPERTRANK},
    {ITEM_UEBERRESTE, ITEM_TOP_BELEBER, ITEM_HERZSCHUPPE, ITEM_SONNENSTEIN, ITEM_MONDSTEIN, ITEM_SONDERBONBON, ITEM_TOP_GENESUNG, ITEM_AETHER, ITEM_RIESENPILZ, ITEM_BELEBER, ITEM_HYPERBALL},
    {ITEM_GLUECKS_EI, ITEM_UEBERRESTE, ITEM_TOP_BELEBER, ITEM_HERZSCHUPPE, ITEM_SONNENSTEIN, ITEM_MONDSTEIN, ITEM_SONDERBONBON, ITEM_TOP_GENESUNG, ITEM_AETHER, ITEM_RIESENPILZ, ITEM_BELEBER}
    
};

u16 *mitnahme_pick_item(pokemon *p){
    int l = (pokemon_get_attribute(p, ATTRIBUTE_LEVEL, 0)-1) / 10;
    int r = rnd16() % 100;
    if(r < 1) return &mitnahme_items[l][0];
    if(r < 2) return &mitnahme_items[l][1];
    if(r < 5) return &mitnahme_items[l][2];
    if(r < 10) return &mitnahme_items[l][3];
    if(r < 20) return &mitnahme_items[l][4];
    if(r < 30) return &mitnahme_items[l][5];
    if(r < 40) return &mitnahme_items[l][6];
    if(r < 60) return &mitnahme_items[l][7];
    if(r < 70) return &mitnahme_items[l][8];
    return &mitnahme_items[l][9];
}

void bsc_cmd_mitnahme(){
    
    int i;
    for (i = 0; i < 6; i++){
        if(!pokemon_get_attribute(&player_pokemon[i], ATTRIBUTE_ITEM, 0) && 
                !pokemon_get_attribute(&player_pokemon[i], ATTRIBUTE_IS_EGG, 0) &&
                pokemon_get_ability(&player_pokemon[i]) == MITNAHME &&
                rnd16() % 10){
            //Trigger 'Mitnahme' on this pokemon
            pokemon_set_attribute(&player_pokemon[i], ATTRIBUTE_ITEM, mitnahme_pick_item(&player_pokemon[i]));
        }
    }
    bsc_offset++;
}
