/*
 * header.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_MAP_HEADER_H_
#define INCLUDE_C_MAP_HEADER_H_

#include "map/footer.h"
#include "map/levelscript.h"
#include "map/connection.h"
#include "map/header.h"
#include "map/event.h"

typedef struct map_header_t {
    map_footer_t *footer;
    map_event_header_t *events;
    levelscript_header_t *levelscripts;
    map_connection_header_t *connections;
    u16 music;
    u16 footer_idx; //main table is used when map is loaded
    u8 map_namespace;
    u8 flash_type;
    u8 weather;
    u8 type;
    u8 bike_usable;
    u8 show_name;
    s8 level;
    u8 battle_style;

} map_header_t;

int dungeon_get_type();

extern map_header_t **mapbanks[];
extern map_header_t mapheader_virtual;

/**
 * Gets a mapheader by the current bank and map id
 * @param bank the desired bank
 * @param map the desired map id
 * @return the mapheader object
 */
map_header_t *get_mapheader(u8 bank, u8 map);

/**
 * Checks if the current map is 40.0
 * @return if the current map is in bank 40 the and has map id 0
 */
bool map_is_x40_x0();

/**
 * Returns the idx of a warp on a certain map or -1 if there is no warp.
 * @param map the map to check on
 * @param position the position where the warp is required to be
 * @return the warp idx or -1 if there is no warp
 */
s8 map_get_warp_idx_by_position(map_header_t *map, position_t *position);

/**
 * Returns the signpost at a certain position.
 * @param map at which map to find the signpost
 * @param x the x coordinate, not +7 shifted
 * @param y the y coordiante, not +7 shifted
 * @param level the level on which the event is supposed to be on
 * @return the event or NULL if none was found
 **/
map_event_signpost *map_get_signpost_by_position(map_header_t *map, s16 x, s16 y, u8 level);

/**
 * Checks if a map type represents an outside map.
 * @param map_type the map type
 * @return if the map represents an outside map
 */
bool map_type_is_outside (u8 map_type);

/**
 * Checks if the virtual map header is a cloud map.
 * @return if the map is a cloud map
 **/
bool map_is_cloud();

/**
 * Plays the current map song if it is not already playing, i.e. after surfing or biking.
 **/
void map_current_play_song_if_not_playing();


#endif /* INCLUDE_C_MAP_HEADER_H_ */
