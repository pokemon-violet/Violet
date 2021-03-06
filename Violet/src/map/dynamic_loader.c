#include "types.h"
#include "oam.h"
#include "callbacks.h"
#include "save.h"
#include "map/header.h"
#include "dungeon/dungeon2.h"
#include "constants/vars.h"
#include "vars.h"


map_header_t *get_mapheader(u8 bank, u8 map) {
    if (dungeon_get_type() && bank == DG2_BANK && map == DG2_MAP) {
        dungeon2_init();
        return &(fmem.dmapheader);
    } else {
        return mapbanks[bank][map];
    }
}

map_footer_t *get_mapfooter() {

    if (dungeon_get_type()) {
        dungeon2_init();
        return &(fmem.dmapfooter);
    }

    //return standard map header
    u16 current_footer = save1->current_footer_id;
    if (current_footer) {
        return mapfooters[current_footer - 1];
    }
    return (map_footer_t*) 0;
}

int dungeon_get_type() {
    u16 *dtype = var_access(DUNGEON_TYPE);
    return *dtype;
}
