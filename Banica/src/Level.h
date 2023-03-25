#pragma once
#include <vector>
#include <memory>
#include <stdint.h>
#include "GridCell.h"
#include "Gate.h"
#include "Lamp.h"
#include <vector>
#include "Solution.h"
#include <string>

namespace bnc
{
    // THIS CLASS IS MEANT TO BE INHERITED IT IS ONLY A TEMPLATE
    class Level
    {
    public:
        Level();
        ~Level();

        /// @brief Getter for the GridCells
        /// @return Reference to a vector of GridCells
        std::vector<std::shared_ptr<bnc::GridCell>>& GetGridCells() const;
        /// @brief Getter for the Gates
        /// @return Reference to a vector of Gates
        std::vector<std::shared_ptr<bnc::Gate>>& GetGates() const;
        /// @brief Getter for the Lamp
        /// @return Reference to a vector of Lamps
        std::vector<std::shared_ptr<bnc::Lamp>>& GetLamps() const;
        /// @brief Getter for the width of the Level
        /// @return unsiged int storing the width of the level
        uint32_t GetSizeX() const;
        /// @brief Getter for the height of the Level
        /// @return unsiged int storing the height of the level
        uint32_t GetSizeY() const;

        /// @brief Setter for the gates
        virtual void SetGates() = 0; 
        /// @brief Setter for the lamp
        /// @param r_Result A std::string storing the result of the Level
        virtual void SetLamps(std::string& r_Result) = 0; 
    protected:
        std::vector<std::shared_ptr<bnc::GridCell>>* m_GridCells;
        std::vector<std::shared_ptr<bnc::Gate>>* m_Gates;
        std::vector<std::shared_ptr<bnc::Lamp>>* m_Lamps;
        std::vector<std::shared_ptr<bnc::LevelSolution>>* m_Solution;

        uint32_t m_SizeX;
        uint32_t m_SizeY;
    };
}