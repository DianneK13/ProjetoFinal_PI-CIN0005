#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

#define ID_BILHETE_VOLTAR 0

GameContext InitializeZoomBilheteState(GameContext context);

GameplaySubstate processZoomBilheteEvent(GameObject* target, GameContext* context);

Texture2D GetZoomBilheteBackground(GameContext context);

GameObject* GetZoomBilheteObjects(GameContext context);

int GetZoomBilheteObjectCount(GameContext context);