#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"


GameContext InitializeZoomEstanteState(GameContext context);

GameplaySubstate processZoomEstanteEvent(GameObject* object);

Texture2D GetZoomEstanteBackground(GameContext context);

GameObject* GetZoomEstanteObjects(GameContext context);

int GetZoomEstanteObjectCount(GameContext context);