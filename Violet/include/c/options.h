#ifndef H_OPTIONS
#define H_OPTIONS

#include "types.h"
#include "save.h"

#define TWO_OPTIONS_STRINGS(symbol, name, first_option_name, first_option_description, second_option_name, second_option_description) \
    static u8 str_option_##symbol##_name[] = name; \
    static u8 str_option_##symbol##_option0_name[] = first_option_name; \
    static u8 str_option_##symbol##_option0_description[] = first_option_description; \
    static u8 str_option_##symbol##_option1_name[] = second_option_name; \
    static u8 str_option_##symbol##_option1_description[] = second_option_description; \
    static u8 *option_##symbol##_names[2] = {[0] = str_option_##symbol##_option0_name, [1] = str_option_##symbol##_option1_name }; \
    static u8 *option_##symbol##_descriptions[2] = {[0] = str_option_##symbol##_option0_description, [1] = str_option_##symbol##_option1_description };

#define THREE_OPTIONS_STRINGS(symbol, name, first_option_name, first_option_description, second_option_name, second_option_description, third_option_name, third_option_description) \
    static u8 str_option_##symbol##_name[] = name; \
    static u8 str_option_##symbol##_option0_name[] = first_option_name; \
    static u8 str_option_##symbol##_option0_description[] = first_option_description; \
    static u8 str_option_##symbol##_option1_name[] = second_option_name; \
    static u8 str_option_##symbol##_option1_description[] = second_option_description; \
    static u8 str_option_##symbol##_option2_name[] = third_option_name; \
    static u8 str_option_##symbol##_option2_description[] = third_option_description; \
    static u8 *option_##symbol##_names[3] = {[0] = str_option_##symbol##_option0_name, [1] = str_option_##symbol##_option1_name, [2] = str_option_##symbol##_option2_name }; \
    static u8 *option_##symbol##_descriptions[3] = {[0] = str_option_##symbol##_option0_description, [1] = str_option_##symbol##_option1_description, [2] = str_option_##symbol##_option2_description };

enum {
    OPTION_FRAME_STYLE = 0,
    OPTION_DNS_COLORS, 
    OPTION_AUTOMATIC_HM_USAGE,
    OPTION_DETECTOR,
    OPTION_TEXT_SPEED,
    OPTION_BATTLE_ANIMATIONS,
    OPTION_BATTLE_STYLE,
    OPTION_SOUND_STATE,
    NUM_OPTIONS,
};

typedef struct {
    u8 initialization_state;
    u8 callback_idx;
    u8 list_menu_callback_idx;
    u16 cursor_position;
    u16 cursor_above;
    list_menu_item list_menu_items[NUM_OPTIONS];
} options_state_t;


enum {
    OPTION_ON,
    OPTION_OFF,
};

typedef struct {
    u8 *name;
    u8 num_options;
    bool (*available)();
    void (*setter)(int);
    int (*getter)();
    u8 **options;
    u8 **option_descriptions;
} option_t;

option_t options[NUM_OPTIONS];

extern u8 gfx_options_uiTiles[];
extern u8 gfx_options_uiMap[];
extern u8 gfx_options_uiPal[];

#define OPTIONS_STATE ((options_state_t*)fmem.gp_state)

#endif