#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"


GameContext InitializeZoomCaixaCamaState(GameContext context);

GameplaySubstate processZoomCaixaCamaEvent(GameObject* object);

Texture2D GetZoomCaixaCamaBackground(GameContext context);

GameObject* GetZoomCaixaCamaObjects(GameContext context);

int GetZoomCaixaCamaObjectCount(GameContext context);