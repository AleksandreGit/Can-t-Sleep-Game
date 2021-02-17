#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <box2d/box2d.h>
#include "PerlinNoise.h"
#include <iostream>
#include <ctime>
#include "Game.h"


int main()
{
    Game game;
    srand(time(NULL));

    game.update();
    // Make a window that is 800 by 200 pixels
    // And has the title "Hello from SFML"
    /*sf::RenderWindow window(sf::VideoMode(800, 600), "Hello from SFML");


    // This "while" loop goes round and round- perhaps forever
    while (window.isOpen())
    {
        // The next 6 lines of code detect if the window is closed
        // And then shuts down the program
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                // Someone closed the window- bye
                window.close();
        }

        // Clear everything from the last run of the while loop
        window.clear();

        // Draw our message
        sf::RectangleShape rectangle(sf::Vector2f(100.0f, 100.0f));;
        rectangle.setFillColor(sf::Color(0, 255, 0, 120));
        rectangle.setPosition(10, 30);
        window.draw(rectangle);

        // Show everything we just drew
        window.display();
    }// This is the end of the "while" loop
    */
    return 0;

}
