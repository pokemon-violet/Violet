#include "types.h"
#include "map/footer.h"
#include "bg.h"
#include "tile/block.h"
#include "overworld/map_control.h"

void map_draw_block_to_bg(u8 layer_type, u16 *blocks, u16 offset) {
    // The layer priority (bottom to top) is 3, 1, 2
    if (layer_type == 0xFF) { // Doors, TODO        
        overworld_bg3_tilemap[offset] = blocks[0];
        overworld_bg3_tilemap[offset + 1] = blocks[1];
        overworld_bg3_tilemap[offset + 32] = blocks[2];
        overworld_bg3_tilemap[offset + 32 + 1] = blocks[3];
        
        overworld_bg2_tilemap[offset] = 0;
        overworld_bg2_tilemap[offset + 1] = 0;
        overworld_bg2_tilemap[offset + 32] = 0;
        overworld_bg2_tilemap[offset + 32 + 1] = 0;

        overworld_bg1_tilemap[offset] = blocks[4];
        overworld_bg1_tilemap[offset + 1] = blocks[5];
        overworld_bg1_tilemap[offset + 32] = blocks[6];
        overworld_bg1_tilemap[offset + 32 + 1] = blocks[7];
    } else {

        overworld_bg3_tilemap[offset] = blocks[0];
        overworld_bg3_tilemap[offset + 1] = blocks[1];
        overworld_bg3_tilemap[offset + 32] = blocks[2];
        overworld_bg3_tilemap[offset + 32 + 1] = blocks[3];
        
        overworld_bg2_tilemap[offset] = blocks[4];
        overworld_bg2_tilemap[offset + 1] = blocks[5];
        overworld_bg2_tilemap[offset + 32] = blocks[6];
        overworld_bg2_tilemap[offset + 32 + 1] = blocks[7];

        overworld_bg1_tilemap[offset] = blocks[8];
        overworld_bg1_tilemap[offset + 1] = blocks[9];
        overworld_bg1_tilemap[offset + 32] = blocks[10];
        overworld_bg1_tilemap[offset + 32 + 1] = blocks[11];
    }
    bg_virtual_sync_reqeust_push(1);
    bg_virtual_sync_reqeust_push(2);
    bg_virtual_sync_reqeust_push(3);
}

void map_draw_block_at_position(map_footer_t *f, u16 offset, s16 x, s16 y) {
    u16 block_idx = block_get_by_pos(x, y);
    if (block_idx >= 1024)
        block_idx = 0;
    u16 *blocks;
    if (block_idx < 0x280) 
        blocks = (u16*)f->tileset1->blocks;
    else {
        blocks = (u16*)f->tileset2->blocks;
        block_idx = (u16)(block_idx - 0x280);
    }
    map_draw_block_to_bg(0, blocks + 12 * block_idx, offset);
}

void map_draw_door_at(s16 x, s16 y, u16 *block_tilemaps) {
    int offset = map_position_to_bg_tilemap_offset(&map_displ_cntrl, x, y);
    if (offset >= 0) {
        map_draw_block_to_bg(0xFF, block_tilemaps, (u16)offset);
    }
}