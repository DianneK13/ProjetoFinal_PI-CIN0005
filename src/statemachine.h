#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum GameState {MENU, GAMEPLAY, ENDING} GameState;
typedef enum PuzzleObjectState {ORIGINAL, ALTERED} PuzzleObjectState;
typedef enum PuzzleObjectType {INTERACTIVE, COLECTABLE} PuzzleObjectType;

// Object structure
// TUDO que der pra clicar no jogo é um GameObject
typedef struct GameObject{
    PuzzleObjectState state;
    PuzzleObjectType type;

    int id;
    const char* name;
    Texture2D texture;
    Rectangle bounds;
    Vector2 position;
    Vector2 size;
} GameObject;

GameObject* objects;
int objectCount;

void InitializeState();

void processEvent(GameObject* object);
void processMenuEvent(GameObject* clickedObject);
void processGameplayEvent(GameObject* utility, GameObject* target);
void processEndingEvent(GameObject* clickedObject);

GameObject* SetupObjects(void);

GameObject* GetObjectInHand(void);
