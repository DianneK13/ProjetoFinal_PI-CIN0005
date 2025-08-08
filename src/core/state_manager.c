#include "core/state_manager.h"

#include "scenes/scenemenu.h"
#include "scenes/scenegameplay.h"
#include "scenes/sceneending.h"

GameState state = STATE_MENU;


GameContext InitializeState(GameContext context) {
    context = InitializeMenuState(context);
    context = InitializeGameplayState(context);
    context = InitializeEndingState(context);
    return context;
}

//funções atualizam o estado, o array de objetos e o fundo a ser desenhado no momento

void processEvent(GameObject* clickedObject,GameContext context) {
    switch(state) {
        case STATE_MENU:
            state = processMenuEvent(clickedObject);
            break;
        case STATE_GAMEPLAY:
            state = processGameplayEvent(hand, clickedObject, context);
            break;
        case STATE_ENDING:
            //state = processEndingEvent(clickedObject);
            break;
    }
}

Texture2D GetBackground(GameContext context){
    Texture2D background;
    switch(state){
        case STATE_MENU:
            background = GetMenuBackground(context);
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

GameObject* GetObjects(GameContext context){
    switch(state){
        case STATE_MENU:
            return GetMenuObjects(context);
            break;
        case STATE_GAMEPLAY:
            //return GetGameplayObjects();
            break;
        case STATE_ENDING:
            //return GetEndingObjects();
            break;
    }    
}

int GetObjectCount(GameContext context){
    switch(state){
        case STATE_MENU:
            return GetMenuObjectCount(context);
            break;
        case STATE_GAMEPLAY:
            //return GetGameplayObjectCount();
            break;
        case STATE_ENDING:
            //return GetEndingObjectCount();
            break;
    }   
}