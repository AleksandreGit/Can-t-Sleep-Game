#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include "Player.h"

unsigned int W_WIDTH(1080), W_HEIGHT(720), S_SIZE(200), SCALE_FACTOR(2);

int main()
{
    sf::RenderWindow window(sf::VideoMode(W_WIDTH, W_HEIGHT), "GameJam #1");
    window.setFramerateLimit(60);
    sf::Clock clock;
    Player player;

    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();
        sf::Event event;
        player.move(dt);
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Left) {
                    player.setDirection(LEFT);
                    player.setState(WALK);
                }
                if (event.key.code == sf::Keyboard::Right) {
                    player.setDirection(RIGHT);
                    player.setState(WALK);
                }
            }
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Right ||
                    event.key.code == sf::Keyboard::Left) {
                    player.setState(IDLE);
                }
            }
        }
        window.clear(sf::Color(154, 240, 229, 1.0f));
        player.draw(window);
        window.display();
    }

    return 0;
}