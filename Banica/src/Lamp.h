#pragma once
#include <memory>
#include "raylib.h"
#include <stdint.h>
#include <vector>
#include "GridCell.h"

namespace bnc
{
    /// @brief This is the base class for a lamp
    class Lamp
    {
    public:
        /// @brief This construction sets m_Type to type and m_Position to position
        /// @param position The grid position of the lamp
        /// @param type The state of the lamp (ON or OFF)
        Lamp(uint32_t position, uint32_t type);
        ~Lamp();

        /// @brief Getter for the lamp position
        /// @return It return unsiged int storing the cell position of the lamp
        uint32_t GetPosition() const;
        /// @brief Getter for the type
        /// @return It return unsiged int storing the state of the lamp (ON or OFF)
        uint32_t GetType() const;

        /// @brief This method runs every frame updated all lamp related variables
        /// @param grid It takes a pointer to the vector sotring the grid
        void OnUpdate(std::vector<std::shared_ptr<GridCell>>& grid);
        /// @brief Setter for the state of the lamp (ON or OFF)
        /// @param val It takes unsiged int storing the state of the lamp
        void SetState(uint32_t val);
    private:
        uint32_t m_Type;
        uint32_t m_Position;
    };
}