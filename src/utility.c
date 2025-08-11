#include "utility.h"
#include <stdlib.h>

void UnloadTextureSafe(Texture2D *tex) {
    if (!tex) return;
    if (tex->id != 0) {
        UnloadTexture(*tex);
        tex->id = 0;          // evita double free
    }
}

void FreeObjects(GameObject **objects, int *count) {
    if (!objects || !*objects) { if (count) *count = 0; return; }

    const int n = count ? *count : 0;
    for (int i = 0; i < n; i++) {
        if ((*objects)[i].texture.id != 0) {
            UnloadTexture((*objects)[i].texture);
            (*objects)[i].texture.id = 0;
        }
    }
    free(*objects);
    *objects = NULL;
    if (count) *count = 0;
}

void FreeScene(GameScene *scene, bool freeBackground) {
    if (!scene) return;
    // objetos da cena
    if (scene->objects) {
        for (int i = 0; i < scene->objectCount; ++i) {
            if (scene->objects[i].texture.id != 0) {
                UnloadTexture(scene->objects[i].texture);
                scene->objects[i].texture.id = 0;
            }
        }
        free(scene->objects);
        scene->objects = NULL;
    }
    scene->objectCount = 0;

    if (freeBackground) {
        UnloadTextureSafe(&scene->background);
    }
}

void FreeAll(GameContext *ctx) {
    if (!ctx) return;
    FreeScene(&ctx->menu, true);
    FreeScene(&ctx->gameplay, true);
    FreeScene(&ctx->creditos, true);
    FreeScene(&ctx->ending, true);

    FreeScene(&ctx->bilhete, true);
    FreeScene(&ctx->caixa_armario, true);
    FreeScene(&ctx->diario, true);
    FreeScene(&ctx->estante, true);
    FreeScene(&ctx->garrafa, true);
    FreeScene(&ctx->pirata, true);
}
