#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

#define ID_ESTANTE_VOLTAR 0

GameContext InitializeZoomEstanteState(GameContext context);

GameplaySubstate processZoomEstanteEvent(GameObject* target, GameContext* context);

Texture2D GetZoomEstanteBackground(GameContext context);

GameObject* GetZoomEstanteObjects(GameContext context);

int GetZoomEstanteObjectCount(GameContext context);