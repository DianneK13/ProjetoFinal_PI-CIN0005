#include "scenes/scenegameplay.h"
#include "scenes/zoom/scenezoomcaixaarmario.h"
#include "scenes/zoom/scenezoomcaixacama.h"
#include "scenes/zoom/scenezoombilhete.h"
#include "scenes/zoom/scenezoomdiario.h"
#include "scenes/zoom/scenezoomestante.h"
#include "scenes/zoom/scenezoomgarrafa.h"
#include "scenes/zoom/scenezoompirata.h"
#include <stdlib.h>

int counterSimbolos[4] = {1, 1, 1, 1};
int counterNumeros[4] = {0, 0, 0, 0};
int temChave=0, leuBilhete=0;

static void SetupGameplayMain(GameContext *ctx);
// static void GameplayFreeObjects(GameContext *ctx);

static GameObject* hand = NULL;
GameObject* GetHand(void) { return hand; }

GameContext InitializeGameplayState(GameContext context) {
    memset(context.flags, 0, sizeof(context.flags));
    context.gameplay.objects = NULL;
    context.gameplay.objectCount = 0;
    context.gameplay.substate = GAMEPLAY_SUBSTATE_MAIN;
    context.gameplay.background = LoadTexture("assets/fundofodao.png");
    SetupGameplayMain(&context);

    return context;
}

// Helper
static bool HasEstanteLetters(GameContext* ctx) {
    if (!ctx->estante.objects) return false;
    return ctx->estante.objectCount > ID_ESTANTE_LETRA_6;
}

void ProcessFlags(GameContext* context, GameObject* target)
{
    if (!context) return;

    // 1) Flag de início de história (uma vez só)
    // if (context->state == STATE_GAMEPLAY && context->flags[HISTORIA_INIT] == 0) {
    //     printf("comeco\n");
    //     context->flags[HISTORIA_INIT] = 1;
    // }

    if (!target) return;

    // 2) Eventos no substate MAIN, baseados no alvo clicado
    if (context->gameplay.substate == GAMEPLAY_SUBSTATE_MAIN && target) {
        switch (target->id) {
            case ID_GAMEPLAY_CAIXA_ARMARIO:
                if (context->flags[CAIXA_ARMARIO] == 0) {
                    printf("dialogo caixa armario\n");
                    context->flags[CAIXA_ARMARIO] = 1;
                }
                return;

            case ID_GAMEPLAY_CAIXA_CAMA:
                if (context->flags[CAIXA_CAMA] == 0) {
                    printf("dialogo caixa cama\n");
                    context->flags[CAIXA_CAMA] = 1;
                }
                return;

            case ID_GAMEPLAY_GARRAFA:
                if (context->flags[GARRAFA] == 0) {
                    printf("dialogo garrafa\n");
                    context->flags[GARRAFA] = 1;
                }
                return;

            case ID_GAMEPLAY_PIRATA:
                if (context->flags[PIRATA] == 0) {
                    printf("dialogo pirata\n");
                    context->flags[PIRATA] = 1;
                }
                return;

            case ID_GAMEPLAY_ESTANTE:
                if (context->flags[ESTANTE] == 0) {
                    printf("dialogo estante\n");
                    context->flags[ESTANTE] = 1;
                }
                return;

            case ID_GAMEPLAY_VITROLA:
                if (context->flags[VITROLA] == 0) {
                    printf("dialogo vitrola\n");
                    context->flags[VITROLA] = 1;
                }
                return;

            case ID_GAMEPLAY_DIARIO:
                if (context->flags[DIADO_N_CHAVE] == 0 && temChave == 0) {
                    printf("dialogo sem chave\n");
                    context->flags[DIADO_N_CHAVE] = 1;
                }
                return;

            case ID_GAMEPLAY_BILHETE:
                if (context->flags[BILHETE] == 0) {
                    printf("dialogo bilhete\n");
                    context->flags[BILHETE] = 1;
                }
                return;

            default: break;
        }
    }

    // 3) Eventos quando já está NO ZOOM
    switch (context->gameplay.substate) {
        case GAMEPLAY_SUBSTATE_ZOOM_DIARIO:
            if (context->flags[DIARIO] == 0) {
                printf("dialogo diario\n");
                context->flags[DIARIO] = 1;
            }
            break;

        case GAMEPLAY_SUBSTATE_ZOOM_ESTANTE:
            if (HasEstanteLetters(context)) {
                bool todasAlteradas =
                    context->estante.objects[ID_ESTANTE_LETRA_1].state == ALTERED &&
                    context->estante.objects[ID_ESTANTE_LETRA_2].state == ALTERED &&
                    context->estante.objects[ID_ESTANTE_LETRA_3].state == ALTERED &&
                    context->estante.objects[ID_ESTANTE_LETRA_4].state == ALTERED &&
                    context->estante.objects[ID_ESTANTE_LETRA_5].state == ALTERED &&
                    context->estante.objects[ID_ESTANTE_LETRA_6].state == ALTERED;

                if (todasAlteradas && context->flags[FINAL] == 0) {
                    printf("dialogo final\n");
                    context->flags[FINAL] = 1;
                }
            }
            break;

        default:
            break;
    }

    // 4) Chave adquirida (flag solta)
    if (context->flags[CHAVE] == 0 && temChave == 1) {
        printf("dialogo chave\n");
        context->flags[CHAVE] = 1;
    }
}


//processa ações entre o objeto na mão do jogador e o objeto em que ele clicou
GameState processGameplayEvent(GameObject* utility, GameObject* target, GameContext* context){

    if (!target || !context) return STATE_GAMEPLAY;
    ProcessFlags(context, target);
    printf("process menu event: %s\n", target->name);
    switch(context->gameplay.substate){
        case GAMEPLAY_SUBSTATE_MAIN:
            switch(target->id) {
                case ID_GAMEPLAY_CAIXA_ARMARIO:
                    context->gameplay.substate = GAMEPLAY_SUBSTATE_ZOOM_CAIXA_ARMARIO;
                    return STATE_GAMEPLAY;
                case ID_GAMEPLAY_CAIXA_CAMA:
                    context->gameplay.substate = GAMEPLAY_SUBSTATE_ZOOM_CAIXA_CAMA;
                    return STATE_GAMEPLAY;
                case ID_GAMEPLAY_GARRAFA:
                    context->gameplay.substate = GAMEPLAY_SUBSTATE_ZOOM_GARRAFA;
                    return STATE_GAMEPLAY;
                case ID_GAMEPLAY_DIARIO:
                    if(temChave == 0) context->gameplay.substate = GAMEPLAY_SUBSTATE_MAIN;
                    else context->gameplay.substate = GAMEPLAY_SUBSTATE_ZOOM_DIARIO;
                    return STATE_GAMEPLAY;
                case ID_GAMEPLAY_ESTANTE:
                    context->gameplay.substate = GAMEPLAY_SUBSTATE_ZOOM_ESTANTE;
                    return STATE_GAMEPLAY;
                case ID_GAMEPLAY_BILHETE:
                    context->gameplay.substate = GAMEPLAY_SUBSTATE_ZOOM_BILHETE;
                    return STATE_GAMEPLAY;
                case ID_GAMEPLAY_PIRATA:
                    context->gameplay.substate = GAMEPLAY_SUBSTATE_ZOOM_PIRATA;
                    return STATE_GAMEPLAY;

                // itens "normais" /sem zoom
                case ID_GAMEPLAY_VITROLA:
                case ID_GAMEPLAY_ARMARIO:
                case ID_GAMEPLAY_CHAVE:
                default:
                    context->gameplay.substate = GAMEPLAY_SUBSTATE_MAIN;
                return STATE_GAMEPLAY;
            }

        case GAMEPLAY_SUBSTATE_ZOOM_CAIXA_ARMARIO:
            context->gameplay.substate = processZoomCaixaArmarioEvent(target, context, counterSimbolos, &temChave);
            return STATE_GAMEPLAY;

        case GAMEPLAY_SUBSTATE_ZOOM_CAIXA_CAMA:
            context->gameplay.substate = processZoomCaixaCamaEvent(target, context, counterNumeros, &leuBilhete);
            return STATE_GAMEPLAY;

        case GAMEPLAY_SUBSTATE_ZOOM_GARRAFA:
            context->gameplay.substate = processZoomGarrafaEvent(target, context);
            return STATE_GAMEPLAY;

        case GAMEPLAY_SUBSTATE_ZOOM_PIRATA:
            context->gameplay.substate = processZoomPirataEvent(target, context);
            return STATE_GAMEPLAY;

        case GAMEPLAY_SUBSTATE_ZOOM_BILHETE:
            context->gameplay.substate = processZoomBilheteEvent(target, context);
            return STATE_GAMEPLAY;

        case GAMEPLAY_SUBSTATE_ZOOM_DIARIO:
            context->gameplay.substate = processZoomDiarioEvent(target, context);
            return STATE_GAMEPLAY;

        case GAMEPLAY_SUBSTATE_ZOOM_ESTANTE:
            context->gameplay.substate = processZoomEstanteEvent(target, context, &leuBilhete);
            return STATE_GAMEPLAY;
        default:
            context->gameplay.substate = GAMEPLAY_SUBSTATE_MAIN;
        return STATE_GAMEPLAY;
    }
}

Texture2D GetGameplayBackground(GameContext *context) {
    switch (context->gameplay.substate) {
        case GAMEPLAY_SUBSTATE_MAIN:               return context->gameplay.background;
        case GAMEPLAY_SUBSTATE_ZOOM_CAIXA_ARMARIO: return GetZoomCaixaArmarioBackground(*context);
        case GAMEPLAY_SUBSTATE_ZOOM_CAIXA_CAMA:    return GetZoomCaixaCamaBackground(*context);
        case GAMEPLAY_SUBSTATE_ZOOM_GARRAFA:       return GetZoomGarrafaBackground(*context);
        case GAMEPLAY_SUBSTATE_ZOOM_PIRATA:        return GetZoomPirataBackground(*context);
        case GAMEPLAY_SUBSTATE_ZOOM_BILHETE:       return GetZoomBilheteBackground(*context);
        case GAMEPLAY_SUBSTATE_ZOOM_DIARIO:        return GetZoomDiarioBackground(*context);
        case GAMEPLAY_SUBSTATE_ZOOM_ESTANTE:       return GetZoomEstanteBackground(*context);
        default:                                   return context->gameplay.background; // fallback
    }
}

GameObject* GetGameplayObjects(GameContext *context){
    switch (context->gameplay.substate) {
        case GAMEPLAY_SUBSTATE_MAIN:               return context->gameplay.objects;
        case GAMEPLAY_SUBSTATE_ZOOM_CAIXA_ARMARIO: return GetZoomCaixaArmarioObjects(*context);
        case GAMEPLAY_SUBSTATE_ZOOM_CAIXA_CAMA:    return GetZoomCaixaCamaObjects(*context);
        case GAMEPLAY_SUBSTATE_ZOOM_GARRAFA:       return GetZoomGarrafaObjects(*context);
        case GAMEPLAY_SUBSTATE_ZOOM_PIRATA:        return GetZoomPirataObjects(*context);
        case GAMEPLAY_SUBSTATE_ZOOM_BILHETE:       return GetZoomBilheteObjects(*context);
        case GAMEPLAY_SUBSTATE_ZOOM_DIARIO:        return GetZoomDiarioObjects(*context);
        case GAMEPLAY_SUBSTATE_ZOOM_ESTANTE:       return GetZoomEstanteObjects(*context);
        default:                                   return context->gameplay.objects;
    }
}

int GetGameplayObjectCount(GameContext *context) {
    switch (context->gameplay.substate) {
        case GAMEPLAY_SUBSTATE_MAIN:               return context->gameplay.objectCount;
        case GAMEPLAY_SUBSTATE_ZOOM_CAIXA_ARMARIO: return GetZoomCaixaArmarioObjectCount(*context);
        case GAMEPLAY_SUBSTATE_ZOOM_CAIXA_CAMA:    return GetZoomCaixaCamaObjectCount(*context);
        case GAMEPLAY_SUBSTATE_ZOOM_GARRAFA:       return GetZoomGarrafaObjectCount(*context);
        case GAMEPLAY_SUBSTATE_ZOOM_PIRATA:        return GetZoomPirataObjectCount(*context);
        case GAMEPLAY_SUBSTATE_ZOOM_BILHETE:       return GetZoomBilheteObjectCount(*context);
        case GAMEPLAY_SUBSTATE_ZOOM_DIARIO:        return GetZoomDiarioObjectCount(*context);
        case GAMEPLAY_SUBSTATE_ZOOM_ESTANTE:       return GetZoomEstanteObjectCount(*context);
        default:                                   return context->gameplay.objectCount;
    }
}

// static void GameplayFreeObjects(GameContext *ctx) {
//     if (!ctx->gameplay.objects) return;
//     for (int i = 0; i < ctx->gameplay.objectCount; i++) {
//         if (ctx->gameplay.objects[i].texture.id != 0) {
//             UnloadTexture(ctx->gameplay.objects[i].texture);
//         }
//     }
//     free(ctx->gameplay.objects);
//     ctx->gameplay.objects = NULL;
//     ctx->gameplay.objectCount = 0;
// }

static void SetupGameplayMain(GameContext *ctx) {
    // GameplayFreeObjects(ctx);

    ctx->gameplay.objectCount = 10;
    ctx->gameplay.objects = (GameObject*)malloc(sizeof(GameObject) * ctx->gameplay.objectCount);
    if (!ctx->gameplay.objects) { ctx->gameplay.objectCount = 0; return; }

    // ARMÁRIO
    ctx->gameplay.objects[ID_GAMEPLAY_ARMARIO] = (GameObject){
        .name="armario", .id=ID_GAMEPLAY_ARMARIO, .type=INTERACTIVE, .state=ORIGINAL,
        .texture=LoadTexture("assets/objetosMainGameplay/Armario.png"),
        .position=(Vector2){0, 0}, .size=(Vector2){SCREEN_WIDTH, SCREEN_HEIGHT},
        .bounds=(Rectangle){0, 0, 0, 0}
    };

    // CAIXA ARMÁRIO
    ctx->gameplay.objects[ID_GAMEPLAY_CAIXA_ARMARIO] = (GameObject){
        .name="caixa", .id=ID_GAMEPLAY_CAIXA_ARMARIO, .type=INTERACTIVE, .state=ORIGINAL,
        .texture = LoadTexture("assets/objetosMainGameplay/CaixaArmario.png"),
        .position=(Vector2){0, 0}, .size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT},
        .bounds = (Rectangle){66, 100, 140, 73},
    };

    // CAIXA CAMA
    ctx->gameplay.objects[ID_GAMEPLAY_CAIXA_CAMA] = (GameObject){
        .name="cofre", .id=ID_GAMEPLAY_CAIXA_CAMA, .type=INTERACTIVE, .state=ORIGINAL,
        .texture = LoadTexture("assets/objetosMainGameplay/CaixaCama.png"),
        .position=(Vector2){0, 0}, .size=(Vector2){SCREEN_WIDTH, SCREEN_HEIGHT},
        .bounds = (Rectangle){957, 710, 118, 75},
    };

    // DIARIO
    ctx->gameplay.objects[ID_GAMEPLAY_DIARIO] = (GameObject){
        .name="diario", .id=ID_GAMEPLAY_DIARIO, .type=INTERACTIVE, .state=ORIGINAL,
        .texture = LoadTexture("assets/objetosMainGameplay/Diario.png"),
        .position=(Vector2){0, 0}, .size=(Vector2){SCREEN_WIDTH, SCREEN_HEIGHT},
        .bounds = (Rectangle){563, 417, 58, 54},
    };

    // VITROLA
    ctx->gameplay.objects[ID_GAMEPLAY_VITROLA] = (GameObject){
        .name="vitrola", .id=ID_GAMEPLAY_VITROLA, .type=INTERACTIVE, .state=ORIGINAL,
        .texture = LoadTexture("assets/objetosMainGameplay/Vitrola.png"),
        .position=(Vector2){0, 0}, .size=(Vector2){SCREEN_WIDTH, SCREEN_HEIGHT},
        .bounds = (Rectangle){390, 313, 105, 153},
    };

    // GARRAFA
    ctx->gameplay.objects[ID_GAMEPLAY_GARRAFA] = (GameObject){
        .name="garrafa", .id=ID_GAMEPLAY_GARRAFA, .type=INTERACTIVE, .state=ORIGINAL,
        .texture = LoadTexture("assets/objetosMainGameplay/Garrafa.png"),
        .position=(Vector2){0, 0}, .size=(Vector2){SCREEN_WIDTH, SCREEN_HEIGHT},
        .bounds = (Rectangle){725, 393, 45, 79}
    };

    // ESTANTE
    ctx->gameplay.objects[ID_GAMEPLAY_ESTANTE] = (GameObject){
        .name="estante", .id=ID_GAMEPLAY_ESTANTE, .type=INTERACTIVE, .state=ORIGINAL,
        .texture = LoadTexture("assets/objetosMainGameplay/Estante.png"),
        .position=(Vector2){0, 0}, .size=(Vector2){SCREEN_WIDTH, SCREEN_HEIGHT},
        .bounds = (Rectangle){905, 191, 157, 101},
    };

    // PIRATA
    ctx->gameplay.objects[ID_GAMEPLAY_PIRATA] = (GameObject){
        .name="pirata", .id=ID_GAMEPLAY_PIRATA, .type=INTERACTIVE, .state=ORIGINAL,
        .texture = LoadTexture("assets/objetosMainGameplay/Pirata.png"),
        .position=(Vector2){0, 0}, .size=(Vector2){SCREEN_WIDTH, SCREEN_HEIGHT},
        .bounds = (Rectangle){873, 377, 156, 183}
    };

    // CHAVE
    ctx->gameplay.objects[ID_GAMEPLAY_CHAVE] = (GameObject){
        .name="chave", .id=ID_GAMEPLAY_CHAVE, .type=INTERACTIVE, .state=ORIGINAL,
        .texture=LoadTexture("assets/jill.png"),
        .position=(Vector2){0, 0}, .size=(Vector2){0, 0},
        .bounds=(Rectangle){0, 0, 0, 0}
    };

    // BILHETE
    ctx->gameplay.objects[ID_GAMEPLAY_BILHETE] = (GameObject){
        .name="bilhete", .id=ID_GAMEPLAY_BILHETE, .type=INTERACTIVE, .state=ORIGINAL,
        .texture = LoadTexture("assets/jill.png"),
        .position=(Vector2){0, 0}, .size=(Vector2){0, 0},
        .bounds=(Rectangle){0, 0, 0, 0}
    };

    if (ctx->gameplay.background.id) UnloadTexture(ctx->gameplay.background);
    ctx->gameplay.background = LoadTexture("assets/fundofodao.png");
}
