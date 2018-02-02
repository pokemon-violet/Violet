#ifndef H_ROMFUNCS
#define H_ROMFUNCS
#include <stdbool.h>
#include "stddef.h"
#include "prng.h"

#define CPUSET_COPY 0
#define CPUSET_FILL 0x1000000
#define CPUSET_HALFWORD 0
#define CPUSET_WORD 0x4000000

//static functions in ROM
u8 get_item_effect_param(u16 item_id);
void init_fadescreen(u8 type, u8 unkown);
void set_callback1(void (*function)());
void *malloc(size_t size);
void oam_reset();
void setflag(u16 flag);
void clearflag(u16 flag);
void set_io(u16 ioreg, u16 value);
void apply_bg_configs(u8 bgid, u8 charbase, u8 mapbase, u8 size, u8 colmode, u8 priority, u8 mosaic, u8 unkown);
void bg_update_and_show(u8 bgid);
void lz77uncompvram(const void*source, void*destination);
void lz77uncompwram(const void*source, void*destination);
void cb1handling();
void bg_copy_vram(u8 bgid, void*source, u16 size, u16 starttile, u8 mode);
void cpuset(const void*source, void*destination, int cnt_and_mode);
void cpufastset(u32*source, u32*destination, u32 cnt_and_mode);
u32* bg_get_tilemap(u8 bgid);
u32 get_pokemons_attribute(void*pokemon_offset, int requested_attribute, void*freespace);
u32 set_pokemons_attribute(void*pokemon_offset, u16 requested_attribute, void*values);
u8 charlen_of_hex_value_dec_format(u32 value);
u8* value_to_str(u8*dest, u32 value, u8 mode, u8 charlength);
void memcopy(void* dest, void*source, u32 size);
void recalculate_stats(void*pokemon_offset);
void pal_load_uncomp(const void *source, u16 dest_col, u16 bytecount);
u8 countpokemon();
void cry(u16 pokeID, u8 feature);
void sound(u16 soundID);
void map_reload();
void free(void* ptr);
void color_blend(u16 color_id_to_blend, u16 color_count, u8 intesity, u16 color_to_blend_into);
void remove_big_callback(u8 cbid);
void init_script(void* script);
u8 spawn_big_callback(void (*function)(u8), u8 priority);
void* cmalloc(size_t size);
u8 allocate_rotscale();
void set_rotscale_param(u8 id, u16 v0, u16 v1, u16 v2, u16 v3);
void pokemenu_free();
void remove_all_big_callbacks();
void bg_reset(u8 unkown); //usually called with unkown = 0x0
void bg_sync_display_and_show(u8 bgid);
void free_all_tboxes();
void bg_hide(u8 bgid);
void bg_display_sync();
void pal_load_comp(const void* source, u16 dest_col, u16 bytecount);
u16 get_io(u16 reg);
void free_tbox(u8 boxid);
void flush_tbox(u8 boxid, u8 unkown);
void string_decrypt(u8* destination, u8* source);
void playsong1(u16 song, u8 feature);
void map_reload_small();
void obj_pal_reset();
void bg_set_tilemap(u8 bgid, void* tilemap);
void display_box_no_transbg(u8 boxid, u8 font, u8* text, u8 unkown, u8 border, u8 display_all, u8 unkown2);
u16* vardecrypt(u16 var);
bool is_function_listed_as_callback(void* func);
u8 get_callback_id_by_func(void *func);
void load_graphic_for_wandler(u8 user_index, u8 target_index, u8 unkown);
bool is_opponent(u8 index);
u8 get_ability(u16 species, u8 fields);
bool checkflag(u16 flag);
void battle_printmsg(u8* str, u16 duration);
void init_attack();
void bsc_executer();
u8* concatenate_strings(u8* first, u8* second); //returns the offset of the 0xFF bytes of the two strings
u8* strcpy(u8* d1, u8* s2);
bool is_double_battle();
//void load_and_alloc_obj_vram_lz77 (graphic*g);	defined in oams.h
u8 ability_management(u8 state, u8 attacker_slot, u8 unkown, u8 defender_ability, u16 active_attack);
void battle_callback1();
void get_current_tile_position(s16 *x, s16 *y);
u16 get_block_id(s16 x, s16 y);
void set_block_id(s16 x, s16 y, u16 block);
void special_x8E_update_map_graphics();
u16 get_block_info_behaviour(s16 x, s16 y);
void warp_setup(u8 bank, u8 map, u8 exit, s16 x, s16 y);
void warp_setup_callbacks();
void script_wait_for_warp();
void script_halt();
void dma3_controller_reset();
void bg_virtual_map_displace(u8 bg_id, u16 value, int mode);
void bg_virtual_set_displace(u8 bg_id, u16 value, int mode);
//
u32 __aeabi_uidivmod(u32 dividend, u32 divisor);
int __sqrt(int x);
script npc_get_script(u8 npc_id);
u16 trainer_get_unaligned_hword(void *src);
u16 trainer_get_flag();
bool get_npc_id_by_overworld(u8 overworld_id, u8 map, u8 bank, u8 *result);
void list_add(u8 *list, u8 *size, u8 value);
u8 pokemon_menu_context_get_current_item_index();
void tbox_flush_and_free_if_present(u8 *boxid);
bool outdoor_moves_usable();
bool map_is_x40_x0();
void pokemenu_opts_clear_pokemenu_and_printstr(u8 string_id);
void pokemenu_task_wait_for_keypress_and_return_to_select(u8 self);
void pokemenu_init_textrenderer(u8 *text, u8 unkown);
void pokemenu_task_wait_for_textrenderer(u8 self);
void surfer_init_proper_error_message();
void script_resume();
u8 get_current_weather();
void save_increment_key(u8 key);
void rain_sound_fadeout();
void startmenu_close();
u8 pokemenu_get_selected_poke_index();
void pokemenu_fade_and_execute_callback(u8 self);
void pokemenu_prepeare_softboiled(u8 self);
void pokemenu_init_fly();
void map_load_namespace(pstring text, u8 namespace_id);
void pokemenu_print_string_as_yes_no(u8 self);
void npc_applymovement(u8 npc_id, u8 map, u8 bank, u8 *moves);
void big_callback_set_int(u8 callback, u8 var, int value);
int big_callback_get_int(u8 callback, u8 var);
void tile_get_coordinates_player_is_facing(s16 *x, s16 *y);
u8 map_get_tile_level(s16 x, s16 y);
u8 get_playerfacing();
void _item_select_pokemon_for_activation(u8 self);
void bg_virutal_sync_reqeust_push(u8 bg_id);
void item_remove(u16 item_id, u16 count);
void item_callback_wait_for_text_render_and_return_to_bag(u8 self);
void bic_io(u8 reg, u16 mask);
void pal_fade_cntrl_reset();
void dma0_cb_reset();
void set_callback3(void (*function)());
void overworld_free();
void bg_virtual_sync(u8 bg_id);
void return_to_pokemenu();
void pokemenu_init(u8 a, u8 b, u8 c, u8 d, u8 e, void (*func1)(), void (*return_callback)());
void malloc_init(void *start, u32 size);
void pal_set_all_to_black();
bool move_is_hm(u16 move);
void unkown_ingame_trade_func();
void ingame_trade_init_callback();
void script_set_active();
void item_field_usage_on_poke_callback_failure(u8 self); //0x8125711;
u8 *str_append(u8 *dst, u8 *src);
void tbox_draw_type_icon_by_type_p1(u8 box_id, u8 type_p1, u16 additional, u16 y_pixel);
bool pokedex_tbox_draw_num(u8 box_id, u8 n, u16 species, u8 n2, u16 y_pixel);
void pal_allocation_reset();
u16 obj_vram_allocate(u16 tiles);
void obj_vram_add_tile_tag_to_allocation_table(u16 tag, u16 tile, u16 tile_amount);
u8 worldmap_get_position_namespace(u8 worldmap_index, u8 layer, u16 x, u16 y);
u8 worldmap_get_current_index();
void player_npc_set_state_and_behavior_tile_anim(u8 movement, u8 unkown);
void pokemon_heal_all();
u8 *flag_access(u16 flag);
void npc_player_set_bike_state(u8 state);
bool checkitem(u16 item, u16 quantity);
void warp_setup_teleport_callback();
void warp_setup_muted_callback();
void warp_enable_flags();
script map_get_levelscript_if_triggered(u8 type);
void script_init_muted(script s);
bool multichoice(u8 x, u8 y, u8 choice, bool forced_choice);
void warp_history_set(u8 index, u8 bank, u8 map, u8 exit, s16 x, s16 y);
int save_get_key(u8 index);
bool tile_is_reflective_water(u8 behavior);
void pal_apply_shader_by_overworld_pal(u8 ow_pal);
void pal_ow_fading_state_sync(u8 ow_pal);
int script_read_word(void *script_state);
void pokemart(u16 *list);
void mart_set_end_callback(void (*func)());
void item_printstr(u8 cb_id, u8 unkown, u8 unkown2, u8 *str);
void worldmapflag_state_set(u16 flag);
void worldmapflag_set(u16 flag);
void item_func_repel(u8 self);
void additem(u16 item, u16 cnt);
void blend_proceed();
void oam_attributes_proceed();
void oam_attributes_copy();
void graphic_copy_queue_do();
void handle_pals();
void dma3_do();
void tbox_proceed();
void big_callbacks_proceed();
void oam_anim_proceed();
int bg_decomp_and_load(u8 bg_id, const void *res, u32 fixed_size, u16 row_displ, bool is_tilemap);
void ts_main_big_cb(u8 self);
void bsc_push_next_cmd();
void attack_anim_remove_big_cb(u8 self);
bool move_needs_charging(u16 move);
void bsc_init_by_interrupting_battle_func(u8 *bsc);
u16 pokemon_get_basic_stage(u16 species);
void bsc_cmd_x06_apply_damage_modifiers();
void remove_pc_item(u16 item, u16 quantity);
void dma3_add_request(void *src, void *dst, u16 size);
void fanfare(u16 song_id);
u8 weather_get();
void pokedex_set_caught_and_load_pid(u16 dex_id, u8 flags, u32 pid);
bool fadescreen_is_active();
/**
 * 
 * @param affects bits 0-15 bg pals, bit 15-31 obj pals
 * @param p1
 * @param p2
 * @param p3
 * @param color
 */
void fadescreen(u32 affects, u8 p1, u8 p2, u8 p3, u16 color);

/**
 * Queries a string (as for pokemon nickname)
 * @param mode TODO (3 seems to be nickname)
 * @param target_buf result of the query
 * @param species species to show
 * @param gender gender of the species to show
 * @param closure closure function after the query (usually includes a reload)
 */
void pokemon_query_string(u8 mode, u8 *target_buf, u16 species, u8 gender,
        u32 pid, void (*closure)());

/**
 * Std. closure function for string queries. Uses map reload.
 */
void pokemon_query_string_std_closure();

#endif