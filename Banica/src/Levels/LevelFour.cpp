#include "LevelFour.h"
#include <memory>
#include <iostream>

namespace bnc
{
    LevelFour::LevelFour(std::vector<std::shared_ptr<bnc::GridCell>>* grid, std::shared_ptr<bnc::Player>& player, std::vector<std::shared_ptr<bnc::Gate>>* gates, std::vector<std::shared_ptr<bnc::Lamp>>* lamps, std::vector<std::shared_ptr<LevelSolution>>& solutions)
    {
        m_GridCells = grid;
        m_Gates = gates;
        m_Lamps = lamps;
        m_Solution = &solutions;
        
        m_SizeX = 12;
        m_SizeY = 11;

        player->SetPlayerPosition(56);
    }

    LevelFour::~LevelFour()
    {

    }

    void LevelFour::SetGates()
    {
        m_Gates->push_back(std::shared_ptr<Gate> (new AndGate(64)));
        m_Gates->push_back(std::shared_ptr<Gate> (new NotGate(67)));

        for(size_t i = 0; i < m_Gates->size(); i++)
        {
            m_GridCells->operator[](m_Gates->operator[](i)->GetCellPosition())->titleType = bnc::GATE;
        }
    }

    void LevelFour::SetLamps(std::string& r_Result)
    {
        uint32_t lampPosition = 13;

        std::string firstPart = "1111";
        std::string secondPart = "1111";
        std::string result = "0000";

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
        m_Solution->push_back(std::shared_ptr<LevelSolution> (new LevelSolution{lampPosition, bnc::NOT}));
        lampPosition++;

        //Second Solution
        m_Solution->push_back(std::shared_ptr<LevelSolution> (new LevelSolution{lampPosition, bnc::AND}));
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