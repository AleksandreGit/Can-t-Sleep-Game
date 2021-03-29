#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "./../header/PerlinNoise.h"
#include <iostream>
#include <ctime>
#include "./../header/Game.h"

// LIVE++
#include <accctrl.h>
#include "../../LivePP/API/LPP_API.h"


int main()
{
    //HMODULE livePP = lpp::lppLoadAndRegister(L"./../../../../../LivePP", "Quickstart");

    // enable Live++
    //lpp::lppEnableAllCallingModulesSync(livePP);

    // enable Live++'s exception handler/error recovery (optional)
    //lpp::lppInstallExceptionHandler(livePP);

    Game game;
    srand(time(NULL));

    game.update();
    return 0;

}
