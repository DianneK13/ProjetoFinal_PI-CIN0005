#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "raylib.h"

#include "core/state_manager.h"
#include "core/common.h"

// Window dimensions
#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 800

// Global variables
Texture2D bedroomBackground;
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

int main(void)
{
    objects = SetupObjects();

    // Initialize window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sagui Island");
    SetTargetFPS(30);
    
    // Load assets
    LoadAssets();
    
    // Setup objects
    InitializeState();

    // Main game loop
    while (!WindowShouldClose())
    {
        // retornar objeto que o player clicar
        GameObject* go = GetClickedObject(GetObjects(), GetObjectCount());

        if(go != NULL) 
            processEvent(go);

        // Draw
        BeginDrawing();
        
        ClearBackground(RAYWHITE);
        
        DrawTexture(GetBackground(), 0, 0, WHITE);
        
        // Draw all objects
        DrawObjects(GetObjects(), GetObjectCount());
        
        // Draw subtitle if hovering over object
        DrawSubtitle();
        
        EndDrawing();
    }
    
    // Cleanup
    //UnloadAssets();
    CloseWindow();
    
    return 0;
}

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

void LoadAssets(void)
{
    // Load background
    bedroomBackground = LoadTexture("BOTAR IMAGEM DO JOGO");
    
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