#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

// IDs dos botões
#define ID_MENU_BOTAO_START      0
#define ID_MENU_BOTAO_CREDITOS   1
#define ID_MENU_BOTAO_SAIR       2
#define ID_MENU_BOTAO_VOLTAR     3

GameContext InitializeMenuState(GameContext context);

GameState processMenuEvent(GameObject* object, GameContext context);

Texture2D GetMenuBackground(GameContext context);

GameObject* GetMenuObjects(GameContext context);

int GetMenuObjectCount(GameContext context);