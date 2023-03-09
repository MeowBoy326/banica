#pragma once 
#include "raylib.h"
#include "GridCell.h"
#include <vector>
#include <stdint.h>
#include "Level.h"

namespace bnc
{
    class Player
    {
    public:
        Player(std::vector<GridCell*>* cells, std::vector<Level*>* levels, uint32_t* currentLevel);
        ~Player();

        void UpdatePlayer(); 

        void MovePlayerLeft();
        void MovePlayerRight();
        void MovePlayerUp();
        void MovePlayerDown();

        uint32_t GetPlayerPosition() const;
    private:
        std::vector<GridCell*>* m_GridCells;
        std::vector<Level*>* m_Levels;

        uint32_t* m_CurrentLevel;

        uint32_t m_PlayerCurrentPosition = 45;
        uint32_t m_PlayerNewPositon = 45;
    };
}