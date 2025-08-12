#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

#define ID_CAIXA_ARMARIO_VOLTAR 0
#define ID_CAIXA_ARMARIO_SIMBOLO_1 1
#define ID_CAIXA_ARMARIO_SIMBOLO_2 2
#define ID_CAIXA_ARMARIO_SIMBOLO_3 3
#define ID_CAIXA_ARMARIO_SIMBOLO_4 4
#define ID_CAIXA_ARMARIO_BOTAO 5

GameContext InitializeZoomCaixaArmarioState(GameContext context);

GameplaySubstate processZoomCaixaArmarioEvent(GameObject* target, GameContext* context);

Texture2D GetZoomCaixaArmarioBackground(GameContext context);

GameObject* GetZoomCaixaArmarioObjects(GameContext context);

int GetZoomCaixaArmarioObjectCount(GameContext context);