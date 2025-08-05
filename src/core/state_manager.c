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
            state = processGameplayEvent(hand, clickedObject);
            break;
        case STATE_ENDING:
            state = processEndingEvent(clickedObject);
            break;
    }
}

Texture2D GetBackground(void){

}

GameObject* GetObjects(void){

}

int GetObjectCount(void){

}