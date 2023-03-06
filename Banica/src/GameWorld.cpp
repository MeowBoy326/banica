#include "GameWorld.h"
#include <iostream>

namespace bnc
{
    GameWorld::GameWorld(std::vector<bnc::GridCell*>* gridCells)
    {
        for(size_t i = 0; i < GetScreenHeight() / m_Scale; i++)
        {
            for(size_t j = 0; j < GetScreenWidth() / m_Scale; j++)
            {
                GridCell* cell = new GridCell;
                cell->positionX = m_GridCellPositionX;
                cell->positionY = m_GridCellPositionY;

                gridCells->push_back(cell);

                m_GridCellPositionX += m_Scale;
            }
            m_GridCellPositionX = 0;
            m_GridCellPositionY += m_Scale;
        }
    }

    GameWorld::~GameWorld()
    {

    }
}