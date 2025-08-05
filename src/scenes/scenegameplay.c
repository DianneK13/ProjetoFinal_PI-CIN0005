#include "scenes/scenegameplay.h"

//array de objects desta cena
GameObject* objects_mainGameplay;
//qtd de objetos desta cena
int objectCount_mainGameplay;

//imagem de fundo desta cena
Texture2D background_mainGameplay;

//subestado da gameplay (tela principal, zoomcaixa...)
GameplaySubstate substate;

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


void InitializeGameplayState() {

    // numero de objetos
    // SEMPRE ATUALIZAR ESSE NUMERO CASO ADICIONE NOVO OBJETO
    objectCount_mainGameplay = 12;
    objects_mainGameplay = (GameObject*)malloc(objectCount_mainGameplay * sizeof(GameObject));
    
    if (objects_mainGameplay == NULL) {
        //printf("Failed to allocate memory for objects\n");
        return;
    }
    
    // Initialize objects with their properties
    objects_mainGameplay[ID_GAMEPLAY_ARMARIO].name = "armario";
    objects_mainGameplay[ID_GAMEPLAY_ARMARIO].id = ID_GAMEPLAY_ARMARIO;
    objects_mainGameplay[ID_GAMEPLAY_ARMARIO].texture = LoadTexture("assets/.png");
    objects_mainGameplay[ID_GAMEPLAY_ARMARIO].position = (Vector2){50, 100};
    objects_mainGameplay[ID_GAMEPLAY_ARMARIO].size = (Vector2){150, 120};
    objects_mainGameplay[ID_GAMEPLAY_ARMARIO].bounds = (Rectangle){50, 100, 150, 120};
    objects_mainGameplay[ID_GAMEPLAY_ARMARIO].state = ORIGINAL;
    objects_mainGameplay[ID_GAMEPLAY_ARMARIO].type = INTERACTIVE;

    objects_mainGameplay[ID_GAMEPLAY_CAIXA_ARMARIO].name = "caixaArmario";
    objects_mainGameplay[ID_GAMEPLAY_CAIXA_ARMARIO].id = ID_GAMEPLAY_CAIXA_ARMARIO;    
    objects_mainGameplay[ID_GAMEPLAY_CAIXA_ARMARIO].texture = LoadTexture("assets/.png");
    objects_mainGameplay[ID_GAMEPLAY_CAIXA_ARMARIO].position = (Vector2){50, 100};
    objects_mainGameplay[ID_GAMEPLAY_CAIXA_ARMARIO].size = (Vector2){150, 120};
    objects_mainGameplay[ID_GAMEPLAY_CAIXA_ARMARIO].bounds = (Rectangle){50, 100, 150, 120};
    objects_mainGameplay[ID_GAMEPLAY_CAIXA_ARMARIO].state = ORIGINAL;
    objects_mainGameplay[ID_GAMEPLAY_CAIXA_ARMARIO].type = INTERACTIVE;

    objects_mainGameplay[ID_GAMEPLAY_CAIXA_CAMA].name = "caixaCama";
    objects_mainGameplay[ID_GAMEPLAY_CAIXA_CAMA].id = ID_GAMEPLAY_CAIXA_CAMA;
    objects_mainGameplay[ID_GAMEPLAY_CAIXA_CAMA].texture = LoadTexture("assets/.png");
    objects_mainGameplay[ID_GAMEPLAY_CAIXA_CAMA].position = (Vector2){50, 100};
    objects_mainGameplay[ID_GAMEPLAY_CAIXA_CAMA].size = (Vector2){150, 120};
    objects_mainGameplay[ID_GAMEPLAY_CAIXA_CAMA].bounds = (Rectangle){50, 100, 150, 120};
    objects_mainGameplay[ID_GAMEPLAY_CAIXA_CAMA].state = ORIGINAL;
    objects_mainGameplay[ID_GAMEPLAY_CAIXA_CAMA].type = INTERACTIVE;    

    objects_mainGameplay[ID_GAMEPLAY_BURACO].name = "buraco";
    objects_mainGameplay[ID_GAMEPLAY_BURACO].id = ID_GAMEPLAY_BURACO;
    objects_mainGameplay[ID_GAMEPLAY_BURACO].texture = LoadTexture("assets/.png");
    objects_mainGameplay[ID_GAMEPLAY_BURACO].position = (Vector2){50, 100};
    objects_mainGameplay[ID_GAMEPLAY_BURACO].size = (Vector2){150, 120};
    objects_mainGameplay[ID_GAMEPLAY_BURACO].bounds = (Rectangle){50, 100, 150, 120};
    objects_mainGameplay[ID_GAMEPLAY_BURACO].state = ORIGINAL;
    objects_mainGameplay[ID_GAMEPLAY_BURACO].type = INTERACTIVE;

    objects_mainGameplay[ID_GAMEPLAY_DIARIO].name = "diario";
    objects_mainGameplay[ID_GAMEPLAY_DIARIO].id = ID_GAMEPLAY_DIARIO;
    objects_mainGameplay[ID_GAMEPLAY_DIARIO].texture = LoadTexture("assets/.png");
    objects_mainGameplay[ID_GAMEPLAY_DIARIO].position = (Vector2){50, 100};
    objects_mainGameplay[ID_GAMEPLAY_DIARIO].size = (Vector2){150, 120};
    objects_mainGameplay[ID_GAMEPLAY_DIARIO].bounds = (Rectangle){50, 100, 150, 120};
    objects_mainGameplay[ID_GAMEPLAY_DIARIO].state = ORIGINAL;
    objects_mainGameplay[ID_GAMEPLAY_DIARIO].type = INTERACTIVE;

    objects_mainGameplay[ID_GAMEPLAY_VITROLA].name = "vitrola";
    objects_mainGameplay[ID_GAMEPLAY_VITROLA].id = ID_GAMEPLAY_VITROLA;
    objects_mainGameplay[ID_GAMEPLAY_VITROLA].texture = LoadTexture("assets/.png");
    objects_mainGameplay[ID_GAMEPLAY_VITROLA].position = (Vector2){50, 100};
    objects_mainGameplay[ID_GAMEPLAY_VITROLA].size = (Vector2){150, 120};
    objects_mainGameplay[ID_GAMEPLAY_VITROLA].bounds = (Rectangle){50, 100, 150, 120};
    objects_mainGameplay[ID_GAMEPLAY_VITROLA].state = ORIGINAL;
    objects_mainGameplay[ID_GAMEPLAY_VITROLA].type = INTERACTIVE;

    objects_mainGameplay[ID_GAMEPLAY_GARRAFA].name = "garrafa";
    objects_mainGameplay[ID_GAMEPLAY_GARRAFA].id = ID_GAMEPLAY_GARRAFA;
    objects_mainGameplay[ID_GAMEPLAY_GARRAFA].texture = LoadTexture("assets/.png");
    objects_mainGameplay[ID_GAMEPLAY_GARRAFA].position = (Vector2){50, 100};
    objects_mainGameplay[ID_GAMEPLAY_GARRAFA].size = (Vector2){150, 120};
    objects_mainGameplay[ID_GAMEPLAY_GARRAFA].bounds = (Rectangle){50, 100, 150, 120};
    objects_mainGameplay[ID_GAMEPLAY_GARRAFA].state = ORIGINAL;
    objects_mainGameplay[ID_GAMEPLAY_GARRAFA].type = INTERACTIVE;

    objects_mainGameplay[ID_GAMEPLAY_ESTANTE].name = "estante";
    objects_mainGameplay[ID_GAMEPLAY_ESTANTE].id = ID_GAMEPLAY_ESTANTE;
    objects_mainGameplay[ID_GAMEPLAY_ESTANTE].texture = LoadTexture("assets/.png");
    objects_mainGameplay[ID_GAMEPLAY_ESTANTE].position = (Vector2){50, 100};
    objects_mainGameplay[ID_GAMEPLAY_ESTANTE].size = (Vector2){150, 120};
    objects_mainGameplay[ID_GAMEPLAY_ESTANTE].bounds = (Rectangle){50, 100, 150, 120};
    objects_mainGameplay[ID_GAMEPLAY_ESTANTE].state = ORIGINAL;
    objects_mainGameplay[ID_GAMEPLAY_ESTANTE].type = INTERACTIVE;    

    objects_mainGameplay[ID_GAMEPLAY_PIRATA].name = "pirata";
    objects_mainGameplay[ID_GAMEPLAY_PIRATA].id = ID_GAMEPLAY_PIRATA;
    objects_mainGameplay[ID_GAMEPLAY_PIRATA].texture = LoadTexture("assets/.png");
    objects_mainGameplay[ID_GAMEPLAY_PIRATA].position = (Vector2){50, 100};
    objects_mainGameplay[ID_GAMEPLAY_PIRATA].size = (Vector2){150, 120};
    objects_mainGameplay[ID_GAMEPLAY_PIRATA].bounds = (Rectangle){50, 100, 150, 120};       
    objects_mainGameplay[ID_GAMEPLAY_PIRATA].state = ORIGINAL;
    objects_mainGameplay[ID_GAMEPLAY_PIRATA].type = INTERACTIVE;

    objects_mainGameplay[ID_GAMEPLAY_VARA_PESCA].name = "varaPesca";
    objects_mainGameplay[ID_GAMEPLAY_VARA_PESCA].id = ID_GAMEPLAY_VARA_PESCA;
    objects_mainGameplay[ID_GAMEPLAY_VARA_PESCA].texture = LoadTexture("assets/.png");
    objects_mainGameplay[ID_GAMEPLAY_VARA_PESCA].position = (Vector2){50, 100};
    objects_mainGameplay[ID_GAMEPLAY_VARA_PESCA].size = (Vector2){150, 120};
    objects_mainGameplay[ID_GAMEPLAY_VARA_PESCA].bounds = (Rectangle){50, 100, 150, 120};     
    objects_mainGameplay[ID_GAMEPLAY_VARA_PESCA].state = ORIGINAL;
    objects_mainGameplay[ID_GAMEPLAY_VARA_PESCA].type = INTERACTIVE;

    objects_mainGameplay[ID_GAMEPLAY_CHAVE].name = "chave";
    objects_mainGameplay[ID_GAMEPLAY_CHAVE].id = ID_GAMEPLAY_CHAVE;
    objects_mainGameplay[ID_GAMEPLAY_CHAVE].texture = LoadTexture("assets/.png");
    objects_mainGameplay[ID_GAMEPLAY_CHAVE].position = (Vector2){50, 100};
    objects_mainGameplay[ID_GAMEPLAY_CHAVE].size = (Vector2){150, 120};
    objects_mainGameplay[ID_GAMEPLAY_CHAVE].bounds = (Rectangle){50, 100, 150, 120};   
    objects_mainGameplay[ID_GAMEPLAY_CHAVE].state = ORIGINAL;
    objects_mainGameplay[ID_GAMEPLAY_CHAVE].type = INTERACTIVE;

    objects_mainGameplay[ID_GAMEPLAY_BILHETE].name = "bilhete";
    objects_mainGameplay[ID_GAMEPLAY_BILHETE].id = ID_GAMEPLAY_BILHETE;
    objects_mainGameplay[ID_GAMEPLAY_BILHETE].texture = LoadTexture("assets/.png");
    objects_mainGameplay[ID_GAMEPLAY_BILHETE].position = (Vector2){50, 100};
    objects_mainGameplay[ID_GAMEPLAY_BILHETE].size = (Vector2){150, 120};
    objects_mainGameplay[ID_GAMEPLAY_BILHETE].bounds = (Rectangle){50, 100, 150, 120};         
    objects_mainGameplay[ID_GAMEPLAY_BILHETE].state = ORIGINAL;
    objects_mainGameplay[ID_GAMEPLAY_BILHETE].type = INTERACTIVE;


}

//processa ações entre o objeto na mão do jogador e o objeto em que ele clicou
GameState processGameplayEvent(GameObject* utility, GameObject* target){
    switch(target->id){
        case ID_GAMEPLAY_ARMARIO:
            substate = processArmarioEvent(utility, target);

            break;
        case ID_GAMEPLAY_CAIXA_ARMARIO:
            substate = processCaixaArmarioEvent(utility, target);

            break;
        case ID_GAMEPLAY_CAIXA_CAMA:
            substate = processCaixaCamaEvent(utility, target);

            break;
        case ID_GAMEPLAY_BURACO:
            substate = processBuracoEvent(utility, target);

            break;
        case ID_GAMEPLAY_DIARIO:
            substate = processDiarioEvent(utility, target);

            break;
        case ID_GAMEPLAY_VITROLA:
            substate = processVitrolaEvent(utility, target);

            break;
        case ID_GAMEPLAY_GARRAFA:
            substate = processGarrafaEvent(utility, target);

            break;
        case ID_GAMEPLAY_ESTANTE:
            substate = processEstanteEvent(utility, target);

            break;
        case ID_GAMEPLAY_PIRATA: 
            substate = processPirataEvent(utility, target);

            break;
        case ID_GAMEPLAY_VARA_PESCA:
            substate = processPescaEvent(utility, target);

            break;
        case ID_GAMEPLAY_CHAVE:
            substate = processChaveEvent(utility, target);

            break;
        case ID_GAMEPLAY_BILHETE:
            substate = processBilheteEvent(utility, target);

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


