#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"


GameContext InitializeZoomBilheteState(GameContext context);

GameplaySubstate processZoomBilheteEvent(GameObject* object);

Texture2D GetZoomBilheteBackground(GameContext context);

GameObject* GetZoomBilheteObjects(GameContext context);

int GetZoomBilheteObjectCount(GameContext context);