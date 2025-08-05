#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"


void InitializeZoomDiarioState();

GameplaySubstate processZoomDiarioEvent(GameObject* object);

GameObject* GetZoomDiarioBackground(void);

GameObject* GetZoomDiarioObjects(void);