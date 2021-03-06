#include "types.h"
#include <stdbool.h>
#include "pokemon/count.h"
#include "pokepad/pokedex/operator.h"
#include "mega.h"

u16 pokedex_order[POKEMON_CNT - 1] = {
	[POKEMON_BISASAM - 1] = 1,
	[POKEMON_BISAKNOSP - 1] = 2,
	[POKEMON_BISAFLOR - 1] = 3,
	[POKEMON_GLUMANDA - 1] = 4,
	[POKEMON_GLUTEXO - 1] = 5,
	[POKEMON_GLURAK - 1] = 6,
	[POKEMON_SCHIGGY - 1] = 7,
	[POKEMON_SCHILLOK - 1] = 8,
	[POKEMON_TURTOK - 1] = 9,
	[POKEMON_DARTIRI - 1] = 167,
	[POKEMON_DARTIGNIS - 1] = 168,
	[POKEMON_FIARO - 1] = 169,
	[POKEMON_HORNLIU - 1] = 10,
	[POKEMON_KOKUNA - 1] = 11,
	[POKEMON_BIBOR - 1] = 12,
	[POKEMON_STARALILI - 1] = 164,
	[POKEMON_STARAVIA - 1] = 165,
	[POKEMON_STARAPTOR - 1] = 166,
	[POKEMON_BRONZEL - 1] = 345,
	[POKEMON_BRONZONG - 1] = 346,
	[POKEMON_MAEHIKEL - 1] = 182,
	[POKEMON_CHEVRUMM - 1] = 183,
	[POKEMON_PARAGONI - 1] = 232,
	[POKEMON_TROMBORK - 1] = 233,
	[POKEMON_PIKACHU - 1] = 14,
	[POKEMON_RAICHU - 1] = 15,
	[POKEMON_SANDAN - 1] = 16,
	[POKEMON_SANDAMER - 1] = 17,
	[POKEMON_NIDORANW - 1] = 18,
	[POKEMON_NIDORINA - 1] = 19,
	[POKEMON_NIDOQUEEN - 1] = 20,
	[POKEMON_NIDORANM - 1] = 21,
	[POKEMON_NIDORINO - 1] = 22,
	[POKEMON_NIDOKING - 1] = 23,
	[POKEMON_FLOETTE - 1] = 162,
	[POKEMON_FLORGES - 1] = 163,
	[POKEMON_VULPIX - 1] = 24,
	[POKEMON_VULNONA - 1] = 25,
	[POKEMON_PUMMELUFF - 1] = 27,
	[POKEMON_KNUDDELUFF - 1] = 28,
	[POKEMON_ZUBAT - 1] = 29,
	[POKEMON_GOLBAT - 1] = 30,
	[POKEMON_MYRAPLA - 1] = 32,
	[POKEMON_DUFLOR - 1] = 33,
	[POKEMON_GIFLOR - 1] = 34,
	[POKEMON_FOLIPURBA - 1] = 132,
	[POKEMON_FEELINARA - 1] = 133,
	[POKEMON_WATTZAPF - 1] = 36,
	[POKEMON_VOLTULA - 1] = 37,
	[POKEMON_DIGDA - 1] = 38,
	[POKEMON_DIGDRI - 1] = 39,
	[POKEMON_KASTADUR - 1] = 325,
	[POKEMON_TENTANTEL - 1] = 326,
	[POKEMON_ENTON - 1] = 40,
	[POKEMON_ENTORON - 1] = 41,
	[POKEMON_MENKI - 1] = 42,
	[POKEMON_RASAFF - 1] = 43,
	[POKEMON_FUKANO - 1] = 44,
	[POKEMON_ARKANI - 1] = 45,
	[POKEMON_GRAMOKLES - 1] = 184,
	[POKEMON_DUOKLES - 1] = 185,
	[POKEMON_DURENGARD - 1] = 186,
	[POKEMON_ABRA - 1] = 46,
	[POKEMON_KADABRA - 1] = 47,
	[POKEMON_SIMSALA - 1] = 48,
	[POKEMON_MACHOLLO - 1] = 49,
	[POKEMON_MASCHOCK - 1] = 50,
	[POKEMON_MACHOMEI - 1] = 51,
	[POKEMON_KNOFENSA - 1] = 52,
	[POKEMON_ULTRIGARIA - 1] = 53,
	[POKEMON_SARZENIA - 1] = 54,
	[POKEMON_TENTACHA - 1] = 55,
	[POKEMON_TENTOXA - 1] = 56,
	[POKEMON_KLEINSTEIN - 1] = 57,
	[POKEMON_GEOROK - 1] = 58,
	[POKEMON_GEOWAZ - 1] = 59,
	[POKEMON_PONITA - 1] = 60,
	[POKEMON_GALLOPA - 1] = 61,
	[POKEMON_FLEGMON - 1] = 62,
	[POKEMON_LAHMUS - 1] = 63,
	[POKEMON_MAGNETILO - 1] = 65,
	[POKEMON_MAGNETON - 1] = 66,
	[POKEMON_PORENTA - 1] = 68,
	[POKEMON_DODU - 1] = 69,
	[POKEMON_DODRI - 1] = 70,
	[POKEMON_JUROB - 1] = 71,
	[POKEMON_JUGONG - 1] = 72,
	[POKEMON_SLEIMA - 1] = 73,
	[POKEMON_SLEIMOK - 1] = 74,
	[POKEMON_MUSCHAS - 1] = 75,
	[POKEMON_AUSTOS - 1] = 76,
	[POKEMON_NEBULAK - 1] = 77,
	[POKEMON_ALPOLLO - 1] = 78,
	[POKEMON_GENGAR - 1] = 79,
	[POKEMON_ONIX - 1] = 80,
	[POKEMON_TRAUMATO - 1] = 82,
	[POKEMON_HYPNO - 1] = 83,
	[POKEMON_KRABBY - 1] = 84,
	[POKEMON_KINGLER - 1] = 85,
	[POKEMON_VOLTOBAL - 1] = 86,
	[POKEMON_LEKTROBAL - 1] = 87,
	[POKEMON_OWEI - 1] = 88,
	[POKEMON_KOKOWEI - 1] = 89,
	[POKEMON_TRAGOSSO - 1] = 90,
	[POKEMON_KNOGGA - 1] = 91,
	[POKEMON_KICKLEE - 1] = 93,
	[POKEMON_NOCKCHAN - 1] = 94,
	[POKEMON_SCHLURP - 1] = 96,
	[POKEMON_SMOGON - 1] = 98,
	[POKEMON_SMOGMOG - 1] = 99,
	[POKEMON_RIHORN - 1] = 100,
	[POKEMON_RIZEROS - 1] = 101,
	[POKEMON_CHANEIRA - 1] = 107,
	[POKEMON_ZOBIRIS - 1] = 356,
	[POKEMON_KANGAMA - 1] = 329,
	[POKEMON_SEEPER - 1] = 103,
	[POKEMON_SEEMON - 1] = 104,
	[POKEMON_QUABBEL - 1] = 236,
	[POKEMON_APOQUALLYP - 1] = 237,
	[POKEMON_STERNDU - 1] = 109,
	[POKEMON_STARMIE - 1] = 110,
	[POKEMON_TRAUNFUGIL - 1] = 234,
	[POKEMON_SICHLOR - 1] = 117,
	[POKEMON_GALAGLADI - 1] = 370,
	[POKEMON_ELEKTEK - 1] = 112,
	[POKEMON_MAGMAR - 1] = 115,
	[POKEMON_PINSIR - 1] = 119,
	[POKEMON_TAUROS - 1] = 120,
	[POKEMON_KARPADOR - 1] = 121,
	[POKEMON_GARADOS - 1] = 122,
	[POKEMON_LAPRAS - 1] = 123,
	[POKEMON_DITTO - 1] = 124,
	[POKEMON_EVOLI - 1] = 125,
	[POKEMON_AQUANA - 1] = 126,
	[POKEMON_BLITZA - 1] = 127,
	[POKEMON_FLAMARA - 1] = 128,
	[POKEMON_PORYGON - 1] = 134,
	[POKEMON_AMONITAS - 1] = 139,
	[POKEMON_AMOROSO - 1] = 140,
	[POKEMON_KABUTO - 1] = 141,
	[POKEMON_KABUTOPS - 1] = 142,
	[POKEMON_AERODACTYL - 1] = 143,
	[POKEMON_RELAXO - 1] = 138,
	[POKEMON_ARKTOS - 1] = 144,
	[POKEMON_ZAPDOS - 1] = 145,
	[POKEMON_LAVADOS - 1] = 146,
	[POKEMON_DRATINI - 1] = 147,
	[POKEMON_DRAGONIR - 1] = 148,
	[POKEMON_DRAGORAN - 1] = 149,
	[POKEMON_MEWTU - 1] = 150,
	[POKEMON_MEW - 1] = 151,
	[POKEMON_ENDIVIE - 1] = 152,
	[POKEMON_LORBLATT - 1] = 153,
	[POKEMON_MEGANIE - 1] = 154,
	[POKEMON_FEURIGEL - 1] = 155,
	[POKEMON_IGELAVAR - 1] = 156,
	[POKEMON_TORNUPTO - 1] = 157,
	[POKEMON_KARNIMANI - 1] = 158,
	[POKEMON_TYRACROC - 1] = 159,
	[POKEMON_IMPERGATOR - 1] = 160,
	[POKEMON_IGNIVOR - 1] = 242,
	[POKEMON_RAMOTH - 1] = 243,
	[POKEMON_GLAZIOLA - 1] = 129,
	[POKEMON_RESLADERO - 1] = 221,
	[POKEMON_LEDYBA - 1] = 170,
	[POKEMON_LEDIAN - 1] = 171,
	[POKEMON_WEBARAK - 1] = 172,
	[POKEMON_ARIADOS - 1] = 173,
	[POKEMON_IKSBAT - 1] = 31,
	[POKEMON_LAMPI - 1] = 230,
	[POKEMON_LANTURN - 1] = 231,
	[POKEMON_MAGNEZONE - 1] = 67,
	[POKEMON_TOGEKISS - 1] = 176,
	[POKEMON_FLABEBE - 1] = 161,
	[POKEMON_TOGEPI - 1] = 174,
	[POKEMON_TOGETIC - 1] = 175,
	[POKEMON_NATU - 1] = 177,
	[POKEMON_XATU - 1] = 178,
	[POKEMON_VOLTILAMM - 1] = 179,
	[POKEMON_WAATY - 1] = 180,
	[POKEMON_AMPHAROS - 1] = 181,
	[POKEMON_BLUBELLA - 1] = 35,
	[POKEMON_MARILL - 1] = 196,
	[POKEMON_AZUMARILL - 1] = 197,
	[POKEMON_MOGELBAUM - 1] = 204,
	[POKEMON_CLAVION - 1] = 187,
	[POKEMON_LICHTEL - 1] = 188,
	[POKEMON_LATERNECTO - 1] = 189,
	[POKEMON_SKELABRA - 1] = 190,
	[POKEMON_GRIFFEL - 1] = 191,
	[POKEMON_SHNEBEDECK - 1] = 193,
	[POKEMON_REXBLISAR - 1] = 194,
	[POKEMON_AMBIDIFFEL - 1] = 192,
	[POKEMON_FELINO - 1] = 198,
	[POKEMON_MORLORD - 1] = 199,
	[POKEMON_PSIANA - 1] = 130,
	[POKEMON_NACHTARA - 1] = 131,
	[POKEMON_KRAMURX - 1] = 200,
	[POKEMON_LASCHOKING - 1] = 64,
	[POKEMON_KRAMSHEF - 1] = 201,
	[POKEMON_ICOGNITO - 1] = 202,
	[POKEMON_FROSDEDJE - 1] = 322,
	[POKEMON_SKORGRO - 1] = 208,
	[POKEMON_TANNZA - 1] = 205,
	[POKEMON_FORSTELLKA - 1] = 206,
	[POKEMON_ELEVOLTEK - 1] = 113,
	[POKEMON_SKORGLA - 1] = 207,
	[POKEMON_STAHLOS - 1] = 81,
	[POKEMON_SNUBBULL - 1] = 209,
	[POKEMON_GRANBULL - 1] = 210,
	[POKEMON_MAMUTEL - 1] = 218,
	[POKEMON_SCHEROX - 1] = 118,
	[POKEMON_FLUFFELUFF - 1] = 26,
	[POKEMON_SKARABORN - 1] = 211,
	[POKEMON_KRYPPUK - 1] = 223,
	[POKEMON_TEDDIURSA - 1] = 212,
	[POKEMON_URSARING - 1] = 213,
	[POKEMON_SCHNECKMAG - 1] = 214,
	[POKEMON_MAGCARGO - 1] = 215,
	[POKEMON_QUIEKEL - 1] = 216,
	[POKEMON_KEIFEL - 1] = 217,
	[POKEMON_MAMPFAXO - 1] = 137,
	[POKEMON_REMORAID - 1] = 219,
	[POKEMON_OCTILLERY - 1] = 220,
	[POKEMON_BOTOGEL - 1] = 224,
	[POKEMON_SCHLURPLEK - 1] = 97,
	[POKEMON_PANZAERON - 1] = 225,
	[POKEMON_HUNDUSTER - 1] = 226,
	[POKEMON_HUNDEMON - 1] = 227,
	[POKEMON_SEEDRAKING - 1] = 105,
	[POKEMON_PHANPY - 1] = 228,
	[POKEMON_DONPHAN - 1] = 229,
	[POKEMON_PORYGON2 - 1] = 135,
	[POKEMON_VOLUMINAS - 1] = 297,
	[POKEMON_TRAUNMAGIL - 1] = 235,
	[POKEMON_RABAUZ - 1] = 92,
	[POKEMON_KAPOERA - 1] = 95,
	[POKEMON_SEN_LONG - 1] = 222,
	[POKEMON_ELEKID - 1] = 111,
	[POKEMON_MAGBY - 1] = 114,
	[POKEMON_MILTANK - 1] = 238,
	[POKEMON_HEITEIRA - 1] = 108,
	[POKEMON_RAIKOU - 1] = 244,
	[POKEMON_ENTEI - 1] = 245,
	[POKEMON_SUICUNE - 1] = 246,
	[POKEMON_LARVITAR - 1] = 247,
	[POKEMON_PUPITAR - 1] = 248,
	[POKEMON_DESPOTAR - 1] = 249,
	[POKEMON_LUGIA - 1] = 250,
	[POKEMON_HO_OH - 1] = 251,
	[POKEMON_CELEBI - 1] = 252,
	[POKEMON_ROTOM_HEAT - 1] = 330,
	[POKEMON_ROTOM_WASH - 1] = 330,
	[POKEMON_ROTOM_FORST - 1] = 330,
	[POKEMON_ROTOM_WIND - 1] = 330,
	[POKEMON_ROTOM_GRASS - 1] = 330,
	[POKEMON_DURENGARD_OFFENSIVE - 1] = 0,
	[POKEMON_IN - 1] = 0,
	[POKEMON_GAME - 1] = 0,
	[POKEMON_TURTOKM - 1] = 0,
	[POKEMON_AMPHARAOSM - 1] = 0,
	[POKEMON_MEGA_BANETTE - 1] = 0,
	[POKEMON_BIBORM - 1] = 0,
	[POKEMON_MEGA_ALTARIA - 1] = 0,
	[POKEMON_MEGA_GEOWAZ - 1] = 0,
	[POKEMON_SENGOM - 1] = 0,
	[POKEMON_VIPITISM - 1] = 0,
	[POKEMON_ZOBIRISM - 1] = 0,
	[POKEMON_MEGA_TROPIUS - 1] = 0,
	[POKEMON_MEGA_OCTILLERY - 1] = 0,
	[POKEMON_MEGA_RASAFF - 1] = 0,
	[POKEMON_110 - 1] = 0,
	[POKEMON_111 - 1] = 0,
	[POKEMON_112 - 1] = 0,
	[POKEMON_113 - 1] = 0,
	[POKEMON_114 - 1] = 0,
	[POKEMON_LOCKSCHAL - 1] = 253,
	[POKEMON_STICHSCHAL - 1] = 254,
	[POKEMON_STAHLSTICH - 1] = 255,
	[POKEMON_WELUNO - 1] = 256,
	[POKEMON_ORTHODOS - 1] = 257,
	[POKEMON_ZERBERTRES - 1] = 258,
	[POKEMON_SEEKID - 1] = 259,
	[POKEMON_SEESKULL - 1] = 260,
	[POKEMON_SKULLYDRA - 1] = 261,
	[POKEMON_FIFFYEN - 1] = 262,
	[POKEMON_MAGNAYEN - 1] = 263,
	[POKEMON_ZIGZACHS - 1] = 264,
	[POKEMON_GERADAKS - 1] = 265,
	[POKEMON_WAUMPEL - 1] = 266,
	[POKEMON_SCHALOKO - 1] = 267,
	[POKEMON_PAPINELLA - 1] = 268,
	[POKEMON_PANEKON - 1] = 269,
	[POKEMON_PUDOX - 1] = 270,
	[POKEMON_LOTURZEL - 1] = 271,
	[POKEMON_LOMBRERO - 1] = 272,
	[POKEMON_KAPPALORES - 1] = 273,
	[POKEMON_SAMURZEL - 1] = 274,
	[POKEMON_BLANAS - 1] = 275,
	[POKEMON_TENGULIST - 1] = 276,
	[POKEMON_NINCADA - 1] = 277,
	[POKEMON_NINJASK - 1] = 278,
	[POKEMON_NINJATOM - 1] = 279,
	[POKEMON_SCHWALBINI - 1] = 280,
	[POKEMON_SCHWALBOSS - 1] = 281,
	[POKEMON_KNILZ - 1] = 282,
	[POKEMON_KAPILZ - 1] = 283,
	[POKEMON_PANDIR - 1] = 284,
	[POKEMON_WINGULL - 1] = 285,
	[POKEMON_PELIPPER - 1] = 286,
	[POKEMON_GEHWEIHER - 1] = 287,
	[POKEMON_MASKEREGEN - 1] = 288,
	[POKEMON_WAILMER - 1] = 289,
	[POKEMON_WAILORD - 1] = 290,
	[POKEMON_ENECO - 1] = 291,
	[POKEMON_ENEKORO - 1] = 292,
	[POKEMON_KECLEON - 1] = 293,
	[POKEMON_PUPPANCE - 1] = 294,
	[POKEMON_LEPUMENTAS - 1] = 295,
	[POKEMON_NASGNET - 1] = 296,
	[POKEMON_MAGBRANT - 1] = 116,
	[POKEMON_ZWIRRFINST - 1] = 338,
	[POKEMON_SCHMERBE - 1] = 298,
	[POKEMON_WELSAR - 1] = 299,
	[POKEMON_RIHORNIOR - 1] = 102,
	[POKEMON_KREBSCORPS - 1] = 300,
	[POKEMON_KREBUTACK - 1] = 301,
	[POKEMON_BARSCHWA - 1] = 302,
	[POKEMON_MILOTIC - 1] = 303,
	[POKEMON_KANIVANHA - 1] = 304,
	[POKEMON_TOHAIDO - 1] = 305,
	[POKEMON_KNACKLION - 1] = 306,
	[POKEMON_VIBRAVA - 1] = 307,
	[POKEMON_LIBELLDRA - 1] = 308,
	[POKEMON_RIOLU - 1] = 309,
	[POKEMON_LUCARIO - 1] = 310,
	[POKEMON_FRIZELBLIZ - 1] = 311,
	[POKEMON_VOLTENSO - 1] = 312,
	[POKEMON_CAMAUB - 1] = 313,
	[POKEMON_CAMERUPT - 1] = 314,
	[POKEMON_SEEMOPS - 1] = 315,
	[POKEMON_SEEJONG - 1] = 316,
	[POKEMON_WALRAISA - 1] = 317,
	[POKEMON_TUSKA - 1] = 318,
	[POKEMON_NOKTUSKA - 1] = 319,
	[POKEMON_SCHNEPPKE - 1] = 320,
	[POKEMON_FIRNONTOR - 1] = 321,
	[POKEMON_LUNASTEIN - 1] = 323,
	[POKEMON_SONNFEL - 1] = 324,
	[POKEMON_AZURILL - 1] = 195,
	[POKEMON_SPOINK - 1] = 327,
	[POKEMON_GROINK - 1] = 328,
	[POKEMON_PICHU - 1] = 13,
	[POKEMON_ROTOM - 1] = 330,
	[POKEMON_FLUNKIFER - 1] = 331,
	[POKEMON_MEDITIE - 1] = 332,
	[POKEMON_MEDITALIS - 1] = 333,
	[POKEMON_WABLU - 1] = 334,
	[POKEMON_ALTARIA - 1] = 335,
	[POKEMON_KLINGPLIM - 1] = 361,
	[POKEMON_ZWIRRLICHT - 1] = 336,
	[POKEMON_ZWIRRKLOP - 1] = 337,
	[POKEMON_PORYGON_Z - 1] = 136,
	[POKEMON_BUMMELZ - 1] = 339,
	[POKEMON_MUNTIER - 1] = 340,
	[POKEMON_LETARKING - 1] = 341,
	[POKEMON_MOLUNK - 1] = 342,
	[POKEMON_AMFIRA - 1] = 343,
	[POKEMON_TROPIUS - 1] = 344,
	[POKEMON_KAUMALAT - 1] = 239,
	[POKEMON_KNARKSEL - 1] = 240,
	[POKEMON_KNAKRACK - 1] = 241,
	[POKEMON_PERLU - 1] = 347,
	[POKEMON_AALABYSS - 1] = 348,
	[POKEMON_SAGANABYSS - 1] = 349,
	[POKEMON_ABSOL - 1] = 350,
	[POKEMON_SHUPPET - 1] = 351,
	[POKEMON_BANETTE - 1] = 352,
	[POKEMON_VIPITIS - 1] = 353,
	[POKEMON_SENGO - 1] = 354,
	[POKEMON_RELICANTH - 1] = 355,
	[POKEMON_STOLLUNIOR - 1] = 357,
	[POKEMON_STOLLRAK - 1] = 358,
	[POKEMON_STOLLOSS - 1] = 359,
	[POKEMON_FORMEO - 1] = 360,
	[POKEMON_WONNEIRA - 1] = 106,
	[POKEMON_MOBAI - 1] = 203,
	[POKEMON_LILIEP - 1] = 363,
	[POKEMON_WIELIE - 1] = 364,
	[POKEMON_ANORITH - 1] = 365,
	[POKEMON_ARMALDO - 1] = 366,
	[POKEMON_TRASLA - 1] = 367,
	[POKEMON_KIRLIA - 1] = 368,
	[POKEMON_GUARDEVOIR - 1] = 369,
	[POKEMON_KINDWURM - 1] = 371,
	[POKEMON_DRASCHEL - 1] = 372,
	[POKEMON_BRUTALANDA - 1] = 373,
	[POKEMON_TANHEL - 1] = 374,
	[POKEMON_METANG - 1] = 375,
	[POKEMON_METAGROSS - 1] = 376,
	[POKEMON_REGIROCK - 1] = 377,
	[POKEMON_REGICE - 1] = 378,
	[POKEMON_REGISTEEL - 1] = 379,
	[POKEMON_KYOGRE - 1] = 380,
	[POKEMON_GROUDON - 1] = 381,
	[POKEMON_RAYQUAZA - 1] = 382,
	[POKEMON_LATIAS - 1] = 383,
	[POKEMON_LATIOS - 1] = 384,
	[POKEMON_JIRACHI - 1] = 385,
	[POKEMON_DEOXYS - 1] = 386,
	[POKEMON_PALIMPALIM - 1] = 362,
	[POKEMON_EGG - 1] = 0,
	[POKEMON_ICOGNITO_B - 1] = 0,
	[POKEMON_ICOGNITO_C - 1] = 0,
	[POKEMON_ICOGNITO_D - 1] = 0,
	[POKEMON_ICOGNITO_E - 1] = 0,
	[POKEMON_ICOGNITO_F - 1] = 0,
	[POKEMON_ICOGNITO_G - 1] = 0,
	[POKEMON_ICOGNITO_H - 1] = 0,
	[POKEMON_ICOGNITO_I - 1] = 0,
	[POKEMON_ICOGNITO_J - 1] = 0,
	[POKEMON_ICOGNITO_K - 1] = 0,
	[POKEMON_ICOGNITO_L - 1] = 0,
	[POKEMON_ICOGNITO_M - 1] = 0,
	[POKEMON_ICOGNITO_N - 1] = 0,
	[POKEMON_ICOGNITO_O - 1] = 0,
	[POKEMON_ICOGNITO_P - 1] = 0,
	[POKEMON_ICOGNITO_Q - 1] = 0,
	[POKEMON_ICOGNITO_R - 1] = 0,
	[POKEMON_ICOGNITO_S - 1] = 0,
	[POKEMON_ICOGNITO_T - 1] = 0,
	[POKEMON_ICOGNITO_U - 1] = 0,
	[POKEMON_ICOGNITO_V - 1] = 0,
	[POKEMON_ICOGNITO_W - 1] = 0,
	[POKEMON_ICOGNITO_X - 1] = 0,
	[POKEMON_ICOGNITO_Y - 1] = 0,
	[POKEMON_ICOGNITO_Z - 1] = 0,
	[POKEMON_ICOGNITO_EXCLAMATION - 1] = 0,
	[POKEMON_ICOGNITO_QUESTION - 1] = 0,
	[POKEMON_GROUDON_REGENT - 1] = 0,
	[POKEMON_KECLEON_PURPLE - 1] = 293,
};

u16 pokemon_get_display_number(u16 species) {
    mega_evolution_t *mega_evolution = mega_evolution_get_by_mega_species(species);
	if (mega_evolution)
		return mega_evolution->species;
    u16 id = pokedex_get_id(species);
    if (!pokedex_is_national() && id > 151)
        return 0xFFFF;
    return id;

}

u16 pokedex_get_species_by_dex_id(u16 dex_id) {
    if (!dex_id)
        return 0;
    u16 i;
    for (i = 0; i < POKEMON_CNT - 1; i++) {
        if (pokedex_order[i] == dex_id)
            return i;
    }
    return 0;
}
