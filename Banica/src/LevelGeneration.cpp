#include "LevelGeneration.h"

namespace bnc
{
    LevelGenerator::LevelGenerator(std::shared_ptr<LevelGenerationData> levelData)
    {
        m_Result = levelData->p_Result;

        m_LevelOne = std::shared_ptr<Level>(new bnc::LevelOne(levelData->gridCells, levelData->player, levelData->gates, levelData->lamps, *levelData->solutions));    
        levelData->levels->push_back(m_LevelOne);   

        m_LevelTwo = std::shared_ptr<Level>(new bnc::LevelTwo(levelData->gridCells, levelData->player, levelData->gates, levelData->lamps, *levelData->solutions));    
        levelData->levels->push_back(m_LevelTwo);   

        m_LevelThree = std::shared_ptr<Level>(new bnc::LevelThree(levelData->gridCells, levelData->player, levelData->gates, levelData->lamps, *levelData->solutions));    
        levelData->levels->push_back(m_LevelThree);

        m_LevelFour = std::shared_ptr<Level>(new bnc::LevelFour(levelData->gridCells, levelData->player, levelData->gates, levelData->lamps, *levelData->solutions));    
        levelData->levels->push_back(m_LevelFour);

        GenerateLevel(*levelData->levels, *levelData->currentLevel);
    }

    LevelGenerator::~LevelGenerator()
    {

    }

    void LevelGenerator::GenerateLevel(std::vector<std::shared_ptr<bnc::Level>>& levels, uint32_t& currentLevel)
    {
        m_LatestLevel = levels[currentLevel];

        m_GridCellPositionX = 35;
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
            m_GridCellPositionX = 35;
            m_GridCellPositionY += m_Scale;
        }

        m_GridCellPositionX = 35;
        m_GridCellPositionY = (GetScreenHeight() / 2)  - ((levels[currentLevel]->GetSizeY()) * m_Scale) / 2;
    }

    void LevelGenerator::SetObjects()
    {
        m_LatestLevel->SetGates();
        m_LatestLevel->SetLamps(*m_Result);
    }
}