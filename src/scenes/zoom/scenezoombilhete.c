#include "scenes/zoom/scenezoombilhete.h"

GameContext InitializeZoomBilheteState(GameContext context) {
    context.bilhete.objectCount = 1;
    context.bilhete.objects = (GameObject*)malloc(context.bilhete.objectCount * sizeof(GameObject));

    context.bilhete.objects[ID_BILHETE_VOLTAR].name = "voltar";
    context.bilhete.objects[ID_BILHETE_VOLTAR].id = ID_BILHETE_VOLTAR;
    context.bilhete.objects[ID_BILHETE_VOLTAR].texture = LoadTexture("assets/voltarSubstates.png");
    context.bilhete.objects[ID_BILHETE_VOLTAR].position = (Vector2){0, 0};
    context.bilhete.objects[ID_BILHETE_VOLTAR].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
    context.bilhete.objects[ID_BILHETE_VOLTAR].bounds = (Rectangle){5, 7, 71, 73};
    context.bilhete.objects[ID_BILHETE_VOLTAR].state = ORIGINAL;
    context.bilhete.objects[ID_BILHETE_VOLTAR].type = INTERACTIVE;

    context.bilhete.background = LoadTexture("assets/zoomBilhete/ZoomBilhete.png");
    return context;
}

GameplaySubstate processZoomBilheteEvent(GameObject* target, GameContext* context) {
    switch(target->id) {
        case ID_BILHETE_VOLTAR:
            return GAMEPLAY_SUBSTATE_MAIN;
        default:
            return GAMEPLAY_SUBSTATE_ZOOM_BILHETE;
    }
}

Texture2D GetZoomBilheteBackground(GameContext) {
    
}

GameObject* GetZoomBilheteObjects(GameContext context) {
    
}

int GetZoomBilheteObjectCount(GameContext context) {
    
}