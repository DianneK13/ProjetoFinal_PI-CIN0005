#include "raylib.h"

typedef enum GameState {
    STATE_MENU, 
    STATE_GAMEPLAY, 
    STATE_ENDING
} GameState;

typedef enum GameplaySubstate {
    GAMEPLAY_SUBSTATE_MAIN,
    GAMEPLAY_SUBSTATE_ZOOM_CAIXA_ARMARIO,
    GAMEPLAY_SUBSTATE_ZOOM_CAIXA_CAMA,
    GAMEPLAY_SUBSTATE_ZOOM_GARRAFA, 
    GAMEPLAY_SUBSTATE_ZOOM_PIRATA,
    GAMEPLAY_SUBSTATE_ZOOM_BILHETE,
    GAMEPLAY_SUBSTATE_ZOOM_DIARIO,
    GAMEPLAY_SUBSTATE_ZOOM_ESTANTE
} GameplaySubstate;

typedef enum MenuSubstate { 
    MENU_SUBSTATE_MAIN, 
    MENU_SUBSTATE_CREDITOS
} MenuSubstate;

typedef enum GameObjectState { 
    ORIGINAL, 
    ALTERED 
} GameObjectState;

typedef enum GameObjectType { 
    INTERACTIVE,
    COLECTABLE
} GameObjectType;


// Object structure
// TUDO que der pra clicar no jogo é um GameObject
typedef struct GameObject{
    //atributos que podem mudar
    GameObjectState state;

    Texture2D texture;
    Rectangle bounds;
    Vector2 position;
    Vector2 size;

    //atributos estáticos
    GameObjectType type;
    int id;
    const char* name;

} GameObject;