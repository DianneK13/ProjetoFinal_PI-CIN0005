#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

#define ID_CAIXA_CAMA_VOLTAR 0
#define ID_CAIXA_CAMA_SIMBOLO_1 1
#define ID_CAIXA_CAMA_SIMBOLO_2 2
#define ID_CAIXA_CAMA_SIMBOLO_3 3
#define ID_CAIXA_CAMA_SIMBOLO_4 4
#define ID_CAIXA_CAMA_BOTAO 5

GameContext InitializeZoomCaixaCamaState(GameContext context);

GameplaySubstate processZoomCaixaCamaEvent(GameObject* target, GameContext* context);

Texture2D GetZoomCaixaCamaBackground(GameContext context);

GameObject* GetZoomCaixaCamaObjects(GameContext context);

int GetZoomCaixaCamaObjectCount(GameContext context);