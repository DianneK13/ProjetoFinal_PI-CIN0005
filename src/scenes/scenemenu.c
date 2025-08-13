#include "scenes/scenemenu.h"

// Libera texturas e array de objetos do menu
static void MenuFreeObjects(GameContext *ctx) {
    if (!ctx->menu.objects) return;
    for (int i = 0; i < ctx->menu.objectCount; i++) {
        if (ctx->menu.objects[i].texture.id != 0) {
            UnloadTexture(ctx->menu.objects[i].texture);
        }
    }
    free(ctx->menu.objects);
    ctx->menu.objects = NULL;
    ctx->menu.objectCount = 0;
}

// funções helper para reconfigurar os objetos conforme o substate
static void SetupMenuMain(GameContext *ctx) {
    MenuFreeObjects(ctx);

    ctx->menu.objectCount = 3;
    ctx->menu.objects = malloc(ctx->menu.objectCount * sizeof(GameObject));

    ctx->menu.objects[ID_MENU_BOTAO_START] = (GameObject) {
        .name="botao_start", .id=ID_MENU_BOTAO_START, .type=INTERACTIVE, .state=ORIGINAL,
        .texture=LoadTexture("assets/JOGAR.png"),
        .position=(Vector2){0, 0}, .size=(Vector2){SCREEN_WIDTH, SCREEN_HEIGHT},
        .bounds=(Rectangle){763, 293, 261, 67}
    };

    ctx->menu.objects[ID_MENU_BOTAO_CREDITOS] = (GameObject) {
        .name="botao_creditos", .id=ID_MENU_BOTAO_CREDITOS, .type=INTERACTIVE, .state=ORIGINAL,
        .texture=LoadTexture("assets/CREDITOS.png"),
        .position=(Vector2){0, 0}, .size=(Vector2){SCREEN_WIDTH, SCREEN_HEIGHT},
        .bounds=(Rectangle){763, 377, 261, 67}
    };

    ctx->menu.objects[ID_MENU_BOTAO_SAIR] = (GameObject) {
        .name="botao_sair", .id=ID_MENU_BOTAO_SAIR, .type=INTERACTIVE, .state=ORIGINAL,
        .texture=LoadTexture("assets/SAIR.png"),
        .position=(Vector2){0, 0}, .size=(Vector2){SCREEN_WIDTH, SCREEN_HEIGHT},
        .bounds=(Rectangle){763, 460, 261, 67}
    };

    if (ctx->menu.background.id != 0) UnloadTexture(ctx->menu.background);
    ctx->menu.background = LoadTexture("assets/menu_background.png");
}


static void SetupMenuCreditos(GameContext *ctx) {
    MenuFreeObjects(ctx);

    ctx->menu.objectCount = 1;
    ctx->menu.objects = malloc(ctx->menu.objectCount * sizeof(GameObject));

    // Índice é 0, id é o constante de VOLTAR
    ctx->menu.objects[0] = (GameObject) {
        .name="botao_voltar", .id=ID_MENU_BOTAO_VOLTAR, .type=INTERACTIVE, .state=ORIGINAL,
        .texture=LoadTexture("assets/voltarSubstates.png"),
        .position=(Vector2){1116, 0}, .size=(Vector2){SCREEN_WIDTH, SCREEN_HEIGHT},
        .bounds=(Rectangle){1123, 7, 71, 73}
    };

    if (ctx->menu.background.id != 0) UnloadTexture(ctx->menu.background);
    ctx->menu.background = LoadTexture("assets/créditos_background.png");
}


GameContext InitializeMenuState(GameContext context) {
    context.menu.objects = NULL;
    context.menu.objectCount = 0;
    context.menu.background.id = 0;
    context.menu.substate = MENU_SUBSTATE_MAIN;
    SetupMenuMain(&context);
    return context;
}

Texture2D GetMenuBackground(GameContext context){
    return context.menu.background;
}

//processa ações do menu
GameState processMenuEvent(GameObject* clickedObject, GameContext *context) {
    if (!clickedObject) return STATE_MENU;
    printf("process menu event: %s\n", clickedObject->name);

    switch(context->menu.substate) {
        case MENU_SUBSTATE_MAIN:
            switch(clickedObject->id) {
            case ID_MENU_BOTAO_START:
                    return STATE_GAMEPLAY;
            case ID_MENU_BOTAO_CREDITOS:
                    context->menu.substate = MENU_SUBSTATE_CREDITOS;
                    SetupMenuCreditos(context);
                    return STATE_MENU;
            case ID_MENU_BOTAO_SAIR:
                    context->should_close = true;
                    return STATE_MENU;
            default:
                    break;
            }
            return STATE_MENU;

        case MENU_SUBSTATE_CREDITOS:
            switch (clickedObject->id) {
            case ID_MENU_BOTAO_VOLTAR:
                    context->menu.substate = MENU_SUBSTATE_MAIN;
                    SetupMenuMain(context);
                    return STATE_MENU;
            default:
                    break;
            }
            return STATE_MENU;

        default:
            break;
    }

    return STATE_MENU;
}


GameObject* GetMenuObjects(GameContext context){
    return context.menu.objects;
}

int GetMenuObjectCount(GameContext context){
    return context.menu.objectCount;
}