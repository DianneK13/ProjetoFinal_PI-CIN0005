#include "scenes/zoom/scenezoomdiario.h"
#include "sfx.h"

#include "raylib.h"

GameContext InitializeZoomDiarioState(GameContext context) {
    context.diario.objectCount = 3;
    context.diario.objects = (GameObject*)malloc(context.diario.objectCount * sizeof(GameObject));

    context.diario.objects[ID_DIARIO_VOLTAR].name = "voltar";
    context.diario.objects[ID_DIARIO_VOLTAR].id = ID_DIARIO_VOLTAR;
    context.diario.objects[ID_DIARIO_VOLTAR].texture = LoadTexture("assets/images/ui/voltarSubstates.png");
    context.diario.objects[ID_DIARIO_VOLTAR].position = (Vector2){0, 0};
    context.diario.objects[ID_DIARIO_VOLTAR].size = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
    context.diario.objects[ID_DIARIO_VOLTAR].bounds = (Rectangle){5, 7, 71, 73};
    context.diario.objects[ID_DIARIO_VOLTAR].state = ORIGINAL;
    context.diario.objects[ID_DIARIO_VOLTAR].type = INTERACTIVE;

    context.diario.objects[ID_DIARIO_ESPACO_FALA].name = "continuar";
    context.diario.objects[ID_DIARIO_ESPACO_FALA].id = ID_DIARIO_ESPACO_FALA;
    context.diario.objects[ID_DIARIO_ESPACO_FALA].texture = LoadTexture("assets/.png");
    context.diario.objects[ID_DIARIO_ESPACO_FALA].position = (Vector2){0, 0};
    context.diario.objects[ID_DIARIO_ESPACO_FALA].size = (Vector2){0, 0};
    context.diario.objects[ID_DIARIO_ESPACO_FALA].bounds = (Rectangle){0, 0, 0, 0};
    context.diario.objects[ID_DIARIO_ESPACO_FALA].state = ORIGINAL;
    context.diario.objects[ID_DIARIO_ESPACO_FALA].type = INTERACTIVE;

    // Área do livro aberto, medida em ZoomDiario.png (1200x800). Fica depois da caixa de fala
    // no array, então enquanto o diálogo estiver aberto o clique vai pra ele.
    context.diario.objects[ID_DIARIO_LIVRO] = (GameObject){
        .name="diario", .id=ID_DIARIO_LIVRO, .type=INTERACTIVE, .state=ORIGINAL,
        .texture=(Texture2D){0},
        .position=(Vector2){0, 0}, .size=(Vector2){0, 0},
        .bounds=(Rectangle){80, 16, 1032, 768}
    };

    context.diario.background = LoadTexture("assets/images/zoom/diario/ZoomDiario.png");
    return context;
}

GameplaySubstate processZoomDiarioEvent(GameObject* target, GameContext* context) {
    switch(target->id) {
        case ID_DIARIO_VOLTAR:
            return GAMEPLAY_SUBSTATE_MAIN;

        case ID_DIARIO_LIVRO:
            PlaySFX(SFX_LIVRO);
            return GAMEPLAY_SUBSTATE_ZOOM_DIARIO;

        case ID_DIARIO_ESPACO_FALA:
            target->size = (Vector2){0, 0};
            target->bounds = (Rectangle){0, 0, 0, 0};
            return GAMEPLAY_SUBSTATE_ZOOM_DIARIO;

        default:
            return GAMEPLAY_SUBSTATE_ZOOM_DIARIO;
    }
}

Texture2D GetZoomDiarioBackground(GameContext context) {
    return context.diario.background;
}

GameObject* GetZoomDiarioObjects(GameContext context) {
    return context.diario.objects;
}

int GetZoomDiarioObjectCount(GameContext context) {
    return context.diario.objectCount;
}
