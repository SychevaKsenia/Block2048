#include "../headers/block.hpp"
#include "../headers/controller.hpp"
Block::~Block() {}

Block::Block(sf::Texture &texture, sf::Vector2f start_pos, int value)
{
    m_pos = start_pos;
    m_value = value;
    m_controller = BlockController::getBlockController();

    m_sprite.setTexture(texture);
    m_size = sf::Vector2f(m_sprite.getTextureRect().width, m_sprite.getTextureRect().height);
}

void Block::Update(float time)
{
    m_controller->controll(this, time);
    m_sprite.setPosition(m_pos);
}

void Block::setPosition(sf::Vector2f &pos)
{
    m_pos = pos;
}

void Block::setDirection(Direction direction)
{
    m_direction = direction;
}

void Block::setValue(int &value)
{
    m_value = value;
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
