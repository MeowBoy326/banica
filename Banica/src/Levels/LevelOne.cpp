#include "LevelOne.h"

namespace bnc
{
    LevelOne::LevelOne(std::vector<bnc::GridCell*>* grid, bnc::Player& player, std::vector<Gate*>* gates)
    {
        m_GridCells = grid;
        m_Gates = gates;
        player.SetPlayerPosition(10);
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
        m_Gates->push_back(new AndGate(45));
        m_Gates->push_back(new OrGate(55));
        m_Gates->push_back(new NotGate(65));
        m_Gates->push_back(new XorGate(75));

        for(size_t i = 0; i < m_Gates->size(); i++)
        {
            m_GridCells->operator[](m_Gates->operator[](i)->GetCellPosition())->titleType = bnc::GATE;
        }
    }

    std::vector<bnc::Gate*>& LevelOne::GetGates()
    {
        return *m_Gates;
    }
}