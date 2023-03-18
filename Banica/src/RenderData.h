#pragma once
#include <stdint.h>
#include "GridCell.h"
#include <vector>
#include "Level.h"
#include <memory>
#include "Particle.h"

namespace bnc
{
    struct RenderData
    {
        std::vector<std::shared_ptr<Level>>* levels;
        uint32_t* currentLevel;
        std::vector<std::shared_ptr<Particle>>* particles;
    };
}