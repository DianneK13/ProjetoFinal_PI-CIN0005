#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

#define ID_GAMEPLAY_ARMARIO 0
#define ID_GAMEPLAY_CAIXA_ARMARIO 1
#define ID_GAMEPLAY_CAIXA_CAMA 2
#define ID_GAMEPLAY_BURACO 3
#define ID_GAMEPLAY_DIARIO 4
#define ID_GAMEPLAY_VITROLA 5
#define ID_GAMEPLAY_GARRAFA 6
#define ID_GAMEPLAY_ESTANTE 7
#define ID_GAMEPLAY_PIRATA 8
#define ID_GAMEPLAY_VARA_PESCA 9
#define ID_GAMEPLAY_CHAVE 10
#define ID_GAMEPLAY_BILHETE 11

//object in player's hand
extern GameObject* hand;

void InitializeGameplayState();

GameState processGameplayEvent(GameObject* utility, GameObject* target);

GameObject* GetGameplayBackground(void);

GameObject* GetGameplayObjects(void);

int GetGameplayObjectCount(void);