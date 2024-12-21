#pragma once

class Block;

class BlockController
{
private:
    BlockController() = default;

    static BlockController *controller;

public:
    BlockController(BlockController const &) = delete;
    void operator=(BlockController const &) = delete;

    ~BlockController();

    static BlockController *getBlockController();

    void controll(Block *block, float time);
};