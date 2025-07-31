#include "statemachine.h"

GameScreen screen = MENU;

GameObject* objects = NULL;
int objectCount = 0;

StateEvent processEvent(PuzzleObject utility, PuzzleObject target){
 // Update
        //----------------------------------------------------------------------------------
        switch(screen) 
        {
            case MENU:
            {
                // Update MENU screen data here!
                
                framesCounter++;
                
                // LESSON 03: Inputs management (keyboard, mouse)
                if (IsKeyPressed(KEY_ENTER)) screen = GAMEPLAY;
                
            } break;
            case GAMEPLAY:
            { 
                // Update GAMEPLAY screen data here!

                if (!gamePaused)
                {
                    // TODO: Gameplay logic
                }
                
                if (IsKeyPressed(KEY_ENTER)) screen = ENDING;

            } break;
            case ENDING: 
            {
                // Update END screen data here!
                
                framesCounter++;
                
                // LESSON 03: Inputs management (keyboard, mouse)
                if (IsKeyPressed(KEY_ENTER)) screen = MENU;

            } break;
            default: break;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        
            ClearBackground(RAYWHITE);
            
            switch(screen) 
            {
                case MENU:
                {
                    // TODO: Draw MENU screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
                    DrawText("MENU SCREEN", 20, 20, 40, DARKGREEN);
                    DrawText("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKGREEN);

                } break;
                case GAMEPLAY:
                {
                    // TODO: Draw GAMEPLAY screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight, PURPLE);
                    DrawText("GAMEPLAY SCREEN", 20, 20, 40, MAROON);
                    DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);

                } break;
                case ENDING:
                {
                    // TODO: Draw ENDING screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
                    DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
                    DrawText("PRESS ENTER or TAP to RETURN to MENU SCREEN", 120, 220, 20, DARKBLUE);

                } break;
                default: break;
            }
        
        EndDrawing();
        //----------------------------------------------------------------------------------
}

GameObject* SetupObjects(void)
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
    
    return objects;
}