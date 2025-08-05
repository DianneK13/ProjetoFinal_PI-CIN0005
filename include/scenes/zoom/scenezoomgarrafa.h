#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"


void InitializeZoomGarrafaState();

GameplaySubstate processZoomGarrafaEvent(GameObject* object);

GameObject* GetZoomGarrafaBackground(void);

GameObject* GetZoomGarrafaObjects(void);