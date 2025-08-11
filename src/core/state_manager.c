#include "core/state_manager.h"

#include "scenes/scenemenu.h"
#include "scenes/scenegameplay.h"
#include "scenes/sceneending.h"
#include "scenes/zoom/scenezoombilhete.h"
#include "scenes/zoom/scenezoomcaixaarmario.h"
#include "scenes/zoom/scenezoomcaixacama.h"
#include "scenes/zoom/scenezoomdiario.h"
#include "scenes/zoom/scenezoomestante.h"
#include "scenes/zoom/scenezoomgarrafa.h"
#include "scenes/zoom/scenezoompirata.h"

GameContext InitializeState(GameContext context) {
    context.state = STATE_MENU;
    context = InitializeMenuState(context);
    context = InitializeGameplayState(context);
    context = InitializeZoomBilheteState(context);
    context = InitializeZoomCaixaArmarioState(context);
    context = InitializeZoomCaixaCamaState(context);
    context = InitializeZoomDiarioState(context);
    context = InitializeZoomEstanteState(context);
    context = InitializeZoomGarrafaState(context);
    context = InitializeZoomPirataState(context);
    context = InitializeEndingState(context);
    return context;
}

//funções atualizam o estado, o array de objetos e o fundo a ser desenhado no momento

GameContext processEvent(GameObject* clickedObject,GameContext context) {
    switch(context.state) {
        case STATE_MENU:
            context.state = processMenuEvent(clickedObject, &context);
            break;
        case STATE_GAMEPLAY:
            context.state = processGameplayEvent(GetHand(), clickedObject, &context);
            break;
        case STATE_ENDING:
            //state = processEndingEvent(clickedObject);
            break;
    }
    return context;
}

Texture2D GetBackground(GameContext context){
    Texture2D background = {};
    switch(context.state){
        case STATE_MENU:
            background = GetMenuBackground(context);
            background.height = SCREEN_HEIGHT;
            background.width = SCREEN_WIDTH;
            return background;
        case STATE_GAMEPLAY:
            //printf("foi buscar background gameplay\n");
            background = GetGameplayBackground(&context);
            background.height = SCREEN_HEIGHT;
            background.width = SCREEN_WIDTH;
            return background;
        case STATE_ENDING:
            //background = GetEndingBackground(context);
            break;
    }
    return background;
}

GameObject* GetObjects(GameContext context){
    switch(context.state){
        case STATE_MENU:
            return GetMenuObjects(context);
        case STATE_GAMEPLAY:
            return GetGameplayObjects(&context);
        case STATE_ENDING:
            //return GetEndingObjects(context);
            return NULL;
    }
    return NULL;
}

int GetObjectCount(GameContext context){
    switch(context.state){
        case STATE_MENU:
            return GetMenuObjectCount(context);
        case STATE_GAMEPLAY:
            return GetGameplayObjectCount(&context);
        case STATE_ENDING:
            //return GetEndingObjectCount(context);
            return 0;
    }
    return 0;
}