#include "../../header/dungeon_generator.h"
#include "../../header/map.h"
#include "../../header/types.h"
#include "../../header/save.h"
#include "../../header/romfuncs.h"

typedef struct neighbours{
	u8 down;
	u8 up;
	u8 left;
	u8 right;
} neighbours;

union union_neighbours{
	neighbours n;
	u32 value;
};

extern int abs (int i);
extern int signum (int i);

void compute_dungeon_blocks();
void compute_dungeon_rooms(dungeon_generator *d);
void compute_dungeon_paths(dungeon_generator *d);
void compute_dungeon_tiles(dungeon_generator *d);
void compute_dungeon_events(dungeon_generator *d);

void set_block(s16 x, s16 y, dungeon_generator *d);
bool get_block(s16 x, s16 y, dungeon_generator *d);

void dungeon_room_get_neighbours (union union_neighbours *drn, union union_neighbours *npn, dungeon_generator *d, u32 current_room);
u8 dungeon_pick_room (union union_neighbours n, dungeon_generator *d);
void dungeon_connect_rooms(u8 first, u8 second, dungeon_generator *d);

u32 random_next32 (dungeon_generator *d);
u16 random_next16 (dungeon_generator *d);
u8 random_next8 (dungeon_generator *d);



void compute_dungeon_rooms(dungeon_generator *d){
	u32 i;
	
	u32 rooms_max = (u32)(d->rooms_per_line * d->rooms_per_row); 
	d->rooms = (room*)malloc(sizeof(room) * rooms_max);
	
	//calculate room size
	u32 hsegment_cnt = (u32)(d->rooms_per_line * 2 - 1);
	u32 vsegment_cnt = (u32)(d->rooms_per_row * 2 - 1);
	u32 hsegment_size = (u32)(d->width / hsegment_cnt);
	u32 vsegment_size = (u32)(d->height / vsegment_cnt);
	

	u16 room_asize_x =(u16)((u16)(d->width-4) / hsegment_cnt);
	u16 room_asize_y =(u16)((u16)(d->height-4) /vsegment_cnt);
	
	u32 rooms_built;
	do{
		
		rooms_built = 0;
		
		//now we build the rooms
		for (i = 0; i < rooms_max; i++){
			
			//room parameters are calculated
			d->rooms[i].width = (u16)(room_asize_x - (random_next8(d) & 3) + 2);
			d->rooms[i].height = (u16)(room_asize_y - (random_next8(d) & 3) + 2);
			
			//for the x and y coordinates it gets tricky, the segment id is 2 * i
			u32 room_y = i / (d->rooms_per_line);
			u32 room_x = __umod( (u32)i, d->rooms_per_line);
			
			d->rooms[i].roomx = (u8) room_x;
			d->rooms[i].roomy = (u8) room_y;
			d->rooms[i].x = (s16)(room_x * 2 * hsegment_size + 1);
			d->rooms[i].y = (s16)(room_y * 2 * vsegment_size + 1);
			
			d->rooms[i].connector_x = (s16)(d->rooms[i].x + (int)__umod(random_next8(d), (u32)(d->rooms[i].width)));
			d->rooms[i].connector_y = (s16)(d->rooms[i].y + (int)__umod(random_next8(d), (u32)(d->rooms[i].height)));
				
			d->rooms[i].region = (u8)rooms_built;
			
			//decide weather to build a room
			if (random_next8(d) <= d->room_frequency){
				
				//room will be built
				d->rooms[i].presence = true;
				//(*((u16*)0x020370D0))++;
				rooms_built++;
				
			}else{
				d->rooms[i].presence = false;
				d->rooms[i].region = 0xFE;
			}
		}
		
	}while(rooms_built < (d->min_rooms));
	d->regions = (u8)rooms_built;
	
	//Now we draw rooms
	for (i = 0; i < rooms_max; i++){
		if (d->rooms[i].presence){
			int x, y;
			for (x = 0; x < d->rooms[i].width; x++){
				for (y = 0; y < d->rooms[i].height; y++){
					set_block((s16)(d->rooms[i].x + x), (s16)(d->rooms[i].y + y), d);
				}
			}
		}
	}
	
}

u8 room_coordinate_to_index (u8 x, u8 y, dungeon_generator *d){
	return (u8)(y * d->rooms_per_line + x);
}

void compute_dungeon_paths(dungeon_generator *d){
		
	//first we pick a random room to start with
	u32 rooms_max = (u32)(d->rooms_per_line * d->rooms_per_row);
	u32 current_room;
	do{
		current_room = __umod(random_next32(d), rooms_max);
		
	}while(!(d->rooms[current_room].presence));
	
	union union_neighbours different_region_neighbours = {{0xFF, 0xFF, 0xFF, 0xFF}}; //all neighbours that have a different region
	union union_neighbours not_present_neighbours = {{0xFF, 0xFF, 0xFF, 0xFF}}; //all neighbours that are not a room but could be expanded into one
	
	//now we collect the neighbours with different regions and not present neighbours
	
	while (d->regions > 1){
		different_region_neighbours.value = 0xFFFFFFFF;
		not_present_neighbours.value = 0xFFFFFFFF;
		dungeon_room_get_neighbours(&different_region_neighbours, &not_present_neighbours, d, current_room);
		
		//we connect rooms
		if (different_region_neighbours.value != 0xFFFFFFFF){
			//we have different region neighbours
			u8 target = dungeon_pick_room(different_region_neighbours, d);
			
			dungeon_connect_rooms((u8)current_room, target, d);
			
			current_room = target;
			d->regions--;
			
		}else if (not_present_neighbours.value != 0xFFFFFFFF){
			//we have no different region neighbours, so we expand a neighbour into a one tile room
			u8 target = dungeon_pick_room(not_present_neighbours, d);
			d->rooms[target].presence = true;
			d->rooms[target].width = 1;
			d->rooms[target].height = 1;
			d->rooms[target].x = d->rooms[target].connector_x;
			d->rooms[target].y = d->rooms[target].connector_y;
			d->rooms[target].region = d->rooms[current_room].region;
			
			dungeon_connect_rooms((u8)current_room, target, d);
			current_room = target;
			set_block((s16)(d->rooms[target].x), (s16)(d->rooms[target].y), d);
			
		}else{
			
			//Algorithm reached dead end, rechoice of current room
			do{
				current_room = __umod(random_next32(d), rooms_max);
			}while(!(d->rooms[current_room].presence));
		}
		
	}
}


// picks a random room from availible neighbour list
u8 dungeon_pick_room (union union_neighbours n, dungeon_generator *d){
	int choice;
	while(true){
		choice = random_next8(d) & 3;
		switch(choice){
			case 0:
				if (n.n.down != 0xFF){return n.n.down;}
				break;
			case 1:
				if (n.n.up != 0xFF){return n.n.up;}
				break;
			case 2:
				if (n.n.left != 0xFF){return n.n.left;}
				break;
			case 3:
				if (n.n.right != 0xFF){return n.n.right;}
				break;
		}
	}
	return 0xFF;
}

void dungeon_connect_rooms(u8 first, u8 second, dungeon_generator *d){
	
	//while (second == 5 || first == 5){}
	
	//First we merge the regions by replacing all occurences of the second region with the first one
	int i;
	u8 rfirst = d->rooms[first].region, rsecond = d->rooms[second].region;
	for (i = 0; i < (d->rooms_per_line * d->rooms_per_row); i++){
		if ((d->rooms[i].region) == rsecond){
			d->rooms[i].region = rfirst;
		}
	}
	
	int dx = d->rooms[second].connector_x - d->rooms[first].connector_x;
	int dy = d->rooms[second].connector_y - d->rooms[first].connector_y;
	
	if (d->rooms[second].roomx != d->rooms[first].roomx){
		//horizontal connection line
		int y = d->rooms[second].connector_y;
		for (int x = 0; x != dx; x += signum(dx)){
			
			if ( abs(x) < abs(dx / 2) ){
				//proceed horizontal line drawing
				set_block((s16)(d->rooms[second].connector_x - x), (s16)(y), d);
			}else{
				if (y == d->rooms[second].connector_y){
					//we draw the vertical part
					for (; y != (d->rooms[first].connector_y); y -= signum(dy)){
						set_block((s16)(d->rooms[second].connector_x - x), (s16)(y), d);
					}
					set_block((s16)(d->rooms[second].connector_x - x), (s16)(y), d);
				}else{
					set_block((s16)(d->rooms[second].connector_x - x), (s16)(y), d);
				}
			}
			
		}
	}else{
		//vertical connection line
		int x = d->rooms[second].connector_x;
		for (int y = 0; y != dy; y += signum(dy)){
			
			if ( abs(y) < abs(dy / 2) ){
				//proceed horizontal line drawing
				set_block((s16)(x), (s16)(d->rooms[second].connector_y - y), d);
			}else{
				if (x == d->rooms[second].connector_x){
					//we draw the vertical part
					for (; x != (d->rooms[first].connector_x); x -= signum(dx)){
						set_block((s16)(x), (s16)(d->rooms[second].connector_y - y), d);
					}
					set_block((s16)(x), (s16)(d->rooms[second].connector_y - y), d);
				}else{
					set_block((s16)(x), (s16)(d->rooms[second].connector_y - y), d);
				}
			}
			
		} 
		
		
	}
	
	//shuffle connection points
	d->rooms[first].connector_x = (s16)((u32)d->rooms[first].x + __umod(random_next8(d), (u32)d->rooms[first].width));
	d->rooms[first].connector_y = (s16)((u32)d->rooms[first].y + __umod(random_next8(d), (u32)d->rooms[first].height));
	d->rooms[second].connector_x = (s16)((u32)d->rooms[second].x + __umod(random_next8(d), (u32)d->rooms[second].width));
	d->rooms[second].connector_y = (s16)((u32)d->rooms[second].y + __umod(random_next8(d), (u32)d->rooms[second].height));
	
}


void dungeon_room_get_neighbours (union union_neighbours *drn, union union_neighbours *npn, dungeon_generator *d, u32 current_room){
	
	drn->value = 0xFFFFFFFF;
	npn->value = 0xFFFFFFFF;
	
	u8 cix = d->rooms[current_room].roomx, ciy = d->rooms[current_room].roomy;
	u8 n;
	if (ciy > 0){ //UP
		n = room_coordinate_to_index(cix, (u8)(ciy-1), d);
		if (d->rooms[n].presence && d->rooms[n].region != d->rooms[current_room].region){
			drn->n.up = n;	
		}else if (!(d->rooms[n].presence)){
			npn->n.up = n;
		}
	}
	if (ciy < ( d->rooms_per_row - 1)){ //DOWN
		n = room_coordinate_to_index(cix, (u8)(ciy+1), d);
		if (d->rooms[n].presence && d->rooms[n].region != d->rooms[current_room].region){
			drn->n.down = n;	
		}else if (!(d->rooms[n].presence)){
			npn->n.down = n;
		}
	}
	if (cix > 0){ //LEFT
		n = room_coordinate_to_index((u8)(cix-1), ciy, d);
		if (d->rooms[n].presence && d->rooms[n].region != d->rooms[current_room].region){
			drn->n.left = n;	
		}else if (!(d->rooms[n].presence)){
			npn->n.left = n;
		}
	}
	if (cix < (d->rooms_per_line - 1)){ //RIGHT
		n = room_coordinate_to_index((u8)(cix+1), ciy, d);
		if (d->rooms[n].presence && d->rooms[n].region != d->rooms[current_room].region){
			drn->n.right = n;	
		}else if (!(d->rooms[n].presence)){
			npn->n.right = n;
		}
	}	
}

void set_block(s16 x, s16 y, dungeon_generator *d){
	
	int index = y * d->width + x;
	u8 mask = (u8)(1 << (index & 7));
	d->dbuf[(u16)(index/8)] |= mask;
	
}

bool get_block (s16 x, s16 y, dungeon_generator *d){
	int index = y * d->width + x;
	int mask = 1 << (index & 7);
	if ((d->dbuf[index/8]) & mask){
		return true;
	}
	return false;
}

void compute_dungeon_tiles(dungeon_generator *d){
	
	s16 x, y;
	for (x = 0; x < d->width; x++){
		for (y = 0; y < d->height; y++){
			u16 block;
			if (get_block(x, y, d)){
				block = 0x2D9;
			}else{
				u8 r = random_next8(d);
				if (r < 0x10){
					block = (u16)(0xE82 + (r&1 ? 1 : 0));
				}else{
					block = (u16)(0x32A + __umod(random_next8(d), 8));
				}
			}
			set_block_id((s16)(x+7), (s16)(y+7), block);
		}
	}
	
}

void compute_dungeon_events(dungeon_generator *d){
	
	return;
	
	//setting up a warp
	u32 rooms_max = (u32)(d->rooms_per_line * d->rooms_per_row);
	u32 entrance;
	do{
		entrance = __umod(random_next8(d), rooms_max);
	}while(d->rooms[entrance].presence && d->rooms[entrance].width > 1 && d->rooms[entrance].height > 1); //pick a real room
	
	while(true){}
	
	//now we pick a random position that is not at rooms border
	s16 x = (s16)((u32)d->rooms[entrance].x + __umod(random_next8(d), (u32)(d->rooms[entrance].width - 2)));
	s16 y = (s16)((u32)d->rooms[entrance].y + __umod(random_next8(d), (u32)(d->rooms[entrance].height - 2)));
	
	dmem->ladder.x = x;
	dmem->ladder.y = y;
	dmem->ladder.field_4 = 0;
	dmem->ladder.target_warp_id = 3;
	dmem->ladder.target_map = 3;
	dmem->ladder.target_bank = 3;
	
	
}

void compute_dungeon_blocks(){
	
	if (dflags->blocks_initialized){
		//The blocks were already loaded, so we use the same seed
		dmem->dgen.seed = dmem->dgen.initial_seed;
	}
	
	dflags->blocks_initialized = 1;
	
	dungeon_generator *d = &(dmem->dgen);
	
	//build a buffer of flags that state if a tile is enabled or not
	d->dbuf = malloc_fill((u32)((d->width) * (d->height) / 8));
	
	
	//first we compute the dungeon
	compute_dungeon_rooms(d);
	compute_dungeon_paths(d);
	compute_dungeon_tiles(d);
	//compute_dungeon_events(d);
	
	
	foot_ddata->footer = &(dmem->footer);
	//special_x8E_update_map_graphics();
	
}





u32 random_next32 (dungeon_generator *d){
	return (u32)((random_next16(d) << 16) | random_next16(d));
}

u16 random_next16 (dungeon_generator *d){
	d->seed = (u32)(d->seed * 0x41C64E6D + 0x6073);
	return (u16)(d->seed >> 16);
}

u8 random_next8(dungeon_generator *d){
	return (u8)random_next16(d);
}