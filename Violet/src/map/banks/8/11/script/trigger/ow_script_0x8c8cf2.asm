.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "overworld_script.s"
.include "mugshot.s"


.global ow_script_0x8c8cf2
ow_script_0x8c8cf2:
lockall
showsprite 0xc
setvar 0x8004 0xc
special 0x1b
waitmovement 0x0
faceplayer
loadpointer 0x0 str_0x93144c
show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT
setvar 0x8005 0x1b
setvar 0x8006 0x2b
special 0x24
goto ow_script_0x93154e


.global ow_script_0x93154e
ow_script_0x93154e:
waitmovement 0x0
hidesprite 0xC
addvar STORY_PROGRESS 0x1
end


.ifdef LANG_GER
.global str_0x93144c

str_0x93144c:
	.autostring 34 2 "Wenn ich es mir recht überlege DOTS\pVielleicht solltest du diesen Ort auf eigene Faust erkunden.\pSo kannst du dir besser selbst ein Bild von den Zuständen in Theto machen.\pKomm einfach zu mir, wenn du dich etwas umgesehen hast.\pAber versuche, nicht zu sehr aufzufallen.\pDie Menschen hierDOTS\nDOTS DOTS DOTS\pSei einfach auf der Hut!"
        
.elseif LANG_EN

.endif
