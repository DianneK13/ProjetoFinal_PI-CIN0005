#include "scenes/zoom/scenezoomcaixacama.h"

/*
//array de objects desta cena
GameObject* objects_sceneCaixaCama;
//qtd de objetos desta cena
int objectCount_sceneCaixaCama;

//imagem de fundo desta cena
Texture2D background_sceneCaixaCama;
*/

#include "raylib.h"
static Sound sfx_caixacama;
static int sfx_caixacama_loaded = 0;

GameContext InitializeZoomCaixaCamaState(GameContext context) {
    if (!sfx_caixacama_loaded) {
        sfx_caixacama = LoadSound("assets/audio/sfx/botão.mp3");
        sfx_caixacama_loaded = 1;
    }
    if (sfx_caixacama_loaded) PlaySound(sfx_caixacama);
    context.caixa_cama.objectCount = 17;
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
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_1].texture = LoadTexture("assets/zoomCaixaCama/1.png");
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_1].position = (Vector2){0, 0};
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_1].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_1].bounds = (Rectangle){186, 284, 132, 222};
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_1].state = ORIGINAL;
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_1].type = INTERACTIVE;

    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_2].name = "simbolo2";
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_2].id = ID_CAIXA_CAMA_SIMBOLO_2;
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_2].texture = LoadTexture("assets/zoomCaixaCama/1.png");
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_2].position = (Vector2){132, 0};
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_2].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_2].bounds = (Rectangle){318, 284, 132, 222};
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_2].state = ORIGINAL;
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_2].type = INTERACTIVE;

    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_3].name = "simbolo3";
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_3].id = ID_CAIXA_CAMA_SIMBOLO_3;
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_3].texture = LoadTexture("assets/zoomCaixaCama/1.png");
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_3].position = (Vector2){264, 0};
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_3].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_3].bounds = (Rectangle){450, 284, 132, 222};
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_3].state = ORIGINAL;
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_3].type = INTERACTIVE;

    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_4].name = "simbolo4";
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_4].id = ID_CAIXA_CAMA_SIMBOLO_4;
    context.caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_4].texture = LoadTexture("assets/zoomCaixaCama/1.png");
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

    context.caixa_cama.objects[ID_CAIXA_CAMA_ESPACO_FALA].name = "continuar";
    context.caixa_cama.objects[ID_CAIXA_CAMA_ESPACO_FALA].id = ID_CAIXA_CAMA_ESPACO_FALA;
    context.caixa_cama.objects[ID_CAIXA_CAMA_ESPACO_FALA].texture = LoadTexture("assets/.png");
    context.caixa_cama.objects[ID_CAIXA_CAMA_ESPACO_FALA].position = (Vector2){0, 0};
    context.caixa_cama.objects[ID_CAIXA_CAMA_ESPACO_FALA].size = (Vector2){0, 0};
    context.caixa_cama.objects[ID_CAIXA_CAMA_ESPACO_FALA].bounds = (Rectangle){0, 0, 0, 0};
    context.caixa_cama.objects[ID_CAIXA_CAMA_ESPACO_FALA].state = ORIGINAL;
    context.caixa_cama.objects[ID_CAIXA_CAMA_ESPACO_FALA].type = INTERACTIVE;

    context.caixa_cama.objects[ID_CAIXA_CAMA_1].texture = LoadTexture("assets/zoomCaixaCama/1.png");
    context.caixa_cama.objects[ID_CAIXA_CAMA_2].texture = LoadTexture("assets/zoomCaixaCama/2.png");
    context.caixa_cama.objects[ID_CAIXA_CAMA_3].texture = LoadTexture("assets/zoomCaixaCama/3.png");
    context.caixa_cama.objects[ID_CAIXA_CAMA_4].texture = LoadTexture("assets/zoomCaixaCama/4.png");
    context.caixa_cama.objects[ID_CAIXA_CAMA_5].texture = LoadTexture("assets/zoomCaixaCama/5.png");
    context.caixa_cama.objects[ID_CAIXA_CAMA_6].texture = LoadTexture("assets/zoomCaixaCama/6.png");
    context.caixa_cama.objects[ID_CAIXA_CAMA_7].texture = LoadTexture("assets/zoomCaixaCama/7.png");
    context.caixa_cama.objects[ID_CAIXA_CAMA_8].texture = LoadTexture("assets/zoomCaixaCama/8.png");
    context.caixa_cama.objects[ID_CAIXA_CAMA_9].texture = LoadTexture("assets/zoomCaixaCama/9.png");
    context.caixa_cama.objects[ID_CAIXA_BILHETE].texture = LoadTexture("assets/zoomCaixaCama/ZoomBilhete.png");

    context.caixa_cama.background = LoadTexture("assets/zoomCaixaCama/ZoomCaixaCama.png");
    return context;
}

GameplaySubstate processZoomCaixaCamaEvent(GameObject* target, GameContext* context, int* counterNumeros, int* leuBilhete) {
    switch(target->id) {
        case ID_CAIXA_CAMA_VOLTAR:
            return GAMEPLAY_SUBSTATE_MAIN;

        case ID_CAIXA_CAMA_ESPACO_FALA:
            target->size = (Vector2){0, 0};
            target->bounds = (Rectangle){0, 0, 0, 0};
            return GAMEPLAY_SUBSTATE_ZOOM_CAIXA_CAMA;

        case ID_CAIXA_CAMA_SIMBOLO_1:
            counterNumeros[0]++;

            if(counterNumeros[0]%9 == 0) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_1].texture;
            else if(counterNumeros[0]%9 == 1) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_2].texture;
            else if(counterNumeros[0]%9 == 2) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_3].texture;
            else if(counterNumeros[0]%9 == 3) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_4].texture;
            else if(counterNumeros[0]%9 == 4) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_5].texture;
            else if(counterNumeros[0]%9 == 5) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_6].texture;
            else if(counterNumeros[0]%9 == 6) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_7].texture;
            else if(counterNumeros[0]%9 == 7) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_8].texture;
            else if(counterNumeros[0]%9 == 8) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_9].texture;

            return GAMEPLAY_SUBSTATE_ZOOM_CAIXA_CAMA;

        case ID_CAIXA_CAMA_SIMBOLO_2:
            counterNumeros[1]++;

            if(counterNumeros[1]%9 == 0) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_1].texture;
            else if(counterNumeros[1]%9 == 1) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_2].texture;
            else if(counterNumeros[1]%9 == 2) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_3].texture;
            else if(counterNumeros[1]%9 == 3) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_4].texture;
            else if(counterNumeros[1]%9 == 4) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_5].texture;
            else if(counterNumeros[1]%9 == 5) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_6].texture;
            else if(counterNumeros[1]%9 == 6) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_7].texture;
            else if(counterNumeros[1]%9 == 7) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_8].texture;
            else if(counterNumeros[1]%9 == 8) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_9].texture;

            return GAMEPLAY_SUBSTATE_ZOOM_CAIXA_CAMA;

        case ID_CAIXA_CAMA_SIMBOLO_3:
            counterNumeros[2]++;

            if(counterNumeros[2]%9 == 0) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_1].texture;
            else if(counterNumeros[2]%9 == 1) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_2].texture;
            else if(counterNumeros[2]%9 == 2) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_3].texture;
            else if(counterNumeros[2]%9 == 3) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_4].texture;
            else if(counterNumeros[2]%9 == 4) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_5].texture;
            else if(counterNumeros[2]%9 == 5) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_6].texture;
            else if(counterNumeros[2]%9 == 6) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_7].texture;
            else if(counterNumeros[2]%9 == 7) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_8].texture;
            else if(counterNumeros[2]%9 == 8) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_9].texture;

            return GAMEPLAY_SUBSTATE_ZOOM_CAIXA_CAMA;

        case ID_CAIXA_CAMA_SIMBOLO_4:
            counterNumeros[3]++;

            if(counterNumeros[3]%9 == 0) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_1].texture;
            else if(counterNumeros[3]%9 == 1) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_2].texture;
            else if(counterNumeros[3]%9 == 2) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_3].texture;
            else if(counterNumeros[3]%9 == 3) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_4].texture;
            else if(counterNumeros[3]%9 == 4) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_5].texture;
            else if(counterNumeros[3]%9 == 5) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_6].texture;
            else if(counterNumeros[3]%9 == 6) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_7].texture;
            else if(counterNumeros[3]%9 == 7) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_8].texture;
            else if(counterNumeros[3]%9 == 8) target->texture = context->caixa_cama.objects[ID_CAIXA_CAMA_9].texture;

            return GAMEPLAY_SUBSTATE_ZOOM_CAIXA_CAMA;
        
        case ID_CAIXA_CAMA_BOTAO:
            if(counterNumeros[0]%9 == 4 && counterNumeros[1]%9 == 2 && counterNumeros[2]%9 == 7 && counterNumeros[3]%9 == 6) {
                printf("receba\n");
                *leuBilhete = 1;

                context->caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_1].size = (Vector2){0, 0};
                context->caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_1].bounds = (Rectangle){0, 0, 0, 0};
                context->caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_2].size = (Vector2){0, 0};
                context->caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_2].bounds = (Rectangle){0, 0, 0, 0};
                context->caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_3].size = (Vector2){0, 0};
                context->caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_3].bounds = (Rectangle){0, 0, 0, 0};
                context->caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_4].size = (Vector2){0, 0};
                context->caixa_cama.objects[ID_CAIXA_CAMA_SIMBOLO_4].bounds = (Rectangle){0, 0, 0, 0};
                context->caixa_cama.objects[ID_CAIXA_CAMA_BOTAO].size = (Vector2){0, 0};
                context->caixa_cama.objects[ID_CAIXA_CAMA_BOTAO].bounds = (Rectangle){0, 0, 0, 0};

                context->estante.objects[1].bounds = (Rectangle){153, 332, 37, 53}; // S
                context->estante.objects[2].bounds = (Rectangle){329, 217, 38, 46}; // A
                context->estante.objects[3].bounds = (Rectangle){460, 516, 38, 46}; // N
                context->estante.objects[4].bounds = (Rectangle){603, 197, 26, 34}; // D
                context->estante.objects[5].bounds = (Rectangle){683, 223, 28, 40}; // R
                context->estante.objects[6].bounds = (Rectangle){891, 427, 38, 45}; // A

                context->estante.objects[7].texture = context->gameplay.objects[26].texture;
                context->estante.objects[7].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
                context->estante.objects[7].bounds = (Rectangle){211, 576, 778, 209};

                context->caixa_cama.objects[ID_CAIXA_CAMA_ESPACO_FALA].texture = context->caixa_cama.objects[22].texture;


                return GAMEPLAY_SUBSTATE_ZOOM_CAIXA_CAMA;
            }
            else return GAMEPLAY_SUBSTATE_ZOOM_CAIXA_CAMA;
        
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