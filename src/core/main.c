#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

GameObject* GetClickedObject(GameObject* objects, int objectCount)
{
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

int main(void)
{
    GameContext context;
    // Initialize window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sagui Island");
    SetTargetFPS(60);
    
    // Load assets
    LoadAssets();
    
    // Setup objects
    context = InitializeState(context);

    // Main game loop
    while (!WindowShouldClose())
    {
        // retornar objeto que o player clicar
        GameObject* go = GetClickedObject(GetObjects(context), GetObjectCount(context));

        if(go != NULL){
            printf("clicou no botao \n");
            processEvent(go, context);
        } 
            
        // Draw
        BeginDrawing();
        
        ClearBackground(RAYWHITE);
        
        DrawTexture(GetBackground(context), 0, 0, WHITE);
        
        // Draw all objects
        DrawObjects(GetObjects(context), GetObjectCount(context));
        
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
    Vector2 mousePos = GetMousePosition();
    hoveredObjectName = NULL;
    
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
    gameFont = LoadFontEx("BOTAR FONTE", 24, NULL, 0);
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
    for (int i = 0; i < objectCount; i++) {
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
        // DrawRectangleRec(objects[i].bounds, (Color){255, 0, 0, 100});
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
void DrawCenteredText(const char* text, int y, Color color)
{
    int textWidth = MeasureText(text, 24);
    int x = (SCREEN_WIDTH - textWidth) / 2;
    
    // Draw background rectangle for better readability
    DrawRectangle(x - 10, y - 5, textWidth + 20, 34, (Color){255, 255, 255, 200});
    DrawRectangleLines(x - 10, y - 5, textWidth + 20, 34, BLACK);
    
    DrawText(text, x, y, 24, color);
} 