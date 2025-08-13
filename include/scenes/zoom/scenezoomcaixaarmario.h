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

#define ID_CAIXA_ARMARIO_ANCORA 6
#define ID_CAIXA_ARMARIO_CIFRAO 7
#define ID_CAIXA_ARMARIO_ESPADA 8
#define ID_CAIXA_ARMARIO_GANCHO 9
#define ID_CAIXA_ARMARIO_LULA 10
#define ID_CAIXA_ARMARIO_ROSA 11
#define ID_CAIXA_ARMARIO_TUBARAO 12
#define ID_CAIXA_ARMARIO_X 13
#define ID_CAIXA_ARMARIO_ESPACO_FALA 14

GameContext InitializeZoomCaixaArmarioState(GameContext context);

GameplaySubstate processZoomCaixaArmarioEvent(GameObject* target, GameContext* context, int* counterSimbolos, int* temChave);

Texture2D GetZoomCaixaArmarioBackground(GameContext context);

GameObject* GetZoomCaixaArmarioObjects(GameContext context);

int GetZoomCaixaArmarioObjectCount(GameContext context);