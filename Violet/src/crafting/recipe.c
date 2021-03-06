#include "types.h"
#include "crafting.h"
#include "item/item.h"
#include "vars.h"
#include "debug.h"
#include "flags.h"

static crafting_recipe crafting_recipies_healing[] = {
    {
        .item = ITEM_TRANK, 
        .ingredients = {
            [0] = {.item = ITEM_BITTERKRAUT, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_SUPERTRANK, 
        .ingredients = {
            [0] = {.item = ITEM_BITTERKRAUT, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_HYPERTRANK, 
        .ingredients = {
            [0] = {.item = ITEM_BITTERKRAUT, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_APFEL, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_TSITRUBEERE, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FRBADGE_2,
    },{
        .item = ITEM_TOP_TRANK, 
        .ingredients = {
            [0] = {.item = ITEM_BITTERKRAUT, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_APFEL, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FRBADGE_4,
    },{
        .item = ITEM_TOP_GENESUNG, 
        .ingredients = {
            [0] = {.item = ITEM_BITTERKRAUT, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_APFEL, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_HYPERHEILER, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FRBADGE_5,
    },{
        .item = ITEM_TOP_GENESUNG, 
        .ingredients = {
            [0] = {.item = ITEM_BITTERKRAUT, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_APFEL, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_PRUNUSBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FRBADGE_5,
    },{
        .item = ITEM_HYPERHEILER, 
        .ingredients = {
            [0] = {.item = ITEM_AMRENABEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_PIRSIFBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_FRAGIABEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [3] = {.item = ITEM_MARONBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_BELEBER, 
        .ingredients = {
            [0] = {.item = ITEM_BITTERKRAUT, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_APFEL, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_HYPERHEILER, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FRBADGE_2,
    },{
        .item = ITEM_BELEBER, 
        .ingredients = {
            [0] = {.item = ITEM_BITTERKRAUT, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_APFEL, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_PRUNUSBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FRBADGE_1,
    },{
        .item = ITEM_TOP_BELEBER, 
        .ingredients = {
            [0] = {.item = ITEM_BITTERKRAUT, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_ENERGIEQUARZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_APFEL, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [3] = {.item = ITEM_BELEBER, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FRBADGE_1,
    },{
        .item = ITEM_SEEGESANG,
        .ingredients = {
            [0] = {.item = ITEM_KUESTENSALZ, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_KUESTENSCHALE, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_GOLDAPFEL,
        .ingredients = {
            [0] = {.item = ITEM_APFEL, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_ENERGIEQUARZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_NUGGET, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        }
    }
};
static crafting_recipe crafting_recipies_jewels[] = {
    {
        .item = ITEM_NUGGET, 
        .ingredients = {
            [0] = {.item = ITEM_MININUGGET, .count = 7, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_STERNENSTUECK, 
        .ingredients = {
            [0] = {.item = ITEM_STERNENSTAUB, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_ENERGIEQUARZ, 
        .ingredients = {
            [0] = {.item = ITEM_QUARZSTAUB, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },
    {
        .item = ITEM_NORMALJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_HIMMIHBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        },
        .flag = FLAG_JEWEL_RECIPIES,
    },{
        .item = ITEM_KAMPFJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_MORBBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        },
        .flag = FLAG_JEWEL_RECIPIES,
    
    },{
        .item = ITEM_FLUGJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_NANABBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        },
        .flag = FLAG_JEWEL_RECIPIES,
    },{
        .item = ITEM_GIFTJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_NIRBEBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        },
        .flag = FLAG_JEWEL_RECIPIES,
    },{
        .item = ITEM_BODENJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_SANANABEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        },
        .flag = FLAG_JEWEL_RECIPIES,
    },{
        .item = ITEM_GESTEINJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_GRANABEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        },
        .flag = FLAG_JEWEL_RECIPIES,
    },{
        .item = ITEM_KAEFERJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_SETANGBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        },
        .flag = FLAG_JEWEL_RECIPIES,
    },{
        .item = ITEM_GEISTJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_QUALOTBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        },
        .flag = FLAG_JEWEL_RECIPIES,
    },{
        .item = ITEM_STAHLJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_HONMELBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        },
        .flag = FLAG_JEWEL_RECIPIES,
    },{
        .item = ITEM_FEEJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_LABRUSBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        },
        .flag = FLAG_JEWEL_RECIPIES,
    },{
        .item = ITEM_FEUERJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_TAMOTBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        },
        .flag = FLAG_JEWEL_RECIPIES,
    },{
        .item = ITEM_WASSERJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_SAIMBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        },
        .flag = FLAG_JEWEL_RECIPIES,
    },{
        .item = ITEM_PFLANZEJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_MAGOSTBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        },
        .flag = FLAG_JEWEL_RECIPIES,
    },{
        .item = ITEM_ELEKTROJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_RABUTABEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        },
        .flag = FLAG_JEWEL_RECIPIES,
    },{
        .item = ITEM_PSYCHOJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_TRONZIBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        },
        .flag = FLAG_JEWEL_RECIPIES,
    },{
        .item = ITEM_EISJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_KIWANBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        },
        .flag = FLAG_JEWEL_RECIPIES,
    },{
        .item = ITEM_DRACOJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_PALLMBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        },
        .flag = FLAG_JEWEL_RECIPIES,
    },{
        .item = ITEM_UNLICHTJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_WASMELBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        },
        .flag = FLAG_JEWEL_RECIPIES,
    }
};
static crafting_recipe crafting_recipies_pokeballs[] = {
    {
        .item = ITEM_TAUCHBALL, 
        .ingredients = {
            [0] = {.item = ITEM_PERLE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_POKEBALL, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_NESTBALL, 
        .ingredients = {
            [0] = {.item = ITEM_MINIPILZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_POKEBALL, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_NETZBALL, 
        .ingredients = {
            [0] = {.item = ITEM_PERLE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_POKEBALL, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_WIEDERBALL, 
        .ingredients = {
            [0] = {.item = ITEM_APFEL, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_POKEBALL, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_TIMERBALL, 
        .ingredients = {
            [0] = {.item = ITEM_STERNENSTAUB, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_POKEBALL, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_LUXUSBALL, 
        .ingredients = {
            [0] = {.item = ITEM_SUESSBONBON, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_POKEBALL, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },
};
static crafting_recipe crafting_recipies_evolution[] = {
    {
        .item = ITEM_BLATTSTEIN, 
        .ingredients = {
            [0] = {.item = ITEM_GRUENSTUECK, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_ENERGIEQUARZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 20, .type = CRAFTING_INGREDIENT_ASH},
        }
    },{
        .item = ITEM_WASSERSTEIN, 
        .ingredients = {
            [0] = {.item = ITEM_INDIGOSTUECK, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_ENERGIEQUARZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 20, .type = CRAFTING_INGREDIENT_ASH},
        }
    },{
        .item = ITEM_FEUERSTEIN, 
        .ingredients = {
            [0] = {.item = ITEM_PURPURSTUECK, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_ENERGIEQUARZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 20, .type = CRAFTING_INGREDIENT_ASH},
        }
    },{
        .item = ITEM_DONNERSTEIN, 
        .ingredients = {
            [0] = {.item = ITEM_GELBSTUECK, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_ENERGIEQUARZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 20, .type = CRAFTING_INGREDIENT_ASH},
        }
    },{
        .item = ITEM_SONNENSTEIN, 
        .ingredients = {
            [0] = {.item = ITEM_SOLARSTUECK, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_ENERGIEQUARZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 20, .type = CRAFTING_INGREDIENT_ASH},
        }
    },{
        .item = ITEM_MONDSTEIN, 
        .ingredients = {
            [0] = {.item = ITEM_LUNARSTUECK, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_ENERGIEQUARZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 20, .type = CRAFTING_INGREDIENT_ASH},
        }
    },{
        .item = ITEM_FINSTERSTEIN, 
        .ingredients = {
            [0] = {.item = ITEM_DUESTERSTUECK, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_ENERGIEQUARZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 20, .type = CRAFTING_INGREDIENT_ASH},
        }
    },{
        .item = ITEM_LEUCHTSTEIN, 
        .ingredients = {
            [0] = {.item = ITEM_LICHTSTUECK, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_ENERGIEQUARZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 20, .type = CRAFTING_INGREDIENT_ASH},
        }
    },{
        .item = ITEM_FUNKELSTEIN, 
        .ingredients = {
            [0] = {.item = ITEM_GLITZERSTUECK, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_ENERGIEQUARZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 20, .type = CRAFTING_INGREDIENT_ASH},
        }
    },{
        .item = ITEM_LINKKABEL, 
        .ingredients = {
            [0] = {.item = ITEM_STERNENSTUECK, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_NUGGET, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_ENERGIEQUARZ, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [3] = {.count = 50, .type = CRAFTING_INGREDIENT_ASH},
        },
        .flag = FLAG_LINK_CABLE_RECIPE,
    },
};
static crafting_recipe crafting_recipies_mints[] = {
    {
        .item = ITEM_ANGR_ORB_P, 
        .ingredients = {
            [0] = {.item = ITEM_LYDZIBEERE, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BITTERKRAUT, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_MINIPILZ, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_MINTS_RECIPIES,
    },{
        .item = ITEM_ANGR_ORB_N, 
        .ingredients = {
            [0] = {.item = ITEM_GIEFEBEERE, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BITTERKRAUT, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_MINIPILZ, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_MINTS_RECIPIES,
    },{
        .item = ITEM_VERT_ORB_P, 
        .ingredients = {
            [0] = {.item = ITEM_LINGANBEERE, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BITTERKRAUT, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_MINIPILZ, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_MINTS_RECIPIES,
    },{
        .item = ITEM_VERT_ORB_N, 
        .ingredients = {
            [0] = {.item = ITEM_YAPABEERE, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BITTERKRAUT, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_MINIPILZ, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_MINTS_RECIPIES,
    },{
        .item = ITEM_INIT_ORB_P, 
        .ingredients = {
            [0] = {.item = ITEM_SALKABEERE, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BITTERKRAUT, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_MINIPILZ, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_MINTS_RECIPIES,
    },{
        .item = ITEM_INIT_ORB_N, 
        .ingredients = {
            [0] = {.item = ITEM_MAGOBEERE, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BITTERKRAUT, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_MINIPILZ, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_MINTS_RECIPIES,
    },{
        .item = ITEM_SPA_ORB_P, 
        .ingredients = {
            [0] = {.item = ITEM_TAHAYBEERE, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BITTERKRAUT, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_MINIPILZ, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_MINTS_RECIPIES,
    },{
        .item = ITEM_SPA_ORB_N, 
        .ingredients = {
            [0] = {.item = ITEM_WIKIBEERE, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BITTERKRAUT, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_MINIPILZ, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_MINTS_RECIPIES,
    },{
        .item = ITEM_SPV_ORB_P, 
        .ingredients = {
            [0] = {.item = ITEM_APIKOBEERE, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BITTERKRAUT, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_MINIPILZ, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_MINTS_RECIPIES,
    },{
        .item = ITEM_SPV_ORB_N, 
        .ingredients = {
            [0] = {.item = ITEM_GAUVEBEERE, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BITTERKRAUT, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_MINIPILZ, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_MINTS_RECIPIES,
    },
};
static crafting_recipe crafting_recipies_nutrients[] = {
    {
        .item = ITEM_KP_PLUS, 
        .ingredients = {
            [0] = {.item = ITEM_APFEL, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_RIESENPILZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_BITTERKRAUT, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_NUTRIENT_RECIPIES,
    },{
        .item = ITEM_PROTEIN, 
        .ingredients = {
            [0] = {.item = ITEM_X_ANGRIFF, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_RIESENPILZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_BITTERKRAUT, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_NUTRIENT_RECIPIES,
    },{
        .item = ITEM_EISEN, 
        .ingredients = {
            [0] = {.item = ITEM_X_ABWEHR, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_RIESENPILZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_BITTERKRAUT, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_NUTRIENT_RECIPIES,
    },{
        .item = ITEM_CARBON, 
        .ingredients = {
            [0] = {.item = ITEM_X_TEMPO, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_RIESENPILZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_BITTERKRAUT, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_NUTRIENT_RECIPIES,
    },{
        .item = ITEM_KALZIUM, 
        .ingredients = {
            [0] = {.item = ITEM_X_SPEZIAL, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_RIESENPILZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_BITTERKRAUT, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_NUTRIENT_RECIPIES,
    },{
        .item = ITEM_ZINK, 
        .ingredients = {
            [0] = {.item = ITEM_X_SPEZIAL, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_RIESENPILZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_BITTERKRAUT, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_NUTRIENT_RECIPIES,
    },{
        .item = ITEM_NULLSAFT, 
        .ingredients = {
            [0] = {.item = ITEM_BITTERKRAUT, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_KUESTENSALZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_KUESTENSCHALE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_NULLSAFT_RECIPE,
    },{
        .item = ITEM_AP_PLUS, 
        .ingredients = {
            [0] = {.item = ITEM_JONAGOBEERE, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_MINIPILZ, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_ENERGIEQUARZ, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_PP_ITEM_RECIPE,
    },{
        .item = ITEM_AP_TOP, 
        .ingredients = {
            [0] = {.item = ITEM_JONAGOBEERE, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_RIESENPILZ, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_ENERGIEQUARZ, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_PP_ITEM_RECIPE,
    },{
        .item = ITEM_SONDERBONBON, 
        .ingredients = {
            [0] = {.item = ITEM_BITTERKRAUT, .count = 15, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_ENERGIEQUARZ, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_RARE_CANDY_RECIPE,
    },{
        .item = ITEM_SUESSBONBON, 
        .ingredients = {
            [0] = {.item = ITEM_BITTERKRAUT, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_GOLDBONBON, 
        .ingredients = {
            [0] = {.item = ITEM_SONDERBONBON, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_NUGGET, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_GOLD_CANDY_RECIPE,
    }
};
static crafting_recipe crafting_recipies_battle[] = {
    {
        .item = ITEM_X_ANGRIFF, 
        .ingredients = {
            [0] = {.item = ITEM_LYDZIBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_X_ABWEHR, 
        .ingredients = {
            [0] = {.item = ITEM_LINGANBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_X_TEMPO, 
        .ingredients = {
            [0] = {.item = ITEM_SALKABEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_X_SPEZIAL, 
        .ingredients = {
            [0] = {.item = ITEM_TAHAYBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_MEGABLOCK, 
        .ingredients = {
            [0] = {.item = ITEM_KRAMBOBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_ANGRIFFPLUS, 
        .ingredients = {
            [0] = {.item = ITEM_LANSATBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },
};

size_t crafting_get_num_recipies_by_type(u16 type) {
    switch (type) {
        case CRAFTING_HEALING: return ARRAY_COUNT(crafting_recipies_healing);
        case CRAFTING_POKEBALLS: return ARRAY_COUNT(crafting_recipies_pokeballs);
        case CRAFTING_JEWELS: return ARRAY_COUNT(crafting_recipies_jewels);
        case CRAFTING_EVOLUTION: return ARRAY_COUNT(crafting_recipies_evolution);
        case CRAFTING_MINTS: return ARRAY_COUNT(crafting_recipies_mints);
        case CRAFTING_NUTRIENTS: return ARRAY_COUNT(crafting_recipies_nutrients);
        case CRAFTING_BATTLE: return ARRAY_COUNT(crafting_recipies_battle);
        default: return 0;
    }
}

crafting_recipe *crafting_recipies_get_by_type(u16 type) {
    switch (type) {
        case CRAFTING_HEALING: return crafting_recipies_healing;
        case CRAFTING_POKEBALLS: return crafting_recipies_pokeballs;
        case CRAFTING_JEWELS: return crafting_recipies_jewels;
        case CRAFTING_EVOLUTION: return crafting_recipies_evolution;
        case CRAFTING_MINTS: return crafting_recipies_mints;
        case CRAFTING_NUTRIENTS: return crafting_recipies_nutrients;
        case CRAFTING_BATTLE: return crafting_recipies_battle;
        default: return 0;
    }
}

bool ingredient_requirements_fulfilled(crafting_ingredient *ingredient, u16 count) {
    count = (u16)(count * ingredient->count);
    if (count == 0)
        return true;
    switch (ingredient->type) {
        case CRAFTING_INGREDIENT_ITEM: {
            return item_check(ingredient->item, count);
        }
        case CRAFTING_INGREDIENT_ASH: {
            u16 ash = *var_access(ASH);
            return ash >= (count * CRAFTING_INGREDIENT_ASH_MULTIPLIER);
        }
    }
    return false;
}

bool recipe_requirements_fulfilled(crafting_recipe *r, u16 count) {
    for (u8 i = 0; i < ARRAY_COUNT(r->ingredients); i++) {
        if (r->ingredients[i].count > 0) {
            if (!ingredient_requirements_fulfilled(r->ingredients + i, count))
                return false;
        }
    }
    return true;
}

u16 recipe_max_count_with_requirements_fulfilled(crafting_recipe *r) {
    int max_count = INT_MAX;
    for (u8 i = 0; i < ARRAY_COUNT(r->ingredients); i++) {
        crafting_ingredient *ingredient = r->ingredients + i;
        if (ingredient->count > 0) {
            switch (ingredient->type) {
                case CRAFTING_INGREDIENT_ITEM: {
                    max_count = MIN(max_count, item_get_count(ingredient->item) / ingredient->count);
                    break;
                }
                case CRAFTING_INGREDIENT_ASH: {
                    max_count = MIN(max_count, *var_access(ASH) / (ingredient->count * CRAFTING_INGREDIENT_ASH_MULTIPLIER));
                    break;
                }
            } 
            dprintf("After ingredient %d with item %d the max count is %d\n", i, ingredient->item, max_count);
        }
    }
    return (u16) max_count;
}

bool recipe_use(crafting_recipe *r, u16 count) {
    if (recipe_requirements_fulfilled(r, count) && item_has_room(r->item, count)) {
        for (u8 i = 0; i < ARRAY_COUNT(r->ingredients); i++) {
            if (r->ingredients[i].type == CRAFTING_INGREDIENT_ASH) {
                *var_access(ASH) = (u16)(*var_access(ASH) - r->ingredients[i].count * CRAFTING_INGREDIENT_ASH_MULTIPLIER * count);
            } else if (r->ingredients[i].count > 0) {
                item_remove(r->ingredients[i].item, (u16)(r->ingredients[i].count * count));
            }
        }
        item_add(r->item, count);
        return true;
    }
    return false;
}