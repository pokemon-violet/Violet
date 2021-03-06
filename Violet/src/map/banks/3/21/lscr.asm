
.include "overworld_script.s"
.include "levelscript_types.s"
.include "flags.s"
.include "ordinals.s"

.global levelscript_felsige_oednis
.global ow_script_felsige_oednis_open_regirock_cave

levelscript_felsige_oednis:
	.byte LEVELSCRIPT_TYPE_ON_LOAD
	.word cave
	.byte 0x0

cave:
	checkflag FLAG_REGIROCK_CAVE_OPENED
	callif EQUAL ow_script_felsige_oednis_open_regirock_cave
	end

ow_script_felsige_oednis_open_regirock_cave:
	setmaptile 0xb 0x5 0x148 0x1
	setmaptile 0xc 0x5 0x149 0x1
	setmaptile 0xd 0x5 0x14a 0x1
	setmaptile 0xb 0x6 0x150 0x1
	setmaptile 0xc 0x6 0x151 0x0
	setmaptile 0xd 0x6 0x152 0x1
	setmaptile 0xb 0x7 0x158 0x0
	setmaptile 0xc 0x7 0x159 0x0
	setmaptile 0xd 0x7 0x15a 0x0
	return
