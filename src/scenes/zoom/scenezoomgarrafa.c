#include "scenes/zoom/scenezoomgarrafa.h"

GameContext InitializeZoomGarrafaState(GameContext context) {
    context.garrafa.objectCount = 2;
    context.garrafa.objects = (GameObject*)malloc(context.garrafa.objectCount * sizeof(GameObject));

    context.garrafa.objects[ID_GARRAFA_VOLTAR].name = "voltar";
    context.garrafa.objects[ID_GARRAFA_VOLTAR].id = ID_GARRAFA_VOLTAR;
    context.garrafa.objects[ID_GARRAFA_VOLTAR].texture = LoadTexture("assets/voltarSubstates.png");
    context.garrafa.objects[ID_GARRAFA_VOLTAR].position = (Vector2){0, 0};
    context.garrafa.objects[ID_GARRAFA_VOLTAR].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
    context.garrafa.objects[ID_GARRAFA_VOLTAR].bounds = (Rectangle){5, 7, 71, 73};
    context.garrafa.objects[ID_GARRAFA_VOLTAR].state = ORIGINAL;
    context.garrafa.objects[ID_GARRAFA_VOLTAR].type = INTERACTIVE;

    context.garrafa.objects[ID_GARRAFA_ESPACO_FALA].name = "continuar";
    context.garrafa.objects[ID_GARRAFA_ESPACO_FALA].id = ID_GARRAFA_ESPACO_FALA;
    context.garrafa.objects[ID_GARRAFA_ESPACO_FALA].texture = LoadTexture("assets/.png");
    context.garrafa.objects[ID_GARRAFA_ESPACO_FALA].position = (Vector2){0, 0};
    context.garrafa.objects[ID_GARRAFA_ESPACO_FALA].size = (Vector2){0, 0};
    context.garrafa.objects[ID_GARRAFA_ESPACO_FALA].bounds = (Rectangle){0, 0, 0, 0};
    context.garrafa.objects[ID_GARRAFA_ESPACO_FALA].state = ORIGINAL;
    context.garrafa.objects[ID_GARRAFA_ESPACO_FALA].type = INTERACTIVE;

    context.garrafa.background = LoadTexture("assets/zoomGarrafa/ZoomGarrafa.png");
    return context;
}

GameplaySubstate processZoomGarrafaEvent(GameObject* target, GameContext* context) {
    switch(target->id) {
        case ID_GARRAFA_VOLTAR:
            return GAMEPLAY_SUBSTATE_MAIN;
        default:
            return GAMEPLAY_SUBSTATE_ZOOM_GARRAFA;
    }
}

Texture2D GetZoomGarrafaBackground(GameContext context) {
    return context.garrafa.background;
}

GameObject* GetZoomGarrafaObjects(GameContext context) {
    return context.garrafa.objects;
}

int GetZoomGarrafaObjectCount(GameContext context) {
    return context.garrafa.objectCount;
}