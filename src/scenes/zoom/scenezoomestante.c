#include "scenes/zoom/scenezoomestante.h"

GameContext InitializeZoomEstanteState(GameContext context) {
    context.estante.objectCount = 8;
    context.estante.objects = (GameObject*)malloc(context.estante.objectCount * sizeof(GameObject));

    context.estante.objects[ID_ESTANTE_VOLTAR].name = "voltar";
    context.estante.objects[ID_ESTANTE_VOLTAR].id = ID_ESTANTE_VOLTAR;
    context.estante.objects[ID_ESTANTE_VOLTAR].texture = LoadTexture("assets/voltarSubstates.png");
    context.estante.objects[ID_ESTANTE_VOLTAR].position = (Vector2){0, 0};
    context.estante.objects[ID_ESTANTE_VOLTAR].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
    context.estante.objects[ID_ESTANTE_VOLTAR].bounds = (Rectangle){5, 7, 71, 73};
    context.estante.objects[ID_ESTANTE_VOLTAR].state = ORIGINAL;
    context.estante.objects[ID_ESTANTE_VOLTAR].type = INTERACTIVE;

    context.estante.objects[ID_ESTANTE_LETRA_1].name = "???";
    context.estante.objects[ID_ESTANTE_LETRA_1].id = ID_ESTANTE_LETRA_1;
    context.estante.objects[ID_ESTANTE_LETRA_1].texture = LoadTexture("assets/zoomEstante/bolaToguro_S.png");
    context.estante.objects[ID_ESTANTE_LETRA_1].position = (Vector2){0, 0};
    context.estante.objects[ID_ESTANTE_LETRA_1].size = (Vector2){0,0};
    context.estante.objects[ID_ESTANTE_LETRA_1].bounds = (Rectangle){0, 0, 0, 0};
    context.estante.objects[ID_ESTANTE_LETRA_1].state = ORIGINAL;
    context.estante.objects[ID_ESTANTE_LETRA_1].type = INTERACTIVE;

    context.estante.objects[ID_ESTANTE_LETRA_2].name = "???";
    context.estante.objects[ID_ESTANTE_LETRA_2].id = ID_ESTANTE_LETRA_2;
    context.estante.objects[ID_ESTANTE_LETRA_2].texture = LoadTexture("assets/zoomEstante/bolaToguro_A1.png");
    context.estante.objects[ID_ESTANTE_LETRA_2].position = (Vector2){0, 0};
    context.estante.objects[ID_ESTANTE_LETRA_2].size = (Vector2){0,0};
    context.estante.objects[ID_ESTANTE_LETRA_2].bounds = (Rectangle){0, 0, 0, 0};
    context.estante.objects[ID_ESTANTE_LETRA_2].state = ORIGINAL;
    context.estante.objects[ID_ESTANTE_LETRA_2].type = INTERACTIVE;

    context.estante.objects[ID_ESTANTE_LETRA_3].name = "???";
    context.estante.objects[ID_ESTANTE_LETRA_3].id = ID_ESTANTE_LETRA_3;
    context.estante.objects[ID_ESTANTE_LETRA_3].texture = LoadTexture("assets/zoomEstante/bolaToguro_N.png");
    context.estante.objects[ID_ESTANTE_LETRA_3].position = (Vector2){0, 0};
    context.estante.objects[ID_ESTANTE_LETRA_3].size = (Vector2){0,0};
    context.estante.objects[ID_ESTANTE_LETRA_3].bounds = (Rectangle){0, 0, 0, 0};
    context.estante.objects[ID_ESTANTE_LETRA_3].state = ORIGINAL;
    context.estante.objects[ID_ESTANTE_LETRA_3].type = INTERACTIVE;

    context.estante.objects[ID_ESTANTE_LETRA_4].name = "???";
    context.estante.objects[ID_ESTANTE_LETRA_4].id = ID_ESTANTE_LETRA_4;
    context.estante.objects[ID_ESTANTE_LETRA_4].texture = LoadTexture("assets/zoomEstante/bolaToguro_D.png");
    context.estante.objects[ID_ESTANTE_LETRA_4].position = (Vector2){0, 0};
    context.estante.objects[ID_ESTANTE_LETRA_4].size = (Vector2){0,0};
    context.estante.objects[ID_ESTANTE_LETRA_4].bounds = (Rectangle){0, 0, 0, 0};
    context.estante.objects[ID_ESTANTE_LETRA_4].state = ORIGINAL;
    context.estante.objects[ID_ESTANTE_LETRA_4].type = INTERACTIVE;

    context.estante.objects[ID_ESTANTE_LETRA_5].name = "???";
    context.estante.objects[ID_ESTANTE_LETRA_5].id = ID_ESTANTE_LETRA_5;
    context.estante.objects[ID_ESTANTE_LETRA_5].texture = LoadTexture("assets/zoomEstante/bolaToguro_R.png");
    context.estante.objects[ID_ESTANTE_LETRA_5].position = (Vector2){0, 0};
    context.estante.objects[ID_ESTANTE_LETRA_5].size = (Vector2){0,0};
    context.estante.objects[ID_ESTANTE_LETRA_5].bounds = (Rectangle){0, 0, 0, 0};
    context.estante.objects[ID_ESTANTE_LETRA_5].state = ORIGINAL;
    context.estante.objects[ID_ESTANTE_LETRA_5].type = INTERACTIVE;

    context.estante.objects[ID_ESTANTE_LETRA_6].name = "???";
    context.estante.objects[ID_ESTANTE_LETRA_6].id = ID_ESTANTE_LETRA_6;
    context.estante.objects[ID_ESTANTE_LETRA_6].texture = LoadTexture("assets/zoomEstante/bolaToguro_A2.png");
    context.estante.objects[ID_ESTANTE_LETRA_6].position = (Vector2){0, 0};
    context.estante.objects[ID_ESTANTE_LETRA_6].size = (Vector2){0,0};
    context.estante.objects[ID_ESTANTE_LETRA_6].bounds = (Rectangle){0, 0, 0, 0};
    context.estante.objects[ID_ESTANTE_LETRA_6].state = ORIGINAL;
    context.estante.objects[ID_ESTANTE_LETRA_6].type = INTERACTIVE;

    context.estante.objects[ID_ESTANTE_ESPACO_FALA].name = "continuar";
    context.estante.objects[ID_ESTANTE_ESPACO_FALA].id = ID_ESTANTE_ESPACO_FALA;
    context.estante.objects[ID_ESTANTE_ESPACO_FALA].texture = LoadTexture("assets/.png");
    context.estante.objects[ID_ESTANTE_ESPACO_FALA].position = (Vector2){0, 0};
    context.estante.objects[ID_ESTANTE_ESPACO_FALA].size = (Vector2){0,0};
    context.estante.objects[ID_ESTANTE_ESPACO_FALA].bounds = (Rectangle){0, 0, 0, 0};
    context.estante.objects[ID_ESTANTE_ESPACO_FALA].state = ORIGINAL;
    context.estante.objects[ID_ESTANTE_ESPACO_FALA].type = INTERACTIVE;

    context.estante.background = LoadTexture("assets/zoomEstante/ZoomEstante.png");
    return context;
}

GameplaySubstate processZoomEstanteEvent(GameObject* target, GameContext* context, int* leuBilhete, int* flagFinal) {
    switch(target->id) {
        case ID_ESTANTE_VOLTAR:
            if(context->estante.objects[ID_ESTANTE_LETRA_1].state == ALTERED && 
                context->estante.objects[ID_ESTANTE_LETRA_2].state == ALTERED &&
                context->estante.objects[ID_ESTANTE_LETRA_3].state == ALTERED &&
                context->estante.objects[ID_ESTANTE_LETRA_4].state == ALTERED &&
                context->estante.objects[ID_ESTANTE_LETRA_5].state == ALTERED &&
                context->estante.objects[ID_ESTANTE_LETRA_6].state == ALTERED) {
                    
                    context->gameplay.objects[10].texture = context->gameplay.objects[27].texture;
                    context->gameplay.objects[10].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
                    context->gameplay.objects[10].bounds = (Rectangle){211, 576, 778, 209};

                    *flagFinal = 1;
                    
            }

            return GAMEPLAY_SUBSTATE_MAIN;
        case ID_ESTANTE_LETRA_1:
            context->estante.objects[ID_ESTANTE_LETRA_1].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
            context->estante.objects[ID_ESTANTE_LETRA_1].state = ALTERED;
            return GAMEPLAY_SUBSTATE_ZOOM_ESTANTE;
        case ID_ESTANTE_LETRA_2:
            context->estante.objects[ID_ESTANTE_LETRA_2].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
            context->estante.objects[ID_ESTANTE_LETRA_2].state = ALTERED;
            return GAMEPLAY_SUBSTATE_ZOOM_ESTANTE;
        case ID_ESTANTE_LETRA_3:
            context->estante.objects[ID_ESTANTE_LETRA_3].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
            context->estante.objects[ID_ESTANTE_LETRA_3].state = ALTERED;
            return GAMEPLAY_SUBSTATE_ZOOM_ESTANTE;
        case ID_ESTANTE_LETRA_4:
            context->estante.objects[ID_ESTANTE_LETRA_4].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
            context->estante.objects[ID_ESTANTE_LETRA_4].state = ALTERED;
            return GAMEPLAY_SUBSTATE_ZOOM_ESTANTE;
        case ID_ESTANTE_LETRA_5:
            context->estante.objects[ID_ESTANTE_LETRA_5].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
            context->estante.objects[ID_ESTANTE_LETRA_5].state = ALTERED;
            return GAMEPLAY_SUBSTATE_ZOOM_ESTANTE;
        case ID_ESTANTE_LETRA_6:
            context->estante.objects[ID_ESTANTE_LETRA_6].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
            context->estante.objects[ID_ESTANTE_LETRA_6].state = ALTERED;
            return GAMEPLAY_SUBSTATE_ZOOM_ESTANTE;

        case ID_ESTANTE_ESPACO_FALA:
            target->size = (Vector2){0, 0};
            target->bounds = (Rectangle){0, 0, 0, 0};
            return GAMEPLAY_SUBSTATE_ZOOM_ESTANTE;   

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