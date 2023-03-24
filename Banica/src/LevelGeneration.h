#pragma once
#include "raylib.h"
#include <vector>
#include <stdint.h>
#include "GridCell.h"
#include "Level.h"
#include "Player.h"
#include "Levels/Levels.h"
#include "Gate.h"
#include <memory>
#include "Solution.h"
#include "Data.h"
#include <string>

namespace bnc
{
    class LevelGenerator
    {
    public:
        LevelGenerator(std::shared_ptr<LevelGenerationData> levelData);
        ~LevelGenerator();

        void GenerateLevel(std::vector<std::shared_ptr<Level>>& levels, uint32_t& currentLevel);
        void SetObjects();

    private:
        uint32_t m_Scale = 60;
        uint32_t m_GridCellPositionX = 0;
        uint32_t m_GridCellPositionY = 0;

        std::string* m_Result;

        std::shared_ptr<Level> m_LatestLevel;

        std::shared_ptr<Level> m_LevelOne;
        std::shared_ptr<Level> m_LevelTwo;
    };
}