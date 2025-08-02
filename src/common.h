#include "raylib.h"

typedef enum GameState {STATE_MENU, STATE_GAMEPLAY, STATE_CREDITOS, STATE_ZOOM_CAIXA_ARMARIO, STATE_ZOOM_CAIXA_CAMA, STATE_ZOOM_GARRAFA, 
                        STATE_ZOOM_PIRATA, STATE_ZOOM_BILHETE, STATE_ZOOM_DIARIO, STATE_ZOOM_ESTANTE, STATE_ENDING} GameState;
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