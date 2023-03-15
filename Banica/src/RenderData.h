#pragma once
#include <stdint.h>
#include "GridCell.h"
#include <vector>
#include "Level.h"
#include <memory>

namespace bnc
{
    struct RenderData
    {
        std::vector<std::shared_ptr<Level>>* levels;
        uint32_t* currentLevel;
    };
}