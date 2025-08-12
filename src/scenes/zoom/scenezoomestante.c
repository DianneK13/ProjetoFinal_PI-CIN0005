#include "scenes/zoom/scenezoomestante.h"

/*
//array de objects desta cena
GameObject* objects_sceneEstante;
//qtd de objetos desta cena
int objectCount_sceneEstante;

//imagem de fundo desta cena
Texture2D background_sceneEstante;
*/

GameContext InitializeZoomEstanteState(GameContext context) {
    context.estante.objectCount = 1;
    context.estante.objects = (GameObject*)malloc(context.estante.objectCount * sizeof(GameObject));

    context.estante.objects[ID_ESTANTE_VOLTAR].name = "voltar";
    context.estante.objects[ID_ESTANTE_VOLTAR].id = ID_ESTANTE_VOLTAR;
    context.estante.objects[ID_ESTANTE_VOLTAR].texture = LoadTexture("assets/voltarSubstates.png");
    context.estante.objects[ID_ESTANTE_VOLTAR].position = (Vector2){0, 0};
    context.estante.objects[ID_ESTANTE_VOLTAR].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
    context.estante.objects[ID_ESTANTE_VOLTAR].bounds = (Rectangle){5, 7, 71, 73};
    context.estante.objects[ID_ESTANTE_VOLTAR].state = ORIGINAL;
    context.estante.objects[ID_ESTANTE_VOLTAR].type = INTERACTIVE;

    context.estante.background = LoadTexture("assets/zoomEstante/ZoomEstante.png");
    return context;
}

GameplaySubstate processZoomEstanteEvent(GameObject* target, GameContext* context) {
    switch(target->id) {
        case ID_ESTANTE_VOLTAR:
            return GAMEPLAY_SUBSTATE_MAIN;
        default:
            return GAMEPLAY_SUBSTATE_ZOOM_ESTANTE;
    }
}

Texture2D GetZoomEstanteBackground(GameContext context) {
    return context.estante.background;
}

GameObject* GetZoomEstanteObjects(GameContext context) {
    return context.estante.objects;
}

int GetZoomEstanteObjectCount(GameContext context) {
    return context.estante.objectCount;
}