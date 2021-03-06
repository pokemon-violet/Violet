.include "vars.s"
.include "movements.s"
.include "specials.s"
.include "songs.s"
.include "callstds.s"
.include "flags.s"
.include "roamers.s"
.include "overworld_script.s"
.include "species.s"

.global ow_script_0x963073
.global ow_script_map_1_30_trigger_0
.global ow_script_0x963082
ow_script_movs_0x801223:
.byte LOOK_UP
.byte STOP


ow_script_movs_0x9630a8:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


ow_script_map_1_30_trigger_0:
lockall
applymovement 0xff ow_script_movs_0x801223
waitmovement 0x0
cry POKEMON_LAVADOS 0x0
fadesong 0
pause 0x40
special 0x113
applymovement 0x7f ow_script_movs_0x9630a8
waitmovement 0x0
showpokepic POKEMON_LAVADOS 0x8 0x2
loadpointer 0x0 str_0x963098
callstd MSG
hidepokepic
call ow_script_0x963073
call ow_script_0x963073
call ow_script_0x963082
call ow_script_0x963082
call ow_script_0x963082
call ow_script_0x963082
call ow_script_0x963082
cry POKEMON_LAVADOS 0x0
showpokepic POKEMON_LAVADOS 0x8 0x2
loadpointer 0x0 str_0x96305b
callstd MSG
hidepokepic
pause 0x40
sound 0x80
applymovement 0x9 ow_script_movs_0x8e1959
waitmovement 0x0
special 0x114
setvar 0x8004 POKEMON_LAVADOS
special SPECIAL_SET_AS_SEEN
setvar 0x8004 ROAMER_LAVADOS
special SPECIAL_ROAMER_RESET_AND_INITIALIZE
hidesprite 0x9
addvar ASCHHAIN_LAVADOS_VAR 0x1
playsong MUS_LAVA 0x0
releaseall
end


ow_script_0x963082:
sound 0x96
applymovement 0x7f ow_script_movs_0x94be33
applymovement 0x9 ow_script_movs_0x94be33
waitmovement 0x0
return


ow_script_0x963073:
sound 0x96
applymovement 0x9 ow_script_movs_0x94be33
waitmovement 0x0
return


ow_script_movs_0x8e1959:
.byte 0xa4
.byte STOP

ow_script_movs_0x94be33:
.byte STEP_DOWN_VERY_SLOW
.byte STOP

.ifdef LANG_GER

str_0x963098:
    .string "Grueeeeh! DOTS"



str_0x96305b:
    .string "Gyahhh! Gyaaaaahhhhh!"


.elseif LANG_EN

.endif