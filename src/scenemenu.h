#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"


#define ID_MENU_BOTAO_START 0
#define ID_MENU_BOTAO_CREDITOS 1


void InitializeMenuState();

GameState processMenuEvent(GameObject* object);

GameObject* GetMenuBackground(void);

GameObject* GetMenuObjects(void);
int GetMenuObjectCount(void);