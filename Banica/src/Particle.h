#pragma once
#include "raylib.h"
#include <stdint.h>

namespace bnc
{
    /// @brief Enum storing the possible shapes of the particles
    enum 
    {
        SQUARE
    };
    
    /// @brief Enum storing the direction of the particle
    enum
    {
        LEFT,
        RIGHT,
        UP,
        DOWN
    };

    /// @brief Struct sotring the information for the particle
    /// 
    ///This struction stores the position of the particle on the screeen, the size of the particle, the color of the particle and the type
    struct Particle
    {
        Vector2 pariclePosition;
        uint32_t particleSize;
        Color particleColor = CLITERAL(Color){ 0, 117, 44, 100};
        uint32_t particleType = bnc::SQUARE;
    };
}
