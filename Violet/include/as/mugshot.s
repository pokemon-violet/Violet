.include "mugshot_character.s"
.include "mugshot_alignment.s"
.include "callstds.s"
.include "specials.s"

.macro load_mugshot person alignment=MUGSHOT_LEFT mask_name=0
    setvar 0x8000 \alignment
    setvar 0x8001 \person

    .if \mask_name == 0x1
        setvar 0x8002 0x0
    .else
        setvar 0x8002 0x1
    .endif
.endm

.macro call_draw_mugshot
    special SPECIAL_MUGSHOT_SHOW
.endm

.macro call_hide_mugshot
    special SPECIAL_MUGSHOT_DELETE
    waitstate
.endm

.macro show_mugshot_message message_type=MSG
    call_draw_mugshot
    callstd \message_type
    call_hide_mugshot
.endm

.macro draw_mugshot person alignment=MUGSHOT_LEFT mask_name=0
    load_mugshot \person \alignment \mask_name
    call_draw_mugshot
.endm


.macro hide_mugshot
    call_hide_mugshot
.endm

.macro show_mugshot person alignment=MUGSHOT_LEFT message_type=MSG mask_name=0
    load_mugshot \person \alignment \mask_name
    show_mugshot_message \message_type
.endm

.macro msgbox_with_name message:req name:req alignment=MUGSHOT_LEFT message_type=MSG
    setvar 0x8000 \alignment
    loadpointer 0 \name
    special SPECIAL_NAME_SHOW
    loadpointer 0 \message
    callstd \message_type
    special SPECIAL_NAME_DELETE
    waitstate
.endm 
