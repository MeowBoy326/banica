#include "LevelSeven.h"
#include <memory>
#include <iostream>

namespace bnc
{
    LevelSeven::LevelSeven(std::vector<std::shared_ptr<bnc::GridCell>>* grid, std::shared_ptr<bnc::Player>& player, std::vector<std::shared_ptr<bnc::Gate>>* gates, std::vector<std::shared_ptr<bnc::Lamp>>* lamps, std::vector<std::shared_ptr<LevelSolution>>& solutions)
    {
        m_GridCells = grid;
        m_Gates = gates;
        m_Lamps = lamps;
        m_Solution = &solutions;
        
        m_SizeX = 13;
        m_SizeY = 11;

        player->SetPlayerPosition(56);
    }

    LevelSeven::~LevelSeven()
    {

    }

    void LevelSeven::SetGates()
    {
        m_Gates->push_back(std::shared_ptr<Gate> (new NotGate(67)));
        m_Gates->push_back(std::shared_ptr<Gate> (new XorGate(69)));
        m_Gates->push_back(std::shared_ptr<Gate> (new NotGate(71)));
        m_Gates->push_back(std::shared_ptr<Gate> (new OrGate(73)));
        m_Gates->push_back(std::shared_ptr<Gate> (new AndGate(75)));

        for(size_t i = 0; i < m_Gates->size(); i++)
        {
            m_GridCells->operator[](m_Gates->operator[](i)->GetCellPosition())->titleType = bnc::GATE;
        }
    }

    void LevelSeven::SetLamps(std::string& r_Result)
    {
        uint32_t lampPosition = 14;

        std::string firstPart =     "1100";
        std::string secondPart =    "0110";
        std::string thirdPart =     "1001";
        std::string forthPart =    "1010";
        std::string result =        "0110";

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


        //First Solution
        m_Solution->push_back(std::shared_ptr<LevelSolution> (new LevelSolution{lampPosition, bnc::NOT}));
        lampPosition++;
        //second Solution
        m_Solution->push_back(std::shared_ptr<LevelSolution> (new LevelSolution{lampPosition, bnc::XOR}));
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

        //third Solution
        lampPosition += 9;
        m_Solution->push_back(std::shared_ptr<LevelSolution> (new LevelSolution{lampPosition, bnc::AND}));

        lampPosition += 7;

        for (size_t i = 0; i < thirdPart.size(); i++)
        {
            if(thirdPart[i] == '1')
            {
                m_Lamps->push_back(std::shared_ptr<Lamp> (new Lamp(lampPosition, bnc::LAMP_ON)));
            }
            else
            {
                m_Lamps->push_back(std::shared_ptr<Lamp> (new Lamp(lampPosition, bnc::LAMP_OFF)));
            }

            lampPosition++;
        }
        // forth Solution
        m_Solution->push_back(std::shared_ptr<LevelSolution> (new LevelSolution{lampPosition, bnc::NOT}));
        lampPosition++;
        // fifth Solution
        m_Solution->push_back(std::shared_ptr<LevelSolution> (new LevelSolution{lampPosition, bnc::OR}));
        lampPosition++;

        for (size_t i = 0; i < forthPart.size(); i++)
        {
            if(forthPart[i] == '1')
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