#include "scenes/scenemenu.h"

//array de objects desta cena
GameObject* objects;
//qtd de objetos desta cena
int objectCount;

//imagem de fundo desta cena
Texture2D background;

//subestado do menu (menu principal, creditos)
MenuSubstate submenu;

void InitializeMenuState() {

    // numero de objetos
    // SEMPRE ATUALIZAR ESSE NUMERO CASO ADICIONE NOVO OBJETO
    objectCount = 2;
    objects = (GameObject*)malloc(objectCount * sizeof(GameObject));
    
    if (objects == NULL) {
        //printf("Failed to allocate memory for objects\n");
        return;
    }
    
    // Initialize objects with their properties
    objects[ID_MENU_BOTAO_START].name = "botao_start";
    objects[ID_MENU_BOTAO_START].id = ID_MENU_BOTAO_START;
    objects[ID_MENU_BOTAO_START].texture = LoadTexture("assets/.png");
    objects[ID_MENU_BOTAO_START].position = (Vector2){50, 100};
    objects[ID_MENU_BOTAO_START].size = (Vector2){150, 120};
    objects[ID_MENU_BOTAO_START].bounds = (Rectangle){50, 100, 150, 120};  
    objects[ID_MENU_BOTAO_START].state = ORIGINAL;
    objects[ID_MENU_BOTAO_START].type = INTERACTIVE;

    objects[ID_MENU_BOTAO_CREDITOS].name = "botao_creditos";
    objects[ID_MENU_BOTAO_CREDITOS].id = ID_MENU_BOTAO_CREDITOS;
    objects[ID_MENU_BOTAO_CREDITOS].texture = LoadTexture("assets/.png");
    objects[ID_MENU_BOTAO_CREDITOS].position = (Vector2){50, 100};
    objects[ID_MENU_BOTAO_CREDITOS].size = (Vector2){150, 120};
    objects[ID_MENU_BOTAO_CREDITOS].bounds = (Rectangle){50, 100, 150, 120};  
    objects[ID_MENU_BOTAO_CREDITOS].state = ORIGINAL;
    objects[ID_MENU_BOTAO_CREDITOS].type = INTERACTIVE;

    submenu = MENU_SUBSTATE_MAIN;

    return objects;
}


//processa ações do menu
GameState processMenuEvent(GameObject* clickedObject){
    switch(clickedObject->id){
        case ID_MENU_BOTAO_START:
            return processBotaoStartEvent(clickedObject);
            break;
        case ID_MENU_BOTAO_CREDITOS:
            return processBotaoCreditosEvent(clickedObject);
            break;
    }
    
    //enfim é esse esquema aí
    
}

GameState processBotaoStartEvent(GameObject* target) {
    return STATE_GAMEPLAY;
}

GameState processBotaoCreditosEvent(GameObject* target) {
    submenu = MENU_SUBSTATE_CREDITOS;
    return STATE_MENU;
}