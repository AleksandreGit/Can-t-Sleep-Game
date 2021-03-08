#include "./../header/Game.h"

const float Game::WORLD_UNIT = AnimableBuilder::DEFAULT_WIDTH;

Game::Game() : 
    m_window(sf::VideoMode(W_WIDTH, W_HEIGHT), "Can't Sleep"), 
    m_clock() 
{
    m_window.setFramerateLimit(60);
    m_playerView.setSize(TILE_WIDTH * 10, TILE_WIDTH * 10 * 9 / 16);
    m_window.setView(m_playerView);


    m_player = Player();
    m_map = Map();
}

void Game::draw() {
    m_window.clear(sf::Color(154, 240, 229, 1.0f));

    m_map.draw(m_window, m_player.getWorldPosition());
    m_player.draw(m_window);

    if (m_player.isInventoryOpen()) {
        m_player.drawInventory(m_window);
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
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::I) {
            m_player.toggleInventory();
            m_player.setState(IDLE);
        }
        else if (event.type == sf::Event::Resized) {
            // resize my view
            m_playerView.setSize({
                    static_cast<float>(TILE_WIDTH * 10),
                    static_cast<float>(TILE_WIDTH * 10 * event.size.height / event.size.width)
                });
            m_window.setView(m_playerView);
        }

        if (!m_player.isInventoryOpen()) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                m_player.setDirection(LEFT);
                m_player.setState(WALK);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                m_player.setDirection(RIGHT);
                m_player.setState(WALK);

            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
                m_player.setState(INTERACT);
                m_map.checkInteraction(m_player);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                m_player.useObject();
            }
            else {
                m_player.setState(IDLE);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
                m_player.changeFocusTool(0);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
                m_player.changeFocusTool(1);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
                m_player.changeFocusTool(2);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
                m_player.changeFocusTool(3);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
                m_player.changeFocusTool(4);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) {
                m_player.changeFocusTool(5);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) {
                m_player.changeFocusTool(6);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
                Item* dropedItem = m_player.dropCurrentItem();
                if (dropedItem){
                    m_map.dropItem(dropedItem, m_player.getWorldPosition());
                }
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

        // TODO: peut être mettre ça dans un update player ??
        // TODO: attention il risque d'y avoir surement un glitch si deux éléments ciblés en même temps !
        std::vector<EnvironmentElement*> elements = m_map.getCurrentElements(m_player.getWorldPosition());
        bool hasTarget = false;
        for (int i = 0; i < elements.size(); i++) {
            hasTarget = m_player.checkInteraction((*elements[i]));
            if (hasTarget) {
                break;
            }
        }
        if (!hasTarget) {
            m_player.setTarget(nullptr);
        }

        this->draw();
    }
}

void Game::handleCamera() {
    this->m_playerView.setCenter(m_player.getRealPosition(), -TILE_HEIGHT/2 );
    this->m_window.setView(m_playerView);

}