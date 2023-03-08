#include "LevelOne.h"

namespace bnc
{
    LevelOne::LevelOne(std::vector<GridCell*>* grid)
    {
        m_GridCells = grid;
    }

    LevelOne::~LevelOne()
    {
        delete m_GridCells;
    }

    std::vector<GridCell*>& LevelOne::GetGridCells() const
    {
        return *m_GridCells;
    }

    uint32_t LevelOne::GetSizeX() const 
    {
        return m_SizeX;
    }

    uint32_t LevelOne::GetSizeY() const
    {
        return m_SizeY;
    }
}