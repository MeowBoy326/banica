#pragma once
#include "raylib.h"
#include <stdint.h>

namespace bnc
{
    enum 
    {
        SQUARE
    };
    
    enum
    {
        LEFT,
        RIGHT,
        UP,
        DOWN
    };

    struct Particle
    {
        Vector2 pariclePosition;
        uint32_t particleSize;
        Color particleColor = CLITERAL(Color){ 0, 117, 44, 100};
        uint32_t particleType = bnc::SQUARE;
    };
}
