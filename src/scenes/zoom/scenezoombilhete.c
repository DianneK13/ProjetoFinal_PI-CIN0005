#include "scenes/zoom/scenezoombilhete.h"

/*
//array de objects desta cena
GameObject* objects_sceneBilhete;
//qtd de objetos desta cena
int objectCount_sceneBilhete;

//imagem de fundo desta cena
Texture2D background_sceneBilhete;
*/

#include "raylib.h"
static Sound sfx_bilhete;
static int sfx_bilhete_loaded = 0;

GameContext InitializeZoomBilheteState(GameContext context) {
    if (!sfx_bilhete_loaded) {
        sfx_bilhete = LoadSound("assets/audio/sfx/livro.mp3");
        sfx_bilhete_loaded = 1;
    }
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
    if (sfx_bilhete_loaded) PlaySound(sfx_bilhete);
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