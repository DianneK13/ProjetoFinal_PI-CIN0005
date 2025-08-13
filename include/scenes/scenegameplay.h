#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

#define ID_GAMEPLAY_ARMARIO        0
#define ID_GAMEPLAY_CAIXA_ARMARIO  1
#define ID_GAMEPLAY_CAIXA_CAMA     2
#define ID_GAMEPLAY_DIARIO         3
#define ID_GAMEPLAY_VITROLA        4
#define ID_GAMEPLAY_GARRAFA        5
#define ID_GAMEPLAY_ESTANTE        6
#define ID_GAMEPLAY_PIRATA         7
#define ID_GAMEPLAY_CHAVE          8
#define ID_GAMEPLAY_BILHETE        9

GameObject* GetHand(void);

GameContext InitializeGameplayState(GameContext context);

GameState processGameplayEvent(GameObject* utility, GameObject* target, GameContext *context);

Texture2D GetGameplayBackground(GameContext *context);

GameObject* GetGameplayObjects(GameContext *context);

int GetGameplayObjectCount(GameContext *context);
