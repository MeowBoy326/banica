#pragma once
#include <stdint.h>
#include <vector>
#include "GridCell.h"
#include <memory>

namespace bnc
{
    /// @brief Enum that stores all possible gate states
    enum
    {
        AND = 1,
        OR = 2,
        XOR = 3,
        NOT = 4
    };

    /// @brief This is the base Gate class it is meant to be inherited NOT initialized directly
    class Gate
    {
    public:
        Gate();
        ~Gate();

        /// @brief Getter for the Gate type
        /// @return It returns unsigned int storing the type of the Gate
        uint32_t GetType() const;
        /// @brief Gettter for the position of the cell
        /// @return It returns unsigned int storing the position of the gate
        uint32_t GetCellPosition() const;
        /// @brief This function runs every frame and updated all gate variables related 
        /// @param cells It takes vector storing the grid
        void OnUpdate(std::vector<std::shared_ptr<bnc::GridCell>>* cells);
        
        /// @brief This method updates the gate position by moving it left
        void MoveGateLeft();
        /// @brief This method updates the gate position by moving it right
        void MoveGateRight();
        /// @brief This method updates the gate position by moving it up
        /// @param sizeX It takes the width of the grid
        void MoveGateUp(uint32_t sizeX);
        /// @brief This method updates the gate position by moving it down
        /// @param sizeX It takes the width of the grid
        void MoveGateDown(uint32_t sizeX);
    protected:
        std::vector<std::shared_ptr<bnc::GridCell>>* m_GridCells;

        uint32_t m_Type;
        uint32_t m_GridCellPosition;
        uint32_t m_GridCellNewPosition;

    };
}
