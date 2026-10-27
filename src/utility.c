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

// Várias cenas guardam cópias da mesma textura (ex.: as falas são copiadas para o objeto 10
// do gameplay e para as cenas de zoom), então guardamos os ids já liberados pra não liberar duas vezes.
// A lista é zerada no começo de FreeAll.
static unsigned int unloadedIds[512];
static int unloadedCount = 0;

static void UnloadTextureOnce(Texture2D *tex) {
    if (!tex || tex->id == 0) return;
    for (int i = 0; i < unloadedCount; i++) {
        if (unloadedIds[i] == tex->id) {
            tex->id = 0;
            return;
        }
    }
    if (unloadedCount < (int)(sizeof(unloadedIds) / sizeof(unloadedIds[0]))) {
        unloadedIds[unloadedCount++] = tex->id;
    }
    UnloadTexture(*tex);
    tex->id = 0;
}

void FreeScene(GameScene *scene, const bool freeBackground) {
    if (!scene) return;
    // objetos da cena
    if (scene->objects) {
        for (int i = 0; i < scene->objectCount; ++i) {
            UnloadTextureOnce(&scene->objects[i].texture);
        }
        free(scene->objects);
        scene->objects = NULL;
    }
    scene->objectCount = 0;

    if (freeBackground) {
        UnloadTextureOnce(&scene->background);
    }
}

void FreeAll(GameContext *ctx) {
    if (!ctx) return;
    unloadedCount = 0;
    FreeScene(&ctx->menu, true);
    FreeScene(&ctx->gameplay, true);
    FreeScene(&ctx->creditos, true);
    FreeScene(&ctx->ending, true);

    FreeScene(&ctx->bilhete, true);
    FreeScene(&ctx->caixa_armario, true);
    FreeScene(&ctx->caixa_cama, true);
    FreeScene(&ctx->diario, true);
    FreeScene(&ctx->estante, true);
    FreeScene(&ctx->garrafa, true);
    FreeScene(&ctx->pirata, true);
}
