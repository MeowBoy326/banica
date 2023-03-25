#pragma once 
#include "raylib.h"
#include "GridCell.h"
#include <vector>
#include <stdint.h>
#include "Level.h"
#include <memory>

namespace bnc
{
    /// @brief This is the player class
    class Player
    {
    public:
        /// @brief Sets all requared variables
        /// @param cells Pointer to the vector storing the grid
        /// @param levels Pointer to the vector storing all levels
        /// @param currentLevel Pointer to the current level
        Player(std::vector<std::shared_ptr<GridCell>>* cells, std::vector<std::shared_ptr<Level>>* levels, uint32_t* currentLevel);
        ~Player();

        /// @brief Runs every frame updating all player related variables
        void UpdatePlayer(); 

        /// @brief Updates the player postion on the grid by moving it left
        void MovePlayerLeft();
        /// @brief Updates the player postion on the grid by moving it right
        void MovePlayerRight();
        /// @brief Updates the player postion on the grid by moving it up
        void MovePlayerUp();
        /// @brief Updates the player postion on the grid by moving it down
        void MovePlayerDown();

        /// @brief Getter for the player position on the grid
        /// @return Unsiged int storing the position of the player 
        uint32_t GetPlayerPosition() const;
        /// @brief Setter for the player position
        /// @param position Take unsiged int storing the position of the player
        void SetPlayerPosition(uint32_t position);
    private:
        std::vector<std::shared_ptr<GridCell>>* m_GridCells;
        std::vector<std::shared_ptr<Level>>* m_Levels;

        uint32_t* m_CurrentLevel;

        uint32_t m_PlayerCurrentPosition = 0;
        uint32_t m_PlayerNewPositon = 0;
    };
}