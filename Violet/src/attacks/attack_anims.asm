.include "attack_anim.s"

.global attack_anims

.align 4
attack_anims:
		.word 0x81cb1c4 @//attack_none
		.word 0x81cb1c4 @//attack_pfund
		.word 0x81d3f7a @//attack_karateschlag
		.word 0x81cb1f5 @//attack_duplexhieb
		.word 0x81cc0f3 @//attack_kometenhieb
		.word 0x81cbf7d @//attack_megahieb
		.word 0x81cd6e5 @//attack_zahltag
		.word 0x81d4b45 @//attack_feuerschlag
		.word 0x81d1570 @//attack_eishieb
		.word 0x81d195a @//attack_donnerschlag
		.word 0x81d1c0a @//attack_kratzer
		.word 0x81cd611 @//attack_klammer
		.word 0x81cd659 @//attack_guillotine
		.word 0x81d5849 @//attack_klingensturm
		.word 0x81cc8d4 @//attack_schwerttanz
		.word 0x81cc5ba @//attack_zerschneider
		.word 0x81d38d8 @//attack_windstoss
		.word 0x81d3929 @//attack_fluegelschlag
		.word 0x81cdc19 @//attack_wirbelwind
		.word 0x81d3ead @//attack_fliegen
		.word 0x81d4f90 @//attack_klammergriff
		.word 0x81ccd39 @//attack_slam
		.word 0x81ccdc1 @//attack_rankenhieb
		.word 0x81cc55a @//attack_stampfer
		.word 0x81d4128 @//attack_doppelkick
		.word 0x81cc057 @//attack_megakick
		.word 0x81d4035 @//attack_sprungkick
		.word 0x81ce46a @//attack_fegekick
		.word 0x81d21b2 @//attack_sandwirbel
		.word 0x81ce4ed @//attack_kopfnuss
		.word 0x81ce54a @//attack_hornattacke
		.word 0x81ce5b7 @//attack_furienschlag
		.word 0x81CE634 @//attack_hornbohrer
		.word 0x81cb722 @//attack_tackle
		.word 0x81cb760 @//attack_bodyslam
		.word 0x81d4fca @//attack_wickel
		.word 0x81cbb16 @//attack_bodychek
		.word 0x81ce7b1 @//attack_fuchtler
		.word 0x81cbbaa @//attack_risikotackle
		.word 0x81cc5a1 @//attack_rutenschlag
		.word 0x81cbcbd @//attack_giftstachel
		.word 0x81cbd12 @//attack_duonadel
		.word 0x81cb98c @//attack_nadelrakete
		.word 0x81d4c58 @//attack_silberblick
		.word 0x81d2420 @//attack_biss
		.word 0x81d1de7 @//attack_heuler
		.word 0x81d1d50 @//attack_brueller
		.word 0x81ce830 @//attack_gesang
		.word 0x81cb7ed @//attack_superschall
		.word 0x81cc16b @//attack_ultraschall
		.word 0x81d592f @//attack_aussetzer
		.word 0x81d3598 @//attack_saeure
		.word 0x81cbf09 @//attack_glut
		.word 0x81d3ca5 @//attack_flammenwurf
		.word 0x81d4ab1 @//attack_weissnebel
		.word 0x81d3b0a @//attack_aquaknarre
		.word 0x81d2c7e @//attack_hydropumpe
		.word 0x81d3c91 @//attack_surfer
		.word 0x81d258b @//attack_eisstrahl
		.word 0x81d29f8 @//attack_blizzard
		.word 0x81d4fe0 @//attack_psystrahl
		.word 0x81cdfa3 @//attack_blubbstrahl
		.word 0x81d26cf @//attack_aurorastrahl
		.word 0x81d6c37 @//attack_hyperstrahl
		.word 0x81d39c6 @//attack_schnabel
		.word 0x81ccdf8 @//attack_bohrschnabel
		.word 0x81d452c @//attack_ueberroller
		.word 0x81ce904 @//attack_fusskick
		.word 0x81d42ea @//attack_fausthieb
		.word 0x81d89bc @//attack_geowurf
		.word 0x81cb68e @//attack_staerke
		.word 0x81d2e65 @//attack_absorber
		.word 0x81d2f7d @//attack_megasauger
		.word 0x81cbeb3 @//attack_egelsamen
		.word 0x81cdbe3 @//attack_wachstum
		.word 0x81d481c @//attack_rasierblatt
		.word 0x81d27a3 @//attack_solarstrahl
		.word 0x81cb248 @//attack_giftpuder
		.word 0x81cb379 @//attack_stachelspore
		.word 0x81cb4a7 @//attack_schlafpuder
		.word 0x81d46e4 @//attack_blaettertanz
		.word 0x81d56d6 @//attack_fadenschuss
		.word 0x81d22f8 @//attack_drachenwut
		.word 0x81ccac6 @//attack_feuerwirbel
		.word 0x81cc1cc @//attack_donnerschock
		.word 0x81cc23a @//attack_donnerblitz
		.word 0x81cc3f0 @//attack_donnerwelle
		.word 0x81d1800 @//attack_donner
		.word 0x81cdd8f @//attack_steinwurf
		.word 0x81ce961 @//attack_erdbeben
		.word 0x81ce9ae @//attack_geofissur
		.word 0x81cead1 @//attack_schaufler
		.word 0x81d33c1 @//attack_toxin
		.word 0x81d169b @//attack_konfusion
		.word 0x81d16fc @//attack_psychokinese
		.word 0x81d507a @//attack_hypnose
		.word 0x81cebed @//attack_meditation
		.word 0x81cec0a @//attack_agilitaet
		.word 0x81cec54 @//attack_ruckzuckhieb
		.word 0x81cecac @//attack_raserei
		.word 0x81ced22 @//attack_teleport
		.word 0x81d544b @//attack_nachtnebel
		.word 0x81d5a07 @//attack_mimikry
		.word 0x81cb845 @//attack_kreideschrei
		.word 0x81ced3b @//attack_doppelteam
		.word 0x81d595d @//attack_genesung
		.word 0x81d133b @//attack_haertner
		.word 0x81ced82 @//attack_komprimator
		.word 0x81ce140 @//attack_rauchwolke
		.word 0x81cdcc1 @//attack_konfustrahl
		.word 0x81d26c2 @//attack_panzerschutz
		.word 0x81cd1ac @//attack_einigler
		.word 0x81d1fbd @//attack_barriere
		.word 0x81d1eb8 @//attack_lichtschild
		.word 0x81d4b12 @//attack_dunkelnebel
		.word 0x81d1f6a @//attack_reflektor
		.word 0x81d5597 @//attack_energiefokus
		.word 0x81d55d7 @//attack_geduld
		.word 0x81ced95 @//attack_metronom
		.word 0x81cb1c4 @//attack_spiegeltrick
		.word 0x81ccc49 @//attack_finale
		.word 0x81d5493 @//attack_eierbombe
		.word 0x81d5570 @//attack_schlecker
		.word 0x81d20b0 @//attack_smog
		.word 0x81d3430 @//attack_schlammbad
		.word 0x81d36e6 @//attack_knochenkeule
		.word 0x81cbd85 @//attack_feuersturm
		.word 0x81cce51 @//attack_kaskade
		.word 0x81d252e @//attack_schnapper
		.word 0x81cb5d5 @//attack_sternschauer
		.word 0x81cedbf @//attack_schaedelwumme
		.word 0x81cc821 @//attack_dornkanone
		.word 0x81d5a51 @//attack_umklammerung
		.word 0x81cee85 @//attack_amnesie
		.word 0x81ceea9 @//attack_psykraft
		.word 0x81d5b79 @//attack_weichei
		.word 0x81d4092 @//attack_turmkick
		.word 0x81ceefa @//attack_giftblick
		.word 0x81d4caf @//attack_traumfresser
		.word 0x81d4eb2 @//attack_giftwolke
		.word 0x81cef63 @//attack_stakkato
		.word 0x81d3315 @//attack_blutsauger
		.word 0x81d5efc @//attack_todeskuss
		.word 0x81cefab @//attack_himmelsfeger
		.word 0x81d6aa1 @//attack_wandler
		.word 0x81d1fda @//attack_blubber
		.word 0x81cc98c @//attack_irrschlag
		.word 0x81d467f @//attack_pilzspore
		.word 0x81cf143 @//attack_blitz
		.word 0x81d50da @//attack_psywelle
		.word 0x81cf150 @//attack_platscher
		.word 0x81cf165 @//attack_saeurepanzer
		.word 0x81d3b97 @//attack_krabbhammer
		.word 0x81cd0a5 @//attack_explosion
		.word 0x81d5f43 @//attack_kratzfurie
		.word 0x81d3692 @//attack_knochmerang
		.word 0x81d165b @//attack_erholung
		.word 0x81cde1b @//attack_steinhagel
		.word 0x81d63f5 @//attack_hyperzahn
		.word 0x81cf17e @//attack_schaerfer
		.word 0x81ce239 @//attack_umwandlung
		.word 0x81d645c @//attack_triplette
		.word 0x81cf18a @//attack_superzahn
		.word 0x81cf20b @//attack_schlitzer
		.word 0x81d76c3 @//attack_delegator
		.word 0x81cf245 @//attack_verzweifler
		.word 0x81cf2ab @//attack_nachahmer
		.word 0x81d415b @//attack_dreifachkick
		.word 0x81cdf5c @//attack_raub
		.word 0x81d57a8 @//attack_spinnennetz
		.word 0x81d1438 @//attack_willensleser
		.word 0x81cf2d3 @//attack_nachtmahr
		.word 0x81cb892 @//attack_flammenrad
		.word 0x81d1e28 @//attack_schnarcher
		.word 0x81d5ab9 @//attack_fluch
		.word 0x81cf329 @//attack_dreschflegel
		.word 0x81ce34e @//attack_unwandlung2
		.word 0x81d39ed @//attack_luftstoss
		.word 0x81d4625 @//attack_baumwollsaat
		.word 0x81cc6d5 @//attack_gegenschlag
		.word 0x81cf366 @//attack_groll
		.word 0x81d2b84 @//attack_pulverschnee
		.word 0x81cd1e5 @//attack_schutzschild
		.word 0x81cf395 @//attack_tempohieb
		.word 0x81d5e30 @//attack_grimasse
		.word 0x81d212b @//attack_finte
		.word 0x81d5e93 @//attack_bitterkuss
		.word 0x81d1350 @//attack_bauchtrommel
		.word 0x81d3472 @//attack_matschbombe
		.word 0x81d225a @//attack_lehmschelle
		.word 0x81d4a4b @//attack_octazooka
		.word 0x81d3793 @//attack_stachler
		.word 0x81d5160 @//attack_blitzkanone
		.word 0x81cf41d @//attack_gesichte
		.word 0x81cf45c @//attack_abgangsbund
		.word 0x81d61d1 @//attack_abgesang
		.word 0x81ce080 @//attack_eissturm
		.word 0x81cd202 @//attack_scanner
		.word 0x81d3748 @//attack_knochenhatz
		.word 0x81cdd14 @//attack_zielschuss
		.word 0x81cd738 @//attack_wutanfall
		.word 0x81d3d42 @//attack_sandsturm
		.word 0x81d310d @//attack_gigasauger
		.word 0x81cf4b7 @//attack_ausdauer
		.word 0x81cf54b @//attack_charme
		.word 0x81cf58e @//attack_walzer
		.word 0x81cf5cf @//attack_trugschlag
		.word 0x81cf656 @//attack_angeberei
		.word 0x81cf69e @//attack_milchgetraenk
		.word 0x81cd8d3 @//attack_funkensprung
		.word 0x81ccb7a @//attack_zornklinge
		.word 0x81d5245 @//attack_stahlfluegel
		.word 0x81cdd4a @//attack_horrorblick
		.word 0x81cdaea @//attack_anziehung
		.word 0x81d633a @//attack_schlafrede
		.word 0x81d5bfb @//attack_vitalglocke
		.word 0x81d798a @//attack_rueckkehr
		.word 0x81d6058 @//attack_geschenk
		.word 0x81cd260 @//attack_frustration
		.word 0x81cd527 @//attack_bodyguard
		.word 0x81cd569 @//attack_leidteiler
		.word 0x81d1a23 @//attack_laeuterfeuer
		.word 0x81cf6e0 @//attack_intensitaet
		.word 0x81d4222 @//attack_wuchtschlag
		.word 0x81d37ea @//attack_vielender
		.word 0x81d1c3c @//attack_feuerodem
		.word 0x81d61af @//attack_staffette
		.word 0x81d668e @//attack_zugabe
		.word 0x81cc7b0 @//attack_verfolgung
		.word 0x81cf771 @//attack_turbodreher
		.word 0x81d6b4d @//attack_lockduft
		.word 0x81d52f4 @//attack_eisenschweif
		.word 0x81d53b8 @//attack_metallklaue
		.word 0x81d43b9 @//attack_ueberwurf
		.word 0x81d6ab9 @//attack_morgengrauen
		.word 0x81d3397 @//attack_synthese
		.word 0x81cf7de @//attack_mondschein
		.word 0x81cc5ec @//attack_innere_kraft
		.word 0x81d3fcc @//attack_kreuzhieb
		.word 0x81d8f9e @//attack_windhose
		.word 0x81d23d5 @//attack_regentanz
		.word 0x81d45cf @//attack_sonnentag
		.word 0x81d247e @//attack_knirscher
		.word 0x81d1f44 @//attack_fokuswelle
		.word 0x81cc91a @//attack_psycho_plus
		.word 0x81cf86e @//attack_turbotempo
		.word 0x81d4923 @//attack_antik_kraft
		.word 0x81d552d @//attack_spukball
		.word 0x81d175f @//attack_seher
		.word 0x81d4434 @//attack_zertruemmerer
		.word 0x81d3dca @//attack_whirlpool
		.word 0x81cc45f @//attack_pruegler
		.word 0x81d5df5 @//attack_mogelhieb
		.word 0x81cf92c @//attack_aufruhr
		.word 0x81d67fb @//attack_horter
		.word 0x81d68b2 @//attack_entfessler
		.word 0x81d69f5 @//attack_verzehrer
		.word 0x81cf9f6 @//attack_hitzewelle
		.word 0x81cfaa6 @//attack_hagelsturm
		.word 0x81cfade @//attack_folterknecht
		.word 0x81d6d79 @//attack_schmeichler
		.word 0x81d65d0 @//attack_irrlicht
		.word 0x81cfb22 @//attack_memento_mori
		.word 0x81cfb66 @//attack_fassade
		.word 0x81d78c3 @//attack_power_punch
		.word 0x81cfb86 @//attack_riechsalz
		.word 0x81cfbe1 @//attack_spotlight
		.word 0x81d4923 @//attack_natur_kraft
		.word 0x81cfc00 @//attack_ladevorgang
		.word 0x81cfc9b @//attack_verhoehner
		.word 0x81cfcef @//attack_rechte_hand
		.word 0x81d6735 @//attack_trickbetrug
		.word 0x81d6e75 @//attack_rollentausch
		.word 0x81d67b3 @//attack_wunschtraum
		.word 0x81cfd62 @//attack_zuschuss
		.word 0x81d5fa7 @//attack_verwurzler
		.word 0x81cfdd3 @//attack_kraftkoloss
		.word 0x81d8b19 @//attack_magiemantel
		.word 0x81cfe8e @//attack_aufbereitung
		.word 0x81d75ed @//attack_vergeltung
		.word 0x81cfec2 @//attack_durchbruch
		.word 0x81d00c7 @//attack_gaehner
		.word 0x81d8c9f @//attack_abschlag
		.word 0x81d010a @//attack_notsituation
		.word 0x81d017f @//attack_eruption
		.word 0x81d024c @//attack_wertwechsel
		.word 0x81d0297 @//attack_begrenzer
		.word 0x81d6ed2 @//attack_heilung
		.word 0x81d02da @//attack_nachspiel
		.word 0x81d83df @//attack_uebernahme
		.word attack_script_secret_power @0x81d8f4a //attack_geheimpower
		.word 0x81d83f9 @//attack_taucher
		.word 0x81d7123 @//attack_armstoss
		.word 0x81d0302 @//attack_tarnung
		.word 0x81d0348 @//attack_schweifglanz
		.word 0x81d038b @//attack_scheinwerfer
		.word 0x81d04a2 @//attack_nebelball
		.word 0x81d0531 @//attack_daunenreigen
		.word 0x81d0601 @//attack_taumeltanz
		.word 0x81d6f15 @//attack_feuerfeger
		.word 0x81d066c @//attack_lehmsuhler
		.word 0x81d921e @//attack_frostbeule
		.word 0x81d07a3 @//attack_nietenranke
		.word 0x81d0953 @//attack_tagedieb
		.word 0x81d6f9d @//attack_schallwelle
		.word 0x81d7684 @//attack_giftzahn
		.word 0x81d096b @//attack_zermalmklaue
		.word 0x81d7e9e @//attack_lohekanonade
		.word 0x81d8842 @//attack_aquahaubitze
		.word 0x81d7566 @//attack_sternhieb
		.word 0x81d8974 @//attack_erstauner
		.word 0x81d93ed @//attack_meteorologe
		.word 0x81d09db @//attack_aromakur
		.word 0x81d0b3d @//attack_trugtraene
		.word 0x81d0bcd @//attack_windschnitt
		.word 0x81d8550 @//attack_hitzekoller
		.word 0x81d0c2f @//attack_schnueffler
		.word 0x81d80e0 @//attack_felsgrab
		.word 0x81d81c7 @//attack_silberhauch
		.word 0x81d7873 @//attack_metallsound
		.word 0x81d0c79 @//attack_grasfloete
		.word 0x81d0d6c @//attack_spasskanone
		.word 0x81d7e19 @//attack_kosmik_kraft
		.word 0x81d0dd8 @//attack_fontraenen
		.word 0x81d2d7d @//attack_ampelleuchte
		.word 0x81d0e06 @//attack_finsterfaust
		.word 0x81d0e61 @//attack_sondersensor
		.word 0x81d8e51 @//attack_himmelhieb
		.word 0x81d7026 @//attack_sandgrab
		.word 0x81d70fe @//attack_eiseskaelte
		.word 0x81d71b8 @//attack_lehmbruehe
		.word 0x81d71ca @//attack_kugelsaat
		.word 0x81d0ec9 @//attack_aero_ass
		.word 0x81cba51 @//attack_eisspeer
		.word 0x81d0f33 @//attack_eisenabwehr
		.word 0x81d0f5d @//attack_rueckentzug
		.word 0x81d0f6c @//attack_jauler
		.word 0x81d7260 @//attack_drachenklaue
		.word 0x81d76cf @//attack_fauna_statue
		.word 0x81d0f8e @//attack_protzer
		.word 0x81d3f17 @//attack_sprungfeder
		.word 0x81d74c9 @//attack_lehmschuss
		.word 0x81d5352 @//attack_giftschweif
		.word 0x81d0fac @//attack_bezirzer
		.word 0x81d1009 @//attack_volttackle
		.word 0x81d90fd @//attack_zauberblatt
		.word 0x81d1101 @//attack_nassmacher
		.word 0x81d1127 @//attack_gedankengut
		.word 0x81d11a7 @//attack_laubklinge
		.word 0x81d122a @//attack_drachentanz
		.word 0x81d84b3 @//attack_felswurf
		.word 0x81d1299 @//attack_schockwelle
		.word 0x81d8b36 @//attack_aquawelle
		.word 0x81d8d2f @//attack_kismetwunsch
		.word 0x81d8c2b @//attack_psyschub
		.word 0x81d9669 @//attack_filler
		.word 0x81d9cd4 @//attack_hammerarm
		.word 0x81cb845 @//attack_aurasphaere
		.word 0x81d5352 @//attack_gifthieb
		.word 0x81d9cd4 @//attack_fokusstoss
		.word 0x81cf395 @//attack_patronenhieb
		.word 0x81cf366 @//attack_finsteraura
		.word 0x81cb892 @//attack_flammenblitz
		.word 0x81d2420 @//attack_eiszahn
		.word 0x81d2420 @//attack_donnerzahn
		.word 0x81d0e06 @//attack_dunkelklaue
		.word 0x81cd659 @//attack_kreuzschere
		.word 0x81cde1b @//attack_steinkante
		.word 0x81cefab @//attack_sturzflug
		.word 0x81d0f33 @//attack_steinpolitur
		.word 0x81cbb16 @//attack_kraxler
		.word 0x81d90fd @//attack_blaettersturm
		.word 0x81d78c3 @//attack_nahkampf
		.word 0x81cf143 @//attack_lichtkanone
		.word 0x81da398 @//attack_draco_meteor
		.word 0x81cce51 @//attack_nasschweif
		.word 0x81ce4ed @//attack_zen_kopfstoss
		.word 0x81d2d7d @//attack_energieball
		.word 0x81d212b @//attack_schattenstoss
		.word 0x81d3f7a @//attack_doppelschlag
		.word 0x81d0e06 @//attack_tiefschlag
		.word 0x81d0e06 @//attack_nachthieb
		.word 0x81d71ca @//attack_samenbombe
		.word 0x81d017f @//attack_erdkraefte
		.word 0x81cb845 @//attack_drachenpuls
		.word 0x81cba51 @//attack_eissplitter
		.word 0x81d2420 @//attack_feuerzahn
		.word 0x81cec54 @//attack_wasserduese
		.word 0x81d1a23 @//attack_zornfeuer
		.word attack_script_tsunami @//attack_tsunami
		.word 0x81d78c3 @//attack_stahlstreich
		.word 0x81d8c2b @//attack_kinesiswelle
		.word 0x81da66c @//attack_supernova
		.word 0x81da746 @//attack_wasserspalt
		.word 0x81d76cf @//attack_schallstich
		.word 0x81d5efc @//attack_diebeskuss
		.word 0x81cdaea @//attack_knuddler
		.word 0x81cf7de @//attack_mondgewalt
		.word 0x81d0348 @//attack_zauberschein
		.word 0x81ce830 @//attack_saeuselstimme
		.word 0x81cbcbd @//attack_bienenstich
		.word 0x81cb98c @//attack_schwarmstich
		.word 0x3f007f19 @//attack_gesang_2
		.word 0x81d017f @//attack_heissstein
		.word 0x81d1800 @//attack_gewitter
		.word 0x81d52f4 @//attack_eisenslam
		.word 0x81d310d @//attack_holzgeweih
		.word 0x81d2420 @//attack_kaeferbiss
		.word 0x81d122a @//attack_falterreigen
		.word 0x81cbf09 @//attack_nitroladung
		.word 0x81d6f9d @//attack_kaefergebrumm
		.word 0x81d8f9e @//attack_tornado
		.word 0x81cd1e5 @//attack_koenigsschild
		.word 0x81d169b @//attack glyphengleich


attack_script_tsunami:
        loadcallback 0x80ab479 0x2 0x1
        .hword 0x0
        loadcallback 0x80b95a1 0x5 0x3
        .hword 0x5, 0xa, 0x32
        loadcallback 0x80b95a1 0x5 0x3
        .hword 0x4, 0xa, 0x32
        playsound_with_pan 0xe3 0x0
        pause 0xa
        loadoam 0x83e703c 0x2 0x7
        .hword 0x1, 0x3, 0x1, 0x0, 0xe, 0x7fff, 0xe
        pause 0x10
        loadoam 0x83e703c 0x2 0x7
        .hword 0x1, 0x3, 0x1, 0x0, 0xe, 0x7fff, 0xe
        waitstate 
        end 

attack_script_secret_power:
	loadcallback attack_anim_task_secret_power 0x5 0
	end

