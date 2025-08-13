#include "scenes/zoom/scenezoomdiario.h"

GameContext InitializeZoomDiarioState(GameContext context) {
    context.diario.objectCount = 1;
    context.diario.objects = (GameObject*)malloc(context.diario.objectCount * sizeof(GameObject));

    context.diario.objects[ID_DIARIO_VOLTAR].name = "voltar";
    context.diario.objects[ID_DIARIO_VOLTAR].id = ID_DIARIO_VOLTAR;
    context.diario.objects[ID_DIARIO_VOLTAR].texture = LoadTexture("assets/voltarSubstates.png");
    context.diario.objects[ID_DIARIO_VOLTAR].position = (Vector2){0, 0};
    context.diario.objects[ID_DIARIO_VOLTAR].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
    context.diario.objects[ID_DIARIO_VOLTAR].bounds = (Rectangle){5, 7, 71, 73};
    context.diario.objects[ID_DIARIO_VOLTAR].state = ORIGINAL;
    context.diario.objects[ID_DIARIO_VOLTAR].type = INTERACTIVE;

    context.diario.background = LoadTexture("assets/zoomDiario/ZoomDiario.png");
    return context;
}

GameplaySubstate processZoomDiarioEvent(GameObject* target, GameContext* context) {
    switch(target->id) {
        case ID_DIARIO_VOLTAR:
            return GAMEPLAY_SUBSTATE_MAIN;
        default:
            return GAMEPLAY_SUBSTATE_ZOOM_DIARIO;
    }
}

Texture2D GetZoomDiarioBackground(GameContext context) {
    return context.diario.background;
}

GameObject* GetZoomDiarioObjects(GameContext context) {
    return context.diario.objects;
}

int GetZoomDiarioObjectCount(GameContext context) {
    return context.diario.objectCount;
}