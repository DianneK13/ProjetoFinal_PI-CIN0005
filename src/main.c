#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Window dimensions
#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 800

// Object structure
typedef struct {
    const char* name;
    Texture2D texture;
    Rectangle bounds;
    Vector2 position;
    Vector2 size;
} GameObject;

// Global variables
GameObject* objects = NULL;
int objectCount = 0;
Texture2D bedroomBackground;
const char* hoveredObjectName = NULL;
Font gameFont;

// Function prototypes
void LoadAssets(void);
void UnloadAssets(void);
void SetupObjects(void);
void DrawObjects(void);
void CheckMouseHover(void);
void DrawSubtitle(void);
void DrawCenteredText(const char* text, int y, Color color);

int main(void)
{
    // Initialize window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Cheren - Bedroom Interactive Game");
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

void LoadAssets(void)
{
    // Load bedroom background
    bedroomBackground = LoadTexture("assets/bedroom.png");
    
    // Load font for subtitles
    gameFont = LoadFontEx("assets/font.ttf", 24, NULL, 0);
    if (gameFont.texture.id == 0) {
        // Fallback to default font if custom font not found
        gameFont = GetFontDefault();
    }
    
    printf("Assets loaded successfully\n");
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
    
    printf("Assets unloaded\n");
}

void SetupObjects(void)
{
    // Define number of objects
    objectCount = 8;
    objects = (GameObject*)malloc(objectCount * sizeof(GameObject));
    
    if (objects == NULL) {
        printf("Failed to allocate memory for objects\n");
        return;
    }
    
    // Initialize objects with their properties
    // Bed
    objects[0].name = "Bed";
    objects[0].texture = LoadTexture("assets/bed.png");
    objects[0].position = (Vector2){100, 400};
    objects[0].size = (Vector2){200, 150};
    objects[0].bounds = (Rectangle){100, 400, 200, 150};
    
    // Chair
    objects[1].name = "Chair";
    objects[1].texture = LoadTexture("assets/chair.png");
    objects[1].position = (Vector2){350, 500};
    objects[1].size = (Vector2){80, 100};
    objects[1].bounds = (Rectangle){350, 500, 80, 100};
    
    // Table
    objects[2].name = "Table";
    objects[2].texture = LoadTexture("assets/table.png");
    objects[2].position = (Vector2){500, 450};
    objects[2].size = (Vector2){120, 80};
    objects[2].bounds = (Rectangle){500, 450, 120, 80};
    
    // Pencil
    objects[3].name = "Pencil";
    objects[3].texture = LoadTexture("assets/pencil.png");
    objects[3].position = (Vector2){550, 480};
    objects[3].size = (Vector2){20, 10};
    objects[3].bounds = (Rectangle){550, 480, 20, 10};
    
    // Computer
    objects[4].name = "Computer";
    objects[4].texture = LoadTexture("assets/computer.png");
    objects[4].position = (Vector2){520, 420};
    objects[4].size = (Vector2){80, 60};
    objects[4].bounds = (Rectangle){520, 420, 80, 60};
    
    // Lamp
    objects[5].name = "Lamp";
    objects[5].texture = LoadTexture("assets/lamp.png");
    objects[5].position = (Vector2){800, 300};
    objects[5].size = (Vector2){60, 120};
    objects[5].bounds = (Rectangle){800, 300, 60, 120};
    
    // Bookshelf
    objects[6].name = "Bookshelf";
    objects[6].texture = LoadTexture("assets/bookshelf.png");
    objects[6].position = (Vector2){900, 200};
    objects[6].size = (Vector2){100, 200};
    objects[6].bounds = (Rectangle){900, 200, 100, 200};
    
    // Window
    objects[7].name = "Window";
    objects[7].texture = LoadTexture("assets/window.png");
    objects[7].position = (Vector2){50, 100};
    objects[7].size = (Vector2){150, 120};
    objects[7].bounds = (Rectangle){50, 100, 150, 120};
    
    printf("Objects setup completed\n");
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