/*
 * cave.h
 *
 *  Created on: Jun 26, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_DUNGEON_CAVE_H_
#define INCLUDE_C_DUNGEON_CAVE_H_

#define DTYPE_CAVE_WILD_POKEMON_FREQUENCY 0x2

    #define DG2_CAVE_WIDTH 50
    #define DG2_CAVE_HEIGHT 50
    #define DG2_CAVE_PATH_RANDOMNESS 45875 //0.7
    #define DG2_CAVE_INIT_RANDOMNESS 0xA000 //0.4
    #define DG2_CAVE_NODES 12
    #define DG2_CAVE_MARGIN 5
    #define DG2_CAVE_NODE_METRIC_LAMBDA_MIN 7
    #define DG2_CAVE_NODE_METRIC_LAMBDA_MEAN 5
    #define DG2_CAVE_NODE_SAMPLES 50


	/**
	 * Receives the adjanceny pattern (bitfield representing adjacent blocks) of a block
	 * @param x the x coordinate
	 * @param y the y coordinate
	 * @param map the block map
	 * @param dg2 underlying dungeon generator instance
	 * @return the bit-battern (8-bit)
	 */
	int dungeon2_cave_get_adjacency_pattern(int x, int y, u8 *map, dungeon_generator2 *dg2);

	/**
	 * Checks if based on the adjacency pattern of a wall block it can be rendered with the
	 * standard rock tileset.
	 * @param map the map data
	 * @param x the x coordiante (0-based)
	 * @param y the y coordinate (0-based)
	 * @param dg2 the underlying dungeon generator instance
	 * @return if the block at x, y can be drawn as wall
	 */
	bool dungeon2_cave_wall_can_be_drawn(u8 *map, int x, int y, dungeon_generator2 *dg2);

    /**
     * Computes blocks for the cave dungeon
     */
    void dungeon2_compute_cave();

    /**
     * Initializes a dungeon_generator2 instance for the cave dungeon
     * @param dg2 the instance to initalize
     */
    void dungeon2_cave_init_state(dungeon_generator2 *dg2);

    /**
     * Computes the header structures for the cave dungeon type
     */
    void dungeon2_init_cave();

    /**
     * Computes map blocks for a cave map by using set_block_id(...) and a bytemap
     * @param map The basic walk map
     * @param over The overlay map for grass patches
     * @param dg2
     */
    void dungeon2_compute_blocks_cave(u8 *map, u8 *over, dungeon_generator2 *dg2);

    map_header_t *dungeon2_init_header_cave(dungeon_generator2 *dg2);

    map_event_header_t *dungeon2_init_events_cave(dungeon_generator2 *dgen);

    map_footer_t *dungeon2_init_footer_cave(dungeon_generator2 *dg2);

    /**
     * Returns an item obtainable in the cave dungeon
     * @param dg2 generator instance
     * @return item to obtain
     */
    u16 dungeon_cave_pick_item(dungeon_generator2 *dg2);

    /**
     * Gets the level distribution (normal) for the cave based on the badges collected
     * @param mean pointer to the mean level
     * @param std_deviation pointer to the standard deviation
     */
    void dungeon2_cave_wild_pokemon_level_distribution(u8 *mean, u8 *std_deviation);

    /**
     * Initializes the wild pokemon for the cave dungeon
     */
    void dungeon2_init_wild_pokemon_cave(dungeon_generator2 *dg2);


    /**
     * Sets the overworld encounter for the cave dungeon
     */
    void dungeon2_set_encounter_cave();


#endif /* INCLUDE_C_DUNGEON_CAVE_H_ */
