#include "LevelTwo.h"
#include <memory>
#include <iostream>

namespace bnc
{
    LevelTwo::LevelTwo(std::vector<std::shared_ptr<bnc::GridCell>>* grid, std::shared_ptr<bnc::Player>& player, std::vector<std::shared_ptr<bnc::Gate>>* gates, std::vector<std::shared_ptr<bnc::Lamp>>* lamps, std::vector<std::shared_ptr<LevelSolution>>& solutions)
    {
        m_GridCells = grid;
        m_Gates = gates;
        m_Lamps = lamps;
        m_Solution = &solutions;
        
        m_SizeX = 11;
        m_SizeY = 11;

        player->SetPlayerPosition(56);
    }

    LevelTwo::~LevelTwo()
    {

    }

    void LevelTwo::SetGates()
    {
        m_Gates->push_back(std::shared_ptr<Gate> (new OrGate(60)));

        for(size_t i = 0; i < m_Gates->size(); i++)
        {
            m_GridCells->operator[](m_Gates->operator[](i)->GetCellPosition())->titleType = bnc::GATE;
        }
    }

    void LevelTwo::SetLamps(std::string& r_Result)
    {
        uint32_t lampPosition = 12;

        std::string firstPart =     "1010";
        std::string secondPart =    "0101";
        std::string result =        "1111";

        r_Result = result;

        for (size_t i = 0; i < firstPart.size(); i++)
        {
            if(firstPart[i] == '1')
            {
                m_Lamps->push_back(std::shared_ptr<Lamp> (new Lamp(lampPosition, bnc::LAMP_ON)));
            }
            else
            {
                m_Lamps->push_back(std::shared_ptr<Lamp> (new Lamp(lampPosition, bnc::LAMP_OFF)));
            }

            lampPosition++;
        }

        // First Solution
        m_Solution->push_back(std::shared_ptr<LevelSolution> (new LevelSolution{lampPosition, bnc::OR}));
        lampPosition++;
        
        for (size_t i = 0; i < secondPart.size(); i++)
        {
            if(secondPart[i] == '1')
            {
                m_Lamps->push_back(std::shared_ptr<Lamp> (new Lamp(lampPosition, bnc::LAMP_ON)));
            }
            else
            {
                m_Lamps->push_back(std::shared_ptr<Lamp> (new Lamp(lampPosition, bnc::LAMP_OFF)));
            }

            lampPosition++;
        }

        for(size_t i = 0; i < m_Lamps->size(); i++)
        {
            m_GridCells->operator[](m_Lamps->operator[](i)->GetPosition())->titleType = bnc::LAMP;
        }
    }
}