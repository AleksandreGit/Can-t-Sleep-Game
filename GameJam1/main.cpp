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

    /*// Create Player
    sf::Texture playerTexture;

    if (!playerTexture.loadFromFile("./Assets/idle.png")) {
        std::cout << "Erreur de chargement de la texture du joueur !" << std::endl;
    }
    playerTexture.setSmooth(true);

    sf::Sprite playerSprite;
    playerSprite.setTexture(playerTexture);
    playerSprite.setTextureRect(sf::IntRect(0, 0, 128, 128)); // On ne prend seulement que la première texture
    playerSprite.setPosition(W_WIDTH / 2 - S_SIZE, W_HEIGHT / 2 - S_SIZE);
    playerSprite.setScale(SCALE_FACTOR, SCALE_FACTOR);*/
    Player player;

    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        player.animate(dt);
        window.clear(sf::Color(154, 240, 229, 1.0f));
        //window.draw(playerSprite);
        player.draw(window);
        window.display();
    }

    return 0;
}