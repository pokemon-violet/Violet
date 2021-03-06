#include "types.h"
#include "pokemon/sprites.h"
#include "oam.h"
#include "text.h"
#include "constants/species.h"
#include "map/wild_pokemon.h"
#include "constants/unown_messages.h"
#include "constants/vars.h"
#include "vars.h"
#include "pokemon/virtual.h"
#include "constants/pokemon_attributes.h"
#include "debug.h"
#include "overworld/unown.h"
#include "bg.h"
#include "agbmemory.h"
#include "callbacks.h"
#include "superstate.h"
#include "overworld/script.h"
#include "music.h"

static u8 unown_message_rock[] = {
    UNOWN_LETTER('R'), UNOWN_LETTER('O'), UNOWN_LETTER('C'), UNOWN_LETTER('K'), 0xFF
};

static u8 unown_message_ice[] = {
    UNOWN_LETTER('I'), UNOWN_LETTER('C'), UNOWN_LETTER('E'), 0xFF
};

static u8 unown_message_steel[] = {
    UNOWN_LETTER('S'), UNOWN_LETTER('T'), UNOWN_LETTER('E'), UNOWN_LETTER('E'), UNOWN_LETTER('L'), 0xFF
};

static u8 *unown_messages[] = {
    [UNOWN_MESSAGE_ROCK] = unown_message_rock, 
    [UNOWN_MESSAGE_ICE] = unown_message_ice, 
    [UNOWN_MESSAGE_STEEL] = unown_message_steel
};

bool player_party_spells_unown_message() {
    u8 *message = unown_messages[*var_access(0x8004)];
    u8 party_message[7] = {0xFF};
    int j = 0;
    for (int i = 0; i < player_pokemon_cnt; i++) {
        if (pokemon_get_attribute(player_pokemon + i, ATTRIBUTE_SPECIES, 0) == POKEMON_ICOGNITO) {
            pid_t pid = {.value = (u32)pokemon_get_attribute(player_pokemon + i, ATTRIBUTE_PID, 0)};
            party_message[j++] = (u8) pokemon_unown_get_letter(pid);
        }
    }
    dprintf("Player party spells %d %d %d %d %d %d %d\n", party_message[0], party_message[1], party_message[2], 
        party_message[3], party_message[4], party_message[5], party_message[6]);
    party_message[j++] = 0xFF;
    int i;
    for (i = 0; party_message[i] != 0xFF && message[i] != 0xFF; i++) {
        if (message[i] != party_message[i]) return false;
    }
    return message[i] == party_message[i];
}
static sprite unown_message_oam_sprite = {.attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_64_64, .attr2 = ATTR2_PRIO(0)};

static oam_template unown_message_oam_templates[UNOWN_MESSAGE_MAX_LEN] = {
    [0] = {
        .tiles_tag = UNOWN_MESSAGE_TAG + 0, .pal_tag = UNOWN_MESSAGE_TAG,
        .oam = &unown_message_oam_sprite, .animation = oam_gfx_anim_table_null,
        .graphics = NULL, .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback,
    },
    [1] = {
        .tiles_tag = UNOWN_MESSAGE_TAG + 1, .pal_tag = UNOWN_MESSAGE_TAG,
        .oam = &unown_message_oam_sprite, .animation = oam_gfx_anim_table_null,
        .graphics = NULL, .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback,
    },
    [2] = {
        .tiles_tag = UNOWN_MESSAGE_TAG + 2, .pal_tag = UNOWN_MESSAGE_TAG,
        .oam = &unown_message_oam_sprite, .animation = oam_gfx_anim_table_null,
        .graphics = NULL, .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback,
    },
    [3] = {
        .tiles_tag = UNOWN_MESSAGE_TAG + 3, .pal_tag = UNOWN_MESSAGE_TAG,
        .oam = &unown_message_oam_sprite, .animation = oam_gfx_anim_table_null,
        .graphics = NULL, .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback,
    },
    [4] = {
        .tiles_tag = UNOWN_MESSAGE_TAG + 4, .pal_tag = UNOWN_MESSAGE_TAG,
        .oam = &unown_message_oam_sprite, .animation = oam_gfx_anim_table_null,
        .graphics = NULL, .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback,
    },
    [5] = {
        .tiles_tag = UNOWN_MESSAGE_TAG + 5, .pal_tag = UNOWN_MESSAGE_TAG,
        .oam = &unown_message_oam_sprite, .animation = oam_gfx_anim_table_null,
        .graphics = NULL, .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback,
    },
};

void overworld_unown_wait_message(u8 self) {
    if (super.keys_new.keys.A || super.keys_new.keys.B) {
        play_sound(5);
        overworld_script_resume();
        big_callback_delete(self);
    }
}

void overworld_unown_print_message() {
    u8 *message = unown_messages[*var_access(0x8004)];
    fmem.gp_state = malloc(sizeof(overworld_unown_state_t));
    for (OVERWORLD_UNOWN_MESSAGE_STATE->message_length = 0; message[OVERWORLD_UNOWN_MESSAGE_STATE->message_length] != 0xFF; 
        OVERWORLD_UNOWN_MESSAGE_STATE->message_length++) {}

    u8 x = (u8)((30 - 4 * OVERWORLD_UNOWN_MESSAGE_STATE->message_length) / 2);
    u8 width = (u8)(4 * OVERWORLD_UNOWN_MESSAGE_STATE->message_length);

    tboxdata boxdata = {
        .x = x, .w = width, .y = 4, .h = 4, .bg_id = 0, .pal = 14, .start_tile = 1
    };
    OVERWORLD_UNOWN_MESSAGE_STATE->box_idx = tbox_new(&boxdata);
    tbox_load_message_gfx_and_pal();
    tbox_print_std_frame(OVERWORLD_UNOWN_MESSAGE_STATE->box_idx, false);
    tbox_flush_set(OVERWORLD_UNOWN_MESSAGE_STATE->box_idx, 0x11);
    tbox_tilemap_draw(OVERWORLD_UNOWN_MESSAGE_STATE->box_idx);

    *strbuf = 255;
    tbox_print_string_parametrized(OVERWORLD_UNOWN_MESSAGE_STATE->box_idx, 2, strbuf, 0, 0, 255, NULL);
    tbox_copy_to_vram(OVERWORLD_UNOWN_MESSAGE_STATE->box_idx, 3);


    for (int i = 0; i < OVERWORLD_UNOWN_MESSAGE_STATE->message_length; i++) {
        u32 letter_idx = message[i];
        pid_t pid = {.fields = {.unown_letter = (u32)(letter_idx & 31)}};
        pokemon_load_gfx_by_graphic(pokemon_frontsprites + POKEMON_ICOGNITO, gp_tmp_buf, POKEMON_ICOGNITO, pid);
        graphic g = {.sprite = gp_tmp_buf, .tag = (u16)(UNOWN_MESSAGE_TAG + i), 
            .size = GRAPHIC_SIZE_4BPP(64, 64)};
        oam_load_graphic_uncompressed(&g);
        u8 pal_idx = oam_allocate_palette(UNOWN_MESSAGE_TAG);
        pal_decompress(pokemon_pals[POKEMON_ICOGNITO].pal, (u16)((pal_idx + 16) * 16), 32);
        OVERWORLD_UNOWN_MESSAGE_STATE->oams[i] = oam_new_forward_search(unown_message_oam_templates + i, (s16)(8 * x + 32 * i + 16), 48, (u8)i);
        (void)unown_message_oam_templates;
    }

    overworld_script_halt();
    big_callback_new(overworld_unown_wait_message, 0);
}

void overworld_unown_delete_message() {
    tbox_flush_all(OVERWORLD_UNOWN_MESSAGE_STATE->box_idx, 0);
    tbox_flush_map(OVERWORLD_UNOWN_MESSAGE_STATE->box_idx);
    tbox_sync(OVERWORLD_UNOWN_MESSAGE_STATE->box_idx, TBOX_SYNC_MAP_AND_SET);
    tbox_border_flush(OVERWORLD_UNOWN_MESSAGE_STATE->box_idx);
    tbox_free(OVERWORLD_UNOWN_MESSAGE_STATE->box_idx);
    for (int i = 0; i < OVERWORLD_UNOWN_MESSAGE_STATE->message_length; i++) {
        oam_free(oams + OVERWORLD_UNOWN_MESSAGE_STATE->oams[i]);
    }
    free(OVERWORLD_UNOWN_MESSAGE_STATE);
}



