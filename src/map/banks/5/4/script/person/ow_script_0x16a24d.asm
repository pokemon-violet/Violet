.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x16a24d
ow_script_0x16a24d:
loadpointer 0x0 str_0x192a92
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x192a92

str_0x192a92:
    .string "Du kannst den PC in der Ecke dort\ndrüben benutzen!\pDarauf hat man mich am Empfang\nfreundlicherweise hingewiesen."
        
        
.elseif LANG_EN

.endif