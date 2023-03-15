#pragma once 
#include "raylib.h"
#include "GridCell.h"
#include <vector>
#include <stdint.h>
#include "Level.h"
#include <memory>

namespace bnc
{
    class Player
    {
    public:
        Player(std::vector<std::shared_ptr<GridCell>>* cells, std::vector<std::shared_ptr<Level>>* levels, uint32_t* currentLevel);
        ~Player();

        void UpdatePlayer(); 

        void MovePlayerLeft();
        void MovePlayerRight();
        void MovePlayerUp();
        void MovePlayerDown();

        uint32_t GetPlayerPosition() const;
        void SetPlayerPosition(uint32_t position);
    private:
        std::vector<std::shared_ptr<GridCell>>* m_GridCells;
        std::vector<std::shared_ptr<Level>>* m_Levels;

        uint32_t* m_CurrentLevel;

        uint32_t m_PlayerCurrentPosition = 0;
        uint32_t m_PlayerNewPositon = 0;
    };
}