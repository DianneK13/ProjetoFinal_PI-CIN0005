#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"


void InitializeZoomBilheteState();

GameplaySubstate processZoomBilheteEvent(GameObject* object);

GameObject* GetZoomBilheteBackground(void);

GameObject* GetZoomBilheteObjects(void);