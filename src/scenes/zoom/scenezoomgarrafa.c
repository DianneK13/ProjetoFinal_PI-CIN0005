#include "scenes/zoom/scenezoomgarrafa.h"

/*
//array de objects desta cena
GameObject* objects_sceneGarrafa;
//qtd de objetos desta cena
int objectCount_sceneGarrafa;

//imagem de fundo desta cena
Texture2D background_sceneGarrafa;
*/

// SFX para a cena zoom garrafa
#include "raylib.h"
static Sound sfx_garrafa;
static int sfx_garrafa_loaded = 0;

GameContext InitializeZoomGarrafaState(GameContext context) {
    if (!sfx_garrafa_loaded) {
        sfx_garrafa = LoadSound("assets/audio/sfx/garrafa.mp3");
        sfx_garrafa_loaded = 1;
    }
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
    // Toca o SFX ao clicar em qualquer objeto
    if (sfx_garrafa_loaded) PlaySound(sfx_garrafa);
    switch(target->id) {
        case ID_GARRAFA_VOLTAR:
            return GAMEPLAY_SUBSTATE_MAIN;

        case ID_GARRAFA_ESPACO_FALA:
            target->size = (Vector2){0, 0};
            target->bounds = (Rectangle){0, 0, 0, 0};
            return GAMEPLAY_SUBSTATE_ZOOM_GARRAFA;

        default:
            return GAMEPLAY_SUBSTATE_ZOOM_GARRAFA;
    }
// Libera o SFX ao sair da cena (opcional, pode ser chamado externamente se desejar)
void UnloadZoomGarrafaSFX(void) {
    if (sfx_garrafa_loaded) {
        UnloadSound(sfx_garrafa);
        sfx_garrafa_loaded = 0;
    }
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