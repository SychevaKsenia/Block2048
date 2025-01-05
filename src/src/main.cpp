#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "../headers/board.hpp"
#include "../headers/block.hpp"
#include "../headers/constants.hpp"
#include <iostream>
using namespace sf;

int main()
{
    sf::RenderWindow window({WINDOW_WEIGHT, WINDOW_HEIGHT}, "Block2028");
    // window.setFramerateLimit(144);

    Board *board = new Board();

    sf::Texture block_texture;
    block_texture.loadFromFile("source/cat1.jpg");
    Block *block = new Block(block_texture, sf::Vector2f(START_X, START_Y), START_VALUE_BLOCK);

    board->setActiveBlock(block);

    while (window.isOpen())
    {
        float time = 300.f;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear(sf::Color::White);

        if (board->getActiveBlock()->getState() == false)
        {
            block_texture.loadFromFile("source/cat1.jpg");

            Block *block1 = new Block(block_texture, sf::Vector2f(START_X, START_Y), START_VALUE_BLOCK);

            board->setActiveBlock(block1);
        }

        board->getActiveBlock()->Update(time);

        // drawing all board
        std::map<int, Block *> mapBlock = board->getMapBlock();
        for (int i = 0; i < board->getCountBlock(); i++)
        {
            window.draw(mapBlock[i]->getSprite());
        }

        window.display();
    }
}
