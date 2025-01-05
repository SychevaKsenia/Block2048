
#include <vector>
#include <map>
#include "../headers/block.hpp"
class Board
{
public:
    Board();
    void createBoard();
    void createBlock(std::string &pathBlockTexture, int value);
    void intersectionBlock();
    void updateBoard();

    void setActiveBlock(Block *actBlock);
    void setCountBlock(int &countBlock);

    Block *getActiveBlock();
    int getCountBlock();
    std::map<int, Block *> getMapBlock();

private:
    std::map<int, Block *> m_blocks;
    Block *m_activeBlock;
    int m_countBlock = 0;
};