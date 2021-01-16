#include "Game.h"

const float Game::WORLD_UNIT = AnimableBuilder::DEFAULT_WIDTH;

Game::Game() : 
    m_currentZoom(1.0f), 
    m_player(), 
    m_map(), 
    m_window(sf::VideoMode(W_WIDTH, W_HEIGHT), "GameJam #1"), 
    m_clock()
{
    m_window.setFramerateLimit(60);

    /*m_playerView = sf::View(sf::FloatRect(
        m_player.getPosition(),
        -Map::TILE_HEIGHT,
        Map::TILE_WIDTH * 14.13 ,
        Map::TILE_WIDTH * 10));*/
    std::cout << Map::TILE_WIDTH << std::endl;
    std::cout << Map::TILE_WIDTH * 9 / 16 << std::endl;
    m_playerView.setSize(Map::TILE_WIDTH * 10, Map::TILE_WIDTH * 10 * 9 / 16);
    m_window.setView(m_playerView);
}

void Game::draw() {
    m_window.clear(sf::Color(154, 240, 229, 1.0f));
    m_map.draw(m_window, 0, 0.0f);
    m_player.draw(m_window);
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
                    static_cast<float>(Map::TILE_WIDTH * 10),
                    static_cast<float>(Map::TILE_WIDTH * 10 * event.size.height / event.size.width)
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
            }
            if (event.key.code == sf::Keyboard::X) {
                m_currentZoom -= 0.01f;
                m_playerView.zoom(m_currentZoom);
                m_window.setView(m_playerView);
            }
            if (event.key.code == sf::Keyboard::W) {
                m_currentZoom += 0.01f;
                m_playerView.zoom(m_currentZoom);
                m_window.setView(m_playerView);
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
        this->handleCamera();

        this->draw();
    }
}

void Game::handleCamera() {
    this->m_playerView.setCenter(m_player.getPosition(), -Map::TILE_HEIGHT/2 );
    this->m_window.setView(m_playerView);

}