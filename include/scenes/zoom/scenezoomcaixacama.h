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

#define ID_CAIXA_CAMA_1 6
#define ID_CAIXA_CAMA_2 7
#define ID_CAIXA_CAMA_3 8
#define ID_CAIXA_CAMA_4 9
#define ID_CAIXA_CAMA_5 10
#define ID_CAIXA_CAMA_6 11
#define ID_CAIXA_CAMA_7 12
#define ID_CAIXA_CAMA_8 13
#define ID_CAIXA_CAMA_9 14

#define ID_CAIXA_BILHETE 15
#define ID_CAIXA_CAMA_ESPACO_FALA 16

GameContext InitializeZoomCaixaCamaState(GameContext context);

GameplaySubstate processZoomCaixaCamaEvent(GameObject* target, GameContext* context, int* counterNumeros, int* leuBilhete);

Texture2D GetZoomCaixaCamaBackground(GameContext context);

GameObject* GetZoomCaixaCamaObjects(GameContext context);

int GetZoomCaixaCamaObjectCount(GameContext context);