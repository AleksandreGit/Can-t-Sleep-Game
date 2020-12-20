#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

unsigned int W_WIDTH(1080), W_HEIGHT(720), C_RADIUS(200);

int main()
{
    sf::RenderWindow window(sf::VideoMode(W_WIDTH, W_HEIGHT), "GameJam #1");
    window.setFramerateLimit(60);
    sf::CircleShape shape(C_RADIUS);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(W_WIDTH/2 - C_RADIUS, W_HEIGHT/2 - C_RADIUS);



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color(154, 240, 229, 1.0f));
        window.draw(shape);
        window.display();
    }

    return 0;
}