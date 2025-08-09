#include "scenes/scenemenu.h"

//array de objects_menu desta cena
GameObject* objects_menu;
//qtd de objetos desta cena
int objectCount_menu;

//imagem de fundo desta cena
Texture2D background_menu;

//subestado do menu (menu principal, creditos)
MenuSubstate submenu;

GameContext InitializeMenuState(GameContext context) {

    // numero de objetos
    // SEMPRE ATUALIZAR ESSE NUMERO CASO ADICIONE NOVO OBJETO
    context.menu.objectCount = 2;
    context.menu.objects = (GameObject*)malloc(context.menu.objectCount * sizeof(GameObject));
    
    if (context.menu.objects == NULL) {
        //printf("Failed to allocate memory for objects\n");
        return;
    }
    
    // Initialize objects with their properties
    objects_menu[ID_MENU_BOTAO_START].name = "botao_start";
    objects_menu[ID_MENU_BOTAO_START].id = ID_MENU_BOTAO_START;
    objects_menu[ID_MENU_BOTAO_START].texture = LoadTexture("assets/jogar.png");
    objects_menu[ID_MENU_BOTAO_START].position = (Vector2){700, 300};
    objects_menu[ID_MENU_BOTAO_START].size = (Vector2){150, 120};
    objects_menu[ID_MENU_BOTAO_START].bounds = (Rectangle){700, 300, 150, 120};  
    objects_menu[ID_MENU_BOTAO_START].state = ORIGINAL;
    objects_menu[ID_MENU_BOTAO_START].type = INTERACTIVE;

    objects_menu[ID_MENU_BOTAO_CREDITOS].name = "botao_creditos";
    objects_menu[ID_MENU_BOTAO_CREDITOS].id = ID_MENU_BOTAO_CREDITOS;
    objects_menu[ID_MENU_BOTAO_CREDITOS].texture = LoadTexture("assets/creditosfodao.png");
    objects_menu[ID_MENU_BOTAO_CREDITOS].position = (Vector2){700, 100};
    objects_menu[ID_MENU_BOTAO_CREDITOS].size = (Vector2){150, 120};
    objects_menu[ID_MENU_BOTAO_CREDITOS].bounds = (Rectangle){700, 100, 150, 120};  
    objects_menu[ID_MENU_BOTAO_CREDITOS].state = ORIGINAL;
    objects_menu[ID_MENU_BOTAO_CREDITOS].type = INTERACTIVE;

    context.menu.objects[ID_MENU_BOTAO_START].texture.height = 120;
    context.menu.objects[ID_MENU_BOTAO_START].texture.width = 150;

    context.menu.objects[ID_MENU_BOTAO_CREDITOS].texture.height = 120;
    context.menu.objects[ID_MENU_BOTAO_CREDITOS].texture.width = 150;

    context.menu.background = LoadTexture("assets/menufodao.png");

    context.menu.substate = MENU_SUBSTATE_MAIN;
    return context;
}

Texture2D GetMenuBackground(GameContext context){
    return context.menu.background;
}

GameState processBotaoStartEvent(GameObject* target) {
    printf("trocou estado!!! \n");
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
            printf("process menu event \n");
            return processBotaoStartEvent(clickedObject);
            break;
        case ID_MENU_BOTAO_CREDITOS:
            return processBotaoCreditosEvent(clickedObject);
            break;
    }
    
    //enfim é esse esquema aí
    
}

GameObject* GetMenuObjects(GameContext context){
    return context.menu.objects;
}

int GetMenuObjectCount(GameContext context){
    return context.menu.objectCount;
}