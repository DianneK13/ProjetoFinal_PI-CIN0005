#include "state_manager.h"

#define ID_ARMARIO 0
#define ID_CAIXA_ARMARIO 1
#define ID_CAIXA_CAMA 2
#define ID_BURACO 3
#define ID_DIARIO 4
#define ID_VITROLA 5
#define ID_GARRAFA 6
#define ID_ESTANTE 7
#define ID_MAPA 8
#define ID_PIRATA 9 
#define ID_VARA_PESCA 10
#define ID_CHAVE 11
#define ID_BILHETE 12

GameObject* gameplayObjects = NULL;
int gameplayObjectCount = 0;

GameObject* menuObjects = NULL;
int menuObjectCount = 0;

GameObject* endingObjects = NULL;
int endingObjectCount = 0;

//object in player's hand
GameObject* hand = NULL;

GameState state = MENU;

//funcions return the new current state, array of objects and background to be drawn

//process changes between 3 main game states (menu, gameplay and ending)
void processEvent(GameObject* clickedObject){
}

//process actions during menu screen
void processMenuEvent(GameObject* clickedObject){
}

//process actions during ending screen
void processEndingEvent(GameObject* clickedObject){
}

//process action between object in player's hand and object from background that was clicked
void processGameplayEvent(GameObject* utility, GameObject* target){

}

GameObject* GetgameplayObjects(void){
    return hand;
}

void InitializeState(){

}

GameObject* SetupGameplayObjects(void){
    // Define number of gameplayObjects
    objectCount = 8;
    gameplayObjects = (GameObject*)malloc(objectCount * sizeof(GameObject));
    
    if (gameplayObjects == NULL) {
        //printf("Failed to allocate memory for gameplayObjects\n");
        return;
    }
    
    // Initialize gameplayObjects with their properties
    gameplayObjects[ID_ARMARIO].name = "armario";
    gameplayObjects[ID_ARMARIO].id = ID_ARMARIO;
    gameplayObjects[ID_ARMARIO].texture = LoadTexture("assets/.png");
    gameplayObjects[ID_ARMARIO].position = (Vector2){50, 100};
    gameplayObjects[ID_ARMARIO].size = (Vector2){150, 120};
    gameplayObjects[ID_ARMARIO].bounds = (Rectangle){50, 100, 150, 120};

    gameplayObjects[ID_CAIXA_ARMARIO].name = "caixaArmario";
    gameplayObjects[ID_CAIXA_ARMARIO].id = ID_CAIXA_ARMARIO;    
    gameplayObjects[ID_CAIXA_ARMARIO].texture = LoadTexture("assets/.png");
    gameplayObjects[ID_CAIXA_ARMARIO].position = (Vector2){50, 100};
    gameplayObjects[ID_CAIXA_ARMARIO].size = (Vector2){150, 120};
    gameplayObjects[ID_CAIXA_ARMARIO].bounds = (Rectangle){50, 100, 150, 120};

    gameplayObjects[ID_CAIXA_CAMA].name = "caixaCama";
    gameplayObjects[ID_CAIXA_CAMA].id = ID_CAIXA_CAMA;
    gameplayObjects[ID_CAIXA_CAMA].texture = LoadTexture("assets/.png");
    gameplayObjects[ID_CAIXA_CAMA].position = (Vector2){50, 100};
    gameplayObjects[ID_CAIXA_CAMA].size = (Vector2){150, 120};
    gameplayObjects[ID_CAIXA_CAMA].bounds = (Rectangle){50, 100, 150, 120};

    gameplayObjects[ID_BURACO].name = "buraco";
    gameplayObjects[ID_BURACO].id = ID_BURACO;
    gameplayObjects[ID_BURACO].texture = LoadTexture("assets/.png");
    gameplayObjects[ID_BURACO].position = (Vector2){50, 100};
    gameplayObjects[ID_BURACO].size = (Vector2){150, 120};
    gameplayObjects[ID_BURACO].bounds = (Rectangle){50, 100, 150, 120};

    gameplayObjects[ID_DIARIO].name = "diario";
    gameplayObjects[ID_DIARIO].id = ID_DIARIO;
    gameplayObjects[ID_DIARIO].texture = LoadTexture("assets/.png");
    gameplayObjects[ID_DIARIO].position = (Vector2){50, 100};
    gameplayObjects[ID_DIARIO].size = (Vector2){150, 120};
    gameplayObjects[ID_DIARIO].bounds = (Rectangle){50, 100, 150, 120};

    gameplayObjects[ID_VITROLA].name = "vitrola";
    gameplayObjects[ID_VITROLA].id = ID_VITROLA;
    gameplayObjects[ID_VITROLA].texture = LoadTexture("assets/.png");
    gameplayObjects[ID_VITROLA].position = (Vector2){50, 100};
    gameplayObjects[ID_VITROLA].size = (Vector2){150, 120};
    gameplayObjects[ID_VITROLA].bounds = (Rectangle){50, 100, 150, 120};

    gameplayObjects[ID_GARRAFA].name = "garrafa";
    gameplayObjects[ID_GARRAFA].id = ID_GARRAFA;
    gameplayObjects[ID_GARRAFA].texture = LoadTexture("assets/.png");
    gameplayObjects[ID_GARRAFA].position = (Vector2){50, 100};
    gameplayObjects[ID_GARRAFA].size = (Vector2){150, 120};
    gameplayObjects[ID_GARRAFA].bounds = (Rectangle){50, 100, 150, 120};

    gameplayObjects[ID_ESTANTE].name = "estante";
    gameplayObjects[ID_ESTANTE].id = ID_ESTANTE;
    gameplayObjects[ID_ESTANTE].texture = LoadTexture("assets/.png");
    gameplayObjects[ID_ESTANTE].position = (Vector2){50, 100};
    gameplayObjects[ID_ESTANTE].size = (Vector2){150, 120};
    gameplayObjects[ID_ESTANTE].bounds = (Rectangle){50, 100, 150, 120};

    gameplayObjects[ID_MAPA].name = "mapa";
    gameplayObjects[ID_MAPA].id = ID_MAPA;
    gameplayObjects[ID_MAPA].texture = LoadTexture("assets/.png");
    gameplayObjects[ID_MAPA].position = (Vector2){50, 100};
    gameplayObjects[ID_MAPA].size = (Vector2){150, 120};
    gameplayObjects[ID_MAPA].bounds = (Rectangle){50, 100, 150, 120};

    gameplayObjects[ID_PIRATA].name = "pirata";
    gameplayObjects[ID_PIRATA].id = ID_PIRATA;
    gameplayObjects[ID_PIRATA].texture = LoadTexture("assets/.png");
    gameplayObjects[ID_PIRATA].position = (Vector2){50, 100};
    gameplayObjects[ID_PIRATA].size = (Vector2){150, 120};
    gameplayObjects[ID_PIRATA].bounds = (Rectangle){50, 100, 150, 120};       

    gameplayObjects[ID_VARA_PESCA].name = "varaPesca";
    gameplayObjects[ID_VARA_PESCA].id = ID_VARA_PESCA;
    gameplayObjects[ID_VARA_PESCA].texture = LoadTexture("assets/.png");
    gameplayObjects[ID_VARA_PESCA].position = (Vector2){50, 100};
    gameplayObjects[ID_VARA_PESCA].size = (Vector2){150, 120};
    gameplayObjects[ID_VARA_PESCA].bounds = (Rectangle){50, 100, 150, 120};     

    gameplayObjects[ID_CHAVE].name = "chave";
    gameplayObjects[ID_CHAVE].id = ID_CHAVE;
    gameplayObjects[ID_CHAVE].texture = LoadTexture("assets/.png");
    gameplayObjects[ID_CHAVE].position = (Vector2){50, 100};
    gameplayObjects[ID_CHAVE].size = (Vector2){150, 120};
    gameplayObjects[ID_CHAVE].bounds = (Rectangle){50, 100, 150, 120};   

    gameplayObjects[ID_BILHETE].name = "bilhete";
    gameplayObjects[ID_BILHETE].id = ID_BILHETE;
    gameplayObjects[ID_BILHETE].texture = LoadTexture("assets/.png");
    gameplayObjects[ID_BILHETE].position = (Vector2){50, 100};
    gameplayObjects[ID_BILHETE].size = (Vector2){150, 120};
    gameplayObjects[ID_BILHETE].bounds = (Rectangle){50, 100, 150, 120};         

    return gameplayObjects;
}