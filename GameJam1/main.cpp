#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include <ctime>
#include "Game.h"


int main()
{
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_real_distribution<float> distribution(-1.0, 1.0);
	std::uniform_real_distribution<float> seedRand(0, 9999999);

	for (int i = 0; i < 15; i++) {
		std::cout << distribution(generator) << std::endl;
	}
    /*Game game; 
    srand(time(NULL));

    game.update();*/

    return 0;
}