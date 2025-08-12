//
// Created by mclar on 25/07/2025.
//

#ifndef UTILITY_H
#define UTILITY_H
#include "common.h"

void UnloadTextureSafe(Texture2D *tex);

void FreeObjects(GameObject **objects, int *count);

void FreeScene(GameScene *scene, bool freeBackground);

void FreeAll(GameContext *ctx);

#endif //UTILITY_H
