#include "raylib.h"

typedef enum GameScreen { MENU, GAMEPLAY, ENDING } GameScreen;

// TODO: Define required structs

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 720;
    const int screenHeight = 450;

    // LESSON 01: Window initialization and screens management
    InitWindow(screenWidth, screenHeight, "Sagui Island");
    
    // NOTE: Load resources (textures, fonts, audio) after Window initialization

    // Game required variables
    GameScreen screen = MENU;
    
    int framesCounter = 0;          // General pourpose frames counter
    int gameResult = -1;            // Game result: 0 - Loose, 1 - Win, -1 - Not defined
    bool gamePaused = false;        // Game paused state toggle
    
    // TODO: Define and Initialize game variables
        
    SetTargetFPS(60);               // Set desired framerate (frames per second)
    //--------------------------------------------------------------------------------------
    
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
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

    // De-Initialization
    //--------------------------------------------------------------------------------------
    
    // NOTE: Unload any loaded resources (texture, fonts, audio)

    CloseWindow();              
    //--------------------------------------------------------------------------------------
    
    return 0;
}