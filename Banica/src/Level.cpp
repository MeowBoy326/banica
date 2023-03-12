#include "Level.h"

namespace bnc
{
    Level::Level()
    {

    }

    Level::~Level()
    {

    }

    std::vector<bnc::GridCell*>& Level::GetGridCells() const
    {
        return *m_GridCells;
    }

    uint32_t Level::GetSizeX() const 
    {
        return m_SizeX;
    }

    uint32_t Level::GetSizeY() const
    {
        return m_SizeY;
    }

    std::vector<bnc::Gate*>& Level::GetGates() const
    {
        return *m_Gates;
    }
}