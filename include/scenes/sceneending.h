#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"


void InitializeEndingState();

GameState processEndingEvent(GameObject* object);

GameObject* GetEndingBackground(void);

GameObject* GetEndingObjects(void);
int GetEndingObjectCount(void);