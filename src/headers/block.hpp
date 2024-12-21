#pragma once

#include <SFML/Graphics.hpp>
#include "../headers/controller.hpp"

enum class Direction : bool
{
    LEFT = 0,
    RIGHT = 1
};
constexpr float PLAYER_SPEED = 0.12;
class Block
{
private:
    sf::Vector2f m_size;
    sf::Vector2f m_pos;
    sf::Sprite m_sprite;
    Direction m_direction = Direction::RIGHT;
    int m_value;
    BlockController *m_controller;

public:
    ~Block();
    Block(sf::Texture &texture, sf::Vector2f start_pos, int value);

    void Update(float time);

    void setPosition(sf::Vector2f &pos);
    void setDirection(Direction direction);
    void setValue(int &value);

    sf::Vector2f getSize() const;
    sf::Vector2f getPosition() const;
    sf::Sprite getSprite() const;
    Direction getDirection() const;
    int getValue() const;
};