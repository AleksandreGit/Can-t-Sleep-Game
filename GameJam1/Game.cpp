#include "Game.h"

const float Game::WORLD_UNIT = AnimableBuilder::DEFAULT_WIDTH;

Game::Game() : 
    m_window(sf::VideoMode(W_WIDTH, W_HEIGHT), "GameJam #1"), 
    m_clock() 
{
    m_window.setFramerateLimit(60);
    m_playerView.setSize(TILE_WIDTH * 10, TILE_WIDTH * 10 * 9 / 16);
    m_window.setView(m_playerView);

    b2Vec2 gravity(0.0f, 0.0f);
    m_world = new b2World(gravity);

    m_player = Player(m_world);
    m_map = Map(m_world);
    if (!BoxTexture.loadFromFile("./Assets/bush.png")) {
        std::cout << "Pas bien chargé" << std::endl;
    }
}

void Game::draw() {
    m_window.clear(sf::Color(154, 240, 229, 1.0f));

    m_map.draw(m_window, m_player.getWorldPosition());
    m_player.draw(m_window);


    for (b2Body* BodyIterator = m_world->GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
    {
        if (BodyIterator->GetType() == b2_dynamicBody)
        {
            sf::RectangleShape rectangle(sf::Vector2f(TILE_WIDTH, 2*TILE_WIDTH));;
            rectangle.setFillColor(sf::Color(0, 255, 0, 120));
            std::cout << BodyIterator->GetPosition().y << std::endl;
            rectangle.setPosition(m_player.getRealPosition(), TILE_WIDTH * BodyIterator->GetPosition().y);
            m_window.draw(rectangle);
            /*sf::Sprite sprite;
           //sprite.setColor(sf::Color::Green);
            sprite.setTexture(BoxTexture);
            sprite.setOrigin(0, 0);
            sprite.setPosition(m_player.getRealPosition(), TILE_WIDTH * BodyIterator->GetPosition().y);
            //Sprite.setRotation(BodyIterator->GetAngle() * 180 / b2_pi);
            m_window.draw(sprite);*/
        }
    }
    m_window.display();

}

void Game::handleEvents(float deltaTime) {
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            m_window.close();
        }
        else if (event.type == sf::Event::Resized) {
            // resize my view
            m_playerView.setSize({
                    static_cast<float>(TILE_WIDTH * 10),
                    static_cast<float>(TILE_WIDTH * 10 * event.size.height / event.size.width)
                });
            m_window.setView(m_playerView);
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Q) {
                m_player.setDirection(LEFT);
                m_player.setState(WALK);
            }
            if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D) {
                m_player.setDirection(RIGHT);
                m_player.setState(WALK);
            }
            if (event.key.code == sf::Keyboard::E) {
                m_player.setState(INTERACT);
            }
            if (event.key.code == sf::Keyboard::A) {
                m_player.setState(ATTACK);
                m_player.attack();
            }
        }
        if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::Right ||
                event.key.code == sf::Keyboard::Left ||
                event.key.code == sf::Keyboard::Q ||
                event.key.code == sf::Keyboard::D) {
                m_player.setState(IDLE);
            }
        }
    }
}

void Game::update() {
    while (m_window.isOpen())
    {
        float dt = m_clock.restart().asSeconds();
        m_player.move(dt);

        this->handleEvents(dt);
        // TODO : checker collision et set la target ici ----> m_player.setTarget(this->m_map.checkCollisions(m_player));
        this->handleCamera();

        this->draw();
    }
}

void Game::handleCamera() {
    this->m_playerView.setCenter(m_player.getRealPosition(), -TILE_HEIGHT/2 );
    this->m_window.setView(m_playerView);

}