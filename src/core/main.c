#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"

#include "core/state_manager.h"

// Global variables
//Texture2D background;
const char* hoveredObjectName = NULL;
Font gameFont;
GameObject* objects;

// Function prototypes
void LoadAssets(void);
//void UnloadAssets(void);
void DrawObjects(GameObject* objects, int objectCount);
void CheckMouseHover(GameObject* objects, int objectCount);
void DrawSubtitle(void);
void DrawCenteredText(const char* text, int y, Color color);

GameObject* GetClickedObject(GameObject* objects, int objectCount) {
    if (!objects || objectCount <= 0) return NULL;
    if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
        Vector2 mousePos = GetMousePosition();
        
        for (int i = 0; i < objectCount; i++) {
            if (CheckCollisionPointRec(mousePos, objects[i].bounds)) {
                return &objects[i];
            }
        }
    }
    return NULL;
}

int main(void) {
    GameContext context = {};
    // Initialize window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sagui Island");
    SetTargetFPS(60);
    
    // Load assets
    LoadAssets();
    
    // Setup objects
    context = InitializeState(context);

    // Main game loop
    while (!WindowShouldClose() && !context.should_close)
    {
        if (context.state == STATE_GAMEPLAY && context.flags[HISTORIA_INIT] == 0) {
            printf("comeco\n");
            context.flags[HISTORIA_INIT] = 1;
        }

        GameObject *objs = GetObjects(context);
        int count = GetObjectCount(context);

        // retornar objeto que o player clicar
        GameObject* go = GetClickedObject(GetObjects(context), GetObjectCount(context));

        if(go != NULL){
            printf("clicou no botao \n");
            context = processEvent(go, context);
            objs = GetObjects(context);
            count = GetObjectCount(context);
        }

        // Atualiza qual objeto está sob o mouse
        CheckMouseHover(GetObjects(context), GetObjectCount(context));

        // Draw
        BeginDrawing();
        
        ClearBackground(RAYWHITE);

        Texture2D bg = GetBackground(context);
        if (bg.id != 0) {
            // pega a imagem toda
            Rectangle sourceRec = (Rectangle){0, 0, bg.width, bg.height};
            // desenha ocupando a tela toda
            Rectangle destRec = (Rectangle){0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
            DrawTexturePro(bg, sourceRec, destRec, (Vector2){0, 0}, 0.0f, WHITE);
        }
        
        // Draw all objects
        if (objs && count > 0) DrawObjects(GetObjects(context), GetObjectCount(context));
        
        // Draw subtitle if hovering over object
        DrawSubtitle();
        
        EndDrawing();
    }
    
    // Cleanup
    //UnloadAssets();
    CloseWindow();
    
    return 0;
}

// ve se o mouse ta em cima de algum objeto
void CheckMouseHover(GameObject* objects, int objectCount)
{
    hoveredObjectName = NULL;
    if (!objects || objectCount <= 0) return;  // proteção

    Vector2 mousePos = GetMousePosition();
    for (int i = 0; i < objectCount; i++) {
        if (CheckCollisionPointRec(mousePos, objects[i].bounds)) {
            hoveredObjectName = objects[i].name;
            break;
        }
    }
}

void LoadAssets(void)
{
    // Load background
    //background = LoadTexture("assets/menu.png");
    
    // Load font for subtitles
    //gameFont = LoadFontEx("BOTAR FONTE", 24, NULL, 0);
    if (gameFont.texture.id == 0) {
        // Fallback to default font if custom font not found
        gameFont = GetFontDefault();
    }
}


/*
void UnloadAssets(GameObject* objects, int objectCount)
{
    // Unload background
    UnloadTexture("assets/botarfundo");
    
    // Unload object textures
    for (int i = 0; i < objectCount; i++) {
        UnloadTexture(objects[i].texture);
    }
    
    // Free objects array
    if (objects != NULL) {
        free(objects);
        objects = NULL;
    }
}
*/

void DrawObjects(GameObject* objects, int objectCount)
{
    // Vector2 const m = GetMousePosition(); //uncomment for debugging

    for (int i = 0; i < objectCount; i++) {
        // uncomment for debugging
        //bool isHovered = CheckCollisionPointRec(m, objects[i].bounds);
        // Draw object texture
        DrawTexturePro(
            objects[i].texture,
            (Rectangle){0, 0, objects[i].texture.width, objects[i].texture.height},
            (Rectangle){objects[i].position.x, objects[i].position.y, objects[i].size.x, objects[i].size.y},
            (Vector2){0, 0},
            0.0f,
            WHITE
        );
        
        // Debug: Draw bounds (uncomment for debugging)
        //if (isHovered) {
        //    DrawRectangleLinesEx(objects[i].bounds,2, YELLOW);
        //}
    }
}



//faz aparecer o nome do objeto quando passa o mouse por cima dele
void DrawSubtitle(void)
{
    if (hoveredObjectName != NULL) {
        DrawCenteredText(hoveredObjectName, SCREEN_HEIGHT - 80, BLACK);
    }
}

// pode ajeitar essa função aqui pra fazer os textos aparecerem
void DrawCenteredText(const char* text, const int y, const Color color)
{
    const int textWidth = MeasureText(text, 24);
    const int x = (SCREEN_WIDTH - textWidth) / 2;
    
    // Draw background rectangle for better readability
    DrawRectangle(x - 10, y - 5, textWidth + 20, 34, (Color){255, 255, 255, 200});
    DrawRectangleLines(x - 10, y - 5, textWidth + 20, 34, BLACK);
    
    DrawText(text, x, y, 24, color);
} 