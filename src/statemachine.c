#include "statemachine.h"

GameScreen screen = MENU;

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