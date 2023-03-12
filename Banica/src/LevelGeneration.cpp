#include "LevelGeneration.h"

namespace bnc
{
    LevelGenerator::LevelGenerator(std::vector<bnc::Level*>& levels, std::vector<bnc::GridCell*>& gridCells, uint32_t& currentLevel, bnc::Player& player, std::vector<Gate*>* gates)
    {
        m_FirstLevel = new bnc::LevelOne(&gridCells, player, gates);
        levels.push_back(m_FirstLevel);        

        GenerateLevel(levels, currentLevel);
    }

    LevelGenerator::~LevelGenerator()
    {
        // DELEATING ALL LEVELS HERE
        delete m_FirstLevel;
    }

    void LevelGenerator::GenerateLevel(std::vector<bnc::Level*>& levels, uint32_t& currentLevel)
    {
        m_GridCellPositionX = (GetScreenWidth() / 2)  - ((levels[currentLevel]->GetSizeX()) * m_Scale) / 2;
        m_GridCellPositionY = (GetScreenHeight() / 2)  - ((levels[currentLevel]->GetSizeY()) * m_Scale) / 2;

        for(size_t i = 0; i < levels[currentLevel]->GetSizeY(); i++)
        {
            for(size_t j = 0; j < levels[currentLevel]->GetSizeX(); j++)
            {
                GridCell* cell = new bnc::GridCell;
                cell->position.x = m_GridCellPositionX;
                cell->position.y = m_GridCellPositionY;

                levels[currentLevel]->GetGridCells().push_back(cell);

                m_GridCellPositionX += m_Scale;
            }
            m_GridCellPositionX = (GetScreenWidth() / 2)  - ((levels[currentLevel]->GetSizeX()) * m_Scale) / 2;
            m_GridCellPositionY += m_Scale;
        }

        m_GridCellPositionX = (GetScreenWidth() / 2)  - ((levels[currentLevel]->GetSizeX()) * m_Scale) / 2;
        m_GridCellPositionY = (GetScreenHeight() / 2)  - ((levels[currentLevel]->GetSizeY()) * m_Scale) / 2;
    }

    void LevelGenerator::SetObjects()
    {
        m_FirstLevel->SetGates();
    }
}