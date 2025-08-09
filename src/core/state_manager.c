#include "core/state_manager.h"

#include "scenes/scenemenu.h"
#include "scenes/scenegameplay.h"
#include "scenes/sceneending.h"

GameContext InitializeState(GameContext context) {
    context.state = STATE_MENU;
    context = InitializeMenuState(context);
    context = InitializeGameplayState(context);
    context = InitializeEndingState(context);
    return context;
}

//funções atualizam o estado, o array de objetos e o fundo a ser desenhado no momento

GameContext processEvent(GameObject* clickedObject,GameContext context) {
    switch(context.state) {
        case STATE_MENU:
            context.state = processMenuEvent(clickedObject, context);
            break;
        case STATE_GAMEPLAY:
            context.state = processGameplayEvent(GetHand(), clickedObject, context);
            break;
        case STATE_ENDING:
            //state = processEndingEvent(clickedObject);
            break;
    }
    return context;
}

Texture2D GetBackground(GameContext context){
    Texture2D background;
    switch(context.state){
        case STATE_MENU:
            background = GetMenuBackground(context);
            background.height = SCREEN_HEIGHT;
            background.width = SCREEN_WIDTH;
            return background;
            break;
        case STATE_GAMEPLAY:
            //printf("foi buscar background gameplay\n");
            background = GetGameplayBackground(context);
            background.height = SCREEN_HEIGHT;
            background.width = SCREEN_WIDTH;
            return background;
            break;
        case STATE_ENDING:
            //background = GetEndingBackground(context);
            background.height = SCREEN_HEIGHT;
            background.width = SCREEN_WIDTH;
            return background;
            break;
    }
}

GameObject* GetObjects(GameContext context){
    switch(context.state){
        case STATE_MENU:
            return GetMenuObjects(context);
            break;
        case STATE_GAMEPLAY:
            return GetGameplayObjects(context);
            break;
        case STATE_ENDING:
            //return GetEndingObjects(context);
            break;
    }    
}

int GetObjectCount(GameContext context){
    switch(context.state){
        case STATE_MENU:
            return GetMenuObjectCount(context);
            break;
        case STATE_GAMEPLAY:
            return GetGameplayObjectCount(context);
            break;
        case STATE_ENDING:
            //return GetEndingObjectCount(context);
            break;
    }   
}