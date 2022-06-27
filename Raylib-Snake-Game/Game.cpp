/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/


#include "Game.h"


static void InitGame(void);         // Initialize game
static void UpdateGame(void);       // Update game (one frame)
static void DrawGame(void);         // Draw game (one frame)
static void UnloadGame(void);       // Unload game
static void UpdateDrawFrame(void);  // Update and Draw (one frame)

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
   
    InitWindow(screenWidth, screenHeight, "Snekky Game");
    InitGame();

    SetTargetFPS(30);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
       // ComposeFrame();
        UpdateDrawFrame();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

void InitGame(void)
{
    brd.DrawFrame();
    

}

void UpdateGame(void)
{
    if (IsKeyPressed(KEY_UP)) {
        delta_loc = { 0,-1 };
    }
    else if (IsKeyPressed(KEY_DOWN)) {
        delta_loc = { 0,1 };
    }
    else if (IsKeyPressed(KEY_LEFT)) {
        delta_loc = { -1,0 };
    }
    else if (IsKeyPressed(KEY_RIGHT)) {
        delta_loc = { 1,0 };
    }

    const Location next = snek.GetNextHeadLocation(delta_loc);
    snek.Moveby(delta_loc);

}

void DrawGame(void)
{
    BeginDrawing();
    snek.Draw(brd);
    EndDrawing();

}

void UnloadGame(void)
{
    // does nothing as of now
}

void UpdateDrawFrame(void)
{
    UpdateGame();
    DrawGame();
}
