#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"


#define ID_MENU_BOTAO_START 0
#define ID_MENU_BOTAO_CREDITOS 1


GameContext InitializeMenuState(GameContext context);

GameState processMenuEvent(GameObject* object);

Texture2D GetMenuBackground(GameContext context);

GameObject* GetMenuObjects(GameContext context);

int GetMenuObjectCount(GameContext context);