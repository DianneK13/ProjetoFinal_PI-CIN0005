#include "scenes/zoom/scenezoomcaixacama.h"

/*
//array de objects desta cena
GameObject* objects_sceneCaixaCama;
//qtd de objetos desta cena
int objectCount_sceneCaixaCama;

//imagem de fundo desta cena
Texture2D background_sceneCaixaCama;
*/

GameContext InitializeZoomCaixaCamaState(GameContext context) {
    context.caixa_cama.objectCount = 6;
    context.caixa_cama.objects = (GameObject*)malloc(context.caixa_cama.objectCount * sizeof(GameObject));

    context.caixa_cama.objects[ID_CAIXA_CAMA_VOLTAR].name = "voltar";
    context.caixa_cama.objects[ID_CAIXA_CAMA_VOLTAR].id = ID_CAIXA_CAMA_VOLTAR;
    context.caixa_cama.objects[ID_CAIXA_CAMA_VOLTAR].texture = LoadTexture("assets/voltarSubstates.png");
    context.caixa_cama.objects[ID_CAIXA_CAMA_VOLTAR].position = (Vector2){0, 0};
    context.caixa_cama.objects[ID_CAIXA_CAMA_VOLTAR].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
    context.caixa_cama.objects[ID_CAIXA_CAMA_VOLTAR].bounds = (Rectangle){5, 7, 71, 73};
    context.caixa_cama.objects[ID_CAIXA_CAMA_VOLTAR].state = ORIGINAL;
    context.caixa_cama.objects[ID_CAIXA_CAMA_VOLTAR].type = INTERACTIVE;

    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_1].name = "simbolo1";
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_1].id = ID_CAIXA_CAMA_SIMBOLO_1;
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_1].texture = LoadTexture("assets/zoomCaixaCama/7.png");
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_1].position = (Vector2){0, 0};
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_1].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_1].bounds = (Rectangle){186, 284, 132, 222};
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_1].state = ORIGINAL;
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_1].type = INTERACTIVE;

    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_2].name = "simbolo2";
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_2].id = ID_CAIXA_CAMA_SIMBOLO_2;
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_2].texture = LoadTexture("assets/zoomCaixaCama/7.png");
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_2].position = (Vector2){132, 0};
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_2].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_2].bounds = (Rectangle){318, 284, 132, 222};
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_2].state = ORIGINAL;
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_2].type = INTERACTIVE;

    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_3].name = "simbolo3";
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_3].id = ID_CAIXA_CAMA_SIMBOLO_3;
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_3].texture = LoadTexture("assets/zoomCaixaCama/7.png");
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_3].position = (Vector2){264, 0};
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_3].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_3].bounds = (Rectangle){450, 284, 132, 222};
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_3].state = ORIGINAL;
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_3].type = INTERACTIVE;

    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_4].name = "simbolo4";
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_4].id = ID_CAIXA_CAMA_SIMBOLO_4;
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_4].texture = LoadTexture("assets/zoomCaixaCama/7.png");
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_4].position = (Vector2){396, 0};
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_4].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_4].bounds = (Rectangle){582, 284, 132, 222};
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_4].state = ORIGINAL;
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_4].type = INTERACTIVE;

    context.caixa_cama.objects[ID_CAIXA_CAMA_BOTAO].name = "botao";
    context.caixa_cama.objects[ID_CAIXA_CAMA_BOTAO].id = ID_CAIXA_CAMA_BOTAO;
    context.caixa_cama.objects[ID_CAIXA_CAMA_BOTAO].texture = LoadTexture("assets/.png");
    context.caixa_cama.objects[ID_CAIXA_CAMA_BOTAO].position = (Vector2){0, 0};
    context.caixa_cama.objects[ID_CAIXA_CAMA_BOTAO].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
    context.caixa_cama.objects[ID_CAIXA_CAMA_BOTAO].bounds = (Rectangle){888, 321, 112, 111};
    context.caixa_cama.objects[ID_CAIXA_CAMA_BOTAO].state = ORIGINAL;
    context.caixa_cama.objects[ID_CAIXA_CAMA_BOTAO].type = INTERACTIVE;

    context.caixa_cama.background = LoadTexture("assets/zoomCaixaCama/ZoomCaixaCama.png");
    return context;
}

GameplaySubstate processZoomCaixaCamaEvent(GameObject* target, GameContext* context) {
    switch(target->id) {
        case ID_CAIXA_CAMA_VOLTAR:
            return GAMEPLAY_SUBSTATE_MAIN;
        default:
            return GAMEPLAY_SUBSTATE_ZOOM_CAIXA_CAMA;
    }
}

Texture2D GetZoomCaixaCamaBackground(GameContext context) {
    return context.caixa_cama.background;
}

GameObject* GetZoomCaixaCamaObjects(GameContext context) {
    return context.caixa_cama.objects;
}

int GetZoomCaixaCamaObjectCount(GameContext context) {
    return context.caixa_cama.objectCount;
}