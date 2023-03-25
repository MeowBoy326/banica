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
    /// @brief This class is responsibly for the level generation
    class LevelGenerator
    {
    public:
        /// @brief Sets all requared variable and levels
        /// @param levelData Pointer to a struct of LevelGenerationData
        /// @see LevelGenerationData
        LevelGenerator(std::shared_ptr<LevelGenerationData> levelData);
        ~LevelGenerator();

        /// @brief Generates the grid for the level
        /// @param levels Reference to a vector storing all levels
        /// @param currentLevel Referece to a unsiged int storing the current level
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
        std::shared_ptr<Level> m_LevelThree;
        std::shared_ptr<Level> m_LevelFour;
    };
}