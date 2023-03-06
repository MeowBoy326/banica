#pragma once
#include <stdint.h>
#include "GridCell.h"
#include <vector>

namespace bnc
{
    struct RenderData
    {
        std::vector<GridCell*>* gridCells;
    };
}