#include "types.h"
#include "agbmemory.h"
#include "save.h"
#include "constants/flags.h"
#include "flags.h"
#include "debug.h"
#include "oam.h"
#include "overworld/palette.h"
#include "tile/any_grass.h"
#include "overworld/sprite.h"
#include "color.h"
#include "bios.h"

void map_reset_temporary_flags_and_vars() {
    memset(save1->flags, 0, 4); // Flags 0 - 32
    memset(save1->vars, 0, 16 * 2); // Vars 0 - 16
    clearflag(0x803);
    clearflag(0x804);
    clearflag(STRENGTH_USED);                   
    clearflag(FLAG_IN_BATTLE);
    clearflag(0x842);
    setflag(POKERADAR_POKEMON_SPAWNED);
    clearflag(FLAG_PLAYER_ON_LADDER);
}


static bool oam_palette_tag_is_npc_palette(u16 tag) {
    if (tag >= 0x1100 && tag < 0x1120) return true;
    // TODO: adapt for dynamic overworlds some kind of check, if a palette belongs to a npc
    return false;
}

u8 palette_get_gamma_type(u8 pal_idx) {
    if (pal_idx < 13)
        return GAMMA_NORMAL; // Tileset palettes are affected by the standard gamma shift
    if (pal_idx >= 13 && pal_idx < 16)
        return GAMMA_NONE; // Text-Palettes are unaffected by gamma shifts
    // For overworld palettes we need to figure out the pal type by its tag
    u16 tag = oam_palette_get_tag((u8)(pal_idx - 16));
    if (tag == 0xFFFF)
        return GAMMA_NONE;
    if (NPC_PAL_TAG_IS_REFLECTION_TAG(tag))
        return GAMMA_NORMAL;
    if (oam_palette_tag_is_npc_palette(tag))
        return GAMMA_ALTERNATIVE;
    else
        return GAMMA_NORMAL;
}

void overworld_npc_palettes_initialize(u8 mode) {
    // Don't reserve any palettes whatsoever
    (void)mode;
    oam_palette_allocation_reset();
}

static palette *overworld_npc_palette_get_by_tag(u16 tag) {
    // TODO: dynamic tags from a more efficient table?

    u8 idx = overworld_npc_palette_get_idx(tag);
    // dprintf("Tag 0x%x is at idx %d in pal-table.\n", tag, idx);
    if (idx != 0xFF) {
        return overworld_npc_palettes + idx;
    }
    return NULL;
}


u8 overworld_npc_palette_load(u16 tag) {
    palette *pal = overworld_npc_palette_get_by_tag(tag);
    if (pal) {
        return oam_palette_load_if_not_present(pal);
    }
    return 0xFF;
}

void overworld_npc_load_palette_by_template(oam_template *template) {
    if (template->pal_tag != 0xFFFF) {
        // dprintf("Loading oam pal from tag 0x%x\n", template->pal_tag);
        overworld_npc_palette_load(template->pal_tag);
    }
}

void overworld_npc_update_palette(npc *n, oam_object *oam) {
    overworld_sprite *sprite = overworld_get(n->sprite);
    u8 pal_idx = overworld_npc_palette_load(sprite->pal_tag);
    oam->final_oam.attr2 = (u16)((pal_idx << 12) | (oam->final_oam.attr2 & ~(15 << 12)));
}

void overworld_npc_reflection_brighten_palette(u8 pal_idx) {
    for (int i = 0; i < 16; i++) {
        color_t c = pals[256 + 16 * pal_idx + i];
        c.rgb.red = (u16)(MIN(31, c.rgb.red + 5) & 31);
        c.rgb.green = (u16)(MIN(31, c.rgb.green + 5) & 31);
        c.rgb.blue = (u16)(MIN(31, c.rgb.blue + 10) & 31);
        dprintf("Old color 0x%x, new color 0x%x\n", pals[256 + 16 * pal_idx + i], c);
        pals[256 + 16 * pal_idx + i] = c;
    }
    // cpuset(pal_restore + 256 + 16 * pal_idx, pals + 256 + 16 * pal_idx, CPUSET_COPY | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(16 * sizeof(color_t)));
    cpuset(pals + 256 + 16 * pal_idx, pal_restore + 256 + 16 * pal_idx, CPUSET_COPY | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(16 * sizeof(color_t)));
}   

// static color_t reflection_blue_channel = {.rgb = {.red = 12, .green = 20, .blue = 27}}; 

void overworld_npc_load_reflection_palette(npc *n, oam_object *oam) {
    overworld_sprite *sprite = overworld_get(n->sprite);
    u16 tag = sprite->pal_tag;
    u16 reflection_tag = NPC_PAL_TAG_TO_REFLECTION_TAG(tag);
    // dprintf("Try to set up reflection tag 0x%x for tag 0x%x\n", reflection_tag, tag);
    u8 pal_idx = oam_palette_get_index(reflection_tag);
    if (pal_idx != 0xFF) {
        oam->final_oam.attr2 = (u16)((pal_idx << 12) | (oam->final_oam.attr2 & ~(15 << 12)));
        return;
    }
    // dprintf("Reflection tag not yet allocated...\n");
    palette *pal = overworld_npc_palette_get_by_tag(tag);
    if (pal == NULL) 
        return; // The original palette doesn't exist...
    palette reflection_palette = *pal;
    reflection_palette.tag = reflection_tag;
    pal_idx = oam_palette_load_if_not_present(&reflection_palette);
    // pal_alpha_blending((u16)(256 + 16 * pal_idx), 16, 6, reflection_blue_channel);
    // cpuset(pals + 256 + 16 * pal_idx, pal_restore + 256 + 16 * pal_idx, CPUSET_COPY | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(16 * sizeof(color_t)));
    overworld_npc_reflection_brighten_palette(pal_idx);
    pal_apply_shaders_by_oam_palette_idx(pal_idx);
    pal_oam_apply_fading(pal_idx);
    oam->final_oam.attr2 = (u16)((pal_idx << 12) | (oam->final_oam.attr2 & ~(15 << 12)));
    // dprintf("Created reflective pal at slot %d\n", pal_idx);
    // dprintf("Attribute2 is 0x%x\n", oam->final_oam.attr2);
}

void npc_free_resources(npc *n) {
    graphic tmp;
    tmp.size = overworld_get(n->sprite)->size;
    oams[n->oam_id].gfx_table = (u32*)&tmp;
    oam_clear_and_free_vram(oams + n->oam_id);

    u8 pal_idx = (u8)((oams[n->oam_id].final_oam.attr2 >> 12) & 0xF);
    // Check if any npcs are using the palette (it is assumed that n is already set to inactive!)
    for (int i = 0; i < 16; i++) {
        if (!npcs[i].flags.active) continue;
        u8 oam_idx = npcs[i].oam_id;
        if (((oams[oam_idx].final_oam.attr2 >> 12) & 0xF) == pal_idx)
            return; // This palette is still referenced by at least one npc
    }
    // No other npc references this pal slot anymore, we can free the allocated palette slot
    u16 tag = oam_palette_get_tag(pal_idx);
    if (tag == 0xFFFF) {
        dprintf("Warning! A npc was using pal %d, which however is not associated with any allocated tag. Bug?\n", pal_idx);
        return;
    }
    if (tag == 0x1200) // This tag is used by weather effects, we never can release this palette...
        return; 
    oam_palette_free(tag);
    dprintf("Released palette %d with tag 0x%x\n", pal_idx, tag);
}


void overworld_effect_surfing_pokemon_setup_oam(u8 oam_idx) {
    // Only the setup-part for the surfing pokemon (the blob below the hiro)
    oam_object *o = oams + oam_idx;
    o->flags |= OAM_FLAG_CENTERED;
    o->private[2] = (u16)overworld_effect_state.height;
    o->private[3] = 0;
    o->private[6] = 0xFFFF;
    o->private[7] = 0xFFFF;
    // Allocate (or rather match) the player palette
    // This oam has a tag of 0xFFFF so that it can't kill the player palette once it despawns...
    u8 pal_idx = overworld_npc_palette_load(0x1100);
    o->final_oam.attr2 = (u16)((pal_idx << 12) | (o->final_oam.attr2 & ~(15 << 12)));
}

oam_object *overworld_effect_fly_allocate_pal(u8 oam_idx) { // Probably for fly...
    oam_object *o = oams + oam_idx;
    u8 pal_idx = overworld_npc_palette_load(0x1100);
    o->final_oam.attr2 = (u16)((pal_idx << 12) | (o->final_oam.attr2 & ~(15 << 12)));
    return o; // We return this so that we can remove more code for the patch... (ugly, hacky, call it whatever you want...)
}

static const u16 overworld_effect_shadow_vertical_offsets[4] = {4, 4, 4, 16,};
static const u8 overworld_effect_shadow_template_idxs[4] = {0, 1, 2, 3};

u32 overworld_effect_shadow(void) {
    u8 npc_idx = npc_get_by_person_idx((u8)(overworld_effect_state.x), (u8)(overworld_effect_state.y), (u8)(overworld_effect_state.height));
    overworld_sprite *ow = overworld_get(npcs[npc_idx].sprite);
    u8 oam_idx = oam_new_backward_search(overworld_effect_oam_templates[overworld_effect_shadow_template_idxs[ow->shadow_size]], 0, 0, 0x94);
    if (oam_idx != 64) {
        oam_object *o = oams + oam_idx;
        o->flags |= OAM_FLAG_CENTERED;
        o->private[0] = (u16)overworld_effect_state.x;
        o->private[1] = (u16)overworld_effect_state.y;
        o->private[2] = (u16)overworld_effect_state.height;
        o->private[3] = (u16)((ow->height / 2) - overworld_effect_shadow_vertical_offsets[ow->shadow_size]);
        u8 pal_idx = overworld_npc_palette_load(0x1100);
        dprintf("Shadow effect found palette at %d\n", pal_idx);
        o->final_oam.attr2 = (u16)((pal_idx << 12) | (o->final_oam.attr2 & ~(15 << 12)));
    }
    return 0;
}


void overworld_effect_emotion_bubble_start(oam_object *o, u16 arg2, u8 anim_idx) {
    u8 pal_idx = overworld_npc_palette_load(0x1100);
    o->final_oam.attr2 = (u16)((pal_idx << 12) | (o->final_oam.attr2 & ~(15 << 12)));
    o->flags |= OAM_FLAG_CENTERED;
    o->private[0] = (u16)overworld_effect_state.x;
    o->private[1] = (u16)overworld_effect_state.y;
    o->private[2] = (u16)overworld_effect_state.height;
    o->private[6] = 0xFFFB;
    o->private[7] = arg2;
    oam_gfx_anim_start(o, anim_idx);
}

void overworld_effect_show_warp_arrow(u8 oam_idx, u8 direction, s16 x, s16 y) {
    // dprintf("Arrow at %d, %d\n", x, y);
    oam_object *o = oams + oam_idx;
    if ((o->flags & OAM_FLAG_INVISIBLE) || (s16)(o->private[0]) != x || (s16)(o->private[1]) != y) { // This is a super hacky way by the game engine to check if there already is an arrow...
        s16 oam_x = 0, oam_y = 0;
        map_position_to_oam_position((s16)x, (s16)y, &oam_x, &oam_y);
        o->x = (s16)(oam_x + 8);
        o->y = (s16)(oam_y + 8);
        dprintf("Create arrow with screen coordinates. %d, %d", oam_x, oam_y);
        o->flags &= (u16)(~(OAM_FLAG_INVISIBLE));
        o->private[0] = (u16)x;
        o->private[1] = (u16)y;
        u8 pal_idx = overworld_npc_palette_load(0x1100);
        o->final_oam.attr2 = (u16)((pal_idx << 12) | (o->final_oam.attr2 & ~(15 << 12)));
        oam_gfx_anim_start(o, (u8)(direction - 1));
    }
}

extern oam_template oam_template_item_finder_arrow;

void itemfinder_create_arrow_sprite(u8 anim_idx, u8 direction) {
    dprintf("Item finder create arrow in direction %d\n", direction);
    u8 oam_idx = oam_new_forward_search(&oam_template_item_finder_arrow, 120, 76, 0);
    oam_object *o = oams + oam_idx;
    oam_gfx_anim_start(o, anim_idx);
    o->private[7] = anim_idx;
    o->private[0] = 0;
    o->private[3] = 0;
    o->private[4] = 0;
    o->private[5] = 120;
    o->private[6] = 76;
    switch (direction) {
        case DIR_NONE: {
            switch(player_get_facing()) {
                case DIR_LEFT:
                    o->private[1] = (u16)(-100);
                    o->private[2] = 0;
                    oam_rotscale_anim_init(o, 0);
                    break;
                case DIR_UP:
                    o->private[1] = 0;
                    o->private[2] = (u16)(-100);
                    oam_rotscale_anim_init(o, 3);
                    break;
                case DIR_RIGHT:
                    o->private[1] = (u16)(100);
                    o->private[2] = 0;
                    oam_rotscale_anim_init(o, 2);
                    break;
                case DIR_DOWN:
                    o->private[1] = 0;
                    o->private[2] = (u16)(100);
                    oam_rotscale_anim_init(o, 1);
                    break;
            }
            break;
        }
        case DIR_DOWN:
            o->private[1] = 0;
            o->private[2] = (u16)(-100);
            oam_rotscale_anim_init(o, 3);
            break;
        case DIR_UP:
            o->private[1] = (u16)(100);
            o->private[2] = 0;
            oam_rotscale_anim_init(o, 2);
            break;
        case DIR_LEFT:
            o->private[1] = 0;
            o->private[2] = (u16)(100);
            oam_rotscale_anim_init(o, 1);
            break;
        case DIR_RIGHT:
            o->private[1] = (u16)(-100);
            o->private[2] = 0;
            oam_rotscale_anim_init(o, 0);
            break;
    }
}

void item_finder_oam_callback_star(oam_object *self);

u8 item_finder_create_star() {
    u8 oam_idx = oam_new_forward_search(&oam_template_item_finder_arrow, 120, 76, 0);
    oam_object *o = oams + oam_idx;
    o->callback = item_finder_oam_callback_star;
    oam_gfx_anim_start(o, 4);
    o->private[7] = 0;
    o->private[0] = 0;
    o->private[3] = 0;
    o->private[4] = 0;
    o->private[5] = 120;
    o->private[6] = 76;
    o->private[1] = 0;
    o->private[2] = (u16)(-100);
    return oam_idx;
}

extern graphic graphic_item_finder_arrow;
extern color_t gfx_item_finder_arrowPal[];

static palette palette_item_finder_arrow = {
    .pal = gfx_item_finder_arrowPal, .tag = 2000,
};

void item_finder_load_gfx_and_pal() {
    oam_load_graphic_uncompressed(&graphic_item_finder_arrow);
    oam_palette_load_if_not_present(&palette_item_finder_arrow);
}

void item_finder_free_gfx_and_pal() {
    oam_palette_free(2000);
    oam_free_vram_by_tag(2000);
}