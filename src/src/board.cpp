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

Block *Board::createBlock(int posX, int posY, int value)
{
    // sf::Texture block_texture;
    // block_texture.loadFromFile("source/cat1.jpg");
    std::string path = "source/cat" + std::to_string(value) + ".jpg";
    Block *block = new Block(path, sf::Vector2f(posX, posY), value);
    return block;
}

void Board::intersectionBlock()
{
    if (m_countBlock < 2)
        return;

    // std::cout << "map" << std::endl;
    // for (int i = 0; i < m_countBlock; i++)
    // {
    //     if (m_blocks[i] != nullptr)
    //         std::cout << i << " " << m_blocks[i]->getPosition().x << " " << m_blocks[i]->getPosition().y << std::endl;
    // }
    // std::cout << "-----" << std::endl;
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
    /*
    0 1 2 3 4
    5  6  7  8  9
    10 11 12 13 14
    15 16 17 18 19
    20 21 22 23 24
    25 26 27 28 29

    */
    int col = m_activeBlock->getPosition().x / 100;
    for (int i = 0; i < SIZE_BOARD_HEIGHT - 1; i++)
    {

        // int x = m_pos.x / 100;
        // int y = (m_pos.y - START_Y) / 100;
        // int number = 5 * y + x;
        int curPosition = i * SIZE_BOARD_WEIGHT + col;
        int nextPosition = curPosition + SIZE_BOARD_WEIGHT;
        std::cout << curPosition << " " << nextPosition << std::endl;
        if (m_blocks[curPosition] != nullptr && m_blocks[nextPosition] != nullptr && m_blocks[curPosition]->getValue() == m_blocks[nextPosition]->getValue())
        {

            mergeBlocks(curPosition, nextPosition, m_blocks[nextPosition]->getPosition());
        }
    }
}

void Board::mergeBlocks(int upperPos, int underPos, sf::Vector2f coord)
{
    std::cout << "merge" << std::endl;
    std::cout << upperPos << " " << underPos << std::endl;
    int value = m_blocks[upperPos]->getValue();
    if (m_blocks[upperPos] != nullptr)
    {
        delete m_blocks[upperPos];
        m_blocks[upperPos] = nullptr;
    }

    if (m_blocks[underPos] != nullptr)
    {
        delete m_blocks[underPos];
        m_blocks[underPos] = nullptr;
    }
    // m_blocks[upperPos] = nullptr;
    //  m_blocks[underPos] = nullptr;

    std::cout << "Cooooooord" << coord.x << coord.y << std::endl;
    m_blocks[underPos] = this->createBlock(coord.x, coord.y, value * value);
    // m_blocks[underPos]->getSprite().setPosition(coord);
    m_blocks[underPos]->setPositionBlock(coord);
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