#include "../headers/controller.hpp"
#include "../headers/block.hpp"
#include <iostream>
BlockController *BlockController::controller = nullptr;

BlockController::~BlockController()
{
    delete controller;
}

BlockController *BlockController::getBlockController()
{
    if (!controller)
    {
        controller = new BlockController();
    }

    return controller;
}

void BlockController::controll(Block *block, float time)
{
    sf::Vector2f updated_pos = block->getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        updated_pos.x -= 100;
        block->setDirection(Direction::LEFT);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        updated_pos.x += 100;
        block->setDirection(Direction::RIGHT);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        updated_pos.y -= PLAYER_SPEED * time;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        updated_pos.y += PLAYER_SPEED * time;
    }
    std::cout << updated_pos.x << " " << updated_pos.y << std::endl;
    block->setPosition(updated_pos);
}