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
    ConstructionItem* constructItem = dynamic_cast<ConstructionItem*>(m_player.getCurrentItem());
    if (constructItem) {
        constructItem->placingDraw(m_window, m_player.getWorldPosition() + 1, m_map);
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

        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i position = sf::Mouse::getPosition(m_window);
                sf::Vector2f worldPos = m_window.mapPixelToCoords(position);
                m_player.getItemIndexWithPos(worldPos.x, worldPos.y, m_window);
            }
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
                // TODO: make the check interaction after a little load time
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
            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i position = sf::Mouse::getPosition(m_window);
                    // Convert coordinates to the view coordinates
                    sf::Vector2f worldPos = m_window.mapPixelToCoords(position);
                    int index = m_player.getItemIndexWithPos(worldPos.x, worldPos.y, m_window, false);
                    if (index < TOOLBAR_SIZE) {
                        Item* item = m_player.switchInventoryElements(m_player.getLastClicked(), index);
                        if (item) {
                            m_map.dropItem(item, m_player.getWorldPosition());
                        }
                    }
                    else if(m_player.getLastClicked() != index){
                        Item* item = m_player.switchInventoryElements(m_player.getLastClicked(), -1);
                        if (item) {
                            m_map.dropItem(item, m_player.getWorldPosition());
                        }
                    }
                }

            }
        }
        else {
            if (event.type == sf::Event::MouseButtonReleased){
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i position = sf::Mouse::getPosition(m_window);
                    // Convert coordinates to the view coordinates
                    sf::Vector2f worldPos = m_window.mapPixelToCoords(position);
                    int index = m_player.getItemIndexWithPos(worldPos.x, worldPos.y, m_window, false);
                    Item* item = m_player.switchInventoryElements(m_player.getLastClicked(), index);
                    if (item) {
                        m_map.dropItem(item, m_player.getWorldPosition());
                    }
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