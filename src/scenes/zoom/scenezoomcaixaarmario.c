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
    context.caixa_armario.objectCount = 14;
    context.caixa_armario.objects = (GameObject*)malloc(context.caixa_armario.objectCount * sizeof(GameObject));

    context.caixa_armario.objects[ID_CAIXA_ARMARIO_VOLTAR].name = "voltar";
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_VOLTAR].id = ID_CAIXA_ARMARIO_VOLTAR;
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_VOLTAR].texture = LoadTexture("assets/voltarSubstates.png");
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_VOLTAR].position = (Vector2){0, 0};
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_VOLTAR].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_VOLTAR].bounds = (Rectangle){5, 7, 71, 73};
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_VOLTAR].state = ORIGINAL;
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_VOLTAR].type = INTERACTIVE;

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
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_3].position = (Vector2){370, 0};
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_3].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_3].bounds = (Rectangle){576, 360, 178, 265};
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_3].state = ORIGINAL;
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_3].type = INTERACTIVE;

    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_4].name = "simbolo4";
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_4].id = ID_CAIXA_ARMARIO_SIMBOLO_4;
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_4].texture = LoadTexture("assets/zoomCaixaArmario/SimboloAncora.png");
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_SIMBOLO_4].position = (Vector2){560, 0};
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
    
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_ANCORA].texture = LoadTexture("assets/zoomCaixaArmario/SimboloAncora.png");
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_CIFRAO].texture = LoadTexture("assets/zoomCaixaArmario/SimboloCifrao.png");
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_ESPADA].texture = LoadTexture("assets/zoomCaixaArmario/SimboloEspada.png");
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_GANCHO].texture = LoadTexture("assets/zoomCaixaArmario/SimboloGancho.png");
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_LULA].texture = LoadTexture("assets/zoomCaixaArmario/SimboloLula.png");
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_ROSA].texture = LoadTexture("assets/zoomCaixaArmario/SimboloRosa.png");
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_TUBARAO].texture = LoadTexture("assets/zoomCaixaArmario/SimboloTubarao.png");
    context.caixa_armario.objects[ID_CAIXA_ARMARIO_X].texture = LoadTexture("assets/zoomCaixaArmario/SimboloX.png");
    
    
    context.caixa_armario.background = LoadTexture("assets/zoomCaixaArmario/ZoomCaixaArmario.png");
    return context;
}

GameplaySubstate processZoomCaixaArmarioEvent(GameObject* target, GameContext* context, int* counterSimbolos, int* temChave) {
    switch(target->id) {
        case ID_CAIXA_ARMARIO_VOLTAR:
            return GAMEPLAY_SUBSTATE_MAIN;
        
        case ID_CAIXA_ARMARIO_SIMBOLO_1:
            counterSimbolos[0]++;

            if(counterSimbolos[0]%8 == 0) target->texture = context->caixa_armario.objects[ID_CAIXA_ARMARIO_ANCORA].texture;
            else if(counterSimbolos[0]%8 == 1) target->texture = context->caixa_armario.objects[ID_CAIXA_ARMARIO_CIFRAO].texture;
            else if(counterSimbolos[0]%8 == 2) target->texture = context->caixa_armario.objects[ID_CAIXA_ARMARIO_ESPADA].texture;
            else if(counterSimbolos[0]%8 == 3) target->texture = context->caixa_armario.objects[ID_CAIXA_ARMARIO_GANCHO].texture;
            else if(counterSimbolos[0]%8 == 4) target->texture = context->caixa_armario.objects[ID_CAIXA_ARMARIO_LULA].texture;
            else if(counterSimbolos[0]%8 == 5) target->texture = context->caixa_armario.objects[ID_CAIXA_ARMARIO_ROSA].texture;
            else if(counterSimbolos[0]%8 == 6) target->texture = context->caixa_armario.objects[ID_CAIXA_ARMARIO_TUBARAO].texture;
            else if(counterSimbolos[0]%8 == 7) target->texture = context->caixa_armario.objects[ID_CAIXA_ARMARIO_X].texture;

            return GAMEPLAY_SUBSTATE_ZOOM_CAIXA_ARMARIO;

        case ID_CAIXA_ARMARIO_SIMBOLO_2:
            counterSimbolos[1]++;

            if(counterSimbolos[1]%8 == 0) target->texture = context->caixa_armario.objects[ID_CAIXA_ARMARIO_ANCORA].texture;
            else if(counterSimbolos[1]%8 == 1) target->texture = context->caixa_armario.objects[ID_CAIXA_ARMARIO_CIFRAO].texture;
            else if(counterSimbolos[1]%8 == 2) target->texture = context->caixa_armario.objects[ID_CAIXA_ARMARIO_ESPADA].texture;
            else if(counterSimbolos[1]%8 == 3) target->texture = context->caixa_armario.objects[ID_CAIXA_ARMARIO_GANCHO].texture;
            else if(counterSimbolos[1]%8 == 4) target->texture = context->caixa_armario.objects[ID_CAIXA_ARMARIO_LULA].texture;
            else if(counterSimbolos[1]%8 == 5) target->texture = context->caixa_armario.objects[ID_CAIXA_ARMARIO_ROSA].texture;
            else if(counterSimbolos[1]%8 == 6) target->texture = context->caixa_armario.objects[ID_CAIXA_ARMARIO_TUBARAO].texture;
            else if(counterSimbolos[1]%8 == 7) target->texture = context->caixa_armario.objects[ID_CAIXA_ARMARIO_X].texture;

            return GAMEPLAY_SUBSTATE_ZOOM_CAIXA_ARMARIO;

        case ID_CAIXA_ARMARIO_SIMBOLO_3:
            counterSimbolos[2]++;

            if(counterSimbolos[2]%8 == 0) target->texture = context->caixa_armario.objects[ID_CAIXA_ARMARIO_ANCORA].texture;
            else if(counterSimbolos[2]%8 == 1) target->texture = context->caixa_armario.objects[ID_CAIXA_ARMARIO_CIFRAO].texture;
            else if(counterSimbolos[2]%8 == 2) target->texture = context->caixa_armario.objects[ID_CAIXA_ARMARIO_ESPADA].texture;
            else if(counterSimbolos[2]%8 == 3) target->texture = context->caixa_armario.objects[ID_CAIXA_ARMARIO_GANCHO].texture;
            else if(counterSimbolos[2]%8 == 4) target->texture = context->caixa_armario.objects[ID_CAIXA_ARMARIO_LULA].texture;
            else if(counterSimbolos[2]%8 == 5) target->texture = context->caixa_armario.objects[ID_CAIXA_ARMARIO_ROSA].texture;
            else if(counterSimbolos[2]%8 == 6) target->texture = context->caixa_armario.objects[ID_CAIXA_ARMARIO_TUBARAO].texture;
            else if(counterSimbolos[2]%8 == 7) target->texture = context->caixa_armario.objects[ID_CAIXA_ARMARIO_X].texture;

            return GAMEPLAY_SUBSTATE_ZOOM_CAIXA_ARMARIO;

        case ID_CAIXA_ARMARIO_SIMBOLO_4:
            counterSimbolos[3]++;

            if(counterSimbolos[3]%8 == 0) target->texture = context->caixa_armario.objects[ID_CAIXA_ARMARIO_ANCORA].texture;
            else if(counterSimbolos[3]%8 == 1) target->texture = context->caixa_armario.objects[ID_CAIXA_ARMARIO_CIFRAO].texture;
            else if(counterSimbolos[3]%8 == 2) target->texture = context->caixa_armario.objects[ID_CAIXA_ARMARIO_ESPADA].texture;
            else if(counterSimbolos[3]%8 == 3) target->texture = context->caixa_armario.objects[ID_CAIXA_ARMARIO_GANCHO].texture;
            else if(counterSimbolos[3]%8 == 4) target->texture = context->caixa_armario.objects[ID_CAIXA_ARMARIO_LULA].texture;
            else if(counterSimbolos[3]%8 == 5) target->texture = context->caixa_armario.objects[ID_CAIXA_ARMARIO_ROSA].texture;
            else if(counterSimbolos[3]%8 == 6) target->texture = context->caixa_armario.objects[ID_CAIXA_ARMARIO_TUBARAO].texture;
            else if(counterSimbolos[3]%8 == 7) target->texture = context->caixa_armario.objects[ID_CAIXA_ARMARIO_X].texture;

            return GAMEPLAY_SUBSTATE_ZOOM_CAIXA_ARMARIO;
        
        case ID_CAIXA_ARMARIO_BOTAO:
            if(counterSimbolos[0]%8 == 7 && counterSimbolos[1]%8 == 4 && counterSimbolos[2]%8 == 6 && counterSimbolos[3]%8 == 0) {
                *temChave = 1;
                printf("receba\n");
                printf("dialogo chave\n");
                context->flags[CHAVE] = 1;
                return GAMEPLAY_SUBSTATE_MAIN;
            }

            return GAMEPLAY_SUBSTATE_ZOOM_CAIXA_ARMARIO;
        
        default:
            return GAMEPLAY_SUBSTATE_ZOOM_CAIXA_ARMARIO;
    }
}

Texture2D GetZoomCaixaArmarioBackground(GameContext context) {
    return context.caixa_armario.background;
}

GameObject* GetZoomCaixaArmarioObjects(GameContext context) {
    return context.caixa_armario.objects;
}

int GetZoomCaixaArmarioObjectCount(GameContext context) {
    return context.caixa_armario.objectCount;
}