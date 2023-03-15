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

namespace bnc
{
    class LevelGenerator
    {
    public:
        LevelGenerator(std::vector<std::shared_ptr<bnc::Level>>& levels, std::vector<std::shared_ptr<GridCell>>& gridCells, uint32_t& currentLevel, std::shared_ptr<Player>& player, std::vector<std::shared_ptr<bnc::Gate>>* gates);
        ~LevelGenerator();

        void GenerateLevel(std::vector<std::shared_ptr<Level>>& levels, uint32_t& currentLevel);
        void SetObjects();

    private:
        uint32_t m_Scale = 60;
        uint32_t m_GridCellPositionX = 0;
        uint32_t m_GridCellPositionY = 0;

        std::shared_ptr<Level> m_LevelOne;
    };
}