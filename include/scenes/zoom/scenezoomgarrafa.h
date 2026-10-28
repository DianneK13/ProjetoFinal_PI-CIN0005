#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

#define ID_GARRAFA_VOLTAR 0
#define ID_GARRAFA_ESPACO_FALA 1
// a garrafa faz parte do fundo do zoom, então são só áreas de clique invisíveis
#define ID_GARRAFA_GARGALO 2
#define ID_GARRAFA_CORPO 3

GameContext InitializeZoomGarrafaState(GameContext context);

GameplaySubstate processZoomGarrafaEvent(GameObject* target, GameContext* context);

Texture2D GetZoomGarrafaBackground(GameContext context);

GameObject* GetZoomGarrafaObjects(GameContext context);

int GetZoomGarrafaObjectCount(GameContext context);
