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
        .texture=LoadTexture("assets/jogar.png"),
        .position=(Vector2){700, 100}, .size=(Vector2){150, 120},
        .bounds=(Rectangle){700, 100, 150, 120}
    };

    ctx->menu.objects[ID_MENU_BOTAO_CREDITOS] = (GameObject) {
        .name="botao_creditos", .id=ID_MENU_BOTAO_CREDITOS, .type=INTERACTIVE, .state=ORIGINAL,
        .texture=LoadTexture("assets/creditosfodao.png"),
        .position=(Vector2){700, 300}, .size=(Vector2){150, 120},
        .bounds=(Rectangle){700, 300, 150, 120}
    };

    ctx->menu.objects[ID_MENU_BOTAO_SAIR] = (GameObject) {
        .name="botao_sair", .id=ID_MENU_BOTAO_SAIR, .type=INTERACTIVE, .state=ORIGINAL,
        .texture=LoadTexture("assets/sair.png"),
        .position=(Vector2){700, 500}, .size=(Vector2){150, 120},
        .bounds=(Rectangle){700, 500, 150, 120}
    };

    if (ctx->menu.background.id != 0) UnloadTexture(ctx->menu.background);
    ctx->menu.background = LoadTexture("assets/menufodao.png");
}


static void SetupMenuCreditos(GameContext *ctx) {
    MenuFreeObjects(ctx);

    ctx->menu.objectCount = 1;
    ctx->menu.objects = malloc(ctx->menu.objectCount * sizeof(GameObject));

    // Índice é 0, id é o constante de VOLTAR
    ctx->menu.objects[0] = (GameObject) {
        .name="botao_voltar", .id=ID_MENU_BOTAO_VOLTAR, .type=INTERACTIVE, .state=ORIGINAL,
        .texture=LoadTexture("assets/voltar.png"),
        .position=(Vector2){30, 30}, .size=(Vector2){150, 120},
        .bounds=(Rectangle){30, 30, 150, 120}
    };

    if (ctx->menu.background.id != 0) UnloadTexture(ctx->menu.background);
    ctx->menu.background = LoadTexture("assets/creditosfodao.png");
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
                    CloseWindow();
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