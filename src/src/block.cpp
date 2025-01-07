#include "../headers/block.hpp"
#include "../headers/controller.hpp"
#include "../headers/constants.hpp"
#include <iostream>

Block::~Block() {}

Block::Block(std::string path_texture, sf::Vector2f start_pos, int value)
{
    m_pos = start_pos;
    m_value = value;
    m_state = true;
    if (!m_texture.loadFromFile(path_texture))
    {
        std::cerr << "Error loading texture from file: " << path_texture << std::endl;
    }
    // m_controller = BlockController::getBlockController();
    BlockController m_controller;
    m_sprite.setTexture(m_texture);
    m_size = sf::Vector2f(m_sprite.getTextureRect().width, m_sprite.getTextureRect().height);
}

void Block::Update(float time)
{
    m_controller->controll(this, time);
    m_sprite.setPosition(m_pos);
}

int Block::determineNumberBlock()
{
    int x = m_pos.x / 100;
    int y = (m_pos.y - START_Y) / 100;
    int number = 5 * y + x;
    // std::cout << number << std::endl;
    //  m_blocks[number] = value;

    return number;
}

void Block::setPositionBlock(sf::Vector2f &pos)
{
    m_pos = pos;
    m_sprite.setPosition(m_pos);
}

void Block::setDirection(Direction direction)
{
    m_direction = direction;
}

void Block::setValue(int &value)
{
    m_value = value;
}

void Block::setState(bool state)
{
    m_state = state;
}

sf::Vector2f Block::getSize() const
{
    return m_size;
}

sf::Vector2f Block::getPosition() const
{
    return m_pos;
}

sf::Sprite Block::getSprite() const
{
    return m_sprite;
}

Direction Block::getDirection() const
{
    return m_direction;
}

int Block::getValue() const
{
    return m_value;
}

bool Block::getState() const
{
    return m_state;
}
