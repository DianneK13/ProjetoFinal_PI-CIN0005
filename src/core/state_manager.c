#include "core/state_manager.h"

#include "scenes/scenemenu.h"
#include "scenes/scenegameplay.h"
#include "scenes/sceneending.h"

GameState state = STATE_MENU;


void InitializeState() {
    InitializeMenuState();
    InitializeGameplayState();
    InitializeEndingState();
}

//funções atualizam o estado, o array de objetos e o fundo a ser desenhado no momento

void processEvent(GameObject* clickedObject) {
    switch(state) {
        case STATE_MENU:
            state = processMenuEvent(clickedObject);
            break;
        case STATE_GAMEPLAY:
            //state = processGameplayEvent(hand, clickedObject);
            break;
        case STATE_ENDING:
            //state = processEndingEvent(clickedObject);
            break;
    }
}

Texture2D GetBackground(void){
    Texture2D background;
    switch(state){
        case STATE_MENU:
            background = GetMenuBackground();
            background.height = SCREEN_HEIGHT;
            background.width = SCREEN_WIDTH;
            return background;
            break;
        case STATE_GAMEPLAY:
            background = GetGameplayBackground();
            background.height = SCREEN_HEIGHT;
            background.width = SCREEN_WIDTH;
            return background;
            break;
        case STATE_ENDING:
            //background = GetEndingBackground();
            background.height = SCREEN_HEIGHT;
            background.width = SCREEN_WIDTH;
            return background;
            break;
    }
}

GameObject* GetObjects(void){
    switch(state){
        case STATE_MENU:
            return GetMenuObjects();
            break;
        case STATE_GAMEPLAY:
            //return GetGameplayObjects();
            break;
        case STATE_ENDING:
            //return GetEndingObjects();
            break;
    }    
}

int GetObjectCount(void){
    switch(state){
        case STATE_MENU:
            return GetMenuObjectCount();
            break;
        case STATE_GAMEPLAY:
            //return GetGameplayObjectCount();
            break;
        case STATE_ENDING:
            //return GetEndingObjectCount();
            break;
    }   
}