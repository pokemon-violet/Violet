.org 0x08098a78
    ldr r2, =item_get_resource | 1
    bx r2
    .pool

.org 0x0815F914 + (0x88*4)
    .word script_cmd_x88_pokemart3 | 1

.org 0x0809a988
    ldr r1, =item_idx_saniztize | 1
    bx r1
    .pool

//@Bike sound := 195
.org 0x080A1402
    mov r0, #195


//item table
.org 0x80001c8
	.word items


.org 0x809a9bc
	.word items


.org 0x809a9e0
	.word items


.org 0x809aa04
	.word items


.org 0x809aa28
	.word items


.org 0x809aa4c
	.word items


.org 0x809aa70
	.word items


.org 0x809aa94
	.word items


.org 0x809aab8
	.word items


.org 0x809aadc
	.word items


.org 0x809ab00
	.word items


.org 0x809ab24
	.word items


.org 0x809ab48
	.word items


.org 0x809ab6c
	.word items


.org 0x809ab90
	.word items
    
.org 0x803a1b0
	.word item_effects


.org 0x8041448
	.word item_effects


.org 0x8042424
	.word item_effects


.org 0x8042b30
	.word item_effects


.org 0x8042d3c
	.word item_effects


.org 0x812509c
	.word item_effects


.org 0x812579c
	.word item_effects


.org 0x8126d14
	.word item_effects


// r0-r3 are used already, so the hook is wrapped by something that saves r4
.org 0x080412e4
    push {r1}
    ldr r1, =fmem
    str r0, [r1]
    pop {r1}
    ldr r0, =item_effect_apply | 1
    bx r0
    .pool

    
// r0-r3 are used already, so the hook is wrapped by something that saves r4
.org 0x08042314
    push {r1}
    ldr r1, =fmem
    str r0, [r1]
    pop {r1}
    ldr r0, =item_effect_unapplicable | 1
    bx r0
    .pool


.org 0x08042b08
    ldr r3, =_item_effect_get_hp_healed_offset | 1
    bx r3
    .pool

.org 0x08126cb8
    ldr r1, = item_get_effect_type | 1
    bx r1
    .pool

.org 0x081250a8
    ldr r1, = item_effect_print_result | 1
    bx r1
    .pool

.org 0x08125adc
	.word tm_hm_to_attack

.org 0x08125afc
	.word tm_hm_to_attack

.org 0x080A13A4
	.word str_cant_dismount_cloud

// Prevent the player form dismounting the clound on underwater maps
.org 0x080A133E
	ldr r1, =cloud_not_dismountable | 1
	bl _bxr1
	ldr r1, =0x080A137E | 1
	bx r1
_bxr1:
	bx r1
	.pool

.org 0x08082ac8
    ldr r1, = fishing_create_pokemon | 1
    bx r1 
    .pool

.org 0x0805d2fc
    .word fishing_big_callback_bait | 1

.org 0x0813dc4c
    .word berry_pouch_callbacks

.org 0x0801bce4
    .word hook_battle_item_switch_in_effects

.org 0x0813dd18
    ldr r0, =berry_pouch_get_context_menu_options_standard_hook | 1
    bx r0 
    .pool
    
.org 0x0813dfc8
    ldr r0, =berry_pouch_toss_hook_print_string_how_many | 1
    bx r0
    .pool

.org 0x0813e020
    ldr r0, =berry_pouch_toss_hook_get_string_confirm_quantity_to_toss | 1
    bx r0
    .pool

.org 0x08465430
    .word berry_pouch_toss_or_compost_confirmed | 1

.org 0x08465460
    .word berry_pouch_context_menu_option_compost_text
    .word berry_pouch_context_menu_option_toss

