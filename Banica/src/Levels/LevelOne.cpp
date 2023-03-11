#include "LevelOne.h"

namespace bnc
{
    LevelOne::LevelOne(std::vector<bnc::GridCell*>* grid, bnc::Player& player)
    {
        m_GridCells = grid;
        player.SetPlayerPosition(25);
    }

    LevelOne::~LevelOne()
    {
        delete m_GridCells;
    }

    std::vector<bnc::GridCell*>& LevelOne::GetGridCells() const
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

    void LevelOne::SetGates()
    {
        m_Gates.reserve(10);
        m_Gates.push_back(new AndGate(40));
        m_Gates.push_back(new AndGate(55));

        for(size_t i = 0; i < m_Gates.size(); i++)
        {
            m_GridCells->operator[](m_Gates[i]->GetCellPosition())->isGateHere = true;
        }
    }

    std::vector<bnc::Gate*>& LevelOne::GetGates()
    {
        return m_Gates;
    }
}