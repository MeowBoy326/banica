#include "LevelOne.h"
#include <memory>
#include <iostream>

namespace bnc
{
    LevelOne::LevelOne(std::vector<std::shared_ptr<bnc::GridCell>>* grid, std::shared_ptr<bnc::Player>& player, std::vector<std::shared_ptr<bnc::Gate>>* gates, std::vector<std::shared_ptr<bnc::Lamp>>* lamps, std::vector<std::shared_ptr<LevelSolution>>& solutions)
    {
        m_GridCells = grid;
        m_Gates = gates;
        m_Lamps = lamps;
        m_Solution = &solutions;
        
        m_SizeX = 10;
        m_SizeY = 10;

        player->SetPlayerPosition(10);
    }

    LevelOne::~LevelOne()
    {

    }

    void LevelOne::SetGates()
    {
        m_Gates->push_back(std::shared_ptr<Gate> (new AndGate(43)));
        m_Gates->push_back(std::shared_ptr<Gate> (new OrGate(44)));
        m_Gates->push_back(std::shared_ptr<Gate> (new NotGate(45)));
        m_Gates->push_back(std::shared_ptr<Gate> (new XorGate(46)));

        for(size_t i = 0; i < m_Gates->size(); i++)
        {
            m_GridCells->operator[](m_Gates->operator[](i)->GetCellPosition())->titleType = bnc::GATE;
        }
    }

    void LevelOne::SetLamps()
    {
        uint32_t lampPosition = 10;
        uint32_t lampResultPosition = 39;

        std::string firstPart = "1011";
        std::string secondPart = "1100";
        std::string result = "1111";

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

        for (size_t i = 0; i < result.size(); i++)
        {
            if(result[i] == '1')
            {
                m_Lamps->push_back(std::shared_ptr<Lamp> (new Lamp(lampResultPosition, bnc::LAMP_ON)));
            }
            else
            {
                m_Lamps->push_back(std::shared_ptr<Lamp> (new Lamp(lampResultPosition, bnc::LAMP_OFF)));
            }

            lampResultPosition += m_SizeX;
        }

        for(size_t i = 0; i < m_Lamps->size(); i++)
        {
            m_GridCells->operator[](m_Lamps->operator[](i)->GetPosition())->titleType = bnc::LAMP;
        }
    }
}