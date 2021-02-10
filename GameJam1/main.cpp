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
    /*
    const double SCALE = 30.0;

    //  Creating sfml window
    sf::RenderWindow window(sf::VideoMode(640, 640), "SFML works!");
    window.setFramerateLimit(60);

    // SFML Objects
    // Box
    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(100, 100));
    // Ground
    sf::RectangleShape Gshape;
    Gshape.setSize(sf::Vector2f(800, 100));
    Gshape.setFillColor(sf::Color::Green);

    //BOX2D
    // Create World
    b2Vec2 gravity(0.0, 20.f);
    b2World world(gravity);


    // Create a dynamic body
    b2BodyDef BodyDef;
    BodyDef.position = b2Vec2(100 / SCALE, 100 / SCALE);
    BodyDef.type = b2_dynamicBody;
    b2Body* boxBody = world.CreateBody(&BodyDef);

    b2PolygonShape Shape;
    Shape.SetAsBox((100.f / 2) / SCALE, (100.f / 2) / SCALE);
    b2FixtureDef FixtureDef;
    FixtureDef.density = 1.f;
    FixtureDef.shape = &Shape;
    boxBody->CreateFixture(&FixtureDef);


    // Create ground
    b2BodyDef gBodyDef;
    gBodyDef.position = b2Vec2(0 / SCALE, 600 / SCALE);
    gBodyDef.type = b2_staticBody;
    b2Body* gBody = world.CreateBody(&gBodyDef);

    b2PolygonShape gShape;
    gShape.SetAsBox((800 / 2) / SCALE, (100 / 2) / SCALE);
    b2FixtureDef gFixtureDef;
    gFixtureDef.density = 0.f;
    gFixtureDef.shape = &gShape;
    gBody->CreateFixture(&gFixtureDef);

    // Create another box
    b2BodyDef box;
    box.position = b2Vec2(300 / SCALE, 100 / SCALE);
    box.type = b2_dynamicBody;
    b2Body* boxBody2 = world.CreateBody(&box);
    b2PolygonShape boxShape;
    boxShape.SetAsBox((100.f / 2) / SCALE, (100.f / 2) / SCALE);
    b2FixtureDef boxFixture;
    boxFixture.density = 0.5f;
    boxFixture.shape = &boxShape;
    boxBody2->CreateFixture(&boxFixture);

    while (window.isOpen())
    {
        world.Step(1 / 60.f, 8, 3);
        window.clear();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        for (b2Body* BodyIterator = world.GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
        {
            if (BodyIterator->GetType() == b2_dynamicBody)
            {
                shape.setOrigin(50, 50);
                shape.setPosition(BodyIterator->GetPosition().x * 30, BodyIterator->GetPosition().y * 30);
                shape.setRotation(BodyIterator->GetAngle() * 180 / b2_pi);

                window.draw(shape);
            }
            else if (BodyIterator->GetType() == b2_staticBody)
            {
                Gshape.setOrigin(400, 50);
                Gshape.setPosition(BodyIterator->GetPosition().x * 30, BodyIterator->GetPosition().y * 30);
                Gshape.setRotation(BodyIterator->GetAngle() * 180 / b2_pi);

                window.draw(Gshape);
            }
        }
        window.display();
    }*/

    return 0;

}