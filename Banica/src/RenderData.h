#pragma once
#include <stdint.h>
#include "GridCell.h"
#include <vector>
#include "Level.h"

namespace bnc
{
    struct RenderData
    {
        std::vector<Level*>* levels;
        uint32_t* currentLevel;
    };
}