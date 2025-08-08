#include "scenes/scenemenu.h"

//array de objects_menu desta cena
GameObject* objects_menu;
//qtd de objetos desta cena
int objectCount_menu;

//imagem de fundo desta cena
Texture2D background_menu;

//subestado do menu (menu principal, creditos)
MenuSubstate submenu;

void InitializeMenuState() {

    // numero de objetos
    // SEMPRE ATUALIZAR ESSE NUMERO CASO ADICIONE NOVO OBJETO
    objectCount_menu = 2;
    objects_menu = (GameObject*)malloc(objectCount_menu * sizeof(GameObject));
    
    if (objects_menu == NULL) {
        //printf("Failed to allocate memory for objects\n");
        return;
    }
    
    // Initialize objects with their properties
    objects_menu[ID_MENU_BOTAO_START].name = "botao_start";
    objects_menu[ID_MENU_BOTAO_START].id = ID_MENU_BOTAO_START;
    objects_menu[ID_MENU_BOTAO_START].texture = LoadTexture("assets/jogar.png");
    objects_menu[ID_MENU_BOTAO_START].position = (Vector2){700, 300};
    objects_menu[ID_MENU_BOTAO_START].size = (Vector2){150, 120};
    objects_menu[ID_MENU_BOTAO_START].bounds = (Rectangle){50, 100, 150, 120};  
    objects_menu[ID_MENU_BOTAO_START].state = ORIGINAL;
    objects_menu[ID_MENU_BOTAO_START].type = INTERACTIVE;

    objects_menu[ID_MENU_BOTAO_CREDITOS].name = "botao_creditos";
    objects_menu[ID_MENU_BOTAO_CREDITOS].id = ID_MENU_BOTAO_CREDITOS;
    objects_menu[ID_MENU_BOTAO_CREDITOS].texture = LoadTexture("assets/jogar.png");
    objects_menu[ID_MENU_BOTAO_CREDITOS].position = (Vector2){700, 100};
    objects_menu[ID_MENU_BOTAO_CREDITOS].size = (Vector2){150, 120};
    objects_menu[ID_MENU_BOTAO_CREDITOS].bounds = (Rectangle){50, 100, 150, 120};  
    objects_menu[ID_MENU_BOTAO_CREDITOS].state = ORIGINAL;
    objects_menu[ID_MENU_BOTAO_CREDITOS].type = INTERACTIVE;

    objects_menu[ID_MENU_BOTAO_START].texture.height = 120;
    objects_menu[ID_MENU_BOTAO_START].texture.width = 150;

    objects_menu[ID_MENU_BOTAO_CREDITOS].texture.height = 120;
    objects_menu[ID_MENU_BOTAO_CREDITOS].texture.width = 150;

    background_menu = LoadTexture("assets/menufodao.png");

    objectCount_menu = 2;

    submenu = MENU_SUBSTATE_MAIN;
}

Texture2D GetMenuBackground(){
    return background_menu;
}

GameState processBotaoStartEvent(GameObject* target) {
    return STATE_GAMEPLAY;
}

GameState processBotaoCreditosEvent(GameObject* target) {
    submenu = MENU_SUBSTATE_CREDITOS;
    return STATE_MENU;
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

GameObject* GetMenuObjects(void){
    return objects_menu;
}

int GetMenuObjectCount(void){
    return objectCount_menu;
}