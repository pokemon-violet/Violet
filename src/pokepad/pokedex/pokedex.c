#include "types.h"
#include "stdbool.h"
#include "romfuncs.h"
#include "pokepad.h"
#include "pokedex.h"
#include "oams.h"
#include "callbacks.h"
#include "save.h"
#include "utils.h"
#include "bg.h"
#include "gfx.h"
#include "text.h"
#include "mega.h"
#include "pokemon.h"
#include "basestats.h"
#include "color.h"
#include "superstate.h"
#include "utils.h"
#include "transparency.h"



bg_config pokedex_bg_main_configs [] = {
    {0, 2, 31, 0, 0, 0},
    {1, 0, 30, 0, 0, 1},
    {2, 1, 29, 0, 0, 2},
    {3, 1, 28, 0, 0, 2}
};

tboxdata pokedex_main_tboxes [] = {
    {0, 11, 0, 3, 2, 15, 1}, //tbox seen
    {0, 11, 2, 3, 2, 15, 7}, //tbox caught
    {0, 14, 5, 8, 14, 15, 13}, //tbox list
    {0, 22, 5, 8, 14, 3, 125}, // type list
    {0, 12, 5, 2, 14, 4, 237}, // capture list
    {0, 7, 5, 5, 14, 14, 265}, // nr list

    {0xFF, 0, 0, 0, 0, 0, 0}
};


sprite pokedex_cursor_sprite = {
    0, 0x8000, 0, 0
};

gfx_frame pokedex_cursor_gfx_anim_idle[] = {
    {0, 0},
    {0xFFFF, 0}
};

gfx_frame pokedex_cursor_gfx_anim_active[] = {
    {0, 32},
    {16, 32},
    {0xFFFE, 0}
};

gfx_frame *pokedex_cursor_anims[] = {
    pokedex_cursor_gfx_anim_idle,
    pokedex_cursor_gfx_anim_active
};

graphic pokedex_cursor_graphic = {
    &gfx_pokedex_sort_cursorTiles,
    0x400,
    0xA013
};

oam_template pokedex_cursor_template = {
    0xA013,
    0xA013,
    &pokedex_cursor_sprite,
    pokedex_cursor_anims,
    NULL,
    ROTSCALE_TABLE_NULL,
    oam_null_callback
};

u8 pokedex_fontcolmap[4] = {0, 2, 1, 0};

u16 pokedex_colors[16] = {0, 0x2927, 0x7FFF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
u16 pokedex_colors_nr[16] = {0, 0x7FFF, 0x2927, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int pokedex_get_first_seen() {
    pokedex_list_element *list = fmem->dex_mem->list;
    int i;
    for (i = 0; i < POKEDEX_CNT; i++) {
        if (pokedex_operator_by_dex_id(list[i].dex_id, 0))
            return i;
    }
    return 0;
}

int pokedex_get_last_seen() {
    pokedex_list_element *list = fmem->dex_mem->list;
    int i;
    for (i = POKEDEX_CNT - 1; i >= 0; i--) {
        if (pokedex_operator_by_dex_id(list[i].dex_id, 0))
            return i;
    }
    return 0;
}

void pokedex_free_maps() {
    free(bg_get_tilemap(0));
    free(bg_get_tilemap(1));
    free(bg_get_tilemap(2));
    free(bg_get_tilemap(3));
}

void pokedex_callback_return() {
    cb1handling();
    if (!is_fading()) {
        //end pokedex
        *vardecrypt(POKEDEX_VAR_COMPARATOR) = fmem->dex_mem->current_comparator;
        *vardecrypt(POKEDEX_VAR_LAST_SPECIES) = fmem->dex_mem->current_species;
        pokedex_free_maps();
        free(fmem->dex_mem->list);
        if (fmem->dex_mem->from_outdoor) {
            set_callback1(map_reload);
        } else {
            set_callback1(pokepad_callback_init);
        }
        free(fmem->dex_mem);
    }
}

void pokedex_callback_group_selection() {
    cb1handling();
    if (!is_fading()) {

        //first we proceed in fading process of current group
        if (fmem->dex_mem->group_fading_mode) {
            //fade count decrease
            if (fmem->dex_mem->group_fading_index) {
                fmem->dex_mem->group_fading_index--;
            } else {
                fmem->dex_mem->group_fading_mode = false;
            }
        } else {
            //fade count increase
            if (fmem->dex_mem->group_fading_index < 16) {
                fmem->dex_mem->group_fading_index++;
            } else {
                fmem->dex_mem->group_fading_mode = true;
            }
        }


        //Progress in input
        if (super->keys_new.keys.A) {
            switch (fmem->dex_mem->current_group) {
                case 0:
                    sound(5);
                    fmem->dex_mem->list_countdown = 0;
                    fmem->dex_mem->list_mode = 0;
                    fmem->dex_mem->in_list = true;
                    set_callback1(pokedex_callback_list);
                    fmem->dex_mem->group_fading_index = 16;
                    fmem->dex_mem->group_fading_mode = true;
                    break;
                case 1:
                    if (checkflag(POKEDEX_FLAG_FEATURE_0) || checkflag(POKEDEX_FLAG_FEATURE_1) || checkflag(POKEDEX_FLAG_FEATURE_2)) {
                        //TODO : features
                    } else {
                        sound(26);
                    }
                    break;
                case 2:

                    sound(5);
                    fmem->dex_mem->resorting = false;
                    fmem->dex_mem->sort_cursor_pos = fmem->dex_mem->current_comparator & 0x3;
                    fmem->dex_mem->group_fading_index = 16;
                    fmem->dex_mem->group_fading_mode = true;
                    set_callback1(pokedex_callback_sort);
                    oams[fmem->dex_mem->oam_sort_cursor].anim_number = 1;
                    gfx_init_animation(&oams[fmem->dex_mem->oam_sort_cursor], 0);
                    break;
            }
        } else if (super->keys_new.keys.B) {
            set_callback1(pokedex_callback_return);
            init_fadescreen(1, 0);
            sound(5);
        } else if (super->keys_new.keys.left && !fmem->dex_mem->current_group) {
            //we switch to feature selection
            fmem->dex_mem->current_group = 1;
            pokedex_group_window_set();
            sound(5);
        } else if (super->keys_new.keys.up && fmem->dex_mem->current_group <= 1) {
            fmem->dex_mem->current_group = 2;
            pokedex_group_window_set();
            sound(5);
        } else if (super->keys_new.keys.down && fmem->dex_mem->current_group == 2) {
            fmem->dex_mem->current_group = 0;
            pokedex_group_window_set();
            sound(5);
        } else if (super->keys_new.keys.right && fmem->dex_mem->current_group == 1) {
            fmem->dex_mem->current_group = 0;
            pokedex_group_window_set();
            sound(5);
        }
        color over = {0x7FFF};
        pals[17] = alpha_blend(pal_restore[17], over, fmem->dex_mem->group_fading_index);


    }
}

void pokedex_group_window_set() {
    set_io(0, get_io(0) | 0x2000); //enable win0
    set_io(0x48, 0x1F1F); //all bgs and obj layer are inside window
    set_io(0x4A, 0x1B1B); //bg2 is excluded from outside the window
    u8 leftmost = 0;
    u8 rightmost = 240;
    u8 topmost = 0;
    u8 bottommost = 160;
    switch (fmem->dex_mem->current_group) {
        case 0://list group, we set the window
            topmost = 31;
            leftmost = 63;
            break;
        case 1:
            topmost = 29;
            rightmost = 63;
            break;
        case 2:
            bottommost = 33;
            leftmost = 110;
            break;
    }
    u16 hdim = (u16) (rightmost | (leftmost << 8));
    u16 vdim = (u16) (bottommost | (topmost << 8));
    set_io(0x40, hdim);
    set_io(0x44, vdim);
}

void pokedex_show_components() {
    bg_sync_display_and_show(0);
    bg_sync_display_and_show(1);
    bg_sync_display_and_show(2);
    bg_sync_display_and_show(3);
    bg_display_sync();
    pokedex_group_window_set();
    set_callback1(pokedex_callback_group_selection);
}

void pokedex_init_components() {
    oam_reset();
    remove_all_big_callbacks();
    pal_fade_cntrl_reset();
    pal_allocation_reset();
    //dma0_cb_reset();
    set_callback3(NULL);
    bg_reset(0);
    bg_setup(0, pokedex_bg_main_configs, 4);

    void *bg0map = cmalloc(0x800);
    void *bg1map = malloc(0x800);
    void *bg2map = malloc(0x800);
    void *bg3map = malloc(0x800);
    bg_set_tilemap(0, bg0map);
    bg_set_tilemap(1, bg1map);
    bg_set_tilemap(2, bg2map);
    bg_set_tilemap(3, bg3map);

    //Load graphics
    lz77uncompwram(gfx_pokedex_uiMap, bg1map);
    lz77uncompvram(gfx_pokedex_uiTiles, (void*) 0x06000000);
    lz77uncompwram(gfx_pokedex_bottom_1Map, bg2map);
    lz77uncompvram(gfx_pokedex_bottom_1Tiles, (void*) 0x06004000);
    lz77uncompwram(gfx_pokedex_bottom_0Map, bg3map);
    //cpuset((void*)0x08E95DFC, (void*)0x0600a000, 0xc00);

    //TODO: textbox load
    tbox_sync_with_virtual_bg_and_init_all(pokedex_main_tboxes);

    u16 seen = pokedex_get_number_seen_or_caught(false);
    u16 caught = pokedex_get_number_seen_or_caught(true);
    value_to_str(strbuf, seen, 0, 3);
    tbox_flush(POKEDEX_TBOX_SEEN, 0);
    tbox_tilemap_draw(POKEDEX_TBOX_SEEN);
    tbox_print_string(POKEDEX_TBOX_SEEN, 2, 0, 0, 0, 0, pokedex_fontcolmap, 0, strbuf);
    value_to_str(strbuf, caught, 0, 3);
    tbox_flush(POKEDEX_TBOX_CAUGHT, 0);
    tbox_tilemap_draw(POKEDEX_TBOX_CAUGHT);
    tbox_print_string(POKEDEX_TBOX_CAUGHT, 2, 0, 0, 0, 0, pokedex_fontcolmap, 0, strbuf);

    //Displacements
    bg_virtual_map_displace(0, 0, 0);
    bg_virtual_set_displace(0, 0, 0);
    bg_virtual_map_displace(1, 0, 0);
    bg_virtual_set_displace(1, 0, 0);
    bg_virtual_map_displace(2, 0, 0);
    bg_virtual_set_displace(2, 0, 0);
    bg_virtual_map_displace(3, 0, 0);
    bg_virtual_set_displace(3, 0, 0);

    //Now we load the oam
    load_and_alloc_obj_vram_lz77(&pokedex_cursor_graphic);

    u8 cursor_pal = (u8) (allocate_obj_pal(0xA013) + 0x10);
    pal_load_comp(gfx_pokedex_sort_cursorPal, (u16) (cursor_pal * 16), 32);
    fmem->dex_mem->oam_sort_cursor = generate_oam_forward_search(&pokedex_cursor_template, 128, 16, 0);
    fmem->dex_mem->sort_cursor_pos = fmem->dex_mem->current_comparator & 3;
    pokedex_sort_locate_cursor();

    pal_load_comp(gfx_pokedex_uiPal, 0, 32);
    //Now we decide weather we want to clear features
    const color cols_active [2] = {
        {0x6754},
        {0x57E0}};
    const color cols_inactive [2] = {
        {0x3E0C},
        {0x35E8}};
    if (checkflag(POKEDEX_FLAG_FEATURE_0)) {
        pal_load_uncomp(cols_active, 10, 4);
    } else {
        pal_load_uncomp(cols_inactive, 10, 4);
    }
    if (checkflag(POKEDEX_FLAG_FEATURE_1)) {
        pal_load_uncomp(cols_active, 12, 4);
    } else {
        pal_load_uncomp(cols_inactive, 12, 4);
    }
    if (checkflag(POKEDEX_FLAG_FEATURE_2)) {
        pal_load_uncomp(cols_active, 14, 4);
    } else {
        pal_load_uncomp(cols_inactive, 14, 4);
    }

    pal_load_comp(gfx_pokedex_bottom_1Pal, 16, 32);
    pal_load_comp(gfx_pokedex_bottom_0Pal, 32, 32);
    pal_load_uncomp(pokedex_colors, 15 * 16, 16);
    pal_load_uncomp(pokedex_colors_nr, 14 * 16, 32);
    pal_load_uncomp((void*) 0x08E95DDC, 3 * 16, 32);
    pal_load_uncomp((void*) 0x08E95DBC, 4 * 16, 32);
    pal_set_all_to_black();

    init_fadescreen(0, 0);
    set_callback1(pokedex_show_components);

    bg_virtual_sync(0);
    bg_virtual_sync(1);
    bg_virtual_sync(2);
    bg_virtual_sync(3);


}

void pokedex_callback_init() {
    cb1handling();
    if (!is_fading()) {
        if (fmem->dex_mem->from_outdoor) {
            overworld_free();
        } else {
            pokepad_free_components();
        }
        pokedex_init_components();
        pokedex_build_list();
        pokedex_quicksort_list((u8) fmem->dex_mem->current_comparator, 0, POKEDEX_CNT - 1); //resort list
        pokedex_update_list();
        set_io(0x50, 0);
        set_io(0x52, 0);
        set_io(0x54, 0);

        bic_io(0, 0x6000);
    }
}

void pokedex_init(bool from_outdoor) {
    fmem->dex_mem = cmalloc(sizeof (pokedex_memory));
    fmem->dex_mem->from_outdoor = from_outdoor;
    fmem->dex_mem->current_group = 0;
    fmem->dex_mem->current_species = *vardecrypt(POKEDEX_VAR_LAST_SPECIES);
    fmem->dex_mem->current_comparator = (u8) * vardecrypt(POKEDEX_VAR_COMPARATOR);
    fmem->dex_mem->cursor_anchor = 0;
    set_callback1(pokedex_callback_init);
    init_fadescreen(1, 0);
}