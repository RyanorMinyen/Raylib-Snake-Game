
#include "Game.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 600;

    Game game = { screenWidth, screenHeight, "Raylib Snek" };
   
    while (!game.GameShouldClose()) {
        game.Tick();
    }
    

    return 0;
}
