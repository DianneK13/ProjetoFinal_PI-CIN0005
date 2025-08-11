#include "scenes/zoom/scenezoomcaixaarmario.h"

/*
//array de objects desta cena
GameObject* objects_sceneCaixaArmario;
//qtd de objetos desta cena
int objectCount_sceneCaixaArmario;

//imagem de fundo desta cena
Texture2D background_sceneCaixaArmario;
*/

GameContext InitializeZoomCaixaArmarioState(GameContext context) {
    context.caixa_armario.objectCount = 5;
    context.caixa_armario.objects = (GameObject*)malloc(context.caixa_armario.objectCount * sizeof(GameObject));

    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_1].name = "simbolo1";
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_1].id = ID_CAIXA_ARMARIO_SIMBOLO_1;
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_1].texture = LoadTexture("assets/zoomCaixaArmario/SimboloAncora.png");
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_1].position = (Vector2){0, 0};
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_1].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_1].bounds = (Rectangle){220, 360, 178, 265};
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_1].state = ORIGINAL;
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_1].type = INTERACTIVE;

    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_2].name = "simbolo2";
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_2].id = ID_CAIXA_ARMARIO_SIMBOLO_2;
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_2].texture = LoadTexture("assets/zoomCaixaArmario/SimboloAncora.png");
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_2].position = (Vector2){178, 0};
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_2].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_2].bounds = (Rectangle){398, 360, 178, 265};
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_2].state = ORIGINAL;
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_2].type = INTERACTIVE;

    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_3].name = "simbolo3";
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_3].id = ID_CAIXA_ARMARIO_SIMBOLO_3;
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_3].texture = LoadTexture("assets/zoomCaixaArmario/SimboloAncora.png");
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_3].position = (Vector2){356, 0};
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_3].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_3].bounds = (Rectangle){576, 360, 178, 265};
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_3].state = ORIGINAL;
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_3].type = INTERACTIVE;

    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_4].name = "simbolo4";
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_4].id = ID_CAIXA_ARMARIO_SIMBOLO_4;
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_4].texture = LoadTexture("assets/zoomCaixaArmario/SimboloAncora.png");
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_4].position = (Vector2){534, 0};
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_4].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_4].bounds = (Rectangle){754, 360, 178, 265};
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_4].state = ORIGINAL;
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_4].type = INTERACTIVE;

    context.caixa_armario.objects[ID_CAIXA_ARMARIO_BOTAO].name = "botao";
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_BOTAO].id = ID_CAIXA_ARMARIO_BOTAO;
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_BOTAO].texture = LoadTexture("assets/.png");
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_BOTAO].position = (Vector2){0, 0};
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_BOTAO].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_BOTAO].bounds = (Rectangle){520, 114, 110, 100};
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_BOTAO].state = ORIGINAL;
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_BOTAO].type = INTERACTIVE;

    context.caixa_armario.background = LoadTexture("assets/zoomCaixaArmario/ZoomCaixaArmario.png");
    return context;
}

GameplaySubstate processZoomCaixaArmarioEvent(GameObject* object) {
    
}

Texture2D GetZoomCaixaArmarioBackground(GameContext context) {
    printf("pegou fundo caixa armario\n");
    return context.caixa_armario.background;
}

GameObject* GetZoomCaixaArmarioObjects(GameContext context) {
    printf("pegou objetos caixa armario\n");
    return context.caixa_armario.objects;
}

int GetZoomCaixaArmarioObjectCount(GameContext context) {
    printf("pegou obj count caixa armario\n");
    return context.caixa_armario.objectCount;
}