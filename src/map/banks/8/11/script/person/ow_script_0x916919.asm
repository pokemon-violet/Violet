.include "overworld_script.s"


.global ow_script_0x916919
ow_script_0x916919:
bufferstring 0x0 str_0x916cab
setvar 0x8000 0x179
goto ow_script_0x8d421d


.ifdef LANG_GER
.global str_0x916cab

str_0x916cab:
    .string "Geist-"
        
        
.elseif LANG_EN

.endif