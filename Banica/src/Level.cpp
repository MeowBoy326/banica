#include "Level.h"

namespace bnc
{
    Level::Level()
    {

    }

    Level::~Level()
    {

    }

    std::vector<std::shared_ptr<GridCell>>& Level::GetGridCells() const
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

    std::vector<std::shared_ptr<bnc::Gate>>& Level::GetGates() const
    {
        return *m_Gates;
    }
}