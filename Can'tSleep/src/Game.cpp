#include "./../header/Game.h"

const float Game::WORLD_UNIT = AnimableBuilder::DEFAULT_WIDTH;

Game::Game() : 
    m_window(sf::VideoMode(W_WIDTH, W_HEIGHT), "Can't Sleep"), 
    m_clock() 
{
    m_window.setFramerateLimit(60);
    m_playerView.setSize(TILE_WIDTH * 10, TILE_WIDTH * 10 * 9 / 16);
    m_window.setView(m_playerView);

    m_player = Player(200.0f);
    m_map = Map();
    CraftSystem test;
}

void Game::draw() {
    m_window.clear(sf::Color(154, 240, 229, 1.0f));

    m_map.draw(m_window, m_player.getWorldPosition());
    m_player.draw(m_window);
    m_craftSystem.draw(m_window, m_player.m_inventory);

    ConstructionItem* constructItem = dynamic_cast<ConstructionItem*>(m_player.m_inventory.getSelectedItem());
    if (constructItem) {
        constructItem->placingDraw(m_window, m_player.getWorldPosition(), m_map.getCurrentElements(m_player.getWorldPosition()), m_player.getDirection());
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
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::I && !m_craftSystem.isCraftOpen()) {
            m_player.toggleInventory();
            m_player.setState(IDLE);
        } 
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::C && !m_player.isInventoryOpen()) {
            m_craftSystem.toggleCraftMenu();
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
                m_player.m_inventory.getItemIndexWithPos(worldPos.x, worldPos.y, m_window);
                //std::cout << m_craftSystem.getItemNameWithPos(worldPos.x, worldPos.y, m_window) << std::endl;

            }
            else if (event.mouseButton.button == sf::Mouse::Right) {
                ConstructionItem* constructionItem = dynamic_cast<ConstructionItem*>(m_player.m_inventory.getSelectedItem());
                if (constructionItem) {
                    int position = constructionItem->getDrawingPos(m_player.getWorldPosition(), m_player.getDirection());
                    Constructible* constructible = constructionItem->getConstructible();
                    if (m_map.putDownConstructible(constructible, position)) {
                        constructible->setWorldPosition(position);
                        m_player.m_inventory.dropCurrentItem();
                    }

                }
            }
        }

        if (!m_player.isInventoryOpen() && !m_craftSystem.isCraftOpen()) {
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
                m_player.m_inventory.changeSelectedItem(0);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
                m_player.m_inventory.changeSelectedItem(1);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
                m_player.m_inventory.changeSelectedItem(2);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
                m_player.m_inventory.changeSelectedItem(3);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
                m_player.m_inventory.changeSelectedItem(4);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) {
                m_player.m_inventory.changeSelectedItem(5);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) {
                m_player.m_inventory.changeSelectedItem(6);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
                Item* dropedItem = m_player.m_inventory.dropCurrentItem();
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
                    int index = m_player.m_inventory.getItemIndexWithPos(worldPos.x, worldPos.y, m_window, false);
                    if (index < TOOLBAR_SIZE) {
                        Item* item = m_player.m_inventory.switchPosition(m_player.m_inventory.getLastClicked(), index);
                        if (item) {
                            m_map.dropItem(item, m_player.getWorldPosition());
                        }
                    }
                    else if(m_player.m_inventory.getLastClicked() != index){
                        Item* item = m_player.m_inventory.switchPosition(m_player.m_inventory.getLastClicked(), -1);
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
                    int index = m_player.m_inventory.getItemIndexWithPos(worldPos.x, worldPos.y, m_window, false);
                    Item* item = m_player.m_inventory.switchPosition(m_player.m_inventory.getLastClicked(), index);
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