#include "scenes/scenegameplay.h"
GameObject* hand;

GameplaySubstate processArmarioEvent(GameObject* utility, GameObject* target){

}

GameplaySubstate processCaixaArmarioEvent(GameObject* utility, GameObject* target){

}

GameplaySubstate processCaixaCamaEvent(GameObject* utility, GameObject* target){

}

GameplaySubstate processBuracoEvent(GameObject* utility, GameObject* target){

}

GameplaySubstate processDiarioEvent(GameObject* utility, GameObject* target){

}

GameplaySubstate processVitrolaEvent(GameObject* utility, GameObject* target){

}

GameplaySubstate processGarrafaEvent(GameObject* utility, GameObject* target){

}

GameplaySubstate processEstanteEvent(GameObject* utility, GameObject* target){

}

GameplaySubstate processPirataEvent(GameObject* utility, GameObject* target){

}

GameplaySubstate processPescaEvent(GameObject* utility, GameObject* target){

}

GameplaySubstate processChaveEvent(GameObject* utility, GameObject* target){

}

GameplaySubstate processBilheteEvent(GameObject* utility, GameObject* target){

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
GameState processGameplayEvent(GameObject* utility, GameObject* target, GameContext context){
    switch(target->id){
        case ID_GAMEPLAY_ARMARIO:
            context.gameplay.substate = processArmarioEvent(utility, target);

            break;
        case ID_GAMEPLAY_CAIXA_ARMARIO:
            context.gameplay.substate = processCaixaArmarioEvent(utility, target);

            break;
        case ID_GAMEPLAY_CAIXA_CAMA:
            context.gameplay.substate = processCaixaCamaEvent(utility, target);

            break;
        case ID_GAMEPLAY_BURACO:
            context.gameplay.substate = processBuracoEvent(utility, target);

            break;
        case ID_GAMEPLAY_DIARIO:
            context.gameplay.substate = processDiarioEvent(utility, target);

            break;
        case ID_GAMEPLAY_VITROLA:
            context.gameplay.substate = processVitrolaEvent(utility, target);

            break;
        case ID_GAMEPLAY_GARRAFA:
            context.gameplay.substate = processGarrafaEvent(utility, target);

            break;
        case ID_GAMEPLAY_ESTANTE:
            context.gameplay.substate = processEstanteEvent(utility, target);

            break;
        case ID_GAMEPLAY_PIRATA: 
            context.gameplay.substate = processPirataEvent(utility, target);

            break;
        case ID_GAMEPLAY_VARA_PESCA:
            context.gameplay.substate = processPescaEvent(utility, target);

            break;
        case ID_GAMEPLAY_CHAVE:
            context.gameplay.substate = processChaveEvent(utility, target);

            break;
        case ID_GAMEPLAY_BILHETE:
            context.gameplay.substate = processBilheteEvent(utility, target);

            break;
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
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_CAIXA_CAMA:
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_GARRAFA:
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_PIRATA:
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_BILHETE:
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_DIARIO:
            break;        
        case GAMEPLAY_SUBSTATE_ZOOM_ESTANTE:
            break;
    }
}

GameObject* GetGameplayObjects(GameContext context){
    switch(context.gameplay.substate){
        case GAMEPLAY_SUBSTATE_MAIN:
            return context.gameplay.objects;
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_CAIXA_ARMARIO:
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_CAIXA_CAMA:
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_GARRAFA:
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_PIRATA:
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_BILHETE:
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_DIARIO:
            break;        
        case GAMEPLAY_SUBSTATE_ZOOM_ESTANTE:
            break;
    }
}

int GetGameplayObjectCount(GameContext context) {
    switch(context.gameplay.substate){
        case GAMEPLAY_SUBSTATE_MAIN:
            return context.gameplay.objectCount;
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_CAIXA_ARMARIO:
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_CAIXA_CAMA:
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_GARRAFA:
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_PIRATA:
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_BILHETE:
            break;
        case GAMEPLAY_SUBSTATE_ZOOM_DIARIO:
            break;        
        case GAMEPLAY_SUBSTATE_ZOOM_ESTANTE:
            break;
    }
}


