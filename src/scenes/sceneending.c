#include "scenes/sceneending.h"
#include "sfx.h"

// tela de "obrigado por jogar", mostrada quando o jogador termina o puzzle da estante
GameContext InitializeEndingState(GameContext context) {
    context.ending.objectCount = 1;
    context.ending.objects = malloc(context.ending.objectCount * sizeof(GameObject));

    context.ending.objects[ID_ENDING_BOTAO_VOLTAR] = (GameObject) {
        .name="voltar ao menu", .id=ID_ENDING_BOTAO_VOLTAR, .type=INTERACTIVE, .state=ORIGINAL,
        .texture=LoadTexture("assets/images/ui/voltarSubstates.png"),
        .position=(Vector2){0, 0}, .size=(Vector2){SCREEN_WIDTH, SCREEN_HEIGHT},
        .bounds=(Rectangle){5, 7, 71, 73}
    };

    context.ending.background = LoadTexture("assets/images/ending/ending_background.png");
    return context;
}

//processa ações da tela de final do jogo
GameState processEndingEvent(GameObject* clickedObject, GameContext *context) {
    if (!clickedObject) return STATE_ENDING;

    switch (clickedObject->id) {
        case ID_ENDING_BOTAO_VOLTAR:
            PlaySFX(SFX_BOTAO);
            return STATE_MENU;
        default:
            return STATE_ENDING;
    }
}

Texture2D GetEndingBackground(GameContext context) {
    return context.ending.background;
}

GameObject* GetEndingObjects(GameContext context) {
    return context.ending.objects;
}

int GetEndingObjectCount(GameContext context) {
    return context.ending.objectCount;
}
