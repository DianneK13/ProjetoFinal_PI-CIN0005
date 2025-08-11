#include "scenes/scenegameplay.h"
#include "scenes/zoom/scenezoombilhete.h"
#include "scenes/zoom/scenezoomcaixaarmario.h"
#include "scenes/zoom/scenezoomcaixacama.h"
#include "scenes/zoom/scenezoomdiario.h"
#include "scenes/zoom/scenezoomestante.h"
#include "scenes/zoom/scenezoomgarrafa.h"
#include "scenes/zoom/scenezoompirata.h"
GameObject* hand;

GameplaySubstate processArmarioEvent(GameObject* utility, GameObject* target, GameContext* context){
    //return 0; //PLACEHOLDER
}

GameplaySubstate processCaixaArmarioEvent(GameObject* utility, GameObject* target, GameContext* context){
    return GAMEPLAY_SUBSTATE_ZOOM_CAIXA_ARMARIO;
}

GameplaySubstate processCaixaCamaEvent(GameObject* utility, GameObject* target, GameContext* context){
    return GAMEPLAY_SUBSTATE_ZOOM_CAIXA_CAMA;
}

GameplaySubstate processBuracoEvent(GameObject* utility, GameObject* target, GameContext* context){
    //return 0; //PLACEHOLDER
}

GameplaySubstate processDiarioEvent(GameObject* utility, GameObject* target, GameContext* context){
    return GAMEPLAY_SUBSTATE_ZOOM_DIARIO;
}   

GameplaySubstate processVitrolaEvent(GameObject* utility, GameObject* target, GameContext* context){
    //return 0; //PLACEHOLDER
}

GameplaySubstate processGarrafaEvent(GameObject* utility, GameObject* target, GameContext* context){
    return GAMEPLAY_SUBSTATE_ZOOM_GARRAFA;
}

GameplaySubstate processEstanteEvent(GameObject* utility, GameObject* target, GameContext* context){
    return GAMEPLAY_SUBSTATE_ZOOM_ESTANTE;
}

GameplaySubstate processPirataEvent(GameObject* utility, GameObject* target, GameContext* context){
    return GAMEPLAY_SUBSTATE_ZOOM_PIRATA;
}

GameplaySubstate processPescaEvent(GameObject* utility, GameObject* target, GameContext* context){
    //return 0; //PLACEHOLDER
}

GameplaySubstate processChaveEvent(GameObject* utility, GameObject* target, GameContext* context){
    //puzzle
    //return 0; //PLACEHOLDER
}

GameplaySubstate processBilheteEvent(GameObject* utility, GameObject* target, GameContext* context){
    //puzzle
    //return GAMEPLAY_SUBSTATE_ZOOM_BILHETE;
}

GameObject* GetHand(void){
    return hand;
}

GameContext InitializeGameplayState(GameContext context) {

    // numero de objetos
    // SEMPRE ATUALIZAR ESSE NUMERO CASO ADICIONE NOVO OBJETO
    context.gameplay.objectCount = 12;
    context.gameplay.objects = (GameObject*)malloc(context.gameplay.objectCount * sizeof(GameObject));
    
    /*
    if (context.gameplay.objects == NULL) {
        //printf("Failed to allocate memory for objects\n");
        return;
    }
    */
    
    // Initialize objects with their properties
    context.gameplay.objects[ID_GAMEPLAY_ARMARIO].name = "armario";
    context.gameplay.objects[ID_GAMEPLAY_ARMARIO].id = ID_GAMEPLAY_ARMARIO;
    context.gameplay.objects[ID_GAMEPLAY_ARMARIO].texture = LoadTexture("assets/objetosMainGameplay/Armario.png");
    context.gameplay.objects[ID_GAMEPLAY_ARMARIO].position = (Vector2){0, 0};
    context.gameplay.objects[ID_GAMEPLAY_ARMARIO].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
    context.gameplay.objects[ID_GAMEPLAY_ARMARIO].bounds = (Rectangle){0, 180, 242, 455};
    context.gameplay.objects[ID_GAMEPLAY_ARMARIO].state = ORIGINAL;
    context.gameplay.objects[ID_GAMEPLAY_ARMARIO].type = INTERACTIVE;

    context.gameplay.objects[ID_GAMEPLAY_CAIXA_ARMARIO].name = "caixaArmario";
    context.gameplay.objects[ID_GAMEPLAY_CAIXA_ARMARIO].id = ID_GAMEPLAY_CAIXA_ARMARIO;    
    context.gameplay.objects[ID_GAMEPLAY_CAIXA_ARMARIO].texture = LoadTexture("assets/objetosMainGameplay/CaixaArmario.png");
    context.gameplay.objects[ID_GAMEPLAY_CAIXA_ARMARIO].position = (Vector2){0, 0};
    context.gameplay.objects[ID_GAMEPLAY_CAIXA_ARMARIO].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
    context.gameplay.objects[ID_GAMEPLAY_CAIXA_ARMARIO].bounds = (Rectangle){66, 100, 140, 73};
    context.gameplay.objects[ID_GAMEPLAY_CAIXA_ARMARIO].state = ORIGINAL;
    context.gameplay.objects[ID_GAMEPLAY_CAIXA_ARMARIO].type = INTERACTIVE;

    context.gameplay.objects[ID_GAMEPLAY_CAIXA_CAMA].name = "caixaCama";
    context.gameplay.objects[ID_GAMEPLAY_CAIXA_CAMA].id = ID_GAMEPLAY_CAIXA_CAMA;
    context.gameplay.objects[ID_GAMEPLAY_CAIXA_CAMA].texture = LoadTexture("assets/objetosMainGameplay/CaixaCama.png");
    context.gameplay.objects[ID_GAMEPLAY_CAIXA_CAMA].position = (Vector2){0, 0};
    context.gameplay.objects[ID_GAMEPLAY_CAIXA_CAMA].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
    context.gameplay.objects[ID_GAMEPLAY_CAIXA_CAMA].bounds = (Rectangle){957, 710, 118, 75};
    context.gameplay.objects[ID_GAMEPLAY_CAIXA_CAMA].state = ORIGINAL;
    context.gameplay.objects[ID_GAMEPLAY_CAIXA_CAMA].type = INTERACTIVE;    

    context.gameplay.objects[ID_GAMEPLAY_BURACO].name = "buraco";
    context.gameplay.objects[ID_GAMEPLAY_BURACO].id = ID_GAMEPLAY_BURACO;
    context.gameplay.objects[ID_GAMEPLAY_BURACO].texture = LoadTexture("assets/.png"); //tá sem textura ainda
    context.gameplay.objects[ID_GAMEPLAY_BURACO].position = (Vector2){0, 0};
    context.gameplay.objects[ID_GAMEPLAY_BURACO].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
    context.gameplay.objects[ID_GAMEPLAY_BURACO].bounds = (Rectangle){321, 739, 22, 22};
    context.gameplay.objects[ID_GAMEPLAY_BURACO].state = ORIGINAL;
    context.gameplay.objects[ID_GAMEPLAY_BURACO].type = INTERACTIVE;

    context.gameplay.objects[ID_GAMEPLAY_DIARIO].name = "diario";
    context.gameplay.objects[ID_GAMEPLAY_DIARIO].id = ID_GAMEPLAY_DIARIO;
    context.gameplay.objects[ID_GAMEPLAY_DIARIO].texture = LoadTexture("assets/objetosMainGameplay/Diario.png");
    context.gameplay.objects[ID_GAMEPLAY_DIARIO].position = (Vector2){0, 0};
    context.gameplay.objects[ID_GAMEPLAY_DIARIO].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
    context.gameplay.objects[ID_GAMEPLAY_DIARIO].bounds = (Rectangle){563, 417, 58, 54};
    context.gameplay.objects[ID_GAMEPLAY_DIARIO].state = ORIGINAL;
    context.gameplay.objects[ID_GAMEPLAY_DIARIO].type = INTERACTIVE;

    context.gameplay.objects[ID_GAMEPLAY_VITROLA].name = "vitrola";
    context.gameplay.objects[ID_GAMEPLAY_VITROLA].id = ID_GAMEPLAY_VITROLA;
    context.gameplay.objects[ID_GAMEPLAY_VITROLA].texture = LoadTexture("assets/objetosMainGameplay/Vitrola_.png");
    context.gameplay.objects[ID_GAMEPLAY_VITROLA].position = (Vector2){0, 0};
    context.gameplay.objects[ID_GAMEPLAY_VITROLA].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
    context.gameplay.objects[ID_GAMEPLAY_VITROLA].bounds = (Rectangle){390, 313, 105, 153};
    context.gameplay.objects[ID_GAMEPLAY_VITROLA].state = ORIGINAL;
    context.gameplay.objects[ID_GAMEPLAY_VITROLA].type = INTERACTIVE;

    context.gameplay.objects[ID_GAMEPLAY_GARRAFA].name = "garrafa";
    context.gameplay.objects[ID_GAMEPLAY_GARRAFA].id = ID_GAMEPLAY_GARRAFA;
    context.gameplay.objects[ID_GAMEPLAY_GARRAFA].texture = LoadTexture("assets/objetosMainGameplay/Garrafa.png");
    context.gameplay.objects[ID_GAMEPLAY_GARRAFA].position = (Vector2){0, 0};
    context.gameplay.objects[ID_GAMEPLAY_GARRAFA].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
    context.gameplay.objects[ID_GAMEPLAY_GARRAFA].bounds = (Rectangle){725, 393, 45, 79};
    context.gameplay.objects[ID_GAMEPLAY_GARRAFA].state = ORIGINAL;
    context.gameplay.objects[ID_GAMEPLAY_GARRAFA].type = INTERACTIVE;

    context.gameplay.objects[ID_GAMEPLAY_ESTANTE].name = "estante";
    context.gameplay.objects[ID_GAMEPLAY_ESTANTE].id = ID_GAMEPLAY_ESTANTE;
    context.gameplay.objects[ID_GAMEPLAY_ESTANTE].texture = LoadTexture("assets/objetosMainGameplay/Estante.png");
    context.gameplay.objects[ID_GAMEPLAY_ESTANTE].position = (Vector2){0, 0};
    context.gameplay.objects[ID_GAMEPLAY_ESTANTE].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
    context.gameplay.objects[ID_GAMEPLAY_ESTANTE].bounds = (Rectangle){905, 191, 157, 101};
    context.gameplay.objects[ID_GAMEPLAY_ESTANTE].state = ORIGINAL;
    context.gameplay.objects[ID_GAMEPLAY_ESTANTE].type = INTERACTIVE;    

    context.gameplay.objects[ID_GAMEPLAY_PIRATA].name = "pirata";
    context.gameplay.objects[ID_GAMEPLAY_PIRATA].id = ID_GAMEPLAY_PIRATA;
    context.gameplay.objects[ID_GAMEPLAY_PIRATA].texture = LoadTexture("assets/objetosMainGameplay/Pirata.png");
    context.gameplay.objects[ID_GAMEPLAY_PIRATA].position = (Vector2){0, 0};
    context.gameplay.objects[ID_GAMEPLAY_PIRATA].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
    context.gameplay.objects[ID_GAMEPLAY_PIRATA].bounds = (Rectangle){873, 377, 156, 183};     
    context.gameplay.objects[ID_GAMEPLAY_PIRATA].state = ORIGINAL;
    context.gameplay.objects[ID_GAMEPLAY_PIRATA].type = INTERACTIVE;

    context.gameplay.objects[ID_GAMEPLAY_VARA_PESCA].name = "varaPesca";
    context.gameplay.objects[ID_GAMEPLAY_VARA_PESCA].id = ID_GAMEPLAY_VARA_PESCA;
    context.gameplay.objects[ID_GAMEPLAY_VARA_PESCA].texture = LoadTexture("assets/objetosMainGameplay/VaraPesca.png");
    context.gameplay.objects[ID_GAMEPLAY_VARA_PESCA].position = (Vector2){0, 0};
    context.gameplay.objects[ID_GAMEPLAY_VARA_PESCA].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
    context.gameplay.objects[ID_GAMEPLAY_VARA_PESCA].bounds = (Rectangle){0, 0, 0, 0};   //preciso pegar a imagem com todas as camadas com malu
    context.gameplay.objects[ID_GAMEPLAY_VARA_PESCA].state = ORIGINAL;
    context.gameplay.objects[ID_GAMEPLAY_VARA_PESCA].type = INTERACTIVE;

    context.gameplay.objects[ID_GAMEPLAY_CHAVE].name = "chave";
    context.gameplay.objects[ID_GAMEPLAY_CHAVE].id = ID_GAMEPLAY_CHAVE;
    context.gameplay.objects[ID_GAMEPLAY_CHAVE].texture = LoadTexture("assets/jill.png");
    context.gameplay.objects[ID_GAMEPLAY_CHAVE].position = (Vector2){0, 0};
    context.gameplay.objects[ID_GAMEPLAY_CHAVE].size = (Vector2){0, 0};
    context.gameplay.objects[ID_GAMEPLAY_CHAVE].bounds = (Rectangle){0, 0, 0, 0};  
    context.gameplay.objects[ID_GAMEPLAY_CHAVE].state = ORIGINAL;
    context.gameplay.objects[ID_GAMEPLAY_CHAVE].type = INTERACTIVE;

    context.gameplay.objects[ID_GAMEPLAY_BILHETE].name = "bilhete";
    context.gameplay.objects[ID_GAMEPLAY_BILHETE].id = ID_GAMEPLAY_BILHETE;
    context.gameplay.objects[ID_GAMEPLAY_BILHETE].texture = LoadTexture("assets/jill.png");
    context.gameplay.objects[ID_GAMEPLAY_BILHETE].position = (Vector2){0, 0};
    context.gameplay.objects[ID_GAMEPLAY_BILHETE].size = (Vector2){0, 0};
    context.gameplay.objects[ID_GAMEPLAY_BILHETE].bounds = (Rectangle){0, 0, 0, 0};         
    context.gameplay.objects[ID_GAMEPLAY_BILHETE].state = ORIGINAL;
    context.gameplay.objects[ID_GAMEPLAY_BILHETE].type = INTERACTIVE;

    context.gameplay.background = LoadTexture("assets/MainGameplayBG.png");
    context.gameplay.substate = GAMEPLAY_SUBSTATE_MAIN;
    return context;
}

//processa ações entre o objeto na mão do jogador e o objeto em que ele clicou
GameState processGameplayEvent(GameObject* utility, GameObject* target, GameContext* context){
    switch(context->gameplay.substate){
        case GAMEPLAY_SUBSTATE_MAIN:
            switch(target->id) {
                case ID_GAMEPLAY_ARMARIO:
                    context->gameplay.substate = processArmarioEvent(utility, target, context);
                    return STATE_GAMEPLAY;
                case ID_GAMEPLAY_CAIXA_ARMARIO:
                    context->gameplay.substate = processCaixaArmarioEvent(utility, target, context);
                    return STATE_GAMEPLAY;
                case ID_GAMEPLAY_CAIXA_CAMA:
                    context->gameplay.substate = processCaixaCamaEvent(utility, target, context);
                    return STATE_GAMEPLAY;
                case ID_GAMEPLAY_BURACO:
                    context->gameplay.substate = processBuracoEvent(utility, target, context);
                    return STATE_GAMEPLAY;
                case ID_GAMEPLAY_DIARIO:
                    context->gameplay.substate = processDiarioEvent(utility, target, context);
                    return STATE_GAMEPLAY;
                case ID_GAMEPLAY_VITROLA:
                    context->gameplay.substate = processVitrolaEvent(utility, target, context);
                    return STATE_GAMEPLAY;
                case ID_GAMEPLAY_GARRAFA:
                    context->gameplay.substate = processGarrafaEvent(utility, target, context);
                    return STATE_GAMEPLAY;
                case ID_GAMEPLAY_ESTANTE:
                    context->gameplay.substate = processEstanteEvent(utility, target, context);
                    return STATE_GAMEPLAY;
                case ID_GAMEPLAY_PIRATA: 
                    context->gameplay.substate = processPirataEvent(utility, target, context);
                    printf("entrou estado pirata\n");
                    return STATE_GAMEPLAY;
                case ID_GAMEPLAY_VARA_PESCA:
                    context->gameplay.substate = processPescaEvent(utility, target, context);
                    return STATE_GAMEPLAY;
                case ID_GAMEPLAY_CHAVE:
                    context->gameplay.substate = processChaveEvent(utility, target, context);
                    return STATE_GAMEPLAY;
                case ID_GAMEPLAY_BILHETE:
                    context->gameplay.substate = processBilheteEvent(utility, target, context);
                    return STATE_GAMEPLAY;
            }

        case GAMEPLAY_SUBSTATE_ZOOM_CAIXA_ARMARIO:
            context->gameplay.substate = processZoomCaixaArmarioEvent(target);
            return STATE_GAMEPLAY;

        case GAMEPLAY_SUBSTATE_ZOOM_CAIXA_CAMA:
            context->gameplay.substate = processZoomCaixaCamaEvent(target);
            return STATE_GAMEPLAY;

        case GAMEPLAY_SUBSTATE_ZOOM_GARRAFA:
            context->gameplay.substate = processZoomGarrafaEvent(target);
            return STATE_GAMEPLAY;

        case GAMEPLAY_SUBSTATE_ZOOM_PIRATA:
            context->gameplay.substate = processZoomPirataEvent(target);
            return STATE_GAMEPLAY;

        case GAMEPLAY_SUBSTATE_ZOOM_BILHETE:
            context->gameplay.substate = processZoomBilheteEvent(target);
            return STATE_GAMEPLAY;

        case GAMEPLAY_SUBSTATE_ZOOM_DIARIO:
            context->gameplay.substate = processZoomDiarioEvent(target);
            return STATE_GAMEPLAY;

        case GAMEPLAY_SUBSTATE_ZOOM_ESTANTE:
            context->gameplay.substate = processZoomEstanteEvent(target);
            return STATE_GAMEPLAY;
    }
}

Texture2D GetGameplayBackground(GameContext context) {
    //printf("procurano o fundo...\n");
    switch(context.gameplay.substate){
        case GAMEPLAY_SUBSTATE_MAIN:
            //printf("pegou fundo gameplay\n");
            return context.gameplay.background;
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_CAIXA_ARMARIO:
            return GetZoomCaixaArmarioBackground(context);
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_CAIXA_CAMA:
            return GetZoomCaixaCamaBackground(context);
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_GARRAFA:
            return GetZoomGarrafaBackground(context);
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_PIRATA:
            printf("pegou fundo pirata\n");
            return GetZoomPirataBackground(context);
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_BILHETE:
            return GetZoomBilheteBackground(context);
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_DIARIO:
            return GetZoomDiarioBackground(context);
            break;        
        case GAMEPLAY_SUBSTATE_ZOOM_ESTANTE:
            return GetZoomEstanteBackground(context);
            break;
    }
}

GameObject* GetGameplayObjects(GameContext context){
    switch(context.gameplay.substate){
        case GAMEPLAY_SUBSTATE_MAIN:
            return context.gameplay.objects;
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_CAIXA_ARMARIO:
            return GetZoomCaixaArmarioObjects(context);
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_CAIXA_CAMA:
            return GetZoomCaixaCamaObjects(context);
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_GARRAFA:
            return GetZoomGarrafaObjects(context);
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_PIRATA:
            printf("pegou objetos pirata\n");
            return GetZoomPirataObjects(context);
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_BILHETE:
            return GetZoomBilheteObjects(context);
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_DIARIO:
            return GetZoomDiarioObjects(context);
            break;        
        case GAMEPLAY_SUBSTATE_ZOOM_ESTANTE:
            return GetZoomEstanteObjects(context);
            break;
    }
}

int GetGameplayObjectCount(GameContext context) {
    switch(context.gameplay.substate){
        case GAMEPLAY_SUBSTATE_MAIN:
            return context.gameplay.objectCount;
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_CAIXA_ARMARIO:
            printf("merda\n");
            return GetZoomCaixaArmarioObjectCount(context);
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_CAIXA_CAMA:
            return GetZoomCaixaCamaObjectCount(context);
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_GARRAFA:
            return GetZoomGarrafaObjectCount(context);
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_PIRATA:
            printf("pegou obj count pirata\n");
            return GetZoomPirataObjectCount(context);
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_BILHETE:
            return GetZoomBilheteObjectCount(context);
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_DIARIO:
            return GetZoomDiarioObjectCount(context);
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_ESTANTE:
            return GetZoomEstanteObjectCount(context);
            break;
    }
}


