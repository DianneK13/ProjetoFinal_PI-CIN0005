#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"


GameContext InitializeZoomGarrafaState(GameContext context);

GameplaySubstate processZoomGarrafaEvent(GameObject* object);

Texture2D GetZoomGarrafaBackground(GameContext context);

GameObject* GetZoomGarrafaObjects(GameContext context);

int GetZoomGarrafaObjectCount(GameContext context);