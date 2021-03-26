#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "./../header/PerlinNoise.h"
#include <iostream>
#include <ctime>
#include "./../header/Game.h"


int main()
{
    Game game;
    srand(time(NULL));

    game.update();
    return 0;

}
