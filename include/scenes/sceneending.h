#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

#define ID_ENDING_BOTAO_VOLTAR 0

GameContext InitializeEndingState(GameContext context);

GameState processEndingEvent(GameObject* clickedObject, GameContext *context);

Texture2D GetEndingBackground(GameContext context);

GameObject* GetEndingObjects(GameContext context);

int GetEndingObjectCount(GameContext context);
