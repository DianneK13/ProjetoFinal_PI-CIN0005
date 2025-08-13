#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

#define ID_ESTANTE_VOLTAR 0
#define ID_ESTANTE_LETRA_1 1
#define ID_ESTANTE_LETRA_2 2
#define ID_ESTANTE_LETRA_3 3
#define ID_ESTANTE_LETRA_4 4
#define ID_ESTANTE_LETRA_5 5
#define ID_ESTANTE_LETRA_6 6
#define ID_ESTANTE_ESPACO_FALA 7

GameContext InitializeZoomEstanteState(GameContext context);

GameplaySubstate processZoomEstanteEvent(GameObject* target, GameContext* context, int* leuBilhete);

Texture2D GetZoomEstanteBackground(GameContext context);

GameObject* GetZoomEstanteObjects(GameContext context);

int GetZoomEstanteObjectCount(GameContext context);