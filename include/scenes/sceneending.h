#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"


GameContext InitializeEndingState();

GameState processEndingEvent(GameObject* object);

GameObject* GetEndingBackground(void);

GameObject* GetEndingObjects(void);
int GetEndingObjectCount(void);