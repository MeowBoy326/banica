#include "LevelOne.h"
#include <memory>

namespace bnc
{
    LevelOne::LevelOne(std::vector<std::shared_ptr<bnc::GridCell>>* grid, std::shared_ptr<bnc::Player>& player, std::vector<std::shared_ptr<bnc::Gate>>* gates)
    {
        m_GridCells = grid;
        m_Gates = gates;
        
        m_SizeX = 10;
        m_SizeY = 10;

        player->SetPlayerPosition(10);
    }

    LevelOne::~LevelOne()
    {

    }

    void LevelOne::SetGates()
    {
        m_Gates->push_back(std::shared_ptr<Gate> (new AndGate(42)));
        m_Gates->push_back(std::shared_ptr<Gate> (new OrGate(44)));
        m_Gates->push_back(std::shared_ptr<Gate> (new NotGate(46)));
        m_Gates->push_back(std::shared_ptr<Gate> (new XorGate(48)));

        for(size_t i = 0; i < m_Gates->size(); i++)
        {
            m_GridCells->operator[](m_Gates->operator[](i)->GetCellPosition())->titleType = bnc::GATE;
        }
    }
}