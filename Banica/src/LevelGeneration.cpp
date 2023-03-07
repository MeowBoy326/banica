#include "LevelGeneration.h"

namespace bnc
{
    LevelGenerator::LevelGenerator(std::vector<Level*>* levels, std::vector<GridCell*>* gridCells)
    {
        // ADDING ALL LEVELS HERE
        m_Levels = levels;
        m_GridCells = gridCells;

        m_FirstLevel = new LevelOne(gridCells);
        m_Levels->push_back(m_FirstLevel);        

        GenerateLevel();
    }

    LevelGenerator::~LevelGenerator()
    {
        // DELEATING ALL LEVELS HERE
        delete m_FirstLevel;

        delete m_Levels;
        delete m_GridCells;
    }

    void LevelGenerator::GenerateLevel()
    {
        m_GridCellPositionX = (GetScreenWidth() / 2)  - ((m_Levels->operator[](m_CurrentLevel)->GetSizeX()) * 60) / 2;
        m_GridCellPositionY = (GetScreenHeight() / 2)  - ((m_Levels->operator[](m_CurrentLevel)->GetSizeY()) * 60) / 2;

        for(size_t i = 0; i < m_Levels->operator[](m_CurrentLevel)->GetSizeY(); i++)
        {
            for(size_t j = 0; j < m_Levels->operator[](m_CurrentLevel)->GetSizeX(); j++)
            {
                GridCell* cell = new GridCell;
                cell->positionX = m_GridCellPositionX;
                cell->positionY = m_GridCellPositionY;

                m_Levels->operator[](m_CurrentLevel)->GetGridCells()->push_back(cell);

                m_GridCellPositionX += m_Scale;
            }
            m_GridCellPositionX = (GetScreenWidth() / 2)  - ((m_Levels->operator[](m_CurrentLevel)->GetSizeX()) * 60) / 2;
            m_GridCellPositionY += m_Scale;
        }

        m_GridCellPositionX = (GetScreenWidth() / 2)  - ((m_Levels->operator[](m_CurrentLevel)->GetSizeX()) * 60) / 2;
        m_GridCellPositionY = (GetScreenHeight() / 2)  - ((m_Levels->operator[](m_CurrentLevel)->GetSizeY()) * 60) / 2;
        m_CurrentLevel++;
    }
}