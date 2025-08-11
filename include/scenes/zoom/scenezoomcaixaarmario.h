#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

#define ID_CAIXA_ARMARIO_SIMBOLO_1 0
#define ID_CAIXA_ARMARIO_SIMBOLO_2 1
#define ID_CAIXA_ARMARIO_SIMBOLO_3 2
#define ID_CAIXA_ARMARIO_SIMBOLO_4 3
#define ID_CAIXA_ARMARIO_BOTAO 4

GameContext InitializeZoomCaixaArmarioState(GameContext context);

GameplaySubstate processZoomCaixaArmarioEvent(GameObject* object);

Texture2D GetZoomCaixaArmarioBackground(GameContext context);

GameObject* GetZoomCaixaArmarioObjects(GameContext context);

int GetZoomCaixaArmarioObjectCount(GameContext context);