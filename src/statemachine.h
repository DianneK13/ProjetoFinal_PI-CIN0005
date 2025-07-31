#include "raylib.h"

typedef enum GameScreen {MENU, GAMEPLAY, ENDING} GameScreen;
typedef enum PuzzleObjectState {ORIGINAL, ALTERED} PuzzleObjectState;
typedef enum PuzzleObjectType {INTERACTIVE, COLECTABLE} PuzzleObjectType;
typedef enum StateEventStatus {STATE_CHANGED, STATE_UNCHANGED} StateEventStatus;

typedef struct PuzzleObject{
  PuzzleObjectState state;
  PuzzleObjectType type;

  const char* name;
  Texture2D image;
  Rectangle bounds;
  Vector2 position;
  Vector2 size;

}PuzzleObject;

typedef struct StateEvent { 
  StateEventStatus status;
  char * message;

}StateEvent;

PuzzleObject armario();
PuzzleObject caixa1;
PuzzleObject caixa2;
PuzzleObject buraco;
PuzzleObject diario;
PuzzleObject vitrola;
PuzzleObject garrafa;
PuzzleObject estante;
PuzzleObject mapa;
PuzzleObject pirata;
PuzzleObject varaPesca;
PuzzleObject chave;
PuzzleObject bilhete;
PuzzleObject dente;

StateEvent processEvent(PuzzleObject utility, PuzzleObject target);

void CheckMouseHover(void);