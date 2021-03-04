#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <box2d/box2d.h>
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
