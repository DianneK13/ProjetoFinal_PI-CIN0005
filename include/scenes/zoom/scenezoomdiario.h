#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"


GameContext InitializeZoomDiarioState(GameContext context);

GameplaySubstate processZoomDiarioEvent(GameObject* object);

Texture2D GetZoomDiarioBackground(GameContext context);

GameObject* GetZoomDiarioObjects(GameContext context);

int GetZoomDiarioObjectCount(GameContext context);