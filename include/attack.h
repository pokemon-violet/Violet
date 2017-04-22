/* 
 * File:   attack.h
 * Author: Domi
 *
 * Created on 3. Januar 2017, 17:56
 */

#ifndef ATTACK_H
#define	ATTACK_H

#ifdef	__cplusplus
extern "C" {
#endif

#define ATTACK_CNT 413
    
#define ATTACK_NONE 0
#define ATTACK_PFUND 1
#define ATTACK_KARATESCHLAG 2
#define ATTACK_DUPLEXHIEB 3
#define ATTACK_KOMETENHIEB 4
#define ATTACK_MEGAHIEB 5
#define ATTACK_ZAHLTAG 6
#define ATTACK_FEUERSCHLAG 7
#define ATTACK_EISHIEB 8
#define ATTACK_DONNERSCHLAG 9
#define ATTACK_KRATZER 10
#define ATTACK_KLAMMER 11
#define ATTACK_GUILLOTINE 12
#define ATTACK_KLINGENSTURM 13
#define ATTACK_SCHWERTTANZ 14
#define ATTACK_ZERSCHNEIDER 15
#define ATTACK_WINDSTOSS 16
#define ATTACK_FLUEGELSCHLAG 17
#define ATTACK_WIRBELWIND 18
#define ATTACK_FLIEGEN 19
#define ATTACK_KLAMMERGRIFF 20
#define ATTACK_SLAM 21
#define ATTACK_RANKENHIEB 22
#define ATTACK_STAMPFER 23
#define ATTACK_DOPPELKICK 24
#define ATTACK_MEGAKICK 25
#define ATTACK_SPRUNGKICK 26
#define ATTACK_FEGEKICK 27
#define ATTACK_SANDWIRBEL 28
#define ATTACK_KOPFNUSS 29
#define ATTACK_HORNATTACKE 30
#define ATTACK_FURIENSCHLAG 31
#define ATTACK_HORNBOHRER 32
#define ATTACK_TACKLE 33
#define ATTACK_BODYSLAM 34
#define ATTACK_WICKEL 35
#define ATTACK_BODYCHEK 36
#define ATTACK_FUCHTLER 37
#define ATTACK_RISIKOTACKLE 38
#define ATTACK_RUTENSCHLAG 39
#define ATTACK_GIFTSTACHEL 40
#define ATTACK_DUONADEL 41
#define ATTACK_NADELRAKETE 42
#define ATTACK_SILBERBLICK 43
#define ATTACK_BISS 44
#define ATTACK_HEULER 45
#define ATTACK_BRUELLER 46
#define ATTACK_GESANG 47
#define ATTACK_SUPERSCHALL 48
#define ATTACK_ULTRASCHALL 49
#define ATTACK_AUSSETZER 50
#define ATTACK_SAEURE 51
#define ATTACK_GLUT 52
#define ATTACK_FLAMMENWURF 53
#define ATTACK_WEISSNEBEL 54
#define ATTACK_AQUAKNARRE 55
#define ATTACK_HYDROPUMPE 56
#define ATTACK_SURFER 57
#define ATTACK_EISSTRAHL 58
#define ATTACK_BLIZZARD 59
#define ATTACK_PSYSTRAHL 60
#define ATTACK_BLUBBSTRAHL 61
#define ATTACK_AURORASTRAHL 62
#define ATTACK_HYPERSTRAHL 63
#define ATTACK_SCHNABEL 64
#define ATTACK_BOHRSCHNABEL 65
#define ATTACK_UEBERROLLER 66
#define ATTACK_FUSSKICK 67
#define ATTACK_FAUSTHIEB 68
#define ATTACK_GEOWURF 69
#define ATTACK_STAERKE 70
#define ATTACK_ABSORBER 71
#define ATTACK_MEGASAUGER 72
#define ATTACK_EGELSAMEN 73
#define ATTACK_WACHSTUM 74
#define ATTACK_RASIERBLATT 75
#define ATTACK_SOLARSTRAHL 76
#define ATTACK_GIFTPUDER 77
#define ATTACK_STACHELSPORE 78
#define ATTACK_SCHLAFPUDER 79
#define ATTACK_BLAETTERTANZ 80
#define ATTACK_FADENSCHUSS 81
#define ATTACK_DRACHENWUT 82
#define ATTACK_FEUERWIRBEL 83
#define ATTACK_DONNERSCHOCK 84
#define ATTACK_DONNERBLITZ 85
#define ATTACK_DONNERWELLE 86
#define ATTACK_DONNER 87
#define ATTACK_STEINWURF 88
#define ATTACK_ERDBEBEN 89
#define ATTACK_GEOFISSUR 90
#define ATTACK_SCHAUFLER 91
#define ATTACK_TOXIN 92
#define ATTACK_KONFUSION 93
#define ATTACK_PSYCHOKINESE 94
#define ATTACK_HYPNOSE 95
#define ATTACK_MEDITATION 96
#define ATTACK_AGILITAET 97
#define ATTACK_RUCKZUCKHIEB 98
#define ATTACK_RASEREI 99
#define ATTACK_TELEPORT 100
#define ATTACK_NACHTNEBEL 101
#define ATTACK_MIMIKRY 102
#define ATTACK_KREIDESCHREI 103
#define ATTACK_DOPPELTEAM 104
#define ATTACK_GENESUNG 105
#define ATTACK_HAERTNER 106
#define ATTACK_KOMPRIMATOR 107
#define ATTACK_RAUCHWOLKE 108
#define ATTACK_KONFUSTRAHL 109
#define ATTACK_PANZERSCHUTZ 110
#define ATTACK_EINIGLER 111
#define ATTACK_BARRIERE 112
#define ATTACK_LICHTSCHILD 113
#define ATTACK_DUNKELNEBEL 114
#define ATTACK_REFLEKTOR 115
#define ATTACK_ENERGIEFOKUS 116
#define ATTACK_GEDULD 117
#define ATTACK_METRONOM 118
#define ATTACK_SPIEGELTRICK 119
#define ATTACK_FINALE 120
#define ATTACK_EIERBOMBE 121
#define ATTACK_SCHLECKER 122
#define ATTACK_SMOG 123
#define ATTACK_SCHLAMMBAD 124
#define ATTACK_KNOCHENKEULE 125
#define ATTACK_FEUERSTURM 126
#define ATTACK_KASKADE 127
#define ATTACK_SCHNAPPER 128
#define ATTACK_STERNSCHAUER 129
#define ATTACK_SCHAEDELWUMME 130
#define ATTACK_DORNKANONE 131
#define ATTACK_UMKLAMMERUNG 132
#define ATTACK_AMNESIE 133
#define ATTACK_PSYKRAFT 134
#define ATTACK_WEICHEI 135
#define ATTACK_TURMKICK 136
#define ATTACK_GIFTBLICK 137
#define ATTACK_TRAUMFRESSER 138
#define ATTACK_GIFTWOLKE 139
#define ATTACK_STAKKATO 140
#define ATTACK_BLUTSAUGER 141
#define ATTACK_TODESKUSS 142
#define ATTACK_HIMMELSFEGER 143
#define ATTACK_WANDLER 144
#define ATTACK_BLUBBER 145
#define ATTACK_IRRSCHLAG 146
#define ATTACK_PILZSPORE 147
#define ATTACK_BLITZ 148
#define ATTACK_PSYWELLE 149
#define ATTACK_PLATSCHER 150
#define ATTACK_SAEUREPANZER 151
#define ATTACK_KRABBHAMMER 152
#define ATTACK_EXPLOSION 153
#define ATTACK_KRATZFURIE 154
#define ATTACK_KNOCHMERANG 155
#define ATTACK_ERHOLUNG 156
#define ATTACK_STEINHAGEL 157
#define ATTACK_HYPERZAHN 158
#define ATTACK_SCHAERFER 159
#define ATTACK_UMWANDLUNG 160
#define ATTACK_TRIPLETTE 161
#define ATTACK_SUPERZAHN 162
#define ATTACK_SCHLITZER 163
#define ATTACK_DELEGATOR 164
#define ATTACK_VERZWEIFLER 165
#define ATTACK_NACHAHMER 166
#define ATTACK_DREIFACHKICK 167
#define ATTACK_RAUB 168
#define ATTACK_SPINNENNETZ 169
#define ATTACK_WILLENSLESER 170
#define ATTACK_NACHTMAHR 171
#define ATTACK_FLAMMENRAD 172
#define ATTACK_SCHNARCHER 173
#define ATTACK_FLUCH 174
#define ATTACK_DRESCHFLEGEL 175
#define ATTACK_UNWANDLUNG2 176
#define ATTACK_LUFTSTOSS 177
#define ATTACK_BAUMWOLLSAAT 178
#define ATTACK_GEGENSCHLAG 179
#define ATTACK_GROLL 180
#define ATTACK_PULVERSCHNEE 181
#define ATTACK_SCHUTZSCHILD 182
#define ATTACK_TEMPOHIEB 183
#define ATTACK_GRIMASSE 184
#define ATTACK_FINTE 185
#define ATTACK_BITTERKUSS 186
#define ATTACK_BAUCHTROMMEL 187
#define ATTACK_MATSCHBOMBE 188
#define ATTACK_LEHMSCHELLE 189
#define ATTACK_OCTAZOOKA 190
#define ATTACK_STACHLER 191
#define ATTACK_BLITZKANONE 192
#define ATTACK_GESICHTE 193
#define ATTACK_ABGANGSBUND 194
#define ATTACK_ABGESANG 195
#define ATTACK_EISSTURM 196
#define ATTACK_SCANNER 197
#define ATTACK_KNOCHENHATZ 198
#define ATTACK_ZIELSCHUSS 199
#define ATTACK_WUTANFALL 200
#define ATTACK_SANDSTURM 201
#define ATTACK_GIGASAUGER 202
#define ATTACK_AUSDAUER 203
#define ATTACK_CHARME 204
#define ATTACK_WALZER 205
#define ATTACK_TRUGSCHLAG 206
#define ATTACK_ANGEBEREI 207
#define ATTACK_MILCHGETRAENK 208
#define ATTACK_FUNKENSPRUNG 209
#define ATTACK_ZORNKLINGE 210
#define ATTACK_STAHLFLUEGEL 211
#define ATTACK_HORRORBLICK 212
#define ATTACK_ANZIEHUNG 213
#define ATTACK_SCHLAFREDE 214
#define ATTACK_VITALGLOCKE 215
#define ATTACK_RUECKKEHR 216
#define ATTACK_GESCHENK 217
#define ATTACK_FRUSTRATION 218
#define ATTACK_BODYGUARD 219
#define ATTACK_LEIDTEILER 220
#define ATTACK_LAEUTERFEUER 221
#define ATTACK_INTENSITAET 222
#define ATTACK_WUCHTSCHLAG 223
#define ATTACK_VIELENDER 224
#define ATTACK_FEUERODEM 225
#define ATTACK_STAFFETTE 226
#define ATTACK_ZUGABE 227
#define ATTACK_VERFOLGUNG 228
#define ATTACK_TURBODREHER 229
#define ATTACK_LOCKDUFT 230
#define ATTACK_EISENSCHWEIF 231
#define ATTACK_METALLKLAUE 232
#define ATTACK_UEBERWURF 233
#define ATTACK_MORGENGRAUEN 234
#define ATTACK_SYNTHESE 235
#define ATTACK_MONDSCHEIN 236
#define ATTACK_INNERE_KRAFT 237
#define ATTACK_KREUZHIEB 238
#define ATTACK_WINDHOSE 239
#define ATTACK_REGENTANZ 240
#define ATTACK_SONNENTAG 241
#define ATTACK_KNIRSCHER 242
#define ATTACK_FOKUSWELLE 243
#define ATTACK_PSYCHO_PLUS 244
#define ATTACK_TURBOTEMPO 245
#define ATTACK_ANTIK_KRAFT 246
#define ATTACK_SPUKBALL 247
#define ATTACK_SEHER 248
#define ATTACK_ZERTRUEMMERER 249
#define ATTACK_WHIRLPOOL 250
#define ATTACK_PRUEGLER 251
#define ATTACK_MOGELHIEB 252
#define ATTACK_AUFRUHR 253
#define ATTACK_HORTER 254
#define ATTACK_ENTFESSLER 255
#define ATTACK_VERZEHRER 256
#define ATTACK_HITZEWELLE 257
#define ATTACK_HAGELSTURM 258
#define ATTACK_FOLTERKNECHT 259
#define ATTACK_SCHMEICHLER 260
#define ATTACK_IRRLICHT 261
#define ATTACK_MEMENTO_MORI 262
#define ATTACK_FASSADE 263
#define ATTACK_POWER_PUNCH 264
#define ATTACK_RIECHSALZ 265
#define ATTACK_SPOTLIGHT 266
#define ATTACK_NATUR_KRAFT 267
#define ATTACK_LADEVORGANG 268
#define ATTACK_VERHOEHNER 269
#define ATTACK_RECHTE_HAND 270
#define ATTACK_TRICKBETRUG 271
#define ATTACK_ROLLENTAUSCH 272
#define ATTACK_WUNSCHTRAUM 273
#define ATTACK_ZUSCHUSS 274
#define ATTACK_VERWURZLER 275
#define ATTACK_KRAFTKOLOSS 276
#define ATTACK_MAGIEMANTEL 277
#define ATTACK_AUFBEREITUNG 278
#define ATTACK_VERGELTUNG 279
#define ATTACK_DURCHBRUCH 280
#define ATTACK_GAEHNER 281
#define ATTACK_ABSCHLAG 282
#define ATTACK_NOTSITUATION 283
#define ATTACK_ERUPTION 284
#define ATTACK_WERTWECHSEL 285
#define ATTACK_BEGRENZER 286
#define ATTACK_HEILUNG 287
#define ATTACK_NACHSPIEL 288
#define ATTACK_UEBERNAHME 289
#define ATTACK_GEHEIMPOWER 290
#define ATTACK_TAUCHER 291
#define ATTACK_ARMSTOSS 292
#define ATTACK_TARNUNG 293
#define ATTACK_SCHWEIFGLANZ 294
#define ATTACK_SCHEINWERFER 295
#define ATTACK_NEBELBALL 296
#define ATTACK_DAUNENREIGEN 297
#define ATTACK_TAUMELTANZ 298
#define ATTACK_FEUERFEGER 299
#define ATTACK_LEHMSUHLER 300
#define ATTACK_FROSTBEULE 301
#define ATTACK_NIETENRANKE 302
#define ATTACK_TAGEDIEB 303
#define ATTACK_SCHALLWELLE 304
#define ATTACK_GIFTZAHN 305
#define ATTACK_ZERMALMKLAUE 306
#define ATTACK_LOHEKANONADE 307
#define ATTACK_AQUAHAUBITZE 308
#define ATTACK_STERNHIEB 309
#define ATTACK_ERSTAUNER 310
#define ATTACK_METEOROLOGE 311
#define ATTACK_AROMAKUR 312
#define ATTACK_TRUGTRAENE 313
#define ATTACK_WINDSCHNITT 314
#define ATTACK_HITZEKOLLER 315
#define ATTACK_SCHNUEFFLER 316
#define ATTACK_FELSGRAB 317
#define ATTACK_SILBERHAUCH 318
#define ATTACK_METALLSOUND 319
#define ATTACK_GRASFLOETE 320
#define ATTACK_SPASSKANONE 321
#define ATTACK_KOSMIK_KRAFT 322
#define ATTACK_FONTRAENEN 323
#define ATTACK_AMPELLEUCHTE 324
#define ATTACK_FINSTERFAUST 325
#define ATTACK_SONDERSENSOR 326
#define ATTACK_HIMMELHIEB 327
#define ATTACK_SANDGRAB 328
#define ATTACK_EISESKAELTE 329
#define ATTACK_LEHMBRUEHE 330
#define ATTACK_KUGELSAAT 331
#define ATTACK_AERO_ASS 332
#define ATTACK_EISSPEER 333
#define ATTACK_EISENABWEHR 334
#define ATTACK_RUECKENTZUG 335
#define ATTACK_JAULER 336
#define ATTACK_DRACHENKLAUE 337
#define ATTACK_FAUNA_STATUE 338
#define ATTACK_PROTZER 339
#define ATTACK_SPRUNGFEDER 340
#define ATTACK_LEHMSCHUSS 341
#define ATTACK_GIFTSCHWEIF 342
#define ATTACK_BEZIRZER 343
#define ATTACK_VOLTTACKLE 344
#define ATTACK_ZAUBERBLATT 345
#define ATTACK_NASSMACHER 346
#define ATTACK_GEDANKENGUT 347
#define ATTACK_LAUBKLINGE 348
#define ATTACK_DRACHENTANZ 349
#define ATTACK_FELSWURF 350
#define ATTACK_SCHOCKWELLE 351
#define ATTACK_AQUAWELLE 352
#define ATTACK_KISMETWUNSCH 353
#define ATTACK_PSYSCHUB 354
#define ATTACK_FILLER 355
#define ATTACK_HAMMERARM 356
#define ATTACK_AURASPHAERE 357
#define ATTACK_GIFTHIEB 358
#define ATTACK_FOKUSSTOSS 359
#define ATTACK_PATRONENHIEB 360
#define ATTACK_FINSTERAURA 361
#define ATTACK_FLAMMENBLITZ 362
#define ATTACK_EISZAHN 363
#define ATTACK_DONNERZAHN 364
#define ATTACK_DUNKELKLAUE 365
#define ATTACK_KREUZSCHERE 366
#define ATTACK_STEINKANTE 367
#define ATTACK_STURZFLUG 368
#define ATTACK_STEINPOLITUR 369
#define ATTACK_KRAXLER 370
#define ATTACK_BLAETTERSTURM 371
#define ATTACK_NAHKAMPF 372
#define ATTACK_LICHTKANONE 373
#define ATTACK_DRACO_METEOR 374
#define ATTACK_NASSCHWEIF 375
#define ATTACK_ZEN_KOPFSTOSS 376
#define ATTACK_ENERGIEBALL 377
#define ATTACK_SCHATTENSTOSS 378
#define ATTACK_DOPPELSCHLAG 379
#define ATTACK_TIEFSCHLAG 380
#define ATTACK_NACHTHIEB 381
#define ATTACK_SAMENBOMBE 382
#define ATTACK_ERDKRAEFTE 383
#define ATTACK_DRACHENPULS 384
#define ATTACK_EISSPLITTER 385
#define ATTACK_FEUERZAHN 386
#define ATTACK_WASSERDUESE 387
#define ATTACK_ZORNFEUER 388
#define ATTACK_TSUNAMI 389
#define ATTACK_STAHLSTREICH 390
#define ATTACK_KINESISWELLE 391
#define ATTACK_SUPERNOVA 392
#define ATTACK_WASSERSPALT 393
#define ATTACK_SCHALLSTICH 394
#define ATTACK_DIEBESKUSS 395
#define ATTACK_KNUDDLER 396
#define ATTACK_MONDGEWALT 397
#define ATTACK_ZAUBERSCHEIN 398
#define ATTACK_SAEUSELSTIMME 399
#define ATTACK_BIENENSTICH 400
#define ATTACK_SCHWARMSTICH 401
#define ATTACK_GESANG_2 402
#define ATTACK_HEISSSTEIN 403
#define ATTACK_GEWITTER 404
#define ATTACK_EISENSLAM 405
#define ATTACK_HOLZGEWEIH 406
#define ATTACK_KAEFERBISS 407
#define ATTACK_FALTERREIGEN 408
#define ATTACK_NITROLADUNG 409
#define ATTACK_KAEFERGEBRUMM 410
#define ATTACK_TORNADO 411
#define ATTACK_KOENIGSSCHILD 412
    
#define SELECTED_TARGET 0
#define TARGET_DEPENDS_ON_ATTACK (1 << 0)    
#define TARGET_UNUSED (1 << 1) 
#define RANDOM_TARGET (1 << 2)
#define TARGET_BOTH_FOES (1 << 3)
#define TARGET_USER (1 << 4)
#define TARGET_BOTH_FOES_AND_PARTNER (1 << 5) 
#define TARGET_OPPONENT_FIELD (1 << 6)

#define MAKES_CONTACT (1 << 0)
#define AFFECTED_BY_PROTECT (1 << 1)
#define AFFECTED_BY_MAGIC_COAT (1 << 2)
#define AFFECTED_BY_SNATCH (1 << 3)
#define MIRRORABLE (1 << 4)
#define TRIGGERS_KINGS_ROCK (1 << 5)
    
#define CATEGORY_PHYSICAL 0
#define CATEGORY_SPECIAL 1
#define CATEGORY_STATUS 2
    typedef struct{
        u8 effect;
        u8 base_power;
        u8 type;
        u8 accuracy;
        u8 pp;
        u8 effect_accuracy;
        u8 affects_whom;
        s8 priority;
        u8 flags;
        u8 effect_table;
        u8 category;
        u8 padding;
    }attack;

    
    typedef struct{
        u8 attacker;
        u8 defender;
        u8 multiplicator;
    }type_effectiveness;
    
    attack attacks[ATTACK_CNT];

#ifdef	__cplusplus
}
#endif

#endif	/* ATTACK_H */

