#include "scenes/scenegameplay.h"


GameObject* objects;
int objectCount;

//object in player's hand
GameObject* hand = NULL;


void InitializeGameplayState() {

    // numero de objetos
    // SEMPRE ATUALIZAR ESSE NUMERO CASO ADICIONE NOVO OBJETO
    objectCount = 12;
    objects = (GameObject*)malloc(objectCount * sizeof(GameObject));
    
    if (objects == NULL) {
        //printf("Failed to allocate memory for objects\n");
        return;
    }
    
    // Initialize objects with their properties
    objects[ID_GAMEPLAY_ARMARIO].name = "armario";
    objects[ID_GAMEPLAY_ARMARIO].id = ID_GAMEPLAY_ARMARIO;
    objects[ID_GAMEPLAY_ARMARIO].texture = LoadTexture("assets/.png");
    objects[ID_GAMEPLAY_ARMARIO].position = (Vector2){50, 100};
    objects[ID_GAMEPLAY_ARMARIO].size = (Vector2){150, 120};
    objects[ID_GAMEPLAY_ARMARIO].bounds = (Rectangle){50, 100, 150, 120};
    objects[ID_GAMEPLAY_ARMARIO].state = ORIGINAL;
    objects[ID_GAMEPLAY_ARMARIO].type = INTERACTIVE;

    objects[ID_GAMEPLAY_CAIXA_ARMARIO].name = "caixaArmario";
    objects[ID_GAMEPLAY_CAIXA_ARMARIO].id = ID_GAMEPLAY_CAIXA_ARMARIO;    
    objects[ID_GAMEPLAY_CAIXA_ARMARIO].texture = LoadTexture("assets/.png");
    objects[ID_GAMEPLAY_CAIXA_ARMARIO].position = (Vector2){50, 100};
    objects[ID_GAMEPLAY_CAIXA_ARMARIO].size = (Vector2){150, 120};
    objects[ID_GAMEPLAY_CAIXA_ARMARIO].bounds = (Rectangle){50, 100, 150, 120};
    objects[ID_GAMEPLAY_CAIXA_ARMARIO].state = ORIGINAL;
    objects[ID_GAMEPLAY_CAIXA_ARMARIO].type = INTERACTIVE;

    objects[ID_GAMEPLAY_CAIXA_CAMA].name = "caixaCama";
    objects[ID_GAMEPLAY_CAIXA_CAMA].id = ID_GAMEPLAY_CAIXA_CAMA;
    objects[ID_GAMEPLAY_CAIXA_CAMA].texture = LoadTexture("assets/.png");
    objects[ID_GAMEPLAY_CAIXA_CAMA].position = (Vector2){50, 100};
    objects[ID_GAMEPLAY_CAIXA_CAMA].size = (Vector2){150, 120};
    objects[ID_GAMEPLAY_CAIXA_CAMA].bounds = (Rectangle){50, 100, 150, 120};
    objects[ID_GAMEPLAY_CAIXA_CAMA].state = ORIGINAL;
    objects[ID_GAMEPLAY_CAIXA_CAMA].type = INTERACTIVE;    

    objects[ID_GAMEPLAY_BURACO].name = "buraco";
    objects[ID_GAMEPLAY_BURACO].id = ID_GAMEPLAY_BURACO;
    objects[ID_GAMEPLAY_BURACO].texture = LoadTexture("assets/.png");
    objects[ID_GAMEPLAY_BURACO].position = (Vector2){50, 100};
    objects[ID_GAMEPLAY_BURACO].size = (Vector2){150, 120};
    objects[ID_GAMEPLAY_BURACO].bounds = (Rectangle){50, 100, 150, 120};
    objects[ID_GAMEPLAY_BURACO].state = ORIGINAL;
    objects[ID_GAMEPLAY_BURACO].type = INTERACTIVE;

    objects[ID_GAMEPLAY_DIARIO].name = "diario";
    objects[ID_GAMEPLAY_DIARIO].id = ID_GAMEPLAY_DIARIO;
    objects[ID_GAMEPLAY_DIARIO].texture = LoadTexture("assets/.png");
    objects[ID_GAMEPLAY_DIARIO].position = (Vector2){50, 100};
    objects[ID_GAMEPLAY_DIARIO].size = (Vector2){150, 120};
    objects[ID_GAMEPLAY_DIARIO].bounds = (Rectangle){50, 100, 150, 120};
    objects[ID_GAMEPLAY_DIARIO].state = ORIGINAL;
    objects[ID_GAMEPLAY_DIARIO].type = INTERACTIVE;

    objects[ID_GAMEPLAY_VITROLA].name = "vitrola";
    objects[ID_GAMEPLAY_VITROLA].id = ID_GAMEPLAY_VITROLA;
    objects[ID_GAMEPLAY_VITROLA].texture = LoadTexture("assets/.png");
    objects[ID_GAMEPLAY_VITROLA].position = (Vector2){50, 100};
    objects[ID_GAMEPLAY_VITROLA].size = (Vector2){150, 120};
    objects[ID_GAMEPLAY_VITROLA].bounds = (Rectangle){50, 100, 150, 120};
    objects[ID_GAMEPLAY_VITROLA].state = ORIGINAL;
    objects[ID_GAMEPLAY_VITROLA].type = INTERACTIVE;

    objects[ID_GAMEPLAY_GARRAFA].name = "garrafa";
    objects[ID_GAMEPLAY_GARRAFA].id = ID_GAMEPLAY_GARRAFA;
    objects[ID_GAMEPLAY_GARRAFA].texture = LoadTexture("assets/.png");
    objects[ID_GAMEPLAY_GARRAFA].position = (Vector2){50, 100};
    objects[ID_GAMEPLAY_GARRAFA].size = (Vector2){150, 120};
    objects[ID_GAMEPLAY_GARRAFA].bounds = (Rectangle){50, 100, 150, 120};
    objects[ID_GAMEPLAY_GARRAFA].state = ORIGINAL;
    objects[ID_GAMEPLAY_GARRAFA].type = INTERACTIVE;

    objects[ID_GAMEPLAY_ESTANTE].name = "estante";
    objects[ID_GAMEPLAY_ESTANTE].id = ID_GAMEPLAY_ESTANTE;
    objects[ID_GAMEPLAY_ESTANTE].texture = LoadTexture("assets/.png");
    objects[ID_GAMEPLAY_ESTANTE].position = (Vector2){50, 100};
    objects[ID_GAMEPLAY_ESTANTE].size = (Vector2){150, 120};
    objects[ID_GAMEPLAY_ESTANTE].bounds = (Rectangle){50, 100, 150, 120};
    objects[ID_GAMEPLAY_ESTANTE].state = ORIGINAL;
    objects[ID_GAMEPLAY_ESTANTE].type = INTERACTIVE;    

    objects[ID_GAMEPLAY_PIRATA].name = "pirata";
    objects[ID_GAMEPLAY_PIRATA].id = ID_GAMEPLAY_PIRATA;
    objects[ID_GAMEPLAY_PIRATA].texture = LoadTexture("assets/.png");
    objects[ID_GAMEPLAY_PIRATA].position = (Vector2){50, 100};
    objects[ID_GAMEPLAY_PIRATA].size = (Vector2){150, 120};
    objects[ID_GAMEPLAY_PIRATA].bounds = (Rectangle){50, 100, 150, 120};       
    objects[ID_GAMEPLAY_PIRATA].state = ORIGINAL;
    objects[ID_GAMEPLAY_PIRATA].type = INTERACTIVE;

    objects[ID_GAMEPLAY_VARA_PESCA].name = "varaPesca";
    objects[ID_GAMEPLAY_VARA_PESCA].id = ID_GAMEPLAY_VARA_PESCA;
    objects[ID_GAMEPLAY_VARA_PESCA].texture = LoadTexture("assets/.png");
    objects[ID_GAMEPLAY_VARA_PESCA].position = (Vector2){50, 100};
    objects[ID_GAMEPLAY_VARA_PESCA].size = (Vector2){150, 120};
    objects[ID_GAMEPLAY_VARA_PESCA].bounds = (Rectangle){50, 100, 150, 120};     
    objects[ID_GAMEPLAY_VARA_PESCA].state = ORIGINAL;
    objects[ID_GAMEPLAY_VARA_PESCA].type = INTERACTIVE;

    objects[ID_GAMEPLAY_CHAVE].name = "chave";
    objects[ID_GAMEPLAY_CHAVE].id = ID_GAMEPLAY_CHAVE;
    objects[ID_GAMEPLAY_CHAVE].texture = LoadTexture("assets/.png");
    objects[ID_GAMEPLAY_CHAVE].position = (Vector2){50, 100};
    objects[ID_GAMEPLAY_CHAVE].size = (Vector2){150, 120};
    objects[ID_GAMEPLAY_CHAVE].bounds = (Rectangle){50, 100, 150, 120};   
    objects[ID_GAMEPLAY_CHAVE].state = ORIGINAL;
    objects[ID_GAMEPLAY_CHAVE].type = INTERACTIVE;

    objects[ID_GAMEPLAY_BILHETE].name = "bilhete";
    objects[ID_GAMEPLAY_BILHETE].id = ID_GAMEPLAY_BILHETE;
    objects[ID_GAMEPLAY_BILHETE].texture = LoadTexture("assets/.png");
    objects[ID_GAMEPLAY_BILHETE].position = (Vector2){50, 100};
    objects[ID_GAMEPLAY_BILHETE].size = (Vector2){150, 120};
    objects[ID_GAMEPLAY_BILHETE].bounds = (Rectangle){50, 100, 150, 120};         
    objects[ID_GAMEPLAY_BILHETE].state = ORIGINAL;
    objects[ID_GAMEPLAY_BILHETE].type = INTERACTIVE;

    return objects;
}

//processa ações entre o objeto na mão do jogador e o objeto em que ele clicou
GameState processGameplayEvent(GameObject* utility, GameObject* target){
    switch(target->id){
        case ID_GAMEPLAY_ARMARIO:
            processArmarioEvent(utility, target);

            break;
        case ID_GAMEPLAY_CAIXA_ARMARIO:
            processCaixaArmarioEvent(utility, target);

            break;
        case ID_GAMEPLAY_CAIXA_CAMA:
            processCaixaCamaEvent(utility, target);

            break;
        case ID_GAMEPLAY_BURACO:
            processBuracoEvent(utility, target);

            break;
        case ID_GAMEPLAY_DIARIO:
            processDiarioEvent(utility, target);

            break;
        case ID_GAMEPLAY_VITROLA:
            processVitrolaEvent(utility, target);

            break;
        case ID_GAMEPLAY_GARRAFA:
            processGarrafaEvent(utility, target);

            break;
        case ID_GAMEPLAY_ESTANTE:
            processEstanteEvent(utility, target);

            break;
        case ID_GAMEPLAY_PIRATA: 
            processPirataEvent(utility, target);

            break;
        case ID_GAMEPLAY_VARA_PESCA:
            processPescaEvent(utility, target);

            break;
        case ID_GAMEPLAY_CHAVE:
            processChaveEvent(utility, target);

            break;
        case ID_GAMEPLAY_BILHETE:
            processBilheteEvent(utility, target);

            break;
    }
}



GameObject* GetGameplayBackground(void) {

}

GameObject* GetgameplayObjects(void){
    return NULL;
}

int GetGameplayObjectCount(void) {
    return 0;
}

void processArmarioEvent(GameObject* utility, GameObject* target){

}

void processCaixaArmarioEvent(GameObject* utility, GameObject* target){

}

void processCaixaCamaEvent(GameObject* utility, GameObject* target){

}

void processBuracoEvent(GameObject* utility, GameObject* target){

}

void processDiarioEvent(GameObject* utility, GameObject* target){

}

void processVitrolaEvent(GameObject* utility, GameObject* target){

}

void processGarrafaEvent(GameObject* utility, GameObject* target){

}

void processEstanteEvent(GameObject* utility, GameObject* target){

}

void processPirataEvent(GameObject* utility, GameObject* target){

}

void processPescaEvent(GameObject* utility, GameObject* target){

}

void processChaveEvent(GameObject* utility, GameObject* target){

}

void processBilheteEvent(GameObject* utility, GameObject* target){

}
