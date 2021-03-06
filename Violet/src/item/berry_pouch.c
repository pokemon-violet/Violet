#include "types.h"
#include "item/item.h"
#include "item/berry_pouch.h"
#include "save.h"
#include "berry.h"
#include "debug.h"
#include "flags.h"
#include "language.h"
#include "bg.h"
#include "overworld/map_control.h"
#include "fading.h"
#include "callbacks.h"
#include "overworld/script.h"
#include "text.h"
#include "superstate.h"
#include "music.h"
#include "constants/berry_pouch_contexts.h"
#include "vars.h"
#include "constants/sav_keys.h"
#include "overworld/pokemon_party_menu.h"

static u8 context_menu_options_standard[4] = {
    BERRY_POUCH_CONTEXT_MENU_ACTION_USE,
    BERRY_POUCH_CONTEXT_MENU_ACTION_GIVE,
    BERRY_POUCH_CONTEXT_MENU_ACTION_TOSS,
    BERRY_POUCH_CONTEXT_MENU_ACTION_EXIT,
};

static u8 context_menu_options_composter[2] = {
    BERRY_POUCH_CONTEXT_MENU_ACTION_COMPOST,
    BERRY_POUCH_CONTEXT_MENU_ACTION_EXIT,
};


void berry_pouch_callback_plant_berry(u8 self) {
    *var_access(LASTRESULT) = 1; // Berry planted
    save_increment_key(SAV_KEY_PLANTED_BERRIES);
    item_remove(item_activated, 1);
    u8 berry_tree_idx = (u8)*var_access(0x8000);
    berry_tree_initialize(berry_tree_idx, (u8)ITEM_IDX_TO_BERRY_IDX(item_activated), BERRY_STAGE_DIRT_PILE);
    cmem.berry_trees[berry_tree_idx].replanted = 1;
    big_callbacks[self].function = berry_pouch_fade_and_continuation;
}

void (*berry_pouch_callbacks[])(u8) = {
    [BERRY_POUCH_CONTEXT_FROM_OVERWORLD] = berry_pouch_callback_context_menu,
    [BERRY_POUCH_CONTEXT_FROM_PARTY_MENU_GIVE] = berry_pouch_callback_from_party_menu_give,
    [BERRY_POUCH_CONTEXT_FROM_MART_SELL] = berry_pouch_callback_from_mart_sell,
    [BERRY_POUCH_CONTEXT_FROM_STORAGE_PC] = berry_pouch_callback_from_storage_pc,
    [BERRY_POUCH_CONTEXT_FROM_BATTLE] = berry_pouch_callback_context_menu,
    [BERRY_POUCH_CONTEXT_FROM_BERRY_CRUSH] = 0,
    [BERRY_POUCH_CONTEXT_PLANTING] = berry_pouch_callback_plant_berry,
    [BERRY_POUCH_CONTEXT_COMPOSTING] = berry_pouch_callback_context_menu,
};

u8 berry_pouch_context_menu_option_compost_text[] = LANGDEP(
    PSTRING("Kompost."),
    PSTRING("Compost")
);

u8 str_berry_pouch_how_many_to_compost[] = LANGDEP(
    PSTRING("Wie viele willst du\nkompostieren?"),
    PSTRING("How many to compost?")
);

extern u8 str_berry_pouch_how_many_to_toss[];

void berry_pouch_toss_print_string_how_many(u8 self) {
    if (berry_pouch_state2.type == BERRY_POUCH_CONTEXT_COMPOSTING) {
        berry_pouch_initialize_toss_quantity_selection(self, str_berry_pouch_how_many_to_compost);
    } else {
        berry_pouch_initialize_toss_quantity_selection(self, str_berry_pouch_how_many_to_toss);
    }
}

u8 str_berry_pouch_how_confirm_quantity_to_compost[] = LANGDEP(
    PSTRING("Dieses Item BUFFER_2 ×\nkompostieren?"),
    PSTRING("Compost this item BUFFER_2 ×?")
);

extern u8 str_berry_pouch_confirm_quantity_to_toss[];

void berry_pouch_toss_get_string_confirm_quantity_to_toss() {
    if (berry_pouch_state2.type == BERRY_POUCH_CONTEXT_COMPOSTING) {
        string_decrypt(strbuf, str_berry_pouch_how_confirm_quantity_to_compost);
    } else {
        string_decrypt(strbuf, str_berry_pouch_confirm_quantity_to_toss);
    }
}

u8 str_berry_pouch_composted_item[] = LANGDEP(
    PSTRING("BUFFER_2 × BUFFER_1\nzu BUFFER_3 kompostiert."),
    PSTRING("Composted BUFFER_2 ×\nBUFFER_1 to BUFFER_3 ")
);

extern u8 str_berry_pouch_tossed_item[];

void berry_pouch_composting_no_room_for_mulch(u8 self) {
    if (super.keys_remapped.keys.A || super.keys_remapped.keys.B) {
        play_sound(5);
        berry_pouch_variable_tbox_delete(9);
        tbox_tilemap_draw(0);
        tbox_tilemap_draw(1);
        bg_virtual_sync_reqeust_push(0);
        bg_virtual_sync_reqeust_push(2);
        berry_pouch_set_arrow_cursor_from_list_menu((u8)big_callbacks[self].params[0], 1);
        berry_pouch_return_to_main(self);
    }
}

u8 str_berry_pouch_no_room_for_mulch[] = LANGDEP(
    PSTRING("Du hast keinen Platz für\nBUFFER_3!"),
    PSTRING("You don't have any room for\nBUFFER_3!")
);

void berry_pouch_toss_or_compost_confirmed(u8 self) {
    if (berry_pouch_state2.type == BERRY_POUCH_CONTEXT_COMPOSTING) {
        if (!item_has_room(ITEM_MULCH, big_callbacks[self].params[8])) {
            // TODO
            strcpy(buffer2, item_get_name(ITEM_MULCH));
            string_decrypt(strbuf, str_berry_pouch_no_room_for_mulch);
            berry_pouch_print_string(berry_pouch_get_or_create_variable_tbox(9), 2, strbuf, 0, 2, 1, 2, 0, 1);
            big_callbacks[self].function = berry_pouch_composting_no_room_for_mulch;
        } else {
            play_sound(257);
            berry_pouch_get_item_name_with_prefix(big_callbacks[self].params[1], buffer0);
            strcpy(buffer2, item_get_name(ITEM_MULCH));
            itoa(buffer1, big_callbacks[self].params[8], ITOA_NO_PADDING, 3);
            string_decrypt(strbuf, str_berry_pouch_composted_item);
            berry_pouch_print_string(berry_pouch_get_or_create_variable_tbox(9), 2, strbuf, 0, 2, 1, 2, 0, 1);
            item_add(ITEM_MULCH, big_callbacks[self].params[8]);
            big_callbacks[self].function = berry_pouch_toss_wait_keypress;
        }
    } else {
        berry_pouch_variable_tbox_delete(7);
        berry_pouch_get_item_name_with_prefix(big_callbacks[self].params[1], buffer0);
        itoa(buffer1, big_callbacks[self].params[8], ITOA_NO_PADDING, 3);
        string_decrypt(strbuf, str_berry_pouch_tossed_item);
        berry_pouch_print_string(berry_pouch_get_or_create_variable_tbox(9), 2, strbuf, 0, 2, 1, 2, 0, 1);
        big_callbacks[self].function = berry_pouch_toss_wait_keypress;
    }
}

void berry_pouch_get_context_menu_options_standard() {
    if (berry_pouch_state2.type == BERRY_POUCH_CONTEXT_COMPOSTING) {
        berry_pouch_context_menu_options = context_menu_options_composter;
        berry_pouch_context_menu_options_count = ARRAY_COUNT(context_menu_options_composter);
    } else {
        berry_pouch_context_menu_options = context_menu_options_standard;
        berry_pouch_context_menu_options_count = ARRAY_COUNT(context_menu_options_standard);
    }
}

static void composter_big_callback_free_overworld_and_initialize(u8 self) {
    if (!fading_is_active()) {
        overworld_free();
        berry_pouch_initialize(BERRY_POUCH_CONTEXT_COMPOSTING, map_reload, true);
        overworld_script_resume();
        big_callback_delete(self);
    }
}

void composter_initialize() {
    overworld_pokemon_league_stop_lighting_effect();
    fadescreen_all(1, 0);
    big_callback_new(composter_big_callback_free_overworld_and_initialize, 0);
}