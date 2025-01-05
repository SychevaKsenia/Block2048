#include "../headers/controller.hpp"
#include "../headers/block.hpp"
#include "../headers/constants.hpp"
#include <iostream>
// BlockController *BlockController::controller = nullptr;

BlockController::~BlockController()
{
    // delete controller;
}

// BlockController *BlockController::getBlockController()
// {
//     // if (!controller)
//     // {
//     //     controller = new BlockController();
//     // }
//     BlockController controller();

//     return controller;
// }

BlockController::BlockController()
{
    std::cout << "Create Controller" << std::endl;
}

void BlockController::controll(Block *block, float time)
{
    if (block->getState())
    {
        sf::Vector2f updated_pos = block->getPosition();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            updated_pos.x -= SIZE_BLOCK;
            block->setDirection(Direction::LEFT);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            updated_pos.x += SIZE_BLOCK;
            block->setDirection(Direction::RIGHT);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            updated_pos.y = SIZE_BLOCK * SIZE_BOARD_HEIGHT;
            block->setState(false);
        }
        std::cout << updated_pos.x << " " << updated_pos.y << std::endl;
        block->setPosition(updated_pos);
    }
}