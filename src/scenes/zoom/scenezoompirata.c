#include "scenes/zoom/scenezoompirata.h"

/*
//array de objects desta cena
GameObject* objects_scenePirata;
//qtd de objetos desta cena
int objectCount_scenePirata;

//imagem de fundo desta cena
Texture2D background_scenePirata;
*/

GameContext InitializeZoomPirataState(GameContext context) {
    context.pirata.objectCount = 1;
    context.pirata.objects = (GameObject*)malloc(context.pirata.objectCount * sizeof(GameObject));

    context.pirata.objects[ID_PIRATA_VOLTAR].name = "voltar";
    context.pirata.objects[ID_PIRATA_VOLTAR].id = ID_PIRATA_VOLTAR;
    context.pirata.objects[ID_PIRATA_VOLTAR].texture = LoadTexture("assets/voltarSubstates.png");
    context.pirata.objects[ID_PIRATA_VOLTAR].position = (Vector2){0, 0};
    context.pirata.objects[ID_PIRATA_VOLTAR].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
    context.pirata.objects[ID_PIRATA_VOLTAR].bounds = (Rectangle){5, 7, 71, 73};
    context.pirata.objects[ID_PIRATA_VOLTAR].state = ORIGINAL;
    context.pirata.objects[ID_PIRATA_VOLTAR].type = INTERACTIVE;

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