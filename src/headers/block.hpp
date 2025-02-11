#pragma once

#include <SFML/Graphics.hpp>
#include "../headers/controller.hpp"

enum class Direction : bool
{
    LEFT = 0,
    RIGHT = 1
};

class Block
{
private:
    sf::Vector2f m_size;
    sf::Vector2f m_pos;
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    Direction m_direction = Direction::RIGHT;
    int m_value;
    BlockController *m_controller;
    bool m_state;

public:
    ~Block();
    Block(std::string path_texture, sf::Vector2f start_pos, int value);

    void Update(float time);
    int determineNumberBlock();

    void setPositionBlock(sf::Vector2f &pos);
    void setDirection(Direction direction);
    void setValue(int &value);
    void setState(bool state);

    sf::Vector2f getSize() const;
    sf::Vector2f getPosition() const;
    sf::Sprite getSprite() const;
    Direction getDirection() const;
    int getValue() const;
    bool getState() const;
};