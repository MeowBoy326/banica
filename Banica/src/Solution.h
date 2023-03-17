#pragma once
#include <stdint.h>

namespace bnc
{
    struct LevelSolution
    {
        uint32_t solutionPosition;
        uint32_t gateType;
        bool isCompleted = false;
    };
}