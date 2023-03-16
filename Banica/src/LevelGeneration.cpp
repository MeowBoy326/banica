#include "LevelGeneration.h"

namespace bnc
{
    LevelGenerator::LevelGenerator(std::vector<std::shared_ptr<bnc::Level>>& levels, std::vector<std::shared_ptr<GridCell>>& gridCells, uint32_t& currentLevel, std::shared_ptr<Player>& player, std::vector<std::shared_ptr<bnc::Gate>>* gates, std::vector<std::shared_ptr<bnc::Lamp>>* lamps)
    {
        m_LevelOne = std::shared_ptr<Level>(new bnc::LevelOne(&gridCells, player, gates, lamps));    
        levels.push_back(m_LevelOne);   

        m_LevelTwo = std::shared_ptr<Level>(new bnc::LevelTwo(&gridCells, player, gates, lamps));    
        levels.push_back(m_LevelTwo);   

        GenerateLevel(levels, currentLevel);
    }

    LevelGenerator::~LevelGenerator()
    {

    }

    void LevelGenerator::GenerateLevel(std::vector<std::shared_ptr<bnc::Level>>& levels, uint32_t& currentLevel)
    {
        m_LatestLevel = levels[currentLevel];

        m_GridCellPositionX = (GetScreenWidth() / 2)  - ((levels[currentLevel]->GetSizeX()) * m_Scale) / 2;
        m_GridCellPositionY = (GetScreenHeight() / 2)  - ((levels[currentLevel]->GetSizeY()) * m_Scale) / 2;

        for(size_t i = 0; i < levels[currentLevel]->GetSizeY(); i++)
        {
            for(size_t j = 0; j < levels[currentLevel]->GetSizeX(); j++)
            {
                std::shared_ptr<GridCell> cell = std::shared_ptr<GridCell>(new bnc::GridCell);
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
        m_LatestLevel->SetGates();
        m_LatestLevel->SetLamps();
    }
}