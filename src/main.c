#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "raylib.h"
#include "statemachine.h"

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
void UnloadAssets(void);
void DrawObjects(void);
void CheckMouseHover(void);
void DrawSubtitle(void);
void DrawCenteredText(const char* text, int y, Color color);

int main(void)
{
    // Initialize window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sagui Island");
    SetTargetFPS(60);
    
    // Load assets
    LoadAssets();
    
    // Setup objects
    SetupObjects();

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        CheckMouseHover();

        // Draw
        BeginDrawing();
        
        ClearBackground(RAYWHITE);
        
        // Draw bedroom background
        DrawTexture(bedroomBackground, 0, 0, WHITE);
        
        // Draw all objects
        DrawObjects();
        
        // Draw subtitle if hovering over object
        DrawSubtitle();
        
        EndDrawing();
    }
    
    // Cleanup
    UnloadAssets();
    CloseWindow();
    
    return 0;
}

void CheckMouseHover(void)
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
    // Load bedroom background
    bedroomBackground = LoadTexture("BOTAR IMAGEM DO JOGO");
    
    // Load font for subtitles
    gameFont = LoadFontEx("BOTAR FONTE", 24, NULL, 0);
    if (gameFont.texture.id == 0) {
        // Fallback to default font if custom font not found
        gameFont = GetFontDefault();
    }
}

void UnloadAssets(void)
{
    // Unload bedroom background
    UnloadTexture(bedroomBackground);
    
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

void DrawObjects(void)
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

void CheckMouseHover(void)
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

void DrawSubtitle(void)
{
    if (hoveredObjectName != NULL) {
        DrawCenteredText(hoveredObjectName, SCREEN_HEIGHT - 80, BLACK);
    }
}

void DrawCenteredText(const char* text, int y, Color color)
{
    int textWidth = MeasureText(text, 24);
    int x = (SCREEN_WIDTH - textWidth) / 2;
    
    // Draw background rectangle for better readability
    DrawRectangle(x - 10, y - 5, textWidth + 20, 34, (Color){255, 255, 255, 200});
    DrawRectangleLines(x - 10, y - 5, textWidth + 20, 34, BLACK);
    
    // Draw text
    DrawText(text, x, y, 24, color);
} 