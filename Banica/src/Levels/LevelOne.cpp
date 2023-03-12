#include "LevelOne.h"

namespace bnc
{
    LevelOne::LevelOne(std::vector<bnc::GridCell*>* grid, bnc::Player& player, std::vector<Gate*>* gates)
    {
        m_GridCells = grid;
        m_Gates = gates;
        
        m_SizeX = 10;
        m_SizeY = 10;

        player.SetPlayerPosition(10);
    }

    LevelOne::~LevelOne()
    {

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
}