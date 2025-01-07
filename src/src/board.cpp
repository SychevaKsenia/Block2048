#include "../headers/block.hpp"
#include "../headers/board.hpp"
#include "../headers/constants.hpp"
#include <iostream>
#include <fstream>

Board::Board()
{
    std::ofstream board("src/src/outboard.txt");
    for (int i = 0; i < SIZE_BOARD_HEIGHT; i++)
    {
        for (int j = 0; j < SIZE_BOARD_WEIGHT; j++)
            board << "0 ";
        board << std::endl;
    }

    for (int i = 0; i < SIZE_BOARD_HEIGHT * SIZE_BOARD_WEIGHT; i++)
    {
        m_blocks[i] = nullptr;
    }
}

void Board::createBoard()
{
}

void Board::createBlock(std::string &pathBlockTexture, int value)
{
    // sf::Texture block_texture;
    // block_texture.loadFromFile(pathBlockTexture);
    // m_activeBlock = new Block(block_texture, sf::Vector2f(250, 100), value);
    // m_activeBlock->Update(300);

    // m_window->clear(sf::Color::Red);
    // m_window->draw(m_activeBlock->getSprite());
    // m_window->display();
}

void Board::intersectionBlock()
{
    if (m_countBlock < 2)
        return;

    std::cout << "map" << std::endl;
    for (int i = 0; i < m_countBlock; i++)
    {
        if (m_blocks[i] != nullptr)
            std::cout << i << " " << m_blocks[i]->getPosition().x << " " << m_blocks[i]->getPosition().y << std::endl;
    }
    std::cout << "-----" << std::endl;
    // part1
    while (true)
    {
        bool flag = false;
        for (int i = 0; i < m_countBlock; i++)
        {
            if (m_blocks[i] != nullptr && m_activeBlock->getSprite().getGlobalBounds().intersects(m_blocks[i]->getSprite().getGlobalBounds()) &&
                m_activeBlock != m_blocks[i])
            {
                std::cout << "Collision detected!" << std::endl;
                // m_activeBlock->setState(true);
                //  надо поменять позицию объекта на нужную (поднять его вверз на 1 болок)
                int x = m_activeBlock->getPosition().x;
                int y = m_activeBlock->getPosition().y - SIZE_BLOCK;
                sf::Vector2f updated_pos(x, (y > START_Y) ? y : START_Y);
                std::cout << "Update " << x << " " << y << std::endl;
                m_activeBlock->setPositionBlock(updated_pos);
                flag = true;
                std::cout << i << std::endl;
                break;
            }
        }

        if (!flag)
        {
            m_blocks[m_activeBlock->determineNumberBlock()] = m_activeBlock;
            break;
        }
    }
    // part 2
}

void Board::updateBoard()
{
}

Block *Board::getActiveBlock()
{
    return m_activeBlock;
}

int Board::getCountBlock()
{
    return m_countBlock;
}

std::map<int, Block *> Board::getMapBlock()
{
    return m_blocks;
}

void Board::setActiveBlock(Block *actBlock)
{
    m_activeBlock = actBlock;
    // m_blocks[m_activeBlock->determineNumberBlock()] = actBlock;
    //  m_countBlock++;
}

void Board::setCountBlock(int &countBlock)
{
    m_countBlock = countBlock;
}