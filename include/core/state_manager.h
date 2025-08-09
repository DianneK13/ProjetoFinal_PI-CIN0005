#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"


GameContext InitializeState(GameContext context);

void processEvent(GameObject* object, GameContext);

Texture2D GetBackground(GameContext context);

GameObject* GetObjects(GameContext context);

int GetObjectCount(GameContext context);
