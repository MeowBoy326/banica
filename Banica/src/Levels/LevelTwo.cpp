#include "LevelTwo.h"
#include <memory>

namespace bnc
{
    LevelTwo::LevelTwo(std::vector<std::shared_ptr<bnc::GridCell>>* grid, std::shared_ptr<bnc::Player>& player, std::vector<std::shared_ptr<bnc::Gate>>* gates, std::vector<std::shared_ptr<bnc::Lamp>>* lamps)
    {
        m_GridCells = grid;
        m_Gates = gates;
        m_Lamps = lamps;
        
        m_SizeX = 15;
        m_SizeY = 10;

        player->SetPlayerPosition(20);
    }

    LevelTwo::~LevelTwo()
    {

    }

    void LevelTwo::SetGates()
    {
        m_Gates->push_back(std::shared_ptr<Gate> (new AndGate(42)));
        m_Gates->push_back(std::shared_ptr<Gate> (new OrGate(44)));

        for(size_t i = 0; i < m_Gates->size(); i++)
        {
            m_GridCells->operator[](m_Gates->operator[](i)->GetCellPosition())->titleType = bnc::GATE;
        }
    }

    void LevelTwo::SetLamps()
    {
        m_Lamps->push_back(std::shared_ptr<Lamp> (new Lamp(15, true)));
        m_Lamps->push_back(std::shared_ptr<Lamp> (new Lamp(16, false)));
        m_Lamps->push_back(std::shared_ptr<Lamp> (new Lamp(17, false)));
        m_Lamps->push_back(std::shared_ptr<Lamp> (new Lamp(18, true)));

        for(size_t i = 0; i < m_Lamps->size(); i++)
        {
            m_GridCells->operator[](m_Lamps->operator[](i)->GetPosition())->titleType = bnc::LAMP;
        }
    }
}