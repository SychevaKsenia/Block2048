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
    m_blocks[m_countBlock++] = actBlock;
}

void Board::setCountBlock(int &countBlock)
{
    m_countBlock = countBlock;
}