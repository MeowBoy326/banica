#include "GameWorld.h"
#include <iostream>

namespace bnc
{
    GameWorld::GameWorld(std::vector<bnc::GridCell*>* gridCells)
    {
        for(size_t i = 0; i < GetScreenWidth() / m_Scale; i++)
        {
            for(size_t j = 0; j < GetScreenHeight() / m_Scale; j++)
            {
                GridCell* cell = new GridCell;
                cell->positionX = m_GridCellPositionX;
                cell->positionY = m_GridCellPositionY;

                gridCells->push_back(cell);

                m_GridCellPositionX += m_Scale;
                
            }

            m_GridCellPositionY += m_Scale;
        }
    }

    GameWorld::~GameWorld()
    {

    }
}