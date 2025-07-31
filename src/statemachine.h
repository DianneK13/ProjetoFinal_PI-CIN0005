#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum GameScreen {MENU, GAMEPLAY, ENDING} GameScreen;
typedef enum PuzzleObjectState {ORIGINAL, ALTERED} PuzzleObjectState;
typedef enum PuzzleObjectType {INTERACTIVE, COLECTABLE} PuzzleObjectType;
typedef enum StateEventStatus {STATE_CHANGED, STATE_UNCHANGED} StateEventStatus;

// Object structure
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

typedef struct StateEvent { 
  StateEventStatus status;
  char * message;

}StateEvent;

GameObject* objects;
int objectCount;

GameObject armario();
GameObject caixa1;
GameObject caixa2;
GameObject buraco;
GameObject diario;
GameObject vitrola;
GameObject garrafa;
GameObject estante;
GameObject mapa;
GameObject pirata;
GameObject varaPesca;
GameObject chave;
GameObject bilhete;
GameObject dente;

StateEvent processEvent(GameObject utility, GameObject target);

void CheckMouseHover(void);

GameObject* SetupObjects(void);