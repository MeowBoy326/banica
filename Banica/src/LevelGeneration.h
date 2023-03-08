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
        LevelGenerator(std::vector<Level*>& levels, std::vector<GridCell*>& gridCells, uint32_t& currentLevel);
        ~LevelGenerator();

        void GenerateLevel(std::vector<Level*>& levels, uint32_t& currentLevel);

    private:
        uint32_t m_Scale = 60;
        uint32_t m_GridCellPositionX = 0;
        uint32_t m_GridCellPositionY = 0;

        LevelOne* m_FirstLevel;
    };
}