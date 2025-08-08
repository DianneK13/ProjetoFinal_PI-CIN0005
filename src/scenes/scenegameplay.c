#include "scenes/scenegameplay.h"


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


GameContext InitializeGameplayState(GameContext context) {

    // numero de objetos
    // SEMPRE ATUALIZAR ESSE NUMERO CASO ADICIONE NOVO OBJETO
    context.gameplay.objectCount = 12;
    context.gameplay.objects = (GameObject*)malloc(context.gameplay.objectCount * sizeof(GameObject));
    
    if (context.gameplay.objects == NULL) {
        //printf("Failed to allocate memory for objects\n");
        return;
    }
    
    // Initialize objects with their properties
    context.gameplay.objects[ID_GAMEPLAY_ARMARIO].name = "armario";
    context.gameplay.objects[ID_GAMEPLAY_ARMARIO].id = ID_GAMEPLAY_ARMARIO;
    context.gameplay.objects[ID_GAMEPLAY_ARMARIO].texture = LoadTexture("assets/.png");
    context.gameplay.objects[ID_GAMEPLAY_ARMARIO].position = (Vector2){50, 100};
    context.gameplay.objects[ID_GAMEPLAY_ARMARIO].size = (Vector2){150, 120};
    context.gameplay.objects[ID_GAMEPLAY_ARMARIO].bounds = (Rectangle){50, 100, 150, 120};
    context.gameplay.objects[ID_GAMEPLAY_ARMARIO].state = ORIGINAL;
    context.gameplay.objects[ID_GAMEPLAY_ARMARIO].type = INTERACTIVE;

    context.gameplay.objects[ID_GAMEPLAY_CAIXA_ARMARIO].name = "caixaArmario";
    context.gameplay.objects[ID_GAMEPLAY_CAIXA_ARMARIO].id = ID_GAMEPLAY_CAIXA_ARMARIO;    
    context.gameplay.objects[ID_GAMEPLAY_CAIXA_ARMARIO].texture = LoadTexture("assets/.png");
    context.gameplay.objects[ID_GAMEPLAY_CAIXA_ARMARIO].position = (Vector2){50, 100};
    context.gameplay.objects[ID_GAMEPLAY_CAIXA_ARMARIO].size = (Vector2){150, 120};
    context.gameplay.objects[ID_GAMEPLAY_CAIXA_ARMARIO].bounds = (Rectangle){50, 100, 150, 120};
    context.gameplay.objects[ID_GAMEPLAY_CAIXA_ARMARIO].state = ORIGINAL;
    context.gameplay.objects[ID_GAMEPLAY_CAIXA_ARMARIO].type = INTERACTIVE;

    context.gameplay.objects[ID_GAMEPLAY_CAIXA_CAMA].name = "caixaCama";
    context.gameplay.objects[ID_GAMEPLAY_CAIXA_CAMA].id = ID_GAMEPLAY_CAIXA_CAMA;
    context.gameplay.objects[ID_GAMEPLAY_CAIXA_CAMA].texture = LoadTexture("assets/.png");
    context.gameplay.objects[ID_GAMEPLAY_CAIXA_CAMA].position = (Vector2){50, 100};
    context.gameplay.objects[ID_GAMEPLAY_CAIXA_CAMA].size = (Vector2){150, 120};
    context.gameplay.objects[ID_GAMEPLAY_CAIXA_CAMA].bounds = (Rectangle){50, 100, 150, 120};
    context.gameplay.objects[ID_GAMEPLAY_CAIXA_CAMA].state = ORIGINAL;
    context.gameplay.objects[ID_GAMEPLAY_CAIXA_CAMA].type = INTERACTIVE;    

    context.gameplay.objects[ID_GAMEPLAY_BURACO].name = "buraco";
    context.gameplay.objects[ID_GAMEPLAY_BURACO].id = ID_GAMEPLAY_BURACO;
    context.gameplay.objects[ID_GAMEPLAY_BURACO].texture = LoadTexture("assets/.png");
    context.gameplay.objects[ID_GAMEPLAY_BURACO].position = (Vector2){50, 100};
    context.gameplay.objects[ID_GAMEPLAY_BURACO].size = (Vector2){150, 120};
    context.gameplay.objects[ID_GAMEPLAY_BURACO].bounds = (Rectangle){50, 100, 150, 120};
    context.gameplay.objects[ID_GAMEPLAY_BURACO].state = ORIGINAL;
    context.gameplay.objects[ID_GAMEPLAY_BURACO].type = INTERACTIVE;

    context.gameplay.objects[ID_GAMEPLAY_DIARIO].name = "diario";
    context.gameplay.objects[ID_GAMEPLAY_DIARIO].id = ID_GAMEPLAY_DIARIO;
    context.gameplay.objects[ID_GAMEPLAY_DIARIO].texture = LoadTexture("assets/.png");
    context.gameplay.objects[ID_GAMEPLAY_DIARIO].position = (Vector2){50, 100};
    context.gameplay.objects[ID_GAMEPLAY_DIARIO].size = (Vector2){150, 120};
    context.gameplay.objects[ID_GAMEPLAY_DIARIO].bounds = (Rectangle){50, 100, 150, 120};
    context.gameplay.objects[ID_GAMEPLAY_DIARIO].state = ORIGINAL;
    context.gameplay.objects[ID_GAMEPLAY_DIARIO].type = INTERACTIVE;

    context.gameplay.objects[ID_GAMEPLAY_VITROLA].name = "vitrola";
    context.gameplay.objects[ID_GAMEPLAY_VITROLA].id = ID_GAMEPLAY_VITROLA;
    context.gameplay.objects[ID_GAMEPLAY_VITROLA].texture = LoadTexture("assets/.png");
    context.gameplay.objects[ID_GAMEPLAY_VITROLA].position = (Vector2){50, 100};
    context.gameplay.objects[ID_GAMEPLAY_VITROLA].size = (Vector2){150, 120};
    context.gameplay.objects[ID_GAMEPLAY_VITROLA].bounds = (Rectangle){50, 100, 150, 120};
    context.gameplay.objects[ID_GAMEPLAY_VITROLA].state = ORIGINAL;
    context.gameplay.objects[ID_GAMEPLAY_VITROLA].type = INTERACTIVE;

    context.gameplay.objects[ID_GAMEPLAY_GARRAFA].name = "garrafa";
    context.gameplay.objects[ID_GAMEPLAY_GARRAFA].id = ID_GAMEPLAY_GARRAFA;
    context.gameplay.objects[ID_GAMEPLAY_GARRAFA].texture = LoadTexture("assets/.png");
    context.gameplay.objects[ID_GAMEPLAY_GARRAFA].position = (Vector2){50, 100};
    context.gameplay.objects[ID_GAMEPLAY_GARRAFA].size = (Vector2){150, 120};
    context.gameplay.objects[ID_GAMEPLAY_GARRAFA].bounds = (Rectangle){50, 100, 150, 120};
    context.gameplay.objects[ID_GAMEPLAY_GARRAFA].state = ORIGINAL;
    context.gameplay.objects[ID_GAMEPLAY_GARRAFA].type = INTERACTIVE;

    context.gameplay.objects[ID_GAMEPLAY_ESTANTE].name = "estante";
    context.gameplay.objects[ID_GAMEPLAY_ESTANTE].id = ID_GAMEPLAY_ESTANTE;
    context.gameplay.objects[ID_GAMEPLAY_ESTANTE].texture = LoadTexture("assets/.png");
    context.gameplay.objects[ID_GAMEPLAY_ESTANTE].position = (Vector2){50, 100};
    context.gameplay.objects[ID_GAMEPLAY_ESTANTE].size = (Vector2){150, 120};
    context.gameplay.objects[ID_GAMEPLAY_ESTANTE].bounds = (Rectangle){50, 100, 150, 120};
    context.gameplay.objects[ID_GAMEPLAY_ESTANTE].state = ORIGINAL;
    context.gameplay.objects[ID_GAMEPLAY_ESTANTE].type = INTERACTIVE;    

    context.gameplay.objects[ID_GAMEPLAY_PIRATA].name = "pirata";
    context.gameplay.objects[ID_GAMEPLAY_PIRATA].id = ID_GAMEPLAY_PIRATA;
    context.gameplay.objects[ID_GAMEPLAY_PIRATA].texture = LoadTexture("assets/.png");
    context.gameplay.objects[ID_GAMEPLAY_PIRATA].position = (Vector2){50, 100};
    context.gameplay.objects[ID_GAMEPLAY_PIRATA].size = (Vector2){150, 120};
    context.gameplay.objects[ID_GAMEPLAY_PIRATA].bounds = (Rectangle){50, 100, 150, 120};       
    context.gameplay.objects[ID_GAMEPLAY_PIRATA].state = ORIGINAL;
    context.gameplay.objects[ID_GAMEPLAY_PIRATA].type = INTERACTIVE;

    context.gameplay.objects[ID_GAMEPLAY_VARA_PESCA].name = "varaPesca";
    context.gameplay.objects[ID_GAMEPLAY_VARA_PESCA].id = ID_GAMEPLAY_VARA_PESCA;
    context.gameplay.objects[ID_GAMEPLAY_VARA_PESCA].texture = LoadTexture("assets/.png");
    context.gameplay.objects[ID_GAMEPLAY_VARA_PESCA].position = (Vector2){50, 100};
    context.gameplay.objects[ID_GAMEPLAY_VARA_PESCA].size = (Vector2){150, 120};
    context.gameplay.objects[ID_GAMEPLAY_VARA_PESCA].bounds = (Rectangle){50, 100, 150, 120};     
    context.gameplay.objects[ID_GAMEPLAY_VARA_PESCA].state = ORIGINAL;
    context.gameplay.objects[ID_GAMEPLAY_VARA_PESCA].type = INTERACTIVE;

    context.gameplay.objects[ID_GAMEPLAY_CHAVE].name = "chave";
    context.gameplay.objects[ID_GAMEPLAY_CHAVE].id = ID_GAMEPLAY_CHAVE;
    context.gameplay.objects[ID_GAMEPLAY_CHAVE].texture = LoadTexture("assets/.png");
    context.gameplay.objects[ID_GAMEPLAY_CHAVE].position = (Vector2){50, 100};
    context.gameplay.objects[ID_GAMEPLAY_CHAVE].size = (Vector2){150, 120};
    context.gameplay.objects[ID_GAMEPLAY_CHAVE].bounds = (Rectangle){50, 100, 150, 120};   
    context.gameplay.objects[ID_GAMEPLAY_CHAVE].state = ORIGINAL;
    context.gameplay.objects[ID_GAMEPLAY_CHAVE].type = INTERACTIVE;

    context.gameplay.objects[ID_GAMEPLAY_BILHETE].name = "bilhete";
    context.gameplay.objects[ID_GAMEPLAY_BILHETE].id = ID_GAMEPLAY_BILHETE;
    context.gameplay.objects[ID_GAMEPLAY_BILHETE].texture = LoadTexture("assets/.png");
    context.gameplay.objects[ID_GAMEPLAY_BILHETE].position = (Vector2){50, 100};
    context.gameplay.objects[ID_GAMEPLAY_BILHETE].size = (Vector2){150, 120};
    context.gameplay.objects[ID_GAMEPLAY_BILHETE].bounds = (Rectangle){50, 100, 150, 120};         
    context.gameplay.objects[ID_GAMEPLAY_BILHETE].state = ORIGINAL;
    context.gameplay.objects[ID_GAMEPLAY_BILHETE].type = INTERACTIVE;

    context.gameplay.background = LoadTexture("assets/fundofodao.png");
    context.gameplay.substate = -1;
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



Texture2D GetGameplayBackground(void) {

}

GameObject* GetgameplayObjects(void){
    return NULL;
}

int GetGameplayObjectCount(void) {
    return 0;
}


