#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

#define ID_CAIXA_CAMA_SIMBOLO_1 0
#define ID_CAIXA_CAMA_SIMBOLO_2 1
#define ID_CAIXA_CAMA_SIMBOLO_3 2
#define ID_CAIXA_CAMA_SIMBOLO_4 3
#define ID_CAIXA_CAMA_BOTAO 4

GameContext InitializeZoomCaixaCamaState(GameContext context);

GameplaySubstate processZoomCaixaCamaEvent(GameObject* object);

Texture2D GetZoomCaixaCamaBackground(GameContext context);

GameObject* GetZoomCaixaCamaObjects(GameContext context);

int GetZoomCaixaCamaObjectCount(GameContext context);