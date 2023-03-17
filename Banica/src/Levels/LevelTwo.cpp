#include "LevelTwo.h"
#include <memory>

namespace bnc
{
    LevelTwo::LevelTwo(std::vector<std::shared_ptr<bnc::GridCell>>* grid, std::shared_ptr<bnc::Player>& player, std::vector<std::shared_ptr<bnc::Gate>>* gates, std::vector<std::shared_ptr<bnc::Lamp>>* lamps, std::vector<std::shared_ptr<LevelSolution>>& solutions)
    {
        m_GridCells = grid;
        m_Gates = gates;
        m_Lamps = lamps;
        m_Solution = &solutions;
        
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
        m_Lamps->push_back(std::shared_ptr<Lamp> (new Lamp(15, bnc::LAMP_ON)));
        m_Lamps->push_back(std::shared_ptr<Lamp> (new Lamp(16, bnc::LAMP_OFF)));
        m_Lamps->push_back(std::shared_ptr<Lamp> (new Lamp(17, bnc::LAMP_OFF)));
        m_Lamps->push_back(std::shared_ptr<Lamp> (new Lamp(18, bnc::LAMP_ON)));

        // dummmy solution for testing
        m_Solution->push_back(std::shared_ptr<LevelSolution> (new LevelSolution{0, bnc::AND}));

        for(size_t i = 0; i < m_Lamps->size(); i++)
        {
            m_GridCells->operator[](m_Lamps->operator[](i)->GetPosition())->titleType = bnc::LAMP;
        }
    }
}