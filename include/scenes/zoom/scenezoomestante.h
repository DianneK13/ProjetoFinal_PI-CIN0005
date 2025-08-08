#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"


void InitializeZoomEstanteState();

GameplaySubstate processZoomEstanteEvent(GameObject* object);

GameObject* GetZoomEstanteBackground(void);

GameObject* GetZoomEstanteObjects(void);