#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"


void InitializeZoomCaixaArmarioState();

GameplaySubstate processZoomCaixaArmarioEvent(GameObject* object);

GameObject* GetZoomCaixaArmarioBackground(void);

GameObject* GetZoomCaixaArmarioObjects(void);