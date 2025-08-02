#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"


void InitializeState();

void processEvent(GameObject* object);

Texture2D GetBackground(void);

GameObject* GetObjects(void);

int GetObjectCount(void);
