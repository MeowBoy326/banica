#pragma once
#include <stdint.h>

namespace bnc
{
    /// @brief Struct that a solution to a level
    ///
    /// It stores as a unsiged int the grid position of the gate. The type of the gate. And if the solution is satisfied
    struct LevelSolution
    {
        uint32_t solutionPosition;
        uint32_t gateType;
        bool isCompleted = false;
    };
}