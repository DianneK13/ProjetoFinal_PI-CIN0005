#include "scenes/zoom/scenezoombilhete.h"
#include "sfx.h"

/*
//array de objects desta cena
GameObject* objects_sceneBilhete;
//qtd de objetos desta cena
int objectCount_sceneBilhete;

//imagem de fundo desta cena
Texture2D background_sceneBilhete;
*/

#include "raylib.h"

GameContext InitializeZoomBilheteState(GameContext context) {
    context.bilhete.objectCount = 2;
    context.bilhete.objects = (GameObject*)malloc(context.bilhete.objectCount * sizeof(GameObject));

    context.bilhete.objects[ID_BILHETE_VOLTAR].name = "voltar";
    context.bilhete.objects[ID_BILHETE_VOLTAR].id = ID_BILHETE_VOLTAR;
    context.bilhete.objects[ID_BILHETE_VOLTAR].texture = LoadTexture("assets/images/ui/voltarSubstates.png");
    context.bilhete.objects[ID_BILHETE_VOLTAR].position = (Vector2){0, 0};
    context.bilhete.objects[ID_BILHETE_VOLTAR].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
    context.bilhete.objects[ID_BILHETE_VOLTAR].bounds = (Rectangle){5, 7, 71, 73};
    context.bilhete.objects[ID_BILHETE_VOLTAR].state = ORIGINAL;
    context.bilhete.objects[ID_BILHETE_VOLTAR].type = INTERACTIVE;

    // Área do papel, medida em ZoomBilhete.png (1200x800)
    context.bilhete.objects[ID_BILHETE_PAPEL] = (GameObject){
        .name="bilhete", .id=ID_BILHETE_PAPEL, .type=INTERACTIVE, .state=ORIGINAL,
        .texture=(Texture2D){0},
        .position=(Vector2){0, 0}, .size=(Vector2){0, 0},
        .bounds=(Rectangle){410, 264, 416, 316}
    };

    context.bilhete.background = LoadTexture("assets/images/zoom/bilhete/ZoomBilhete.png");
    return context;
}

GameplaySubstate processZoomBilheteEvent(GameObject* target, GameContext* context) {
    switch(target->id) {
        case ID_BILHETE_VOLTAR:
            return GAMEPLAY_SUBSTATE_MAIN;
        case ID_BILHETE_PAPEL:
            PlaySFX(SFX_LIVRO);
            return GAMEPLAY_SUBSTATE_ZOOM_BILHETE;
        default:
            return GAMEPLAY_SUBSTATE_ZOOM_BILHETE;
    }
}

Texture2D GetZoomBilheteBackground(GameContext context) {
    return context.bilhete.background;
}

GameObject* GetZoomBilheteObjects(GameContext context) {
    return context.bilhete.objects;
}

int GetZoomBilheteObjectCount(GameContext context) {
    return context.bilhete.objectCount;
}
