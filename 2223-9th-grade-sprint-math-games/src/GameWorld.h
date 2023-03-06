#pragma once
#include "GridCell.h"
#include <vector>
#include "raylib.h"

namespace bnc
{
    class GameWorld
    {
    public: 
        GameWorld(std::vector<bnc::GridCell*>* gridCells);
        ~GameWorld();

    private:
        uint32_t m_Scale = 30;
        uint32_t m_GridCellPositionX = 0;
        uint32_t m_GridCellPositionY = 0;
    };
}

