#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

#define ID_DIARIO_VOLTAR 0
#define ID_DIARIO_ESPACO_FALA 1
// o livro faz parte do fundo do zoom, então é só uma área de clique invisível
#define ID_DIARIO_LIVRO 2

GameContext InitializeZoomDiarioState(GameContext context);

GameplaySubstate processZoomDiarioEvent(GameObject* target, GameContext* context);

Texture2D GetZoomDiarioBackground(GameContext context);

GameObject* GetZoomDiarioObjects(GameContext context);

int GetZoomDiarioObjectCount(GameContext context);
