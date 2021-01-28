#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "PerlinNoise.h"
#include <iostream>
#include <ctime>
#include "Game.h"


int main()
{
    PerlinNoise noise1(20.0f);

    for (float i = 0.0f; i < 40.0f; i+=0.1f) {
        std::cout << "Noise 1: " << noise1.noise1D(i) << std::endl;
    }

    /*Game game; 
    srand(time(NULL));

    game.update();*/

    return 0;
}