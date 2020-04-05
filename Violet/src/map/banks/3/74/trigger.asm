.include "ordinals.s"
.include "vars.s"
.include "movements.s"
.include "songs.s"
.include "callstds.s"
.include "mugshot.s"
.include "flags.s"
.include "overworld_script.s"
.include "items.s"

.global ow_script_0x8e33a7
.global ow_script_0x8e63a6
.global ow_script_0x8fb3fe
.global ow_script_map_3_74_trigger_0
.global ow_script_0x8e33bb
.global ow_script_0x8e63b7

ow_script_movs_0x8e63b5:
.byte STEP_RIGHT
.byte STOP


ow_script_movs_0x8e63a3:
.byte LOOK_LEFT
.byte STOP


ow_script_movs_0x8e639b:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


ow_script_map_3_74_trigger_0:
lockall
clearflag PKMNMENU
showsprite 0x11
setflag PKMNMENU
playsong MUS_RIVALE_ERSCHEINT_GARY 0x0
applymovement 0x11 ow_script_movs_0x8e63b5
waitmovement 0x0
getplayerpos 0x8000 0x8001
compare 0x8001 0x9
callif HIGHER_OR_EQUAL ow_script_0x8e63a6
compare 0x8001 0xa
callif HIGHER_OR_EQUAL ow_script_0x8e63a6
applymovement 0xff ow_script_movs_0x8e63a3
waitmovement 0x0
applymovement 0x11 ow_script_movs_0x8e639b
waitmovement 0x0
goto ow_script_0x8fb3fe


ow_script_0x8fb3fe:
draw_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
compare STARTER_SELECTED 0x0
gotoif EQUAL ow_script_0x8e33a7
compare STARTER_SELECTED 0x1
gotoif EQUAL ow_script_0x8e33bb
trainerbattlecont 0x1 0xbb 0x0 str_0x8e627c str_0x8e6231 ow_script_0x8e63b7


ow_script_0x8e63b7:
loadpointer 0x0 str_0x8e6164
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
setflag DETEKTOR_ID
copyvarifnotzero 0x8000 ITEM_DETEKTOR
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
loadpointer 0x0 str_0x9681e9
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
fadescreen 0x1
hidesprite 0x11
fadescreen 0x0
addvar STORY_PROGRESS 0x1
releaseall
end


ow_script_0x8e33bb:
trainerbattlecont 0x1 0xba 0x0 str_0x8e627c str_0x8e6231 ow_script_0x8e63b7


ow_script_0x8e33a7:
trainerbattlecont 0x1 0xb9 0x0 str_0x8e627c str_0x8e6231 ow_script_0x8e63b7


ow_script_movs_0x8e63b2:
.byte STEP_DOWN
.byte STOP


ow_script_0x8e63a6:
applymovement 0x11 ow_script_movs_0x8e63b2
waitmovement 0x0
return


.ifdef LANG_GER

str_0x8e627c:
	.autostring 35 2 "PLAYER!\nDu machst dich wohl auf den Weg nach Kaskada?\pIch warne dich, im Osten lauert eine tückische Wüste.\pAllerdings habe ich ja auch bereits zwei Arena-Orden erkämpft.\pFür mich wird das ein Kinderspiel DOTS\pWie sieht es um deine Fähigkeiten aus?"


str_0x8e6231:
    .autostring 35 2 "Du und dein verfluchtes Glück!\pMeine Arenaorden sprechen ja wohl für mich!"


str_0x8e6164:
	.autostring 35 2 "Pures Glück!\pDu kannst gar kein besserer Trainer sein als ich, weil ich mehr Arena-Orden besitze als du!\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pAch, fast hätte ich vergessen, dass ich dir von Papi etwas geben soll."


str_0x9681e9:
	.autostring 35 2 "Der Detektor findet Gegenstände, die dem bloßen Auge leicht entgehen können.\pDafür musst du ihn nicht einmal einschalten.\pEr aktiviert sich automatisch in der Nähe eines versteckten Items.\pDiese Funktion kannst du auch in den Optionen ausschalten.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pWie auch immer!\nIch mache mich auf den Weg nach Kaskada!\pBei unserem nächsten Treffen bin ich siegreich!"


.elseif LANG_EN

.endif