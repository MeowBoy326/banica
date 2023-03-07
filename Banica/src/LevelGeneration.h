#pragma once
#include "raylib.h"
#include <vector>
#include <stdint.h>
#include "GridCell.h"
#include "Level.h"
#include "Levels/Levels.h"

namespace bnc
{
    class LevelGenerator
    {
    public:
        LevelGenerator(std::vector<Level*>* levels, std::vector<GridCell*>* gridCells);
        ~LevelGenerator();

        void GenerateLevel();

    private:
        uint32_t m_Scale = 60;
        uint32_t m_GridCellPositionX = 0;
        uint32_t m_GridCellPositionY = 0;

        uint32_t m_CurrentLevel = 0;

        std::vector<Level*>* m_Levels;
        std::vector<GridCell*>* m_GridCells;


        LevelOne* m_FirstLevel;
    };
}