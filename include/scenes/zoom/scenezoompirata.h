#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

#define ID_PIRATA_VOLTAR 0

GameContext InitializeZoomPirataState(GameContext context);

GameplaySubstate processZoomPirataEvent(GameObject* object);

Texture2D GetZoomPirataBackground(GameContext context);

GameObject* GetZoomPirataObjects(GameContext context);

int GetZoomPirataObjectCount(GameContext context);