#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

#define ID_PIRATA_VOLTAR 0
#define ID_PIRATA_ESPACO_FALA 1

GameContext InitializeZoomPirataState(GameContext context);

GameplaySubstate processZoomPirataEvent(GameObject* target, GameContext* context);

Texture2D GetZoomPirataBackground(GameContext context);

GameObject* GetZoomPirataObjects(GameContext context);

int GetZoomPirataObjectCount(GameContext context);