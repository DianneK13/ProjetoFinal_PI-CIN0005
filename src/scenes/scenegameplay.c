#include "scenes/scenegameplay.h"
#include "scenes/zoom/scenezoomcaixaarmario.h"
#include "scenes/zoom/scenezoombilhete.h"
#include "scenes/zoom/scenezoomcaixacama.h"
#include "scenes/zoom/scenezoomdiario.h"
#include "scenes/zoom/scenezoomestante.h"
#include "scenes/zoom/scenezoomgarrafa.h"
#include "scenes/zoom/scenezoompirata.h"
#include <stdlib.h>

static void SetupGameplayMain(GameContext *ctx);
// static void GameplayFreeObjects(GameContext *ctx);

static GameObject* hand = NULL;
GameObject* GetHand(void) { return hand; }

GameContext InitializeGameplayState(GameContext context) {
    context.gameplay.objects = NULL;
    context.gameplay.objectCount = 0;
    context.gameplay.substate = GAMEPLAY_SUBSTATE_MAIN;
    context.gameplay.background = LoadTexture("assets/fundofodao.png");
    SetupGameplayMain(&context);
    return context;
}

//processa ações entre o item na mão (utility) e o alvo clicado (target)
GameState processGameplayEvent(GameObject* utility, GameObject* target, GameContext *context){
    if (!target || !context) return STATE_GAMEPLAY;
    printf("process menu event: %s\n", target->name);

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
            context->gameplay.substate = GAMEPLAY_SUBSTATE_ZOOM_DIARIO;
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
}

Texture2D GetGameplayBackground(GameContext *context) {
    switch (context->gameplay.substate) {
        case GAMEPLAY_SUBSTATE_MAIN:               return context->gameplay.background;
        case GAMEPLAY_SUBSTATE_ZOOM_CAIXA_ARMARIO: return GetZoomCaixaArmarioBackground(*context);
        case GAMEPLAY_SUBSTATE_ZOOM_CAIXA_CAMA:    return GetZoomCaixaCamaBackground(*context);
        // case GAMEPLAY_SUBSTATE_ZOOM_GARRAFA:       return GetZoomGarrafaBackground(context);  //AINDA TEM QUE ARRUMAR
        // case GAMEPLAY_SUBSTATE_ZOOM_PIRATA:        return GetZoomPirataBackground(context);   //AINDA TEM QUE ARRUMAR
        // case GAMEPLAY_SUBSTATE_ZOOM_BILHETE:       return GetZoomBilheteBackground(context);  //AINDA TEM QUE ARRUMAR
        // case GAMEPLAY_SUBSTATE_ZOOM_DIARIO:        return GetZoomDiarioBackground(context);   //AINDA TEM QUE ARRUMAR
        // case GAMEPLAY_SUBSTATE_ZOOM_ESTANTE:       return GetZoomEstanteBackground(context);  //AINDA TEM QUE ARRUMAR
        default:                                   return context->gameplay.background; // fallback
    }
}

GameObject* GetGameplayObjects(GameContext *context){
    switch (context->gameplay.substate) {
        case GAMEPLAY_SUBSTATE_MAIN:               return context->gameplay.objects;
        case GAMEPLAY_SUBSTATE_ZOOM_CAIXA_ARMARIO: return GetZoomCaixaArmarioObjects(*context);
        case GAMEPLAY_SUBSTATE_ZOOM_CAIXA_CAMA:    return GetZoomCaixaCamaObjects(*context);
        // case GAMEPLAY_SUBSTATE_ZOOM_GARRAFA:       return GetZoomGarrafaObjects(*context);
        // case GAMEPLAY_SUBSTATE_ZOOM_PIRATA:        return GetZoomPirataObjects(*context);
        // case GAMEPLAY_SUBSTATE_ZOOM_BILHETE:       return GetZoomBilheteObjects(*context);
        // case GAMEPLAY_SUBSTATE_ZOOM_DIARIO:        return GetZoomDiarioObjects(*context);
        // case GAMEPLAY_SUBSTATE_ZOOM_ESTANTE:       return GetZoomEstanteObjects(*context);
        default:                                   return context->gameplay.objects;
    }
}

int GetGameplayObjectCount(GameContext *context) {
    switch (context->gameplay.substate) {
        case GAMEPLAY_SUBSTATE_MAIN:               return context->gameplay.objectCount;
        case GAMEPLAY_SUBSTATE_ZOOM_CAIXA_ARMARIO: return GetZoomCaixaArmarioObjectCount(*context);
        case GAMEPLAY_SUBSTATE_ZOOM_CAIXA_CAMA:    return GetZoomCaixaCamaObjectCount(*context);
        // case GAMEPLAY_SUBSTATE_ZOOM_GARRAFA:       return GetZoomGarrafaObjectCount(*context);
        // case GAMEPLAY_SUBSTATE_ZOOM_PIRATA:        return GetZoomPirataObjectCount(*context);
        // case GAMEPLAY_SUBSTATE_ZOOM_BILHETE:       return GetZoomBilheteObjectCount(*context);
        // case GAMEPLAY_SUBSTATE_ZOOM_DIARIO:        return GetZoomDiarioObjectCount(*context);
        // case GAMEPLAY_SUBSTATE_ZOOM_ESTANTE:       return GetZoomEstanteObjectCount(*context);
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
        .bounds=(Rectangle){0, 180, 242, 455}
    };

    // CAIXA ARMÁRIO
    ctx->gameplay.objects[ID_GAMEPLAY_CAIXA_ARMARIO] = (GameObject){
        .name="caixaArmario", .id=ID_GAMEPLAY_CAIXA_ARMARIO, .type=INTERACTIVE, .state=ORIGINAL,
        .texture = LoadTexture("assets/objetosMainGameplay/CaixaArmario.png"),
        .position=(Vector2){0, 0}, .size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT},
        .bounds = (Rectangle){66, 100, 140, 73},
    };

    // CAIXA CAMA
    ctx->gameplay.objects[ID_GAMEPLAY_CAIXA_CAMA] = (GameObject){
        .name="caixaCama", .id=ID_GAMEPLAY_CAIXA_CAMA, .type=INTERACTIVE, .state=ORIGINAL,
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
