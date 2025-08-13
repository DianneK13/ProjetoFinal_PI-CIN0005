#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

#define ID_GAMEPLAY_ARMARIO          0
#define ID_GAMEPLAY_CAIXA_ARMARIO    1
#define ID_GAMEPLAY_CAIXA_CAMA       2
#define ID_GAMEPLAY_DIARIO           3
#define ID_GAMEPLAY_VITROLA          4
#define ID_GAMEPLAY_GARRAFA          5
#define ID_GAMEPLAY_ESTANTE          6
#define ID_GAMEPLAY_PIRATA           7
#define ID_GAMEPLAY_CHAVE            8
#define ID_GAMEPLAY_BILHETE          9
#define ID_GAMEPLAY_ESPACO_FALA      10
#define ID_HISTORIA_INICIAL_FALA_1   11
#define ID_HISTORIA_INICIAL_FALA_2   12
#define ID_HISTORIA_INICIAL_FALA_3   13
#define ID_VITROLA_FALA              14
#define ID_CAIXA_ARMARIO_FALA        15
#define ID_PEGOU_CHAVE_FALA          16
#define ID_CAIXA_CAMA_FALA           17
#define ID_DIARIO_SEM_CHAVE_FALA     18
#define ID_DIARIO_COM_CHAVE_FALA     19
#define ID_PIRATA_FALA               20
#define ID_GARRAFA_FALA              21
#define ID_BILHETE_FALA_1            22
#define ID_BILHETE_FALA_2            23
#define ID_BILHETE_FALA_3            24
#define ID_ESTANTE_FALA              25
#define ID_ESTANTE_POS_BILHETE_FALA  26
#define ID_FINAL_FALA_1              27
#define ID_FINAL_FALA_2              28
#define ID_FINAL_FALA_3              29
#define ID_FINAL_FALA_4              30
#define ID_FINAL_FALA_5              31
#define ID_FINAL_FALA_6              32
#define ID_FINAL_FALA_7              33

GameObject* GetHand(void);

GameContext InitializeGameplayState(GameContext context);

GameState processGameplayEvent(GameObject* utility, GameObject* target, GameContext *context);

Texture2D GetGameplayBackground(GameContext *context);

GameObject* GetGameplayObjects(GameContext *context);

int GetGameplayObjectCount(GameContext *context);
