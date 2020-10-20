.include "vars.s"

.global lscr_0x71df9c

lscr_0x71df9c:
	.byte 0x2
.word lscr_0x71dfa2
	.byte 0x0


.align 4
.global lscr_0x71dfa2

lscr_0x71dfa2:
	.hword STORY_PROGRESS, 0x2a
	.word ow_script_0x949d92
	.hword 0x0
.include "vars.s"
.include "callstds.s"
.include "songs.s"
.include "mugshot.s"
.include "overworld_script.s"

.global ow_script_0x949d92

ow_script_0x949d92:
lockall
fadesong 0
loadpointer 0x0 str_0x94d7a4
show_mugshot MUGSHOT_PLAYER
playsong MUS_ROUTE_3_10_AND_ROUTE_16_22 0x0
addvar STORY_PROGRESS 0x1
releaseall
end


.ifdef LANG_GER

str_0x94d7a4:
	.autostring 35 2 "Was war das nur für eine seltsame Vision?\pUnd dieser Ort DOTS DOTS DOTS\pWas war das nur für ein schrecklicher Ort?\pDOTS DOTS DOTS\pWar es wieder eine Vision der Vergangenheit?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pNein, so einen düsteren Ort kann es unmöglich gegeben haben.\pBleibt also nur DOTS DOTS DOTS\pDOTS DOTS DOTS\pHabe ich einen Blick in die Zukunft erhalten?\pDas ist unmöglich!\pNiemals kann das die Zukunft Thetos gewesen sein DOTS\pIch muss herausfinden, was es mit diesen Vision auf sich hat DOTS"

.elseif LANG_EN

.endif