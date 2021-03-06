/* 
 * File:   trainer_encounter.c
 * Author: Domi
 *
 * Created on 9. Juni 2016, 11:49
 */


#include "types.h"
#include "stdbool.h"
#include "trainer/trainer.h"
#include "music.h"
#include "battle/state.h"
#include "flags.h"
#include "constants/vars.h"
#include "constants/songs.h"
#include "constants/trainerclasses.h"
#include "vars.h"

short_pair trainer_music_table [] = {
    {TRAINERCLASS_RIVALE, MUS_RIVAL_BATTLE},
    {TRAINERCLASS_TEAM_VIOLET, MUS_VIOLET_BATTLE},
    {TRAINERCLASS_ARENALEITER, MUS_GYMLEADER_NEW},
    {TRAINERCLASS_REVOLUTIONAER, MUS_REVOLUTIONARY_BATTLE},
    {TRAINERCLASS_KAPITAEN, MUS_BB_BATTLE},
    {0xFFFF, 0xFFFF}
};

u16 battle_get_song() {
    u16 *battle_music = var_access(BATTLE_SONG_OVERRIDE);
    if (*battle_music) {
        u16 forced_mus = *battle_music;
        *battle_music = 0;
        return forced_mus;
    }
    if (battle_flags & BATTLE_TRAINER) {
        //scan a lo_table
        int i = 0;
        while (trainer_music_table[i].id != 0xFFFF) {
            if (trainer_music_table[i].id == trainers[battle_trainer_id].trainerclass) {
                return trainer_music_table[i].value;
            }
            i++;
        }
        return MUS_KAMPF_GEGEN_RIVALEN_GARY;
    }
    if ((battle_flags & BATTLE_12) || (battle_flags & BATTLE_LEGENDARY)) {
        return MUS_KAMPF_GEGEN_WILDES_POKEMON;
    }
    return MUS_KAMPF_GEGEN_WILDES_POKEMON;
}
