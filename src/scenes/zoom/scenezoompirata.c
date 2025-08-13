#include "scenes/zoom/scenezoompirata.h"

GameContext InitializeZoomPirataState(GameContext context) {
    context.pirata.objectCount = 2;
    context.pirata.objects = (GameObject*)malloc(context.pirata.objectCount * sizeof(GameObject));

    context.pirata.objects[ID_PIRATA_VOLTAR].name = "voltar";
    context.pirata.objects[ID_PIRATA_VOLTAR].id = ID_PIRATA_VOLTAR;
    context.pirata.objects[ID_PIRATA_VOLTAR].texture = LoadTexture("assets/voltarSubstates.png");
    context.pirata.objects[ID_PIRATA_VOLTAR].position = (Vector2){0, 0};
    context.pirata.objects[ID_PIRATA_VOLTAR].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
    context.pirata.objects[ID_PIRATA_VOLTAR].bounds = (Rectangle){5, 7, 71, 73};
    context.pirata.objects[ID_PIRATA_VOLTAR].state = ORIGINAL;
    context.pirata.objects[ID_PIRATA_VOLTAR].type = INTERACTIVE;

    context.pirata.objects[ID_PIRATA_ESPACO_FALA].name = "continuar";
    context.pirata.objects[ID_PIRATA_ESPACO_FALA].id = ID_PIRATA_ESPACO_FALA;
    context.pirata.objects[ID_PIRATA_ESPACO_FALA].texture = LoadTexture("assets/.png");
    context.pirata.objects[ID_PIRATA_ESPACO_FALA].position = (Vector2){0, 0};
    context.pirata.objects[ID_PIRATA_ESPACO_FALA].size = (Vector2){0, 0};
    context.pirata.objects[ID_PIRATA_ESPACO_FALA].bounds = (Rectangle){0, 0, 0, 0};
    context.pirata.objects[ID_PIRATA_ESPACO_FALA].state = ORIGINAL;
    context.pirata.objects[ID_PIRATA_ESPACO_FALA].type = INTERACTIVE;

    context.pirata.background = LoadTexture("assets/zoomPirata/ZoomPirata.png");
    return context;
}

GameplaySubstate processZoomPirataEvent(GameObject* target, GameContext* context) {
    switch(target->id) {
        case ID_PIRATA_VOLTAR:
            return GAMEPLAY_SUBSTATE_MAIN;
        default:
            return GAMEPLAY_SUBSTATE_ZOOM_PIRATA;
    }
}

Texture2D GetZoomPirataBackground(GameContext context) {
    return context.pirata.background;
}

GameObject* GetZoomPirataObjects(GameContext context) {
    return context.pirata.objects;
}

int GetZoomPirataObjectCount(GameContext context) {
    return context.pirata.objectCount;
}