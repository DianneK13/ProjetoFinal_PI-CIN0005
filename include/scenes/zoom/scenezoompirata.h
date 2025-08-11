#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"


GameContext InitializeZoomPirataState(GameContext context);

GameplaySubstate processZoomPirataEvent(GameObject* object);

Texture2D GetZoomPirataBackground(GameContext context);

GameObject* GetZoomPirataObjects(GameContext context);

int GetZoomPirataObjectCount(GameContext context);