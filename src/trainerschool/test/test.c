#include "types.h"
#include "romfuncs.h"
#include "save.h"
#include "callbacks.h"
#include "starterselection.h"
#include "bg.h"
#include "utils.h"
#include "text.h"
#include "superstate.h"
#include "oams.h"
#include "debug.h"


bg_config trainerschool_test_bg_configs[3] = {
    {0, 2, 31, 0, 0, 1}, //text on bg0
    {1, 1, 30, 0, 0, 0}, //bg1 is above bg0 to show paper sliding
    {2, 0, 29, 0, 0, 2}
};

tboxdata trainerschool_test_tboxes [] = {
    {0, 8, 1, 12, 8, 0, 1}, //0 := question
    {0, 9, 10, 14, 2, 0, 97}, //1 + x = answer x
    {0, 9, 12, 14, 2, 0, 125},
    {0, 9, 14, 14, 2, 0, 153},
    {0, 9, 16, 14, 2, 0, 181},
    {0, 9, 18, 14, 2, 0, 209},
    {0xFF, 0, 0, 0, 0, 0, 0}
};

extern const short gfx_trainerschool_page_0Tiles[];
extern const short gfx_trainerschool_page_0Map[];
extern const short gfx_trainerschool_page_1Tiles[];
extern const short gfx_trainerschool_page_1Map[];
extern const short gfx_trainerschool_page_2Tiles[];
extern const short gfx_trainerschool_page_2Map[];
extern const short gfx_trainerschool_paperTiles[];
extern const short gfx_trainerschool_paperMap[];
extern const short gfx_trainerschool_paperPal[];
extern const short gfx_trainerschool_correctTiles[];
extern const short gfx_trainerschool_correctPal[];
extern const short gfx_trainerschool_wrongTiles[];

u8 trainerschool_test_fontcolmap_std[4] = {
    0, 6, 7, 3
};

graphic trainerschool_test_graphic_correct = {
    &gfx_trainerschool_correctTiles,
    0x800,
    0xA0E0
};

graphic trainerschool_test_graphic_wrong = {
    &gfx_trainerschool_wrongTiles,
    0x800,
    0xA0E1
};

sprite trainerschool_test_sprite = {
    ATTR0_SHAPE_SQUARE | ATTR0_ROTSCALE | ATTR0_DSIZE, 
    ATTR1_SIZE_64_64, 
    ATTR2_PRIO(0), 
    0
};


rotscale_frame trainerschool_test_rotscal_anim[] = {
    {0x200, 0x200, 0, 0, 0}, {-36, -36, 0, 12, 0}, {ROTSCAL_ANIM_END, 0, 0, 0, 0} 
};

rotscale_frame *trainerschool_test_rotscale_table[] = {trainerschool_test_rotscal_anim};


oam_template trainerschool_test_oam_template_correct = {
    0xA0E0, 0xA0E0,
    &trainerschool_test_sprite,
    GFX_ANIM_TABLE_NULL,
    NULL,
    trainerschool_test_rotscale_table,
    oam_null_callback,
};

oam_template trainerschool_test_oam_template_wrong = {
    0xA0E1, 0xA0E0,
    &trainerschool_test_sprite,
    GFX_ANIM_TABLE_NULL,
    NULL,
    trainerschool_test_rotscale_table,
    oam_null_callback,
};

extern u8 str_trainerschool_test_list[];
extern u8 str_trainerschool_test_cursor[];

void trainerschool_test_load_answers(){
    u8 question = fmem->tst_mem->current_question;
    dprintf("Question %d\n", question);
    int i;
    for(i = 0; i < 5; i++){
        dprintf("Printing answer %d\n", i);
        tbox_flush((u8)(i + 1), 0);
        tbox_tilemap_draw((u8)(i + 1));
        
        if(i < trainerschool_test_questions[question].answer_cnt){
            strcpy(strbuf, 
                    fmem->tst_mem->cursor == i ? str_trainerschool_test_cursor :
                    str_trainerschool_test_list);
            str_append(strbuf, trainerschool_test_questions[question].answers[i]);
            tbox_print_string((u8)(i + 1), 2, 0, 0, 0, 0, 
                    trainerschool_test_fontcolmap_std, 0, 
                    strbuf);
            
        }else{
            dprintf("clearing answer %d\n", i);
            //tbox_flush_map((u8)(i + 1));
            u8 str_none[] = {0xFF};
            tbox_print_string((u8)(i + 1), 2, 0, 0, 0, 0, 
                    trainerschool_test_fontcolmap_std, 0, 
                    str_none);
        }
    }
}

void trainerschool_test_load_question(){
    u8 question = fmem->tst_mem->current_question;
    fmem->tst_mem->cursor = 0;
    //Print question
    
    tbox_flush(0, 0);
    tbox_tilemap_draw(0);
    tbox_print_string(0, 2, 0, 0, 0, 0, trainerschool_test_fontcolmap_std, 0, 
            trainerschool_test_questions[question].question);
    trainerschool_test_load_answers();
}

void trainerschool_test_done(){
    cb1handling();
    if(!is_fading()){
        clearflag(MAP_BGN_AUTO_ALIGN_OFF);   
        *((bool*) 0x03000EA8) = false;
        set_callback1(map_reload);
    }
}

void trainerschool_test_question_done(){
    cb1handling();
    if(fmem->tst_mem->delay) fmem->tst_mem->delay--;
    else{
        switch(fmem->tst_mem->frame){
            case 0:
                fmem->tst_mem->current_question++;
                if(fmem->tst_mem->current_question == 10){
                    init_fadescreen(1, 0);
                    set_callback1(trainerschool_test_done);
                    return;
                }
                trainerschool_test_load_question(); //load next question
                sound(30);
                bg_sync_display_and_show(1);
                bg_display_sync();
                oam_rs_free(&oams[fmem->tst_mem->answer_oam]);
                clear_oam_entry(&oams[fmem->tst_mem->answer_oam]);
                lz77uncompwram(gfx_trainerschool_page_0Tiles, gp_tmp_buf);
                lz77uncompwram(gfx_trainerschool_page_0Map, bg_get_tilemap(1));
                bg_copy_vram(1, gp_tmp_buf, 0x1000, 0, 1);
                bg_copy_vram(1, bg_get_tilemap(1), 0x800, 0, 2);
                fmem->tst_mem->delay = 10;
                fmem->tst_mem->frame++;
                break;
            case 1:
                lz77uncompwram(gfx_trainerschool_page_1Tiles, gp_tmp_buf);
                lz77uncompwram(gfx_trainerschool_page_1Map, bg_get_tilemap(1));
                bg_copy_vram(1, gp_tmp_buf, 0x1000, 0, 1);
                bg_copy_vram(1, bg_get_tilemap(1), 0x800, 0, 2);
                fmem->tst_mem->delay = 10;
                fmem->tst_mem->frame++;
                break;
            case 2:
                lz77uncompwram(gfx_trainerschool_page_2Tiles, gp_tmp_buf);
                lz77uncompwram(gfx_trainerschool_page_2Map, bg_get_tilemap(1));
                bg_copy_vram(1, gp_tmp_buf, 0x1000, 0, 1);
                bg_copy_vram(1, bg_get_tilemap(1), 0x800, 0, 2);
                fmem->tst_mem->delay = 10;
                fmem->tst_mem->frame++;
                break;
            default:
                bg_hide(1);
                bg_display_sync();
                set_callback1(trainerschool_test_idle);
                break;
        }
    }
}


void trainerschool_test_idle(){
    cb1handling();
    if(super->keys_new.keys.down){
        fmem->tst_mem->cursor++;
        fmem->tst_mem->cursor = 
        (u8)(fmem->tst_mem->cursor %
                trainerschool_test_questions[fmem->tst_mem->current_question].answer_cnt);
        sound(5);
        trainerschool_test_load_answers();
    }else if(super->keys_new.keys.up){
        if(!fmem->tst_mem->cursor)fmem->tst_mem->cursor = (u8)
                (trainerschool_test_questions[fmem->tst_mem->current_question].answer_cnt - 1);
        else fmem->tst_mem->cursor--;
        sound(5);
        trainerschool_test_load_answers();
    }else if(super->keys_new.keys.A){
        s16 y = (s16)(fmem->tst_mem->cursor * 16 + 83);
        u8 question = fmem->tst_mem->current_question;
        if(trainerschool_test_questions[question].correct_answer == fmem->tst_mem->cursor){
            //correct answer
            fanfare(269);
            sound(12);
            (*vardecrypt(TRAINERSCHOOL_CORRECT_ANSWERS))++;
            fmem->tst_mem->answer_oam = generate_oam_forward_search(
                &trainerschool_test_oam_template_correct, 168, y, 0);
            fmem->tst_mem->delay = 0xC0;
            fmem->tst_mem->frame = 0;
            set_callback1(trainerschool_test_question_done);
        }else{
            fanfare(271);
            sound(12);
            fmem->tst_mem->answer_oam = generate_oam_forward_search(
                &trainerschool_test_oam_template_wrong, 168, y, 0);
            fmem->tst_mem->delay = 0xC0;
            fmem->tst_mem->frame = 0;
            set_callback1(trainerschool_test_question_done);
        }
    }
}

void trainerschool_test_init_components(){
    cb1handling();
    if(!is_fading()){
        //init gfx and stuff
        
        remove_all_big_callbacks();
        oam_reset();
        pal_allocation_reset();
        bg_reset(0);
        bg_setup(0, trainerschool_test_bg_configs, 3);
        
        bg_sync_display_and_show(0);
        bg_sync_display_and_show(1);
        bg_sync_display_and_show(2);
        bg_display_sync();
        bg_virtual_map_displace(0, 0, 0);
        bg_virtual_set_displace(0, 0, 0);
        bg_virtual_map_displace(1, 0, 0);
        bg_virtual_set_displace(1, 0, 0);
        bg_virtual_map_displace(2, 0, 0);
        bg_virtual_set_displace(2, 0, 0);
        set_io(0x10, 0);
        set_io(0x12, 4);
        set_io(0x14, 0);
        set_io(0x16, 0);
        set_io(0x18, 0);
        set_io(0x1A, 0);
        
        void *bg0map = cmalloc(0x800);
        void *bg1map = cmalloc(0x800);
        void *bg2map = cmalloc(0x800);
        
        bg_set_tilemap(0, bg0map);
        bg_set_tilemap(1, bg1map);
        bg_set_tilemap(2, bg2map);
        
        lz77uncompwram(gfx_trainerschool_paperMap, bg2map);
        lz77uncompvram(gfx_trainerschool_paperTiles, (void*) 0x06000000);
        lz77uncompvram(gfx_trainerschool_page_0Tiles, (void*) 0x06004000);
        bg_copy_vram(0, bg0map, 0x800, 0, 2);
        bg_copy_vram(1, bg1map, 0x800, 0, 2);
        bg_copy_vram(2, bg2map, 0x800, 0, 2);
        pal_load_comp(gfx_trainerschool_paperPal, 0, 32);
        u8 pal_id = allocate_obj_pal(0xA0E0);
        pal_load_comp(gfx_trainerschool_correctPal, (u16)(256 + pal_id * 16), 32);
        pal_set_all_to_black(); //we avoid the 1frame show of a pal
        

        tbox_sync_with_virtual_bg_and_init_all(trainerschool_test_tboxes);
        trainerschool_test_load_question();
        
        load_and_alloc_obj_vram_lz77(&trainerschool_test_graphic_correct);
        load_and_alloc_obj_vram_lz77(&trainerschool_test_graphic_wrong);
        
        init_fadescreen(0, 0);
        set_callback1(trainerschool_test_idle);

        bg_virtual_sync(0);
        bg_virtual_sync(1);
        bg_virtual_sync(2);
    }
}

void trainerschool_test_init(){
    cb1handling();
    *vardecrypt(TRAINERSCHOOL_CORRECT_ANSWERS) = 0;
    fmem->tst_mem = (trainerschool_test_memory*) cmalloc(sizeof(trainerschool_test_memory));
    fmem->tst_mem->current_question = 0;
    init_fadescreen(1, 0);
    set_callback1(trainerschool_test_init_components);
    setflag(MAP_BGN_AUTO_ALIGN_OFF);
}

