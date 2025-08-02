#include "state_manager.h"

#include "scenemenu.h"
#include "scenegameplay.h"
#include "sceneending.h"

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
            state = processGameplayEvent(clickedObject);
            break;
        case STATE_ENDING:
            state = processEndingEvent(clickedObject);
            break;
    }
}