
.include "flags.s"
.include "overworld_script.s"
.include "vars.s"
.include "levelscript_types.s"
.include "ordinals.s"

.global route_3_eg_levelscripts

route_3_eg_levelscripts:    
	.byte LEVELSCRIPT_TYPE_ON_LOAD
    .word lscr_setmaptile
	.byte 0x0

lscr_setmaptile:
	checkflag FLAG_ROUTE_3_MILL_HAY_BALE
	gotoif NOT_EQUAL hay_not_moved
	setmaptile 0xc 0xe 0x2b8 0
	setmaptile 0xc 0xf 0x2c0 1
hay_not_moved:
	end