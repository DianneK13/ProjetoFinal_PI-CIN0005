#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"


void InitializeZoomPirataState();

GameplaySubstate processZoomPirataEvent(GameObject* object);

GameObject* GetZoomPirataBackground(void);

GameObject* GetZoomPirataObjects(void);