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
        uint32_t m_Scale = 60;
        float m_GridCellPositionX = 0;
        float m_GridCellPositionY = 0;
    };
}

